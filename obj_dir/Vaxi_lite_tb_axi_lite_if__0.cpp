// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

void Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__0(Vaxi_lite_tb_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__RVALID = vlSelfRef.RVALID;
    vlSelfRef.__Vdly__BVALID = vlSelfRef.BVALID;
}

void Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__1(Vaxi_lite_tb_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vaxi_lite_tb_axi_lite_if___nba_sequent__TOP__axi_lite_tb__DOT__bus__1\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.RVALID = vlSelfRef.__Vdly__RVALID;
    vlSelfRef.BVALID = vlSelfRef.__Vdly__BVALID;
}

std::string VL_TO_STRING(const Vaxi_lite_tb_axi_lite_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vaxi_lite_tb_axi_lite_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
