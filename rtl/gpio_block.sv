// Simple GPIO Block
// Controlled via a 32-bit register interface.
//
// Register Map (each field is one register):
//   [0] DATA_OUT    - Output data for GPIO pins
//   [1] DIRECTION   - Pin direction (1=output, 0=input)
//   [2] DATA_IN     - Sampled input data (read-only)
//   [3] CONFIG      - Reserved for future use
`default_nettype none
module gpio_block #(
    parameter int DATA_WIDTH = 32   // GPIO pin count
)(
    input  logic clk,
    input  logic rst_n,

    // Register interface from AXI slave
    input  logic [DATA_WIDTH-1:0] data_out_reg,
    input  logic [DATA_WIDTH-1:0] direction_reg,

    // GPIO pins (open-drain or tri-state capable)
    output logic [DATA_WIDTH-1:0] gpio_o,      // Output values
    output logic [DATA_WIDTH-1:0] gpio_oe_n,   // Output enable (active low)
    input  logic [DATA_WIDTH-1:0] gpio_i,       // Input samples

    // output port
    output logic [DATA_WIDTH-1:0] gpio_in_sync
);

    // Simple combinational logic: drive outputs based on registers
    // gpio_oe_n = 0 means drive (output enabled), 1 means high-Z (input)
    assign gpio_oe_n = ~direction_reg;
    assign gpio_o = data_out_reg & direction_reg;  // Only drive when output-enabled


    // Input sampling: gpio_i is asynchronous, so pass it through a two-flop synchronizer
    sync_2ff #(
        .WIDTH(DATA_WIDTH)
    ) gpio_in_sync_inst (
        .clk(clk),
        .rst_n(rst_n),
        .d(gpio_i),
        .q(gpio_in_sync)
    );

endmodule
`default_nettype wire
