#!/usr/bin/env python3
"""Diff the reference's window-gated per-instruction histogram against
native's per-PC execution counts over the melody, revealing which ARM PCs the
reference executes *more* of during note holds (the ~657 extra instructions).

Reference histogram:  ref_melody_hist.txt   (pc  count, window-gated)
Native stream:        build/arm_seq.bin      (u32 PC stream)
"""
import struct
from collections import Counter
import sys

REF_HIST = "extract/analysis/audio_arm_observer_v3/ref_melody_hist.txt"
SEQ = "build/arm_seq.bin"


def native_melody_pc():
    d = open(SEQ, "rb").read()
    pcs = struct.unpack("<%dI" % (len(d) // 4), d)
    keys = [i for i, x in enumerate(pcs) if x == 0x264c]  # key-on store pc
    if len(keys) < 6:
        print("!! native key-on count < 6 (%d)" % len(keys)); return Counter()
    lo, hi = keys[0], keys[5]  # note1 .. note6
    return Counter(pcs[lo:hi]), lo, hi


def ref_hist():
    c = Counter()
    try:
        for line in open(REF_HIST):
            line = line.strip()
            if not line: continue
            pc_s, cnt_s = line.split()
            c[int(pc_s, 16)] = int(cnt_s)
    except FileNotFoundError:
        print("!! missing reference histogram: " + REF_HIST); return c
    return c


def main():
    nhist, lo, hi = native_melody_pc()
    rhist = ref_hist()
    if not rhist:
        sys.exit("reference histogram not captured yet")
    nat_total = sum(nhist.values())
    ref_total = sum(rhist.values())
    print("native melody insns (key1..key6, seq %d..%d): %d" % (lo, hi, nat_total))
    print("reference window histogram total:              %d" % ref_total)
    print()
    # Compare per-PC.  Reference window (frames 3500..3800) is wider than the
    # native melody span, so background PCs carry extra ref counts; the note-hold
    # PCs stand out as the large deltas we care about.
    allp = set(nhist) | set(rhist)
    rows = []
    for pc in allp:
        n = nhist.get(pc, 0)
        r = rhist.get(pc, 0)
        d = r - n
        if d != 0:
            rows.append((d, pc, r, n))
    rows.sort(reverse=True)
    print("PCs where reference executes MORE than native (top 40 by delta):")
    print("   delta    ref      nat    pc   (asm!)")
    for d, pc, r, n in rows[:40]:
        print("  %+6d %7d %7d  0x%04x" % (d, r, n, pc))
    print()
    print("PCs where native executes MORE than reference (top 20):")
    for d, pc, r, n in rows[-20:]:
        print("  %+6d %7d %7d  0x%04x" % (d, r, n, pc))


if __name__ == "__main__":
    main()
