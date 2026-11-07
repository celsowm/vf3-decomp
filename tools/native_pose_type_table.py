#!/usr/bin/env python3
"""Inspect the 108-byte fighter-kind records used by the pose producer.

The SH-4 routine at 0x8C09EAF2 indexes 0x0C10D3C4 with actor byte +0x61 and
uses a 0x6c-byte stride. This tool reports the selected raw words and their
IEEE-754 interpretations without assigning field names or meanings.

Example:
  python tools/native_pose_type_table.py extract/exe/1ST_READ.unsc.bin \
      --base 0x8c010000 --kind 7 --kind 11 --json
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import struct
import sys


ADDRESS_MASK = 0x1FFFFFFF
DEFAULT_TABLE = 0x0C10D3C4
DEFAULT_STRIDE = 0x6C
DEFAULT_COUNT = 13


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def inspect(data: bytes, base: int, table: int, stride: int,
            count: int, kinds: list[int]) -> list[dict[str, object]]:
    physical_base = base & ADDRESS_MASK
    physical_table = table & ADDRESS_MASK
    table_offset = physical_table - physical_base
    if table_offset < 0 or table_offset + count * stride > len(data):
        raise ValueError(
            f"table {table:#010x} with {count} records of {stride:#x} bytes "
            f"lies outside the {len(data):#x}-byte image based at {base:#010x}"
        )

    result = []
    for kind in kinds:
        if kind >= count:
            raise ValueError(f"kind {kind} is outside the {count}-record table")
        offset = table_offset + kind * stride
        row = data[offset:offset + stride]
        words = []
        for word_index in range(stride // 4):
            raw = row[word_index * 4:word_index * 4 + 4]
            bits = struct.unpack("<I", raw)[0]
            value = struct.unpack("<f", raw)[0]
            words.append({
                "word_offset": word_index * 4,
                "bits": f"0x{bits:08x}",
                "float32": value if math.isfinite(value) else None,
            })
        result.append({
            "kind": kind,
            "guest_address": f"0x{(table + kind * stride) & 0xFFFFFFFF:08x}",
            "file_offset": offset,
            "stride": stride,
            "raw_hex": row.hex(),
            "words": words,
        })
    return result


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw image or RAM dump")
    parser.add_argument("--base", required=True, type=number,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--table", type=number, default=DEFAULT_TABLE,
                        help=f"record table address (default {DEFAULT_TABLE:#x})")
    parser.add_argument("--stride", type=number, default=DEFAULT_STRIDE,
                        help=f"record size in bytes (default {DEFAULT_STRIDE:#x})")
    parser.add_argument("--count", type=int, default=DEFAULT_COUNT,
                        help=f"number of table records (default {DEFAULT_COUNT})")
    parser.add_argument("--kind", type=int, action="append", required=True,
                        help="fighter-kind row to inspect; repeatable")
    parser.add_argument("--json", action="store_true",
                        help="emit raw words and finite float interpretations as JSON")
    args = parser.parse_args(argv)

    if args.stride < 4 or args.stride % 4:
        parser.error("--stride must be a positive multiple of four")
    if args.count <= 0:
        parser.error("--count must be positive")
    if any(kind < 0 for kind in args.kind):
        parser.error("--kind values cannot be negative")
    if len(set(args.kind)) != len(args.kind):
        parser.error("--kind values must be unique")

    try:
        data = args.binary.read_bytes()
        rows = inspect(data, args.base, args.table, args.stride,
                       args.count, args.kind)
    except (OSError, ValueError) as exc:
        print(f"native_pose_type_table: {exc}", file=sys.stderr)
        return 1

    if args.json:
        print(json.dumps({
            "diagnostic_only": True,
            "binary": str(args.binary),
            "table": f"0x{args.table:08x}",
            "stride": args.stride,
            "count": args.count,
            "rows": rows,
            "limitation": "Raw field offsets are reported without semantic names.",
        }, indent=2, allow_nan=False))
        return 0

    for row in rows:
        print(f"kind={row['kind']} guest={row['guest_address']} "
              f"file+0x{row['file_offset']:x} stride=0x{row['stride']:x}")
        for word in row["words"]:
            value = word["float32"]
            decoded = "non-finite" if value is None else f"{value:.9g}"
            print(f"  +0x{word['word_offset']:02x} {word['bits']} f32={decoded}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
