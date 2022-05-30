// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated_heavy.h"
#include "verilated_save.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_48,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_HB,0,0);
    VL_OUT8(VGA_VB,0,0);
    VL_IN8(ioctl_download,0,0);
    VL_IN8(ioctl_upload,0,0);
    VL_IN8(ioctl_wr,0,0);
    VL_IN8(ioctl_dout,7,0);
    VL_IN8(ioctl_din,7,0);
    VL_IN8(ioctl_index,7,0);
    VL_OUT8(ioctl_wait,0,0);
    VL_IN16(inputs,11,0);
    VL_OUT16(AUDIO_L,15,0);
    VL_OUT16(AUDIO_R,15,0);
    VL_IN(ioctl_addr,24,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__clk_48;
    CData/*0:0*/ top__DOT__reset;
    CData/*7:0*/ top__DOT__VGA_R;
    CData/*7:0*/ top__DOT__VGA_G;
    CData/*7:0*/ top__DOT__VGA_B;
    CData/*0:0*/ top__DOT__VGA_HS;
    CData/*0:0*/ top__DOT__VGA_VS;
    CData/*0:0*/ top__DOT__VGA_HB;
    CData/*0:0*/ top__DOT__VGA_VB;
    CData/*0:0*/ top__DOT__ioctl_download;
    CData/*0:0*/ top__DOT__ioctl_upload;
    CData/*0:0*/ top__DOT__ioctl_wr;
    CData/*7:0*/ top__DOT__ioctl_dout;
    CData/*7:0*/ top__DOT__ioctl_din;
    CData/*7:0*/ top__DOT__ioctl_index;
    CData/*0:0*/ top__DOT__ioctl_wait;
    CData/*0:0*/ top__DOT__ce_pix;
    CData/*7:0*/ top__DOT__ram_d;
    CData/*0:0*/ top__DOT__ram_we;
    CData/*0:0*/ top__DOT__ram_cs;
    CData/*7:0*/ top__DOT__ram_q;
    CData/*0:0*/ top__DOT__tape_wr;
    CData/*7:0*/ top__DOT__tape_dout;
    CData/*0:0*/ top__DOT__tape_complete;
    CData/*0:0*/ top__DOT__tape_autorun;
    CData/*0:0*/ top__DOT__tape__DOT__clk;
    CData/*7:0*/ top__DOT__tape__DOT__dout;
    CData/*0:0*/ top__DOT__tape__DOT__cs;
    CData/*0:0*/ top__DOT__tape__DOT__rom_init;
    CData/*0:0*/ top__DOT__tape__DOT__rom_init_clk;
    CData/*7:0*/ top__DOT__tape__DOT__rom_init_data;
    CData/*0:0*/ top__DOT__cassette__DOT__clk;
    CData/*0:0*/ top__DOT__cassette__DOT__ioctl_download;
    CData/*0:0*/ top__DOT__cassette__DOT__ioctl_wr;
    CData/*7:0*/ top__DOT__cassette__DOT__ioctl_dout;
    CData/*0:0*/ top__DOT__cassette__DOT__reset_n;
    CData/*0:0*/ top__DOT__cassette__DOT__autostart;
    CData/*0:0*/ top__DOT__cassette__DOT__tape_autorun;
    CData/*0:0*/ top__DOT__cassette__DOT__tape_wr;
    CData/*7:0*/ top__DOT__cassette__DOT__tape_dout;
    CData/*0:0*/ top__DOT__cassette__DOT__tape_complete;
    CData/*7:0*/ top__DOT__cassette__DOT__fileType;
    CData/*7:0*/ top__DOT__cassette__DOT__autorun;
    CData/*7:0*/ top__DOT__cassette__DOT__endAddressHIGH;
    CData/*7:0*/ top__DOT__cassette__DOT__endAddressLOW;
    CData/*7:0*/ top__DOT__cassette__DOT__startAddressHIGH;
    CData/*7:0*/ top__DOT__cassette__DOT__startAddressLOW;
    CData/*0:0*/ top__DOT__cassette__DOT__unused;
    SData/*11:0*/ top__DOT__inputs;
    SData/*15:0*/ top__DOT__AUDIO_L;
    SData/*15:0*/ top__DOT__AUDIO_R;
    SData/*15:0*/ top__DOT__ram_ad;
    SData/*15:0*/ top__DOT__tape_addr;
    SData/*15:0*/ top__DOT__tape__DOT__addr;
    SData/*15:0*/ top__DOT__tape__DOT__rom_init_address;
    SData/*15:0*/ top__DOT__cassette__DOT__loadpoint;
    SData/*15:0*/ top__DOT__cassette__DOT__tape_addr;
    SData/*15:0*/ top__DOT__cassette__DOT__programlength;
    SData/*15:0*/ top__DOT__cassette__DOT__start_addr;
    SData/*15:0*/ top__DOT__cassette__DOT__end_addr;
    SData/*15:0*/ top__DOT__cassette__DOT__state;
    IData/*24:0*/ top__DOT__ioctl_addr;
    IData/*16:0*/ top__DOT__clr_addr;
    IData/*24:0*/ top__DOT__cassette__DOT__ioctl_addr;
    VlUnpacked<CData/*7:0*/, 65536> top__DOT__ram;
    VlUnpacked<CData/*7:0*/, 65536> top__DOT__tape__DOT__memory;

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk_48;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table

    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    enum _IDatatop__DOT__cassette__DOT__SM_INIT { top__DOT__cassette__DOT__SM_INIT = 1U};
    static const IData var_top__DOT__cassette__DOT__SM_INIT;
    enum _IDatatop__DOT__cassette__DOT__SM_FILETYPE { top__DOT__cassette__DOT__SM_FILETYPE = 2U};
    static const IData var_top__DOT__cassette__DOT__SM_FILETYPE;
    enum _IDatatop__DOT__cassette__DOT__SM_AUTORUN { top__DOT__cassette__DOT__SM_AUTORUN = 3U};
    static const IData var_top__DOT__cassette__DOT__SM_AUTORUN;
    enum _IDatatop__DOT__cassette__DOT__SM_ENDADDRESSHIGH { top__DOT__cassette__DOT__SM_ENDADDRESSHIGH = 4U};
    static const IData var_top__DOT__cassette__DOT__SM_ENDADDRESSHIGH;
    enum _IDatatop__DOT__cassette__DOT__SM_ENDADDRESSLOW { top__DOT__cassette__DOT__SM_ENDADDRESSLOW = 5U};
    static const IData var_top__DOT__cassette__DOT__SM_ENDADDRESSLOW;
    enum _IDatatop__DOT__cassette__DOT__SM_STARTADDRESSHIGH { top__DOT__cassette__DOT__SM_STARTADDRESSHIGH = 6U};
    static const IData var_top__DOT__cassette__DOT__SM_STARTADDRESSHIGH;
    enum _IDatatop__DOT__cassette__DOT__SM_STARTADDRESSLOW { top__DOT__cassette__DOT__SM_STARTADDRESSLOW = 7U};
    static const IData var_top__DOT__cassette__DOT__SM_STARTADDRESSLOW;
    enum _IDatatop__DOT__cassette__DOT__SM_UNUSED { top__DOT__cassette__DOT__SM_UNUSED = 8U};
    static const IData var_top__DOT__cassette__DOT__SM_UNUSED;
    enum _IDatatop__DOT__cassette__DOT__SM_PROGRAMCODE { top__DOT__cassette__DOT__SM_PROGRAMCODE = 9U};
    static const IData var_top__DOT__cassette__DOT__SM_PROGRAMCODE;
    enum _IDatatop__DOT__cassette__DOT__SM_COMPLETED { top__DOT__cassette__DOT__SM_COMPLETED = 0xaU};
    static const IData var_top__DOT__cassette__DOT__SM_COMPLETED;

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(VerilatedContext* contextp, const char* name = "TOP");
    Vtop(const char* name = "TOP")
      : Vtop(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtop__Syms* __restrict vlSymsp);
  private:
    static void _ctor_var_reset(Vtop* self) VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
  public:
    void __Vserialize(VerilatedSerialize& os);
    void __Vdeserialize(VerilatedDeserialize& os);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


inline VerilatedSerialize& operator<<(VerilatedSerialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vserialize(os); return os; }
inline VerilatedDeserialize& operator>>(VerilatedDeserialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vdeserialize(os); return os; }

#endif  // guard
