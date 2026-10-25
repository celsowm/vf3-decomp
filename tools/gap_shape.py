#!/usr/bin/env python3
"""gap_shape.py - classify the still-unported entries by the shape of their
generated body: how many guest PCs it spans, how many calls it makes, and
whether it touches the FP unit.  Ranks the pool so the cheapest leaves come
first and the big dispatchers come last.
"""
from __future__ import annotations

import csv
import json
import re
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
SRC = REPO / "src" / "fight"

LABEL = re.compile(r"^P_([0-9a-f]{8}):")


def bodies():
    out = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        cur = None
        blocks = {}
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            m = LABEL.match(line)
            if m:
                cur = int(m.group(1), 16)
                blocks[cur] = []
                continue
            if cur is not None:
                s = line.strip()
                if s and not s.startswith("if(!s->budget--)"):
                    blocks[cur].append(s)
        out[path.stem] = blocks
    return out


def main() -> int:
    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    br = defaultdict(list)
    with open(AN / "function_body_ranges.csv", newline="") as f:
        for row in csv.DictReader(f):
            br[int(row["entry"], 16)].append((int(row["start"], 16), int(row["end"], 16)))

    allb = bodies()
    # flatten every module's blocks into one pc -> statements map
    flat = {}
    for stem, blocks in allb.items():
        for pc, body in blocks.items():
            flat.setdefault(pc, []).append((stem, body))

    rows = []
    for g in gap:
        e = g["entry"]
        lo, hi = min(s for s, _ in br[e]), max(z for _, z in br[e])
        calls, fp, nstmt, nblocks = 0, 0, 0, 0
        mods = set()
        for pc in range(lo & 0x1FFFFFFF, hi & 0x1FFFFFFF, 2):
            for stem, body in flat.get(pc, ()):
                nblocks += 1
                mods.add(stem)
                for s in body:
                    nstmt += 1
                    if "vf3_matrix_family(" in s or "target=" in s:
                        calls += 1
                    if re.search(r"\bv\[\d+\]|fr\d+|vf3_fpu", s):
                        fp += 1
        rows.append({"entry": e, "new": g["new"], "size": g["size"],
                     "nblocks": nblocks, "calls": calls, "fp": fp,
                     "nstmt": nstmt, "mods": sorted(mods)})
    (AN / "gap_shape.json").write_text(json.dumps(rows, indent=1), encoding="utf-8")

    leaves = [r for r in rows if r["calls"] == 0 and r["nstmt"]]
    withgen = [r for r in rows if r["nstmt"]]
    print(f"{len(rows)} entries; {len(withgen)} have a generated translation; "
          f"{len(leaves)} of them are call-free leaves "
          f"({sum(r['new'] for r in leaves)} B)")
    print(f"no generated translation: {len(rows)-len(withgen)} entries, "
          f"{sum(r['new'] for r in rows if not r['nstmt'])} B")
    print("\n-- leaves with a translation, biggest first --")
    for r in sorted(leaves, key=lambda r: -r["new"])[:25]:
        print(f"  0x{r['entry']:08X} {r['new']:5d} B  stmts {r['nstmt']:4d}  fp {r['fp']:4d}")
    print("\n-- with calls, smallest first --")
    for r in sorted([r for r in withgen if r["calls"]], key=lambda r: r["new"])[:25]:
        print(f"  0x{r['entry']:08X} {r['new']:5d} B  calls {r['calls']:3d}  stmts {r['nstmt']:4d}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
