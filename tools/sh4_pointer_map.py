#!/usr/bin/env python3
"""Inspect a little-endian SH-4 pointer table whose targets are packed maps.

The table contains ``count`` guest addresses. Each target starts a packed array
of fixed-width values; the next target bounds the current array, and ``--end``
bounds the final one. This is an offline image/RAM inspection helper and never
modifies its input.

Example (the state-to-motion maps at 0x0c102e34):
  python tools/sh4_pointer_map.py extract/exe/1ST_READ.unsc.bin \
      --base 0x0c010000 --table 0x0c102e34 --count 7 --end 0x0c102e34
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


def number(value: str) -> int:
    return int(value, 0)


def physical(address: int) -> int:
    """Collapse the SH-4 P1/P2 aliases to their 29-bit physical address."""
    return address & 0x1FFFFFFF


def offset_for(address: int, base: int, size: int, width: int = 1) -> int:
    offset = physical(address) - physical(base)
    if offset < 0 or offset + width > size:
        raise ValueError(
            f"guest address 0x{address:08x} (physical 0x{physical(address):08x}) "
            f"is outside image [0x{physical(base):08x}, "
            f"0x{physical(base) + size:08x})"
        )
    return offset


def run() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw image/RAM binary")
    parser.add_argument("--base", required=True, type=number,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--table", required=True, type=number,
                        help="guest address of the pointer table")
    parser.add_argument("--count", required=True, type=int,
                        help="number of pointers in the table")
    parser.add_argument("--end", required=True, type=number,
                        help="exclusive guest address ending the last map")
    parser.add_argument("--element-width", type=int, choices=(1, 2, 4),
                        default=2, help="packed map value width (default: 2)")
    parser.add_argument("--selector", type=int,
                        help="show only this pointer-table row")
    parser.add_argument("--index", type=int,
                        help="show only this element index from each selected map")
    args = parser.parse_args()

    try:
        data = args.binary.read_bytes()
        if args.count < 1:
            raise ValueError("--count must be positive")
        if args.selector is not None and not 0 <= args.selector < args.count:
            raise ValueError(f"--selector must be in 0..{args.count - 1}")
        if args.index is not None and args.index < 0:
            raise ValueError("--index must be non-negative")

        table_off = offset_for(args.table, args.base, len(data), args.count * 4)
        pointers = list(struct.unpack_from(f"<{args.count}I", data, table_off))
        end_phys = physical(args.end)
        targets = [physical(pointer) for pointer in pointers]
        if any(right <= left for left, right in zip(targets, targets[1:])):
            raise ValueError("pointer targets must be strictly increasing")
        if end_phys <= targets[-1]:
            raise ValueError("--end must be after the final pointer target")

        first = args.selector if args.selector is not None else 0
        last = first + 1 if args.selector is not None else args.count
        fmt = {1: "B", 2: "H", 4: "I"}[args.element_width]
        for selector in range(first, last):
            start = targets[selector]
            stop = targets[selector + 1] if selector + 1 < args.count else end_phys
            span = stop - start
            if span % args.element_width:
                raise ValueError(
                    f"map {selector} span 0x{span:x} is not divisible by "
                    f"element width {args.element_width}"
                )
            entries = span // args.element_width
            if args.index is not None:
                if args.index >= entries:
                    raise ValueError(
                        f"map {selector} has {entries} elements; index {args.index} is out of range"
                    )
                selected = struct.unpack_from(
                    f"<{fmt}", data,
                    offset_for(start + args.index * args.element_width,
                               args.base, len(data), args.element_width),
                )
                values = selected
            else:
                start_off = offset_for(start, args.base, len(data), span)
                values = struct.unpack_from(f"<{entries}{fmt}", data, start_off)

            rendered = " ".join(f"0x{value:0{args.element_width * 2}x}" for value in values)
            print(
                f"selector={selector} target=0x{pointers[selector]:08x} "
                f"count={entries} values={rendered}"
            )
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"sh4_pointer_map: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(run())
