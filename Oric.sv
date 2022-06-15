//============================================================================
//  Oric-1 and Oric Atmos
//  Copyright (C) rampa
//
//  Port to MiSTer by Sorgelig
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//============================================================================

module emu
(
	//Master input clock
	input         CLK_50M,

	//Async reset from top-level module.
	//Can be used as initial reset.
	input         RESET,

	//Must be passed to hps_io module
	inout  [48:0] HPS_BUS,

	//Base video clock. Usually equals to CLK_SYS.
	output        CLK_VIDEO,

	//Multiple resolutions are supported using different CE_PIXEL rates.
	//Must be based on CLK_VIDEO
	output        CE_PIXEL,

	//Video aspect ratio for HDMI. Most retro systems have ratio 4:3.
	//if VIDEO_ARX[12] or VIDEO_ARY[12] is set then [11:0] contains scaled size instead of aspect ratio.
	output [12:0] VIDEO_ARX,
	output [12:0] VIDEO_ARY,

	output  [7:0] VGA_R,
	output  [7:0] VGA_G,
	output  [7:0] VGA_B,
	output        VGA_HS,
	output        VGA_VS,
	output        VGA_DE,    // = ~(VBlank | HBlank)
	output        VGA_F1,
	output [1:0]  VGA_SL,
	output        VGA_SCALER, // Force VGA scaler

	input  [11:0] HDMI_WIDTH,
	input  [11:0] HDMI_HEIGHT,
	output        HDMI_FREEZE,

`ifdef MISTER_FB
	// Use framebuffer in DDRAM (USE_FB=1 in qsf)
	// FB_FORMAT:
	//    [2:0] : 011=8bpp(palette) 100=16bpp 101=24bpp 110=32bpp
	//    [3]   : 0=16bits 565 1=16bits 1555
	//    [4]   : 0=RGB  1=BGR (for 16/24/32 modes)
	//
	// FB_STRIDE either 0 (rounded to 256 bytes) or multiple of pixel size (in bytes)
	output        FB_EN,
	output  [4:0] FB_FORMAT,
	output [11:0] FB_WIDTH,
	output [11:0] FB_HEIGHT,
	output [31:0] FB_BASE,
	output [13:0] FB_STRIDE,
	input         FB_VBL,
	input         FB_LL,
	output        FB_FORCE_BLANK,

`ifdef MISTER_FB_PALETTE
	// Palette control for 8bit modes.
	// Ignored for other video modes.
	output        FB_PAL_CLK,
	output  [7:0] FB_PAL_ADDR,
	output [23:0] FB_PAL_DOUT,
	input  [23:0] FB_PAL_DIN,
	output        FB_PAL_WR,
`endif
`endif

	output        LED_USER,  // 1 - ON, 0 - OFF.

	// b[1]: 0 - LED status is system status OR'd with b[0]
	//       1 - LED status is controled solely by b[0]
	// hint: supply 2'b00 to let the system control the LED.
	output  [1:0] LED_POWER,
	output  [1:0] LED_DISK,

	// I/O board button press simulation (active high)
	// b[1]: user button
	// b[0]: osd button
	output  [1:0] BUTTONS,

	input         CLK_AUDIO, // 24.576 MHz
	output [15:0] AUDIO_L,
	output [15:0] AUDIO_R,
	output        AUDIO_S,   // 1 - signed audio samples, 0 - unsigned
	output  [1:0] AUDIO_MIX, // 0 - no mix, 1 - 25%, 2 - 50%, 3 - 100% (mono)

	//ADC
	inout   [3:0] ADC_BUS,

	//SD-SPI
	output        SD_SCK,
	output        SD_MOSI,
	input         SD_MISO,
	output        SD_CS,
	input         SD_CD,

	//High latency DDR3 RAM interface
	//Use for non-critical time purposes
	output        DDRAM_CLK,
	input         DDRAM_BUSY,
	output  [7:0] DDRAM_BURSTCNT,
	output [28:0] DDRAM_ADDR,
	input  [63:0] DDRAM_DOUT,
	input         DDRAM_DOUT_READY,
	output        DDRAM_RD,
	output [63:0] DDRAM_DIN,
	output  [7:0] DDRAM_BE,
	output        DDRAM_WE,

	//SDRAM interface with lower latency
	output        SDRAM_CLK,
	output        SDRAM_CKE,
	output [12:0] SDRAM_A,
	output  [1:0] SDRAM_BA,
	inout  [15:0] SDRAM_DQ,
	output        SDRAM_DQML,
	output        SDRAM_DQMH,
	output        SDRAM_nCS,
	output        SDRAM_nCAS,
	output        SDRAM_nRAS,
	output        SDRAM_nWE,

`ifdef MISTER_DUAL_SDRAM
	//Secondary SDRAM
	//Set all output SDRAM_* signals to Z ASAP if SDRAM2_EN is 0
	input         SDRAM2_EN,
	output        SDRAM2_CLK,
	output [12:0] SDRAM2_A,
	output  [1:0] SDRAM2_BA,
	inout  [15:0] SDRAM2_DQ,
	output        SDRAM2_nCS,
	output        SDRAM2_nCAS,
	output        SDRAM2_nRAS,
	output        SDRAM2_nWE,
`endif

	input         UART_CTS,
	output        UART_RTS,
	input         UART_RXD,
	output        UART_TXD,
	output        UART_DTR,
	input         UART_DSR,

	// Open-drain User port.
	// 0 - D+/RX
	// 1 - D-/TX
	// 2..6 - USR2..USR6
	// Set USER_OUT to 1 to read from USER_IN.
	input   [6:0] USER_IN,
	output  [6:0] USER_OUT,

	input         OSD_STATUS
);


