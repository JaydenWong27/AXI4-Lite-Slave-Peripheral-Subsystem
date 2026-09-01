# AXI-Lite Bus

Project goal: build an AXI4-Lite bus implementation.

AXI4-Lite is a memory-mapped AMBA AXI4 subset intended for simple register access. It does not support burst transfers. The interface is split into five independent channels:

- Read Address
- Read Data
- Write Address
- Write Data
- Write Response

All channels use a `VALID` / `READY` handshake. A transfer on a channel completes on a rising clock edge when both signals are asserted.

## Project Layout

- `docs/` - protocol notes and design planning
- `rtl/` - synthesizable SystemVerilog source files
- `tb/` - testbench files
- `sim/` - simulator notes and scripts
- `constraints/` - FPGA constraint files

## Planned RTL Files

- `rtl/axi_lite_if.sv` - AXI4-Lite interface definition
- `rtl/axi_lite_master.sv` - master-side transaction source
- `rtl/axi_lite_slave.sv` - slave-side register target
- `rtl/axi_lite_interconnect.sv` - bus/interconnect top level

## Current Status

Implemented:

- AXI4-Lite SystemVerilog interface
- Basic AXI4-Lite slave with 4 32-bit registers
- Byte write strobe support through `WSTRB`
- Independent write address and write data channel handling
- Valid address `OKAY` responses
- Invalid address `SLVERR` responses
- Verilator testbench with VCD waveform output


## Run Simulation

From the project root:

```sh
verilator -sv --timing --binary --trace rtl/axi_lite_if.sv rtl/axi_lite_slave.sv tb/axi_lite_tb.sv --top-module axi_lite_tb
./obj_dir/Vaxi_lite_tb
```

Expected output:

```text
readback passed: 0xdeadbeef
WSTRB test passed: 0xdead5678
Register 1 test passed: 0xcafebabe
Address-first write passed: 0x11112222
Data-first write passed: 0x33334444
Invalid write correctly returned SLVERR
Invalid read correctly returned SLVERR
```

## View Waveforms

The testbench writes:

```text
axi_lite_tb.vcd
```

Open it with GTKWave:

```sh
gtkwave axi_lite_tb.vcd
```

Useful signals to inspect:

- `ACLK`
- `ARESETN`
- `AWADDR[31:0]`
- `AWVALID`
- `AWREADY`
- `WDATA[31:0]`
- `WSTRB[3:0]`
- `WVALID`
- `WREADY`
- `BRESP[1:0]`
- `BVALID`
- `BREADY`
- `ARADDR[31:0]`
- `ARVALID`
- `ARREADY`
- `RDATA[31:0]`
- `RRESP[1:0]`
- `RVALID`
- `RREADY`
