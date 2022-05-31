//
//  video.vhd
//
//  Manage video attribute
//
//        Copyright (C)2001 - 2005 SEILEBOST
//                   All rights reserved.
//
//  SystemVerilog conversion
//        Copyright (C) 2022 Frank Bruno All rights reserved
// $Id: video.vhd, v0.01 2005/01/01 00:00:00 SEILEBOST $
//
// TODO :
// Remark :

module videov
  (
   input wire          RESETn,
   input wire          CLK_PIXEL,
   input wire          CLK_FLASH,
   // delete 17/11/2009 FLASH_SEL   : in  std_logic;
   input wire          BLANKINGn,
   input wire          RELOAD_SEL,
   input wire [7:0]    DATABUS,
   input wire          ATTRIB_DEC,
   input wire          DATABUS_EN,
   input wire          LDFROMBUS,
   input wire          LD_REG_0,
   input wire          RELD_REG,
   input wire [2:0]    CHROWCNT,
   output logic [2:0]  RGB,
   output logic        FREQ_SEL,
   output logic        TXTHIR_SEL,
   output logic        isAttrib,
   output logic        DBLSTD_SEL,
   output logic [15:0] VAP2
   );

  // locals signals
  logic [7:0]          lDATABUS;
  logic [5:0]          lSHFREG;
  logic [5:0]          lREGHOLD;
  logic [2:0]          lRGB;
  logic [3:0]          lCLK_REG;
  logic [2:0]          lREG_0;
  logic [2:0]          lREG_1;
  logic [2:0]          lREG_2;
  logic [2:0]          lREG_3;
  logic [1:0]          tmp;
  logic [1:0]          lADD;
  logic                lDIN;                    // SET INVERSE LOGIC
  logic                lSHFVIDEO;
  logic                lBGFG_SEL;
  logic                lFLASH_SEL;
  logic                lIsATTRIB;

  // Latch data from Data Bus - This is really bad coding to use a signal as a clock
  always_ff @(posedge DATABUS_EN) begin : u_data_bus
    // Correctif 03/02/09 if (DATABUS_EN = '1') then
    lDATABUS <= DATABUS;
  end

  // Ajout du 04/02/09 / Commentaire le 05/12/09
  //isAttrib <= not lDATABUS(6); // =1 is an attribut, = 0 is not an attribut

  // Decode register
  always_ff @(posedge ATTRIB_DEC) begin : u_attr_dec
    //lCLK_REG <= '0; // Ajout 11/11/09
    if (~|lDATABUS[6:5]) begin
      case (lDATABUS[4:3])
       2'b00:   lCLK_REG <= 4'b0001;
       2'b01:   lCLK_REG <= 4'b0010;
       2'b10:   lCLK_REG <= 4'b0100;
       2'b11:   lCLK_REG <= 4'b1000;
       default: lCLK_REG <= 4'b1111; // 11/11/09 null;
      endcase
    end
  end // block: u_attr_dec

  // ajout le 05/12/09
  always_ff @(posedge ATTRIB_DEC, negedge RESETn) begin : u_isattrib
    if (~RESETn)
      lIsATTRIB <= '0;
    else
      lIsATTRIB <= ~(DATABUS[6] | DATABUS[5]); // =1 is an attribut, = 0 is not an attribut
  end

  // Assignation
  assign isAttrib = lIsATTRIB;

  // get value for register number 0 : INK
  always_ff @(posedge lCLK_REG[0], negedge RESETn, posedge RELOAD_SEL) begin : u_ld_reg0
    // Ajout du 17/11/2009
    if (~RESETn)
      lREG_0 <= '0;
    else if (RELOAD_SEL)
      lREG_0 <= '0;
    // le 17/11/2009 elsif (lCLK_REG(0) = '1') then
    else
      lREG_0 <= lDATABUS[2:0];
  end

  // get value for register number 1 : STYLE : Alt/std, Dbl/std, Flash sel
  always_ff @(posedge lCLK_REG[1], negedge RESETn, posedge RELOAD_SEL) begin : u_ld_reg1
    // Ajout du 17/11/2009
    if (~RESETn)
      lREG_1 <= '0;
    else if (RELOAD_SEL)
      lREG_1 <= '0;
    // le 17/11/2009 elsif (lCLK_REG(1) = '1') then
    else
      lREG_1 <= lDATABUS[2:0];
  end

  // get value for register number 2 : PAPER
  always_ff @(posedge lCLK_REG[2], negedge RESETn, posedge RELOAD_SEL) begin : u_ld_reg2
    // Ajout du 17/11/2009
    if (~RESETn)
      lREG_2 <= '1;
    else if (RELOAD_SEL)
      lREG_2 <= '1;
    // le 17/11/2009 elsif (lCLK_REG(2) = '1') then
    else
      lREG_2 <= lDATABUS[2:0];
  end

  // get value for register number 3 : Mode
  always_ff @(posedge lCLK_REG[3], negedge RESETn) begin : u_ld_reg3
    if (~RESETn)
      lREG_3 <= '0;
    // modif 04/02/09 elsif (lCLK_REG(3) = '1') then
    else
      lREG_3 <= lDATABUS[2:0];
  end

  // hold data value
  always_ff @(posedge LDFROMBUS, posedge LD_REG_0) begin : u_hold_reg
    // Chargement si attribut
    if (LD_REG_0)
      lREGHOLD <= '0;
    else begin
      lREGHOLD <= lDATABUS[5:0];
      lDIN <= lDATABUS[7]; // Ajout du 15/12/2009
    end
  end
  //-mise en commentaire 15/12/2009 lDIN <= lDATABUS(7);

  // shift data for video
  always_ff @(posedge CLK_PIXEL, posedge RELD_REG) begin : u_shf_reg
    // Chargement du shifter avant le front montant de PHI2
    if (RELD_REG)
      lSHFREG <= lREGHOLD;
    // 6 bits à envoyer
    else begin
      lSHFVIDEO <= lSHFREG[5];
      lSHFREG   <= {lSHFREG[4:0], 1'b0};
    end
  end

  assign lFLASH_SEL = lREG_1[2];
  assign lBGFG_SEL  = (CLK_FLASH & lFLASH_SEL) ? ~lSHFVIDEO : lSHFVIDEO;
  // le 17/11/2009 : lBGFG_SEL  <= NOT(lSHFVIDEO) when ( (CLK_FLASH = '1') AND (FLASH_SEL = '1') ) else lSHFVIDEO;
  // lBGFG_SEL  <= lSHFVIDEO and not ( CLK_FLASH AND FLASH_SEL );

  // local assign for R(ed)G(reen)B(lue) signal
  assign lRGB = ~lBGFG_SEL ? lREG_0 : lREG_2;

  // Assign out signal
  always_comb begin
    case ({lDIN, BLANKINGn})
      2'b01:   RGB = lRGB;
      2'b11:   RGB = ~lRGB;
      default: RGB = '0;
    endcase // case ({lDIN, BLANKINGn})
  end

  assign DBLSTD_SEL = lREG_1[1]; // Double/Standard height character select
  assign FREQ_SEL   = lREG_3[1]; // Frenquecy video (50/60Hz) select
  assign TXTHIR_SEL = lREG_3[2]; // Texte/Hires mode select

  // Compute offset
  assign tmp = {lREG_3[2], lREG_1[0]};
  always_comb begin
    case (tmp)
      2'b00: lADD = 2'b01;// TXT & STD
      2'b01: lADD = 2'b10;// TXT & ALT
      2'b10: lADD = 2'b10;// HIRES & STD
      2'b11: lADD = 2'b11;// HIRES & ALT
      default: lADD = 2'b01;// Du fait que le design original de l'ULA
      // n'a pas de reset, nous supposerons que
      // l'ULA est en mode text et standard
    endcase // case (tmp)
  end // always_comb

  // Generate Address Phase 2
  assign VAP2 = {2'b10, ~lREG_3[2], 1'b1, lADD, lDATABUS[6:0], CHROWCNT};
endmodule // video
