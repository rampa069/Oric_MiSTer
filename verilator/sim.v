`timescale 1ns/1ns

module top(

   input clk_48,
  // input clk_24,
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

always @(posedge clk_48) begin
      $display( "(TOP) tape_autorun %x", tape_autorun);              
end

reg [15:0]  tape_addr;
reg         tape_wr;
reg [7:0]   tape_dout;
reg         tape_complete;
reg 		    tape_autorun = 0;

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

  .autostart(),

  .tape_autorun(tape_autorun),

  .tape_addr(tape_addr),
  .tape_wr(tape_wr),
  .tape_dout(tape_dout),
  .tape_complete(tape_complete)
);

endmodule
