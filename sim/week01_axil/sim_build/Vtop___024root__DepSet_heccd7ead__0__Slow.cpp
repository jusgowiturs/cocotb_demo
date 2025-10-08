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
            VL_FATAL_MT("/mnt/d/BS_ES/EL_FPGA/coco_tb/sim/week01_axil/rtl/axil_regbank.v", 7, "", "Settle region did not converge.");
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
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
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ACLK = VL_RAND_RESET_I(1);
    vlSelf->ARESETn = VL_RAND_RESET_I(1);
    vlSelf->saxi_awaddr = VL_RAND_RESET_I(4);
    vlSelf->saxi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_awready = VL_RAND_RESET_I(1);
    vlSelf->saxi_wdata = VL_RAND_RESET_I(32);
    vlSelf->saxi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->saxi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_wready = VL_RAND_RESET_I(1);
    vlSelf->saxi_bresp = VL_RAND_RESET_I(2);
    vlSelf->saxi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_bready = VL_RAND_RESET_I(1);
    vlSelf->saxi_araddr = VL_RAND_RESET_I(4);
    vlSelf->saxi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_arready = VL_RAND_RESET_I(1);
    vlSelf->saxi_rdata = VL_RAND_RESET_I(32);
    vlSelf->saxi_rresp = VL_RAND_RESET_I(2);
    vlSelf->saxi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->saxi_rready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__ACLK = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__ARESETn = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_awaddr = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__saxi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_awready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_wdata = VL_RAND_RESET_I(32);
    vlSelf->axil_regbank__DOT__saxi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__saxi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_wready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_bresp = VL_RAND_RESET_I(2);
    vlSelf->axil_regbank__DOT__saxi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_bready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_araddr = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__saxi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_arready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_rdata = VL_RAND_RESET_I(32);
    vlSelf->axil_regbank__DOT__saxi_rresp = VL_RAND_RESET_I(2);
    vlSelf->axil_regbank__DOT__saxi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__saxi_rready = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__reg_ctrl = VL_RAND_RESET_I(32);
    vlSelf->axil_regbank__DOT__reg_data = VL_RAND_RESET_I(32);
    vlSelf->axil_regbank__DOT__aw_hs_done = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__awaddr_q = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__w_hs_done = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__wdata_q = VL_RAND_RESET_I(32);
    vlSelf->axil_regbank__DOT__wstrb_q = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__ar_hs_done = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__araddr_q = VL_RAND_RESET_I(4);
    vlSelf->axil_regbank__DOT__do_write = VL_RAND_RESET_I(1);
    vlSelf->axil_regbank__DOT__word_sel_w = VL_RAND_RESET_I(2);
    vlSelf->axil_regbank__DOT__word_sel_r = VL_RAND_RESET_I(2);
    vlSelf->axil_regbank__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__ACLK__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__ARESETn__0 = VL_RAND_RESET_I(1);
}
