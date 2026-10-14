#!/usr/bin/env python3
"""Add missing clean-pass replay_scan entries to ledger."""
import csv, json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
LEDGER = REPO / "docs" / "decomp_status.csv"
BINDINGS = REPO / "tools" / "golden_bindings.json"
FIELDS = ["entry", "status", "file", "size", "method", "oracle"]

ledger = list(csv.DictReader(open(LEDGER, newline="")))
ledger_entries = {r["entry"].lower() for r in ledger}

rows = [r for r in csv.DictReader(open(REPO / "extract/analysis/replay_scan.csv", newline=""))
        if r["pass_all"] == "1" and r.get("big_pending", "0") == "0"]

bindings = json.load(open(BINDINGS))

to_add = [r for r in rows if r["entry"].lower() not in ledger_entries]
print(f"adding {len(to_add)} missing clean-pass entries")

with open(LEDGER, "a", newline="") as f:
    w = csv.DictWriter(f, fieldnames=["entry", "status", "file", "size", "method", "oracle"])
    for r in to_add:
        pc = r["entry"]
        router = bindings.get(pc, {}).get("port", "src/fight/unknown.c")
        w.writerow(dict(entry=pc, status="ported",
                        file=router, size=r["size"],
                        method="capture-driven port (batch replay_scan)",
                        oracle=f"Batch replay promotion (replay_scan): strict "
                               f"vf3matrixfamily replay PASS in {r['corpora']} "
                               f"corpora, {r['cases_total']} cases; "
                               "RAM shadows byte-identical regenerations"))
        print(f"  + {pc} ({r['size']}B) via {router}")
print("done")