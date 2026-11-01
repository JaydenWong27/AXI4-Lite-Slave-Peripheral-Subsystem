// Env: builds both agents and the scoreboard and wires them up.
// - s_agent is active on bus (ACLK) and drives traffic; m_agent is passive on m_bus (PCLK),
//   where the bridge is the master, so it only monitors.
// - Routes s_vif / m_vif from tb_top to each agent as "vif": the agent, driver and monitor
//   never need to know which bus they are on, so the same classes serve both sides.
// - is_active is set through config_db before m_agent is created; uvm_agent reads it in its
//   own build_phase, which runs after this one (top-down).
class axi_lite_env extends uvm_env;
    `uvm_component_utils(axi_lite_env)

    axi_lite_agent s_agent;
    axi_vif_t s_vif;
    axi_lite_scoreboard sb;

    axi_lite_agent m_agent;
    axi_vif_t m_vif;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        if (!uvm_config_db#(axi_vif_t)::get(this, "", "s_vif", s_vif))
            `uvm_fatal("NOVIF", "env: no 's_vif' in config_db")

        s_agent = axi_lite_agent::type_id::create("s_agent", this);
        sb = axi_lite_scoreboard::type_id::create("sb", this);

        uvm_config_db#(axi_vif_t)::set(this, "s_agent.*", "vif", s_vif);

        if (!uvm_config_db#(axi_vif_t)::get(this, "", "m_vif", m_vif))
            `uvm_fatal("NOVIF", "env: no 'm_vif' in config_db")

        uvm_config_db#(uvm_active_passive_enum)::set(this, "m_agent", "is_active", UVM_PASSIVE);
        m_agent = axi_lite_agent::type_id::create("m_agent", this);
        uvm_config_db#(axi_vif_t)::set(this, "m_agent.*", "vif", m_vif);
        
    endfunction

    function void connect_phase(uvm_phase phase);

        super.connect_phase(phase);
        s_agent.ap.connect(sb.s_imp);
        m_agent.ap.connect(sb.m_imp);

    endfunction

endclass