// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_axil_regbank);

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
    __Vscope_axil_regbank.configure(this, name(), "axil_regbank", "axil_regbank", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_axil_regbank);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"ACLK", &(TOP.ACLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"ARESETn", &(TOP.ARESETn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_araddr", &(TOP.saxi_araddr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_arready", &(TOP.saxi_arready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_arvalid", &(TOP.saxi_arvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"saxi_awaddr", &(TOP.saxi_awaddr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
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
        __Vscope_axil_regbank.varInsert(__Vfinal,"ACLK", &(TOP.axil_regbank__DOT__ACLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axil_regbank__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"ARESETn", &(TOP.axil_regbank__DOT__ARESETn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.axil_regbank__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"OKAY", const_cast<void*>(static_cast<const void*>(&(TOP.axil_regbank__DOT__OKAY))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"SLVERR", const_cast<void*>(static_cast<const void*>(&(TOP.axil_regbank__DOT__SLVERR))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"ar_hs_done", &(TOP.axil_regbank__DOT__ar_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"araddr_q", &(TOP.axil_regbank__DOT__araddr_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"aw_hs_done", &(TOP.axil_regbank__DOT__aw_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"awaddr_q", &(TOP.axil_regbank__DOT__awaddr_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"do_write", &(TOP.axil_regbank__DOT__do_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"i", &(TOP.axil_regbank__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"reg_ctrl", &(TOP.axil_regbank__DOT__reg_ctrl), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"reg_data", &(TOP.axil_regbank__DOT__reg_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_araddr", &(TOP.axil_regbank__DOT__saxi_araddr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_arready", &(TOP.axil_regbank__DOT__saxi_arready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_arvalid", &(TOP.axil_regbank__DOT__saxi_arvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_awaddr", &(TOP.axil_regbank__DOT__saxi_awaddr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_awready", &(TOP.axil_regbank__DOT__saxi_awready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_awvalid", &(TOP.axil_regbank__DOT__saxi_awvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_bready", &(TOP.axil_regbank__DOT__saxi_bready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_bresp", &(TOP.axil_regbank__DOT__saxi_bresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_bvalid", &(TOP.axil_regbank__DOT__saxi_bvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_rdata", &(TOP.axil_regbank__DOT__saxi_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_rready", &(TOP.axil_regbank__DOT__saxi_rready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_rresp", &(TOP.axil_regbank__DOT__saxi_rresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_rvalid", &(TOP.axil_regbank__DOT__saxi_rvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_wdata", &(TOP.axil_regbank__DOT__saxi_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_wready", &(TOP.axil_regbank__DOT__saxi_wready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_wstrb", &(TOP.axil_regbank__DOT__saxi_wstrb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"saxi_wvalid", &(TOP.axil_regbank__DOT__saxi_wvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"w_hs_done", &(TOP.axil_regbank__DOT__w_hs_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"wdata_q", &(TOP.axil_regbank__DOT__wdata_q), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"word_sel_r", &(TOP.axil_regbank__DOT__word_sel_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"word_sel_w", &(TOP.axil_regbank__DOT__word_sel_w), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_axil_regbank.varInsert(__Vfinal,"wstrb_q", &(TOP.axil_regbank__DOT__wstrb_q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
    }
}
