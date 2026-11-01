// AXI-Lite monitor: only watches vif (never drives it) and turns completed handshakes back
// into seq_items, broadcast on ap for the scoreboard and coverage.
// - Samples on the rising edge: that edge IS the handshake (VALID && READY). The driver's
//   signals have been stable since the falling edge, and the DUT's flops have not updated yet
//   (<= takes effect after this process reads them), so we see what the DUT sampled.
// - AXI-Lite has no IDs and stays in order, so the N-th B belongs to the N-th AW and W, and
//   the N-th R to the N-th AR. Requests wait in FIFO queues until their response arrives.
// - One loop, separate ifs: all five channels can handshake in the same cycle, and pushes
//   come before pops so a request is queued before its response could look for it.
// - Queues are cleared in reset so a half-finished transaction never pairs with a later one.
// - Only uses vif.ACLK, so the same class works on m_bus (whose ACLK is pclk).
class axi_lite_monitor extends uvm_monitor;
    `uvm_component_utils(axi_lite_monitor)

    axi_vif_t vif;
    uvm_analysis_port #(axi_lite_seq_item) ap;   // send completed items out

    bit [ADDR_WIDTH-1:0] aw_q[$];
    bit [ADDR_WIDTH-1:0] ar_q[$];
    bit [DATA_WIDTH-1:0] wdata_q[$];
    bit [STRB_WIDTH-1:0] wstrb_q[$];

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        ap = new("ap", this);   // ports use plain new, not type_id::create
        if (!uvm_config_db#(axi_vif_t)::get(this, "", "vif", vif))
            `uvm_fatal("NOVIF", "monitor: no virtual interface 'vif' in config_db")
    endfunction

    task run_phase(uvm_phase phase);
        axi_lite_seq_item item;

        forever begin
            @(posedge vif.ACLK);

            if (!vif.ARESETN) begin
                aw_q.delete();
                ar_q.delete();
                wdata_q.delete();
                wstrb_q.delete();
            end else begin
                // ---- requests: remember them until the response arrives ----
                if (vif.AWVALID && vif.AWREADY)
                    aw_q.push_back(vif.AWADDR);

                if (vif.WVALID && vif.WREADY) begin
                    wdata_q.push_back(vif.WDATA);
                    wstrb_q.push_back(vif.WSTRB);
                end

                if (vif.ARVALID && vif.ARREADY)
                    ar_q.push_back(vif.ARADDR);

                // ---- responses: pair with the oldest request and send the item ----
                if (vif.BVALID && vif.BREADY) begin
                    if (aw_q.size() == 0 || wdata_q.size() == 0) begin
                        `uvm_error("MON", "BRESP without matching AW/W")
                    end else begin
                        item = axi_lite_seq_item::type_id::create("item");
                        item.is_write = 1;
                        item.addr = aw_q.pop_front();
                        item.data = wdata_q.pop_front();
                        item.strb = wstrb_q.pop_front();
                        item.resp = vif.BRESP;
                        `uvm_info("MON", item.convert2string(), UVM_MEDIUM)
                        ap.write(item);
                    end
                end

                if (vif.RVALID && vif.RREADY) begin
                    if (ar_q.size() == 0) begin
                        `uvm_error("MON", "RRESP without matching AR")
                    end else begin
                        item = axi_lite_seq_item::type_id::create("item");
                        item.is_write = 0;
                        item.addr = ar_q.pop_front();
                        item.data = vif.RDATA;
                        item.resp = vif.RRESP;
                        `uvm_info("MON", item.convert2string(), UVM_MEDIUM)
                        ap.write(item);
                    end
                end
            end
        end
    endtask

endclass
