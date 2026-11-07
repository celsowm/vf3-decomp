#!/usr/bin/env python3
"""Read little-endian values from a raw guest RAM or image binary.

The file is treated as a contiguous range beginning at ``--base``. Guest
address mirrors in the 0x0c/0x8c/0xac regions resolve to the same physical
offset. This is for offline inspection; it does not patch the input file.

Example:
  python tools/ram_read.py build/boot_long.ram --base 0x0c000000 \
      0x0c046e50 0x0c04c9a2
  python tools/ram_read.py extract/exe/1ST_READ.unsc.bin --base 0x8c010000 \
      --float32 0x8c08ddc8 0x8c08ddcc
  python tools/ram_read.py extract/exe/1ST_READ.unsc.bin --base 0x8c010000 \
      --dump-range 0x8c08dd54:0x24
"""

from __future__ import annotations

import argparse
from pathlib import Path
import struct
import sys

ADDRESS_MASK = 0x1FFFFFFF
UINT32_MAX = 0xFFFFFFFF


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= UINT32_MAX:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def read_value(data: bytes, base: int, address: int, width: int) -> tuple[int, bytes]:
    physical_base = base & ADDRESS_MASK
    physical_address = address & ADDRESS_MASK
    offset = physical_address - physical_base
    if offset < 0 or offset + width > len(data):
        raise ValueError(
            f"{address:#010x} maps to file offset {offset:#x}, outside "
            f"the {len(data):#x}-byte file based at {base:#010x}"
        )
    raw = data[offset:offset + width]
    return offset, raw


def range_spec(text: str) -> tuple[int, int]:
    try:
        address_text, size_text = text.split(":", 1)
        address = number(address_text)
        size = int(size_text, 0)
    except (ValueError, argparse.ArgumentTypeError) as exc:
        raise argparse.ArgumentTypeError(
            "range must be ADDRESS:SIZE (for example 0x8c010000:0x40)"
        ) from exc
    if size <= 0:
        raise argparse.ArgumentTypeError("range size must be positive")
    return address, size


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path, help="raw RAM/image binary")
    parser.add_argument("addresses", nargs="*", type=number,
                        help="guest virtual addresses to read (decimal or 0x hex)")
    parser.add_argument("--base", type=number, required=True,
                        help="guest address corresponding to file offset zero")
    parser.add_argument("--bytes", type=int, default=4,
                        help="read width in bytes, from 1 to 8 (default: 4)")
    parser.add_argument("--float32", action="store_true",
                        help="also decode each four-byte value as IEEE-754 float")
    parser.add_argument("--dump-range", action="append", type=range_spec, default=[],
                        metavar="ADDRESS:SIZE",
                        help="dump bytes from an address range; may be repeated")
    args = parser.parse_args(argv)
    if not args.addresses and not args.dump_range:
        parser.error("provide at least one address or --dump-range")
    if not 1 <= args.bytes <= 8:
        parser.error("--bytes must be between 1 and 8")
    if args.float32 and (args.bytes != 4 or not args.addresses):
        parser.error("--float32 requires --bytes 4")

    try:
        data = args.binary.read_bytes()
        for address in args.addresses:
            offset, raw = read_value(data, args.base, address, args.bytes)
            value = int.from_bytes(raw, "little")
            float_value = f" f32={struct.unpack('<f', raw)[0]:.9g}" if args.float32 else ""
            print(
                f"guest={address:#010x} physical={address & ADDRESS_MASK:#010x} "
                f"file+{offset:#x} bytes={raw.hex()} "
                f"little=0x{value:0{args.bytes * 2}x}{float_value}"
            )
        for address, size in args.dump_range:
            offset, raw = read_value(data, args.base, address, size)
            print(
                f"range guest={address:#010x} physical={address & ADDRESS_MASK:#010x} "
                f"file+{offset:#x} size={size:#x}"
            )
            for line_offset in range(0, len(raw), 16):
                line = raw[line_offset:line_offset + 16]
                print(f"  {address + line_offset:#010x}: {line.hex(' ')}")
    except (OSError, ValueError) as exc:
        print(f"ram_read: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
