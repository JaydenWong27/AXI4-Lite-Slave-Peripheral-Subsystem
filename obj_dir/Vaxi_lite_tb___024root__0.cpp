// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_initial__TOP(Vaxi_lite_tb___024root* vlSelf);
VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_lite_tb___024root* vlSelf);
VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_lite_tb___024root* vlSelf);
VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_lite_tb___024root* vlSelf);
VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__3(Vaxi_lite_tb___024root* vlSelf);

void Vaxi_lite_tb___024root___eval_initial(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaxi_lite_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__3(vlSelf);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    vlSelfRef.axi_lite_tb__DOT__ARESETN = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWPROT = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARPROT = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                           "@(posedge axi_lite_tb.ACLK)");
        co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge axi_lite_tb.ACLK)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             37);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (axi_lite_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.axi_lite_tb__DOT__ARESETN = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.axi_lite_tb__DOT__ACLK = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/axi_lite_tb.sv", 
                                             43);
        vlSelfRef.axi_lite_tb__DOT__ACLK = (1U & (~ (IData)(vlSelfRef.axi_lite_tb__DOT__ACLK)));
    }
    co_return;
}

void Vaxi_lite_tb___024root____VbeforeTrig_h6a9430a7__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_h89f01a72__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);
void Vaxi_lite_tb___024root____VbeforeTrig_hb447cace__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__0__addr;
    __Vtask_axi_lite_tb__DOT__axi_write__0__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__0__data;
    __Vtask_axi_lite_tb__DOT__axi_write__0__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write__0__strb;
    __Vtask_axi_lite_tb__DOT__axi_write__0__strb = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_write__0__resp;
    __Vtask_axi_lite_tb__DOT__axi_write__0__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__1__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__1__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__1__data;
    __Vtask_axi_lite_tb__DOT__axi_read__1__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__1__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__1__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__2__addr;
    __Vtask_axi_lite_tb__DOT__axi_write__2__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__2__data;
    __Vtask_axi_lite_tb__DOT__axi_write__2__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write__2__strb;
    __Vtask_axi_lite_tb__DOT__axi_write__2__strb = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_write__2__resp;
    __Vtask_axi_lite_tb__DOT__axi_write__2__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__3__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__3__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__3__data;
    __Vtask_axi_lite_tb__DOT__axi_read__3__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__3__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__3__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__4__addr;
    __Vtask_axi_lite_tb__DOT__axi_write__4__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__4__data;
    __Vtask_axi_lite_tb__DOT__axi_write__4__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write__4__strb;
    __Vtask_axi_lite_tb__DOT__axi_write__4__strb = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_write__4__resp;
    __Vtask_axi_lite_tb__DOT__axi_write__4__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__5__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__5__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__5__data;
    __Vtask_axi_lite_tb__DOT__axi_read__5__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__5__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__5__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__addr;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__data;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__strb;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__strb = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__7__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__7__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__7__data;
    __Vtask_axi_lite_tb__DOT__axi_read__7__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__7__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__7__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__addr;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__data;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__strb;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__strb = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__9__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__9__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__9__data;
    __Vtask_axi_lite_tb__DOT__axi_read__9__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__9__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__9__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__10__addr;
    __Vtask_axi_lite_tb__DOT__axi_write__10__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_write__10__data;
    __Vtask_axi_lite_tb__DOT__axi_write__10__data = 0;
    CData/*3:0*/ __Vtask_axi_lite_tb__DOT__axi_write__10__strb;
    __Vtask_axi_lite_tb__DOT__axi_write__10__strb = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_write__10__resp;
    __Vtask_axi_lite_tb__DOT__axi_write__10__resp = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__11__addr;
    __Vtask_axi_lite_tb__DOT__axi_read__11__addr = 0;
    IData/*31:0*/ __Vtask_axi_lite_tb__DOT__axi_read__11__data;
    __Vtask_axi_lite_tb__DOT__axi_read__11__data = 0;
    CData/*1:0*/ __Vtask_axi_lite_tb__DOT__axi_read__11__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__11__resp = 0;
    // Body
    while ((1U & (~ (IData)(vlSelfRef.axi_lite_tb__DOT__ARESETN)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6a9430a7__0(vlSelf, 
                                                           "@( axi_lite_tb.ARESETN)");
        co_await vlSelfRef.__VtrigSched_h6a9430a7__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.ARESETN)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             169);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         170);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    __Vtask_axi_lite_tb__DOT__axi_write__0__strb = 0x0fU;
    __Vtask_axi_lite_tb__DOT__axi_write__0__data = 0xdeadbeefU;
    __Vtask_axi_lite_tb__DOT__axi_write__0__addr = 0U;
    __Vtask_axi_lite_tb__DOT__axi_write__0__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write__0__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write__0__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write__0__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                     & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY))))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(vlSelf, 
                                                           "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
        co_await vlSelfRef.__VtrigSched_h15d04b76__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))", 
                                                             "tb/axi_lite_tb.sv", 
                                                             64);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         65);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             69);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_write__0__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp 
        = __Vtask_axi_lite_tb__DOT__axi_write__0__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__1__addr = 0U;
    __Vtask_axi_lite_tb__DOT__axi_read__1__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__1__resp = 0;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:175: Assertion failed in %m: Write response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 175, "");
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__1__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__1__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__1__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__1__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__1__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:181: Assertion failed in %m: Read response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 181, "");
    }
    if (VL_UNLIKELY(((0xdeadbeefU != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:185: Assertion failed in %m: Readback failed: expected 0xdeadbeef, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 185, "");
    } else {
        VL_WRITEF_NX("readback passed: 0x%08h\n",1, '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
    }
    __Vtask_axi_lite_tb__DOT__axi_write__2__strb = 3U;
    __Vtask_axi_lite_tb__DOT__axi_write__2__data = 0x12345678U;
    __Vtask_axi_lite_tb__DOT__axi_write__2__addr = 0U;
    __Vtask_axi_lite_tb__DOT__axi_write__2__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write__2__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write__2__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write__2__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                     & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY))))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(vlSelf, 
                                                           "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
        co_await vlSelfRef.__VtrigSched_h15d04b76__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))", 
                                                             "tb/axi_lite_tb.sv", 
                                                             64);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         65);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             69);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_write__2__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp 
        = __Vtask_axi_lite_tb__DOT__axi_write__2__resp;
    __Vtask_axi_lite_tb__DOT__axi_read__3__addr = 0U;
    __Vtask_axi_lite_tb__DOT__axi_read__3__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__3__resp = 0;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:194: Assertion failed in %m: Write response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 194, "");
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__3__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__3__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__3__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__3__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__3__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:200: Assertion failed in %m: Read response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 200, "");
    }
    if (VL_UNLIKELY(((0xdead5678U != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:204: Assertion failed in %m: WSTRB test failed: expected 0xdead5678, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 204, "");
    } else {
        VL_WRITEF_NX("WSTRB test passed: 0x%08h\n",1
                     , '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
    }
    __Vtask_axi_lite_tb__DOT__axi_write__4__strb = 0x0fU;
    __Vtask_axi_lite_tb__DOT__axi_write__4__data = 0xcafebabeU;
    __Vtask_axi_lite_tb__DOT__axi_write__4__addr = 4U;
    __Vtask_axi_lite_tb__DOT__axi_write__4__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write__4__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write__4__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write__4__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                     & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY))))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(vlSelf, 
                                                           "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
        co_await vlSelfRef.__VtrigSched_h15d04b76__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))", 
                                                             "tb/axi_lite_tb.sv", 
                                                             64);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         65);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             69);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_write__4__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp 
        = __Vtask_axi_lite_tb__DOT__axi_write__4__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:213: Assertion failed in %m: Write response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 213, "");
    }
    __Vtask_axi_lite_tb__DOT__axi_read__5__addr = 4U;
    __Vtask_axi_lite_tb__DOT__axi_read__5__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__5__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__5__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__5__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__5__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__5__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__5__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:219: Assertion failed in %m: Read response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 219, "");
    }
    if (VL_UNLIKELY(((0xcafebabeU != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:223: Assertion failed in %m: Register 1 test failed: expected 0xcafebabe, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 223, "");
    } else {
        VL_WRITEF_NX("Register 1 test passed: 0x%08h\n",1
                     , '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
    }
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__strb = 0x0fU;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__data = 0x11112222U;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__addr = 8U;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h89f01a72__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.AWREADY)");
        co_await vlSelfRef.__VtrigSched_h89f01a72__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.AWREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             88);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         89);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    while (VL_LTS_III(32, 0U, __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                           "@(posedge axi_lite_tb.ACLK)");
        co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge axi_lite_tb.ACLK)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             92);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (__Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__axi_lite_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write_addr_first__6__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_hb447cace__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.WREADY)");
        co_await vlSelfRef.__VtrigSched_hb447cace__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.WREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             98);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         99);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             102);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         103);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    __Vtask_axi_lite_tb__DOT__axi_read__7__addr = 8U;
    __Vtask_axi_lite_tb__DOT__axi_read__7__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__7__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__7__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__7__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__7__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__7__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__7__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:233: Assertion failed in %m: Read response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 233, "");
    }
    if (VL_UNLIKELY(((0x11112222U != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:237: Assertion failed in %m: Address-first write failed: expected 0x11112222, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 237, "");
    } else {
        VL_WRITEF_NX("Address-first write passed: 0x%08h\n",1
                     , '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
    }
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__strb = 0x0fU;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__data = 0x33334444U;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__addr = 0x0000000cU;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         114);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_hb447cace__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.WREADY)");
        co_await vlSelfRef.__VtrigSched_hb447cace__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.WREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             121);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    while (VL_LTS_III(32, 0U, __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                           "@(posedge axi_lite_tb.ACLK)");
        co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge axi_lite_tb.ACLK)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             125);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (__Vtask_axi_lite_tb__DOT__axi_write_data_first__8__axi_lite_tb__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write_data_first__8__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h89f01a72__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.AWREADY)");
        co_await vlSelfRef.__VtrigSched_h89f01a72__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.AWREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             130);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             134);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         135);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    __Vtask_axi_lite_tb__DOT__axi_read__9__addr = 0x0000000cU;
    __Vtask_axi_lite_tb__DOT__axi_read__9__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__9__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__9__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__9__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__9__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__9__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__9__resp;
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:247: Assertion failed in %m: Read response failed: expected OKAY, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 247, "");
    }
    if (VL_UNLIKELY(((0x33334444U != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:251: Assertion failed in %m: Data-first write failed: expected 0x33334444, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 251, "");
    } else {
        VL_WRITEF_NX("Data-first write passed: 0x%08h\n",1
                     , '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
    }
    __Vtask_axi_lite_tb__DOT__axi_write__10__strb = 0x0fU;
    __Vtask_axi_lite_tb__DOT__axi_write__10__data = 0xffffffffU;
    __Vtask_axi_lite_tb__DOT__axi_write__10__addr = 0x00000010U;
    __Vtask_axi_lite_tb__DOT__axi_write__10__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         53);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR = __Vtask_axi_lite_tb__DOT__axi_write__10__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA = __Vtask_axi_lite_tb__DOT__axi_write__10__data;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB = __Vtask_axi_lite_tb__DOT__axi_write__10__strb;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 1U;
    while ((1U & (~ ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                     & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY))))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(vlSelf, 
                                                           "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
        co_await vlSelfRef.__VtrigSched_h15d04b76__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))", 
                                                             "tb/axi_lite_tb.sv", 
                                                             64);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         65);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID = 0U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.BVALID)");
        co_await vlSelfRef.__VtrigSched_h6c264e19__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.BVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             69);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_write__10__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp 
        = __Vtask_axi_lite_tb__DOT__axi_write__10__resp;
    if (VL_UNLIKELY(((2U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:260: Assertion failed in %m: Invalid write response failed: expected SLVERR, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 260, "");
    } else {
        VL_WRITEF_NX("Invalid write correctly returned SLVERR\n",0);
    }
    __Vtask_axi_lite_tb__DOT__axi_read__11__addr = 0x00000010U;
    __Vtask_axi_lite_tb__DOT__axi_read__11__data = 0;
    __Vtask_axi_lite_tb__DOT__axi_read__11__resp = 0;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         146);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR = __Vtask_axi_lite_tb__DOT__axi_read__11__addr;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 1U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.ARREADY)");
        co_await vlSelfRef.__VtrigSched_h0d5f886f__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.ARREADY)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             152);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         153);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID = 0U;
    while ((1U & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)))) {
        Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(vlSelf, 
                                                           "@( axi_lite_tb.bus.RVALID)");
        co_await vlSelfRef.__VtrigSched_h4d9a469e__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( axi_lite_tb.bus.RVALID)", 
                                                             "tb/axi_lite_tb.sv", 
                                                             156);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    __Vtask_axi_lite_tb__DOT__axi_read__11__data = vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA;
    __Vtask_axi_lite_tb__DOT__axi_read__11__resp = vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP;
    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(vlSelf, 
                                                       "@(posedge axi_lite_tb.ACLK)");
    co_await vlSelfRef.__VtrigSched_h6caf7641__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge axi_lite_tb.ACLK)", 
                                                         "tb/axi_lite_tb.sv", 
                                                         159);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY = 0U;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data 
        = __Vtask_axi_lite_tb__DOT__axi_read__11__data;
    vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp 
        = __Vtask_axi_lite_tb__DOT__axi_read__11__resp;
    if (VL_UNLIKELY(((2U != (IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp))))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:269: Assertion failed in %m: Invalid read response failed: expected SLVERR, got 0b%02b\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2,(IData)(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp));
        VL_STOP_MT("tb/axi_lite_tb.sv", 269, "");
    } else {
        VL_WRITEF_NX("Invalid read correctly returned SLVERR\n",0);
    }
    if (VL_UNLIKELY(((0U != vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data)))) {
        VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:275: Assertion failed in %m: Invalid read data failed: expected 0x00000000, got 0x%08h\n",4, 'M',vlSymsp->name(),"axi_lite_tb.unnamedblk1", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',32,vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data);
        VL_STOP_MT("tb/axi_lite_tb.sv", 275, "");
    }
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000014ULL, 
                                         nullptr, "tb/axi_lite_tb.sv", 
                                         279);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    VL_FINISH_MT("tb/axi_lite_tb.sv", 280, "");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_return;
}

