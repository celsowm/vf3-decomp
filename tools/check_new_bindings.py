#!/usr/bin/env python3
"""check_new_bindings.py — strict-replay gate over a set of ledger rows.

Runs the same strict replay the coverage gate uses
(`build/vf3matrixfamily.exe <pc> <golden>` with VF3_STRICT_REPLAY=1) for
every entry listed in a binding file, and reports PASS/FAIL per entry.

    python tools/check_new_bindings.py --bindings tools/golden_bindings.json \
        --only-new-since HEAD
    python tools/check_new_bindings.py --pc 0x8c064246 --pc 0x8c05027a
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

REPO = Path(__file__).resolve().parents[1]
EXE = REPO / "build" / "vf3matrixfamily.exe"


def ledger_entries() -> set[str]:
    p = REPO / "docs" / "decomp_status.csv"
    return {r["entry"].lower() for r in csv.DictReader(p.open(newline=""))}


def entries_new_since(ref: str) -> set[str]:
    p = subprocess.run(["git", "show", f"{ref}:docs/decomp_status.csv"],
                       capture_output=True, text=True, cwd=REPO)
    if p.returncode != 0:
        return set()
    old = {r["entry"].lower() for r in csv.DictReader(p.stdout.splitlines())}
    return ledger_entries() - old


def run(pc: str, spec: dict) -> tuple[str, str, str]:
    golden = REPO / spec["golden"]
    argv = str(spec.get("test", "build/vf3matrixfamily.exe")).split()
    exe = REPO / argv[0]
    if not exe.exists():
        return pc, "MISSING-TEST", str(exe)
    if not golden.exists():
        return pc, "MISSING-GOLDEN", str(golden)
    env = dict(os.environ)
    if spec.get("strict"):
        env["VF3_STRICT_REPLAY"] = "1"
    cmd = [str(exe)] + argv[1:] + [str(golden)]
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, cwd=REPO,
                           timeout=900, env=env)
    except subprocess.TimeoutExpired:
        return pc, "TIMEOUT", ""
    lines = ((p.stdout or "") + (p.stderr or "")).strip().splitlines()
    tail = lines[-1] if lines else ""
    return pc, ("PASS" if p.returncode == 0 else "FAIL"), tail


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--bindings", default="tools/golden_bindings.json")
    ap.add_argument("--only-new-since", default="")
    ap.add_argument("--pc", action="append", default=[])
    ap.add_argument("--jobs", type=int, default=4)
    a = ap.parse_args()
    if not EXE.is_file():
        raise SystemExit("build/vf3matrixfamily.exe missing - build first")
    cfg = json.loads((REPO / a.bindings).read_text(encoding="utf-8"))
    if a.pc:
        want = {p.lower() for p in a.pc}
    elif a.only_new_since:
        want = entries_new_since(a.only_new_since)
    else:
        want = set(cfg)
    jobs = [(pc, spec) for pc, spec in cfg.items() if pc.lower() in want]
    if not jobs:
        print("no bindings selected")
        return 0
    print(f"check_new_bindings: {len(jobs)} bindings, strict replay, "
          f"{a.jobs} jobs", flush=True)
    fails = []
    with ThreadPoolExecutor(max_workers=a.jobs) as pool:
        for pc, status, tail in pool.map(lambda it: run(*it), jobs):
            if status != "PASS":
                fails.append((pc, status, tail))
                print(f"  {status:>12} {pc}: {tail[:110]}", flush=True)
    print(f"\n{len(jobs) - len(fails)}/{len(jobs)} PASS, {len(fails)} not-PASS")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(main())
