// AXI4-Lite Slave Register Module
// Implements a configurable register file accessible via AXI-Lite write and read transactions.
//
// Features:
//   - Configurable number of 32-bit registers
//   - Byte-granular write strobes (WSTRB support)
//   - Write buffering (address and data decoupled)
//   - Address range checking with error response (SLVERR)
//
// Address Mapping:
//   Registers are word-aligned at offsets 0x0, 0x4, 0x8, ..., up to (NUM_REGS-1)*4.
//   Register 2 (0x8) is read-only and returns gpio_in; writes to it return SLVERR.
//   Out-of-range accesses return an error response and do not modify registers.
`default_nettype none
module axi_lite_slave #(
    parameter int ADDR_WIDTH = 32,      // AXI address bus width (typically 32)
    parameter int DATA_WIDTH = 32,      // AXI data bus width (must be multiple of 8)
    parameter int NUM_REGS = 4          // Number of 32-bit registers to implement
)(
    axi_lite_if.slave bus,
    output logic [DATA_WIDTH-1:0] reg_out0,   // Register 0 to GPIO data out
    output logic [DATA_WIDTH-1:0] reg_out1,   // Register 1 to GPIO direction
    input  logic [DATA_WIDTH-1:0] gpio_in     // Synchronized GPIO input, read at register 2
);

    // Register 2 is the read-only GPIO input register
    localparam int GPIO_IN_IDX = 2;

    // Register storage: array of NUM_REGS words
    logic [DATA_WIDTH-1:0] regs [NUM_REGS];

    assign reg_out0 = regs[0];
    assign reg_out1 = regs[1];

    // Derived parameters for address decoding
    localparam int ADDR_LSB = $clog2(DATA_WIDTH / 8);          // Bit offset of first register index bit
    localparam int REG_INDEX_WIDTH = $clog2(NUM_REGS);         // Width of register index

    // Write channel: buffered address and data (decoupled per AXI spec)
    logic [ADDR_WIDTH-1:0] write_addr;
    logic [DATA_WIDTH-1:0] write_data;
    logic [(DATA_WIDTH/8)-1:0] write_strb;
    logic write_addr_valid;
    logic write_data_valid;

    // Decoded write index
    logic [REG_INDEX_WIDTH-1:0] write_index;

    // Address range validation
    logic write_addr_in_range;
    logic read_addr_in_range;

    assign write_index = write_addr[ADDR_LSB +: REG_INDEX_WIDTH];
    assign write_addr_in_range = write_addr[ADDR_WIDTH-1:ADDR_LSB] < (ADDR_WIDTH-ADDR_LSB)'(NUM_REGS);
    assign read_addr_in_range = bus.ARADDR[ADDR_WIDTH-1:ADDR_LSB] < (ADDR_WIDTH-ADDR_LSB)'(NUM_REGS);

    always_ff @(posedge bus.ACLK or negedge bus.ARESETN) begin
        if (!bus.ARESETN) begin
            // Reset all AXI control signals and registers
            bus.AWREADY <= 1'b0;
            bus.WREADY  <= 1'b0;
            bus.BVALID  <= 1'b0;
            bus.BRESP   <= 2'b00;

            bus.ARREADY <= 1'b0;
            bus.RVALID  <= 1'b0;
            bus.RRESP   <= 2'b00;
            bus.RDATA   <= '0;

            write_addr_valid <= 1'b0;
            write_data_valid <= 1'b0;

            for (int i = 0; i < NUM_REGS; i++) begin
                regs[i] <= '0;
            end

        end else begin
            // Default: deassert ready signals (will reassert if applicable)
            bus.AWREADY <= 1'b0;
            bus.WREADY <= 1'b0;
            bus.ARREADY <= 1'b0;

            // Write address capture: wait for AWVALID when no address is pending
            if (!write_addr_valid && bus.AWVALID) begin
                bus.AWREADY <= 1'b1;
                write_addr <= bus.AWADDR;
                write_addr_valid <= 1'b1;
            end

            // Write data capture: wait for WVALID when no data is pending
            if (!write_data_valid && bus.WVALID) begin
                bus.WREADY <= 1'b1;
                write_data <= bus.WDATA;
                write_strb <= bus.WSTRB;
                write_data_valid <= 1'b1;
            end

            // Write response: when both address and data are valid, perform write and send response
            if (write_addr_valid && write_data_valid && !bus.BVALID) begin
                if (write_addr_in_range && write_index != GPIO_IN_IDX) begin
                    // Byte-granular write: only update bytes indicated by WSTRB
                    for (int byte_idx = 0; byte_idx < DATA_WIDTH / 8; byte_idx++) begin
                        if (write_strb[byte_idx]) begin
                            regs[write_index][byte_idx*8 +: 8] <= write_data[byte_idx*8 +: 8];
                        end
                    end
                    bus.BRESP <= 2'b00;  // OKAY response
                end else begin
                    bus.BRESP <= 2'b10;  // SLVERR: out of range or read-only register
                end

                bus.BVALID <= 1'b1;
                write_addr_valid <= 1'b0;
                write_data_valid <= 1'b0;
            end

            // Write response handshake: clear BVALID when master acknowledges
            if (bus.BVALID && bus.BREADY) begin
                bus.BVALID <= 1'b0;
            end

            // Read address handshake, then read response one cycle later
            // (RVALID must not assert until the AR handshake has completed)
            if (bus.ARVALID && !bus.ARREADY && !bus.RVALID) begin
                bus.ARREADY <= 1'b1;
            end

            if (bus.ARVALID && bus.ARREADY) begin
                if (read_addr_in_range) begin
                    if (bus.ARADDR[ADDR_LSB +: REG_INDEX_WIDTH] != GPIO_IN_IDX) begin
                        bus.RDATA <= regs[bus.ARADDR[ADDR_LSB +: REG_INDEX_WIDTH]];
                    end else begin
                        bus.RDATA <= gpio_in;
                    end
                    bus.RRESP <= 2'b00;  // OKAY
                end else begin
                    bus.RDATA <= '0;
                    bus.RRESP <= 2'b10;  // SLVERR
                end
                bus.RVALID  <= 1'b1;
                bus.ARREADY <= 1'b0;
            end

            // Read data handshake: clear RVALID when master acknowledges
            if (bus.RVALID && bus.RREADY) begin
                bus.RVALID <= 1'b0;
            end
        end
    end

endmodule
`default_nettype wire
