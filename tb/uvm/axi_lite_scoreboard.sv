// Scoreboard: two checks on every transaction.
//   1. Register model: does the system answer like the register map says? (write_s)
//   2. Bridge check: did the transaction cross the bridge unchanged? (bus item vs m_bus item)
//   Together they localize a bug: model fails but bridge passes -> slave; bridge fails -> bridge.
// - The model updates when the monitor sends the write, i.e. after B: that is the order in
//   which the slave really applied the writes.
// - The order is correct because the driver finishes one item (item_done) before taking the
//   next, so reads and writes never overlap. Revisit this for outstanding traffic.
// - write_s / write_m instead of write: two inputs, and a class can only have one write().
//   uvm_analysis_imp_decl creates a port class per suffix.
// - write_m only queues: the PCLK side always finishes first (its B/R handshake happens before
//   the response crosses back), so the m_bus item is waiting when the bus item arrives.
// - Separate write/read queues: AXI-Lite only guarantees order within a channel, not between
//   reads and writes.
// - report_phase checks the queues are empty: an m_bus transaction that never came back on bus.
// - Compares with !== so X/Z from the DUT counts as a mismatch.
`uvm_analysis_imp_decl(_s)   // creates class uvm_analysis_imp_s, which calls write_s()
`uvm_analysis_imp_decl(_m)   // creates class uvm_analysis_imp_m, which calls write_m()

class axi_lite_scoreboard extends uvm_scoreboard;
    `uvm_component_utils(axi_lite_scoreboard)

    uvm_analysis_imp_s #(axi_lite_seq_item, axi_lite_scoreboard) s_imp;   // from s_agent (ACLK)
    uvm_analysis_imp_m #(axi_lite_seq_item, axi_lite_scoreboard) m_imp;   // from m_agent (PCLK)

    bit [DATA_WIDTH-1:0] model [4];
    axi_lite_seq_item m_wr_q[$];
    axi_lite_seq_item m_rd_q[$];

    int n_writes, n_reads, n_errors;
    int n_bridge_checks;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        s_imp = new("s_imp", this);
        m_imp = new("m_imp", this);
    endfunction

    function void write_s(axi_lite_seq_item t);
        int idx = int'(t.addr[3:2]);
        bit in_range = (t.addr < 32'h10);
        bit [1:0] exp_resp;
        bit [DATA_WIDTH-1:0] exp_data;

        if (t.is_write) begin
            n_writes++;
            if (!in_range || idx == DATA_IN_IDX) begin
                exp_resp = SLVERR;
            end else begin
                exp_resp = OKAY;
                for (int b = 0; b < STRB_WIDTH; b++)
                    if (t.strb[b]) model[idx][b*8 +: 8] = t.data[b*8 +: 8];
            end
            // 2. compare with what DID come back
            if (t.resp !== exp_resp) begin
                n_errors++;
                `uvm_error("SB", $sformatf("write resp: expected %b, got %b | %s",
                                           exp_resp, t.resp, t.convert2string()))
            end
        end else begin
            n_reads++;
            if (!in_range) begin
                exp_data = '0;
                exp_resp = SLVERR;
            end else if (idx == DATA_IN_IDX) begin
                exp_data = GPIO_IN_VALUE;
                exp_resp = OKAY;
            end else begin
                exp_data = model[idx];
                exp_resp = OKAY;
            end

            if (t.resp !== exp_resp) begin
                n_errors++;
                `uvm_error("SB", $sformatf("read resp: expected %b, got %b | %s",
                                           exp_resp, t.resp, t.convert2string()))
            end

            if (t.data !== exp_data) begin
                n_errors++;
                `uvm_error("SB", $sformatf("read data: expected 0x%08h, got 0x%08h | %s",
                                           exp_data, t.data, t.convert2string()))
            end
        end

        check_bridge(t);
    endfunction

    // m_bus (PCLK) side: just queue it, the matching bus item arrives later
    function void write_m(axi_lite_seq_item t);
        if (t.is_write) m_wr_q.push_back(t);
        else            m_rd_q.push_back(t);
    endfunction

    // The same transaction must appear unchanged on both sides of the bridge
    function void check_bridge(axi_lite_seq_item s);
        axi_lite_seq_item m;
        bit mismatch;

        if (s.is_write ? (m_wr_q.size() == 0) : (m_rd_q.size() == 0)) begin
            n_errors++;
            `uvm_error("SB", $sformatf("bridge: bus transaction never appeared on m_bus | %s",
                                       s.convert2string()))
            return;
        end

        m = s.is_write ? m_wr_q.pop_front() : m_rd_q.pop_front();
        n_bridge_checks++;

        mismatch = (m.addr !== s.addr) || (m.data !== s.data) || (m.resp !== s.resp);
        if (s.is_write && (m.strb !== s.strb)) mismatch = 1;    // strb only means something on writes

        if (mismatch) begin
            n_errors++;
            `uvm_error("SB", $sformatf("bridge: changed crossing the bridge\n  bus:   %s\n  m_bus: %s",
                                       s.convert2string(), m.convert2string()))
        end
    endfunction

    // Runs automatically after every run_phase has finished
    function void report_phase(uvm_phase phase);
        super.report_phase(phase);

        // Anything left came out of the bridge on m_bus but never came back on bus
        if (m_wr_q.size() != 0 || m_rd_q.size() != 0) begin
            n_errors++;
            `uvm_error("SB", $sformatf("bridge: %0d writes / %0d reads on m_bus never returned on bus",
                                       m_wr_q.size(), m_rd_q.size()))
        end

        if (n_errors == 0) begin
            `uvm_info("SB", $sformatf("PASS: writes=%0d reads=%0d bridge_checks=%0d",
                                      n_writes, n_reads, n_bridge_checks), UVM_LOW)
        end else begin
            `uvm_error("SB", $sformatf("FAIL: %0d errors, writes=%0d reads=%0d bridge_checks=%0d",
                                       n_errors, n_writes, n_reads, n_bridge_checks))
        end
    endfunction

endclass