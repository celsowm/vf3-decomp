#!/usr/bin/env python3
"""Disassemble a range of the 1ST_READ image (the tools/sh4.py decoder).

The image is loaded at 0x0C010000 and copied to 0x0C004000, so a guest
address below 0x0C010000 belongs to the copy.

Usage:
    python tools/disasm_range.py 0x0C02B1F8 0x80
"""
from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from sh4 import decode  # noqa: E402

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
COPY = 0x0C010000          # the image runs where it is loaded (the 29 bit mask)


def main() -> int:
    start = int(sys.argv[1], 0)
    length = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x40
    image = IMAGE.read_bytes()
    off = start - COPY
    if off < 0 or off >= len(image):
        print("the address is outside the image")
        return 1
    for a in range(start, min(start + length, COPY + len(image)), 2):
        w = int.from_bytes(image[off + (a - start):off + (a - start) + 2], "little")
        d = decode(w, a)
        print("%08X %04X  %s" % (a, w, d if d else "?"))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
