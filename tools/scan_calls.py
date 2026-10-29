#!/usr/bin/env python3
"""scan_calls.py - the direct call sites of a function in the 1ST_READ image.

The image loads at 0x0C010000, so the guest addresses are the 0x0C form
(0x8C... is the uncached mirror of the same code).  Only `bsr` is scanned: a
call through a function pointer or through a literal-pool register leaves no
`bsr` behind, and `tools/lit_find.py` is the tool for that side.

    python tools/scan_calls.py 0x0C04C18C

The target is `instruction + 4 + disp*2` (the rule `tools/sh4.py` uses).
"""
import sys
from pathlib import Path

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
LOAD = 0x0C010000


def sign12(v: int) -> int:
    return v - 0x1000 if v & 0x800 else v


def main() -> int:
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    target = int(sys.argv[1], 0)
    image = IMAGE.read_bytes()
    hits = []
    for i in range(0, len(image) - 2, 2):
        w = int.from_bytes(image[i:i + 2], "little")
        if (w & 0xF000) != 0xB000:            # bsr disp12
            continue
        pc = LOAD + i
        if pc + 4 + sign12(w & 0xFFF) * 2 == target:
            hits.append(pc)
    for pc in hits:
        print("bsr -> %08X at %08X (image %06X)" % (target, pc, pc - LOAD))
    print("%d direct call sites" % len(hits))
    return 0


if __name__ == "__main__":
    sys.exit(main())
