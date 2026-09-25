#!/usr/bin/env python3
"""decomp_stats.py — decomp coverage dashboard (M31/M40 gate).

Joins:
  - extract/analysis/funcs_<prog>.csv       (baseline inventory)
  - extract/analysis/libmask_matches.csv    (SDK masked attribution, M30)
  - extract/analysis/katana_matches_true.csv (SDK exact-byte regions)
  - docs/decomp_status.csv                  (hand ledger: entry,status,file)
Writes docs/coverage.md + extract/analysis/coverage.json.
"""
from __future__ import annotations

import csv
import json
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def load_funcs():
    p = AN / "funcs_1ST_READ.unsc.bin.csv"
    rows = []
    with open(p, newline="") as f:
        for r in csv.DictReader(f):
            rows.append({"entry": int(r["entry"], 16),
                          "size": int(r["size"]),
                          "name": r.get("name", "")})
    return rows


def trace_executed():
    """fn entries with live-trace evidence (L1, execution-identification).
    NOT byte-matched or ported. Reads trace_executed.csv (tools/trace_attrib.py)."""
    out = set()
    p = AN / "trace_executed.csv"
    if p.exists():
        with open(p, newline="") as f:
            for r in csv.DictReader(f):
                if r.get("fn_entry"):
                    out.add(int(r["fn_entry"], 16))
    return out


def claimed_set():
    """entry -> (source, label) for attributed/ported functions."""
    claim = {}
    lm = AN / "libmask_matches.csv"
    if lm.exists():
        regions = []
        with open(lm, newline="") as f:
            for r in csv.DictReader(f):
                regions.append((int(r["game_start"], 16),
                                int(r["game_end"], 16),
                                f"{r['lib']}:{r['module']}"))
        regions.sort(key=lambda t: -(t[1] - t[0]))
        return regions
    return []


def reloc_regions():
    """L2 reloc-aware SDK regions (libmask2, verified by verify_libmask2.py)."""
    lm = AN / "libmask2_matches.csv"
    if not lm.exists():
        return []
    regions = []
    with open(lm, newline="") as f:
        for r in csv.DictReader(f):
            regions.append((int(r["game_start"], 16),
                            int(r["game_end"], 16),
                            f"{r['lib']}:{r['module']}"))
    regions.sort(key=lambda t: -(t[1] - t[0]))
    return regions


def v040_regions():
    """Katana SDK 0.40 (Pre.2/Release.4) version-adjacent regions.

    These SDKs carry GDFS 0.46/0.49 + syCache + mpdrv_/pdmain_/kdapi_ (the
    game links GDFS 0.53) + ninja. Masked-match fragments verified 0
    mismatch (gdfs_/pdmain_/kdapi_/mpdrv_/mpapi_/gdfshn_/gdfsif_)."""
    regions = []
    for name in ("v040_shinobi_libmask.csv", "v040_ninja_libmask.csv"):
        lm = AN / name
        if not lm.exists():
            continue
        with open(lm, newline="") as f:
            for r in csv.DictReader(f):
                regions.append((int(r["game_start"], 16),
                                int(r["game_end"], 16),
                                f"{r['lib']}:{r['module']}"))
    regions.sort(key=lambda t: -(t[1] - t[0]))
    return regions