VlCoroutine Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__3(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial__TOP__Vtiming__3\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/axi_lite_tb.sv", 
                                         284);
    VL_WRITEF_NX("[%0t] %%Error: axi_lite_tb.sv:285: Assertion failed in %m: Simulation timeout\n",3, 'M',vlSymsp->name(),"axi_lite_tb", 'T',-12
                 , '#',64,VL_TIME_UNITED_Q(1));
    VL_STOP_MT("tb/axi_lite_tb.sv", 285, "");
    VL_FINISH_MT("tb/axi_lite_tb.sv", 286, "");
    co_return;
}

void Vaxi_lite_tb___024root___eval_triggers_vec__act(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_triggers_vec__act\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vtrigprevexpr_h91e75ef1__0;
    __Vtrigprevexpr_h91e75ef1__0 = 0;
    // Body
    __Vtrigprevexpr_h91e75ef1__0 = ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                                    & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY));
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY) 
                                                        != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0)) 
                                                       << 9U) 
                                                      | (((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0)) 
                                                         << 8U)) 
                                                     | (((((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID) 
                                                             != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0)) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0)) 
                                                              << 1U) 
                                                             | ((IData)(__Vtrigprevexpr_h91e75ef1__0) 
                                                                != (IData)(vlSelfRef.__Vtrigprevexpr_h91e75ef1__1)))) 
                                                         << 4U) 
                                                        | (((((IData)(vlSelfRef.axi_lite_tb__DOT__ARESETN) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0)) 
                                                             << 3U) 
                                                            | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.axi_lite_tb__DOT__ARESETN)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.axi_lite_tb__DOT__ACLK) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0)))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0 
        = vlSelfRef.axi_lite_tb__DOT__ACLK;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0 
        = vlSelfRef.axi_lite_tb__DOT__ARESETN;
    vlSelfRef.__Vtrigprevexpr_h91e75ef1__1 = __Vtrigprevexpr_h91e75ef1__0;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY;
}

