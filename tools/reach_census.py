#!/usr/bin/env python3
"""Reachability census: how much remaining coverage can the trace method supply?

The porting pipeline so far is capture-driven: a baseline body earns credit
only after a golden replay against an emulator trace. That method can never
reach a function no archived scenario executes. This tool splits the uncovered
baseline into buckets by observed execution and static closure, so planning can
tell capture-bound work apart from capture-impossible work.

Buckets
  executed   : hits > 0        -> capture is possible today
  zero-hit   : hits == 0       -> needs a new scenario, or a non-trace method
  closure_ok : closure_ok == Y -> every callee is resolvable by static analysis
"""
from __future__ import annotations

import csv
import os
import sys
import collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PLAN = os.path.join(ROOT, "extract", "analysis", "port_plan_current.csv")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")


def load_plan() -> list[dict]:
    with open(PLAN, newline="") as fh:
        return list(csv.DictReader(fh))


def covered_entries() -> set[int]:
    out = set()
    with open(LEDGER, newline="") as fh:
        for row in csv.DictReader(fh):
            raw = (row.get("entry") or "").strip().lower()
            if not raw:
                continue
            try:
                out.add(int(raw, 16))
            except ValueError:
                continue
    return out


def as_int(row: dict, key: str, default: int = 0) -> int:
    try:
        return int(row.get(key) or default)
    except ValueError:
        return default


def main() -> int:
    plan = load_plan()
    covered = covered_entries()

    def entry_of(row: dict) -> int:
        try:
            return int((row.get("entry") or "0").strip(), 16)
        except ValueError:
            return 0

    rows = [r for r in plan if entry_of(r) and entry_of(r) not in covered]
    total_bytes = sum(as_int(r, "size") for r in rows)
    print("baseline total : %d fns / %d B" % (len(plan), sum(as_int(r, "size") for r in plan)))
    print("uncovered      : %d fns / %d B" % (len(rows), total_bytes))
    print()

    # execution split
    exec_rows = [r for r in rows if as_int(r, "hits") > 0]
    zero_rows = [r for r in rows if as_int(r, "hits") == 0]
    print("== by observed execution ==")
    print("%-12s %7s %10s %7s" % ("bucket", "fns", "bytes", "%bytes"))
    for name, group in (("executed", exec_rows), ("zero-hit", zero_rows)):
        b = sum(as_int(r, "size") for r in group)
        print("%-12s %7d %10d %6.1f%%"
              % (name, len(group), b, 100.0 * b / total_bytes if total_bytes else 0))
    print()

    # cross with static closure
    print("== executed x closure_ok ==")
    print("%-10s %-12s %7s %10s" % ("closure", "bucket", "fns", "bytes"))
    grid = collections.defaultdict(lambda: [0, 0])
    for r in rows:
        cok = (r.get("closure_ok") or "").strip().upper() == "Y"
        ex = as_int(r, "hits") > 0
        key = ("Y" if cok else "N", "executed" if ex else "zero-hit")
        grid[key][0] += 1
        grid[key][1] += as_int(r, "size")
    for key in sorted(grid):
        n, b = grid[key]
        print("%-10s %-12s %7d %10d" % (key[0], key[1], n, b))
    print()

    # size mass of zero-hit work
    print("== zero-hit uncovered by size ==")
    buckets = [(0, 32), (32, 64), (64, 128), (128, 256), (256, 512),
               (512, 1024), (1024, 4096), (4096, 1 << 30)]
    print("%-14s %7s %10s" % ("size", "fns", "bytes"))
    for lo, hi in buckets:
        g = [r for r in zero_rows if lo <= as_int(r, "size") < hi]
        b = sum(as_int(r, "size") for r in g)
        if g:
            print("%-14s %7d %10d" % ("%d-%d" % (lo, min(hi, 4096) if hi < (1 << 30) else 0), len(g), b))
    print()

    # campaign tagging of the executed+closure-ok pool
    print("== executed & closure_ok by campaign ==")
    pool = [r for r in rows if as_int(r, "hits") > 0
            and (r.get("closure_ok") or "").strip().upper() == "Y"]
    camp = collections.defaultdict(lambda: [0, 0])
    for r in pool:
        c = (r.get("campaign") or "?").strip()
        camp[c][0] += 1
        camp[c][1] += as_int(r, "size")
    for c, (n, b) in sorted(camp.items(), key=lambda kv: -kv[1][1]):
        print("campaign %-4s %6d fns %9d B" % (c, n, b))
    print()
    print("executed+closure_ok pool: %d fns / %d B" % (len(pool), sum(as_int(r, "size") for r in pool)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
