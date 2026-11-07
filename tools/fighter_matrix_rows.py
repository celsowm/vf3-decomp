#!/usr/bin/env python3
"""Dump the 32-byte matrix-setup rows selected by 0x8C09132E.

The routine reads a selector byte at ``0x0C29B880``, indexes
``0x0C110B88 + selector * 32``, then reads halfwords at row offsets +8 and
+10. This offline inspector preserves the row bytes without assigning
meanings to the other fields.

Example:
  python tools/fighter_matrix_rows.py extract/exe/1ST_READ.unsc.bin \
      --base 0x8c010000 --row 11
"""

from __future__ import annotations

import argparse
from pathlib import Path
import struct
import sys


ADDRESS_MASK = 0x1FFFFFFF
DEFAULT_TABLE = 0x0C110B88
DEFAULT_STRIDE = 32
DEFAULT_COUNT = 22


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path,
                        help="raw game image or RAM dump")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--table", type=number, default=DEFAULT_TABLE,
                        help=f"row table address (default {DEFAULT_TABLE:#010x})")
    parser.add_argument("--count", type=int, default=DEFAULT_COUNT,
                        help=f"number of rows to inspect (default {DEFAULT_COUNT})")
    parser.add_argument("--stride", type=int, default=DEFAULT_STRIDE,
                        help=f"row byte stride (default {DEFAULT_STRIDE})")
    parser.add_argument("--row", type=int, action="append",
                        help="inspect only this zero-based selector row; repeatable")
    args = parser.parse_args(argv)
    if args.count < 1 or args.stride < 12 or args.stride % 4:
        parser.error("--count must be positive and --stride a multiple of four >= 12")
    if args.row is not None and any(row < 0 or row >= args.count
                                    for row in args.row):
        parser.error("--row must be in 0..count-1")

    try:
        data = args.binary.read_bytes()
        physical_base = args.base & ADDRESS_MASK
        physical_table = args.table & ADDRESS_MASK
        offset = physical_table - physical_base
        selected = set(args.row) if args.row is not None else set(range(args.count))
        if offset < 0 or offset + args.count * args.stride > len(data):
            raise ValueError(
                f"table {args.table:#010x} with {args.count} rows of "
                f"{args.stride} bytes exceeds the file based at {args.base:#010x}"
            )
        print(f"table={args.table:#010x} stride={args.stride} count={args.count}")
        print("row   +08/u16 +0a/u16  row words (little-endian)")
        word_count = args.stride // 4
        for row_index in sorted(selected):
            row = data[offset + row_index * args.stride:
                       offset + (row_index + 1) * args.stride]
            words = struct.unpack_from("<" + "I" * word_count, row)
            half8, half10 = struct.unpack_from("<HH", row, 8)
            print(f"{row_index:4d}  0x{half8:04x}  0x{half10:04x}  " +
                  " ".join(f"{word:08x}" for word in words))
    except (OSError, ValueError, struct.error) as exc:
        print(f"fighter_matrix_rows: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
