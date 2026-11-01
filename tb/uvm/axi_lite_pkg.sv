
package axi_lite_pkg;

import uvm_pkg::*;
`include "uvm_macros.svh"

localparam int ADDR_WIDTH = 32;
localparam int DATA_WIDTH = 32;
localparam int STRB_WIDTH = DATA_WIDTH/8;


localparam logic [1:0] OKAY = 2'b00;
localparam logic [1:0] SLVERR = 2'b10;
localparam int DATA_IN_IDX = 2;                       // register 2 (0x8) is read-only
localparam logic [31:0] GPIO_IN_VALUE = 32'hA5A5_5A5A; // tb_top drives gpio_i with this

typedef virtual axi_lite_if axi_vif_t;

`include "axi_lite_seq_item.sv"
`include "axi_lite_sequencer.sv"
`include "axi_lite_driver.sv"
`include "axi_lite_monitor.sv"
`include "axi_lite_agent.sv"
`include "axi_lite_scoreboard.sv"
`include "axi_lite_coverage.sv"
`include "axi_lite_env.sv"
`include "axi_lite_sequences.sv"
`include "axi_lite_tests.sv"

endpackage
