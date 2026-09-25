#!/usr/bin/env python3
"""libmask_match2.py — relocation-aware SDK matcher (L2).

Extends tools/libmask_match.py: in addition to fidhash.mask_word masking of
immediate/disp fields, the literal-pool dwords referenced by
mov.l/mov.w @(disp,PC) within a module's code window are treated as wildcards,
so a full code window can match across relocation.

Emits extract/analysis/libmask2_matches.csv with the same schema as
libmask_matches.csv. decomp_stats unions it.

Verification: tools/libmask_match2.py --verify spot-checks 5 matches via
sh4 dump; done outside this script (tools/sh4full.py).
"""
from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fidhash import mask_word
from sysrof import _code_windows

REPO = Path(__file__).resolve().parent.parent


def tokens(win_bytes: bytes, win_off: int):
    n = len(win_bytes) // 2
    words = [win_bytes[2 * i] | (win_bytes[2 * i + 1] << 8) for i in range(n)]
    bad = set()
    for i, w in enumerate(words):
        top = w & 0xF000
        if top == 0xD000:  # mov.l @(disp,PC),Rn -> dword (2 words)
            pool_byte = ((win_off + i * 2 + 4) & ~3) + (w & 0xFF) * 4
            t = (pool_byte - win_off) // 2
            bad.add(t); bad.add(t + 1)
        elif top == 0x9000:  # mov.w @(disp,PC),Rn -> word
            pool_byte = (win_off + i * 2 + 4) + (w & 0xFF) * 2
            t = (pool_byte - win_off) // 2
            bad.add(t)
    return [None if i in bad else mask_word(w) for i, w in enumerate(words)]


def find_span(toks, game_masked, gm_bytes, gn):
    nt = len(toks)
    if nt < 12:
        return None
    # seed: find a run of >=6 concrete tokens to probe
    s_i = None; s_v = None
    i = 0
    while i < nt - 5:
        if all(toks[i + k] is not None for k in range(6)):
            s_i = i; s_v = toks[i:i + 6]; break
        i += 1
    if s_i is None:
        return None
    sb = b"".join(x.to_bytes(2, "little") for x in s_v)
    best = None
    start = 0
    while True:
        gi = gm_bytes.find(sb, start)
        if gi < 0:
            break
        start = gi + 1
        if gi & 1:
            continue
        gw = gi // 2
        b = s_i; f = s_i + 6; gf = gw + 6
        while f < nt and gf < gn and (toks[f] is None or toks[f] == game_masked[gf]):
            f += 1; gf += 1
        while b > 0:
            gi2 = gw - (s_i - b) - 1
            if gi2 < 0:
                break
            if toks[b - 1] is None or toks[b - 1] == game_masked[gi2]:
                b -= 1
            else:
                break
        sp = f - b
        if best is None or sp > best[1]:
            best = (gw - (s_i - b), sp)
        if sp >= nt:
            break
    return best or None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("dir", nargs="+")
    ap.add_argument("--game", required=True)
    ap.add_argument("--funcs", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--min-words", type=int, default=24)
    a = ap.parse_args()

    game_raw = Path(a.game).read_bytes()
    gn = len(game_raw) // 2
    game_masked = [mask_word(game_raw[2 * i] | (game_raw[2 * i + 1] << 8))
                   for i in range(gn)]
    gm_bytes = b"".join(t.to_bytes(2, "little") for t in game_masked)

    funcs = []
    with open(a.funcs, newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))

    rows = []
    for libdir in a.dir:
        for obj in sorted(Path(libdir).glob("*.obj")):
            d = obj.read_bytes()
            for ws, we in _code_windows(d):
                win = d[ws:we]
                if len(win) < a.min_words * 2:
                    continue
                t = tokens(win, ws)
                m = find_span(t, game_masked, gm_bytes, gn)
                if not m or m[1] < a.min_words:
                    continue
                g_word, span = m
                gstart = Path(a.game).stem and (0x8C010000 + g_word * 2)
                gend = gstart + span * 2
                inside = [fn for fn in funcs if gstart <= fn[0] < gend]
                rows.append({
                    "lib": Path(libdir).name, "module": obj.stem,
                    "win_off": f"0x{ws:x}", "span_bytes": span * 2,
                    "game_start": f"0x{gstart:08x}", "game_end": f"0x{gend:08x}",
                    "n_funcs": len(inside),
                    "funcs": "|".join(fn[2] for fn in inside[:12]),
                })
    rows.sort(key=lambda r: -r["span_bytes"])
    with open(a.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()) if rows else
                           ["lib", "module", "win_off", "span_bytes",
                            "game_start", "game_end", "n_funcs", "funcs"])
        w.writeheader()
        w.writerows(rows)
    print(f"libmask2: {len(rows)} matched windows, "
          f"{sum(r['span_bytes'] for r in rows)} B -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
