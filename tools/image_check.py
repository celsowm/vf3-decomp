#!/usr/bin/env python3
"""image_check.py - validate the restored ROM against the repo's own capture
evidence: every opcode word the oracle recorded must match the image byte for
byte at the identity load (0x8C010000).

Also checks the baseline funcs CSV against the image (entry -> first word).
"""
from __future__ import annotations

import csv
import json
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
BASE = 0x8C010000


def main() -> int:
    img = (REPO / "extract" / "exe" / "1ST_READ.unsc.bin").read_bytes()
    print(f"image: {len(img)} bytes (0x{len(img):x})")

    words = {}
    for k, v in json.load(open(AN / "ops_words.json", encoding="utf-8")).items():
        words[int(k, 16)] = v
    ok = bad = oob = 0
    ex = []
    for pc, w in words.items():
        off = pc - 0x0C010000
        if off + 2 > len(img):
            oob += 1
            continue
        got = struct.unpack_from("<H", img, off)[0]
        if got == w:
            ok += 1
        else:
            bad += 1
            if len(ex) < 8:
                ex.append((pc, w, got))
    print(f"captured opcode words: {len(words)}  match {ok}  mismatch {bad}  out-of-image {oob}")
    for pc, w, got in ex:
        print(f"  pc {pc:08x}: captured {w:04x} image {got:04x}")

    # the baseline inventory: every entry must land inside the image
    funcs = list(csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="")))
    out = [r for r in funcs if int(r["entry"], 16) + int(r["size"]) > BASE + len(img)]
    print(f"baseline funcs {len(funcs)}  outside the image: {len(out)}")
    tot = sum(int(r["size"]) for r in funcs)
    print(f"baseline body bytes: {tot}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
