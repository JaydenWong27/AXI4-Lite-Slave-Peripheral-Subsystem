# AXI4-Lite Clock-Domain-Crossing Bridge with UVM Verification

A SystemVerilog **AXI4-Lite clock-domain-crossing (CDC) bridge** in front of a register peripheral with GPIO. The AXI bus runs on one clock (`ACLK`); the registers and GPIO run on another (`PCLK`); five asynchronous FIFOs, one per AXI channel, carry requests and responses between them. It is the same idea as Xilinx's AXI Clock Converter IP.

The design is verified in three layers:

1. **Directed and random SystemVerilog testbenches** (Verilator): FIFO unit test and a full-system test at many clock ratios, checked against a reference model and validated by mutation testing.
2. **UVM environment** (Vivado xsim, UVM 1.2): active and passive AXI-Lite agents, a scoreboard with a register model and an end-to-end bridge check, directed and constrained-random tests, functional coverage.
3. **SystemVerilog Assertions**, attached with `bind`: AXI handshake rules on both buses and Gray-code / full / empty rules on every FIFO.

## Architecture

```
          ACLK domain                     │                    PCLK domain
                                          │
 ┌──────────────┐  bus  ┌─────────────────┴──────────┐  m_bus  ┌────────────────┐     ┌────────────┐
 │ AXI master   │──────►│     axi_lite_cdc_bridge    │────────►│ axi_lite_slave │────►│ gpio_block │──► gpio_o
 │ (UVM driver) │◄──────│  AW  W  AR ──► async_fifo  │◄────────│ 4 x 32-bit regs│◄────│ (sync_2ff) │◄── gpio_i
 └──────────────┘       │  B   R     ◄── async_fifo  │         └────────────────┘     └────────────┘
                        └─────────────────┬──────────┘
                                          │   prst_n ──► rst_sync ──► PCLK-domain reset
```

### Bridge

Each AXI channel gets its own async FIFO. The side that **produces** the data writes the FIFO:

| Channel | Width | FIFO write side | FIFO read side | Packing |
|---|---|---|---|---|
| AW | 35 | `bus` (ACLK) | `m_bus` (PCLK) | `{AWPROT, AWADDR}` |
| W  | 36 | `bus` | `m_bus` | `{WSTRB, WDATA}` |
| AR | 35 | `bus` | `m_bus` | `{ARPROT, ARADDR}` |
| B  | 2  | `m_bus` | `bus` | `BRESP` |
| R  | 34 | `m_bus` | `bus` | `{RRESP, RDATA}` |

The FIFO handshake maps straight onto AXI: `wr_en = VALID`, `READY = !full` on the producer side, `VALID = !empty`, `rd_en = READY` on the consumer side. The FIFO is first-word-fall-through, so the payload stays stable while `VALID` is high, as AXI requires, and `VALID` never depends on `READY`.

Why one FIFO per channel: AXI lets a master send write data before or after the write address. Separate FIFOs let each channel cross independently; the slave latches address and data separately and responds once it has both.

### Async FIFO

Follows Cummings, *"Simulation and Synthesis Techniques for Asynchronous FIFO Design"* (SNUG 2002), section 6:

- Binary pointers address the memory; **only Gray-coded pointers cross domains**, each through a two-flop synchronizer clocked by the destination domain.
- Pointers carry one extra wrap bit to tell full from empty.
- `full` compares the next write Gray pointer with the synchronized read pointer with its top two bits inverted; `empty` is a direct compare. Both are registered.
- Writes are blocked when full and reads when empty, so the FIFO cannot overflow or underflow even if a producer ignores the flags.

### Resets

One external reset drives both domains, so both halves of every FIFO reset together. `ARESETN` is released synchronously to `ACLK` (an AXI requirement); the PCLK side uses `rst_sync` (asynchronous assert, synchronous release; Cummings & Mills, SNUG 2002).

## Register Map

| Offset | Name | Access | Description |
|---|---|---|---|
| `0x0` | DATA_OUT | RW | GPIO output values |
| `0x4` | DIRECTION | RW | Pin direction, 1 = output |
| `0x8` | DATA_IN | RO | Synchronized GPIO input. Writes return `SLVERR` |
| `0xC` | CONFIG | RW | Reserved |

Accesses at `0x10` and above return `SLVERR`; reads there return 0.

## Verification

### 1. Async FIFO unit test (`tb/async_fifo_tb.sv`)

Fill phase (overflow check), drain phase (underflow check) and a random phase, every word checked against a queue reference model, plus assertions that each Gray pointer changes at most one bit per clock.

| Write clock | Read clock | Result |
|---|---|---|
| 10 ns | 17 ns | PASS, 204 / 204 words |
| 17 ns | 10 ns | PASS, 204 / 204 words |
| 10 ns | 10 ns | PASS, 204 / 204 words |
| 10 ns | 37 ns | PASS, 204 / 204 words |
| 37 ns | 10 ns | PASS, 204 / 204 words |

