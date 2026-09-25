#!/usr/bin/env python3
"""verify_libmask2.py — spot-verify relocation-aware matches (L2 acceptance).

For requested match rows, recompute the module-window token stream, walk it
against the game image at the reported location, and report:
  - matched words / window words (cover)
  - wildcard (literal-pool) positions inside the matched run
  - whether any concrete token mismatches (should be zero)
Also prints the game-side masked word sequence for eyeball + a sh4full hint.
"""
from __future__ import annotations

import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fidhash import mask_word
from sysrof import _code_windows

REPO = Path(__file__).resolve().parent.parent
BASE = 0x8C010000


def tokens(win_bytes, win_off):
    n = len(win_bytes) // 2
    words = [win_bytes[2 * i] | (win_bytes[2 * i + 1] << 8) for i in range(n)]
    bad = set()
    for i, w in enumerate(words):
        top = w & 0xF000
        if top == 0xD000:
            pb = ((win_off + i * 2 + 4) & ~3) + (w & 0xFF) * 4
            t = (pb - win_off) // 2
            bad.add(t); bad.add(t + 1)
        elif top == 0x9000:
            pb = (win_off + i * 2 + 4) + (w & 0xFF) * 2
            bad.add((pb - win_off) // 2)
    return [None if i in bad else mask_word(w) for i, w in enumerate(words)]


def main() -> int:
    targets = sys.argv[1:] or ["0x8c059de4", "0x8c0594b4", "0x8c05ec0e"]
    game = (REPO / "extract" / "exe" / "1ST_READ.unsc.bin").read_bytes()
    gn = len(game) // 2
    gmask = [mask_word(game[2 * i] | (game[2 * i + 1] << 8)) for i in range(gn)]
    rows = list(csv.DictReader(open(REPO / "extract" / "analysis" /
                                    "libmask2_matches.csv")))
    rc = 0
    for tgt in targets:
        row = next((r for r in rows if r["game_start"] == tgt), None)
        if not row:
            print(f"{tgt}: NOT FOUND in csv"); rc = 1; continue
        libdir = REPO / "extract" / "analysis" / "sysrof" / row["lib"]
        obj = libdir / f"{row['module']}.obj"
        d = obj.read_bytes()
        ws = int(row["win_off"], 16)
        gstart = int(row["game_start"], 16)
        span = int(row["span_bytes"])
        win = d[ws:ws + span]
        toks = tokens(win, ws)
        gw = (gstart - BASE) // 2
        mism = 0; wild = 0; conc = 0
        for i, t in enumerate(toks):
            if t is None:
                wild += 1; continue
            conc += 1
            if gmask[gw + i] != t:
                mism += 1
        cover = f"{conc}/{len(toks)}"
        ok = mism == 0
        rc |= 0 if ok else 1
        print(f"{tgt} {row['lib']}:{row['module']} span={span}B "
              f"concrete={cover} wildcards={wild} mismatches={mism} "
              f"{'OK' if ok else 'FAIL'}")
    print("verify_libmask2:", "PASS" if rc == 0 else "FAIL")
    return rc


if __name__ == "__main__":
    sys.exit(main())
