#!/usr/bin/env python3
"""adapter_dump.py - print a generated adapter function as guest disassembly.

The generated modules under src/fight/*adapter*.c are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode.  Each
label carries the original opcode word in a comment ("original 2fe6"), so the
file is a faithful disassembly of the function it implements.

This tool prints that view for one entry: the PC, the opcode word, the decoded
SH-4 mnemonic and the C the translator emitted for it.  It is the bridge
between the generated translation and a hand-written readable port, and it
needs no capture artifact - it reads the committed sources only.

Usage:
    python tools/adapter_dump.py 0x0c035a20
    python tools/adapter_dump.py 0x0c035a20 --module matrix_adapters
    python tools/adapter_dump.py --list 0x0c035a2
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src" / "fight"

LABEL_RE = re.compile(r"^P_([0-9a-f]{8}):\s*(?:/\* original ([0-9a-f]{4}), guest PC 0x([0-9a-f]{8}) \*/)?")
ADDR_RE = re.compile(r"0x([0-9a-f]{8})u")
GOTO_RE = re.compile(r"goto P_([0-9a-f]{8});")


def index_modules() -> dict[str, dict[int, tuple[str, list[str]]]]:
    """module stem -> {pc: (opcode word, [C statements])}"""
    out: dict[str, dict[int, tuple[str, list[str]]]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        lines = text.splitlines()
        blocks: dict[int, tuple[str, list[str]]] = {}
        current: int | None = None
        opcode = ""
        body: list[str] = []
        for line in lines:
            m = LABEL_RE.match(line)
            if m:
                if current is not None:
                    blocks[current] = (opcode, body)
                current = int(m.group(1), 16)
                opcode = m.group(2) or ""
                body = []
                continue
            if current is not None:
                stripped = line.strip()
                if stripped and not stripped.startswith("/*") and not stripped.startswith("*"):
                    body.append(stripped)
                elif stripped.startswith("/*") and "original" in stripped:
                    body.append(stripped)
        if current is not None:
            blocks[current] = (opcode, body)
        out[path.stem] = blocks
    return out


def decode(word: str) -> str:
    """Best-effort SH-4 mnemonic for an opcode word."""
    if not word:
        return "?"
    w = int(word, 16)
    n, m, d4 = (w >> 8) & 15, (w >> 4) & 15, w & 15
    top = w >> 12
    names = {0: "mov", 1: "mov.w", 2: "mov.b", 3: "add", 4: "addc",
             5: "mov.l", 6: "mov", 7: "add", 8: "cmp/eq", 9: "mov.w(str)",
             0xB: "bsr", 0xD: "mov.l(str)", 0xE: "mov #imm"}
    if w == 0x0009:
        return "nop"
    if top in names:
        return names[top]
    return "op?"


def functions_of(blocks: dict[int, tuple[str, list[str]]]) -> list[tuple[int, int, bool]]:
    """Split a module's blocks into functions: (entry, instruction count, has loop).

    The translator emits one label per guest PC, in PC order, and a function
    ends at its `rts`.  A backward goto inside a function is a loop.
    """
    out: list[tuple[int, int, bool]] = []
    current: list[tuple[int, str]] = []
    for pc in sorted(blocks):
        body = " ".join(blocks[pc][1])
        current.append((pc, body))
        if "s->pc=target" in body:
            loop = False
            for p, b in current:
                for g in GOTO_RE.finditer(b):
                    if int(g.group(1), 16) <= p:
                        loop = True
            out.append((current[0][0], len(current), loop))
            current = []
    return out


def walk(entry: int, blocks: dict[int, tuple[str, list[str]]]) -> tuple[list[int], bool]:
    """Follow a function's control flow from its entry.

    Returns the guest PCs it executes and whether it contains a loop (a
    backward edge).  A call (`return vf3_matrix_family(...)`) is not a
    successor: the callee has its own entry.
    """
    pcs: list[int] = []
    seen: set[int] = set()
    pc: int | None = entry
    loop = False
    while pc is not None and pc not in seen:
        seen.add(pc)
        pcs.append(pc)
        word, body = blocks.get(pc, ("", []))
        nxt = None
        for stmt in body:
            m = GOTO_RE.search(stmt)
            if m:
                nxt = int(m.group(1), 16)
                if nxt <= pc:
                    loop = True
        if nxt is None:
            break
        pc = nxt
    return pcs, loop


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("entry", nargs="?", help="guest entry, e.g. 0x0c035a20")
    ap.add_argument("--module", help="restrict to one generated module")
    ap.add_argument("--list", help="list the PCs of a module that match a prefix")
    ap.add_argument("--range", help="list the functions whose entry falls in LO..HI")
    ap.add_argument("--max", type=int, default=400, help="max blocks to print")
    args = ap.parse_args()

    modules = index_modules()
    if args.module:
        modules = {k: v for k, v in modules.items() if args.module in k}

    if args.range:
        lo, hi = (int(x, 16) for x in args.range.lower().split(".."))
        for stem, blocks in modules.items():
            for entry, size, has_loop in functions_of(blocks):
                if lo <= entry < hi:
                    print(f"0x{entry:08x}  {stem:<34}  {size:4d} instr"
                          f"{'  loop' if has_loop else ''}")
        return 0

    if args.list:
        pref = args.list.lower().replace("0x", "")
        for stem, blocks in modules.items():
            hits = sorted(p for p in blocks if f"{p:08x}".startswith(pref))
            for p in hits:
                print(f"0x{p:08x}  {stem}")
        return 0

    if not args.entry:
        ap.error("entry or --list is required")

    want = int(args.entry, 16) & 0x1FFFFFFF
    found = None
    for stem, blocks in modules.items():
        if want in blocks:
            found = (stem, blocks)
            break
    if not found:
        print(f"entry {args.entry} is not implemented by a generated module")
        return 1

    stem, blocks = found
    print(f"# {args.entry} in {stem}")
    pc = want
    seen = set()
    count = 0
    while pc is not None and count < args.max:
        if pc in seen:
            print(f"  ... back edge to 0x{pc:08x}")
            break
        seen.add(pc)
        word, body = blocks.get(pc, ("", []))
        code = " ".join(s for s in body if not s.startswith("if(!s->budget--)"))
        print(f"  0x{pc:08x}  {word:<4}  {decode(word):<12}  {code}")
        count += 1
        nxt = None
        for stmt in body:
            m = re.search(r"goto P_([0-9a-f]{8});", stmt)
            if m:
                nxt = int(m.group(1), 16)
        if nxt is None:
            for stmt in body:
                if "s->pc=target" in stmt:
                    print("  # rts")
                    return 0
            print("  # (no successor)")
            return 0
        pc = nxt
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
