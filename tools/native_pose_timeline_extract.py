#!/usr/bin/env python3
"""Extract joint and pose matrices from checkpoint states made by the timeline probe.

This complements ``native_motion_timeline_probe.py --include-pose`` for an
existing capture whose first pass retained motion fields or joint records but
not matrices. It reads the capture's ``motion_timeline.csv`` and checkpoint
states; it does not launch Flycast or alter the capture. Joint rows retain
their raw 64-byte prefixes in the variable-stride order used by the bone-pose
builder.
"""

from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path
import sys

from aica_state import load_state
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram
from native_motion_timeline_probe import (
    JOINT_ADVANCE_ADDRESS,
    joint_records,
    matrix_rows,
    read_floats,
    read_u16s,
)


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"


def repo_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def address_value(value: str) -> int:
    try:
        result = int(value, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {value}") from exc
    if not 0 <= result <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return result


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--timeline", required=True, type=Path,
                        help="motion_timeline.csv from native_motion_timeline_probe.py")
    parser.add_argument("--image", required=True, type=Path,
                        help="exact game image loaded into main RAM")
    parser.add_argument("--image-address", type=address_value,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help=f"image load address (default {DEFAULT_IMAGE_ADDRESS:#x})")
    parser.add_argument("--actor", type=address_value, action="append",
                        help="include this actor address; repeat to select more")
    parser.add_argument("--out", required=True, type=Path,
                        help="new JSONL file inside extract/analysis")
    args = parser.parse_args(argv)

    timeline = repo_path(args.timeline)
    image_path = repo_path(args.image)
    out_path = repo_path(args.out)
    try:
        out_path.relative_to(ANALYSIS.resolve())
    except ValueError:
        parser.error("--out must be inside extract/analysis")
    if not timeline.is_file():
        parser.error(f"timeline does not exist: {timeline}")
    if not image_path.is_file():
        parser.error(f"image does not exist: {image_path}")
    if args.actor and len(set(args.actor)) != len(args.actor):
        parser.error("--actor values must be unique")

    image = image_path.read_bytes()
    rows_written = 0
    previous_state_path: Path | None = None
    ram: bytes | None = None
    anchor: str | None = None
    try:
        with timeline.open("r", newline="", encoding="utf-8") as source:
            reader = csv.DictReader(source)
            required = {"frame", "input_mask", "slot", "state", "actor",
                        "byte_0x60", "byte_0x61", "motion_id", "phase_raw",
                        "phase_q8", "phase_frame", "cycle", "descriptor_pointer",
                        "record_pointer", "ram_anchor"}
            if not reader.fieldnames or not required.issubset(reader.fieldnames):
                raise ValueError("motion timeline is missing required columns")
            selected_rows = []
            for line_number, row in enumerate(reader, 2):
                try:
                    actor = int(row["actor"], 0)
                except (KeyError, TypeError, ValueError) as exc:
                    raise ValueError(f"{timeline}:{line_number}: invalid actor: {exc}") from exc
                if not args.actor or actor in args.actor:
                    selected_rows.append((line_number, row, actor))
            if not selected_rows:
                raise ValueError("no matching timeline rows")
            out_path.parent.mkdir(parents=True, exist_ok=True)
            with out_path.open("x", encoding="utf-8") as output:
                for line_number, row, actor in selected_rows:
                    try:
                        state_path = repo_path(Path(row["state"]))
                        if state_path != previous_state_path:
                            if not state_path.is_file():
                                raise ValueError(f"checkpoint state does not exist: {state_path}")
                            blob = load_state(str(state_path))
                            _ram_offset, ram, anchor = locate_ram(
                                blob, image, args.image_address, None)
                            previous_state_path = state_path
                        assert ram is not None and anchor is not None
                        frame_row = {
                            "frame": int(row["frame"]),
                            "input_mask": row["input_mask"],
                            "slot": int(row["slot"]),
                            "state": Path(row["state"]).as_posix(),
                            "actor": f"0x{actor:08x}",
                            "byte_0x60": int(row["byte_0x60"]),
                            "byte_0x61": int(row["byte_0x61"]),
                            "motion_id": row["motion_id"],
                            "phase_raw": row["phase_raw"],
                            "phase_q8": int(row["phase_q8"]),
                            "phase_frame": float(row["phase_frame"]),
                            "cycle": int(row["cycle"]),
                            "descriptor_pointer": row["descriptor_pointer"],
                            "record_pointer": row["record_pointer"],
                            "ram_anchor": anchor,
                        }
                        pose_row = {
                            **frame_row,
                            "channels_at_0x1d04": read_floats(ram, actor + 0x1D04, 63),
                            "packed_pose_fields_at_0x1f50": read_u16s(
                                ram, actor + 0x1F50, 42),
                            "joint_records_at_0x180": joint_records(
                                ram, actor,
                                read_ram(ram, JOINT_ADVANCE_ADDRESS, 23)),
                            "attachment_rows_at_0x180": matrix_rows(
                                ram, actor + 0x180, 18),
                            "bone_rows_at_0x7c0": matrix_rows(
                                ram, actor + 0x7C0, 23),
                        }
                        output.write(json.dumps(
                            pose_row, allow_nan=False, separators=(",", ":")) + "\n")
                        rows_written += 1
                    except (KeyError, TypeError, ValueError) as exc:
                        raise ValueError(f"{timeline}:{line_number}: {exc}") from exc
    except (OSError, ValueError) as exc:
        print(f"native_pose_timeline_extract: {exc}", file=sys.stderr)
        return 1
    print(f"pose rows={rows_written}; JSONL: {out_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
