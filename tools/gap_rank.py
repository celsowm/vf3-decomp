#!/usr/bin/env python3
"""gap_rank.py — rank the entries that would still add bytes to the verified
C address union (docs/coverage.md's "Verified C address union").

Coverage is a *body-range union*: promoting an entry whose body is nested
inside an already-ported entry adds nothing.  This ranks the remaining
baseline entries by the bytes they would actually add.
"""
from __future__ import annotations

import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def load():
    funcs = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            funcs.append({"entry": int(r["entry"], 16),
                          "size": int(r["size"]),
                          "name": r.get("name", "")})
    br = defaultdict(list)
    with open(AN / "function_body_ranges.csv", newline="") as f:
        for row in csv.DictReader(f):
            br[int(row["entry"], 16)].append((int(row["start"], 16),
                                             int(row["end"], 16)))
    rows = list(csv.DictReader(open(REPO / "docs" / "decomp_status.csv", newline="")))
    baseline = {f["entry"] for f in funcs}
    ported, extra = set(), []
    for r in rows:
        ent = int(r["entry"], 16)
        if r.get("status", "").startswith("ported"):
            if ent in baseline:
                ported.add(ent)
            else:
                extra.append((ent, int(r.get("size") or 0), r["file"]))
    return funcs, br, ported, extra


def merge(spans):
    out = []
    for s, e in sorted(spans):
        if out and s <= out[-1][1]:
            out[-1][1] = max(out[-1][1], e)
        else:
            out.append([s, e])
    return out


def main() -> int:
    funcs, br, ported, extra = load()
    spans = []
    for f in funcs:
        if f["entry"] in ported:
            spans += br[f["entry"]]
    spans += [(e, e + s) for e, s, _ in extra]
    merged = merge(spans)
    tot = sum(f["size"] for f in funcs)
    cov = sum(e - s for s, e in merged)

    # bytes of each unported entry that are NOT already covered by another
    # ported entry's body span
    un = []
    for f in funcs:
        if f["entry"] in ported:
            continue
        newb = 0
        for s, e in br[f["entry"]]:
            covered = 0
            for ms, me in merged:
                lo, hi = max(s, ms), min(e, me)
                if hi > lo:
                    covered += hi - lo
            newb += (e - s) - covered
        un.append({"entry": f["entry"], "size": f["size"], "new": newb,
                   "name": f["name"]})
    un.sort(key=lambda r: -r["new"])
    print(f"union {cov}/{tot} = {100*cov/tot:.4f}%  remaining {tot-cov}")
    print(f"unported baseline fns: {len(un)}  sum(size) {sum(r['size'] for r in un)}"
          f"  sum(new) {sum(r['new'] for r in un)}")
    top = int(sys.argv[1]) if len(sys.argv) > 1 else 40
    for r in un[:top]:
        print(f"  0x{r['entry']:08X} new {r['new']:5d} B  size {r['size']:5d} B  {r['name']}")
    (AN / "gap_rank.json").write_text(json.dumps(un, indent=1), encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
