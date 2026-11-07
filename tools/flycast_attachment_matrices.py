#!/usr/bin/env python3
"""Export an actor's attachment-matrix rows from a Flycast savestate.

The output is an offline evidence file for the native POL preview. It preserves
the guest's little-endian, column-major float32 rows and reports each row's
selector, translation, and basis lengths. It does not convert captures into
runtime pose data.

Example:
  python tools/flycast_attachment_matrices.py \
      extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c \
      --matrix-bin extract/analysis/jacky_s47_attachments.bin \
      --scene-matrix-bin extract/analysis/jacky_s47_scene_matrix.bin
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


SELECTOR_OFFSET = 0x6C
MATRIX_OFFSET = 0x180
MATRIX_STRIDE = 0x40
MATRIX_FLOATS = 16
DEFAULT_COUNT = 18
SCENE_MATRIX_ADDRESS = 0x0C2A5F60


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def basis_lengths(matrix: tuple[float, ...]) -> list[float]:
    return [math.sqrt(sum(matrix[column * 4 + row] ** 2 for row in range(3)))
            for column in range(3)]


def export(state: Path, image_path: Path, image_address: int, actor: int,
           selector_offset: int, matrix_offset: int, count: int,
           matrix_path: Path, scene_matrix_address: int,
           scene_matrix_path: Path | None) -> dict[str, object]:
    image = image_path.read_bytes()
    state_blob = load_state(str(state))
    ram_offset, ram, anchor = locate_ram(state_blob, image, image_address, None)
    selector_bytes = read_ram(ram, actor + selector_offset, count * 4)
    matrix_bytes = read_ram(ram, actor + matrix_offset, count * MATRIX_STRIDE)
    selectors = list(struct.unpack(f"<{count}I", selector_bytes))
    matrices = [struct.unpack_from("<16f", matrix_bytes, row * MATRIX_STRIDE)
                for row in range(count)]
    if any(not math.isfinite(value) for matrix in matrices for value in matrix):
        raise ValueError("attachment matrix table contains a non-finite float")

    scene_matrix_bytes = None
    if scene_matrix_path is not None:
        if scene_matrix_path.resolve() == matrix_path.resolve():
            raise ValueError("attachment and scene matrix outputs must be different files")
        if scene_matrix_path.exists():
            raise ValueError(f"refusing to replace existing scene matrix file: {scene_matrix_path}")
        scene_matrix_bytes = read_ram(ram, scene_matrix_address, MATRIX_STRIDE)
        scene_values = struct.unpack("<16f", scene_matrix_bytes)
        if not all(math.isfinite(value) for value in scene_values):
            raise ValueError("scene matrix contains a non-finite float")

    if matrix_path.exists():
        raise ValueError(f"refusing to replace existing matrix file: {matrix_path}")
    matrix_path.parent.mkdir(parents=True, exist_ok=True)
    matrix_path.write_bytes(matrix_bytes)
    if scene_matrix_path is not None and scene_matrix_bytes is not None:
        scene_matrix_path.parent.mkdir(parents=True, exist_ok=True)
        scene_matrix_path.write_bytes(scene_matrix_bytes)

    root_translation = list(matrices[0][12:15]) if matrices else [0.0, 0.0, 0.0]
    rows = []
    for index, matrix in enumerate(matrices):
        translation = list(matrix[12:15])
        rows.append({
            "entry": index,
            "selector": f"0x{selectors[index]:08x}",
            "translation": translation,
            "relative_translation": [translation[axis] - root_translation[axis]
                                     for axis in range(3)],
            "basis_lengths": basis_lengths(matrix),
            "matrix": list(matrix),
        })
    return {
        "diagnostic_only": True,
        "state": str(state),
        "image": str(image_path),
        "actor": f"0x{actor:08x}",
        "ram_offset": f"0x{ram_offset:x}",
        "ram_anchor": anchor,
        "selector_offset": f"0x{selector_offset:x}",
        "matrix_offset": f"0x{matrix_offset:x}",
        "matrix_stride": MATRIX_STRIDE,
        "matrix_count": count,
        "matrix_bin": str(matrix_path),
        "scene_matrix_address": f"0x{scene_matrix_address:08x}",
        "scene_matrix_bin": str(scene_matrix_path) if scene_matrix_path else None,
        "rows": rows,
        "limitations": [
            "Rows are captured guest state for offline preview only.",
            "The scene matrix composes the captured draw transform; it is not runtime data.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact game image loaded at --image-address")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help=f"game image address (default {DEFAULT_IMAGE_ADDRESS:#x})")
    parser.add_argument("--actor", type=number, required=True,
                        help="actor record address")
    parser.add_argument("--selector-offset", type=number, default=SELECTOR_OFFSET,
                        help=f"selector table offset (default {SELECTOR_OFFSET:#x})")
    parser.add_argument("--matrix-offset", type=number, default=MATRIX_OFFSET,
                        help=f"matrix table offset (default {MATRIX_OFFSET:#x})")
    parser.add_argument("--count", type=int, default=DEFAULT_COUNT,
                        help=f"matrix rows to export (default {DEFAULT_COUNT})")
    parser.add_argument("--matrix-bin", type=Path, required=True,
                        help="new output file for contiguous float32 matrix rows")
    parser.add_argument("--scene-matrix-address", type=number,
                        default=SCENE_MATRIX_ADDRESS,
                        help=f"scene transform address (default {SCENE_MATRIX_ADDRESS:#x})")
    parser.add_argument("--scene-matrix-bin", type=Path,
                        help="optional new output file for the 64-byte draw scene matrix")
    parser.add_argument("--json", action="store_true",
                        help="emit the complete matrix report as JSON")
    args = parser.parse_args(argv)
    if not 1 <= args.count <= 64:
        parser.error("--count must be between 1 and 64")

    try:
        state = args.state.resolve()
        image = args.image.resolve()
        output = args.matrix_bin.resolve()
        scene_output = args.scene_matrix_bin.resolve() if args.scene_matrix_bin else None
        if not state.is_file():
            raise ValueError(f"savestate does not exist: {state}")
        if not image.is_file():
            raise ValueError(f"game image does not exist: {image}")
        report = export(state, image, args.image_address, args.actor,
                        args.selector_offset, args.matrix_offset, args.count,
                        output, args.scene_matrix_address, scene_output)
    except (OSError, ValueError, struct.error) as exc:
        print(f"flycast_attachment_matrices: {exc}", file=sys.stderr)
        return 1

    if args.json:
        print(json.dumps(report, indent=2, allow_nan=False))
        return 0
    print(f"{report['state']}: actor {report['actor']}, "
          f"{report['matrix_count']} rows, {report['matrix_bin']}")
    if report["scene_matrix_bin"]:
        print(f"scene matrix {report['scene_matrix_address']}: "
              f"{report['scene_matrix_bin']}")
    print("row selector    relative translation (x,y,z)       basis lengths")
    for row in report["rows"]:
        x, y, z = row["relative_translation"]
        sx, sy, sz = row["basis_lengths"]
        print(f"{row['entry']:>3} {row['selector']}  "
              f"({x:>9.4f},{y:>9.4f},{z:>9.4f})  "
              f"({sx:.4f},{sy:.4f},{sz:.4f})")
    print("Captured matrices are diagnostic data; do not use them as native runtime poses.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
