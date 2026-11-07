#!/usr/bin/env python3
"""Export every POL-slot/matrix transform candidate for manual review.

The report applies each captured column-major matrix to the corners of a
tagged POL slot's local bounds, relative to matrix row 0's translation. It
accepts either the 23-row bone table or another 1..64-row matrix table, such as
the 18 attachment transforms used by fighter refresh. It retains slot and row
identities and deliberately does not assign a rig mapping. Bounds are
conservative because they transform local AABB corners, not every source
vertex.

Example:
  python tools/pose_slot_matrix_report.py extract/gamedata/MKAO_JAC.POL \
      extract/analysis/native_pose_inventory_s26_s27_v2/matrices/vf3_27_actor_0c20138c.bin \
      --slot 17 --slot 18 --slot 19 --csv extract/analysis/jacky_slot_bone_candidates.csv
"""

from __future__ import annotations

import argparse
import csv
import json
import math
from pathlib import Path
import struct
import sys

from pol_model_inventory import Model, parse_models

MATRIX_COUNT = 23  # compatibility constant for native_pose_audit's bone table
MATRIX_FLOATS = 16
MATRIX_ROW_BYTES = MATRIX_FLOATS * 4
MAX_MATRIX_COUNT = 64


def bounds(models: list[Model]) -> dict[int, tuple[list[float], list[float], str]]:
    result: dict[int, tuple[list[float], list[float], str]] = {}
    for model in models:
        low = [math.inf, math.inf, math.inf]
        high = [-math.inf, -math.inf, -math.inf]
        for mesh in model.meshes:
            if not mesh.vertices:
                continue
            for axis in range(3):
                low[axis] = min(low[axis], mesh.low[axis])
                high[axis] = max(high[axis], mesh.high[axis])
        if all(math.isfinite(value) for value in low + high):
            result[model.slot] = (low, high, f"0x{model.start:06x}")
    return result


def transformed_bounds(matrix: tuple[float, ...], low: list[float],
                       high: list[float], root: tuple[float, float, float]
                       ) -> tuple[list[float], list[float]]:
    out_low = [math.inf, math.inf, math.inf]
    out_high = [-math.inf, -math.inf, -math.inf]
    for x in (low[0], high[0]):
        for y in (low[1], high[1]):
            for z in (low[2], high[2]):
                point = (
                    matrix[0] * x + matrix[4] * y + matrix[8] * z + matrix[12] - root[0],
                    matrix[1] * x + matrix[5] * y + matrix[9] * z + matrix[13] - root[1],
                    matrix[2] * x + matrix[6] * y + matrix[10] * z + matrix[14] - root[2],
                )
                for axis, value in enumerate(point):
                    out_low[axis] = min(out_low[axis], value)
                    out_high[axis] = max(out_high[axis], value)
    return out_low, out_high


def report(pol_data: bytes, matrix_data: bytes,
           selected_slots: set[int] | None = None) -> dict[str, object]:
    if not matrix_data or len(matrix_data) % MATRIX_ROW_BYTES:
        raise ValueError("matrix dump size must be a nonzero multiple of 64 bytes")
    matrix_count = len(matrix_data) // MATRIX_ROW_BYTES
    if matrix_count > MAX_MATRIX_COUNT:
        raise ValueError(f"matrix dump has {matrix_count} rows; maximum is {MAX_MATRIX_COUNT}")
    values = struct.unpack(f"<{matrix_count * MATRIX_FLOATS}f", matrix_data)
    if not all(math.isfinite(value) for value in values):
        raise ValueError("matrix dump contains a non-finite value")
    matrices = [values[i * MATRIX_FLOATS:(i + 1) * MATRIX_FLOATS]
                for i in range(matrix_count)]
    root = (matrices[0][12], matrices[0][13], matrices[0][14])
    slots = bounds(parse_models(pol_data))
    if selected_slots is not None:
        missing = sorted(selected_slots - slots.keys())
        if missing:
            raise ValueError("requested slots have no tagged geometry: " +
                             ", ".join(str(slot) for slot in missing))
    rows = []
    for slot, (low, high, model_start) in sorted(slots.items()):
        if selected_slots is not None and slot not in selected_slots:
            continue
        for matrix_row, matrix in enumerate(matrices):
            world_low, world_high = transformed_bounds(matrix, low, high, root)
            rows.append({
                "slot": slot,
                "model_start": model_start,
                "matrix_row": matrix_row,
                "bone_row": matrix_row,  # kept for existing 23-row report consumers
                "local_min": low,
                "local_max": high,
                "relative_min": world_low,
                "relative_max": world_high,
                "relative_center": [(world_low[i] + world_high[i]) * 0.5
                                    for i in range(3)],
            })
    return {
        "diagnostic_only": True,
        "matrix_count": matrix_count,
        "matrix_bytes": len(matrix_data),
        "root_translation": list(root),
        "slot_count": len({row["slot"] for row in rows}),
        "candidate_count": len(rows),
        "candidates": rows,
        "limitations": [
            "Each candidate pairs one whole tagged POL slot with one matrix row.",
            "Bounds are transformed AABB corners, not source vertices.",
            "The output does not identify the correct slot-to-matrix assignment.",
            "Matrix 0 translation is only the preview's relative origin.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", type=Path, help="extracted tagged fighter POL file")
    parser.add_argument("matrix_bin", type=Path,
                        help="little-endian 64-byte matrix rows (1..64 rows)")
    parser.add_argument("--slot", type=int, action="append",
                        help="restrict report to this tagged model slot; repeatable")
    parser.add_argument("--csv", type=Path,
                        help="write one row per slot/matrix candidate; refuses overwrite")
    parser.add_argument("--json", action="store_true",
                        help="emit full diagnostic JSON to stdout")
    args = parser.parse_args(argv)
    if args.slot is not None and any(slot < 0 for slot in args.slot):
        parser.error("--slot values must be nonnegative")
    if args.csv and args.json:
        parser.error("choose --csv or --json")
    try:
        if args.csv and args.csv.exists():
            raise FileExistsError(f"refusing to replace {args.csv}")
        result = report(args.pol.read_bytes(), args.matrix_bin.read_bytes(),
                        None if args.slot is None else set(args.slot))
        if args.json:
            print(json.dumps(result, indent=2))
        elif args.csv:
            args.csv.parent.mkdir(parents=True, exist_ok=True)
            with args.csv.open("w", newline="", encoding="utf-8") as handle:
                fields = list(result["candidates"][0]) if result["candidates"] else ["slot"]
                writer = csv.DictWriter(handle, fieldnames=fields)
                writer.writeheader()
                writer.writerows(result["candidates"])
            print(f"wrote {args.csv} ({result['candidate_count']} candidates; diagnostic only)")
        else:
            print(f"{args.pol.name}: {result['slot_count']} tagged slots x "
                  f"{result['matrix_count']} matrices = {result['candidate_count']} candidates")
            print("Pass --csv PATH or --json to inspect transformed bounds.")
    except (OSError, ValueError, struct.error) as exc:
        print(f"pose_slot_matrix_report: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
