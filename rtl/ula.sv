`default_nettype none
//
// A simulation model of ULA
// Copyright (c) seilebost - 2001 - 2009
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
// The latest version of this file can be found at: www.fpgaarcade.com
//
// Email seilebost@free.fr
//
//
//
//
// 2013 Significant rewrite by d18c7db(a)hotmail
//
//   Combined all ULA submodules into one file
//   Elliminated gated clocks
//   Overall simplified and streamlined RTL
//   Reduced number of synthesis warnings
//   Fixed attribute decoding
//   Fixed phase1/phase2 address generation
//   Changes in timing signal generation
//   Fixed attributes not alligned to characters on screen
//   Implemented 50/60Hz attribute
//
// SystemVerilog conversion (c) 2022 Frank Bruno
//      ULA pinout
//  1 MUX    U RAM_D1 40
//  2 RAM_D2   RAM_D0 39
//  3 RAM_D3   RAM_D7 38
//  4 RAM_D4   RAM_D5 37
//  5 D5       RAM_D6 36
//  6 GND         A12 35
//  7 CLK          D6 34
//  8 D0          A09 33
//  9 CAS         A08 32
// 10 RAS         A10 31
// 11 D2          A15 30
// 12 D3          A14 29
// 13 D4      RAM_R/W 28
// 14 PHI         R/W 27
// 15 A11         MAP 26
// 16 SYNC        I/O 25
// 17 D1          Vcc 24
// 18 D7       ROM_CS 23
// 19 BLU         A13 22
// 20 GRN         RED 21

module ULA
  (
   input wire          RESETn, // RESET master
   output logic        CLK_4, // 4 MHz internal
   output logic        CLK_4_EN, // 4 MHz internal clock enable pulse

   input wire          CLK, // 24 MHz                       // pin 07
   output logic        PHI2, // 1 MHz CPU & system           // pin 14
   output logic        PHI2_EN, // 1 MHz clock enable pulse
   input wire          RW, // R/W from CPU                 // pin 27
   input wire          MAPn, // MAP                          // pin 26
   input wire [7:0]    DB, // DATA BUS                     // pin 18,34,5,13,12,11,17,8
   input wire [15:0]   ADDR, // ADDRESS BUS                  // pin 30,29,22,35,15,31,33,32, A7,A6,A5,A4,A3,A2,A1,A0

   // SRAM
   output logic        CSRAMn,
   output logic [15:0] SRAM_AD,
   output logic        SRAM_OE,
   output logic        SRAM_CE,
   output logic        SRAM_WE,
   output logic        LATCH_SRAM,

   // DRAM
   //	AD_RAM     :   out std_logic_vector( 7 downto 0); // ADDRESS BUS for dynamic ram  // pin 38,36,37,4,3,2,40,39
   //	RASn       :   out std_logic;                     // RAS for dynamic ram          // pin 10
   //	CASn       :   out std_logic;                     // CAS for dynamic ram          // pin 09
   //	MUX        :   out std_logic;                     // MUX selector                 // pin 01
   //	RW_RAM     :   out std_logic;                     // Read/Write for dynamic ram   // pin 28

   output logic        CSIOn,
   output logic        CSROMn,
   output logic        R, // Red                          // pin 21
   output logic        G, // Green                        // pin 20
   output logic        B, // Blue                         // pin 19
   output logic        SYNC, // Synchronisation              // pin 16
   // VCC                          // pin 24
   // GND                          // pin 06

   output logic        CLK_PIX,
   output logic        HBLANK,
   output logic        VBLANK,
   output logic        HSYNC,
   output logic        VSYNC,

   output logic [6:0]  hcnt, // Horizontal counter
   output logic [8:0]  vcnt  // Vertical counter   
   );

  // Signal CLOCK
  logic                CLK_24;        // CLOCK 24 MHz internal
  logic                CLK_4_INT;     // CLOCK  4 MHz internal
  logic                CLK_1_INT;     // CLOCK  1 MHz internal
  logic                CLK_1_EN;      // CLOCK  1 MHz enable pulse
  logic                CLK_PIXEL_INT; // CLOCK PIXEL  internal
  logic                CLK_FLASH;     // CLOCK FLASH  external

  // Data Bus Internal
  logic [7:0]          DB_INT;

  // Manage memory access
  logic [15:0]         VAP1;          // VIDEO ADDRESS PHASE 1
  logic [15:0]         VAP2;          // VIDEO ADDRESS PHASE 2
  logic [15:0]         lADDR;         // BUS ADDRESS PROCESSOR
  logic                RW_INT;        // Read/Write INTERNAL FROM CPU

  // local signal
  logic                lHIRES_SEL;                     // TXT/HIRES SELECT
  logic                HIRES_DEC;                     // TXT/HIRES DECODE
  logic                lDBLHGT_SEL;                     // Double Height SELECT
  logic                lALT_SEL;                     // Character set select
  logic                lFORCETXT;                     // Force text mode
  logic                isAttrib;                     // Attrib
  logic                ATTRIB_DEC;                     // Attrib decode
  //	logic LD_REG_0;                     // Load zero into video register
  logic                RELD_REG;                     // Reload from register to shift
  logic                DATABUS_EN;                     // Data bus enable
  logic                lCOMPSYNC;                     // Composite Synchronization for video
  logic                lHSYNCn;                     // Horizontal Synchronization for video
  logic                lVSYNC50n;                     // Vertical Synchronization for 50Hz video
  logic                lVSYNC60n;                     // Vertical Synchronization for 60Hz video
  logic                lVSYNCn;                     // Vertical Synchronization for video
  logic                BLANKINGn;                     // Blanking signal
  logic                lRELOAD_SEL;                     // reload register SELECT
  logic                lFREQ_SEL;                     // Frequency video SELECT (50 or 60 Hz)
  logic                LDFROMBUS;                     // Load from Bus Data
  logic [2:0]          CHROWCNT; // ch?? row count
  logic [6:0]          lCTR_H; // Horizontal counter
  logic [8:0]          lCTR_V; // Vertical counter
  logic [2:0]          RGB_INT; // Red Green Blue video signal

  // local select RAM, IO & ROM
  logic                CSRAMn_INT;                     // RAM Chip Select
  logic                CSIOn_INT;                     // Input/Output Chip Select
  logic                CSROMn_INT;                     // ROM Chip select

  // Bus Address internal
  logic [15:0]         AD_RAM_INT; // RAM ADDRESS BUS

  // RESET internal
  logic                RESET_INT;

  // MAP internal
  logic                lMAPn;

  logic                DBLHGT_EN;                     // ENABLE DOUBLE HEIGHT
  logic [8:0]          CTR_V_DIV8; // VERTICAL COUNTER DIVIDE OR NOT BY 8
  logic [15:0]         voffset; // OFFSET SCREEN
  logic [14:0]         mulBy40; // Used to mult by 40

  logic [23:0]         c; // states
  logic [2:0]          ph; // phases

  logic [4:0]          lCTR_FLASH;
  logic                lVBLANKn;
  logic                lHBLANKn;

  logic [7:0]          lDATABUS;
  logic [5:0]          lSHFREG;
  logic [6:0]          lREGHOLD;
  logic [2:0]          lRGB;
  logic [2:0]          lREG_INK;
  logic [2:0]          lREG_STYLE;
  logic [2:0]          lREG_PAPER;
  logic [2:0]          lREG_MODE;
  logic [1:0]          ModeStyle;
  logic [5:0]          lADD;
  logic                lInv;                    // inverse signal
  logic                lInv_hold;                    // inverse signal hold
  logic                lBGFG_SEL;
  logic                lFLASH_SEL;

  // input assignments
  assign lADDR        = ADDR;
  assign DB_INT       = DB;
  assign CLK_24       = CLK;
  assign RESET_INT    = ~RESETn;
  assign lMAPn        = MAPn;
  assign RW_INT       = RW;

  // output assignments
  assign PHI2         = CLK_1_INT;
  assign PHI2_EN      = CLK_1_EN;
  //	assign AD_RAM       = AD_RAM_INT[15:8];
  assign CSIOn        = CSIOn_INT;
  assign CSROMn       = CSROMn_INT;
  assign CSRAMn       = CSRAMn_INT;
  assign CLK_4        = CLK_4_INT;

  //////////////////
  // SRAM signals //
  //////////////////
  assign SRAM_AD    = AD_RAM_INT;
  assign LATCH_SRAM = ~c[4] & ~c[12] & ~c[20];

  //                phase 1  phase 2  phase 3
  assign SRAM_OE    = ph[0] | ph[1] |        RW_INT;
  assign SRAM_CE    = ph[0] | ph[1] | (ph[2] & ~CSRAMn_INT);

  assign SRAM_WE    = (~CSRAMn_INT) & (~RW_INT)  & c[17] ;

  // VIDEO OUT
  assign R       = RGB_INT[0];
  assign G       = RGB_INT[1];
  assign B       = RGB_INT[2];
  assign SYNC    = lCOMPSYNC;
  assign HSYNC   = lHSYNCn;
  assign VSYNC   = lVSYNCn;

  //////////////////////
  //////////////////////
  // Address Decoding //
  //////////////////////
  //////////////////////

  // PAGE 3 I/O decoder : 0x300-0x3FF
  assign CSIOn_INT = ~((lADDR[15:8] == 8'h03) & CLK_1_INT);

  // PAGE ROM : 0xC000-0xFFFF
  assign CSROMn_INT = ~(&lADDR[15:14] & lMAPn & CLK_1_INT);

  assign CSRAMn_INT = ~((&lADDR[15:14] & ~lMAPn & CLK_1_INT) | // shadow RAM section
                        // normal RAM section
                        ((lADDR[15:8] != 8'h03) & ~&lADDR[15:14] & lMAPn &
                         CLK_1_INT));

  ///////////////////////////////////////////////
  //////////////////////////////////////////////
  // Control signal generation and sequencing //
  //////////////////////////////////////////////
  //////////////////////////////////////////////

  // state and phase shifter
  always_ff @(posedge CLK_24, posedge RESET_INT) begin : U_TB_CPT
    if (RESET_INT)  begin
      c  <= 24'h1;
      ph <= 3'b1;
    end else begin
      // advance states
      c <= {c[22:0], c[23]};
      if (c[7] || c[15] || c[23]) begin
        // advance phases
        ph <= {ph[1:0], ph[2]};
      end
    end // else: !if(RESET_INT)
  end // always_ff @ (posedge clk_24, posedge RESET_INT)

  //////////////////////
  // Clock generation //
  //////////////////////

  // CPU clock //
  assign CLK_1_INT = ph[2];
  assign CLK_1_EN  = c[15];

  // VIA 6522 clock
  assign CLK_4_INT     = |c[2:0] | (|c[8:6]) | (|c[14:12]) | (|c[20:18]);
  assign CLK_4_EN      = c[23] | c[5] | c[11] | c[16];

  // assign LD_REG_0      = isAttrib & c[5];

  assign CLK_PIXEL_INT = c[1] | c[5] | c[9] | c[13] | c[17] | c[21];
  assign ATTRIB_DEC    = c[3];
  assign RELD_REG      = c[17];
  assign DATABUS_EN    = c[2] | c[10];
  assign LDFROMBUS     = ((~isAttrib) & c[12] & (~HIRES_DEC)) |
                         ((~isAttrib) & c[5]  &   HIRES_DEC) |
                         (isAttrib & c[9]);

  ////////////////////////////////////-
  ////////////////////////////////////-
  // Video timing signals generation //
  ////////////////////////////////////-
  ////////////////////////////////////-

assign hcnt = lCTR_H;
assign vcnt = lCTR_V;

  // Horizontal Counter
  always_ff @(posedge CLK_24, posedge RESET_INT) begin : u_CPT_H
    if (RESET_INT) begin
      lCTR_H  <= '0;
    end else if (CLK_1_EN) begin
      if (lCTR_H < 63)
        lCTR_H <= lCTR_H + 1'b1;
      else
        lCTR_H <= '0;
    end
  end

  // Vertical Counter
  always_ff @(posedge CLK_24, posedge RESET_INT) begin : u_CPT_V
    if (RESET_INT) begin
      lCTR_V <= '0;
      lCTR_FLASH <= '0;
    end else if (CLK_1_EN) begin
      if (lCTR_H == 63) begin
        // 50Hz = 312 lines, 60Hz = 260 lines
        if (((lCTR_V < 312) &&  lFREQ_SEL) ||
            ((lCTR_V < 260) && ~lFREQ_SEL)) begin
          lCTR_V <= lCTR_V + 1'b1;
        end else begin
          lCTR_V <= '0;
          // increment flash counter every frame
          lCTR_FLASH <= lCTR_FLASH + 1'b1;
        end
      end // if (lCTR_H == 63)
    end // if (CLK_1_EN)
  end // block: u_CPT_V

  // Horizontal Synchronisation
  assign lHSYNCn     = ~((lCTR_H >= 49) & (lCTR_H <= 53));

  // Horizontal Blank
  assign lHBLANKn    = (lCTR_H >=   1) & (lCTR_H <=  40);

  // Signal to Reload Register to reset attributes
  assign lRELOAD_SEL = (lCTR_H >=  49);

  // Vertical Synchronisation
  assign lVSYNC50n   = ~((lCTR_V >= 258) & (lCTR_V <= 259)); // 50Hz
  assign lVSYNC60n   = ~((lCTR_V >= 241) & (lCTR_V <= 242)); // 60Hz
  assign lVSYNCn     = lFREQ_SEL ? lVSYNC50n : lVSYNC60n;

  // Vertical Blank
  assign lVBLANKn    = ~(lCTR_V >= 224);

  // Signal To Force TEXT MODE
  assign lFORCETXT   = (lCTR_V >  199);

  // Assign output signals
  assign CLK_FLASH   = lCTR_FLASH[4];  // Flash clock toggles every 16 video frames
  assign lCOMPSYNC   = ~(lHSYNCn ^ lVSYNCn);
  assign BLANKINGn   = lVBLANKn & lHBLANKn;
  assign CLK_PIX     = CLK_PIXEL_INT;

/*
always @(posedge CLK_24)
$display("RESET_INT %x  RESETn %x  lHSYNCn %x VBLANKn %x",RESET_INT,RESETn,lHSYNCn,lVBLANKn);
*/

  always_ff @(posedge CLK_24)
    if (CLK_PIXEL_INT) begin
      HBLANK <= ~lHBLANKn;
      VBLANK <= ~lVBLANKn;
    end

  ////////////////////////////-
  ////////////////////////////-
  // Video attribute decoder //
  ////////////////////////////-
  ////////////////////////////-

  // Latch data from Data Bus
  always_ff @(posedge CLK_24) begin : u_data_bus
    if (DATABUS_EN) lDATABUS <= DB_INT;
  end

  always_ff @(posedge CLK_24, posedge RESET_INT) begin : u_isattrib
    if (RESET_INT) begin
      isAttrib  <= '0;
      lInv_hold <= '0;
    end else if (ATTRIB_DEC) begin
      isAttrib  <= ~(|DB_INT[6:5]); // 1 = attribute, 0 = not an attribute
      lInv_hold <= DB_INT[7];
    end
  end

  always_ff @(posedge CLK_24) begin : u_lInv_hold
    if (CLK_PIXEL_INT && RELD_REG) lInv <= lInv_hold;
  end

  // hold data bus value
  always_ff @(posedge CLK_24, posedge RESET_INT) begin : u_hold_reg
    if (RESET_INT) begin
      lREGHOLD <= '0;
    end else if (LDFROMBUS) begin
      lREGHOLD <= lDATABUS[6:0];
    end
  end

  always_ff @(posedge CLK_24, posedge RESET_INT, posedge lRELOAD_SEL) begin : u_ld_reg
    if (RESET_INT) begin
      lREG_INK   <= '1;
      lREG_STYLE <= '0;
      lREG_PAPER <= '0;
      lREG_MODE  <= '0;
    end else if (lRELOAD_SEL) begin
      lREG_INK   <= '1;
      lREG_STYLE <= '0;
      lREG_PAPER <= '0;
      // mode is missing, bad coding style
    end else if (RELD_REG && isAttrib && BLANKINGn) begin
      case (lREGHOLD[6:3])
        4'b0000: lREG_INK   <= lREGHOLD[2:0];
        4'b0001: lREG_STYLE <= lREGHOLD[2:0];
        4'b0010: lREG_PAPER <= lREGHOLD[2:0];
        4'b0011: lREG_MODE  <= lREGHOLD[2:0];
      endcase
    end
  end // block: u_ld_reg

  // selector bits in mode/style registers
  assign lALT_SEL    = lREG_STYLE[0]; // Character set select : 0=Standard  1=Alternate
  assign lDBLHGT_SEL = lREG_STYLE[1]; // Character type select: 0=Standard  1=Double
  assign lFLASH_SEL  = lREG_STYLE[2]; // Flash select         : 0=Steady    1=Flashing
  assign lFREQ_SEL   = lREG_MODE[1];  // Frequency select     : 0=60Hz      1=50Hz
  assign lHIRES_SEL  = lREG_MODE[2];  // Mode Select          : 0=Text      1=Hires

  // Output signal for text/hires mode decode
  assign HIRES_DEC   = (lHIRES_SEL  & (~lFORCETXT));
  assign DBLHGT_EN   = (lDBLHGT_SEL & (~HIRES_DEC));

  // shift video data
  always_ff @(posedge CLK_24) begin : u_shf_reg
    if (CLK_PIXEL_INT) begin
      // Load shifter before the rising edge of PHI2
      if (RELD_REG && ~isAttrib)
        lSHFREG <= lREGHOLD[5:0];
      else
        // send 6 bits
        lSHFREG <= {lSHFREG[4:0], 1'b0};
    end
  end

  assign lBGFG_SEL  = (CLK_FLASH & lFLASH_SEL) ? '0 : lSHFREG[5];

  // local assign for R(ed)G(reen)B(lue) signal
  assign lRGB = lBGFG_SEL? lREG_INK : lREG_PAPER;

  // Assign out signal
  assign RGB_INT = ~lInv ? lRGB : ~lRGB;

  // Compute offset
  assign ModeStyle = {lHIRES_SEL, lALT_SEL};

  always_comb begin
    case (ModeStyle)
      2'b11:   lADD <= 6'b100111;   // HIRES & ALT  x9Cxx
      2'b10:   lADD <= 6'b100110;   // HIRES & STD  x98xx
      2'b01:   lADD <= 6'b101110;   // TEXT  & ALT  xB8xx
      default: lADD <= 6'b101101;   // TEXT  & STD  xB4xx
    endcase // case (ModeStyle)
  end

  ////////////////////////////-
  ////////////////////////////-
  // Video address generator //
  ////////////////////////////-
  ////////////////////////////-

  // divide by 8 in LORES
  assign CTR_V_DIV8 = HIRES_DEC ? lCTR_V : {3'b000, lCTR_V[8:3]};

  // to multiply by 40 without using a multiplier we just sum the results of the operations of
  // multiply by 32 by shifting 5 bits and multiply by 8 by shifting 3 bits
  assign mulBy40     = {3'b0, CTR_V_DIV8, 5'b0} + {3'b0, CTR_V_DIV8, 3'b0};
  assign voffset     = HIRES_DEC ? 16'hA000 : 16'hBB80;

  // Generate Address Phase 1
  assign VAP1        = (voffset + mulBy40) + lCTR_H;

  // Compute character row counter
  assign CHROWCNT    = DBLHGT_EN ? lCTR_V[3:1] : lCTR_V[2:0];

  // Generate Address Phase 2
  assign VAP2 = {lADD, lDATABUS[6:0], CHROWCNT};

  // multiplex addresses at rising edge of each phase
  always_ff @(posedge CLK_24) begin : addr_latch
    if (c[23]) begin
      // Generate video phase 1 address
      AD_RAM_INT <= VAP1;
    end else if (c[7]) begin
      // Generate video phase 2 address
      AD_RAM_INT <= VAP2;
    end else if (c[15]) begin
      // Generate CPU phase 3 address
      AD_RAM_INT <= lADDR;
    end
  end // block: addr_latch

endmodule // ula
`default_nettype wire
