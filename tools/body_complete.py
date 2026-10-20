#!/usr/bin/env python3
"""body_complete.py — prove an entry's whole Ghidra body is emitted by C.

Coverage is credited per ledger row, unioned over the entry's Ghidra body
ranges.  A body that is only *partly* translated would therefore be credited
for bytes it does not implement.  This tool checks the other direction: for
each requested entry, every PC of every body range must carry a translated
label (`P_<pc>:`) in some adapter under src/fight/.

    python tools/body_complete.py 8c0492be 8c0831f8
"""
from __future__ import annotations

import csv
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SRC = REPO / "src" / "fight"
RANGES = REPO / "extract" / "analysis" / "function_body_ranges.csv"


def body_ranges() -> dict[int, list[tuple[int, int]]]:
    by_entry: dict[int, list[tuple[int, int]]] = defaultdict(list)
    with RANGES.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            entry = int(row["entry"], 16) & 0x1FFFFFFF
            by_entry[entry].append((int(row["start"], 16) & 0x1FFFFFFF,
                                    int(row["end"], 16) & 0x1FFFFFFF))
    return by_entry


def owners() -> dict[int, str]:
    own: dict[int, str] = {}
    for path in sorted(SRC.glob("*.c")):
        if path.name == "unknown.c":
            continue
        text = path.read_text(errors="ignore")
        for m in re.finditer(r"^P_([0-9a-f]+):", text, re.M):
            own.setdefault(int(m.group(1), 16) & 0x1FFFFFFF, path.name)
    return own


def main() -> int:
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    ranges = body_ranges()
    own = owners()
    bad = 0
    for arg in sys.argv[1:]:
        entry = int(arg, 16) & 0x1FFFFFFF
        spans = ranges.get(entry, [])
        total = sum(b - a for a, b in spans)
        missing = [pc for a, b in spans for pc in range(a, b, 2) if pc not in own]
        files = sorted({own[pc] for a, b in spans
                        for pc in range(a, b, 2) if pc in own})
        if missing:
            bad += 1
            print("0x%08x  body=%5d B ranges=%d  MISSING %d PCs  owners=%s"
                  % (entry, total, len(spans), len(missing), files))
            print("     first missing: %s"
                  % ", ".join("0x%08x" % m for m in missing[:8]))
        else:
            print("0x%08x  body=%5d B ranges=%d  COMPLETE  owners=%s"
                  % (entry, total, len(spans), files))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
