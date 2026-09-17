#!/usr/bin/env python3
"""Select unambiguous auto-tier fuzzy names -> fuzzy_apply_<target>.csv
for Vf3ApplyNames.java."""
import csv, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")

for t in ("1ST_READ", "VF3TBE3", "RELOAD"):
    rows = list(csv.DictReader(open(os.path.join(AN, f"fuzzy_{t}.csv"))))
    best = {}
    for r in rows:
        a = int(r["addr"], 16)
        s = float(r["score"])
        if a not in best or s > best[a][1]:
            best[a] = (r["name"], s)
    out = [(a, n, s) for a, (n, s) in best.items() if s >= 0.92]
    with open(os.path.join(AN, f"fuzzy_apply_{t}.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["addr", "name", "span"])
        for a, n, s in sorted(out):
            w.writerow([f"0x{a:08X}", n, -3])
    print(t, "unambiguous auto names:", len(out))
