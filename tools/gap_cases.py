#!/usr/bin/env python3
"""gap_cases.py - which gap entries own a .cases corpus (the corpus sidecar
the strict replay needs), using exactly the discovery rule of
tools/replay_scan.py:corpora_map."""
from __future__ import annotations

import json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"

cmap: dict[str, list] = {}
for c in sorted(AN.rglob("f_*.cases")):
    cmap.setdefault(c.stem[2:], []).append(c.parent)

gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
rows = []
for g in gap:
    e = f"{g['entry'] & 0x1FFFFFFF:08x}"
    dirs = cmap.get(e, [])
    rows.append({"entry": g["entry"], "new": g["new"], "n_corpora": len(dirs),
                 "corpora": [str(d.relative_to(REPO)) for d in dirs]})
(AN / "gap_cases.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")
have = [r for r in rows if r["n_corpora"]]
print(f"gap entries with a .cases corpus: {len(have)} / {len(rows)} "
      f"({sum(r['new'] for r in have)} B of {sum(r['new'] for r in rows)} B)")
for r in sorted(have, key=lambda r: -r["new"])[:20]:
    print(f"  0x{r['entry']:08X} {r['new']:5d} B  {r['corpora'][0]}")
