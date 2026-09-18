#!/usr/bin/env python3
"""Huge-trace analysis (numpy): fn hit counts + first-seen index."""
import csv
import os
import sys

import numpy as np

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")


def load_funcs(prog="1ST_READ"):
    rows = []
    with open(os.path.join(AN, f"funcs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    rows.sort()
    return rows, np.array([r[0] for r in rows], dtype=np.int64)


def main():
    path = sys.argv[1]
    total_bytes = os.path.getsize(path)
    print(f"streaming {total_bytes/1e9:.1f} GB ...")
    n_rec = total_bytes // 8

    funcs, ents = load_funcs()
    fsz = np.array([f[1] for f in funcs], dtype=np.int64)
    counts = np.zeros(len(funcs), dtype=np.int64)
    first_seen_idx = np.full(len(funcs), -1, dtype=np.int64)

    CHUNK = 32 * 1024 * 1024  # 32M records = 256MB per chunk
    with open(path, "rb") as fh:
        base = 0
        while True:
            data = np.frombuffer(fh.read(CHUNK * 8), dtype=np.uint64)
            if len(data) == 0:
                break
            pc = (data >> np.uint64(16)).astype(np.uint32)
            alias = (pc >= 0x0C000000) & (pc < 0x0C200000)
            pc[alias] |= 0x80000000
            idx = np.searchsorted(ents, pc, side="right") - 1
            idxc = np.maximum(idx, 0)
            fen_sel = ents[idxc]
            fsz_sel = fsz[idxc]
            good = (idx >= 0) & (pc >= fen_sel) & (
                pc < fen_sel + np.maximum(fsz_sel, 1))
            ok = idxc[good]
            if len(ok):
                np.add.at(counts, ok, 1)
                uniq_c, firstpos = np.unique(ok, return_index=True)
                for u, pos in zip(uniq_c, firstpos):
                    if first_seen_idx[u] < 0:
                        first_seen_idx[u] = base + pos
            if base % (256 * 1024 * 1024) == 0:
                print(f"  ... at {base//1_000_000_000}G recs")
            base += len(data)

    with open(os.path.join(AN, "trace_fn_hits.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["fn", "hits"])
        for u in range(len(funcs)):
            if counts[u] > 0:
                w.writerow([f"0x{ents[u]:08X}", int(counts[u])])
    print("\n-- hottest functions --")
    hot = np.argsort(-counts)[:40]
    for u in hot:
        if counts[u] == 0:
            break
        print(f"  {funcs[u][2]:45s} 0x{ents[u]:08X} x{counts[u]:,}")
    print(f"\ndistinct functions: {(counts>0).sum()}")

    # first-seen CSV from chunk accumulator
    pairs = [(u, int(first_seen_idx[u]))
             for u in range(len(funcs)) if counts[u] > 0]
    pairs.sort(key=lambda t: t[1])
    with open(os.path.join(AN, "trace_fn_first_seen.csv"), "w",
              newline="") as f:
        w = csv.writer(f)
        w.writerow(["fn", "first_trace_idx"])
        for u, ti in pairs:
            w.writerow([f"0x{ents[u]:08X}", ti])
    print("\n-- first-seen order (top 50) --")
    for u, ti in pairs[:50]:
        print(f"  trace#{ti:>12,}  0x{ents[u]:08X}  {funcs[u][2]}")


if __name__ == "__main__":
    main()
