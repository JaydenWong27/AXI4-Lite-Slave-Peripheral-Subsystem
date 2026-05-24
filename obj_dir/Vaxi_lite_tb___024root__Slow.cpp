// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

void Vaxi_lite_tb___024root___ctor_var_reset(Vaxi_lite_tb___024root* vlSelf);

Vaxi_lite_tb___024root::Vaxi_lite_tb___024root(Vaxi_lite_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vaxi_lite_tb___024root___ctor_var_reset(this);
}

void Vaxi_lite_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vaxi_lite_tb___024root::~Vaxi_lite_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
