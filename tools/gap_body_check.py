#!/usr/bin/env python3
"""gap_body_check.py - run tools/body_complete.py over every still-unported
baseline entry and summarise the result."""
from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"

gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
args = [f"0x{g['entry']:08x}" for g in gap]
p = subprocess.run([sys.executable, str(REPO / "tools" / "body_complete.py"), *args],
                   cwd=REPO, capture_output=True, text=True)
lines = p.stdout.splitlines()
bad, good = [], 0
for ln in lines:
    if "COMPLETE" in ln:
        good += 1
    elif "MISSING" in ln:
        bad.append(ln)
print(f"complete: {good} / {len(gap)}   incomplete: {len(bad)}")
for ln in bad:
    print(" ", ln)
    nxt = lines[lines.index(ln) + 1] if lines.index(ln) + 1 < len(lines) else ""
    print("   ", nxt[:150])
