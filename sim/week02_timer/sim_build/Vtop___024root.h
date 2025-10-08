// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(ACLK,0,0);
        VL_IN8(ARESETn,0,0);
        CData/*0:0*/ smart_timer_axil__DOT__rstn_core;
        VL_IN8(saxi_awaddr,5,0);
        VL_IN8(saxi_awvalid,0,0);
        VL_OUT8(saxi_awready,0,0);
        VL_IN8(saxi_wstrb,3,0);
        VL_IN8(saxi_wvalid,0,0);
        VL_OUT8(saxi_wready,0,0);
        VL_OUT8(saxi_bresp,1,0);
        VL_OUT8(saxi_bvalid,0,0);
        VL_IN8(saxi_bready,0,0);
        VL_IN8(saxi_araddr,5,0);
        VL_IN8(saxi_arvalid,0,0);
        VL_OUT8(saxi_arready,0,0);
        VL_OUT8(saxi_rresp,1,0);
        VL_OUT8(saxi_rvalid,0,0);
        VL_IN8(saxi_rready,0,0);
        VL_OUT8(pwm_out,0,0);
        CData/*0:0*/ smart_timer_axil__DOT__ACLK;
        CData/*0:0*/ smart_timer_axil__DOT__ARESETn;
        CData/*5:0*/ smart_timer_axil__DOT__saxi_awaddr;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_awvalid;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_awready;
        CData/*3:0*/ smart_timer_axil__DOT__saxi_wstrb;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_wvalid;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_wready;
        CData/*1:0*/ smart_timer_axil__DOT__saxi_bresp;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_bvalid;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_bready;
        CData/*5:0*/ smart_timer_axil__DOT__saxi_araddr;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_arvalid;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_arready;
        CData/*1:0*/ smart_timer_axil__DOT__saxi_rresp;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_rvalid;
        CData/*0:0*/ smart_timer_axil__DOT__saxi_rready;
        CData/*0:0*/ smart_timer_axil__DOT__pwm_out;
        CData/*0:0*/ smart_timer_axil__DOT__aw_hs_done;
        CData/*5:0*/ smart_timer_axil__DOT__awaddr_q;
        CData/*0:0*/ smart_timer_axil__DOT__w_hs_done;
        CData/*3:0*/ smart_timer_axil__DOT__wstrb_q;
        CData/*0:0*/ smart_timer_axil__DOT__ar_hs_done;
        CData/*5:0*/ smart_timer_axil__DOT__araddr_q;
        CData/*0:0*/ smart_timer_axil__DOT__do_write;
        CData/*1:0*/ smart_timer_axil__DOT__word_sel_w;
        CData/*1:0*/ smart_timer_axil__DOT__word_sel_r;
        CData/*0:0*/ smart_timer_axil__DOT__ctrl_en;
        CData/*0:0*/ smart_timer_axil__DOT__ctrl_rst_pulse;
        CData/*0:0*/ smart_timer_axil__DOT__upd_pending;
        CData/*0:0*/ smart_timer_axil__DOT__status_wrap;
        CData/*0:0*/ smart_timer_axil__DOT__wrap_pulse;
        CData/*0:0*/ smart_timer_axil__DOT__u_pwm__DOT__clk;
        CData/*0:0*/ smart_timer_axil__DOT__u_pwm__DOT__rstn;
        CData/*0:0*/ smart_timer_axil__DOT__u_pwm__DOT__en;
        CData/*0:0*/ smart_timer_axil__DOT__u_pwm__DOT__pwm_out;
        CData/*0:0*/ smart_timer_axil__DOT__u_pwm__DOT__wrap;
        CData/*0:0*/ __Vdly__smart_timer_axil__DOT__saxi_bvalid;
        CData/*0:0*/ __Vdly__smart_timer_axil__DOT__upd_pending;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ACLK__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ARESETn__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__smart_timer_axil__DOT__rstn_core__0;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        VL_IN(saxi_wdata,31,0);
        VL_OUT(saxi_rdata,31,0);
        IData/*31:0*/ smart_timer_axil__DOT__saxi_wdata;
        IData/*31:0*/ smart_timer_axil__DOT__saxi_rdata;
        IData/*31:0*/ smart_timer_axil__DOT__wdata_q;
        IData/*31:0*/ smart_timer_axil__DOT__period_shadow;
        IData/*31:0*/ smart_timer_axil__DOT__period_active;
        IData/*31:0*/ smart_timer_axil__DOT__duty_shadow;
        IData/*31:0*/ smart_timer_axil__DOT__duty_active;
        IData/*31:0*/ smart_timer_axil__DOT__i;
        IData/*31:0*/ smart_timer_axil__DOT__u_pwm__DOT__period;
        IData/*31:0*/ smart_timer_axil__DOT__u_pwm__DOT__duty;
        IData/*31:0*/ smart_timer_axil__DOT__u_pwm__DOT__cnt;
        IData/*31:0*/ smart_timer_axil__DOT__u_pwm__DOT__duty_clip;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*1:0*/ smart_timer_axil__DOT__OKAY = 0U;
    static constexpr CData/*1:0*/ smart_timer_axil__DOT__SLVERR = 2U;
    static constexpr IData/*31:0*/ smart_timer_axil__DOT__ADDR_WIDTH = 6U;
    static constexpr IData/*31:0*/ smart_timer_axil__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ smart_timer_axil__DOT__PERIOD_RST = 0x000000ffU;
    static constexpr IData/*31:0*/ smart_timer_axil__DOT__DUTY_RST = 0U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
