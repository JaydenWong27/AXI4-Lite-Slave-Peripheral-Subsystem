`default_nettype none

module axi_lite_cdc_bridge #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int FIFO_ADDR_W = 2
    ) (
    axi_lite_if.slave s_axi,
    axi_lite_if.master m_axi
);

    //packed widths for each channel
    localparam int AW_W = ADDR_WIDTH + 3;


    // =========================
    // AW channel ACLK -> PCLK
    // =========================
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
    assign {m_axi.AWPROT, m_axi.AWADDR} = aw_rdata;

    // ======================

    //32 data bits plus 4 strobe bits
    //W Channel 
    // ======================
    localparam W_W = DATA_WIDTH + DATA_WIDTH / 8;

    logic w_full;
    logic w_empty;
    logic [W_W-1:0] w_rdata;


    async_fifo #(
        .DATA_W(W_W),
        .ADDR_W(FIFO_ADDR_W)
    ) u_w_fifo (
        // write side = s_axi (ACLK): master offers an address
        .wclk (s_axi.ACLK),
        .wrst_n (s_axi.ARESETN),
        .wr_en (s_axi.WVALID),
        .wdata ({s_axi.WSTRB, s_axi.WDATA}),
        .full (w_full),
        // read side 
        .rclk (m_axi.ACLK),
        .rrst_n (m_axi.ARESETN),
        .rd_en (m_axi.WREADY),
        .rdata (w_rdata),
        .empty (w_empty)
    );

    assign s_axi.WREADY = !w_full;
    assign m_axi.WVALID = !w_empty;
    assign {m_axi.WSTRB, m_axi.WDATA} = w_rdata;
    
    // ====================================
    // AR Channel 
    // ====================================

    localparam int AR_W = ADDR_WIDTH + 3;

    logic ar_full;
    logic ar_empty;
    logic [AR_W-1:0] ar_rdata;

    async_fifo #(
        .DATA_W(AR_W),
        .ADDR_W(FIFO_ADDR_W)
    ) u_ar_fifo (
        // write side = s_axi (ACLK): master offers an address
        .wclk (s_axi.ACLK),
        .wrst_n (s_axi.ARESETN),
        .wr_en (s_axi.ARVALID),
        .wdata ({s_axi.ARPROT, s_axi.ARADDR}),
        .full (ar_full),
        // read side 
        .rclk (m_axi.ACLK),
        .rrst_n (m_axi.ARESETN),
        .rd_en (m_axi.ARREADY),
        .rdata (ar_rdata),
        .empty (ar_empty)
    );

    assign s_axi.ARREADY = !ar_full;
    assign m_axi.ARVALID = !ar_empty;
    assign {m_axi.ARPROT, m_axi.ARADDR} = ar_rdata;

    // ================================
    // B Channel
    // =================================

    localparam int B_W = 2;

    logic b_full;
    logic b_empty;
    logic [B_W-1:0] b_rdata;

    async_fifo #(
        .DATA_W(B_W),
        .ADDR_W(FIFO_ADDR_W)
    ) u_b_fifo (
        // write side = m_axi (PCLK): slave offers responise
        .wclk (m_axi.ACLK),
        .wrst_n (m_axi.ARESETN),
        .wr_en (m_axi.BVALID),
        .wdata (m_axi.BRESP),
        .full (b_full),
        // read side 
        .rclk (s_axi.ACLK),
        .rrst_n (s_axi.ARESETN),
        .rd_en (s_axi.BREADY),
        .rdata (b_rdata),
        .empty (b_empty)
    );

    assign m_axi.BREADY = !b_full;
    assign s_axi.BVALID = !b_empty;
    assign s_axi.BRESP = b_rdata;


    // ================================
    // R Channel
    // =================================

    localparam int R_W = DATA_WIDTH + 2;

    logic r_full;
    logic r_empty;
    logic [R_W-1:0] r_rdata;

    async_fifo #(
        .DATA_W(R_W),
        .ADDR_W(FIFO_ADDR_W)
    ) u_r_fifo (
        // write side = s_axi (ACLK): master offers an address
        .wclk (m_axi.ACLK),
        .wrst_n (m_axi.ARESETN),
        .wr_en (m_axi.RVALID),
        .wdata ({m_axi.RRESP, m_axi.RDATA}),
        .full (r_full),
        // read side 
        .rclk (s_axi.ACLK),
        .rrst_n (s_axi.ARESETN),
        .rd_en (s_axi.RREADY),
        .rdata (r_rdata),
        .empty (r_empty)
    );

    assign m_axi.RREADY = !r_full;
    assign s_axi.RVALID = !r_empty;
    assign {s_axi.RRESP, s_axi.RDATA} = r_rdata;


endmodule

`default_nettype wire