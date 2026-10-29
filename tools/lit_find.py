#!/usr/bin/env python3
"""lit_find.py - every place the image spells a 32-bit value.

A PC-relative literal (`mov.l @(disp,PC),Rn`) is found by looking for the value
in the image and then for the loads that point at that pool slot; the
`mov.l #imm,Rn` form (the literal in the word after the opcode) is found too.

    python tools/lit_find.py 0x0C0EA314

A value that is spelled only ONCE, and only as data, is not reachable from
code - that is how the SDK service table's address was proved to have no
literal reference in 1ST_READ (see docs/re/mpdrv_device_table.md).
"""
import sys
from pathlib import Path

IMAGE = Path("extract/exe/1ST_READ.unsc.bin")
LOAD = 0x0C010000


def main() -> int:
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    value = int(sys.argv[1], 0)
    image = IMAGE.read_bytes()
    lit = value.to_bytes(4, "little")
    pos = 0
    found = 0
    while True:
        p = image.find(lit, pos)
        if p < 0:
            break
        found += 1
        print("literal at %08X (image %06X)" % (LOAD + p, p))
        for i in range(max(0, p - 0x1000), p):
            if i + 6 > len(image):
                break
            w = int.from_bytes(image[i:i + 4], "little")
            if (w & 0xF000) == 0xD000:        # mov.l @(disp,PC),Rn
                disp = w & 0xFF
                pc = LOAD + i
                if ((pc + 4) & ~3) + disp * 4 == LOAD + p:
                    print("   mov.l @(%d,PC),r%d at %08X" % (disp, (w >> 8) & 0xF, pc))
            if (w & 0x000F) == 0 and image[i + 2:i + 6] == lit:
                print("   mov.l #%08X,r%d at %08X" % (value, (w >> 8) & 0xF, LOAD + i))
        pos = p + 1
    if not found:
        print("the value does not occur in the image")
    return 0


if __name__ == "__main__":
    sys.exit(main())
