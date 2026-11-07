#!/usr/bin/env python3
"""Print the 23 bone-pose table advances and their cumulative object offsets.

This reads the static byte table used by 0x8C091438 from a raw image or RAM
dump. It reports pointer arithmetic only; it does not assign joints to POL
models or MT channels.

Example:
  python tools/bone_pose_map.py extract/exe/1ST_READ.unsc.bin --base 0x8c010000
"""

from __future__ import annotations

import argparse
from pathlib import Path
import sys

from ram_read import number, read_value

DEFAULT_TABLE = 0x0C119670
DEFAULT_BONES = 23


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw image or RAM binary")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--table", type=number, default=DEFAULT_TABLE,
                        help=f"joint-advance byte table (default {DEFAULT_TABLE:#x})")
    parser.add_argument("--count", type=int, default=DEFAULT_BONES,
                        help=f"number of bone rows (default {DEFAULT_BONES})")
    parser.add_argument("--joint-base", type=number, default=0x180,
                        help="joint pointer offset in the fighter object")
    parser.add_argument("--matrix-base", type=number, default=0x7C0,
                        help="matrix array offset in the fighter object")
    parser.add_argument("--pose-base", type=number, default=0xE00,
                        help="cached pose-record array offset in the fighter object")
    args = parser.parse_args(argv)
    if not 1 <= args.count <= 255:
        parser.error("--count must be between 1 and 255")

    try:
        data = args.binary.read_bytes()
        _offset, raw = read_value(data, args.base, args.table, args.count)
    except (OSError, ValueError) as exc:
        print(f"bone_pose_map: {exc}", file=sys.stderr)
        return 1

    cumulative = 0
    print(f"table={args.table:#010x} count={args.count} bytes={raw.hex()}")
    print("bone advance joint_object_offset matrix_object_offset pose_object_offset")
    for index, advance in enumerate(raw):
        cumulative += advance
        print(
            f"{index:4d} {advance:#08x} "
            f"{args.joint_base + cumulative:#08x} "
            f"{args.matrix_base + index * 64:#08x} "
            f"{args.pose_base + index * 20:#08x}"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
