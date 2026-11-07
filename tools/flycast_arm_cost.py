"""Cost the native ARM7 PC stream with flycast's own per-class cycle model.

flycast's ARM7 is the C interpreter in tools/emu/flycast/core/hw/arm7/
arm-new.h.  Every fetched instruction is charged 6 ticks (line 1321); the
handler then adds a class-specific charge:

    DP / PSR / MRS / MSR      +0        (only `movs pc,lr`-style adds +1)
    B / BL / SWI              +3
    MUL / MLA                 +2..+6   (from |Rs|)
    LDR word                  +3 + 1 = +4   (+2 when Rd == PC)
    STR word                  +2 + 1 = +3
    LDRB                      +3 + 1 = +4
    STRB                      +2 + 1 = +3
    LDRH / LDRSB / LDRSH      +3 + 1 = +4
    STRH                      +4 + 1 = +5
    LDM                       +2 + 2*count (+1 if PC is loaded)
    STM                       +2 + 2*count
    MRS/MSR/SWP/BX            +0

(CPUUpdateTicksAccess{16,32,Seq32} are all 1 in arm7.cpp lines 21-23.)

Input : build/arm_seq.bin   the native run's executed-PC stream (u32 LE)
        extract/gamedata/SNDDRV.BIN   the AICA firmware image
Output: per main-loop iteration (PC 0x5ec), the predicted cost in samples.

Used to test the hypothesis that our interpreter's per-class billing is why
the native main loop runs faster than the reference's.
"""
import struct
import sys

IMAGE = 'extract/gamedata/SNDDRV.BIN'
SEQ = 'build/arm_seq.bin'
MAIN_LOOP = 0x5EC
KEY_ON = 0x264C
CYCLES_PER_SAMPLE = 512.0

BITS = [bin(i).count('1') for i in range(65536)]


def popcount16(v):
    return BITS[v & 0xFFFF]


def classify_native(insn):
    """The port's opcode-only estimate (base 6 added separately).

    The multiply case is approximate because its real cost depends on the
    live Rs value, which the executed-PC stream does not record.
    """
    cond = insn >> 28
    if cond == 0xF:
        return 1, 'nv'
    if (insn & 0x0F000000) == 0x0F000000:
        return 1, 'swi'
    if (insn & 0x0E000000) == 0x0A000000:
        return 1, 'branch'
    op = (insn >> 25) & 7
    if op == 7:
        return 1, 'swi'
    if op == 4:
        n = popcount16(insn)
        load = bool(insn & (1 << 20))
        pc_extra = 1 if load and (insn & (1 << 15)) else 0
        return 2 + 2 * n + pc_extra, ('ldm' if load else 'stm')
    if op in (2, 3):
        load = (insn >> 20) & 1
        byte = (insn >> 22) & 1
        cls = ('ldr' if load else 'str') + ('b' if byte else '')
        return 1, cls
    if (insn & 0x90) == 0x90:
        if (insn & 0x60) == 0:
            if (insn & 0x0F800000) == 0x01000000:
                return 1, 'swp'
            return 1, ('mla' if insn & (1 << 21) else 'mul')
        load = (insn >> 20) & 1
        if not load:
            return 1, 'strh'
        op2 = (insn >> 5) & 3
        return 1, {1: 'ldrh', 2: 'ldrsb'}.get(op2, 'ldrsh')
    return 1, 'dp'


def classify(insn):
    """flycast's extra ticks for an instruction whose condition passed."""
    cond = insn >> 28
    if cond == 0xF:
        return 0, 'nv'
    if (insn & 0x0F000000) == 0x0F000000:
        return 3, 'swi'                      # SWI
    if (insn & 0x0E000000) == 0x0A000000:
        return 3, 'branch'                   # B / BL
    op = (insn >> 25) & 7
    if op == 7:
        return 3, 'swi'                      # coprocessor/SWI row
    if op == 4:
        n = popcount16(insn)
        if insn & (1 << 20):
            pc_extra = 1 if insn & (1 << 15) else 0
            return 2 + 2 * n + pc_extra, 'ldm'
        return 2 + 2 * n, 'stm'
    if op in (2, 3):
        load = (insn >> 20) & 1
        byte = (insn >> 22) & 1
        rd = (insn >> 12) & 0xF
        if byte:
            return (4 if load else 3), ('ldrb' if load else 'strb')
        if load:
            return 4 + (2 if rd == 15 else 0), 'ldr'
        return 3, 'str'
    # op == 0: data processing / multiply / halfword / PSR / swap / BX
    if (insn & 0x90) == 0x90:                # bit7=1, bit4=1
        if (insn & 0x60) == 0:               # multiply or swap
            if (insn & 0x0F800000) == 0x01000000:
                return 0, 'swp'
            if insn & (1 << 21):
                return 3, 'mla'              # flycast +3..+6; assume small
            return 3, 'mul'                  # flycast +2..+5
        load = (insn >> 20) & 1
        op2 = (insn >> 5) & 3
        if not load:
            return 5, 'strh'
        if op2 == 1:
            return 4, 'ldrh'
        if op2 == 2:
            return 4, 'ldrsb'
        return 4, 'ldrsh'
    # data processing: flycast charges +1 only when S and Rd==15 (exception
    # return), otherwise nothing.
    if (insn & 0x00100000) and ((insn >> 12) & 0xF) == 15:
        return 1, 'dp-pc'
    return 0, 'dp'


