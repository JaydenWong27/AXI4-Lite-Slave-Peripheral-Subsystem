interface axi_lite_if #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
)(
    input logic ACLK,
    input logic ARESETN
);

    localparam int STRB_WIDTH = DATA_WIDTH / 8;

    // Write address channel
    logic [ADDR_WIDTH-1:0] AWADDR;
    logic [2:0] AWPROT;
    logic AWVALID;
    logic AWREADY;

    // Write data channel
    logic [DATA_WIDTH-1:0] WDATA;
    logic [STRB_WIDTH-1:0] WSTRB;
    logic WVALID;
    logic WREADY;

    // Write response channel
    logic [1:0] BRESP;
    logic BVALID;
    logic BREADY;

    // Read address channel
    logic [ADDR_WIDTH-1:0] ARADDR;
    logic [2:0] ARPROT;
    logic ARVALID;
    logic ARREADY;

    // Read data channel
    logic [DATA_WIDTH-1:0] RDATA;
    logic [1:0] RRESP;
    logic RVALID;
    logic RREADY;

    modport master (
        input ACLK,
        input ARESETN,

        output AWADDR,
        output AWPROT,
        output AWVALID,
        input AWREADY,

        output WDATA,
        output WSTRB,
        output WVALID,
        input WREADY,

        input BRESP,
        input BVALID,
        output BREADY,

        output ARADDR,
        output ARPROT,
        output ARVALID,
        input ARREADY,

        input RDATA,
        input RRESP,
        input RVALID,
        output RREADY
    );

    modport slave (
        input ACLK,
        input ARESETN,

        input AWADDR,
        input AWPROT,
        input AWVALID,
        output AWREADY,

        input WDATA,
        input WSTRB,
        input WVALID,
        output WREADY,

        output BRESP,
        output BVALID,
        input BREADY,

        input ARADDR,
        input ARPROT,
        input ARVALID,
        output ARREADY,

        output RDATA,
        output RRESP,
        output RVALID,
        input RREADY
    );

endinterface
