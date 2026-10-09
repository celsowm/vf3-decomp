"""Install bounded ARM observation in the ignored x64 research emulator.

Run the main installer first. This deliberately leaves its frozen capture
sources unchanged; existing executable snapshots remain usable during builds.
"""
from pathlib import Path
import shutil
from install import CORE, insert


def main():
    for name in ('vf3armtrace.cpp','vf3armtrace.h'):
        shutil.copyfile(Path(__file__).parent/name,CORE/name)
    insert(Path('hw/arm7/arm7_rec.h'), '\tOpType op_type;',
           '\tu32 guest_pc = 0; // research memory-access attribution\n\tOpType op_type;')
    insert(Path('hw/arm7/arm7_rec.cpp'), '\t\tArmOp last_op = decodeArmOp(opcd, pc);',
           '\t\tArmOp last_op = decodeArmOp(opcd, pc);\n\t\tlast_op.guest_pc = pc;')
    insert(Path('hw/arm7/arm7_rec_x64.cpp'), '#include "arm7_rec.h"',
           '#include "arm7_rec.h"\n#include "vf3armtrace.h"')
    for func in ('emitMemOp','emitFallback'):
        anchor=f'\tvoid {func}(const ArmOp& op)\n\t{{'
        insert(Path('hw/arm7/arm7_rec_x64.cpp'),anchor,
               anchor+'\n\t\tmov(dword[rip + &vf3ArmTracePc], op.guest_pc);')
    insert(Path('hw/arm7/arm_mem.h'), '#include "types.h"',
           '#include "types.h"\n#include "vf3armtrace.h"')
    insert(Path('hw/arm7/arm_mem.h'), '\t\t\treturn (rv >> sf) | (rv << (32 - sf));',
           '\t\t\tT rotated = (rv >> sf) | (rv << (32 - sf));\n'
           '\t\t\tvf3ArmTraceMemory(addr,rotated,sizeof(T),false);\n\t\t\treturn rotated;')
    insert(Path('hw/arm7/arm_mem.h'), '\t\telse\n\t\t\treturn rv;',
           '\t\telse {\n\t\t\tvf3ArmTraceMemory(addr,rv,sizeof(T),false);\n\t\t\treturn rv;\n\t\t}')
    insert(Path('hw/arm7/arm_mem.h'), '\t\treturn readReg<T>(addr);',
           '\t\tT rv = readReg<T>(addr);\n\t\tvf3ArmTraceMemory(addr,rv,sizeof(T),false);\n\t\treturn rv;')
    insert(Path('hw/arm7/arm_mem.h'), '\t\twriteReg(addr, data);\n\t}\n}',
           '\t\twriteReg(addr, data);\n\t}\n\tvf3ArmTraceMemory(addr,data,sizeof(T),true);\n}')
    insert(Path('hw/arm7/CMakeLists.txt'), 'target_sources(${PROJECT_NAME} PRIVATE',
           'target_sources(${PROJECT_NAME} PRIVATE\n        ../../vf3armtrace.cpp')


if __name__=='__main__': main()