Both `full` and `empty` were reached in every run.

### 2. System testbench (`tb/axi_lite_system_tb.sv`)

Drives the two-clock system top through the bridge. Nine tests: reset values, write/readback, partial WSTRB writes, AW-before-W and W-before-AW, GPIO pins, GPIO input through the synchronizer, read-only and out-of-range `SLVERR`, **8 outstanding writes and 8 outstanding reads with late `BREADY`/`RREADY`** (fills the B and R FIFOs), and 300 random transactions against a register model. Protocol assertions watch both sides of the bridge.

- **24 runs, all PASS**: 8 clock ratios (10/17, 17/10, 10/10, 10/11, 10/37, 37/10, 10/100, 100/10 ns) × 3 seeds, about 510 checks per run.
- **Mutation testing**: five deliberate bugs injected into copies of the bridge, all caught:

| Injected bug | Caught by |
|---|---|
| B FIFO ignores `full` (`BREADY = 1`) | timeout waiting for a lost response |
| R FIFO ignores `full` (`RREADY = 1`) | wrong data on outstanding read |
| R payload unpacked in the wrong order | wrong `RRESP` on the first read |
| AW FIFO popped on `WREADY` | AXI handshake assertion on `m_bus` |
| `WSTRB` forced to all ones | WSTRB readback check |

The two "ignores full" mutations show the outstanding tests really fill the FIFOs.

### 3. UVM environment (`tb/uvm/`)

```
 test ── env ─┬─ s_agent (ACTIVE, bus / ACLK):  sequencer ─► driver ─► bus
              │                                 monitor ──► ap ─┬─► scoreboard.write_s
              │                                                 └─► coverage
              ├─ m_agent (PASSIVE, m_bus / PCLK): monitor ──► ap ──► scoreboard.write_m
              ├─ scoreboard: register model + end-to-end bridge check
              └─ coverage:   covergroup on monitor transactions
```

- **One agent class, used twice.** Active on the ACLK bus (drives traffic); passive on the PCLK bus, where the bridge is already the master, so it only monitors. The env routes each interface to its agent through `config_db`, so the driver and monitor never know which bus they are on.
- **Monitor** rebuilds transactions from handshakes. AXI-Lite has no IDs and stays in order, so AW/W/AR requests wait in FIFO queues until their B/R response arrives.
- **Scoreboard, two checks per transaction:**
  1. *Register model*: predicts every response and read value (WSTRB byte updates, read-only and out-of-range `SLVERR`).
  2. *Bridge check*: the same transaction must appear unchanged on both buses. The PCLK side always finishes first, so its items are queued and compared when the ACLK item arrives.

  Together they localize a bug: model fails but bridge passes → slave; bridge fails → bridge.
- **Coverage** (sampled from the monitor, i.e. what really happened on the bus): every register and both out-of-range areas × read/write, `OKAY`/`SLVERR` × read/write, WSTRB none / full / each single byte / other partial; `EXOKAY` and `DECERR` are illegal bins.
- **Tests**: `axi_lite_base_test` (smoke), `axi_lite_directed_test` (reset values, WSTRB, AW/W skew, read-only, out of range), `axi_lite_random_test` (100–300 constrained-random transactions).

All three tests pass in Vivado xsim. The directed test reports `PASS: writes=7 reads=10 bridge_checks=17`.

### 4. Assertions (`tb/uvm/axi_lite_sva.sv`)

Attached with `bind`, so the RTL is untouched:

- **`axi_lite_protocol_sva`**, bound to `axi_lite_if`, so it checks **both** buses: `VALID` held with a stable payload until `READY` on all five channels, and no X/Z on any `VALID` after reset. On `bus` this checks the UVM driver's requests and the bridge's responses; on `m_bus`, the bridge's requests and the slave's responses.
- **`async_fifo_sva`**, bound to `async_fifo`, so it checks all five bridge FIFOs: each Gray pointer changes at most one bit per clock, and the pointers do not move on a write while full or a read while empty.

Checked by binding them into the system testbench: no failures on the correct design at four clock ratios; an AW-pop bug fires `a_aw_stable` on `m_bus`, and sending the write pointer as binary instead of Gray fires `a_wptr_gray` (`001 → 010` changes two bits).

### A note on CDC verification

RTL simulation never goes metastable, so a passing simulation alone cannot prove a clock crossing is safe. Correctness here rests on **structure** (only Gray-coded pointers cross, always through two-flop synchronizers in the destination domain), backed by assertions that the Gray pointers really change one bit at a time. The synchronized copies are deliberately not checked: when a fast clock is sampled by a slow one they can legitimately jump several steps.

## Project Layout

