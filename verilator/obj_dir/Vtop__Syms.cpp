// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"


void Vtop__Syms::__Vserialize(VerilatedSerialize& os) {
    // LOCAL STATE
    os<<__Vm_activity;
    os<<__Vm_didInit;
    // SUBCELL STATE
}
void Vtop__Syms::__Vdeserialize(VerilatedDeserialize& os) {
    // LOCAL STATE
    os>>__Vm_activity;
    os>>__Vm_didInit;
    // SUBCELL STATE
}


// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, Vtop* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
