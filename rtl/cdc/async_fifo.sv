`default_nettype none

module async_fifo #(
    parameter int DATA_W = 8,
    parameter int ADDR_W = 2
) (

    // write side
    input logic wclk,
    input logic wrst_n,
    input logic wr_en,
    input logic [DATA_W-1:0] wdata,
    output logic full,

    // read side
    input logic rclk,
    input logic rrst_n,
    input logic rd_en,
    output logic [DATA_W-1:0] rdata,
    output logic empty

);

    logic [ADDR_W-1:0] waddr;
    logic [ADDR_W-1:0] raddr;

    logic [ADDR_W:0] wptr;
    logic [ADDR_W:0] rptr;
    logic [ADDR_W:0] wq2_rptr;
    logic [ADDR_W:0] rq2_wptr;

    fifo_wptr_full #(
        .ADDR_W(ADDR_W)
    ) fifo_wptr_full_inst (
        .wclk(wclk),
        .wrst_n(wrst_n),
        .wr_en(wr_en),
        .wq2_rptr(wq2_rptr),
        .full(full),
        .waddr(waddr),
        .wptr(wptr)
    );

    fifo_rptr_empty #(
        .ADDR_W(ADDR_W)
    ) fifo_rptr_empty_inst (
        .rclk(rclk),
        .rrst_n(rrst_n),
        .rd_en(rd_en),
        .rq2_wptr(rq2_wptr),
        .empty(empty),
        .raddr(raddr),
        .rptr(rptr)
    );

    fifo_mem #(
        .DATA_W(DATA_W),
        .ADDR_W(ADDR_W)
    ) fifo_mem_inst(
        .wclk(wclk),
        .wr_en(wr_en),
        .full(full),
        .waddr(waddr),
        .wdata(wdata),
        .raddr(raddr),
        .rdata(rdata)
    );

    sync_2ff #(
        .WIDTH(ADDR_W+1)
    ) sync_2ff_inst_w (
        .clk(wclk),
        .rst_n(wrst_n),
        .d(rptr),
        .q(wq2_rptr)
    );

    sync_2ff #(
        .WIDTH(ADDR_W+1)
    ) sync_2ff_inst_r (
        .clk(rclk),
        .rst_n(rrst_n),
        .d(wptr),
        .q(rq2_wptr)
    );

endmodule

`default_nettype wire