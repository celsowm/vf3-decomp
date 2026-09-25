#!/usr/bin/env python3
"""port_plan.py — regenerable port roadmap joining heat, call graph and claims.

Joins:
  extract/analysis/funcs_1ST_READ.unsc.bin.csv      baseline inventory
  extract/analysis/port_backlog.csv                 heat (hits/leaf/out_calls)
  extract/analysis/disasm_1ST_READ.unsc.bin.calls.csv  static call edges
  extract/analysis/trace_fn_hits.csv                executed set (containment)
  SDK/libmask claim CSVs + docs/decomp_status.csv   accounted set

and emits extract/analysis/port_plan.csv with a campaign tag:
  A  hot small (hits>=10k)
  B  executed but not hot
  C  never executed (lowest priority)
plus closure_ok (all resolved callees already ported/accounted) and effort.

Usage: python tools/port_plan.py [--out extract/analysis/port_plan.csv]
"""
from __future__ import annotations

import argparse
import bisect
import csv
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
AN = REPO / "extract" / "analysis"


def load_funcs():
    rows = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))
    rows.sort()
    return rows


def containing(starts, funcs, addr):
    i = bisect.bisect_right(starts, addr) - 1
    if i < 0:
        return None
    ent, size, _ = funcs[i]
    if addr < ent + size:
        return ent
    return None


def sdk_claims():
    """Entry set that is SDK-attributed (full-body)."""
    out = set()
    for name, key in (("libmask_matches.csv", None),
                      ("libmask2_matches.csv", None),
                      ("v040_shinobi_libmask.csv", None),
                      ("v040_ninja_libmask.csv", None)):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            out.add(int(r["game_start"], 16))       # region roots
    for name in ("sdk053_matches.csv", "sdk_union_matches.csv"):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            if int(r["span_words"]) * 2 >= int(r["size"]):
                out.add(int(r["entry"], 16))
    return out


def region_claims():
    regs = []
    for name in ("libmask_matches.csv", "libmask2_matches.csv",
                 "v040_shinobi_libmask.csv", "v040_ninja_libmask.csv"):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            regs.append((int(r["game_start"], 16), int(r["game_end"], 16)))
    regs.sort()
    return regs


def in_regions(regs, addr):
    for a, b in regs:
        if a <= addr < b:
            return True
        if a > addr:
            return False
    return False


def ported():
    out = set()
    p = REPO / "docs" / "decomp_status.csv"
    if p.exists():
        for r in csv.DictReader(open(p, newline="")):
            if r.get("status", "").startswith("ported"):
                out.add(int(r["entry"], 16))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="extract/analysis/port_plan.csv")
    a = ap.parse_args()

    funcs = load_funcs()
    starts = [e for e, _, _ in funcs]
    F = {e: (s, n) for e, s, n in funcs}

    hits = {}
    with open(AN / "trace_fn_hits.csv", newline="") as f:
        for r in csv.DictReader(f):
            ent = containing(starts, funcs, int(r["fn"], 16))
            if ent is not None:
                hits[ent] = hits.get(ent, 0) + int(r["hits"])
    executed = set(hits)

    backlog = {}
    with open(AN / "port_backlog.csv", newline="") as f:
        for r in csv.DictReader(f):
            ent = int(r["entry"], 16)
            backlog[ent] = r
            bh = int(r.get("hits", 0))
            if bh > 0:
                executed.add(ent)
            if bh > hits.get(ent, 0):
                hits[ent] = bh

    calls = defaultdict(set)
    with open(AN / "disasm_1ST_READ.unsc.bin.calls.csv", newline="") as f:
        for r in csv.DictReader(f):
            caller = containing(starts, funcs, int(r["call_site"], 16))
            if caller is None:
                continue
            target = int(r["target"], 16)
            callee = containing(starts, funcs, target)
            calls[caller].add(callee if callee is not None else target)

    sdk = sdk_claims()
    regs = region_claims()
    done = ported()
    # an entry is accounted if it is SDK-matched, inside an SDK region, or ported
    def accounted(e):
        return e in sdk or in_regions(regs, e) or e in done

    rows = []
    for ent, size, name in funcs:
        h = hits.get(ent, 0)
        bl = backlog.get(ent, {})
        callees = sorted(calls.get(ent, set()))
        resolved = [c for c in callees if c in F]
        unresolved = [c for c in callees if c not in F]
        missing = [c for c in resolved if c != ent and not accounted(c)]
        closure_ok = len(missing) == 0
        if accounted(ent):
            camp = "accounted"
        elif h >= 10000:
            camp = "A"
        elif ent in executed:
            camp = "B"
        elif bl:
            camp = "C"
        else:
            camp = "D"
        if size <= 64:
            effort = "S"
        elif size <= 256:
            effort = "M"
        elif size <= 1024:
            effort = "L"
        else:
            effort = "XL"
        rows.append({
            "entry": f"0x{ent:08X}", "name": name, "size": size,
            "hits": h, "leaf": bl.get("leaf", ""),
            "out_calls": bl.get("out_calls", len(callees)),
            "campaign": camp, "effort": effort,
            "executed": "Y" if ent in executed else "-",
            "closure_ok": "Y" if closure_ok else "-",
            "missing_callees": " ".join(f"0x{c:08X}" for c in missing[:8]),
            "page": f"0x{(ent >> 16):02x}",
            "score": h * max(size, 16),
        })
    rows.sort(key=lambda r: (-r["score"], r["entry"]))
    outp = Path(a.out)
    with open(outp, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "name", "size", "hits",
                                          "leaf", "out_calls", "campaign",
                                          "effort", "executed", "closure_ok",
                                          "missing_callees", "page", "score"])
        w.writeheader()
        w.writerows(rows)
    by_camp = defaultdict(lambda: [0, 0])
    for r in rows:
        by_camp[r["campaign"]][0] += 1
        by_camp[r["campaign"]][1] += r["size"]
    print(f"port_plan: {outp}")
    for c in sorted(by_camp):
        n, b = by_camp[c]
        print(f"  campaign {c}: {n} fns / {b} B")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())