// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi_lite_tb.h for the primary calling header

#ifndef VERILATED_VAXI_LITE_TB_AXI_LITE_IF_H_
#define VERILATED_VAXI_LITE_TB_AXI_LITE_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaxi_lite_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi_lite_tb_axi_lite_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ACLK;
    CData/*0:0*/ ARESETN;
    CData/*2:0*/ AWPROT;
    CData/*0:0*/ AWVALID;
    CData/*0:0*/ AWREADY;
    CData/*3:0*/ WSTRB;
    CData/*0:0*/ WVALID;
    CData/*0:0*/ WREADY;
    CData/*1:0*/ BRESP;
    CData/*0:0*/ BVALID;
    CData/*0:0*/ BREADY;
    CData/*2:0*/ ARPROT;
    CData/*0:0*/ ARVALID;
    CData/*0:0*/ ARREADY;
    CData/*1:0*/ RRESP;
    CData/*0:0*/ RVALID;
    CData/*0:0*/ RREADY;
    CData/*0:0*/ __Vdly__BVALID;
    CData/*0:0*/ __Vdly__RVALID;
    IData/*31:0*/ AWADDR;
    IData/*31:0*/ WDATA;
    IData/*31:0*/ ARADDR;
    IData/*31:0*/ RDATA;

    // INTERNAL VARIABLES
    Vaxi_lite_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vaxi_lite_tb_axi_lite_if();
    ~Vaxi_lite_tb_axi_lite_if();
    void ctor(Vaxi_lite_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vaxi_lite_tb_axi_lite_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vaxi_lite_tb_axi_lite_if* obj);

#endif  // guard