def load_image():
    return open(IMAGE, 'rb').read()


def main():
    img = load_image()
    d = open(SEQ, 'rb').read()
    n = len(d) // 4
    pcs = struct.unpack('<%dI' % n, d)

    # per-PC classification cache (the image never changes)
    cache = {}

    def cost(pc):
        if pc in cache:
            return cache[pc]
        try:
            insn = struct.unpack_from('<I', img, pc)[0]
        except struct.error:
            r = (6, 6, 'oob')
            cache[pc] = r
            return r
        if insn == 0:
            r = (6, 6, 'zero')
            cache[pc] = r
            return r
        f_extra, cls = classify(insn)
        n_extra, _ = classify_native(insn)
        cond = insn >> 28
        c = cls if cond == 0xE else cls + '?'
        r = (6 + n_extra, 6 + f_extra, c)
        cache[pc] = r
        return r

    total_f = 0
    total_n = 0
    iters = []
    cur = None
    for i, pc in enumerate(pcs):
        cn, cf, cls = cost(pc)
        total_n += cn
        total_f += cf
        if cur is None:
            cur = {'pc0': i, 'n': 0, 'f': 0, 'insns': 0, 'classes': {}}
        cur['n'] += cn
        cur['f'] += cf
        cur['insns'] += 1
        cur['classes'][cls] = cur['classes'].get(cls, 0) + 1
        if pc == MAIN_LOOP:
            iters.append(cur)
            cur = {'pc0': i, 'n': 0, 'f': 0, 'insns': 0, 'classes': {}}

    keys = [i for i, pc in enumerate(pcs) if pc == KEY_ON]

    def iter_of(idx):
        # binary search the iteration whose span holds idx
        lo, hi = 0, len(iters)
        while lo < hi:
            mid = (lo + hi) // 2
            if iters[mid]['pc0'] <= idx:
                lo = mid + 1
            else:
                hi = mid
        return lo - 1

    print('instructions %d  iterations %d' % (n, len(iters)))
    print('total native model %d cyc = %.1f samples' % (total_n, total_n / CYCLES_PER_SAMPLE))
    print('total flycast model %d cyc = %.1f samples' % (total_f, total_f / CYCLES_PER_SAMPLE))
    print('key-on # -> iteration -> predicted duration (native | flycast)')
    for k in range(7):
        it = iter_of(keys[k])
        c = iters[it]
        print('  key %d at pc idx %7d  it %4d  nat %6.2f  fly %6.2f samples  insns %5d'
              % (k + 1, keys[k], it, c['n'] / CYCLES_PER_SAMPLE,
                 c['f'] / CYCLES_PER_SAMPLE, c['insns']))
    print()
    print('melody iterations, class histogram:')
    for k in range(6):
        it = iter_of(keys[k])
        c = iters[it]
        hist = sorted(c['classes'].items(), key=lambda kv: -kv[1])
        print('  it %d  nat %6.2f fly %6.2f  %5d insns  %s'
              % (it, c['n'] / CYCLES_PER_SAMPLE, c['f'] / CYCLES_PER_SAMPLE, c['insns'],
                 ' '.join('%s=%d' % kv for kv in hist if not kv[0].endswith('?'))))
    print()
    print('all class totals:')
    allc = {}
    for it in iters:
        for k, v in it['classes'].items():
            allc[k] = allc.get(k, 0) + v
    for k, v in sorted(allc.items(), key=lambda kv: -kv[1]):
        print('  %-8s %8d' % (k, v))


if __name__ == '__main__':
    main()
