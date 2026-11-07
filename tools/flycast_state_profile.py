#!/usr/bin/env python3
"""Read the same SH-4 RAM fields from several saved Flycast states.

This is an offline reverse-engineering helper. It reuses the verified RAM
locator from ``flycast_ram.py`` and never changes the state files.

Example:
  python tools/flycast_state_profile.py tools/emu/flycast-build/data/vf3_26.state \
      tools/emu/flycast-build/data/vf3_27.state --image extract/exe/1ST_READ.unsc.bin \
      --read 0x0c1fefe4+0x61:1 --read 0x0c1fefe4+0x3c:2
"""

from __future__ import annotations

import argparse
from collections import Counter
from pathlib import Path
import sys

from flycast_ram import (DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram)
from aica_state import load_state


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def read_spec(text: str) -> tuple[str, int, int]:
    try:
        label, size_text = text.rsplit(":", 1)
        if "+" in label:
            address_text, offset_text = label.split("+", 1)
            address = number(address_text)
            offset = int(offset_text, 0)
        else:
            address, offset = number(label), 0
        size = int(size_text, 0)
    except (ValueError, argparse.ArgumentTypeError) as exc:
        raise argparse.ArgumentTypeError(
            "expected ADDRESS[:+OFFSET]:SIZE, e.g. 0x0c100000+0x61:1") from exc
    if offset < 0 or size <= 0 or address + offset + size > 0x100000000:
        raise argparse.ArgumentTypeError("read range must fit the 32-bit address space")
    return text, address + offset, size


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("states", nargs="+", type=Path,
                        help="Flycast savestate paths to inspect")
    parser.add_argument("--image", required=True, type=Path,
                        help="exact game image loaded in each state")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS)
    parser.add_argument("--anchor-bytes", type=number,
                        help="require this many leading image bytes to match")
    parser.add_argument("--read", required=True, action="append", type=read_spec,
                        metavar="ADDRESS[+OFFSET]:SIZE",
                        help="RAM field to read; repeat for additional fields")
    parser.add_argument("--summary", action="store_true",
                        help="also group identical field values across the states")
    args = parser.parse_args(argv)

    try:
        image = args.image.read_bytes()
        observed: dict[str, list[tuple[str, str]]] = {
            label: [] for label, _, _ in args.read
        }
        for state_path in args.states:
            blob = load_state(str(state_path))
            ram_offset, ram, proof = locate_ram(
                blob, image, args.image_address, args.anchor_bytes)
            print(f"{state_path}: RAM+0x{ram_offset:x} ({proof})")
            for label, address, size in args.read:
                raw = read_ram(ram, address, size)
                value = raw.hex()
                print(f"  {label} [{address:#010x}, {size} B] = {value}")
                observed[label].append((str(state_path), value))
        if args.summary:
            print("Field value summary:")
            for label, values in observed.items():
                counts = Counter(value for _, value in values)
                print(f"  {label}: {len(counts)} distinct value(s) across {len(values)} state(s)")
                for value, count in counts.most_common():
                    states = ", ".join(path for path, item in values if item == value)
                    print(f"    {value}: {count} state(s) [{states}]")
    except (OSError, ValueError) as exc:
        print(f"flycast_state_profile: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
