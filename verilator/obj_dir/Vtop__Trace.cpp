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
    // Variables
    WData/*127:0*/ __Vtemp18[4];
    WData/*127:0*/ __Vtemp19[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_a));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+1,(vlTOPp->top__DOT__ram_d_temp),8);
            tracep->chgSData(oldp+2,(vlTOPp->top__DOT__tape_addr),16);
            tracep->chgBit(oldp+3,(vlTOPp->top__DOT__tape_wr));
            tracep->chgCData(oldp+4,(vlTOPp->top__DOT__tape_dout),8);
            tracep->chgBit(oldp+5,(vlTOPp->top__DOT__tape_complete));
            tracep->chgBit(oldp+6,(vlTOPp->top__DOT__tape_autorun));
            tracep->chgSData(oldp+7,(vlTOPp->top__DOT__loadpoint),16);
            tracep->chgBit(oldp+8,(vlTOPp->top__DOT__old_keystb));
            tracep->chgBit(oldp+9,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__sd_din))));
            tracep->chgCData(oldp+10,(vlTOPp->top__DOT__ram__DOT__do2),8);
            tracep->chgSData(oldp+11,(vlTOPp->top__DOT__cassette__DOT__start_addr),16);
            tracep->chgSData(oldp+12,(vlTOPp->top__DOT__cassette__DOT__end_addr),16);
            tracep->chgSData(oldp+13,(vlTOPp->top__DOT__cassette__DOT__state),16);
            tracep->chgCData(oldp+14,(vlTOPp->top__DOT__cassette__DOT__fileType),8);
            tracep->chgCData(oldp+15,(vlTOPp->top__DOT__cassette__DOT__autorun),8);
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH),8);
            tracep->chgCData(oldp+17,(vlTOPp->top__DOT__cassette__DOT__endAddressLOW),8);
            tracep->chgCData(oldp+18,(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH),8);
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__cassette__DOT__startAddressLOW),8);
            tracep->chgSData(oldp+20,(vlTOPp->top__DOT__cassette__DOT__cache_addr),16);
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__cassette__DOT__cache_dout),8);
            tracep->chgBit(oldp+22,(vlTOPp->top__DOT__cassette__DOT__cache_cs));
            tracep->chgBit(oldp+23,(vlTOPp->top__DOT__cassette__DOT__tapecache_loaded));
            tracep->chgBit(oldp+24,(vlTOPp->top__DOT__cassette__DOT__ioctl_downlD));
            tracep->chgCData(oldp+25,(vlTOPp->top__DOT____Vcellout__oricatmos__sd_din),8);
            tracep->chgCData(oldp+26,(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW),8);
            tracep->chgBit(oldp+27,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__swrst)))));
            tracep->chgBit(oldp+28,(vlTOPp->top__DOT__oricatmos__DOT__swrst));
            tracep->chgCData(oldp+29,((0xffU & (IData)(vlTOPp->top__DOT__loadpoint))),8);
            tracep->chgCData(oldp+30,(vlTOPp->top__DOT__tape_autorun),8);
            tracep->chgCData(oldp+31,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG),6);
            tracep->chgBit(oldp+32,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv));
            tracep->chgBit(oldp+33,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_t1));
            tracep->chgBit(oldp+34,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_active));
            tracep->chgBit(oldp+35,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_done));
            tracep->chgBit(oldp+36,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable));
            tracep->chgBit(oldp+37,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq));
            tracep->chgBit(oldp+38,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done));
            tracep->chgBit(oldp+39,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n));
            tracep->chgBit(oldp+40,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n));
            tracep->chgBit(oldp+41,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok));
            tracep->chgBit(oldp+42,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw0));
            tracep->chgBit(oldp+43,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw1));
            tracep->chgBit(oldp+44,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw2));
            tracep->chgBit(oldp+45,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw3));
            tracep->chgBit(oldp+46,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw4));
            tracep->chgBit(oldp+47,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw5));
            tracep->chgBit(oldp+48,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw6));
            tracep->chgBit(oldp+49,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw7));
            tracep->chgBit(oldp+50,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw8));
            tracep->chgBit(oldp+51,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw9));
            tracep->chgBit(oldp+52,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swa));
            tracep->chgBit(oldp+53,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swb));
            tracep->chgBit(oldp+54,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swc));
            tracep->chgBit(oldp+55,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swd));
            tracep->chgBit(oldp+56,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swe));
            tracep->chgBit(oldp+57,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf));
            tracep->chgBit(oldp+58,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swg));
            tracep->chgBit(oldp+59,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swh));
            tracep->chgBit(oldp+60,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swi));
            tracep->chgBit(oldp+61,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swj));
            tracep->chgBit(oldp+62,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swk));
            tracep->chgBit(oldp+63,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swl));
            tracep->chgBit(oldp+64,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swm));
            tracep->chgBit(oldp+65,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swn));
            tracep->chgBit(oldp+66,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swo));
            tracep->chgBit(oldp+67,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swp));
            tracep->chgBit(oldp+68,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swq));
            tracep->chgBit(oldp+69,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swr));
            tracep->chgBit(oldp+70,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sws));
            tracep->chgBit(oldp+71,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swt));
            tracep->chgBit(oldp+72,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swu));
            tracep->chgBit(oldp+73,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swv));
            tracep->chgBit(oldp+74,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sww));
            tracep->chgBit(oldp+75,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swx));
            tracep->chgBit(oldp+76,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swy));
            tracep->chgBit(oldp+77,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swz));
            tracep->chgBit(oldp+78,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swU));
            tracep->chgBit(oldp+79,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swD));
            tracep->chgBit(oldp+80,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swL));
            tracep->chgBit(oldp+81,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swR));
            tracep->chgBit(oldp+82,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrs));
            tracep->chgBit(oldp+83,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swls));
            tracep->chgBit(oldp+84,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsp));
            tracep->chgBit(oldp+85,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swcom));
            tracep->chgBit(oldp+86,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdot));
            tracep->chgBit(oldp+87,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swret));
            tracep->chgBit(oldp+88,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfs));
            tracep->chgBit(oldp+89,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sweq));
            tracep->chgBit(oldp+90,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfcn));
            tracep->chgBit(oldp+91,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel));
            tracep->chgBit(oldp+92,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrsb));
            tracep->chgBit(oldp+93,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swlsb));
            tracep->chgBit(oldp+94,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swbs));
            tracep->chgBit(oldp+95,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdsh));
            tracep->chgBit(oldp+96,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsq));
            tracep->chgBit(oldp+97,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsc));
            tracep->chgBit(oldp+98,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swesc));
            tracep->chgBit(oldp+99,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swctl));
            tracep->chgBit(oldp+100,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf1));
            tracep->chgBit(oldp+101,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf2));
            tracep->chgBit(oldp+102,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf3));
            tracep->chgBit(oldp+103,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf4));
            tracep->chgBit(oldp+104,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf5));
            tracep->chgBit(oldp+105,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf6));
            tracep->chgBit(oldp+106,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inROMDIS));
            tracep->chgCData(oldp+107,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DSEL),2);
            tracep->chgBit(oldp+108,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__nROMEN));
            tracep->chgCData(oldp+109,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout),8);
            tracep->chgBit(oldp+110,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_index));
            tracep->chgSData(oldp+111,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size),11);
            tracep->chgIData(oldp+112,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt),32);
            tracep->chgCData(oldp+113,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos),8);
            tracep->chgCData(oldp+114,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsize),8);
            tracep->chgBit(oldp+115,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_active));
            tracep->chgBit(oldp+116,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_wr));
            tracep->chgCData(oldp+117,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track),7);
            tracep->chgBit(oldp+118,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side));
            tracep->chgCData(oldp+119,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector),8);
            tracep->chgCData(oldp+120,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode),2);
            tracep->chgCData(oldp+121,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors),8);
            tracep->chgSData(oldp+122,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size),16);
            tracep->chgSData(oldp+123,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos),16);
            tracep->chgIData(oldp+124,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset),20);
            tracep->chgIData(oldp+125,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1),20);
            tracep->chgCData(oldp+126,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo),8);
            tracep->chgSData(oldp+127,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos),11);
            tracep->chgCData(oldp+128,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf),8);
            tracep->chgCData(oldp+129,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+130,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_A))));
            tracep->chgBit(oldp+131,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_B))));
            tracep->chgBit(oldp+132,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_C))));
            tracep->chgBit(oldp+133,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT))));
            tracep->chgCData(oldp+134,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_A),8);
            tracep->chgCData(oldp+135,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_B),8);
            tracep->chgCData(oldp+136,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_C),8);
            tracep->chgSData(oldp+137,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT),10);
            tracep->chgCData(oldp+138,(vlTOPp->top__DOT__oricatmos__DOT__via_pa_in_from_psg),8);
            tracep->chgBit(oldp+139,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_step));
            tracep->chgBit(oldp+140,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_restart));
            tracep->chgCData(oldp+141,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc_st),4);
            tracep->chgSData(oldp+142,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc),10);
            tracep->chgBit(oldp+143,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__last_write));
            tracep->chgSData(oldp+144,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chA__DOT__count),12);
            tracep->chgSData(oldp+145,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chB__DOT__count),12);
            tracep->chgSData(oldp+146,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chC__DOT__count),12);
            tracep->chgBit(oldp+147,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__noise_en));
            tracep->chgBit(oldp+148,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__last_en));
            tracep->chgBit(oldp+149,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__noise_en) 
                                      & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__last_en)))));
            tracep->chgCData(oldp+150,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__u_div__DOT__count),5);
            tracep->chgSData(oldp+151,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_envdiv__DOT__count),16);
            tracep->chgBit(oldp+152,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__stop));
            tracep->chgBit(oldp+153,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__last_step));
            tracep->chgBit(oldp+154,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_clr));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+155,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__EF_i));
            tracep->chgBit(oldp+156,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MF_i));
            tracep->chgBit(oldp+157,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__XF_i));
            tracep->chgBit(oldp+158,((0U != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To_r))));
            tracep->chgCData(oldp+159,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC))),8);
            tracep->chgCData(oldp+160,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__X))),8);
            tracep->chgCData(oldp+161,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Y))),8);
            tracep->chgCData(oldp+162,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__S))),8);
            tracep->chgSData(oldp+163,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC),16);
            tracep->chgSData(oldp+164,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__X),16);
            tracep->chgSData(oldp+165,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Y),16);
            tracep->chgCData(oldp+166,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__AD),8);
            tracep->chgCData(oldp+167,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DL),8);
            tracep->chgCData(oldp+168,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAH),8);
            tracep->chgSData(oldp+169,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAL),9);
            tracep->chgCData(oldp+170,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PBR),8);
            tracep->chgCData(oldp+171,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DBR),8);
            tracep->chgSData(oldp+172,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PC),16);
            tracep->chgSData(oldp+173,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__S),16);
            tracep->chgCData(oldp+174,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Mode_r),2);
            tracep->chgCData(oldp+175,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op_r),5);
            tracep->chgCData(oldp+176,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data_r),4);
            tracep->chgCData(oldp+177,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To_r),2);
            tracep->chgBit(oldp+178,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__SO_n_o));
            tracep->chgCData(oldp+179,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA_r),8);
            tracep->chgCData(oldp+180,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB),8);
            tracep->chgCData(oldp+181,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB_r),8);
            tracep->chgBit(oldp+182,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__rdy_mod));
            tracep->chgCData(oldp+183,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__xhdl0__DOT__tmpP),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+184,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq)))));
            tracep->chgCData(oldp+185,((0xffU & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddra)))),8);
            tracep->chgBit(oldp+186,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_oe_l));
            tracep->chgBit(oldp+187,(vlTOPp->top__DOT__oricatmos__DOT__via_cb2_oe_l));
            tracep->chgBit(oldp+188,(vlTOPp->top__DOT__oricatmos__DOT__OPEN));
            tracep->chgBit(oldp+189,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH) 
                                            >> 4U))));
            tracep->chgCData(oldp+190,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH),5);
            tracep->chgBit(oldp+191,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv_hold));
            tracep->chgCData(oldp+192,((0xffU & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddrb)))),8);
            tracep->chgCData(oldp+193,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddra),8);
            tracep->chgCData(oldp+194,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ira),8);
            tracep->chgCData(oldp+195,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddrb),8);
            tracep->chgCData(oldp+196,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_orb),8);
            tracep->chgCData(oldp+197,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_irb),8);
            tracep->chgCData(oldp+198,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_l),8);
            tracep->chgCData(oldp+199,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_h),8);
            tracep->chgCData(oldp+200,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ier),7);
            tracep->chgBit(oldp+201,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ifr_write_ena));
            tracep->chgBit(oldp+202,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ier_write_ena));
            tracep->chgBit(oldp+203,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7));
            tracep->chgBit(oldp+204,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_w_reset_int));
            tracep->chgBit(oldp+205,((1U & ((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_oe_l)) 
                                            | (IData)(vlTOPp->top__DOT__tape_adc)))));
            tracep->chgBit(oldp+206,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_c));
            tracep->chgBit(oldp+207,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_d));
            tracep->chgBit(oldp+208,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_c));
            tracep->chgBit(oldp+209,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_d));
            tracep->chgBit(oldp+210,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_irq));
            tracep->chgBit(oldp+211,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_irq));
            tracep->chgBit(oldp+212,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_c));
            tracep->chgBit(oldp+213,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_d));
            tracep->chgBit(oldp+214,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_c));
            tracep->chgBit(oldp+215,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_d));
            tracep->chgBit(oldp+216,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_irq));
            tracep->chgBit(oldp+217,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_irq));
            tracep->chgBit(oldp+218,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq));
            tracep->chgBit(oldp+219,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_op));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgBit(oldp+220,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE) 
                                            >> 2U))));
            tracep->chgBit(oldp+221,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE) 
                                            >> 1U))));
            tracep->chgCData(oldp+222,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_INK),3);
            tracep->chgCData(oldp+223,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_PAPER),3);
            tracep->chgCData(oldp+224,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgBit(oldp+225,(vlTOPp->top__DOT__fdd_ready));
            tracep->chgBit(oldp+226,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active));
            tracep->chgBit(oldp+227,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active)
                                             ? (0x7ffU 
                                                & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                   >> 9U))
                                             : ((0x7ffU 
                                                 & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a 
                                                    >> 9U)) 
                                                + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block))))));
            tracep->chgBit(oldp+228,(vlTOPp->top__DOT__sd_rd));
            tracep->chgBit(oldp+229,(vlTOPp->top__DOT__sd_wr));
            tracep->chgIData(oldp+230,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active)
                                         ? (0x7ffU 
                                            & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                               >> 9U))
                                         : ((0x7ffU 
                                             & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a 
                                                >> 9U)) 
                                            + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block)))),32);
            tracep->chgCData(oldp+231,(vlTOPp->top__DOT__oricatmos__DOT__cpu_di),8);
            tracep->chgBit(oldp+232,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen16));
            tracep->chgCData(oldp+233,(vlTOPp->top__DOT__oricatmos__DOT__ROM_ATMOS_DO),8);
            tracep->chgCData(oldp+234,(vlTOPp->top__DOT__oricatmos__DOT__ROM_1_DO),8);
            tracep->chgCData(oldp+235,(vlTOPp->top__DOT__oricatmos__DOT__ROM_MD_DO),8);
            tracep->chgBit(oldp+236,(vlTOPp->top__DOT__oricatmos__DOT__cont_ROMDISn));
            tracep->chgBit(oldp+237,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq) 
                                               & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN))))));
            tracep->chgSData(oldp+238,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c),16);
            tracep->chgBit(oldp+239,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c_active));
            tracep->chgBit(oldp+240,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c_done));
            tracep->chgBit(oldp+241,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_reload_counter));
            tracep->chgBit(oldp+242,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable));
            tracep->chgBit(oldp+243,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_toggle));
            tracep->chgBit(oldp+244,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_irq));
            tracep->chgBit(oldp+245,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_c));
            tracep->chgBit(oldp+246,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_d));
            tracep->chgBit(oldp+247,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer1_done__DOT__done));
            tracep->chgCData(oldp+248,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr),4);
            tracep->chgCData(oldp+249,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__din_latch),8);
            tracep->chgCData(oldp+250,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__envelope),5);
            tracep->chgBit(oldp+251,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__noise));
            tracep->chgBit(oldp+252,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Amix));
            tracep->chgBit(oldp+253,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Bmix));
            tracep->chgBit(oldp+254,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Cmix));
            tracep->chgBit(oldp+255,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen256));
            tracep->chgCData(oldp+256,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logA),5);
            tracep->chgCData(oldp+257,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logB),5);
            tracep->chgCData(oldp+258,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logC),5);
            tracep->chgCData(oldp+259,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__lin),8);
            tracep->chgCData(oldp+260,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__read_mask),8);
            tracep->chgBit(oldp+261,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__write));
            tracep->chgBit(oldp+262,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch));
            tracep->chgBit(oldp+263,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy) 
                                            >> 1U))));
            tracep->chgBit(oldp+264,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq));
            tracep->chgBit(oldp+265,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__SSEL));
            tracep->chgBit(oldp+266,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN));
            tracep->chgBit(oldp+267,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy))));
            tracep->chgIData(oldp+268,((0xfffffU & 
                                        ((0xffe00U 
                                          & vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a) 
                                         + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr)))),20);
            tracep->chgCData(oldp+269,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_size_code),2);
            tracep->chgCData(oldp+270,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sectors_per_track),8);
            tracep->chgCData(oldp+271,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_spt),8);
            tracep->chgSData(oldp+272,((0x7ffU & ((IData)(0x80U) 
                                                  << (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_size_code)))),11);
            tracep->chgSData(oldp+273,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr),11);
            tracep->chgIData(oldp+274,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a),20);
            tracep->chgCData(oldp+275,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block),2);
            tracep->chgBit(oldp+276,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__format));
            tracep->chgBit(oldp+277,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_crcerr));
            tracep->chgBit(oldp+278,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_headloaded));
            tracep->chgBit(oldp+279,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_seekerr));
            tracep->chgBit(oldp+280,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_lostdata));
            tracep->chgBit(oldp+281,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wrfault));
            tracep->chgBit(oldp+282,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__cmd_mode));
            tracep->chgBit(oldp+283,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wpe));
            tracep->chgCData(oldp+284,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy),2);
            tracep->chgCData(oldp+285,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_track),8);
            tracep->chgCData(oldp+286,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector),8);
            tracep->chgCData(oldp+287,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data),8);
            tracep->chgCData(oldp+288,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track),8);
            tracep->chgCData(oldp+289,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[0]),8);
            tracep->chgCData(oldp+290,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[1]),8);
            tracep->chgCData(oldp+291,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[2]),8);
            tracep->chgCData(oldp+292,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[3]),8);
            tracep->chgCData(oldp+293,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[4]),8);
            tracep->chgCData(oldp+294,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[5]),8);
            tracep->chgBit(oldp+295,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size));
            tracep->chgIData(oldp+296,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_size),20);
            tracep->chgBit(oldp+297,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__layout_r));
            tracep->chgIData(oldp+298,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__hs),20);
            tracep->chgCData(oldp+299,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__dts),8);
            tracep->chgBit(oldp+300,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_rd));
            tracep->chgBit(oldp+301,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__step_direction));
            tracep->chgSData(oldp+302,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__data_length),11);
            tracep->chgIData(oldp+303,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state),32);
            tracep->chgSData(oldp+304,((0x7ffU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__data_length) 
                                                  - (IData)(1U)))),11);
            tracep->chgBit(oldp+305,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__watchdog_set));
            tracep->chgSData(oldp+306,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer),16);
            tracep->chgBit(oldp+307,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer))));
            tracep->chgIData(oldp+308,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr),20);
            tracep->chgBit(oldp+309,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr));
            tracep->chgCData(oldp+310,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sizecode),2);
            tracep->chgBit(oldp+311,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_side));
            tracep->chgCData(oldp+312,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_track),7);
            tracep->chgCData(oldp+313,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sector),8);
            tracep->chgIData(oldp+314,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_offset),20);
            tracep->chgCData(oldp+315,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_trackf),8);
            tracep->chgCData(oldp+316,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sidef),8);
            tracep->chgSData(oldp+317,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr),11);
            tracep->chgSData(oldp+318,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_start),11);
            tracep->chgSData(oldp+319,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_next),11);
            tracep->chgCData(oldp+320,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size),8);
            tracep->chgBit(oldp+321,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_wr));
            tracep->chgCData(oldp+322,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__blk_size),2);
            tracep->chgCData(oldp+323,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr),8);
            tracep->chgBit(oldp+324,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_wr));
            tracep->chgBit(oldp+325,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_rd));
            tracep->chgCData(oldp+326,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr),3);
            tracep->chgBit(oldp+327,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data));
            tracep->chgBit(oldp+328,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data));
            tracep->chgBit(oldp+329,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__rw_type));
            tracep->chgIData(oldp+330,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time),32);
            tracep->chgCData(oldp+331,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer),4);
            tracep->chgSData(oldp+332,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer),10);
            tracep->chgCData(oldp+333,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector),8);
            tracep->chgBit(oldp+334,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector));
            tracep->chgBit(oldp+335,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write));
            tracep->chgCData(oldp+336,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack),6);
            tracep->chgBit(oldp+337,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy));
            tracep->chgBit(oldp+338,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_mounted));
            tracep->chgCData(oldp+339,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state),4);
            tracep->chgCData(oldp+340,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt),2);
            tracep->chgCData(oldp+341,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max),2);
            __Vtemp18[0U] = 0x2044534bU;
            __Vtemp18[1U] = 0x20435043U;
            __Vtemp18[2U] = 0x4e444544U;
            __Vtemp18[3U] = 0x45585445U;
            VL_SHIFTR_WWI(128,128,8, __Vtemp19, __Vtemp18, 
                          (0xffU & ((IData)(0x78U) 
                                    - (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                       << 3U))));
            tracep->chgWData(oldp+342,(__Vtemp19),128);
            tracep->chgSData(oldp+346,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_a),11);
            tracep->chgSData(oldp+347,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_b),11);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[7U])) {
            tracep->chgBit(oldp+348,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                            >> 7U))));
            tracep->chgBit(oldp+349,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                            >> 6U))));
            tracep->chgCData(oldp+350,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ora),8);
            tracep->chgBit(oldp+351,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_out));
            tracep->chgBit(oldp+352,(vlTOPp->top__DOT__oricatmos__DOT__via_cb2_out));
            tracep->chgCData(oldp+353,(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out),8);
            tracep->chgBit(oldp+354,(vlTOPp->top__DOT__oricatmos__DOT__psg_bdir));
            tracep->chgBit(oldp+355,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                            >> 4U))));
            tracep->chgBit(oldp+356,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib));
            tracep->chgCData(oldp+357,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREGHOLD),7);
            tracep->chgCData(oldp+358,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_sr),8);
            tracep->chgCData(oldp+359,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_pcr),8);
            tracep->chgCData(oldp+360,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ifr),8);
            tracep->chgBit(oldp+361,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_write_ena));
            tracep->chgCData(oldp+362,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__clear_irq),8);
            tracep->chgCData(oldp+363,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__load_data),8);
            tracep->chgBit(oldp+364,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_w_reset_int));
            tracep->chgBit(oldp+365,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_load_counter));
            tracep->chgCData(oldp+366,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cnt),4);
            tracep->chgBit(oldp+367,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_drive_cb2));
            tracep->chgBit(oldp+368,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_do_shift));
            tracep->chgBit(oldp+369,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_irq));
            tracep->chgBit(oldp+370,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_out));
            tracep->chgBit(oldp+371,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_active));
            tracep->chgBit(oldp+372,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__w_orb_hs));
            tracep->chgBit(oldp+373,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__w_ora_hs));
            tracep->chgBit(oldp+374,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_sr));
            tracep->chgBit(oldp+375,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_pulse));
            tracep->chgBit(oldp+376,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_sr));
            tracep->chgBit(oldp+377,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_pulse));
            tracep->chgBit(oldp+378,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_int));
            tracep->chgBit(oldp+379,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_int));
            tracep->chgBit(oldp+380,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_int));
            tracep->chgBit(oldp+381,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_int));
            tracep->chgBit(oldp+382,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__dir_out));
            tracep->chgBit(oldp+383,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__ena));
            tracep->chgBit(oldp+384,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_ip));
            tracep->chgBit(oldp+385,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__use_t2));
            tracep->chgBit(oldp+386,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__free_run));
            tracep->chgBit(oldp+387,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__sr_count_ena));
            tracep->chgCData(oldp+388,((7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[8U])) {
            tracep->chgCData(oldp+389,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                       [0xeU]),8);
            tracep->chgCData(oldp+390,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                       [0xfU]),8);
            tracep->chgCData(oldp+391,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[0]),8);
            tracep->chgCData(oldp+392,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[1]),8);
            tracep->chgCData(oldp+393,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[2]),8);
            tracep->chgCData(oldp+394,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[3]),8);
            tracep->chgCData(oldp+395,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[4]),8);
            tracep->chgCData(oldp+396,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[5]),8);
            tracep->chgCData(oldp+397,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[6]),8);
            tracep->chgCData(oldp+398,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[7]),8);
            tracep->chgCData(oldp+399,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[8]),8);
            tracep->chgCData(oldp+400,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[9]),8);
            tracep->chgCData(oldp+401,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[10]),8);
            tracep->chgCData(oldp+402,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[11]),8);
            tracep->chgCData(oldp+403,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[12]),8);
            tracep->chgCData(oldp+404,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[13]),8);
            tracep->chgCData(oldp+405,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[14]),8);
            tracep->chgCData(oldp+406,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[15]),8);
            tracep->chgCData(oldp+407,(((0x40U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [7U]) ? vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [0xeU] : 0U)),8);
            tracep->chgCData(oldp+408,(((0x80U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [7U]) ? vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [0xfU] : 0U)),8);
            tracep->chgBit(oldp+409,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitA));
            tracep->chgBit(oldp+410,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitB));
            tracep->chgBit(oldp+411,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitC));
            tracep->chgSData(oldp+412,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period),16);
            tracep->chgBit(oldp+413,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period))));
            tracep->chgCData(oldp+414,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__log),5);
            tracep->chgCData(oldp+415,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                  [8U] 
                                                  << 1U)) 
                                        | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                 [8U] 
                                                 >> 3U)))),5);
            tracep->chgCData(oldp+416,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                  [9U] 
                                                  << 1U)) 
                                        | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                 [9U] 
                                                 >> 3U)))),5);
            tracep->chgCData(oldp+417,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                  [0xaU] 
                                                  << 1U)) 
                                        | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                 [0xaU] 
                                                 >> 3U)))),5);
            tracep->chgBit(oldp+418,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [8U] >> 4U))));
            tracep->chgBit(oldp+419,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [9U] >> 4U))));
            tracep->chgBit(oldp+420,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [0xaU] 
                                            >> 4U))));
            tracep->chgBit(oldp+421,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [7U] >> 3U))));
            tracep->chgBit(oldp+422,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [7U] >> 4U))));
            tracep->chgBit(oldp+423,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [7U] >> 5U))));
            tracep->chgSData(oldp+424,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt),10);
            tracep->chgBit(oldp+425,((1U & (~ (IData)(
                                                      (0U 
                                                       != 
                                                       (7U 
                                                        & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt))))))));
            tracep->chgBit(oldp+426,((1U & (~ (IData)(
                                                      (0U 
                                                       != 
                                                       (3U 
                                                        & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt))))))));
            tracep->chgSData(oldp+427,(((0xf00U & (
                                                   vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                   [1U] 
                                                   << 8U)) 
                                        | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [0U])),12);
            tracep->chgSData(oldp+428,(((0xf00U & (
                                                   vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                   [3U] 
                                                   << 8U)) 
                                        | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [2U])),12);
            tracep->chgSData(oldp+429,(((0xf00U & (
                                                   vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                   [5U] 
                                                   << 8U)) 
                                        | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [4U])),12);
            tracep->chgCData(oldp+430,((0x1fU & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [6U])),5);
            tracep->chgIData(oldp+431,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17),17);
            tracep->chgBit(oldp+432,((0U == vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17)));
            tracep->chgCData(oldp+433,((0xfU & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                        [0xdU])),4);
            tracep->chgBit(oldp+434,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__inv));
            tracep->chgCData(oldp+435,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__gain),5);
            tracep->chgBit(oldp+436,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [0xdU] 
                                            >> 3U))));
            tracep->chgBit(oldp+437,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [0xdU] 
                                            >> 2U))));
            tracep->chgBit(oldp+438,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [0xdU] 
                                            >> 1U))));
            tracep->chgBit(oldp+439,((1U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                      [0xdU])));
            tracep->chgBit(oldp+440,((1U & ((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [0xdU] 
                                                >> 3U)) 
                                            | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                            [0xdU]))));
            tracep->chgBit(oldp+441,((1U & (((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                 [0xdU] 
                                                 >> 3U)) 
                                             & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [0xdU] 
                                                >> 2U)) 
                                            | ((vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [0xdU] 
                                                >> 3U) 
                                               & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                  [0xdU] 
                                                  >> 1U))))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[9U])) {
            tracep->chgBit(oldp+442,(vlTOPp->top__DOT__key_strobe));
            tracep->chgBit(oldp+443,(vlTOPp->top__DOT__oricatmos__DOT__RESETn));
            tracep->chgBit(oldp+444,(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET));
            tracep->chgBit(oldp+445,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn)))));
            tracep->chgBit(oldp+446,(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n));
            tracep->chgBit(oldp+447,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET)))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xaU])) {
            tracep->chgSData(oldp+448,(vlTOPp->top__DOT__ram_ad_temp),16);
            tracep->chgBit(oldp+449,(vlTOPp->top__DOT__ram_we_temp));
            tracep->chgBit(oldp+450,(vlTOPp->top__DOT__ram_cs_temp));
            tracep->chgCData(oldp+451,(vlTOPp->top__DOT__ram_q),8);
            tracep->chgSData(oldp+452,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__AD_RAM_INT),16);
            tracep->chgCData(oldp+453,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS),8);
            tracep->chgCData(oldp+454,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase),2);
            tracep->chgBit(oldp+455,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_dl));
            tracep->chgSData(oldp+456,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c),16);
            tracep->chgBit(oldp+457,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6));
            tracep->chgBit(oldp+458,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6_t1));
            tracep->chgBit(oldp+459,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_cnt_clk));
            tracep->chgBit(oldp+460,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_reload_counter));
            tracep->chgBit(oldp+461,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_sr_ena));
            tracep->chgBit(oldp+462,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_t1));
            tracep->chgBit(oldp+463,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_falling));
            tracep->chgBit(oldp+464,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_rising));
            tracep->chgBit(oldp+465,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done_sr));
            tracep->chgBit(oldp+466,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2__DOT__ena));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xbU])) {
            tracep->chgBit(oldp+467,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                            >> 2U))));
            tracep->chgBit(oldp+468,((0xc7U < (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))));
            tracep->chgBit(oldp+469,((1U & (~ ((0x31U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)) 
                                               & (0x35U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))))));
            tracep->chgBit(oldp+470,((1U & (~ ((0x102U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                               & (0x103U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))))));
            tracep->chgBit(oldp+471,((1U & (~ ((0xf1U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                               & (0xf2U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))))));
            tracep->chgBit(oldp+472,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__BLANKINGn));
            tracep->chgBit(oldp+473,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL));
            tracep->chgCData(oldp+474,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H),7);
            tracep->chgSData(oldp+475,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V),9);
            tracep->chgCData(oldp+476,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph),3);
            tracep->chgBit(oldp+477,((0xe0U > (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))));
            tracep->chgBit(oldp+478,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lHBLANKn));
            tracep->chgCData(oldp+479,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_l),8);
            tracep->chgCData(oldp+480,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_h),8);
            tracep->chgCData(oldp+481,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_acr),8);
            tracep->chgBit(oldp+482,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_load_counter));
            tracep->chgBit(oldp+483,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xcU])) {
            tracep->chgBit(oldp+484,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT))));
            tracep->chgBit(oldp+485,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT) 
                                            >> 1U))));
            tracep->chgBit(oldp+486,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT) 
                                            >> 2U))));
            tracep->chgBit(oldp+487,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC));
            tracep->chgBit(oldp+488,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                            >> 1U))));
            tracep->chgBit(oldp+489,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE))));
            tracep->chgCData(oldp+490,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT),3);
            tracep->chgBit(oldp+491,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                             >> 1U) 
                                            & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))))));
            tracep->chgSData(oldp+492,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8),9);
            tracep->chgSData(oldp+493,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC)
                                         ? 0xa000U : 0xbb80U)),16);
            tracep->chgSData(oldp+494,((0x7fffU & (
                                                   (0x7fe0U 
                                                    & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                       << 5U)) 
                                                   + 
                                                   ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                    << 3U)))),15);
            tracep->chgCData(oldp+495,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lRGB),3);
            tracep->chgCData(oldp+496,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE),3);
            tracep->chgCData(oldp+497,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle),2);
            tracep->chgCData(oldp+498,(((3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                         ? 0x27U : 
                                        ((2U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                          ? 0x26U : 
                                         ((1U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                           ? 0x2eU : 0x2dU)))),6);
            tracep->chgBit(oldp+499,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                            >> 2U))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xdU])) {
            tracep->chgCData(oldp+500,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r),8);
            tracep->chgIData(oldp+501,(vlTOPp->top__DOT__oricatmos__DOT__cpu_ad),24);
            tracep->chgBit(oldp+502,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i));
            tracep->chgBit(oldp+503,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inECE));
            tracep->chgBit(oldp+504,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle))));
            tracep->chgBit(oldp+505,((1U & (~ (((2U 
                                                 != 
                                                 (3U 
                                                  & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                     >> 6U))) 
                                                & (3U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                       >> 1U)))) 
                                               & (0U 
                                                  != 
                                                  (3U 
                                                   & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle) 
                                                      >> 1U))))))));
            tracep->chgBit(oldp+506,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle) 
                                               & ((5U 
                                                   == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle)) 
                                                  | (6U 
                                                     == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle))))))));
            tracep->chgBit(oldp+507,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Jump) 
                                               >> 1U)))));
            tracep->chgCData(oldp+508,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR),8);
            tracep->chgCData(oldp+509,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P),8);
            tracep->chgBit(oldp+510,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMIAct));
            tracep->chgCData(oldp+511,((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle) 
                                         | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMICycle))
                                         ? (0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P))
                                         : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P))),8);
            tracep->chgCData(oldp+512,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle),3);
            tracep->chgSData(oldp+513,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdder),9);
            tracep->chgBit(oldp+514,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__RstCycle));
            tracep->chgBit(oldp+515,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle));
            tracep->chgBit(oldp+516,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMICycle));
            tracep->chgBit(oldp+517,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQ_n_o));
            tracep->chgBit(oldp+518,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_n_o));
            tracep->chgBit(oldp+519,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Break));
            tracep->chgCData(oldp+520,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA),8);
            tracep->chgCData(oldp+521,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Q),8);
            tracep->chgCData(oldp+522,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P_Out),8);
            tracep->chgCData(oldp+523,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LCycle),3);
            tracep->chgCData(oldp+524,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op),5);
            tracep->chgCData(oldp+525,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_BusA_To),4);
            tracep->chgCData(oldp+526,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To),2);
            tracep->chgCData(oldp+527,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data),4);
            tracep->chgCData(oldp+528,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Jump),2);
            tracep->chgCData(oldp+529,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAAdd),2);
            tracep->chgCData(oldp+530,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAQuirk),2);
            tracep->chgBit(oldp+531,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BreakAtNA));
            tracep->chgBit(oldp+532,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ADAdd));
            tracep->chgBit(oldp+533,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__AddY));
            tracep->chgBit(oldp+534,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdd));
            tracep->chgBit(oldp+535,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Inc_S));
            tracep->chgBit(oldp+536,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Dec_S));
            tracep->chgBit(oldp+537,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDA));
            tracep->chgBit(oldp+538,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDP));
            tracep->chgBit(oldp+539,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDX));
            tracep->chgBit(oldp+540,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDY));
            tracep->chgBit(oldp+541,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDS));
            tracep->chgBit(oldp+542,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDDI));
            tracep->chgBit(oldp+543,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDALU));
            tracep->chgBit(oldp+544,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDAD));
            tracep->chgBit(oldp+545,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAL));
            tracep->chgBit(oldp+546,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAH));
            tracep->chgBit(oldp+547,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__SaveP));
            tracep->chgBit(oldp+548,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write));
            tracep->chgBit(oldp+549,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_entered));
            tracep->chgBit(oldp+550,((1U & ((0U == 
                                             (7U & 
                                              ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                               >> 5U)))
                                             ? (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                   >> 7U))
                                             : ((1U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                     >> 5U)))
                                                 ? 
                                                ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                 >> 7U)
                                                 : 
                                                ((2U 
                                                  == 
                                                  (7U 
                                                   & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                      >> 5U)))
                                                  ? 
                                                 (~ 
                                                  ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                   >> 6U))
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                       >> 5U)))
                                                   ? 
                                                  ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                   >> 6U)
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                        >> 5U)))
                                                    ? 
                                                   (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P))
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                         >> 5U)))
                                                     ? (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P)
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                          >> 5U)))
                                                      ? 
                                                     (~ 
                                                      ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                       >> 1U))
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                      >> 1U)))))))))));
            tracep->chgBit(oldp+551,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__mcode__DOT__ALUmore));
            tracep->chgBit(oldp+552,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Z));
            tracep->chgBit(oldp+553,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_C));
            tracep->chgBit(oldp+554,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_V));
            tracep->chgBit(oldp+555,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_N));
            tracep->chgCData(oldp+556,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Q),8);
            tracep->chgBit(oldp+557,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Z));
            tracep->chgBit(oldp+558,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_C));
            tracep->chgBit(oldp+559,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_V));
            tracep->chgBit(oldp+560,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_N));
            tracep->chgCData(oldp+561,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Q),8);
            tracep->chgCData(oldp+562,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBX_Q),8);
            tracep->chgCData(oldp+563,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AL),7);
            tracep->chgCData(oldp+564,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AH),7);
            tracep->chgBit(oldp+565,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__C));
            tracep->chgCData(oldp+566,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AL),7);
            tracep->chgCData(oldp+567,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AH),6);
            tracep->chgBit(oldp+568,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__C));
            tracep->chgBit(oldp+569,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__CT));
            tracep->chgCData(oldp+570,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q_t),8);
            tracep->chgCData(oldp+571,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q2_t),8);
            tracep->chgSData(oldp+572,((0x3fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),14);
            tracep->chgSData(oldp+573,((0x1fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),13);
            tracep->chgSData(oldp+574,((0xffffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),16);
            tracep->chgCData(oldp+575,((0xfU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),4);
            tracep->chgCData(oldp+576,((3U & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),2);
            tracep->chgCData(oldp+577,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__q),8);
            tracep->chgBit(oldp+578,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__u16k));
            tracep->chgCData(oldp+579,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__next_track),8);
            tracep->chgCData(oldp+580,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__data_b),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xeU])) {
            tracep->chgBit(oldp+581,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT));
            tracep->chgBit(oldp+582,((1U & (((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                 >> 4U)) 
                                             & (~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                   >> 0xcU))) 
                                            & (~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                  >> 0x14U))))));
            tracep->chgBit(oldp+583,(((((0U != (7U 
                                                & vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c)) 
                                        | (0U != (7U 
                                                  & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                     >> 6U)))) 
                                       | (0U != (7U 
                                                 & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                    >> 0xcU)))) 
                                      | (0U != (7U 
                                                & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                   >> 0x12U))))));
            tracep->chgBit(oldp+584,(vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en));
            tracep->chgBit(oldp+585,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                            >> 0xfU))));
            tracep->chgBit(oldp+586,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                            >> 3U))));
            tracep->chgBit(oldp+587,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                            >> 0x11U))));
            tracep->chgBit(oldp+588,((1U & ((vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                             >> 2U) 
                                            | (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                               >> 0xaU)))));
            tracep->chgIData(oldp+589,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c),24);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0xfU])) {
            tracep->chgCData(oldp+590,(vlTOPp->top__DOT__oricatmos__DOT__VIA_DO),8);
            tracep->chgBit(oldp+591,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT));
            tracep->chgBit(oldp+592,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT));
            tracep->chgBit(oldp+593,(vlTOPp->top__DOT__oricatmos__DOT__cont_MAPn));
            tracep->chgBit(oldp+594,(vlTOPp->top__DOT__oricatmos__DOT__cont_IOCONTROLn));
            tracep->chgBit(oldp+595,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__O_DATA_OE_L));
            tracep->chgBit(oldp+596,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cs));
            tracep->chgBit(oldp+597,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_read_ena));
            tracep->chgBit(oldp+598,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_r_reset_int));
            tracep->chgBit(oldp+599,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_r_reset_int));
            tracep->chgBit(oldp+600,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_irb_hs));
            tracep->chgBit(oldp+601,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ira_hs));
            tracep->chgCData(oldp+602,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__orb),8);
            tracep->chgBit(oldp+603,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nCS));
            tracep->chgBit(oldp+604,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nRE));
            tracep->chgBit(oldp+605,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel));
            tracep->chgBit(oldp+606,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nCS)))));
            tracep->chgBit(oldp+607,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nRE)))));
            tracep->chgBit(oldp+608,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__rde));
            tracep->chgBit(oldp+609,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wre));
            tracep->chgBit(oldp+610,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_b));
        }
        tracep->chgBit(oldp+611,(vlTOPp->clk_48));
        tracep->chgBit(oldp+612,(vlTOPp->reset));
        tracep->chgSData(oldp+613,(vlTOPp->inputs),12);
        tracep->chgCData(oldp+614,(vlTOPp->VGA_R),8);
        tracep->chgCData(oldp+615,(vlTOPp->VGA_G),8);
        tracep->chgCData(oldp+616,(vlTOPp->VGA_B),8);
        tracep->chgBit(oldp+617,(vlTOPp->VGA_HS));
        tracep->chgBit(oldp+618,(vlTOPp->VGA_VS));
        tracep->chgBit(oldp+619,(vlTOPp->VGA_HB));
        tracep->chgBit(oldp+620,(vlTOPp->VGA_VB));
        tracep->chgSData(oldp+621,(vlTOPp->AUDIO_L),16);
        tracep->chgSData(oldp+622,(vlTOPp->AUDIO_R),16);
        tracep->chgBit(oldp+623,(vlTOPp->ioctl_download));
        tracep->chgBit(oldp+624,(vlTOPp->ioctl_upload));
        tracep->chgBit(oldp+625,(vlTOPp->ioctl_wr));
        tracep->chgIData(oldp+626,(vlTOPp->ioctl_addr),25);
        tracep->chgCData(oldp+627,(vlTOPp->ioctl_dout),8);
        tracep->chgCData(oldp+628,(vlTOPp->ioctl_din),8);
        tracep->chgCData(oldp+629,(vlTOPp->ioctl_index),8);
        tracep->chgSData(oldp+630,(vlTOPp->ps2_key),11);
        tracep->chgBit(oldp+631,(vlTOPp->ioctl_wait));
        tracep->chgBit(oldp+632,(vlTOPp->ce_pix));
        tracep->chgSData(oldp+633,((0xffffU & ((4U 
                                                & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph))
                                                ? vlTOPp->top__DOT__oricatmos__DOT__cpu_ad
                                                : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__AD_RAM_INT)))),16);
        tracep->chgBit(oldp+634,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                  & (((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)) 
                                      & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))) 
                                     & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                        >> 0x11U)))));
        tracep->chgBit(oldp+635,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                  & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                      | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         >> 1U)) | 
                                     (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                       >> 2U) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)))))));
        tracep->chgBit(oldp+636,((1U & (~ (IData)(vlTOPp->reset)))));
        tracep->chgSData(oldp+637,((0xffffU & vlTOPp->ioctl_addr)),16);
        tracep->chgBit(oldp+638,((1U & ((IData)(vlTOPp->ps2_key) 
                                        >> 9U))));
        tracep->chgBit(oldp+639,((1U & ((IData)(vlTOPp->ps2_key) 
                                        >> 8U))));
        tracep->chgCData(oldp+640,((0xffU & (IData)(vlTOPp->ps2_key))),8);
        tracep->chgBit(oldp+641,((1U & (~ ((~ ((0x31U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)) 
                                               & (0x35U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))) 
                                           ^ ((2U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE))
                                               ? (~ 
                                                  ((0x102U 
                                                    <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                                   & (0x103U 
                                                      >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))
                                               : (~ 
                                                  ((0xf1U 
                                                    <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                                   & (0xf2U 
                                                      >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))))))));
        tracep->chgBit(oldp+642,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                  & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                      | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         >> 1U)) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))));
        tracep->chgCData(oldp+643,(vlTOPp->top__DOT__oricatmos__DOT__via_pa_in),8);
        tracep->chgCData(oldp+644,(vlTOPp->top__DOT__oricatmos__DOT__via_pb_in),8);
        tracep->chgBit(oldp+645,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__swnmi)))));
        tracep->chgBit(oldp+646,((1U & (~ (((3U == 
                                             (3U & 
                                              (vlTOPp->top__DOT__oricatmos__DOT__cpu_ad 
                                               >> 0xeU))) 
                                            & (IData)(vlTOPp->top__DOT__oricatmos__DOT__cont_MAPn)) 
                                           & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                              >> 2U))))));
        tracep->chgBit(oldp+647,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                            >> 1U)) 
                                        | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                            >> 2U) 
                                           & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)))))));
        tracep->chgBit(oldp+648,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                            >> 1U)) 
                                        | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))));
        tracep->chgBit(oldp+649,((1U & (((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)) 
                                         & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))) 
                                        & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                           >> 0x11U)))));
        tracep->chgBit(oldp+650,(vlTOPp->top__DOT__oricatmos__DOT__swnmi));
        tracep->chgCData(oldp+651,(((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out0) 
                                      | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out1)) 
                                     | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out2)) 
                                    | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out3))),8);
        tracep->chgBit(oldp+652,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel) 
                                           & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                              >> 2U))))));
        tracep->chgBit(oldp+653,((1U & ((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq)) 
                                        & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq) 
                                              & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN)))))));
        tracep->chgQData(oldp+654,((((QData)((IData)(
                                                     (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PC) 
                                                       << 0x10U) 
                                                      | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__S)))) 
                                     << 0x20U) | (QData)((IData)(
                                                                 (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                                   << 0x18U) 
                                                                  | ((0xff0000U 
                                                                      & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Y) 
                                                                         << 0x10U)) 
                                                                     | ((0xff00U 
                                                                         & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__X) 
                                                                            << 8U)) 
                                                                        | (0xffU 
                                                                           & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC))))))))),64);
        tracep->chgBit(oldp+656,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i));
        tracep->chgBit(oldp+657,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_d));
        tracep->chgSData(oldp+658,((0xffffU & ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC)
                                                  ? 0xa000U
                                                  : 0xbb80U) 
                                                + (0x7fffU 
                                                   & ((0x7fe0U 
                                                       & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                          << 5U)) 
                                                      + 
                                                      ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                       << 3U)))) 
                                               + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))),16);
        tracep->chgSData(oldp+659,(((((3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                       ? 0x27U : ((2U 
                                                   == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                                   ? 0x26U
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                                    ? 0x2eU
                                                    : 0x2dU))) 
                                     << 0xaU) | ((0x3f8U 
                                                  & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS) 
                                                     << 3U)) 
                                                 | (7U 
                                                    & ((1U 
                                                        & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                                            >> 1U) 
                                                           & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))))
                                                        ? 
                                                       ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V) 
                                                        >> 1U)
                                                        : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))))),16);
        tracep->chgBit(oldp+660,((1U & ((2U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE))
                                         ? (~ ((0x102U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                               & (0x103U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))
                                         : (~ ((0xf1U 
                                                <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                               & (0xf2U 
                                                  >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))))));
        tracep->chgBit(oldp+661,((1U & (((((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib)) 
                                           & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                              >> 0xcU)) 
                                          & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))) 
                                         | (((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib)) 
                                             & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                >> 5U)) 
                                            & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))) 
                                        | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib) 
                                           & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                              >> 9U))))));
        tracep->chgCData(oldp+662,((7U & ((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                                  >> 1U) 
                                                 & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))))
                                           ? ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V) 
                                              >> 1U)
                                           : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))),3);
        tracep->chgBit(oldp+663,((1U & ((~ (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH) 
                                             >> 4U) 
                                            & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                               >> 2U))) 
                                        & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG) 
                                           >> 5U)))));
        tracep->chgBit(oldp+664,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__write) 
                                  & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__last_write)))));
        tracep->chgBit(oldp+665,((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_step) 
                                   & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__last_step))) 
                                  | (0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period)))));
        tracep->chgBit(oldp+666,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         >> 2U) | (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))))));
        tracep->chgBit(oldp+667,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT) 
                                  | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))));
        tracep->chgBit(oldp+668,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_CLK_en));
        tracep->chgCData(oldp+669,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__count),3);
        tracep->chgBit(oldp+670,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT) 
                                           | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))))));
        tracep->chgBit(oldp+671,(((3U == (3U & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)) 
                                  & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_rd))));
        tracep->chgCData(oldp+672,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__cmd_mode)
                                     ? ((0x80U & ((~ (IData)(vlTOPp->top__DOT__fdd_ready)) 
                                                  << 7U)) 
                                        | ((((IData)(vlTOPp->top__DOT__img_readonly) 
                                             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wpe)) 
                                            << 6U) 
                                           | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wrfault) 
                                               << 5U) 
                                              | ((0x10U 
                                                  & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_seekerr) 
                                                      | (~ (IData)(vlTOPp->top__DOT__fdd_ready))) 
                                                     << 4U)) 
                                                 | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_crcerr) 
                                                     << 3U) 
                                                    | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_lostdata) 
                                                        << 2U) 
                                                       | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy)))))))
                                     : ((0x80U & ((~ (IData)(vlTOPp->top__DOT__fdd_ready)) 
                                                  << 7U)) 
                                        | ((((IData)(vlTOPp->top__DOT__img_readonly) 
                                             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wpe)) 
                                            << 6U) 
                                           | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_headloaded) 
                                               << 5U) 
                                              | ((0x10U 
                                                  & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_seekerr) 
                                                      | (~ (IData)(vlTOPp->top__DOT__fdd_ready))) 
                                                     << 4U)) 
                                                 | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_crcerr) 
                                                     << 3U) 
                                                    | ((4U 
                                                        & ((~ (IData)(
                                                                      (0U 
                                                                       != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track)))) 
                                                           << 2U)) 
                                                       | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_index) 
                                                           << 1U) 
                                                          | (1U 
                                                             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy))))))))))),8);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
        vlTOPp->__Vm_traceActivity[7U] = 0U;
        vlTOPp->__Vm_traceActivity[8U] = 0U;
        vlTOPp->__Vm_traceActivity[9U] = 0U;
        vlTOPp->__Vm_traceActivity[0xaU] = 0U;
        vlTOPp->__Vm_traceActivity[0xbU] = 0U;
        vlTOPp->__Vm_traceActivity[0xcU] = 0U;
        vlTOPp->__Vm_traceActivity[0xdU] = 0U;
        vlTOPp->__Vm_traceActivity[0xeU] = 0U;
        vlTOPp->__Vm_traceActivity[0xfU] = 0U;
    }
}
