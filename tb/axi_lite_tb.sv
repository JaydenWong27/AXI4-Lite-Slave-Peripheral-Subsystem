// AXI4-Lite testbench placeholder.
// Add clock/reset generation, read tests, and write tests here when implementation begins.

module axi_lite_tb;

    logic ACLK;
    logic ARESETN;

    axi_lite_if bus (
        .ACLK(ACLK),
        .ARESETN(ARESETN)
    );

    logic [31:0] reg_out0;
    logic [31:0] reg_out1;
    logic [31:0] gpio_in;

    axi_lite_slave dut (
        .bus(bus),
        .reg_out0(reg_out0),
        .reg_out1(reg_out1),
        .gpio_in(gpio_in)
    );

    initial begin
        ARESETN = 1'b0;
        gpio_in = '0;

        bus.AWADDR = '0;
        bus.AWPROT = '0;
        bus.AWVALID = 1'b0;

        bus.WDATA = '0;
        bus.WSTRB = '0;
        bus.WVALID = 1'b0;

        bus.BREADY = 1'b0;

        bus.ARADDR = '0;
        bus.ARPROT = '0;
        bus.ARVALID = 1'b0;

        bus.RREADY = 1'b0;

        repeat (5) @(posedge ACLK);
        ARESETN = 1'b1;
    end

    initial begin
        ACLK = 1'b0;
        forever #5 ACLK = ~ACLK;
    end

    task automatic axi_write(
        input logic [31:0] addr,
        input logic [31:0] data,
        input logic [3:0] strb,
        output logic [1:0] resp
    );
        begin
            @(posedge ACLK);

            bus.AWADDR  = addr;
            bus.AWVALID = 1'b1;

            bus.WDATA  = data;
            bus.WSTRB  = strb;
            bus.WVALID = 1'b1;

            bus.BREADY = 1'b1;

            wait (bus.AWREADY && bus.WREADY);
            @(posedge ACLK);
            bus.AWVALID = 1'b0;
            bus.WVALID  = 1'b0;

            wait (bus.BVALID);
            resp = bus.BRESP;
            @(posedge ACLK);
            bus.BREADY = 1'b0;
        end
    endtask

    task automatic axi_write_addr_first(
        input logic [31:0] addr,
        input logic [31:0] data,
        input logic [3:0] strb
    );
        begin
            @(posedge ACLK);

            bus.AWADDR  = addr;
            bus.AWVALID = 1'b1;
            bus.BREADY  = 1'b1;

            wait (bus.AWREADY);
            @(posedge ACLK);
            bus.AWVALID = 1'b0;

            repeat (2) @(posedge ACLK);

            bus.WDATA  = data;
            bus.WSTRB  = strb;
            bus.WVALID = 1'b1;

            wait (bus.WREADY);
            @(posedge ACLK);
            bus.WVALID = 1'b0;

            wait (bus.BVALID);
            @(posedge ACLK);
            bus.BREADY = 1'b0;
        end
    endtask

    task automatic axi_write_data_first(
        input logic [31:0] addr,
        input logic [31:0] data,
        input logic [3:0] strb
    );
        begin
            @(posedge ACLK);

            bus.WDATA  = data;
            bus.WSTRB  = strb;
            bus.WVALID = 1'b1;
            bus.BREADY = 1'b1;

            wait (bus.WREADY);
            @(posedge ACLK);
            bus.WVALID = 1'b0;

            repeat (2) @(posedge ACLK);

            bus.AWADDR  = addr;
            bus.AWVALID = 1'b1;

            wait (bus.AWREADY);
            @(posedge ACLK);
            bus.AWVALID = 1'b0;

            wait (bus.BVALID);
            @(posedge ACLK);
            bus.BREADY = 1'b0;
        end
    endtask

    task automatic axi_read(
        input logic [31:0] addr,
        output logic [31:0] data,
        output logic [1:0] resp
    );
        begin
            @(posedge ACLK);

            bus.ARADDR  = addr;
            bus.ARVALID = 1'b1;
            bus.RREADY  = 1'b1;

            wait (bus.ARREADY);
            @(posedge ACLK);
            bus.ARVALID = 1'b0;

            wait (bus.RVALID);
            data = bus.RDATA;
            resp = bus.RRESP;
            @(posedge ACLK);
            bus.RREADY = 1'b0;
        end
    endtask

    initial begin
        logic [31:0] read_data;
        logic [1:0] write_resp;
        logic [1:0] read_resp;

        wait (ARESETN == 1'b1);
        @(posedge ACLK);

        axi_write(32'h0000_0000, 32'hDEAD_BEEF, 4'b1111, write_resp);

        if (write_resp !== 2'b00) begin
            $error("Write response failed: expected OKAY, got 0b%02b", write_resp);
        end

        axi_read(32'h0000_0000, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("Read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'hDEAD_BEEF) begin
            $error("Readback failed: expected 0x%08h, got 0x%08h",
                32'hDEAD_BEEF, read_data);
        end else begin
            $display("readback passed: 0x%08h", read_data);
        end

        axi_write(32'h0000_0000, 32'h1234_5678, 4'b0011, write_resp);

        if (write_resp !== 2'b00) begin
            $error("Write response failed: expected OKAY, got 0b%02b", write_resp);
        end

        axi_read(32'h0000_0000, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("Read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'hDEAD_5678) begin
            $error("WSTRB test failed: expected 0x%08h, got 0x%08h",
                32'hDEAD_5678, read_data);
        end else begin
            $display("WSTRB test passed: 0x%08h", read_data);
        end

        axi_write(32'h0000_0004, 32'hCAFE_BABE, 4'b1111, write_resp);

        if (write_resp !== 2'b00) begin
            $error("Write response failed: expected OKAY, got 0b%02b", write_resp);
        end

        axi_read(32'h0000_0004, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("Read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'hCAFE_BABE) begin
            $error("Register 1 test failed: expected 0x%08h, got 0x%08h",
                32'hCAFE_BABE, read_data);
        end else begin
            $display("Register 1 test passed: 0x%08h", read_data);
        end

        axi_write_addr_first(32'h0000_0000, 32'h1111_2222, 4'b1111);
        axi_read(32'h0000_0000, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("Read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'h1111_2222) begin
            $error("Address-first write failed: expected 0x%08h, got 0x%08h",
                32'h1111_2222, read_data);
        end else begin
            $display("Address-first write passed: 0x%08h", read_data);
        end

        axi_write_data_first(32'h0000_000C, 32'h3333_4444, 4'b1111);
        axi_read(32'h0000_000C, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("Read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'h3333_4444) begin
            $error("Data-first write failed: expected 0x%08h, got 0x%08h",
                32'h3333_4444, read_data);
        end else begin
            $display("Data-first write passed: 0x%08h", read_data);
        end

        // Register outputs to the GPIO block should mirror registers 0 and 1
        if (reg_out0 !== 32'h1111_2222 || reg_out1 !== 32'hCAFE_BABE) begin
            $error("Register outputs failed: reg_out0=0x%08h reg_out1=0x%08h",
                reg_out0, reg_out1);
        end else begin
            $display("Register outputs passed: reg_out0=0x%08h reg_out1=0x%08h",
                reg_out0, reg_out1);
        end

        // Register 2 is read-only and returns gpio_in
        gpio_in = 32'hA5A5_5A5A;
        axi_read(32'h0000_0008, read_data, read_resp);

        if (read_resp !== 2'b00) begin
            $error("GPIO input read response failed: expected OKAY, got 0b%02b", read_resp);
        end

        if (read_data !== 32'hA5A5_5A5A) begin
            $error("GPIO input read failed: expected 0x%08h, got 0x%08h",
                32'hA5A5_5A5A, read_data);
        end else begin
            $display("GPIO input read passed: 0x%08h", read_data);
        end

        axi_write(32'h0000_0008, 32'hFFFF_FFFF, 4'b1111, write_resp);

        if (write_resp !== 2'b10) begin
            $error("Read-only write response failed: expected SLVERR, got 0b%02b",
                write_resp);
        end else begin
            $display("Read-only write correctly returned SLVERR");
        end

        axi_read(32'h0000_0008, read_data, read_resp);

        if (read_data !== 32'hA5A5_5A5A) begin
            $error("Read-only register changed: expected 0x%08h, got 0x%08h",
                32'hA5A5_5A5A, read_data);
        end

        axi_write(32'h0000_0010, 32'hFFFF_FFFF, 4'b1111, write_resp);

        if (write_resp !== 2'b10) begin
            $error("Invalid write response failed: expected SLVERR, got 0b%02b",
                write_resp);
        end else begin
            $display("Invalid write correctly returned SLVERR");
        end

        axi_read(32'h0000_0010, read_data, read_resp);

        if (read_resp !== 2'b10) begin
            $error("Invalid read response failed: expected SLVERR, got 0b%02b", read_resp);
        end else begin
            $display("Invalid read correctly returned SLVERR");
        end

        if (read_data !== 32'h0000_0000) begin
            $error("Invalid read data failed: expected 0x%08h, got 0x%08h",
                32'h0000_0000, read_data);
        end
        
        #20;
        $finish;
    end

    initial begin
        #5000;
        $error("Simulation timeout");
        $finish;
    end

    initial begin
        $dumpfile("axi_lite_tb.vcd");
        $dumpvars(0, axi_lite_tb);
    end

endmodule
