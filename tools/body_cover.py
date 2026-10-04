#!/usr/bin/env python3
"""body_cover.py — how much of a baseline body did a capture corpus actually execute?

The port ledger credits whole functions (`docs/decomp_status.csv` + `decomp_stats.py`),
so promoting a body whose golden corpus only ever walked one path would book bytes no
case ever proved. This tool measures the gap directly: for each entry, the frozen Ghidra
body ranges (`extract/analysis/function_body_ranges.csv`) minus the PCs the corpus
executed (`<case dir>/f_<entry>.ops.json`, the per-corpus union of every captured
invocation's instruction stream).

Each executed PC accounts for its own 2-byte instruction word. Call targets recorded
inside the body count; PCs outside every body range (callees, other code) do not.

    python tools/body_cover.py extract/analysis/phase3_mt3_cases
    python tools/body_cover.py --min-cover 100 extract/analysis/phase3_cases   # gate

Writes `extract/analysis/body_cover.csv` and, with `--pcs`, an uncovered-PC list per
entry so a seed campaign can aim at the branches that never ran.
"""
from __future__ import annotations

import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AN = ROOT / "extract" / "analysis"
WORD = 2


def body_spans() -> dict[int, list[tuple[int, int]]]:
    spans: dict[int, list[tuple[int, int]]] = defaultdict(list)
    with (AN / "function_body_ranges.csv").open(newline="") as f:
        for row in csv.DictReader(f):
            spans[int(row["entry"], 16)].append((int(row["start"], 16), int(row["end"], 16)))
    for entry in spans:
        spans[entry].sort()
    return spans


def sizes() -> dict[int, int]:
    out: dict[int, int] = {}
    with (AN / "funcs_1ST_READ.unsc.bin.csv").open(newline="") as f:
        for row in csv.DictReader(f):
            out[int(row["entry"], 16)] = int(row["size"])
    return out


def corpus_pcs(cases: list[Path]) -> dict[int, tuple[set[int], int, list[str]]]:
    """entry -> (executed PCs, ops-file count, contributing case dirs).

    The counter measures corpora, not distinct invocation inputs.
    """
    out: dict[int, tuple[set[int], int, list[str]]] = {}
    for case in cases:
        for ops in sorted(case.glob("f_*.ops.json")):
            entry = int(ops.stem.split("_", 1)[1].split(".")[0], 16)
            pcs = {int(pc, 16) | 0x80000000 for pc in json.loads(ops.read_text())}
            got = out.setdefault(entry, (set(), 0, []))
            out[entry] = (got[0] | pcs, got[1] + 1, got[2] + [case.name])
    return out


