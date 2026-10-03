#!/usr/bin/env python3
"""gate_scan.py — list the flag-bit gates and selector switches of one function.

A descriptor worker's control flow is a tree of `tst r12,<mask>` gates over a
flags word plus `cmp/eq #n` switches over selector words. Seed campaigns need
both: a selector arm is only reachable when the gate that guards its switch is
open, so sweeping selector values with a closed gate measures nothing.

WARNING: the masks this tool prints come straight out of the sh4dump
disassembly, and they are NOT the values the emulator ends up applying. On
0x8C0C321E the disassembly's `lit.w=0300` and `tst #10` behave as 0x0030 and
0x0A00; seeding the printed value leaves the gate shut and the symptom is "my
seed did nothing". The mechanism is not yet explained (sh4dump's literal reads
are little-endian and correct, and `tst #10,r0` really is encoded as 0xC80A), so
treat these as uncalibrated. Re-measure each mask against a capture before
building a recipe - see docs/re/entry_patch.md.

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
    """`tst <reg>,rN` where rN holds an immediate: the mask that opens a branch.

    The mask can arrive as `mov #imm,rN`, as `mov.w lit.w=imm,rN` or as a
    `mov.l <pc-relative literal>,rN` whose pool value sh4dump annotates. Missing
    the last form hides whole flag bits from the seed plan (0x01000000 on
    0x8C05B20E is exactly such a mask).
    """
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
            lit = re.search(r"# lit=([0-9a-f]{8})", prev)
            if lit:
                mask = int(lit.group(1), 16)
                break
            imm = re.search(rf"mov #(-?\d+),{target}$", prev) or re.search(rf"mov #(-?\d+),{target}", prev)
            if imm:
                mask = int(imm.group(1)) & 0xFFFF
                break
        bt = re.search(r"bt/s? (0x[0-9a-f]+)", txt)
        if mask is not None:
            out.append((pc, mask, bt.group(1) if bt else ""))
    return out


def descriptor_offsets(recs):
    """Every descriptor offset the function reads through `r13` (P4 addressing).

    Offsets arrive two ways: a literal displacement `@(off,r13)` or an immediate
    loaded into a register first (`mov #64,r0` then `mov.l @(r0,r13)`). Only the
    first form is visible in a naive scan, so a seed plan built from it leaves
    the second half of the descriptor unseeded.
    """
    direct, indirect = {}, {}
    for i, (pc, txt) in enumerate(recs):
        m = re.search(r"mov\.l @\((\d+),r13\)", txt)
        if m:
            direct.setdefault(int(m.group(1)), []).append(pc)
            continue
        m = re.search(r"mov\.l @\(r(\d+),r13\)", txt)
        if not m:
            continue
        reg = m.group(1)
        for j in range(i - 1, max(-1, i - 5), -1):
            prev = recs[j][1]
            lw = re.search(r"lit\.w=([0-9a-f]+)", prev)
            if lw:
                indirect.setdefault(int(lw.group(1), 16), []).append(pc)
                break
            imm = re.search(rf"mov #(\d+),r{reg}$", prev) or re.search(rf"mov #(\d+),r{reg}", prev)
            if imm:
                indirect.setdefault(int(imm.group(1)), []).append(pc)
                break
    return direct, indirect


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
    direct, indirect = descriptor_offsets(recs)
    print(f"\ndescriptor offsets read through r13 ({len(direct) + len(indirect)} distinct):")
    print("  literal displacement: " + ", ".join(f"0x{o:02x}" for o in sorted(direct)))
    print("  register-loaded:      " + ", ".join(f"0x{o:02x}" for o in sorted(indirect)))
    print("  seed plan must cover every offset above.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
