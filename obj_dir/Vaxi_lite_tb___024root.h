// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi_lite_tb.h for the primary calling header

#ifndef VERILATED_VAXI_LITE_TB___024ROOT_H_
#define VERILATED_VAXI_LITE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vaxi_lite_tb_axi_lite_if;


class Vaxi_lite_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi_lite_tb___024root final {
  public:
    // CELLS
    Vaxi_lite_tb_axi_lite_if* __PVT__axi_lite_tb__DOT__bus;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ axi_lite_tb__DOT__ACLK;
    CData/*0:0*/ axi_lite_tb__DOT__ARESETN;
    CData/*1:0*/ axi_lite_tb__DOT__unnamedblk1__DOT__write_resp;
    CData/*1:0*/ axi_lite_tb__DOT__unnamedblk1__DOT__read_resp;
    CData/*3:0*/ axi_lite_tb__DOT__dut__DOT__write_strb;
    CData/*0:0*/ axi_lite_tb__DOT__dut__DOT__write_addr_valid;
    CData/*0:0*/ axi_lite_tb__DOT__dut__DOT__write_data_valid;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0;
    CData/*0:0*/ __Vtrigprevexpr_h91e75ef1__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ axi_lite_tb__DOT__unnamedblk1__DOT__read_data;
    IData/*31:0*/ axi_lite_tb__DOT__dut__DOT__write_addr;
    IData/*31:0*/ axi_lite_tb__DOT__dut__DOT__write_data;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<IData/*31:0*/, 4> axi_lite_tb__DOT__dut__DOT__regs;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlTriggerScheduler __VtrigSched_h6caf7641__0;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h6a9430a7__0;
    VlTriggerScheduler __VtrigSched_h15d04b76__0;
    VlTriggerScheduler __VtrigSched_h6c264e19__0;
    VlTriggerScheduler __VtrigSched_h0d5f886f__0;
    VlTriggerScheduler __VtrigSched_h4d9a469e__0;
    VlTriggerScheduler __VtrigSched_h89f01a72__0;
    VlTriggerScheduler __VtrigSched_hb447cace__0;

    // INTERNAL VARIABLES
    Vaxi_lite_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vaxi_lite_tb___024root(Vaxi_lite_tb__Syms* symsp, const char* namep);
    ~Vaxi_lite_tb___024root();
    VL_UNCOPYABLE(Vaxi_lite_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
