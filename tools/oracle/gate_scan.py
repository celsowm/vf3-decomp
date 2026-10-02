#!/usr/bin/env python3
"""gate_scan.py — list the flag-bit gates and selector switches of one function.

A descriptor worker's control flow is a tree of `tst r12,<mask>` gates over a
flags word plus `cmp/eq #n` switches over selector words. Seed campaigns need
both: a selector arm is only reachable when the gate that guards its switch is
open, so sweeping selector values with a closed gate measures nothing.

    python tools/oracle/gate_scan.py extract/analysis/tmp_8c05b20e.dis
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

INSN = re.compile(r"^([0-9a-f]+)\s+([0-9a-f]{4})\s+(.*)$")


def load(path: Path):
    recs = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        m = INSN.match(line)
        if m:
            recs.append((int(m.group(1), 16), m.group(3).strip()))
    return recs


def gates(recs, reg="r12"):
    """`tst <reg>,rN` where rN holds an immediate: the mask that opens a branch."""
    out = []
    for i, (pc, txt) in enumerate(recs):
        m = re.match(rf"tst {reg},(r\d+)", txt)
        if not m:
            continue
        target = m.group(1)
        mask = None
        for j in range(i - 1, max(-1, i - 6), -1):
            prev = recs[j][1]
            lw = re.search(r"lit\.w=([0-9a-f]+)", prev)
            if lw:
                mask = int(lw.group(1), 16)
                break
            imm = re.search(rf"mov #(-?\d+),{target}$", prev) or re.search(rf"mov #(-?\d+),{target}", prev)
            if imm:
                mask = int(imm.group(1)) & 0xFFFF
                break
        bt = re.search(r"bt/s? (0x[0-9a-f]+)", txt)
        if mask is not None:
            out.append((pc, mask, bt.group(1) if bt else ""))
    return out


def switches(recs):
    """`mov.l @(off,r13),rN` followed by a cmp/eq chain: a selector switch."""
    out = []
    for i, (pc, txt) in enumerate(recs):
        m = re.search(r"mov\.l @\((\d+),r13\),r(\d+)$", txt)
        if not m:
            continue
        reg = m.group(2)
        arms = []
        for j in range(i + 1, min(i + 45, len(recs))):
            a = re.search(rf"cmp/eq #(\d+),{reg}$", recs[j][1])
            if a:
                arms.append((int(a.group(1)), recs[j][0]))
        if len(arms) >= 2:
            out.append((int(m.group(1)), pc, reg, arms))
    return out


def main() -> int:
    path = Path(sys.argv[1] if len(sys.argv) > 1 else "extract/analysis/tmp_8c05b20e.dis")
    recs = load(path)
    print(f"{path}: {len(recs)} instructions")
    print("\nflag-word gates (open when the mask ANDs to zero):")
    for pc, mask, skip in gates(recs):
        print(f"  {pc:08x}  mask 0x{mask:04x}  -> {skip}")
    print("\nselector switches:")
    for off, pc, reg, arms in switches(recs):
        codes = ",".join(str(c) for c, _ in arms)
        print(f"  descriptor+0x{off:02x} loaded at {pc:08x} into {reg}: codes [{codes}]")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
