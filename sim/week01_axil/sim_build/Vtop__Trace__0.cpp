// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->ACLK));
    bufp->chgBit(oldp+1,(vlSelf->ARESETn));
    bufp->chgCData(oldp+2,(vlSelf->saxi_awaddr),4);
    bufp->chgBit(oldp+3,(vlSelf->saxi_awvalid));
    bufp->chgBit(oldp+4,(vlSelf->saxi_awready));
    bufp->chgIData(oldp+5,(vlSelf->saxi_wdata),32);
    bufp->chgCData(oldp+6,(vlSelf->saxi_wstrb),4);
    bufp->chgBit(oldp+7,(vlSelf->saxi_wvalid));
    bufp->chgBit(oldp+8,(vlSelf->saxi_wready));
    bufp->chgCData(oldp+9,(vlSelf->saxi_bresp),2);
    bufp->chgBit(oldp+10,(vlSelf->saxi_bvalid));
    bufp->chgBit(oldp+11,(vlSelf->saxi_bready));
    bufp->chgCData(oldp+12,(vlSelf->saxi_araddr),4);
    bufp->chgBit(oldp+13,(vlSelf->saxi_arvalid));
    bufp->chgBit(oldp+14,(vlSelf->saxi_arready));
    bufp->chgIData(oldp+15,(vlSelf->saxi_rdata),32);
    bufp->chgCData(oldp+16,(vlSelf->saxi_rresp),2);
    bufp->chgBit(oldp+17,(vlSelf->saxi_rvalid));
    bufp->chgBit(oldp+18,(vlSelf->saxi_rready));
    bufp->chgBit(oldp+19,(vlSelf->axil_regbank__DOT__ACLK));
    bufp->chgBit(oldp+20,(vlSelf->axil_regbank__DOT__ARESETn));
    bufp->chgCData(oldp+21,(vlSelf->axil_regbank__DOT__saxi_awaddr),4);
    bufp->chgBit(oldp+22,(vlSelf->axil_regbank__DOT__saxi_awvalid));
    bufp->chgBit(oldp+23,(vlSelf->axil_regbank__DOT__saxi_awready));
    bufp->chgIData(oldp+24,(vlSelf->axil_regbank__DOT__saxi_wdata),32);
    bufp->chgCData(oldp+25,(vlSelf->axil_regbank__DOT__saxi_wstrb),4);
    bufp->chgBit(oldp+26,(vlSelf->axil_regbank__DOT__saxi_wvalid));
    bufp->chgBit(oldp+27,(vlSelf->axil_regbank__DOT__saxi_wready));
    bufp->chgCData(oldp+28,(vlSelf->axil_regbank__DOT__saxi_bresp),2);
    bufp->chgBit(oldp+29,(vlSelf->axil_regbank__DOT__saxi_bvalid));
    bufp->chgBit(oldp+30,(vlSelf->axil_regbank__DOT__saxi_bready));
    bufp->chgCData(oldp+31,(vlSelf->axil_regbank__DOT__saxi_araddr),4);
    bufp->chgBit(oldp+32,(vlSelf->axil_regbank__DOT__saxi_arvalid));
    bufp->chgBit(oldp+33,(vlSelf->axil_regbank__DOT__saxi_arready));
    bufp->chgIData(oldp+34,(vlSelf->axil_regbank__DOT__saxi_rdata),32);
    bufp->chgCData(oldp+35,(vlSelf->axil_regbank__DOT__saxi_rresp),2);
    bufp->chgBit(oldp+36,(vlSelf->axil_regbank__DOT__saxi_rvalid));
    bufp->chgBit(oldp+37,(vlSelf->axil_regbank__DOT__saxi_rready));
    bufp->chgIData(oldp+38,(vlSelf->axil_regbank__DOT__reg_ctrl),32);
    bufp->chgIData(oldp+39,(vlSelf->axil_regbank__DOT__reg_data),32);
    bufp->chgBit(oldp+40,(vlSelf->axil_regbank__DOT__aw_hs_done));
    bufp->chgCData(oldp+41,(vlSelf->axil_regbank__DOT__awaddr_q),4);
    bufp->chgBit(oldp+42,(vlSelf->axil_regbank__DOT__w_hs_done));
    bufp->chgIData(oldp+43,(vlSelf->axil_regbank__DOT__wdata_q),32);
    bufp->chgCData(oldp+44,(vlSelf->axil_regbank__DOT__wstrb_q),4);
    bufp->chgBit(oldp+45,(vlSelf->axil_regbank__DOT__ar_hs_done));
    bufp->chgCData(oldp+46,(vlSelf->axil_regbank__DOT__araddr_q),4);
    bufp->chgBit(oldp+47,(vlSelf->axil_regbank__DOT__do_write));
    bufp->chgCData(oldp+48,(vlSelf->axil_regbank__DOT__word_sel_w),2);
    bufp->chgCData(oldp+49,(vlSelf->axil_regbank__DOT__word_sel_r),2);
    bufp->chgIData(oldp+50,(vlSelf->axil_regbank__DOT__i),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
