// Tests: pick which env to build and which sequence to run.
// - Components (part of the tree), so new() takes a parent.
// - The objection keeps run_phase alive until the sequence finishes; without it the
//   simulation ends at time 0.
// - seq.start(sqr) runs the sequence's body() on that sequencer and returns when it is done.
class axi_lite_base_test extends uvm_test;
    `uvm_component_utils(axi_lite_base_test)

    axi_lite_env env;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = axi_lite_env::type_id::create("env", this);
    endfunction

    task run_phase(uvm_phase phase);
        axi_lite_basic_seq seq;     // declarations must come before any statement

        phase.raise_objection(this);
        seq = axi_lite_basic_seq::type_id::create("seq");
        seq.start(env.s_agent.sqr);
        phase.drop_objection(this);
    endtask

endclass

class axi_lite_random_test extends axi_lite_base_test;
    `uvm_component_utils(axi_lite_random_test)

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    task run_phase(uvm_phase phase);
        axi_lite_random_seq seq;
        phase.raise_objection(this);
        seq = axi_lite_random_seq::type_id::create("seq");
        if (!seq.randomize())
            `uvm_fatal("RAND", "seq randomize failed")
        seq.start(env.s_agent.sqr);
        phase.drop_objection(this);
    endtask
endclass

// Directed cases (reset values, WSTRB, AW/W skew, read-only, out of range).
// The sequence has no rand fields, so no seq.randomize() here.
class axi_lite_directed_test extends axi_lite_base_test;
    `uvm_component_utils(axi_lite_directed_test)

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    task run_phase(uvm_phase phase);
        axi_lite_directed_seq seq;
        phase.raise_objection(this);
        seq = axi_lite_directed_seq::type_id::create("seq");
        seq.start(env.s_agent.sqr);
        phase.drop_objection(this);
    endtask
endclass