assign USER_OUT = '1;
assign {UART_RTS, UART_TXD, UART_DTR} = 0;
assign {SD_SCK, SD_MOSI, SD_CS} = 'Z;
assign {SDRAM_DQ, SDRAM_A, SDRAM_BA, SDRAM_CLK, SDRAM_CKE, SDRAM_DQML, SDRAM_DQMH, SDRAM_nWE, SDRAM_nCAS, SDRAM_nRAS, SDRAM_nCS} = 'Z;
assign {DDRAM_CLK, DDRAM_BURSTCNT, DDRAM_ADDR, DDRAM_DIN, DDRAM_BE, DDRAM_RD, DDRAM_WE} = '0; 
 
assign LED_USER  = ioctl_download | led_disk; // | tape_adc_act;
assign LED_DISK  = 0;
assign LED_POWER = 0;
assign BUTTONS   = 0; 
assign VGA_SCALER= 0;

assign AUDIO_S   = 0;
assign AUDIO_MIX = 0;

wire [1:0] ar = status[122:121];
video_freak video_freak
(
	.*,
	.VGA_DE_IN(VGA_DE),
	.VGA_DE(),

	.ARX((!ar) ? 12'd4 : (ar - 1'd1)),
	.ARY((!ar) ? 12'd3 : 12'd0),
	.CROP_SIZE(0),
	.CROP_OFF(0),
	.SCALE(status[16:15])
);

`include "build_id.v"
localparam CONF_STR = {
	"Oric;;",
	"F1,TAP,Load TAP file;",	
	"S0,DSK,Mount Drive A:;",
	"-;",
	"O3,ROM,Oric Atmos,Oric 1;",
	"O56,FDD Controller,Auto,Off,On;",
	"O7,Drive Write,Allow,Prohibit;",
	"-;",
	"O[51],Tape Input,File,ADC;",
	"H0T[52],Stop & Rewind;",	
	"-;",
	"O[122:121],Aspect ratio,Original,Full Screen,[ARC1],[ARC2];",
	"OAC,Scandoubler Fx,None,HQ2x,CRT 25%,CRT 50%;",
	"OFG,Scale,Normal,V-Integer,Narrower HV-Integer,Wider HV-Integer;",
	"-;",
	"O89,Stereo,Off,ABC (West Europe),ACB (East Europe);",
	"-;",
	"R0,Reset & Apply;",
	"V,v",`BUILD_DATE
};

///////////////////////////////////////////////////

wire locked;
wire clk_sys;

pll pll
(
	.refclk(CLK_50M),
	.rst(0),
	.outclk_0(clk_sys),
	.outclk_1(CLK_VIDEO),
	.locked(locked)
);

reg        reset = 0;
reg [16:0] clr_addr = 0;
always @(posedge clk_sys) begin

	if(~&clr_addr) clr_addr <= clr_addr + 1'd1;
	else reset <= 0;

	if(RESET | status[0] | buttons[1]) begin
		clr_addr <= 0;
		reset <= 1;
	end
	
end

wire tape_clk;
always @(posedge clk_sys) begin
	if (reset)
    	tape_clk <= 1'b0;
	else
    	tape_clk <= ~tape_clk;	
end

///////////////////////////////////////////////////

