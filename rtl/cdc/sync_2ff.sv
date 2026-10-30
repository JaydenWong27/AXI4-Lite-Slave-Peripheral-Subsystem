// Two-flop synchronizer
//
// Why two flops and not one:
//   d is asynchronous to clk, so it can change right at the sampling edge and the first
//   flop can go metastable (output stuck between 0 and 1 for an unpredictable time).
//   With one flop, that unsettled value would go straight into downstream logic, and
//   different gates could read it differently. The second flop gives the first a full
//   clock period to settle, which makes a metastable value reaching the logic very unlikely.
//
// Why d must be a single bit or a Gray-coded value:
//   Each bit of a bus is sampled independently, and the bits don't change at exactly the
//   same instant. A multi-bit binary value changing near the edge can be captured as a mix
//   of old and new bits. A single bit can only be captured as old or new.
//   Gray code changes only one bit per source clock, so the captured value is always the
//   old count or the new count, never a mix. The destination may still see several steps
//   between its own edges when the source clock is faster; that's fine, because only the
//   latest change can land near the destination's edge.
//
// ASYNC_REG tells Vivado these flops are a synchronizer, so it places them close together.
`default_nettype none
module sync_2ff #(
    parameter int WIDTH = 1
)(
    input  logic             clk,
    input  logic             rst_n,
    input  logic [WIDTH-1:0] d,
    output logic [WIDTH-1:0] q
);

    (* ASYNC_REG = "TRUE" *) logic [WIDTH-1:0] q1;
    (* ASYNC_REG = "TRUE" *) logic [WIDTH-1:0] q2;

    assign q = q2;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            q1 <= '0;
            q2 <= '0;
        end else begin
            q1 <= d;
            q2 <= q1;
        end
    end

endmodule
`default_nettype wire
