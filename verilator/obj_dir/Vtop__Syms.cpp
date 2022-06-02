// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop___024unit.h"


void Vtop__Syms::__Vserialize(VerilatedSerialize& os) {
    // LOCAL STATE
    os<<__Vm_activity;
    os<<__Vm_didInit;
    // SUBCELL STATE
    TOP____024unit.__Vserialize(os);
}
void Vtop__Syms::__Vdeserialize(VerilatedDeserialize& os) {
    // LOCAL STATE
    os>>__Vm_activity;
    os>>__Vm_didInit;
    // SUBCELL STATE
    TOP____024unit.__Vdeserialize(os);
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
    , TOP____024unit(Verilated::catName(topp->name(), "$unit"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP____024unit.__Vconfigure(this, true);
}
