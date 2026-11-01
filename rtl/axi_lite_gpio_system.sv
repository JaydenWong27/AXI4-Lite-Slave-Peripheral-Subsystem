// AXI-Lite GPIO System Integration
// Example of wiring an AXI-Lite slave with a GPIO block.
`default_nettype none
module axi_lite_gpio_system #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int NUM_REGS = 4,
    parameter int GPIO_WIDTH = 32
)(
    input  logic pclk,
    input  logic prst_n,

    // AXI-Lite bus interface
    axi_lite_if.slave axi_bus,

    // GPIO pins
    output logic [GPIO_WIDTH-1:0] gpio_o,
    output logic [GPIO_WIDTH-1:0] gpio_oe_n,
    input  logic [GPIO_WIDTH-1:0] gpio_i

);

    logic [GPIO_WIDTH-1:0] reg_out0;
    logic [GPIO_WIDTH-1:0] reg_out1;
    logic [GPIO_WIDTH-1:0] gpio_in_sync;

    logic prst_n_sync;

    // Instantiate AXI-Lite slave
    axi_lite_slave #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_REGS(NUM_REGS)
    ) slave_inst (
        .bus(m_bus),
        .reg_out0(reg_out0),
        .reg_out1(reg_out1),
        .gpio_in(gpio_in_sync)
    );

    // Instantiate GPIO block
    gpio_block #(
        .DATA_WIDTH(GPIO_WIDTH)
    ) gpio_inst (
        .clk(pclk),
        .rst_n(prst_n_sync),
        .data_out_reg(reg_out0),      // Register 0: data output
        .direction_reg(reg_out1),     // Register 1: direction (1=output)
        .gpio_in_sync(gpio_in_sync),
        .gpio_o(gpio_o),
        .gpio_oe_n(gpio_oe_n),
        .gpio_i(gpio_i)
    );

    axi_lite_if #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) m_bus (
        .ACLK(pclk),
        .ARESETN(prst_n_sync)
    );

    rst_sync u_prst_sync (
        .clk(pclk),
        .arst_n(prst_n),
        .rst_n_sync(prst_n_sync)
    );

    axi_lite_cdc_bridge #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_bridge (
        .s_axi(axi_bus),
        .m_axi(m_bus)
    );

endmodule
`default_nettype wire
