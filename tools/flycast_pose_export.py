#!/usr/bin/env python3
"""Inspect or export one fighter's matrix table from a Flycast savestate.

This is an offline evidence tool. It locates main RAM using the loaded game
image, follows the actor address supplied by the caller, and reports the
motion fields and 23 matrix rows used by the readable bone-pose routine. The
optional binary output is the exact little-endian matrix span; it is not a
native runtime asset or a POL-slot mapping.

Examples:
  python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_26.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --json
  python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_26.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c \
      --matrix-bin extract/analysis/vf3_26_jacky_matrices.bin
  python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_28.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 \
      --joint-bin extract/analysis/vf3_28_akira_joint_rows.bin
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import struct
import sys

from aica_state import load_state
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram

MATRIX_OFFSET = 0x7C0
MATRIX_COUNT = 23
MATRIX_ROW_BYTES = 16 * 4
JOINT_TABLE_ADDRESS = 0x0C119670
JOINT_BASE = 0x180


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def u16(ram: bytes, address: int, label: str) -> int:
    return struct.unpack("<H", read_ram(ram, address, 2))[0]


def json_float(value: float, bits: int) -> float | dict[str, str]:
    if math.isfinite(value):
        return value
    category = "nan" if math.isnan(value) else ("+inf" if value > 0 else "-inf")
    return {"non_finite": category, "bits": f"0x{bits:08x}"}


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact game image loaded at --image-address")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help="image's SH-4 address (default: 0x0c010000)")
    parser.add_argument("--actor", type=number, required=True,
                        help="actor record address from offline evidence")
    parser.add_argument("--matrix-bin", type=Path,
                        help="write the selected little-endian float32 matrix span")
    parser.add_argument("--matrix-offset", type=number, default=MATRIX_OFFSET,
                        help="matrix-table offset from actor (default: 0x7c0)")
    parser.add_argument("--matrix-count", type=int, default=MATRIX_COUNT,
                        help="number of 64-byte matrices (default: 23)")
    parser.add_argument("--joint-bin", type=Path,
                        help="write 64-byte joint-record prefixes in variable-stride order")
    parser.add_argument("--joint-table-address", type=number,
                        default=JOINT_TABLE_ADDRESS,
                        help="image address of joint-advance bytes (default: 0x0c119670)")
    parser.add_argument("--joint-base", type=number, default=JOINT_BASE,
                        help="joint-record base offset from actor (default: 0x180)")
    parser.add_argument("--joint-count", type=int, default=MATRIX_COUNT,
                        help="number of joint records to export (default: 23)")
    parser.add_argument("--json", action="store_true",
                        help="include every matrix word in JSON")
    args = parser.parse_args(argv)
    if not 1 <= args.matrix_count <= 64:
        parser.error("--matrix-count must be between 1 and 64")
    if args.matrix_bin and args.matrix_bin.exists():
        parser.error(f"refusing to replace existing matrix dump: {args.matrix_bin}")
    if not 1 <= args.joint_count <= 64:
        parser.error("--joint-count must be between 1 and 64")
    if args.joint_bin and args.joint_bin.exists():
        parser.error(f"refusing to replace existing joint dump: {args.joint_bin}")

    try:
        image = args.image.read_bytes()
        table_offset = args.joint_table_address - args.image_address
        if (table_offset < 0 or table_offset > len(image) or
                args.joint_count > len(image) - table_offset):
            raise ValueError("joint-advance table lies outside the loaded image")
        joint_advances = image[table_offset:table_offset + args.joint_count]
        blob = load_state(str(args.state))
        ram_offset, ram, anchor = locate_ram(
            blob, image, args.image_address, None)
        actor = args.actor
        kind60 = read_ram(ram, actor + 0x60, 1)[0]
        kind61 = read_ram(ram, actor + 0x61, 1)[0]
        motion_id = u16(ram, actor + 0x3C, "motion ID")
        cycle = u16(ram, actor + 0x1A00, "motion cycle")
        matrix_bytes = read_ram(ram, actor + args.matrix_offset,
                                args.matrix_count * MATRIX_ROW_BYTES)
        value_count = args.matrix_count * 16
        words = struct.unpack(f"<{value_count}I", matrix_bytes)
        values = struct.unpack(f"<{value_count}f", matrix_bytes)
        nonzero_words = sum(word != 0 for word in words)
        rows = []
        for row_index in range(args.matrix_count):
            start = row_index * 16
            row = {
                "row_index": row_index,
                "translation": [
                    json_float(values[start + i], words[start + i])
                    for i in (12, 13, 14)
                ],
            }
            if args.json:
                row["matrix"] = [
                    json_float(values[start + i], words[start + i])
                    for i in range(16)
                ]
            rows.append(row)
        if args.matrix_bin:
            args.matrix_bin.parent.mkdir(parents=True, exist_ok=True)
            with args.matrix_bin.open("xb") as output:
                output.write(matrix_bytes)

        joint_bytes = b""
        if args.joint_bin:
            joint_rows = []
            cursor = 0
            for advance in joint_advances:
                joint_rows.append(read_ram(ram, actor + args.joint_base + cursor,
                                           MATRIX_ROW_BYTES))
                cursor += advance
            joint_bytes = b"".join(joint_rows)
            args.joint_bin.parent.mkdir(parents=True, exist_ok=True)
            with args.joint_bin.open("xb") as output:
                output.write(joint_bytes)

        report = {
            "diagnostic_only": True,
            "state": str(args.state),
            "ram_offset": f"0x{ram_offset:x}",
            "ram_anchor": anchor,
            "actor": f"0x{actor:08x}",
            "actor_byte_0x60": kind60,
            "actor_byte_0x61": kind61,
            "motion_id": f"0x{motion_id:x}",
            "cycle": cycle,
            "matrix_address": f"0x{actor + args.matrix_offset:08x}",
            "matrix_offset": f"0x{args.matrix_offset:x}",
            "matrix_count": args.matrix_count,
            "matrix_bytes": len(matrix_bytes),
            "matrix_nonzero_words": nonzero_words,
            "matrix_state": "zero" if nonzero_words == 0 else "nonzero",
            "matrices": rows,
            "matrix_bin": str(args.matrix_bin) if args.matrix_bin else None,
            "joint_table_address": f"0x{args.joint_table_address:08x}",
            "joint_base_offset": f"0x{args.joint_base:x}",
            "joint_count": args.joint_count,
            "joint_bin": str(args.joint_bin) if args.joint_bin else None,
            "notes": [
            "Rows retain their source table order; 0x8c091438 uses 23 rows at actor+0x7c0.",
                "A zero matrix span is not a usable pose; the state may predate matrix construction.",
                "The report does not map bone rows to POL slots or MT channels.",
                "The matrix binary is offline comparison data, not runtime input.",
            ],
        }
        if args.json:
            print(json.dumps(report, indent=2) + "\n", end="")
        else:
            print(f"{args.state}: RAM at decompressed offset {report['ram_offset']}; {anchor}")
            print(f"actor={report['actor']} byte60={kind60} byte61={kind61} "
                  f"motion=0x{motion_id:x} cycle={cycle} matrices={args.matrix_count} "
                  f"nonzero_words={nonzero_words}")
            for row in rows:
                tx, ty, tz = row["translation"]
                print(f"  row {row['row_index']:2d}: translation=({tx}, {ty}, {tz})")
            if args.matrix_bin:
                print(f"wrote {args.matrix_bin} ({len(matrix_bytes)} bytes)")
            if args.joint_bin:
                print(f"wrote {args.joint_bin} ({len(joint_bytes)} bytes; "
                      f"{args.joint_count} variable-stride rows)")
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"flycast_pose_export: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
