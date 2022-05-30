`timescale 1ns/1ns

module top(

   input clk_48,
   input clk_24,
   input reset,
   input [11:0]  inputs,

   output [7:0] VGA_R,
   output [7:0] VGA_G,
   output [7:0] VGA_B,
   
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
   output  reg  ioctl_wait=1'b0
   
);
   
   // Core inputs/outputs
   wire       pause;
   wire [7:0] audio;
   wire [8:0] rgb;
   wire [3:0] led;
   reg [7:0]  trakball;
   reg [7:0]  joystick;
   reg [9:0]  playerinput;  

   // Hardcode default switches
   reg [7:0]  sw1 = { 1'b0, 1'b0,2'b0,2'b0,2'b0 };
   reg [7:0]  sw2 = 8'h02;

   // Convert 3bpp output to 8bpp
   assign VGA_R = {rgb[2:0],rgb[2:0],rgb[2:1]};
   assign VGA_G = {rgb[5:3],rgb[5:3],rgb[5:4]};
   assign VGA_B = {rgb[8:6],rgb[8:6],rgb[8:7]};
    
   // MAP INPUTS FROM SIM
   // -------------------
   assign playerinput[9] = ~inputs[10]; // coin r
   assign playerinput[8] = ~inputs[9]; // coin m
   assign playerinput[7] = ~inputs[8]; // coin l
   assign playerinput[6] = 1'b1;       // self-test
   assign playerinput[5] = 1'b0;       // cocktail
   assign playerinput[4] = 1'b1;       // slam
   assign playerinput[3] = ~inputs[7]; // start 2
   assign playerinput[2] = ~inputs[6]; // start 1
   assign playerinput[1] = ~inputs[5]; // fire 2
   assign playerinput[0] = ~inputs[4]; // fire 1  
   assign joystick[7:4] = { ~inputs[0],~inputs[1],~inputs[2],~inputs[3] }; // right, left, down, up 1
   assign joystick[3:0] = { ~inputs[0],~inputs[1],~inputs[2],~inputs[3] }; // right, left, down, up 2
   assign pause = inputs[11];       // pause

   // MAP OUTPUTS
   assign AUDIO_L = {audio,audio};
   assign AUDIO_R = AUDIO_L;

   reg ce_pix;
   always @(posedge clk_48) begin
      reg old_clk;
      
      old_clk <= clk_24;
      ce_pix <= old_clk & ~clk_24;
   end


wire ce_pix = 1'b1;   

newrom tape(
  .clk(clk_48),
  .addr(),
  .dout(),
  .cs(),
  .rom_init(ioctl_download),
  .rom_init_clk(clk_48),
  .rom_init_address(ioctl_addr),
  .rom_init_data(ioctl_dout)
);

reg [16:0] clr_addr = 0;
wire [15:0] ram_ad;
wire  [7:0] ram_d;
wire        ram_we,ram_cs;

reg   [7:0] ram[65536];
always @(posedge clk_48) begin
	if(reset) ram[clr_addr[15:0]] <= '1;
	else if(ram_we & ram_cs) ram[ram_ad] <= ram_d;
end

reg  [7:0] ram_q;
always @(posedge clk_48) ram_q <= ram[ram_ad];

reg [15:0]  tape_addr;
reg         tape_wr;
reg [7:0]   tape_dout;
reg         tape_complete;

always @(posedge clk_48) 
    begin
      if(tape_wr)
        ram[tape_addr] <= tape_dout;      
        $display( "(TOP) tape_addr %x tape_wr %x tape_dout %x tape_complete %x", tape_addr, tape_wr, tape_dout, tape_complete);   
    end

cassette cassette(
  .clk(clk_48),

  .ioctl_download(ioctl_download),
  .ioctl_wr(ioctl_wr),
  .ioctl_addr(ioctl_addr),
  .ioctl_dout(ioctl_dout),

  .reset_n(~reset),

  .autostart_basic(),

  .tape_addr(tape_addr),
  .tape_wr(tape_wr),
  .tape_dout(tape_dout),
  .tape_complete(tape_complete)
);

endmodule
