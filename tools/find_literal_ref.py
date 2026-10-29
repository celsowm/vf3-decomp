#!/usr/bin/env python3
"""Find the code that references a 32 bit literal in the 1ST_READ image.

The tool finds the literal in the image's literal pools and the SH-4
`mov.l @(disp,PC),Rn` instructions that load it.  It is the way into the
game's own code from a data address.

The image runs where it is loaded (0x0C010000), so a guest address is the
load address plus the image offset.  The PC-relative load follows the
decoder the oracle uses: the register is in bits 8-11, the displacement is
the eight bits at 3-0 (unsigned) and the literal sits at
((pc + 4) & ~3) + disp * 4.

Usage:
    python tools/find_literal_ref.py 0x0C19C6A0
"""
from __future__ import annotations

import sys
from pathlib import Path

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
LOAD = 0x0C010000          # the image runs where it is loaded


def main() -> int:
    value = int(sys.argv[1], 0)
    image = IMAGE.read_bytes()
    lit = value.to_bytes(4, "little")
    pos = 0
    hits = 0
    while True:
        p = image.find(lit, pos)
        if p < 0:
            break
        pool = LOAD + p
        print("literal %08X at image offset %06X (pool slot %08X)" % (value, p, pool))
        for i in range(max(0, p - 0x800), p):
            w = int.from_bytes(image[i:i + 4], "little")
            if (w & 0xF000) != 0xD000:
                continue
            disp = w & 0xFF
            pc = LOAD + i
            if ((pc + 4) & ~3) + disp * 4 == pool:
                print("  mov.l @(%d,PC),r%d at %08X (image %06X)" % (disp, (w >> 8) & 0xF, pc, i))
                hits += 1
        pos = p + 1
    if not hits:
        print("no PC-relative load found")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
