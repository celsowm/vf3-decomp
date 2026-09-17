#!/usr/bin/env python3
"""MT*.BIN motion-table scanner.

Structure (established over 91 files):
  0x0000..0x22BF (shared): u32 slot table, 8880 entries; 0 = empty.
  payload start = min nonzero entry = 0x8AC0 on all files seen.
  records: [u32 header][bone-ctl bytes][float params] (variable length).
"""
import csv
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(REPO, "extract", "gamedata")
OUT = os.path.join(REPO, "extract", "analysis", "mt_tables")

SLOT_BYTES = 0x8AC1  # payload floor seen on all scanned files


def parse(path):
    d = open(path, "rb").read()
    n = len(d)
    slots = []
    last = 0x8AC0
    for i in range(0, SLOT_BYTES, 4):
        v = struct.unpack_from("<I", d, i)[0]
        if v and v < n:
            slots.append((i // 4, v))
    with_rec = []
    for k, (slot, off) in enumerate(slots):
        nxt = slots[k + 1][1] if k + 1 < len(slots) else n
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
        print(f"  {fn:16s} {c:5d} records")
    tot = sum(c for _, c in stat)
    print(f"{len(stat)} MT files, {tot} records total")


if __name__ == "__main__":
    main()
