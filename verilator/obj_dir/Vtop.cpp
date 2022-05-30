// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

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
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
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
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_din = vlTOPp->ioctl_din;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__tape__DOT__rom_init_address = 
        (0xffffU & (vlTOPp->ioctl_addr >> 0U));
    vlTOPp->top__DOT__cassette__DOT__reset_n = (1U 
                                                & (~ (IData)(vlTOPp->reset)));
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__cassette__DOT__ioctl_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__cassette__DOT__ioctl_addr = vlTOPp->top__DOT__ioctl_addr;
    vlTOPp->top__DOT__tape__DOT__rom_init = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__cassette__DOT__ioctl_download 
        = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__tape__DOT__rom_init_data = vlTOPp->top__DOT__ioctl_dout;
    vlTOPp->top__DOT__cassette__DOT__ioctl_dout = vlTOPp->top__DOT__ioctl_dout;
    vlTOPp->top__DOT__tape__DOT__clk = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__tape__DOT__rom_init_clk = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__cassette__DOT__clk = vlTOPp->top__DOT__clk_48;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__tape__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__tape__DOT__memory__v0;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__fileType;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__autorun;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__endAddressHIGH;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__endAddressLOW;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__startAddressHIGH;
    CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__startAddressLOW;
    CData/*0:0*/ __Vdly__top__DOT__tape_wr;
    CData/*0:0*/ __Vdly__top__DOT__tape_complete;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__v1;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__v2;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__tape__DOT__memory__v0;
    SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__state;
    SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__end_addr;
    SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__start_addr;
    // Body
    __Vdlyvset__top__DOT__tape__DOT__memory__v0 = 0U;
    __Vdly__top__DOT__cassette__DOT__start_addr = vlTOPp->top__DOT__cassette__DOT__start_addr;
    __Vdly__top__DOT__cassette__DOT__startAddressLOW 
        = vlTOPp->top__DOT__cassette__DOT__startAddressLOW;
    __Vdly__top__DOT__cassette__DOT__startAddressHIGH 
        = vlTOPp->top__DOT__cassette__DOT__startAddressHIGH;
    __Vdly__top__DOT__cassette__DOT__end_addr = vlTOPp->top__DOT__cassette__DOT__end_addr;
    __Vdly__top__DOT__cassette__DOT__endAddressLOW 
        = vlTOPp->top__DOT__cassette__DOT__endAddressLOW;
    __Vdly__top__DOT__cassette__DOT__endAddressHIGH 
        = vlTOPp->top__DOT__cassette__DOT__endAddressHIGH;
    __Vdly__top__DOT__cassette__DOT__autorun = vlTOPp->top__DOT__cassette__DOT__autorun;
    __Vdly__top__DOT__cassette__DOT__fileType = vlTOPp->top__DOT__cassette__DOT__fileType;
    __Vdly__top__DOT__cassette__DOT__state = vlTOPp->top__DOT__cassette__DOT__state;
    __Vdly__top__DOT__tape_complete = vlTOPp->top__DOT__tape_complete;
    __Vdly__top__DOT__tape_wr = vlTOPp->top__DOT__tape_wr;
    __Vdlyvset__top__DOT__ram__v0 = 0U;
    __Vdlyvset__top__DOT__ram__v1 = 0U;
    __Vdlyvset__top__DOT__ram__v2 = 0U;
    VL_WRITEF("(TOP) tape_autorun %x\n(TOP) tape_addr %x tape_wr %x tape_dout %x tape_complete %x\n",
              1,vlTOPp->top__DOT__tape_autorun,16,(IData)(vlTOPp->top__DOT__tape_addr),
              1,vlTOPp->top__DOT__tape_wr,8,(IData)(vlTOPp->top__DOT__tape_dout),
              1,vlTOPp->top__DOT__tape_complete);
    vlTOPp->top__DOT__ram_q = vlTOPp->top__DOT__ram
        [vlTOPp->top__DOT__ram_ad];
    if (vlTOPp->ioctl_download) {
        __Vdlyvval__top__DOT__tape__DOT__memory__v0 
            = vlTOPp->ioctl_dout;
        __Vdlyvset__top__DOT__tape__DOT__memory__v0 = 1U;
        __Vdlyvdim0__top__DOT__tape__DOT__memory__v0 
            = (0xffffU & vlTOPp->ioctl_addr);
    }
    if (vlTOPp->reset) {
        __Vdlyvset__top__DOT__ram__v0 = 1U;
        __Vdlyvdim0__top__DOT__ram__v0 = (0xffffU & vlTOPp->top__DOT__clr_addr);
    } else if (((IData)(vlTOPp->top__DOT__ram_we) & (IData)(vlTOPp->top__DOT__ram_cs))) {
        __Vdlyvval__top__DOT__ram__v1 = vlTOPp->top__DOT__ram_d;
        __Vdlyvset__top__DOT__ram__v1 = 1U;
        __Vdlyvdim0__top__DOT__ram__v1 = vlTOPp->top__DOT__ram_ad;
    }
    if (vlTOPp->top__DOT__tape_wr) {
        __Vdlyvval__top__DOT__ram__v2 = vlTOPp->top__DOT__tape_dout;
        __Vdlyvset__top__DOT__ram__v2 = 1U;
        __Vdlyvdim0__top__DOT__ram__v2 = vlTOPp->top__DOT__tape_addr;
    }
    if (__Vdlyvset__top__DOT__tape__DOT__memory__v0) {
        vlTOPp->top__DOT__tape__DOT__memory[__Vdlyvdim0__top__DOT__tape__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__tape__DOT__memory__v0;
    }
    if (__Vdlyvset__top__DOT__ram__v0) {
        vlTOPp->top__DOT__ram[__Vdlyvdim0__top__DOT__ram__v0] = 0xffU;
    }
    if (__Vdlyvset__top__DOT__ram__v1) {
        vlTOPp->top__DOT__ram[__Vdlyvdim0__top__DOT__ram__v1] 
            = __Vdlyvval__top__DOT__ram__v1;
    }
    if (__Vdlyvset__top__DOT__ram__v2) {
        vlTOPp->top__DOT__ram[__Vdlyvdim0__top__DOT__ram__v2] 
            = __Vdlyvval__top__DOT__ram__v2;
    }
    if (((IData)(vlTOPp->ioctl_download) & (IData)(vlTOPp->ioctl_wr))) {
        if (((((((((1U == (IData)(vlTOPp->top__DOT__cassette__DOT__state)) 
                   | (2U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                  | (3U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                 | (4U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                | (5U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
               | (6U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
              | (7U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
             | (8U == (IData)(vlTOPp->top__DOT__cassette__DOT__state)))) {
            if ((1U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((6U == vlTOPp->ioctl_addr)) {
                    __Vdly__top__DOT__cassette__DOT__fileType 
                        = vlTOPp->ioctl_dout;
                    __Vdly__top__DOT__cassette__DOT__state = 2U;
                }
            } else if ((2U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((0U == (IData)(vlTOPp->top__DOT__cassette__DOT__fileType))) {
                    __Vdly__top__DOT__cassette__DOT__autorun 
                        = vlTOPp->ioctl_dout;
                    __Vdly__top__DOT__cassette__DOT__state = 3U;
                } else if ((0x80U == (IData)(vlTOPp->top__DOT__cassette__DOT__fileType))) {
                    __Vdly__top__DOT__cassette__DOT__autorun 
                        = vlTOPp->ioctl_dout;
                    __Vdly__top__DOT__cassette__DOT__state = 3U;
                }
            } else if ((3U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((0U == (IData)(vlTOPp->top__DOT__cassette__DOT__autorun))) {
                    __Vdly__top__DOT__cassette__DOT__endAddressHIGH 
                        = vlTOPp->ioctl_dout;
                    __Vdly__top__DOT__cassette__DOT__state = 4U;
                } else if ((0xc7U == (IData)(vlTOPp->top__DOT__cassette__DOT__autorun))) {
                    vlTOPp->top__DOT__cassette__DOT__autostart = 1U;
                    __Vdly__top__DOT__cassette__DOT__endAddressHIGH 
                        = vlTOPp->ioctl_dout;
                    __Vdly__top__DOT__cassette__DOT__state = 4U;
                }
            } else if ((4U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                __Vdly__top__DOT__cassette__DOT__endAddressLOW 
                    = vlTOPp->ioctl_dout;
                __Vdly__top__DOT__cassette__DOT__state = 5U;
            } else if ((5U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                __Vdly__top__DOT__cassette__DOT__end_addr 
                    = (((IData)(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH) 
                        << 8U) | (IData)(vlTOPp->top__DOT__cassette__DOT__endAddressLOW));
                __Vdly__top__DOT__cassette__DOT__startAddressHIGH 
                    = vlTOPp->ioctl_dout;
                __Vdly__top__DOT__cassette__DOT__state = 6U;
            } else if ((6U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                __Vdly__top__DOT__cassette__DOT__startAddressLOW 
                    = vlTOPp->ioctl_dout;
                __Vdly__top__DOT__cassette__DOT__state = 7U;
            } else if ((7U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                __Vdly__top__DOT__cassette__DOT__start_addr 
                    = (((IData)(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH) 
                        << 8U) | (IData)(vlTOPp->top__DOT__cassette__DOT__startAddressLOW));
                vlTOPp->top__DOT__cassette__DOT__unused 
                    = (1U & (IData)(vlTOPp->ioctl_dout));
                __Vdly__top__DOT__cassette__DOT__state = 8U;
            } else {
                vlTOPp->top__DOT__cassette__DOT__programlength 
                    = (0xffffU & ((IData)(vlTOPp->top__DOT__cassette__DOT__end_addr) 
                                  - (IData)(vlTOPp->top__DOT__cassette__DOT__start_addr)));
                if ((0U == (IData)(vlTOPp->ioctl_dout))) {
                    vlTOPp->top__DOT__cassette__DOT__loadpoint 
                        = vlTOPp->top__DOT__cassette__DOT__start_addr;
                    __Vdly__top__DOT__cassette__DOT__state = 9U;
                }
            }
        } else if ((9U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
            __Vdly__top__DOT__tape_wr = 1U;
            vlTOPp->top__DOT__tape_addr = vlTOPp->top__DOT__cassette__DOT__start_addr;
            vlTOPp->top__DOT__tape_dout = vlTOPp->ioctl_dout;
            __Vdly__top__DOT__cassette__DOT__start_addr 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__start_addr)));
            if (VL_UNLIKELY(((IData)(vlTOPp->top__DOT__cassette__DOT__start_addr) 
                             == (IData)(vlTOPp->top__DOT__cassette__DOT__end_addr)))) {
                VL_WRITEF("(state SM_PROGRAMCODE %x) start_addr %x end_addr %x\n",
                          16,vlTOPp->top__DOT__cassette__DOT__state,
                          16,(IData)(vlTOPp->top__DOT__cassette__DOT__start_addr),
                          16,vlTOPp->top__DOT__cassette__DOT__end_addr);
                __Vdly__top__DOT__tape_complete = 1U;
                __Vdly__top__DOT__cassette__DOT__state = 1U;
            }
        }
    } else if (vlTOPp->top__DOT__tape_complete) {
        if (VL_UNLIKELY(vlTOPp->top__DOT__tape_wr)) {
            VL_WRITEF("(state else if %x) tape_complete %x tape_wr %x\n",
                      16,vlTOPp->top__DOT__cassette__DOT__state,
                      1,(IData)(vlTOPp->top__DOT__tape_complete),
                      1,vlTOPp->top__DOT__tape_wr);
            vlTOPp->top__DOT__tape_autorun = 1U;
            __Vdly__top__DOT__tape_wr = 0U;
        } else {
            vlTOPp->top__DOT__tape_autorun = 0U;
        }
    }
    vlTOPp->top__DOT__cassette__DOT__fileType = __Vdly__top__DOT__cassette__DOT__fileType;
    vlTOPp->top__DOT__cassette__DOT__autorun = __Vdly__top__DOT__cassette__DOT__autorun;
    vlTOPp->top__DOT__cassette__DOT__endAddressHIGH 
        = __Vdly__top__DOT__cassette__DOT__endAddressHIGH;
    vlTOPp->top__DOT__cassette__DOT__endAddressLOW 
        = __Vdly__top__DOT__cassette__DOT__endAddressLOW;
    vlTOPp->top__DOT__cassette__DOT__end_addr = __Vdly__top__DOT__cassette__DOT__end_addr;
    vlTOPp->top__DOT__cassette__DOT__startAddressHIGH 
        = __Vdly__top__DOT__cassette__DOT__startAddressHIGH;
    vlTOPp->top__DOT__cassette__DOT__startAddressLOW 
        = __Vdly__top__DOT__cassette__DOT__startAddressLOW;
    vlTOPp->top__DOT__cassette__DOT__start_addr = __Vdly__top__DOT__cassette__DOT__start_addr;
    vlTOPp->top__DOT__cassette__DOT__state = __Vdly__top__DOT__cassette__DOT__state;
    vlTOPp->top__DOT__tape_complete = __Vdly__top__DOT__tape_complete;
    vlTOPp->top__DOT__tape_wr = __Vdly__top__DOT__tape_wr;
    vlTOPp->top__DOT__cassette__DOT__tape_addr = vlTOPp->top__DOT__tape_addr;
    vlTOPp->top__DOT__cassette__DOT__tape_dout = vlTOPp->top__DOT__tape_dout;
    vlTOPp->top__DOT__cassette__DOT__tape_complete 
        = vlTOPp->top__DOT__tape_complete;
    vlTOPp->top__DOT__cassette__DOT__tape_wr = vlTOPp->top__DOT__tape_wr;
    vlTOPp->top__DOT__cassette__DOT__tape_autorun = vlTOPp->top__DOT__tape_autorun;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->clk_48) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_48)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_48 = vlTOPp->clk_48;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_48 & 0xfeU))) {
        Verilated::overWidthError("clk_48");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((inputs & 0xf000U))) {
        Verilated::overWidthError("inputs");}
    if (VL_UNLIKELY((ioctl_download & 0xfeU))) {
        Verilated::overWidthError("ioctl_download");}
    if (VL_UNLIKELY((ioctl_upload & 0xfeU))) {
        Verilated::overWidthError("ioctl_upload");}
    if (VL_UNLIKELY((ioctl_wr & 0xfeU))) {
        Verilated::overWidthError("ioctl_wr");}
    if (VL_UNLIKELY((ioctl_addr & 0xfe000000U))) {
        Verilated::overWidthError("ioctl_addr");}
}
#endif  // VL_DEBUG
