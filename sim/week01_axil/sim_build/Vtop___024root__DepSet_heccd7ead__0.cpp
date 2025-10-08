// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->axil_regbank__DOT__ACLK = vlSelf->ACLK;
    vlSelf->axil_regbank__DOT__ARESETn = vlSelf->ARESETn;
    vlSelf->axil_regbank__DOT__saxi_awaddr = vlSelf->saxi_awaddr;
    vlSelf->axil_regbank__DOT__saxi_awvalid = vlSelf->saxi_awvalid;
    vlSelf->axil_regbank__DOT__saxi_wdata = vlSelf->saxi_wdata;
    vlSelf->axil_regbank__DOT__saxi_wstrb = vlSelf->saxi_wstrb;
    vlSelf->axil_regbank__DOT__saxi_wvalid = vlSelf->saxi_wvalid;
    vlSelf->axil_regbank__DOT__saxi_bready = vlSelf->saxi_bready;
    vlSelf->axil_regbank__DOT__saxi_araddr = vlSelf->saxi_araddr;
    vlSelf->axil_regbank__DOT__saxi_arvalid = vlSelf->saxi_arvalid;
    vlSelf->axil_regbank__DOT__saxi_rready = vlSelf->saxi_rready;
    vlSelf->saxi_bvalid = vlSelf->axil_regbank__DOT__saxi_bvalid;
    vlSelf->saxi_rvalid = vlSelf->axil_regbank__DOT__saxi_rvalid;
    vlSelf->saxi_bresp = vlSelf->axil_regbank__DOT__saxi_bresp;
    vlSelf->saxi_rdata = vlSelf->axil_regbank__DOT__saxi_rdata;
    vlSelf->saxi_rresp = vlSelf->axil_regbank__DOT__saxi_rresp;
    vlSelf->axil_regbank__DOT__word_sel_w = (3U & ((IData)(vlSelf->axil_regbank__DOT__awaddr_q) 
                                                   >> 2U));
    vlSelf->axil_regbank__DOT__word_sel_r = (3U & ((IData)(vlSelf->axil_regbank__DOT__araddr_q) 
                                                   >> 2U));
    vlSelf->axil_regbank__DOT__do_write = ((IData)(vlSelf->axil_regbank__DOT__aw_hs_done) 
                                           & ((~ (IData)(vlSelf->axil_regbank__DOT__saxi_bvalid)) 
                                              & (IData)(vlSelf->axil_regbank__DOT__w_hs_done)));
    vlSelf->saxi_awready = ((~ (IData)(vlSelf->axil_regbank__DOT__aw_hs_done)) 
                            & (IData)(vlSelf->ARESETn));
    vlSelf->saxi_wready = ((~ (IData)(vlSelf->axil_regbank__DOT__w_hs_done)) 
                           & (IData)(vlSelf->ARESETn));
    vlSelf->saxi_arready = ((~ (IData)(vlSelf->axil_regbank__DOT__ar_hs_done)) 
                            & ((~ (IData)(vlSelf->axil_regbank__DOT__saxi_rvalid)) 
                               & (IData)(vlSelf->ARESETn)));
    vlSelf->axil_regbank__DOT__saxi_awready = vlSelf->saxi_awready;
    vlSelf->axil_regbank__DOT__saxi_wready = vlSelf->saxi_wready;
    vlSelf->axil_regbank__DOT__saxi_arready = vlSelf->saxi_arready;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__axil_regbank__DOT__saxi_bvalid;
    __Vdly__axil_regbank__DOT__saxi_bvalid = 0;
    CData/*0:0*/ __Vdly__axil_regbank__DOT__saxi_rvalid;
    __Vdly__axil_regbank__DOT__saxi_rvalid = 0;
    // Body
    __Vdly__axil_regbank__DOT__saxi_bvalid = vlSelf->axil_regbank__DOT__saxi_bvalid;
    __Vdly__axil_regbank__DOT__saxi_rvalid = vlSelf->axil_regbank__DOT__saxi_rvalid;
    if (vlSelf->ARESETn) {
        if ((((~ (IData)(vlSelf->axil_regbank__DOT__aw_hs_done)) 
              & (IData)(vlSelf->saxi_awvalid)) & (IData)(vlSelf->saxi_awready))) {
            vlSelf->axil_regbank__DOT__aw_hs_done = 1U;
            vlSelf->axil_regbank__DOT__awaddr_q = vlSelf->saxi_awaddr;
        }
        if (vlSelf->axil_regbank__DOT__do_write) {
            if ((0U == (IData)(vlSelf->axil_regbank__DOT__word_sel_w))) {
                vlSelf->axil_regbank__DOT__i = 1U;
                vlSelf->axil_regbank__DOT__i = 2U;
                vlSelf->axil_regbank__DOT__i = 3U;
                vlSelf->axil_regbank__DOT__i = 4U;
            } else if ((1U == (IData)(vlSelf->axil_regbank__DOT__word_sel_w))) {
                vlSelf->axil_regbank__DOT__i = 1U;
                vlSelf->axil_regbank__DOT__i = 2U;
                vlSelf->axil_regbank__DOT__i = 3U;
                vlSelf->axil_regbank__DOT__i = 4U;
            }
            __Vdly__axil_regbank__DOT__saxi_bvalid = 1U;
        }
        if ((((~ (IData)(vlSelf->axil_regbank__DOT__ar_hs_done)) 
              & (IData)(vlSelf->saxi_arvalid)) & (IData)(vlSelf->saxi_arready))) {
            vlSelf->axil_regbank__DOT__ar_hs_done = 1U;
            vlSelf->axil_regbank__DOT__araddr_q = vlSelf->saxi_araddr;
            if ((0U == (3U & ((IData)(vlSelf->saxi_araddr) 
                              >> 2U)))) {
                vlSelf->axil_regbank__DOT__saxi_rdata 
                    = vlSelf->axil_regbank__DOT__reg_ctrl;
                vlSelf->axil_regbank__DOT__saxi_rresp = 0U;
            } else if ((1U == (3U & ((IData)(vlSelf->saxi_araddr) 
                                     >> 2U)))) {
                vlSelf->axil_regbank__DOT__saxi_rdata 
                    = vlSelf->axil_regbank__DOT__reg_data;
                vlSelf->axil_regbank__DOT__saxi_rresp = 0U;
            } else {
                vlSelf->axil_regbank__DOT__saxi_rdata = 0U;
                vlSelf->axil_regbank__DOT__saxi_rresp = 2U;
            }
            __Vdly__axil_regbank__DOT__saxi_rvalid = 1U;
        }
        if (vlSelf->axil_regbank__DOT__do_write) {
            if ((0U == (IData)(vlSelf->axil_regbank__DOT__word_sel_w))) {
                vlSelf->axil_regbank__DOT__saxi_bresp = 0U;
                if ((1U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                    vlSelf->axil_regbank__DOT__reg_ctrl 
                        = ((0xffffff00U & vlSelf->axil_regbank__DOT__reg_ctrl) 
                           | (0xffU & vlSelf->axil_regbank__DOT__wdata_q));
                }
                if ((2U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                    vlSelf->axil_regbank__DOT__reg_ctrl 
                        = ((0xffff00ffU & vlSelf->axil_regbank__DOT__reg_ctrl) 
                           | (0xff00U & vlSelf->axil_regbank__DOT__wdata_q));
                }
                if ((4U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                    vlSelf->axil_regbank__DOT__reg_ctrl 
                        = ((0xff00ffffU & vlSelf->axil_regbank__DOT__reg_ctrl) 
                           | (0xff0000U & vlSelf->axil_regbank__DOT__wdata_q));
                }
                if ((8U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                    vlSelf->axil_regbank__DOT__reg_ctrl 
                        = ((0xffffffU & vlSelf->axil_regbank__DOT__reg_ctrl) 
                           | (0xff000000U & vlSelf->axil_regbank__DOT__wdata_q));
                }
            } else {
                vlSelf->axil_regbank__DOT__saxi_bresp 
                    = ((1U == (IData)(vlSelf->axil_regbank__DOT__word_sel_w))
                        ? 0U : 2U);
            }
            if ((0U != (IData)(vlSelf->axil_regbank__DOT__word_sel_w))) {
                if ((1U == (IData)(vlSelf->axil_regbank__DOT__word_sel_w))) {
                    if ((1U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                        vlSelf->axil_regbank__DOT__reg_data 
                            = ((0xffffff00U & vlSelf->axil_regbank__DOT__reg_data) 
                               | (0xffU & vlSelf->axil_regbank__DOT__wdata_q));
                    }
                    if ((2U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                        vlSelf->axil_regbank__DOT__reg_data 
                            = ((0xffff00ffU & vlSelf->axil_regbank__DOT__reg_data) 
                               | (0xff00U & vlSelf->axil_regbank__DOT__wdata_q));
                    }
                    if ((4U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                        vlSelf->axil_regbank__DOT__reg_data 
                            = ((0xff00ffffU & vlSelf->axil_regbank__DOT__reg_data) 
                               | (0xff0000U & vlSelf->axil_regbank__DOT__wdata_q));
                    }
                    if ((8U & (IData)(vlSelf->axil_regbank__DOT__wstrb_q))) {
                        vlSelf->axil_regbank__DOT__reg_data 
                            = ((0xffffffU & vlSelf->axil_regbank__DOT__reg_data) 
                               | (0xff000000U & vlSelf->axil_regbank__DOT__wdata_q));
                    }
                }
            }
        }
        if (((IData)(vlSelf->axil_regbank__DOT__saxi_rvalid) 
             & (IData)(vlSelf->saxi_rready))) {
            __Vdly__axil_regbank__DOT__saxi_rvalid = 0U;
            vlSelf->axil_regbank__DOT__ar_hs_done = 0U;
        }
        if ((((~ (IData)(vlSelf->axil_regbank__DOT__w_hs_done)) 
              & (IData)(vlSelf->saxi_wvalid)) & (IData)(vlSelf->saxi_wready))) {
            vlSelf->axil_regbank__DOT__w_hs_done = 1U;
            vlSelf->axil_regbank__DOT__wdata_q = vlSelf->saxi_wdata;
            vlSelf->axil_regbank__DOT__wstrb_q = vlSelf->saxi_wstrb;
        }
        if (((IData)(vlSelf->axil_regbank__DOT__saxi_bvalid) 
             & (IData)(vlSelf->saxi_bready))) {
            __Vdly__axil_regbank__DOT__saxi_bvalid = 0U;
            vlSelf->axil_regbank__DOT__aw_hs_done = 0U;
            vlSelf->axil_regbank__DOT__w_hs_done = 0U;
        }
        vlSelf->axil_regbank__DOT__saxi_rvalid = __Vdly__axil_regbank__DOT__saxi_rvalid;
        vlSelf->saxi_bresp = vlSelf->axil_regbank__DOT__saxi_bresp;
        vlSelf->saxi_awready = (1U & (~ (IData)(vlSelf->axil_regbank__DOT__aw_hs_done)));
    } else {
        __Vdly__axil_regbank__DOT__saxi_bvalid = 0U;
        vlSelf->axil_regbank__DOT__saxi_bresp = 0U;
        vlSelf->axil_regbank__DOT__aw_hs_done = 0U;
        vlSelf->axil_regbank__DOT__awaddr_q = 0U;
        __Vdly__axil_regbank__DOT__saxi_rvalid = 0U;
        vlSelf->axil_regbank__DOT__ar_hs_done = 0U;
        vlSelf->axil_regbank__DOT__araddr_q = 0U;
        vlSelf->axil_regbank__DOT__saxi_rresp = 0U;
        vlSelf->axil_regbank__DOT__saxi_rdata = 0U;
        vlSelf->axil_regbank__DOT__reg_ctrl = 0U;
        vlSelf->axil_regbank__DOT__reg_data = 0U;
        vlSelf->axil_regbank__DOT__w_hs_done = 0U;
        vlSelf->axil_regbank__DOT__wdata_q = 0U;
        vlSelf->axil_regbank__DOT__wstrb_q = 0U;
        vlSelf->axil_regbank__DOT__saxi_rvalid = __Vdly__axil_regbank__DOT__saxi_rvalid;
        vlSelf->saxi_bresp = vlSelf->axil_regbank__DOT__saxi_bresp;
        vlSelf->saxi_awready = 0U;
    }
    vlSelf->axil_regbank__DOT__word_sel_r = (3U & ((IData)(vlSelf->axil_regbank__DOT__araddr_q) 
                                                   >> 2U));
    vlSelf->saxi_rdata = vlSelf->axil_regbank__DOT__saxi_rdata;
    vlSelf->saxi_rresp = vlSelf->axil_regbank__DOT__saxi_rresp;
    vlSelf->saxi_rvalid = vlSelf->axil_regbank__DOT__saxi_rvalid;
    vlSelf->saxi_arready = ((~ (IData)(vlSelf->axil_regbank__DOT__ar_hs_done)) 
                            & ((~ (IData)(vlSelf->axil_regbank__DOT__saxi_rvalid)) 
                               & (IData)(vlSelf->ARESETn)));
    vlSelf->axil_regbank__DOT__saxi_awready = vlSelf->saxi_awready;
    vlSelf->axil_regbank__DOT__saxi_arready = vlSelf->saxi_arready;
    vlSelf->axil_regbank__DOT__word_sel_w = (3U & ((IData)(vlSelf->axil_regbank__DOT__awaddr_q) 
                                                   >> 2U));
    vlSelf->axil_regbank__DOT__saxi_bvalid = __Vdly__axil_regbank__DOT__saxi_bvalid;
    vlSelf->saxi_bvalid = vlSelf->axil_regbank__DOT__saxi_bvalid;
    vlSelf->axil_regbank__DOT__do_write = ((IData)(vlSelf->axil_regbank__DOT__aw_hs_done) 
                                           & ((~ (IData)(vlSelf->axil_regbank__DOT__saxi_bvalid)) 
                                              & (IData)(vlSelf->axil_regbank__DOT__w_hs_done)));
    vlSelf->saxi_wready = ((~ (IData)(vlSelf->axil_regbank__DOT__w_hs_done)) 
                           & (IData)(vlSelf->ARESETn));
    vlSelf->axil_regbank__DOT__saxi_wready = vlSelf->saxi_wready;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/mnt/d/BS_ES/EL_FPGA/coco_tb/sim/week01_axil/rtl/axil_regbank.v", 7, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/mnt/d/BS_ES/EL_FPGA/coco_tb/sim/week01_axil/rtl/axil_regbank.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/mnt/d/BS_ES/EL_FPGA/coco_tb/sim/week01_axil/rtl/axil_regbank.v", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ACLK & 0xfeU))) {
        Verilated::overWidthError("ACLK");}
    if (VL_UNLIKELY((vlSelf->ARESETn & 0xfeU))) {
        Verilated::overWidthError("ARESETn");}
    if (VL_UNLIKELY((vlSelf->saxi_awaddr & 0xf0U))) {
        Verilated::overWidthError("saxi_awaddr");}
    if (VL_UNLIKELY((vlSelf->saxi_awvalid & 0xfeU))) {
        Verilated::overWidthError("saxi_awvalid");}
    if (VL_UNLIKELY((vlSelf->saxi_wstrb & 0xf0U))) {
        Verilated::overWidthError("saxi_wstrb");}
    if (VL_UNLIKELY((vlSelf->saxi_wvalid & 0xfeU))) {
        Verilated::overWidthError("saxi_wvalid");}
    if (VL_UNLIKELY((vlSelf->saxi_bready & 0xfeU))) {
        Verilated::overWidthError("saxi_bready");}
    if (VL_UNLIKELY((vlSelf->saxi_araddr & 0xf0U))) {
        Verilated::overWidthError("saxi_araddr");}
    if (VL_UNLIKELY((vlSelf->saxi_arvalid & 0xfeU))) {
        Verilated::overWidthError("saxi_arvalid");}
    if (VL_UNLIKELY((vlSelf->saxi_rready & 0xfeU))) {
        Verilated::overWidthError("saxi_rready");}
}
#endif  // VL_DEBUG
