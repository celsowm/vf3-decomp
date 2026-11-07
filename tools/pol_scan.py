#!/usr/bin/env python3
"""Find contiguous float-vector blocks in POL files and render point clouds.

Heuristic: u32 dwords that decode as IEEE floats in a sane range and align as
xyz (each rk triple in [-8,8]) form vertex data; image-space XY projection
renders them to a PNG for visual validation of a foot/limb silhouette.
"""
import os
import argparse
import struct
import sys
import zlib
from pathlib import Path

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def scan_float_blocks(data, min_len=64):
    """Return list of (offset, float triple count)."""
    n = len(data)
    blocks = []
    i = 0
    while i + 12 <= n:
        # read as 3 floats
        a, b, c = struct.unpack_from("<fff", data, i)
        if (-8 <= a <= 8 and -8 <= b <= 8 and -8 <= c <= 8
                and (a != 0.0 or b != 0.0 or c != 0.0)):
            j = i
            cnt = 0
            while j + 12 <= n:
                a, b, c = struct.unpack_from("<fff", data, j)
                if not (-8 <= a <= 8 and -8 <= b <= 8 and -8 <= c <= 8):
                    break
                j += 12
                cnt += 1
            if cnt >= min_len:
                blocks.append((i, cnt))
                i = j
        i += 4
    return blocks


def png(path, w, h, pix):
    def chunk(typ, d):
        c = struct.pack(">I", len(d)) + typ + d
        return c + struct.pack(">I", zlib.crc32(typ + d) & 0xFFFFFFFF)
    hdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)
    raw = b"".join(b"\x00" + b"".join(bytes(x) for x in row) for row in pix)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", hdr) +
                           chunk(b"IDAT", zlib.compress(raw, 9)) +
                           chunk(b"IEND", b""))


def render(proj, out, w=640, h=640):
    pix = [[(16, 16, 20) for _ in range(w)] for _ in range(h)]
    xs = [p[0] for p in proj]
    ys = [p[1] for p in proj]
    if not xs:
        return
    x0, x1 = min(xs), max(xs)
    y0, y1 = min(ys), max(ys)
    span = max(x1 - x0, y1 - y0, 1e-6)
    pad = 20
    for x, y in proj:
        px = pad + int((x - x0) / span * (w - 2 * pad))
        py = pad + int((y - y0) / span * (h - 2 * pad))
        pix[py][px] = (220, 240, 255)
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            if 0 <= px + dx < w and 0 <= py + dy < h:
                pix[py + dy][px + dx] = (140, 170, 200)
    png(out, w, h, pix)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", help="POL file to scan")
    parser.add_argument("output", nargs="?",
                        help="combined PNG path; omit when using --split-dir")
    parser.add_argument("--block", action="append", type=int,
                        help="render one zero-based float block; may be repeated")
    parser.add_argument("--split-dir", type=Path,
                        help="write one point-cloud PNG per detected block")
    parser.add_argument("--axes", choices=("x-y", "x-z", "y-z"), default="x-y",
                        help="2D projection axes for point-cloud previews")
    parser.add_argument("--min-triples", type=int, default=64,
                        help="minimum consecutive triples to keep (default: 64)")
    args = parser.parse_args(argv)
    if not args.split_dir and not args.output:
        parser.error("output PNG is required unless --split-dir is used")
    if args.min_triples < 1:
        parser.error("--min-triples must be positive")

    try:
        data = Path(args.pol).read_bytes()
    except OSError as exc:
        print(f"pol_scan: {exc}", file=sys.stderr)
        return 1
    blocks = scan_float_blocks(data, args.min_triples)
    print(f"{os.path.basename(args.pol)}: {len(blocks)} float blocks")
    if args.block is not None and any(index < 0 or index >= len(blocks)
                                      for index in args.block):
        parser.error(f"--block values must be in 0..{len(blocks) - 1}")
    selected = (list(enumerate(blocks)) if args.block is None else
                [(index, blocks[index]) for index in args.block])
    axes = {"x-y": (0, 1), "x-z": (0, 2), "y-z": (1, 2)}[args.axes]
    total = 0
    clouds = []
    for index, (offset, count) in selected:
        print(f"  block {index:02d} @0x{offset:06X} {count:5d} triples")
        total += count
        points = [struct.unpack_from("<fff", data, offset + k * 12)
                  for k in range(count)]
        if args.split_dir:
            args.split_dir.mkdir(parents=True, exist_ok=True)
            out = args.split_dir / f"block_{index:02d}_{offset:06x}.png"
            render([(point[axes[0]], point[axes[1]]) for point in points], out)
            print(f"    wrote {out}")
        else:
            clouds.extend(points)
    print(f"  total points: {total}")
    if not args.split_dir:
        render([(point[axes[0]], point[axes[1]]) for point in clouds], args.output)
        print("wrote", args.output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
