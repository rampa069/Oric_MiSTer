
module cassette(
  input              clk,

  input              ioctl_download,
  input              ioctl_wr,
  input      [24:0]  ioctl_addr,
  input      [7:0]   ioctl_dout,

  input              reset_n,

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
localparam SM_UNUSED           =  8;
localparam SM_PROGRAMCODE      =  9;
localparam SM_COMPLETED        = 10;

// TAP
reg	[15:0]	programlength;
reg	[15:0]	start_addr;
reg	[15:0]	end_addr;
reg [15:0]  state = SM_INIT;

reg [7:0] fileType;
reg [7:0] autorun;

reg [7:0] endAddressHIGH;
reg [7:0] endAddressLOW;
reg [7:0] startAddressHIGH;
reg [7:0] startAddressLOW;

reg unused;

always @(posedge clk) 
    begin
    if(ioctl_download && ioctl_wr)
        begin
            case (state)
                SM_INIT: 
                begin
                    $display( "(state SM_INIT %x) ioctl_addr: %x ioctl_dout: %x", state, ioctl_addr, ioctl_dout);
                    if(ioctl_addr=='h06) begin   
                        fileType <= ioctl_dout;  
                        state <= SM_FILETYPE;  
                    end
                    //$display( "(state SM_INIT %x) ioctl_addr: %x ioctl_dout: %x fileType %x", state, ioctl_addr, ioctl_dout, fileType);                                          
                end
                SM_FILETYPE: 
                begin
                    //$display( "(state SM_FILETYPE %x) ioctl_addr: %x ioctl_dout: %x fileType %x", state, ioctl_addr, ioctl_dout, fileType);
                    if(fileType=='h00) begin
                        //$display( "(state SM_FILETYPE %x) filetype BASIC: %x", state, fileType);   
                        autorun <= ioctl_dout;                         
                        state <= SM_AUTORUN;                        
                    end                
                    else if(fileType=='h80) begin
                        //$display( "(state SM_FILETYPE %x) filetype MC or bloc: %x", state, fileType);                 
                        autorun <= ioctl_dout;
                        state <= SM_AUTORUN;
                    end   
                end
                SM_AUTORUN: 
                begin
                    //$display( "(state SM_AUTORUN %x) ioctl_dout: %x", state, ioctl_dout);
                    if(autorun=='h00) begin
                        //$display( "(state SM_AUTORUN %x) autorun OFF: %x", state, autorun);    
                        endAddressHIGH <= ioctl_dout;
                        state <= SM_ENDADDRESSHIGH;                        
                    end                
                    else if(autorun=='hC7) begin
                        //$display( "(state SM_AUTORUN %x) autorun ON: %x", state, autorun);  
                        autostart <= 1'b1; 
                        endAddressHIGH <= ioctl_dout;
                        state <= SM_ENDADDRESSHIGH;
                    end
                end    
                SM_ENDADDRESSHIGH: 
                begin
                    //$display( "(state SM_ENDADDRESSHIGH %x) ioctl_dout: %x", state, ioctl_dout);
                    endAddressLOW <= ioctl_dout;  
                    state <= SM_ENDADDRESSLOW;                    
                    //$display( "(state SM_ENDADDRESSHIGH %x) endAddressHIGH: %x", state, endAddressHIGH);    
                end    
                SM_ENDADDRESSLOW: 
                begin
                    end_addr <= {endAddressHIGH, endAddressLOW};                      
                    //$display( "(state SM_ENDADDRESSLOW %x) ioctl_dout: %x", state, ioctl_dout);
                    startAddressHIGH <= ioctl_dout;
                    state <= SM_STARTADDRESSHIGH;                      
                    //$display( "(state SM_ENDADDRESSLOW %x) endAddressLOW: %x", state, endAddressLOW);    
                end  
                SM_STARTADDRESSHIGH: 
                begin
                  //  $display( "(state SM_STARTADDRESSHIGH %x) end_addr: %x", state, end_addr);                        
                    //$display( "(state SM_STARTADDRESSLOW %x) ioctl_dout: %x", state, ioctl_dout);
                    startAddressLOW <= ioctl_dout;
                    state <= SM_STARTADDRESSLOW;                        
                    //$display( "(state SM_STARTADDRESSHIGH %x) startAddressHIGH: %x", state, startAddressHIGH);    
                end      
                SM_STARTADDRESSLOW: 
                begin
                    start_addr <= {startAddressHIGH, startAddressLOW};   
                    //$display( "(state SM_STARTADDRESSLOW %x) ioctl_dout: %x", state, ioctl_dout);
                    unused <= ioctl_dout;
                    state <= SM_UNUSED;                    
                    //$display( "(state SM_STARTADDRESSLOW %x) startAddressLOW: %x", state, startAddressLOW);    
                end   
                SM_UNUSED:  
                begin
                    programlength <= (end_addr-start_addr);                     
                    if(ioctl_dout=='h00) begin
                        loadpoint <= start_addr;                   
                        state <= SM_PROGRAMCODE;
                    end
                 //   $display( "(state SM_UNUSED %x) start_addr: %x programlength %x", state, start_addr, programlength);                         
                    //$display( "(state SM_UNUSED %x) ioctl_dout: %x", state, ioctl_dout);
                    //$display( "(state SM_UNUSED %x) unused: %x", state, unused);    
                end                                                                         
                SM_PROGRAMCODE:
                begin
                    tape_wr <= 1'b1;	                     
                    tape_addr <= start_addr;
                    tape_dout <= ioctl_dout;
                    start_addr <= start_addr + 1;
                    //$display( "(state SM_PROGRAMCODE %x) programlength %x", state, programlength);                       
                  //  $display( "(state SM_PROGRAMCODE %x) ioctl_dout: %x ioctl_download %x ioctl_wr %x", state, ioctl_dout, ioctl_download, ioctl_wr);   
                  //  $display( "(state SM_PROGRAMCODE %x) tape_dout %x tape_addr %x", state, tape_dout, tape_addr);    
                    if(start_addr == (end_addr))
                    begin
                        tape_complete <= 1'b1;                          
                        $display( "(state SM_PROGRAMCODE %x) start_addr %x end_addr %x", state, start_addr, end_addr); 
                        state <= SM_INIT;                                                  
                    end                    
                end
            endcase
        end
    else if(tape_complete) begin
        if(tape_wr) begin
 		    tape_wr <= 1'b0;   
            tape_autorun <= 1'b1;       
            $display( "(state else if %x) tape_complete %x tape_wr %x", state, tape_complete, tape_wr);                    
        end
        else begin
            tape_autorun <= 1'b0;              
        end
    end
end
endmodule
