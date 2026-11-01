`default_nettype none

// Protocol and CDC assertions, attached with bind so the RTL stays untouched.
// - Every port is an input: assertion modules only watch. An output would become a second
//   driver on the signal it is bound to.
// - Port names match the target's signal names exactly, so (.*) connects them by name.
// - axi_lite_protocol_sva is bound to axi_lite_if, so it checks BOTH bus (ACLK: UVM driver
//   requests, bridge responses) and m_bus (PCLK: bridge requests, slave responses).
// - async_fifo_sva is bound to async_fifo, so it checks all five bridge FIFOs.
// - Not part of axi_lite_pkg: modules cannot live in a package. Compile it after the RTL.

// AXI handshake rule on all five channels: once VALID is high it stays high with a stable
// payload until READY. Otherwise the receiver could capture half-old, half-new data.
module axi_lite_protocol_sva #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (
    input logic                    ACLK,
    input logic                    ARESETN,
    // AW channel
    input logic [ADDR_WIDTH-1:0]   AWADDR,
    input logic [2:0]              AWPROT,
    input logic                    AWVALID,
    input logic                    AWREADY,
    // W channel
    input logic [DATA_WIDTH-1:0]   WDATA,
    input logic [DATA_WIDTH/8-1:0] WSTRB,
    input logic                    WVALID,
    input logic                    WREADY,
    // B channel
    input logic [1:0]              BRESP,
    input logic                    BVALID,
    input logic                    BREADY,
    // AR channel
    input logic [ADDR_WIDTH-1:0]   ARADDR,
    input logic [2:0]              ARPROT,
    input logic                    ARVALID,
    input logic                    ARREADY,
    // R channel
    input logic [DATA_WIDTH-1:0]   RDATA,
    input logic [1:0]              RRESP,
    input logic                    RVALID,
    input logic                    RREADY
);

    // AW: once VALID is high it must stay high, with the same payload, until READY
    a_aw_stable : assert property (@(posedge ACLK) disable iff (!ARESETN)
        AWVALID && !AWREADY |=> AWVALID && $stable(AWADDR) && $stable(AWPROT))
        else $error("AW: VALID dropped or payload changed before READY");

    // W: same rule for write data and strobes
    a_w_stable : assert property (@(posedge ACLK) disable iff (!ARESETN)
        WVALID && !WREADY |=> WVALID && $stable(WDATA) && $stable(WSTRB))
        else $error("W: VALID dropped or payload changed before READY");

    // AR: same rule for the read address
    a_ar_stable : assert property (@(posedge ACLK) disable iff (!ARESETN)
        ARVALID && !ARREADY |=> ARVALID && $stable(ARADDR) && $stable(ARPROT))
        else $error("AR: VALID dropped or payload changed before READY");

    // B: the write response must hold until the master accepts it
    a_b_stable : assert property (@(posedge ACLK) disable iff (!ARESETN)
        BVALID && !BREADY |=> BVALID && $stable(BRESP))
        else $error("B: VALID dropped or payload changed before READY");

    // R: read data and response must hold until the master accepts them
    a_r_stable : assert property (@(posedge ACLK) disable iff (!ARESETN)
        RVALID && !RREADY |=> RVALID && $stable(RDATA) && $stable(RRESP))
        else $error("R: VALID dropped or payload changed before READY");

    // VALIDs must never be X/Z once out of reset (an undriven VALID is a testbench or RTL bug)
    a_no_x_valid : assert property (@(posedge ACLK) disable iff (!ARESETN)
        !$isunknown({AWVALID, WVALID, BVALID, ARVALID, RVALID}))
        else $error("a VALID is X/Z after reset");

endmodule

// Async FIFO CDC checks. Only the source pointers (wptr, rptr) are checked for one-bit
// changes: the synchronized copies (wq2_rptr, rq2_wptr) can legitimately jump several steps
// when a fast clock is sampled by a slow one.
module async_fifo_sva #(
    parameter int ADDR_W = 2
) (
    // write side
    input logic            wclk,
    input logic            wrst_n,
    input logic            wr_en,
    input logic            full,
    input logic [ADDR_W:0] wptr,
    // read side
    input logic            rclk,
    input logic            rrst_n,
    input logic            rd_en,
    input logic            empty,
    input logic [ADDR_W:0] rptr
);

    // Gray write pointer changes by at most one bit per wclk: the 2FF synchronizer in the
    // read domain is only safe if one bit changes at a time (Cummings section 2)
    a_wptr_gray : assert property (@(posedge wclk) disable iff (!wrst_n)
        $onehot0(wptr ^ $past(wptr)))
        else $error("wptr changed more than one bit: %b", wptr);

    // Same for the Gray read pointer, which crosses into the write domain
    a_rptr_gray : assert property (@(posedge rclk) disable iff (!rrst_n)
        $onehot0(rptr ^ $past(rptr)))
        else $error("rptr changed more than one bit: %b", rptr);

    // A write while full must not move the pointer, or unread data gets overwritten
    a_no_push_full : assert property (@(posedge wclk) disable iff (!wrst_n)
        wr_en && full |=> $stable(wptr))
        else $error("write pointer moved while full");

    // A read while empty must not move the pointer, or garbage gets read
    a_no_pop_empty : assert property (@(posedge rclk) disable iff (!rrst_n)
        rd_en && empty |=> $stable(rptr))
        else $error("read pointer moved while empty");

endmodule

// Attach the checkers. The parameters on the right are the TARGET's, so every instance
// gets its own widths. (.*) connects each port to the target signal with the same name.
bind axi_lite_if axi_lite_protocol_sva #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) u_proto_sva (.*);
bind async_fifo  async_fifo_sva        #(.ADDR_W(ADDR_W))                                  u_fifo_sva  (.*);

`default_nettype wire
