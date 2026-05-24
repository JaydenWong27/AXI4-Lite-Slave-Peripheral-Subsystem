// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAXI_LITE_TB__SYMS_H_
#define VERILATED_VAXI_LITE_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vaxi_lite_tb.h"

// INCLUDE MODULE CLASSES
#include "Vaxi_lite_tb___024root.h"
#include "Vaxi_lite_tb_axi_lite_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vaxi_lite_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vaxi_lite_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vaxi_lite_tb___024root         TOP;
    Vaxi_lite_tb_axi_lite_if       TOP__axi_lite_tb__DOT__bus;

    // CONSTRUCTORS
    Vaxi_lite_tb__Syms(VerilatedContext* contextp, const char* namep, Vaxi_lite_tb* modelp);
    ~Vaxi_lite_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
