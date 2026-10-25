#!/usr/bin/env python3
"""gap_callees.py - the call targets of the still-unported bodies that the
Ghidra inventory does not cover.

A `--code-only` walk stops at the inventory's edge, so a callee outside it
would be routed to the router instead of being translated in place.  This
lists them, so the risk is measured instead of assumed.
"""
from __future__ import annotations

import csv
import json
import re
import struct
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
SRC = REPO / "src" / "fight"

img = (REPO / "extract" / "exe" / "1ST_READ.unsc.bin").read_bytes()


def word(pc):
    off = pc - 0x0C010000
    if off < 0 or off + 2 > len(img):
        return None
    return struct.unpack_from("<H", img, off)[0]


def sx(v, b):
    return v - (1 << b) if v & (1 << (b - 1)) else v


code = set()
for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
    code.update(range(int(row["start"], 16) & 0x1FFFFFFF,
                      int(row["end"], 16) & 0x1FFFFFFF, 2))
entries = {int(r["entry"], 16) & 0x1FFFFFFF for r in
           csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv", newline=""))}

br = defaultdict(list)
for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
    br[int(row["entry"], 16) & 0x1FFFFFFF].append(
        (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))

gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
outside = defaultdict(set)
total = 0
for g in gap:
    e = g["entry"] & 0x1FFFFFFF
    for s, t in br.get(e, []):
        for pc in range(s, t, 2):
            w = word(pc)
            if w is None:
                continue
            top, k = w >> 12, (w >> 8) & 15
            tgt = None
            if top == 0xB:                       # bsr
                tgt = pc + 4 + sx(w & 4095, 12) * 2
            elif (w & 0xF0FF) == 0x000B:        # jsr @Rn
                tgt = None                     # register indirect
            if tgt is None:
                continue
            total += 1
            if tgt not in code and tgt not in entries:
                outside[g["entry"]].add(tgt)
print(f"direct call sites in the gap bodies: {total}")
print(f"entries with a call target outside the inventory: {len(outside)}")
allt = sorted({t for v in outside.values() for t in v})
print(f"distinct such targets: {len(allt)}")
for t in allt[:20]:
    print(f"  0x{t:08x}")
