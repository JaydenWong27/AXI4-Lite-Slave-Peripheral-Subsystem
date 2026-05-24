// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vaxi_lite_tb__Syms.h"


VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_sub__TOP__axi_lite_tb__DOT__bus__0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_sub__TOP__0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_init_sub__TOP__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"ACLK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+30,0,"ARESETN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "bus", VerilatedTracePrefixType::SCOPE_INTERFACE, 0, 0);
    Vaxi_lite_tb___024root__trace_init_sub__TOP__axi_lite_tb__DOT__bus__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"NUM_REGS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vaxi_lite_tb___024root__trace_init_dtype____0(vlSelf, tracep, "regs", 0, c+10, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"ADDR_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"REG_INDEX_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"write_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"write_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+17,0,"write_addr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"write_data_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"write_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"write_addr_in_range",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"read_addr_in_range",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "bus", VerilatedTracePrefixType::SCOPE_INTERFACE, 0, 0);
    Vaxi_lite_tb___024root__trace_init_sub__TOP__axi_lite_tb__DOT__bus__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+32,0,"write_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+33,0,"read_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_dtype_sub____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_init_dtype____0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaxi_lite_tb___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_dtype_sub____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_init_dtype_sub____0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    for (int i = 0; i < 4; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_sub__TOP__axi_lite_tb__DOT__bus__0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_init_sub__TOP__axi_lite_tb__DOT__bus__0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+36,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"ACLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+30,0,"ARESETN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"STRB_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"AWADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+34,0,"AWPROT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"AWVALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+21,0,"AWREADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"WDATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"WSTRB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"WVALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+22,0,"WREADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"BRESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"BVALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"BREADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"ARADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"ARPROT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"ARVALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"ARREADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"RDATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"RRESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"RVALID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"RREADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_init_top(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_init_top\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaxi_lite_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi_lite_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi_lite_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_register(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_register\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vaxi_lite_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vaxi_lite_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vaxi_lite_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vaxi_lite_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_const_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_const_0\n"); );
    // Body
    Vaxi_lite_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_lite_tb___024root*>(voidSelf);
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vaxi_lite_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_const_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_const_0_sub_0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+36,(0x00000020U),32);
    bufp->fullIData(oldp+37,(4U),32);
    bufp->fullIData(oldp+38,(2U),32);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_full_0\n"); );
    // Body
    Vaxi_lite_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_lite_tb___024root*>(voidSelf);
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vaxi_lite_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar);

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_full_0_sub_0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,((4U > (vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR 
                                 >> 2U))));
    bufp->fullIData(oldp+1,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR),32);
    bufp->fullBit(oldp+2,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID));
    bufp->fullIData(oldp+3,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA),32);
    bufp->fullCData(oldp+4,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB),4);
    bufp->fullBit(oldp+5,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID));
    bufp->fullBit(oldp+6,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY));
    bufp->fullIData(oldp+7,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR),32);
    bufp->fullBit(oldp+8,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID));
    bufp->fullBit(oldp+9,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY));
    Vaxi_lite_tb___024root__trace_full_dtype____0(vlSelf, bufp, 10, vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs);
    bufp->fullIData(oldp+14,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr),32);
    bufp->fullIData(oldp+15,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data),32);
    bufp->fullCData(oldp+16,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb),4);
    bufp->fullBit(oldp+17,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid));
    bufp->fullBit(oldp+18,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid));
    bufp->fullCData(oldp+19,((3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                    >> 2U))),2);
    bufp->fullBit(oldp+20,((4U > (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                  >> 2U))));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY));
    bufp->fullBit(oldp+22,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY));
    bufp->fullCData(oldp+23,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP),2);
    bufp->fullBit(oldp+24,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY));
    bufp->fullIData(oldp+26,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA),32);
    bufp->fullCData(oldp+27,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP),2);
    bufp->fullBit(oldp+28,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID));
    bufp->fullBit(oldp+29,(vlSelfRef.axi_lite_tb__DOT__ACLK));
    bufp->fullBit(oldp+30,(vlSelfRef.axi_lite_tb__DOT__ARESETN));
    bufp->fullIData(oldp+31,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data),32);
    bufp->fullCData(oldp+32,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp),2);
    bufp->fullCData(oldp+33,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp),2);
    bufp->fullCData(oldp+34,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWPROT),3);
    bufp->fullCData(oldp+35,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARPROT),3);
}

VL_ATTR_COLD void Vaxi_lite_tb___024root__trace_full_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_full_dtype____0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),32);
}
