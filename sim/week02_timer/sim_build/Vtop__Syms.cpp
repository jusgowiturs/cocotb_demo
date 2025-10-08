// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_smart_timer_axil);
    __Vhier.remove(&__Vscope_smart_timer_axil, &__Vscope_smart_timer_axil__u_pwm);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_smart_timer_axil.configure(this, name(), "smart_timer_axil", "smart_timer_axil", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_smart_timer_axil__u_pwm.configure(this, name(), "smart_timer_axil.u_pwm", "u_pwm", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_smart_timer_axil);
    __Vhier.add(&__Vscope_smart_timer_axil, &__Vscope_smart_timer_axil__u_pwm);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"ACLK", &(TOP.ACLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"ARESETn", &(TOP.ARESETn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"pwm_out", &(TOP.pwm_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_araddr", &(TOP.saxi_araddr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,5,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_arready", &(TOP.saxi_arready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_arvalid", &(TOP.saxi_arvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_awaddr", &(TOP.saxi_awaddr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,5,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_awready", &(TOP.saxi_awready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_awvalid", &(TOP.saxi_awvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_bready", &(TOP.saxi_bready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_bresp", &(TOP.saxi_bresp), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_bvalid", &(TOP.saxi_bvalid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_rdata", &(TOP.saxi_rdata), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_rready", &(TOP.saxi_rready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_rresp", &(TOP.saxi_rresp), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_rvalid", &(TOP.saxi_rvalid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_wdata", &(TOP.saxi_wdata), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_wready", &(TOP.saxi_wready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_wstrb", &(TOP.saxi_wstrb), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_wvalid", &(TOP.saxi_wvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ACLK", &(TOP.smart_timer_axil__DOT__ACLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ARESETn", &(TOP.smart_timer_axil__DOT__ARESETn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"DUTY_RST", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__DUTY_RST))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"OKAY", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__OKAY))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"PERIOD_RST", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__PERIOD_RST))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"SLVERR", const_cast<void*>(static_cast<const void*>(&(TOP.smart_timer_axil__DOT__SLVERR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ar_hs_done", &(TOP.smart_timer_axil__DOT__ar_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"araddr_q", &(TOP.smart_timer_axil__DOT__araddr_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"aw_hs_done", &(TOP.smart_timer_axil__DOT__aw_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"awaddr_q", &(TOP.smart_timer_axil__DOT__awaddr_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ctrl_en", &(TOP.smart_timer_axil__DOT__ctrl_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"ctrl_rst_pulse", &(TOP.smart_timer_axil__DOT__ctrl_rst_pulse), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"do_write", &(TOP.smart_timer_axil__DOT__do_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"duty_active", &(TOP.smart_timer_axil__DOT__duty_active), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"duty_shadow", &(TOP.smart_timer_axil__DOT__duty_shadow), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"i", &(TOP.smart_timer_axil__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"period_active", &(TOP.smart_timer_axil__DOT__period_active), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"period_shadow", &(TOP.smart_timer_axil__DOT__period_shadow), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"pwm_out", &(TOP.smart_timer_axil__DOT__pwm_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"rstn_core", &(TOP.smart_timer_axil__DOT__rstn_core), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_araddr", &(TOP.smart_timer_axil__DOT__saxi_araddr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_arready", &(TOP.smart_timer_axil__DOT__saxi_arready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_arvalid", &(TOP.smart_timer_axil__DOT__saxi_arvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_awaddr", &(TOP.smart_timer_axil__DOT__saxi_awaddr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_awready", &(TOP.smart_timer_axil__DOT__saxi_awready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_awvalid", &(TOP.smart_timer_axil__DOT__saxi_awvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_bready", &(TOP.smart_timer_axil__DOT__saxi_bready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_bresp", &(TOP.smart_timer_axil__DOT__saxi_bresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_bvalid", &(TOP.smart_timer_axil__DOT__saxi_bvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_rdata", &(TOP.smart_timer_axil__DOT__saxi_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_rready", &(TOP.smart_timer_axil__DOT__saxi_rready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_rresp", &(TOP.smart_timer_axil__DOT__saxi_rresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_rvalid", &(TOP.smart_timer_axil__DOT__saxi_rvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_wdata", &(TOP.smart_timer_axil__DOT__saxi_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_wready", &(TOP.smart_timer_axil__DOT__saxi_wready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_wstrb", &(TOP.smart_timer_axil__DOT__saxi_wstrb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"saxi_wvalid", &(TOP.smart_timer_axil__DOT__saxi_wvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"status_wrap", &(TOP.smart_timer_axil__DOT__status_wrap), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"upd_pending", &(TOP.smart_timer_axil__DOT__upd_pending), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"w_hs_done", &(TOP.smart_timer_axil__DOT__w_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"wdata_q", &(TOP.smart_timer_axil__DOT__wdata_q), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"word_sel_r", &(TOP.smart_timer_axil__DOT__word_sel_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"word_sel_w", &(TOP.smart_timer_axil__DOT__word_sel_w), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"wrap_pulse", &(TOP.smart_timer_axil__DOT__wrap_pulse), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil.varInsert(__Vfinal,"wstrb_q", &(TOP.smart_timer_axil__DOT__wstrb_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"clk", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"cnt", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__cnt), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"duty", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__duty), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"duty_clip", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__duty_clip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"en", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"period", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__period), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"pwm_out", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__pwm_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"rstn", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__rstn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_smart_timer_axil__u_pwm.varInsert(__Vfinal,"wrap", &(TOP.smart_timer_axil__DOT__u_pwm__DOT__wrap), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
