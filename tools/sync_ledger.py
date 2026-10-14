#!/usr/bin/env python3
"""Sync ledger rows from replay_scan bindings."""
import csv, json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
BINDINGS = REPO / "tools" / "golden_bindings.json"
LEDGER = REPO / "docs" / "decomp_status.csv"
FIELDS = ["entry", "status", "file", "size", "method", "oracle"]

bindings = json.loads(BINDINGS.read_text())
ledger = list(csv.DictReader(open(LEDGER, newline="")))
ledger_entries = {r["entry"].lower() for r in ledger}

scan = [(k, v) for k, v in bindings.items() if "replay_scan" in v.get("source", "")]
added = 0
for pc, v in scan:
    if pc.lower() not in ledger_entries:
        ledger.append(dict(entry=pc, status="ported",
                           file=v["port"], size="0",
                           method="capture-driven port (batch replay_scan)",
                           oracle=v["source"]))
        added += 1
        print(f"adding {pc}")

# Sanitize: only keep expected fields
clean = [{k: r.get(k, "") for k in FIELDS} for r in ledger]

with open(LEDGER, "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=FIELDS)
    w.writeheader()
    w.writerows(sorted(clean, key=lambda r: r["entry"].lower()))
print(f"added {added} ledger rows")