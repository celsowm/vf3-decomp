#!/usr/bin/env python3
"""Find SH-4 PC-relative literal loads whose pool value matches a target.

Unlike a raw 32-bit pointer scan, this reports the instruction, pool address,
width, and decoded literal value. It is useful for locating code that loads a
constant or pointer from the nearby literal pool. The scan is linear over
2-byte offsets, so validate each candidate against a real function boundary.

Examples:
  python tools/sh4_literal_scan.py extract/exe/1ST_READ.unsc.bin \
      --base 0x8c010000 --target 0x1561 --target 0x1560 --width 2
  python tools/sh4_literal_scan.py extract/exe/1ST_READ.unsc.bin \
      --base 0x8c010000 --target 0x0c2a4d90 --width 4
"""

from __future__ import annotations

import argparse
from pathlib import Path
import re
import sys

from capstone import CS_ARCH_SH, CS_MODE_LITTLE_ENDIAN, CS_MODE_SH4, CS_MODE_SHFPU, Cs

UINT32_MAX = 0xFFFFFFFF


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= UINT32_MAX:
        raise argparse.ArgumentTypeError("value must fit in an unsigned 32-bit word")
    return value


def scan(data: bytes, base: int,
         targets: set[tuple[int, int]]) -> list[dict[str, int | str]]:
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_SHFPU | CS_MODE_LITTLE_ENDIAN)
    matches: list[dict[str, int | str]] = []
    for offset in range(0, len(data) - 1, 2):
        address = base + offset
        instruction = next(md.disasm(data[offset:offset + 2], address, 1), None)
        if instruction is None or instruction.mnemonic not in ("mov.w", "mov.l"):
            continue
        match = re.fullmatch(r"(0x[0-9a-fA-F]+),\s*(r\d+)", instruction.op_str)
        if not match:
            continue
        pool_address = int(match.group(1), 16)
        width = 2 if instruction.mnemonic == "mov.w" else 4
        pool_offset = pool_address - base
        if pool_offset < 0 or pool_offset + width > len(data):
            continue
        value = int.from_bytes(data[pool_offset:pool_offset + width], "little")
        if (width, value) in targets:
            matches.append({
                "instruction": address,
                "pool": pool_address,
                "width": width,
                "value": value,
                "register": match.group(2),
                "mnemonic": instruction.mnemonic,
            })
    return matches


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw SH-4 image or RAM dump")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--target", type=number, action="append", required=True,
                        help="literal value to find; repeat for multiple values")
    parser.add_argument("--width", type=int, choices=(2, 4), action="append",
                        help="literal width to search; repeatable (default: both)")
    args = parser.parse_args(argv)
    widths = set(args.width or (2, 4))
    targets = {(width, value) for width in widths for value in args.target
               if value < (1 << (width * 8))}
    try:
        data = args.binary.read_bytes()
        matches = scan(data, args.base, targets)
        print(f"{args.binary}: {len(data)} bytes at {args.base:#010x}")
        if not matches:
            print("no matching PC-relative literal loads")
        for row in matches:
            print(f"{row['instruction']:#010x}: {row['mnemonic']} {row['register']} "
                  f"pool={row['pool']:#010x} width={row['width']} "
                  f"value={row['value']:#010x}")
        print(f"{len(matches)} candidate(s); confirm function boundaries before interpreting")
        return 0
    except (OSError, ImportError) as exc:
        print(f"sh4_literal_scan: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
