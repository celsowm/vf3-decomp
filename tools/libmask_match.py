#!/usr/bin/env python3
"""libmask_match.py — masked-word SDK module attribution (M30).

Reuses fidhash.mask_word (zeroes address/linker-dependent fields so modules
built at different addresses still match) and sysrof._code_windows (CODE
section extraction from SYSROF .obj). Finds each library module's longest
masked-exact contiguous run inside the game image, then reports which
baseline functions fall inside the matched region.

Usage:
  python tools/libmask_match.py DIR [DIR...] --game extract/exe/1ST_READ.unsc.bin \
      --funcs extract/analysis/funcs_1ST_READ.unsc.bin.csv \
      --out extract/analysis/libmask_matches.csv
"""
from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fidhash import mask_word            # noqa: E402
from sysrof import _code_windows         # noqa: E402


def masked_words(data: bytes) -> list[int]:
    return [mask_word(data[2 * i] | (data[2 * i + 1] << 8))
            for i in range(len(data) // 2)]


def words_to_bytes(ws: list[int]) -> bytes:
    b = bytearray()
    for w in ws:
        b += w.to_bytes(2, "little")
    return bytes(b)


def build_index(game_words: list[int], probe_words: int = 8):
    """seed bytes -> list of game word indices (word-aligned only)."""
    gb = words_to_bytes(game_words)
    idx = {}
    step = 2  # word aligned
    n = len(gb)
    seed_len = probe_words * 2
    for at in range(0, n - seed_len + 1, step):
        idx.setdefault(bytes(gb[at:at + seed_len]), []).append(at // 2)
    return idx


def find_module(win_words: list[int], idx: dict, n_game: int,
                min_words: int = 12, probe_words: int = 8,
                max_hits_per_probe: int = 40):
    """Longest masked-exact run of win_words inside the indexed game words."""
    best = None
    n = len(win_words)
    if n < min_words:
        return None
    for o in range(0, n - probe_words + 1, 6):
        seed = words_to_bytes(win_words[o:o + probe_words])
        if len(set(win_words[o:o + probe_words])) < 4:
            continue  # degenerate (nop runs) seed
        hits = idx.get(seed)
        if not hits:
            continue
        for wa in hits[:max_hits_per_probe]:
            f = o + probe_words
            while f < n and wa + (f - o) < n_game and \
                    win_words[f] == gw[wa + (f - o)]:
                f += 1
            b = o
            while b > 0 and wa - (o - b) - 1 >= 0 and \
                    win_words[b - 1] == gw[wa - (o - b) - 1]:
                b -= 1
            span = f - b
            if best is None or span > best[1]:
                best = (b, span, wa - o + b)
    if best and best[1] >= min_words:
        return best  # (mod_off_words, span_words, game_word_index)
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("dir", nargs="+")
    ap.add_argument("--game", required=True)
    ap.add_argument("--funcs", required=True)
    ap.add_argument("--base", default="0x8C010000")
    ap.add_argument("--out", required=True)
    ap.add_argument("--min-words", type=int, default=12)
    a = ap.parse_args()

    game_raw = Path(a.game).read_bytes()
    base = int(a.base, 0)
    global gw
    gw = masked_words(game_raw)
    idx = build_index(gw)

    funcs = []
    with open(a.funcs, newline="") as f:
        for row in csv.DictReader(f):
            funcs.append((int(row["entry"], 16), int(row["size"]),
                          row.get("name", "")))

    rows = []
    for libdir in a.dir:
        lib = Path(libdir)
        for obj in sorted(lib.glob("*.obj")):
            data = obj.read_bytes()
            for (ws, we) in _code_windows(data):
                win = data[ws:we]
                ww = masked_words(win)
                m = find_module(ww, idx, len(gw), min_words=a.min_words)
                if not m:
                    continue
                mo, span, gwi = m
                gstart = base + gwi * 2
                gend = gstart + span * 2
                inside = [fn for fn in funcs
                          if gstart <= fn[0] < gend]
                rows.append({
                    "lib": lib.name,
                    "module": obj.stem,
                    "win_off": f"0x{ws + 2 * mo:x}",
                    "span_bytes": span * 2,
                    "game_start": f"0x{gstart:08x}",
                    "game_end": f"0x{gend:08x}",
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
    total = sum(r["span_bytes"] for r in rows)
    print(f"matched {len(rows)} module code windows, {total} B -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
