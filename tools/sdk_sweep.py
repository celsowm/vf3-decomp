#!/usr/bin/env python3
"""sdk_sweep.py — union-corpus SDK attribution sweep for game functions.

Runs the sdk053_match token matcher (masked words + literal-pool wildcards)
for every baseline function against one or more carved corpora:

  blob:PREFIX   PREFIX.bin + PREFIX.csv manifest (iso_carve.py output)
  dir:DIR       every *.obj/*.lib/*.elf in DIR, seam-separated
  file:PATH     a single raw file

Output: extract/analysis/sdk_union_matches.csv with the best match per
function (corpus, region/source, version banner when present, span, coverage).
A match is only accepted when the matched span lies fully inside one carved
region (no cross-seam false positives).

Usage:
  python tools/sdk_sweep.py --corpus blob:extract/analysis/sdk_corpus/sdk8eu \
      --corpus blob:extract/analysis/sdk053_samples \
      --funcs extract/analysis/funcs_1ST_READ.unsc.bin.csv \
      --game extract/exe/1ST_READ.unsc.bin \
      --out extract/analysis/sdk_union_matches.csv [--min-words 5]
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from array import array
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from fidhash import mask_word
from sdk053_match import find, make_tokens

BASE = 0x8C010000
SEAM = b"\x00" * 64
_BANNER = re.compile(rb"[ -~]{6,80}")


def ascii_runs(d: bytes):
    for m in _BANNER.finditer(d):
        yield m.group().decode("ascii", "replace")


def banner_for(raw: bytes, start: int, end: int, key=("GDFS", "Ver", "Build",
                                                    "LIBRARY", "NAOMI", "libsnd",
                                                    "Kamui", "Ninja", "NINJA",
                                                    "SH4", "Katana")):
    """First informative version banner in a region (bounded read)."""
    seg = raw[start:min(end, start + 4 * 1024 * 1024)]
    hits = []
    for s in ascii_runs(seg):
        if any(k.lower() in s.lower() for k in key):
            hits.append(s)
            if len(hits) >= 1:
                break
    return hits[0] if hits else ""


def load_blob(prefix: Path):
    b = prefix.with_suffix(".bin")
    c = prefix.with_suffix(".csv")
    if not b.exists():
        raise SystemExit(f"missing corpus blob {b}")
    raw = b.read_bytes()
    intervals = []
    names = {}
    if c.exists():
        with open(c, newline="") as f:
            for r in csv.DictReader(f):
                s = int(r["blob_off"])
                e = s + int(r["size"])
                intervals.append((s, e, r["source"], r.get("kind", "")))
                names[s] = r["source"]
    else:
        intervals.append((0, len(raw), b.name, "blob"))
    return raw, intervals


def load_dir(d: Path):
    parts = []
    intervals = []
    off = 0
    for p in sorted(d.rglob("*")):
        if p.suffix.lower() not in (".obj", ".lib", ".elf", ".o", ".a"):
            continue
        try:
            data = p.read_bytes()
        except OSError:
            continue
        if len(data) < 32:
            continue
        parts.append(data)
        intervals.append((off, off + len(data), str(p), "obj"))
        off += len(data) + len(SEAM)
        parts.append(SEAM)
    return b"".join(parts), intervals


def load_file(p: Path):
    raw = p.read_bytes()
    return raw, [(0, len(raw), p.name, "file")]


def load_corpus(spec: str):
    kind, _, rest = spec.partition(":")
    if kind == "blob":
        return load_blob(Path(rest))
    if kind == "dir":
        return load_dir(Path(rest))
    if kind == "file":
        return load_file(Path(rest))
    raise SystemExit(f"bad corpus spec {spec!r}")


def inside(intervals, start, end):
    for s, e, src, k in intervals:
        if s <= start and end <= e:
            return src, k
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--corpus", action="append", required=True)
    ap.add_argument("--funcs", required=True)
    ap.add_argument("--game", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--min-words", type=int, default=5)
    a = ap.parse_args()

    game = Path(a.game).read_bytes()
    funcs = []
    with open(a.funcs, newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))

    best: dict[int, dict] = {}
    for spec in a.corpus:
        raw, intervals = load_corpus(spec)
        n = len(raw) // 2
        gmask = array("H", (mask_word(raw[2 * i] | (raw[2 * i + 1] << 8))
                            for i in range(n)))
        gbytes = gmask.tobytes()
        hits = 0
        for ent, size, name in funcs:
            off = ent - BASE
            if size < a.min_words * 2 or off < 0 or off + size > len(game):
                continue
            m = find(make_tokens(game[off:off + size], off), gmask, gbytes,
                     0, len(gbytes), a.min_words)
            if not m:
                continue
            span = m[1]
            gs, ge = m[0] * 2, (m[0] + span) * 2
            reg = inside(intervals, gs, ge)
            if not reg:
                continue
            cov = span * 2 / size
            cur = best.get(ent)
            if cur and cur["span_words"] >= span:
                continue
            src, kind = reg
            best[ent] = {
                "entry": f"0x{ent:08x}", "name": name, "size": size,
                "corpus": spec,
                "region": src, "kind": kind,
                "blob_off": f"0x{gs:x}", "span_words": span,
                "coverage": f"{cov:.2f}",
                "banner": banner_for(raw, gs, ge),
            }
            hits += 1
        print(f"{spec}: {hits} fn matches so far")
        del gmask, gbytes, raw

    rows = sorted(best.values(), key=lambda r: int(r["entry"], 16))
    out = Path(a.out)
    with open(out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "name", "size", "corpus",
                                          "region", "kind", "blob_off",
                                          "span_words", "coverage", "banner"])
        w.writeheader()
        w.writerows(rows)
    full = [r for r in rows if int(r["span_words"]) * 2 >= int(r["size"])]
    print(f"sdk_sweep: {len(rows)} matched, {len(full)} full-body -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
