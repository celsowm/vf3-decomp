#!/usr/bin/env python3
"""Append missing replay_scan ledger rows (append-only, no rewrite)."""
import csv, json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
BINDINGS = REPO / "tools" / "golden_bindings.json"
LEDGER = REPO / "docs" / "decomp_status.csv"
FIELDS = ["entry", "status", "file", "size", "method", "oracle"]

bindings = json.loads(BINDINGS.read_text())
existing = {r["entry"].lower() for r in csv.DictReader(open(LEDGER, newline=""))
            if r.get("status", "").startswith("ported")}

scan = [(k, v) for k, v in bindings.items() if "replay_scan" in v.get("source", "")]
to_append = [(pc, v) for pc, v in scan if pc.lower() not in existing]
print(f"appending {len(to_append)} rows (skipping {len(scan) - len(to_append)} already present)")

with open(LEDGER, "a", newline="") as f:
    w = csv.DictWriter(f, fieldnames=FIELDS)
    for pc, v in to_append:
        w.writerow(dict(entry=pc, status="ported",
                        file=v["port"], size="0",
                        method="capture-driven port (batch replay_scan)",
                        oracle=v["source"]))
        print(f"  + {pc}")
print("done")