// Simple GPIO Block
// Controlled via a 32-bit register interface.
//
// Register Map (each field is one register):
//   [0] DATA_OUT    - Output data for GPIO pins
//   [1] DIRECTION   - Pin direction (1=output, 0=input)
//   [2] DATA_IN     - Sampled input data (read-only)
//   [3] CONFIG      - Reserved for future use

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
    input  logic [DATA_WIDTH-1:0] gpio_i       // Input samples
);

    // Simple combinational logic: drive outputs based on registers
    // gpio_oe_n = 0 means drive (output enabled), 1 means high-Z (input)
    assign gpio_oe_n = ~direction_reg;
    assign gpio_o = data_out_reg & direction_reg;  // Only drive when output-enabled

    // Input sampling: capture external GPIO state synchronously
    logic [DATA_WIDTH-1:0] gpio_sync;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            gpio_sync <= '0;
        end else begin
            gpio_sync <= gpio_i;
        end
    end

    // Export synchronized input for reads (would be register[2] in slave)
    // Note: In integration, connect this back to slave.regs[2] for software to read

endmodule
