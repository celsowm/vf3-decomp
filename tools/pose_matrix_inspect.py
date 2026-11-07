#!/usr/bin/env python3
"""Inspect a retained 23-row VF3 bone-matrix dump.

The input is a little-endian float32 matrix span exported by
``mt_pose_capture_compare.py --matrix-bin`` or
``flycast_pose_export.py --matrix-bin``. Rows are reported in the order used by
their source table; the bone-pose table has 23 rows, while the fighter refresh
table has 18. This is an offline evidence tool; it does not map rows to POL
slots or drive the native runtime.

Examples:
  python tools/pose_matrix_inspect.py extract/analysis/native_pose_bones_s29_v1/case1_matrices.bin
  python tools/pose_matrix_inspect.py build/vf3_28_akira_matrices.bin --json
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import struct
import sys

MATRIX_FLOATS = 16
MATRIX_ROW_BYTES = MATRIX_FLOATS * 4


def inspect(path: Path, basis_epsilon: float = 1e-6) -> dict[str, object]:
    data = path.read_bytes()
    if not data or len(data) % MATRIX_ROW_BYTES:
        raise ValueError("matrix dump size must be a nonzero multiple of 64 bytes")
    matrix_count = len(data) // MATRIX_ROW_BYTES
    if matrix_count > 64:
        raise ValueError(f"matrix dump has {matrix_count} rows; maximum is 64")
    values = struct.unpack(f"<{matrix_count * MATRIX_FLOATS}f", data)
    rows = []
    for index in range(matrix_count):
        start = index * MATRIX_FLOATS
        matrix = values[start:start + MATRIX_FLOATS]
        if not all(math.isfinite(value) for value in matrix):
            raise ValueError(f"bone {index} contains a non-finite matrix value")
        translation = [matrix[12], matrix[13], matrix[14]]
        axes = []
        for column in range(3):
            axes.append(math.sqrt(sum(matrix[column * 4 + row] ** 2
                                      for row in range(3))))
        rows.append({
            "row_index": index,
            "translation": translation,
            "basis_lengths": axes,
            "matrix": list(matrix),
        })

    root = rows[0]["translation"]
    for row in rows:
        row["relative_to_bone_0"] = [
            row["translation"][axis] - root[axis] for axis in range(3)
        ]
    usable_rows = [
        all(length > basis_epsilon for length in row["basis_lengths"])
        for row in rows
    ]
    return {
        "diagnostic_only": True,
        "source": str(path),
        "matrix_count": matrix_count,
        "matrix_bytes": len(data),
        "basis_epsilon": basis_epsilon,
        "basis_usable_rows": sum(usable_rows),
        "basis_degenerate_rows": [index for index, usable in enumerate(usable_rows)
                                   if not usable],
        "matrices": rows,
        "notes": [
            "Rows retain their source table order; the bone-pose table has 23 rows.",
            "Matrix words are interpreted as column-major float32 values.",
            "Relative positions are diagnostic and do not identify POL parts.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("matrix_bin", type=Path,
                        help="exact 1,472-byte matrix dump")
    parser.add_argument("--json", action="store_true",
                        help="emit all matrix words and derived fields as JSON")
    parser.add_argument("--basis-epsilon", type=float, default=1e-6,
                        help="minimum usable basis length (default 1e-6)")
    args = parser.parse_args(argv)
    if not math.isfinite(args.basis_epsilon) or args.basis_epsilon < 0:
        parser.error("--basis-epsilon must be finite and nonnegative")
    try:
        report = inspect(args.matrix_bin, args.basis_epsilon)
    except (OSError, ValueError, struct.error) as exc:
        print(f"pose_matrix_inspect: {exc}", file=sys.stderr)
        return 1
    if args.json:
        print(json.dumps(report, indent=2) + "\n", end="")
        return 0
    count = report["matrix_count"]
    size = report["matrix_bytes"]
    print(f"{args.matrix_bin}: {count} matrices, {size} bytes")
    print(f"usable basis rows: {report['basis_usable_rows']}/{count} "
          f"(epsilon={args.basis_epsilon:g})")
    print("row   translation (x,y,z)                    relative to row 0                  basis lengths")
    for row in report["matrices"]:
        tx, ty, tz = row["translation"]
        rx, ry, rz = row["relative_to_bone_0"]
        sx, sy, sz = row["basis_lengths"]
        print(f"{row['row_index']:>4}  ({tx:>9.4f},{ty:>9.4f},{tz:>9.4f})  "
              f"({rx:>9.4f},{ry:>9.4f},{rz:>9.4f})  "
              f"({sx:.4f},{sy:.4f},{sz:.4f})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
