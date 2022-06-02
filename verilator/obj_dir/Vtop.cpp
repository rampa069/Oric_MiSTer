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

VL_INLINE_OPT void Vtop::_combo__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__14\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_din = vlTOPp->ioctl_din;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__ps2_key = vlTOPp->ps2_key;
    vlTOPp->top__DOT__cassette__DOT__reset_n = (1U 
                                                & (~ (IData)(vlTOPp->reset)));
    vlTOPp->top__DOT__cassette__DOT__tapecache__DOT__bram_init_address 
        = (0xffffU & (vlTOPp->ioctl_addr >> 0U));
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__oricatmos__DOT__key_pressed = 
        (1U & ((IData)(vlTOPp->ps2_key) >> 9U));
    vlTOPp->top__DOT__oricatmos__DOT__key_extended 
        = (1U & ((IData)(vlTOPp->ps2_key) >> 8U));
    vlTOPp->top__DOT__oricatmos__DOT__key_code = (0xffU 
                                                  & ((IData)(vlTOPp->ps2_key) 
                                                     >> 0U));
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_24 
        = vlTOPp->clk_48;
    vlTOPp->top__DOT__oricatmos__DOT__RESET = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__cassette__DOT__ioctl_addr = vlTOPp->top__DOT__ioctl_addr;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__key_pressed 
        = vlTOPp->top__DOT__oricatmos__DOT__key_pressed;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__key_extended 
        = vlTOPp->top__DOT__oricatmos__DOT__key_extended;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__key_code 
        = vlTOPp->top__DOT__oricatmos__DOT__key_code;
    vlTOPp->top__DOT__cassette__DOT__ioctl_download 
        = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__cassette__DOT__ioctl_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__cassette__DOT__ioctl_dout = vlTOPp->top__DOT__ioctl_dout;
    vlTOPp->top__DOT__ram__DOT__clock = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__cassette__DOT__clk = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__oricatmos__DOT__CLK_IN = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__cassette__DOT__tapecache__DOT__bram_download 
        = vlTOPp->top__DOT__cassette__DOT__ioctl_download;
    vlTOPp->top__DOT__cassette__DOT__tapecache__DOT__bram_wr 
        = vlTOPp->top__DOT__cassette__DOT__ioctl_wr;
    vlTOPp->top__DOT__cassette__DOT__tapecache__DOT__bram_din 
        = vlTOPp->top__DOT__cassette__DOT__ioctl_dout;
    vlTOPp->top__DOT__cassette__DOT__tapecache__DOT__clk 
        = vlTOPp->top__DOT__cassette__DOT__clk;
    vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Clk 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
    vlTOPp->top__DOT__oricatmos__DOT__inst_rom0__DOT__clk 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
    vlTOPp->top__DOT__oricatmos__DOT__inst_rom1__DOT__clk 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
    vlTOPp->top__DOT__oricatmos__DOT__inst_rom2__DOT__clk 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
    vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__clk_sys 
        = vlTOPp->top__DOT__oricatmos__DOT__CLK_IN;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__17(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__17\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__d__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__d__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__d__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__d__v1;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__DOT__d__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__DOT__d__v1;
    // Body
    vlTOPp->__Vdlyvset__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 = 0U;
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
    vlTOPp->__Vdly__top__DOT__cassette__DOT__state 
        = vlTOPp->top__DOT__cassette__DOT__state;
    vlTOPp->__Vdly__top__DOT__tape_complete = vlTOPp->top__DOT__tape_complete;
    vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
        = vlTOPp->top__DOT__cassette__DOT__cache_addr;
    vlTOPp->__Vdly__top__DOT__tape_wr = vlTOPp->top__DOT__tape_wr;
    __Vdlyvset__top__DOT__ram__DOT__d__v0 = 0U;
    __Vdlyvset__top__DOT__ram__DOT__d__v1 = 0U;
    if (vlTOPp->top__DOT__img_mounted) {
        vlTOPp->top__DOT__fdd_ready = vlTOPp->top__DOT__img_size;
    }
    if (((IData)(vlTOPp->ioctl_download) & (IData)(vlTOPp->ioctl_wr))) {
        vlTOPp->__Vdlyvval__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 
            = vlTOPp->ioctl_dout;
        vlTOPp->__Vdlyvset__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__cassette__DOT__tapecache__DOT__memory__v0 
            = (0xffffU & vlTOPp->ioctl_addr);
    }
    vlTOPp->VGA_B = (0xfU & (- (IData)((IData)(vlTOPp->top__DOT__b))));
    vlTOPp->VGA_G = (0xfU & (- (IData)((IData)(vlTOPp->top__DOT__g))));
    vlTOPp->VGA_R = (0xfU & (- (IData)((IData)(vlTOPp->top__DOT__r))));
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
                                                         != 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->ps2_key)))) {
                                                        if (
                                                            (9U 
                                                             == 
                                                             (0xffU 
                                                              & (IData)(vlTOPp->ps2_key)))) {
                                                            vlTOPp->top__DOT__oricatmos__DOT__swnmi 
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
    if (vlTOPp->top__DOT__ram_cs_temp) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__ram_we_temp)))) {
            vlTOPp->top__DOT__ram_q = vlTOPp->top__DOT__ram__DOT__d
                [vlTOPp->top__DOT__ram_ad_temp];
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__tape_wr)))) {
        vlTOPp->top__DOT__ram__DOT__do2 = vlTOPp->top__DOT__ram__DOT__d
            [vlTOPp->top__DOT__tape_addr];
    }
    if (vlTOPp->ce_pix) {
        if ((1U & ((~ (IData)(vlTOPp->VGA_HS)) & (~ (IData)(vlTOPp->top__DOT__hs))))) {
            vlTOPp->VGA_VS = (1U & (~ (IData)(vlTOPp->top__DOT__vs)));
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
    if (vlTOPp->top__DOT__ram_cs_temp) {
        if (vlTOPp->top__DOT__ram_we_temp) {
            __Vdlyvval__top__DOT__ram__DOT__d__v0 = vlTOPp->top__DOT__ram_d_temp;
            __Vdlyvset__top__DOT__ram__DOT__d__v0 = 1U;
            __Vdlyvdim0__top__DOT__ram__DOT__d__v0 
                = vlTOPp->top__DOT__ram_ad_temp;
        }
    }
    if (vlTOPp->top__DOT__tape_wr) {
        __Vdlyvval__top__DOT__ram__DOT__d__v1 = vlTOPp->top__DOT__tape_dout;
        __Vdlyvset__top__DOT__ram__DOT__d__v1 = 1U;
        __Vdlyvdim0__top__DOT__ram__DOT__d__v1 = vlTOPp->top__DOT__tape_addr;
    }
    vlTOPp->top__DOT__oricatmos__DOT__ROM_MD_DO = vlTOPp->top__DOT__oricatmos__DOT__inst_rom2__DOT__rom_data
        [(0x1fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)];
    vlTOPp->top__DOT__oricatmos__DOT__ROM_1_DO = vlTOPp->top__DOT__oricatmos__DOT__inst_rom1__DOT__rom_data
        [(0x3fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)];
    if ((7U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sweq) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf1) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swret) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrs) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfs) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw0) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swl) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw8)))));
    } else if ((6U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sww) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sws) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swa) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf2) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swe) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swg) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swh) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swy)))));
    } else if ((5U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swlsb) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrsb) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfcn) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swp) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swo) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swi) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swu)))));
    } else if ((4U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swR) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swD) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swL) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swls) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swU) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdot) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swcom) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsp)))));
    } else if ((3U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsq) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swbs) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf3) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf4) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdsh) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsc) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw9) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swk)))));
    } else if ((2U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swc) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw2) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swz) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swctl) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw4) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swb) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw6) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swm)))));
    } else if ((1U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swd) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swq) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swesc) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf5) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swr) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swt) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swj)))));
    } else if ((0U == (7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out)))) {
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xfU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw3) 
                 << 7U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swx) 
                            << 6U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw1) 
                                       << 5U) | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf6) 
                                                 << 4U)))));
        vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW = 
            ((0xf0U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW)) 
             | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swv) 
                 << 3U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw5) 
                            << 2U) | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swn) 
                                       << 1U) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw7)))));
    }
    if (__Vdlyvset__top__DOT__ram__DOT__d__v0) {
        vlTOPp->top__DOT__ram__DOT__d[__Vdlyvdim0__top__DOT__ram__DOT__d__v0] 
            = __Vdlyvval__top__DOT__ram__DOT__d__v0;
    }
    if (__Vdlyvset__top__DOT__ram__DOT__d__v1) {
        vlTOPp->top__DOT__ram__DOT__d[__Vdlyvdim0__top__DOT__ram__DOT__d__v1] 
            = __Vdlyvval__top__DOT__ram__DOT__d__v1;
    }
    vlTOPp->top__DOT__oricatmos__DOT__fdd_ready = vlTOPp->top__DOT__fdd_ready;
    vlTOPp->top__DOT__VGA_B = vlTOPp->VGA_B;
    vlTOPp->top__DOT__VGA_G = vlTOPp->VGA_G;
    vlTOPp->top__DOT__VGA_R = vlTOPp->VGA_R;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swnmi 
        = vlTOPp->top__DOT__oricatmos__DOT__swnmi;
    vlTOPp->top__DOT__ram__DOT__do1 = vlTOPp->top__DOT__ram_q;
    vlTOPp->top__DOT__oricatmos__DOT__ram_q = vlTOPp->top__DOT__ram_q;
    vlTOPp->top__DOT__VGA_VS = vlTOPp->VGA_VS;
    if (vlTOPp->ce_pix) {
        vlTOPp->VGA_HS = (1U & (~ (IData)(vlTOPp->top__DOT__hs)));
    }
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrst 
        = vlTOPp->top__DOT__oricatmos__DOT__swrst;
    vlTOPp->top__DOT__oricatmos__DOT__KEYB_RESETn = 
        (1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__swrst)));
    vlTOPp->top__DOT__ram_d_temp = ((IData)(vlTOPp->reset)
                                     ? 1U : (IData)(vlTOPp->top__DOT__ram_d));
    vlTOPp->top__DOT__ram_cs_temp = ((IData)(vlTOPp->reset) 
                                     | (IData)(vlTOPp->top__DOT__ram_cs));
    vlTOPp->top__DOT__ram_we_temp = ((IData)(vlTOPp->reset) 
                                     | (IData)(vlTOPp->top__DOT__ram_we));
    vlTOPp->top__DOT__ram_ad_temp = (0xffffU & ((IData)(vlTOPp->reset)
                                                 ? vlTOPp->top__DOT__clr_addr
                                                 : (IData)(vlTOPp->top__DOT__ram_ad)));
    if (((IData)(vlTOPp->top__DOT__cassette__DOT__tapecache_loaded) 
         & (~ (IData)(vlTOPp->top__DOT__tape_complete)))) {
        if (((((((((2U == (IData)(vlTOPp->top__DOT__cassette__DOT__state)) 
                   | (3U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                  | (4U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                 | (5U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
                | (6U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
               | (7U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
              | (8U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) 
             | (9U == (IData)(vlTOPp->top__DOT__cassette__DOT__state)))) {
            if ((2U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((6U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    if ((0U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout))) {
                        vlTOPp->top__DOT__cassette__DOT__fileType 
                            = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                        vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 3U;
                    } else if ((0x80U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout))) {
                        vlTOPp->top__DOT__cassette__DOT__fileType 
                            = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                        vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 3U;
                    }
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((3U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((7U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    if ((0U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout))) {
                        vlTOPp->top__DOT__cassette__DOT__autorun 
                            = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                        vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 4U;
                    } else if ((0xc7U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout))) {
                        vlTOPp->top__DOT__cassette__DOT__autorun 
                            = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                        vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 4U;
                    }
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((4U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((9U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__endAddressHIGH 
                        = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 5U;
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((5U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((0xaU == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__endAddressLOW 
                        = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 6U;
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((6U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((0xbU == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__end_addr 
                        = (((IData)(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH) 
                            << 8U) | (IData)(vlTOPp->top__DOT__cassette__DOT__endAddressLOW));
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__startAddressHIGH 
                        = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 7U;
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((7U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if ((0xcU == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr))) {
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__startAddressLOW 
                        = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 8U;
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else if ((8U == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
                if (VL_UNLIKELY((0xeU <= (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)))) {
                    VL_WRITEF("cache_addr %x cache_dout %x\n",
                              16,vlTOPp->top__DOT__cassette__DOT__cache_addr,
                              8,(IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout));
                    vlTOPp->top__DOT__loadpoint = vlTOPp->top__DOT__cassette__DOT__start_addr;
                    if (VL_UNLIKELY(((0x20U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout)) 
                                     | ((0x30U <= (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout)) 
                                        & (0x5aU >= (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout)))))) {
                        VL_WRITEF("Ascii found %c\n",
                                  8,vlTOPp->top__DOT__cassette__DOT__cache_dout);
                    } else if (VL_UNLIKELY((0U == (IData)(vlTOPp->top__DOT__cassette__DOT__cache_dout)))) {
                        VL_WRITEF("End of Filename found\n");
                        vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 9U;
                    }
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__start_addr 
                        = (((IData)(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH) 
                            << 8U) | (IData)(vlTOPp->top__DOT__cassette__DOT__startAddressLOW));
                }
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
            } else {
                vlTOPp->__Vdly__top__DOT__cassette__DOT__cache_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__cache_addr)));
                vlTOPp->__Vdly__top__DOT__tape_wr = 1U;
                vlTOPp->top__DOT__tape_addr = vlTOPp->top__DOT__cassette__DOT__start_addr;
                vlTOPp->top__DOT__tape_dout = vlTOPp->top__DOT__cassette__DOT__cache_dout;
                vlTOPp->__Vdly__top__DOT__cassette__DOT__start_addr 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__cassette__DOT__start_addr)));
                if (VL_UNLIKELY(((IData)(vlTOPp->top__DOT__cassette__DOT__start_addr) 
                                 == (IData)(vlTOPp->top__DOT__cassette__DOT__end_addr)))) {
                    VL_WRITEF("(state SM_PROGRAMCODE %x) start_addr %x end_addr %x\n",
                              16,vlTOPp->top__DOT__cassette__DOT__state,
                              16,(IData)(vlTOPp->top__DOT__cassette__DOT__start_addr),
                              16,vlTOPp->top__DOT__cassette__DOT__end_addr);
                    vlTOPp->__Vdly__top__DOT__tape_complete = 1U;
                    vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 0xaU;
                }
            }
        } else if ((0xaU == (IData)(vlTOPp->top__DOT__cassette__DOT__state))) {
            vlTOPp->__Vdly__top__DOT__cassette__DOT__state = 2U;
        }
    } else if (vlTOPp->top__DOT__tape_complete) {
        if (vlTOPp->top__DOT__tape_wr) {
            vlTOPp->__Vdly__top__DOT__tape_wr = 0U;
            vlTOPp->top__DOT__tape_autorun = 1U;
        } else {
            vlTOPp->top__DOT__tape_autorun = 0U;
        }
    }
    vlTOPp->top__DOT__oricatmos__DOT__inst_rom2__DOT__data 
        = vlTOPp->top__DOT__oricatmos__DOT__ROM_MD_DO;
    vlTOPp->top__DOT__oricatmos__DOT__inst_rom1__DOT__data 
        = vlTOPp->top__DOT__oricatmos__DOT__ROM_1_DO;
    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__ROWbit 
        = vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW;
    vlTOPp->top__DOT__oricatmos__DOT__via_pb_in__out1 
        = ((0xf7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_in__out1)) 
           | ((0U != ((IData)(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW) 
                      & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__ym_o_ioa)))) 
              << 3U));
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
                                        } else if (
                                                   (0x71U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->ps2_key)))) {
                                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel 
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
                                if ((0x3bU == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swj 
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
                    if ((0x1eU != (0xffU & (IData)(vlTOPp->ps2_key)))) {
                        if ((0x26U == (0xffU & (IData)(vlTOPp->ps2_key)))) {
                            vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw3 
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
                                if ((0x22U == (0xffU 
                                               & (IData)(vlTOPp->ps2_key)))) {
                                    vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swx 
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
}
