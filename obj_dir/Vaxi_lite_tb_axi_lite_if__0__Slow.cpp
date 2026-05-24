// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_lite_tb.h for the primary calling header

#include "Vaxi_lite_tb__pch.h"

VL_ATTR_COLD void Vaxi_lite_tb_axi_lite_if___ctor_var_reset(Vaxi_lite_tb_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vaxi_lite_tb_axi_lite_if___ctor_var_reset\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->ACLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3034660589080906099ull);
    vlSelf->ARESETN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18228550893963144628ull);
    vlSelf->AWADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3704207311081907456ull);
    vlSelf->AWPROT = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7076923066334087385ull);
    vlSelf->AWVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11750918698781911943ull);
    vlSelf->AWREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17297234574184235162ull);
    vlSelf->WDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13545846466767745629ull);
    vlSelf->WSTRB = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17384056636743468383ull);
    vlSelf->WVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9495255681580949789ull);
    vlSelf->WREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17076114656213402080ull);
    vlSelf->BRESP = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12793087776628502554ull);
    vlSelf->BVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8367422369656964262ull);
    vlSelf->BREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18149121645282540317ull);
    vlSelf->ARADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17761954141230437835ull);
    vlSelf->ARPROT = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4622094218666349735ull);
    vlSelf->ARVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1896485211029909696ull);
    vlSelf->ARREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11936612248788037190ull);
    vlSelf->RDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4866321451055619796ull);
    vlSelf->RRESP = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17082317525515500324ull);
    vlSelf->RVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5829902753712117520ull);
    vlSelf->RREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2085817933989443683ull);
    vlSelf->__Vdly__BVALID = 0;
    vlSelf->__Vdly__RVALID = 0;
}
