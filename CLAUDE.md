# CLAUDE.md

Context for Claude Code sessions in this repo. Read this before helping.

## What this project is

A SystemVerilog AXI4-Lite peripheral subsystem being grown into an **AXI4-Lite clock-domain-crossing (CDC) bridge with UVM verification**. It's a resume/portfolio project aimed at ASIC/FPGA design-verification roles. The point is to cover AXI, CDC, async FIFOs, UVM, coverage and SVA in one project.

Three-step plan (about 3 weeks total):

1. **Week 1: async FIFO** (Cummings "FIFO style #1" with Gray-code style #2 pointers). Status: RTL and directed testbench written, **not yet simulated**.
2. **Week 2: AXI CDC bridge.** The AXI bus runs on `ACLK`; the register slave and GPIO run on `PCLK`; five async FIFOs (one per AXI channel) cross between them. Status: **in progress**, only the AW channel is started.
3. **Week 3: UVM** (replaces nothing; the directed testbenches stay as smoke tests). AXI-Lite agent (driver, monitor, sequencer), scoreboard with a register reference model, random reads/writes/WSTRB/clock ratios, functional coverage, SVA (VALID stable until READY, payload stable, RVALID/BVALID only after request handshakes, Gray pointers change one bit per clock). Status: not started.

Fallback if time is short: finish UVM on the FIFO alone and add the bridge later.

## How to work with this user

- **The user writes the RTL and testbenches themselves.** Default to explaining what a module does, giving a spec (parameters, ports, behavior, the "why" questions to answer in comments), then reviewing what they wrote. Don't write or rewrite their RTL unless they explicitly ask (they sometimes say "fix the small stuff" or "finish it for me"; then it's fine).
- **Reviews:** read the file, then list issues as a table of line number, problem, fix, with clickable `[file:line](path#Lline)` links. Separate compile errors, logic bugs and cleanups. Say clearly what is already correct.
- **They can't compile on this laptop.** Verilator is not installed here (no WSL). Vivado (xsim) is on their other computer and they test there later. So act as their compiler/linter: check syntax, widths, port directions, undeclared names and leftover names after renames, carefully.
- They're learning: give the reasoning behind each design choice, tied to the Cummings paper sections where relevant. Keep explanations concrete.
- Commit or push only when they ask.

## Architecture (target)

```
 ACLK domain                                      PCLK domain
 AXI master (tb / UVM) --s_axi--> axi_lite_cdc_bridge --m_axi--> axi_lite_slave --> gpio_block
                                  (5 x async_fifo)               (unchanged)
```

Bridge channel mapping. FIFO write side = whichever side **produces** the data:

| Channel | Width | FIFO write side | FIFO read side | Packing |
|---|---|---|---|---|
| AW | ADDR_WIDTH+3 (35) | s_axi: `wr_en=AWVALID`, `AWREADY=!full` | m_axi: `AWVALID=!empty`, `rd_en=AWREADY` | `{AWPROT, AWADDR}` |
| W  | DATA_WIDTH+DATA_WIDTH/8 (36) | s_axi | m_axi | `{WSTRB, WDATA}` |
| AR | ADDR_WIDTH+3 (35) | s_axi | m_axi | `{ARPROT, ARADDR}` |
| B  | 2 | **m_axi**: `wr_en=BVALID`, `BREADY=!full` | **s_axi**: `BVALID=!empty`, `rd_en=BREADY` | `BRESP` |
| R  | DATA_WIDTH+2 (34) | **m_axi** | **s_axi** | `{RRESP, RDATA}` |

The FIFO is first-word-fall-through, so `VALID=!empty` with `rdata` held stable until the pop satisfies AXI's payload-stability rule, and VALID never depends on READY. The bridge gets clocks/resets from the interfaces (`s_axi.ACLK/ARESETN`, `m_axi.ACLK/ARESETN`).

Register map (slave, 4 x 32-bit, word-aligned):

| Offset | Name | Access | Notes |
|---|---|---|---|
| 0x0 | DATA_OUT | RW | `reg_out0` to `gpio_block` |
| 0x4 | DIRECTION | RW | `reg_out1`, 1 = output |
| 0x8 | DATA_IN | RO | returns `gpio_in` (2-flop synchronized); **writes return SLVERR** |
| 0xC | CONFIG | RW | reserved |
| >= 0x10 | - | - | SLVERR on read and write; reads return 0 |

## File map

| File | Status |
|---|---|
| `rtl/axi_lite_if.sv` | AXI4-Lite interface with `master`/`slave` modports. Done |
| `rtl/axi_lite_slave.sv` | Register slave. Done. Read path asserts ARREADY, then RVALID one cycle after the AR handshake (fixed an earlier spec violation). Exposes `reg_out0/1` and `gpio_in` ports (no hierarchical refs) |
| `rtl/gpio_block.sv` | GPIO; `gpio_i` goes through `sync_2ff`. Done |
| `rtl/axi_lite_gpio_system.sv` | Top level. **Still single-clock**; week 2 converts it to two clocks (see Next steps) |
| `rtl/axi_lite_cdc_bridge.sv` | **In progress.** AW channel only; has syntax errors (see Open issues) |
| `rtl/axi_lite_interconnect.sv`, `rtl/axi_lite_master.sv` | Empty placeholders. Interconnect is to be deleted (bridge replaces it) |
| `rtl/cdc/sync_2ff.sv` | Two-flop synchronizer, `WIDTH` param, `ASYNC_REG` attribute. Done |
| `rtl/cdc/rst_sync.sv` | Reset synchronizer (async assert, sync deassert). Ports `clk`, `arst_n`, `rst_n_sync`. Done |
| `rtl/cdc/fifo_mem.sv` | FIFO storage, no reset, combinational read. Done |
| `rtl/cdc/fifo_wptr_full.sv` | Write pointer (binary + Gray), registered full via next-Gray compare with top two bits inverted. `ADDR_W >= 2` enforced. Done |
| `rtl/cdc/fifo_rptr_empty.sv` | Read pointer, registered empty (resets to 1), advances only on `rd_en & ~empty`. Done |
| `rtl/cdc/async_fifo.sv` | Top: wires mem, both pointer modules, `sync_r2w` (wclk) and `sync_w2r` (rclk). Done |
| `tb/axi_lite_tb.sv` | Directed testbench for the bare slave (Verilator). Includes GPIO-input and read-only-register tests |
| `tb/async_fifo_tb.sv` | Directed FIFO testbench: queue scoreboard, fill / drain / random phases, Gray one-bit assertions, full/empty coverage counters, timeout. Clock periods via `+WCLK=` / `+RCLK=` plusargs |
| `docs/axi4_lite_protocol_notes.md` | Protocol notes |
| `constraints/` | Empty. Planned: `set_max_delay -datapath_only` on the Gray pointer crossings |