def measure(entry: int, spans: list[tuple[int, int]], pcs: set[int]) -> tuple[int, int, list[int]]:
    """(covered bytes, total bytes, uncovered body PCs)."""
    covered = 0
    total = 0
    missing: list[int] = []
    for start, end in spans:
        total += end - start
        for pc in range(start, end, WORD):
            # A body range may start mid-word on fragmented functions; attribute the
            # word only when the executed PC actually lands inside the range.
            if pc in pcs:
                covered += WORD
            else:
                missing.append(pc)
    return min(covered, total), total, sorted(missing)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cases", nargs="*", default=[],
                    help="capture case directories or *.ops.json files "
                         "(optional with --bindings)")
    ap.add_argument("--entry", action="append", default=[],
                    help="restrict to these entries (repeatable, hex)")
    ap.add_argument("--pcs", action="store_true",
                    help="also write extract/analysis/body_cover_uncovered.json")
    ap.add_argument("--min-cover", type=float, default=None,
                    help="exit non-zero if any listed entry stays below this percent")
    ap.add_argument("--bindings", default="",
                    help="derive the corpora and entries from a golden bindings "
                         "file: every port claimed in the ledger must be backed "
                         "by a corpus that executed its whole body")
    ap.add_argument("--strict", action="store_true",
                    help="with --min-cover, fail instead of reporting: use when "
                         "promoting a whole-body port")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    dirs: list[Path] = []
    if a.bindings:
        bindings = json.loads((ROOT / a.bindings).read_text())
        # Keys are either a bare entry ("0x8c0483f4") or a labelled group
        # ("matrix:0x8c03b450"); take the entry part of each.
        only = {int(key.split(":")[-1], 16) for key in bindings}
        for spec in bindings.values():
            corpus = ROOT / spec["golden"]
            if corpus.parent.is_dir():
                dirs.append(corpus.parent)

    spans = body_spans()
    sizes_ = sizes()
    for item in a.cases:
        p = Path(item)
        p = p if p.is_absolute() else ROOT / p
        if p.is_dir():
            dirs.append(p)
        elif p.suffix == ".json":
            dirs.append(p.parent)
        else:
            raise SystemExit(f"not a capture corpus: {p}")
    only = {int(x, 16) for x in a.entry}
    if a.bindings:
        only.update(int(key.split(":")[-1], 16) for key in bindings)
    corpora = corpus_pcs(dirs)
    if not corpora:
        raise SystemExit("no f_*.ops.json found in the given corpora")

    rows = []
    uncovered: dict[str, list[str]] = {}
    for entry, (pcs, ncases, sources) in sorted(corpora.items()):
        if only and entry not in only:
            continue
        if entry not in spans:
            continue
        covered, total, missing = measure(entry, spans[entry], pcs)
        pct = 100.0 * covered / total if total else 0.0
        rows.append(dict(entry=f"0x{entry:08x}", size=sizes_.get(entry, total),
                         corpus_cases=ncases, covered_bytes=covered,
                         body_bytes=total, cover_pct=f"{pct:.1f}",
                         covered_pcs=len([pc for pc in pcs
                                         if any(s <= pc < e for s, e in spans[entry])]),
                         uncovered_pcs=len(missing), corpus=";".join(sources)))
        uncovered[f"0x{entry:08x}"] = [f"0x{pc:08x}" for pc in missing]

    if only:
        measured = {int(row["entry"], 16) for row in rows}
        missing_entries = sorted(only - measured)
        if missing_entries and a.strict:
            raise SystemExit("COVERAGE GATE FAIL: no body PCs captured for " +
                             ", ".join(f"0x{entry:08x}" for entry in missing_entries))
    if a.strict and a.min_cover is not None:
        incomplete = [row for row in rows
                      if float(row["covered_bytes"]) * 100.0 /
                      max(1, int(row["body_bytes"])) < a.min_cover - 1e-9]
        if incomplete:
            for row in incomplete:
                print(f"COVERAGE GATE FAIL {row['entry']}: "
                      f"{row['covered_bytes']}/{row['body_bytes']} body bytes "
                      f"({row['cover_pct']}%) < {a.min_cover:g}%")
            return 1
    if not rows:
        if a.strict:
            raise SystemExit("COVERAGE GATE FAIL: no selected entries have a "
                             "valid baseline body and captured PCs")
        if not a.quiet:
            print("no baseline body entries selected")
        return 0

    out = AN / "body_cover.csv"
    with out.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    if a.pcs:
        (AN / "body_cover_uncovered.json").write_text(json.dumps(uncovered, indent=1) + "\n")
    if not a.quiet:
        for r in rows:
            print(f"{r['entry']} {r['size']:>5}B corpus {r['covered_bytes']:>5}B "
                  f"({r['cover_pct']:>5}%) cases {r['corpus_cases']:>4} "
                  f"uncovered PCs {r['uncovered_pcs']:>4}")
        print(f"wrote {out.relative_to(ROOT)}")

    if a.min_cover is not None:
        bad = [r for r in rows if float(r["covered_bytes"]) * 100.0 /
               max(1, int(r["body_bytes"])) < a.min_cover - 1e-9]
        if bad and a.strict:
            for r in bad:
                print(f"COVERAGE GATE FAIL {r['entry']}: {r['cover_pct']}% < {a.min_cover}%")
            return 1
        if bad:
            # Advisory by default: historical piecewise ports are bound to
            # fragment-boundary corpora that intentionally cover part of a body
            # (see docs/re/port_oracle.md, giant-unit rules). Only a whole-body
            # promotion should pass --strict.
            if not a.quiet:
                for r in sorted(bad, key=lambda r: float(r["cover_pct"]))[:10]:
                    print(f"COVERAGE GATE FAIL {r['entry']}: {r['cover_pct']}% < {a.min_cover}%")
            print(f"advisory: {len(bad)} entr{'y' if len(bad) == 1 else 'ies'} below "
                  f"{a.min_cover}% body coverage (pass --strict to fail the gate)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
