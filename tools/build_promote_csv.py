#!/usr/bin/env python3
"""build_promote_csv.py — emit a promote-ready CSV for a set of entries.

tools/promote_replay.py wants, per entry, the list of corpora that hold a
complete replay for it.  "Complete" means every row of `f_<entry>.cases` still
has its entry/exit RAM shadow; a corpus with pruned shadows replays as
"N/N match, K skipped" and is not evidence, so promote_replay.py drops it via
its own `corpus_complete` check.

This tool resolves those corpora from the recorded artefacts and writes the
CSV, so the corpus column is never hand-typed.

    python tools/build_promote_csv.py 8c0871ee 8c03a07c --out scan.csv
"""
from __future__ import annotations

import argparse
import csv
import os
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
sys.path.insert(0, str(REPO / "tools" / "oracle"))
from prune_corpus import parse_row, row_complete  # noqa: E402

ANALYSIS = REPO / "extract" / "analysis"
SIZES = ANALYSIS / "funcs_1ST_READ.unsc.bin.csv"


def sizes() -> dict[str, int]:
    out: dict[str, int] = {}
    with SIZES.open(newline="", encoding="utf-8", errors="replace") as fh:
        for row in csv.DictReader(fh):
            out[row["entry"].lower()] = int(row["size"])
    return out


def corpus_complete(d: Path, entry: str) -> tuple[bool, int]:
    """Same definition promote_replay.py uses: every row keeps its RAM shadow."""
    cases = d / f"f_{entry}.cases"
    try:
        lines = cases.read_text(encoding="ascii", errors="replace").splitlines()
    except OSError:
        return False, 0
    if not lines:
        return False, 0
    for line in lines:
        if not line.strip():
            continue
        try:
            ok, _ = row_complete(d, parse_row(line))
        except ValueError:
            return False, len(lines)
        if not ok:
            return False, len(lines)
    return True, len(lines)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("entries", nargs="+")
    ap.add_argument("--out", required=True)
    a = ap.parse_args()

    want = {e.lower().replace("0x", "") for e in a.entries}
    found: dict[str, list[tuple[str, int]]] = {e: [] for e in want}
    for root, _dirs, files in os.walk(ANALYSIS):
        names = set(files)
        for n in names:
            if not (n.startswith("f_") and n.endswith(".cases")):
                continue
            entry = n[2:-len(".cases")]
            if entry not in want:
                continue
            if not any(x.endswith(".in.bin") for x in names):
                continue
            d = Path(root)
            ok, nrows = corpus_complete(d, entry)
            if ok:
                found[entry].append((d.relative_to(REPO).as_posix(), nrows))

    size_of = sizes()
    out = Path(a.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["entry", "size", "corpora", "pass_all", "cases_total",
                    "big_pending", "first_fail", "corpus"])
        for e in sorted(want, key=lambda x: -size_of.get(x, 0)):
            corpora = found.get(e, [])
            if not corpora:
                print("# %s: no complete corpus — excluded" % e)
                continue
            w.writerow([e, size_of.get(e, 0), len(corpora), 1,
                        sum(n for _, n in corpora), 0, "",
                        ";".join(d for d, _ in corpora)])
            print("  %s  %5d B  %d corpora  %5d cases" % (
                e, size_of.get(e, 0), len(corpora), sum(n for _, n in corpora)))
    print("wrote %s" % out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
