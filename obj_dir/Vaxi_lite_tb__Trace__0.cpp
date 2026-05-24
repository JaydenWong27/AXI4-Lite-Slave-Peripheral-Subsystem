// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vaxi_lite_tb__Syms.h"


void Vaxi_lite_tb___024root__trace_chg_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaxi_lite_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_chg_0\n"); );
    // Body
    Vaxi_lite_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_lite_tb___024root*>(voidSelf);
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vaxi_lite_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaxi_lite_tb___024root__trace_chg_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar);

void Vaxi_lite_tb___024root__trace_chg_0_sub_0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_chg_0_sub_0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgBit(oldp+0,((4U > (vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR 
                                    >> 2U))));
        bufp->chgIData(oldp+1,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWADDR),32);
        bufp->chgBit(oldp+2,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWVALID));
        bufp->chgIData(oldp+3,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WDATA),32);
        bufp->chgCData(oldp+4,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WSTRB),4);
        bufp->chgBit(oldp+5,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WVALID));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BREADY));
        bufp->chgIData(oldp+7,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARADDR),32);
        bufp->chgBit(oldp+8,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARVALID));
        bufp->chgBit(oldp+9,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RREADY));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        Vaxi_lite_tb___024root__trace_chg_dtype____0(vlSelf, bufp, 10, vlSelfRef.axi_lite_tb__DOT__dut__DOT__regs);
        bufp->chgIData(oldp+14,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr),32);
        bufp->chgIData(oldp+15,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data),32);
        bufp->chgCData(oldp+16,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_strb),4);
        bufp->chgBit(oldp+17,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr_valid));
        bufp->chgBit(oldp+18,(vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_data_valid));
        bufp->chgCData(oldp+19,((3U & (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                       >> 2U))),2);
        bufp->chgBit(oldp+20,((4U > (vlSelfRef.axi_lite_tb__DOT__dut__DOT__write_addr 
                                     >> 2U))));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWREADY));
        bufp->chgBit(oldp+22,(vlSymsp->TOP__axi_lite_tb__DOT__bus.WREADY));
        bufp->chgCData(oldp+23,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BRESP),2);
        bufp->chgBit(oldp+24,(vlSymsp->TOP__axi_lite_tb__DOT__bus.BVALID));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARREADY));
        bufp->chgIData(oldp+26,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RDATA),32);
        bufp->chgCData(oldp+27,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RRESP),2);
        bufp->chgBit(oldp+28,(vlSymsp->TOP__axi_lite_tb__DOT__bus.RVALID));
    }
    bufp->chgBit(oldp+29,(vlSelfRef.axi_lite_tb__DOT__ACLK));
    bufp->chgBit(oldp+30,(vlSelfRef.axi_lite_tb__DOT__ARESETN));
    bufp->chgIData(oldp+31,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_data),32);
    bufp->chgCData(oldp+32,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__write_resp),2);
    bufp->chgCData(oldp+33,(vlSelfRef.axi_lite_tb__DOT__unnamedblk1__DOT__read_resp),2);
    bufp->chgCData(oldp+34,(vlSymsp->TOP__axi_lite_tb__DOT__bus.AWPROT),3);
    bufp->chgCData(oldp+35,(vlSymsp->TOP__axi_lite_tb__DOT__bus.ARPROT),3);
}

void Vaxi_lite_tb___024root__trace_chg_dtype____0(Vaxi_lite_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_chg_dtype____0\n"); );
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
}

void Vaxi_lite_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_lite_tb___024root__trace_cleanup\n"); );
    // Body
    Vaxi_lite_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_lite_tb___024root*>(voidSelf);
    Vaxi_lite_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
