// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable;
    CData/*6:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track;
    CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side;
    CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors;
    CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf;
    CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef;
    CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector;
    CData/*1:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode;
    CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo;
    SData/*10:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size;
    SData/*15:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos;
    SData/*15:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size;
    SData/*10:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos;
    IData/*31:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt;
    IData/*19:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset;
    IData/*19:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1;
    WData/*127:0*/ __Vtemp1[4];
    WData/*127:0*/ __Vtemp2[4];
    // Body
    vlTOPp->__Vdlyvset__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1 = 0U;
    vlTOPp->__Vdly__top__DOT__tape_complete = vlTOPp->top__DOT__tape_complete;
    vlTOPp->__Vdly__top__DOT__tape_wr = vlTOPp->top__DOT__tape_wr;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__start_addr 
        = vlTOPp->top__DOT__cassette__DOT__start_addr;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__startAddressLOW 
        = vlTOPp->top__DOT__cassette__DOT__startAddressLOW;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__startAddressHIGH 
        = vlTOPp->top__DOT__cassette__DOT__startAddressHIGH;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__end_addr 
        = vlTOPp->top__DOT__cassette__DOT__end_addr;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__endAddressLOW 
        = vlTOPp->top__DOT__cassette__DOT__endAddressLOW;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__endAddressHIGH 
        = vlTOPp->top__DOT__cassette__DOT__endAddressHIGH;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
        = vlTOPp->top__DOT__cassette__DOT__cache_addr;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__state 
        = vlTOPp->top__DOT__cassette__DOT__state;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0 = 0U;
    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1 = 0U;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__phase 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS;
    vlTOPp->__Vdlyvset__top__DOT__ram__DOT__d__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__ram__DOT__d__v0 = 0U;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v4 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v5 = 0U;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2c 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable;
    __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable;
    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch;
    if (((IData)(vlTOPp->ioctl_download) & (IData)(vlTOPp->ioctl_wr))) {
        vlTOPp->__Vdlyvval__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 
            = vlTOPp->ioctl_dout;
        vlTOPp->__Vdlyvset__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 
            = (0xffffU & vlTOPp->ioctl_addr);
    }
    vlTOPp->top__DOT____Vcellout__oricatmos__sd_din 
        = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_a)
            ? (IData)(vlTOPp->top__DOT__sd_buff_dout)
            : vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram
           [vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_a]);
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT) {
        vlTOPp->VGA_HB = (1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lHBLANKn)));
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT) {
        vlTOPp->VGA_VB = (0xe0U <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V));
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_a) {
        vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0 
            = vlTOPp->top__DOT__sd_buff_dout;
        vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0 
            = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_a;
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1 
            = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__data_b;
        vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1 
            = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_b;
    }
    vlTOPp->top__DOT__old_keystb = (1U & ((IData)(vlTOPp->ps2_key) 
                                          >> 0xaU));
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x14U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x78U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        vlTOPp->top__DOT__oricatmos__DOT__swrst 
                                                            = 
                                                            (1U 
                                                             & ((IData)(vlTOPp->ps2_key) 
                                                                >> 9U));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__tape_wr)))) {
        vlTOPp->top__DOT__ram__DOT__do2 = vlTOPp->top__DOT__ram__DOT__d
            [vlTOPp->top__DOT__tape_addr];
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_CLK_en) {
        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt 
            = ((IData)(vlTOPp->top__DOT__fdd_ready)
                ? ((0U != vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt)
                    ? (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt 
                       - (IData)(1U)) : 0x88b8U) : 0U);
        vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_index 
            = VL_GTS_III(1,32,32, 0x64U, vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt);
    }
    if (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active) 
         & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_active)))) {
        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size = 0U;
        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size = 0U;
        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos = 0U;
        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size = 1U;
    }
    if ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr) 
          & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_wr))) 
         & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active))) {
        if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size) {
            if ((0x30U == vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr)) {
                vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size 
                    = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
            } else {
                if (((0x31U == vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr) 
                     & (2U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout)))) {
                    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size 
                        = (0xffU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size) 
                                    << 1U));
                } else {
                    if ((0x34U == vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr)) {
                        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size 
                            = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout) 
                               << 8U);
                        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos = 0U;
                        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos = 1U;
                    } else {
                        if (((0x34U < vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr) 
                             & (0xdaU > vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr))) {
                            vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound1 
                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                            vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound2 = 0U;
                            if ((0xa5U >= (0xffU & 
                                           (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                            - (IData)(0x34U))))) {
                                vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0 
                                    = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound1;
                                vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0 = 1U;
                                vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0 
                                    = (0xffU & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                - (IData)(0x34U)));
                            }
                            if ((0xa5U >= (0xffU & 
                                           (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                            - (IData)(0x34U))))) {
                                vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0 
                                    = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound2;
                                vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0 = 1U;
                                vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0 
                                    = (0xffU & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                - (IData)(0x34U)));
                            }
                        } else {
                            if (((0x100U <= vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr) 
                                 & (0U != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size)))) {
                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos 
                                    = (0xffffU & ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)));
                                if ((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos))) {
                                    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset 
                                        = (0xfffffU 
                                           & ((IData)(0x100U) 
                                              + vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr));
                                } else {
                                    if ((0x10U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos))) {
                                        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track 
                                            = (0x7fU 
                                               & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout));
                                    } else {
                                        if ((0x11U 
                                             == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos))) {
                                            __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side 
                                                = (1U 
                                                   & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout));
                                        } else {
                                            if ((0x15U 
                                                 == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos))) {
                                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors 
                                                    = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                                            } else {
                                                if (
                                                    (0x16U 
                                                     == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound3 
                                                        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors;
                                                    if (
                                                        (0xa5U 
                                                         >= 
                                                         (0xffU 
                                                          & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side)
                                                               ? 
                                                              ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size) 
                                                               >> 1U)
                                                               : 0U) 
                                                             + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track))))) {
                                                        vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1 
                                                            = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound3;
                                                        vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1 = 1U;
                                                        vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1 
                                                            = 
                                                            (0xffU 
                                                             & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side)
                                                                  ? 
                                                                 ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size) 
                                                                  >> 1U)
                                                                  : 0U) 
                                                                + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track)));
                                                    }
                                                } else {
                                                    if (
                                                        ((0x18U 
                                                          <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)) 
                                                         & (0U 
                                                            != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors)))) {
                                                        if (
                                                            (0U 
                                                             == 
                                                             (7U 
                                                              & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                            __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf 
                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                                                            __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos 
                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size;
                                                            __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1 
                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset;
                                                        } else {
                                                            if (
                                                                (1U 
                                                                 == 
                                                                 (7U 
                                                                  & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef 
                                                                    = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                                                            } else {
                                                                if (
                                                                    (2U 
                                                                     == 
                                                                     (7U 
                                                                      & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                                    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector 
                                                                        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                                                                } else {
                                                                    if (
                                                                        (3U 
                                                                         == 
                                                                         (7U 
                                                                          & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                                        __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode 
                                                                            = 
                                                                            (3U 
                                                                             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout));
                                                                    } else {
                                                                        if (
                                                                            (6U 
                                                                             == 
                                                                             (7U 
                                                                              & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                                            __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo 
                                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
                                                                        } else {
                                                                            if (
                                                                                (7U 
                                                                                == 
                                                                                (7U 
                                                                                & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos)))) {
                                                                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors 
                                                                                = 
                                                                                (0xffU 
                                                                                & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors) 
                                                                                - (IData)(1U)));
                                                                                if (
                                                                                ((0U 
                                                                                != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout)) 
                                                                                | (0U 
                                                                                != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo)))) {
                                                                                vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound4 
                                                                                = 
                                                                                (((QData)((IData)(
                                                                                (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector))))))) 
                                                                                << 0x16U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode) 
                                                                                << 0x14U) 
                                                                                | vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1))));
                                                                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size 
                                                                                = 
                                                                                (0x7ffU 
                                                                                & ((IData)(1U) 
                                                                                + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size)));
                                                                                __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset 
                                                                                = 
                                                                                (0xfffffU 
                                                                                & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset 
                                                                                + 
                                                                                (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo))));
                                                                                if (
                                                                                (0x7c7U 
                                                                                >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos))) {
                                                                                vlTOPp->__Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0 
                                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound4;
                                                                                vlTOPp->__Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0 = 1U;
                                                                                vlTOPp->__Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0 
                                                                                = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos;
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos) 
                                     >= (0xffffU & 
                                         ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size) 
                                          - (IData)(1U))))) {
                                    vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos)));
                                    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size 
                                        = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsize) 
                                           << 8U);
                                    __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
        __Vtemp1[0U] = 0x2044534bU;
        __Vtemp1[1U] = 0x20435043U;
        __Vtemp1[2U] = 0x4e444544U;
        __Vtemp1[3U] = 0x45585445U;
        VL_SHIFTR_WWI(128,128,8, __Vtemp2, __Vtemp1, 
                      (0xffU & ((IData)(0x78U) - (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                  << 3U))));
        if (((0x10U > vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr) 
             & ((0xffU & __Vtemp2[0U]) != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout)))) {
            vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size = 0U;
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en) {
        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__phase 
            = ((1U & ((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_t1)) 
                      & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                         >> 2U))) ? 3U : (3U & ((IData)(1U) 
                                                + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase))));
    }
    if ((7U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sweq) 
                << 7U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf1) 
                << 6U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swret) 
                << 5U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrs) 
                << 4U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfs) 
                << 3U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw0) 
                << 2U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swl) 
                << 1U));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw8));
    } else {
        if ((6U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sww) 
                      << 7U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sws) 
                      << 6U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swa) 
                      << 5U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf2) 
                      << 4U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swe) 
                      << 3U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swg) 
                      << 2U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swh) 
                      << 1U));
            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                   | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swy));
        } else {
            if ((5U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swlsb) 
                          << 7U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrsb) 
                          << 6U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel) 
                          << 5U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfcn) 
                          << 4U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swp) 
                          << 3U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swo) 
                          << 2U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swi) 
                          << 1U));
                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                    = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                       | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swu));
            } else {
                if ((4U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swR) 
                              << 7U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swD) 
                              << 6U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swL) 
                              << 5U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swls) 
                              << 4U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swU) 
                              << 3U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdot) 
                              << 2U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swcom) 
                              << 1U));
                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                        = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                           | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsp));
                } else {
                    if ((3U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsq) 
                                  << 7U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swbs) 
                                  << 6U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf3) 
                                  << 5U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf4) 
                                  << 4U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdsh) 
                                  << 3U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsc) 
                                  << 2U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw9) 
                                  << 1U));
                        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                            = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                               | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swk));
                    } else {
                        if ((2U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swc) 
                                      << 7U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw2) 
                                      << 6U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swz) 
                                      << 5U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swctl) 
                                      << 4U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw4) 
                                      << 3U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swb) 
                                      << 2U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw6) 
                                      << 1U));
                            vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                   | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swm));
                        } else {
                            if ((1U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swd) 
                                          << 7U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swq) 
                                          << 6U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swesc) 
                                          << 5U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf5) 
                                          << 4U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf) 
                                          << 3U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swr) 
                                          << 2U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swt) 
                                          << 1U));
                                vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                    = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                       | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swj));
                            } else {
                                if ((0U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0x7fU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw3) 
                                              << 7U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xbfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swx) 
                                              << 6U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xdfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw1) 
                                              << 5U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf6) 
                                              << 4U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swv) 
                                              << 3U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xfbU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw5) 
                                              << 2U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xfdU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swn) 
                                              << 1U));
                                    vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW 
                                        = ((0xfeU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
                                           | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw7));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET) {
        if ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel) 
              & (1U == (3U & (vlTOPp->top__DOT__oricatmos__DOT__cpu_ad 
                              >> 2U)))) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))) {
            vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DSEL 
                = (3U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r) 
                         >> 5U));
        }
    } else {
        vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DSEL = 0U;
    }
    if (vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET) {
        if ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel) 
              & (1U == (3U & (vlTOPp->top__DOT__oricatmos__DOT__cpu_ad 
                              >> 2U)))) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))) {
            vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__nROMEN 
                = (1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r) 
                         >> 7U));
        }
    } else {
        vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__nROMEN = 0U;
    }
    if (vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET) {
        if ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel) 
              & (1U == (3U & (vlTOPp->top__DOT__oricatmos__DOT__cpu_ad 
                              >> 2U)))) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))) {
            vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inROMDIS 
                = (1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r) 
                         >> 1U));
        }
    } else {
        vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inROMDIS = 1U;
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_CLK_en) {
        if (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__watchdog_set) {
            vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer = 0x1000U;
        } else {
            if ((0U != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer))) {
                vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer 
                    = (0xffffU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer) 
                                  - (IData)(1U)));
            }
        }
    }
    if ((1U & ((vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                >> 2U) | (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                          >> 0xaU)))) {
        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS 
            = vlTOPp->top__DOT__ram_q;
    }
    if (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT) 
         & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
            >> 0x11U))) {
        vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv 
            = vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv_hold;
    }
    if (vlTOPp->top__DOT__tape_wr) {
        vlTOPp->__Vdlyvval__top__DOT__ram__DOT__d__v1 
            = vlTOPp->top__DOT__tape_dout;
        vlTOPp->__Vdlyvset__top__DOT__ram__DOT__d__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__ram__DOT__d__v1 
            = vlTOPp->top__DOT__tape_addr;
    }
    if (vlTOPp->top__DOT__ram_cs_temp) {
        if (vlTOPp->top__DOT__ram_we_temp) {
            vlTOPp->__Vdlyvval__top__DOT__ram__DOT__d__v0 
                = vlTOPp->top__DOT__ram_d_temp;
            vlTOPp->__Vdlyvset__top__DOT__ram__DOT__d__v0 = 1U;
            vlTOPp->__Vdlyvdim0__top__DOT__ram__DOT__d__v0 
                = vlTOPp->top__DOT__ram_ad_temp;
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT) {
        vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG 
            = (0x3fU & ((1U & ((vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                >> 0x11U) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib))))
                         ? (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREGHOLD)
                         : (0x3eU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG) 
                                     << 1U))));
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en) {
        if (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_load_counter) 
             | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_reload_counter) 
                & (3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase))))) {
            vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c 
                = ((0xff00U & (IData)(vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c)) 
                   | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_l));
            vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c 
                = ((0xffU & (IData)(vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c)) 
                   | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_h) 
                      << 8U));
        } else {
            if ((3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase))) {
                vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c 
                    = (0xffffU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c) 
                                  - (IData)(1U)));
            }
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en) {
        if (vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_cnt_clk) {
            __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable = 1U;
        }
        if ((1U & (~ (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_reload_counter) 
                       & (3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase))) 
                      & (((1U == (7U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_acr) 
                                        >> 2U))) | 
                          (4U == (7U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_acr) 
                                        >> 2U)))) | 
                         (5U == (7U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_acr) 
                                       >> 2U)))))))) {
            if (vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_load_counter) {
                __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable = 1U;
            }
        }
        if ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_active) 
              & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_done)) 
             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable))) {
            __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable = 0U;
            vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq = 1U;
        } else {
            if ((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_w_reset_int) 
                        | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_r_reset_int)) 
                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__clear_irq) 
                          >> 5U)))) {
                vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq = 0U;
            }
        }
        if (vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_load_counter) {
            vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq = 0U;
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_restart) {
        vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch = 1U;
    } else {
        if (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_clr) {
            vlTOPp->__Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch = 0U;
        }
    }
    if (vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n) {
        if (vlTOPp->top__DOT__oricatmos__DOT__via_cb2_out) {
            if (vlTOPp->top__DOT__oricatmos__DOT__psg_bdir) {
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n = 1U;
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n = 1U;
            } else {
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n 
                    = (1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok)
                               ? 0U : 3U) >> 1U));
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n 
                    = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok)
                        ? 0U : 1U);
            }
        } else {
            if (vlTOPp->top__DOT__oricatmos__DOT__psg_bdir) {
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n 
                    = (1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok)
                               ? 2U : 3U) >> 1U));
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n 
                    = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok)
                        ? 0U : 1U);
            } else {
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n = 1U;
                vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n = 1U;
            }
        }
    } else {
        vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n = 1U;
        vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n = 1U;
    }
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size 
        = __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size;
    vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable 
        = __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_wr 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsize 
        = ((0xa5U >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos))
            ? vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes
           [vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos]
            : 0U);
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_active 
        = vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active;
    vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout 
        = ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_b)
            ? (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__data_b)
            : vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram
           [vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_b]);
    if (vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en) {
        vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_t1 
            = (1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                     >> 2U));
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x41U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x49U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x5aU 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (0x4aU 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sweq 
                                                                = 
                                                                (1U 
                                                                 & ((IData)(vlTOPp->ps2_key) 
                                                                    >> 9U));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x14U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x78U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (9U 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            if (
                                                                (5U 
                                                                 == 
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf1 
                                                                    = 
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->ps2_key) 
                                                                        >> 9U));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x41U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x49U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x5aU 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swret 
                                                            = 
                                                            (1U 
                                                             & ((IData)(vlTOPp->ps2_key) 
                                                                >> 9U));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrs 
                                        = (1U & ((IData)(vlTOPp->ps2_key) 
                                                 >> 9U));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x41U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x49U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x5aU 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (0x4aU 
                                                             == 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfs 
                                                                = 
                                                                (1U 
                                                                 & ((IData)(vlTOPp->ps2_key) 
                                                                    >> 9U));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if (((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                   | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
               | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
              | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
             | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
            if ((0x45U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw0 
                    = (1U & ((IData)(vlTOPp->ps2_key) 
                             >> 9U));
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x33U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x43U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x3bU != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x42U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x4bU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swl 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw8 
                        = (1U & ((IData)(vlTOPp->ps2_key) 
                                 >> 9U));
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sww 
                                    = (1U & ((IData)(vlTOPp->ps2_key) 
                                             >> 9U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x15U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x2dU != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1bU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sws 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swa 
                                = (1U & ((IData)(vlTOPp->ps2_key) 
                                         >> 9U));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x14U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x78U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (9U 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            if (
                                                                (5U 
                                                                 != 
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                                if (
                                                                    (6U 
                                                                     == 
                                                                     (0xffU 
                                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf2 
                                                                        = 
                                                                        (1U 
                                                                         & ((IData)(vlTOPp->ps2_key) 
                                                                            >> 9U));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x32U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x21U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x23U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x24U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swe 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swg 
                            = (1U & ((IData)(vlTOPp->ps2_key) 
                                     >> 9U));
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swh 
                                = (1U & ((IData)(vlTOPp->ps2_key) 
                                         >> 9U));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swy 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x71U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x5bU 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x54U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swlsb 
                                                            = 
                                                            (1U 
                                                             & ((IData)(vlTOPp->ps2_key) 
                                                                >> 9U));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x71U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrsb 
                                                        = 
                                                        (1U 
                                                         & ((IData)(vlTOPp->ps2_key) 
                                                            >> 9U));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        } else {
                                            if ((0x71U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfcn 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swp 
                                    = (1U & ((IData)(vlTOPp->ps2_key) 
                                             >> 9U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swo 
                                = (1U & ((IData)(vlTOPp->ps2_key) 
                                         >> 9U));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x33U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swi 
                                    = (1U & ((IData)(vlTOPp->ps2_key) 
                                             >> 9U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x15U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x2dU != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1bU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x2cU 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x3cU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swu 
                                                        = 
                                                        (1U 
                                                         & ((IData)(vlTOPp->ps2_key) 
                                                            >> 9U));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1aU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x75U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x72U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x6bU 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swR 
                                                            = 
                                                            (1U 
                                                             & ((IData)(vlTOPp->ps2_key) 
                                                                >> 9U));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1aU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x75U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x72U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swD 
                                                        = 
                                                        (1U 
                                                         & ((IData)(vlTOPp->ps2_key) 
                                                            >> 9U));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1aU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x75U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x72U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x6bU 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swL 
                                                            = 
                                                            (1U 
                                                             & ((IData)(vlTOPp->ps2_key) 
                                                                >> 9U));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swls 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1aU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x75U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swU 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x41U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x49U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdot 
                                                        = 
                                                        (1U 
                                                         & ((IData)(vlTOPp->ps2_key) 
                                                            >> 9U));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swcom 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if (((((((((0x59U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                       | (0x12U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x29U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x41U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x49U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x5aU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x4aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x55U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))))) {
                                if ((0x59U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x12U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x29U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsp 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x71U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x5bU 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x54U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (0x5dU 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            if (
                                                                (0x4eU 
                                                                 != 
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsq 
                                                                    = 
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->ps2_key) 
                                                                        >> 9U));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x71U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x5bU 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x54U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (0x5dU 
                                                             == 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swbs 
                                                                = 
                                                                (1U 
                                                                 & ((IData)(vlTOPp->ps2_key) 
                                                                    >> 9U));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x14U 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x78U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (9U 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            if (
                                                                (5U 
                                                                 != 
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                                if (
                                                                    (6U 
                                                                     != 
                                                                     (0xffU 
                                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf3 
                                                                        = 
                                                                        (1U 
                                                                         & ((IData)(vlTOPp->ps2_key) 
                                                                            >> 9U));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if ((1U & (~ ((
                                                   ((((((0x4cU 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key))) 
                                                        | (0x76U 
                                                           == 
                                                           (0xffU 
                                                            & (IData)(vlTOPp->ps2_key)))) 
                                                       | (0x14U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(vlTOPp->ps2_key)))) 
                                                      | (0x78U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) 
                                                     | (9U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(vlTOPp->ps2_key)))) 
                                                    | (5U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (6U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (4U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))))))) {
                                        if ((0xcU == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf4 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if (((((((((0x11U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key))) 
                                           | (0x66U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x71U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x5bU == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x54U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x5dU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x4eU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x52U == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))) {
                                    if ((0x11U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x66U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x71U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x5bU 
                                                     != 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    if (
                                                        (0x54U 
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (0x5dU 
                                                             != 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            if (
                                                                (0x4eU 
                                                                 == 
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdsh 
                                                                    = 
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->ps2_key) 
                                                                        >> 9U));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsc 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw9 
                            = (1U & ((IData)(vlTOPp->ps2_key) 
                                     >> 9U));
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x33U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x43U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x3bU != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x42U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swk 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x32U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x21U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swc 
                                        = (1U & ((IData)(vlTOPp->ps2_key) 
                                                 >> 9U));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if (((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                   | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
               | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
              | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
             | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
            if ((0x45U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                if ((0x16U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw2 
                            = (1U & ((IData)(vlTOPp->ps2_key) 
                                     >> 9U));
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if (((((((((0x1dU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key))) 
                                   | (0x22U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x35U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x1aU == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x75U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x72U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x6bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x74U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                            if ((0x1dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x22U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x35U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swz 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                if (
                                                    (0x14U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) {
                                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swctl 
                                                        = 
                                                        (1U 
                                                         & ((IData)(vlTOPp->ps2_key) 
                                                            >> 9U));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if (((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                   | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
               | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
              | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
             | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
            if ((0x45U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                if ((0x16U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x1eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x26U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw4 
                                    = (1U & ((IData)(vlTOPp->ps2_key) 
                                             >> 9U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swb 
                                    = (1U & ((IData)(vlTOPp->ps2_key) 
                                             >> 9U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if (((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                   | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
               | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
              | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
             | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
            if ((0x45U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                if ((0x16U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x1eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x26U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x25U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x2eU != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x36U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw6 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if (((((((((0x34U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                           | (0x33U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x43U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x3bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x42U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x4bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                    if ((0x34U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x33U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x43U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x3bU != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x42U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x4bU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x3aU 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swm 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x32U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x21U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x23U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swd 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x15U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swq 
                                        = (1U & ((IData)(vlTOPp->ps2_key) 
                                                 >> 9U));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if (((((((((0x4cU 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                               | (0x76U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x14U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x78U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (9U == 
                                               (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                           | (5U == 
                                              (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                          | (6U == 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                         | (4U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))) {
                                        if ((0x4cU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x76U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swesc 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if ((1U & (~ ((((((((0x44U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))) 
                                        | (0x4dU == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x15U == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                     | (0x1bU == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                    | (0x2cU == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x3cU == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x2aU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))))))) {
                        if ((1U & (~ ((((((((0x1dU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))) 
                                            | (0x22U 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x35U 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x1aU 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                         | (0x75U == 
                                            (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                                        | (0x72U == 
                                           (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                       | (0x6bU == 
                                          (0xffU & (IData)(vlTOPp->ps2_key)))) 
                                      | (0x74U == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key))))))) {
                            if ((1U & (~ ((((((((0x59U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))) 
                                                | (0x12U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x29U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x41U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                             | (0x49U 
                                                == 
                                                (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                            | (0x5aU 
                                               == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                           | (0x4aU 
                                              == (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) 
                                          | (0x55U 
                                             == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x11U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))) 
                                                    | (0x66U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (0x71U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (0x5bU 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key)))) 
                                                 | (0x54U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) 
                                                | (0x5dU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->ps2_key)))) 
                                               | (0x4eU 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) 
                                              | (0x52U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key))))))) {
                                    if ((1U & (~ ((
                                                   ((((((0x4cU 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key))) 
                                                        | (0x76U 
                                                           == 
                                                           (0xffU 
                                                            & (IData)(vlTOPp->ps2_key)))) 
                                                       | (0x14U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(vlTOPp->ps2_key)))) 
                                                      | (0x78U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) 
                                                     | (9U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(vlTOPp->ps2_key)))) 
                                                    | (5U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->ps2_key)))) 
                                                   | (6U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->ps2_key)))) 
                                                  | (4U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->ps2_key))))))) {
                                        if ((0xcU != 
                                             (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) {
                                            if ((3U 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf5 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if (((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                       | (0x46U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                     | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                    | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                   | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                  | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                 | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                if ((0x3eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                    if ((0x46U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x1cU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x32U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x21U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x23U != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x24U 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf 
                                                = (1U 
                                                   & ((IData)(vlTOPp->ps2_key) 
                                                      >> 9U));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x15U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x2dU == (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swr 
                                            = (1U & 
                                               ((IData)(vlTOPp->ps2_key) 
                                                >> 9U));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__key_strobe) {
        if ((1U & (~ ((((((((0x45U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                            | (0x16U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x1eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x25U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                        | (0x2eU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                       | (0x36U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                      | (0x3dU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
            if ((1U & (~ ((((((((0x3eU == (0xffU & (IData)(vlTOPp->ps2_key))) 
                                | (0x46U == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x1cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x32U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x21U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x23U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x24U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x2bU == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                if ((1U & (~ ((((((((0x34U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key))) 
                                    | (0x33U == (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) 
                                   | (0x43U == (0xffU 
                                                & (IData)(vlTOPp->ps2_key)))) 
                                  | (0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) 
                                 | (0x42U == (0xffU 
                                              & (IData)(vlTOPp->ps2_key)))) 
                                | (0x4bU == (0xffU 
                                             & (IData)(vlTOPp->ps2_key)))) 
                               | (0x3aU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x31U == (0xffU & (IData)(vlTOPp->ps2_key))))))) {
                    if (((((((((0x44U == (0xffU & (IData)(vlTOPp->ps2_key))) 
                               | (0x4dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                              | (0x15U == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                             | (0x2dU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                            | (0x1bU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                           | (0x2cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                          | (0x3cU == (0xffU & (IData)(vlTOPp->ps2_key)))) 
                         | (0x2aU == (0xffU & (IData)(vlTOPp->ps2_key))))) {
                        if ((0x44U != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            if ((0x4dU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                                if ((0x15U != (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    if ((0x2dU != (0xffU 
                                                   & (IData)(vlTOPp->ps2_key)))) {
                                        if ((0x1bU 
                                             != (0xffU 
                                                 & (IData)(vlTOPp->ps2_key)))) {
                                            if ((0x2cU 
                                                 == 
                                                 (0xffU 
                                                  & (IData)(vlTOPp->ps2_key)))) {
                                                vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swt 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->ps2_key) 
                                                        >> 9U));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
