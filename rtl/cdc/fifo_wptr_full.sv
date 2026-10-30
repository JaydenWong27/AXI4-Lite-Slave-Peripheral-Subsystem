// Async FIFO write side: write pointer and full flag
// Everything in this module lives in the write clock domain (wclk).
//
// wbin is the binary write pointer, one bit wider than the memory address.
// It increments by one each time a write is accepted (wr_en && !full).
// waddr is the lower ADDR_W bits of wbin, used to address fifo_mem.
// wbinnext / wgraynext are the values wbin / wptr will take on the next clock.
//
// Why the pointer is one bit wider than the address:
//   Equal addresses could mean empty (reader caught up) or full (writer lapped the reader).
//   The extra MSB counts wraps: same MSB = same number of wraps = empty,
//   different MSB = writer is one lap ahead = full.
//
// Why binary for waddr but Gray for wptr:
//   waddr never leaves the wclk domain, so plain binary is fine.
//   wptr is sent to the read domain through sync_2ff. Gray code changes one bit per
//   increment, so the read side always captures either the old or the new value, never a mix.
//
// Why full inverts the top TWO bits (not just the MSB as with binary pointers):
//   Reflected Gray code mirrors its lower half about the midpoint, so after one lap the
//   second MSB is also inverted. Full = MSB differs, 2nd MSB differs, all other bits equal.
//   (Cummings, SNUG 2002, section 5.2 / Figure 6)
//
// full_val compares the NEXT Gray pointer, so the registered full flag is on time.
// Comparing the current pointer would make full one cycle late and allow an overflow write.
`default_nettype none
module fifo_wptr_full #(
    parameter int ADDR_W = 2
)(
    input  logic              wclk,
    input  logic              wrst_n,
    input  logic              wr_en,
    input  logic [ADDR_W:0]   wq2_rptr,   // read pointer synchronized into wclk
    output logic              full,
    output logic [ADDR_W-1:0] waddr,
    output logic [ADDR_W:0]   wptr        // Gray write pointer sent to the read side
);

    // The full comparison slices wq2_rptr[ADDR_W-2:0], which needs ADDR_W >= 2
    initial assert (ADDR_W >= 2) else $fatal(1, "fifo_wptr_full: ADDR_W must be >= 2");

    logic [ADDR_W:0] wbin;
    logic [ADDR_W:0] wbinnext;
    logic [ADDR_W:0] wgraynext;
    logic            full_val;

    always_ff @(posedge wclk or negedge wrst_n) begin
        if (!wrst_n) begin
            wbin <= '0;
            wptr <= '0;
            full <= 1'b0;
        end else begin
            wbin <= wbinnext;
            wptr <= wgraynext;
            full <= full_val;
        end
    end

    assign wbinnext  = wbin + (ADDR_W+1)'(wr_en & ~full);
    assign wgraynext = (wbinnext >> 1) ^ wbinnext;
    assign waddr     = wbin[ADDR_W-1:0];
    assign full_val  = (wgraynext == {~wq2_rptr[ADDR_W:ADDR_W-1], wq2_rptr[ADDR_W-2:0]});

endmodule
`default_nettype wire
