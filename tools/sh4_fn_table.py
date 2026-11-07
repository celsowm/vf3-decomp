#!/usr/bin/env python3
"""List entries from an unsorted SH-4 function-pointer table.

Unlike ``sh4_pointer_map.py``, this tool does not infer packed-array spans or
require targets to be increasing. It is intended for callback and dispatch
tables whose values are code addresses.

Example:
  python tools/sh4_fn_table.py extract/exe/1ST_READ.unsc.bin \
      --base 0x0c010000 --table 0x0c10f4b0 --count 20
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
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


def physical(value: int) -> int:
    return value & ADDRESS_MASK


def read_table(data: bytes, base: int, table: int, count: int,
               selected: list[int] | None = None) -> list[dict[str, object]]:
    if count < 1:
        raise ValueError("--count must be positive")
    indices = list(range(count)) if selected is None else sorted(set(selected))
    if any(index < 0 or index >= count for index in indices):
        raise ValueError(f"selected indices must be between 0 and {count - 1}")
    offset = physical(table) - physical(base)
    if offset < 0 or offset + count * 4 > len(data):
        raise ValueError(
            f"table 0x{table:08x} with {count} entries is outside image "
            f"based at 0x{base:08x}"
        )
    pointers = struct.unpack_from(f"<{count}I", data, offset)
    return [{
        "index": index,
        "file_offset": offset + index * 4,
        "pointer": pointers[index],
        "physical": physical(pointers[index]),
    } for index in indices]


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw SH-4 image or RAM dump")
    parser.add_argument("--base", required=True, type=address,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--table", required=True, type=address,
                        help="guest address of the first 32-bit pointer")
    parser.add_argument("--count", required=True, type=int,
                        help="number of entries to read")
    parser.add_argument("--index", type=int, action="append",
                        help="show only this index; repeatable")
    parser.add_argument("--json", action="store_true", help="emit JSON")
    args = parser.parse_args(argv)

    try:
        rows = read_table(args.binary.read_bytes(), args.base, args.table,
                          args.count, args.index)
        if args.json:
            print(json.dumps({
                "diagnostic_only": True,
                "binary": str(args.binary),
                "base": f"0x{args.base:08x}",
                "table": f"0x{args.table:08x}",
                "count": args.count,
                "entries": [{
                    "index": row["index"],
                    "file_offset": f"0x{row['file_offset']:x}",
                    "pointer": f"0x{row['pointer']:08x}",
                    "physical": f"0x{row['physical']:08x}",
                } for row in rows],
            }, indent=2))
        else:
            for row in rows:
                print(f"[{row['index']:3}] file+0x{row['file_offset']:x} "
                      f"0x{row['pointer']:08x} "
                      f"(physical 0x{row['physical']:08x})")
    except (OSError, ValueError, struct.error) as exc:
        print(f"sh4_fn_table: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
