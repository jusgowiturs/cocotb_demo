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
    bufp->chgCData(oldp+2,(vlSelf->saxi_awaddr),6);
    bufp->chgBit(oldp+3,(vlSelf->saxi_awvalid));
    bufp->chgBit(oldp+4,(vlSelf->saxi_awready));
    bufp->chgIData(oldp+5,(vlSelf->saxi_wdata),32);
    bufp->chgCData(oldp+6,(vlSelf->saxi_wstrb),4);
    bufp->chgBit(oldp+7,(vlSelf->saxi_wvalid));
    bufp->chgBit(oldp+8,(vlSelf->saxi_wready));
    bufp->chgCData(oldp+9,(vlSelf->saxi_bresp),2);
    bufp->chgBit(oldp+10,(vlSelf->saxi_bvalid));
    bufp->chgBit(oldp+11,(vlSelf->saxi_bready));
    bufp->chgCData(oldp+12,(vlSelf->saxi_araddr),6);
    bufp->chgBit(oldp+13,(vlSelf->saxi_arvalid));
    bufp->chgBit(oldp+14,(vlSelf->saxi_arready));
    bufp->chgIData(oldp+15,(vlSelf->saxi_rdata),32);
    bufp->chgCData(oldp+16,(vlSelf->saxi_rresp),2);
    bufp->chgBit(oldp+17,(vlSelf->saxi_rvalid));
    bufp->chgBit(oldp+18,(vlSelf->saxi_rready));
    bufp->chgBit(oldp+19,(vlSelf->pwm_out));
    bufp->chgBit(oldp+20,(vlSelf->smart_timer_axil__DOT__ACLK));
    bufp->chgBit(oldp+21,(vlSelf->smart_timer_axil__DOT__ARESETn));
    bufp->chgCData(oldp+22,(vlSelf->smart_timer_axil__DOT__saxi_awaddr),6);
    bufp->chgBit(oldp+23,(vlSelf->smart_timer_axil__DOT__saxi_awvalid));
    bufp->chgBit(oldp+24,(vlSelf->smart_timer_axil__DOT__saxi_awready));
    bufp->chgIData(oldp+25,(vlSelf->smart_timer_axil__DOT__saxi_wdata),32);
    bufp->chgCData(oldp+26,(vlSelf->smart_timer_axil__DOT__saxi_wstrb),4);
    bufp->chgBit(oldp+27,(vlSelf->smart_timer_axil__DOT__saxi_wvalid));
    bufp->chgBit(oldp+28,(vlSelf->smart_timer_axil__DOT__saxi_wready));
    bufp->chgCData(oldp+29,(vlSelf->smart_timer_axil__DOT__saxi_bresp),2);
    bufp->chgBit(oldp+30,(vlSelf->smart_timer_axil__DOT__saxi_bvalid));
    bufp->chgBit(oldp+31,(vlSelf->smart_timer_axil__DOT__saxi_bready));
    bufp->chgCData(oldp+32,(vlSelf->smart_timer_axil__DOT__saxi_araddr),6);
    bufp->chgBit(oldp+33,(vlSelf->smart_timer_axil__DOT__saxi_arvalid));
    bufp->chgBit(oldp+34,(vlSelf->smart_timer_axil__DOT__saxi_arready));
    bufp->chgIData(oldp+35,(vlSelf->smart_timer_axil__DOT__saxi_rdata),32);
    bufp->chgCData(oldp+36,(vlSelf->smart_timer_axil__DOT__saxi_rresp),2);
    bufp->chgBit(oldp+37,(vlSelf->smart_timer_axil__DOT__saxi_rvalid));
    bufp->chgBit(oldp+38,(vlSelf->smart_timer_axil__DOT__saxi_rready));
    bufp->chgBit(oldp+39,(vlSelf->smart_timer_axil__DOT__pwm_out));
    bufp->chgBit(oldp+40,(vlSelf->smart_timer_axil__DOT__aw_hs_done));
    bufp->chgCData(oldp+41,(vlSelf->smart_timer_axil__DOT__awaddr_q),6);
    bufp->chgBit(oldp+42,(vlSelf->smart_timer_axil__DOT__w_hs_done));
    bufp->chgIData(oldp+43,(vlSelf->smart_timer_axil__DOT__wdata_q),32);
    bufp->chgCData(oldp+44,(vlSelf->smart_timer_axil__DOT__wstrb_q),4);
    bufp->chgBit(oldp+45,(vlSelf->smart_timer_axil__DOT__ar_hs_done));
    bufp->chgCData(oldp+46,(vlSelf->smart_timer_axil__DOT__araddr_q),6);
    bufp->chgBit(oldp+47,(vlSelf->smart_timer_axil__DOT__do_write));
    bufp->chgCData(oldp+48,(vlSelf->smart_timer_axil__DOT__word_sel_w),2);
    bufp->chgCData(oldp+49,(vlSelf->smart_timer_axil__DOT__word_sel_r),2);
    bufp->chgBit(oldp+50,(vlSelf->smart_timer_axil__DOT__ctrl_en));
    bufp->chgBit(oldp+51,(vlSelf->smart_timer_axil__DOT__ctrl_rst_pulse));
    bufp->chgIData(oldp+52,(vlSelf->smart_timer_axil__DOT__period_shadow),32);
    bufp->chgIData(oldp+53,(vlSelf->smart_timer_axil__DOT__period_active),32);
    bufp->chgIData(oldp+54,(vlSelf->smart_timer_axil__DOT__duty_shadow),32);
    bufp->chgIData(oldp+55,(vlSelf->smart_timer_axil__DOT__duty_active),32);
    bufp->chgBit(oldp+56,(vlSelf->smart_timer_axil__DOT__upd_pending));
    bufp->chgBit(oldp+57,(vlSelf->smart_timer_axil__DOT__status_wrap));
    bufp->chgIData(oldp+58,(vlSelf->smart_timer_axil__DOT__i),32);
    bufp->chgBit(oldp+59,(vlSelf->smart_timer_axil__DOT__rstn_core));
    bufp->chgBit(oldp+60,(vlSelf->smart_timer_axil__DOT__wrap_pulse));
    bufp->chgBit(oldp+61,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__clk));
    bufp->chgBit(oldp+62,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__rstn));
    bufp->chgBit(oldp+63,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__en));
    bufp->chgIData(oldp+64,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__period),32);
    bufp->chgIData(oldp+65,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty),32);
    bufp->chgBit(oldp+66,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__pwm_out));
    bufp->chgBit(oldp+67,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__wrap));
    bufp->chgIData(oldp+68,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__cnt),32);
    bufp->chgIData(oldp+69,(vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty_clip),32);
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
