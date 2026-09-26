#!/usr/bin/env python3
"""verify_all.py — one-command gate for the port campaign.

Runs, in order:
  1. cmake --build build            (unless --no-build)
  2. python tools/portcheck.py      (goldens + all port replay tests)
  3. python tools/decomp_stats.py   (coverage)
  4. python tools/verify_union.py   (SDK union evidence, 0 mismatch)
  5. python tools/sh4_calls.py      (machine-decoded call cross-check)
  6. python tools/sh4_resolve.py    (dynamic-target resolution)
  7. python tools/port_plan.py      (roadmap refresh, consumes both)

Usage: python tools/verify_all.py [--no-build] [--quiet]
"""
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
PY = sys.executable


def run(cmd, allow_fail=False):
    print(f"$ {' '.join(cmd)}")
    p = subprocess.run(cmd, cwd=str(REPO))
    if p.returncode != 0 and not allow_fail:
        print(f"FAILED ({p.returncode}): {' '.join(cmd)}")
        return False
    return True


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    a = ap.parse_args()
    ok = True
    if not a.no_build:
        ok &= run(["cmake", "--build", "build"])
    ok &= run([PY, "tools/portcheck.py"])
    ok &= run([PY, "tools/decomp_stats.py"])
    ok &= run([PY, "tools/verify_union.py"])
    ok &= run([PY, "tools/sh4_calls.py"])
    ok &= run([PY, "tools/sh4_resolve.py"])
    ok &= run([PY, "tools/port_plan.py"])
    print("verify_all:", "PASS" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())