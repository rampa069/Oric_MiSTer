
module cassettecached(
  input              clk,

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
localparam SM_INIT	           =  1;
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
reg [15:0]  state = SM_FILETYPE;

reg [7:0] fileType;
reg [7:0] autorun;

reg [7:0] endAddressHIGH;
reg [7:0] endAddressLOW;
reg [7:0] startAddressHIGH;
reg [7:0] startAddressLOW;

reg unused;

reg	[15:0]	cache_addr = 'd06;
wire	[7:0]	cache_dout;
reg         cache_cs;

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

reg tapecache_loaded = 0;
reg ioctl_downlD;

always @(posedge clk) begin
    // fill the cache
	ioctl_downlD <= ioctl_download;
	if(ioctl_downlD & ~ioctl_download) tapecache_loaded <= 1;
    if(tapecache_loaded) begin
        cache_cs <= 1'b1;
    end
end

// process tape header
always @(posedge clk) begin
    if(tapecache_loaded && tape_complete==1'b0) begin
        case (state)
            SM_FILETYPE: 
            begin
                if(cache_addr=='d06) begin
                    if (cache_dout=='h00) begin
                        fileType <= cache_dout;
                        state <= SM_AUTORUN;                       
                    end                
                    else if (cache_dout=='h80) begin
                        fileType <= cache_dout;
                        state <= SM_AUTORUN;                       
                    end
                end
                cache_addr <= cache_addr + 1'd1;   
            end
            SM_AUTORUN: 
            begin
                if(cache_addr=='d07) begin
                   if(cache_dout=='h00) begin
                        autorun <= cache_dout;   
                        state <= SM_ENDADDRESSHIGH;       
                    end
                    else if (cache_dout=='hC7) begin
                        autorun <= cache_dout;
                        state <= SM_ENDADDRESSHIGH;                       
                    end
                end
                cache_addr <= cache_addr + 1'd1;   
            end    
            SM_ENDADDRESSHIGH: 
            begin
                if(cache_addr=='d09) begin
                    endAddressHIGH <= cache_dout;
                    state <= SM_ENDADDRESSLOW;
                end   
                cache_addr <= cache_addr + 1'd1;                
            end  
            SM_ENDADDRESSLOW: 
            begin
                if(cache_addr=='d10) begin
                    endAddressLOW <= cache_dout;
                    state <= SM_STARTADDRESSHIGH;
                end   
                cache_addr <= cache_addr + 1'd1;    
            end  
            SM_STARTADDRESSHIGH: 
            begin
                if(cache_addr=='d11) begin
                    end_addr <= { endAddressHIGH, endAddressLOW };                         
                    startAddressHIGH <= cache_dout;
                    state <= SM_STARTADDRESSLOW;
                end   
                cache_addr <= cache_addr + 1'd1; 
            end  
            SM_STARTADDRESSLOW: 
            begin
                if(cache_addr=='d12) begin
                    startAddressLOW <= cache_dout;
                    state <= SM_FILENAME;                                                                             
                end   
                cache_addr <= cache_addr + 1'd1; 
            end   
            SM_FILENAME: 
            begin
                if(cache_addr>='d14) begin
                    start_addr <= { startAddressHIGH, startAddressLOW }; 
                    loadpoint <= start_addr;                        
                    $display("cache_addr %x cache_dout %x", cache_addr, cache_dout); 

                    // check the byte for ASCII uppercase and h'20
                    if(cache_dout=='h20 || (cache_dout >= 'h30 && cache_dout <= 'h5A)) begin
                        $display("Ascii found %c", cache_dout); 
                    end
                    else if (cache_dout=='h00) begin
                        $display("End of Filename found"); 
                        state <= SM_PROGRAMCODE;                           
                    end
                end                                                        
                cache_addr <= cache_addr + 1'd1; 
            end    
            SM_PROGRAMCODE: 
            begin
               // $display("cache_addr %x cache_dout %x", cache_addr, cache_dout); 
                tape_wr <= 1'b1;	                     
                tape_addr <= start_addr;
                tape_dout <= cache_dout;
                start_addr <= start_addr + 1;                
                cache_addr <= cache_addr + 1'd1; 

                if(start_addr == (end_addr))
                begin
                    tape_complete <= 1'b1;                          
                    $display( "(state SM_PROGRAMCODE %x) start_addr %x end_addr %x", state, start_addr, end_addr); 
                    state <= SM_COMPLETE;                                                  
                end                    
            end   
            SM_COMPLETE: 
            begin
            //    $display( "(state SM_COMPLETE %x) start_addr %x end_addr %x", state, start_addr, end_addr);         
                state <= SM_FILETYPE;                          
            end                                                                                        
        endcase
       // $display("fileType %x autorun %x end_addr %x start_addr %x startAddressLOW %x", fileType, autorun, end_addr, start_addr, startAddressLOW);
    end
    else if(tape_complete) begin
        if(tape_wr) begin
 		    tape_wr <= 1'b0;  
            //if(loadpoint > 4'h0505) tape_autorun <= 1'b1; 
            tape_autorun <= 1'b1;                              
        end
        else begin
            tape_autorun <= 1'b0;  
        //    $display( "(state else if %x) tape_complete %x tape_wr %x tape_autorun %x", state, tape_complete, tape_wr, tape_autorun);                             
        end
    end
end

endmodule
