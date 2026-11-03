#!/usr/bin/env python3
"""Compare the per-channel note-duration counter re-sets (firmware pc 0x6004)
between the reference ARM trace and the native run's write trace.

The dispatch gates on [r8,#0x14] (counter) expiring (0x5f00 asr #0x10 cmp #0
bgt skip) and 0x6004 re-sets it to the next note's duration.  If native only
ever re-sets channel 0 (0xcc64) while the reference re-sets every melody
channel, the melody channels' counters are never armed in native, so their
notes fire uncontrolled (the compressed burst).

Usage: python tools/aica_channel_reset.py
"""
import struct

CH_BASE = 0xcc50
CH_STRIDE = 0x30


def ch_index(addr):
    a = addr & 0x1fffff
    if a < CH_BASE:
        return None
    d = a - CH_BASE
    if d % CH_STRIDE != 0:
        return None
    return d // CH_STRIDE


def ref_resets():
    p = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
    d = open(p, 'rb').read()
    n = (len(d) - 8) // 40
    out = []
    for i in range(n):
        seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
        if st == 1 and pcv == 0x6004:
            ci = ch_index(addr)
            out.append((cyc // 4535, ci, hex(addr & 0x1fffff), hex(val)))
    return out


def nat_resets():
    p = 'build/native_trace.bin'
    d = open(p, 'rb').read()
    n = len(d) // 40
    out = []
    for i in range(n):
        s, at, v, sz, pcv = struct.unpack_from('<QQQQQ', d, i * 40)
        if (at >> 63) == 0 and pcv == 0x6004:
            ci = ch_index(at & 0x7fffffff)
            out.append((int(s), ci, hex(at & 0x7fffffff), hex(v)))
    return out


def main():
    rr = ref_resets()
    nr = nat_resets()
    ref_chs = {}
    for s, ci, a, v in rr:
        ref_chs.setdefault(ci, []).append((s, a, v))
    nat_chs = {}
    for s, ci, a, v in nr:
        nat_chs.setdefault(ci, []).append((s, a, v))

    print('REFERENCE: %d counter re-sets (pc 0x6004), across %d channel indexes' %
          (len(rr), len(ref_chs)))
    print('   first few in order:')
    for s, ci, a, v in rr[:30]:
        print('     sample %8d ch%-2d %s %s' % (s, ci if ci is not None else -1, a, v))
    print('   per-channel counts:')
    for ci in sorted(ref_chs):
        print('     ch%-2d : %d' % (ci, len(ref_chs[ci])))

    print()
    print('NATIVE: %d counter re-sets (pc 0x6004), across %d channel indexes' %
          (len(nr), len(nat_chs)))
    for s, ci, a, v in nr:
        print('     sample %8d ch%-2d %s %s' % (s, ci if ci is not None else -1, a, v))
    print('   per-channel counts:')
    for ci in sorted(nat_chs):
        print('     ch%-2d : %d' % (ci, len(nat_chs[ci])))

    print()
    print('Conclusion: reference arms %d distinct channels; native arms %d.' %
          (len(ref_chs), len(nat_chs)))


if __name__ == '__main__':
    main()
