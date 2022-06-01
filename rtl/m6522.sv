//
// A simulation model of VIC20 hardware - VIA implementation
// Copyright (c) MikeJ - March 2003
//
// All rights reserved
//
// Redistribution and use in source and synthezised forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// Redistributions in synthesized form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// Neither the name of the author nor the names of other contributors may
// be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS CODE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// You are responsible for any legal issues arising from your use of this code.
//
// The latest version of this file can be found at: www.fpgaarcade.com
//
// Email vic20@fpgaarcade.com
//
//
// Revision list
//
//        dmb: ier bit 7 should read back as '1'
//        dmb: Fixes to sr_do_shift change that broke MMFS on the Beeb (SR mode 0)
// version 006 Tweak to p_timer2_ena to fix clocking issue
// version 005 Many fixes to all areas, VIA now passes all VICE tests
// version 004 fixes to PB7 T1 control and Mode 0 Shift Register operation
// version 003 fix reset of T1/T2 IFR flags if T1/T2 is reload via reg5/reg9 from wolfgang (WoS)
//             Ported to numeric_std and simulation fix for signal initializations from arnim laeuger
// version 002 fix from Mark McDougall, untested
// version 001 initial release
// not very sure about the shift register, documentation is a bit light.
// SystemVerilog conversion Copyright 2022 Frank Bruno

