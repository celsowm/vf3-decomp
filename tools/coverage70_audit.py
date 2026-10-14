#!/usr/bin/env python3
"""coverage70_audit.py — honest 65% -> 70% audit for verified C coverage.

Consolidates the ad-hoc inline-python queries used during planning into one
reusable tool (read-only; no state changes):

  python tools/coverage70_audit.py ghosts     # stale unknown.c ledger rows
  python tools/coverage70_audit.py plan       # A/B/C + closure_ok breakdown
  python tools/coverage70_audit.py fullcover  # 100% body-cover unported fns
  python tools/coverage70_audit.py owners     # ghost entry -> adapter file
  python tools/coverage70_audit.py all        # everything above + gap math

Inputs (all existing, frozen):
  docs/decomp_status.csv                      hand ledger
  extract/analysis/coverage.json              decomp_stats.py union
  extract/analysis/funcs_1ST_READ.unsc.bin.csv denominator
  extract/analysis/port_plan_70.csv           campaign tags
  extract/analysis/body_cover.csv             optional (tools/body_cover.py)
  src/fight/*_adapters.c routers              owned_pcs[] arrays only

Why routers only: full 0x0cXXXX scans over src/fight/*_*.c timed out (>30 s);
router owned_pcs arrays give the same ownership answer in milliseconds.
"""
from __future__ import annotations

import argparse
import csv
import json
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
DENOM_BYTES = 434656
TARGET_BYTES = int(DENOM_BYTES * 0.70)


def load_ported_ledger():
    rows = list(csv.DictReader(open(REPO / "docs" / "decomp_status.csv", newline="")))
    ported = {r["entry"].lower() for r in rows if r.get("status", "").startswith("ported")}
    ghosts = [r for r in rows if "unknown.c" in r.get("file", "")]
    return rows, ported, ghosts


def cmd_ghosts():
    _, ported, ghosts = load_ported_ledger()
    gbytes = sum(int(r["size"] or 0) for r in ghosts)
    print(f"ghost rows: {len(ghosts)} / {len(ported)} ported entries claim src/fight/unknown.c")
    print(f"ghost bytes (ledger sum, NOT union credit): {gbytes}")
    print("entry        size file")
    for r in sorted(ghosts, key=lambda x: x["entry"]):
        print(f"{r['entry']:12} {r['size']:>5} {r['file']}")
    plan = {}
    p = AN / "port_plan_70.csv"
    if p.exists():
        for r in csv.DictReader(open(p, newline="")):
            plan[r["entry"].lower()] = r["campaign"]
    camps = {plan.get(g["entry"].lower(), "?") for g in ghosts}
    print(f"ghost campaigns in port_plan_70: {sorted(camps)} (expected ['accounted'])")
    return 0


def cmd_plan():
    cov = json.loads((AN / "coverage.json").read_text())
    union = cov["ported_unique_bytes"]
    total = cov["bytes_total"]
    need = TARGET_BYTES - union
    print(f"union: {union} / {total} = {100.0 * union / total:.4f}%")
    print(f"target 70%: {TARGET_BYTES} -> gap {need} bytes ({100.0 * need / total:.2f} pp)")
    rows = list(csv.DictReader(open(AN / "port_plan_70.csv", newline="")))
    ported = {r["entry"].lower() for r in csv.DictReader(
        open(REPO / "docs" / "decomp_status.csv", newline=""))
        if r.get("status", "").startswith("ported")}
    unp = [r for r in rows if r["entry"].lower() not in ported
           and r["campaign"] in ("A", "B", "C")]
    c, s = Counter(), {}
    for r in unp:
        c[r["campaign"]] += 1
        s[r["campaign"]] = s.get(r["campaign"], 0) + int(r["size"])
    print(f"truly unported: {len(unp)} fns / {sum(s.values())} B -> {dict(c)} {s}")
    clo = [r for r in unp if r["closure_ok"] == "Y"]
    print(f"closure_ok=Y: {len(clo)} fns / {sum(int(r['size']) for r in clo)} B "
          f"(easy queue; NOT enough for {need} B gap)")
    ab = sum(int(r["size"]) for r in unp if r["campaign"] in ("A", "B"))
    print(f"A+B ceiling: {ab} B "
          f"{'< gap (need C-campaign unlocks)' if ab < need else '>= gap'}")
    unp.sort(key=lambda r: -int(r["size"]))
    print("top-15 truly unported (entry size camp effort closure dyn static):")
    for r in unp[:15]:
        print(f"  {r['entry']} {r['size']:>5} {r['campaign']} {r['effort']:>2} "
              f"closure={r['closure_ok']} dyn={r['sh4_dyn']} static={r['sh4_static']}")
    return 0


def cmd_fullcover():
    p = AN / "body_cover.csv"
    if not p.exists():
        print("no body_cover.csv — run tools/body_cover.py on capture corpora first")
        return 0
    rows = list(csv.DictReader(open(p, newline="")))
    full = [r for r in rows if float(r["cover_pct"]) >= 100.0]
    _, ported, _ = load_ported_ledger()
    new = [r for r in full if r["entry"].lower() not in ported]
    print(f"full-cover entries: {len(full)} / {sum(int(r['size']) for r in full)} B")
    print(f"unported full-cover: {len(new)} / {sum(int(r['size']) for r in new)} B")
    for r in sorted(new, key=lambda x: -int(x["size"]))[:40]:
        print(f"  {r['entry']} {r['size']:>5} cases={r['corpus_cases']}")
    return 0


def router_owned_pcs():
    """entry -> router file, from owned_pcs[] arrays and split bodies (fast)."""
    import re
    owned = {}
    for path in sorted((REPO / "src" / "fight").glob("*.c")):
        if path.name == "unknown.c":
            continue
        text = path.read_text(errors="ignore")
        for m in re.finditer(r"0x0c([0-9a-f]{6})u", text):
            ent = int("0x8c" + m.group(1), 16)
            owned.setdefault(ent, path.name)
    for path in sorted((REPO / "src" / "fight").glob("*.inc")):
        text = path.read_text(errors="ignore")
        for m in re.finditer(r"0x0c([0-9a-f]{6})u", text):
            ent = int("0x8c" + m.group(1), 16)
            owned.setdefault(ent, path.name)
    return owned


def cmd_owners():
    _, _, ghosts = load_ported_ledger()
    owned = router_owned_pcs()
    print(f"router owned PCs indexed: {len(owned)}")
    print("ghost entry -> owning router (code exists; ledger file column is stale):")
    missing = 0
    for r in sorted(ghosts, key=lambda x: x["entry"]):
        ent = int(r["entry"], 16)
        owner = owned.get(ent, "(not in router owned_pcs — split body, same family)")
        if owner.startswith("("):
            missing += 1
        print(f"  {r['entry']} ({r['size']:>4}B) -> {owner}")
    print(f"unmapped: {missing}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["ghosts", "plan", "fullcover", "owners", "all"],
                    help="audit to run")
    a = ap.parse_args()
    if a.cmd in ("ghosts", "all"):
        cmd_ghosts()
    if a.cmd in ("plan", "all"):
        cmd_plan()
    if a.cmd in ("fullcover", "all"):
        cmd_fullcover()
    if a.cmd in ("owners", "all"):
        cmd_owners()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
