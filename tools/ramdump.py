#!/usr/bin/env python3
"""ramdump.py - SH-4 disassembly of a range out of a raw RAM dump.

The 1ST_READ image does not cover the whole RAM: the REIOS's bootstrap lives at
0x0C004000 (below the image, which starts at 0x0C010000), and the BIOS's own
copies live at 0x8C000000.  `tools/sh4dump.py` only reads the image, so this
one reads a raw dump instead - the port's `--dump-ram` output or a RAM window
pulled out of a reference capture.

Usage (venv python only):
  tools/.venv/Scripts/python tools/ramdump.py <ram.bin> <addr_hex> [n_instructions]

The address is the guest address (0x0C000000 base for a RAM dump); the literal
pool of a `mov.l @(disp,PC),Rn` is resolved and shown inline, the way
tools/sh4dump.py does it.
"""
import os
import re
import struct
import sys

from capstone import CS_ARCH_SH, CS_MODE_SH4, CS_MODE_SHFPU, CS_MODE_LITTLE_ENDIAN, Cs

BRANCH = re.compile(r"^(bf/s|bf|bt|bt/s|braf|bra|bsr|bsrf|jmp|jsr|rts|rte)")


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    path = sys.argv[1]
    base = int(sys.argv[2], 0) & ~3
    count = int(sys.argv[3], 0) if len(sys.argv) > 3 else 64
    data = open(path, "rb").read()
    ram_base = 0x0C000000 if len(data) == 0x01000000 else 0
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_SHFPU | CS_MODE_LITTLE_ENDIAN)
    pc = base
    emitted = 0
    while emitted < count:
        off = pc - ram_base
        if off < 0 or off + 2 > len(data):
            break
        chunk = data[off:off + 2]
        insn = next(md.disasm(chunk, pc, 1), None)
        if insn is None:
            print("%08x  %04x    .word" % (pc, int.from_bytes(chunk, "little")))
            pc += 2
            emitted += 1
            continue
        text = insn.mnemonic
        if text == "mov.l" and "@(" in insn.op_str and ",pc)" in insn.op_str:
            m = re.search(r"\((\d+),pc\)", insn.op_str)
            if m:
                disp = int(m.group(1))
                pool = ((pc + 4) & ~3) + disp * 4
                poff = pool - ram_base
                if 0 <= poff + 4 <= len(data):
                    val = struct.unpack_from("<I", data, poff)[0]
                    text += " # %08x" % val
        print("%08x  %04x    %-24s %s" % (pc, int.from_bytes(chunk, "little"), text, insn.op_str))
        pc += 2
        emitted += 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
