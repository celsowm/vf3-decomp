#!/usr/bin/env python3
"""ops_coverage.py - build the global pc->opcode-word map from every capture
map in extract/analysis (f_*.ops.json) and measure how much of each
still-unported baseline entry's body it covers.

The ROM image (extract/exe/1ST_READ.unsc.bin) is not in the workspace, so the
capture maps are the only source of SH-4 opcode words we have.
"""
from __future__ import annotations

import csv
import json
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def main() -> int:
    words = {}
    nfiles = 0
    for p in AN.rglob("*.ops.json"):
        try:
            d = json.load(open(p, encoding="utf-8"))
        except Exception:
            continue
        if not isinstance(d, dict):
            continue
        nfiles += 1
        for k, v in d.items():
            try:
                pc = int(k, 16) & 0x1FFFFFFF
                w = int(v, 16)
            except Exception:
                continue
            old = words.get(pc)
            if old is not None and old != w:
                print(f"CONFLICT at {pc:08x}: {old:04x} vs {w:04x} ({p.name})")
            words[pc] = w
    print(f"{nfiles} capture maps, {len(words)} distinct pcs")
    (AN / "ops_words.json").write_text(json.dumps({f"{k:08x}": v for k, v in words.items()}),
                                       encoding="utf-8")

    br = defaultdict(list)
    with open(AN / "function_body_ranges.csv", newline="") as f:
        for row in csv.DictReader(f):
            br[int(row["entry"], 16) & 0x1FFFFFFF].append(
                (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))
    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    tot_b = tot_h = 0
    rows = []
    for g in gap:
        e = g["entry"] & 0x1FFFFFFF
        body = br.get(e, [])
        nb = nh = 0
        for s, t in body:
            nb += (t - s)
            for pc in range(s, t, 2):
                if pc in words:
                    nh += 1
        tot_b += nb
        tot_h += nh
        rows.append({"entry": g["entry"], "new": g["new"], "body": nb, "have": nh})
    (AN / "gap_ops_coverage.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")
    print(f"gap body bytes {tot_b}, covered by capture words {tot_h} "
          f"({100*tot_h/max(1,tot_b):.1f}%)")
    full = [r for r in rows if r["body"] and r["have"] == r["body"]]
    part = [r for r in rows if 0 < r["have"] < r["body"]]
    none = [r for r in rows if r["have"] == 0]
    print(f"entries fully covered: {len(full)} ({sum(r['new'] for r in full)} B)")
    print(f"entries partly covered: {len(part)} ({sum(r['new'] for r in part)} B)")
    print(f"entries not covered at all: {len(none)} ({sum(r['new'] for r in none)} B)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
