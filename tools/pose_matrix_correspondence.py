#!/usr/bin/env python3
"""Rank direct row correspondences between two captured matrix tables.

The tool compares the directions of the three basis columns after removing
per-column scale, then compares each row's translation relative to a selected
root row. It is an offline diagnostic: a low score can suggest a relationship,
but does not prove how the game constructs or uses either table.

Examples:
  python tools/pose_matrix_correspondence.py attachments.bin bones.bin
  python tools/pose_matrix_correspondence.py attachments.bin bones.bin \
      --left-root 0 --right-root 0 --top 12 --json
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import struct
import sys


MATRIX_BYTES = 64
MATRIX_FLOATS = 16


def read_matrices(path: Path) -> list[tuple[float, ...]]:
    data = path.read_bytes()
    if not data or len(data) % MATRIX_BYTES:
        raise ValueError(f"{path}: size must be a nonzero multiple of 64 bytes")
    count = len(data) // MATRIX_BYTES
    if count > 64:
        raise ValueError(f"{path}: {count} rows exceeds the 64-row limit")
    values = struct.unpack(f"<{count * MATRIX_FLOATS}f", data)
    if not all(math.isfinite(value) for value in values):
        raise ValueError(f"{path}: matrix table contains a non-finite value")
    return [values[i * MATRIX_FLOATS:(i + 1) * MATRIX_FLOATS]
            for i in range(count)]


def basis_directions(matrix: tuple[float, ...], epsilon: float) -> list[tuple[float, float, float]] | None:
    directions = []
    for column in range(3):
        vector = tuple(matrix[column * 4 + axis] for axis in range(3))
        length = math.sqrt(sum(component * component for component in vector))
        if length <= epsilon:
            return None
        directions.append(tuple(component / length for component in vector))
    return directions


def relative_translation(matrix: tuple[float, ...], root: tuple[float, ...]) -> tuple[float, float, float]:
    return tuple(matrix[12 + axis] - root[12 + axis] for axis in range(3))


def compare(left: list[tuple[float, ...]], right: list[tuple[float, ...]],
            left_root: int, right_root: int, epsilon: float) -> dict[str, object]:
    if not 0 <= left_root < len(left) or not 0 <= right_root < len(right):
        raise ValueError("root row is outside its matrix table")
    left_root_matrix = left[left_root]
    right_root_matrix = right[right_root]
    candidates = []
    rejected_degenerate = 0
    for left_index, left_matrix in enumerate(left):
        left_basis = basis_directions(left_matrix, epsilon)
        if left_basis is None:
            rejected_degenerate += len(right)
            continue
        left_position = relative_translation(left_matrix, left_root_matrix)
        for right_index, right_matrix in enumerate(right):
            right_basis = basis_directions(right_matrix, epsilon)
            if right_basis is None:
                rejected_degenerate += 1
                continue
            angles = []
            for left_axis, right_axis in zip(left_basis, right_basis):
                dot = sum(a * b for a, b in zip(left_axis, right_axis))
                angles.append(math.degrees(math.acos(max(-1.0, min(1.0, dot)))))
            right_position = relative_translation(right_matrix, right_root_matrix)
            translation_delta = math.sqrt(sum(
                (left_position[axis] - right_position[axis]) ** 2
                for axis in range(3)))
            candidates.append({
                "left_row": left_index,
                "right_row": right_index,
                "axis_degrees": angles,
                "mean_axis_degrees": sum(angles) / 3.0,
                "max_axis_degrees": max(angles),
                "left_relative_translation": left_position,
                "right_relative_translation": right_position,
                "translation_delta": translation_delta,
            })
    candidates.sort(key=lambda row: (
        row["max_axis_degrees"], row["translation_delta"],
        row["left_row"], row["right_row"]))
    return {
        "diagnostic_only": True,
        "left_rows": len(left),
        "right_rows": len(right),
        "left_root": left_root,
        "right_root": right_root,
        "basis_epsilon": epsilon,
        "rejected_degenerate_pairs": rejected_degenerate,
        "candidates": candidates,
        "notes": [
            "Basis-column scale is removed before comparing axis directions.",
            "Translations are compared relative to each table's selected root row.",
            "A close row pair suggests a direct-table relationship but does not prove it.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("left", type=Path, help="first little-endian matrix table")
    parser.add_argument("right", type=Path, help="second little-endian matrix table")
    parser.add_argument("--left-root", type=int, default=0,
                        help="root row in the first table (default 0)")
    parser.add_argument("--right-root", type=int, default=0,
                        help="root row in the second table (default 0)")
    parser.add_argument("--top", type=int, default=20,
                        help="number of candidate pairs to print (default 20)")
    parser.add_argument("--basis-epsilon", type=float, default=1e-6,
                        help="minimum usable basis-column length (default 1e-6)")
    parser.add_argument("--json", action="store_true",
                        help="emit the full candidate report as JSON")
    args = parser.parse_args(argv)
    if args.left_root < 0 or args.right_root < 0:
        parser.error("root row indices must be nonnegative")
    if args.top < 0:
        parser.error("--top must be nonnegative")
    if not math.isfinite(args.basis_epsilon) or args.basis_epsilon < 0:
        parser.error("--basis-epsilon must be finite and nonnegative")
    try:
        report = compare(read_matrices(args.left), read_matrices(args.right),
                         args.left_root, args.right_root, args.basis_epsilon)
    except (OSError, ValueError, struct.error) as exc:
        print(f"pose_matrix_correspondence: {exc}", file=sys.stderr)
        return 1
    report["left"] = str(args.left)
    report["right"] = str(args.right)
    if args.json:
        print(json.dumps(report, indent=2) + "\n", end="")
        return 0
    print(f"{args.left}: {report['left_rows']} rows (root {args.left_root}); "
          f"{args.right}: {report['right_rows']} rows (root {args.right_root})")
    print("best direct row pairs (basis directions normalized; translations root-relative)")
    print(" left right  mean-axis  max-axis  translation-delta")
    for row in report["candidates"][:args.top]:
        print(f" {row['left_row']:>4} {row['right_row']:>5}  "
              f"{row['mean_axis_degrees']:>9.3f}  "
              f"{row['max_axis_degrees']:>8.3f}  "
              f"{row['translation_delta']:>17.5f}")
    if report["rejected_degenerate_pairs"]:
        print(f"skipped {report['rejected_degenerate_pairs']} pairs with a degenerate basis")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
