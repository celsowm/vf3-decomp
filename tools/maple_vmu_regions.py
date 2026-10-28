#!/usr/bin/env python3
"""Map the non-zero regions of the reference's default VMU image.

The port builds the same card in C (`src/sys/maple_hle.c`), so the port's
synthetic card has to reproduce the image the reference starts from.  This tool
lists every region that is not zero, so the C model can be written from the
facts instead of from a guess.

Usage:
    python tools/maple_vmu_regions.py build/vmu_default.bin
"""
from __future__ import annotations

import sys
from pathlib import Path

BLOCK = 512


def main() -> int:
    image = Path(sys.argv[1] if len(sys.argv) > 1 else "build/vmu_default.bin").read_bytes()
    blocks = len(image) // BLOCK
    print("%d blocks, %d bytes" % (blocks, len(image)))
    for b in range(blocks):
        chunk = image[b * BLOCK:(b + 1) * BLOCK]
        if any(chunk):
            first = next(i for i, v in enumerate(chunk) if v)
            last = len(chunk) - 1 - next(i for i, v in enumerate(reversed(chunk)) if v)
            print("block %3d: bytes %04x..%04x non-zero (%d bytes)" % (b, first, last, sum(1 for v in chunk if v)))
            print("   %s" % chunk[first:last + 1].hex(" "))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
