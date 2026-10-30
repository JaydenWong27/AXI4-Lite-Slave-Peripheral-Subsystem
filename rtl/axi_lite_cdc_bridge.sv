module axi_lite_cdc_bridge #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int FIFO_ADDR_W = 2
    ) (
    axi_lite_if.slave s_axi,
    axi_lite_if.master m_axi,
);

    //packed widths for each channel
    localparam int AW_W = ADDR_WIDTH + 3;

    // AW channel ACLK -> PCLK
    logic aw_full;
    logic aw_empty;
    logic [AW_W-1:0] aw_rdata;

    async_fifo #(
        .DATA_W(AW_W),
        .ADDR_W(FIFO_ADDR_W)
    ) u_aw_fifo (
        // write side = s_axi (ACLK): master offers an address
        .wclk (s_axi.ACLK),
        .wrst_n (s_axi.ARESETN),
        .wr_en (s_axi.AWVALID),
        .wdata ({s_axi.AWPROT, s_axi.AWADDR}),
        .full (aw_full),
        // read side 
        .rclk (m_axi.ACLK),
        .rrst_n (m_axi.ARESETN),
        .rd_en (m_axi.AWREADY),
        .rdata (aw_rdata),
        .empty (aw_empty)
    );

    assign s_axi.AWREADY = !aw_full;
    assign m_axi.AWVALID = !aw_empty;
    assign {m_axi.AWPROT< m_axi.AWADDR} = aw_rdata;


endmodule