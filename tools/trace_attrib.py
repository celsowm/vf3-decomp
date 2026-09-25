#!/usr/bin/env python3
"""trace_attrib.py — trace-executed function attribution (L1 bucket).

Maps trace waypoint addresses (flycast VF3_TRACE hit/first-seen CSVs) into the
containing baseline function from funcs_1ST_READ.unsc.bin.csv. Emits
extract/analysis/trace_executed.csv for tools/decomp_stats.py.

Method: execution-identification ONLY. A credited fn ran during the captured
scene but is NOT byte-matched or ported here. Address normalization:
0x0Cxxxxxx P2 alias -> 0x8Cxxxxxx P1. Unmapped waypoints are listed with
are blank `containing_fn` rows (counted in `unmapped` tail).

Sources:
  extract/analysis/trace_fn_first_seen.csv  (union of fight+boot first-seen)
  extract/analysis/trace_fn_hits.csv        (hit counts)
"""
from __future__ import annotations

import bisect
import csv
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"

HEX_RE = re.compile(r"([0-9a-fA-F]{6,8})$")


def load_base() -> tuple[list[int], list[tuple[int, int, str]]]:
    rows = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))
    rows.sort()
    return [r[0] for r in rows], rows


def containing(ents, rows, addr):
    i = bisect.bisect_right(ents, addr) - 1
    if i >= 0:
        e, s, n = rows[i]
        if e <= addr < e + max(s, 1):
            return e, n
    return None, None


def norm_addr(name: str) -> int | None:
    m = HEX_RE.search(name.strip().lower().replace("0x", ""))
    if not m:
        return None
    v = int(m.group(1), 16)
    if v < 0x8C000000:
        v |= 0x80000000
    return v


def main() -> int:
    ents, rows = load_base()
    first_seen = {}
    hits = {}
    for path in ("trace_fn_first_seen.csv", "trace_fn_hits.csv"):
        p = AN / path
        if not p.exists():
            continue
        with open(p, newline="") as f:
            for r in csv.DictReader(f):
                v = norm_addr(r.get("fn", ""))
                if v is None:
                    continue
                if "first_trace_idx" in r:
                    first_seen[v] = int(r["first_trace_idx"])
                if "hits" in r:
                    hits[v] = int(r["hits"])

    out_rows = []
    mapped = set()
    for v in sorted(set(list(first_seen) + list(hits))):
        e, fname = containing(ents, rows, v)
        if e is None:
            out_rows.append({"trace_addr": f"0x{v:08x}",
                             "containing_fn": "",
                             "fn_entry": "",
                             "hits": hits.get(v, 0),
                             "first_trace_idx": first_seen.get(v, "")})
            continue
        mapped.add(e)
        out_rows.append({"trace_addr": f"0x{v:08x}",
                         "containing_fn": fname,
                         "fn_entry": f"0x{e:08x}",
                         "hits": hits.get(v, 0),
                         "first_trace_idx": first_seen.get(v, "")})

    out = AN / "trace_executed.csv"
    with open(out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["trace_addr", "containing_fn",
                                          "fn_entry", "hits",
                                          "first_trace_idx"])
        w.writeheader()
        w.writerows(out_rows)
    nmap = sum(1 for r in out_rows if not r["fn_entry"])
    print(f"trace_attrib: {len(mapped)} baseline fns carrying trace evidence"
          f" ({nmap} unmapped waypoints) -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
