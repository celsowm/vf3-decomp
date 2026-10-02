#!/usr/bin/env python3
"""Merge every archived per-state hit survey into one execution table.

extract/analysis/port_plan_current.csv carries a `hits` column, but that file
predates the batch 6-7 scenario captures, so it understates how much of the
baseline has actually executed. Every campaign wrote its own
hits_*.csv survey; this tool unions them all so planning decisions rest on the
full archived corpus rather than one stale snapshot.

Usage:
    python tools/merge_hits.py --out extract/analysis/hits_merged.csv
    python tools/merge_hits.py --stats
"""
from __future__ import annotations

import argparse
import collections
import csv
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
A = os.path.join(ROOT, "extract", "analysis")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")
FUNCS = os.path.join(A, "funcs_1ST_READ.unsc.bin.csv")
DEFAULT_OUT = os.path.join(A, "hits_merged.csv")


def baseline() -> dict[int, int]:
    out = {}
    with open(FUNCS, newline="") as fh:
        for r in csv.DictReader(fh):
            out[int(r["entry"], 16)] = int(r["size"])
    return out


def covered() -> set[int]:
    out = set()
    with open(LEDGER, newline="") as fh:
        for r in csv.DictReader(fh):
            e = (r.get("entry") or "").strip()
            if e:
                out.add(int(e, 16))
    return out


def merge() -> tuple[dict[int, int], dict[int, set[str]], list[str]]:
    """Return (total hits, states seen per entry, source files)."""
    totals: dict[int, int] = collections.defaultdict(int)
    states: dict[int, set[str]] = collections.defaultdict(set)
    used: list[str] = []
    for path in sorted(glob.glob(os.path.join(A, "hits_*.csv"))):
        base = os.path.basename(path)[len("hits_"):-len(".csv")]
        try:
            with open(path, newline="") as fh:
                rows = list(csv.DictReader(fh))
        except OSError:
            continue
        seen = 0
        for r in rows:
            raw = (r.get("entry") or "").strip()
            if not raw:
                continue
            try:
                addr = int(raw, 16)
                hits = int(r.get("hits") or 0)
            except ValueError:
                continue
            if hits:
                totals[addr] += hits
                states[addr].add(base)
                seen += 1
        if seen:
            used.append("%s(%d)" % (base, seen))
    return dict(totals), {k: v for k, v in states.items()}, used


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--stats", action="store_true")
    args = ap.parse_args()

    totals, states, used = merge()
    inv = baseline()
    cov = covered()
    print("hit surveys merged : %d files with data" % len(used))
    print("entries observed   : %d / %d baseline" % (len(totals), len(inv)))

    unc = {a: s for a, s in inv.items() if a not in cov}
    ex = [a for a in unc if totals.get(a, 0) > 0]
    zero = [a for a in unc if totals.get(a, 0) == 0]
    exb = sum(inv[a] for a in ex)
    zerob = sum(inv[a] for a in zero)
    print()
    print("== uncovered baseline, fresh execution census ==")
    print("%-12s %7s %10s %8s" % ("bucket", "fns", "bytes", "%unc"))
    print("%-12s %7d %10d %7.1f%%" % ("executed", len(ex), exb, 100.0 * exb / (exb + zerob)))
    print("%-12s %7d %10d %7.1f%%" % ("zero-hit", len(zero), zerob, 100.0 * zerob / (exb + zerob)))
    print("uncovered total    : %d fns / %d B" % (len(unc), exb + zerob))

    if states:
        multi = sum(1 for a in ex if len(states[a]) >= 3)
        print()
        print("executed uncovered seen in >=3 distinct surveys: %d" % multi)

    with open(args.out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["entry", "size", "hits", "surveys"])
        for a in sorted(inv):
            w.writerow(["0x%08X" % a, inv[a], totals.get(a, 0), len(states.get(a, ()))])
    print()
    print("wrote %s" % os.path.relpath(args.out, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
