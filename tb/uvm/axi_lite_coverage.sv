// Functional coverage: what did the tests actually exercise?
// - Samples monitor items (what really happened on the bus), not driver items: a driver bug
//   that never sends some case would still look "covered" on the driver side.
// - The covergroup lives inside the class, so it must be created in new(), not build_phase.
// - The field is "item", not "t", so the write() argument doesn't hide it.
// - Bins: each register on its own plus both out-of-range areas; strobe edge cases (none,
//   full, each single byte) separate from the other partial patterns; crosses check every
//   register was both read and written and SLVERR was seen in both directions.
// - illegal_bins turns EXOKAY/DECERR (never valid for this slave) into an error, not a count.
// - Not covered: delays / AW-W order, because monitor items do not carry them.
class axi_lite_coverage extends uvm_subscriber #(axi_lite_seq_item);
    `uvm_component_utils(axi_lite_coverage)

    axi_lite_seq_item item;

    covergroup cg;
        cp_rw : coverpoint item.is_write;      // 1 bit -> automatic bins 0 and 1

        cp_addr : coverpoint item.addr {
            bins data_out  = {'h0};
            bins direction = {'h4};
            bins data_in   = {'h8};
            bins cfg       = {'hC};
            bins oor_near  = {['h10:'hFC]};
            bins oor_far   = {['h100:$]};
        }

        cp_resp : coverpoint item.resp {
            bins okay   = {OKAY};
            bins slverr = {SLVERR};
            illegal_bins bad = {2'b01, 2'b11};
        }

        // Only writes: strb means nothing on a read. 0 + 15 + 4 singles + 10 partial = all 16
        cp_strb : coverpoint item.strb iff (item.is_write) {
            bins none     = {4'h0};
            bins full     = {4'hF};
            bins single[] = {4'h1, 4'h2, 4'h4, 4'h8};
            bins partial  = {4'h3, 4'h5, 4'h6, 4'h7, 4'h9, 4'hA, 4'hB, 4'hC, 4'hD, 4'hE};
        }

        x_rw_addr : cross cp_rw, cp_addr;      // every register written AND read
        x_rw_resp : cross cp_rw, cp_resp;      // SLVERR on writes AND on reads
    endgroup

    function new(string name, uvm_component parent);
        super.new(name, parent);
        cg = new();                            // embedded covergroup: must be created here
    endfunction

    // Called for every monitor item through s_agent.ap -> analysis_export
    function void write(axi_lite_seq_item t);
        item = t;
        cg.sample();
    endfunction

    function void report_phase(uvm_phase phase);
        super.report_phase(phase);
        `uvm_info("COV", $sformatf("coverage: %.1f%%", cg.get_coverage()), UVM_LOW)
    endfunction

endclass
