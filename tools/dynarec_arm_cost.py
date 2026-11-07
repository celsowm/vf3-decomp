#!/usr/bin/env python3
"""flycast ARM7 dynarec: static block cost, block formation, and a scheduler
simulation over an executed-PC stream.

The reference ran the ARM7 *dynarec* (tools/oracle/vf3armtrace.h: "PC is
assigned by the x64 ARM compiler"; core/build.h defaults FEAT_AREC to
DYNAREC_JIT on x64).  This module mirrors the two functions that decide when
the guest's time passes:

  arm7_rec.cpp   decodeArmOp()   the per-opcode `cycles` field
  arm7_rec.cpp   compile()       the block loop: 32 fetched opcodes max, a
                                 block ends after any OP_SETS_PC instruction,
                                 NOPs are skipped but still cost 6
  arm7_rec_x64.cpp compile()     `sub CYCL_CNT, cycles` with the *sum of the
                                 fetched opcodes' cycles* (synthetic ops the
                                 block builder inserts are not in that sum)
  arm7_rec_x64.cpp arm_dispatch  the timeslice and the FIQ are checked only
                                 when a block is dispatched

Fallback opcodes contribute 0 to the block's static charge and are billed by
`interpret()` (arm-new.h) while the block runs.

Used by the audio live-work: tools/dynarec_arm_cost.py build/arm_seq.bin
"""
import struct
import sys

IMAGE = 'extract/gamedata/SNDDRV.BIN'
SEQ = 'build/arm_seq.bin'
CYCLES_PER_SAMPLE = 512

BITS = [bin(i).count('1') for i in range(65536)]

OP_READS_FLAGS = 1
OP_SETS_FLAGS = 4
OP_SETS_PC = 8

# ArmOp::OpType
AND, EOR, SUB, RSB, ADD, ADC, SBC, RSC = range(8)
TST, TEQ, CMP, CMN, ORR, MOV, BIC, MVN = range(8, 16)
LDR, STR, B, BL, MSR, MRS, FALLBACK = range(16, 23)


class Op:
    __slots__ = ('cycles', 'flags', 'kind', 'fallback')

    def __init__(self):
        self.cycles = 6
        self.flags = 0
        self.kind = '?'
        self.fallback = False


def popcount(v):
    return (BITS[v & 0xFFFF] + BITS[(v >> 16) & 0xFFFF])


