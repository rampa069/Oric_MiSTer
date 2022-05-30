// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

const IData Vtop::var_top__DOT__cassette__DOT__SM_INIT(1U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_FILETYPE(2U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_AUTORUN(3U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_ENDADDRESSHIGH(4U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_ENDADDRESSLOW(5U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_STARTADDRESSHIGH(6U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_STARTADDRESSLOW(7U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_UNUSED(8U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_PROGRAMCODE(9U);
const IData Vtop::var_top__DOT__cassette__DOT__SM_COMPLETED(0xaU);

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-9);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

// Savable
void Vtop::__Vserialize(VerilatedSerialize& os) {
    vluint64_t __Vcheckval = 0x84a44d6812647398ULL;
    os << __Vcheckval;
    os << __VlSymsp->_vm_contextp__;
    os<<clk_48;
    os<<reset;
    os<<inputs;
    os<<VGA_R;
    os<<VGA_G;
    os<<VGA_B;
    os<<VGA_HS;
    os<<VGA_VS;
    os<<VGA_HB;
    os<<VGA_VB;
    os<<AUDIO_L;
    os<<AUDIO_R;
    os<<ioctl_download;
    os<<ioctl_upload;
    os<<ioctl_wr;
    os<<ioctl_addr;
    os<<ioctl_dout;
    os<<ioctl_din;
    os<<ioctl_index;
    os<<ioctl_wait;
    os<<top__DOT__clk_48;
    os<<top__DOT__reset;
    os<<top__DOT__inputs;
    os<<top__DOT__VGA_R;
    os<<top__DOT__VGA_G;
    os<<top__DOT__VGA_B;
    os<<top__DOT__VGA_HS;
    os<<top__DOT__VGA_VS;
    os<<top__DOT__VGA_HB;
    os<<top__DOT__VGA_VB;
    os<<top__DOT__AUDIO_L;
    os<<top__DOT__AUDIO_R;
    os<<top__DOT__ioctl_download;
    os<<top__DOT__ioctl_upload;
    os<<top__DOT__ioctl_wr;
    os<<top__DOT__ioctl_addr;
    os<<top__DOT__ioctl_dout;
    os<<top__DOT__ioctl_din;
    os<<top__DOT__ioctl_index;
    os<<top__DOT__ioctl_wait;
    os<<top__DOT__ce_pix;
    os<<top__DOT__clr_addr;
    os<<top__DOT__ram_ad;
    os<<top__DOT__ram_d;
    os<<top__DOT__ram_we;
    os<<top__DOT__ram_cs;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os<<top__DOT__ram[__Vi0];
    }
    os<<top__DOT__ram_q;
    os<<top__DOT__tape_addr;
    os<<top__DOT__tape_wr;
    os<<top__DOT__tape_dout;
    os<<top__DOT__tape_complete;
    os<<top__DOT__tape_autorun;
    os<<top__DOT__tape__DOT__clk;
    os<<top__DOT__tape__DOT__addr;
    os<<top__DOT__tape__DOT__dout;
    os<<top__DOT__tape__DOT__cs;
    os<<top__DOT__tape__DOT__rom_init;
    os<<top__DOT__tape__DOT__rom_init_clk;
    os<<top__DOT__tape__DOT__rom_init_address;
    os<<top__DOT__tape__DOT__rom_init_data;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os<<top__DOT__tape__DOT__memory[__Vi0];
    }
    os<<top__DOT__cassette__DOT__clk;
    os<<top__DOT__cassette__DOT__ioctl_download;
    os<<top__DOT__cassette__DOT__ioctl_wr;
    os<<top__DOT__cassette__DOT__ioctl_addr;
    os<<top__DOT__cassette__DOT__ioctl_dout;
    os<<top__DOT__cassette__DOT__reset_n;
    os<<top__DOT__cassette__DOT__autostart;
    os<<top__DOT__cassette__DOT__tape_autorun;
    os<<top__DOT__cassette__DOT__loadpoint;
    os<<top__DOT__cassette__DOT__tape_addr;
    os<<top__DOT__cassette__DOT__tape_wr;
    os<<top__DOT__cassette__DOT__tape_dout;
    os<<top__DOT__cassette__DOT__tape_complete;
    os<<top__DOT__cassette__DOT__programlength;
    os<<top__DOT__cassette__DOT__start_addr;
    os<<top__DOT__cassette__DOT__end_addr;
    os<<top__DOT__cassette__DOT__state;
    os<<top__DOT__cassette__DOT__fileType;
    os<<top__DOT__cassette__DOT__autorun;
    os<<top__DOT__cassette__DOT__endAddressHIGH;
    os<<top__DOT__cassette__DOT__endAddressLOW;
    os<<top__DOT__cassette__DOT__startAddressHIGH;
    os<<top__DOT__cassette__DOT__startAddressLOW;
    os<<top__DOT__cassette__DOT__unused;
    os<<__Vclklast__TOP__clk_48;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os<<__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vserialize(os);
}
void Vtop::__Vdeserialize(VerilatedDeserialize& os) {
    vluint64_t __Vcheckval = 0x84a44d6812647398ULL;
    os.readAssert(__Vcheckval);
    os >> __VlSymsp->_vm_contextp__;
    os>>clk_48;
    os>>reset;
    os>>inputs;
    os>>VGA_R;
    os>>VGA_G;
    os>>VGA_B;
    os>>VGA_HS;
    os>>VGA_VS;
    os>>VGA_HB;
    os>>VGA_VB;
    os>>AUDIO_L;
    os>>AUDIO_R;
    os>>ioctl_download;
    os>>ioctl_upload;
    os>>ioctl_wr;
    os>>ioctl_addr;
    os>>ioctl_dout;
    os>>ioctl_din;
    os>>ioctl_index;
    os>>ioctl_wait;
    os>>top__DOT__clk_48;
    os>>top__DOT__reset;
    os>>top__DOT__inputs;
    os>>top__DOT__VGA_R;
    os>>top__DOT__VGA_G;
    os>>top__DOT__VGA_B;
    os>>top__DOT__VGA_HS;
    os>>top__DOT__VGA_VS;
    os>>top__DOT__VGA_HB;
    os>>top__DOT__VGA_VB;
    os>>top__DOT__AUDIO_L;
    os>>top__DOT__AUDIO_R;
    os>>top__DOT__ioctl_download;
    os>>top__DOT__ioctl_upload;
    os>>top__DOT__ioctl_wr;
    os>>top__DOT__ioctl_addr;
    os>>top__DOT__ioctl_dout;
    os>>top__DOT__ioctl_din;
    os>>top__DOT__ioctl_index;
    os>>top__DOT__ioctl_wait;
    os>>top__DOT__ce_pix;
    os>>top__DOT__clr_addr;
    os>>top__DOT__ram_ad;
    os>>top__DOT__ram_d;
    os>>top__DOT__ram_we;
    os>>top__DOT__ram_cs;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os>>top__DOT__ram[__Vi0];
    }
    os>>top__DOT__ram_q;
    os>>top__DOT__tape_addr;
    os>>top__DOT__tape_wr;
    os>>top__DOT__tape_dout;
    os>>top__DOT__tape_complete;
    os>>top__DOT__tape_autorun;
    os>>top__DOT__tape__DOT__clk;
    os>>top__DOT__tape__DOT__addr;
    os>>top__DOT__tape__DOT__dout;
    os>>top__DOT__tape__DOT__cs;
    os>>top__DOT__tape__DOT__rom_init;
    os>>top__DOT__tape__DOT__rom_init_clk;
    os>>top__DOT__tape__DOT__rom_init_address;
    os>>top__DOT__tape__DOT__rom_init_data;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os>>top__DOT__tape__DOT__memory[__Vi0];
    }
    os>>top__DOT__cassette__DOT__clk;
    os>>top__DOT__cassette__DOT__ioctl_download;
    os>>top__DOT__cassette__DOT__ioctl_wr;
    os>>top__DOT__cassette__DOT__ioctl_addr;
    os>>top__DOT__cassette__DOT__ioctl_dout;
    os>>top__DOT__cassette__DOT__reset_n;
    os>>top__DOT__cassette__DOT__autostart;
    os>>top__DOT__cassette__DOT__tape_autorun;
    os>>top__DOT__cassette__DOT__loadpoint;
    os>>top__DOT__cassette__DOT__tape_addr;
    os>>top__DOT__cassette__DOT__tape_wr;
    os>>top__DOT__cassette__DOT__tape_dout;
    os>>top__DOT__cassette__DOT__tape_complete;
    os>>top__DOT__cassette__DOT__programlength;
    os>>top__DOT__cassette__DOT__start_addr;
    os>>top__DOT__cassette__DOT__end_addr;
    os>>top__DOT__cassette__DOT__state;
    os>>top__DOT__cassette__DOT__fileType;
    os>>top__DOT__cassette__DOT__autorun;
    os>>top__DOT__cassette__DOT__endAddressHIGH;
    os>>top__DOT__cassette__DOT__endAddressLOW;
    os>>top__DOT__cassette__DOT__startAddressHIGH;
    os>>top__DOT__cassette__DOT__startAddressLOW;
    os>>top__DOT__cassette__DOT__unused;
    os>>__Vclklast__TOP__clk_48;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os>>__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vdeserialize(os);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ce_pix = 1U;
    vlTOPp->ioctl_wait = 0U;
    vlTOPp->top__DOT__tape_autorun = 0U;
    vlTOPp->top__DOT__clr_addr = 0U;
    vlTOPp->top__DOT__cassette__DOT__state = 1U;
    vlTOPp->top__DOT__ioctl_wait = vlTOPp->ioctl_wait;
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__VGA_R = vlTOPp->VGA_R;
    vlTOPp->top__DOT__VGA_G = vlTOPp->VGA_G;
    vlTOPp->top__DOT__VGA_B = vlTOPp->VGA_B;
    vlTOPp->top__DOT__VGA_HS = vlTOPp->VGA_HS;
    vlTOPp->top__DOT__VGA_VS = vlTOPp->VGA_VS;
    vlTOPp->top__DOT__VGA_HB = vlTOPp->VGA_HB;
    vlTOPp->top__DOT__VGA_VB = vlTOPp->VGA_VB;
    vlTOPp->top__DOT__AUDIO_L = vlTOPp->AUDIO_L;
    vlTOPp->top__DOT__AUDIO_R = vlTOPp->AUDIO_R;
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
    vlTOPp->top__DOT__cassette__DOT__tape_addr = vlTOPp->top__DOT__tape_addr;
    vlTOPp->top__DOT__cassette__DOT__tape_wr = vlTOPp->top__DOT__tape_wr;
    vlTOPp->top__DOT__cassette__DOT__tape_dout = vlTOPp->top__DOT__tape_dout;
    vlTOPp->top__DOT__cassette__DOT__tape_complete 
        = vlTOPp->top__DOT__tape_complete;
    vlTOPp->top__DOT__ioctl_wait = vlTOPp->ioctl_wait;
    vlTOPp->top__DOT__cassette__DOT__tape_autorun = vlTOPp->top__DOT__tape_autorun;
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_48 = vlTOPp->clk_48;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop::_ctor_var_reset(Vtop* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clk_48 = 0;
    self->reset = 0;
    self->inputs = 0;
    self->VGA_R = 0;
    self->VGA_G = 0;
    self->VGA_B = 0;
    self->VGA_HS = 0;
    self->VGA_VS = 0;
    self->VGA_HB = 0;
    self->VGA_VB = 0;
    self->AUDIO_L = 0;
    self->AUDIO_R = 0;
    self->ioctl_download = 0;
    self->ioctl_upload = 0;
    self->ioctl_wr = 0;
    self->ioctl_addr = 0;
    self->ioctl_dout = 0;
    self->ioctl_din = 0;
    self->ioctl_index = 0;
    self->ioctl_wait = 0;
    self->top__DOT__clk_48 = 0;
    self->top__DOT__reset = 0;
    self->top__DOT__inputs = 0;
    self->top__DOT__VGA_R = 0;
    self->top__DOT__VGA_G = 0;
    self->top__DOT__VGA_B = 0;
    self->top__DOT__VGA_HS = 0;
    self->top__DOT__VGA_VS = 0;
    self->top__DOT__VGA_HB = 0;
    self->top__DOT__VGA_VB = 0;
    self->top__DOT__AUDIO_L = 0;
    self->top__DOT__AUDIO_R = 0;
    self->top__DOT__ioctl_download = 0;
    self->top__DOT__ioctl_upload = 0;
    self->top__DOT__ioctl_wr = 0;
    self->top__DOT__ioctl_addr = 0;
    self->top__DOT__ioctl_dout = 0;
    self->top__DOT__ioctl_din = 0;
    self->top__DOT__ioctl_index = 0;
    self->top__DOT__ioctl_wait = 0;
    self->top__DOT__ce_pix = 0;
    self->top__DOT__clr_addr = 0;
    self->top__DOT__ram_ad = 0;
    self->top__DOT__ram_d = 0;
    self->top__DOT__ram_we = 0;
    self->top__DOT__ram_cs = 0;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        self->top__DOT__ram[__Vi0] = 0;
    }
    self->top__DOT__ram_q = 0;
    self->top__DOT__tape_addr = 0;
    self->top__DOT__tape_wr = 0;
    self->top__DOT__tape_dout = 0;
    self->top__DOT__tape_complete = 0;
    self->top__DOT__tape_autorun = 0;
    self->top__DOT__tape__DOT__clk = 0;
    self->top__DOT__tape__DOT__addr = 0;
    self->top__DOT__tape__DOT__dout = 0;
    self->top__DOT__tape__DOT__cs = 0;
    self->top__DOT__tape__DOT__rom_init = 0;
    self->top__DOT__tape__DOT__rom_init_clk = 0;
    self->top__DOT__tape__DOT__rom_init_address = 0;
    self->top__DOT__tape__DOT__rom_init_data = 0;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        self->top__DOT__tape__DOT__memory[__Vi0] = 0;
    }
    self->top__DOT__cassette__DOT__clk = 0;
    self->top__DOT__cassette__DOT__ioctl_download = 0;
    self->top__DOT__cassette__DOT__ioctl_wr = 0;
    self->top__DOT__cassette__DOT__ioctl_addr = 0;
    self->top__DOT__cassette__DOT__ioctl_dout = 0;
    self->top__DOT__cassette__DOT__reset_n = 0;
    self->top__DOT__cassette__DOT__autostart = 0;
    self->top__DOT__cassette__DOT__tape_autorun = 0;
    self->top__DOT__cassette__DOT__loadpoint = 0;
    self->top__DOT__cassette__DOT__tape_addr = 0;
    self->top__DOT__cassette__DOT__tape_wr = 0;
    self->top__DOT__cassette__DOT__tape_dout = 0;
    self->top__DOT__cassette__DOT__tape_complete = 0;
    self->top__DOT__cassette__DOT__programlength = 0;
    self->top__DOT__cassette__DOT__start_addr = 0;
    self->top__DOT__cassette__DOT__end_addr = 0;
    self->top__DOT__cassette__DOT__state = 0;
    self->top__DOT__cassette__DOT__fileType = 0;
    self->top__DOT__cassette__DOT__autorun = 0;
    self->top__DOT__cassette__DOT__endAddressHIGH = 0;
    self->top__DOT__cassette__DOT__endAddressLOW = 0;
    self->top__DOT__cassette__DOT__startAddressHIGH = 0;
    self->top__DOT__cassette__DOT__startAddressLOW = 0;
    self->top__DOT__cassette__DOT__unused = 0;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        self->__Vm_traceActivity[__Vi0] = 0;
    }
}
