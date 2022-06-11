
//          +-----+----> Address for next line ($0510)
//          |   | +----+----> Line number (10)
//          |   | |   | +----> Token for REM
//          |   | |   | |  +------------------------+----> LIGNE 10
//          |   | |   | |  |                        |  +----> End Of Line
//00000501  10 05 0a 00 9d 20 4c 49  47 4e 45 20 31 30 00       |..... LIGNE 10.|

//          +--+----> Address for next line ($051d)
//          |   | +----+----> Line number (20)
//          |   | |   | +----> Token for PRINT
//          |   | |   | |  +-------------------+----> "TEST"
//          |   | |   | |  |                   | +----> End Of Line
//00000510  1d 05 14 00 ba 20 22 54 45  53 54 22 00                |.... "TEST"..|

//           +---+---> End of Program
//0000051d   00 00

//                                      +---+--> End address
//                                      |   | +---+--> Start address
//00000000  16 16 16 16 24 ff ff 00  00 05 1f 05 01 03 54 45  |....$.........TE|
//00000010  53 54 53 41 56 45 00 10  05 0a 00 9d 20 4c 49 47  |STSAVE...... LIG|
//00000020  4e 45 20 31 30 00 1d 05  14 00 ba 20 22 54 45 53  |NE 10...... "TES|
//00000030  54 22 00 00 00 0b                                 |T"....|

module cassettecached(
  input              clk,
  input              tape_clk,

  input              ioctl_download,
  input              ioctl_wr,
  input      [24:0]  ioctl_addr,
  input      [7:0]   ioctl_dout,

  input              reset_n,

  output reg         tape_request,

  output reg         autostart,

  output reg         tape_autorun,

  output reg [15:0]  loadpoint,
  output reg [15:0]  tape_addr,
  output reg         tape_wr,
  output reg [7:0]   tape_dout,
  output reg         tape_complete
);

// State machine constants
localparam SM_SYNC	           =  1;
localparam SM_FILETYPE         =  2;
localparam SM_AUTORUN          =  3;
localparam SM_ENDADDRESSHIGH   =  4;
localparam SM_ENDADDRESSLOW    =  5;
localparam SM_STARTADDRESSHIGH =  6;
localparam SM_STARTADDRESSLOW  =  7;
localparam SM_FILENAME         =  8;
localparam SM_PROGRAMCODE      =  9;
localparam SM_COMPLETE         = 10;

// TAP
reg	[15:0]	programlength;
reg	[15:0]	start_addr;
reg	[15:0]	end_addr;
reg [15:0]  state = SM_SYNC;

reg [7:0]   fileType;
reg [7:0]   autorun;
reg [7:0]   endAddressHIGH;
reg [7:0]   endAddressLOW;
reg [7:0]   startAddressHIGH;
reg [7:0]   startAddressLOW;

reg unused;

reg	    [15:0]	cache_addr = 'd00;
wire	[7:0]	cache_dout;
reg             cache_cs;

bram tapecache(
  .clk(clk),

  .bram_download(ioctl_download),
  .bram_wr(ioctl_wr),
  .bram_init_address(ioctl_addr),
  .bram_din(ioctl_dout),

  .addr(cache_addr),
  .dout(cache_dout),
  .cs(cache_cs)
);

reg         tapecache_loaded;
reg         ioctl_downlD;
reg [24:0]  tape_size;

