`timescale 1ns/1ps
`default_nettype none

// Directed + random testbench for the two-clock system:
//   tb master --bus (ACLK)--> axi_lite_cdc_bridge --m_bus (PCLK)--> axi_lite_slave --> gpio_block
//
// Why it is built this way:
// - ACLK and PCLK periods come from +ACLK= / +PCLK= plusargs so the same test runs at
//   ACLK-faster, PCLK-faster and near-equal ratios without recompiling.
// - One external reset (rst_n) drives both ARESETN and the raw prst_n. Both halves of every
//   bridge FIFO must reset together, otherwise their pointers disagree. rst_n deasserts on a
//   falling ACLK edge, which satisfies AXI's "ARESETN deasserts synchronously" rule; the PCLK
//   side gets its own synchronous release from rst_sync inside the system top.
// - Inputs are driven on the falling ACLK edge. READY/VALID from the bridge are registered
//   (!full / !empty), so the value seen at the falling edge is the value the next rising edge
//   samples; that rising edge is the handshake. This avoids races with the DUT's flops.
// - AW and W are driven by separate tasks so each holds VALID until its own handshake. The
//   bridge has one FIFO per channel, so address and data may reach the slave in any order.
// - A register reference model (model[]) predicts every response. Expected values are
//   computed in issue order: FIFOs and the slave both preserve order (AXI-Lite has no IDs).
// - Protocol assertions watch both sides of the bridge: on bus the bridge is the slave
//   (BVALID/RVALID must hold with stable payload), on m_bus it is the master (AWVALID/WVALID/
//   ARVALID must hold with stable payload). This checks the FWFT "VALID = !empty" claim.
module axi_lite_system_tb;

    localparam int ADDR_WIDTH = 32;
    localparam int DATA_WIDTH = 32;
    localparam int STRB_WIDTH = DATA_WIDTH / 8;
    localparam int GPIO_WIDTH = 32;
    localparam int NUM_REGS = 4;
    localparam int DATA_IN_IDX = 2;         // register 2 (0x8) is read-only
    localparam int NUM_OUTSTANDING = 8;     // more than one FIFO deep, so full gets hit
    localparam int NUM_RANDOM = 300;
    localparam int HANDSHAKE_TIMEOUT = 2000; // ACLK cycles to wait for any single handshake

    localparam logic [1:0] OKAY   = 2'b00;
    localparam logic [1:0] SLVERR = 2'b10;

    int aclk_period = 10;
    int pclk_period = 17;
    int seed = 1;

    int errors = 0;
    int checks = 0;
    int writes = 0;
    int reads = 0;

    logic aclk;
    logic pclk;
    logic rst_n;

    logic [GPIO_WIDTH-1:0] gpio_o;
    logic [GPIO_WIDTH-1:0] gpio_oe_n;
    logic [GPIO_WIDTH-1:0] gpio_i;

    // Reference model of the four registers (index 2 is unused: reads return gpio_i)
    logic [DATA_WIDTH-1:0] model [NUM_REGS];

    axi_lite_if #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) bus (
        .ACLK(aclk),
        .ARESETN(rst_n)
    );

    axi_lite_gpio_system #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_REGS(NUM_REGS),
        .GPIO_WIDTH(GPIO_WIDTH)
    ) dut (
        .pclk(pclk),
        .prst_n(rst_n),
        .axi_bus(bus),
        .gpio_o(gpio_o),
        .gpio_oe_n(gpio_oe_n),
        .gpio_i(gpio_i)
    );

    // Read plusargs, start both clocks, arm the global watchdog
    initial begin
        void'($value$plusargs("ACLK=%d", aclk_period));
        void'($value$plusargs("PCLK=%d", pclk_period));
        if ($value$plusargs("SEED=%d", seed)) begin
            // Seed the random generator; the returned value is discarded
            void'($urandom(seed));
        end
        aclk = 1'b0;
        pclk = 1'b0;
        fork
            forever #(aclk_period/2.0) aclk = ~aclk;
            forever #(pclk_period/2.0) pclk = ~pclk;
        join_none
        // Every transaction crosses the bridge two or three times, so scale with both clocks
        #(200_000.0 * (aclk_period + pclk_period));
        $fatal(1, "Global timeout (aclk=%0dns pclk=%0dns)", aclk_period, pclk_period);
    end

    // Reset: hold for at least 5 edges of BOTH clocks so every flop sees it, then release on
    // a falling ACLK edge
    initial begin
        rst_n = 1'b0;
        gpio_i = '0;

        bus.AWADDR  = '0;
        bus.AWPROT  = '0;
        bus.AWVALID = 1'b0;
        bus.WDATA   = '0;
        bus.WSTRB   = '0;
        bus.WVALID  = 1'b0;
        bus.BREADY  = 1'b0;
        bus.ARADDR  = '0;
        bus.ARPROT  = '0;
        bus.ARVALID = 1'b0;
        bus.RREADY  = 1'b0;

        fork
            repeat (5) @(posedge aclk);
            repeat (5) @(posedge pclk);
        join
        @(negedge aclk);
        rst_n = 1'b1;
    end

    // ------------------------------------------------------------------
    // Driver tasks (one per channel)
    // ------------------------------------------------------------------

    // One falling ACLK edge of waiting, with a per-handshake timeout
    task automatic wait_cycle(inout int cycles, input string what);
        @(negedge aclk);
        cycles++;
        if (cycles > HANDSHAKE_TIMEOUT) begin
            $fatal(1, "[%0t] Timeout waiting for %s", $time, what);
        end
    endtask

    task automatic send_aw(input logic [ADDR_WIDTH-1:0] addr);
        int cycles = 0;
        @(negedge aclk);
        bus.AWADDR  = addr;
        bus.AWPROT  = 3'b000;
        bus.AWVALID = 1'b1;
        while (!bus.AWREADY) wait_cycle(cycles, "AWREADY");
        @(posedge aclk);    // handshake
        @(negedge aclk);
        bus.AWVALID = 1'b0;
    endtask

    task automatic send_w(input logic [DATA_WIDTH-1:0] data, input logic [STRB_WIDTH-1:0] strb);
        int cycles = 0;
        @(negedge aclk);
        bus.WDATA  = data;
        bus.WSTRB  = strb;
        bus.WVALID = 1'b1;
        while (!bus.WREADY) wait_cycle(cycles, "WREADY");
        @(posedge aclk);
        @(negedge aclk);
        bus.WVALID = 1'b0;
    endtask

    task automatic recv_b(output logic [1:0] resp, input int ready_delay = 0);
        int cycles = 0;
        repeat (ready_delay) @(negedge aclk);   // back-pressure: let the B FIFO fill
        @(negedge aclk);
        bus.BREADY = 1'b1;
        while (!bus.BVALID) wait_cycle(cycles, "BVALID");
        resp = bus.BRESP;
        @(posedge aclk);
        @(negedge aclk);
        bus.BREADY = 1'b0;
    endtask

    task automatic send_ar(input logic [ADDR_WIDTH-1:0] addr);
        int cycles = 0;
        @(negedge aclk);
        bus.ARADDR  = addr;
        bus.ARPROT  = 3'b000;
        bus.ARVALID = 1'b1;
        while (!bus.ARREADY) wait_cycle(cycles, "ARREADY");
        @(posedge aclk);
        @(negedge aclk);
        bus.ARVALID = 1'b0;
    endtask

    task automatic recv_r(output logic [DATA_WIDTH-1:0] data, output logic [1:0] resp,
                          input int ready_delay = 0);
        int cycles = 0;
        repeat (ready_delay) @(negedge aclk);
        @(negedge aclk);
        bus.RREADY = 1'b1;
        while (!bus.RVALID) wait_cycle(cycles, "RVALID");
        data = bus.RDATA;
        resp = bus.RRESP;
        @(posedge aclk);
        @(negedge aclk);
        bus.RREADY = 1'b0;
    endtask

    // Full write: AW and W run in parallel, each delayed independently, then wait for B
    task automatic axi_write(input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data,
                             input logic [STRB_WIDTH-1:0] strb, output logic [1:0] resp,
                             input int aw_delay = 0, input int w_delay = 0, input int b_delay = 0);
        fork
            begin
                repeat (aw_delay) @(negedge aclk);
                send_aw(addr);
            end
            begin
                repeat (w_delay) @(negedge aclk);
                send_w(data, strb);
            end
        join
        recv_b(resp, b_delay);
        writes++;
    endtask

    task automatic axi_read(input logic [ADDR_WIDTH-1:0] addr, output logic [DATA_WIDTH-1:0] data,
                            output logic [1:0] resp, input int r_delay = 0);
        send_ar(addr);
        recv_r(data, resp, r_delay);
        reads++;
    endtask

    // ------------------------------------------------------------------
    // Reference model and checks
    // ------------------------------------------------------------------

    function automatic logic addr_in_range(input logic [ADDR_WIDTH-1:0] addr);
        return addr[ADDR_WIDTH-1:2] < (ADDR_WIDTH-2)'(NUM_REGS);
    endfunction

    // Apply a write to the model and return the response the slave should give
    function automatic logic [1:0] model_write(input logic [ADDR_WIDTH-1:0] addr,
                                               input logic [DATA_WIDTH-1:0] data,
                                               input logic [STRB_WIDTH-1:0] strb);
        int idx = int'(addr[3:2]);
        if (!addr_in_range(addr) || idx == DATA_IN_IDX) begin
            return SLVERR;
        end
        for (int b = 0; b < STRB_WIDTH; b++) begin
            if (strb[b]) model[idx][b*8 +: 8] = data[b*8 +: 8];
        end
        return OKAY;
    endfunction

    function automatic void model_read(input logic [ADDR_WIDTH-1:0] addr,
                                       output logic [DATA_WIDTH-1:0] data,
                                       output logic [1:0] resp);
        int idx = int'(addr[3:2]);
        if (!addr_in_range(addr)) begin
            data = '0;
            resp = SLVERR;
        end else if (idx == DATA_IN_IDX) begin
            data = gpio_i;     // only valid once gpio_i has been stable for 2+ PCLK cycles
            resp = OKAY;
        end else begin
            data = model[idx];
            resp = OKAY;
        end
    endfunction

    function automatic void check_data(input string what, input logic [DATA_WIDTH-1:0] got,
                                       input logic [DATA_WIDTH-1:0] exp);
        checks++;
        if (got !== exp) begin
            $error("%s: expected 0x%08h, got 0x%08h", what, exp, got);
            errors++;
        end
    endfunction

    function automatic void check_resp(input string what, input logic [1:0] got,
                                       input logic [1:0] exp);
        checks++;
        if (got !== exp) begin
            $error("%s: expected resp 0b%02b, got 0b%02b", what, exp, got);
            errors++;
        end
    endfunction

    // Write through the bridge and check BRESP against the model
    task automatic write_check(input string what, input logic [ADDR_WIDTH-1:0] addr,
                               input logic [DATA_WIDTH-1:0] data, input logic [STRB_WIDTH-1:0] strb,
                               input int aw_delay = 0, input int w_delay = 0, input int b_delay = 0);
        logic [1:0] resp;
        logic [1:0] exp_resp;
        exp_resp = model_write(addr, data, strb);
        axi_write(addr, data, strb, resp, aw_delay, w_delay, b_delay);
        check_resp(what, resp, exp_resp);
    endtask

    // Read through the bridge and check RDATA/RRESP against the model
    task automatic read_check(input string what, input logic [ADDR_WIDTH-1:0] addr,
                              input int r_delay = 0);
        logic [DATA_WIDTH-1:0] data;
        logic [DATA_WIDTH-1:0] exp_data;
        logic [1:0] resp;
        logic [1:0] exp_resp;
        model_read(addr, exp_data, exp_resp);
        axi_read(addr, data, resp, r_delay);
        check_resp(what, resp, exp_resp);
        check_data(what, data, exp_data);
    endtask

    // Change gpio_i and wait long enough for sync_2ff (2 PCLK flops) to pass it through
    task automatic set_gpio_in(input logic [GPIO_WIDTH-1:0] value);
        @(negedge pclk);
        gpio_i = value;
        repeat (3) @(posedge pclk);
    endtask

    // ------------------------------------------------------------------
    // Test sequence
    // ------------------------------------------------------------------
    initial begin
        logic [ADDR_WIDTH-1:0] addrs [NUM_OUTSTANDING];
        logic [DATA_WIDTH-1:0] datas [NUM_OUTSTANDING];
        logic [DATA_WIDTH-1:0] exp_data [NUM_OUTSTANDING];
        logic [1:0] exp_resp [NUM_OUTSTANDING];

        for (int i = 0; i < NUM_REGS; i++) model[i] = '0;

        wait (rst_n === 1'b1);
        repeat (5) @(posedge pclk);     // let rst_sync release the PCLK side
        @(negedge aclk);

        $display("[%0t] Test 1: reset values", $time);
        read_check("Reset DATA_OUT", 32'h0);
        read_check("Reset DIRECTION", 32'h4);
        read_check("Reset CONFIG", 32'hC);
        check_data("Reset gpio_oe_n (all inputs)", gpio_oe_n, '1);

        $display("[%0t] Test 2: basic write/readback and WSTRB", $time);
        write_check("Write DATA_OUT", 32'h0, 32'hDEAD_BEEF, 4'b1111);
        read_check("Readback DATA_OUT", 32'h0);
        write_check("Partial write DATA_OUT", 32'h0, 32'h1234_5678, 4'b0011);
        read_check("WSTRB readback (expect 0xDEAD5678)", 32'h0);
        write_check("Write DIRECTION", 32'h4, 32'hCAFE_BABE, 4'b1111);
        read_check("Readback DIRECTION", 32'h4);

        $display("[%0t] Test 3: AW/W ordering through separate FIFOs", $time);
        write_check("Address-first write", 32'h0, 32'h1111_2222, 4'b1111, 0, 8);
        read_check("Address-first readback", 32'h0);
        write_check("Data-first write", 32'hC, 32'h3333_4444, 4'b1111, 8, 0);
        read_check("Data-first readback", 32'hC);

        $display("[%0t] Test 4: GPIO pins follow the registers", $time);
        check_data("gpio_o = DATA_OUT & DIRECTION", gpio_o, model[0] & model[1]);
        check_data("gpio_oe_n = ~DIRECTION", gpio_oe_n, ~model[1]);

        $display("[%0t] Test 5: GPIO input and read-only register", $time);
        set_gpio_in(32'hA5A5_5A5A);
        read_check("DATA_IN read", 32'h8);
        write_check("Write to read-only DATA_IN (expect SLVERR)", 32'h8, 32'hFFFF_FFFF, 4'b1111);
        read_check("DATA_IN unchanged", 32'h8);

        $display("[%0t] Test 6: out-of-range address", $time);
        write_check("Write 0x10 (expect SLVERR)", 32'h10, 32'hFFFF_FFFF, 4'b1111);
        read_check("Read 0x10 (expect SLVERR, 0)", 32'h10);
        write_check("Write 0x1000 (expect SLVERR)", 32'h1000, 32'h0BAD_F00D, 4'b1111);
        read_check("Read 0x1000 (expect SLVERR, 0)", 32'h1000);

        // Issue NUM_OUTSTANDING writes without waiting for B, and start collecting B late.
        // The B FIFO fills, BREADY on m_bus drops, and the slave must hold BVALID.
        $display("[%0t] Test 7: %0d outstanding writes with late BREADY", $time, NUM_OUTSTANDING);
        for (int i = 0; i < NUM_OUTSTANDING; i++) begin
            addrs[i] = ADDR_WIDTH'(4 * (i % NUM_REGS));     // includes 0x8 -> SLVERR
            datas[i] = 32'hA000_0000 + i;
            exp_resp[i] = model_write(addrs[i], datas[i], 4'b1111);
        end
        fork
            for (int i = 0; i < NUM_OUTSTANDING; i++) send_aw(addrs[i]);
            for (int i = 0; i < NUM_OUTSTANDING; i++) send_w(datas[i], 4'b1111);
            begin
                logic [1:0] resp;
                repeat (40) @(negedge aclk);
                for (int i = 0; i < NUM_OUTSTANDING; i++) begin
                    recv_b(resp);
                    check_resp($sformatf("Outstanding write %0d", i), resp, exp_resp[i]);
                    writes++;
                end
            end
        join

        // Same for reads: R must come back in AR order, with the R FIFO filling first
        $display("[%0t] Test 8: %0d outstanding reads with late RREADY", $time, NUM_OUTSTANDING);
        for (int i = 0; i < NUM_OUTSTANDING; i++) begin
            addrs[i] = ADDR_WIDTH'(4 * ((NUM_OUTSTANDING - 1 - i) % (NUM_REGS + 1)));
            model_read(addrs[i], exp_data[i], exp_resp[i]);
        end
        fork
            for (int i = 0; i < NUM_OUTSTANDING; i++) send_ar(addrs[i]);
            begin
                logic [DATA_WIDTH-1:0] data;
                logic [1:0] resp;
                repeat (40) @(negedge aclk);
                for (int i = 0; i < NUM_OUTSTANDING; i++) begin
                    recv_r(data, resp);
                    check_resp($sformatf("Outstanding read %0d", i), resp, exp_resp[i]);
                    check_data($sformatf("Outstanding read %0d", i), data, exp_data[i]);
                    reads++;
                end
            end
        join

        // Random reads/writes with random addresses, data, strobes, AW/W skew and READY delay
        $display("[%0t] Test 9: %0d random transactions (seed=%0d)", $time, NUM_RANDOM, seed);
        set_gpio_in($urandom());
        for (int i = 0; i < NUM_RANDOM; i++) begin
            logic [ADDR_WIDTH-1:0] addr;
            case ($urandom_range(0, 9))
                8:       addr = 32'h10 + ADDR_WIDTH'($urandom_range(0, 15) * 4);
                9:       addr = $urandom() & ~32'h3;
                default: addr = ADDR_WIDTH'($urandom_range(0, NUM_REGS - 1) * 4);
            endcase
            if ($urandom_range(0, 1) == 1) begin
                write_check($sformatf("Random write %0d @0x%08h", i, addr), addr, $urandom(),
                            STRB_WIDTH'($urandom_range(0, 2**STRB_WIDTH - 1)),
                            $urandom_range(0, 3), $urandom_range(0, 3), $urandom_range(0, 3));
            end else begin
                read_check($sformatf("Random read %0d @0x%08h", i, addr), addr,
                           $urandom_range(0, 3));
            end
        end

        repeat (10) @(posedge aclk);
        if (errors == 0) begin
            $display("PASS: checks=%0d writes=%0d reads=%0d (aclk=%0dns pclk=%0dns)",
                checks, writes, reads, aclk_period, pclk_period);
        end else begin
            $display("FAIL: %0d errors, checks=%0d writes=%0d reads=%0d (aclk=%0dns pclk=%0dns)",
                errors, checks, writes, reads, aclk_period, pclk_period);
        end
        $finish;
    end

    // ------------------------------------------------------------------
    // Protocol assertions on both sides of the bridge
    // ------------------------------------------------------------------

    // ACLK side: the bridge is the slave, so its responses must hold until accepted
    assert property (@(posedge aclk) disable iff (!rst_n)
        bus.BVALID && !bus.BREADY |=> bus.BVALID && $stable(bus.BRESP))
        else $error("bus: BVALID dropped or BRESP changed before BREADY");

    assert property (@(posedge aclk) disable iff (!rst_n)
        bus.RVALID && !bus.RREADY |=> bus.RVALID && $stable(bus.RDATA) && $stable(bus.RRESP))
        else $error("bus: RVALID dropped or RDATA/RRESP changed before RREADY");

    // PCLK side: the bridge is the master, so its requests must hold until accepted
    assert property (@(posedge pclk) disable iff (!dut.m_bus.ARESETN)
        dut.m_bus.AWVALID && !dut.m_bus.AWREADY |=>
            dut.m_bus.AWVALID && $stable(dut.m_bus.AWADDR) && $stable(dut.m_bus.AWPROT))
        else $error("m_bus: AWVALID dropped or AWADDR changed before AWREADY");

    assert property (@(posedge pclk) disable iff (!dut.m_bus.ARESETN)
        dut.m_bus.WVALID && !dut.m_bus.WREADY |=>
            dut.m_bus.WVALID && $stable(dut.m_bus.WDATA) && $stable(dut.m_bus.WSTRB))
        else $error("m_bus: WVALID dropped or WDATA changed before WREADY");

    assert property (@(posedge pclk) disable iff (!dut.m_bus.ARESETN)
        dut.m_bus.ARVALID && !dut.m_bus.ARREADY |=>
            dut.m_bus.ARVALID && $stable(dut.m_bus.ARADDR) && $stable(dut.m_bus.ARPROT))
        else $error("m_bus: ARVALID dropped or ARADDR changed before ARREADY");

    initial begin
        if ($test$plusargs("DUMP")) begin
            $dumpfile("axi_lite_system_tb.vcd");
            $dumpvars(0, axi_lite_system_tb);
        end
    end

endmodule
`default_nettype wire
