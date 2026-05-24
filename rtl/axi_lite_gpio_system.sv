// AXI-Lite GPIO System Integration
// Example of wiring an AXI-Lite slave with a GPIO block.

module axi_lite_gpio_system #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int NUM_REGS = 4,
    parameter int GPIO_WIDTH = 32
)(
    input  logic clk,
    input  logic rst_n,

    // AXI-Lite bus interface
    axi_lite_if.slave axi_bus,

    // GPIO pins
    output logic [GPIO_WIDTH-1:0] gpio_o,
    output logic [GPIO_WIDTH-1:0] gpio_oe_n,
    input  logic [GPIO_WIDTH-1:0] gpio_i
);

    // Instantiate AXI-Lite slave
    axi_lite_slave #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_REGS(NUM_REGS)
    ) slave_inst (
        .bus(axi_bus)
    );

    // Instantiate GPIO block
    gpio_block #(
        .DATA_WIDTH(GPIO_WIDTH)
    ) gpio_inst (
        .clk(axi_bus.ACLK),
        .rst_n(axi_bus.ARESETN),
        .data_out_reg(slave_inst.regs[0]),      // Register 0: data output
        .direction_reg(slave_inst.regs[1]),     // Register 1: direction (1=output)
        .gpio_o(gpio_o),
        .gpio_oe_n(gpio_oe_n),
        .gpio_i(gpio_i)
    );

    // Register 2 is reserved for GPIO input samples (optional, would require feedback logic)
    // Register 3 is reserved for future use

endmodule
