#!/usr/bin/env python3
"""Offline run-matched scheduler-hit diff (diagnosis doc, route 2).

Both sides run the SAME firmware; the reference's per-GAP touch counts come
from the run-matched memory-access trace (vf3_28_traced.arm), native's from
its executed-PC stream (build/arm_seq.bin).  For a scanner PC that does one
memory access per iteration, the trace's count of that PC in a gap is a fair
proxy for native's executed count of that PC (one execution == one access).
The diff over the five melody gaps exposes which scheduler/scanner site
native hits an *odd* number fewer times on long notes (gaps 2/4/5 = 3 frames
short) -- the note-hold path whose countdown lands 3 frames early.
"""
import struct
from collections import Counter, defaultdict

REF = "extract/analysis/audio_arm_observer_v3/vf3_28_traced.arm"
SEQ = "build/arm_seq.bin"
ORIG = 5001139045
A = 4535

# Melody key-ons on each side (6 notes + the post-melody) from direct reads.
REF_KEYS = [5017270272, 5017342848, 5017451712, 5017510400, 5017614784, 5017710208, 5019038976]
NAT_KEYS = [245801, 246927, 248411, 249309, 250671, 251975, 272220]
GAP_N = 5  # the five in-melody gaps

# Sites of interest: the per-frame scanner and the note state machine.
SCANS = list(range(0x22a8, 0x22f8 + 1, 4))           # 64-slot voice scanner
SEQSM = [0x2e38, 0x2e3c, 0x2e44, 0x2e48, 0x2e58, 0x2e5c, 0x2e74, 0x2640, 0x264c]
SEQST = [0x5e70, 0x5e7c, 0x5e88, 0x5efc, 0x5f14, 0x5f34, 0x601c]
WATCH = set(SCANS) | set(SEQSM) | set(SEQST)


def ref_gap_counts():
    d = open(REF, "rb").read()
    n = (len(d) - 8) // 40
    # buckets per gap (sample span between key-ons)
    buckets = [Counter() for _ in range(GAP_N)]
    for i in range(n):
        seq, cyc, pc, op, addr, val, sz, st = struct.unpack_from("<QQ6I", d, 8 + i * 40)
        if pc not in WATCH or not st:
            continue
        for g in range(GAP_N):
            if REF_KEYS[g] <= cyc < REF_KEYS[g + 1]:
                buckets[g][pc] += 1
                break
    return buckets


def nat_gap_counts():
    d = open(SEQ, "rb").read()
    pcs = struct.unpack("<%dI" % (len(d) // 4), d)
    buckets = [Counter() for _ in range(GAP_N)]
    for i, pc in enumerate(pcs):
        if pc not in WATCH:
            continue
        for g in range(GAP_N):
            if NAT_KEYS[g] <= i < NAT_KEYS[g + 1]:
                buckets[g][pc] += 1
                break
    return buckets


def main():
    rb = ref_gap_counts()
    nb = nat_gap_counts()
    names = {0x22a8: "scanner", 0x2e38: "state(ldrb)",
             0x2e3c: "tst#8", 0x2e44: "tst#1", 0x2e58: "tst#20",
             0x2640: "keyon-ldr", 0x264c: "keyon-store", 0x5e70: "seq-loop"}
    print("per-gap touch counts  (ref / nat)   [gap = ref/nat samples]")
    print("gap refS natS : ", end="")
    for g in range(GAP_N):
        print("g%d %2d/%2d  " % (g + 1,
            (REF_KEYS[g + 1] - REF_KEYS[g]) // A,
            (REF_KEYS[g + 1] - REF_KEYS[g]) // A), end="")
    print()
    # group by PC
    pcs = sorted(WATCH)
    hdr = "site        " + "".join("   g%d" % (g + 1) for g in range(GAP_N))
    print(hdr)
    for pc in pcs:
        nm = names.get(pc, "pc%04x" % pc)
        row = "%-11s" % nm
        for g in range(GAP_N):
            r, n = rb[g].get(pc, 0), nb[g].get(pc, 0)
            tag = " %2d/%2d " % (r, n) if (r or n) else "  ./.  "
            row += tag
        print(row)
    # The long gaps vs short gaps: native short by ~206/258/175 insns on gaps 2/4/5.
    print()
    print("scanner (0x22a8..0x22f8) total ref/nat per gap:")
    for g in range(GAP_N):
        r = sum(rb[g].get(p, 0) for p in SCANS)
        n = sum(nb[g].get(p, 0) for p in SCANS)
        print("  g%d: ref %d  nat %d  (diff %+d)" % (g + 1, r, n, r - n))


if __name__ == "__main__":
    main()
