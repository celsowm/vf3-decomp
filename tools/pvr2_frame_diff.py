#!/usr/bin/env python3
"""pvr2_frame_diff.py - compare two frames pixel by pixel.

The port renders a frame with its own PVR2 model; the reference emulator
renders the same frame with the hardware model.  This tool says how close they
are: the number of differing pixels, the largest channel error, the first
differing pixel, and (optionally) a difference image.

Both inputs are either a binary PPM (P6, what the port writes) or a raw RGB
dump of --width x --height bytes (what the emulator's TEST_AUTOMATION build
writes, one frame at a time).

  python tools/pvr2_frame_diff.py ours.ppm ref.raw --width 640 --height 480
  python tools/pvr2_frame_diff.py ours.ppm ref.ppm --out diff.ppm --tolerance 1
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path


def read_ppm(path: Path) -> tuple[int, int, bytearray]:
    blob = path.read_bytes()
    if not blob.startswith(b'P6'):
        raise SystemExit(f'{path}: not a binary PPM')
    fields = []
    pos = 2
    while len(fields) < 3:
        while pos < len(blob) and blob[pos:pos + 1].isspace():
            pos += 1
        if blob[pos:pos + 1] == b'#':
            while pos < len(blob) and blob[pos:pos + 1] not in (b'\n', b'\r'):
                pos += 1
            continue
        start = pos
        while pos < len(blob) and not blob[pos:pos + 1].isspace():
            pos += 1
        fields.append(int(blob[start:pos]))
    pos += 1                       # exactly one whitespace byte after the maxval
    w, h, maxval = fields
    if maxval != 255:
        raise SystemExit(f'{path}: only 8-bit PPM is supported')
    data = bytearray(blob[pos:pos + w * h * 3])
    if len(data) != w * h * 3:
        raise SystemExit(f'{path}: truncated ({len(data)} of {w * h * 3} bytes)')
    return w, h, data


def read_raw(path: Path, w: int, h: int) -> tuple[int, int, bytearray]:
    blob = path.read_bytes()
    need = w * h * 3
    if len(blob) < need:
        raise SystemExit(f'{path}: truncated ({len(blob)} of {need} bytes)')
    return w, h, bytearray(blob[:need])


def read_any(path: Path, w: int, h: int) -> tuple[int, int, bytearray]:
    blob = path.read_bytes()[:2]
    if blob == b'P6':
        return read_ppm(path)
    return read_raw(path, w, h)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('a', type=Path)
    ap.add_argument('b', type=Path)
    ap.add_argument('--width', type=int, default=640)
    ap.add_argument('--height', type=int, default=480)
    ap.add_argument('--tolerance', type=int, default=0,
                    help='per-channel error that still counts as equal')
    ap.add_argument('--out', type=Path, help='write a difference image (PPM)')
    ap.add_argument('--max-report', type=int, default=10)
    a = ap.parse_args()

    w1, h1, da = read_any(a.a, a.width, a.height)
    w2, h2, db = read_any(a.b, a.width, a.height)
    if (w1, h1) != (w2, h2):
        raise SystemExit(f'size mismatch: {w1}x{h1} vs {w2}x{h2}')

    tol = a.tolerance
    differ = 0
    worst = 0
    first = None
    diff = bytearray(w1 * h1 * 3)
    for i in range(w1 * h1):
        o = 3 * i
        dr = da[o] - db[o]
        dg = da[o + 1] - db[o + 1]
        dbl = da[o + 2] - db[o + 2]
        m = max(abs(dr), abs(dg), abs(dbl))
        if m > worst:
            worst = m
        if m > tol:
            differ += 1
            if first is None:
                first = (i % w1, i // w1, (da[o], da[o + 1], da[o + 2]),
                         (db[o], db[o + 1], db[o + 2]), m)
            diff[o] = 255 if dr else 0
            diff[o + 1] = 255 if dg else 0
            diff[o + 2] = 255 if dbl else 0

    total = w1 * h1
    print(f'{a.a} vs {a.b}: {w1}x{h1}')
    print(f'  differing pixels: {differ} / {total} ({100.0 * differ / total:.4f}%)'
          f'  tolerance {tol}')
    print(f'  largest channel error: {worst}')
    if first is not None:
        x, y, ours, theirs, m = first
        print(f'  first difference at ({x},{y}): ours {ours} reference {theirs} (delta {m})')
    if a.out is not None:
        header = f'P6\n{w1} {h1}\n255\n'.encode()
        a.out.write_bytes(header + bytes(diff))
        print(f'  difference image: {a.out}')
    return 0 if differ == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
