#!/usr/bin/env python3
"""pool_at.py - print the image's literal-pool words at a few addresses.

    python tools/pool_at.py 0x0c0371fc 0x0c037238
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
BASE = 0x0C010000


def main() -> int:
    data = IMAGE.read_bytes()
    lo = int(sys.argv[1], 0)
    hi = int(sys.argv[2], 0)
    for a in range(lo, hi, 4):
        off = a - BASE
        if 0 <= off <= len(data) - 4:
            print("%08x  %08x" % (a, struct.unpack_from("<I", data, off)[0]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
