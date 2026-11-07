#!/usr/bin/env python3
"""Find reachable direct SH-4 branches that target requested addresses.

The scan follows control flow from each function entry, which avoids decoding
literal pools skipped by branches. It reports direct ``bra``, ``bsr``, ``bt``,
``bf`` and delayed conditional branches. Register-indirect targets are not
resolved, and function fragments entered only at an interior address may be
missed.

Example:
  python tools/sh4_branch_refs.py extract/exe/1ST_READ.unsc.bin \
      --base 0x8c010000 \
      --functions extract/analysis/funcs_1ST_READ.unsc.bin.csv \
      --target 0x8c095040 --target 0x8c0951d2
"""

from __future__ import annotations

import argparse
import csv
from pathlib import Path
import re
import sys

from capstone import CS_ARCH_SH, CS_MODE_LITTLE_ENDIAN, CS_MODE_SH4, CS_MODE_SHFPU, Cs

UINT32_MAX = 0xFFFFFFFF
PHYSICAL_MASK = 0x1FFFFFFF
BRANCHES = {"bra", "bsr", "bt", "bf", "bt/s", "bf/s"}


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= UINT32_MAX:
        raise argparse.ArgumentTypeError("address must fit in an unsigned 32-bit word")
    return value


def read_functions(path: Path) -> list[tuple[int, int, str]]:
    rows = []
    with path.open(newline="", encoding="utf-8-sig") as handle:
        for row in csv.DictReader(handle):
            try:
                entry = int(row["entry"], 16)
                size = int(row["size"], 0)
                name = row.get("name") or f"fn_{entry:08x}"
            except (KeyError, TypeError, ValueError) as exc:
                raise ValueError(f"invalid function row: {row}") from exc
            if size <= 0:
                continue
            rows.append((entry, size, name))
    return rows


def scan(data: bytes, base: int, functions: list[tuple[int, int, str]],
         targets: list[int], physical_aliases: bool) -> dict[int, list[dict[str, int | str]]]:
    normalize = (lambda value: value & PHYSICAL_MASK) if physical_aliases else int
    wanted: dict[int, list[int]] = {}
    for target in targets:
        wanted.setdefault(normalize(target), []).append(target)
    found: dict[int, list[dict[str, int | str]]] = {target: [] for target in targets}
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_SHFPU | CS_MODE_LITTLE_ENDIAN)
    operand_target = re.compile(r"0x[0-9a-fA-F]+")

    for entry, size, name in functions:
        start = (entry & PHYSICAL_MASK) - (base & PHYSICAL_MASK)
        if start < 0 or start >= len(data):
            continue
        stop = min(start + size, len(data))
        pending = [start]
        visited: set[int] = set()
        while pending:
            offset = pending.pop()
            if offset in visited or offset < start or offset + 1 >= stop:
                continue
            visited.add(offset)
            address = base + offset
            instruction = next(md.disasm(data[offset:offset + 2], address, 1), None)
            if instruction is None:
                continue
            mnemonic = instruction.mnemonic
            branch_target = None
            if mnemonic in BRANCHES:
                match = operand_target.search(instruction.op_str)
                if match:
                    branch_target = int(match.group(0), 16)
                    for target in wanted.get(normalize(branch_target), ()):
                        found[target].append({
                            "source": address,
                            "target": branch_target,
                            "function": name,
                            "mnemonic": mnemonic,
                        })

            delayed = mnemonic.endswith("/s") or mnemonic in {"bra", "bsr", "jmp", "jsr", "braf", "bsrf", "rts", "rte"}
            after_delay = offset + (4 if delayed else 2)
            if delayed:
                pending.append(offset + 2)

            if mnemonic in {"rts", "rte", "jmp", "braf"}:
                continue
            if mnemonic == "bra":
                if branch_target is not None:
                    target_offset = (branch_target & PHYSICAL_MASK) - (base & PHYSICAL_MASK)
                    if start <= target_offset < stop:
                        pending.append(target_offset)
                continue
            if mnemonic in {"bt", "bf", "bt/s", "bf/s"} and branch_target is not None:
                target_offset = (branch_target & PHYSICAL_MASK) - (base & PHYSICAL_MASK)
                if start <= target_offset < stop:
                    pending.append(target_offset)
            if after_delay < stop:
                pending.append(after_delay)
    return found


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw SH-4 image or RAM dump")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--functions", type=Path, required=True,
                        help="CSV with entry,size,name columns")
    parser.add_argument("--target", type=number, action="append", required=True,
                        help="branch destination to find; repeat for multiple targets")
    parser.add_argument("--physical-aliases", action="store_true",
                        help="match 0x0c/0x8c/0xac mirrors by physical address")
    args = parser.parse_args(argv)
    try:
        data = args.binary.read_bytes()
        functions = read_functions(args.functions)
        matches = scan(data, args.base, functions, args.target,
                       args.physical_aliases)
        print(f"{args.binary}: {len(functions)} functions; "
              f"{len(data)} bytes at {args.base:#010x}")
        for target in args.target:
            rows = matches[target]
            print(f"target {target:#010x}: {len(rows)} direct branch(es)")
            for row in rows:
                print(f"  {row['source']:#010x}: {row['function']} "
                      f"{row['mnemonic']} {row['target']:#010x}")
        return 0
    except (OSError, ValueError) as exc:
        print(f"sh4_branch_refs: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
