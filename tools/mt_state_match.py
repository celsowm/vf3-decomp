#!/usr/bin/env python3
"""Match a live fighter's mounted MT streams in a Flycast savestate.

This is an offline evidence tool. It extracts SH-4 RAM from a retained
Flycast savestate, follows ``actor+0x1D00`` to the mounted motion record, and
compares its bounded opcode/count/time/tuple streams with extracted MT packs.

Example:
  python tools/mt_state_match.py tools/emu/flycast-build/data/vf3_29.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4
"""

from __future__ import annotations

import argparse
from pathlib import Path
import struct
import sys

from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram
from aica_state import load_state
from mt_capture_match import CHANNELS, row_for_asset, stream_lengths


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def u16(ram: bytes, address: int, label: str) -> int:
    raw = read_ram(ram, address, 2)
    if len(raw) != 2:
        raise ValueError(f"short {label} at {address:#010x}")
    return struct.unpack("<H", raw)[0]


def u32(ram: bytes, address: int, label: str) -> int:
    raw = read_ram(ram, address, 4)
    if len(raw) != 4:
        raise ValueError(f"short {label} at {address:#010x}")
    return struct.unpack("<I", raw)[0]


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact game image loaded at --image-address")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help="game image RAM address (default: 0x0c010000)")
    parser.add_argument("--actor", type=number, required=True,
                        help="actor record address from offline evidence")
    parser.add_argument("--assets", type=Path, default=Path("extract/gamedata"),
                        help="directory containing extracted MT*.BIN files")
    parser.add_argument("--verbose", action="store_true",
                        help="list every exact pack match instead of the first five")
    args = parser.parse_args(argv)

    try:
        image = args.image.read_bytes()
        blob = load_state(str(args.state))
        ram_offset, ram, anchor = locate_ram(
            blob, image, args.image_address, None)
        motion_id = u16(ram, args.actor + 0x3C, "motion ID")
        frame_field = u16(ram, args.actor + 0x3E, "motion frame field")
        cycle = u16(ram, args.actor + 0x1A00, "cycle")
        record = u32(ram, args.actor + 0x1D00, "animation record pointer")
        count_pointer = u32(ram, record, "count-stream pointer")
        time_pointer = u32(ram, record + 4, "key-time pointer")
        tuple_pointer = u32(ram, record + 8, "tuple pointer")
        ops = read_ram(ram, record + 12, CHANNELS)
        count_count = sum(op >= 2 for op in ops)
        counts = read_ram(ram, count_pointer + 1, count_count)
        time_count, tuple_count = stream_lengths(ops, counts)
        times = read_ram(ram, time_pointer, time_count)
        tuples = read_ram(ram, tuple_pointer, tuple_count)
        captured = {"ops": ops, "counts": counts,
                    "times": times, "tuples": tuples}

        paths = sorted(args.assets.glob("MT*.BIN"))
        if not paths:
            raise ValueError(f"no MT*.BIN assets found in {args.assets}")
        cache: dict[Path, tuple[bytes, dict[int, tuple[int, int]]]] = {}
        results = [row_for_asset(path, motion_id, captured, cache)
                   for path in paths]
        matches = [row for row in results if row.get("state") == "exact"]
        partial = [row for row in results if row.get("state") == "partial"]

        print(f"{args.state}: RAM at decompressed offset 0x{ram_offset:x}; {anchor}")
        print(f"actor={args.actor:#010x} motion=0x{motion_id:x} "
              f"frame_field={frame_field} cycle={cycle} "
              f"record={record:#010x} exact={len(matches)}/{len(paths)}")
        shown_matches = matches if args.verbose else matches[:5]
        for row in shown_matches:
            offsets = ",".join(f"0x{value:x}" for value in row["offsets"])
            print(f"  EXACT {row['asset']} offsets={offsets}")
        if len(shown_matches) < len(matches):
            print(f"  ... {len(matches) - len(shown_matches)} additional exact packs "
                  "(use --verbose to list)")
        if not matches:
            for row in partial:
                checks = " ".join(f"{name}={int(value)}"
                                  for name, value in row["comparisons"].items())
                print(f"  PARTIAL {row['asset']} {checks}")
        print(f"stream sizes: counts={len(counts)} times={len(times)} "
              f"tuples={len(tuples)}")
        return 0 if matches else 2
    except (OSError, ValueError, struct.error) as exc:
        print(f"mt_state_match: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
