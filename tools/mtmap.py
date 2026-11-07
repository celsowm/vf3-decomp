#!/usr/bin/env python3
"""MT*.BIN motion-table scanner.

Structure (established over 91 files):
  0x0000..0x8ABF (shared): u32 slot table, 8880 entries; 0 = empty.
  payload start = min nonzero entry = 0x8AC0 on all files seen.
  offsets are not ordered by slot; equal offsets alias the same payload span.
  a span ends at the next greater distinct offset, or at EOF.
  payload field meanings remain only partially mapped.
"""
import csv
import os
import struct
import sys
from bisect import bisect_right

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(REPO, "extract", "gamedata")
OUT = os.path.join(REPO, "extract", "analysis", "mt_tables")

SLOT_COUNT = 8880
SLOT_BYTES = SLOT_COUNT * 4
PAYLOAD_FLOOR = SLOT_BYTES


def parse(path):
    d = open(path, "rb").read()
    n = len(d)
    slots = []
    if n < PAYLOAD_FLOOR:
        raise ValueError(f"{path}: file is shorter than its {SLOT_COUNT}-slot table")
    for slot in range(SLOT_COUNT):
        v = struct.unpack_from("<I", d, slot * 4)[0]
        if not v:
            continue
        if v < PAYLOAD_FLOOR or v >= n:
            raise ValueError(f"{path}: slot {slot} has invalid offset 0x{v:X}")
        slots.append((slot, v))
    offsets = sorted({off for _, off in slots})
    with_rec = []
    for slot, off in slots:
        index = bisect_right(offsets, off)
        nxt = offsets[index] if index < len(offsets) else n
        with_rec.append((slot, off, nxt - off))
    return with_rec


def main():
    os.makedirs(OUT, exist_ok=True)
    files = sorted(f for f in os.listdir(SRC)
                   if f.startswith("MT") and f.endswith(".BIN"))
    import collections
    stat = []
    for fn in files:
        recs = parse(os.path.join(SRC, fn))
        p = os.path.join(OUT, fn.replace(".BIN", ".csv"))
        with open(p, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["slot", "offset", "size"])
            for slot, off, size in recs:
                w.writerow([slot, f"0x{off:06X}", size])
        stat.append((fn, len(recs)))
    for fn, c in stat:
        print(f"  {fn:16s} {c:5d} slot references")
    tot = sum(c for _, c in stat)
    print(f"{len(stat)} MT files, {tot} nonzero slot references total")


if __name__ == "__main__":
    main()
