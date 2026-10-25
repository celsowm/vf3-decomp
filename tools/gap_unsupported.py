#!/usr/bin/env python3
"""gap_unsupported.py - which gap entries own an instruction the translator
cannot express?  (An unsupported instruction makes its block fail closed.)"""
from __future__ import annotations

import csv
import json
import re
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
SRC = REPO / "src" / "fight"

FAIL = re.compile(r"^s->failed_pc=0x([0-9a-f]+)u; return 0;$", re.M)

br = defaultdict(list)
for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
    br[int(row["entry"], 16) & 0x1FFFFFFF].append(
        (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))

bad = defaultdict(list)
for p in sorted(SRC.glob("vf3_gap_b*.c")):
    t = p.read_text(errors="ignore")
    for m in FAIL.finditer(t):
        bad[int(m.group(1), 16) & 0x1FFFFFFF].append(p.name)

gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
rows = []
for g in gap:
    e = g["entry"] & 0x1FFFFFFF
    own = []
    for s, t in br.get(e, []):
        for pc in range(s, t, 2):
            if pc in bad:
                own.append(pc)
    rows.append({"entry": g["entry"], "new": g["new"], "unsupported": own})

hit = [r for r in rows if r["unsupported"]]
print(f"gap entries with an unexpressible instruction in their own body: "
      f"{len(hit)} / {len(rows)}  ({sum(r['new'] for r in hit)} B)")
for r in sorted(hit, key=lambda r: -r["new"]):
    print(f"  0x{r['entry']:08X} {r['new']:5d} B  "
          f"{[hex(p) for p in r['unsupported'][:6]]}")
(AN / "gap_unsupported.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")
