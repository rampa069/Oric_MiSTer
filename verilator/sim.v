`timescale 1ns/1ns

module top(

   input clk_48,
   //input clk_24,
   input reset,
   input [11:0]  inputs,

   output reg [7:0] VGA_R,
   output reg [7:0] VGA_G,
   output reg [7:0] VGA_B,
   
   output VGA_HS,
   output VGA_VS,
   output VGA_HB,
   output VGA_VB,

   output [15:0] AUDIO_L,
   output [15:0] AUDIO_R,
   
   input        ioctl_download,
   input        ioctl_upload,
   input        ioctl_wr,
   input [24:0] ioctl_addr,
   input [7:0]  ioctl_dout,
   input [7:0]  ioctl_din,   
   input [7:0]  ioctl_index,

   // ps2 alternative interface.
   // [8] - extended, [9] - pressed, [10] - toggles with every press/release
   input [10:0] ps2_key,

   output  reg  ioctl_wait=1'b0,
   output  reg	ce_pix
);

reg [16:0] clr_addr = 0;

wire [15:0] ram_ad;
reg  [15:0] ram_ad_temp;
wire  [7:0] ram_d;
reg   [7:0] ram_d_temp;
wire        ram_we,ram_cs;
reg         ram_we_temp,ram_cs_temp;
reg   [7:0] ram_q;

always @(posedge clk_48) begin
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

/*
reg   [7:0] ram[65536];
always @(posedge clk_48) begin
	if(reset) ram[clr_addr[15:0]] <= '1;
	else if(ram_we & ram_cs) ram[ram_ad] <= ram_d;
end

reg  [7:0] ram_q;
always @(posedge clk_48) ram_q <= ram[ram_ad];
*/

always @(posedge clk_48) begin
     // $display( "(TOP) tape_autorun %x", tape_autorun);              
//$display("VGA_HS %x VGA_HB %x clk %x",VGA_HS,VGA_HB,video_clk);
end
wire video_clk;

reg [15:0]  tape_addr;
reg         tape_wr;
reg [7:0]   tape_dout;
reg         tape_complete;
reg 		    tape_autorun = 0;
reg [15:0]  loadpoint;

wire tape_request;
reg [15:0]  tape_read_addr;
reg [15:0]  tape_read_dout;

/*
always @(posedge clk_48) 
    begin
      if(tape_wr)
        ram[tape_addr] <= tape_dout;      
        $display( "(TOP) tape_addr %x tape_wr %x tape_dout %x tape_complete %x tape_autorun %x loadpoint %x", tape_addr, tape_wr, tape_dout, tape_complete, tape_autorun, loadpoint);   
    end
*/

dpram #(.AW(16)) ram (
	.clock(clk_48),

	.ce1(ram_cs_temp),
	.we1(ram_we_temp),
	.di1(ram_d_temp),
	.do1(ram_q),
	.a1(ram_ad_temp),

	.ce2(1'b1),
	.we2(tape_wr),
	.di2(tape_dout),
	.do2(),
	.a2(tape_addr)
);

cassettecached cassette(
  .clk(clk_48),

  // input raw tape data from tape cache
  .ioctl_download(ioctl_download),
  .ioctl_wr(ioctl_wr),
  .ioctl_addr(ioctl_addr),
  .ioctl_dout(ioctl_dout),

  .reset_n(~reset),
  .tape_request(tape_request),

  // output processed tape data to ram
  .autostart(),
  .tape_autorun(tape_autorun),
  .loadpoint(loadpoint),
  .tape_addr(tape_addr),
  .tape_wr(tape_wr),
  .tape_dout(tape_dout),
  .tape_complete(tape_complete)
);

wire key_strobe = old_keystb ^ ps2_key[10];
reg old_keystb = 0;
always @(posedge clk_48) old_keystb <= ps2_key[10];

oricatmos oricatmos
(
	.CLK_IN           (clk_48),
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
	.VIDEO_HBLANK	  (VGA_HB),
	.VIDEO_VBLANK	  (VGA_VB),

	.K7_TAPEIN		  (tape_adc),
	.K7_TAPEOUT		  (tape_out),
	.K7_REMOTE		  (),

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
	.pll_locked       (0),
	.disk_enable      (1'b1),
	.rom			  (1),

	.img_mounted      (img_mounted), // signaling that new image has been mounted
	.img_size         (img_size), // size of image in bytes
	.img_wp           (img_readonly), // write protect
  	.sd_lba           (sd_lba),
	.sd_rd            (sd_rd),
	.sd_wr            (sd_wr),
	.sd_ack           (sd_ack),
	.sd_buff_addr     (sd_buff_addr),
	.sd_dout          (sd_buff_dout),
	.sd_din           (sd_buff_din),
	.sd_dout_strobe   (sd_buff_wr),
	.sd_din_strobe    (0),

  	.tape_addr		  (loadpoint),
  	.tape_complete	  (tape_autorun)
);

wire   r, g, b; 
wire   hs, vs;
reg    clk_pix2;
always @(posedge clk_48) clk_pix2 <= clk_pix;

always @(posedge clk_48) begin
	reg old_clk;
	
	old_clk <= clk_pix2;
	ce_pix <= ~old_clk & clk_pix2;
end

always @(posedge clk_48) begin
	if(ce_pix) begin
		VGA_HS <= ~hs;
		if(~VGA_HS & ~hs) VGA_VS <= ~vs;
	end

	VGA_R <= {4{r}};
	VGA_G <= {4{g}};
	VGA_B <= {4{b}};	
end

//assign	VGA_R = {4{r}};
//assign	VGA_G = {4{g}};
//assign 	VGA_B = {4{b}};

reg fdd_ready = 0;
always @(posedge clk_48) if(img_mounted) fdd_ready <= |img_size;

endmodule