def decode(opcode, arm_pc):
    """Mirror recompiler::decodeArmOp(opcode, arm_pc) (arm7_rec.cpp:128)."""
    op = Op()
    cond = opcode >> 28
    if cond == 0xF:
        op.fallback = True
        op.cycles = 0
        op.kind = 'nv'
        return op
    if cond != 0xE:
        op.flags |= OP_READS_FLAGS

    rd = (opcode >> 12) & 0xF
    rn = (opcode >> 16) & 0xF
    set_flags = (opcode >> 20) & 1
    op_type = (opcode >> 21) & 0xF
    imm_op = (opcode >> 25) & 1
    group = (opcode >> 26) & 3
    shift_by_reg = (opcode >> 4) & 1
    shift_imm = (opcode >> 7) & 0x1F
    shift_type = (opcode >> 5) & 3
    _zero = (opcode >> 7) & 1
    rm = opcode & 0xF

    if group == 0:                                   # data processing / mul / swap
        if opcode & 0x0FFFFFF0 == 0x012FFF10:         # BX uses interpreter fallback
            op.fallback = True
            op.cycles = 0
            op.flags |= OP_SETS_PC
            op.kind = 'bx'
            return op
        if (op_type & 4) == 0 and imm_op == 0 and shift_by_reg and _zero:
            op.fallback = True
            op.cycles = 0
            op.kind = 'mul'
            return op
        if TST <= op_type <= CMN and set_flags == 0:
            if (opcode & 0x0FBF0FFF) == 0x010F0000:
                op.kind = 'mrs'
                return op                            # cycles 6
            if (opcode & 0x0FB0FFF0) == 0x0120F000:
                op.cycles += 1
                op.kind = 'msr'
                return op
            if (opcode & 0x0DB0F000) == 0x0120F000:
                op.kind = 'msr'
                return op
            op.kind = 'msr?'
            return op
        # generic data processing
        op.kind = 'dp'
        if op_type != MOV and op_type != MVN:
            pass
        if set_flags:
            op.flags |= OP_SETS_FLAGS
        if imm_op == 0 and shift_by_reg:
            op.cycles += 1                            # register-specified shift
        if rd == 15:
            if (op_type == MOV and imm_op == 0 and not shift_by_reg and
                    shift_imm == 0 and shift_type == 0 and not set_flags):
                # MOVcc pc, rn -> B
                op.cycles += 3
                op.flags |= OP_SETS_PC
                op.kind = 'movpc'
                return op
            if cond != 0xE or set_flags:
                op.fallback = True
                op.cycles = 0
                op.kind = 'dp-pc-fb'
                return op
            op.cycles += 1
            op.flags |= OP_SETS_PC
            op.kind = 'dp-pc'
        return op

    if group == 1:                                   # LDR / STR
        pre = (opcode >> 24) & 1
        up = (opcode >> 23) & 1
        byte = (opcode >> 22) & 1
        wb = (opcode >> 21) & 1
        load = (opcode >> 20) & 1
        imm12 = opcode & 0xFFF
        write_back = (wb or not pre) and rd != rn and (imm_op != 0 or imm12 != 0)
        if load:
            if rd == 15:
                op.flags |= OP_SETS_PC
                if cond != 0xE:
                    op.fallback = True
                    op.cycles = 0
                    op.kind = 'ldr-pc-fb'
                    return op
                op.cycles += 1
            op.cycles += 4
            op.kind = 'ldrb' if byte else 'ldr'
        else:
            op.cycles += 3
            op.kind = 'strb' if byte else 'str'
        if rn == 15 and write_back:
            op.fallback = True
            op.cycles = 0
            op.flags |= OP_SETS_PC
            op.kind = 'ldst-pc-fb'
            return op
        if imm_op and rm == 15:
            op.fallback = True
            op.cycles = 0
            op.kind = 'ldst-rmpc-fb'
            return op
        return op

    if group == 2:                                   # LDM/STM, B/BL
        if imm_op:
            op.cycles += 3
            op.flags |= OP_SETS_PC
            op.kind = 'bl' if (opcode >> 24) & 1 else 'b'
            return op
        reg_list = opcode & 0xFFFF
        if not (opcode & (1 << 22)) and popcount(reg_list) == 1:
            # rewritten as a single LDR/STR with an immediate offset of 4
            pre = (opcode >> 24) & 1
            up = (opcode >> 23) & 1
            wb = (opcode >> 21) & 1
            first = (reg_list & -reg_list).bit_length() - 1
            new = (0x04000000 | (opcode & 0xF0000000) |
                   (pre << 24) | (up << 23) | ((wb & pre) << 21) |
                   ((1 if (opcode >> 20) & 1 else 0) << 20) |
                   (rn << 16) | (first << 12) | 4)
            inner = decode(new, arm_pc)
            inner.cycles += 4
            inner.kind = 'ldm1' if (opcode >> 20) & 1 else 'stm1'
            return inner
        op.fallback = True
        op.cycles = 0
        op.kind = 'ldm' if (opcode >> 20) & 1 else 'stm'
        if (opcode & 0x8000) and ((opcode >> 20) & 1):
            op.flags |= OP_SETS_PC
        return op

    # group 3: coprocessor / SWI
    op.fallback = True
    op.cycles = 0
    op.kind = 'swi'
    if imm_op == 1 and (op_type & 8):
        op.flags |= OP_SETS_PC
    return op


def is_nop(opcode):
    return opcode == 0 or opcode == 0x41474553


def block_cost(img, pc, max_ops=32):
    """One dynarec block: (static charge, ops fetched, end pc, decoded ops)."""
    total = 0
    ops = 0
    pcs = []
    while ops < max_ops:
        opcode = struct.unpack_from('<I', img, pc & 0x1FFFFF)[0]
        op = decode(opcode, pc)
        total += op.cycles
        ops += 1
        pcs.append((pc, op, opcode))
        pc += 4
        if not is_nop(opcode) and (op.flags & OP_SETS_PC):
            break
    return total, ops, pc, pcs


def main():
    img = open(IMAGE, 'rb').read()
    data = open(sys.argv[1] if len(sys.argv) > 1 else SEQ, 'rb').read()
    n = len(data) // 4
    pcs = struct.unpack('<%dI' % n, data)

    # walk the PC stream as the dynarec would dispatch it: each block starts
    # at the stream's current PC and consumes the stream until its static
    # block ends.  (The executed stream is already the guest's path.)
    i = 0
    total_static = 0
    total_dynamic = 0
    total_ops = 0
    blocks = 0
    fallbacks = {}
    while i < n:
        pc = pcs[i]
        cost, ops, endpc, decoded = block_cost(img, pc)
        total_static += cost
        blocks += 1
        for j, (p, op, opcode) in enumerate(decoded):
            if op.fallback:
                fallbacks[op.kind] = fallbacks.get(op.kind, 0) + 1
        # skip the stream forward by the block's fetched ops: the stream is
        # the executed path, so a conditional branch's not-taken arm appears
        # as the next PC; block ops are the same number of instructions.
        i += ops
        total_ops += ops

    print('instructions %d  blocks %d  static %d cyc (%.2f samples)'
          % (n, blocks, total_static, total_static / CYCLES_PER_SAMPLE))
    print('fallback executions in blocked stream:', fallbacks)
    print('avg block %.2f ops' % (total_ops / blocks))


if __name__ == '__main__':
    main()
