class axi_lite_seq_item extends uvm_sequence_item;
    `uvm_object_utils(axi_lite_seq_item)

    // stimulus (rand: sequence randomizes these)

    rand bit is_write;
    rand bit [ADDR_WIDTH-1:0] addr;
    rand bit [DATA_WIDTH-1:0] data;
    rand bit [STRB_WIDTH-1:0] strb;
    rand int unsigned aw_delay;
    rand int unsigned w_delay;
    rand int unsigned ready_delay;

    // Response (filled by driver / monintor)

    logic [1:0] resp;

    // Constraints
    constraint c_align {
        addr[1:0] == 2'b00;
    }

    // expression must be true valid address multiple sof 4 so bottom 2 bits are always 0

    constraint c_addr {
        addr dist {
            [32'h0000_0000 : 32'h0000_000C] :/ 80, // 4 real registers
            [32'h0000_0010 : 32'h0000_00FC] :/ 10, // past the end -> SLVERR
            [32'h0000_0100 : 32'hFFFF_FFFC] :/ 10 // anywhere else -> SLVERR
        };
    }

    // dist means pick from these ranges
    // [a : b] range, inclusive both ends
     // :/ 80 means 80 split across whole range first range 80% the other two 10% each
     // third range is 4 billion address so would win almost every time and hardly ever test a real register

     // solver handles c align and caddr 

    constraint c_delay {
        aw_delay dist { 0:= 5, [1:3] :/ 3};
        w_delay dist { 0:= 5, [1:3] :/ 3};
        ready_delay dist { 0 := 5, [1:3] :/ 3};
    }

    // c delay two kinds of weigh tmixed together
    // 0: = 5 single value of 0 gets weight 5
    // [1:3] :/ 3, 3 split across 1,2 and 3 so weight 1 each 

    function new (string name = "axi_lite_seq_item");
        super.new(name);
    endfunction

    function string convert2string();
                return $sformatf("%s addr=0x%08h data=0x%08h strb=%b resp=%b",
                         is_write ? "WR" : "RD", addr, data, strb, resp);

    endfunction

endclass