```
rtl/
  axi_lite_if.sv            AXI4-Lite interface (master/slave modports)
  axi_lite_cdc_bridge.sv    AXI clock-crossing bridge (5 x async_fifo)
  axi_lite_slave.sv         Register slave
  gpio_block.sv             GPIO with input synchronizer
  axi_lite_gpio_system.sv   Two-clock top level: bridge + slave + GPIO + rst_sync
  cdc/
    sync_2ff.sv             Two-flop synchronizer
    rst_sync.sv             Reset synchronizer (async assert, sync release)
    fifo_mem.sv             FIFO storage
    fifo_wptr_full.sv       Write pointer and full flag (write domain)
    fifo_rptr_empty.sv      Read pointer and empty flag (read domain)
    async_fifo.sv           Async FIFO top level
tb/
  axi_lite_tb.sv            Directed testbench for the bare register slave
  async_fifo_tb.sv          Async FIFO testbench
  axi_lite_system_tb.sv     Full-system testbench through the bridge
  uvm/
    axi_lite_pkg.sv         Package: includes all UVM classes
    axi_lite_seq_item.sv    Transaction with constraints
    axi_lite_sequencer.sv
    axi_lite_driver.sv
    axi_lite_monitor.sv
    axi_lite_agent.sv       Active or passive
    axi_lite_scoreboard.sv  Register model + bridge check
    axi_lite_coverage.sv    Functional coverage
    axi_lite_env.sv
    axi_lite_sequences.sv   Basic, directed and random sequences
    axi_lite_tests.sv       Base, directed and random tests
    axi_lite_sva.sv         Protocol and FIFO assertions (bind)
    tb_top.sv               Clocks, reset, DUT, config_db, run_test
docs/                       AXI4-Lite protocol notes
constraints/                CDC timing constraints (planned)
```

## Running the Simulations

### Async FIFO (Verilator)

```sh
verilator -sv --timing --binary --assert -Wno-fatal rtl/cdc/sync_2ff.sv rtl/cdc/fifo_mem.sv rtl/cdc/fifo_wptr_full.sv rtl/cdc/fifo_rptr_empty.sv rtl/cdc/async_fifo.sv tb/async_fifo_tb.sv --top-module async_fifo_tb
./obj_dir/Vasync_fifo_tb +WCLK=10 +RCLK=17
```

### System testbench (Verilator)

```sh
verilator -sv --timing --binary --assert -Wno-fatal rtl/axi_lite_if.sv rtl/cdc/*.sv rtl/axi_lite_cdc_bridge.sv rtl/axi_lite_slave.sv rtl/gpio_block.sv rtl/axi_lite_gpio_system.sv tb/uvm/axi_lite_sva.sv tb/axi_lite_system_tb.sv --top-module axi_lite_system_tb
./obj_dir/Vaxi_lite_system_tb +ACLK=10 +PCLK=17 +SEED=7
```

Including `tb/uvm/axi_lite_sva.sv` binds the protocol and FIFO assertions into the run. Add `--trace` to the build and `+DUMP` to the run for a VCD.

### UVM (Vivado xsim)

```sh
xvlog -sv -L uvm -i tb/uvm rtl/axi_lite_if.sv rtl/cdc/*.sv rtl/axi_lite_cdc_bridge.sv rtl/axi_lite_slave.sv rtl/gpio_block.sv rtl/axi_lite_gpio_system.sv tb/uvm/axi_lite_sva.sv tb/uvm/axi_lite_pkg.sv tb/uvm/tb_top.sv
xelab tb_top -L uvm -s uvm_sim --debug typical
xsim uvm_sim -R -testplusarg UVM_TESTNAME=axi_lite_directed_test
xsim uvm_sim -R -testplusarg UVM_TESTNAME=axi_lite_random_test -sv_seed 7 -testplusarg ACLK=10 -testplusarg PCLK=37
```

`+ACLK=` / `+PCLK=` set the clock periods in ns; `-sv_seed` makes a random run reproducible. The scoreboard prints `[SB] PASS: ...` and the coverage component prints `[COV] coverage: ...` at the end.

## Possible Extensions

- **Pipelined UVM driver** for outstanding transactions. The UVM driver finishes each transaction before starting the next; outstanding traffic is covered by the system testbench (tests 7 and 8).
- **CDC timing constraints**: `set_max_delay -datapath_only` on the Gray pointer crossings.
- AW/W ordering coverage, by having the monitor record the cycle of each handshake.

## References

- C. Cummings, "Simulation and Synthesis Techniques for Asynchronous FIFO Design", SNUG 2002.
- C. Cummings and D. Mills, "Synchronous Resets? Asynchronous Resets? I am so confused!", SNUG 2002.
- ARM, AMBA AXI and ACE Protocol Specification.
- Xilinx, AXI Clock Converter LogiCORE IP (PG062).
