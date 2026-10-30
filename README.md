# AXI4-Lite Clock-Domain-Crossing Peripheral Subsystem

A SystemVerilog AXI4-Lite register peripheral with GPIO, being extended into an **AXI4-Lite clock-domain-crossing bridge**: the AXI bus runs on one clock, the registers and GPIO on another, and asynchronous FIFOs carry requests and responses between them. This is the same pattern as Xilinx's AXI Clock Converter IP.

Verification is planned in two layers: fast directed testbenches (Verilator / Vivado xsim), then a UVM environment with an AXI-Lite agent, scoreboard, functional coverage and SVA.

## Architecture

```
 ACLK domain                                        PCLK domain
┌──────────────┐     ┌──────────────────────┐     ┌──────────────────┐     ┌────────────┐
│ AXI master   │────►│ axi_lite_cdc_bridge  │────►│ axi_lite_slave   │────►│ gpio_block │
│ (testbench)  │◄────│  5 x async_fifo      │◄────│ 4 x 32-bit regs  │◄────│            │
└──────────────┘     └──────────────────────┘     └──────────────────┘     └────────────┘
```

The bridge uses one async FIFO per AXI channel. Requests (AW, W, AR) cross from ACLK to PCLK; responses (B, R) cross back. Each FIFO's handshake maps directly onto AXI: `wr_en = VALID`, `READY = !full`, `VALID = !empty`, `rd_en = READY`. The FIFOs are first-word-fall-through, so payloads stay stable until accepted, as AXI requires.

### Async FIFO

Follows Cummings, *"Simulation and Synthesis Techniques for Asynchronous FIFO Design"* (SNUG 2002):

- Binary pointers address the memory; Gray-coded pointers cross clock domains through two-flop synchronizers clocked by the destination domain.
- Pointers carry one extra wrap bit to tell full from empty.
- `full` compares the next write Gray pointer against the synchronized read pointer with its top two bits inverted; `empty` is a direct comparison. Both flags are registered, assert exactly on time and clear conservatively late.
- Writes are blocked when full and reads when empty, so the FIFO can't overflow or underflow even if the producer or consumer ignores the flags.

## Register Map

| Offset | Name | Access | Description |
|---|---|---|---|
| `0x0` | DATA_OUT | RW | GPIO output values |
| `0x4` | DIRECTION | RW | Pin direction, 1 = output |
| `0x8` | DATA_IN | RO | Synchronized GPIO input. Writes return `SLVERR` |
| `0xC` | CONFIG | RW | Reserved |

Accesses at `0x10` and above return `SLVERR` (reads return 0).

## Status

| Component | Status |
|---|---|
| AXI4-Lite interface, register slave, WSTRB, SLVERR responses | Done, verified (Verilator) before the latest changes |
| GPIO block with 2-flop input synchronizer, read-only DATA_IN register | Written, not yet re-simulated |
| Async FIFO (`rtl/cdc/`) and reset synchronizer | Written, not yet simulated |
| Async FIFO directed testbench | Written, not yet run |
| AXI CDC bridge | In progress |
| Two-clock system top level and system testbench | Planned |
| UVM environment (agent, scoreboard, coverage, assertions) | Planned |
| CDC timing constraints | Planned |

## Project Layout

```
rtl/
  axi_lite_if.sv            AXI4-Lite interface (master/slave modports)
  axi_lite_slave.sv         Register slave
  gpio_block.sv             GPIO with input synchronizer
  axi_lite_gpio_system.sv   Top level (being converted to two clocks)
  axi_lite_cdc_bridge.sv    AXI clock-crossing bridge (in progress)
  cdc/
    sync_2ff.sv             Two-flop synchronizer
    rst_sync.sv             Reset synchronizer (async assert, sync deassert)
    fifo_mem.sv             FIFO storage
    fifo_wptr_full.sv       Write pointer and full flag (write clock domain)
    fifo_rptr_empty.sv      Read pointer and empty flag (read clock domain)
    async_fifo.sv           Async FIFO top level
tb/
  axi_lite_tb.sv            Directed testbench for the register slave
  async_fifo_tb.sv          Directed testbench for the async FIFO
docs/                       Protocol notes
constraints/                FPGA constraints (planned)
```

## Running the Simulations

### Register slave (Verilator)

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
Register outputs passed: reg_out0=0x11112222 reg_out1=0xcafebabe
GPIO input read passed: 0xa5a55a5a
Read-only write correctly returned SLVERR
Invalid write correctly returned SLVERR
Invalid read correctly returned SLVERR
```

The testbench writes `axi_lite_tb.vcd`; open it with `gtkwave axi_lite_tb.vcd`.

### Async FIFO (Vivado xsim)

The testbench runs a fill phase (overflow check), a drain phase (underflow check) and a random phase with both clocks running, checking every word against a queue-based reference model. Clock periods are set from the command line, so the same test covers fast-write/slow-read and the reverse:

```sh
xvlog -sv rtl/cdc/sync_2ff.sv rtl/cdc/fifo_mem.sv rtl/cdc/fifo_wptr_full.sv rtl/cdc/fifo_rptr_empty.sv rtl/cdc/async_fifo.sv tb/async_fifo_tb.sv
xelab async_fifo_tb -s fifo_sim --debug typical
xsim fifo_sim -R -testplusarg WCLK=10 -testplusarg RCLK=17
xsim fifo_sim -R -testplusarg WCLK=17 -testplusarg RCLK=10
```

Replace `-R` with `--gui` to view waveforms.

### A note on CDC verification

RTL simulation never goes metastable, so a simulation pass alone can't prove a clock-crossing design is safe. Correctness here rests on structure (only Gray-coded pointers cross domains, always through two-flop synchronizers), backed by assertions that each Gray pointer changes at most one bit per clock.

## AXI4-Lite Background

AXI4-Lite is the register-access subset of AMBA AXI4, with no bursts. It has five independent channels (write address, write data, write response, read address, read data), each using a `VALID`/`READY` handshake that completes on a rising clock edge when both are high. See [docs/axi4_lite_protocol_notes.md](docs/axi4_lite_protocol_notes.md).

## References

- C. Cummings, "Simulation and Synthesis Techniques for Asynchronous FIFO Design", SNUG 2002.
- C. Cummings and D. Mills, "Synchronous Resets? Asynchronous Resets? I am so confused!", SNUG 2002.
- ARM, AMBA AXI and ACE Protocol Specification.
