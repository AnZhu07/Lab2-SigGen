// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vram.h"
#include "Vram__Syms.h"

//============================================================
// Constructors

Vram::Vram(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vram__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , wr_en{vlSymsp->TOP.wr_en}
    , rd_en{vlSymsp->TOP.rd_en}
    , din{vlSymsp->TOP.din}
    , doutDelayed{vlSymsp->TOP.doutDelayed}
    , wr_addr{vlSymsp->TOP.wr_addr}
    , rd_addr{vlSymsp->TOP.rd_addr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vram::Vram(const char* _vcname__)
    : Vram(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vram::~Vram() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vram___024root___eval_initial(Vram___024root* vlSelf);
void Vram___024root___eval_settle(Vram___024root* vlSelf);
void Vram___024root___eval(Vram___024root* vlSelf);
#ifdef VL_DEBUG
void Vram___024root___eval_debug_assertions(Vram___024root* vlSelf);
#endif  // VL_DEBUG
void Vram___024root___final(Vram___024root* vlSelf);

static void _eval_initial_loop(Vram__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vram___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vram___024root___eval_settle(&(vlSymsp->TOP));
        Vram___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vram::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vram::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vram___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vram___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vram::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vram::final() {
    Vram___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vram::hierName() const { return vlSymsp->name(); }
const char* Vram::modelName() const { return "Vram"; }
unsigned Vram::threads() const { return 1; }
