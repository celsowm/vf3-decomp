#!/usr/bin/env python3
"""Compare per-channel songstep counters/rates between the reference ARM trace
and the native run's write trace, across every channel.

Channel struct: base 0xCC50, stride 0x30.  The songstep decrements the note
counter at +0x14 by the rate at +0x4; the dispatch gates on the counter's top
16 bits (0x5f00) and re-arms it at +0x14 (0x6004).  The melody channel's
counter is what paces the 16/24/13/23/21 note gaps.
"""
import struct

BASE = 0xcc50
STRIDE = 0x30
NCH = 16


def ch_ctx(addr):
    a = addr & 0x1fffff
    for n in range(NCH):
        b = BASE + n * STRIDE
        if b <= a < b + STRIDE:
            return n, a - b
    return None


def chan_dump(records, title, lo, hi):
    """records: list of (sample, addr, val, pc, isram).  Print counter(+0x14)
    and rate(+0x4) writes in [lo,hi)."""
    out = []
    for s, addr, val, pc, isram in records:
        if not isram:
            continue
        if not (lo <= s <= hi):
            continue
        c = ch_ctx(addr)
        if not c:
            continue
        n, off = c
        if off in (0x14, 0x4):
            out.append((s, n, off, hex(val), hex(pc)))
    out.sort()
    print(title)
    for s, n, off, val, pc in out:
        print('   sample %7d ch%-2d +0x%02x %8s pc %s' % (s, n, off, val, pc))
    print()
    return out


def read_ref():
    p = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
    d = open(p, 'rb').read()
    n = (len(d) - 8) // 40
    rec = []
    for i in range(n):
        seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
        rec.append((cyc // 4535, addr & 0x1fffff, val, pcv, st == 1))
    return rec


def read_nat():
    p = 'build/native_trace.bin'
    d = open(p, 'rb').read()
    n = len(d) // 40
    rec = []
    for i in range(n):
        s, at, v, sz, pcv = struct.unpack_from('<QQQQQ', d, i * 40)
        rec.append((int(s), at & 0x7fffffff, v, pcv, (at >> 63) == 0))
    return rec


def main():
    ref = read_ref()
    nat = read_nat()
    # reference melody window: melody key-ons at samples 1,106,340-1,106,438
    chan_dump(ref, 'REFERENCE channel counter/rate writes, sample 1106200..1106900 (melody burst)',
              1106200, 1106900)
    # native melody window: 3500..3600
    chan_dump(nat, 'NATIVE channel counter/rate writes, sample 3500..3600 (melody burst)',
              3500, 3600)
    chan_dump(nat, 'NATIVE channel counter/rate writes, sample 3900..4000 (2nd note)',
              3900, 4000)


if __name__ == '__main__':
    main()
