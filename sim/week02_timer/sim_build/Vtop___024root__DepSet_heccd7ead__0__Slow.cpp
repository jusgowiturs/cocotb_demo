// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__ACLK__0 = vlSelf->ACLK;
    vlSelf->__Vtrigprevexpr___TOP__ARESETn__0 = vlSelf->ARESETn;
    vlSelf->__Vtrigprevexpr___TOP__smart_timer_axil__DOT__rstn_core__0 
        = vlSelf->smart_timer_axil__DOT__rstn_core;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/mnt/d/BS_ES/EL_FPGA/coco_tb/sim/week02_timer/rtl/smart_timer_axil.v", 10, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->smart_timer_axil__DOT__ARESETn = vlSelf->ARESETn;
    vlSelf->smart_timer_axil__DOT__saxi_awaddr = vlSelf->saxi_awaddr;
    vlSelf->smart_timer_axil__DOT__saxi_awvalid = vlSelf->saxi_awvalid;
    vlSelf->smart_timer_axil__DOT__saxi_wdata = vlSelf->saxi_wdata;
    vlSelf->smart_timer_axil__DOT__saxi_wstrb = vlSelf->saxi_wstrb;
    vlSelf->smart_timer_axil__DOT__saxi_wvalid = vlSelf->saxi_wvalid;
    vlSelf->smart_timer_axil__DOT__saxi_bready = vlSelf->saxi_bready;
    vlSelf->smart_timer_axil__DOT__saxi_araddr = vlSelf->saxi_araddr;
    vlSelf->smart_timer_axil__DOT__saxi_arvalid = vlSelf->saxi_arvalid;
    vlSelf->smart_timer_axil__DOT__saxi_rready = vlSelf->saxi_rready;
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__en = vlSelf->smart_timer_axil__DOT__ctrl_en;
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__period 
        = vlSelf->smart_timer_axil__DOT__period_active;
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty 
        = vlSelf->smart_timer_axil__DOT__duty_active;
    vlSelf->saxi_bvalid = vlSelf->smart_timer_axil__DOT__saxi_bvalid;
    vlSelf->saxi_rvalid = vlSelf->smart_timer_axil__DOT__saxi_rvalid;
    vlSelf->saxi_bresp = vlSelf->smart_timer_axil__DOT__saxi_bresp;
    vlSelf->saxi_rdata = vlSelf->smart_timer_axil__DOT__saxi_rdata;
    vlSelf->saxi_rresp = vlSelf->smart_timer_axil__DOT__saxi_rresp;
    vlSelf->smart_timer_axil__DOT__word_sel_w = (3U 
                                                 & ((IData)(vlSelf->smart_timer_axil__DOT__awaddr_q) 
                                                    >> 2U));
    vlSelf->smart_timer_axil__DOT__word_sel_r = (3U 
                                                 & ((IData)(vlSelf->smart_timer_axil__DOT__araddr_q) 
                                                    >> 2U));
    vlSelf->smart_timer_axil__DOT__wrap_pulse = vlSelf->smart_timer_axil__DOT__u_pwm__DOT__wrap;
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty_clip 
        = ((vlSelf->smart_timer_axil__DOT__duty_active 
            > vlSelf->smart_timer_axil__DOT__period_active)
            ? vlSelf->smart_timer_axil__DOT__period_active
            : vlSelf->smart_timer_axil__DOT__duty_active);
    vlSelf->smart_timer_axil__DOT__do_write = ((IData)(vlSelf->smart_timer_axil__DOT__aw_hs_done) 
                                               & ((~ (IData)(vlSelf->smart_timer_axil__DOT__saxi_bvalid)) 
                                                  & (IData)(vlSelf->smart_timer_axil__DOT__w_hs_done)));
    vlSelf->smart_timer_axil__DOT__ACLK = vlSelf->ACLK;
    vlSelf->pwm_out = vlSelf->smart_timer_axil__DOT__u_pwm__DOT__pwm_out;
    vlSelf->saxi_awready = ((~ (IData)(vlSelf->smart_timer_axil__DOT__aw_hs_done)) 
                            & (IData)(vlSelf->ARESETn));
    vlSelf->saxi_wready = ((~ (IData)(vlSelf->smart_timer_axil__DOT__w_hs_done)) 
                           & (IData)(vlSelf->ARESETn));
    vlSelf->smart_timer_axil__DOT__rstn_core = ((~ (IData)(vlSelf->smart_timer_axil__DOT__ctrl_rst_pulse)) 
                                                & (IData)(vlSelf->ARESETn));
    vlSelf->saxi_arready = ((~ (IData)(vlSelf->smart_timer_axil__DOT__ar_hs_done)) 
                            & ((~ (IData)(vlSelf->smart_timer_axil__DOT__saxi_rvalid)) 
                               & (IData)(vlSelf->ARESETn)));
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__clk 
        = vlSelf->smart_timer_axil__DOT__ACLK;
    vlSelf->smart_timer_axil__DOT__pwm_out = vlSelf->pwm_out;
    vlSelf->smart_timer_axil__DOT__saxi_awready = vlSelf->saxi_awready;
    vlSelf->smart_timer_axil__DOT__saxi_wready = vlSelf->saxi_wready;
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__rstn 
        = vlSelf->smart_timer_axil__DOT__rstn_core;
    vlSelf->smart_timer_axil__DOT__saxi_arready = vlSelf->saxi_arready;
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ACLK or negedge ARESETn)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge ACLK or negedge smart_timer_axil.rstn_core)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ACLK or negedge ARESETn)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge ACLK or negedge smart_timer_axil.rstn_core)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ACLK = VL_RAND_RESET_I(1);
    vlSelf->ARESETn = VL_RAND_RESET_I(1);
    vlSelf->saxi_awaddr = VL_RAND_RESET_I(6);
    vlSelf->saxi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_awready = VL_RAND_RESET_I(1);
    vlSelf->saxi_wdata = VL_RAND_RESET_I(32);
    vlSelf->saxi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->saxi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_wready = VL_RAND_RESET_I(1);
    vlSelf->saxi_bresp = VL_RAND_RESET_I(2);
    vlSelf->saxi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_bready = VL_RAND_RESET_I(1);
    vlSelf->saxi_araddr = VL_RAND_RESET_I(6);
    vlSelf->saxi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_arready = VL_RAND_RESET_I(1);
    vlSelf->saxi_rdata = VL_RAND_RESET_I(32);
    vlSelf->saxi_rresp = VL_RAND_RESET_I(2);
    vlSelf->saxi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_rready = VL_RAND_RESET_I(1);
    vlSelf->pwm_out = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__ACLK = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__ARESETn = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_awaddr = VL_RAND_RESET_I(6);
    vlSelf->smart_timer_axil__DOT__saxi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_awready = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_wdata = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__saxi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->smart_timer_axil__DOT__saxi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_wready = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_bresp = VL_RAND_RESET_I(2);
    vlSelf->smart_timer_axil__DOT__saxi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_bready = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_araddr = VL_RAND_RESET_I(6);
    vlSelf->smart_timer_axil__DOT__saxi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_arready = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_rdata = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__saxi_rresp = VL_RAND_RESET_I(2);
    vlSelf->smart_timer_axil__DOT__saxi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__saxi_rready = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__pwm_out = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__aw_hs_done = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__awaddr_q = VL_RAND_RESET_I(6);
    vlSelf->smart_timer_axil__DOT__w_hs_done = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__wdata_q = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__wstrb_q = VL_RAND_RESET_I(4);
    vlSelf->smart_timer_axil__DOT__ar_hs_done = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__araddr_q = VL_RAND_RESET_I(6);
    vlSelf->smart_timer_axil__DOT__do_write = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__word_sel_w = VL_RAND_RESET_I(2);
    vlSelf->smart_timer_axil__DOT__word_sel_r = VL_RAND_RESET_I(2);
    vlSelf->smart_timer_axil__DOT__ctrl_en = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__ctrl_rst_pulse = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__period_shadow = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__period_active = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__duty_shadow = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__duty_active = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__upd_pending = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__status_wrap = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__rstn_core = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__wrap_pulse = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__rstn = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__en = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__period = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__pwm_out = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__wrap = VL_RAND_RESET_I(1);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__cnt = VL_RAND_RESET_I(32);
    vlSelf->smart_timer_axil__DOT__u_pwm__DOT__duty_clip = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__smart_timer_axil__DOT__saxi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__smart_timer_axil__DOT__upd_pending = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__ACLK__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__ARESETn__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__smart_timer_axil__DOT__rstn_core__0 = VL_RAND_RESET_I(1);
}
