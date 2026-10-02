#!/usr/bin/env python3
"""Static reachability census for the zero-hit baseline mass.

reach_census.py shows that 95% of uncovered baseline bytes belong to functions
that no archived scenario executes, so the capture-driven pipeline cannot reach
them. This tool separates that mass into two very different populations:

  live      : statically reachable from an executed function through code-flow
              edges. Real program code that current scenarios merely never
              reached. A new scenario could execute it.
  orphan    : no static code-flow path from any executed function. Ghidra
              seeds with no call path - data misidentified as code, alignment
              fragments, or genuinely dead code.

Only the `live` population is worth a scenario or port campaign; the `orphan`
population needs a validity screen before any of it can be credited.

Usage:
    python tools/reach_static.py [--min-size 0] [--orphans]
"""
from __future__ import annotations

import argparse
import collections
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
A = lambda *p: os.path.join(ROOT, "extract", "analysis", *p)

FUNCS = A("funcs_1ST_READ.unsc.bin.csv")
PLAN = A("port_plan_current.csv")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")
XREFS = A("xrefs_1ST_READ.unsc.bin.csv")
RESOLVED = A("sh4_resolved.csv")

FLOW_TYPES = {
    "UNCONDITIONAL_CALL",
    "CONDITIONAL_CALL",
    "COMPUTED_CALL",
    "UNCONDITIONAL_JUMP",
    "CONDITIONAL_JUMP",
    "COMPUTED_JUMP",
}


def hexint(text: str) -> int:
    return int(text.strip(), 16)


def load_baseline() -> list[tuple[int, int]]:
    with open(FUNCS, newline="") as fh:
        rows = [(hexint(r["entry"]), int(r["size"])) for r in csv.DictReader(fh)]
    rows.sort()
    return rows


def load_hits() -> dict[int, int]:
    """Prefer the merged per-state census; fall back to the port plan snapshot.

    port_plan_current.csv predates the batch 6-7 scenario captures and so
    understates execution. tools/merge_hits.py unions every archived survey.
    """
    merged = A("hits_merged.csv")
    if os.path.exists(merged):
        out: dict[int, int] = {}
        with open(merged, newline="") as fh:
            for r in csv.DictReader(fh):
                try:
                    out[hexint(r["entry"])] = int(r["hits"] or 0)
                except ValueError:
                    continue
        return out
    out = {}
    with open(PLAN, newline="") as fh:
        for r in csv.DictReader(fh):
            out[hexint(r["entry"])] = int(r["hits"] or 0)
    return out


def load_covered() -> set[int]:
    out = set()
    with open(LEDGER, newline="") as fh:
        for r in csv.DictReader(fh):
            e = (r.get("entry") or "").strip()
            if e:
                out.add(hexint(e))
    return out


