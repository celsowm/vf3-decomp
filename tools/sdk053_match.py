#!/usr/bin/env python3
"""sdk053_match.py — attribute game functions against the GDFS-0.53 sample ELFs.

The Sega Library 1.00J ISO ships 14 SH-4 sample ELFs statically linked with
the *exact* game libraries (GDFS Version 0.53 1998/08/28, gdFs Ver 0.53
Build:Sep 07 1998). This tool takes each baseline function (or a restricted
set), builds a mask/pool-wildcard token stream, and searches the carved ELF
blob for a matching run. A match means the game function is byte-identical
(modulo relocated literal pools) to the SDK 0.53 build -> SDK attribution.

Usage:
  python tools/sdk053_match.py --blob extract/analysis/sdk053_samples.bin \
      --funcs extract/analysis/funcs_1ST_READ.unsc.bin.csv \
      --game extract/exe/1ST_READ.unsc.bin \
      --out extract/analysis/sdk053_matches.csv [--min-words N] [--lo HEX --hi HEX]
"""
from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fidhash import mask_word

BASE = 0x8C010000


def make_tokens(body: bytes, fn_off: int, reg_mask: bool = False):
    """Token stream for a function body: None = literal-pool wildcard."""
    n = len(body) // 2
    words = [body[2 * i] | (body[2 * i + 1] << 8) for i in range(n)]
    bad = set()
    for i, w in enumerate(words):
        top = w & 0xF000
        if top == 0xD000:  # mov.l @(disp,PC),Rn -> 2-word dword
            pool = ((fn_off + i * 2 + 4) & ~3) + (w & 0xFF) * 4
            t = (pool - fn_off) // 2
            bad.add(t); bad.add(t + 1)
        elif top == 0x9000:  # mov.w @(disp,PC),Rn -> 1 word
            pool = (fn_off + i * 2 + 4) + (w & 0xFF) * 2
            bad.add((pool - fn_off) // 2)
    def tok(w):
        if reg_mask:
            # opcode + low nibble only; zero register fields [11:4]
            return (w & 0xF00F)
        return mask_word(w)
    return [None if i in bad else tok(w) for i, w in enumerate(words)]


def find(tokens, gmask, gbytes, lo, hi, min_words):
    nt = len(tokens)
    if nt < min_words:
        return None
    # seed: run of >=6 concrete tokens
    s_i = None
    i = 0
    while i < nt - 5:
        if all(tokens[i + k] is not None for k in range(6)):
            s_i = i
            break
        i += 1
    if s_i is None:
        return None
    sb = b"".join(tokens[s_i + k].to_bytes(2, "little") for k in range(6))
    best = None
    pos = lo
    while True:
        gi = gbytes.find(sb, pos, hi)
        if gi < 0:
            break
        pos = gi + 1
        if gi & 1:
            continue
        gw = gi // 2
        b = s_i; f = s_i + 6; gf = gw + 6
        while f < nt and gf < len(gmask) and (tokens[f] is None or tokens[f] == gmask[gf]):
            f += 1; gf += 1
        while b > 0:
            gi2 = gw - (s_i - b) - 1
            if gi2 < 0:
                break
            if tokens[b - 1] is None or tokens[b - 1] == gmask[gi2]:
                b -= 1
            else:
                break
        if (f - b) >= nt:
            return gw - (s_i - b), nt
        if best is None or (f - b) > best[1]:
            best = (gw - (s_i - b), f - b)
    return best


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--blob", required=True)
    ap.add_argument("--funcs", required=True)
    ap.add_argument("--game", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--min-words", type=int, default=8)
    ap.add_argument("--lo", default=None)
    ap.add_argument("--hi", default=None)
    ap.add_argument("--reg-mask", action="store_true",
                    help="opcode-structural matching (zero register fields)")
    a = ap.parse_args()

    blob = Path(a.blob).read_bytes()
    gn = len(blob) // 2
    if a.reg_mask:
        gmask = [(blob[2 * i] | (blob[2 * i + 1] << 8)) & 0xF00F
                 for i in range(gn)]
    else:
        gmask = [mask_word(blob[2 * i] | (blob[2 * i + 1] << 8))
                 for i in range(gn)]
    gbytes = b"".join(t.to_bytes(2, "little") for t in gmask)
    lo = int(a.lo, 0) if a.lo else 0
    hi = int(a.hi, 0) if a.hi else len(blob)

    game = Path(a.game).read_bytes()
    funcs = []
    with open(a.funcs, newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))

    rows = []
    for ent, size, name in funcs:
        off = ent - BASE
        if size < a.min_words * 2 or off < 0 or off + size > len(game):
            continue
        toks = make_tokens(game[off:off + size], off, reg_mask=a.reg_mask)
        m = find(toks, gmask, gbytes, lo, hi, a.min_words)
        if m:
            rows.append({"entry": f"0x{ent:08x}", "name": name,
                         "size": size, "blob_off": f"0x{m[0] * 2:x}",
                         "span_words": m[1]})
    with open(a.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "name", "size",
                                          "blob_off", "span_words"])
        w.writeheader()
        w.writerows(rows)
    full = [r for r in rows if r["span_words"] * 2 >= r["size"]]
    print(f"sdk053: {len(rows)} partial matches, {len(full)} full-body matches "
          f"-> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())