#!/usr/bin/env python3
"""readable_gap.py - rank the SH-4 entries the fight tick calls that are still
served only by a generated adapter.

The readable track (src/fight/readable.c) replaces the machine-generated
per-instruction translation with source-level C.  Every generated module is
kept in the tree, so a readable port can be proved offline by differential
execution against the translation it replaces (the pattern used by
tests/state_helpers_replay.c).

This tool answers three questions without any capture artifact:
  * which entries the captured fight ticks actually call
    (src/fight/call_targets.c),
  * which of them have no readable port yet,
  * how big the generated translation of each remaining entry is, i.e. how
    much machine-generated C a readable port would replace.

Usage:
    python tools/readable_gap.py [--top N] [--only-call-targets]
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src" / "fight"

ENTRY_RE = re.compile(r"\b(0x0[0-9a-f]{7})u\b")
LABEL_RE = re.compile(r"^P_([0-9a-f]{8}):", re.MULTILINE)


def read_call_targets() -> list[int]:
    text = (SRC / "call_targets.c").read_text(encoding="utf-8", errors="replace")
    body = text.split("call_targets[] = {", 1)[1].split("}", 1)[0]
    return [int(v, 16) for v in ENTRY_RE.findall(body)]


def read_readable() -> dict[int, str]:
    text = (SRC / "readable.c").read_text(encoding="utf-8", errors="replace")
    body = text.split("vf3_readable_table[] = {", 1)[1].split("\n};", 1)[0]
    out: dict[int, str] = {}
    for m in re.finditer(r"\{\s*(0x0[0-9a-f]{7})u,\s*\"([A-Za-z0-9_]+)\"", body):
        out[int(m.group(1), 16)] = m.group(2)
    return out


def scan_generated() -> dict[int, tuple[str, int]]:
    """Map every guest PC a generated module implements to (module, index)."""
    per_pc: dict[int, tuple[str, int]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        labels = LABEL_RE.findall(text)
        for index, pc in enumerate(labels):
            per_pc.setdefault(int(pc, 16), (path.stem, index))
    return per_pc


RTS_RE = re.compile(r"s->pc=target")
GOTO_RE = re.compile(r"goto P_([0-9a-f]{8});")


def scan_functions() -> list[tuple[int, str, int, bool]]:
    """Split every generated module into functions.

    The translator emits one label per guest PC and one C statement per
    executed opcode; a function ends at its `rts`.  The function of an entry
    is the set of blocks its control flow reaches, so a backward goto inside
    it is a loop.

    Returns (entry, module, instruction count, has_loop).
    """
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from adapter_dump import index_modules, walk  # noqa: E402

    out: list[tuple[int, str, int, bool]] = []
    for stem, blocks in index_modules().items():
        for entry in blocks:
            pcs, loop = walk(entry, blocks)
            out.append((entry, stem, len(pcs), loop))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--only-call-targets", action="store_true",
                    help="restrict the report to entries the fight tick calls")
    ap.add_argument("--loops", action="store_true",
                    help="also rank the call-target functions that still contain a loop")
    ap.add_argument("--overlap", action="store_true",
                    help="list the readable ports that still have a generated twin")
    args = ap.parse_args()

    readable = read_readable()
    per_pc = scan_generated()
    targets = read_call_targets()

    rows = []
    for pc, (module, index) in per_pc.items():
        if pc in readable:
            continue
        if args.only_call_targets and pc not in set(targets):
            continue
        rows.append((pc, module, index))
    rows.sort(key=lambda r: r[0])

    print(f"generated PCs: {len(per_pc)}   readable ports: {len(readable)}")
    print(f"call targets: {len(targets)}")
    gap = [r for r in rows if r[0] in set(targets)]
    print(f"call-target PCs still generated: {len(gap)}\n")
    print(f"{'entry':>10}  {'module':<42}  label#")
    for pc, module, index in gap[: args.top]:
        print(f"0x{pc:08x}  {module:<42}  {index}")

    if args.loops:
        target_set = set(targets)
        fns = [f for f in scan_functions()
               if f[0] in target_set and f[0] not in readable]
        loops = [f for f in fns if f[3]]
        print(f"\ncall-target functions still generated: {len(fns)}"
              f"   of which loop-bearing: {len(loops)}\n")
        print(f"{'entry':>10}  {'module':<42}  instr")
        for entry, module, size, _ in sorted(loops, key=lambda f: -f[2])[: args.top]:
            print(f"0x{entry:08x}  {module:<42}  {size}")

    if args.overlap:
        twin = sorted(pc for pc in readable if pc in per_pc)
        print(f"\nreadable ports that still have a generated twin: {len(twin)}")
        for pc in twin:
            print(f"0x{pc:08x}  {readable[pc]:<28}  {per_pc[pc][0]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
