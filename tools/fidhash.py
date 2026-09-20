#!/usr/bin/env python3
"""FID-style function digests for SH-4 binaries, and cross-build matching.

Digest = sha1 of the function's 16-bit instruction words after masking fields
whose bits are address/linker dependent. The result is stable across rebuilds
at different addresses, which is the same property Ghidra's Function ID relies
on (Full Hash), here implemented directly on raw words so it works on our raw
BinaryLoader programs and, later, on decoded SYSROF objects.

Masked fields (SH-4 word encodings, imm/disp zeroed; opcode+registers kept):
  A_yyy  bra disp12           -> A000      (target address)
  B_yyy  bsr disp12           -> B000      (target address)
  C0yy   mov.b @(disp,GBR),R0 -> C000 ;C1/C2 word/long versions likewise
  C4..C7 mov..#imm / add #imm -> Cn00
  C8..CF imm8 ops (tst/cmp/and/xor/eor/trapa) -> Cn00
  8nyy   bf/s etc disp8       -> 8n00 / 9n00 / 9nyy mov.w @(disp,PC),Rn
  Dnyy   mov.l @(disp,PC),Rn  -> Dn00      (literal-pool offset)
  Enyy   mov #imm,Rn          -> En00
  7nyy   add #imm,Rn          -> 7n00      (frame sizes may shift)
everything else verbatim.

Usage:
  # digest one image's function inventory (funcs CSV: entry,size,name)
  fidhash.py digests --image extract/exe/1ST_READ.unsc.bin \
      --funcs extract/analysis/funcs_1ST_READ.unsc.bin.csv --base 0x8C010000 \
      --out extract/analysis/fid_1ST_READ.csv

  # match two digest CSVs (retail vs E3)
  fidhash.py match extract/analysis/fid_1ST_READ.csv extract/analysis/fid_VF3TBE3.csv \
      --out extract/analysis/fid_matches.csv
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import sys
from pathlib import Path


def mask_word(w: int) -> int:
    top = w & 0xF000
    if top in (0xA000, 0xB000):
        return top
    if top == 0x8000 or top == 0x9000:      # 8n disp8; 9n mov.w @(disp,PC)
        return w & 0xFF00
    if top == 0xD000:                        # mov.l @(disp,PC),Rn
        return w & 0xFF00
    if top == 0xC000:
        n = (w >> 8) & 0xF
        return 0xC000 | (n << 8)             # all Cx ops carry imm8/disp8
    if top in (0xE000, 0x7000):              # mov / add #imm,Rn
        return w & 0xFF00
    return w


def digest_body(body: bytes) -> tuple[str, int]:
    """(sha1 of masked words, word count). Odd trailing byte ignored."""
    m = bytearray()
    n = len(body) // 2
    for i in range(n):
        w = body[2 * i] | (body[2 * i + 1] << 8)
        m += mask_word(w).to_bytes(2, "little")
    return hashlib.sha1(bytes(m)).hexdigest(), n


def cmd_digests(a) -> int:
    img = Path(a.image).read_bytes()
    base = int(a.base, 0)
    rows_out = []
    with open(a.funcs, newline="") as f:
        r = csv.DictReader(f)
        for row in r:
            entry = int(row["entry"], 16)
            size = int(row["size"])
            off = entry - base
            if off < 0 or off + size > len(img):
                continue
            h, nw = digest_body(img[off:off + size])
            rows_out.append((row["entry"], size, row.get("name", ""), h, nw))
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["entry", "size", "name", "digest", "nwords"])
        w.writerows(rows_out)
    print(f"digests: {len(rows_out)} -> {a.out}")
    return 0


def cmd_match(a) -> int:
    def load(p):
        d = {}
        with open(p, newline="") as f:
            for row in csv.DictReader(f):
                d.setdefault(row["digest"], []).append(row)
        return d

    na, nb = (Path(a.left).stem, Path(a.right).stem)
    la, lb = load(a.left), load(a.right)
    matched = [(g[0], h[0]) for dg in la for g in [la[dg]] for h in [lb.get(dg, [])] if h]
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow([f"{na}_entry", f"{na}_name", f"{nb}_entry", f"{nb}_name", "size"])
        for g, h in sorted(matched, key=lambda gh: int(gh[0]["entry"], 16)):
            w.writerow([g["entry"], g["name"], h["entry"], h["name"], g["size"]])
    uniq_a = sum(1 for v in la.values() if len(v) == 1)
    ambiguous = sum(len(v) - 1 for v in la.values() if len(v) > 1)
    print(f"match: {na}({sum(len(v) for v in la.values())}) vs {nb}({sum(len(v) for v in lb.values())})")
    print(f"  pairs: {len(matched)}  unique-digest on {na}: {uniq_a}  collisions(extra): {ambiguous}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("digests", help="digest every function of one image")
    p.add_argument("--image", required=True)
    p.add_argument("--funcs", required=True, help="funcs CSV (entry,size,name)")
    p.add_argument("--base", default="0x8C010000")
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_digests)

    p = sub.add_parser("match", help="match two digest CSVs 1:1 by digest")
    p.add_argument("left")
    p.add_argument("right")
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_match)

    a = ap.parse_args()
    return a.fn(a)


if __name__ == "__main__":
    sys.exit(main())
