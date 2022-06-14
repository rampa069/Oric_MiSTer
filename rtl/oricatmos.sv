//
// A simulation model of ORIC ATMOS hardware
// Copyright (c) SEILEBOST - March 2006
// SystemVerilog conversion Copyright (c) 2022 Frank Bruno
//
// All rights reserved
//
// Redistribution and use in source and synthezised forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// Redistributions in synthesized form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// Neither the name of the author nor the names of other contributors may
// be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// You are responsible for any legal issues arising from your use of this code.
//
// The latest version of this file can be found at: passionoric.free.fr
//
// Email seilebost@free.fr
//
//

module oricatmos
  (
   input wire          CLK_IN,
   input wire          RESET,
   input wire          key_pressed,
   input wire          key_extended,
   input wire [7:0]    key_code,
   input wire          key_strobe,
   input wire          K7_TAPEIN,
   output logic        K7_TAPEOUT,
   output logic        K7_REMOTE,
   output logic        cas_relay,

   output logic [7:0]  PSG_OUT_A,
   output logic [7:0]  PSG_OUT_B,
   output logic [7:0]  PSG_OUT_C,
   output logic [9:0]  PSG_OUT,

   output logic        VIDEO_CLK,
   output logic        VIDEO_R,
   output logic        VIDEO_G,
   output logic        VIDEO_B,
   output logic        VIDEO_HBLANK,
   output logic        VIDEO_VBLANK,
   output logic        VIDEO_HSYNC,
   output logic        VIDEO_VSYNC,
   output logic        VIDEO_SYNC,
   output logic [15:0] ram_ad,
   output logic [7:0]  ram_d,
   input wire [7:0]    ram_q,
   output logic        ram_cs,
   output logic        ram_oe,
   output logic        ram_we,
   output logic        phi2,
   output logic        fd_led,
   input wire          fdd_ready,
   output logic        fdd_busy,
   input wire          fdd_reset,
   input wire          fdd_layout,
   input wire [7:0]    joystick_0,
   input wire [7:0]    joystick_1,
   input wire          pll_locked,
   input wire          disk_enable,
   input wire          rom,
   input wire          img_mounted,
   input wire          img_wp,
   input wire [31:0]   img_size,
   output logic [31:0] sd_lba,
   output logic        sd_rd,
   output logic        sd_wr,
   input wire          sd_ack,
   input wire [8:0]    sd_buff_addr,
   input wire [7:0]    sd_dout,
   output logic [7:0]  sd_din,
   input wire          sd_dout_strobe,
   input wire          sd_din_strobe,

   input wire [15:0]   tape_addr,
   input wire          tape_complete,

   output logic [6:0]  hcnt, // Horizontal counter
   output logic [8:0]  vcnt  // Vertical counter      
   );

  // Gestion des resets
  logic                RESETn;
  logic                reset_dll_h;
  logic [7:0]          delay_count = '0;
  logic [2:0]          clk_cnt = '0;

  // cpu
  logic [23:0]         cpu_ad;
  logic [7:0]          cpu_di;
  logic [7:0]          cpu_do;
  logic                cpu_rw;
  logic                cpu_irq;

  // VIA
  logic [7:0]          via_pa_out_oe;
  logic [7:0]          via_pa_in;
  logic [7:0]          via_pa_out;
  logic [7:0]          via_pa_in_from_psg;
  logic                via_cb1_out;
  logic                via_cb1_oe_l;
  logic                via_cb2_out;
  logic                via_cb2_oe_l;
  logic [7:0]          via_pb_in;
  logic [7:0]          via_pb_out;
  logic [7:0]          via_pb_oe_l;
  logic [7:0]          VIA_DO;
  // Clavier : émulation par port PS2
  logic [7:0]          KEY_ROW;
  logic                KEYB_RESETn;
  logic                KEYB_NMIn;

  // PSG
  logic                psg_bdir;
  logic                psg_bc1;
  logic [7:0]          ym_o_ioa;
  logic                psg_sample_ok;
  // ULA
  logic                ula_phi2;
  logic                ula_CSIOn;
  logic                ula_CSROMn;
  logic                ula_CSRAMn;
  logic [15:0]         ula_AD_SRAM;
  logic                ula_CE_SRAM;
  logic                ula_OE_SRAM;
  logic                ula_WE_SRAM;
  logic                ula_LATCH_SRAM;
  logic                ula_CLK_4;
  logic                ula_CLK_4_en;
  logic                ula_MUX;
  logic                ula_RW_RAM;
  logic                ula_VIDEO_R;
  logic                ula_VIDEO_G;
  logic                ula_VIDEO_B;
  //	 signal lSRAM_D            : std_logic_vector(7 downto 0);
  logic                ENA_1MHZ;
  logic [7:0]          ROM_ATMOS_DO;
  logic [7:0]          ROM_1_DO;
  logic [7:0]          ROM_MD_DO;

  //- Printer port
  logic                PRN_STROBE;
  logic [7:0]          PRN_DATA;
  logic [7:0]          SRAM_DO;

  logic                swnmi;
  logic                swrst;

  // Disk controller
  logic                cont_MAPn = '1;
  logic                cont_ROMDISn = '1;
  logic [7:0]          cont_D_OUT;
  logic                cont_IOCONTROLn = '1;
  logic                cont_ECE;
  logic                cont_RESETn;
  logic                cont_nOE;
  logic                cont_irq;

  // Controller derived clocks
  logic                PH2_1;
  logic                PH2_2;
  logic                PH2_3;
  logic [3:0]          PH2_old;
  logic [4:0]          PH2_cntr;

  assign RESETn = (~RESET & KEYB_RESETn);

  T65 inst_cpu
    (
     .Mode          ('0),
     .Res_n         (cont_RESETn),
     .Enable        (ENA_1MHZ),
     .Clk           (CLK_IN),
     .Rdy           ('1),
     .Abort_n       ('1),
     .IRQ_n         (cpu_irq & cont_irq), // Via and disk controller
     .NMI_n         (KEYB_NMIn),
     .SO_n          ('1),
     .R_W_n         (cpu_rw),
     .A             (cpu_ad),
     .DI            (cpu_di),
     .DO            (cpu_do),

     .tape_addr     (tape_addr),
     .tape_complete (tape_complete)
     );

  assign ram_ad  = ~ula_phi2 ? ula_AD_SRAM : cpu_ad[15:0];
  assign ram_d   = cpu_do;
  assign SRAM_DO = ram_q;
  assign ram_cs  = RESETn & ula_CE_SRAM;
  assign ram_oe  = RESETn & ula_OE_SRAM;
  assign ram_we  = RESETn & ula_WE_SRAM;
  assign phi2    = ula_phi2;

  assign cas_relay = via_cb1_oe_l;

  BASIC11A inst_rom0
    (
     .clk  (CLK_IN),
     .addr (cpu_ad[13:0]),
     .data (ROM_ATMOS_DO)
     );

  BASIC10 inst_rom1 // Oric 1 ROM
    (
     .clk  (CLK_IN),
     .addr (cpu_ad[13:0]),
     .data (ROM_1_DO)
     );

  ORICDOS06 inst_rom2 // Microdisc ROM
    (
     .clk  (CLK_IN),
     .addr (cpu_ad[12:0]),
     .data (ROM_MD_DO)
     );

  ULA inst_ula
    (
     .CLK (CLK_IN),
     .PHI2 (ula_phi2),
     .PHI2_EN (ENA_1MHZ),
     .CLK_4 (ula_CLK_4),
     .CLK_4_EN (ula_CLK_4_en),
     .RW (cpu_rw),
     .RESETn (pll_locked), //RESETn),
     //.RESETn (RESETn),
     .MAPn (cont_MAPn),
     .DB (SRAM_DO),
     .ADDR (cpu_ad[15:0]),
     .SRAM_AD (ula_AD_SRAM),
     .SRAM_OE (ula_OE_SRAM),
     .SRAM_CE (ula_CE_SRAM),
     .SRAM_WE (ula_WE_SRAM),
     .LATCH_SRAM (ula_LATCH_SRAM),
     .CSIOn (ula_CSIOn),
     .CSROMn (ula_CSROMn),
     .CSRAMn (ula_CSRAMn),
     .R (VIDEO_R),
     .G (VIDEO_G),
     .B (VIDEO_B),
     .CLK_PIX (VIDEO_CLK),
     .HBLANK (VIDEO_HBLANK),
     .VBLANK (VIDEO_VBLANK),
     .SYNC (VIDEO_SYNC),
     .HSYNC (VIDEO_HSYNC),
     .VSYNC (VIDEO_VSYNC),
     .hcnt(hcnt),
     .vcnt(v_cnt)
     );


  M6522 inst_via
    (
     .I_RS (cpu_ad[3:0]),
     .I_DATA (cpu_do[7:0]),
     .O_DATA (VIA_DO),
     .I_RW_L (cpu_rw),
     .I_CS1 (cont_IOCONTROLn),
     .I_CS2_L (ula_CSIOn),

     .O_IRQ_L (cpu_irq),

     //PORT A
     .I_CA1 ('1), // PRT_ACK
     .I_CA2 ('1), // psg_bdir
     .O_CA2 (psg_bdir),
     .O_CA2_OE_L (OPEN),

     .I_PA (via_pa_in),
     .O_PA (via_pa_out),
     .O_PA_OE_L (via_pa_out_oe),

     // PORT B
     .I_CB1 (K7_TAPEIN),
     .O_CB1 (via_cb1_out),
     .O_CB1_OE_L (via_cb1_oe_l),

     .I_CB2 ('1),
     .O_CB2 (via_cb2_out),
     .O_CB2_OE_L (via_cb2_oe_l),

     .I_PB (via_pb_in),
     .O_PB (via_pb_out),
     .RESET_L (RESETn),
     .I_P2_H (ula_phi2),
     .ENA_4 (ula_CLK_4_en),
     .CLK (CLK_IN)
     );

  jt49_bus inst_psg
    (
     .clk (CLK_IN),
     .clk_en (ENA_1MHZ),
     .sel ('1),
     .rst_n (RESETn & KEYB_RESETn),
     .bc1 (psg_bdir),
     .bdir (via_cb2_out),
     .din (via_pa_out),
     .dout (via_pa_in_from_psg),
     .sample (psg_sample_ok),
     .sound (PSG_OUT),
     .A (PSG_OUT_A),
     .B (PSG_OUT_B),
     .C (PSG_OUT_C),
     .IOA_in ('0),
     .IOA_out (ym_o_ioa),
     .IOB_in ('0)
     );


  keyboard inst_key
    (
     .clk_sys (CLK_IN),
     .reset (~RESETn), //not RESETn),
     .key_pressed (key_pressed),
     .key_extended (key_extended),
     .key_strobe (key_strobe),
     .key_code (key_code),
     .row (ym_o_ioa),
     .col (via_pb_out[2:0]),
     .ROWbit (KEY_ROW),
     .swnmi (swnmi),
     .swrst (swrst)
     );

  assign KEYB_NMIn = ~swnmi;
  assign KEYB_RESETn = ~swrst;


  Microdisc inst_microdisc
    (
     .CLK_SYS (CLK_IN),
     // Oric Expansion Port Signals
     .DI (cpu_do), // 6502 Data Bus
     .DO (cont_D_OUT), // 6502 Data Bus
     .A (cpu_ad[15:0]), // 6502 Address Bus
     .RnW (cpu_rw), // 6502 Read-/Write
     .nIRQ (cont_irq), // 6502 /IRQ
     .PH2 (ula_phi2), // 6502 PH2
     .nROMDIS (cont_ROMDISn), // Oric ROM Disable
     .nMAP (cont_MAPn), // Oric MAP
     .IO (ula_CSIOn), // Oric I/O
     .IOCTRL (cont_IOCONTROLn), // Oric I/O Control
     .nHOSTRST (cont_RESETn), // Oric RESET
     // Additional MCU Interface Lines
     .nRESET (RESETn & pll_locked), // RESET from MCU
     //DSEL      (cont_DSEL),                           // Drive Select
     //SSEL      (cont_SSEL),                           // Side Select

     // EEPROM Control Lines.
     .nECE (cont_ECE), // Chip Enable

     .ENA (disk_enable),

     .nOE (cont_nOE),

     .img_mounted (img_mounted),
     .img_wp (img_wp),
     .img_size (img_size),
     .sd_lba (sd_lba),
     .sd_rd (sd_rd),
     .sd_wr (sd_wr),
     .sd_ack (sd_ack),
     .sd_buff_addr (sd_buff_addr),
     .sd_dout (sd_dout),
     .sd_din (sd_din),
     .sd_dout_strobe (sd_dout_strobe),
     .sd_din_strobe (sd_din_strobe),
     .fdd_ready (fdd_ready),
     .fdd_busy (fdd_busy),
     .fdd_reset (fdd_reset),
     .fdd_layout (fdd_layout),
     .fd_led (fd_led)
     );


  assign via_pa_in = (via_pa_out & ~via_pa_out_oe) |
                     (via_pa_in_from_psg & via_pa_out_oe);
  assign via_pb_in[2:0] = via_pb_out[2:0];
  assign via_pb_in[3]   = |((KEY_ROW & (ym_o_ioa ^ 8'hFF)));
  assign via_pb_in[4]   = via_pb_out[4];
  assign via_pb_in[5]   = 'z;
  assign via_pb_in[6]   = via_pb_out[6];
  assign via_pb_in[7]   = via_pb_out[7];

  assign K7_TAPEOUT = via_pb_out[7];
  assign K7_REMOTE  = via_pb_out[6];
  assign PRN_STROBE = via_pb_out[4];
  assign PRN_DATA   = via_pa_out;

  always @(posedge CLK_IN) begin
    // expansion port
    if (cpu_rw && ula_phi2 && ~ula_CSIOn && ~cont_IOCONTROLn)
      cpu_di <= cont_D_OUT;
    // VIA
    else if (cpu_rw && ula_phi2 && ~ula_CSIOn && cont_IOCONTROLn)
      cpu_di <= VIA_DO;
    // ROM Atmos
    else if (cpu_rw && ula_phi2 && ula_CSIOn && ~ula_CSROMn && cont_MAPn &&
             cont_ROMDISn && rom)
      cpu_di <= ROM_ATMOS_DO;
    // ROM Oric 1
    else if (cpu_rw && ula_phi2 && ula_CSIOn && ~ula_CSROMn && cont_MAPn &&
             cont_ROMDISn && ~rom)
      cpu_di <= ROM_1_DO;
    //ROM Microdisc
    else if (cpu_rw && ula_phi2 && ~cont_ECE && ~cont_ROMDISn && cont_MAPn)
      cpu_di <= ROM_MD_DO;
    // RAM
    else if (cpu_rw && ula_phi2 && ~ula_CSRAMn && ~ula_LATCH_SRAM)
      cpu_di <= SRAM_DO;
  end // always @ (posedge clk_in)
endmodule // oricatmos
