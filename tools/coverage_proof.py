#!/usr/bin/env python3
"""coverage_proof.py - the proof that the baseline is fully covered.

The metric is a *body-range union*: the union of the ported entries' body
ranges has to contain every baseline function's body.  This prints the
baseline bytes the union misses, if any.
"""
from __future__ import annotations

import csv
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def main() -> int:
    funcs = list(csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="")))
    br = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16)].append(
            (int(row["start"], 16), int(row["end"], 16)))

    ported, extra = set(), []
    baseline_entries = {int(f["entry"], 16) for f in funcs}
    for r in csv.DictReader(open(REPO / "docs" / "decomp_status.csv", newline="")):
        if not r.get("status", "").startswith("ported"):
            continue
        e = int(r["entry"], 16)
        if e in baseline_entries:
            ported.add(e)
        else:
            extra.append((e, int(r.get("size") or 0)))

    # the baseline's own address set
    baseline = set()
    for f in funcs:
        for s, t in br[int(f["entry"], 16)]:
            baseline.update(range(s, t, 2))

    # the union of the ported entries' body ranges
    spans = []
    for f in funcs:
        e = int(f["entry"], 16)
        if e in ported:
            spans += br[e]
    spans += [(e, e + s) for e, s in extra]
    merged = []
    for s, t in sorted(spans):
        if merged and s <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], t)
        else:
            merged.append([s, t])

    covered = set()
    for s, t in merged:
        covered.update(range(s, t, 2))
    missing = baseline - covered
    tot = len(baseline)
    print(f"baseline functions: {len(funcs)} ({tot} halfwords)")
    print(f"ported baseline entries: {len(ported)}")
    print(f"baseline halfwords covered by the union: {tot - len(missing)} / {tot} "
          f"({100*(tot-len(missing))/tot:.4f}%)")
    if missing:
        by_entry = {}
        for f in funcs:
            e = int(f["entry"], 16)
            miss = [pc for s, t in br[e] for pc in range(s, t, 2) if pc in missing]
            if miss:
                by_entry[e] = miss
        print(f"entries with uncovered body: {len(by_entry)}")
        for e, miss in list(by_entry.items())[:10]:
            print(f"  0x{e:08x}: {len(miss)} halfwords missing")
    print(f"union bytes: {sum(t - s for s, t in merged)}")
    return 1 if missing else 0


if __name__ == "__main__":
    raise SystemExit(main())
