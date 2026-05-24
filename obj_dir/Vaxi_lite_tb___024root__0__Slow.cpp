// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_static__TOP(Vaxi_lite_tb___024root* vlSelf);
void Vaxi_lite_tb___024root___timing_ready(Vaxi_lite_tb___024root* vlSelf);

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_static(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_static\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaxi_lite_tb___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000020ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000040ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000080ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000100ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000200ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0 
        = vlSelfRef.axi_lite_tb__DOT__ACLK;
    vlSelfRef.__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0 
        = vlSelfRef.axi_lite_tb__DOT__ARESETN;
    vlSelfRef.__Vtrigprevexpr_h91e75ef1__1 = ((IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY) 
                                              & (IData)(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY));
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
    Vaxi_lite_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_static__TOP(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_static__TOP\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->axi_lite_tb__DOT__unnamedblk1__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10742934285636747377ull);
    vlSelf->axi_lite_tb__DOT__unnamedblk1__DOT__write_resp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1223456809033189347ull);
    vlSelf->axi_lite_tb__DOT__unnamedblk1__DOT__read_resp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1763870582872269202ull);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_initial__TOP(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_initial__TOP\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("axi_lite_tb.vcd"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_final(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_final\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vaxi_lite_tb___024root___eval_settle(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___eval_settle\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vaxi_lite_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_lite_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vaxi_lite_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge axi_lite_tb.ACLK)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge axi_lite_tb.ARESETN)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( axi_lite_tb.ARESETN)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( (axi_lite_tb.bus.AWREADY & axi_lite_tb.bus.WREADY))\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( axi_lite_tb.bus.BVALID)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( axi_lite_tb.bus.ARREADY)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( axi_lite_tb.bus.RVALID)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( axi_lite_tb.bus.AWREADY)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @( axi_lite_tb.bus.WREADY)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaxi_lite_tb___024root___ctor_var_reset(Vaxi_lite_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root___ctor_var_reset\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->axi_lite_tb__DOT__ACLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17787633544070898003ull);
    vlSelf->axi_lite_tb__DOT__ARESETN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5819785463558284331ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->axi_lite_tb__DOT__dut__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3227838533358516106ull);
    }
    vlSelf->axi_lite_tb__DOT__dut__DOT__write_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16276658715491659098ull);
    vlSelf->axi_lite_tb__DOT__dut__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9330927349967340576ull);
    vlSelf->axi_lite_tb__DOT__dut__DOT__write_strb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5162779059860270699ull);
    vlSelf->axi_lite_tb__DOT__dut__DOT__write_addr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9918444107696557712ull);
    vlSelf->axi_lite_tb__DOT__dut__DOT__write_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1969858148688094646ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ACLK__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__ARESETN__0 = 0;
    vlSelf->__Vtrigprevexpr_h91e75ef1__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__BVALID__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__ARREADY__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__RVALID__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__AWREADY__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__axi_lite_tb__DOT__bus__WREADY__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
