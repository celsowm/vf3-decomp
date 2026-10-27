#!/usr/bin/env python3
"""ta_split.py - cut a reference TA capture into frames.

The instrument (tools/refemu/vf3dump.c) writes every 32-byte TA block the
reference received, and after each frame a marker block whose first word is
0xDEADBE01 and whose second word is the frame number.  Frame N is the run of
blocks between marker N-1 and marker N.

  python tools/ta_split.py ref_ta.bin 299 300 --out-dir frames/   # ta_fr299.bin ...
  python tools/ta_split.py ref_ta.bin --list                      # marker table
"""
from __future__ import annotations

import argparse
import mmap
import struct
import sys
from pathlib import Path

MARKER = b'\x01\xbe\xad\xde'      # 0xDEADBE01, little-endian
BLOCK = 32


def find_markers(m) -> dict[int, int]:
    """frame number -> index of its marker block"""
    marks: dict[int, int] = {}
    for i in range(len(m) // BLOCK):
        if m[i * BLOCK:i * BLOCK + 4] == MARKER:
            marks[struct.unpack_from('<I', m, i * BLOCK + 4)[0]] = i
    return marks


def frame_blocks(m, marks: dict[int, int], frame: int) -> bytes:
    if frame not in marks:
        raise SystemExit(f'frame {frame} has no marker (have {min(marks)}..{max(marks)})')
    start = marks[frame - 1] + 1 if frame - 1 in marks else 0
    return bytes(m[start * BLOCK:marks[frame] * BLOCK])


def split(path: Path, frames: list[int], out_dir: Path) -> list[Path]:
    out_dir.mkdir(parents=True, exist_ok=True)
    with path.open('rb') as f, mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ) as m:
        marks = find_markers(m)
        out = []
        for fr in frames:
            data = frame_blocks(m, marks, fr)
            p = out_dir / f'ta_fr{fr}.bin'
            p.write_bytes(data)
            out.append(p)
        return out


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or '').split('\n')[0])
    ap.add_argument('capture', type=Path)
    ap.add_argument('frames', type=int, nargs='*')
    ap.add_argument('--out-dir', type=Path, default=Path('.'))
    ap.add_argument('--list', action='store_true', help='print the markers and exit')
    a = ap.parse_args()
    if a.list:
        with a.capture.open('rb') as f, mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ) as m:
            marks = find_markers(m)
        prev = -1
        for fr in sorted(marks):
            print(f'frame {fr}: marker block {marks[fr]}, {marks[fr] - prev - 1} blocks')
            prev = marks[fr]
        return 0
    if not a.frames:
        ap.error('give frame numbers or --list')
    for p in split(a.capture, a.frames, a.out_dir):
        print(f'{p} ({p.stat().st_size // BLOCK} blocks)')
    return 0


if __name__ == '__main__':
    sys.exit(main())
