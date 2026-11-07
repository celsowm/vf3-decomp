#!/usr/bin/env python3
"""Inspect candidate float-vector blocks in VF3 stage collision (.CLI) files.

This is a structural aid, not a format decoder: it reports contiguous xyz-like
float runs with their bounds so candidate collision arrays can be compared
across stages. A candidate is not labeled as a floor, wall, or collision mesh.
"""
from __future__ import annotations

import argparse
import csv
import math
import struct
import sys
from pathlib import Path


def scan_float_blocks(data: bytes, min_triples: int, max_abs: float):
    """Yield (offset, points) for long runs of finite, bounded float triples."""
    blocks = []
    offset = 0
    limit = len(data) - 11
    while offset <= limit:
        point = struct.unpack_from("<fff", data, offset)
        if (max(abs(value) for value in point) >= 1e-12 and
                all(math.isfinite(value) and abs(value) <= max_abs
                    for value in point)):
            start = offset
            points = []
            cursor = offset
            while cursor <= limit:
                point = struct.unpack_from("<fff", data, cursor)
                if not all(math.isfinite(value) and abs(value) <= max_abs
                           for value in point):
                    break
                points.append(point)
                cursor += 12
            if len(points) >= min_triples:
                blocks.append((start, points))
                offset = cursor
                continue
        offset += 4
    return blocks


def bounds(points):
    return tuple((min(point[axis] for point in points),
                  max(point[axis] for point in points)) for axis in range(3))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("cli", nargs="+", type=Path,
                        help="one or more extracted .CLI files")
    parser.add_argument("--min-triples", type=int, default=24,
                        help="minimum consecutive xyz triples (default: 24)")
    parser.add_argument("--max-abs", type=float, default=4096.0,
                        help="maximum absolute component to consider (default: 4096)")
    parser.add_argument("--csv", type=Path,
                        help="write block offsets, counts and bounds to CSV")
    args = parser.parse_args(argv)
    if args.min_triples < 1:
        parser.error("--min-triples must be positive")
    if not math.isfinite(args.max_abs) or args.max_abs <= 0:
        parser.error("--max-abs must be a positive finite number")

    rows = []
    for path in args.cli:
        try:
            data = path.read_bytes()
        except OSError as exc:
            print(f"cli_scan: {path}: {exc}", file=sys.stderr)
            return 1
        if len(data) < 16 or struct.unpack_from("<I", data)[0] != 0x18:
            print(f"cli_scan: {path}: missing expected 0x18 header marker",
                  file=sys.stderr)
            return 1
        header = struct.unpack_from("<4I", data)
        blocks = scan_float_blocks(data, args.min_triples, args.max_abs)
        print(f"{path.name}: {len(data)} bytes, header="
              f"{header[0]:#x} {header[1]:#x} {header[2]:#x} {header[3]:#x}, "
              f"{len(blocks)} candidate blocks")
        for index, (offset, points) in enumerate(blocks):
            box = bounds(points)
            print(f"  {index:03d} @0x{offset:06X} {len(points):5d} xyz  "
                  f"x=[{box[0][0]:.3f},{box[0][1]:.3f}] "
                  f"y=[{box[1][0]:.3f},{box[1][1]:.3f}] "
                  f"z=[{box[2][0]:.3f},{box[2][1]:.3f}]")
            rows.append((str(path), len(data), *header, index, offset,
                         len(points), *(value for axis in box for value in axis)))

    if args.csv:
        args.csv.parent.mkdir(parents=True, exist_ok=True)
        columns = ("file", "file_size", "header0", "header1", "header2",
                   "header3", "block", "offset", "triples", "x_min",
                   "x_max", "y_min", "y_max", "z_min", "z_max")
        with args.csv.open("w", newline="", encoding="utf-8") as output:
            writer = csv.writer(output)
            writer.writerow(columns)
            writer.writerows(rows)
        print(f"wrote {args.csv}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
