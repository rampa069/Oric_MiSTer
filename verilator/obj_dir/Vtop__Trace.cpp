// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk_48));
        tracep->chgBit(oldp+1,(vlTOPp->reset));
        tracep->chgSData(oldp+2,(vlTOPp->inputs),12);
        tracep->chgCData(oldp+3,(vlTOPp->VGA_R),8);
        tracep->chgCData(oldp+4,(vlTOPp->VGA_G),8);
        tracep->chgCData(oldp+5,(vlTOPp->VGA_B),8);
        tracep->chgBit(oldp+6,(vlTOPp->VGA_HS));
        tracep->chgBit(oldp+7,(vlTOPp->VGA_VS));
        tracep->chgBit(oldp+8,(vlTOPp->VGA_HB));
        tracep->chgBit(oldp+9,(vlTOPp->VGA_VB));
        tracep->chgSData(oldp+10,(vlTOPp->AUDIO_L),16);
        tracep->chgSData(oldp+11,(vlTOPp->AUDIO_R),16);
        tracep->chgBit(oldp+12,(vlTOPp->ioctl_download));
        tracep->chgBit(oldp+13,(vlTOPp->ioctl_upload));
        tracep->chgBit(oldp+14,(vlTOPp->ioctl_wr));
        tracep->chgIData(oldp+15,(vlTOPp->ioctl_addr),25);
        tracep->chgCData(oldp+16,(vlTOPp->ioctl_dout),8);
        tracep->chgCData(oldp+17,(vlTOPp->ioctl_din),8);
        tracep->chgCData(oldp+18,(vlTOPp->ioctl_index),8);
        tracep->chgBit(oldp+19,(vlTOPp->ioctl_wait));
        tracep->chgBit(oldp+20,(vlTOPp->top__DOT__clk_48));
        tracep->chgBit(oldp+21,(vlTOPp->top__DOT__reset));
        tracep->chgSData(oldp+22,(vlTOPp->top__DOT__inputs),12);
        tracep->chgCData(oldp+23,(vlTOPp->top__DOT__VGA_R),8);
        tracep->chgCData(oldp+24,(vlTOPp->top__DOT__VGA_G),8);
        tracep->chgCData(oldp+25,(vlTOPp->top__DOT__VGA_B),8);
        tracep->chgBit(oldp+26,(vlTOPp->top__DOT__VGA_HS));
        tracep->chgBit(oldp+27,(vlTOPp->top__DOT__VGA_VS));
        tracep->chgBit(oldp+28,(vlTOPp->top__DOT__VGA_HB));
        tracep->chgBit(oldp+29,(vlTOPp->top__DOT__VGA_VB));
        tracep->chgSData(oldp+30,(vlTOPp->top__DOT__AUDIO_L),16);
        tracep->chgSData(oldp+31,(vlTOPp->top__DOT__AUDIO_R),16);
        tracep->chgBit(oldp+32,(vlTOPp->top__DOT__ioctl_download));
        tracep->chgBit(oldp+33,(vlTOPp->top__DOT__ioctl_upload));
        tracep->chgBit(oldp+34,(vlTOPp->top__DOT__ioctl_wr));
        tracep->chgIData(oldp+35,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->chgCData(oldp+36,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->chgCData(oldp+37,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->chgCData(oldp+38,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->chgBit(oldp+39,(vlTOPp->top__DOT__ioctl_wait));
        tracep->chgBit(oldp+40,(vlTOPp->top__DOT__ce_pix));
        tracep->chgIData(oldp+41,(vlTOPp->top__DOT__clr_addr),17);
        tracep->chgSData(oldp+42,(vlTOPp->top__DOT__ram_ad),16);
        tracep->chgCData(oldp+43,(vlTOPp->top__DOT__ram_d),8);
        tracep->chgBit(oldp+44,(vlTOPp->top__DOT__ram_we));
        tracep->chgBit(oldp+45,(vlTOPp->top__DOT__ram_cs));
        tracep->chgCData(oldp+46,(vlTOPp->top__DOT__ram_q),8);
        tracep->chgSData(oldp+47,(vlTOPp->top__DOT__tape_addr),16);
        tracep->chgBit(oldp+48,(vlTOPp->top__DOT__tape_wr));
        tracep->chgCData(oldp+49,(vlTOPp->top__DOT__tape_dout),8);
        tracep->chgBit(oldp+50,(vlTOPp->top__DOT__tape_complete));
        tracep->chgBit(oldp+51,(vlTOPp->top__DOT__tape_autorun));
        tracep->chgBit(oldp+52,(vlTOPp->top__DOT__tape__DOT__clk));
        tracep->chgSData(oldp+53,(vlTOPp->top__DOT__tape__DOT__addr),16);
        tracep->chgCData(oldp+54,(vlTOPp->top__DOT__tape__DOT__dout),8);
        tracep->chgBit(oldp+55,(vlTOPp->top__DOT__tape__DOT__cs));
        tracep->chgBit(oldp+56,(vlTOPp->top__DOT__tape__DOT__rom_init));
        tracep->chgBit(oldp+57,(vlTOPp->top__DOT__tape__DOT__rom_init_clk));
        tracep->chgSData(oldp+58,(vlTOPp->top__DOT__tape__DOT__rom_init_address),16);
        tracep->chgCData(oldp+59,(vlTOPp->top__DOT__tape__DOT__rom_init_data),8);
        tracep->chgBit(oldp+60,(vlTOPp->top__DOT__cassette__DOT__clk));
        tracep->chgBit(oldp+61,(vlTOPp->top__DOT__cassette__DOT__ioctl_download));
        tracep->chgBit(oldp+62,(vlTOPp->top__DOT__cassette__DOT__ioctl_wr));
        tracep->chgIData(oldp+63,(vlTOPp->top__DOT__cassette__DOT__ioctl_addr),25);
        tracep->chgCData(oldp+64,(vlTOPp->top__DOT__cassette__DOT__ioctl_dout),8);
        tracep->chgBit(oldp+65,(vlTOPp->top__DOT__cassette__DOT__reset_n));
        tracep->chgBit(oldp+66,(vlTOPp->top__DOT__cassette__DOT__autostart));
        tracep->chgBit(oldp+67,(vlTOPp->top__DOT__cassette__DOT__tape_autorun));
        tracep->chgSData(oldp+68,(vlTOPp->top__DOT__cassette__DOT__loadpoint),16);
        tracep->chgSData(oldp+69,(vlTOPp->top__DOT__cassette__DOT__tape_addr),16);
        tracep->chgBit(oldp+70,(vlTOPp->top__DOT__cassette__DOT__tape_wr));
        tracep->chgCData(oldp+71,(vlTOPp->top__DOT__cassette__DOT__tape_dout),8);
        tracep->chgBit(oldp+72,(vlTOPp->top__DOT__cassette__DOT__tape_complete));
        tracep->chgSData(oldp+73,(vlTOPp->top__DOT__cassette__DOT__programlength),16);
        tracep->chgSData(oldp+74,(vlTOPp->top__DOT__cassette__DOT__start_addr),16);
        tracep->chgSData(oldp+75,(vlTOPp->top__DOT__cassette__DOT__end_addr),16);
        tracep->chgSData(oldp+76,(vlTOPp->top__DOT__cassette__DOT__state),16);
        tracep->chgCData(oldp+77,(vlTOPp->top__DOT__cassette__DOT__fileType),8);
        tracep->chgCData(oldp+78,(vlTOPp->top__DOT__cassette__DOT__autorun),8);
        tracep->chgCData(oldp+79,(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH),8);
        tracep->chgCData(oldp+80,(vlTOPp->top__DOT__cassette__DOT__endAddressLOW),8);
        tracep->chgCData(oldp+81,(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH),8);
        tracep->chgCData(oldp+82,(vlTOPp->top__DOT__cassette__DOT__startAddressLOW),8);
        tracep->chgBit(oldp+83,(vlTOPp->top__DOT__cassette__DOT__unused));
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
