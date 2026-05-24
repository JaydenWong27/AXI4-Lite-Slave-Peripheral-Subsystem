// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

void Vaxi_lite_tb_axi_lite_if___ctor_var_reset(Vaxi_lite_tb_axi_lite_if* vlSelf);

Vaxi_lite_tb_axi_lite_if::Vaxi_lite_tb_axi_lite_if() = default;
Vaxi_lite_tb_axi_lite_if::~Vaxi_lite_tb_axi_lite_if() = default;

void Vaxi_lite_tb_axi_lite_if::ctor(Vaxi_lite_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vaxi_lite_tb_axi_lite_if___ctor_var_reset(this);
}

void Vaxi_lite_tb_axi_lite_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vaxi_lite_tb_axi_lite_if::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
