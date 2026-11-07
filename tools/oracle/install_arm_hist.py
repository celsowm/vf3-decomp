"""Install the window-gated per-instruction ARM observer in the ignored x64
research emulator (source tree tools/emu/flycast, built by flycast-ref-build).

Adds, on top of the memory-access observer (vf3armtrace.cpp/h):
  - a per-instruction execution histogram, emitted in the recompiler's
    compile loop, incremented only when vf3ArmWinActive is set (which the
    memory path maintains from the scheduler cycle window VF3_ARM_WIN);
  - a headless self-stop: once the scheduler passes the window (plus margin)
    the process exits so the histogram is dumped to VF3_ARM_HIST at finish().

A run is:
  VF3_ARM_HIST=<out.hist> VF3_ARM_WIN=<ws>,<we> flycast-ref-build/flycast_v3.exe ...
No memory trace (VF3_ARM_TRACE) is required for the histogram.
"""
from pathlib import Path
import shutil
from install import CORE, insert

HIST_EMIT = (
    '\t\t/*\n'
    '\t\t * VF3 research: per-instruction execution histogram, window-gated.\n'
    '\t\t * Guest regs are flushed to arm_Reg between instructions, so eax/rcx\n'
    '\t\t * are free before regalloc->load(i).  The increment sits inside the\n'
    '\t\t * conditional region, so it counts only executed instructions. */\n'
    '\t\t{\n'
    '\t\t\tXbyak::Label skip;\n'
    '\t\t\tmov(eax, dword[rip + &vf3ArmWinActive]);\n'
    '\t\t\ttest(eax, eax);\n'
    '\t\t\tjz(skip);\n'
    '\t\t\tmov(rcx, (size_t)&vf3ArmHist);\n'
    '\t\t\tadd(rcx, (size_t)((op.guest_pc >> 2) * 4));\n'
    '\t\t\tinc(dword[rcx]);\n'
    '\t\t\tL(skip);\n'
    '\t\t}\n'
    '\t\tregalloc->load(i);'
)


def main():
    for name in ('vf3armtrace.cpp', 'vf3armtrace.h'):
        shutil.copyfile(Path(__file__).parent / name, CORE / name)
    # guest_pc wiring (also used by the memory observer for PC attribution).
    insert(Path('hw/arm7/arm7_rec.h'), '\tOpType op_type;',
           '\tu32 guest_pc = 0; // research memory-access/exec attribution\n\tOpType op_type;')
    insert(Path('hw/arm7/arm7_rec.cpp'), '\t\tArmOp last_op = decodeArmOp(opcd, pc);',
           '\t\tArmOp last_op = decodeArmOp(opcd, pc);\n\t\tlast_op.guest_pc = pc;')
    # Include the observer and emit the per-instruction histogram increment.
    insert(Path('hw/arm7/arm7_rec_x64.cpp'), '#include "arm7_rec.h"',
           '#include "arm7_rec.h"\n#include "vf3armtrace.h"')
    insert(Path('hw/arm7/arm7_rec_x64.cpp'), '\t\t\tregalloc->load(i);', HIST_EMIT)
    # PC attribution for the (optional) memory trace.
    for func in ('emitMemOp', 'emitFallback'):
        anchor = f'\tvoid {func}(const ArmOp& op)\n\t{{'
        insert(Path('hw/arm7/arm7_rec_x64.cpp'), anchor,
               anchor + '\n\t\tmov(dword[rip + &vf3ArmTracePc], op.guest_pc);')
    # Memory-hook path: drives the window gate (vf3ArmWinActive) and, when a
    # mem trace is wanted, records VF3ARM1 records.  arm_mem.h is where the
    # memory observer hooks live.
    insert(Path('hw/arm7/arm_mem.h'), '#include "types.h"',
           '#include "types.h"\n#include "vf3armtrace.h"')
    insert(Path('hw/arm7/arm_mem.h'), '\t\t\treturn (rv >> sf) | (rv << (32 - sf));',
           '\t\t\tT rotated = (rv >> sf) | (rv << (32 - sf));\n'
           '\t\t\tvf3ArmTraceMemory(addr, rotated, sizeof(T), false);\n\t\t\treturn rotated;')
    insert(Path('hw/arm7/arm_mem.h'), '\t\telse\n\t\t\treturn rv;',
           '\t\telse {\n\t\t\tvf3ArmTraceMemory(addr, rv, sizeof(T), false);\n\t\t\treturn rv;\n\t\t}')
    insert(Path('hw/arm7/arm_mem.h'), '\t\treturn readReg<T>(addr);',
           '\t\tT rv = readReg<T>(addr);\n\t\tvf3ArmTraceMemory(addr, rv, sizeof(T), false);\n\t\treturn rv;')
    insert(Path('hw/arm7/arm_mem.h'), '\t\twriteReg(addr, data);\n\t}\n}',
           '\t\twriteReg(addr, data);\n\t}\n\tvf3ArmTraceMemory(addr, data, sizeof(T), true);\n}')
    insert(Path('hw/arm7/CMakeLists.txt'), 'target_sources(${PROJECT_NAME} PRIVATE',
           'target_sources(${PROJECT_NAME} PRIVATE\n        ../../vf3armtrace.cpp')
    print('ARM histogram observer installed; rebuild flycast-ref-build.')


if __name__ == '__main__':
    main()
