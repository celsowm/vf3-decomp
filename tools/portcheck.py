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
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TESTS = ["vf3dl", "vf3walker", "vf3mtmount", "vf3loop", "vf3taskvm",
         "vf3vm", "vf3frame", "vf3libutil", "vf3orient2", "vf3poly", "vf3vecpush",
         "vf3tailcall", "vf3walker2", "vf3fvecadd", "vf3scaler3",
         "vf3frameseq", "vf3cbefc", "vf3f040f1e", "vf3f0747d8",
         "vf3f9f6fc", "vf3f9f6dc", "vf3cc148", "vf3c5dbe", "vf3b10aa",
         "vf3c6ec4", "vf3maplookup", "vf3meshnode", "vf3d0fa",
         "vf3c788", "vf3f096258", "vf3matrix",
         "vf3bootmix",
         "vf3fvecnorm070x", "vf3fvecnorm070a84", "vf3fvecnorm070120",
         "vf3fvecnorm07030c", "vf3fvecnorm070cf0", "vf3fpu"]
# NOTE: vf3fvecmix2 (0x8C070852) builds but is NOT gated: its window's float
# exits carry loop-carried pipeline state and the exit RAM contains stores
# from below-window code — parked until re-captured with tighter windows.

# NOTE: vf3g06f6f8 builds but is NOT gated: the 88-byte model ends before the
# paired caller RTS, and both available captures disagree beyond its scope.


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


def run_bindings(bindings: Path, jobs=1):
    if not bindings.exists():
        return []
    cfg = json.loads(bindings.read_text(encoding="utf-8"))
    def replay(item):
        pc,spec=item
        test = str(spec["test"]).split()
        golden = REPO / spec["golden"]
        exe = REPO / test[0]
        if not exe.exists():
            return pc, "MISSING-TEST", str(exe)
        if not golden.exists():
            return pc, "MISSING-GOLDEN", str(golden)
        cmd = [str(exe)] + test[1:] + [str(golden)]
        env=dict(os.environ)
        if spec.get("strict"):
            env["VF3_STRICT_REPLAY"]="1"
        p = subprocess.run(cmd, capture_output=True,
                           text=True, cwd=REPO, timeout=600,env=env)
        line = (p.stdout or p.stderr).strip().splitlines()
        return pc, "PASS" if p.returncode == 0 else "FAIL", line[-1] if line else ""
    with ThreadPoolExecutor(max_workers=jobs) as executor:
        out=[]
        for result in executor.map(replay,sorted(cfg.items())):
            out.append(result)
            if jobs>1: print(f'binding {result[0]}: {result[1]}',flush=True)
        return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--goldens", default="extract/analysis/goldens")
    ap.add_argument("--bindings", default="tools/golden_bindings.json")
    ap.add_argument('--jobs',type=int,default=1,choices=range(1,5),help='independent bound replay processes (1-4)')
    a = ap.parse_args()

    rows, errs = validate_goldens(REPO / a.goldens)
    print(f"goldens: {len(rows)} fns, {len(errs)} issues")
    for e in errs:
        print("  !", e)
    tests = run_tests()
    print("replay tests:")
    for t, st, last in tests:
        print(f"  {t:12} {st:6} {last[:80]}")
    binds = run_bindings(REPO / a.bindings,a.jobs)
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