always @(posedge clk) begin
	ioctl_downlD <= ioctl_download;
	if(ioctl_downlD & ~ioctl_download) tapecache_loaded <= 1'b1;
    if(tapecache_loaded) begin
        cache_cs <= 1'b1;
        tape_size <= ioctl_addr;
    end
    if(tape_complete==1'b1) begin
        $display("tapecache_loaded tape_complete %x state %x size %x", tape_complete, state, ioctl_addr); 
        tapecache_loaded <= 1'b0;
    end
end

reg	    [15:0]	new_address = 'd00;

// process tape header
always @(posedge tape_clk) begin

    if(tapecache_loaded==1'b1 && tape_complete==1'b0) begin
        $display("cache_addr %x cache_dout %x----------------------------->>", cache_addr, cache_dout);              
        case (state)
            // -------------------------------------------------------------------------------        
            SM_SYNC:
            begin
                if (cache_dout==8'h24) begin
                    new_address <= cache_addr + 8'd03;  
                    $display("SM_SYNC cache_addr %x cache_dout %x new_address %x", cache_addr, cache_dout, new_address);    
                    state <= SM_FILETYPE;                     
                end
                else begin
                    cache_addr <= cache_addr + 1'd1;                   
                end
            end
            // -------------------------------------------------------------------------------
            SM_FILETYPE: 
            begin
                if(cache_addr==new_address) begin
                    if (cache_dout==8'h00 || cache_dout==8'h40 || cache_dout==8'h80) begin
                        fileType <= cache_dout;
                        $display("SM_FILETYPE cache_addr %x cache_dout %x new_address %x", cache_addr, cache_dout, new_address);  
                        state <= SM_AUTORUN;                       
                    end   
                end             
                cache_addr <= cache_addr + 1'd1;   
            end
            // -------------------------------------------------------------------------------            
            SM_AUTORUN: 
            begin
                //if(cache_addr==8'd07) begin
                   if(cache_dout==8'h00 || cache_dout==8'h04 || cache_dout==8'h80) begin
                        autorun <= cache_dout;   
                        state <= SM_ENDADDRESSHIGH;       
                    end
                    else if (cache_dout==8'hC7) begin
                        autorun <= cache_dout;
                        state <= SM_ENDADDRESSHIGH;                       
                    end
                //end

                $display("SM_AUTORUN cache_addr %x cache_dout %x", cache_addr, cache_dout);                 
                cache_addr <= cache_addr + 1'd1;   
            end   
            // -------------------------------------------------------------------------------             
            SM_ENDADDRESSHIGH: 
            begin
                //if(cache_addr==8'd08) begin
                    endAddressHIGH <= cache_dout;
                    state <= SM_ENDADDRESSLOW;
                //end 

                $display("SM_ENDADDRESSHIGH cache_addr %x cache_dout %x", cache_addr, cache_dout);                   
                cache_addr <= cache_addr + 1'd1;                
            end  
            // -------------------------------------------------------------------------------            
            SM_ENDADDRESSLOW: 
            begin
                //if(cache_addr==8'd09) begin
                    endAddressLOW <= cache_dout;
                    state <= SM_STARTADDRESSHIGH;
                //end   

                cache_addr <= cache_addr + 1'd1;    
            end  
            // -------------------------------------------------------------------------------            
            SM_STARTADDRESSHIGH: 
            begin
                //if(cache_addr==8'd10) begin
                    end_addr <= { endAddressHIGH, endAddressLOW };                         
                    startAddressHIGH <= cache_dout;
                    state <= SM_STARTADDRESSLOW;
                //end   

                $display("SM_STARTADDRESSHIGH cache_addr %x cache_dout %x", cache_addr, cache_dout);                     
                cache_addr <= cache_addr + 1'd1; 
            end  
            // -------------------------------------------------------------------------------            
            SM_STARTADDRESSLOW: 
            begin
                //if(cache_addr==8'd11) begin
                    startAddressLOW <= cache_dout;
                    state <= SM_FILENAME;                                                                             
                //end   

                $display("SM_STARTADDRESSLOW cache_addr %x cache_dout %x", cache_addr, cache_dout);                   
                cache_addr <= cache_addr + 1'd1; 
            end   
            // -------------------------------------------------------------------------------            
            SM_FILENAME: 
            begin
                //if(cache_addr>=8'd13) begin
                    start_addr <= { startAddressHIGH, startAddressLOW }; 
                    programlength <= start_addr;
                    $display("cache_addr %x cache_dout %x", cache_addr, cache_dout); 

                    // check the byte for ASCII uppercase and h'20
                    if(cache_dout==8'h20 || (cache_dout >= 8'h30 && cache_dout <= 8'h5A)) begin
                        $display("Ascii found %c", cache_dout); 
                    end
                    else if (cache_dout==8'h00) begin
                        $display("End of Filename found"); 
                        state <= SM_PROGRAMCODE;                           
                    end
                //end   

                $display("SM_FILENAME cache_addr %x cache_dout %x", cache_addr, cache_dout);                                                                       
                cache_addr <= cache_addr + 1'd1; 
            end    
            // -------------------------------------------------------------------------------            
            SM_PROGRAMCODE: 
            begin
                loadpoint <= { startAddressHIGH, startAddressLOW }; 
                $display("(state SM_PROGRAMCODE %x) cache_addr %x cache_dout %x", state, cache_addr, cache_dout); 
                tape_wr <= 1'b1;	                     
                tape_addr <= start_addr;
                tape_dout <= cache_dout;
                programlength <= programlength + 1;                
                cache_addr <= cache_addr + 1'd1; 

                if(programlength == tape_size)
                begin
                    tape_complete <= 1'b1;                          
                    $display( "(state SM_PROGRAMCODE %x) loadpoint %x end_addr %x", state, loadpoint, end_addr); 
                    state <= SM_COMPLETE;                                                  
                end                    
            end   
            // -------------------------------------------------------------------------------            
            SM_COMPLETE: 
            begin
            //    $display( "(state SM_COMPLETE %x) start_addr %x end_addr %x", state, start_addr, end_addr);         
            //    state <= SM_FILETYPE;                          
            end    
        endcase
        //$display("fileType %x autorun %x end_addr %x start_addr %x startAddressLOW %x", fileType, autorun, end_addr, start_addr, startAddressLOW);
    end
    else if(tape_complete) begin
        if(tape_wr) begin
 		    tape_wr <= 1'b0;  
            //$display( "(tape_complete tape_wr) loadpoint %x ", loadpoint);              
            if(loadpoint > 16'h0505) begin
                tape_autorun <= 1'b1; 
            end                        
        end
        else begin
            tape_autorun <= 1'b0;  
            //$display( "(state else if %x) tape_complete %x tape_wr %x tape_autorun %x", state, tape_complete, tape_wr, tape_autorun);  
            tape_complete <= 1'b0;        
            cache_addr <= 8'd00;                  
            state <= SM_SYNC;                                              
        end
    end
end

endmodule
