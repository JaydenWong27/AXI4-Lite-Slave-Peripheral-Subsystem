// Async FIFO storage: 2**ADDR_W words of DATA_W bits
// Written on wclk at waddr, read combinationally at raddr. Holds no pointers or flags.
//
// Why no reset on the array:
//   After reset the pointers are equal and empty is high, so no slot is ever read before
//   it has been written. A reset would only cost hardware: a non-resettable array can map
//   to FPGA LUTRAM, a resettable one needs a flip-flop per bit.
//
// Why the read is combinational:
//   rdata always shows the oldest entry (first-word-fall-through), so a consumer can use
//   VALID = !empty with zero latency and the payload stays stable until it is taken,
//   as the AXI handshake requires. Cost: can't use block RAM (needs a clocked read),
//   which doesn't matter at this depth.
//
// Why the write is also gated by !full:
//   The write pointer already stops at full, but blocking the memory write too means a
//   producer that ignores full still can't overwrite unread data (Cummings section 3.4).
`default_nettype none
module fifo_mem #(
    parameter int DATA_W = 8,
    parameter int ADDR_W = 2
)(
    input  logic              wclk,
    input  logic              wr_en,
    input  logic              full,
    input  logic [ADDR_W-1:0] waddr,
    input  logic [DATA_W-1:0] wdata,
    input  logic [ADDR_W-1:0] raddr,
    output logic [DATA_W-1:0] rdata
);

    localparam int DEPTH = 1 << ADDR_W;

    logic [DATA_W-1:0] mem [DEPTH];

    assign rdata = mem[raddr];

    always_ff @(posedge wclk) begin
        if (wr_en && !full) begin
            mem[waddr] <= wdata;
        end
    end

endmodule
`default_nettype wire
