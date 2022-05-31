// Cumulus CPLD Core
// Top Level Entity
// Copyright 2010 Retromaster
// SystemVerilog Copyright 2022 Frank Bruno
//
// This file is part of Cumulus CPLD Core.
//
// Cumulus CPLD Core is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License,
// or any later version.
//
// Cumulus CPLD Core is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Cumulus CPLD Core. If not, see .
//

module Microdiscv
  (
   input wire          CLK_SYS, // 24 Mhz input clock

   // Oric Expansion Port Signals
   input wire [7:0]    DI, // 6502 Data Bus
   output logic [7:0]  DO, // 6502 Data Bus

   input wire [15:0]   A, // 6502 Address Bus
   input wire          RnW, // 6502 Read-/Write
   output wire         nIRQ, // 6502 /IRQ
   input wire          PH2, // 6502 PH2
   output logic        nROMDIS, // Oric ROM Disable
   output logic        nMAP, // Oric MAP
   input wire          IO, // Oric I/O
   output logic        IOCTRL, // Oric I/O Control
   output logic        nHOSTRST, // Oric RESET

   // Data Bus Buffer Control Signals
   output logic        nOE, // Output Enable
   output logic        DIR, // Direction
   // Additional MCU Interface Lines
   input wire          nRESET, // RESET from MCU
   // output logic [1:0] DSEL, // Drive Select
   // output logic       SSEL, // Side Select

   // EEPROM Control Lines.
   output logic        nECE, // Chip Enable
   output logic        nEOE, // Output Enable
   input wire          ENA,

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

   input wire          fdd_ready,
   output logic        fdd_busy,
   input wire          fdd_reset,
   input wire          fdd_layout,
   output logic        fd_led
   );

  // Status
  logic                fdc_nCS;
  logic                nCS;
  logic                fdc_nRE;
  logic                fdc_nWE;
  logic                fdc_CLK_en;
  logic [1:0]          fdc_A;
  logic [7:0]          fdc_DALin;
  logic [7:0]          fdc_DALout;
  logic                fdc_DRQ;
  logic                fdc_IRQ;

  logic                sel;
  logic                u16k;
  logic                inECE;
  logic                inROMDIS;
  logic                iDIR;

  logic [1:0]          DSEL; // Drive Select
  logic                SSEL; // Side Select

  // Control Register
  logic                nROMEN; // ROM Enable
  logic                IRQEN; // IRQ Enable

  logic                inMCRQ;

  wd1793
    #
    (
     .EDSK         (1),
     .RWMODE       (1)
     )
  fdc1
    (
     .clk_sys      (CLK_SYS),
     .ce           (fdc_CLK_en),

     .reset        (~nRESET),
     .io_en        (~fdc_nCS),
     .rd           (~fdc_nRE),
     .wr           (~fdc_nWE),
     .addr         (fdc_A),
     .din          (fdc_DALin),
     .dout         (fdc_DALout),

     .intrq        (fdc_IRQ),
     .drq          (fdc_DRQ),

     .ready        (fdd_ready),
     //.busy       (fdd_busy),

     .layout       (fdd_layout), //fdd_layout),
     .size_code    (3'b001),
     .side         (SSEL),
     .prepare      (fdd_busy),
     .img_mounted  (img_mounted),
     .wp           (img_wp),
     .img_size     (img_size[19:0]),
     .sd_lba       (sd_lba),
     .sd_rd        (sd_rd),
     .sd_wr        (sd_wr),
     .sd_ack       (sd_ack),
     .sd_buff_addr (sd_buff_addr),
     .sd_buff_dout (sd_dout),
     .sd_buff_din  (sd_din),
     .sd_buff_wr   (sd_dout_strobe),

     .input_active ('0),
     .input_addr   ('0),
     .input_data   ('0),
     .input_wr     ('0),
     .buff_din     ('0)
     );

  // Reset
  assign nHOSTRST  = nRESET;

  // Select signal (Address Range 031-)
  assign sel       = (A[7:4] == 4'b0001) & ~IO & ~&A[3:2];

  // WD1793 Signals
  assign fdc_A     = A[1:0];
  assign fdc_nCS   = ~(sel & ~|A[3:2]);


  assign fdc_nRE   = IO | ~RnW;
  assign fdc_nWE   = IO |  RnW;
  assign fdc_DALin = DI;

  // DEBUG led
  assign fd_led    = fdd_busy;

  // ORIC Expansion Port Signals
  assign IOCTRL    = ~sel;
  assign nROMDIS   = inROMDIS;
  assign nIRQ      = ~(fdc_IRQ & IRQEN);

  // EEPROM Control Signals
  assign nEOE      = PH2 | ~RnW;
  assign u16k      = ~inROMDIS & A[14] & A[15];
  assign inECE     = ~(A[13] & u16k & ~nROMEN);
  assign nECE      = inECE;
  assign nMAP      = ~(PH2 & inECE & u16k);

  // assign nMCRQ  = inMCRQ;

  assign DIR       = iDIR;
  assign iDIR      = RnW;

  // Data Bus Control.
  always_comb begin
    if (iDIR) begin
      if (A[3:2] == 2'b10) begin
        DO = {~fdc_DRQ, 7'bxxxxxxx};
      end else if (A[3:2] == 2'b01) begin
        DO = {~fdc_IRQ, 7'bxxxxxxx};
      end else if (~fdc_nRE && ~fdc_nCS) begin
        DO = fdc_DALout;
      end else begin
        DO = 'x;
      end
    end else begin
      DO = 'z;
    end // else: !if(iDIR)
  end // always_comb

  assign nOE = ~(sel & PH2);

  // Control Register.
  always_ff @(posedge CLK_SYS) begin
    if (~nRESET) begin
      nROMEN   <= '0;
      DSEL     <= '0;
      SSEL     <= '0;
      inROMDIS <= ENA;
      IRQEN    <= '0;
    end else if (sel && (A[3:2] == 2'b01) && ~RnW) begin
      nROMEN   <= DI[7];
      DSEL     <= DI[6:5];
      SSEL     <= DI[4];
      inROMDIS <= DI[1];
      IRQEN    <= DI[0];
    end
  end // always_ff @ (posedge CLK_SYS)

  // FDC clock enable: 24/6 = 4MHz
  logic [2:0] count;
  always_ff @(posedge CLK_SYS, negedge nRESET) begin
    if (~nRESET) begin
      count      <= '0;
      fdc_CLK_en <= '0;
    end else begin
      fdc_CLK_en <= '0;
      if (count == 0) begin
        fdc_CLK_en       <= '1;
      end
      if (count == 5) count <= '0;
      else            count <= count + 1'b1;
    end // else: !if(~nRESET)
  end // always_ff @ (posedge CLK_SYS, negedge nRESET)
endmodule // Microdisc
