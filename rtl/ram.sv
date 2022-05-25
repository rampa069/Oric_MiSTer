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

    output [7:0] ram_q
);

reg   [7:0] ram[65536];

always @(posedge clk_sys) begin
	//if(reset) 
    //    ram[clr_addr] <= '1;
	//else 
    if(ram_we & ram_cs) 
        ram[ram_ad] <= ram_d;
    else if(ram_we_b)
        ram[ram_ad_b] <= ram_d_b; 
    else
        ram_q <= ram[ram_ad];
end

//always @(posedge clk_sys) ram_q <= ram[ram_ad];

/*
always @(posedge clk_sys) begin
    if(ram_we_b)
        ram[ram_ad_b] <= ram_d_b; 		
end
*/

endmodule
