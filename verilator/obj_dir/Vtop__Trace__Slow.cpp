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
    if (!Verilated::calcUnusedSigs()) {
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
        tracep->declBit(c+610,"clk_48", false,-1);
        tracep->declBit(c+611,"reset", false,-1);
        tracep->declBus(c+612,"inputs", false,-1, 11,0);
        tracep->declBus(c+613,"VGA_R", false,-1, 7,0);
        tracep->declBus(c+614,"VGA_G", false,-1, 7,0);
        tracep->declBus(c+615,"VGA_B", false,-1, 7,0);
        tracep->declBit(c+616,"VGA_HS", false,-1);
        tracep->declBit(c+617,"VGA_VS", false,-1);
        tracep->declBit(c+618,"VGA_HB", false,-1);
        tracep->declBit(c+619,"VGA_VB", false,-1);
        tracep->declBus(c+620,"AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+621,"AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+622,"ioctl_download", false,-1);
        tracep->declBit(c+623,"ioctl_upload", false,-1);
        tracep->declBit(c+624,"ioctl_wr", false,-1);
        tracep->declBus(c+625,"ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+626,"ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+627,"ioctl_din", false,-1, 7,0);
        tracep->declBus(c+628,"ioctl_index", false,-1, 7,0);
        tracep->declBit(c+629,"ioctl_wait", false,-1);
        tracep->declBit(c+630,"ce_pix", false,-1);
        tracep->declBit(c+610,"top clk_48", false,-1);
        tracep->declBit(c+611,"top reset", false,-1);
        tracep->declBus(c+612,"top inputs", false,-1, 11,0);
        tracep->declBus(c+613,"top VGA_R", false,-1, 7,0);
        tracep->declBus(c+614,"top VGA_G", false,-1, 7,0);
        tracep->declBus(c+615,"top VGA_B", false,-1, 7,0);
        tracep->declBit(c+616,"top VGA_HS", false,-1);
        tracep->declBit(c+617,"top VGA_VS", false,-1);
        tracep->declBit(c+618,"top VGA_HB", false,-1);
        tracep->declBit(c+619,"top VGA_VB", false,-1);
        tracep->declBus(c+620,"top AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+621,"top AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+622,"top ioctl_download", false,-1);
        tracep->declBit(c+623,"top ioctl_upload", false,-1);
        tracep->declBit(c+624,"top ioctl_wr", false,-1);
        tracep->declBus(c+625,"top ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+626,"top ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+627,"top ioctl_din", false,-1, 7,0);
        tracep->declBus(c+628,"top ioctl_index", false,-1, 7,0);
        tracep->declBit(c+629,"top ioctl_wait", false,-1);
        tracep->declBit(c+630,"top ce_pix", false,-1);
        tracep->declBus(c+668,"top ps2_key", false,-1, 10,0);
        tracep->declBit(c+483,"top r", false,-1);
        tracep->declBit(c+484,"top g", false,-1);
        tracep->declBit(c+485,"top b", false,-1);
        tracep->declBus(c+669,"top clr_addr", false,-1, 16,0);
        tracep->declBus(c+631,"top ram_ad", false,-1, 15,0);
        tracep->declBus(c+447,"top ram_ad_temp", false,-1, 15,0);
        tracep->declBus(c+499,"top ram_d", false,-1, 7,0);
        tracep->declBus(c+2,"top ram_d_temp", false,-1, 7,0);
        tracep->declBit(c+632,"top ram_we", false,-1);
        tracep->declBit(c+633,"top ram_cs", false,-1);
        tracep->declBit(c+448,"top ram_we_temp", false,-1);
        tracep->declBit(c+449,"top ram_cs_temp", false,-1);
        tracep->declBus(c+450,"top ram_q", false,-1, 7,0);
        tracep->declBit(c+580,"top video_clk", false,-1);
        tracep->declBus(c+3,"top tape_addr", false,-1, 15,0);
        tracep->declBit(c+4,"top tape_wr", false,-1);
        tracep->declBus(c+5,"top tape_dout", false,-1, 7,0);
        tracep->declBit(c+6,"top tape_complete", false,-1);
        tracep->declBit(c+7,"top tape_autorun", false,-1);
        tracep->declBus(c+8,"top loadpoint", false,-1, 15,0);
        tracep->declBit(c+670,"top tape_request", false,-1);
        tracep->declBus(c+671,"top tape_read_addr", false,-1, 15,0);
        tracep->declBus(c+672,"top tape_read_dout", false,-1, 15,0);
        tracep->declBit(c+225,"top fdd_ready", false,-1);
        tracep->declBit(c+673,"top key_strobe", false,-1);
        tracep->declBit(c+130,"top psg_a", false,-1);
        tracep->declBit(c+131,"top psg_b", false,-1);
        tracep->declBit(c+132,"top psg_c", false,-1);
        tracep->declBit(c+133,"top psg_out", false,-1);
        tracep->declBit(c+674,"top tape_adc", false,-1);
        tracep->declBit(c+348,"top tape_out", false,-1);
        tracep->declBit(c+226,"top led_disk", false,-1);
        tracep->declBit(c+675,"top locked", false,-1);
        tracep->declBit(c+676,"top rom", false,-1);
        tracep->declBit(c+677,"top img_mounted", false,-1);
        tracep->declBit(c+678,"top img_size", false,-1);
        tracep->declBit(c+679,"top img_readonly", false,-1);
        tracep->declBit(c+227,"top sd_lba", false,-1);
        tracep->declBit(c+228,"top sd_rd", false,-1);
        tracep->declBit(c+229,"top sd_wr", false,-1);
        tracep->declBit(c+680,"top sd_ack", false,-1);
        tracep->declBit(c+681,"top sd_buff_addr", false,-1);
        tracep->declBit(c+682,"top sd_buff_dout", false,-1);
        tracep->declBit(c+9,"top sd_buff_din", false,-1);
        tracep->declBit(c+683,"top sd_buff_wr", false,-1);
        tracep->declBus(c+684,"top ram DW", false,-1, 31,0);
        tracep->declBus(c+685,"top ram AW", false,-1, 31,0);
        tracep->declBit(c+610,"top ram clock", false,-1);
        tracep->declBit(c+449,"top ram ce1", false,-1);
        tracep->declBit(c+448,"top ram we1", false,-1);
        tracep->declBus(c+2,"top ram di1", false,-1, 7,0);
        tracep->declBus(c+450,"top ram do1", false,-1, 7,0);
        tracep->declBus(c+447,"top ram a1", false,-1, 15,0);
        tracep->declBit(c+686,"top ram ce2", false,-1);
        tracep->declBit(c+4,"top ram we2", false,-1);
        tracep->declBus(c+5,"top ram di2", false,-1, 7,0);
        tracep->declBus(c+10,"top ram do2", false,-1, 7,0);
        tracep->declBus(c+3,"top ram a2", false,-1, 15,0);
        tracep->declBit(c+610,"top cassette clk", false,-1);
        tracep->declBit(c+622,"top cassette ioctl_download", false,-1);
        tracep->declBit(c+624,"top cassette ioctl_wr", false,-1);
        tracep->declBus(c+625,"top cassette ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+626,"top cassette ioctl_dout", false,-1, 7,0);
        tracep->declBit(c+634,"top cassette reset_n", false,-1);
        tracep->declBit(c+670,"top cassette tape_request", false,-1);
        tracep->declBit(c+687,"top cassette autostart", false,-1);
        tracep->declBit(c+7,"top cassette tape_autorun", false,-1);
        tracep->declBus(c+8,"top cassette loadpoint", false,-1, 15,0);
        tracep->declBus(c+3,"top cassette tape_addr", false,-1, 15,0);
        tracep->declBit(c+4,"top cassette tape_wr", false,-1);
        tracep->declBus(c+5,"top cassette tape_dout", false,-1, 7,0);
        tracep->declBit(c+6,"top cassette tape_complete", false,-1);
        tracep->declBus(c+688,"top cassette SM_INIT", false,-1, 31,0);
        tracep->declBus(c+689,"top cassette SM_FILETYPE", false,-1, 31,0);
        tracep->declBus(c+690,"top cassette SM_AUTORUN", false,-1, 31,0);
        tracep->declBus(c+691,"top cassette SM_ENDADDRESSHIGH", false,-1, 31,0);
        tracep->declBus(c+692,"top cassette SM_ENDADDRESSLOW", false,-1, 31,0);
        tracep->declBus(c+693,"top cassette SM_STARTADDRESSHIGH", false,-1, 31,0);
        tracep->declBus(c+694,"top cassette SM_STARTADDRESSLOW", false,-1, 31,0);
        tracep->declBus(c+684,"top cassette SM_FILENAME", false,-1, 31,0);
        tracep->declBus(c+695,"top cassette SM_PROGRAMCODE", false,-1, 31,0);
        tracep->declBus(c+696,"top cassette SM_COMPLETE", false,-1, 31,0);
        tracep->declBus(c+697,"top cassette programlength", false,-1, 15,0);
        tracep->declBus(c+11,"top cassette start_addr", false,-1, 15,0);
        tracep->declBus(c+12,"top cassette end_addr", false,-1, 15,0);
        tracep->declBus(c+13,"top cassette state", false,-1, 15,0);
        tracep->declBus(c+14,"top cassette fileType", false,-1, 7,0);
        tracep->declBus(c+15,"top cassette autorun", false,-1, 7,0);
        tracep->declBus(c+16,"top cassette endAddressHIGH", false,-1, 7,0);
        tracep->declBus(c+17,"top cassette endAddressLOW", false,-1, 7,0);
        tracep->declBus(c+18,"top cassette startAddressHIGH", false,-1, 7,0);
        tracep->declBus(c+19,"top cassette startAddressLOW", false,-1, 7,0);
        tracep->declBit(c+698,"top cassette unused", false,-1);
        tracep->declBus(c+20,"top cassette cache_addr", false,-1, 15,0);
        tracep->declBus(c+21,"top cassette cache_dout", false,-1, 7,0);
        tracep->declBit(c+22,"top cassette cache_cs", false,-1);
        tracep->declBit(c+23,"top cassette tapecache_loaded", false,-1);
        tracep->declBit(c+24,"top cassette ioctl_downlD", false,-1);
        tracep->declBit(c+610,"top cassette tapecache clk", false,-1);
        tracep->declBit(c+622,"top cassette tapecache bram_download", false,-1);
        tracep->declBit(c+624,"top cassette tapecache bram_wr", false,-1);
        tracep->declBus(c+635,"top cassette tapecache bram_init_address", false,-1, 15,0);
        tracep->declBus(c+626,"top cassette tapecache bram_din", false,-1, 7,0);
        tracep->declBit(c+22,"top cassette tapecache cs", false,-1);
        tracep->declBus(c+20,"top cassette tapecache addr", false,-1, 15,0);
        tracep->declBus(c+21,"top cassette tapecache dout", false,-1, 7,0);
        tracep->declBit(c+610,"top oricatmos CLK_IN", false,-1);
        tracep->declBit(c+611,"top oricatmos RESET", false,-1);
        tracep->declBit(c+699,"top oricatmos key_pressed", false,-1);
        tracep->declBit(c+700,"top oricatmos key_extended", false,-1);
        tracep->declBus(c+701,"top oricatmos key_code", false,-1, 7,0);
        tracep->declBit(c+673,"top oricatmos key_strobe", false,-1);
        tracep->declBit(c+674,"top oricatmos K7_TAPEIN", false,-1);
        tracep->declBit(c+348,"top oricatmos K7_TAPEOUT", false,-1);
        tracep->declBit(c+349,"top oricatmos K7_REMOTE", false,-1);
        tracep->declBus(c+134,"top oricatmos PSG_OUT_A", false,-1, 7,0);
        tracep->declBus(c+135,"top oricatmos PSG_OUT_B", false,-1, 7,0);
        tracep->declBus(c+136,"top oricatmos PSG_OUT_C", false,-1, 7,0);
        tracep->declBus(c+137,"top oricatmos PSG_OUT", false,-1, 9,0);
        tracep->declBit(c+580,"top oricatmos VIDEO_CLK", false,-1);
        tracep->declBit(c+483,"top oricatmos VIDEO_R", false,-1);
        tracep->declBit(c+484,"top oricatmos VIDEO_G", false,-1);
        tracep->declBit(c+485,"top oricatmos VIDEO_B", false,-1);
        tracep->declBit(c+618,"top oricatmos VIDEO_HBLANK", false,-1);
        tracep->declBit(c+619,"top oricatmos VIDEO_VBLANK", false,-1);
        tracep->declBit(c+616,"top oricatmos VIDEO_HSYNC", false,-1);
        tracep->declBit(c+617,"top oricatmos VIDEO_VSYNC", false,-1);
        tracep->declBit(c+636,"top oricatmos VIDEO_SYNC", false,-1);
        tracep->declBus(c+631,"top oricatmos ram_ad", false,-1, 15,0);
        tracep->declBus(c+499,"top oricatmos ram_d", false,-1, 7,0);
        tracep->declBus(c+450,"top oricatmos ram_q", false,-1, 7,0);
        tracep->declBit(c+633,"top oricatmos ram_cs", false,-1);
        tracep->declBit(c+637,"top oricatmos ram_oe", false,-1);
        tracep->declBit(c+632,"top oricatmos ram_we", false,-1);
        tracep->declBit(c+466,"top oricatmos phi2", false,-1);
        tracep->declBit(c+226,"top oricatmos fd_led", false,-1);
        tracep->declBit(c+225,"top oricatmos fdd_ready", false,-1);
        tracep->declBit(c+226,"top oricatmos fdd_busy", false,-1);
        tracep->declBit(c+702,"top oricatmos fdd_reset", false,-1);
        tracep->declBit(c+702,"top oricatmos fdd_layout", false,-1);
        tracep->declBus(c+703,"top oricatmos joystick_0", false,-1, 7,0);
        tracep->declBus(c+703,"top oricatmos joystick_1", false,-1, 7,0);
        tracep->declBit(c+675,"top oricatmos pll_locked", false,-1);
        tracep->declBit(c+686,"top oricatmos disk_enable", false,-1);
        tracep->declBit(c+676,"top oricatmos rom", false,-1);
        tracep->declBit(c+677,"top oricatmos img_mounted", false,-1);
        tracep->declBit(c+679,"top oricatmos img_wp", false,-1);
        tracep->declBus(c+704,"top oricatmos img_size", false,-1, 31,0);
        tracep->declBus(c+230,"top oricatmos sd_lba", false,-1, 31,0);
        tracep->declBit(c+228,"top oricatmos sd_rd", false,-1);
        tracep->declBit(c+229,"top oricatmos sd_wr", false,-1);
        tracep->declBit(c+680,"top oricatmos sd_ack", false,-1);
        tracep->declBus(c+705,"top oricatmos sd_buff_addr", false,-1, 8,0);
        tracep->declBus(c+706,"top oricatmos sd_dout", false,-1, 7,0);
        tracep->declBus(c+25,"top oricatmos sd_din", false,-1, 7,0);
        tracep->declBit(c+683,"top oricatmos sd_dout_strobe", false,-1);
        tracep->declBit(c+702,"top oricatmos sd_din_strobe", false,-1);
        tracep->declBus(c+8,"top oricatmos tape_addr", false,-1, 15,0);
        tracep->declBit(c+7,"top oricatmos tape_complete", false,-1);
        tracep->declBit(c+442,"top oricatmos RESETn", false,-1);
        tracep->declBit(c+707,"top oricatmos reset_dll_h", false,-1);
        tracep->declBus(c+703,"top oricatmos delay_count", false,-1, 7,0);
        tracep->declBus(c+708,"top oricatmos clk_cnt", false,-1, 2,0);
        tracep->declBus(c+500,"top oricatmos cpu_ad", false,-1, 23,0);
        tracep->declBus(c+231,"top oricatmos cpu_di", false,-1, 7,0);
        tracep->declBus(c+499,"top oricatmos cpu_do", false,-1, 7,0);
        tracep->declBit(c+501,"top oricatmos cpu_rw", false,-1);
        tracep->declBit(c+184,"top oricatmos cpu_irq", false,-1);
        tracep->declBus(c+185,"top oricatmos via_pa_out_oe", false,-1, 7,0);
        tracep->declBus(c+638,"top oricatmos via_pa_in", false,-1, 7,0);
        tracep->declBus(c+350,"top oricatmos via_pa_out", false,-1, 7,0);
        tracep->declBus(c+138,"top oricatmos via_pa_in_from_psg", false,-1, 7,0);
        tracep->declBit(c+351,"top oricatmos via_cb1_out", false,-1);
        tracep->declBit(c+186,"top oricatmos via_cb1_oe_l", false,-1);
        tracep->declBit(c+352,"top oricatmos via_cb2_out", false,-1);
        tracep->declBit(c+187,"top oricatmos via_cb2_oe_l", false,-1);
        tracep->declBus(c+639,"top oricatmos via_pb_in", false,-1, 7,0);
        tracep->declBus(c+353,"top oricatmos via_pb_out", false,-1, 7,0);
        tracep->declBus(c+709,"top oricatmos via_pb_oe_l", false,-1, 7,0);
        tracep->declBus(c+589,"top oricatmos VIA_DO", false,-1, 7,0);
        tracep->declBus(c+26,"top oricatmos KEY_ROW", false,-1, 7,0);
        tracep->declBit(c+27,"top oricatmos KEYB_RESETn", false,-1);
        tracep->declBit(c+640,"top oricatmos KEYB_NMIn", false,-1);
        tracep->declBit(c+354,"top oricatmos psg_bdir", false,-1);
        tracep->declBit(c+710,"top oricatmos psg_bc1", false,-1);
        tracep->declBus(c+389,"top oricatmos ym_o_ioa", false,-1, 7,0);
        tracep->declBit(c+232,"top oricatmos psg_sample_ok", false,-1);
        tracep->declBit(c+466,"top oricatmos ula_phi2", false,-1);
        tracep->declBit(c+590,"top oricatmos ula_CSIOn", false,-1);
        tracep->declBit(c+641,"top oricatmos ula_CSROMn", false,-1);
        tracep->declBit(c+591,"top oricatmos ula_CSRAMn", false,-1);
        tracep->declBus(c+451,"top oricatmos ula_AD_SRAM", false,-1, 15,0);
        tracep->declBit(c+642,"top oricatmos ula_CE_SRAM", false,-1);
        tracep->declBit(c+643,"top oricatmos ula_OE_SRAM", false,-1);
        tracep->declBit(c+644,"top oricatmos ula_WE_SRAM", false,-1);
        tracep->declBit(c+581,"top oricatmos ula_LATCH_SRAM", false,-1);
        tracep->declBit(c+582,"top oricatmos ula_CLK_4", false,-1);
        tracep->declBit(c+583,"top oricatmos ula_CLK_4_en", false,-1);
        tracep->declBit(c+711,"top oricatmos ula_MUX", false,-1);
        tracep->declBit(c+712,"top oricatmos ula_RW_RAM", false,-1);
        tracep->declBit(c+713,"top oricatmos ula_VIDEO_R", false,-1);
        tracep->declBit(c+714,"top oricatmos ula_VIDEO_G", false,-1);
        tracep->declBit(c+715,"top oricatmos ula_VIDEO_B", false,-1);
        tracep->declBit(c+584,"top oricatmos ENA_1MHZ", false,-1);
        tracep->declBus(c+233,"top oricatmos ROM_ATMOS_DO", false,-1, 7,0);
        tracep->declBus(c+234,"top oricatmos ROM_1_DO", false,-1, 7,0);
        tracep->declBus(c+235,"top oricatmos ROM_MD_DO", false,-1, 7,0);
        tracep->declBit(c+355,"top oricatmos PRN_STROBE", false,-1);
        tracep->declBus(c+350,"top oricatmos PRN_DATA", false,-1, 7,0);
        tracep->declBus(c+450,"top oricatmos SRAM_DO", false,-1, 7,0);
        tracep->declBit(c+645,"top oricatmos swnmi", false,-1);
        tracep->declBit(c+28,"top oricatmos swrst", false,-1);
        tracep->declBit(c+592,"top oricatmos cont_MAPn", false,-1);
        tracep->declBit(c+236,"top oricatmos cont_ROMDISn", false,-1);
        tracep->declBus(c+646,"top oricatmos cont_D_OUT", false,-1, 7,0);
        tracep->declBit(c+593,"top oricatmos cont_IOCONTROLn", false,-1);
        tracep->declBit(c+502,"top oricatmos cont_ECE", false,-1);
        tracep->declBit(c+443,"top oricatmos cont_RESETn", false,-1);
        tracep->declBit(c+647,"top oricatmos cont_nOE", false,-1);
        tracep->declBit(c+237,"top oricatmos cont_irq", false,-1);
        tracep->declBit(c+716,"top oricatmos PH2_1", false,-1);
        tracep->declBit(c+717,"top oricatmos PH2_2", false,-1);
        tracep->declBit(c+718,"top oricatmos PH2_3", false,-1);
        tracep->declBus(c+719,"top oricatmos PH2_old", false,-1, 3,0);
        tracep->declBus(c+720,"top oricatmos PH2_cntr", false,-1, 4,0);
        tracep->declBit(c+188,"top oricatmos OPEN", false,-1);
        tracep->declBus(c+721,"top oricatmos inst_cpu Flag_C", false,-1, 31,0);
        tracep->declBus(c+688,"top oricatmos inst_cpu Flag_Z", false,-1, 31,0);
        tracep->declBus(c+689,"top oricatmos inst_cpu Flag_I", false,-1, 31,0);
        tracep->declBus(c+690,"top oricatmos inst_cpu Flag_D", false,-1, 31,0);
        tracep->declBus(c+691,"top oricatmos inst_cpu Flag_B", false,-1, 31,0);
        tracep->declBus(c+692,"top oricatmos inst_cpu Flag_1", false,-1, 31,0);
        tracep->declBus(c+693,"top oricatmos inst_cpu Flag_V", false,-1, 31,0);
        tracep->declBus(c+694,"top oricatmos inst_cpu Flag_N", false,-1, 31,0);
        tracep->declBus(c+708,"top oricatmos inst_cpu Cycle_sync", false,-1, 2,0);
        tracep->declBus(c+722,"top oricatmos inst_cpu Cycle_1", false,-1, 2,0);
        tracep->declBus(c+723,"top oricatmos inst_cpu Cycle_2", false,-1, 2,0);
        tracep->declBus(c+724,"top oricatmos inst_cpu Cycle_3", false,-1, 2,0);
        tracep->declBus(c+725,"top oricatmos inst_cpu Cycle_4", false,-1, 2,0);
        tracep->declBus(c+726,"top oricatmos inst_cpu Cycle_5", false,-1, 2,0);
        tracep->declBus(c+727,"top oricatmos inst_cpu Cycle_6", false,-1, 2,0);
        tracep->declBus(c+728,"top oricatmos inst_cpu Cycle_7", false,-1, 2,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_DI", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_DA", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_DAO", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_DAX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_AAX", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu T_Set_BusA_To_Set_BusA_To_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+740,"top oricatmos inst_cpu T_Set_Addr_To_Set_Addr_To_PBR", false,-1, 1,0);
        tracep->declBus(c+741,"top oricatmos inst_cpu T_Set_Addr_To_Set_Addr_To_SP", false,-1, 1,0);
        tracep->declBus(c+742,"top oricatmos inst_cpu T_Set_Addr_To_Set_Addr_To_ZPG", false,-1, 1,0);
        tracep->declBus(c+743,"top oricatmos inst_cpu T_Set_Addr_To_Set_Addr_To_BA", false,-1, 1,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu T_Write_Data_Write_Data_DL", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu T_Write_Data_Write_Data_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu T_Write_Data_Write_Data_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu T_Write_Data_Write_Data_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu T_Write_Data_Write_Data_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu T_Write_Data_Write_Data_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu T_Write_Data_Write_Data_PCL", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu T_Write_Data_Write_Data_PCH", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu T_Write_Data_Write_Data_AX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu T_Write_Data_Write_Data_AXB", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu T_Write_Data_Write_Data_XB", false,-1, 3,0);
        tracep->declBus(c+744,"top oricatmos inst_cpu T_Write_Data_Write_Data_YB", false,-1, 3,0);
        tracep->declBus(c+745,"top oricatmos inst_cpu T_Write_Data_Write_Data_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+746,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_OR", false,-1, 4,0);
        tracep->declBus(c+747,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_AND", false,-1, 4,0);
        tracep->declBus(c+748,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_EOR", false,-1, 4,0);
        tracep->declBus(c+749,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ADC", false,-1, 4,0);
        tracep->declBus(c+750,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_EQ1", false,-1, 4,0);
        tracep->declBus(c+751,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_EQ2", false,-1, 4,0);
        tracep->declBus(c+752,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_CMP", false,-1, 4,0);
        tracep->declBus(c+753,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_SBC", false,-1, 4,0);
        tracep->declBus(c+754,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ASL", false,-1, 4,0);
        tracep->declBus(c+755,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ROL", false,-1, 4,0);
        tracep->declBus(c+756,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_LSR", false,-1, 4,0);
        tracep->declBus(c+757,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ROR", false,-1, 4,0);
        tracep->declBus(c+758,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_BIT", false,-1, 4,0);
        tracep->declBus(c+759,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_DEC", false,-1, 4,0);
        tracep->declBus(c+760,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_INC", false,-1, 4,0);
        tracep->declBus(c+761,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ARR", false,-1, 4,0);
        tracep->declBus(c+762,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_ANC", false,-1, 4,0);
        tracep->declBus(c+763,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_SAX", false,-1, 4,0);
        tracep->declBus(c+764,"top oricatmos inst_cpu T_ALU_OP_ALU_OP_XAA", false,-1, 4,0);
        tracep->declBus(c+740,"top oricatmos inst_cpu Mode", false,-1, 1,0);
        tracep->declBit(c+443,"top oricatmos inst_cpu Res_n", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_cpu Enable", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_cpu Clk", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_cpu Rdy", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_cpu Abort_n", false,-1);
        tracep->declBit(c+648,"top oricatmos inst_cpu IRQ_n", false,-1);
        tracep->declBit(c+640,"top oricatmos inst_cpu NMI_n", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_cpu SO_n", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_cpu R_W_n", false,-1);
        tracep->declBit(c+503,"top oricatmos inst_cpu Sync", false,-1);
        tracep->declBit(c+155,"top oricatmos inst_cpu EF", false,-1);
        tracep->declBit(c+156,"top oricatmos inst_cpu MF", false,-1);
        tracep->declBit(c+157,"top oricatmos inst_cpu XF", false,-1);
        tracep->declBit(c+504,"top oricatmos inst_cpu ML_n", false,-1);
        tracep->declBit(c+505,"top oricatmos inst_cpu VP_n", false,-1);
        tracep->declBit(c+158,"top oricatmos inst_cpu VDA", false,-1);
        tracep->declBit(c+506,"top oricatmos inst_cpu VPA", false,-1);
        tracep->declBus(c+500,"top oricatmos inst_cpu A", false,-1, 23,0);
        tracep->declBus(c+231,"top oricatmos inst_cpu DI", false,-1, 7,0);
        tracep->declBus(c+499,"top oricatmos inst_cpu DO", false,-1, 7,0);
        tracep->declQuad(c+649,"top oricatmos inst_cpu Regs", false,-1, 63,0);
        tracep->declBus(c+507,"top oricatmos inst_cpu DEBUG_I", false,-1, 7,0);
        tracep->declBus(c+159,"top oricatmos inst_cpu DEBUG_A", false,-1, 7,0);
        tracep->declBus(c+160,"top oricatmos inst_cpu DEBUG_X", false,-1, 7,0);
        tracep->declBus(c+161,"top oricatmos inst_cpu DEBUG_Y", false,-1, 7,0);
        tracep->declBus(c+162,"top oricatmos inst_cpu DEBUG_S", false,-1, 7,0);
        tracep->declBus(c+508,"top oricatmos inst_cpu DEBUG_P", false,-1, 7,0);
        tracep->declBit(c+509,"top oricatmos inst_cpu NMI_ack", false,-1);
        tracep->declBit(c+765,"top oricatmos inst_cpu PRINT", false,-1);
        tracep->declBus(c+29,"top oricatmos inst_cpu tape_addr", false,-1, 7,0);
        tracep->declBus(c+30,"top oricatmos inst_cpu tape_complete", false,-1, 7,0);
        tracep->declBus(c+163,"top oricatmos inst_cpu ABC", false,-1, 15,0);
        tracep->declBus(c+164,"top oricatmos inst_cpu X", false,-1, 15,0);
        tracep->declBus(c+165,"top oricatmos inst_cpu Y", false,-1, 15,0);
        tracep->declBus(c+508,"top oricatmos inst_cpu P", false,-1, 7,0);
        tracep->declBus(c+166,"top oricatmos inst_cpu AD", false,-1, 7,0);
        tracep->declBus(c+167,"top oricatmos inst_cpu DL", false,-1, 7,0);
        tracep->declBus(c+510,"top oricatmos inst_cpu PwithB", false,-1, 7,0);
        tracep->declBus(c+168,"top oricatmos inst_cpu BAH", false,-1, 7,0);
        tracep->declBus(c+169,"top oricatmos inst_cpu BAL", false,-1, 8,0);
        tracep->declBus(c+170,"top oricatmos inst_cpu PBR", false,-1, 7,0);
        tracep->declBus(c+171,"top oricatmos inst_cpu DBR", false,-1, 7,0);
        tracep->declBus(c+172,"top oricatmos inst_cpu PC", false,-1, 15,0);
        tracep->declBus(c+173,"top oricatmos inst_cpu S", false,-1, 15,0);
        tracep->declBit(c+155,"top oricatmos inst_cpu EF_i", false,-1);
        tracep->declBit(c+156,"top oricatmos inst_cpu MF_i", false,-1);
        tracep->declBit(c+157,"top oricatmos inst_cpu XF_i", false,-1);
        tracep->declBus(c+507,"top oricatmos inst_cpu IR", false,-1, 7,0);
        tracep->declBus(c+511,"top oricatmos inst_cpu MCycle", false,-1, 2,0);
        tracep->declBus(c+499,"top oricatmos inst_cpu DO_r", false,-1, 7,0);
        tracep->declBus(c+174,"top oricatmos inst_cpu Mode_r", false,-1, 1,0);
        tracep->declBus(c+175,"top oricatmos inst_cpu ALU_Op_r", false,-1, 4,0);
        tracep->declBus(c+176,"top oricatmos inst_cpu Write_Data_r", false,-1, 3,0);
        tracep->declBus(c+177,"top oricatmos inst_cpu Set_Addr_To_r", false,-1, 1,0);
        tracep->declBus(c+512,"top oricatmos inst_cpu PCAdder", false,-1, 8,0);
        tracep->declBit(c+513,"top oricatmos inst_cpu RstCycle", false,-1);
        tracep->declBit(c+514,"top oricatmos inst_cpu IRQCycle", false,-1);
        tracep->declBit(c+515,"top oricatmos inst_cpu NMICycle", false,-1);
        tracep->declBit(c+178,"top oricatmos inst_cpu SO_n_o", false,-1);
        tracep->declBit(c+516,"top oricatmos inst_cpu IRQ_n_o", false,-1);
        tracep->declBit(c+517,"top oricatmos inst_cpu NMI_n_o", false,-1);
        tracep->declBit(c+509,"top oricatmos inst_cpu NMIAct", false,-1);
        tracep->declBit(c+518,"top oricatmos inst_cpu Break", false,-1);
        tracep->declBus(c+519,"top oricatmos inst_cpu BusA", false,-1, 7,0);
        tracep->declBus(c+179,"top oricatmos inst_cpu BusA_r", false,-1, 7,0);
        tracep->declBus(c+180,"top oricatmos inst_cpu BusB", false,-1, 7,0);
        tracep->declBus(c+181,"top oricatmos inst_cpu BusB_r", false,-1, 7,0);
        tracep->declBus(c+520,"top oricatmos inst_cpu ALU_Q", false,-1, 7,0);
        tracep->declBus(c+521,"top oricatmos inst_cpu P_Out", false,-1, 7,0);
        tracep->declBus(c+522,"top oricatmos inst_cpu LCycle", false,-1, 2,0);
        tracep->declBus(c+523,"top oricatmos inst_cpu ALU_Op", false,-1, 4,0);
        tracep->declBus(c+524,"top oricatmos inst_cpu Set_BusA_To", false,-1, 3,0);
        tracep->declBus(c+525,"top oricatmos inst_cpu Set_Addr_To", false,-1, 1,0);
        tracep->declBus(c+526,"top oricatmos inst_cpu Write_Data", false,-1, 3,0);
        tracep->declBus(c+527,"top oricatmos inst_cpu Jump", false,-1, 1,0);
        tracep->declBus(c+528,"top oricatmos inst_cpu BAAdd", false,-1, 1,0);
        tracep->declBus(c+529,"top oricatmos inst_cpu BAQuirk", false,-1, 1,0);
        tracep->declBit(c+530,"top oricatmos inst_cpu BreakAtNA", false,-1);
        tracep->declBit(c+531,"top oricatmos inst_cpu ADAdd", false,-1);
        tracep->declBit(c+532,"top oricatmos inst_cpu AddY", false,-1);
        tracep->declBit(c+533,"top oricatmos inst_cpu PCAdd", false,-1);
        tracep->declBit(c+534,"top oricatmos inst_cpu Inc_S", false,-1);
        tracep->declBit(c+535,"top oricatmos inst_cpu Dec_S", false,-1);
        tracep->declBit(c+536,"top oricatmos inst_cpu LDA", false,-1);
        tracep->declBit(c+537,"top oricatmos inst_cpu LDP", false,-1);
        tracep->declBit(c+538,"top oricatmos inst_cpu LDX", false,-1);
        tracep->declBit(c+539,"top oricatmos inst_cpu LDY", false,-1);
        tracep->declBit(c+540,"top oricatmos inst_cpu LDS", false,-1);
        tracep->declBit(c+541,"top oricatmos inst_cpu LDDI", false,-1);
        tracep->declBit(c+542,"top oricatmos inst_cpu LDALU", false,-1);
        tracep->declBit(c+543,"top oricatmos inst_cpu LDAD", false,-1);
        tracep->declBit(c+544,"top oricatmos inst_cpu LDBAL", false,-1);
        tracep->declBit(c+545,"top oricatmos inst_cpu LDBAH", false,-1);
        tracep->declBit(c+546,"top oricatmos inst_cpu SaveP", false,-1);
        tracep->declBit(c+547,"top oricatmos inst_cpu Write", false,-1);
        tracep->declBit(c+651,"top oricatmos inst_cpu Res_n_i", false,-1);
        tracep->declBit(c+652,"top oricatmos inst_cpu Res_n_d", false,-1);
        tracep->declBit(c+182,"top oricatmos inst_cpu rdy_mod", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_cpu really_rdy", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_cpu WRn_i", false,-1);
        tracep->declBit(c+548,"top oricatmos inst_cpu NMI_entered", false,-1);
        tracep->declBus(c+183,"top oricatmos inst_cpu xhdl0 tmpP", false,-1, 7,0);
        tracep->declBus(c+721,"top oricatmos inst_cpu mcode Flag_C", false,-1, 31,0);
        tracep->declBus(c+688,"top oricatmos inst_cpu mcode Flag_Z", false,-1, 31,0);
        tracep->declBus(c+689,"top oricatmos inst_cpu mcode Flag_I", false,-1, 31,0);
        tracep->declBus(c+690,"top oricatmos inst_cpu mcode Flag_D", false,-1, 31,0);
        tracep->declBus(c+691,"top oricatmos inst_cpu mcode Flag_B", false,-1, 31,0);
        tracep->declBus(c+692,"top oricatmos inst_cpu mcode Flag_1", false,-1, 31,0);
        tracep->declBus(c+693,"top oricatmos inst_cpu mcode Flag_V", false,-1, 31,0);
        tracep->declBus(c+694,"top oricatmos inst_cpu mcode Flag_N", false,-1, 31,0);
        tracep->declBus(c+708,"top oricatmos inst_cpu mcode Cycle_sync", false,-1, 2,0);
        tracep->declBus(c+722,"top oricatmos inst_cpu mcode Cycle_1", false,-1, 2,0);
        tracep->declBus(c+723,"top oricatmos inst_cpu mcode Cycle_2", false,-1, 2,0);
        tracep->declBus(c+724,"top oricatmos inst_cpu mcode Cycle_3", false,-1, 2,0);
        tracep->declBus(c+725,"top oricatmos inst_cpu mcode Cycle_4", false,-1, 2,0);
        tracep->declBus(c+726,"top oricatmos inst_cpu mcode Cycle_5", false,-1, 2,0);
        tracep->declBus(c+727,"top oricatmos inst_cpu mcode Cycle_6", false,-1, 2,0);
        tracep->declBus(c+728,"top oricatmos inst_cpu mcode Cycle_7", false,-1, 2,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_DI", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_DA", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_DAO", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_DAX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_AAX", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu mcode T_Set_BusA_To_Set_BusA_To_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+740,"top oricatmos inst_cpu mcode T_Set_Addr_To_Set_Addr_To_PBR", false,-1, 1,0);
        tracep->declBus(c+741,"top oricatmos inst_cpu mcode T_Set_Addr_To_Set_Addr_To_SP", false,-1, 1,0);
        tracep->declBus(c+742,"top oricatmos inst_cpu mcode T_Set_Addr_To_Set_Addr_To_ZPG", false,-1, 1,0);
        tracep->declBus(c+743,"top oricatmos inst_cpu mcode T_Set_Addr_To_Set_Addr_To_BA", false,-1, 1,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_DL", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_PCL", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_PCH", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_AX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_AXB", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_XB", false,-1, 3,0);
        tracep->declBus(c+744,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_YB", false,-1, 3,0);
        tracep->declBus(c+745,"top oricatmos inst_cpu mcode T_Write_Data_Write_Data_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+746,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_OR", false,-1, 4,0);
        tracep->declBus(c+747,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_AND", false,-1, 4,0);
        tracep->declBus(c+748,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_EOR", false,-1, 4,0);
        tracep->declBus(c+749,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ADC", false,-1, 4,0);
        tracep->declBus(c+750,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_EQ1", false,-1, 4,0);
        tracep->declBus(c+751,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_EQ2", false,-1, 4,0);
        tracep->declBus(c+752,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_CMP", false,-1, 4,0);
        tracep->declBus(c+753,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_SBC", false,-1, 4,0);
        tracep->declBus(c+754,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ASL", false,-1, 4,0);
        tracep->declBus(c+755,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ROL", false,-1, 4,0);
        tracep->declBus(c+756,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_LSR", false,-1, 4,0);
        tracep->declBus(c+757,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ROR", false,-1, 4,0);
        tracep->declBus(c+758,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_BIT", false,-1, 4,0);
        tracep->declBus(c+759,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_DEC", false,-1, 4,0);
        tracep->declBus(c+760,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_INC", false,-1, 4,0);
        tracep->declBus(c+761,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ARR", false,-1, 4,0);
        tracep->declBus(c+762,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_ANC", false,-1, 4,0);
        tracep->declBus(c+763,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_SAX", false,-1, 4,0);
        tracep->declBus(c+764,"top oricatmos inst_cpu mcode T_ALU_OP_ALU_OP_XAA", false,-1, 4,0);
        tracep->declBus(c+174,"top oricatmos inst_cpu mcode Mode", false,-1, 1,0);
        tracep->declBus(c+507,"top oricatmos inst_cpu mcode IR", false,-1, 7,0);
        tracep->declBus(c+511,"top oricatmos inst_cpu mcode MCycle", false,-1, 2,0);
        tracep->declBus(c+508,"top oricatmos inst_cpu mcode P", false,-1, 7,0);
        tracep->declBit(c+182,"top oricatmos inst_cpu mcode Rdy_mod", false,-1);
        tracep->declBus(c+522,"top oricatmos inst_cpu mcode LCycle", false,-1, 2,0);
        tracep->declBus(c+523,"top oricatmos inst_cpu mcode ALU_Op", false,-1, 4,0);
        tracep->declBus(c+524,"top oricatmos inst_cpu mcode Set_BusA_To", false,-1, 3,0);
        tracep->declBus(c+525,"top oricatmos inst_cpu mcode Set_Addr_To", false,-1, 1,0);
        tracep->declBus(c+526,"top oricatmos inst_cpu mcode Write_Data", false,-1, 3,0);
        tracep->declBus(c+527,"top oricatmos inst_cpu mcode Jump", false,-1, 1,0);
        tracep->declBus(c+528,"top oricatmos inst_cpu mcode BAAdd", false,-1, 1,0);
        tracep->declBus(c+529,"top oricatmos inst_cpu mcode BAQuirk", false,-1, 1,0);
        tracep->declBit(c+530,"top oricatmos inst_cpu mcode BreakAtNA", false,-1);
        tracep->declBit(c+531,"top oricatmos inst_cpu mcode ADAdd", false,-1);
        tracep->declBit(c+532,"top oricatmos inst_cpu mcode AddY", false,-1);
        tracep->declBit(c+533,"top oricatmos inst_cpu mcode PCAdd", false,-1);
        tracep->declBit(c+534,"top oricatmos inst_cpu mcode Inc_S", false,-1);
        tracep->declBit(c+535,"top oricatmos inst_cpu mcode Dec_S", false,-1);
        tracep->declBit(c+536,"top oricatmos inst_cpu mcode LDA", false,-1);
        tracep->declBit(c+537,"top oricatmos inst_cpu mcode LDP", false,-1);
        tracep->declBit(c+538,"top oricatmos inst_cpu mcode LDX", false,-1);
        tracep->declBit(c+539,"top oricatmos inst_cpu mcode LDY", false,-1);
        tracep->declBit(c+540,"top oricatmos inst_cpu mcode LDS", false,-1);
        tracep->declBit(c+541,"top oricatmos inst_cpu mcode LDDI", false,-1);
        tracep->declBit(c+542,"top oricatmos inst_cpu mcode LDALU", false,-1);
        tracep->declBit(c+543,"top oricatmos inst_cpu mcode LDAD", false,-1);
        tracep->declBit(c+544,"top oricatmos inst_cpu mcode LDBAL", false,-1);
        tracep->declBit(c+545,"top oricatmos inst_cpu mcode LDBAH", false,-1);
        tracep->declBit(c+546,"top oricatmos inst_cpu mcode SaveP", false,-1);
        tracep->declBit(c+547,"top oricatmos inst_cpu mcode Write", false,-1);
        tracep->declBit(c+549,"top oricatmos inst_cpu mcode Branch", false,-1);
        tracep->declBit(c+550,"top oricatmos inst_cpu mcode ALUmore", false,-1);
        tracep->declBus(c+721,"top oricatmos inst_cpu alu Flag_C", false,-1, 31,0);
        tracep->declBus(c+688,"top oricatmos inst_cpu alu Flag_Z", false,-1, 31,0);
        tracep->declBus(c+689,"top oricatmos inst_cpu alu Flag_I", false,-1, 31,0);
        tracep->declBus(c+690,"top oricatmos inst_cpu alu Flag_D", false,-1, 31,0);
        tracep->declBus(c+691,"top oricatmos inst_cpu alu Flag_B", false,-1, 31,0);
        tracep->declBus(c+692,"top oricatmos inst_cpu alu Flag_1", false,-1, 31,0);
        tracep->declBus(c+693,"top oricatmos inst_cpu alu Flag_V", false,-1, 31,0);
        tracep->declBus(c+694,"top oricatmos inst_cpu alu Flag_N", false,-1, 31,0);
        tracep->declBus(c+708,"top oricatmos inst_cpu alu Cycle_sync", false,-1, 2,0);
        tracep->declBus(c+722,"top oricatmos inst_cpu alu Cycle_1", false,-1, 2,0);
        tracep->declBus(c+723,"top oricatmos inst_cpu alu Cycle_2", false,-1, 2,0);
        tracep->declBus(c+724,"top oricatmos inst_cpu alu Cycle_3", false,-1, 2,0);
        tracep->declBus(c+725,"top oricatmos inst_cpu alu Cycle_4", false,-1, 2,0);
        tracep->declBus(c+726,"top oricatmos inst_cpu alu Cycle_5", false,-1, 2,0);
        tracep->declBus(c+727,"top oricatmos inst_cpu alu Cycle_6", false,-1, 2,0);
        tracep->declBus(c+728,"top oricatmos inst_cpu alu Cycle_7", false,-1, 2,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_DI", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_DA", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_DAO", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_DAX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_AAX", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu alu T_Set_BusA_To_Set_BusA_To_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+740,"top oricatmos inst_cpu alu T_Set_Addr_To_Set_Addr_To_PBR", false,-1, 1,0);
        tracep->declBus(c+741,"top oricatmos inst_cpu alu T_Set_Addr_To_Set_Addr_To_SP", false,-1, 1,0);
        tracep->declBus(c+742,"top oricatmos inst_cpu alu T_Set_Addr_To_Set_Addr_To_ZPG", false,-1, 1,0);
        tracep->declBus(c+743,"top oricatmos inst_cpu alu T_Set_Addr_To_Set_Addr_To_BA", false,-1, 1,0);
        tracep->declBus(c+729,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_DL", false,-1, 3,0);
        tracep->declBus(c+730,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_X", false,-1, 3,0);
        tracep->declBus(c+732,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_Y", false,-1, 3,0);
        tracep->declBus(c+733,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_S", false,-1, 3,0);
        tracep->declBus(c+734,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_P", false,-1, 3,0);
        tracep->declBus(c+735,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_PCL", false,-1, 3,0);
        tracep->declBus(c+736,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_PCH", false,-1, 3,0);
        tracep->declBus(c+737,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_AX", false,-1, 3,0);
        tracep->declBus(c+738,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_AXB", false,-1, 3,0);
        tracep->declBus(c+739,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_XB", false,-1, 3,0);
        tracep->declBus(c+744,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_YB", false,-1, 3,0);
        tracep->declBus(c+745,"top oricatmos inst_cpu alu T_Write_Data_Write_Data_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+746,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_OR", false,-1, 4,0);
        tracep->declBus(c+747,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_AND", false,-1, 4,0);
        tracep->declBus(c+748,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_EOR", false,-1, 4,0);
        tracep->declBus(c+749,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ADC", false,-1, 4,0);
        tracep->declBus(c+750,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_EQ1", false,-1, 4,0);
        tracep->declBus(c+751,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_EQ2", false,-1, 4,0);
        tracep->declBus(c+752,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_CMP", false,-1, 4,0);
        tracep->declBus(c+753,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_SBC", false,-1, 4,0);
        tracep->declBus(c+754,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ASL", false,-1, 4,0);
        tracep->declBus(c+755,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ROL", false,-1, 4,0);
        tracep->declBus(c+756,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_LSR", false,-1, 4,0);
        tracep->declBus(c+757,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ROR", false,-1, 4,0);
        tracep->declBus(c+758,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_BIT", false,-1, 4,0);
        tracep->declBus(c+759,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_DEC", false,-1, 4,0);
        tracep->declBus(c+760,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_INC", false,-1, 4,0);
        tracep->declBus(c+761,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ARR", false,-1, 4,0);
        tracep->declBus(c+762,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_ANC", false,-1, 4,0);
        tracep->declBus(c+763,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_SAX", false,-1, 4,0);
        tracep->declBus(c+764,"top oricatmos inst_cpu alu T_ALU_OP_ALU_OP_XAA", false,-1, 4,0);
        tracep->declBus(c+174,"top oricatmos inst_cpu alu Mode", false,-1, 1,0);
        tracep->declBus(c+175,"top oricatmos inst_cpu alu Op", false,-1, 4,0);
        tracep->declBus(c+179,"top oricatmos inst_cpu alu BusA", false,-1, 7,0);
        tracep->declBus(c+180,"top oricatmos inst_cpu alu BusB", false,-1, 7,0);
        tracep->declBus(c+508,"top oricatmos inst_cpu alu P_In", false,-1, 7,0);
        tracep->declBus(c+521,"top oricatmos inst_cpu alu P_Out", false,-1, 7,0);
        tracep->declBus(c+520,"top oricatmos inst_cpu alu Q", false,-1, 7,0);
        tracep->declBit(c+551,"top oricatmos inst_cpu alu ADC_Z", false,-1);
        tracep->declBit(c+552,"top oricatmos inst_cpu alu ADC_C", false,-1);
        tracep->declBit(c+553,"top oricatmos inst_cpu alu ADC_V", false,-1);
        tracep->declBit(c+554,"top oricatmos inst_cpu alu ADC_N", false,-1);
        tracep->declBus(c+555,"top oricatmos inst_cpu alu ADC_Q", false,-1, 7,0);
        tracep->declBit(c+556,"top oricatmos inst_cpu alu SBC_Z", false,-1);
        tracep->declBit(c+557,"top oricatmos inst_cpu alu SBC_C", false,-1);
        tracep->declBit(c+558,"top oricatmos inst_cpu alu SBC_V", false,-1);
        tracep->declBit(c+559,"top oricatmos inst_cpu alu SBC_N", false,-1);
        tracep->declBus(c+560,"top oricatmos inst_cpu alu SBC_Q", false,-1, 7,0);
        tracep->declBus(c+561,"top oricatmos inst_cpu alu SBX_Q", false,-1, 7,0);
        tracep->declBus(c+562,"top oricatmos inst_cpu alu xhdl0 AL", false,-1, 6,0);
        tracep->declBus(c+563,"top oricatmos inst_cpu alu xhdl0 AH", false,-1, 6,0);
        tracep->declBit(c+564,"top oricatmos inst_cpu alu xhdl0 C", false,-1);
        tracep->declBus(c+565,"top oricatmos inst_cpu alu xhdl1 AL", false,-1, 6,0);
        tracep->declBus(c+566,"top oricatmos inst_cpu alu xhdl1 AH", false,-1, 5,0);
        tracep->declBit(c+567,"top oricatmos inst_cpu alu xhdl1 C", false,-1);
        tracep->declBit(c+568,"top oricatmos inst_cpu alu xhdl1 CT", false,-1);
        tracep->declBus(c+569,"top oricatmos inst_cpu alu xhdl2 Q_t", false,-1, 7,0);
        tracep->declBus(c+570,"top oricatmos inst_cpu alu xhdl2 Q2_t", false,-1, 7,0);
        tracep->declBit(c+610,"top oricatmos inst_rom0 clk", false,-1);
        tracep->declBus(c+571,"top oricatmos inst_rom0 addr", false,-1, 13,0);
        tracep->declBus(c+233,"top oricatmos inst_rom0 data", false,-1, 7,0);
        tracep->declBit(c+610,"top oricatmos inst_rom1 clk", false,-1);
        tracep->declBus(c+571,"top oricatmos inst_rom1 addr", false,-1, 13,0);
        tracep->declBus(c+234,"top oricatmos inst_rom1 data", false,-1, 7,0);
        tracep->declBus(c+572,"top oricatmos inst_rom2 addr", false,-1, 12,0);
        tracep->declBit(c+610,"top oricatmos inst_rom2 clk", false,-1);
        tracep->declBus(c+235,"top oricatmos inst_rom2 data", false,-1, 7,0);
        tracep->declBit(c+442,"top oricatmos inst_ula RESETn", false,-1);
        tracep->declBit(c+582,"top oricatmos inst_ula CLK_4", false,-1);
        tracep->declBit(c+583,"top oricatmos inst_ula CLK_4_EN", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_ula CLK", false,-1);
        tracep->declBit(c+466,"top oricatmos inst_ula PHI2", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_ula PHI2_EN", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_ula RW", false,-1);
        tracep->declBit(c+592,"top oricatmos inst_ula MAPn", false,-1);
        tracep->declBus(c+450,"top oricatmos inst_ula DB", false,-1, 7,0);
        tracep->declBus(c+573,"top oricatmos inst_ula ADDR", false,-1, 15,0);
        tracep->declBit(c+591,"top oricatmos inst_ula CSRAMn", false,-1);
        tracep->declBus(c+451,"top oricatmos inst_ula SRAM_AD", false,-1, 15,0);
        tracep->declBit(c+643,"top oricatmos inst_ula SRAM_OE", false,-1);
        tracep->declBit(c+642,"top oricatmos inst_ula SRAM_CE", false,-1);
        tracep->declBit(c+644,"top oricatmos inst_ula SRAM_WE", false,-1);
        tracep->declBit(c+581,"top oricatmos inst_ula LATCH_SRAM", false,-1);
        tracep->declBit(c+590,"top oricatmos inst_ula CSIOn", false,-1);
        tracep->declBit(c+641,"top oricatmos inst_ula CSROMn", false,-1);
        tracep->declBit(c+483,"top oricatmos inst_ula R", false,-1);
        tracep->declBit(c+484,"top oricatmos inst_ula G", false,-1);
        tracep->declBit(c+485,"top oricatmos inst_ula B", false,-1);
        tracep->declBit(c+636,"top oricatmos inst_ula SYNC", false,-1);
        tracep->declBit(c+580,"top oricatmos inst_ula CLK_PIX", false,-1);
        tracep->declBit(c+618,"top oricatmos inst_ula HBLANK", false,-1);
        tracep->declBit(c+619,"top oricatmos inst_ula VBLANK", false,-1);
        tracep->declBit(c+616,"top oricatmos inst_ula HSYNC", false,-1);
        tracep->declBit(c+617,"top oricatmos inst_ula VSYNC", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_ula CLK_24", false,-1);
        tracep->declBit(c+582,"top oricatmos inst_ula CLK_4_INT", false,-1);
        tracep->declBit(c+466,"top oricatmos inst_ula CLK_1_INT", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_ula CLK_1_EN", false,-1);
        tracep->declBit(c+580,"top oricatmos inst_ula CLK_PIXEL_INT", false,-1);
        tracep->declBit(c+189,"top oricatmos inst_ula CLK_FLASH", false,-1);
        tracep->declBus(c+450,"top oricatmos inst_ula DB_INT", false,-1, 7,0);
        tracep->declBus(c+653,"top oricatmos inst_ula VAP1", false,-1, 15,0);
        tracep->declBus(c+654,"top oricatmos inst_ula VAP2", false,-1, 15,0);
        tracep->declBus(c+573,"top oricatmos inst_ula lADDR", false,-1, 15,0);
        tracep->declBit(c+501,"top oricatmos inst_ula RW_INT", false,-1);
        tracep->declBit(c+220,"top oricatmos inst_ula lHIRES_SEL", false,-1);
        tracep->declBit(c+486,"top oricatmos inst_ula HIRES_DEC", false,-1);
        tracep->declBit(c+487,"top oricatmos inst_ula lDBLHGT_SEL", false,-1);
        tracep->declBit(c+488,"top oricatmos inst_ula lALT_SEL", false,-1);
        tracep->declBit(c+467,"top oricatmos inst_ula lFORCETXT", false,-1);
        tracep->declBit(c+356,"top oricatmos inst_ula isAttrib", false,-1);
        tracep->declBit(c+585,"top oricatmos inst_ula ATTRIB_DEC", false,-1);
        tracep->declBit(c+586,"top oricatmos inst_ula RELD_REG", false,-1);
        tracep->declBit(c+587,"top oricatmos inst_ula DATABUS_EN", false,-1);
        tracep->declBit(c+636,"top oricatmos inst_ula lCOMPSYNC", false,-1);
        tracep->declBit(c+468,"top oricatmos inst_ula lHSYNCn", false,-1);
        tracep->declBit(c+469,"top oricatmos inst_ula lVSYNC50n", false,-1);
        tracep->declBit(c+470,"top oricatmos inst_ula lVSYNC60n", false,-1);
        tracep->declBit(c+655,"top oricatmos inst_ula lVSYNCn", false,-1);
        tracep->declBit(c+471,"top oricatmos inst_ula BLANKINGn", false,-1);
        tracep->declBit(c+472,"top oricatmos inst_ula lRELOAD_SEL", false,-1);
        tracep->declBit(c+221,"top oricatmos inst_ula lFREQ_SEL", false,-1);
        tracep->declBit(c+656,"top oricatmos inst_ula LDFROMBUS", false,-1);
        tracep->declBus(c+657,"top oricatmos inst_ula CHROWCNT", false,-1, 2,0);
        tracep->declBus(c+473,"top oricatmos inst_ula lCTR_H", false,-1, 6,0);
        tracep->declBus(c+474,"top oricatmos inst_ula lCTR_V", false,-1, 8,0);
        tracep->declBus(c+489,"top oricatmos inst_ula RGB_INT", false,-1, 2,0);
        tracep->declBit(c+591,"top oricatmos inst_ula CSRAMn_INT", false,-1);
        tracep->declBit(c+590,"top oricatmos inst_ula CSIOn_INT", false,-1);
        tracep->declBit(c+641,"top oricatmos inst_ula CSROMn_INT", false,-1);
        tracep->declBus(c+451,"top oricatmos inst_ula AD_RAM_INT", false,-1, 15,0);
        tracep->declBit(c+444,"top oricatmos inst_ula RESET_INT", false,-1);
        tracep->declBit(c+592,"top oricatmos inst_ula lMAPn", false,-1);
        tracep->declBit(c+490,"top oricatmos inst_ula DBLHGT_EN", false,-1);
        tracep->declBus(c+491,"top oricatmos inst_ula CTR_V_DIV8", false,-1, 8,0);
        tracep->declBus(c+492,"top oricatmos inst_ula voffset", false,-1, 15,0);
        tracep->declBus(c+493,"top oricatmos inst_ula mulBy40", false,-1, 14,0);
        tracep->declBus(c+588,"top oricatmos inst_ula c", false,-1, 23,0);
        tracep->declBus(c+475,"top oricatmos inst_ula ph", false,-1, 2,0);
        tracep->declBus(c+190,"top oricatmos inst_ula lCTR_FLASH", false,-1, 4,0);
        tracep->declBit(c+476,"top oricatmos inst_ula lVBLANKn", false,-1);
        tracep->declBit(c+477,"top oricatmos inst_ula lHBLANKn", false,-1);
        tracep->declBus(c+452,"top oricatmos inst_ula lDATABUS", false,-1, 7,0);
        tracep->declBus(c+31,"top oricatmos inst_ula lSHFREG", false,-1, 5,0);
        tracep->declBus(c+357,"top oricatmos inst_ula lREGHOLD", false,-1, 6,0);
        tracep->declBus(c+494,"top oricatmos inst_ula lRGB", false,-1, 2,0);
        tracep->declBus(c+222,"top oricatmos inst_ula lREG_INK", false,-1, 2,0);
        tracep->declBus(c+495,"top oricatmos inst_ula lREG_STYLE", false,-1, 2,0);
        tracep->declBus(c+223,"top oricatmos inst_ula lREG_PAPER", false,-1, 2,0);
        tracep->declBus(c+224,"top oricatmos inst_ula lREG_MODE", false,-1, 2,0);
        tracep->declBus(c+496,"top oricatmos inst_ula ModeStyle", false,-1, 1,0);
        tracep->declBus(c+497,"top oricatmos inst_ula lADD", false,-1, 5,0);
        tracep->declBit(c+32,"top oricatmos inst_ula lInv", false,-1);
        tracep->declBit(c+191,"top oricatmos inst_ula lInv_hold", false,-1);
        tracep->declBit(c+658,"top oricatmos inst_ula lBGFG_SEL", false,-1);
        tracep->declBit(c+498,"top oricatmos inst_ula lFLASH_SEL", false,-1);
        tracep->declBus(c+574,"top oricatmos inst_via I_RS", false,-1, 3,0);
        tracep->declBus(c+499,"top oricatmos inst_via I_DATA", false,-1, 7,0);
        tracep->declBus(c+589,"top oricatmos inst_via O_DATA", false,-1, 7,0);
        tracep->declBit(c+594,"top oricatmos inst_via O_DATA_OE_L", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_via I_RW_L", false,-1);
        tracep->declBit(c+593,"top oricatmos inst_via I_CS1", false,-1);
        tracep->declBit(c+590,"top oricatmos inst_via I_CS2_L", false,-1);
        tracep->declBit(c+184,"top oricatmos inst_via O_IRQ_L", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_via I_CA1", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_via I_CA2", false,-1);
        tracep->declBit(c+354,"top oricatmos inst_via O_CA2", false,-1);
        tracep->declBit(c+188,"top oricatmos inst_via O_CA2_OE_L", false,-1);
        tracep->declBus(c+638,"top oricatmos inst_via I_PA", false,-1, 7,0);
        tracep->declBus(c+350,"top oricatmos inst_via O_PA", false,-1, 7,0);
        tracep->declBus(c+185,"top oricatmos inst_via O_PA_OE_L", false,-1, 7,0);
        tracep->declBit(c+674,"top oricatmos inst_via I_CB1", false,-1);
        tracep->declBit(c+351,"top oricatmos inst_via O_CB1", false,-1);
        tracep->declBit(c+186,"top oricatmos inst_via O_CB1_OE_L", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_via I_CB2", false,-1);
        tracep->declBit(c+352,"top oricatmos inst_via O_CB2", false,-1);
        tracep->declBit(c+187,"top oricatmos inst_via O_CB2_OE_L", false,-1);
        tracep->declBus(c+639,"top oricatmos inst_via I_PB", false,-1, 7,0);
        tracep->declBus(c+353,"top oricatmos inst_via O_PB", false,-1, 7,0);
        tracep->declBus(c+192,"top oricatmos inst_via O_PB_OE_L", false,-1, 7,0);
        tracep->declBit(c+466,"top oricatmos inst_via I_P2_H", false,-1);
        tracep->declBit(c+442,"top oricatmos inst_via RESET_L", false,-1);
        tracep->declBit(c+583,"top oricatmos inst_via ENA_4", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_via CLK", false,-1);
        tracep->declBus(c+453,"top oricatmos inst_via phase", false,-1, 1,0);
        tracep->declBit(c+33,"top oricatmos inst_via p2_h_t1", false,-1);
        tracep->declBit(c+454,"top oricatmos inst_via p2_h_dl", false,-1);
        tracep->declBit(c+595,"top oricatmos inst_via cs", false,-1);
        tracep->declBus(c+193,"top oricatmos inst_via r_ddra", false,-1, 7,0);
        tracep->declBus(c+350,"top oricatmos inst_via r_ora", false,-1, 7,0);
        tracep->declBus(c+194,"top oricatmos inst_via r_ira", false,-1, 7,0);
        tracep->declBus(c+195,"top oricatmos inst_via r_ddrb", false,-1, 7,0);
        tracep->declBus(c+196,"top oricatmos inst_via r_orb", false,-1, 7,0);
        tracep->declBus(c+197,"top oricatmos inst_via r_irb", false,-1, 7,0);
        tracep->declBus(c+198,"top oricatmos inst_via r_t1l_l", false,-1, 7,0);
        tracep->declBus(c+199,"top oricatmos inst_via r_t1l_h", false,-1, 7,0);
        tracep->declBus(c+478,"top oricatmos inst_via r_t2l_l", false,-1, 7,0);
        tracep->declBus(c+479,"top oricatmos inst_via r_t2l_h", false,-1, 7,0);
        tracep->declBus(c+358,"top oricatmos inst_via r_sr", false,-1, 7,0);
        tracep->declBus(c+480,"top oricatmos inst_via r_acr", false,-1, 7,0);
        tracep->declBus(c+359,"top oricatmos inst_via r_pcr", false,-1, 7,0);
        tracep->declBus(c+360,"top oricatmos inst_via r_ifr", false,-1, 7,0);
        tracep->declBus(c+200,"top oricatmos inst_via r_ier", false,-1, 6,0);
        tracep->declBit(c+361,"top oricatmos inst_via sr_write_ena", false,-1);
        tracep->declBit(c+596,"top oricatmos inst_via sr_read_ena", false,-1);
        tracep->declBit(c+201,"top oricatmos inst_via ifr_write_ena", false,-1);
        tracep->declBit(c+202,"top oricatmos inst_via ier_write_ena", false,-1);
        tracep->declBus(c+362,"top oricatmos inst_via clear_irq", false,-1, 7,0);
        tracep->declBus(c+363,"top oricatmos inst_via load_data", false,-1, 7,0);
        tracep->declBus(c+238,"top oricatmos inst_via t1c", false,-1, 15,0);
        tracep->declBit(c+239,"top oricatmos inst_via t1c_active", false,-1);
        tracep->declBit(c+240,"top oricatmos inst_via t1c_done", false,-1);
        tracep->declBit(c+364,"top oricatmos inst_via t1_w_reset_int", false,-1);
        tracep->declBit(c+597,"top oricatmos inst_via t1_r_reset_int", false,-1);
        tracep->declBit(c+365,"top oricatmos inst_via t1_load_counter", false,-1);
        tracep->declBit(c+241,"top oricatmos inst_via t1_reload_counter", false,-1);
        tracep->declBit(c+242,"top oricatmos inst_via t1_int_enable", false,-1);
        tracep->declBit(c+243,"top oricatmos inst_via t1_toggle", false,-1);
        tracep->declBit(c+244,"top oricatmos inst_via t1_irq", false,-1);
        tracep->declBit(c+203,"top oricatmos inst_via t1_pb7", false,-1);
        tracep->declBit(c+245,"top oricatmos inst_via t1_pb7_en_c", false,-1);
        tracep->declBit(c+246,"top oricatmos inst_via t1_pb7_en_d", false,-1);
        tracep->declBus(c+455,"top oricatmos inst_via t2c", false,-1, 15,0);
        tracep->declBit(c+34,"top oricatmos inst_via t2c_active", false,-1);
        tracep->declBit(c+35,"top oricatmos inst_via t2c_done", false,-1);
        tracep->declBit(c+456,"top oricatmos inst_via t2_pb6", false,-1);
        tracep->declBit(c+457,"top oricatmos inst_via t2_pb6_t1", false,-1);
        tracep->declBit(c+458,"top oricatmos inst_via t2_cnt_clk", false,-1);
        tracep->declBit(c+204,"top oricatmos inst_via t2_w_reset_int", false,-1);
        tracep->declBit(c+598,"top oricatmos inst_via t2_r_reset_int", false,-1);
        tracep->declBit(c+481,"top oricatmos inst_via t2_load_counter", false,-1);
        tracep->declBit(c+459,"top oricatmos inst_via t2_reload_counter", false,-1);
        tracep->declBit(c+36,"top oricatmos inst_via t2_int_enable", false,-1);
        tracep->declBit(c+37,"top oricatmos inst_via t2_irq", false,-1);
        tracep->declBit(c+460,"top oricatmos inst_via t2_sr_ena", false,-1);
        tracep->declBus(c+366,"top oricatmos inst_via sr_cnt", false,-1, 3,0);
        tracep->declBit(c+186,"top oricatmos inst_via sr_cb1_oe_l", false,-1);
        tracep->declBit(c+351,"top oricatmos inst_via sr_cb1_out", false,-1);
        tracep->declBit(c+367,"top oricatmos inst_via sr_drive_cb2", false,-1);
        tracep->declBit(c+482,"top oricatmos inst_via sr_strobe", false,-1);
        tracep->declBit(c+368,"top oricatmos inst_via sr_do_shift", false,-1);
        tracep->declBit(c+461,"top oricatmos inst_via sr_strobe_t1", false,-1);
        tracep->declBit(c+462,"top oricatmos inst_via sr_strobe_falling", false,-1);
        tracep->declBit(c+463,"top oricatmos inst_via sr_strobe_rising", false,-1);
        tracep->declBit(c+369,"top oricatmos inst_via sr_irq", false,-1);
        tracep->declBit(c+370,"top oricatmos inst_via sr_out", false,-1);
        tracep->declBit(c+371,"top oricatmos inst_via sr_active", false,-1);
        tracep->declBit(c+372,"top oricatmos inst_via w_orb_hs", false,-1);
        tracep->declBit(c+373,"top oricatmos inst_via w_ora_hs", false,-1);
        tracep->declBit(c+599,"top oricatmos inst_via r_irb_hs", false,-1);
        tracep->declBit(c+600,"top oricatmos inst_via r_ira_hs", false,-1);
        tracep->declBit(c+374,"top oricatmos inst_via ca_hs_sr", false,-1);
        tracep->declBit(c+375,"top oricatmos inst_via ca_hs_pulse", false,-1);
        tracep->declBit(c+376,"top oricatmos inst_via cb_hs_sr", false,-1);
        tracep->declBit(c+377,"top oricatmos inst_via cb_hs_pulse", false,-1);
        tracep->declBit(c+205,"top oricatmos inst_via cb1_in_mux", false,-1);
        tracep->declBit(c+206,"top oricatmos inst_via ca1_ip_reg_c", false,-1);
        tracep->declBit(c+207,"top oricatmos inst_via ca1_ip_reg_d", false,-1);
        tracep->declBit(c+208,"top oricatmos inst_via cb1_ip_reg_c", false,-1);
        tracep->declBit(c+209,"top oricatmos inst_via cb1_ip_reg_d", false,-1);
        tracep->declBit(c+378,"top oricatmos inst_via ca1_int", false,-1);
        tracep->declBit(c+379,"top oricatmos inst_via cb1_int", false,-1);
        tracep->declBit(c+210,"top oricatmos inst_via ca1_irq", false,-1);
        tracep->declBit(c+211,"top oricatmos inst_via cb1_irq", false,-1);
        tracep->declBit(c+212,"top oricatmos inst_via ca2_ip_reg_c", false,-1);
        tracep->declBit(c+213,"top oricatmos inst_via ca2_ip_reg_d", false,-1);
        tracep->declBit(c+214,"top oricatmos inst_via cb2_ip_reg_c", false,-1);
        tracep->declBit(c+215,"top oricatmos inst_via cb2_ip_reg_d", false,-1);
        tracep->declBit(c+380,"top oricatmos inst_via ca2_int", false,-1);
        tracep->declBit(c+381,"top oricatmos inst_via cb2_int", false,-1);
        tracep->declBit(c+216,"top oricatmos inst_via ca2_irq", false,-1);
        tracep->declBit(c+217,"top oricatmos inst_via cb2_irq", false,-1);
        tracep->declBit(c+218,"top oricatmos inst_via final_irq", false,-1);
        tracep->declBus(c+601,"top oricatmos inst_via orb", false,-1, 7,0);
        tracep->declBit(c+247,"top oricatmos inst_via p_timer1_done done", false,-1);
        tracep->declBit(c+38,"top oricatmos inst_via p_timer2_done done", false,-1);
        tracep->declBit(c+464,"top oricatmos inst_via p_timer2_done done_sr", false,-1);
        tracep->declBit(c+465,"top oricatmos inst_via p_timer2 ena", false,-1);
        tracep->declBit(c+382,"top oricatmos inst_via p_sr dir_out", false,-1);
        tracep->declBit(c+383,"top oricatmos inst_via p_sr ena", false,-1);
        tracep->declBit(c+219,"top oricatmos inst_via p_sr cb1_op", false,-1);
        tracep->declBit(c+384,"top oricatmos inst_via p_sr cb1_ip", false,-1);
        tracep->declBit(c+385,"top oricatmos inst_via p_sr use_t2", false,-1);
        tracep->declBit(c+386,"top oricatmos inst_via p_sr free_run", false,-1);
        tracep->declBit(c+387,"top oricatmos inst_via p_sr sr_count_ena", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg rst_n", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg clk", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_psg clk_en", false,-1);
        tracep->declBit(c+352,"top oricatmos inst_psg bdir", false,-1);
        tracep->declBit(c+354,"top oricatmos inst_psg bc1", false,-1);
        tracep->declBus(c+350,"top oricatmos inst_psg din", false,-1, 7,0);
        tracep->declBit(c+686,"top oricatmos inst_psg sel", false,-1);
        tracep->declBus(c+138,"top oricatmos inst_psg dout", false,-1, 7,0);
        tracep->declBus(c+137,"top oricatmos inst_psg sound", false,-1, 9,0);
        tracep->declBus(c+134,"top oricatmos inst_psg A", false,-1, 7,0);
        tracep->declBus(c+135,"top oricatmos inst_psg B", false,-1, 7,0);
        tracep->declBus(c+136,"top oricatmos inst_psg C", false,-1, 7,0);
        tracep->declBit(c+232,"top oricatmos inst_psg sample", false,-1);
        tracep->declBus(c+703,"top oricatmos inst_psg IOA_in", false,-1, 7,0);
        tracep->declBus(c+389,"top oricatmos inst_psg IOA_out", false,-1, 7,0);
        tracep->declBus(c+703,"top oricatmos inst_psg IOB_in", false,-1, 7,0);
        tracep->declBus(c+390,"top oricatmos inst_psg IOB_out", false,-1, 7,0);
        tracep->declBus(c+740,"top oricatmos inst_psg COMP", false,-1, 1,0);
        tracep->declBit(c+39,"top oricatmos inst_psg wr_n", false,-1);
        tracep->declBit(c+40,"top oricatmos inst_psg cs_n", false,-1);
        tracep->declBus(c+248,"top oricatmos inst_psg addr", false,-1, 3,0);
        tracep->declBit(c+41,"top oricatmos inst_psg addr_ok", false,-1);
        tracep->declBus(c+249,"top oricatmos inst_psg din_latch", false,-1, 7,0);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 rst_n", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 clk", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_psg u_jt49 clk_en", false,-1);
        tracep->declBus(c+248,"top oricatmos inst_psg u_jt49 addr", false,-1, 3,0);
        tracep->declBit(c+40,"top oricatmos inst_psg u_jt49 cs_n", false,-1);
        tracep->declBit(c+39,"top oricatmos inst_psg u_jt49 wr_n", false,-1);
        tracep->declBus(c+249,"top oricatmos inst_psg u_jt49 din", false,-1, 7,0);
        tracep->declBit(c+686,"top oricatmos inst_psg u_jt49 sel", false,-1);
        tracep->declBus(c+138,"top oricatmos inst_psg u_jt49 dout", false,-1, 7,0);
        tracep->declBus(c+137,"top oricatmos inst_psg u_jt49 sound", false,-1, 9,0);
        tracep->declBus(c+134,"top oricatmos inst_psg u_jt49 A", false,-1, 7,0);
        tracep->declBus(c+135,"top oricatmos inst_psg u_jt49 B", false,-1, 7,0);
        tracep->declBus(c+136,"top oricatmos inst_psg u_jt49 C", false,-1, 7,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 sample", false,-1);
        tracep->declBus(c+703,"top oricatmos inst_psg u_jt49 IOA_in", false,-1, 7,0);
        tracep->declBus(c+389,"top oricatmos inst_psg u_jt49 IOA_out", false,-1, 7,0);
        tracep->declBus(c+703,"top oricatmos inst_psg u_jt49 IOB_in", false,-1, 7,0);
        tracep->declBus(c+390,"top oricatmos inst_psg u_jt49 IOB_out", false,-1, 7,0);
        tracep->declBus(c+740,"top oricatmos inst_psg u_jt49 COMP", false,-1, 1,0);
        tracep->declBus(c+690,"top oricatmos inst_psg u_jt49 CLKDIV", false,-1, 31,0);
        tracep->declBus(c+740,"top oricatmos inst_psg u_jt49 comp", false,-1, 1,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+391+i*1,"top oricatmos inst_psg u_jt49 regarray", true,(i+0), 7,0);}}
        tracep->declBus(c+407,"top oricatmos inst_psg u_jt49 port_A", false,-1, 7,0);
        tracep->declBus(c+408,"top oricatmos inst_psg u_jt49 port_B", false,-1, 7,0);
        tracep->declBus(c+250,"top oricatmos inst_psg u_jt49 envelope", false,-1, 4,0);
        tracep->declBit(c+409,"top oricatmos inst_psg u_jt49 bitA", false,-1);
        tracep->declBit(c+410,"top oricatmos inst_psg u_jt49 bitB", false,-1);
        tracep->declBit(c+411,"top oricatmos inst_psg u_jt49 bitC", false,-1);
        tracep->declBit(c+251,"top oricatmos inst_psg u_jt49 noise", false,-1);
        tracep->declBit(c+252,"top oricatmos inst_psg u_jt49 Amix", false,-1);
        tracep->declBit(c+253,"top oricatmos inst_psg u_jt49 Bmix", false,-1);
        tracep->declBit(c+254,"top oricatmos inst_psg u_jt49 Cmix", false,-1);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 cen16", false,-1);
        tracep->declBit(c+255,"top oricatmos inst_psg u_jt49 cen256", false,-1);
        tracep->declBit(c+139,"top oricatmos inst_psg u_jt49 eg_step", false,-1);
        tracep->declBus(c+412,"top oricatmos inst_psg u_jt49 eg_period", false,-1, 15,0);
        tracep->declBit(c+413,"top oricatmos inst_psg u_jt49 null_period", false,-1);
        tracep->declBit(c+140,"top oricatmos inst_psg u_jt49 eg_restart", false,-1);
        tracep->declBus(c+256,"top oricatmos inst_psg u_jt49 logA", false,-1, 4,0);
        tracep->declBus(c+257,"top oricatmos inst_psg u_jt49 logB", false,-1, 4,0);
        tracep->declBus(c+258,"top oricatmos inst_psg u_jt49 logC", false,-1, 4,0);
        tracep->declBus(c+414,"top oricatmos inst_psg u_jt49 log", false,-1, 4,0);
        tracep->declBus(c+259,"top oricatmos inst_psg u_jt49 lin", false,-1, 7,0);
        tracep->declBus(c+415,"top oricatmos inst_psg u_jt49 volA", false,-1, 4,0);
        tracep->declBus(c+416,"top oricatmos inst_psg u_jt49 volB", false,-1, 4,0);
        tracep->declBus(c+417,"top oricatmos inst_psg u_jt49 volC", false,-1, 4,0);
        tracep->declBit(c+418,"top oricatmos inst_psg u_jt49 use_envA", false,-1);
        tracep->declBit(c+419,"top oricatmos inst_psg u_jt49 use_envB", false,-1);
        tracep->declBit(c+420,"top oricatmos inst_psg u_jt49 use_envC", false,-1);
        tracep->declBit(c+421,"top oricatmos inst_psg u_jt49 use_noA", false,-1);
        tracep->declBit(c+422,"top oricatmos inst_psg u_jt49 use_noB", false,-1);
        tracep->declBit(c+423,"top oricatmos inst_psg u_jt49 use_noC", false,-1);
        tracep->declBus(c+141,"top oricatmos inst_psg u_jt49 acc_st", false,-1, 3,0);
        tracep->declBus(c+142,"top oricatmos inst_psg u_jt49 acc", false,-1, 9,0);
        tracep->declBus(c+260,"top oricatmos inst_psg u_jt49 read_mask", false,-1, 7,0);
        tracep->declBit(c+261,"top oricatmos inst_psg u_jt49 write", false,-1);
        tracep->declBit(c+143,"top oricatmos inst_psg u_jt49 last_write", false,-1);
        tracep->declBit(c+659,"top oricatmos inst_psg u_jt49 wr_edge", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_cen clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_cen rst_n", false,-1);
        tracep->declBit(c+584,"top oricatmos inst_psg u_jt49 u_cen cen", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_psg u_jt49 u_cen sel", false,-1);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_cen cen16", false,-1);
        tracep->declBit(c+255,"top oricatmos inst_psg u_jt49 u_cen cen256", false,-1);
        tracep->declBus(c+424,"top oricatmos inst_psg u_jt49 u_cen cencnt", false,-1, 9,0);
        tracep->declBus(c+690,"top oricatmos inst_psg u_jt49 u_cen CLKDIV", false,-1, 31,0);
        tracep->declBus(c+690,"top oricatmos inst_psg u_jt49 u_cen eg", false,-1, 31,0);
        tracep->declBit(c+425,"top oricatmos inst_psg u_jt49 u_cen toggle16", false,-1);
        tracep->declBit(c+426,"top oricatmos inst_psg u_jt49 u_cen toggle256", false,-1);
        tracep->declBus(c+766,"top oricatmos inst_psg u_jt49 u_chA W", false,-1, 31,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_chA cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_chA clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_chA rst_n", false,-1);
        tracep->declBus(c+427,"top oricatmos inst_psg u_jt49 u_chA period", false,-1, 11,0);
        tracep->declBit(c+409,"top oricatmos inst_psg u_jt49 u_chA div", false,-1);
        tracep->declBus(c+144,"top oricatmos inst_psg u_jt49 u_chA count", false,-1, 11,0);
        tracep->declBus(c+767,"top oricatmos inst_psg u_jt49 u_chA one", false,-1, 11,0);
        tracep->declBus(c+766,"top oricatmos inst_psg u_jt49 u_chB W", false,-1, 31,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_chB cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_chB clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_chB rst_n", false,-1);
        tracep->declBus(c+428,"top oricatmos inst_psg u_jt49 u_chB period", false,-1, 11,0);
        tracep->declBit(c+410,"top oricatmos inst_psg u_jt49 u_chB div", false,-1);
        tracep->declBus(c+145,"top oricatmos inst_psg u_jt49 u_chB count", false,-1, 11,0);
        tracep->declBus(c+767,"top oricatmos inst_psg u_jt49 u_chB one", false,-1, 11,0);
        tracep->declBus(c+766,"top oricatmos inst_psg u_jt49 u_chC W", false,-1, 31,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_chC cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_chC clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_chC rst_n", false,-1);
        tracep->declBus(c+429,"top oricatmos inst_psg u_jt49 u_chC period", false,-1, 11,0);
        tracep->declBit(c+411,"top oricatmos inst_psg u_jt49 u_chC div", false,-1);
        tracep->declBus(c+146,"top oricatmos inst_psg u_jt49 u_chC count", false,-1, 11,0);
        tracep->declBus(c+767,"top oricatmos inst_psg u_jt49 u_chC one", false,-1, 11,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_ng cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_ng clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_ng rst_n", false,-1);
        tracep->declBus(c+430,"top oricatmos inst_psg u_jt49 u_ng period", false,-1, 4,0);
        tracep->declBit(c+251,"top oricatmos inst_psg u_jt49 u_ng noise", false,-1);
        tracep->declBus(c+768,"top oricatmos inst_psg u_jt49 u_ng count", false,-1, 5,0);
        tracep->declBus(c+431,"top oricatmos inst_psg u_jt49 u_ng poly17", false,-1, 16,0);
        tracep->declBit(c+432,"top oricatmos inst_psg u_jt49 u_ng poly17_zero", false,-1);
        tracep->declBit(c+147,"top oricatmos inst_psg u_jt49 u_ng noise_en", false,-1);
        tracep->declBit(c+148,"top oricatmos inst_psg u_jt49 u_ng last_en", false,-1);
        tracep->declBit(c+149,"top oricatmos inst_psg u_jt49 u_ng noise_up", false,-1);
        tracep->declBus(c+692,"top oricatmos inst_psg u_jt49 u_ng u_div W", false,-1, 31,0);
        tracep->declBit(c+232,"top oricatmos inst_psg u_jt49 u_ng u_div cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_ng u_div clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_ng u_div rst_n", false,-1);
        tracep->declBus(c+430,"top oricatmos inst_psg u_jt49 u_ng u_div period", false,-1, 4,0);
        tracep->declBit(c+147,"top oricatmos inst_psg u_jt49 u_ng u_div div", false,-1);
        tracep->declBus(c+150,"top oricatmos inst_psg u_jt49 u_ng u_div count", false,-1, 4,0);
        tracep->declBus(c+747,"top oricatmos inst_psg u_jt49 u_ng u_div one", false,-1, 4,0);
        tracep->declBus(c+685,"top oricatmos inst_psg u_jt49 u_envdiv W", false,-1, 31,0);
        tracep->declBit(c+255,"top oricatmos inst_psg u_jt49 u_envdiv cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_envdiv clk", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_envdiv rst_n", false,-1);
        tracep->declBus(c+412,"top oricatmos inst_psg u_jt49 u_envdiv period", false,-1, 15,0);
        tracep->declBit(c+139,"top oricatmos inst_psg u_jt49 u_envdiv div", false,-1);
        tracep->declBus(c+151,"top oricatmos inst_psg u_jt49 u_envdiv count", false,-1, 15,0);
        tracep->declBus(c+769,"top oricatmos inst_psg u_jt49 u_envdiv one", false,-1, 15,0);
        tracep->declBit(c+255,"top oricatmos inst_psg u_jt49 u_env cen", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_env clk", false,-1);
        tracep->declBit(c+139,"top oricatmos inst_psg u_jt49 u_env step", false,-1);
        tracep->declBit(c+413,"top oricatmos inst_psg u_jt49 u_env null_period", false,-1);
        tracep->declBit(c+445,"top oricatmos inst_psg u_jt49 u_env rst_n", false,-1);
        tracep->declBit(c+140,"top oricatmos inst_psg u_jt49 u_env restart", false,-1);
        tracep->declBus(c+433,"top oricatmos inst_psg u_jt49 u_env ctrl", false,-1, 3,0);
        tracep->declBus(c+250,"top oricatmos inst_psg u_jt49 u_env env", false,-1, 4,0);
        tracep->declBit(c+434,"top oricatmos inst_psg u_jt49 u_env inv", false,-1);
        tracep->declBit(c+152,"top oricatmos inst_psg u_jt49 u_env stop", false,-1);
        tracep->declBus(c+435,"top oricatmos inst_psg u_jt49 u_env gain", false,-1, 4,0);
        tracep->declBit(c+436,"top oricatmos inst_psg u_jt49 u_env CONT", false,-1);
        tracep->declBit(c+437,"top oricatmos inst_psg u_jt49 u_env ATT", false,-1);
        tracep->declBit(c+438,"top oricatmos inst_psg u_jt49 u_env ALT", false,-1);
        tracep->declBit(c+439,"top oricatmos inst_psg u_jt49 u_env HOLD", false,-1);
        tracep->declBit(c+440,"top oricatmos inst_psg u_jt49 u_env will_hold", false,-1);
        tracep->declBit(c+153,"top oricatmos inst_psg u_jt49 u_env last_step", false,-1);
        tracep->declBit(c+660,"top oricatmos inst_psg u_jt49 u_env step_edge", false,-1);
        tracep->declBit(c+441,"top oricatmos inst_psg u_jt49 u_env will_invert", false,-1);
        tracep->declBit(c+262,"top oricatmos inst_psg u_jt49 u_env rst_latch", false,-1);
        tracep->declBit(c+154,"top oricatmos inst_psg u_jt49 u_env rst_clr", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_psg u_jt49 u_exp clk", false,-1);
        tracep->declBus(c+740,"top oricatmos inst_psg u_jt49 u_exp comp", false,-1, 1,0);
        tracep->declBus(c+414,"top oricatmos inst_psg u_jt49 u_exp din", false,-1, 4,0);
        tracep->declBus(c+259,"top oricatmos inst_psg u_jt49 u_exp dout", false,-1, 7,0);
        tracep->declBit(c+610,"top oricatmos inst_key clk_sys", false,-1);
        tracep->declBit(c+444,"top oricatmos inst_key reset", false,-1);
        tracep->declBit(c+699,"top oricatmos inst_key key_pressed", false,-1);
        tracep->declBit(c+700,"top oricatmos inst_key key_extended", false,-1);
        tracep->declBit(c+673,"top oricatmos inst_key key_strobe", false,-1);
        tracep->declBus(c+701,"top oricatmos inst_key key_code", false,-1, 7,0);
        tracep->declBus(c+388,"top oricatmos inst_key col", false,-1, 2,0);
        tracep->declBus(c+389,"top oricatmos inst_key row", false,-1, 7,0);
        tracep->declBus(c+26,"top oricatmos inst_key ROWbit", false,-1, 7,0);
        tracep->declBit(c+28,"top oricatmos inst_key swrst", false,-1);
        tracep->declBit(c+645,"top oricatmos inst_key swnmi", false,-1);
        tracep->declBit(c+42,"top oricatmos inst_key sw0", false,-1);
        tracep->declBit(c+43,"top oricatmos inst_key sw1", false,-1);
        tracep->declBit(c+44,"top oricatmos inst_key sw2", false,-1);
        tracep->declBit(c+45,"top oricatmos inst_key sw3", false,-1);
        tracep->declBit(c+46,"top oricatmos inst_key sw4", false,-1);
        tracep->declBit(c+47,"top oricatmos inst_key sw5", false,-1);
        tracep->declBit(c+48,"top oricatmos inst_key sw6", false,-1);
        tracep->declBit(c+49,"top oricatmos inst_key sw7", false,-1);
        tracep->declBit(c+50,"top oricatmos inst_key sw8", false,-1);
        tracep->declBit(c+51,"top oricatmos inst_key sw9", false,-1);
        tracep->declBit(c+52,"top oricatmos inst_key swa", false,-1);
        tracep->declBit(c+53,"top oricatmos inst_key swb", false,-1);
        tracep->declBit(c+54,"top oricatmos inst_key swc", false,-1);
        tracep->declBit(c+55,"top oricatmos inst_key swd", false,-1);
        tracep->declBit(c+56,"top oricatmos inst_key swe", false,-1);
        tracep->declBit(c+57,"top oricatmos inst_key swf", false,-1);
        tracep->declBit(c+58,"top oricatmos inst_key swg", false,-1);
        tracep->declBit(c+59,"top oricatmos inst_key swh", false,-1);
        tracep->declBit(c+60,"top oricatmos inst_key swi", false,-1);
        tracep->declBit(c+61,"top oricatmos inst_key swj", false,-1);
        tracep->declBit(c+62,"top oricatmos inst_key swk", false,-1);
        tracep->declBit(c+63,"top oricatmos inst_key swl", false,-1);
        tracep->declBit(c+64,"top oricatmos inst_key swm", false,-1);
        tracep->declBit(c+65,"top oricatmos inst_key swn", false,-1);
        tracep->declBit(c+66,"top oricatmos inst_key swo", false,-1);
        tracep->declBit(c+67,"top oricatmos inst_key swp", false,-1);
        tracep->declBit(c+68,"top oricatmos inst_key swq", false,-1);
        tracep->declBit(c+69,"top oricatmos inst_key swr", false,-1);
        tracep->declBit(c+70,"top oricatmos inst_key sws", false,-1);
        tracep->declBit(c+71,"top oricatmos inst_key swt", false,-1);
        tracep->declBit(c+72,"top oricatmos inst_key swu", false,-1);
        tracep->declBit(c+73,"top oricatmos inst_key swv", false,-1);
        tracep->declBit(c+74,"top oricatmos inst_key sww", false,-1);
        tracep->declBit(c+75,"top oricatmos inst_key swx", false,-1);
        tracep->declBit(c+76,"top oricatmos inst_key swy", false,-1);
        tracep->declBit(c+77,"top oricatmos inst_key swz", false,-1);
        tracep->declBit(c+78,"top oricatmos inst_key swU", false,-1);
        tracep->declBit(c+79,"top oricatmos inst_key swD", false,-1);
        tracep->declBit(c+80,"top oricatmos inst_key swL", false,-1);
        tracep->declBit(c+81,"top oricatmos inst_key swR", false,-1);
        tracep->declBit(c+82,"top oricatmos inst_key swrs", false,-1);
        tracep->declBit(c+83,"top oricatmos inst_key swls", false,-1);
        tracep->declBit(c+84,"top oricatmos inst_key swsp", false,-1);
        tracep->declBit(c+85,"top oricatmos inst_key swcom", false,-1);
        tracep->declBit(c+86,"top oricatmos inst_key swdot", false,-1);
        tracep->declBit(c+87,"top oricatmos inst_key swret", false,-1);
        tracep->declBit(c+88,"top oricatmos inst_key swfs", false,-1);
        tracep->declBit(c+89,"top oricatmos inst_key sweq", false,-1);
        tracep->declBit(c+90,"top oricatmos inst_key swfcn", false,-1);
        tracep->declBit(c+91,"top oricatmos inst_key swdel", false,-1);
        tracep->declBit(c+92,"top oricatmos inst_key swrsb", false,-1);
        tracep->declBit(c+93,"top oricatmos inst_key swlsb", false,-1);
        tracep->declBit(c+94,"top oricatmos inst_key swbs", false,-1);
        tracep->declBit(c+95,"top oricatmos inst_key swdsh", false,-1);
        tracep->declBit(c+96,"top oricatmos inst_key swsq", false,-1);
        tracep->declBit(c+97,"top oricatmos inst_key swsc", false,-1);
        tracep->declBit(c+98,"top oricatmos inst_key swesc", false,-1);
        tracep->declBit(c+99,"top oricatmos inst_key swctl", false,-1);
        tracep->declBit(c+100,"top oricatmos inst_key swf1", false,-1);
        tracep->declBit(c+101,"top oricatmos inst_key swf2", false,-1);
        tracep->declBit(c+102,"top oricatmos inst_key swf3", false,-1);
        tracep->declBit(c+103,"top oricatmos inst_key swf4", false,-1);
        tracep->declBit(c+104,"top oricatmos inst_key swf5", false,-1);
        tracep->declBit(c+105,"top oricatmos inst_key swf6", false,-1);
        tracep->declBit(c+610,"top oricatmos inst_microdisc CLK_SYS", false,-1);
        tracep->declBus(c+499,"top oricatmos inst_microdisc DI", false,-1, 7,0);
        tracep->declBus(c+646,"top oricatmos inst_microdisc DO", false,-1, 7,0);
        tracep->declBus(c+573,"top oricatmos inst_microdisc A", false,-1, 15,0);
        tracep->declBit(c+501,"top oricatmos inst_microdisc RnW", false,-1);
        tracep->declBit(c+237,"top oricatmos inst_microdisc nIRQ", false,-1);
        tracep->declBit(c+466,"top oricatmos inst_microdisc PH2", false,-1);
        tracep->declBit(c+236,"top oricatmos inst_microdisc nROMDIS", false,-1);
        tracep->declBit(c+592,"top oricatmos inst_microdisc nMAP", false,-1);
        tracep->declBit(c+590,"top oricatmos inst_microdisc IO", false,-1);
        tracep->declBit(c+593,"top oricatmos inst_microdisc IOCTRL", false,-1);
        tracep->declBit(c+443,"top oricatmos inst_microdisc nHOSTRST", false,-1);
        tracep->declBit(c+647,"top oricatmos inst_microdisc nOE", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_microdisc DIR", false,-1);
        tracep->declBit(c+443,"top oricatmos inst_microdisc nRESET", false,-1);
        tracep->declBit(c+502,"top oricatmos inst_microdisc nECE", false,-1);
        tracep->declBit(c+661,"top oricatmos inst_microdisc nEOE", false,-1);
        tracep->declBit(c+686,"top oricatmos inst_microdisc ENA", false,-1);
        tracep->declBit(c+677,"top oricatmos inst_microdisc img_mounted", false,-1);
        tracep->declBit(c+679,"top oricatmos inst_microdisc img_wp", false,-1);
        tracep->declBus(c+704,"top oricatmos inst_microdisc img_size", false,-1, 31,0);
        tracep->declBus(c+230,"top oricatmos inst_microdisc sd_lba", false,-1, 31,0);
        tracep->declBit(c+228,"top oricatmos inst_microdisc sd_rd", false,-1);
        tracep->declBit(c+229,"top oricatmos inst_microdisc sd_wr", false,-1);
        tracep->declBit(c+680,"top oricatmos inst_microdisc sd_ack", false,-1);
        tracep->declBus(c+705,"top oricatmos inst_microdisc sd_buff_addr", false,-1, 8,0);
        tracep->declBus(c+706,"top oricatmos inst_microdisc sd_dout", false,-1, 7,0);
        tracep->declBus(c+25,"top oricatmos inst_microdisc sd_din", false,-1, 7,0);
        tracep->declBit(c+683,"top oricatmos inst_microdisc sd_dout_strobe", false,-1);
        tracep->declBit(c+702,"top oricatmos inst_microdisc sd_din_strobe", false,-1);
        tracep->declBit(c+225,"top oricatmos inst_microdisc fdd_ready", false,-1);
        tracep->declBit(c+226,"top oricatmos inst_microdisc fdd_busy", false,-1);
        tracep->declBit(c+702,"top oricatmos inst_microdisc fdd_reset", false,-1);
        tracep->declBit(c+702,"top oricatmos inst_microdisc fdd_layout", false,-1);
        tracep->declBit(c+226,"top oricatmos inst_microdisc fd_led", false,-1);
        tracep->declBit(c+602,"top oricatmos inst_microdisc fdc_nCS", false,-1);
        tracep->declBit(c+770,"top oricatmos inst_microdisc nCS", false,-1);
        tracep->declBit(c+603,"top oricatmos inst_microdisc fdc_nRE", false,-1);
        tracep->declBit(c+662,"top oricatmos inst_microdisc fdc_nWE", false,-1);
        tracep->declBit(c+663,"top oricatmos inst_microdisc fdc_CLK_en", false,-1);
        tracep->declBus(c+575,"top oricatmos inst_microdisc fdc_A", false,-1, 1,0);
        tracep->declBus(c+499,"top oricatmos inst_microdisc fdc_DALin", false,-1, 7,0);
        tracep->declBus(c+576,"top oricatmos inst_microdisc fdc_DALout", false,-1, 7,0);
        tracep->declBit(c+263,"top oricatmos inst_microdisc fdc_DRQ", false,-1);
        tracep->declBit(c+264,"top oricatmos inst_microdisc fdc_IRQ", false,-1);
        tracep->declBit(c+604,"top oricatmos inst_microdisc sel", false,-1);
        tracep->declBit(c+577,"top oricatmos inst_microdisc u16k", false,-1);
        tracep->declBit(c+502,"top oricatmos inst_microdisc inECE", false,-1);
        tracep->declBit(c+106,"top oricatmos inst_microdisc inROMDIS", false,-1);
        tracep->declBit(c+501,"top oricatmos inst_microdisc iDIR", false,-1);
        tracep->declBus(c+107,"top oricatmos inst_microdisc DSEL", false,-1, 1,0);
        tracep->declBit(c+265,"top oricatmos inst_microdisc SSEL", false,-1);
        tracep->declBit(c+108,"top oricatmos inst_microdisc nROMEN", false,-1);
        tracep->declBit(c+266,"top oricatmos inst_microdisc IRQEN", false,-1);
        tracep->declBit(c+771,"top oricatmos inst_microdisc inMCRQ", false,-1);
        tracep->declBus(c+664,"top oricatmos inst_microdisc count", false,-1, 2,0);
        tracep->declBus(c+688,"top oricatmos inst_microdisc fdc1 RWMODE", false,-1, 31,0);
        tracep->declBus(c+688,"top oricatmos inst_microdisc fdc1 EDSK", false,-1, 31,0);
        tracep->declBit(c+610,"top oricatmos inst_microdisc fdc1 clk_sys", false,-1);
        tracep->declBit(c+663,"top oricatmos inst_microdisc fdc1 ce", false,-1);
        tracep->declBit(c+446,"top oricatmos inst_microdisc fdc1 reset", false,-1);
        tracep->declBit(c+605,"top oricatmos inst_microdisc fdc1 io_en", false,-1);
        tracep->declBit(c+606,"top oricatmos inst_microdisc fdc1 rd", false,-1);
        tracep->declBit(c+665,"top oricatmos inst_microdisc fdc1 wr", false,-1);
        tracep->declBus(c+575,"top oricatmos inst_microdisc fdc1 addr", false,-1, 1,0);
        tracep->declBus(c+499,"top oricatmos inst_microdisc fdc1 din", false,-1, 7,0);
        tracep->declBus(c+576,"top oricatmos inst_microdisc fdc1 dout", false,-1, 7,0);
        tracep->declBit(c+263,"top oricatmos inst_microdisc fdc1 drq", false,-1);
        tracep->declBit(c+264,"top oricatmos inst_microdisc fdc1 intrq", false,-1);
        tracep->declBit(c+267,"top oricatmos inst_microdisc fdc1 busy", false,-1);
        tracep->declBit(c+679,"top oricatmos inst_microdisc fdc1 wp", false,-1);
        tracep->declBus(c+722,"top oricatmos inst_microdisc fdc1 size_code", false,-1, 2,0);
        tracep->declBit(c+702,"top oricatmos inst_microdisc fdc1 layout", false,-1);
        tracep->declBit(c+265,"top oricatmos inst_microdisc fdc1 side", false,-1);
        tracep->declBit(c+225,"top oricatmos inst_microdisc fdc1 ready", false,-1);
        tracep->declBit(c+677,"top oricatmos inst_microdisc fdc1 img_mounted", false,-1);
        tracep->declBus(c+772,"top oricatmos inst_microdisc fdc1 img_size", false,-1, 19,0);
        tracep->declBit(c+226,"top oricatmos inst_microdisc fdc1 prepare", false,-1);
        tracep->declBus(c+230,"top oricatmos inst_microdisc fdc1 sd_lba", false,-1, 31,0);
        tracep->declBit(c+228,"top oricatmos inst_microdisc fdc1 sd_rd", false,-1);
        tracep->declBit(c+229,"top oricatmos inst_microdisc fdc1 sd_wr", false,-1);
        tracep->declBit(c+680,"top oricatmos inst_microdisc fdc1 sd_ack", false,-1);
        tracep->declBus(c+705,"top oricatmos inst_microdisc fdc1 sd_buff_addr", false,-1, 8,0);
        tracep->declBus(c+706,"top oricatmos inst_microdisc fdc1 sd_buff_dout", false,-1, 7,0);
        tracep->declBus(c+25,"top oricatmos inst_microdisc fdc1 sd_buff_din", false,-1, 7,0);
        tracep->declBit(c+683,"top oricatmos inst_microdisc fdc1 sd_buff_wr", false,-1);
        tracep->declBit(c+702,"top oricatmos inst_microdisc fdc1 input_active", false,-1);
        tracep->declBus(c+773,"top oricatmos inst_microdisc fdc1 input_addr", false,-1, 19,0);
        tracep->declBus(c+703,"top oricatmos inst_microdisc fdc1 input_data", false,-1, 7,0);
        tracep->declBit(c+702,"top oricatmos inst_microdisc fdc1 input_wr", false,-1);
        tracep->declBus(c+268,"top oricatmos inst_microdisc fdc1 buff_addr", false,-1, 19,0);
        tracep->declBit(c+666,"top oricatmos inst_microdisc fdc1 buff_read", false,-1);
        tracep->declBus(c+703,"top oricatmos inst_microdisc fdc1 buff_din", false,-1, 7,0);
        tracep->declBus(c+269,"top oricatmos inst_microdisc fdc1 wd_size_code", false,-1, 1,0);
        tracep->declBus(c+270,"top oricatmos inst_microdisc fdc1 sectors_per_track", false,-1, 7,0);
        tracep->declBus(c+271,"top oricatmos inst_microdisc fdc1 edsk_spt", false,-1, 7,0);
        tracep->declBus(c+272,"top oricatmos inst_microdisc fdc1 sector_size", false,-1, 10,0);
        tracep->declBus(c+273,"top oricatmos inst_microdisc fdc1 byte_addr", false,-1, 10,0);
        tracep->declBus(c+274,"top oricatmos inst_microdisc fdc1 buff_a", false,-1, 19,0);
        tracep->declBus(c+109,"top oricatmos inst_microdisc fdc1 buff_dout", false,-1, 7,0);
        tracep->declBus(c+275,"top oricatmos inst_microdisc fdc1 sd_block", false,-1, 1,0);
        tracep->declBit(c+276,"top oricatmos inst_microdisc fdc1 format", false,-1);
        tracep->declBus(c+721,"top oricatmos inst_microdisc fdc1 A_COMMAND", false,-1, 31,0);
        tracep->declBus(c+721,"top oricatmos inst_microdisc fdc1 A_STATUS", false,-1, 31,0);
        tracep->declBus(c+688,"top oricatmos inst_microdisc fdc1 A_TRACK", false,-1, 31,0);
        tracep->declBus(c+689,"top oricatmos inst_microdisc fdc1 A_SECTOR", false,-1, 31,0);
        tracep->declBus(c+690,"top oricatmos inst_microdisc fdc1 A_DATA", false,-1, 31,0);
        tracep->declBit(c+679,"top oricatmos inst_microdisc fdc1 s_readonly", false,-1);
        tracep->declBit(c+277,"top oricatmos inst_microdisc fdc1 s_crcerr", false,-1);
        tracep->declBit(c+278,"top oricatmos inst_microdisc fdc1 s_headloaded", false,-1);
        tracep->declBit(c+279,"top oricatmos inst_microdisc fdc1 s_seekerr", false,-1);
        tracep->declBit(c+110,"top oricatmos inst_microdisc fdc1 s_index", false,-1);
        tracep->declBit(c+280,"top oricatmos inst_microdisc fdc1 s_lostdata", false,-1);
        tracep->declBit(c+281,"top oricatmos inst_microdisc fdc1 s_wrfault", false,-1);
        tracep->declBit(c+282,"top oricatmos inst_microdisc fdc1 cmd_mode", false,-1);
        tracep->declBit(c+283,"top oricatmos inst_microdisc fdc1 s_wpe", false,-1);
        tracep->declBus(c+284,"top oricatmos inst_microdisc fdc1 s_drq_busy", false,-1, 1,0);
        tracep->declBit(c+263,"top oricatmos inst_microdisc fdc1 s_drq", false,-1);
        tracep->declBit(c+267,"top oricatmos inst_microdisc fdc1 s_busy", false,-1);
        tracep->declBit(c+264,"top oricatmos inst_microdisc fdc1 s_intrq", false,-1);
        tracep->declBus(c+285,"top oricatmos inst_microdisc fdc1 wdreg_track", false,-1, 7,0);
        tracep->declBus(c+286,"top oricatmos inst_microdisc fdc1 wdreg_sector", false,-1, 7,0);
        tracep->declBus(c+287,"top oricatmos inst_microdisc fdc1 wdreg_data", false,-1, 7,0);
        tracep->declBus(c+288,"top oricatmos inst_microdisc fdc1 disk_track", false,-1, 7,0);
        tracep->declBus(c+667,"top oricatmos inst_microdisc fdc1 wdreg_status", false,-1, 7,0);
        {int i; for (i=0; i<6; i++) {
                tracep->declBus(c+289+i*1,"top oricatmos inst_microdisc fdc1 read_addr", true,(i+0), 7,0);}}
        tracep->declBus(c+576,"top oricatmos inst_microdisc fdc1 q", false,-1, 7,0);
        tracep->declBit(c+295,"top oricatmos inst_microdisc fdc1 var_size", false,-1);
        tracep->declBus(c+296,"top oricatmos inst_microdisc fdc1 disk_size", false,-1, 19,0);
        tracep->declBit(c+297,"top oricatmos inst_microdisc fdc1 layout_r", false,-1);
        tracep->declBus(c+298,"top oricatmos inst_microdisc fdc1 hs", false,-1, 19,0);
        tracep->declBus(c+299,"top oricatmos inst_microdisc fdc1 dts", false,-1, 7,0);
        tracep->declBit(c+300,"top oricatmos inst_microdisc fdc1 buff_rd", false,-1);
        tracep->declBit(c+301,"top oricatmos inst_microdisc fdc1 step_direction", false,-1);
        tracep->declBus(c+302,"top oricatmos inst_microdisc fdc1 data_length", false,-1, 10,0);
        tracep->declBus(c+303,"top oricatmos inst_microdisc fdc1 state", false,-1, 31,0);
        tracep->declBus(c+578,"top oricatmos inst_microdisc fdc1 next_track", false,-1, 7,0);
        tracep->declBus(c+304,"top oricatmos inst_microdisc fdc1 next_length", false,-1, 10,0);
        tracep->declBit(c+305,"top oricatmos inst_microdisc fdc1 watchdog_set", false,-1);
        tracep->declBus(c+306,"top oricatmos inst_microdisc fdc1 wd_timer", false,-1, 15,0);
        tracep->declBit(c+307,"top oricatmos inst_microdisc fdc1 watchdog_bark", false,-1);
        tracep->declBit(c+226,"top oricatmos inst_microdisc fdc1 scan_active", false,-1);
        tracep->declBus(c+308,"top oricatmos inst_microdisc fdc1 scan_addr", false,-1, 19,0);
        tracep->declBit(c+309,"top oricatmos inst_microdisc fdc1 scan_wr", false,-1);
        tracep->declBus(c+310,"top oricatmos inst_microdisc fdc1 edsk_sizecode", false,-1, 1,0);
        tracep->declBit(c+311,"top oricatmos inst_microdisc fdc1 edsk_side", false,-1);
        tracep->declBus(c+312,"top oricatmos inst_microdisc fdc1 edsk_track", false,-1, 6,0);
        tracep->declBus(c+313,"top oricatmos inst_microdisc fdc1 edsk_sector", false,-1, 7,0);
        tracep->declBus(c+314,"top oricatmos inst_microdisc fdc1 edsk_offset", false,-1, 19,0);
        tracep->declBus(c+315,"top oricatmos inst_microdisc fdc1 edsk_trackf", false,-1, 7,0);
        tracep->declBus(c+316,"top oricatmos inst_microdisc fdc1 edsk_sidef", false,-1, 7,0);
        tracep->declBus(c+317,"top oricatmos inst_microdisc fdc1 edsk_addr", false,-1, 10,0);
        tracep->declBus(c+318,"top oricatmos inst_microdisc fdc1 edsk_start", false,-1, 10,0);
        tracep->declBus(c+111,"top oricatmos inst_microdisc fdc1 edsk_size", false,-1, 10,0);
        tracep->declBus(c+319,"top oricatmos inst_microdisc fdc1 edsk_next", false,-1, 10,0);
        tracep->declBus(c+320,"top oricatmos inst_microdisc fdc1 spt_size", false,-1, 7,0);
        tracep->declBit(c+321,"top oricatmos inst_microdisc fdc1 buff_wr", false,-1);
        tracep->declBus(c+322,"top oricatmos inst_microdisc fdc1 blk_size", false,-1, 1,0);
        tracep->declBus(c+323,"top oricatmos inst_microdisc fdc1 spt_addr", false,-1, 7,0);
        tracep->declBit(c+607,"top oricatmos inst_microdisc fdc1 rde", false,-1);
        tracep->declBit(c+608,"top oricatmos inst_microdisc fdc1 wre", false,-1);
        tracep->declBus(c+112,"top oricatmos inst_microdisc fdc1 unnamedblk1 cnt", false,-1, 31,0);
        tracep->declBit(c+324,"top oricatmos inst_microdisc fdc1 unnamedblk2 old_wr", false,-1);
        tracep->declBit(c+325,"top oricatmos inst_microdisc fdc1 unnamedblk2 old_rd", false,-1);
        tracep->declBus(c+326,"top oricatmos inst_microdisc fdc1 unnamedblk2 cur_addr", false,-1, 2,0);
        tracep->declBit(c+327,"top oricatmos inst_microdisc fdc1 unnamedblk2 read_data", false,-1);
        tracep->declBit(c+328,"top oricatmos inst_microdisc fdc1 unnamedblk2 write_data", false,-1);
        tracep->declBit(c+329,"top oricatmos inst_microdisc fdc1 unnamedblk2 rw_type", false,-1);
        tracep->declBus(c+330,"top oricatmos inst_microdisc fdc1 unnamedblk2 wait_time", false,-1, 31,0);
        tracep->declBus(c+331,"top oricatmos inst_microdisc fdc1 unnamedblk2 read_timer", false,-1, 3,0);
        tracep->declBus(c+332,"top oricatmos inst_microdisc fdc1 unnamedblk2 seektimer", false,-1, 9,0);
        tracep->declBus(c+333,"top oricatmos inst_microdisc fdc1 unnamedblk2 ra_sector", false,-1, 7,0);
        tracep->declBit(c+334,"top oricatmos inst_microdisc fdc1 unnamedblk2 multisector", false,-1);
        tracep->declBit(c+335,"top oricatmos inst_microdisc fdc1 unnamedblk2 write", false,-1);
        tracep->declBus(c+336,"top oricatmos inst_microdisc fdc1 unnamedblk2 ack", false,-1, 5,0);
        tracep->declBit(c+337,"top oricatmos inst_microdisc fdc1 unnamedblk2 sd_busy", false,-1);
        tracep->declBit(c+338,"top oricatmos inst_microdisc fdc1 unnamedblk2 old_mounted", false,-1);
        tracep->declBus(c+339,"top oricatmos inst_microdisc fdc1 unnamedblk2 scan_state", false,-1, 3,0);
        tracep->declBus(c+340,"top oricatmos inst_microdisc fdc1 unnamedblk2 scan_cnt", false,-1, 1,0);
        tracep->declBus(c+341,"top oricatmos inst_microdisc fdc1 unnamedblk2 blk_max", false,-1, 1,0);
        tracep->declBus(c+109,"top oricatmos inst_microdisc fdc1 genblk3 scan_data", false,-1, 7,0);
        tracep->declBus(c+113,"top oricatmos inst_microdisc fdc1 genblk3 tpos", false,-1, 7,0);
        tracep->declBus(c+114,"top oricatmos inst_microdisc fdc1 genblk3 tsize", false,-1, 7,0);
        tracep->declArray(c+774,"top oricatmos inst_microdisc fdc1 genblk3 edsk_sig", false,-1, 127,0);
        tracep->declArray(c+342,"top oricatmos inst_microdisc fdc1 genblk3 sig_pos", false,-1, 127,0);
        tracep->declBit(c+115,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 old_active", false,-1);
        tracep->declBit(c+116,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 old_wr", false,-1);
        tracep->declBus(c+778,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 hdr_pos", false,-1, 13,0);
        tracep->declBus(c+779,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 bcnt", false,-1, 13,0);
        tracep->declBus(c+780,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 idStatus", false,-1, 7,0);
        tracep->declBus(c+117,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 track", false,-1, 6,0);
        tracep->declBit(c+118,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 side", false,-1);
        tracep->declBus(c+119,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 sector", false,-1, 7,0);
        tracep->declBus(c+120,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 sizecode", false,-1, 1,0);
        tracep->declBus(c+781,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 crc1", false,-1, 7,0);
        tracep->declBus(c+782,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 crc2", false,-1, 7,0);
        tracep->declBus(c+121,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 sectors", false,-1, 7,0);
        tracep->declBus(c+122,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 track_size", false,-1, 15,0);
        tracep->declBus(c+123,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 track_pos", false,-1, 15,0);
        tracep->declBus(c+124,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 offset", false,-1, 19,0);
        tracep->declBus(c+125,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 offset1", false,-1, 19,0);
        tracep->declBus(c+126,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 size_lo", false,-1, 7,0);
        tracep->declBus(c+127,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 secpos", false,-1, 10,0);
        tracep->declBus(c+128,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 trackf", false,-1, 7,0);
        tracep->declBus(c+129,"top oricatmos inst_microdisc fdc1 genblk3 unnamedblk3 sidef", false,-1, 7,0);
        tracep->declBus(c+684,"top oricatmos inst_microdisc fdc1 genblk1 sbuf DATAWIDTH", false,-1, 31,0);
        tracep->declBus(c+783,"top oricatmos inst_microdisc fdc1 genblk1 sbuf ADDRWIDTH", false,-1, 31,0);
        tracep->declBit(c+610,"top oricatmos inst_microdisc fdc1 genblk1 sbuf clock", false,-1);
        tracep->declBus(c+346,"top oricatmos inst_microdisc fdc1 genblk1 sbuf address_a", false,-1, 10,0);
        tracep->declBus(c+706,"top oricatmos inst_microdisc fdc1 genblk1 sbuf data_a", false,-1, 7,0);
        tracep->declBit(c+1,"top oricatmos inst_microdisc fdc1 genblk1 sbuf wren_a", false,-1);
        tracep->declBus(c+25,"top oricatmos inst_microdisc fdc1 genblk1 sbuf q_a", false,-1, 7,0);
        tracep->declBus(c+347,"top oricatmos inst_microdisc fdc1 genblk1 sbuf address_b", false,-1, 10,0);
        tracep->declBus(c+579,"top oricatmos inst_microdisc fdc1 genblk1 sbuf data_b", false,-1, 7,0);
        tracep->declBit(c+609,"top oricatmos inst_microdisc fdc1 genblk1 sbuf wren_b", false,-1);
        tracep->declBus(c+109,"top oricatmos inst_microdisc fdc1 genblk1 sbuf q_b", false,-1, 7,0);
        tracep->declBus(c+721,"$unit Flag_C", false,-1, 31,0);
        tracep->declBus(c+688,"$unit Flag_Z", false,-1, 31,0);
        tracep->declBus(c+689,"$unit Flag_I", false,-1, 31,0);
        tracep->declBus(c+690,"$unit Flag_D", false,-1, 31,0);
        tracep->declBus(c+691,"$unit Flag_B", false,-1, 31,0);
        tracep->declBus(c+692,"$unit Flag_1", false,-1, 31,0);
        tracep->declBus(c+693,"$unit Flag_V", false,-1, 31,0);
        tracep->declBus(c+694,"$unit Flag_N", false,-1, 31,0);
        tracep->declBus(c+708,"$unit Cycle_sync", false,-1, 2,0);
        tracep->declBus(c+722,"$unit Cycle_1", false,-1, 2,0);
        tracep->declBus(c+723,"$unit Cycle_2", false,-1, 2,0);
        tracep->declBus(c+724,"$unit Cycle_3", false,-1, 2,0);
        tracep->declBus(c+725,"$unit Cycle_4", false,-1, 2,0);
        tracep->declBus(c+726,"$unit Cycle_5", false,-1, 2,0);
        tracep->declBus(c+727,"$unit Cycle_6", false,-1, 2,0);
        tracep->declBus(c+728,"$unit Cycle_7", false,-1, 2,0);
        tracep->declBus(c+729,"$unit T_Set_BusA_To_Set_BusA_To_DI", false,-1, 3,0);
        tracep->declBus(c+730,"$unit T_Set_BusA_To_Set_BusA_To_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"$unit T_Set_BusA_To_Set_BusA_To_X", false,-1, 3,0);
        tracep->declBus(c+732,"$unit T_Set_BusA_To_Set_BusA_To_Y", false,-1, 3,0);
        tracep->declBus(c+733,"$unit T_Set_BusA_To_Set_BusA_To_S", false,-1, 3,0);
        tracep->declBus(c+734,"$unit T_Set_BusA_To_Set_BusA_To_P", false,-1, 3,0);
        tracep->declBus(c+735,"$unit T_Set_BusA_To_Set_BusA_To_DA", false,-1, 3,0);
        tracep->declBus(c+736,"$unit T_Set_BusA_To_Set_BusA_To_DAO", false,-1, 3,0);
        tracep->declBus(c+737,"$unit T_Set_BusA_To_Set_BusA_To_DAX", false,-1, 3,0);
        tracep->declBus(c+738,"$unit T_Set_BusA_To_Set_BusA_To_AAX", false,-1, 3,0);
        tracep->declBus(c+739,"$unit T_Set_BusA_To_Set_BusA_To_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+740,"$unit T_Set_Addr_To_Set_Addr_To_PBR", false,-1, 1,0);
        tracep->declBus(c+741,"$unit T_Set_Addr_To_Set_Addr_To_SP", false,-1, 1,0);
        tracep->declBus(c+742,"$unit T_Set_Addr_To_Set_Addr_To_ZPG", false,-1, 1,0);
        tracep->declBus(c+743,"$unit T_Set_Addr_To_Set_Addr_To_BA", false,-1, 1,0);
        tracep->declBus(c+729,"$unit T_Write_Data_Write_Data_DL", false,-1, 3,0);
        tracep->declBus(c+730,"$unit T_Write_Data_Write_Data_ABC", false,-1, 3,0);
        tracep->declBus(c+731,"$unit T_Write_Data_Write_Data_X", false,-1, 3,0);
        tracep->declBus(c+732,"$unit T_Write_Data_Write_Data_Y", false,-1, 3,0);
        tracep->declBus(c+733,"$unit T_Write_Data_Write_Data_S", false,-1, 3,0);
        tracep->declBus(c+734,"$unit T_Write_Data_Write_Data_P", false,-1, 3,0);
        tracep->declBus(c+735,"$unit T_Write_Data_Write_Data_PCL", false,-1, 3,0);
        tracep->declBus(c+736,"$unit T_Write_Data_Write_Data_PCH", false,-1, 3,0);
        tracep->declBus(c+737,"$unit T_Write_Data_Write_Data_AX", false,-1, 3,0);
        tracep->declBus(c+738,"$unit T_Write_Data_Write_Data_AXB", false,-1, 3,0);
        tracep->declBus(c+739,"$unit T_Write_Data_Write_Data_XB", false,-1, 3,0);
        tracep->declBus(c+744,"$unit T_Write_Data_Write_Data_YB", false,-1, 3,0);
        tracep->declBus(c+745,"$unit T_Write_Data_Write_Data_DONTCARE", false,-1, 3,0);
        tracep->declBus(c+746,"$unit T_ALU_OP_ALU_OP_OR", false,-1, 4,0);
        tracep->declBus(c+747,"$unit T_ALU_OP_ALU_OP_AND", false,-1, 4,0);
        tracep->declBus(c+748,"$unit T_ALU_OP_ALU_OP_EOR", false,-1, 4,0);
        tracep->declBus(c+749,"$unit T_ALU_OP_ALU_OP_ADC", false,-1, 4,0);
        tracep->declBus(c+750,"$unit T_ALU_OP_ALU_OP_EQ1", false,-1, 4,0);
        tracep->declBus(c+751,"$unit T_ALU_OP_ALU_OP_EQ2", false,-1, 4,0);
        tracep->declBus(c+752,"$unit T_ALU_OP_ALU_OP_CMP", false,-1, 4,0);
        tracep->declBus(c+753,"$unit T_ALU_OP_ALU_OP_SBC", false,-1, 4,0);
        tracep->declBus(c+754,"$unit T_ALU_OP_ALU_OP_ASL", false,-1, 4,0);
        tracep->declBus(c+755,"$unit T_ALU_OP_ALU_OP_ROL", false,-1, 4,0);
        tracep->declBus(c+756,"$unit T_ALU_OP_ALU_OP_LSR", false,-1, 4,0);
        tracep->declBus(c+757,"$unit T_ALU_OP_ALU_OP_ROR", false,-1, 4,0);
        tracep->declBus(c+758,"$unit T_ALU_OP_ALU_OP_BIT", false,-1, 4,0);
        tracep->declBus(c+759,"$unit T_ALU_OP_ALU_OP_DEC", false,-1, 4,0);
        tracep->declBus(c+760,"$unit T_ALU_OP_ALU_OP_INC", false,-1, 4,0);
        tracep->declBus(c+761,"$unit T_ALU_OP_ALU_OP_ARR", false,-1, 4,0);
        tracep->declBus(c+762,"$unit T_ALU_OP_ALU_OP_ANC", false,-1, 4,0);
        tracep->declBus(c+763,"$unit T_ALU_OP_ALU_OP_SAX", false,-1, 4,0);
        tracep->declBus(c+764,"$unit T_ALU_OP_ALU_OP_XAA", false,-1, 4,0);
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
    // Variables
    WData/*127:0*/ __Vtemp15[4];
    WData/*127:0*/ __Vtemp16[4];
    WData/*127:0*/ __Vtemp17[4];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_a));
        tracep->fullCData(oldp+2,(vlTOPp->top__DOT__ram_d_temp),8);
        tracep->fullSData(oldp+3,(vlTOPp->top__DOT__tape_addr),16);
        tracep->fullBit(oldp+4,(vlTOPp->top__DOT__tape_wr));
        tracep->fullCData(oldp+5,(vlTOPp->top__DOT__tape_dout),8);
        tracep->fullBit(oldp+6,(vlTOPp->top__DOT__tape_complete));
        tracep->fullBit(oldp+7,(vlTOPp->top__DOT__tape_autorun));
        tracep->fullSData(oldp+8,(vlTOPp->top__DOT__loadpoint),16);
        tracep->fullBit(oldp+9,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__sd_din))));
        tracep->fullCData(oldp+10,(vlTOPp->top__DOT__ram__DOT__do2),8);
        tracep->fullSData(oldp+11,(vlTOPp->top__DOT__cassette__DOT__start_addr),16);
        tracep->fullSData(oldp+12,(vlTOPp->top__DOT__cassette__DOT__end_addr),16);
        tracep->fullSData(oldp+13,(vlTOPp->top__DOT__cassette__DOT__state),16);
        tracep->fullCData(oldp+14,(vlTOPp->top__DOT__cassette__DOT__fileType),8);
        tracep->fullCData(oldp+15,(vlTOPp->top__DOT__cassette__DOT__autorun),8);
        tracep->fullCData(oldp+16,(vlTOPp->top__DOT__cassette__DOT__endAddressHIGH),8);
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__cassette__DOT__endAddressLOW),8);
        tracep->fullCData(oldp+18,(vlTOPp->top__DOT__cassette__DOT__startAddressHIGH),8);
        tracep->fullCData(oldp+19,(vlTOPp->top__DOT__cassette__DOT__startAddressLOW),8);
        tracep->fullSData(oldp+20,(vlTOPp->top__DOT__cassette__DOT__cache_addr),16);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__cassette__DOT__cache_dout),8);
        tracep->fullBit(oldp+22,(vlTOPp->top__DOT__cassette__DOT__cache_cs));
        tracep->fullBit(oldp+23,(vlTOPp->top__DOT__cassette__DOT__tapecache_loaded));
        tracep->fullBit(oldp+24,(vlTOPp->top__DOT__cassette__DOT__ioctl_downlD));
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT____Vcellout__oricatmos__sd_din),8);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__oricatmos__DOT__KEY_ROW),8);
        tracep->fullBit(oldp+27,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__swrst)))));
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__oricatmos__DOT__swrst));
        tracep->fullCData(oldp+29,((0xffU & (IData)(vlTOPp->top__DOT__loadpoint))),8);
        tracep->fullCData(oldp+30,(vlTOPp->top__DOT__tape_autorun),8);
        tracep->fullCData(oldp+31,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG),6);
        tracep->fullBit(oldp+32,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv));
        tracep->fullBit(oldp+33,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_t1));
        tracep->fullBit(oldp+34,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_active));
        tracep->fullBit(oldp+35,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c_done));
        tracep->fullBit(oldp+36,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_int_enable));
        tracep->fullBit(oldp+37,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_irq));
        tracep->fullBit(oldp+38,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done));
        tracep->fullBit(oldp+39,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__wr_n));
        tracep->fullBit(oldp+40,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__cs_n));
        tracep->fullBit(oldp+41,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr_ok));
        tracep->fullBit(oldp+42,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw0));
        tracep->fullBit(oldp+43,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw1));
        tracep->fullBit(oldp+44,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw2));
        tracep->fullBit(oldp+45,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw3));
        tracep->fullBit(oldp+46,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw4));
        tracep->fullBit(oldp+47,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw5));
        tracep->fullBit(oldp+48,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw6));
        tracep->fullBit(oldp+49,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw7));
        tracep->fullBit(oldp+50,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw8));
        tracep->fullBit(oldp+51,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sw9));
        tracep->fullBit(oldp+52,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swa));
        tracep->fullBit(oldp+53,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swb));
        tracep->fullBit(oldp+54,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swc));
        tracep->fullBit(oldp+55,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swd));
        tracep->fullBit(oldp+56,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swe));
        tracep->fullBit(oldp+57,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf));
        tracep->fullBit(oldp+58,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swg));
        tracep->fullBit(oldp+59,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swh));
        tracep->fullBit(oldp+60,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swi));
        tracep->fullBit(oldp+61,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swj));
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swk));
        tracep->fullBit(oldp+63,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swl));
        tracep->fullBit(oldp+64,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swm));
        tracep->fullBit(oldp+65,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swn));
        tracep->fullBit(oldp+66,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swo));
        tracep->fullBit(oldp+67,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swp));
        tracep->fullBit(oldp+68,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swq));
        tracep->fullBit(oldp+69,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swr));
        tracep->fullBit(oldp+70,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sws));
        tracep->fullBit(oldp+71,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swt));
        tracep->fullBit(oldp+72,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swu));
        tracep->fullBit(oldp+73,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swv));
        tracep->fullBit(oldp+74,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sww));
        tracep->fullBit(oldp+75,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swx));
        tracep->fullBit(oldp+76,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swy));
        tracep->fullBit(oldp+77,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swz));
        tracep->fullBit(oldp+78,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swU));
        tracep->fullBit(oldp+79,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swD));
        tracep->fullBit(oldp+80,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swL));
        tracep->fullBit(oldp+81,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swR));
        tracep->fullBit(oldp+82,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrs));
        tracep->fullBit(oldp+83,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swls));
        tracep->fullBit(oldp+84,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsp));
        tracep->fullBit(oldp+85,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swcom));
        tracep->fullBit(oldp+86,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdot));
        tracep->fullBit(oldp+87,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swret));
        tracep->fullBit(oldp+88,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfs));
        tracep->fullBit(oldp+89,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__sweq));
        tracep->fullBit(oldp+90,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swfcn));
        tracep->fullBit(oldp+91,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdel));
        tracep->fullBit(oldp+92,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swrsb));
        tracep->fullBit(oldp+93,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swlsb));
        tracep->fullBit(oldp+94,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swbs));
        tracep->fullBit(oldp+95,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swdsh));
        tracep->fullBit(oldp+96,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsq));
        tracep->fullBit(oldp+97,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swsc));
        tracep->fullBit(oldp+98,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swesc));
        tracep->fullBit(oldp+99,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swctl));
        tracep->fullBit(oldp+100,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf1));
        tracep->fullBit(oldp+101,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf2));
        tracep->fullBit(oldp+102,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf3));
        tracep->fullBit(oldp+103,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf4));
        tracep->fullBit(oldp+104,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf5));
        tracep->fullBit(oldp+105,(vlTOPp->top__DOT__oricatmos__DOT__inst_key__DOT__swf6));
        tracep->fullBit(oldp+106,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inROMDIS));
        tracep->fullCData(oldp+107,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DSEL),2);
        tracep->fullBit(oldp+108,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__nROMEN));
        tracep->fullCData(oldp+109,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_dout),8);
        tracep->fullBit(oldp+110,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_index));
        tracep->fullSData(oldp+111,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_size),11);
        tracep->fullIData(oldp+112,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk1__DOT__cnt),32);
        tracep->fullCData(oldp+113,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tpos),8);
        tracep->fullCData(oldp+114,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__tsize),8);
        tracep->fullBit(oldp+115,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_active));
        tracep->fullBit(oldp+116,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__old_wr));
        tracep->fullCData(oldp+117,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track),7);
        tracep->fullBit(oldp+118,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__side));
        tracep->fullCData(oldp+119,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sector),8);
        tracep->fullCData(oldp+120,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sizecode),2);
        tracep->fullCData(oldp+121,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sectors),8);
        tracep->fullSData(oldp+122,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_size),16);
        tracep->fullSData(oldp+123,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__track_pos),16);
        tracep->fullIData(oldp+124,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset),20);
        tracep->fullIData(oldp+125,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__offset1),20);
        tracep->fullCData(oldp+126,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__size_lo),8);
        tracep->fullSData(oldp+127,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__secpos),11);
        tracep->fullCData(oldp+128,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__trackf),8);
        tracep->fullCData(oldp+129,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__sidef),8);
        tracep->fullBit(oldp+130,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_A))));
        tracep->fullBit(oldp+131,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_B))));
        tracep->fullBit(oldp+132,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_C))));
        tracep->fullBit(oldp+133,((1U & (IData)(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT))));
        tracep->fullCData(oldp+134,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_A),8);
        tracep->fullCData(oldp+135,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_B),8);
        tracep->fullCData(oldp+136,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT_C),8);
        tracep->fullSData(oldp+137,(vlTOPp->top__DOT____Vcellout__oricatmos__PSG_OUT),10);
        tracep->fullCData(oldp+138,(vlTOPp->top__DOT__oricatmos__DOT__via_pa_in_from_psg),8);
        tracep->fullBit(oldp+139,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_step));
        tracep->fullBit(oldp+140,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_restart));
        tracep->fullCData(oldp+141,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc_st),4);
        tracep->fullSData(oldp+142,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__acc),10);
        tracep->fullBit(oldp+143,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__last_write));
        tracep->fullSData(oldp+144,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chA__DOT__count),12);
        tracep->fullSData(oldp+145,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chB__DOT__count),12);
        tracep->fullSData(oldp+146,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_chC__DOT__count),12);
        tracep->fullBit(oldp+147,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__noise_en));
        tracep->fullBit(oldp+148,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__last_en));
        tracep->fullBit(oldp+149,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__noise_en) 
                                   & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__last_en)))));
        tracep->fullCData(oldp+150,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__u_div__DOT__count),5);
        tracep->fullSData(oldp+151,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_envdiv__DOT__count),16);
        tracep->fullBit(oldp+152,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__stop));
        tracep->fullBit(oldp+153,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__last_step));
        tracep->fullBit(oldp+154,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_clr));
        tracep->fullBit(oldp+155,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__EF_i));
        tracep->fullBit(oldp+156,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MF_i));
        tracep->fullBit(oldp+157,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__XF_i));
        tracep->fullBit(oldp+158,((0U != (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To_r))));
        tracep->fullCData(oldp+159,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC))),8);
        tracep->fullCData(oldp+160,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__X))),8);
        tracep->fullCData(oldp+161,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Y))),8);
        tracep->fullCData(oldp+162,((0xffU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__S))),8);
        tracep->fullSData(oldp+163,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ABC),16);
        tracep->fullSData(oldp+164,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__X),16);
        tracep->fullSData(oldp+165,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Y),16);
        tracep->fullCData(oldp+166,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__AD),8);
        tracep->fullCData(oldp+167,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DL),8);
        tracep->fullCData(oldp+168,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAH),8);
        tracep->fullSData(oldp+169,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAL),9);
        tracep->fullCData(oldp+170,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PBR),8);
        tracep->fullCData(oldp+171,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DBR),8);
        tracep->fullSData(oldp+172,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PC),16);
        tracep->fullSData(oldp+173,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__S),16);
        tracep->fullCData(oldp+174,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Mode_r),2);
        tracep->fullCData(oldp+175,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op_r),5);
        tracep->fullCData(oldp+176,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data_r),4);
        tracep->fullCData(oldp+177,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To_r),2);
        tracep->fullBit(oldp+178,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__SO_n_o));
        tracep->fullCData(oldp+179,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA_r),8);
        tracep->fullCData(oldp+180,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB),8);
        tracep->fullCData(oldp+181,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusB_r),8);
        tracep->fullBit(oldp+182,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__rdy_mod));
        tracep->fullCData(oldp+183,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__xhdl0__DOT__tmpP),8);
        tracep->fullBit(oldp+184,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq)))));
        tracep->fullCData(oldp+185,((0xffU & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddra)))),8);
        tracep->fullBit(oldp+186,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_oe_l));
        tracep->fullBit(oldp+187,(vlTOPp->top__DOT__oricatmos__DOT__via_cb2_oe_l));
        tracep->fullBit(oldp+188,(vlTOPp->top__DOT__oricatmos__DOT__OPEN));
        tracep->fullBit(oldp+189,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH) 
                                         >> 4U))));
        tracep->fullCData(oldp+190,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH),5);
        tracep->fullBit(oldp+191,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lInv_hold));
        tracep->fullCData(oldp+192,((0xffU & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddrb)))),8);
        tracep->fullCData(oldp+193,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddra),8);
        tracep->fullCData(oldp+194,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ira),8);
        tracep->fullCData(oldp+195,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ddrb),8);
        tracep->fullCData(oldp+196,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_orb),8);
        tracep->fullCData(oldp+197,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_irb),8);
        tracep->fullCData(oldp+198,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_l),8);
        tracep->fullCData(oldp+199,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t1l_h),8);
        tracep->fullCData(oldp+200,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ier),7);
        tracep->fullBit(oldp+201,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ifr_write_ena));
        tracep->fullBit(oldp+202,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ier_write_ena));
        tracep->fullBit(oldp+203,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7));
        tracep->fullBit(oldp+204,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_w_reset_int));
        tracep->fullBit(oldp+205,((1U & ((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_oe_l)) 
                                         | (IData)(vlTOPp->top__DOT__tape_adc)))));
        tracep->fullBit(oldp+206,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_c));
        tracep->fullBit(oldp+207,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_ip_reg_d));
        tracep->fullBit(oldp+208,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_c));
        tracep->fullBit(oldp+209,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_ip_reg_d));
        tracep->fullBit(oldp+210,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_irq));
        tracep->fullBit(oldp+211,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_irq));
        tracep->fullBit(oldp+212,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_c));
        tracep->fullBit(oldp+213,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_ip_reg_d));
        tracep->fullBit(oldp+214,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_c));
        tracep->fullBit(oldp+215,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_ip_reg_d));
        tracep->fullBit(oldp+216,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_irq));
        tracep->fullBit(oldp+217,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_irq));
        tracep->fullBit(oldp+218,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq));
        tracep->fullBit(oldp+219,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_op));
        tracep->fullBit(oldp+220,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE) 
                                         >> 2U))));
        tracep->fullBit(oldp+221,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE) 
                                         >> 1U))));
        tracep->fullCData(oldp+222,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_INK),3);
        tracep->fullCData(oldp+223,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_PAPER),3);
        tracep->fullCData(oldp+224,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE),3);
        tracep->fullBit(oldp+225,(vlTOPp->top__DOT__fdd_ready));
        tracep->fullBit(oldp+226,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active));
        tracep->fullBit(oldp+227,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active)
                                          ? (0x7ffU 
                                             & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                >> 9U))
                                          : ((0x7ffU 
                                              & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a 
                                                 >> 9U)) 
                                             + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block))))));
        tracep->fullBit(oldp+228,(vlTOPp->top__DOT__sd_rd));
        tracep->fullBit(oldp+229,(vlTOPp->top__DOT__sd_wr));
        tracep->fullIData(oldp+230,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_active)
                                      ? (0x7ffU & (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                   >> 9U))
                                      : ((0x7ffU & 
                                          (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a 
                                           >> 9U)) 
                                         + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block)))),32);
        tracep->fullCData(oldp+231,(vlTOPp->top__DOT__oricatmos__DOT__cpu_di),8);
        tracep->fullBit(oldp+232,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen16));
        tracep->fullCData(oldp+233,(vlTOPp->top__DOT__oricatmos__DOT__ROM_ATMOS_DO),8);
        tracep->fullCData(oldp+234,(vlTOPp->top__DOT__oricatmos__DOT__ROM_1_DO),8);
        tracep->fullCData(oldp+235,(vlTOPp->top__DOT__oricatmos__DOT__ROM_MD_DO),8);
        tracep->fullBit(oldp+236,(vlTOPp->top__DOT__oricatmos__DOT__cont_ROMDISn));
        tracep->fullBit(oldp+237,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq) 
                                            & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN))))));
        tracep->fullSData(oldp+238,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c),16);
        tracep->fullBit(oldp+239,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c_active));
        tracep->fullBit(oldp+240,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1c_done));
        tracep->fullBit(oldp+241,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_reload_counter));
        tracep->fullBit(oldp+242,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_int_enable));
        tracep->fullBit(oldp+243,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_toggle));
        tracep->fullBit(oldp+244,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_irq));
        tracep->fullBit(oldp+245,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_c));
        tracep->fullBit(oldp+246,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_pb7_en_d));
        tracep->fullBit(oldp+247,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer1_done__DOT__done));
        tracep->fullCData(oldp+248,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__addr),4);
        tracep->fullCData(oldp+249,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__din_latch),8);
        tracep->fullCData(oldp+250,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__envelope),5);
        tracep->fullBit(oldp+251,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__noise));
        tracep->fullBit(oldp+252,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Amix));
        tracep->fullBit(oldp+253,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Bmix));
        tracep->fullBit(oldp+254,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__Cmix));
        tracep->fullBit(oldp+255,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__cen256));
        tracep->fullCData(oldp+256,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logA),5);
        tracep->fullCData(oldp+257,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logB),5);
        tracep->fullCData(oldp+258,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__logC),5);
        tracep->fullCData(oldp+259,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__lin),8);
        tracep->fullCData(oldp+260,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__read_mask),8);
        tracep->fullBit(oldp+261,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__write));
        tracep->fullBit(oldp+262,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__rst_latch));
        tracep->fullBit(oldp+263,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy) 
                                         >> 1U))));
        tracep->fullBit(oldp+264,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq));
        tracep->fullBit(oldp+265,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__SSEL));
        tracep->fullBit(oldp+266,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN));
        tracep->fullBit(oldp+267,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy))));
        tracep->fullIData(oldp+268,((0xfffffU & ((0xffe00U 
                                                  & vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a) 
                                                 + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr)))),20);
        tracep->fullCData(oldp+269,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_size_code),2);
        tracep->fullCData(oldp+270,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sectors_per_track),8);
        tracep->fullCData(oldp+271,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_spt),8);
        tracep->fullSData(oldp+272,((0x7ffU & ((IData)(0x80U) 
                                               << (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_size_code)))),11);
        tracep->fullSData(oldp+273,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__byte_addr),11);
        tracep->fullIData(oldp+274,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_a),20);
        tracep->fullCData(oldp+275,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__sd_block),2);
        tracep->fullBit(oldp+276,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__format));
        tracep->fullBit(oldp+277,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_crcerr));
        tracep->fullBit(oldp+278,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_headloaded));
        tracep->fullBit(oldp+279,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_seekerr));
        tracep->fullBit(oldp+280,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_lostdata));
        tracep->fullBit(oldp+281,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wrfault));
        tracep->fullBit(oldp+282,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__cmd_mode));
        tracep->fullBit(oldp+283,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_wpe));
        tracep->fullCData(oldp+284,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_drq_busy),2);
        tracep->fullCData(oldp+285,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_track),8);
        tracep->fullCData(oldp+286,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_sector),8);
        tracep->fullCData(oldp+287,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wdreg_data),8);
        tracep->fullCData(oldp+288,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_track),8);
        tracep->fullCData(oldp+289,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[0]),8);
        tracep->fullCData(oldp+290,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[1]),8);
        tracep->fullCData(oldp+291,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[2]),8);
        tracep->fullCData(oldp+292,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[3]),8);
        tracep->fullCData(oldp+293,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[4]),8);
        tracep->fullCData(oldp+294,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__read_addr[5]),8);
        tracep->fullBit(oldp+295,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__var_size));
        tracep->fullIData(oldp+296,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__disk_size),20);
        tracep->fullBit(oldp+297,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__layout_r));
        tracep->fullIData(oldp+298,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__hs),20);
        tracep->fullCData(oldp+299,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__dts),8);
        tracep->fullBit(oldp+300,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_rd));
        tracep->fullBit(oldp+301,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__step_direction));
        tracep->fullSData(oldp+302,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__data_length),11);
        tracep->fullIData(oldp+303,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__state),32);
        tracep->fullSData(oldp+304,((0x7ffU & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__data_length) 
                                               - (IData)(1U)))),11);
        tracep->fullBit(oldp+305,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__watchdog_set));
        tracep->fullSData(oldp+306,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer),16);
        tracep->fullBit(oldp+307,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wd_timer))));
        tracep->fullIData(oldp+308,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr),20);
        tracep->fullBit(oldp+309,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_wr));
        tracep->fullCData(oldp+310,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sizecode),2);
        tracep->fullBit(oldp+311,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_side));
        tracep->fullCData(oldp+312,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_track),7);
        tracep->fullCData(oldp+313,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sector),8);
        tracep->fullIData(oldp+314,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_offset),20);
        tracep->fullCData(oldp+315,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_trackf),8);
        tracep->fullCData(oldp+316,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_sidef),8);
        tracep->fullSData(oldp+317,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_addr),11);
        tracep->fullSData(oldp+318,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_start),11);
        tracep->fullSData(oldp+319,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__edsk_next),11);
        tracep->fullCData(oldp+320,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_size),8);
        tracep->fullBit(oldp+321,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_wr));
        tracep->fullCData(oldp+322,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__blk_size),2);
        tracep->fullCData(oldp+323,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__spt_addr),8);
        tracep->fullBit(oldp+324,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_wr));
        tracep->fullBit(oldp+325,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_rd));
        tracep->fullCData(oldp+326,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__cur_addr),3);
        tracep->fullBit(oldp+327,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_data));
        tracep->fullBit(oldp+328,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write_data));
        tracep->fullBit(oldp+329,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__rw_type));
        tracep->fullIData(oldp+330,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__wait_time),32);
        tracep->fullCData(oldp+331,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__read_timer),4);
        tracep->fullSData(oldp+332,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__seektimer),10);
        tracep->fullCData(oldp+333,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ra_sector),8);
        tracep->fullBit(oldp+334,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__multisector));
        tracep->fullBit(oldp+335,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__write));
        tracep->fullCData(oldp+336,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__ack),6);
        tracep->fullBit(oldp+337,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__sd_busy));
        tracep->fullBit(oldp+338,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__old_mounted));
        tracep->fullCData(oldp+339,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_state),4);
        tracep->fullCData(oldp+340,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__scan_cnt),2);
        tracep->fullCData(oldp+341,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__unnamedblk2__DOT__blk_max),2);
        __Vtemp15[0U] = 0x2044534bU;
        __Vtemp15[1U] = 0x20435043U;
        __Vtemp15[2U] = 0x4e444544U;
        __Vtemp15[3U] = 0x45585445U;
        VL_SHIFTR_WWI(128,128,8, __Vtemp16, __Vtemp15, 
                      (0xffU & ((IData)(0x78U) - (vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__scan_addr 
                                                  << 3U))));
        tracep->fullWData(oldp+342,(__Vtemp16),128);
        tracep->fullSData(oldp+346,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_a),11);
        tracep->fullSData(oldp+347,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__address_b),11);
        tracep->fullBit(oldp+348,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                         >> 7U))));
        tracep->fullBit(oldp+349,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                         >> 6U))));
        tracep->fullCData(oldp+350,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ora),8);
        tracep->fullBit(oldp+351,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cb1_out));
        tracep->fullBit(oldp+352,(vlTOPp->top__DOT__oricatmos__DOT__via_cb2_out));
        tracep->fullCData(oldp+353,(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out),8);
        tracep->fullBit(oldp+354,(vlTOPp->top__DOT__oricatmos__DOT__psg_bdir));
        tracep->fullBit(oldp+355,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out) 
                                         >> 4U))));
        tracep->fullBit(oldp+356,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib));
        tracep->fullCData(oldp+357,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREGHOLD),7);
        tracep->fullCData(oldp+358,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_sr),8);
        tracep->fullCData(oldp+359,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_pcr),8);
        tracep->fullCData(oldp+360,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ifr),8);
        tracep->fullBit(oldp+361,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_write_ena));
        tracep->fullCData(oldp+362,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__clear_irq),8);
        tracep->fullCData(oldp+363,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__load_data),8);
        tracep->fullBit(oldp+364,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_w_reset_int));
        tracep->fullBit(oldp+365,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_load_counter));
        tracep->fullCData(oldp+366,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_cnt),4);
        tracep->fullBit(oldp+367,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_drive_cb2));
        tracep->fullBit(oldp+368,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_do_shift));
        tracep->fullBit(oldp+369,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_irq));
        tracep->fullBit(oldp+370,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_out));
        tracep->fullBit(oldp+371,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_active));
        tracep->fullBit(oldp+372,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__w_orb_hs));
        tracep->fullBit(oldp+373,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__w_ora_hs));
        tracep->fullBit(oldp+374,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_sr));
        tracep->fullBit(oldp+375,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca_hs_pulse));
        tracep->fullBit(oldp+376,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_sr));
        tracep->fullBit(oldp+377,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb_hs_pulse));
        tracep->fullBit(oldp+378,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca1_int));
        tracep->fullBit(oldp+379,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb1_int));
        tracep->fullBit(oldp+380,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__ca2_int));
        tracep->fullBit(oldp+381,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cb2_int));
        tracep->fullBit(oldp+382,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__dir_out));
        tracep->fullBit(oldp+383,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__ena));
        tracep->fullBit(oldp+384,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__cb1_ip));
        tracep->fullBit(oldp+385,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__use_t2));
        tracep->fullBit(oldp+386,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__free_run));
        tracep->fullBit(oldp+387,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_sr__DOT__sr_count_ena));
        tracep->fullCData(oldp+388,((7U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__via_pb_out))),3);
        tracep->fullCData(oldp+389,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                    [0xeU]),8);
        tracep->fullCData(oldp+390,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                    [0xfU]),8);
        tracep->fullCData(oldp+391,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[0]),8);
        tracep->fullCData(oldp+392,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[1]),8);
        tracep->fullCData(oldp+393,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[2]),8);
        tracep->fullCData(oldp+394,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[3]),8);
        tracep->fullCData(oldp+395,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[4]),8);
        tracep->fullCData(oldp+396,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[5]),8);
        tracep->fullCData(oldp+397,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[6]),8);
        tracep->fullCData(oldp+398,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[7]),8);
        tracep->fullCData(oldp+399,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[8]),8);
        tracep->fullCData(oldp+400,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[9]),8);
        tracep->fullCData(oldp+401,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[10]),8);
        tracep->fullCData(oldp+402,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[11]),8);
        tracep->fullCData(oldp+403,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[12]),8);
        tracep->fullCData(oldp+404,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[13]),8);
        tracep->fullCData(oldp+405,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[14]),8);
        tracep->fullCData(oldp+406,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray[15]),8);
        tracep->fullCData(oldp+407,(((0x40U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                      [7U]) ? vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [0xeU] : 0U)),8);
        tracep->fullCData(oldp+408,(((0x80U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                      [7U]) ? vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [0xfU] : 0U)),8);
        tracep->fullBit(oldp+409,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitA));
        tracep->fullBit(oldp+410,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitB));
        tracep->fullBit(oldp+411,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__bitC));
        tracep->fullSData(oldp+412,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period),16);
        tracep->fullBit(oldp+413,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period))));
        tracep->fullCData(oldp+414,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__log),5);
        tracep->fullCData(oldp+415,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                               [8U] 
                                               << 1U)) 
                                     | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                              [8U] 
                                              >> 3U)))),5);
        tracep->fullCData(oldp+416,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                               [9U] 
                                               << 1U)) 
                                     | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                              [9U] 
                                              >> 3U)))),5);
        tracep->fullCData(oldp+417,(((0x1eU & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                               [0xaU] 
                                               << 1U)) 
                                     | (1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                              [0xaU] 
                                              >> 3U)))),5);
        tracep->fullBit(oldp+418,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [8U] >> 4U))));
        tracep->fullBit(oldp+419,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [9U] >> 4U))));
        tracep->fullBit(oldp+420,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [0xaU] >> 4U))));
        tracep->fullBit(oldp+421,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [7U] >> 3U))));
        tracep->fullBit(oldp+422,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [7U] >> 4U))));
        tracep->fullBit(oldp+423,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [7U] >> 5U))));
        tracep->fullSData(oldp+424,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt),10);
        tracep->fullBit(oldp+425,((1U & (~ (IData)(
                                                   (0U 
                                                    != 
                                                    (7U 
                                                     & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt))))))));
        tracep->fullBit(oldp+426,((1U & (~ (IData)(
                                                   (0U 
                                                    != 
                                                    (3U 
                                                     & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_cen__DOT__cencnt))))))));
        tracep->fullSData(oldp+427,(((0xf00U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [1U] 
                                                << 8U)) 
                                     | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [0U])),12);
        tracep->fullSData(oldp+428,(((0xf00U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [3U] 
                                                << 8U)) 
                                     | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [2U])),12);
        tracep->fullSData(oldp+429,(((0xf00U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                                [5U] 
                                                << 8U)) 
                                     | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [4U])),12);
        tracep->fullCData(oldp+430,((0x1fU & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [6U])),5);
        tracep->fullIData(oldp+431,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17),17);
        tracep->fullBit(oldp+432,((0U == vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__poly17)));
        tracep->fullCData(oldp+433,((0xfU & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                     [0xdU])),4);
        tracep->fullBit(oldp+434,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__inv));
        tracep->fullCData(oldp+435,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__gain),5);
        tracep->fullBit(oldp+436,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [0xdU] >> 3U))));
        tracep->fullBit(oldp+437,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [0xdU] >> 2U))));
        tracep->fullBit(oldp+438,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [0xdU] >> 1U))));
        tracep->fullBit(oldp+439,((1U & vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                   [0xdU])));
        tracep->fullBit(oldp+440,((1U & ((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                             [0xdU] 
                                             >> 3U)) 
                                         | vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
                                         [0xdU]))));
        tracep->fullBit(oldp+441,((1U & (((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__regarray
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
        tracep->fullBit(oldp+442,(vlTOPp->top__DOT__oricatmos__DOT__RESETn));
        tracep->fullBit(oldp+443,(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET));
        tracep->fullBit(oldp+444,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn)))));
        tracep->fullBit(oldp+445,(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_psg__rst_n));
        tracep->fullBit(oldp+446,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT____Vcellinp__inst_microdisc__nRESET)))));
        tracep->fullSData(oldp+447,(vlTOPp->top__DOT__ram_ad_temp),16);
        tracep->fullBit(oldp+448,(vlTOPp->top__DOT__ram_we_temp));
        tracep->fullBit(oldp+449,(vlTOPp->top__DOT__ram_cs_temp));
        tracep->fullCData(oldp+450,(vlTOPp->top__DOT__ram_q),8);
        tracep->fullSData(oldp+451,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__AD_RAM_INT),16);
        tracep->fullCData(oldp+452,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lDATABUS),8);
        tracep->fullCData(oldp+453,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__phase),2);
        tracep->fullBit(oldp+454,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p2_h_dl));
        tracep->fullSData(oldp+455,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2c),16);
        tracep->fullBit(oldp+456,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6));
        tracep->fullBit(oldp+457,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_pb6_t1));
        tracep->fullBit(oldp+458,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_cnt_clk));
        tracep->fullBit(oldp+459,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_reload_counter));
        tracep->fullBit(oldp+460,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_sr_ena));
        tracep->fullBit(oldp+461,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_t1));
        tracep->fullBit(oldp+462,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_falling));
        tracep->fullBit(oldp+463,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe_rising));
        tracep->fullBit(oldp+464,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2_done__DOT__done_sr));
        tracep->fullBit(oldp+465,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__p_timer2__DOT__ena));
        tracep->fullBit(oldp+466,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                         >> 2U))));
        tracep->fullBit(oldp+467,((0xc7U < (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))));
        tracep->fullBit(oldp+468,((1U & (~ ((0x31U 
                                             <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)) 
                                            & (0x35U 
                                               >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))))));
        tracep->fullBit(oldp+469,((1U & (~ ((0x102U 
                                             <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                            & (0x103U 
                                               >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))))));
        tracep->fullBit(oldp+470,((1U & (~ ((0xf1U 
                                             <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                            & (0xf2U 
                                               >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))))));
        tracep->fullBit(oldp+471,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__BLANKINGn));
        tracep->fullBit(oldp+472,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lRELOAD_SEL));
        tracep->fullCData(oldp+473,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H),7);
        tracep->fullSData(oldp+474,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V),9);
        tracep->fullCData(oldp+475,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph),3);
        tracep->fullBit(oldp+476,((0xe0U > (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))));
        tracep->fullBit(oldp+477,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lHBLANKn));
        tracep->fullCData(oldp+478,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_l),8);
        tracep->fullCData(oldp+479,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_t2l_h),8);
        tracep->fullCData(oldp+480,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_acr),8);
        tracep->fullBit(oldp+481,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_load_counter));
        tracep->fullBit(oldp+482,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_strobe));
        tracep->fullBit(oldp+483,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT))));
        tracep->fullBit(oldp+484,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT) 
                                         >> 1U))));
        tracep->fullBit(oldp+485,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT) 
                                         >> 2U))));
        tracep->fullBit(oldp+486,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC));
        tracep->fullBit(oldp+487,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                         >> 1U))));
        tracep->fullBit(oldp+488,((1U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE))));
        tracep->fullCData(oldp+489,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__RGB_INT),3);
        tracep->fullBit(oldp+490,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                          >> 1U) & 
                                         (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))))));
        tracep->fullSData(oldp+491,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8),9);
        tracep->fullSData(oldp+492,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC)
                                      ? 0xa000U : 0xbb80U)),16);
        tracep->fullSData(oldp+493,((0x7fffU & ((0x7fe0U 
                                                 & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                    << 5U)) 
                                                + ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                   << 3U)))),15);
        tracep->fullCData(oldp+494,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lRGB),3);
        tracep->fullCData(oldp+495,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE),3);
        tracep->fullCData(oldp+496,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle),2);
        tracep->fullCData(oldp+497,(((3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                      ? 0x27U : ((2U 
                                                  == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                                  ? 0x26U
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                                   ? 0x2eU
                                                   : 0x2dU)))),6);
        tracep->fullBit(oldp+498,((1U & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                         >> 2U))));
        tracep->fullCData(oldp+499,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__DO_r),8);
        tracep->fullIData(oldp+500,(vlTOPp->top__DOT__oricatmos__DOT__cpu_ad),24);
        tracep->fullBit(oldp+501,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i));
        tracep->fullBit(oldp+502,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inECE));
        tracep->fullBit(oldp+503,((0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle))));
        tracep->fullBit(oldp+504,((1U & (~ (((2U != 
                                              (3U & 
                                               ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                >> 6U))) 
                                             & (3U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                    >> 1U)))) 
                                            & (0U != 
                                               (3U 
                                                & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle) 
                                                   >> 1U))))))));
        tracep->fullBit(oldp+505,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle) 
                                            & ((5U 
                                                == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle)) 
                                               | (6U 
                                                  == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle))))))));
        tracep->fullBit(oldp+506,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Jump) 
                                            >> 1U)))));
        tracep->fullCData(oldp+507,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR),8);
        tracep->fullCData(oldp+508,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P),8);
        tracep->fullBit(oldp+509,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMIAct));
        tracep->fullCData(oldp+510,((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle) 
                                      | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMICycle))
                                      ? (0xefU & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P))
                                      : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P))),8);
        tracep->fullCData(oldp+511,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__MCycle),3);
        tracep->fullSData(oldp+512,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdder),9);
        tracep->fullBit(oldp+513,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__RstCycle));
        tracep->fullBit(oldp+514,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQCycle));
        tracep->fullBit(oldp+515,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMICycle));
        tracep->fullBit(oldp+516,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IRQ_n_o));
        tracep->fullBit(oldp+517,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_n_o));
        tracep->fullBit(oldp+518,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Break));
        tracep->fullCData(oldp+519,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BusA),8);
        tracep->fullCData(oldp+520,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Q),8);
        tracep->fullCData(oldp+521,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P_Out),8);
        tracep->fullCData(oldp+522,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LCycle),3);
        tracep->fullCData(oldp+523,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ALU_Op),5);
        tracep->fullCData(oldp+524,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_BusA_To),4);
        tracep->fullCData(oldp+525,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Set_Addr_To),2);
        tracep->fullCData(oldp+526,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write_Data),4);
        tracep->fullCData(oldp+527,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Jump),2);
        tracep->fullCData(oldp+528,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAAdd),2);
        tracep->fullCData(oldp+529,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BAQuirk),2);
        tracep->fullBit(oldp+530,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__BreakAtNA));
        tracep->fullBit(oldp+531,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__ADAdd));
        tracep->fullBit(oldp+532,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__AddY));
        tracep->fullBit(oldp+533,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PCAdd));
        tracep->fullBit(oldp+534,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Inc_S));
        tracep->fullBit(oldp+535,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Dec_S));
        tracep->fullBit(oldp+536,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDA));
        tracep->fullBit(oldp+537,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDP));
        tracep->fullBit(oldp+538,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDX));
        tracep->fullBit(oldp+539,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDY));
        tracep->fullBit(oldp+540,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDS));
        tracep->fullBit(oldp+541,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDDI));
        tracep->fullBit(oldp+542,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDALU));
        tracep->fullBit(oldp+543,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDAD));
        tracep->fullBit(oldp+544,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAL));
        tracep->fullBit(oldp+545,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__LDBAH));
        tracep->fullBit(oldp+546,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__SaveP));
        tracep->fullBit(oldp+547,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Write));
        tracep->fullBit(oldp+548,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__NMI_entered));
        tracep->fullBit(oldp+549,((1U & ((0U == (7U 
                                                 & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                    >> 5U)))
                                          ? (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                >> 7U))
                                          : ((1U == 
                                              (7U & 
                                               ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__IR) 
                                                >> 5U)))
                                              ? ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__P) 
                                                 >> 7U)
                                              : ((2U 
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
        tracep->fullBit(oldp+550,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__mcode__DOT__ALUmore));
        tracep->fullBit(oldp+551,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Z));
        tracep->fullBit(oldp+552,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_C));
        tracep->fullBit(oldp+553,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_V));
        tracep->fullBit(oldp+554,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_N));
        tracep->fullCData(oldp+555,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__ADC_Q),8);
        tracep->fullBit(oldp+556,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Z));
        tracep->fullBit(oldp+557,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_C));
        tracep->fullBit(oldp+558,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_V));
        tracep->fullBit(oldp+559,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_N));
        tracep->fullCData(oldp+560,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBC_Q),8);
        tracep->fullCData(oldp+561,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__SBX_Q),8);
        tracep->fullCData(oldp+562,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AL),7);
        tracep->fullCData(oldp+563,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__AH),7);
        tracep->fullBit(oldp+564,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl0__DOT__C));
        tracep->fullCData(oldp+565,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AL),7);
        tracep->fullCData(oldp+566,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__AH),6);
        tracep->fullBit(oldp+567,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__C));
        tracep->fullBit(oldp+568,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl1__DOT__CT));
        tracep->fullCData(oldp+569,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q_t),8);
        tracep->fullCData(oldp+570,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__alu__DOT__xhdl2__DOT__Q2_t),8);
        tracep->fullSData(oldp+571,((0x3fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),14);
        tracep->fullSData(oldp+572,((0x1fffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),13);
        tracep->fullSData(oldp+573,((0xffffU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),16);
        tracep->fullCData(oldp+574,((0xfU & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),4);
        tracep->fullCData(oldp+575,((3U & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)),2);
        tracep->fullCData(oldp+576,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__q),8);
        tracep->fullBit(oldp+577,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__u16k));
        tracep->fullCData(oldp+578,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__next_track),8);
        tracep->fullCData(oldp+579,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__data_b),8);
        tracep->fullBit(oldp+580,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CLK_PIXEL_INT));
        tracep->fullBit(oldp+581,((1U & (((~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                              >> 4U)) 
                                          & (~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                >> 0xcU))) 
                                         & (~ (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                               >> 0x14U))))));
        tracep->fullBit(oldp+582,(((((0U != (7U & vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c)) 
                                     | (0U != (7U & 
                                               (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                >> 6U)))) 
                                    | (0U != (7U & 
                                              (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                               >> 0xcU)))) 
                                   | (0U != (7U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                                   >> 0x12U))))));
        tracep->fullBit(oldp+583,(vlTOPp->top__DOT__oricatmos__DOT__ula_CLK_4_en));
        tracep->fullBit(oldp+584,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                         >> 0xfU))));
        tracep->fullBit(oldp+585,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                         >> 3U))));
        tracep->fullBit(oldp+586,((1U & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                         >> 0x11U))));
        tracep->fullBit(oldp+587,((1U & ((vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                          >> 2U) | 
                                         (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                          >> 0xaU)))));
        tracep->fullIData(oldp+588,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c),24);
        tracep->fullCData(oldp+589,(vlTOPp->top__DOT__oricatmos__DOT__VIA_DO),8);
        tracep->fullBit(oldp+590,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT));
        tracep->fullBit(oldp+591,(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT));
        tracep->fullBit(oldp+592,(vlTOPp->top__DOT__oricatmos__DOT__cont_MAPn));
        tracep->fullBit(oldp+593,(vlTOPp->top__DOT__oricatmos__DOT__cont_IOCONTROLn));
        tracep->fullBit(oldp+594,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__O_DATA_OE_L));
        tracep->fullBit(oldp+595,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__cs));
        tracep->fullBit(oldp+596,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__sr_read_ena));
        tracep->fullBit(oldp+597,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t1_r_reset_int));
        tracep->fullBit(oldp+598,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__t2_r_reset_int));
        tracep->fullBit(oldp+599,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_irb_hs));
        tracep->fullBit(oldp+600,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__r_ira_hs));
        tracep->fullCData(oldp+601,(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__orb),8);
        tracep->fullBit(oldp+602,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nCS));
        tracep->fullBit(oldp+603,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nRE));
        tracep->fullBit(oldp+604,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel));
        tracep->fullBit(oldp+605,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nCS)))));
        tracep->fullBit(oldp+606,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_nRE)))));
        tracep->fullBit(oldp+607,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__rde));
        tracep->fullBit(oldp+608,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__wre));
        tracep->fullBit(oldp+609,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT____Vcellinp__genblk1__DOT__sbuf__wren_b));
        tracep->fullBit(oldp+610,(vlTOPp->clk_48));
        tracep->fullBit(oldp+611,(vlTOPp->reset));
        tracep->fullSData(oldp+612,(vlTOPp->inputs),12);
        tracep->fullCData(oldp+613,(vlTOPp->VGA_R),8);
        tracep->fullCData(oldp+614,(vlTOPp->VGA_G),8);
        tracep->fullCData(oldp+615,(vlTOPp->VGA_B),8);
        tracep->fullBit(oldp+616,(vlTOPp->VGA_HS));
        tracep->fullBit(oldp+617,(vlTOPp->VGA_VS));
        tracep->fullBit(oldp+618,(vlTOPp->VGA_HB));
        tracep->fullBit(oldp+619,(vlTOPp->VGA_VB));
        tracep->fullSData(oldp+620,(vlTOPp->AUDIO_L),16);
        tracep->fullSData(oldp+621,(vlTOPp->AUDIO_R),16);
        tracep->fullBit(oldp+622,(vlTOPp->ioctl_download));
        tracep->fullBit(oldp+623,(vlTOPp->ioctl_upload));
        tracep->fullBit(oldp+624,(vlTOPp->ioctl_wr));
        tracep->fullIData(oldp+625,(vlTOPp->ioctl_addr),25);
        tracep->fullCData(oldp+626,(vlTOPp->ioctl_dout),8);
        tracep->fullCData(oldp+627,(vlTOPp->ioctl_din),8);
        tracep->fullCData(oldp+628,(vlTOPp->ioctl_index),8);
        tracep->fullBit(oldp+629,(vlTOPp->ioctl_wait));
        tracep->fullBit(oldp+630,(vlTOPp->ce_pix));
        tracep->fullSData(oldp+631,((0xffffU & ((4U 
                                                 & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph))
                                                 ? vlTOPp->top__DOT__oricatmos__DOT__cpu_ad
                                                 : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__AD_RAM_INT)))),16);
        tracep->fullBit(oldp+632,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                   & (((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)) 
                                       & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))) 
                                      & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                         >> 0x11U)))));
        tracep->fullBit(oldp+633,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                   & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                          >> 1U)) | 
                                      (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                        >> 2U) & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)))))));
        tracep->fullBit(oldp+634,((1U & (~ (IData)(vlTOPp->reset)))));
        tracep->fullSData(oldp+635,((0xffffU & vlTOPp->ioctl_addr)),16);
        tracep->fullBit(oldp+636,((1U & (~ ((~ ((0x31U 
                                                 <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)) 
                                                & (0x35U 
                                                   >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))) 
                                            ^ ((2U 
                                                & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE))
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
        tracep->fullBit(oldp+637,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__RESETn) 
                                   & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                       | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                          >> 1U)) | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))));
        tracep->fullCData(oldp+638,(vlTOPp->top__DOT__oricatmos__DOT__via_pa_in),8);
        tracep->fullCData(oldp+639,(vlTOPp->top__DOT__oricatmos__DOT__via_pb_in),8);
        tracep->fullBit(oldp+640,((1U & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__swnmi)))));
        tracep->fullBit(oldp+641,((1U & (~ (((3U == 
                                              (3U & 
                                               (vlTOPp->top__DOT__oricatmos__DOT__cpu_ad 
                                                >> 0xeU))) 
                                             & (IData)(vlTOPp->top__DOT__oricatmos__DOT__cont_MAPn)) 
                                            & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                               >> 2U))))));
        tracep->fullBit(oldp+642,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                          | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                             >> 1U)) 
                                         | (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                             >> 2U) 
                                            & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)))))));
        tracep->fullBit(oldp+643,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                          | ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                             >> 1U)) 
                                         | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i)))));
        tracep->fullBit(oldp+644,((1U & (((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSRAMn_INT)) 
                                          & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))) 
                                         & (vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__c 
                                            >> 0x11U)))));
        tracep->fullBit(oldp+645,(vlTOPp->top__DOT__oricatmos__DOT__swnmi));
        tracep->fullCData(oldp+646,(((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out0) 
                                       | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out1)) 
                                      | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out2)) 
                                     | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__DO__out__out3))),8);
        tracep->fullBit(oldp+647,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__sel) 
                                            & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                               >> 2U))))));
        tracep->fullBit(oldp+648,((1U & ((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_via__DOT__final_irq)) 
                                         & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__s_intrq) 
                                               & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__IRQEN)))))));
        tracep->fullQData(oldp+649,((((QData)((IData)(
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
        tracep->fullBit(oldp+651,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_i));
        tracep->fullBit(oldp+652,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__Res_n_d));
        tracep->fullSData(oldp+653,((0xffffU & ((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC)
                                                   ? 0xa000U
                                                   : 0xbb80U) 
                                                 + 
                                                 (0x7fffU 
                                                  & ((0x7fe0U 
                                                      & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                         << 5U)) 
                                                     + 
                                                     ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CTR_V_DIV8) 
                                                      << 3U)))) 
                                                + (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_H)))),16);
        tracep->fullSData(oldp+654,(((((3U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ModeStyle))
                                        ? 0x27U : (
                                                   (2U 
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
        tracep->fullBit(oldp+655,((1U & ((2U & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_MODE))
                                          ? (~ ((0x102U 
                                                 <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                                & (0x103U 
                                                   >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))
                                          : (~ ((0xf1U 
                                                 <= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)) 
                                                & (0xf2U 
                                                   >= (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V))))))));
        tracep->fullBit(oldp+656,((1U & (((((~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__isAttrib)) 
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
        tracep->fullCData(oldp+657,((7U & ((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                                   >> 1U) 
                                                  & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__HIRES_DEC))))
                                            ? ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V) 
                                               >> 1U)
                                            : (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_V)))),3);
        tracep->fullBit(oldp+658,((1U & ((~ (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lCTR_FLASH) 
                                              >> 4U) 
                                             & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lREG_STYLE) 
                                                >> 2U))) 
                                         & ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__lSHFREG) 
                                            >> 5U)))));
        tracep->fullBit(oldp+659,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__write) 
                                   & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__last_write)))));
        tracep->fullBit(oldp+660,((((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_step) 
                                    & (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_env__DOT__last_step))) 
                                   | (0U == (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__eg_period)))));
        tracep->fullBit(oldp+661,((1U & (((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__ph) 
                                          >> 2U) | 
                                         (~ (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))))));
        tracep->fullBit(oldp+662,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT) 
                                   | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))));
        tracep->fullBit(oldp+663,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc_CLK_en));
        tracep->fullCData(oldp+664,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__count),3);
        tracep->fullBit(oldp+665,((1U & (~ ((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_ula__DOT__CSIOn_INT) 
                                            | (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__WRn_i))))));
        tracep->fullBit(oldp+666,(((3U == (3U & vlTOPp->top__DOT__oricatmos__DOT__cpu_ad)) 
                                   & (IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__buff_rd))));
        tracep->fullCData(oldp+667,(((IData)(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__cmd_mode)
                                      ? ((0x80U & (
                                                   (~ (IData)(vlTOPp->top__DOT__fdd_ready)) 
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
                                      : ((0x80U & (
                                                   (~ (IData)(vlTOPp->top__DOT__fdd_ready)) 
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
        tracep->fullSData(oldp+668,(vlTOPp->top__DOT__ps2_key),11);
        tracep->fullIData(oldp+669,(0U),17);
        tracep->fullBit(oldp+670,(vlTOPp->top__DOT__tape_request));
        tracep->fullSData(oldp+671,(vlTOPp->top__DOT__tape_read_addr),16);
        tracep->fullSData(oldp+672,(vlTOPp->top__DOT__tape_read_dout),16);
        tracep->fullBit(oldp+673,(vlTOPp->top__DOT__key_strobe));
        tracep->fullBit(oldp+674,(vlTOPp->top__DOT__tape_adc));
        tracep->fullBit(oldp+675,(vlTOPp->top__DOT__locked));
        tracep->fullBit(oldp+676,(vlTOPp->top__DOT__rom));
        tracep->fullBit(oldp+677,(vlTOPp->top__DOT__img_mounted));
        tracep->fullBit(oldp+678,(vlTOPp->top__DOT__img_size));
        tracep->fullBit(oldp+679,(vlTOPp->top__DOT__img_readonly));
        tracep->fullBit(oldp+680,(vlTOPp->top__DOT__sd_ack));
        tracep->fullBit(oldp+681,(vlTOPp->top__DOT__sd_buff_addr));
        tracep->fullBit(oldp+682,(vlTOPp->top__DOT__sd_buff_dout));
        tracep->fullBit(oldp+683,(vlTOPp->top__DOT__sd_buff_wr));
        tracep->fullIData(oldp+684,(8U),32);
        tracep->fullIData(oldp+685,(0x10U),32);
        tracep->fullBit(oldp+686,(1U));
        tracep->fullBit(oldp+687,(vlTOPp->top__DOT__cassette__DOT__autostart));
        tracep->fullIData(oldp+688,(1U),32);
        tracep->fullIData(oldp+689,(2U),32);
        tracep->fullIData(oldp+690,(3U),32);
        tracep->fullIData(oldp+691,(4U),32);
        tracep->fullIData(oldp+692,(5U),32);
        tracep->fullIData(oldp+693,(6U),32);
        tracep->fullIData(oldp+694,(7U),32);
        tracep->fullIData(oldp+695,(9U),32);
        tracep->fullIData(oldp+696,(0xaU),32);
        tracep->fullSData(oldp+697,(vlTOPp->top__DOT__cassette__DOT__programlength),16);
        tracep->fullBit(oldp+698,(vlTOPp->top__DOT__cassette__DOT__unused));
        tracep->fullBit(oldp+699,((1U & ((IData)(vlTOPp->top__DOT__ps2_key) 
                                         >> 9U))));
        tracep->fullBit(oldp+700,((1U & ((IData)(vlTOPp->top__DOT__ps2_key) 
                                         >> 8U))));
        tracep->fullCData(oldp+701,((0xffU & (IData)(vlTOPp->top__DOT__ps2_key))),8);
        tracep->fullBit(oldp+702,(0U));
        tracep->fullCData(oldp+703,(0U),8);
        tracep->fullIData(oldp+704,(vlTOPp->top__DOT__img_size),32);
        tracep->fullSData(oldp+705,(vlTOPp->top__DOT__sd_buff_addr),9);
        tracep->fullCData(oldp+706,(vlTOPp->top__DOT__sd_buff_dout),8);
        tracep->fullBit(oldp+707,(vlTOPp->top__DOT__oricatmos__DOT__reset_dll_h));
        tracep->fullCData(oldp+708,(0U),3);
        tracep->fullCData(oldp+709,(vlTOPp->top__DOT__oricatmos__DOT__via_pb_oe_l),8);
        tracep->fullBit(oldp+710,(vlTOPp->top__DOT__oricatmos__DOT__psg_bc1));
        tracep->fullBit(oldp+711,(vlTOPp->top__DOT__oricatmos__DOT__ula_MUX));
        tracep->fullBit(oldp+712,(vlTOPp->top__DOT__oricatmos__DOT__ula_RW_RAM));
        tracep->fullBit(oldp+713,(vlTOPp->top__DOT__oricatmos__DOT__ula_VIDEO_R));
        tracep->fullBit(oldp+714,(vlTOPp->top__DOT__oricatmos__DOT__ula_VIDEO_G));
        tracep->fullBit(oldp+715,(vlTOPp->top__DOT__oricatmos__DOT__ula_VIDEO_B));
        tracep->fullBit(oldp+716,(vlTOPp->top__DOT__oricatmos__DOT__PH2_1));
        tracep->fullBit(oldp+717,(vlTOPp->top__DOT__oricatmos__DOT__PH2_2));
        tracep->fullBit(oldp+718,(vlTOPp->top__DOT__oricatmos__DOT__PH2_3));
        tracep->fullCData(oldp+719,(vlTOPp->top__DOT__oricatmos__DOT__PH2_old),4);
        tracep->fullCData(oldp+720,(vlTOPp->top__DOT__oricatmos__DOT__PH2_cntr),5);
        tracep->fullIData(oldp+721,(0U),32);
        tracep->fullCData(oldp+722,(1U),3);
        tracep->fullCData(oldp+723,(2U),3);
        tracep->fullCData(oldp+724,(3U),3);
        tracep->fullCData(oldp+725,(4U),3);
        tracep->fullCData(oldp+726,(5U),3);
        tracep->fullCData(oldp+727,(6U),3);
        tracep->fullCData(oldp+728,(7U),3);
        tracep->fullCData(oldp+729,(0U),4);
        tracep->fullCData(oldp+730,(1U),4);
        tracep->fullCData(oldp+731,(2U),4);
        tracep->fullCData(oldp+732,(3U),4);
        tracep->fullCData(oldp+733,(4U),4);
        tracep->fullCData(oldp+734,(5U),4);
        tracep->fullCData(oldp+735,(6U),4);
        tracep->fullCData(oldp+736,(7U),4);
        tracep->fullCData(oldp+737,(8U),4);
        tracep->fullCData(oldp+738,(9U),4);
        tracep->fullCData(oldp+739,(0xaU),4);
        tracep->fullCData(oldp+740,(0U),2);
        tracep->fullCData(oldp+741,(1U),2);
        tracep->fullCData(oldp+742,(2U),2);
        tracep->fullCData(oldp+743,(3U),2);
        tracep->fullCData(oldp+744,(0xbU),4);
        tracep->fullCData(oldp+745,(0xcU),4);
        tracep->fullCData(oldp+746,(0U),5);
        tracep->fullCData(oldp+747,(1U),5);
        tracep->fullCData(oldp+748,(2U),5);
        tracep->fullCData(oldp+749,(3U),5);
        tracep->fullCData(oldp+750,(4U),5);
        tracep->fullCData(oldp+751,(5U),5);
        tracep->fullCData(oldp+752,(6U),5);
        tracep->fullCData(oldp+753,(7U),5);
        tracep->fullCData(oldp+754,(8U),5);
        tracep->fullCData(oldp+755,(9U),5);
        tracep->fullCData(oldp+756,(0xaU),5);
        tracep->fullCData(oldp+757,(0xbU),5);
        tracep->fullCData(oldp+758,(0xcU),5);
        tracep->fullCData(oldp+759,(0xdU),5);
        tracep->fullCData(oldp+760,(0xeU),5);
        tracep->fullCData(oldp+761,(0xfU),5);
        tracep->fullCData(oldp+762,(0x10U),5);
        tracep->fullCData(oldp+763,(0x11U),5);
        tracep->fullCData(oldp+764,(0x12U),5);
        tracep->fullBit(oldp+765,(vlTOPp->top__DOT__oricatmos__DOT__inst_cpu__DOT__PRINT));
        tracep->fullIData(oldp+766,(0xcU),32);
        tracep->fullSData(oldp+767,(1U),12);
        tracep->fullCData(oldp+768,(vlTOPp->top__DOT__oricatmos__DOT__inst_psg__DOT__u_jt49__DOT__u_ng__DOT__count),6);
        tracep->fullSData(oldp+769,(1U),16);
        tracep->fullBit(oldp+770,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__nCS));
        tracep->fullBit(oldp+771,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__inMCRQ));
        tracep->fullIData(oldp+772,((0xfffffU & (IData)(vlTOPp->top__DOT__img_size))),20);
        tracep->fullIData(oldp+773,(0U),20);
        __Vtemp17[0U] = 0x2044534bU;
        __Vtemp17[1U] = 0x20435043U;
        __Vtemp17[2U] = 0x4e444544U;
        __Vtemp17[3U] = 0x45585445U;
        tracep->fullWData(oldp+774,(__Vtemp17),128);
        tracep->fullSData(oldp+778,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__hdr_pos),14);
        tracep->fullSData(oldp+779,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__bcnt),14);
        tracep->fullCData(oldp+780,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__idStatus),8);
        tracep->fullCData(oldp+781,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__crc1),8);
        tracep->fullCData(oldp+782,(vlTOPp->top__DOT__oricatmos__DOT__inst_microdisc__DOT__fdc1__DOT__genblk3__DOT__unnamedblk3__DOT__crc2),8);
        tracep->fullIData(oldp+783,(0xbU),32);
    }
}
