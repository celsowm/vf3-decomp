#!/usr/bin/env python3
"""Inventory fighter pose tables across retained Flycast savestates.

This wraps flycast_pose_export.py for each state/actor pair, reports actor
kind, motion, matrix population and basis-vector quality, and can retain the
matrix and variable-stride joint binaries for comparison. It does not infer
fighter identity, POL-slot assignments or native runtime behavior.

Examples:
  python tools/pose_state_inventory.py --image extract/exe/1ST_READ.unsc.bin \
      --state-dir tools/emu/flycast-build/data --actor 0x0c1fefe4 \
      --actor 0x0c20138c
  python tools/pose_state_inventory.py --image extract/exe/1ST_READ.unsc.bin \
      --state-dir tools/emu/flycast-build/data --actor 0x0c20138c \
      --matrix-dir extract/analysis/pose_state_matrices \
      --joint-dir extract/analysis/pose_state_joints --json
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
EXPORTER = ROOT / "tools" / "flycast_pose_export.py"
DEFAULT_IMAGE_ADDRESS = 0x0C010000


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def basis_lengths(matrix: list[object]) -> list[float] | None:
    if len(matrix) != 16 or any(not isinstance(value, (int, float)) for value in matrix):
        return None
    values = [float(value) for value in matrix]
    if not all(math.isfinite(value) for value in values):
        return None
    return [math.sqrt(sum(values[column * 4 + row] ** 2 for row in range(3)))
            for column in range(3)]


def inspect_one(state: Path, image: Path, image_address: int, actor: int,
                matrix_path: Path | None, joint_path: Path | None,
                epsilon: float) -> dict[str, object]:
    command = [
        sys.executable, str(EXPORTER), str(state), "--image", str(image),
        "--image-address", hex(image_address), "--actor", hex(actor), "--json",
    ]
    if matrix_path is not None:
        command.extend(("--matrix-bin", str(matrix_path)))
    if joint_path is not None:
        command.extend(("--joint-bin", str(joint_path)))
    result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True,
                            check=False)
    if result.returncode != 0:
        return {
            "state": str(state), "actor": f"0x{actor:08x}",
            "error": result.stderr.strip() or result.stdout.strip() or
                     f"exporter exited {result.returncode}",
        }
    exported = json.loads(result.stdout)
    rows = exported["matrices"]
    lengths = [basis_lengths(row.get("matrix", [])) for row in rows]
    usable = [row is not None and all(length > epsilon for length in row)
              for row in lengths]
    return {
        "state": str(state),
        "actor": exported["actor"],
        "actor_byte_0x60": exported["actor_byte_0x60"],
        "actor_byte_0x61": exported["actor_byte_0x61"],
        "motion_id": exported["motion_id"],
        "cycle": exported["cycle"],
        "matrix_nonzero_words": exported["matrix_nonzero_words"],
        "matrix_count": exported["matrix_count"],
        "basis_usable_rows": sum(usable),
        "basis_degenerate_rows": [index for index, valid in enumerate(usable)
                                   if not valid],
        "matrix_bin": str(matrix_path) if matrix_path is not None else None,
        "joint_bin": str(joint_path) if joint_path is not None else None,
        "diagnostic_only": True,
        "limitations": [
            "Actor bytes are reported without assigning game character names.",
            "Nonzero basis vectors do not prove the POL-slot mapping.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("states", nargs="*", type=Path,
                        help="savestates to inspect")
    parser.add_argument("--state-dir", type=Path,
                        help="also scan this directory for --pattern matches")
    parser.add_argument("--pattern", default="vf3_*.state",
                        help="state filename glob for --state-dir")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact 1ST_READ image loaded at --image-address")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help=f"image address (default {DEFAULT_IMAGE_ADDRESS:#x})")
    parser.add_argument("--actor", type=number, action="append", required=True,
                        help="actor address; repeat to inspect a pair")
    parser.add_argument("--matrix-dir", type=Path,
                        help="export one matrix binary per state/actor pair")
    parser.add_argument("--joint-dir", type=Path,
                        help="export variable-stride joint rows per state/actor pair")
    parser.add_argument("--basis-epsilon", type=float, default=1e-6,
                        help="minimum usable basis length (default 1e-6)")
    parser.add_argument("--json", action="store_true",
                        help="emit the inventory as JSON")
    args = parser.parse_args(argv)
    if not args.states and not args.state_dir:
        parser.error("provide savestate paths or --state-dir")
    if len(set(args.actor)) != len(args.actor):
        parser.error("--actor values must be unique")
    if not math.isfinite(args.basis_epsilon) or args.basis_epsilon < 0:
        parser.error("--basis-epsilon must be finite and nonnegative")

    states = [path.resolve() for path in args.states]
    if args.state_dir:
        state_dir = args.state_dir.resolve()
        if not state_dir.is_dir():
            parser.error(f"state directory does not exist: {state_dir}")
        states.extend(path.resolve() for path in state_dir.glob(args.pattern)
                      if path.is_file())
    states = sorted(set(states), key=lambda path: str(path).casefold())
    if not states:
        parser.error("no savestates matched the requested inputs")
    if any(not state.is_file() for state in states):
        parser.error("one or more savestate paths do not exist")

    image = args.image.resolve()
    if not image.is_file():
        parser.error(f"game image does not exist: {image}")
    matrix_dir = args.matrix_dir.resolve() if args.matrix_dir else None
    joint_dir = args.joint_dir.resolve() if args.joint_dir else None
    if matrix_dir is not None:
        matrix_dir.mkdir(parents=True, exist_ok=True)
    if joint_dir is not None:
        joint_dir.mkdir(parents=True, exist_ok=True)

    report = []
    failures = 0
    for state in states:
        for actor in args.actor:
            matrix_path = None
            joint_path = None
            if matrix_dir is not None:
                matrix_path = matrix_dir / f"{state.stem}_actor_{actor:08x}.bin"
                if matrix_path.exists():
                    print(f"pose_state_inventory: refusing to overwrite {matrix_path}",
                          file=sys.stderr)
                    return 1
            if joint_dir is not None:
                joint_path = joint_dir / f"{state.stem}_actor_{actor:08x}.bin"
                if joint_path.exists():
                    print(f"pose_state_inventory: refusing to overwrite {joint_path}",
                          file=sys.stderr)
                    return 1
            row = inspect_one(state, image, args.image_address, actor,
                              matrix_path, joint_path, args.basis_epsilon)
            failures += "error" in row
            report.append(row)

    if args.json:
        print(json.dumps({"diagnostic_only": True, "records": report}, indent=2))
    else:
        print("state actor      kind60 kind61 motion cycle nonzero_words usable/total")
        for row in report:
            if "error" in row:
                print(f"{Path(row['state']).name} {row['actor']} ERROR: {row['error']}")
                continue
            print(f"{Path(row['state']).name:18} {row['actor']} "
                  f"{row['actor_byte_0x60']:>6} {row['actor_byte_0x61']:>6} "
                  f"{row['motion_id']:>6} {row['cycle']:>5} "
                  f"{row['matrix_nonzero_words']:>13} "
                  f"{row['basis_usable_rows']:>2}/{row['matrix_count']}")
            if row["matrix_bin"]:
                print(f"  matrix dump: {row['matrix_bin']}")
            if row["joint_bin"]:
                print(f"  joint dump: {row['joint_bin']}")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
