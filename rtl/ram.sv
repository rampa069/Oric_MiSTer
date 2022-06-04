//`timescale 1ns / 1ps

module ram 
(
    input clk_sys, 
    input reset,

    input [7:0]  ram_d,
    input [15:0] ram_ad,	
    input        ram_cs, 
    input        ram_we, 

    input [7:0]  ram_d_b,
    input [15:0] ram_ad_b,	
    input        ram_cs_b, 
    input        ram_we_b, 

    input [15:0] clr_addr,

    output reg [7:0] ram_q
    //output reg [7:0] ram_q_b    
);

reg   [7:0] ram[65536];

always @(posedge clk_sys) begin
    ram_q <= ram[ram_ad];
    //ram_q_b <= ram[ram_ad_b];
	
    if(reset) 
        ram[clr_addr] <= '1;
	else if(ram_cs & ram_we) 
        ram[ram_ad] <= ram_d;

    if(ram_cs_b & ram_we_b) 
        ram[ram_ad_b] <= ram_d_b; 
end

/*
always @(posedge clk_sys) begin
    ram_q_b <= ram[ram_ad_b];

    if(ram_cs_b & ram_we_b) 
        ram[ram_ad_b] <= ram_d_b; 
end
*/

//always @(posedge clk_sys) ram_q <= ram[ram_ad];

endmodule
