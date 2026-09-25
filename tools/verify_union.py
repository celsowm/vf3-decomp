#!/usr/bin/env python3
"""verify_union.py — independent verification of sdk_union_matches.csv.

For every full-body match, re-reads the corpus bytes and compares the raw
16-bit words against the game function:

  concrete mismatch = a word whose *unmasked* fields (opcode + registers)
                      differ from the corpus word, excluding the PC-relative
                      literal-pool slots the matcher treats as wildcards.
  allowed difference = branch target / disp8 / imm8 / pool slot variation.

Writes extract/analysis/sdk_union_verify.txt with a summary and a
side-by-side capstone disassembly of the largest new matches.

Usage (venv python recommended, capstone optional):
  tools/.venv/Scripts/python tools/verify_union.py [--top 8]
"""
from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
from fidhash import mask_word
from sdk053_match import make_tokens
from sdk_sweep import load_corpus

BASE = 0x8C010000
AN = REPO / "extract" / "analysis"


def classify(game_body: bytes, fn_off: int, corpus: bytes):
    """Return (concrete, allowed, words, cwords) for one match."""
    gt = make_tokens(game_body, fn_off)
    n = min(len(game_body), len(corpus)) // 2
    concrete = allowed = 0
    words, cwords = [], []
    for i in range(n):
        gw = game_body[2 * i] | (game_body[2 * i + 1] << 8)
        cw = corpus[2 * i] | (corpus[2 * i + 1] << 8)
        words.append(gw)
        cwords.append(cw)
        if gw == cw:
            continue
        if gt[i] is None or mask_word(gw) == mask_word(cw):
            allowed += 1
        else:
            concrete += 1
    return concrete, allowed, words, cwords


def disasm(data: bytes, base_off: int, nbytes: int):
    try:
        from capstone import CS_ARCH_SH, CS_MODE_SH4, CS_MODE_LITTLE_ENDIAN, Cs
    except Exception:
        return [f"    (raw) {' '.join(f'{data[base_off + 2 * i] | (data[base_off + 2 * i + 1] << 8):04x}' for i in range(min(nbytes // 2, 24)))}"]
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)
    out = []
    for ins in md.disasm(data[base_off:base_off + nbytes], 0x8C010000 + base_off):
        out.append(f"    {ins.address:08x}  {ins.mnemonic:<10} {ins.op_str}")
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=8)
    ap.add_argument("--min-size", type=int, default=32)
    a = ap.parse_args()

    rows = list(csv.DictReader(open(AN / "sdk_union_matches.csv")))
    full = [r for r in rows if int(r["span_words"]) * 2 >= int(r["size"])]
    game = (REPO / "extract" / "exe" / "1ST_READ.unsc.bin").read_bytes()

    old = {r["entry"] for r in csv.DictReader(open(AN / "sdk053_matches.csv"))
           if int(r["span_words"]) * 2 >= int(r["size"])}
    new = [r for r in full if r["entry"] not in old]

    corpus_cache: dict[str, bytes] = {}
    results = []
    for r in new:
        ent = int(r["entry"], 16)
        size = int(r["size"])
        boff = int(r["blob_off"], 16)
        spec = r.get("corpus") or "blob:extract/analysis/sdk_corpus/sdk8eu"
        entry = corpus_cache.get(spec)
        if entry is None:
            entry = corpus_cache[spec] = load_corpus(spec)[0]
        blob = entry
        if boff + size > len(blob):
            # fall back to the biggest blob that can host the offset
            for alt in ("blob:extract/analysis/sdk_corpus/sdk8eu",
                        "blob:extract/analysis/sdk053_samples"):
                b = corpus_cache.get(alt)
                if b is None:
                    b = corpus_cache[alt] = load_corpus(alt)[0]
                if boff + size <= len(b):
                    blob = b
                    break
            else:
                results.append((ent, size, r, -1, -1, None, None))
                continue
        c, al, w, cw = classify(game[ent - BASE:ent - BASE + size],
                                ent - BASE, blob[boff:boff + size])
        results.append((ent, size, r, c, al, w, cw))

    ok = [x for x in results if x[3] == 0]
    bad = [x for x in results if x[3] != 0]
    lines = [
        "# SDK union-corpus verification (independent re-derivation)",
        "",
        f"new full-body matches: {len(new)} (size>={a.min_size} shown below)",
        f"0 concrete mismatch: {len(ok)} / {len(results)}",
        f"concrete mismatches: {len(bad)}",
        "",
        "| entry | size | corpus region | concrete | allowed diff |",
        "|---|---|---|---|---|",
    ]
    for ent, size, r, c, al, w, cw in sorted(results, key=lambda x: -x[1]):
        lines.append(f"| 0x{ent:08x} | {size} | {r['region'][-70:]} | {c} | {al} |")
    lines.append("")
    big = [x for x in sorted(results, key=lambda x: -x[1])
           if x[1] >= a.min_size][:a.top]
    for ent, size, r, c, al, w, cw in big:
        lines += [f"## 0x{ent:08x} ({size} B) vs {r['region'][-70:]}",
                  f"concrete={c} allowed={al}", "```", "  game:", *disasm(
                      game, ent - BASE, size)[:24]]
        spec = r.get("corpus") or "blob:extract/analysis/sdk_corpus/sdk8eu"
        blob = corpus_cache.get(spec)
        if blob is None:
            blob = load_corpus(spec)[0]
        lines += ["  corpus:", *disasm(blob, int(r["blob_off"], 16), size)[:24], "```", ""]
    out = AN / "sdk_union_verify.txt"
    out.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"verify: {len(ok)}/{len(results)} new full matches with "
          f"0 concrete mismatch -> {out}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
