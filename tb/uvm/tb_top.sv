`timescale 1ns/1ps
`default_nettype none

// UVM top: clocks, reset, DUT and interface. Everything else lives in classes.
// Drives no bus signal, driver owns them 
// hands interface to classes through config_db, since class can't have ports
// No $finish/watchdog: uvm ends when all objections drop 

module tb_top;

    import uvm_pkg::*;
    import axi_lite_pkg::*;
    `include "uvm_macros.svh"

    int aclk_period = 10;
    int pclk_period = 17;

    logic aclk;
    logic pclk;
    logic rst_n;
    logic [31:0] gpio_o;
    logic [31:0] gpio_oe_n;
    logic [31:0] gpio_i;

    axi_lite_if #(
        .ADDR_WIDTH(ADDR_WIDTH), 
        .DATA_WIDTH(DATA_WIDTH)
        ) bus (
        .ACLK(aclk),
        .ARESETN(rst_n)
    );

    axi_lite_gpio_system #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .pclk(pclk),
        .prst_n(rst_n),
        .axi_bus(bus),
        .gpio_o(gpio_o),
        .gpio_oe_n(gpio_oe_n),
        .gpio_i(gpio_i)
    );

    // Clock from +ACLK / +PCLK = plus args
    initial begin
        void'($value$plusargs("ACLK=%d", aclk_period));
        void'($value$plusargs("PCLK=%d", pclk_period));
        aclk = 1'b0;
        pclk = 1'b0;
        fork
            forever #(aclk_period/2.0) aclk = ~aclk;
            forever #(pclk_period/2.0) pclk = ~pclk;
        join_none
    end

    // One reset for both domains, held for 5 edges of each clock released on falling edge
    initial begin
        rst_n = 1'b0;
        gpio_i = GPIO_IN_VALUE;     // shared with the scoreboard via the package
        fork
            repeat (5) @(posedge aclk);
            repeat (5) @(posedge pclk);
        join
        @(negedge aclk);
        rst_n = 1'b1;
    end

    // hand interface to UVM class, then start test named by +UVM_TESTNAME
    initial begin
        uvm_config_db#(axi_vif_t)::set(null, "uvm_test_top.*", "s_vif", bus);
        uvm_config_db#(axi_vif_t)::set(null, "uvm_test_top.*", "m_vif", dut.m_bus);
        run_test();
    end

endmodule
`default_nettype wire