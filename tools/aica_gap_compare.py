#!/usr/bin/env python3
"""Characterize what the firmware does BETWEEN successive melody key-ons.

Reference trace (extract/.../vf3_28_traced.arm) logs only stores; native trace
(build/native_trace.bin) logs RAM+reg writes.  Both log the same per-note
voice-config stores, so the ONLY difference is the inter-note gap.  Dump every
store record between consecutive melody key-ons (pc 0x264c) in each, and count
how many cycles/samples each side needs to cover the same per-note config.

The reference melody key-ons are at seq 20409, 20467, 20579, 20637, 20744,
20822 in vf3_28_traced.arm.
"""
import struct

REF = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
NAT = 'build/native_trace.bin'


def read_ref():
    d = open(REF, 'rb').read()
    n = (len(d) - 8) // 40
    recs = []
    for i in range(n):
        seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
        recs.append((seq, cyc, pcv, addr & 0xffffff, val & 0xffffff))
    return recs


def read_nat():
    d = open(NAT, 'rb').read()
    n = len(d) // 40
    recs = []
    for i in range(n):
        s, at, v, sz, pcv = struct.unpack_from('<QQQQQ', d, i * 40)
        a = at & 0x7fffffff
        if (at >> 63) == 0:
            a &= 0xffffff
        recs.append((int(s), pcv, a, v & 0xffffff))
    return recs


def dump_ref_gap(recs, a_seq, b_seq):
    """Dump store records in reference seq range [a_seq, b_seq)."""
    print('--- REFERENCE, seq %d..%d (one melody gap) ---' % (a_seq, b_seq))
    key_samples = set()
    for seq, cyc, pcv, a, v in recs:
        if a_seq <= seq < b_seq:
            tag = ''
            if pcv == 0x264c:
                tag = '   <KEY'
            if (cyc // 4535) not in key_samples:
                print('  [sample %d]' % (cyc // 4535))
                key_samples.add(cyc // 4535)
            print('   seq %5d c%d pc %04x a %06x v %06x%s' % (seq, cyc // 4535, pcv, a, v, tag))
    print()


def dump_nat_gap(recs, lo, hi):
    """Dump native store records in sample range [lo, hi)."""
    print('--- NATIVE, samples %d..%d (one melody gap) ---' % (lo, hi))
    cur = None
    for s, pcv, a, v in recs:
        if lo <= s < hi:
            if s != cur:
                print('  [sample %d]' % s)
                cur = s
            tag = '   <KEY' if pcv == 0x264c else ''
            print('   s%5d pc %04x a %06x v %06x%s' % (s, pcv, a, v, tag))
    print()


def main():
    ref = read_ref()
    nat = read_nat()
    # reference key-on seqs
    keys = [r for r in ref if r[2] == 0x264c]
    print('Reference key-ons at seq:', [k[0] for k in keys[:8]])
    # gap between first and second melody key-on
    dump_ref_gap(ref, keys[0][0], keys[1][0])
    # native melody window key-on samples
    natkeys = [r for r in nat if r[1] == 0x264c]
    print('Native key-ons at sample:', [k[0] for k in natkeys[:8]])
    if len(natkeys) >= 2:
        dump_nat_gap(nat, natkeys[0][0], natkeys[1][0])


if __name__ == '__main__':
    main()
