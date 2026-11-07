#!/usr/bin/env python3
"""Compare retained binary pose dumps in fixed-size rows.

The tool reports exact word differences per row for matrix or variable-stride
joint exports. It is an offline diagnostic; differing fields are not assigned
gameplay meaning.

Examples:
  python tools/pose_dump_diff.py state26_joints.bin state27_joints.bin
  python tools/pose_dump_diff.py pose_a.bin pose_b.bin --row-bytes 64 --json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
import sys


def compare(left: bytes, right: bytes, row_bytes: int) -> dict[str, object]:
    if row_bytes <= 0 or row_bytes % 4:
        raise ValueError("row size must be a positive multiple of four bytes")
    if not left or len(left) != len(right) or len(left) % row_bytes:
        raise ValueError("dumps must have equal, nonzero sizes divisible by row size")
    word_count = len(left) // 4
    left_words = struct.unpack(f"<{word_count}I", left)
    right_words = struct.unpack(f"<{word_count}I", right)
    words_per_row = row_bytes // 4
    rows = []
    for row_index in range(len(left) // row_bytes):
        first = row_index * words_per_row
        changed = [index for index in range(words_per_row)
                   if left_words[first + index] != right_words[first + index]]
        if changed:
            rows.append({
                "row": row_index,
                "changed_words": len(changed),
                "word_indices": changed,
                "byte_offsets": [index * 4 for index in changed],
            })
    return {
        "diagnostic_only": True,
        "bytes": len(left),
        "row_bytes": row_bytes,
        "row_count": len(left) // row_bytes,
        "changed_rows": len(rows),
        "changed_words": sum(row["changed_words"] for row in rows),
        "rows": rows,
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("left", type=Path, help="first binary dump")
    parser.add_argument("right", type=Path, help="second binary dump")
    parser.add_argument("--row-bytes", type=int, default=64,
                        help="fixed row size in bytes (default 64)")
    parser.add_argument("--json", action="store_true",
                        help="emit the comparison as JSON")
    args = parser.parse_args(argv)
    try:
        report = compare(args.left.read_bytes(), args.right.read_bytes(),
                         args.row_bytes)
    except (OSError, ValueError, struct.error) as exc:
        print(f"pose_dump_diff: {exc}", file=sys.stderr)
        return 1
    if args.json:
        report["left"] = str(args.left)
        report["right"] = str(args.right)
        print(json.dumps(report, indent=2))
    else:
        print(f"{args.left} vs {args.right}: {report['changed_rows']}/"
              f"{report['row_count']} rows, {report['changed_words']} changed words")
        for row in report["rows"]:
            offsets = ",".join(f"+0x{offset:x}" for offset in row["byte_offsets"])
            print(f"  row {row['row']:2}: {row['changed_words']} words at {offsets}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
