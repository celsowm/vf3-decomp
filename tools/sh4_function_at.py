#!/usr/bin/env python3
"""Find Ghidra function records that contain requested SH-4 addresses.

This is useful for assigning pointer-table or literal-pool references back to
the function whose byte range contains them. The function CSV is expected to
have the standard ``entry,size,name`` header emitted by the repo's Ghidra
baseline script. Function sizes are decimal byte counts; CSV entries are
hexadecimal without a prefix, while queried addresses accept Python-style
integer syntax.

Example:
  python tools/sh4_function_at.py extract/analysis/funcs_1ST_READ.unsc.bin.csv \
      --address 0x8c0a99e0 --address 0x8c0aa1bc --physical-aliases
"""

from __future__ import annotations

import argparse
import csv
from pathlib import Path
import sys

ADDRESS_MASK = 0x1FFFFFFF
UINT32_MAX = 0xFFFFFFFF


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= UINT32_MAX:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def load_functions(path: Path) -> list[tuple[int, int, str]]:
    functions: list[tuple[int, int, str]] = []
    with path.open("r", encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream)
        required = {"entry", "size", "name"}
        if reader.fieldnames is None or not required.issubset(reader.fieldnames):
            raise ValueError("CSV must have entry,size,name columns")
        for line, row in enumerate(reader, start=2):
            try:
                raw_entry = row["entry"].strip()
                entry = (int(raw_entry, 0) if raw_entry.lower().startswith("0x")
                         else int(raw_entry, 16))
                size = int(row["size"].strip(), 10)
                name = row["name"].strip()
            except (AttributeError, ValueError) as exc:
                raise ValueError(f"invalid function row at line {line}") from exc
            if not 0 <= entry <= UINT32_MAX or size <= 0 or not name:
                raise ValueError(f"invalid function row at line {line}")
            if entry + size > UINT32_MAX + 1:
                raise ValueError(f"function range overflows at line {line}")
            functions.append((entry, size, name))
    return functions


def find_containing(functions: list[tuple[int, int, str]], query: int,
                    physical_aliases: bool) -> list[tuple[int, int, str]]:
    normalized = query & ADDRESS_MASK if physical_aliases else query
    matches = []
    for entry, size, name in functions:
        start = entry & ADDRESS_MASK if physical_aliases else entry
        if start <= normalized < start + size:
            matches.append((entry, size, name))
    return matches


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("functions", type=Path, help="Ghidra function CSV")
    parser.add_argument("--address", type=address, action="append", required=True,
                        help="guest address to locate; repeatable")
    parser.add_argument("--physical-aliases", action="store_true",
                        help="compare 0x0c/0x8c/0xac mirrors by physical address")
    args = parser.parse_args(argv)

    try:
        functions = load_functions(args.functions)
        for query in args.address:
            matches = find_containing(functions, query, args.physical_aliases)
            print(f"{query:#010x}:")
            if not matches:
                print("  no function range contains this address")
                continue
            for entry, size, name in matches:
                print(f"  {name} [{entry:#010x}, {entry + size:#010x}) "
                      f"({size} bytes)")
        return 0
    except (OSError, ValueError) as exc:
        print(f"sh4_function_at: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
