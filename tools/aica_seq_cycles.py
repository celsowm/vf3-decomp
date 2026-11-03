#!/usr/bin/env python3
"""Decisive test: does flycast's per-instruction cycle billing explain the
melody-gap skew?

Native executes the same per-note config, but retires it in ~1161 insns over
~3 samples (bills ~1.3 cyc/insn, 512-cycle budget).  The reference - flycast's
arm-new.h *interpreter* - bills a base 6 cycles per instruction (line 1321)
plus a per-class memory-access tick, so it retires only ~68 insns/sample and
spreads the same config over ~16 samples.

Here we take native's captured executed-PC stream (build/arm_seq.bin, one
uint32 PC per retired instruction), disassemble each instruction, apply
flycast's interpreter cost model, and print the per-melody-gap sample count it
predicts.  If that matches the reference's 16/24/12/23/21, billing alone is
the lever and I implement it in vf3_arm7_step.
"""
import struct
from math import inf
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

FW = open('extract/gamedata/SNDDRV.BIN', 'rb').read()

# flycast arm-new.h interpreter costs (base 6 in line 1321, per-class below).
# Access tick = 1 (CPUUpdateTicksAccess32/16/8 = 1 in arm7.cpp).
def insn_cost(insn):
    m = insn.mnemonic
    ops = insn.op_str
    cls = insn.group  # capstone groups
    # memory ops: LDR/STR (+ word/halfword/byte)
    if insn.operands and all(x.type == 3 for x in insn.operands):  # mem operand present
        pass
    if m in ('ldr', 'str'):
        # word STR 2+1, word LDR 3+1 (flycast); base 6
        return 6 + (2 + 1 if m == 'str' else 3 + 1)
    if m in ('ldrh', 'strh', 'ldrsh', 'ldrsb', 'ldrb', 'strb'):
        return 6 + (3 + 1)
    if m in ('stm', 'ldm', 'stmdb', 'ldmdb', 'stmia', 'ldmia'):
        # block transfer: 2 + regs (flycast ~2..5)
        nregs = ops.count(',') + 1
        return 6 + min(2 + nregs, 6)
    if m in ('mul', 'mla', 'umull', 'umlal', 'smull', 'smlal'):
        return 6 + 2
    if m in ('b', 'bl', 'bx', 'blx'):
        return 6 + 3
    # data processing / everything else: base 6
    return 6


def cost_stream(pcs):
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
    md.detail = True
    total = 0
    last = None
    for pc in pcs:
        a = pc & ~3
        if last == a:
            continue
        last = a
        try:
            insns = list(md.disasm(FW[a:a+4], a))
        except Exception:
            insns = []
        if not insns:
            total += 6
            continue
        total += insn_cost(insns[0])
    return total


def main():
    d = open('build/arm_seq.bin', 'rb').read()
    n = len(d) // 4
    pcs = struct.unpack('<%dI' % n, d)
    keys = [i for i, x in enumerate(pcs) if x == 0x264c]
    print('total instructions:', n)
    print('key-ons:', keys[:8])
    print('\nPer melody gap (flycast interpreter model):')
    print('  gap   native_insns   flycast_cycles   flycast_samples   ref_samples')
    ref = [16, 24, 12, 23, 21]
    for i in range(min(5, len(keys) - 1)):
        a, b = keys[i], keys[i + 1]
        seg = pcs[a:b]
        cyc = cost_stream(seg)
        samples = cyc / 512.0
        rsamp = ref[i] if i < len(ref) else '?'
        print('  %d     %6d         %8d        %8.2f          %s' %
              (i + 1, len(seg), cyc, samples, rsamp))


if __name__ == '__main__':
    main()
