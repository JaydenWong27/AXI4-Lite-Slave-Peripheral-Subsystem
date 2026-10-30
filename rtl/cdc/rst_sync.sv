`default_nettype none
module rst_sync (
    input  logic clk,
    input  logic arst_n,
    output logic rst_n_sync
);

    (* ASYNC_REG = "TRUE" *) logic rst_q1;
    (* ASYNC_REG = "TRUE" *) logic rst_q2;

    assign rst_n_sync = rst_q2;

    always_ff @(posedge clk or negedge arst_n) begin
        if (!arst_n) begin
            rst_q1 <= 1'b0;
            rst_q2 <= 1'b0;
        end else begin
            rst_q1 <= 1'b1;
            rst_q2 <= rst_q1;
        end
    end

endmodule
`default_nettype wire
