#!/usr/bin/env python3
"""gap_reach.py - for each still-unported baseline entry, which captured
entry's corpus *reaches* it?

A capture map (f_<entry>.ops.json) holds the whole call tree the oracle
executed for that entry, so a gap entry whose PCs appear in another entry's
map was executed during that entry's capture: a strict replay of that corpus
exercises the gap entry and its exit state carries the effect.
"""
from __future__ import annotations

import csv
import json
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def main() -> int:
    br = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16) & 0x1FFFFFFF].append(
            (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))

    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    # entry -> the pcs that identify it
    entry_pcs = {g["entry"] & 0x1FFFFFFF: set() for g in gap}
    for e in entry_pcs:
        for s, t in br.get(e, []):
            entry_pcs[e].update(range(s, t, 2))

    reach = defaultdict(list)
    nfiles = 0
    for p in AN.rglob("*.ops.json"):
        try:
            d = json.load(open(p, encoding="utf-8"))
        except Exception:
            continue
        if not isinstance(d, dict):
            continue
        nfiles += 1
        pcs = {int(k, 16) & 0x1FFFFFFF for k in d}
        stem = p.stem[2:]          # f_<entry> -> <entry>
        for e, want in entry_pcs.items():
            if e in pcs:
                reach[e].append(stem)
    print(f"{nfiles} capture maps scanned")
    rows = []
    for g in gap:
        e = g["entry"] & 0x1FFFFFFF
        r = sorted(set(reach.get(e, [])))
        rows.append({"entry": g["entry"], "new": g["new"], "reached_by": r})
    (AN / "gap_reach.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")
    got = [r for r in rows if r["reached_by"]]
    print(f"gap entries reached by some capture: {len(got)} / {len(rows)} "
          f"({sum(r['new'] for r in got)} B of {sum(r['new'] for r in rows)} B)")
    for r in sorted(got, key=lambda r: -r["new"])[:25]:
        print(f"  0x{r['entry']:08X} {r['new']:5d} B  reached by "
              f"{', '.join(r['reached_by'][:6])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
