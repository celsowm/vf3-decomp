#!/usr/bin/env python3
"""Find one-based runtime motion IDs in extracted MT*.BIN pairing packs.

Each runtime motion ID selects three consecutive slots from the 8,880-entry
table. This scanner reports the three source offsets together so incomplete
rows are visible. It identifies where a row exists, not what the row means.

Example:
  python tools/mt_motion_find.py 0x69f 0x41a --assets extract/gamedata
"""

from __future__ import annotations

import argparse
from pathlib import Path
import sys

from mtmap import parse as parse_slots

MAX_MOTION_ID = 8880 // 3


def integer(text: str) -> int:
    try:
        return int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc


def asset_files(root: Path) -> list[Path]:
    if root.is_file():
        return [root]
    if root.is_dir():
        return sorted(root.glob("MT*.BIN"))
    raise FileNotFoundError(f"asset path does not exist: {root}")


def find_motion_rows(paths: list[Path], motion_ids: list[int]) -> tuple[list[str], list[str]]:
    output: list[str] = []
    errors: list[str] = []
    found: set[int] = set()
    for path in paths:
        try:
            offsets = {slot: offset for slot, offset, _size in parse_slots(path)}
        except (OSError, ValueError) as exc:
            errors.append(f"{path}: {exc}")
            continue
        for motion_id in motion_ids:
            first_slot = (motion_id - 1) * 3
            row = [offsets.get(first_slot + part) for part in range(3)]
            if not any(value is not None for value in row):
                continue
            found.add(motion_id)
            state = "complete" if all(value is not None for value in row) else "partial"
            rendered = ",".join("-" if value is None else f"0x{value:06x}" for value in row)
            output.append(
                f"motion=0x{motion_id:x} asset={path.name} state={state} offsets={rendered}"
            )
    for motion_id in motion_ids:
        if motion_id not in found:
            output.append(f"motion=0x{motion_id:x} state=absent packs={len(paths)}")
    return output, errors


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("motion_ids", nargs="+", type=integer,
                        help=f"one-based runtime motion IDs (1..{MAX_MOTION_ID})")
    parser.add_argument("--assets", type=Path, default=Path("extract/gamedata"),
                        help="an extracted asset directory or one MT file")
    args = parser.parse_args(argv)
    invalid = [value for value in args.motion_ids if not 1 <= value <= MAX_MOTION_ID]
    if invalid:
        parser.error(f"motion IDs must be in 1..{MAX_MOTION_ID}: " +
                     ", ".join(hex(value) for value in invalid))
    try:
        paths = asset_files(args.assets)
    except OSError as exc:
        print(f"mt_motion_find: {exc}", file=sys.stderr)
        return 1
    if not paths:
        print(f"mt_motion_find: no MT*.BIN files in {args.assets}", file=sys.stderr)
        return 1
    rows, errors = find_motion_rows(paths, list(dict.fromkeys(args.motion_ids)))
    for row in rows:
        print(row)
    for error in errors:
        print(f"mt_motion_find: {error}", file=sys.stderr)
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