module M6522
  (
   input wire [3:0]   I_RS,
   input wire [7:0]   I_DATA,
   output logic [7:0] O_DATA,
   output logic       O_DATA_OE_L,

   input wire         I_RW_L,
   input wire         I_CS1,
   input wire         I_CS2_L,

   output logic       O_IRQ_L, // note, not open drain

   // port a
   input wire         I_CA1,
   input wire         I_CA2,
   output logic       O_CA2,
   output logic       O_CA2_OE_L,

   input wire [7:0]   I_PA,
   output logic [7:0] O_PA,
   output logic [7:0] O_PA_OE_L,

   // port b
   input wire         I_CB1,
   output logic       O_CB1,
   output logic       O_CB1_OE_L,

   input wire         I_CB2,
   output logic       O_CB2,
   output logic       O_CB2_OE_L,

   input wire [7:0]   I_PB,
   output logic [7:0] O_PB,
   output logic [7:0] O_PB_OE_L,

   input wire         I_P2_H, // high for phase 2 clock  ____----__
   input wire         RESET_L,
   input wire         ENA_4, // clk enable
   input wire         CLK
   );

  logic [1:0]         phase = '0;
  logic               p2_h_t1 = '0;
  logic               p2_h_dl; // 1 clock delay, no enable
  logic               cs;

  // registers
  logic [7:0]         r_ddra;
  logic [7:0]         r_ora;
  logic [7:0]         r_ira;

  logic [7:0]         r_ddrb;
  logic [7:0]         r_orb;
  logic [7:0]         r_irb;

  logic [7:0]         r_t1l_l;
  logic [7:0]         r_t1l_h;
  logic [7:0]         r_t2l_l;
  logic [7:0]         r_t2l_h; // not in real chip
  logic [7:0]         r_sr;
  logic [7:0]         r_acr;
  logic [7:0]         r_pcr;
  logic [7:0]         r_ifr;
  logic [6:0]         r_ier;

  logic               sr_write_ena;
  logic               sr_read_ena;
  logic               ifr_write_ena;
  logic               ier_write_ena;
  logic [7:0]         clear_irq;
  logic [7:0]         load_data;

   // timer 1
  logic [15:0]        t1c = '1; // simulators may not catch up w/o init here...
  logic               t1c_active;
  logic               t1c_done;
  logic               t1_w_reset_int;
  logic               t1_r_reset_int;
  logic               t1_load_counter;
  logic               t1_reload_counter;
  logic               t1_int_enable = '0;
  logic               t1_toggle;
  logic               t1_irq = '0;
  logic               t1_pb7 = '1;
  logic               t1_pb7_en_c;
  logic               t1_pb7_en_d;

  // timer 2
  logic [15:0]        t2c = '1; // simulators may not catch up w/o init here...
  logic               t2c_active;
  logic               t2c_done;
  logic               t2_pb6;
  logic               t2_pb6_t1;
  logic               t2_cnt_clk = '1;
  logic               t2_w_reset_int;
  logic               t2_r_reset_int;
  logic               t2_load_counter;
  logic               t2_reload_counter;
  logic               t2_int_enable = '0;
  logic               t2_irq = '0;
  logic               t2_sr_ena;

   // shift reg
  logic [3:0]         sr_cnt;
  logic               sr_cb1_oe_l;
  logic               sr_cb1_out;
  logic               sr_drive_cb2;
  logic               sr_strobe;
  logic               sr_do_shift = '0;
  logic               sr_strobe_t1;
  logic               sr_strobe_falling;
  logic               sr_strobe_rising;
  logic               sr_irq;
  logic               sr_out;
  logic               sr_active;

   // io
  logic               w_orb_hs;
  logic               w_ora_hs;
  logic               r_irb_hs;
  logic               r_ira_hs;

  logic               ca_hs_sr;
  logic               ca_hs_pulse;
  logic               cb_hs_sr;
  logic               cb_hs_pulse;

  logic               cb1_in_mux;
  logic               ca1_ip_reg_c;
  logic               ca1_ip_reg_d;
  logic               cb1_ip_reg_c;
  logic               cb1_ip_reg_d;
  logic               ca1_int;
  logic               cb1_int;
  logic               ca1_irq;
  logic               cb1_irq;

  logic               ca2_ip_reg_c;
  logic               ca2_ip_reg_d;
  logic               cb2_ip_reg_c;
  logic               cb2_ip_reg_d;
  logic               ca2_int;
  logic               cb2_int;
  logic               ca2_irq;
  logic               cb2_irq;

  logic               final_irq;

  always_ff @(posedge CLK) begin : p_phase
    // internal clock phase
    if (ENA_4) begin
      p2_h_t1 <= I_P2_H;
      if (~p2_h_t1 && I_P2_H) begin
        phase <= '1;
      end else begin
        phase <= phase + 1'b1;
      end
    end
  end // block: p_phase

  always_comb begin : p_cs
    cs = '0;
    if (I_CS1 && ~I_CS2_L && I_P2_H) begin
      cs <= '1;
    end
  end

  // peripheral control reg (pcr)
  // 0      ca1 interrupt control (0 +ve edge, 1 -ve edge)
  // 3..1   ca2 operation
  //        000 input -ve edge
  //        001 independend interrupt input -ve edge
  //        010 input +ve edge
  //        011 independend interrupt input +ve edge
  //        100 handshake output
  //        101 pulse output
  //        110 low output
  //        111 high output
  // 7..4   as 3..0 for cb1,cb2

  // auxiliary control reg (acr)
  // 0      input latch PA (0 disable, 1 enable)
  // 1      input latch PB (0 disable, 1 enable)
  // 4..2   shift reg control
  //        000 disable
  //        001 shift in using t2
  //        010 shift in using o2
  //        011 shift in using ext clk
  //        100 shift out free running t2 rate
  //        101 shift out using t2
  //        101 shift out using o2
  //        101 shift out using ext clk
  // 5      t2 timer control (0 timed interrupt, 1 count down with pulses on pb6)
  // 7..6   t1 timer control
  //        00 timed interrupt each time t1 is loaded   pb7 disable
  //        01 continuous interrupts                    pb7 disable
  //        00 timed interrupt each time t1 is loaded   pb7 one shot output
  //        01 continuous interrupts                    pb7 square wave output
  //

  always_ff @(posedge CLK, negedge RESET_L) begin : p_write_reg_reset
    if (~RESET_L) begin
      r_ora   <= '0;
      r_orb   <= '0;
      r_ddra  <= '0;
      r_ddrb  <= '0;
      r_acr   <= '0;
      r_pcr   <= '0;

      w_orb_hs <= '0;
      w_ora_hs <= '0;
    end else begin
      if (ENA_4) begin
        w_orb_hs <= '0;
        w_ora_hs <= '0;
        if (cs && ~I_RW_L) begin
          case (I_RS)
            4'h0: begin
              r_orb        <= I_DATA;
              w_orb_hs     <= '1;
            end
            4'h1: begin
              r_ora        <= I_DATA;
              w_ora_hs     <= '1;
            end
            4'h2: r_ddrb <= I_DATA;
            4'h3: r_ddra <= I_DATA;

            4'hB: r_acr  <= I_DATA;
            4'hC: r_pcr  <= I_DATA;
            4'hF: r_ora  <= I_DATA;
          endcase
        end

        // Set timer PB7 state, only on rising edge of setting ACR(7)
        if (~t1_pb7_en_d && t1_pb7_en_c) t1_pb7 <= '1;

        if (t1_load_counter)
          t1_pb7 <= '0; // Reset internal timer 1 PB7 state on every timer load
        else if (t1_toggle)
          t1_pb7 <= ~t1_pb7;
      end // if (ENA_4)
    end // else: !if(~RESET_L)
  end // block: p_write_reg_reset

  always_ff @(posedge CLK, negedge RESET_L) begin : p_write_reg
    if (~RESET_L) begin
      // The spec says, this is not reset.
      // Fact is that the 1541 VIA1 timer won't work,
      // as the firmware ONLY sets the r_t1l_h latch!!!!
      r_t1l_l   <= '1; // All latches default to FFFF
      r_t1l_h   <= '1;
      r_t2l_l   <= '1;
      r_t2l_h   <= '1;
    end else begin
      if (ENA_4) begin
        t1_w_reset_int  <= '0;
        t1_load_counter <= '0;

        t2_w_reset_int  <= '0;
        t2_load_counter <= '0;

        load_data       <= '0;
        sr_write_ena    <= '0;
        ifr_write_ena   <= '0;
        ier_write_ena   <= '0;

        if (cs && ~I_RW_L) begin
          load_data <= I_DATA;
          case (I_RS)
            4'h4: r_t1l_l   <= I_DATA;
            4'h5: begin
              r_t1l_h   <= I_DATA;
              t1_w_reset_int  <= '1;
              t1_load_counter <= '1;
            end
            4'h6: r_t1l_l   <= I_DATA;
            4'h7: begin
              r_t1l_h   <= I_DATA;
              t1_w_reset_int  <= '1;
            end
            4'h8: r_t2l_l   <= I_DATA;
            4'h9: begin
              r_t2l_h         <= I_DATA;
              t2_w_reset_int  <= '1;
              t2_load_counter <= '1;
            end
            4'hA: sr_write_ena    <= '1;
            4'hD: ifr_write_ena   <= '1;
            4'hE: ier_write_ena   <= '1;
          endcase
        end // if (cs && ~I_RW_L)
      end // if (ENA_4)
    end // else: !if(~RESET_L)
  end // block: p_write_reg

  always_comb begin : p_oe
      O_DATA_OE_L = '1;
      if (cs  && I_RW_L) O_DATA_OE_L = '0;
  end

  logic [7:0] orb;
  always_comb begin : p_read
    t1_r_reset_int = '0;
    t2_r_reset_int = '0;
    sr_read_ena    = '0;
    r_irb_hs       = '0;
    r_ira_hs       = '0;
    O_DATA         = '0; // default
    orb            = (r_irb & ~r_ddrb) | (r_orb & r_ddrb);

    // If PB7 under timer control, assign value from timer
    if (t1_pb7_en_d) orb[7] = t1_pb7;

    if (cs && I_RW_L) begin
      case (I_RS)
        4'h0: begin
          O_DATA             = orb;
          r_irb_hs           = '1;
        end
        4'h1: begin
          O_DATA        = (r_ira & ~r_ddra) | (r_ora & r_ddra);
          r_ira_hs      = '1;
        end
        4'h2: O_DATA = r_ddrb;
        4'h3: O_DATA = r_ddra;
        4'h4: begin
          O_DATA          = t1c[7:0];
          t1_r_reset_int  = '1;
        end
        4'h5: O_DATA    = t1c[15:8];
        4'h6: O_DATA    = r_t1l_l;
        4'h7: O_DATA    = r_t1l_h;
        4'h8: begin
          O_DATA          = t2c[7:0];
          t2_r_reset_int  = '1;
        end
        4'h9: O_DATA    = t2c[15:8];
        4'hA: begin
          O_DATA       = r_sr;
          sr_read_ena  = '1;
        end
        4'hB: O_DATA = r_acr;
        4'hC: O_DATA = r_pcr;
        4'hD: O_DATA = r_ifr;
        // DMB: ier bit 7 should read back as '1
        4'hE: O_DATA = {1'b1, r_ier};
        4'hF: O_DATA = r_ira;
      endcase // case (I_RS)
    end // if (cs && I_RW_L)
  end // block: p_read

  //
  // IO
  //
  always_comb begin : p_ca1_cb1_sel
    // if the shift register is enabled, cb1 may be an output
    // in this case we should NOT listen to the input as
    // CB1 interrupts are not generated by the shift register
    if (sr_cb1_oe_l) cb1_in_mux = I_CB1;
    else             cb1_in_mux = '1;
  end

  always_comb begin : p_ca1_cb1_int
    if (~r_pcr[0]) begin // ca1 control
      // negative edge
      ca1_int = ca1_ip_reg_d & ~ca1_ip_reg_c;
    end else begin
      // positive edge
      ca1_int = ~ca1_ip_reg_d & ca1_ip_reg_c;
    end

    if (~r_pcr[4]) begin // cb1 control
      // negative edge
      cb1_int =  cb1_ip_reg_d & ~cb1_ip_reg_c;
    end else begin
      // positive edge
      cb1_int = ~cb1_ip_reg_d &  cb1_ip_reg_c;
    end
  end // block: p_ca1_cb1_int

  always_comb begin : p_ca2_cb2_int
    ca2_int = '0;
    if (~r_pcr[3]) begin // ca2 input
      if (~r_pcr[2]) begin // ca2 edge
        // negative edge
        ca2_int =  ca2_ip_reg_d & ~ca2_ip_reg_c;
      end else begin
        // positive edge
        ca2_int = ~ca2_ip_reg_d &  ca2_ip_reg_c;
      end
    end

    cb2_int = '0;
    if (~r_pcr[7]) begin // cb2 input
      if (~r_pcr[6]) begin // cb2 edge
        // negative edge
        cb2_int =  cb2_ip_reg_d & ~cb2_ip_reg_c;
      end else begin
        // positive edge
        cb2_int = ~cb2_ip_reg_d &  cb2_ip_reg_c;
      end
    end
  end // block: p_ca2_cb2_int

  always_ff @(posedge CLK, negedge RESET_L) begin : p_ca2_cb2
    if (~RESET_L) begin
      O_CA2       <= '1; // Pullup is default
      O_CA2_OE_L  <= '1;
      O_CB2       <= '1; // Pullup is default
      O_CB2_OE_L  <= '1;

      ca_hs_sr    <= '0;
      ca_hs_pulse <= '0;
      cb_hs_sr    <= '0;
      cb_hs_pulse <= '0;
    end else begin
      if (ENA_4) begin
        // ca
        if (~|phase && (w_ora_hs || r_ira_hs)) begin
          ca_hs_sr <= '1;
        end else if (ca1_int) begin
          ca_hs_sr <= '0;
        end;

        if (~|phase) ca_hs_pulse <= w_ora_hs | r_ira_hs;

        O_CA2_OE_L <= ~r_pcr[3]; // ca2 output

        case (r_pcr[3:1])
          3'b000: O_CA2 <= I_CA2; // input, output follows input
          3'b001: O_CA2 <= I_CA2; // input, output follows input
          3'b010: O_CA2 <= I_CA2; // input, output follows input
          3'b011: O_CA2 <= I_CA2; // input, output follows input
          3'b100: O_CA2 <= ~(ca_hs_sr); // handshake
          3'b101: O_CA2 <= ~(ca_hs_pulse); // pulse
          3'b110: O_CA2 <= '0; // low
          3'b111: O_CA2 <= '1; // high
        endcase

        // cb
        if (~|phase && w_orb_hs) cb_hs_sr <= '1;
        else if (cb1_int)        cb_hs_sr <= '0;

        if (~|phase)             cb_hs_pulse <= w_orb_hs;

        O_CB2_OE_L <= ~(r_pcr[7] | sr_drive_cb2); // cb2 output or serial

        if (sr_drive_cb2) // serial output
          O_CB2 <= sr_out;
        else
          case (r_pcr[7:5])
            3'b000: O_CB2 <= I_CB2; // input, output follows input
            3'b001: O_CB2 <= I_CB2; // input, output follows input
            3'b010: O_CB2 <= I_CB2; // input, output follows input
            3'b011: O_CB2 <= I_CB2; // input, output follows input
            3'b100: O_CB2 <= ~(cb_hs_sr); // handshake
            3'b101: O_CB2 <= ~(cb_hs_pulse); // pulse
            3'b110: O_CB2 <= '0; // low
            3'b111: O_CB2 <= '1; // high
          endcase // case (r_pcr[7:5])
      end // if (ENA_4)
    end // else: !if(~RESET_L)
  end // block: p_ca2_cb2

  assign O_CB1      = sr_cb1_out;
  assign O_CB1_OE_L = sr_cb1_oe_l;

  always_ff @(posedge CLK, negedge RESET_L) begin : p_ca_cb_irq
    if (~RESET_L) begin
      ca1_irq <= '0;
      ca2_irq <= '0;
      cb1_irq <= '0;
      cb2_irq <= '0;
    end else begin
      if (ENA_4) begin
        // not pretty
        if (ca1_int)
          ca1_irq <= '1;
        else if (r_ira_hs || w_ora_hs || clear_irq[1])
          ca1_irq <= '0;

        if (ca2_int)
          ca2_irq <= '1;
        else if (((r_ira_hs || w_ora_hs) && ~r_pcr[1]) || clear_irq[0])
          ca2_irq <= '0;

        if (cb1_int)
          cb1_irq <= '1;
        else if (r_irb_hs || w_orb_hs || clear_irq[4])
          cb1_irq <= '0;

        if (cb2_int)
          cb2_irq <= '1;
        else if (((r_irb_hs || w_orb_hs) && ~r_pcr[5]) || clear_irq[3])
          cb2_irq <= '0;
      end // if (ENA_4)
    end // else: !if(~RESET_L)
  end // block: p_ca_cb_irq

  always_ff @(posedge CLK, negedge RESET_L) begin : p_input_reg
    if (~RESET_L) begin
      ca1_ip_reg_c <= '0;
      ca1_ip_reg_d <= '0;

      cb1_ip_reg_c <= '0;
      cb1_ip_reg_d <= '0;

      ca2_ip_reg_c <= '0;
      ca2_ip_reg_d <= '0;

      cb2_ip_reg_c <= '0;
      cb2_ip_reg_d <= '0;

      r_ira        <= '0;
      r_irb        <= '0;

    end else if (ENA_4) begin
      // we have a fast clock, so we can have input registers
      ca1_ip_reg_c <= I_CA1;
      ca1_ip_reg_d <= ca1_ip_reg_c;

      cb1_ip_reg_c <= cb1_in_mux;
      cb1_ip_reg_d <= cb1_ip_reg_c;

      ca2_ip_reg_c <= I_CA2;
      ca2_ip_reg_d <= ca2_ip_reg_c;

      cb2_ip_reg_c <= I_CB2;
      cb2_ip_reg_d <= cb2_ip_reg_c;

      if (~r_acr[0]) begin
        r_ira <= I_PA;
      end else begin // enable latching
        if (ca1_int) r_ira <= I_PA;
      end

      if (~r_acr[1]) begin
        r_irb <= I_PB;
      end else begin // enable latching
        if (cb1_int) r_irb <= I_PB;
      end
    end // if (ENA_4)
  end // block: p_input_reg

  always_comb begin : p_buffers
    // data direction reg (ddr) 0 = input, 1 = output
    O_PA      = r_ora;
    O_PA_OE_L = ~r_ddra;

    // If PB7 is timer driven output set PB7 to the timer state,
    // otherwise use value in ORB register
    if (t1_pb7_en_d) O_PB = {t1_pb7, r_orb[6:0]};
    else             O_PB = r_orb;

    // NOTE: r_ddrb(7) must be set to enable T1 output on PB7 -
    //       [various datasheets specify this]
    O_PB_OE_L = ~r_ddrb;
  end // block: p_buffers

  //
  // Timer 1
  //

  // Detect change in r_acr(7), timer 1 mode for PB7
  always_ff @(posedge CLK) begin: p_pb7_enable
    if (ENA_4) begin
      t1_pb7_en_c <= r_acr[7];
      t1_pb7_en_d <= t1_pb7_en_c;
    end
  end

  always_ff @(posedge CLK) begin: p_timer1_done
    logic done;
    if (ENA_4) begin
      done = ~|t1c;
      t1c_done <= done & (&phase);
      if (&phase && ~t1_load_counter) begin // Don't set reload if T1L-H written
        t1_reload_counter <= done;
      end else if (t1_load_counter) begin  // Cancel a reload when T1L-H written
        t1_reload_counter <= '0;
      end
      if (t1_load_counter) begin // done reset on load!
        t1c_done <= '0;
      end
    end // if (ENA_4)
  end // block: p_timer1_done

  always_ff @(posedge CLK) begin: p_timer1
    if (ENA_4) begin
      if (t1_load_counter || (t1_reload_counter && (&phase))) begin
        t1c[7:0]  <= r_t1l_l;
        t1c[15:8] <= r_t1l_h;
        // There is a need to write to Latch HI to enable interrupts for both continuous and one-shot modes
        if (t1_load_counter) t1_int_enable <= '1;
      end else if (&phase) begin
        t1c <= t1c - 1'b1;
      end

      if (t1_load_counter || t1_reload_counter) begin
        t1c_active <= '1;
      end else if (t1c_done) begin
        t1c_active <= '0;
      end

      t1_toggle <= '0;
      if (t1c_active && t1c_done) begin
        if (t1_int_enable) begin // Set interrupt only if T1L-H has been written
          t1_toggle <= '1;
          t1_irq    <= '1;
          if (~r_acr[6]) // Disable further interrupts if in one shot mode
            t1_int_enable <= '0;
        end
      end else if (t1_w_reset_int || t1_r_reset_int || clear_irq[6]) begin
        t1_irq <= '0;
      end
      if (t1_load_counter) // irq reset on load!
        t1_irq <= '0;
    end // if (ENA_4)
  end // block: p_timer1

  //
  // Timer2
  //
  always_ff @(posedge CLK) begin: p_timer2_pb6_input
    if (ENA_4) begin
      if (phase == 2'b01) begin // leading edge p2_h
        t2_pb6    <= I_PB[6];
        t2_pb6_t1 <= t2_pb6;
      end
    end
  end

  // Ensure we don't start counting until the P2 clock after r_acr is changed
  always_ff @(posedge CLK) begin: p_timer2_ena
    p2_h_dl <= I_P2_H;
    if (I_P2_H && ~p2_h_dl) begin
      if (~r_acr[5]) t2_cnt_clk <= '1;
      else           t2_cnt_clk <= '0;
    end
  end

  always_ff @(posedge CLK) begin: p_timer2_done
    logic done;
    logic done_sr;
    if (ENA_4) begin
      done    = (~|t2c);     // Normal timer expires at 0000
      done_sr = ~|t2c[7:0];  // Shift register expires on low byte = 00
      t2c_done <= done & (&phase);
      if (&phase) begin
        t2_reload_counter <= done_sr;        // Timer 2 is only reloaded when used for the shift register
      end
      if (t2_load_counter) begin // done reset on load!
        t2c_done <= '0;
      end
    end // if (ENA_4)
  end // block: p_timer2_done

  always_ff @(posedge CLK) begin: p_timer2
    logic ena;
    if (ENA_4) begin
      if (t2_cnt_clk) begin
        ena            = '1;
        t2c_active    <= '1;
        t2_int_enable <= '1;
      end else
        ena = t2_pb6_t1 & ~t2_pb6; // falling edge

      // Shift register reload is only active when shift register mode using T2 is enabled
      if (t2_reload_counter && (&phase) &&
          ((r_acr[4:2] == 3'b001) || (r_acr[4:2] == 3'b100) ||
           (r_acr[4:2] == 3'b101)))  begin
        t2c[7:0] <= r_t2l_l; // For shift register only low latch is loaded!
      end else if (t2_load_counter) begin
        t2_int_enable <= '1;
        t2c[7:0]      <= r_t2l_l;
        t2c[15:8]     <= r_t2l_h;
      end else begin
        if (&phase && ena) begin // or count mode
          t2c <= t2c - 1'b1;
        end
      end

      // Shift register strobe on T2 occurs one P2H clock after timer expires
      // so enable the strobe when we roll over to FF
      t2_sr_ena <= (&t2c[7:0] && (&phase));

      if (t2_load_counter) t2c_active <= '1;
      else if (t2c_done)   t2c_active <= '0;

      if (t2c_active && t2c_done && t2_int_enable) begin
        t2_int_enable <= '0;
        t2_irq        <= '1;
      end else if (t2_w_reset_int || t2_r_reset_int || clear_irq[5]) begin
        t2_irq <= '0;
      end
      if (t2_load_counter) // irq reset on load!
        t2_irq <= '0;
    end // if (ENA_4)
  end // block: p_timer2

  //
  // Shift Register
  //
  always_ff @(posedge CLK, negedge RESET_L) begin : p_sr
    logic dir_out;
    logic ena;
    logic cb1_op;
    logic cb1_ip;
    logic use_t2;
    logic free_run;
    logic sr_count_ena;
    if (~RESET_L) begin
      r_sr         <= '0;
      sr_drive_cb2 <= '0;
      sr_cb1_oe_l  <= '1;
      sr_cb1_out   <= '0;
      sr_do_shift  <= '0;
      sr_strobe    <= '1;
      sr_cnt       <= '0;
      sr_irq       <= '0;
      sr_out       <= '0;
      sr_active    <= '0;
    end else if (ENA_4) begin
      // decode mode
      dir_out  = r_acr[4]; // output on cb2
      cb1_op   = '0;
      cb1_ip   = '0;
      use_t2   = '0;
      free_run = '0;

      // DMB: SR still runs even in disabled mode (on rising edge of CB1).
      // It just doesn't generate any interrupts.
      // Ref BBC micro advanced user guide p409

      case (r_acr[4:2])
        // DMB: in disabled mode, configure cb1 as an input
        3'b000: begin // 0x00 Mode 0 SR disabled
          ena    = '0;
          cb1_ip = '1;
        end
        3'b001: begin // 0x04 Mode 1 Shift in under T2 control
          ena    = '1;
          cb1_op = '1;
          use_t2 = '1;
        end
        3'b010: begin // 0x08 Mode 2 Shift in under P2 control
          ena    = '1;
          cb1_op = '1;
        end
        3'b011: begin // 0x0C Mode 3 Shift in under control of ext clock
          ena    = '1;
          cb1_ip = '1;
        end
        3'b100: begin // 0x10 Mode 4 Shift out free running under T2 control
          ena      = '1;
          cb1_op   = '1;
          use_t2   = '1;
          free_run = '1;
        end
        3'b101: begin // 0x14 Mode 5 Shift out under T2 control
          ena    = '1;
          cb1_op = '1;
          use_t2 = '1;
        end
        3'b110: begin // 0x18 Mode 6 Shift out under P2 control
          ena = '1;
          cb1_op = '1;
        end
        3'b111: begin // 0x1C Mode 7 Shift out under control of ext clock
          ena = '1;
          cb1_ip = '1;
        end
      endcase

      // clock select
      // DMB: in disabled mode, strobe from cb1
      if (cb1_ip)
        sr_strobe <= I_CB1;
      else if (~sr_cnt[3] && ~free_run)
        sr_strobe <= '1;
      else if ((use_t2 && t2_sr_ena) || (~use_t2 && ~|phase))
        sr_strobe <= ~sr_strobe;

      // latch on rising edge, shift on falling edge of P2
      if (sr_write_ena) begin
        r_sr   <= load_data;
        sr_out <= r_sr[7];
      end else begin
        // DMB: allow shifting in all modes
        if (~dir_out) begin
          // input
          if (sr_cnt[3] || cb1_ip) begin
            if (sr_strobe_rising) begin
              sr_do_shift <= '1;
              r_sr[0]     <= I_CB2;
              // DMB: Added sr_stroble_falling to avoid premature shift
              // (fixes issue with MMFS on the Beeb in SR mode 0)
            end else if (sr_do_shift && sr_strobe_falling) begin
              sr_do_shift <= '0;
              r_sr[7:1]   <= r_sr[6:0];
            end
          end
        end else begin
          // output
          if (sr_cnt[3]  || cb1_ip || free_run) begin
            if (sr_strobe_falling) begin
              sr_out      <= r_sr[7];
              sr_do_shift <= '1;
              // DMB: Added sr_stroble_falling to avoid premature shift
              // (fixes issue with MMFS on the Beeb in SR mode 0)
            end else if (sr_do_shift && sr_strobe_rising) begin
              sr_do_shift <= '0;
              r_sr        <= {r_sr[6:0], r_sr[7]};
            end
          end // if (sr_cnt[3]  || cb1_ip || free_run)
        end // else: !if(~dir_out)

        // Set shift enabled flag, note does not get set for free_run mode !
        if (ena && sr_cnt[3])
          sr_active <= '1;
        else if (ena && ~sr_cnt[3] && (&phase))
          sr_active <= '0;

        sr_count_ena = sr_strobe_rising;

        // DMB: reseting sr_count when not enabled cause the sr to
        // start running immediately it was enabled, which is incorrect
        // and broke the latest SmartSPI ROM on the BBC Micro
        if (ena && (sr_write_ena || sr_read_ena) && ~sr_active)
          // some documentation says sr bit in IFR must be set as well ?
          sr_cnt <= 4'b1000;
        else if (sr_count_ena && sr_cnt[3])
          sr_cnt <= sr_cnt + 1'b1;

        if (sr_count_ena && (&sr_cnt) && ena && ~free_run)
          sr_irq <= '1;
        else if (sr_write_ena || sr_read_ena || clear_irq[2])
          sr_irq <= '0;

        // assign ops
        sr_drive_cb2 <= dir_out;
        sr_cb1_oe_l  <= ~cb1_op;
        sr_cb1_out   <= sr_strobe;
      end // else: !if(sr_write_ena)
    end // if (ENA_4)
  end // block: p_sr

  always_ff @(posedge CLK) begin : p_sr_strobe_rise_fall
    if (ENA_4) begin
      sr_strobe_t1      <=  sr_strobe;
      sr_strobe_rising  <= ~sr_strobe_t1 &  sr_strobe;
      sr_strobe_falling <=  sr_strobe_t1 & ~sr_strobe;
    end
  end

  //
  // Interrupts
  //
  always_ff @(posedge CLK, negedge RESET_L) begin : p_ier
    if (~RESET_L) begin
      r_ier <= '0;
    end else if (ENA_4) begin
      if (ier_write_ena) begin
        if (load_data[7]) begin
          // set
          r_ier <= r_ier | load_data[6:0];
        end else begin
          // clear
          r_ier <= r_ier & ~load_data[6:0];
        end
      end
    end // if (ENA_4)
  end // block: p_ier

  always_comb begin : p_ifr
    r_ifr[7] = final_irq;
    r_ifr[6] = t1_irq;
    r_ifr[5] = t2_irq;
    r_ifr[4] = cb1_irq;
    r_ifr[3] = cb2_irq;
    r_ifr[2] = sr_irq;
    r_ifr[1] = ca1_irq;
    r_ifr[0] = ca2_irq;
    O_IRQ_L  = ~final_irq;
  end // always_comb

  always_ff @(posedge CLK, negedge RESET_L) begin : p_irq
    if (~RESET_L) begin
      final_irq <= '0;
    end else if (ENA_4) begin
      if (~|(r_ifr[6:0] & r_ier[6:0])) begin
        final_irq <= '0; // no interrupts
      end else begin
        final_irq <= '1;
      end
    end
  end // block: p_irq

  always_comb begin : p_clear_irq
    clear_irq = '0;
    if (ifr_write_ena) clear_irq = load_data;
  end
endmodule // M6522
