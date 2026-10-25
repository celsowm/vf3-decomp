#!/usr/bin/env python3
"""fix_ledger_form.py - the ledger's entry column has to use the same address
form as the baseline inventory (0x8c...).  A row in the 0x0c mirror form is
not recognised as a baseline function, so its bytes are credited as an
off-baseline leaf and the coverage union counts the mirror instead of the
baseline.

    python tools/fix_ledger_form.py            # report
    python tools/fix_ledger_form.py --write    # rewrite the rows
"""
from __future__ import annotations

import csv
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
LEDGER = REPO / "docs" / "decomp_status.csv"


def main() -> int:
    write = "--write" in sys.argv
    rows = list(csv.DictReader(open(LEDGER, newline="")))
    fixed = 0
    for r in rows:
        e = int(r["entry"], 16)
        if (e & 0xFF000000) == 0x0C000000:
            r["entry"] = f"0x{e | 0x80000000:08x}"
            fixed += 1
    print(f"{fixed} rows in the 0x0c mirror form")
    if write and fixed:
        with open(LEDGER, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=["entry", "status", "file", "size",
                                              "method", "oracle"])
            w.writeheader()
            w.writerows(rows)
        print(f"rewrote {LEDGER}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
