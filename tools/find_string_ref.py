#!/usr/bin/env python3
"""Find the code that references a string in the 1ST_READ image.

The tool locates the string's bytes, then the 32 bit literal that holds its
address, then the SH-4 `mov.l @(disp,PC),Rn` instructions that load that
literal - which are the instructions that reference the string.

Usage:
    python tools/find_string_ref.py "A Memory Card or enough free"
"""
from __future__ import annotations

import sys
from pathlib import Path

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
LOAD = 0x0C010000          # the image is copied to 0x0C004000 at the start
COPY = 0x0C004000


def main() -> int:
    needle = sys.argv[1].encode()
    image = IMAGE.read_bytes()
    off = image.find(needle)
    if off < 0:
        print("the string is not in the image")
        return 1
    print("string at image offset %06X (loaded at %08X, run at %08X)" % (off, LOAD + off, COPY + off))

    addr = LOAD + off
    lit = addr.to_bytes(4, "little")
    pos = 0
    while True:
        p = image.find(lit, pos)
        if p < 0:
            break
        # the literal's value is the *load* address; the code that reads it
        # runs at the copy address, so the pool slot sits at COPY + p.
        pool = COPY + p
        print("literal %08X at image offset %06X (pool slot %08X)" % (addr, p, pool))
        for i in range(max(0, p - 0x600), p):
            w = int.from_bytes(image[i:i + 4], "little")
            if (w & 0xF000) != 0xD000:
                continue
            disp = w & 0xFFF
            if w & 0x100:
                disp = disp - 0x1000
            pc = COPY + i
            target = ((pc + 4) & ~3) + disp * 4
            if target == pool:
                print("  referenced by mov.l @(%d,PC),r%d at %08X (image %06X)" % (disp, w & 0xF, pc, i))
        pos = p + 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
