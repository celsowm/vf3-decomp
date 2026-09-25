#!/usr/bin/env python3
"""portcheck.py — differential port validation harness (Phase B).

Three jobs:
  1. validate the golden snapshots in extract/analysis/goldens (pairing,
     non-empty unique samples, fingerprint present);
  2. run every compiled replay test in build/ and record PASS/FAIL;
  3. run each *bound* port against its golden vectors (tools/golden_bindings
     .json: pc -> {test, golden}); a bound test is invoked as
         <test> <golden.txt>
     and must exit 0 after matching every entry/exit snapshot.

Usage:
  python tools/portcheck.py [--goldens extract/analysis/goldens]
                            [--bindings tools/golden_bindings.json]
"""
from __future__ import annotations

import argparse
import csv
import json
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TESTS = ["vf3dl", "vf3walker", "vf3mtmount", "vf3loop", "vf3taskvm",
         "vf3vm", "vf3frame", "vf3libutil", "vf3orient2", "vf3poly"]


def validate_goldens(d: Path):
    idx = d / "goldens_index.csv"
    if not idx.exists():
        return [], ["no goldens_index.csv"]
    rows = list(csv.DictReader(open(idx)))
    errs = []
    for r in rows:
        if int(r["unique"]) == 0:
            errs.append(f"{r['name']}: no unique samples")
        if not r["fingerprint"]:
            errs.append(f"{r['name']}: missing fingerprint")
        if not (d / f"{r['name']}.txt").exists():
            errs.append(f"{r['name']}: missing .txt vectors")
    return rows, errs


def run_tests():
    out = []
    for t in TESTS:
        exe = REPO / "build" / f"{t}.exe"
        if not exe.exists():
            out.append((t, "missing", ""))
            continue
        p = subprocess.run([str(exe)], capture_output=True, text=True,
                           cwd=REPO, timeout=300)
        last = (p.stdout or p.stderr).strip().splitlines()
        out.append((t, "PASS" if p.returncode == 0 else "FAIL",
                    last[-1] if last else ""))
    return out


def run_bindings(bindings: Path):
    if not bindings.exists():
        return []
    cfg = json.loads(bindings.read_text(encoding="utf-8"))
    out = []
    for pc, spec in sorted(cfg.items()):
        test = REPO / spec["test"]
        golden = REPO / spec["golden"]
        if not test.exists():
            out.append((pc, "MISSING-TEST", str(test)))
            continue
        if not golden.exists():
            out.append((pc, "MISSING-GOLDEN", str(golden)))
            continue
        p = subprocess.run([str(test), str(golden)], capture_output=True,
                           text=True, cwd=REPO, timeout=600)
        line = (p.stdout or p.stderr).strip().splitlines()
        out.append((pc, "PASS" if p.returncode == 0 else "FAIL",
                    line[-1] if line else ""))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--goldens", default="extract/analysis/goldens")
    ap.add_argument("--bindings", default="tools/golden_bindings.json")
    a = ap.parse_args()

    rows, errs = validate_goldens(REPO / a.goldens)
    print(f"goldens: {len(rows)} fns, {len(errs)} issues")
    for e in errs:
        print("  !", e)
    tests = run_tests()
    print("replay tests:")
    for t, st, last in tests:
        print(f"  {t:12} {st:6} {last[:80]}")
    binds = run_bindings(REPO / a.bindings)
    print("golden-bound ports:")
    if not binds:
        print("  (none yet - add tools/golden_bindings.json)")
    for pc, st, last in binds:
        print(f"  {pc:12} {st:6} {last[:80]}")

    bad = errs or [t for t, st, _ in tests if st != "PASS"] \
        or [b for b in binds if b[1] != "PASS"]
    print("portcheck:", "FAIL" if bad else "PASS")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
