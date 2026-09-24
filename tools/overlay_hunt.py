#!/usr/bin/env python3
"""Locate traced code in shipped game files (overlay resolver).

Interprets an interp-mode VF3 TRACE stream, collects executed pc->opcode,
extracts contiguous runs of >=N words, byte-packs them LE, and searches all
extract/gamedata files (and optionally a dtpk payload) for each run.

Usage: overlay_hunt.py <trace.bin> <lo_hex> <hi_hex> [min_words=12]
"""
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GD = os.path.join(REPO, "extract", "gamedata")
AN = os.path.join(REPO, "extract", "analysis")
BASE = 0x8C010000


def collect_ops(path):
    data = open(path, "rb").read()
    n = len(data) // 8
    ops = {}
    i = 0
    while i < n:
        (rec,) = struct.unpack_from("<Q", data, i * 8)
        i += 1
        tag = rec & 0xFFFF
        pc = rec >> 16
        if tag == 0xFA20:
            i += 3
            continue
        if tag in (0xFA10, 0xFA11, 0xFA21):
            continue
        pc8 = pc | 0x80000000
        if 0x8C010000 <= pc8 < 0x8E000000:
            ops[pc8] = rec & 0xFFFF
    return ops


def main():
    path, lo, hi = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
    minw = int(sys.argv[4]) if len(sys.argv) > 4 else 12
    ops = collect_ops(path)
    addrs = sorted(a for a in ops if lo <= a < hi)
    print(f"traced words in [{lo:#x},{hi:#x}): {len(addrs)}")

    # contiguous runs
    runs = []
    run = []
    last = None
    for a in addrs:
        if last is not None and a != last + 2:
            if len(run) >= minw:
                runs.append(run)
            run = []
        run.append(a)
        last = a
    if len(run) >= minw:
        runs.append(run)
    print(f"contiguous runs (>= {minw} words): {[(hex(r[0]), hex(r[-1]+2), len(r)) for r in runs]}")

    files = []
    for root, _, names in os.walk(GD):
        for nm in names:
            files.append(os.path.join(root, nm))
    print(f"searching {len(files)} game files...")

    for run in runs:
        pat = b"".join(struct.pack("<H", ops[a]) for a in run)
        hits = []
        for fp in files:
            blob = open(fp, "rb").read()
            p = blob.find(pat)
            if p >= 0:
                hits.append((fp, p))
        print(f"run {run[0]:#010x}..{run[-1]+2:#010x} ({len(run)}w): {len(hits)} file hits")
        for fp, p in hits[:5]:
            print(f"    {os.path.basename(fp)}  @0x{p:x}")


if __name__ == "__main__":
    main()
