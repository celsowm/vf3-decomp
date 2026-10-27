#!/usr/bin/env python3
"""port_frame_match.py - find the reference frame the port's render matches.

The port renders a frame with its own PVR2 model; the reference emulator
records the same game in a raw RGB video.  The two are not frame-aligned by
construction (the display lags the Tile Accelerator by a few frames), so the
comparison has to find the frame that matches and then say how close it is.

    python tools/port_frame_match.py --ours build/attract.ppm \\
        --ref extract/analysis/p1/probe.raw --tolerance 24

The reference may be a raw RGB dump (--width x --height x 3 bytes a frame) or
a sequence of images.  The report is, for the best frames: the share of pixels
within the tolerance, the mean absolute error and the largest channel error.
"""
from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parent.parent
import sys
sys.path.insert(0, str(ROOT / 'tools'))
from pvr2_frame_diff import read_ppm  # noqa: E402


def read_png(path: Path) -> np.ndarray:
    from PIL import Image
    return np.asarray(Image.open(path).convert('RGB'), dtype=np.int16)


def read_ours(path: Path) -> np.ndarray:
    if path.suffix.lower() == '.png':
        return read_png(path)
    w, h, data = read_ppm(path)
    return np.frombuffer(bytes(data), dtype=np.uint8).reshape(h, w, 3).astype(np.int16)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--ours', type=Path, required=True)
    ap.add_argument('--ref', type=Path, required=True)
    ap.add_argument('--width', type=int, default=640)
    ap.add_argument('--height', type=int, default=480)
    ap.add_argument('--tolerance', type=int, default=24)
    ap.add_argument('--top', type=int, default=8)
    ap.add_argument('--from-frame', type=int, default=0)
    ap.add_argument('--to-frame', type=int, default=-1)
    ap.add_argument('--out', type=Path, help='write the best reference frame as a PPM')
    a = ap.parse_args()

    ours = read_ours(a.ours)
    blob = a.ref.read_bytes()
    frame_bytes = a.width * a.height * 3
    frames = len(blob) // frame_bytes
    if frames == 0:
        raise SystemExit(f'{a.ref}: no {a.width}x{a.height}x3 frame in it')
    last = frames if a.to_frame < 0 else min(frames, a.to_frame + 1)
    print(f'{a.ref}: {frames} frames of {a.width}x{a.height}; scanning {a.from_frame}..{last - 1}')

    best = []
    for i in range(a.from_frame, last):
        ref = np.frombuffer(blob[i * frame_bytes:(i + 1) * frame_bytes],
                            dtype=np.uint8).reshape(a.height, a.width, 3).astype(np.int16)
        d = np.abs(ours - ref)
        m = d.max(axis=2)
        within = float((m <= a.tolerance).mean())
        mae = float(d.mean())
        best.append((within, -mae, i, int(m.max())))

    best.sort(reverse=True)
    print(f'tolerance {a.tolerance} levels')
    for within, negmae, i, worst in best[:a.top]:
        print(f'  frame {i:5d}: {100.0 * within:6.2f}% of the pixels within {a.tolerance}, '
              f'mean error {-negmae:6.2f}, worst channel {worst}')

    if a.out is not None:
        i = best[0][2]
        ref = blob[i * frame_bytes:(i + 1) * frame_bytes]
        a.out.write_bytes(f'P6\n{a.width} {a.height}\n255\n'.encode() + ref)
        print(f'wrote {a.out} (reference frame {i})')
    return 0


if __name__ == '__main__':
    sys.exit(main())
