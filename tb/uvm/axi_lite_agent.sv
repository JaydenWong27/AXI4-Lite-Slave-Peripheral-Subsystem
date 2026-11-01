// AXI-Lite agent: container that builds the sequencer, driver and monitor and wires them up.
// - type_id::create (not new): goes through the factory, so a test can override the driver or
//   sequencer type (e.g. an axi_lite_err_driver) without editing the agent.
// - get_is_active(): the same class is used active (s_agent: drives bus) and passive
//   (m_agent: only monitors m_bus, where the bridge is already the master). Passive agents
//   create no driver/sequencer, so the connect is guarded the same way.
// - The monitor is built in both modes; ap passes its port through so the env only needs
//   s_agent.ap / m_agent.ap, not the agent's internals.
// - Connect in connect_phase: build_phase runs top-down level by level, and only after ALL
//   build_phases are done is every component guaranteed to exist.
class axi_lite_agent extends uvm_agent;
    `uvm_component_utils(axi_lite_agent)

    axi_lite_sequencer sqr;
    axi_lite_driver    drv;
    axi_lite_monitor   mon;
    uvm_analysis_port #(axi_lite_seq_item) ap;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        mon = axi_lite_monitor::type_id::create("mon", this);   // active and passive
        if (get_is_active() == UVM_ACTIVE) begin
            sqr = axi_lite_sequencer::type_id::create("sqr", this);
            drv = axi_lite_driver::type_id::create("drv", this);
        end
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        ap = mon.ap;
        if (get_is_active() == UVM_ACTIVE)
            drv.seq_item_port.connect(sqr.seq_item_export);
    endfunction

endclass
