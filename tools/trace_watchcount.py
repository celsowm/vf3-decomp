#!/usr/bin/env python3
"""trace_watchcount.py — one-pass execution histogram over a VF3 flycast
pc+op trace (record = u64: pc<<16 | op; bit16 = exception marker).

Usage:
  python tools/trace_watchcount.py extract/analysis/trace_boot3.bin \
      --watch 0x8c034864,0x8c0349aa,0x8c0796f4,0x8c0b1a54 --out CSV
Prints per-pc hit counts and first/last record indices — the empirical
anchor the ported frame engine (M25/M34/M35) is diffed against (M36).
"""
from __future__ import annotations

import argparse
import struct
import sys


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--watch", required=True)
    ap.add_argument("--out", default="")
    a = ap.parse_args()

    watch = {}
    for n, w in enumerate(a.watch.split(",")):
        v = int(w, 0)
        watch[v] = n
        # SH4 P1 cached (0x8C) / physical (0x0C) aliases are both seen in
        # old traces; count both.
        if 0x8C000000 <= v < 0x8D000000:
            watch[v - 0x80000000] = n
        elif 0x0C000000 <= v < 0x0D000000:
            watch[v + 0x80000000] = n
    hits = [0] * len(watch)
    first = [-1] * len(watch)
    last = [-1] * len(watch)

    chunk = 1 << 22
    rec = 0
    with open(a.trace, "rb") as f:
        while True:
            buf = f.read(chunk)
            if not buf:
                break
            n = len(buf) // 8
            for i, u in enumerate(struct.iter_unpack("<Q", buf[:n * 8])):
                v = u[0]
                if v & 0x10000:
                    continue
                pc = v >> 16
                idx = watch.get(pc)
                if idx is not None:
                    hits[idx] += 1
                    if first[idx] < 0:
                        first[idx] = rec + i
                    last[idx] = rec + i
            rec += n

    lines = ["pc,hits,first_rec,last_rec"]
    for w, i in sorted(((w, i) for w, i in watch.items())):
        lines.append(f"0x{w:08x},{hits[i]},{first[i]},{last[i]}")
    out = "\n".join(lines)
    if a.out:
        with open(a.out, "w", newline="") as f:
            f.write(out + "\n")
    print(out)
    print(f"scanned {rec} records")
    return 0


if __name__ == "__main__":
    sys.exit(main())
