#!/usr/bin/env python3
"""gap_translation_diff.py - validate the new gap modules against the
translation that was already committed for the same bodies.

The repo's translator emits one C statement per SH-4 instruction, so the
statements under a `P_<pc>:` label *are* the instruction's semantics.  For
every gap entry whose body was already translated by an older module, the
statements of the two modules have to agree instruction by instruction: the
older module was replayed against the oracle, so it carries the oracle's
approval, and the new module was produced by the same emitter.

  python tools/gap_translation_diff.py
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
BUDGET = re.compile(r"^if\(!s->budget--\)")


def blocks(path: Path) -> dict[int, list[str]]:
    out: dict[int, list[str]] = {}
    cur = None
    for line in path.read_text(errors="ignore").splitlines():
        m = LABEL.match(line)
        if m:
            cur = int(m.group(1), 16)
            out.setdefault(cur, [])
            continue
        if cur is None:
            continue
        s = line.strip()
        if not s or BUDGET.match(s):
            continue
        if s.startswith("goto P_") or s.startswith("//"):
            continue
        out[cur].append(s)
    return out


def main() -> int:
    br = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16) & 0x1FFFFFFF].append(
            (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))

    allb: dict[int, list[tuple[str, list[str]]]] = defaultdict(list)
    for p in sorted(SRC.glob("*.c")):
        if p.name == "unknown.c":
            continue
        for pc, stmts in blocks(p).items():
            allb[pc].append((p.name, stmts))

    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    newmods = {f"vf3_gap_b{i:02d}_adapter.c" for i in range(1, 7)}
    same = diff = nopc = 0
    bad: list[str] = []
    for g in gap:
        e = g["entry"] & 0x1FFFFFFF
        body = []
        for s, t in br.get(e, []):
            body.extend(range(s, t, 2))
        for pc in body:
            entries = allb.get(pc, [])
            old = [(n, st) for n, st in entries if n not in newmods]
            new = [(n, st) for n, st in entries if n in newmods]
            if not new:
                nopc += 1
                continue
            if not old:
                continue
            olds = {tuple(st) for _, st in old}
            news = {tuple(st) for _, st in new}
            if olds & news:
                same += 1
            else:
                diff += 1
                if len(bad) < 20:
                    bad.append(f"0x{pc:08x} old={[ (n, st[:2]) for n, st in old][:1]} "
                               f"new={[(n, st[:2]) for n, st in new][:1]}")
    print(f"body PCs with an older and a new translation: same {same}, different {diff}")
    print(f"body PCs with no new translation: {nopc}")
    for b in bad:
        print("  ", b)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
