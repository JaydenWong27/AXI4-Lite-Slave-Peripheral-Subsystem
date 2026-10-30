// Async FIFO read side: read pointer and empty flag
// Everything in this module lives in the read clock domain (rclk).
// Mirror of fifo_wptr_full: rbin is the binary read pointer (one extra wrap bit),
// raddr addresses fifo_mem, rptr is the Gray read pointer sent to the write side.
//
// Why empty resets to 1:
//   After reset both pointers are 0, so the FIFO really is empty. If empty reset to 0,
//   a consumer using VALID = !empty would take junk data from the memory on the first cycle.
//
// Why empty is a plain comparison (no bit inversion like full):
//   Equal pointers, including the wrap bit, mean the reader has caught up with the writer
//   on the same lap. Equal binary values always give equal Gray values, so a direct
//   compare works. Only full needs the top-two-bit inversion.
//
// The read pointer only advances on rd_en && !empty, so reading an empty FIFO
// can't move the read pointer past the write pointer (underflow protection).
// empty_val compares the NEXT Gray pointer so the registered empty flag is on time.
`default_nettype none
module fifo_rptr_empty #(
    parameter int ADDR_W = 2
)(
    input  logic              rclk,
    input  logic              rrst_n,
    input  logic              rd_en,
    input  logic [ADDR_W:0]   rq2_wptr,   // write pointer synchronized into rclk
    output logic              empty,
    output logic [ADDR_W-1:0] raddr,
    output logic [ADDR_W:0]   rptr        // Gray read pointer sent to the write side
);

    logic [ADDR_W:0] rbin;
    logic [ADDR_W:0] rbinnext;
    logic [ADDR_W:0] rgraynext;
    logic            empty_val;

    always_ff @(posedge rclk or negedge rrst_n) begin
        if (!rrst_n) begin
            rbin  <= '0;
            rptr  <= '0;
            empty <= 1'b1;
        end else begin
            rbin  <= rbinnext;
            rptr  <= rgraynext;
            empty <= empty_val;
        end
    end

    assign rbinnext  = rbin + (ADDR_W+1)'(rd_en & ~empty);
    assign rgraynext = (rbinnext >> 1) ^ rbinnext;
    assign raddr     = rbin[ADDR_W-1:0];
    assign empty_val = (rgraynext == rq2_wptr);

endmodule
`default_nettype wire