def load_edges() -> dict[int, set[int]]:
    """Code-flow edges only. Data READ/WRITE refs are not program flow."""
    edges: dict[int, set[int]] = collections.defaultdict(set)
    with open(XREFS, newline="") as fh:
        for r in csv.DictReader(fh):
            if r["type"] not in FLOW_TYPES:
                continue
            edges[hexint(r["from"])].add(hexint(r["to"]))
    # STICALLY resolved computed-call/jump sites (gap@ and image-range targets)
    with open(RESOLVED, newline="") as fh:
        for r in csv.DictReader(fh):
            if r["class"] not in ("STATIC", "FIXED"):
                continue
            tgt = (r["target"] or "").strip()
            if not tgt:
                continue
            try:
                target = int(tgt.split("@")[-1], 16)
            except ValueError:
                continue
            edges[hexint(r["site"])].add(target)
    return edges


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-size", type=int, default=0)
    ap.add_argument("--orphans", action="store_true", help="list the largest orphans")
    ap.add_argument("--top", type=int, default=30)
    ap.add_argument("--roots", default="",
                    help="comma-separated hex address roots; replaces the "
                         "executed-function roots (e.g. 0x8C010000,0x8C020000) "
                         "so orphans can be screened against true-image "
                         "reachability from the program entrypoint")
    args = ap.parse_args()

    baseline = load_baseline()
    hits = load_hits()
    covered = load_covered()
    sizes = dict(baseline)
    entries = {a for a, _ in baseline}

    edges = load_edges()

    # roots: every baseline function observed executing, covered or not —
    # unless --roots overrides them with explicit address roots (which need
    # not be baseline entries; the CRT0/startup chain is not).
    if args.roots:
        roots = set()
        for tok in args.roots.split(","):
            tok = tok.strip()
            if tok:
                roots.add(int(tok, 16))
    else:
        roots = {a for a in entries if hits.get(a, 0) > 0}
    # Reverse map: address -> owning baseline function (for intra-body edges)
    owner: dict[int, int] = {}
    for a, sz in baseline:
        for off in range(0, max(sz, 1) * 2, 2):
            owner[a + off] = a
        owner[a] = a

    seen_functions = {a for a in roots if a in entries}
    seen_addrs = set()
    queue = collections.deque()
    for a in roots:
        for off in range(0, max(sizes.get(a, 1), 1) * 2, 2):
            seen_addrs.add(a + off)

    # BFS over addresses; entering an address that starts a baseline function
    # pulls that whole function into the live set.
    queue.extend(sorted(seen_addrs))
    while queue:
        pc = queue.popleft()
        f = owner.get(pc)
        if f is not None and f not in seen_functions:
            seen_functions.add(f)
            sz = sizes.get(f, 0)
            for off in range(0, max(sz, 1) * 2, 2):
                if f + off not in seen_addrs:
                    seen_addrs.add(f + off)
                    queue.append(f + off)
        for nxt in edges.get(pc, ()):
            if nxt not in seen_addrs:
                seen_addrs.add(nxt)
                queue.append(nxt)

    uncovered = [(a, s) for a, s in baseline if a not in covered]
    live = [(a, s) for a, s in uncovered if a in seen_functions]
    orphan = [(a, s) for a, s in uncovered if a not in seen_functions]

    def mass(rows):
        return len(rows), sum(s for _, s in rows)

    lb, lby = mass(live)
    ob, oby = mass(orphan)
    tb, tby = mass(uncovered)
    print("baseline           : %d fns / %d B" % (len(baseline), sum(s for _, s in baseline)))
    print("covered (ledger)   : %d fns / %d B" % (len(covered), sum(s for a, s in baseline if a in covered)))
    print("uncovered          : %d fns / %d B" % (tb, tby))
    print()
    print("== uncovered by static reachability from executed roots ==")
    print("%-10s %7s %10s %8s" % ("class", "fns", "bytes", "%unc"))
    print("%-10s %7d %10d %7.1f%%" % ("live", lb, lby, 100.0 * lby / tby if tby else 0))
    print("%-10s %7d %10d %7.1f%%" % ("orphan", ob, oby, 100.0 * oby / tby if tby else 0))
    print()

    # Of the live mass, how much is already covered vs is fresh prize?
    print("== live uncovered by size band ==")
    bands = [(0, 32), (32, 64), (64, 128), (128, 256), (256, 512), (512, 1024), (1024, 1 << 30)]
    print("%-14s %7s %10s" % ("size", "fns", "bytes"))
    for lo, hi in bands:
        g = [(a, s) for a, s in live if lo <= s < hi]
        if g:
            print("%-14s %7d %10d" % ("%d-%s" % (lo, hi if hi < (1 << 30) else "up"), len(g), sum(s for _, s in g)))
    print()

    # page-level concentration of the live mass
    print("== live uncovered by 64K page (top 15) ==")
    pages = collections.defaultdict(lambda: [0, 0])
    for a, s in live:
        p = a >> 16
        pages[p][0] += 1
        pages[p][1] += s
    for p, (n, b) in sorted(pages.items(), key=lambda kv: -kv[1][1])[:15]:
        print("  %08X  %5d fns %8d B" % (p << 16, n, b))
    print()

    if args.orphans:
        print("== largest orphans (no static path from any executed fn) ==")
        orphan.sort(key=lambda r: -r[1])
        for a, s in orphan[: args.top]:
            print("  %08X %6d B hits=%d" % (a, s, hits.get(a, 0)))

    return 0


if __name__ == "__main__":
    sys.exit(main())
