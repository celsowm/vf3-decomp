"""Per-gap store-PC histogram: reference v4 ARM event trace vs native trace.

Reference : extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm
            (VF3ARM1 header + 40-byte memory events, loads and stores)
Native    : build/native_trace.bin (5 u64 per write: sample, at, value, size, pc)

Both are cut at the six melody key-on writes, so the histogram of a gap is the
work the firmware did between two notes.
"""
import struct
import sys
from collections import Counter

REF = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
NAT = 'build/native_trace.bin'
EV = struct.Struct('<QQIIIIII')
W = struct.Struct('<QQQQQ')


def ref_events():
    d = open(REF, 'rb').read()
    assert d[:8] == b'VF3ARM1\0'
    n = (len(d) - 8) // 40
    for i in range(n):
        yield EV.unpack_from(d, 8 + i * 40)


def ref_keys():
    """(event index, cycle) of each key-on store, in order."""
    out = []
    for i, (seq, cyc, pc, op, addr, data, size, store) in enumerate(ref_events()):
        if store and pc == 0x264c and (addr & 0x7fff) < 0x2000 and data in (0x82, 0x83):
            out.append((i, cyc, addr & 0x7fff, data))
    return out


def ref_gap_hist(lo, hi):
    h = Counter()
    for i, (seq, cyc, pc, op, addr, data, size, store) in enumerate(ref_events()):
        if lo <= i < hi and store:
            h[pc] += 1
    return h


def nat_recs():
    d = open(NAT, 'rb').read()
    return [W.unpack_from(d, i * 40) if False else W.unpack_from(d, i * 40)
            for i in range(len(d) // 40)]


def nat_keys(recs):
    out = []
    for s, at, val, sz, pc in recs:
        if at >> 31 and (at & 0x7fff) < 0x2000 and val in (0x82, 0x83):
            out.append((s, at & 0x7fff, val, pc))
    return out


def nat_gap_hist(recs, lo, hi):
    h = Counter()
    for s, at, val, sz, pc in recs:
        if lo <= s < hi:
            h[pc] += 1
    return h


def main():
    rk = ref_keys()
    recs = nat_recs()
    nk = nat_keys(recs)
    print('reference keys:', [(i, c, '%04x' % a, '%02x' % v) for i, c, a, v in rk])
    print('native keys   :', nk)
    for g in range(5):
        rl, rh = rk[g][0], rk[g + 1][0]
        nl, nh = nk[g][0], nk[g + 1][0]
        rh_ = ref_gap_hist(rl, rh)
        nh_ = nat_gap_hist(recs, nl, nh)
        print('\n=== gap %d  ref [%d..%d)  native [%d..%d) ===' % (g + 1, rl, rh, nl, nh))
        print('  ref stores %d  native stores %d' % (sum(rh_.values()), sum(nh_.values())))
        pcs = sorted(set(rh_) | set(nh_))
        rows = [(rh_[p] - nh_[p], p, rh_[p], nh_[p]) for p in pcs]
        rows.sort(key=lambda r: -abs(r[0]))
        for d, p, r, n in rows[:18]:
            print('  pc %04x  ref %5d  nat %5d  d %+5d' % (p, r, n, d))


if __name__ == '__main__':
    main()
