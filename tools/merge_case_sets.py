#!/usr/bin/env python3
"""Merge oracle .cases files and copy their referenced RAM snapshots.

The v2 case format stores the entry RAM filename at field 74, followed by a
window count and window descriptors, then the exit RAM filename and its
descriptors. This utility preserves row order and gives copied snapshots
unique names based on their source set and row number.
"""
from __future__ import annotations

import argparse
import shutil
from pathlib import Path


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", required=True, type=Path,
                    help="output .cases file")
    ap.add_argument("inputs", nargs="+", type=Path,
                    help="input .cases files, in desired output order")
    args = ap.parse_args()
    out_cases = args.out
    out_dir = out_cases.parent
    out_dir.mkdir(parents=True, exist_ok=True)
    merged: list[str] = []

    for source in args.inputs:
        prefix = source.stem
        for ordinal, line in enumerate(source.read_text().splitlines()):
            if not line.strip():
                continue
            fields = line.split()
            if len(fields) < 77:
                raise SystemExit(f"{source}:{ordinal + 1}: truncated case row")

            def copy_snapshot(index: int, tag: str) -> None:
                old_name = fields[index]
                old_path = source.parent / old_name
                if not old_path.is_file():
                    raise SystemExit(f"missing RAM snapshot: {old_path}")
                new_name = f"{prefix}_{ordinal:04d}_{tag}.bin"
                shutil.copyfile(old_path, out_dir / new_name)
                fields[index] = new_name

            copy_snapshot(74, "in")
            try:
                exit_name_index = 76 + 2 * int(fields[75], 0)
                if exit_name_index >= len(fields):
                    raise ValueError("exit RAM filename is outside row")
                copy_snapshot(exit_name_index, "out")
            except ValueError as exc:
                raise SystemExit(f"{source}:{ordinal + 1}: invalid case row: {exc}")
            merged.append(" ".join(fields))

    out_cases.write_text("\n".join(merged) + "\n", encoding="utf-8")
    print(f"{out_cases}: {len(merged)} cases")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
