#!/usr/bin/env python3
"""port_backlog.py — ranked engine port backlog (trace heat first).

Joins:
  extract/analysis/funcs_1ST_READ.unsc.bin.csv  (baseline inventory)
  extract/analysis/trace_fn_hits.csv            (runtime heat; labels may be
                                                 internal, mapped to the
                                                 containing baseline fn)
  extract/analysis/disasm_*.calls.csv           (outgoing calls per fn)
  docs/decomp_status.csv                        (already ported)
  the SDK/decomp_stats buckets                 (already attributed)

Rank score = summed_hits * 1.0 + 40 * (leaf ? 1 : 0) - 0.05*size, but the
primary sort is heat; leaf and size break ties so the easiest hot functions
surface first.

Usage: python tools/port_backlog.py [--out extract/analysis/port_backlog.csv]
                                     [--top 40]
"""
from __future__ import annotations

import argparse
import bisect
import collections
import csv
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def load_funcs():
    rows = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            rows.append({"entry": int(r["entry"], 16), "size": int(r["size"]),
                         "name": r.get("name", "")})
    rows.sort(key=lambda r: r["entry"])
    return rows


def heat_map(funcs):
    entries = [f["entry"] for f in funcs]
    heat = collections.Counter()
    direct = collections.Counter()
    for r in csv.DictReader(open(AN / "trace_fn_hits.csv")):
        a = int(r["fn"], 16)
        h = int(r["hits"])
        i = bisect.bisect_right(entries, a) - 1
        if i < 0:
            continue
        e = entries[i]
        heat[e] += h
        if a == e:
            direct[e] += h
    return heat, direct


def out_calls():
    calls = collections.Counter()
    p = AN / "disasm_1ST_READ.unsc.bin.calls.csv"
    if not p.exists():
        return calls
    name2ent = {}
    for f in csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv")):
        name2ent[f.get("name", "")] = int(f["entry"], 16)
    for r in csv.DictReader(open(p)):
        if r["caller_fn"] in name2ent:
            calls[name2ent[r["caller_fn"]]] += 1
    return calls


def claimed():
    out = set()
    p = REPO / "docs" / "decomp_status.csv"
    if p.exists():
        for r in csv.DictReader(open(p)):
            out.add(int(r["entry"], 16))
    for name, col in (("libmask_matches.csv", "funcs"),):
        pass
    # SDK matches (union + sdk053) as fn entries
    for f in ("sdk_union_matches.csv",):
        q = AN / f
        if q.exists():
            for r in csv.DictReader(open(q)):
                if int(r["span_words"]) * 2 >= int(r["size"]):
                    out.add(int(r["entry"], 16))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="extract/analysis/port_backlog.csv")
    ap.add_argument("--top", type=int, default=40)
    a = ap.parse_args()

    funcs = load_funcs()
    heat, direct = heat_map(funcs)
    calls = out_calls()
    done = claimed()

    rows = []
    for f in funcs:
        e, s = f["entry"], f["size"]
        if e in done:
            continue
        h = heat.get(e, 0)
        oc = calls.get(e, 0)
        leaf = 1 if oc == 0 else 0
        score = h + (40 if leaf else 0) - 0.05 * s
        rows.append({"entry": f"0x{e:08x}", "name": f["name"], "size": s,
                     "hits": h, "direct_hits": direct.get(e, 0),
                     "out_calls": oc, "leaf": leaf, "score": f"{score:.0f}"})
    rows.sort(key=lambda r: (-int(r["score"]), r["entry"]))
    out = Path(a.out)
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["entry", "name", "size", "hits",
                                           "direct_hits", "out_calls", "leaf",
                                           "score"])
        w.writeheader()
        w.writerows(rows)
    print(f"port_backlog: {len(rows)} unclaimed fns -> {out}")
    print(f"{'entry':12} {'size':>6} {'hits':>9} {'calls':>5} {'leaf':>4}")
    for r in rows[:a.top]:
        print(f"{r['entry']:12} {r['size']:>6} {r['hits']:>9} "
              f"{r['out_calls']:>5} {r['leaf']:>4}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
