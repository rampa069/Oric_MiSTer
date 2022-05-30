// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_48", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"inputs", false,-1, 11,0);
        tracep->declBus(c+4,"VGA_R", false,-1, 7,0);
        tracep->declBus(c+5,"VGA_G", false,-1, 7,0);
        tracep->declBus(c+6,"VGA_B", false,-1, 7,0);
        tracep->declBit(c+7,"VGA_HS", false,-1);
        tracep->declBit(c+8,"VGA_VS", false,-1);
        tracep->declBit(c+9,"VGA_HB", false,-1);
        tracep->declBit(c+10,"VGA_VB", false,-1);
        tracep->declBus(c+11,"AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+12,"AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+13,"ioctl_download", false,-1);
        tracep->declBit(c+14,"ioctl_upload", false,-1);
        tracep->declBit(c+15,"ioctl_wr", false,-1);
        tracep->declBus(c+16,"ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+17,"ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+18,"ioctl_din", false,-1, 7,0);
        tracep->declBus(c+19,"ioctl_index", false,-1, 7,0);
        tracep->declBit(c+20,"ioctl_wait", false,-1);
        tracep->declBit(c+21,"top clk_48", false,-1);
        tracep->declBit(c+22,"top reset", false,-1);
        tracep->declBus(c+23,"top inputs", false,-1, 11,0);
        tracep->declBus(c+24,"top VGA_R", false,-1, 7,0);
        tracep->declBus(c+25,"top VGA_G", false,-1, 7,0);
        tracep->declBus(c+26,"top VGA_B", false,-1, 7,0);
        tracep->declBit(c+27,"top VGA_HS", false,-1);
        tracep->declBit(c+28,"top VGA_VS", false,-1);
        tracep->declBit(c+29,"top VGA_HB", false,-1);
        tracep->declBit(c+30,"top VGA_VB", false,-1);
        tracep->declBus(c+31,"top AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+32,"top AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+33,"top ioctl_download", false,-1);
        tracep->declBit(c+34,"top ioctl_upload", false,-1);
        tracep->declBit(c+35,"top ioctl_wr", false,-1);
        tracep->declBus(c+36,"top ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+37,"top ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+38,"top ioctl_din", false,-1, 7,0);
        tracep->declBus(c+39,"top ioctl_index", false,-1, 7,0);
        tracep->declBit(c+40,"top ioctl_wait", false,-1);
        tracep->declBit(c+41,"top ce_pix", false,-1);
        tracep->declBus(c+42,"top clr_addr", false,-1, 16,0);
        tracep->declBus(c+43,"top ram_ad", false,-1, 15,0);
        tracep->declBus(c+44,"top ram_d", false,-1, 7,0);
        tracep->declBit(c+45,"top ram_we", false,-1);
        tracep->declBit(c+46,"top ram_cs", false,-1);
        tracep->declBus(c+47,"top ram_q", false,-1, 7,0);
        tracep->declBus(c+48,"top tape_addr", false,-1, 15,0);
        tracep->declBit(c+49,"top tape_wr", false,-1);
        tracep->declBus(c+50,"top tape_dout", false,-1, 7,0);
        tracep->declBit(c+51,"top tape_complete", false,-1);
        tracep->declBit(c+52,"top tape_autorun", false,-1);
        tracep->declBit(c+53,"top tape clk", false,-1);
        tracep->declBus(c+54,"top tape addr", false,-1, 15,0);
        tracep->declBus(c+55,"top tape dout", false,-1, 7,0);
        tracep->declBit(c+56,"top tape cs", false,-1);
        tracep->declBit(c+57,"top tape rom_init", false,-1);
        tracep->declBit(c+58,"top tape rom_init_clk", false,-1);
        tracep->declBus(c+59,"top tape rom_init_address", false,-1, 15,0);
        tracep->declBus(c+60,"top tape rom_init_data", false,-1, 7,0);
        tracep->declBit(c+61,"top cassette clk", false,-1);
        tracep->declBit(c+62,"top cassette ioctl_download", false,-1);
        tracep->declBit(c+63,"top cassette ioctl_wr", false,-1);
        tracep->declBus(c+64,"top cassette ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+65,"top cassette ioctl_dout", false,-1, 7,0);
        tracep->declBit(c+66,"top cassette reset_n", false,-1);
        tracep->declBit(c+67,"top cassette autostart", false,-1);
        tracep->declBit(c+68,"top cassette tape_autorun", false,-1);
        tracep->declBus(c+69,"top cassette loadpoint", false,-1, 15,0);
        tracep->declBus(c+70,"top cassette tape_addr", false,-1, 15,0);
        tracep->declBit(c+71,"top cassette tape_wr", false,-1);
        tracep->declBus(c+72,"top cassette tape_dout", false,-1, 7,0);
        tracep->declBit(c+73,"top cassette tape_complete", false,-1);
        tracep->declBus(c+85,"top cassette SM_INIT", false,-1, 31,0);
        tracep->declBus(c+86,"top cassette SM_FILETYPE", false,-1, 31,0);
        tracep->declBus(c+87,"top cassette SM_AUTORUN", false,-1, 31,0);
        tracep->declBus(c+88,"top cassette SM_ENDADDRESSHIGH", false,-1, 31,0);
        tracep->declBus(c+89,"top cassette SM_ENDADDRESSLOW", false,-1, 31,0);
        tracep->declBus(c+90,"top cassette SM_STARTADDRESSHIGH", false,-1, 31,0);
        tracep->declBus(c+91,"top cassette SM_STARTADDRESSLOW", false,-1, 31,0);
        tracep->declBus(c+92,"top cassette SM_UNUSED", false,-1, 31,0);
        tracep->declBus(c+93,"top cassette SM_PROGRAMCODE", false,-1, 31,0);
        tracep->declBus(c+94,"top cassette SM_COMPLETED", false,-1, 31,0);
        tracep->declBus(c+74,"top cassette programlength", false,-1, 15,0);
        tracep->declBus(c+75,"top cassette start_addr", false,-1, 15,0);
        tracep->declBus(c+76,"top cassette end_addr", false,-1, 15,0);
        tracep->declBus(c+77,"top cassette state", false,-1, 15,0);
        tracep->declBus(c+78,"top cassette fileType", false,-1, 7,0);
        tracep->declBus(c+79,"top cassette autorun", false,-1, 7,0);
        tracep->declBus(c+80,"top cassette endAddressHIGH", false,-1, 7,0);
        tracep->declBus(c+81,"top cassette endAddressLOW", false,-1, 7,0);
        tracep->declBus(c+82,"top cassette startAddressHIGH", false,-1, 7,0);
        tracep->declBus(c+83,"top cassette startAddressLOW", false,-1, 7,0);
        tracep->declBit(c+84,"top cassette unused", false,-1);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk_48));
        tracep->fullBit(oldp+2,(vlTOPp->reset));
        tracep->fullSData(oldp+3,(vlTOPp->inputs),12);
        tracep->fullCData(oldp+4,(vlTOPp->VGA_R),8);
        tracep->fullCData(oldp+5,(vlTOPp->VGA_G),8);
        tracep->fullCData(oldp+6,(vlTOPp->VGA_B),8);
        tracep->fullBit(oldp+7,(vlTOPp->VGA_HS));
        tracep->fullBit(oldp+8,(vlTOPp->VGA_VS));
        tracep->fullBit(oldp+9,(vlTOPp->VGA_HB));
        tracep->fullBit(oldp+10,(vlTOPp->VGA_VB));
        tracep->fullSData(oldp+11,(vlTOPp->AUDIO_L),16);
        tracep->fullSData(oldp+12,(vlTOPp->AUDIO_R),16);
        tracep->fullBit(oldp+13,(vlTOPp->ioctl_download));
        tracep->fullBit(oldp+14,(vlTOPp->ioctl_upload));
        tracep->fullBit(oldp+15,(vlTOPp->ioctl_wr));
        tracep->fullIData(oldp+16,(vlTOPp->ioctl_addr),25);
        tracep->fullCData(oldp+17,(vlTOPp->ioctl_dout),8);
        tracep->fullCData(oldp+18,(vlTOPp->ioctl_din),8);
        tracep->fullCData(oldp+19,(vlTOPp->ioctl_index),8);
        tracep->fullBit(oldp+20,(vlTOPp->ioctl_wait));
        tracep->fullBit(oldp+21,(vlTOPp->top__DOT__clk_48));
        tracep->fullBit(oldp+22,(vlTOPp->top__DOT__reset));
        tracep->fullSData(oldp+23,(vlTOPp->top__DOT__inputs),12);
        tracep->fullCData(oldp+24,(vlTOPp->top__DOT__VGA_R),8);
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT__VGA_G),8);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__VGA_B),8);
        tracep->fullBit(oldp+27,(vlTOPp->top__DOT__VGA_HS));
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__VGA_VS));
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__VGA_HB));
        tracep->fullBit(oldp+30,(vlTOPp->top__DOT__VGA_VB));
        tracep->fullSData(oldp+31,(vlTOPp->top__DOT__AUDIO_L),16);
        tracep->fullSData(oldp+32,(vlTOPp->top__DOT__AUDIO_R),16);
        tracep->fullBit(oldp+33,(vlTOPp->top__DOT__ioctl_download));
        tracep->fullBit(oldp+34,(vlTOPp->top__DOT__ioctl_upload));
        tracep->fullBit(oldp+35,(vlTOPp->top__DOT__ioctl_wr));
        tracep->fullIData(oldp+36,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->fullCData(oldp+37,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->fullCData(oldp+38,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->fullCData(oldp+39,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->fullBit(oldp+40,(vlTOPp->top__DOT__ioctl_wait));
        tracep->fullBit(oldp+41,(vlTOPp->top__DOT__ce_pix));
        tracep->fullIData(oldp+42,(vlTOPp->top__DOT__clr_addr),17);
        tracep->fullSData(oldp+43,(vlTOPp->top__DOT__ram_ad),16);
        tracep->fullCData(oldp+44,(vlTOPp->top__DOT__ram_d),8);
        tracep->fullBit(oldp+45,(vlTOPp->top__DOT__ram_we));
        tracep->fullBit(oldp+46,(vlTOPp->top__DOT__ram_cs));
        tracep->fullCData(oldp+47,(vlTOPp->top__DOT__ram_q),8);
        tracep->fullSData(oldp+48,(vlTOPp->top__DOT__tape_addr),16);
        tracep->fullBit(oldp+49,(vlTOPp->top__DOT__tape_wr));
        tracep->fullCData(oldp+50,(vlTOPp->top__DOT__tape_dout),8);
        tracep->fullBit(oldp+51,(vlTOPp->top__DOT__tape_complete));
        tracep->fullBit(oldp+52,(vlTOPp->top__DOT__tape_autorun));
        tracep->fullBit(oldp+53,(vlTOPp->top__DOT__tape__DOT__clk));
        tracep->fullSData(oldp+54,(vlTOPp->top__DOT__tape__DOT__addr),16);
        tracep->fullCData(oldp+55,(vlTOPp->top__DOT__tape__DOT__dout),8);
        tracep->fullBit(oldp+56,(vlTOPp->top__DOT__tape__DOT__cs));
        tracep->fullBit(oldp+57,(vlTOPp->top__DOT__tape__DOT__rom_init));
        tracep->fullBit(oldp+58,(vlTOPp->top__DOT__tape__DOT__rom_init_clk));
        tracep->fullSData(oldp+59,(vlTOPp->top__DOT__tape__DOT__rom_init_address),16);
        tracep->fullCData(oldp+60,(vlTOPp->top__DOT__tape__DOT__rom_init_data),8);
        tracep->fullBit(oldp+61,(vlTOPp->top__DOT__cassette__DOT__clk));
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__cassette__DOT__ioctl_download));
        tracep->fullBit(oldp+63,(vlTOPp->top__DOT__cassette__DOT__ioctl_wr));
        tracep->fullIData(oldp+64,(vlTOPp->top__DOT__cassette__DOT__ioctl_addr),25);
        tracep->fullCData(oldp+65,(vlTOPp->top__DOT__cassette__DOT__ioctl_dout),8);
        tracep->fullBit(oldp+66,(vlTOPp->top__DOT__cassette__DOT__reset_n));
        tracep->fullBit(oldp+67,(vlTOPp->top__DOT__cassette__DOT__autostart));
        tracep->fullBit(oldp+68,(vlTOPp->top__DOT__cassette__DOT__tape_autorun));
        tracep->fullSData(oldp+69,(vlTOPp->top__DOT__cassette__DOT__loadpoint),16);
        tracep->fullSData(oldp+70,(vlTOPp->top__DOT__cassette__DOT__tape_addr),16);
        tracep->fullBit(oldp+71,(vlTOPp->top__DOT__cassette__DOT__tape_wr));
        tracep->fullCData(oldp+72,(vlTOPp->top__DOT__cassette__DOT__tape_dout),8);
        tracep->fullBit(oldp+73,(vlTOPp->top__DOT__cassette__DOT__tape_complete));
        tracep->fullSData(oldp+74,(vlTOPp->top__DOT__cassette__DOT__programlength),16);
        tracep->fullSData(oldp+75,(vlTOPp->top__DOT__cassette__DOT__start_addr),16);
        tracep->fullSData(oldp+76,(vlTOPp->top__DOT__cassette__DOT__end_addr),16);
        tracep->fullSData(oldp+77,(vlTOPp->top__DOT__cassette__DOT__state),16);
        tracep->fullCData(oldp+78,(vlTOPp->top__DOT__cassette__DOT__fileType),8);
        tracep->fullCData(oldp+79,(vlTOPp->top__DOT__cassette__DOT__autorun),8);
        tracep->fullCData(oldp+80,(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH),8);
        tracep->fullCData(oldp+81,(vlTOPp->top__DOT__cassette__DOT__endAddressLOW),8);
        tracep->fullCData(oldp+82,(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH),8);
        tracep->fullCData(oldp+83,(vlTOPp->top__DOT__cassette__DOT__startAddressLOW),8);
        tracep->fullBit(oldp+84,(vlTOPp->top__DOT__cassette__DOT__unused));
        tracep->fullIData(oldp+85,(1U),32);
        tracep->fullIData(oldp+86,(2U),32);
        tracep->fullIData(oldp+87,(3U),32);
        tracep->fullIData(oldp+88,(4U),32);
        tracep->fullIData(oldp+89,(5U),32);
        tracep->fullIData(oldp+90,(6U),32);
        tracep->fullIData(oldp+91,(7U),32);
        tracep->fullIData(oldp+92,(8U),32);
        tracep->fullIData(oldp+93,(9U),32);
        tracep->fullIData(oldp+94,(0xaU),32);
    }
}
