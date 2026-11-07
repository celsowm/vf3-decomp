#!/usr/bin/env python3
"""Find aligned SH-4 pointer words that refer to requested guest addresses.

This is an offline reverse-engineering helper for locating function-pointer
tables, descriptor references, and runtime objects in an image or RAM dump.
The input is treated as a contiguous byte range beginning at ``--base``.
With ``--physical-aliases``, P1/P2/P3 aliases compare by their 29-bit physical
address while the original word and virtual location are retained in output.

Examples:
  python tools/sh4_pointer_refs.py extract/exe/1ST_READ.unsc.bin \
      --base 0x0c010000 --target 0x8c095040 --physical-aliases
  python tools/sh4_pointer_refs.py extract/analysis/vf3_27_ram.bin \
      --base 0x0c000000 --target 0x0c20138c --target 0x8c095040 \
      --physical-aliases
"""

from __future__ import annotations

import argparse
from pathlib import Path
import struct
import sys

UINT32_MAX = 0xFFFFFFFF
PHYSICAL_MASK = 0x1FFFFFFF


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= UINT32_MAX:
        raise argparse.ArgumentTypeError("value must fit in an unsigned 32-bit word")
    return value


def scan(data: bytes, base: int, targets: list[int], alignment: int,
         physical_aliases: bool) -> dict[int, list[tuple[int, int]]]:
    """Return (guest location, original word) matches for each target."""
    normalize = (lambda value: value & PHYSICAL_MASK) if physical_aliases else int
    wanted: dict[int, list[int]] = {}
    for target in targets:
        wanted.setdefault(normalize(target), []).append(target)
    found: dict[int, list[tuple[int, int]]] = {target: [] for target in targets}
    first = (-base) % alignment
    for offset in range(first, len(data) - 3, alignment):
        word = struct.unpack_from("<I", data, offset)[0]
        for target in wanted.get(normalize(word), ()):
            found[target].append((base + offset, word))
    return found


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw image or RAM dump")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--target", type=number, action="append", required=True,
                        help="pointer value to find; repeat for multiple targets")
    parser.add_argument("--alignment", type=int, default=4,
                        help="file-offset alignment to scan (default: 4)")
    parser.add_argument("--physical-aliases", action="store_true",
                        help="match 0x0c/0x8c/0xac mirrors by physical address")
    args = parser.parse_args(argv)
    if args.alignment < 1 or args.alignment > 16:
        parser.error("--alignment must be between 1 and 16")
    try:
        data = args.binary.read_bytes()
        matches = scan(data, args.base, args.target, args.alignment,
                       args.physical_aliases)
        mode = "physical aliases" if args.physical_aliases else "exact values"
        print(f"{args.binary}: {len(data)} bytes at {args.base:#010x}; {mode}")
        for target in args.target:
            rows = matches[target]
            print(f"target {target:#010x}: {len(rows)} reference(s)")
            for address, word in rows:
                print(f"  {address:#010x}: {word:#010x}")
        return 0
    except OSError as exc:
        print(f"sh4_pointer_refs: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
