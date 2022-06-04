//`timescale 1ns / 1ps

module bram (
  input clk,

  input bram_download,
  input bram_wr,
  input [15:0] bram_init_address,
  input [7:0] bram_din,

  input cs,
  input [15:0] addr,
  output reg [7:0] dout
);

reg [7:0] memory[65536:0];

always @(posedge clk) begin
  if (bram_download && bram_wr)
    memory[bram_init_address] <= bram_din;
  else if (cs)
    dout <= memory[addr];
end

endmodule
