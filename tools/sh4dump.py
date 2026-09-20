#!/usr/bin/env python3
"""SH-4 clean disassembly of 1ST_READ regions (uses tools/.venv capstone).

Linear-sweep from a start address; every mov.l @(disp,PC) / mov.w @(disp,PC)
gets its literal pool target resolved and the 4-byte value shown inline.
Branches and delayed slots both printed (delay slot line prefixed '_').

Usage (venv python only):
  tools/.venv/Scripts/python tools/sh4dump.py <addr_hex> [n_instructions]
  tools/.venv/Scripts/python tools/sh4dump.py f 8c058e92 200
"""
import os
import struct
import sys

from capstone import CS_MODE_SH4, CS_MODE_LITTLE_ENDIAN, Cs

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMG = os.path.join(REPO, "extract", "exe", "1ST_READ.unsc.bin")
BASE = 0x8C010000


def load():
    with open(IMG, "rb") as f:
        return f.read()


def main():
    args = sys.argv[1:]
    if args and args[0] == "f":
        args = args[1:]
    addr = int(args[0], 16)
    n = int(args[1]) if len(args) > 1 else 60
    data = load()

    md = Cs(CS_ARCH := 0x0, 0)  # placeholder; replaced below
    from capstone import CS_ARCH_SH
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)
    md.detail = False

    code = data[addr - BASE:]
    off = 0
    shown = 0
    delay_next = False
    while shown < n and off + 2 <= len(code):
        chunk = code[off:off + 2]
        insns = list(md.disasm(chunk, addr + off))
        if not insns:
            print(f"{addr + off:08x}  {int.from_bytes(chunk, 'little'):04x}    .word")
            off += 2
            continue
        i = insns[0]
        txt = f"{i.mnemonic} {i.op_str}".strip()
        note = ""
        # capstone renders pc-relative literal loads as absolute addresses
        import re
        m = re.match(r"mov\.([lw])\s+(0x[0-9a-f]+),\s*(r\d+)", txt)
        if m:
            w = m.group(1)
            lit = int(m.group(2), 16)
            offimg = lit - BASE
            if 0 <= offimg < len(data):
                if w == "l":
                    val = struct.unpack_from("<I", data, offimg)[0]
                    note = f"  # lit={val:08x}"
                else:
                    val = struct.unpack_from("<H", data, offimg)[0]
                    note = f"  # lit.w={val:04x}"
        # jsr/bsrf-style resolved targets: annotate name from funcs csv if given
        tag = "_" if delay_next else ""
        print(f"{addr + off:08x}  {int.from_bytes(chunk, 'little'):04x}    {tag}{txt}{note}")
        shown += 1
        off += 2
        # delay slot tracking: branch-class mnemonics take effect next slot
        branchy = i.mnemonic.startswith(("bra", "bsr", "bf", "bt", "jmp", "jsr", "rts", "rte")) or i.mnemonic.endswith("/s")
        delay_next = branchy and not delay_next
        if delay_next and i.mnemonic in ("rts", "jmp", "bra") and shown:
            pass


if __name__ == "__main__":
    main()
