#!/usr/bin/env python3
"""Analyze a vf3trace binary stream: count per-PC executions, flag first-seen
sequence, and map hits onto function names (funcs CSV).

Format: u64 records, pc = rec>>32, op = rec&0xFFFF, marker bit 16 = exception.
"""
import bisect
import collections
import csv
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")
BASE = 0x8C010000


def load_funcs(prog="1ST_READ"):
    rows = []
    with open(os.path.join(AN, f"funcs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    rows.sort()
    return rows, [r[0] for r in rows]


def fn_of(funcs, ents, a):
    i = bisect.bisect_right(ents, a) - 1
    if i >= 0 and funcs[i][0] <= a < funcs[i][0] + max(funcs[i][1], 4):
        return funcs[i][2], funcs[i][0]
    return (None, None)


def main():
    path = sys.argv[1]
    n = os.path.getsize(path) // 8
    print(f"{n:,} trace records")
    funcs, ents = load_funcs()
    stack = []  # (record_idx, exe_range_of_fn[(lo,hi)])  - simple first-seen
    pc_count = collections.Counter()
    fn_first_seen = {}   # fn entry -> first trace index
    op_hist = collections.Counter()
    data = open(path, "rb").read()
    idx = iter(struct.iter_unpack("<Q", data))
    for i, (rec,) in enumerate(idx):
        if rec & 0x10000:            # exception marker (shared-bit trick)
            op_hist["exc"] += 1
            continue
        pc = (rec >> 16) & 0xFFFFFFFF
        op = rec & 0xFFFF
        if 0x0C000000 <= pc < 0x0C200000:        # P2 alias -> 0x8C01xxxx
            pc |= 0x80000000
        pc_count[pc] += 1
        op_hist[op & 0xF000] += 1
        fn, fen = fn_of(funcs, ents, pc)
        if fen is not None and fen not in fn_first_seen:
            fn_first_seen[fen] = (i, fn)
    print("\n-- fn first-seen order (top 40): --")
    for fen, (i, nm) in sorted(fn_first_seen.items(), key=lambda kv: kv[1][0])[:40]:
        print(f"  trace#{i:>9d}  0x{fen:08X}  {nm}")
    print("\n-- most executed PCs --")
    for pc, c in pc_count.most_common(12):
        fn, _ = fn_of(funcs, ents, pc)
        print(f"  0x{pc:08X} x{c}  in {fn}")
    print("\ntotal distinct fns touched:", len(fn_first_seen))

    # first index where execution leaves 0x8C000xxx boot/IP zone for game image
    print("\n-- boot->game boundary scan --")
    idx = struct.iter_unpack("<Q", data)
    prev = None
    lo, hi = BASE, BASE + 0x120000
    crossed = None
    n_game = 0
    for i, (rec,) in enumerate(idx):
        if rec & 0x10000:
            continue
        pc = (rec >> 16) & 0xFFFFFFFF
        if 0x0C000000 <= pc < 0x0C200000:
            pc |= 0x80000000
        if crossed is None and lo <= pc < hi and pc != prev:
            crossed = (i, pc)
            break
        prev = pc
    if crossed:
        print(f"  first game-image execution: record #{crossed[0]:,} pc=0x{crossed[1]:08X}")
    else:
        print("  game image never reached?!")

    # pass 2: function hit counts + phase activity (phase = 10M instrs)
    fn_hits = collections.Counter()
    phase_hits = collections.defaultdict(set)
    PH = 10_000_000
    idx = struct.iter_unpack("<Q", data)
    for i, (rec,) in enumerate(idx):
        if rec & 0x10000:
            continue
        pc = (rec >> 16) & 0xFFFFFFFF
        if 0x0C000000 <= pc < 0x0C200000:
            pc |= 0x80000000
        fn, fen = fn_of(funcs, ents, pc)
        if fen is not None:
            fn_hits[fen] += 1
            phase_hits[i // PH].add(fen)
    fn_name = {fen: nm for fen, (i, nm) in fn_first_seen.items()}
    print("\n-- hottest game functions --")
    for fen, c in fn_hits.most_common(20):
        print(f"  0x{fen:08X} x{c:>10,}  {fn_name.get(fen, '?')}")
    named = [(fen, i, nm) for fen, (i, nm) in fn_first_seen.items()
             if not nm.startswith(("f_", "FUN_"))]
    print(f"\nnamed anchors seen running: {len(named)}")
    for fen, i, nm in sorted(named, key=lambda t: t[1]):
        print(f"  {nm:40s} @0x{fen:08X} first seen #{i:,}")
    nph = max(phase_hits) + 1
    print(f"\nphases = {nph}")
    for ph in sorted(phase_hits):
        print(f"  phase {ph:3d}: {len(phase_hits[ph])} distinct fns")
    with open(os.path.join(AN, "trace_functions_by_first_seen.csv"),
              "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["idx", "addr", "name"])
        for fen, (i, nm) in sorted(fn_first_seen.items(),
                                   key=lambda kv: kv[1][0]):
            w.writerow([i, f"0x{fen:08X}", nm])
    with open(os.path.join(AN, "trace_fn_hits.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["fn", "hits", "first_seen_idx"])
        for fen, c in fn_hits.most_common():
            w.writerow([f"0x{fen:08X}", c, fn_first_seen.get(fen, (0,))[0]])


if __name__ == "__main__":
    main()