def main() -> int:
    funcs = load_funcs()
    tot_f, tot_b = len(funcs), sum(f["size"] for f in funcs)

    # 1) ported (hand ledger). Rows missing from the baseline CSV (small
    # leaves Vf3Prologue never segmented) still count via their `size`
    # column as byte-credit with fn-credit 0 (baseline is fn-denominated).
    ported = {}
    extra_rows = []
    p = REPO / "docs" / "decomp_status.csv"
    baseline_entries = {fn["entry"] for fn in funcs}
    if p.exists():
        with open(p, newline="") as f:
            for r in csv.DictReader(f):
                ent = int(r["entry"], 16)
                if ent in baseline_entries:
                    ported[ent] = (r["status"], r["file"])
                elif r.get("status", "").startswith("ported"):
                    extra_rows.append({"entry": ent,
                                       "size": int(r.get("size") or 0),
                                       "file": r["file"]})

    # 2) library attribution regions (largest region claims first)
    regions = claimed_set()
    lib_claim = {}
    covered_span = [False] * len(funcs)
    for s, e, label in regions:
        for i, fn in enumerate(funcs):
            if covered_span[i] or ported.get(fn["entry"]):
                continue
            if s <= fn["entry"] < e:
                covered_span[i] = True
                lib_claim[fn["entry"]] = label

    ported_n = sum(1 for fn in funcs if fn["entry"] in ported)
    ported_b = sum(fn["size"] for fn in funcs if fn["entry"] in ported) \
        + sum(r["size"] for r in extra_rows)
    extra_n = len(extra_rows)
    lib_n = len(lib_claim)
    lib_b = sum(f["size"] for f in funcs if f["entry"] in lib_claim)

    # 2b) L2 reloc-aware SDK regions (verified) not already claimed
    reloc_claim = {}
    for s, e, label in reloc_regions():
        for fn in funcs:
            if fn["entry"] in ported or fn["entry"] in lib_claim \
                    or fn["entry"] in reloc_claim:
                continue
            if s <= fn["entry"] < e:
                reloc_claim[fn["entry"]] = label
    reloc_n = len(reloc_claim)
    reloc_b = sum(f["size"] for f in funcs if f["entry"] in reloc_claim)

    # 2c) Katana 0.40 version-adjacent regions not already claimed
    v040_claim = {}
    for s, e, label in v040_regions():
        for fn in funcs:
            if fn["entry"] in ported or fn["entry"] in lib_claim \
                    or fn["entry"] in reloc_claim or fn["entry"] in v040_claim:
                continue
            if s <= fn["entry"] < e:
                v040_claim[fn["entry"]] = label
    v040_n = len(v040_claim)
    v040_b = sum(f["size"] for f in funcs if f["entry"] in v040_claim)

    att_n, att_b = (ported_n + lib_n + reloc_n + v040_n,
                    ported_b + lib_b + reloc_b + v040_b)

    # 3) trace-executed (execution-identification, not byte-matched/ported)
    trace = trace_executed()
    trace_claim = {e for e in trace
                   if e not in ported and e not in lib_claim
                   and e not in reloc_claim and e not in v040_claim}
    trace_n = len(trace_claim)
    trace_b = sum(f["size"] for f in funcs if f["entry"] in trace_claim)
    grand_n = att_n + trace_n
    grand_b = att_b + trace_b

    by_lib = {}
    for ent, label in lib_claim.items():
        by_lib.setdefault(label.split(":")[0], set()).add(ent)

    pct = lambda n: f"{100.0 * n:.1f}%"
    md = [
        "# Decomp coverage (auto-generated by tools/decomp_stats.py)", "",
        "Baseline: `extract/analysis/funcs_1ST_READ.unsc.bin.csv` "
        f"({tot_f} functions, {tot_b} body bytes) on the TRUE image.", "",
        "| bucket | functions | % | body bytes | % |", "|---|---|---|---|---|",
        f"| ported (src/) | {ported_n} (+{extra_n} off-baseline leaves) | {pct(ported_n/tot_f)} | {ported_b} | {pct(ported_b/tot_b)} |",
        f"| SDK-attributed (masked byte match) | {lib_n} | {pct(lib_n/tot_f)} | {lib_b} | {pct(lib_b/tot_b)} |",
        f"| SDK-attributed (reloc-aware, L2 verified) | {reloc_n} | {pct(reloc_n/tot_f)} | {reloc_b} | {pct(reloc_b/tot_b)} |",
        f"| SDK-attributed (Katana 0.40 adjacent, GDFS/mpdrv/pdmain) | {v040_n} | {pct(v040_n/tot_f)} | {v040_b} | {pct(v040_b/tot_b)} |",
        f"| trace-executed (execution-ID, NOT ported/matched) | {trace_n} | {pct(trace_n/tot_f)} | {trace_b} | {pct(trace_b/tot_b)} |",
        f"| **rigorous accounted (ported+SDK)** | {att_n} | {pct(att_n/tot_f)} | {att_b} | {pct(att_b/tot_b)} |",
        f"| **total incl. trace** | {grand_n} | {pct(grand_n/tot_f)} | {grand_b} | {pct(grand_b/tot_b)} |",
        "",
        "SDK attribution by library (fn count):",
    ]
    for lib, ids in sorted(by_lib.items(), key=lambda kv: -len(kv[1])):
        md.append(f"- {lib}: {len(ids)}")
    md += ["", "Ported ledger: `docs/decomp_status.csv`; trace bucket:",
           "extract/analysis/trace_executed.csv (method: execution-ID —"
           " identified, not verified-ported)"]
    (REPO / "docs" / "coverage.md").write_text("\n".join(md) + "\n",
                                               encoding="utf-8")
    (AN / "coverage.json").write_text(json.dumps({
        "funcs_total": tot_f, "bytes_total": tot_b,
        "ported_fns": ported_n, "ported_bytes": ported_b,
        "lib_fns": lib_n, "lib_bytes": lib_b,
        "reloc_fns": reloc_n, "reloc_bytes": reloc_b,
        "v040_fns": v040_n, "v040_bytes": v040_b,
        "trace_fns": trace_n, "trace_bytes": trace_b,
        "grand_fns": grand_n, "grand_bytes": grand_b,
    }, indent=1))
    print(f"coverage: rigorous {att_n}/{tot_f} fns ({pct(att_n/tot_f)}), "
          f"{att_b}/{tot_b} bytes ({pct(att_b/tot_b)}); "
          f"incl-trace {grand_n}/{tot_f} ({pct(grand_n/tot_f)}), "
          f"{grand_b}/{tot_b} ({pct(grand_b/tot_b)})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