wire [10:0] ps2_key;

wire [15:0]  joy;
wire  [1:0]  buttons;
wire         forced_scandoubler;
wire [127:0] status;
wire 		 freeze_sync;

wire [31:0] sd_lba;
reg   [1:0] sd_rd;
reg   [1:0] sd_wr;
wire  [1:0] sd_ack;
wire  [8:0] sd_buff_addr;
wire  [7:0] sd_buff_dout;
wire  [7:0] sd_buff_din;
wire        sd_buff_wr;

wire        img_mounted;
wire [31:0] img_size;
wire        img_readonly;

wire        ioctl_wr;
wire [24:0] ioctl_addr;
wire  [7:0] ioctl_dout;
wire        ioctl_download;
wire  [7:0] ioctl_index;

reg         status_set;
reg  [31:0] status_out;

wire [21:0] gamma_bus;

hps_io #(.CONF_STR(CONF_STR)) hps_io
(
	.clk_sys(clk_sys),
	.HPS_BUS(HPS_BUS),

	.ps2_key(ps2_key),

	.joystick_0(joy),
	.buttons(buttons),
	.forced_scandoubler(forced_scandoubler),
	.status(status),

	.sd_lba('{sd_lba}),
	.sd_rd(sd_rd),
	.sd_wr(sd_wr),
	.sd_ack(sd_ack),
	.sd_buff_addr(sd_buff_addr),
	.sd_buff_dout(sd_buff_dout),
	.sd_buff_din('{sd_buff_din}),
	.sd_buff_wr(sd_buff_wr),
	.img_mounted(img_mounted),
	.img_size(img_size),
	.img_readonly(img_readonly),

	.ioctl_wr(ioctl_wr),
	.ioctl_addr(ioctl_addr),
	.ioctl_dout(ioctl_dout),
	.ioctl_download(ioctl_download),
	.ioctl_index(ioctl_index),

	.gamma_bus(gamma_bus)
);

///////////////////////////////////////////////////

wire key_strobe = old_keystb ^ ps2_key[10];
reg old_keystb = 0;
always @(posedge clk_sys) old_keystb <= ps2_key[10];

wire  [7:0] psg_a;
wire  [7:0] psg_b;
wire  [7:0] psg_c;
wire  [9:0] psg_out;

wire  [1:0] stereo = status [9:8];

wire        r, g, b; 
wire        hs, vs, HBlank, VBlank;
wire        clk_pix;
wire        tape_in, tape_out;

wire [15:0] ram_ad;
wire [15:0] ram_ad_temp;
wire  [7:0] ram_d;
wire  [7:0] ram_d_temp;
wire        ram_we,ram_cs;
wire        ram_we_temp,ram_cs_temp;
reg   [7:0] ram_q;

always @(posedge clk_sys) begin
	if(reset) begin
		ram_d_temp <= 1;
		ram_ad_temp <= clr_addr[15:0];
		ram_cs_temp <= 1'b1;
		ram_we_temp <= 1'b1;
	end
	else begin
		ram_d_temp <= ram_d;
		ram_ad_temp <= ram_ad;
		ram_cs_temp <= ram_cs;
		ram_we_temp <= ram_we;		
	end
end

dpram #(.addr_width_g(16)) ram (
	.clk_sys(clk_sys),

	.ram_cs(ram_cs_temp),
	.ram_we(ram_we_temp),
	.ram_d(ram_d_temp),
	.ram_q(ram_q),
	.ram_ad(ram_ad_temp),

	.ram_cs_b(1'b1),
	.ram_we_b(tape_wr),
	.ram_d_b(tape_dout),
	.ram_q_b(),
	.ram_ad_b(tape_addr)
);

wire        led_disk;

reg [15:0]  loadpoint;
reg [15:0]  tape_addr;
reg         tape_wr;
reg [7:0]   tape_dout;
wire        tape_complete;

reg 		tape_autorun = 0;

/*
cassette cassette(
  .clk(clk_sys),

  .ioctl_download(ioctl_download),
  .ioctl_wr(ioctl_wr),
  .ioctl_addr(ioctl_addr),
  .ioctl_dout(ioctl_dout),

  .reset_n(~reset),

  .autostart(),

  .tape_autorun(tape_autorun),

  .loadpoint(loadpoint),
  .tape_addr(tape_addr),
  .tape_wr(tape_wr),
  .tape_dout(tape_dout),
  .tape_complete(tape_complete)
);
*/

/*
cassettecached cassette(
  .clk(clk_sys),
  .tape_clk(tape_clk),

  // input raw tape data from tape cache
  .ioctl_download(ioctl_download),
  .ioctl_wr(ioctl_wr),
  .ioctl_addr(ioctl_addr),
  .ioctl_dout(ioctl_dout),

  .reset_n(~reset),
  //.tape_request(tape_request),

  // output processed tape data to ram
  .autostart(),
  .tape_autorun(tape_autorun),
  .loadpoint(loadpoint),
  .tape_addr(tape_addr),
  .tape_wr(tape_wr),
  .tape_dout(tape_dout),
  .tape_complete(tape_complete)
);
*/


oricatmos oricatmos
(
	.CLK_IN           (clk_sys),
	.RESET            (reset),

	.key_pressed      (ps2_key[9]),
	.key_code         (ps2_key[7:0]),
	.key_extended     (ps2_key[8]),
	.key_strobe       (key_strobe),
	//.PSG_OUT_L			(psg_l),
	//.PSG_OUT_R			(psg_r),
	.PSG_OUT_A        (psg_a),
	.PSG_OUT_B        (psg_b),
	.PSG_OUT_C        (psg_c),
	.PSG_OUT          (psg_out),

	.VIDEO_CLK		  (clk_pix),
	.VIDEO_R		  (r),
	.VIDEO_G		  (g),
	.VIDEO_B		  (b),
	.VIDEO_HSYNC	  (hs),
	.VIDEO_VSYNC	  (vs),
	.VIDEO_HBLANK	  (HBlank),
	.VIDEO_VBLANK	  (VBlank),

	.K7_TAPEIN		  (status[51] ? adc_cassette_bit : casdout ), //(tape_status != 3'h0 ? casdout : 1'b0)), // casdout ), // (tape_adc),
	.K7_TAPEOUT		  (tape_out),
	.K7_REMOTE		  (cas_relay),

	.ram_ad           (ram_ad),
	.ram_d            (ram_d),
	.ram_q            (ram_q),
	.ram_cs           (ram_cs),
	.ram_oe           (),
	.ram_we           (ram_we),

	.joystick_0       (0),
	.joystick_1       (0),

	.fd_led           (led_disk),
	.fdd_ready        (fdd_ready),
	.fdd_busy         (),
	.fdd_reset        (0),
	.fdd_layout       (0),

	.phi2             (),
	.pll_locked       (~reset),
	.disk_enable      ((!status[6:5]) ? ~fdd_ready : status[5]),
	.rom			  (rom),

	.img_mounted      (img_mounted), // signaling that new image has been mounted
	.img_size         (img_size), // size of image in bytes
	.img_wp           (status[7] | img_readonly), // write protect
    .sd_lba           (sd_lba[0]),
	.sd_rd            (sd_rd),
	.sd_wr            (sd_wr),
	.sd_ack           (sd_ack),
	.sd_buff_addr     (sd_buff_addr),
	.sd_dout          (sd_buff_dout),
	.sd_din           (sd_buff_din[0]),
	.sd_dout_strobe   (sd_buff_wr),
	.sd_din_strobe    (0),

  	.tape_addr		  (loadpoint),
    .tape_complete	  (tape_autorun),

    .hcnt(h_cnt), 
    .vcnt(v_cnt)  
);

reg fdd_ready = 0;
always @(posedge clk_sys) if(img_mounted) fdd_ready <= |img_size;

reg rom = 0;
always @(posedge clk_sys) if(reset) rom <= ~status[3];

///////////////////////////////////////////////////

reg clk_pix2;
always @(posedge clk_sys) clk_pix2 <= clk_pix;

reg ce_pix;
always @(posedge CLK_VIDEO) begin
	reg old_clk;
	
	old_clk <= clk_pix2;
	ce_pix <= ~old_clk & clk_pix2;
end

reg HSync, VSync;
always @(posedge CLK_VIDEO) begin
	if(ce_pix) begin
		HSync <= ~hs;
		if(~HSync & ~hs) VSync <= ~vs;
	end
end

wire [2:0] scale = status[12:10];
wire [2:0] sl = scale ? scale - 1'd1 : 3'd0;
wire       scandoubler = scale || forced_scandoubler;

assign VGA_F1 = 0;
assign VGA_SL = sl[1:0];

video_mixer #(.LINE_LENGTH(250), .HALF_DEPTH(1), .GAMMA(1)) video_mixer
(
	.*,
	.R({4{r}}),
	.G({4{g}}),
	.B({4{b}}),	
	.hq2x(scale==1)
);

///////////////////////////////////////////////////

always @ (psg_a,psg_b,psg_c,psg_out,stereo) begin
		case (stereo)
			2'b01  : {AUDIO_L,AUDIO_R} <= {{{2'b0,psg_a} + {2'b0,psg_b}},6'b0,{{2'b0,psg_c} + {2'b0,psg_b}},6'b0};
			2'b10  : {AUDIO_L,AUDIO_R} <= {{{2'b0,psg_a} + {2'b0,psg_c}},6'b0,{{2'b0,psg_c} + {2'b0,psg_b}},6'b0};
			default: {AUDIO_L,AUDIO_R} <= {psg_out,6'b0,psg_out,6'b0};
       endcase
end

/////////////////////// ADC Module  //////////////////////////////


wire [11:0] adc_data;
wire        adc_sync;
reg [11:0] adc_value;
reg adc_sync_d;

integer ii=0;
reg [11:0] adc_val[0:511];
reg [21:0] adc_total = 0;
reg [11:0] adc_avg;

reg adc_cassette_bit;


// interface to ADC via framework
//
ltc2308 #(1, 48000, 50000000) adc_input		// mono, ADC_RATE = 48000, CLK_RATE = 50000000
(
	.reset(reset),
	.clk(CLK_50M),

	.ADC_BUS(ADC_BUS),
	.dout(adc_data),
	.dout_sync(adc_sync)
);

// when data arrives:
//		- latch it in adc_value
//		- keep track of a running average across 512 samples
//
//		-> this average acts as a high-pass filter above roughly 100 Hz while retaining
//		 	while retaining very high frequency response, for possible future fast-load techniques
//
always @(posedge CLK_50M) begin

	adc_sync_d<=adc_sync;
	if(adc_sync_d ^ adc_sync) begin
		adc_value <= adc_data;					// latch in current value, adc_Value
		
		adc_val[0] <= adc_value;				
		adc_total  <= adc_total - adc_val[511] + adc_value;

		for (ii=0; ii<511; ii=ii+1)
			adc_val[ii+1] <= adc_val[ii];
			
		adc_avg <= adc_total[20:9];			// update average value every fetch
		
		if (adc_value < (adc_avg - 100))		// flip the cassette bit if > 0.1V from average
			adc_cassette_bit <= 1;				// note that original CoCo reversed polarity

		if (adc_value > (adc_avg + 100))
			adc_cassette_bit <= 0;
		
	end
end

wire casdout;
wire cas_relay;

wire [24:0] sdram_addr;
wire  [7:0] sdram_data;
wire 		sdram_rd;
wire 		load_tape = ioctl_index==1;
reg  [24:0] tape_end;
reg 		tape_loaded = 1'b0;
reg         ioctl_downlD;
reg   [2:0] tape_status;

/*
sdram sdram
(
	.*,
	.init(~locked),
	.clk(clk_sys),
	.addr(ioctl_download ? ioctl_addr : sdram_addr),
	.wtbt(0),
	.dout(sdram_data),
	.din(ioctl_dout),
	.rd(sdram_rd),
	.we(ioctl_wr & load_tape),
	.ready()
);
*/

bram tapecache (
  .clk(clk_sys),

  .bram_download(ioctl_download),
  .bram_wr(ioctl_wr & load_tape),
  .bram_init_address(ioctl_addr),
  .bram_din(ioctl_dout),

  .addr(sdram_addr),
  .dout(sdram_data),
  .cs(sdram_rd)
);


always @(posedge clk_sys) begin
 if (load_tape) tape_end <= ioctl_addr;
end

always @(posedge clk_sys) begin
	ioctl_downlD <= ioctl_download;
	if(ioctl_downlD & ~ioctl_download) tape_loaded <= 1'b1;
end

cassette cassette (
  .clk(clk_sys),

  .rewind(status[52] | (load_tape&ioctl_download)),
  .en(cas_relay&tape_loaded), 
  .sdram_addr(sdram_addr),
  .sdram_data(sdram_data),
  .sdram_rd(sdram_rd),

  .tape_end(tape_end),
  .data(casdout),
  .state(tape_status)
);

/* older adc
wire tape_adc, tape_adc_act;
ltc2308_tape ltc2308_tape
(
	.clk(CLK_50M),
	.ADC_BUS(ADC_BUS),
	.dout(tape_adc),
	.active(tape_adc_act)
);
*/

endmodule
