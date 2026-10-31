#!/usr/bin/env python3
"""gd_layout.py - map the data track of a .gdi: which sectors carry data.

The port's loader asked the drive for FAD 0x0000b06e (LBA 45016) and the
sector it received was all zeros, while the reference's loader reads FAD
429257 (LBA 429107) and never asks for 45016.  This tool walks the data track
and prints the first sectors that are not empty, so the disc's own layout can
be compared with what the guest asks for.

    python tools/gd_layout.py rom/vf3.gdi [--from 44990] [--count 60]
"""
from __future__ import annotations

import sys
from pathlib import Path

SECTOR = 2048
RAW = 2352


def rows(gdi: Path):
    out = []
    for line in gdi.read_text(errors="replace").splitlines()[1:]:
        p = line.split()
        if len(p) >= 6:
            out.append((int(p[1]), int(p[3]), p[4].strip('"')))
    return out


def main() -> int:
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    gdi = Path(sys.argv[1])
    start = 45000
    count = 60
    args = sys.argv[2:]
    for i, a in enumerate(args):
        if a == "--from":
            start = int(args[i + 1], 0)
        if a == "--count":
            count = int(args[i + 1], 0)
    tracks = rows(gdi)
    base, size, name = tracks[-1]
    path = gdi.parent / name
    with open(path, "rb") as f:
        lba = start
        while lba < start + count:
            off = (lba - base) * size + (16 if size == RAW else 0)
            f.seek(off)
            buf = f.read(SECTOR)
            if len(buf) < SECTOR:
                break
            nz = sum(1 for b in buf if b)
            head = buf[:16].hex()
            print("LBA %6d (FAD %6d)  nonzero %4d/2048  %s" % (lba, lba + 150, nz, head))
            lba += 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
