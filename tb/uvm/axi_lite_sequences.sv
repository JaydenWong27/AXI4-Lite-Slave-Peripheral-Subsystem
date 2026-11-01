// Sequences: each class generates one kind of traffic and hands items to the driver.
// - Sequences are objects (no parent): created per test run and thrown away afterwards.
// - randomize() with { } pins only the fields a test cares about; the delays and the class
//   constraints (c_align, c_addr, c_delay) still apply.
// - A fresh item per transaction: the monitor/scoreboard may still hold handles to old ones.

// One write to DATA_OUT, then a read back. Smoke test for the whole chain:
// sequence -> sequencer -> driver -> bus -> bridge -> slave -> back.
class axi_lite_basic_seq extends uvm_sequence #(axi_lite_seq_item);
    `uvm_object_utils(axi_lite_basic_seq)

    function new(string name = "axi_lite_basic_seq");
        super.new(name);
    endfunction

    task body();
        // Write 0xDEADBEEF to 0x0
        req = axi_lite_seq_item::type_id::create("req");
        start_item(req);
        if (!req.randomize() with { is_write == 1; addr == 32'h0; data == 32'hDEAD_BEEF; strb == 4'hF; })
            `uvm_error("RAND", "write randomize failed")
        finish_item(req);
        `uvm_info("SEQ", req.convert2string(), UVM_LOW)

        // Read it back; finish_item returns after item_done, so req.data/resp are filled in
        req = axi_lite_seq_item::type_id::create("req");
        start_item(req);
        if (!req.randomize() with { is_write == 0; addr == 32'h0; })
            `uvm_error("RAND", "read randomize failed")
        finish_item(req);
        `uvm_info("SEQ", req.convert2string(), UVM_LOW)

    endtask
endclass

// Random traffic: no with { }, so the seq_item constraints (c_addr, c_delay) shape the
// distribution. No checks here: the scoreboard checks every transaction.
class axi_lite_random_seq extends uvm_sequence #(axi_lite_seq_item);
    `uvm_object_utils(axi_lite_random_seq)

    rand int unsigned n_items;
    constraint c_n_items { n_items inside {[100:300]}; }

    function new(string name = "axi_lite_random_seq");
        super.new(name);
    endfunction

    task body();
        for (int i = 0; i < n_items; i++) begin
            req = axi_lite_seq_item::type_id::create("req");
            start_item(req);
            if (!req.randomize())
                `uvm_error("RAND", "randomize failed")
            finish_item(req);
            `uvm_info("SEQ", req.convert2string(), UVM_HIGH)
        end
        `uvm_info("SEQ", $sformatf("random_seq done: %0d items", n_items), UVM_LOW)
    endtask
endclass

// Directed cases from axi_lite_system_tb tests 1-6: reset values, WSTRB, AW/W skew,
// read-only register, out-of-range addresses. Only generates traffic; the scoreboard
// predicts every response, so no expected values here.
// - Helper arguments are a/d/s, not addr/data/strb: inside with { }, "addr == addr" would
//   compare the item's field with itself (always true) and pin nothing.
class axi_lite_directed_seq extends uvm_sequence #(axi_lite_seq_item);
    `uvm_object_utils(axi_lite_directed_seq)

    function new(string name = "axi_lite_directed_seq");
        super.new(name);
    endfunction

    // aw_d / w_d skew the AW and W channels (default: both at once)
    task do_write(bit [ADDR_WIDTH-1:0] a, bit [DATA_WIDTH-1:0] d, bit [STRB_WIDTH-1:0] s,
                  int unsigned aw_d = 0, int unsigned w_d = 0);
        req = axi_lite_seq_item::type_id::create("req");
        start_item(req);
        if (!req.randomize() with { is_write == 1; addr == a; data == d; strb == s;
                                    aw_delay == aw_d; w_delay == w_d; })
            `uvm_error("RAND", "write randomize failed")
        finish_item(req);
    endtask

    task do_read(bit [ADDR_WIDTH-1:0] a);
        req = axi_lite_seq_item::type_id::create("req");
        start_item(req);
        if (!req.randomize() with { is_write == 0; addr == a; })
            `uvm_error("RAND", "read randomize failed")
        finish_item(req);
    endtask

    task body();
        // Reset values (before any write): all registers read 0
        do_read(32'h0);
        do_read(32'h4);
        do_read(32'hC);

        // Full write, then a partial write: WSTRB 0011 only touches the low 2 bytes,
        // so the readback is 0xDEAD5678
        do_write(32'h0, 32'hDEAD_BEEF, 4'b1111);
        do_read(32'h0);
        do_write(32'h0, 32'h1234_5678, 4'b0011);
        do_read(32'h0);

        // AW/W skew through the separate bridge FIFOs
        do_write(32'h4, 32'hCAFE_BABE, 4'b1111, 0, 3);   // W 3 cycles after AW
        do_read(32'h4);
        do_write(32'hC, 32'h3333_4444, 4'b1111, 3, 0);   // AW 3 cycles after W
        do_read(32'hC);

        // Read-only DATA_IN: the write returns SLVERR, the read still returns gpio_i
        do_write(32'h8, 32'hFFFF_FFFF, 4'b1111);
        do_read(32'h8);

        // Out of range: SLVERR on both, reads return 0
        do_write(32'h10, 32'hFFFF_FFFF, 4'b1111);
        do_read(32'h10);
        do_write(32'h1000, 32'h0BAD_F00D, 4'b1111);
        do_read(32'h1000);

        `uvm_info("SEQ", "directed_seq done", UVM_LOW)
    endtask
endclass