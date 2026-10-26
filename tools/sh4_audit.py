#!/usr/bin/env python3
"""sh4_audit.py - how much does tools/sh4.py actually decode?

The decoder is the reader for the game's code, so its holes are holes in every
listing built from it (tools/adapter_dump.py calls it).  Two numbers:

  * over the whole image - most of which is data (literal pools, textures), so
    this is a lower bound on the holes;
  * over the instructions the game actually executes (from a hits table), which
    is what a reader of the code runs into.

  python tools/sh4_audit.py [hits.csv]

A hits table is written by the reference emulator's instrument
(tools/refemu/vf3dump.c, VF3_HITS=...).
"""
import csv
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / 'tools'))
import sh4  # noqa: E402

IMAGE = REPO / 'extract' / 'gamedata' / '1ST_READ.BIN'
BASE = 0x8C010000
RAM = 0x0C010000          # the RAM copy of the image the game executes from


def main() -> int:
    if not IMAGE.exists():
        print(f'{IMAGE} is missing (the disc image); nothing to audit')
        return 0
    blob = IMAGE.read_bytes()
    words = len(blob) // 4
    holes = 0
    for i in range(words):
        w = int.from_bytes(blob[4 * i:4 * i + 2], 'little')   # the decoder takes 16-bit words
        if sh4.decode(w, BASE + 4 * i) is None:
            holes += 1
    print(f'whole image: {words} words, {holes} holes ({100.0 * holes / words:.2f}%)')

    if len(sys.argv) > 1:
        groups = {}
        bad = 0
        total = 0
        with open(sys.argv[1], newline='') as f:
            for row in csv.DictReader(f):
                pc = int(row['pc'], 16)
                if not (RAM <= pc < RAM + len(blob)):
                    continue
                off = pc - RAM
                w = int.from_bytes(blob[off:off + 2], 'little')
                total += 1
                if sh4.decode(w, pc) is None:
                    bad += 1
                    key = ((w >> 12) & 0xF, (w >> 4) & 0xF)
                    groups[key] = groups.get(key, 0) + 1
        print(f'executed instructions: {total}, {bad} holes ({100.0 * bad / max(total, 1):.2f}%)')
        for (grp, op), n in sorted(groups.items()):
            print(f'  group {grp:1x} row {op:1x} (bits 7-4): {n:6d}')
        return 1 if bad else 0
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