## Conventions

- `` `default_nettype none `` at the top of every RTL/TB file, `` `default_nettype wire `` after `endmodule`.
- `always_ff` with async active-low reset (`posedge clk or negedge rst_n`); `assign` for combinational next-state logic; `'0` / sized literals (`1'b1`), no unsized `1`/`0` on vectors.
- FIFO naming follows Cummings: `w*` signals belong to `wclk`, `r*` to `rclk`; synchronized copies are `wq2_rptr` / `rq2_wptr`. Only Gray pointers cross domains, always through `sync_2ff` clocked by the **destination** clock.
- Bridge naming: one prefix per channel (`aw_`, `w_`, `ar_`, `b_`, `r_`), instances `u_aw_fifo` etc.
- Header comment in each module explaining the "why" of its design choices.
- Testbenches: drive inputs on the falling edge, sample/check on the rising edge; monitors only watch, drivers only drive (UVM-style separation); compare with `!==`.

## Verification status

**Nothing changed since the initial commit has been compiled or simulated yet.** First runs are expected to surface syntax issues.

- Slave (Verilator, original flow):
  ```sh
  verilator -sv --timing --binary --trace rtl/axi_lite_if.sv rtl/axi_lite_slave.sv tb/axi_lite_tb.sv --top-module axi_lite_tb
  ./obj_dir/Vaxi_lite_tb
  ```
- Async FIFO (Vivado xsim), run at both clock ratios; both should print `PASS: writes=204 reads=204`:
  ```sh
  xvlog -sv rtl/cdc/sync_2ff.sv rtl/cdc/fifo_mem.sv rtl/cdc/fifo_wptr_full.sv rtl/cdc/fifo_rptr_empty.sv rtl/cdc/async_fifo.sv tb/async_fifo_tb.sv
  xelab async_fifo_tb -s fifo_sim --debug typical
  xsim fifo_sim -R -testplusarg WCLK=10 -testplusarg RCLK=17
  xsim fifo_sim -R -testplusarg WCLK=17 -testplusarg RCLK=10
  ```
  If older xsim rejects `$onehot0`/`$past`, comment out the two `assert property` blocks to unblock.
- Gray one-bit assertions apply to the source pointers (`wptr`, `rptr`) only, never to the synchronized copies (they can legitimately jump when a fast clock is sampled by a slow one).
- RTL simulation cannot show metastability, so CDC correctness rests on structure (Gray-only crossings through `sync_2ff`) plus assertions.

## Open issues

- `rtl/axi_lite_cdc_bridge.sv`: trailing comma after `axi_lite_if.master m_axi,` (line 7); `{m_axi.AWPROT< m_axi.AWADDR}` uses `<` instead of `,` (line 38); missing `` `default_nettype `` lines; W, AR, B, R channels not written yet.
- `obj_dir/` and `axi_lite_tb.vcd` are committed even though `.gitignore` now excludes them; untrack with `git rm -r --cached obj_dir axi_lite_tb.vcd`.
- Optional: `axi_lite_slave.sv` header still says registers are "32-bit"; fine at the default width.

## Next steps (week 2)

1. Finish the bridge: W, AR, B, R channels from the table above (B and R swap `s_axi`/`m_axi`).
2. Convert `axi_lite_gpio_system.sv` to two clocks: rename unused `clk`/`rst_n` to `pclk`/`prst_n`; add `rst_sync` on `pclk`; add a second `axi_lite_if m_bus` on `pclk` with the synchronized reset; instantiate bridge (`axi_bus` -> `m_bus`), slave on `m_bus`, `gpio_block` on `pclk`. Both domains' resets come from one external reset so the FIFO halves reset together.
3. `tb/axi_lite_system_tb.sv`: copy `axi_lite_tb.sv`, instantiate the system top, add a second clock via plusargs, drive `gpio_i` and read 0x8, raise the timeout a lot (two crossings per transaction), run at ACLK-faster, PCLK-faster and near-equal ratios.
4. Delete `rtl/axi_lite_interconnect.sv`; add the CDC timing constraints; update README.
5. Week 3: UVM (see plan above). Use Vivado xsim (UVM 1.2) or EDA Playground; Verilator's UVM support is incomplete.

## References

- Clifford Cummings, "Simulation and Synthesis Techniques for Asynchronous FIFO Design", SNUG 2002, rev 1.3. The FIFO follows its section 6 code (Examples 2-7).
- Cummings & Mills, "Synchronous Resets? Asynchronous Resets?", SNUG 2002, for the reset synchronizer.
- Xilinx AXI Clock Converter IP is the real-world equivalent of the bridge.
