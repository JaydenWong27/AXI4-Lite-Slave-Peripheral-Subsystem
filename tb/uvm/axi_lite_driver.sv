// AXI-Lite master driver: turns each axi_lite_seq_item into pin activity on vif.
// - Drives on the falling ACLK edge. The bridge's READY/VALID are registered (!full/!empty),
//   so the value seen at the falling edge is what the next rising edge samples; that rising
//   edge is the handshake. No race with the DUT's flops.
// - AW and W run in a fork, each with its own delay, so they reach the bridge in any order
//   (the bridge has one FIFO per channel and the slave latches them independently).
// - Gets "vif", not "s_vif": the env decides which interface each agent sees, so the same
//   driver/monitor classes work on both buses.
// - BRESP/RDATA/RRESP are written straight into the item; the sequence holds the same handle
//   and can read them as soon as item_done() returns.
// - No per-handshake timeout: UVM's global +UVM_TIMEOUT covers a hung bus.
class axi_lite_driver extends uvm_driver #(axi_lite_seq_item);
    `uvm_component_utils(axi_lite_driver)

    axi_vif_t vif;

    function new (string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        if(!uvm_config_db#(axi_vif_t)::get(this, "", "vif", vif))
            `uvm_fatal("NOVIF", "driver: no virtual interface 'vif' in config_db")
    endfunction

    task run_phase(uvm_phase phase);
        vif.AWVALID     = '0;
        vif.WVALID      = '0;
        vif.BREADY      = '0;
        vif.ARVALID     = '0;
        vif.RREADY      = '0;

        vif.AWADDR      = '0;
        vif.AWPROT      = '0;
        vif.WDATA       = '0;
        vif.WSTRB       = '0;
        vif.ARADDR      = '0;
        vif.ARPROT      = '0;

        wait (vif.ARESETN === 1'b1);
        @(posedge vif.ACLK);
        @(posedge vif.ACLK);
        forever begin
            seq_item_port.get_next_item(req);
            if (req.is_write) drive_write(req); else drive_read(req);
            seq_item_port.item_done();
        end
    endtask

    task send_aw(input logic [ADDR_WIDTH-1:0] addr);
        @(negedge vif.ACLK);
        vif.AWADDR  = addr;
        vif.AWPROT  = 3'b000;
        vif.AWVALID = 1'b1;
        while (!vif.AWREADY) @(negedge vif.ACLK);
        @(posedge vif.ACLK);    // handshake
        @(negedge vif.ACLK);
        vif.AWVALID = 1'b0;
    endtask

    task send_w(input logic [DATA_WIDTH-1:0] data, input logic [STRB_WIDTH-1:0] strb);
        @(negedge vif.ACLK);
        vif.WDATA  = data;
        vif.WSTRB  = strb;
        vif.WVALID = 1'b1;
        while (!vif.WREADY) @(negedge vif.ACLK);
        @(posedge vif.ACLK);
        @(negedge vif.ACLK);
        vif.WVALID = 1'b0;
    endtask

    task recv_b(output logic [1:0] resp, input int ready_delay = 0);
        repeat (ready_delay) @(negedge vif.ACLK);   // back-pressure: let the B FIFO fill
        @(negedge vif.ACLK);
        vif.BREADY = 1'b1;
        while (!vif.BVALID) @(negedge vif.ACLK);
        resp = vif.BRESP;
        @(posedge vif.ACLK);
        @(negedge vif.ACLK);
        vif.BREADY = 1'b0;
    endtask

    task send_ar(input logic [ADDR_WIDTH-1:0] addr);
        @(negedge vif.ACLK);
        vif.ARADDR  = addr;
        vif.ARPROT  = 3'b000;
        vif.ARVALID = 1'b1;
        while (!vif.ARREADY) @(negedge vif.ACLK);
        @(posedge vif.ACLK);
        @(negedge vif.ACLK);
        vif.ARVALID = 1'b0;
    endtask

    task recv_r(output logic [DATA_WIDTH-1:0] data, output logic [1:0] resp,
                input int ready_delay = 0);
        repeat (ready_delay) @(negedge vif.ACLK);
        @(negedge vif.ACLK);
        vif.RREADY = 1'b1;
        while (!vif.RVALID) @(negedge vif.ACLK);
        data = vif.RDATA;
        resp = vif.RRESP;
        @(posedge vif.ACLK);
        @(negedge vif.ACLK);
        vif.RREADY = 1'b0;
    endtask

    task drive_write(axi_lite_seq_item t);
        fork
            begin
                repeat (t.aw_delay) @(negedge vif.ACLK);
                send_aw(t.addr);
            end
            begin
                repeat (t.w_delay) @(negedge vif.ACLK);
                send_w(t.data, t.strb);
            end
        join
        recv_b(t.resp, t.ready_delay);
    endtask

    task drive_read(axi_lite_seq_item t);
        send_ar(t.addr);
        recv_r(t.data, t.resp, t.ready_delay);
    endtask


endclass