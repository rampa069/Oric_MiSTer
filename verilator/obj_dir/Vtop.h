// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"
#include "verilated_save.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_48,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_HB,0,0);
    VL_OUT8(VGA_VB,0,0);
    VL_IN8(ioctl_download,0,0);
    VL_IN8(ioctl_upload,0,0);
    VL_IN8(ioctl_wr,0,0);
    VL_IN8(ioctl_dout,7,0);
    VL_IN8(ioctl_din,7,0);
    VL_IN8(ioctl_index,7,0);
    VL_OUT8(ioctl_wait,0,0);
    VL_OUT8(ce_pix,0,0);
    VL_IN16(inputs,11,0);
    VL_OUT16(AUDIO_L,15,0);
    VL_OUT16(AUDIO_R,15,0);
    VL_IN16(ps2_key,10,0);
    VL_IN(ioctl_addr,24,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__RESETn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL;
        CData/*7:0*/ top__DOT__ram_d_temp;
        CData/*0:0*/ top__DOT__ram_we_temp;
        CData/*0:0*/ top__DOT__ram_cs_temp;
        CData/*7:0*/ top__DOT__ram_q;
        CData/*0:0*/ top__DOT__tape_wr;
        CData/*7:0*/ top__DOT__tape_dout;
        CData/*0:0*/ top__DOT__tape_complete;
        CData/*0:0*/ top__DOT__tape_autorun;
        CData/*0:0*/ top__DOT__tape_request;
        CData/*0:0*/ top__DOT__key_strobe;
        CData/*0:0*/ top__DOT__old_keystb;
        CData/*0:0*/ top__DOT__fdd_ready;
        CData/*0:0*/ top__DOT__tape_adc;
        CData/*0:0*/ top__DOT__locked;
        CData/*0:0*/ top__DOT__rom;
        CData/*0:0*/ top__DOT__img_mounted;
        CData/*0:0*/ top__DOT__img_size;
        CData/*0:0*/ top__DOT__img_readonly;
        CData/*0:0*/ top__DOT__sd_rd;
        CData/*0:0*/ top__DOT__sd_wr;
        CData/*0:0*/ top__DOT__sd_ack;
        CData/*0:0*/ top__DOT__sd_buff_addr;
        CData/*0:0*/ top__DOT__sd_buff_dout;
        CData/*0:0*/ top__DOT__sd_buff_wr;
        CData/*7:0*/ top__DOT__ram__DOT__do2;
        CData/*0:0*/ top__DOT__cassette__DOT__autostart;
        CData/*7:0*/ top__DOT__cassette__DOT__fileType;
        CData/*7:0*/ top__DOT__cassette__DOT__autorun;
        CData/*7:0*/ top__DOT__cassette__DOT__endAddressHIGH;
        CData/*7:0*/ top__DOT__cassette__DOT__endAddressLOW;
        CData/*7:0*/ top__DOT__cassette__DOT__startAddressHIGH;
        CData/*7:0*/ top__DOT__cassette__DOT__startAddressLOW;
        CData/*0:0*/ top__DOT__cassette__DOT__unused;
        CData/*7:0*/ top__DOT__cassette__DOT__cache_dout;
        CData/*0:0*/ top__DOT__cassette__DOT__cache_cs;
        CData/*0:0*/ top__DOT__cassette__DOT__tapecache_loaded;
        CData/*0:0*/ top__DOT__cassette__DOT__ioctl_downlD;
        CData/*0:0*/ top__DOT__oricatmos__DOT__reset_dll_h;
        CData/*7:0*/ top__DOT__oricatmos__DOT__cpu_di;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pa_in;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pa_in_from_psg;
        CData/*0:0*/ top__DOT__oricatmos__DOT__via_cb2_out;
        CData/*0:0*/ top__DOT__oricatmos__DOT__via_cb2_oe_l;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_out;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_oe_l;
        CData/*7:0*/ top__DOT__oricatmos__DOT__VIA_DO;
        CData/*7:0*/ top__DOT__oricatmos__DOT__KEY_ROW;
        CData/*0:0*/ top__DOT__oricatmos__DOT__psg_bdir;
        CData/*0:0*/ top__DOT__oricatmos__DOT__psg_bc1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_CLK_4_en;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_MUX;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_RW_RAM;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_VIDEO_R;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_VIDEO_G;
        CData/*0:0*/ top__DOT__oricatmos__DOT__ula_VIDEO_B;
        CData/*7:0*/ top__DOT__oricatmos__DOT__ROM_ATMOS_DO;
        CData/*7:0*/ top__DOT__oricatmos__DOT__ROM_1_DO;
        CData/*7:0*/ top__DOT__oricatmos__DOT__ROM_MD_DO;
        CData/*0:0*/ top__DOT__oricatmos__DOT__swnmi;
        CData/*0:0*/ top__DOT__oricatmos__DOT__swrst;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__cont_MAPn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__cont_ROMDISn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__cont_IOCONTROLn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__PH2_1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__PH2_2;
        CData/*0:0*/ top__DOT__oricatmos__DOT__PH2_3;
        CData/*3:0*/ top__DOT__oricatmos__DOT__PH2_old;
        CData/*4:0*/ top__DOT__oricatmos__DOT__PH2_cntr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__OPEN;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__PRINT;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__P;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__AD;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__DL;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BAH;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__PBR;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__DBR;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__EF_i;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__MF_i;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__XF_i;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__IR;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Mode_r;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op_r;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data_r;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To_r;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__RstCycle;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__NMICycle;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__SO_n_o;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQ_n_o;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_n_o;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__NMIAct;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Break;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA_r;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB_r;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Q;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__P_Out;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LCycle;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_BusA_To;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Jump;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BAAdd;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BAQuirk;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BreakAtNA;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__ADAdd;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__AddY;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdd;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Inc_S;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Dec_S;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDA;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDP;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDX;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDY;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDS;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDDI;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDALU;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDAD;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAL;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAH;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__SaveP;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Write;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__rdy_mod;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_entered;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__xhdl0__DOT__tmpP;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__mcode__DOT__ALUmore;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Z;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_C;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_V;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_N;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Q;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Z;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_C;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_V;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_N;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Q;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBX_Q;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AL;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AH;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__C;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AL;
        CData/*5:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AH;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__C;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__CT;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q_t;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q2_t;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__BLANKINGn;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__ph;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lHBLANKn;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS;
        CData/*5:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lREGHOLD;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lRGB;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_INK;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_PAPER;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lInv;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lInv_hold;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__O_DATA_OE_L;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__phase;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_t1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_dl;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cs;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ddra;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ora;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ira;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ddrb;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_orb;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_irb;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_l;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_h;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_l;
    };
    struct {
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_h;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_sr;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_acr;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_pcr;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ifr;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ier;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_write_ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_read_ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ifr_write_ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ier_write_ena;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__clear_irq;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__load_data;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1c_active;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1c_done;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_w_reset_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_r_reset_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_load_counter;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_reload_counter;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_toggle;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_c;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2c_active;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2c_done;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6_t1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_cnt_clk;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_w_reset_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_r_reset_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_load_counter;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_reload_counter;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2_sr_ena;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_cnt;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_oe_l;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_out;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_drive_cb2;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_do_shift;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_t1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_falling;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_rising;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_out;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__sr_active;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__w_orb_hs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__w_ora_hs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_irb_hs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__r_ira_hs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_sr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_pulse;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_sr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_pulse;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_c;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_c;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca1_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb1_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca1_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb1_irq;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_c;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_c;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_d;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca2_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb2_int;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__ca2_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__cb2_irq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__final_irq;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__orb;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_timer1_done__DOT__done;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done_sr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2__DOT__ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__dir_out;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_op;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_ip;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__use_t2;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__free_run;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__sr_count_ena;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__addr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__din_latch;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__envelope;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitA;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitB;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitC;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__noise;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Amix;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Bmix;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Cmix;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen16;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen256;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_step;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_restart;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logA;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logB;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logC;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__log;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__lin;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc_st;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__read_mask;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__write;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__last_write;
        CData/*5:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__count;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17_zero;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__noise_en;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__last_en;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__u_div__DOT__count;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__inv;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__stop;
        CData/*4:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__gain;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__last_step;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_clr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw0;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw2;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw3;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw4;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw5;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw6;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw7;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw8;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sw9;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swa;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swb;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swc;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swd;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swe;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swg;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swh;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swi;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swj;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swk;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swl;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swm;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swo;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swp;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sws;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swt;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swu;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swv;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sww;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swx;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swy;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swz;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swU;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swD;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swL;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swR;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swrs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swls;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swsp;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swcom;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swdot;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swret;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swfs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__sweq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swfcn;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swdel;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swrsb;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swlsb;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swbs;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swdsh;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swsq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swsc;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swesc;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swctl;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf1;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf2;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf3;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf4;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf5;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_key__DOT__swf6;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nCS;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__nCS;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nRE;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_CLK_en;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__u16k;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__inECE;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__inROMDIS;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__DSEL;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__SSEL;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__nROMEN;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__inMCRQ;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__count;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_size_code;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sectors_per_track;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_spt;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__format;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_crcerr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_headloaded;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_seekerr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_index;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_lostdata;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wrfault;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__cmd_mode;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wpe;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_busy;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_track;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__q;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__layout_r;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__dts;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_rd;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__step_direction;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__next_track;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__watchdog_set;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sizecode;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_side;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_track;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sector;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_trackf;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sidef;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_wr;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__blk_size;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__rde;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wre;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_wr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_rd;
        CData/*2:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__rw_type;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write;
        CData/*5:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy;
    };
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_mounted;
        CData/*3:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsize;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_active;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_wr;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__idStatus;
        CData/*6:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector;
        CData/*1:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__crc1;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__crc2;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef;
        SData/*15:0*/ top__DOT__ram_ad_temp;
        SData/*15:0*/ top__DOT__tape_addr;
        SData/*15:0*/ top__DOT__loadpoint;
        SData/*15:0*/ top__DOT__tape_read_addr;
        SData/*15:0*/ top__DOT__tape_read_dout;
        SData/*15:0*/ top__DOT__cassette__DOT__programlength;
        SData/*15:0*/ top__DOT__cassette__DOT__start_addr;
        SData/*15:0*/ top__DOT__cassette__DOT__end_addr;
        SData/*15:0*/ top__DOT__cassette__DOT__state;
        SData/*15:0*/ top__DOT__cassette__DOT__cache_addr;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__X;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__Y;
        SData/*8:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__BAL;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__PC;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__S;
        SData/*8:0*/ top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdder;
        SData/*8:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__AD_RAM_INT;
        SData/*8:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t1c;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_via__DOT__t2c;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period;
        SData/*9:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc;
        SData/*9:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt;
        SData/*11:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chA__DOT__count;
        SData/*11:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chB__DOT__count;
        SData/*11:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chC__DOT__count;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_envdiv__DOT__count;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__data_length;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__next_length;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_start;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_next;
        SData/*9:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer;
        SData/*13:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__hdr_pos;
        SData/*13:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__bcnt;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size;
        SData/*15:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos;
        IData/*23:0*/ top__DOT__oricatmos__DOT__cpu_ad;
        IData/*23:0*/ top__DOT__oricatmos__DOT__inst_ula__DOT__c;
    };
    struct {
        IData/*16:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_size;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__hs;
        IData/*31:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_offset;
        IData/*31:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt;
        IData/*31:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset;
        IData/*19:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1;
        CData/*7:0*/ top__DOT__ram__DOT__d[65536];
        CData/*7:0*/ top__DOT__cassette__DOT__tapecache__DOT__memory[65536];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_rom0__DOT__rom_data[16384];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_rom1__DOT__rom_data[16384];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_rom2__DOT__rom_data[8192];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[16];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_exp__DOT__lut[128];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[6];
        QData/*53:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk[1992];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt[166];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes[166];
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram[2048];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n;
        CData/*0:0*/ top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET;
        CData/*7:0*/ top__DOT____Vcellout__oricatmos__sd_din;
        CData/*7:0*/ top__DOT____Vcellout__oricatmos__PSG_OUT_C;
        CData/*7:0*/ top__DOT____Vcellout__oricatmos__PSG_OUT_B;
        CData/*7:0*/ top__DOT____Vcellout__oricatmos__PSG_OUT_A;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in__out1;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in__out2;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in__out3;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in__out5;
        CData/*7:0*/ top__DOT__oricatmos__DOT__via_pb_in__out6;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out0;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out1;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out2;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out3;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_b;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__data_b;
        CData/*0:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_a;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound1;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound2;
        CData/*7:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound3;
        CData/*3:0*/ __Vtableidx2;
        CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__d__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__d__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__d__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__d__v1;
        CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__endAddressHIGH;
        CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__endAddressLOW;
        CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__startAddressHIGH;
        CData/*7:0*/ __Vdly__top__DOT__cassette__DOT__startAddressLOW;
        CData/*0:0*/ __Vdly__top__DOT__tape_wr;
        CData/*0:0*/ __Vdly__top__DOT__tape_complete;
        CData/*7:0*/ __Vdlyvval__top__DOT__cassette__DOT__tapecache__DOT__memory__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__cassette__DOT__tapecache__DOT__memory__v0;
        CData/*1:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__phase;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active;
        CData/*3:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr;
        CData/*1:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data;
        CData/*5:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector;
        CData/*1:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt;
        CData/*2:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v1;
        CData/*1:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max;
        CData/*3:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v4;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr__v5;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos;
        CData/*7:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0;
    };
    struct {
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsizes__v0;
        CData/*7:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v0;
        CData/*7:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__spt__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_cpu__DOT__IR;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_cpu__DOT__P;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQ_n_o;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_entered;
        CData/*2:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle;
        CData/*2:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__ph;
        CData/*6:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS;
        CData/*2:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe;
        CData/*7:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__r_sr;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__sr_do_shift;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__sr_active;
        CData/*3:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__sr_cnt;
        CData/*4:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__log;
        CData/*3:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray__v0;
        CData/*7:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray__v1;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitA;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitB;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitC;
        CData/*4:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__gain;
        CData/*0:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__inv;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__oricatmos__DOT__RESETn;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL;
        CData/*0:0*/ __Vclklast__TOP__clk_48;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__oricatmos__DOT__RESETn;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__oricatmos__DOT__RESETn;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL;
        SData/*9:0*/ top__DOT____Vcellout__oricatmos__PSG_OUT;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_b;
        SData/*10:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_a;
        SData/*10:0*/ __Vtableidx1;
        SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__DOT__d__v0;
        SData/*15:0*/ __Vdlyvdim0__top__DOT__ram__DOT__d__v1;
        SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__state;
        SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__cache_addr;
        SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__end_addr;
        SData/*15:0*/ __Vdly__top__DOT__cassette__DOT__start_addr;
        SData/*15:0*/ __Vdlyvdim0__top__DOT__cassette__DOT__tapecache__DOT__memory__v0;
        SData/*15:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t1c;
    };
    struct {
        SData/*15:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_via__DOT__t2c;
        SData/*15:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer;
        SData/*10:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr;
        SData/*9:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer;
        SData/*10:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr;
        SData/*10:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0;
        SData/*10:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v0;
        SData/*10:0*/ __Vdlyvdim0__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk1__DOT__sbuf__DOT__ram__v1;
        SData/*8:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V;
        SData/*9:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt;
        IData/*19:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr;
        IData/*31:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state;
        IData/*31:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time;
        IData/*23:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_ula__DOT__c;
        IData/*16:0*/ __Vdly__top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17;
        QData/*53:0*/ top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vlvbound4;
        QData/*53:0*/ __Vdlyvval__top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__edsk__v0;
        CData/*0:0*/ __Vm_traceActivity[16];
    };
    static CData/*4:0*/ __Vtable1_top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op[2048];
    static CData/*7:0*/ __Vtable2_top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__read_mask[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__18(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__25(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__32(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__20(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__24(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__31(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__16(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__17(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__19(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__22(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__23(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__26(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__27(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__28(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__29(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__30(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__13(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__14(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
  public:
    void __Vserialize(VerilatedSerialize& os);
    void __Vdeserialize(VerilatedDeserialize& os);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


inline VerilatedSerialize& operator<<(VerilatedSerialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vserialize(os); return os; }
inline VerilatedDeserialize& operator>>(VerilatedDeserialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vdeserialize(os); return os; }

#endif  // guard