bool Vaxi_lite_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vaxi_lite_tb___024root___nba_sequent__TOP__0(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___nba_sequent__TOP__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr = 0;
    CData/*0:0*/ __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid = 0;
    IData/*31:0*/ __Vdly__axi_lite_tb__DOT__dut__DOT__write_data;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_data = 0;
    CData/*3:0*/ __Vdly__axi_lite_tb__DOT__dut__DOT__write_strb;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_strb = 0;
    CData/*0:0*/ __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid = 0;
    CData/*7:0*/ __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v0;
    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v0 = 0;
    CData/*1:0*/ __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v0;
    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v0;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v1;
    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v1 = 0;
    CData/*1:0*/ __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v1;
    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v1 = 0;
    CData/*0:0*/ __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v1;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v1 = 0;
    CData/*7:0*/ __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v2;
    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v2 = 0;
    CData/*1:0*/ __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v2;
    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v2 = 0;
    CData/*0:0*/ __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v2;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v2 = 0;
    CData/*7:0*/ __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v3;
    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v3 = 0;
    CData/*1:0*/ __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v3;
    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v3 = 0;
    CData/*0:0*/ __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v3;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v3 = 0;
    CData/*0:0*/ __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v4;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v4 = 0;
    // Body
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr 
        = vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid 
        = vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_data 
        = vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_strb 
        = vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb;
    __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid 
        = vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v0 = 0U;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v1 = 0U;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v2 = 0U;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v3 = 0U;
    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v4 = 0U;
    if (vlSelfRef.axi_lite_tb__DOT__ARESETN) {
        vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY = 0U;
        if (((~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID)) 
             & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID))) {
            vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY = 1U;
            if ((4U > (vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR 
                       >> 2U))) {
                vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA 
                    = vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs
                    [(3U & (vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR 
                            >> 2U))];
                vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP = 0U;
            } else {
                vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA = 0U;
                vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP = 2U;
            }
            vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__RVALID = 1U;
        }
        if (((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID) 
             & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY))) {
            vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__RVALID = 0U;
        }
        vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY = 0U;
        if (((~ (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid)) 
             & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID))) {
            vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY = 1U;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr 
                = vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid = 1U;
        }
        if (((~ (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid)) 
             & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID))) {
            vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY = 1U;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_data 
                = vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_strb 
                = vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid = 1U;
        }
        if ((((IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid) 
              & (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid)) 
             & (~ (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID)))) {
            if ((4U > (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                       >> 2U))) {
                if ((1U & (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb))) {
                    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v0 
                        = (0x000000ffU & vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data);
                    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v0 
                        = (3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                 >> 2U));
                    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v0 = 1U;
                }
                vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP = 0U;
                if ((2U & (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb))) {
                    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v1 
                        = (0x000000ffU & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data 
                                          >> 8U));
                    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v1 
                        = (3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                 >> 2U));
                    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v1 = 1U;
                }
                if ((4U & (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb))) {
                    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v2 
                        = (0x000000ffU & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data 
                                          >> 0x10U));
                    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v2 
                        = (3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                 >> 2U));
                    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v2 = 1U;
                }
                if ((8U & (IData)(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb))) {
                    __VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v3 
                        = (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data 
                           >> 0x18U);
                    __VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v3 
                        = (3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                 >> 2U));
                    __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v3 = 1U;
                }
            } else {
                vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP = 2U;
            }
            vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__BVALID = 1U;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid = 0U;
            __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid = 0U;
        }
        if (((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID) 
             & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY))) {
            vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__BVALID = 0U;
        }
    } else {
        vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__RVALID = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.__Vdly__BVALID = 0U;
        vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP = 0U;
        __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid = 0U;
        __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid = 0U;
        __VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v4 = 1U;
    }
    vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
        = __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr;
    vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid 
        = __Vdly__axi_lite_tb__DOT__dut__DOT__write_addr_valid;
    vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data 
        = __Vdly__axi_lite_tb__DOT__dut__DOT__write_data;
    vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb 
        = __Vdly__axi_lite_tb__DOT__dut__DOT__write_strb;
    vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid 
        = __Vdly__axi_lite_tb__DOT__dut__DOT__write_data_valid;
    if (__VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v0) {
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v0] 
            = ((0xffffff00U & vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs
                [__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v0]) 
               | (IData)(__VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v0));
    }
    if (__VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v1) {
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v1] 
            = ((0xffff00ffU & vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs
                [__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v1]) 
               | ((IData)(__VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v1) 
                  << 8U));
    }
    if (__VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v2) {
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v2] 
            = ((0xff00ffffU & vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs
                [__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v2]) 
               | ((IData)(__VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v3) {
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v3] 
            = ((0x00ffffffU & vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs
                [__VdlyDim0__axi_lite_tb__DOT__dut__DOT__regs__v3]) 
               | ((IData)(__VdlyVal__axi_lite_tb__DOT__dut__DOT__regs__v3) 
                  << 0x00000018U));
    }
    if (__VdlySet__axi_lite_tb__DOT__dut__DOT__regs__v4) {
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[0U] = 0U;
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[1U] = 0U;
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[2U] = 0U;
        vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs[3U] = 0U;
    }
}

void Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__0(Vaxi_lite_tb_axi_lite_if* vlSelf);
void Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__1(Vaxi_lite_tb_axi_lite_if* vlSelf);

void Vaxi_lite_tb___024root___eval_nba(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_nba\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__0((&vlSymsp->TOP__axi_lite_tb__DOT__bus));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vaxi_lite_tb___024root___nba_sequent__TOP__0(vlSelf);
        Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__1((&vlSymsp->TOP__axi_lite_tb__DOT__bus));
    }
}

void Vaxi_lite_tb___024root___timing_ready(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___timing_ready\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6caf7641__0.ready("@(posedge axi_lite_tb.ACLK)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6a9430a7__0.ready("@( axi_lite_tb.ARESETN)");
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h15d04b76__0.ready("@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6c264e19__0.ready("@( axi_lite_tb.bus.BVALID)");
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready("@( axi_lite_tb.bus.ARREADY)");
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready("@( axi_lite_tb.bus.RVALID)");
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h89f01a72__0.ready("@( axi_lite_tb.bus.AWREADY)");
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb447cace__0.ready("@( axi_lite_tb.bus.WREADY)");
    }
}

void Vaxi_lite_tb___024root___timing_resume(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___timing_resume\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h6caf7641__0.moveToResumeQueue(
                                                          "@(posedge axi_lite_tb.ACLK)");
    vlSelfRef.__VtrigSched_h6a9430a7__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.ARESETN)");
    vlSelfRef.__VtrigSched_h15d04b76__0.moveToResumeQueue(
                                                          "@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
    vlSelfRef.__VtrigSched_h6c264e19__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.bus.BVALID)");
    vlSelfRef.__VtrigSched_h0d5f886f__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.bus.ARREADY)");
    vlSelfRef.__VtrigSched_h4d9a469e__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.bus.RVALID)");
    vlSelfRef.__VtrigSched_h89f01a72__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.bus.AWREADY)");
    vlSelfRef.__VtrigSched_hb447cace__0.moveToResumeQueue(
                                                          "@( axi_lite_tb.bus.WREADY)");
    vlSelfRef.__VtrigSched_h6caf7641__0.resume("@(posedge axi_lite_tb.ACLK)");
    vlSelfRef.__VtrigSched_h6a9430a7__0.resume("@( axi_lite_tb.ARESETN)");
    vlSelfRef.__VtrigSched_h15d04b76__0.resume("@( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))");
    vlSelfRef.__VtrigSched_h6c264e19__0.resume("@( axi_lite_tb.bus.BVALID)");
    vlSelfRef.__VtrigSched_h0d5f886f__0.resume("@( axi_lite_tb.bus.ARREADY)");
    vlSelfRef.__VtrigSched_h4d9a469e__0.resume("@( axi_lite_tb.bus.RVALID)");
    vlSelfRef.__VtrigSched_h89f01a72__0.resume("@( axi_lite_tb.bus.AWREADY)");
    vlSelfRef.__VtrigSched_hb447cace__0.resume("@( axi_lite_tb.bus.WREADY)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaxi_lite_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_lite_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vaxi_lite_tb___024root___eval_phase__act(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_phase__act\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vaxi_lite_tb___024root___eval_triggers_vec__act(vlSelf);
    Vaxi_lite_tb___024root___timing_ready(vlSelf);
    Vaxi_lite_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaxi_lite_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vaxi_lite_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vaxi_lite_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vaxi_lite_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vaxi_lite_tb___024root___eval_phase__inact(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_phase__inact\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/axi_lite_tb.sv", 4, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vaxi_lite_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vaxi_lite_tb___024root___eval_phase__nba(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_phase__nba\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vaxi_lite_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vaxi_lite_tb___024root___eval_nba(vlSelf);
        Vaxi_lite_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vaxi_lite_tb___024root___eval(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vaxi_lite_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/axi_lite_tb.sv", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/axi_lite_tb.sv", 4, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vaxi_lite_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/axi_lite_tb.sv", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vaxi_lite_tb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vaxi_lite_tb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vaxi_lite_tb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h6caf7641__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.axi_lite_tb__DOT__ACLK) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0 
        = vlSelfRef.axi_lite_tb__DOT__ACLK;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6caf7641__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h6a9430a7__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h6a9430a7__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSelfRef.axi_lite_tb__DOT__ARESETN) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0)) 
                                  << 3U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0 
        = vlSelfRef.axi_lite_tb__DOT__ARESETN;
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6a9430a7__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h15d04b76__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    CData/*0:0*/ __Vtrigprevexpr_h91e75ef1__0;
    __Vtrigprevexpr_h91e75ef1__0 = 0;
    // Body
    __Vtrigprevexpr_h91e75ef1__0 = ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                                    & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY));
    __VTmp[0U] = (QData)((IData)((((IData)(__Vtrigprevexpr_h91e75ef1__0) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr_h91e75ef1__1)) 
                                  << 4U)));
    vlSelfRef.__Vtrigprevexpr_h91e75ef1__1 = __Vtrigprevexpr_h91e75ef1__0;
    if ((0x0000000000000010ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h15d04b76__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h15d04b76__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h15d04b76__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h15d04b76__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h6c264e19__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0)) 
                                  << 5U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID;
    if ((0x0000000000000020ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6c264e19__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h0d5f886f__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0)) 
                                  << 6U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY;
    if ((0x0000000000000040ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0d5f886f__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h4d9a469e__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0)) 
                                  << 7U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID;
    if ((0x0000000000000080ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h4d9a469e__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_h89f01a72__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_h89f01a72__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0)) 
                                  << 8U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY;
    if ((0x0000000000000100ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h89f01a72__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h89f01a72__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vaxi_lite_tb___024root____VbeforeTrig_hb447cace__0(Vaxi_lite_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root____VbeforeTrig_hb447cace__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0)) 
                                  << 9U)));
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0 
        = vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY;
    if ((0x0000000000000200ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb447cace__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb447cace__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vaxi_lite_tb___024root___eval_debug_assertions(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_debug_assertions\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
