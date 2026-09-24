#!/usr/bin/env python3
"""Dump an interleaved instr+mem trace stream in order.

Interpreter mode pushes for every instruction: (pc<<16)|op   (op = word)
Mem hits push 4 records starting with (pc<<16)|0xFA20.
Probe records: (pc<<16)|0xFA10 / 0xFA11 (skipped).

Usage:
  m14_seq.py <trace.bin>                 # interleaved dump (first 400)
  m14_seq.py <trace.bin> --vdis LO HI    # virtual disasm from trace opcodes
"""
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMG = os.path.join(REPO, "extract", "exe", "1ST_READ.unsc.bin")
BASE = 0x8C010000

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sh4


def main():
    path = sys.argv[1]
    data = open(path, "rb").read()
    img = open(IMG, "rb").read()
    n = len(data) // 8
    vdis = "--vdis" in sys.argv
    lo_a, hi_a = 0x8C000000, 0x8E000000
    if vdis:
        pidx = sys.argv.index("--vdis")
        lo_a = int(sys.argv[pidx + 1], 16)
        hi_a = int(sys.argv[pidx + 2], 16)

    ops = {}                 # pc(0x8C) -> executed opcode word (trace truth)
    pc_imgdiff = 0
    memrecs = []
    i = 0
    while i < n:
        (rec,) = struct.unpack_from("<Q", data, i * 8)
        i += 1
        tag = rec & 0xFFFF
        pc = rec >> 16
        if tag == 0xFA20 and i + 2 < n:
            size_w = struct.unpack_from("<Q", data, i * 8)[0]
            addr = struct.unpack_from("<Q", data, (i + 1) * 8)[0]
            val = struct.unpack_from("<Q", data, (i + 2) * 8)[0]
            i += 3
            size = (size_w >> 48) & 0xFFFF
            isw = (size_w >> 47) & 1
            memrecs.append((pc | 0x80000000, "W" if isw else "R",
                            size, addr, val))
        elif tag in (0xFA10, 0xFA11, 0xFA21):
            continue
        else:
            pc8 = pc | 0x80000000
            if 0x8C010000 <= pc8 < 0x8E000000:
                ops[pc8] = rec & 0xFFFF
                off = pc8 - BASE
                if 0 <= off + 2 <= len(img):
                    w = struct.unpack_from("<H", img, off)[0]
                    if w != (rec & 0xFFFF):
                        pc_imgdiff += 1

    if vdis:
        delay = False
        for a in sorted(a for a in ops if lo_a <= a < hi_a):
            w = ops[a]
            d = sh4.decode(w, a)
            txt = f"{d[0]} {d[1]}".strip() if d else f".word 0x{w:04x}"
            pref = "_" if delay else ""
            print(f"{a:08x}  {w:04x}   {pref}{txt}")
            delay = (d and d[0] in sh4.BRANCHY) if not delay else False
        print(f"traced code words: {sum(1 for a in ops if lo_a <= a < hi_a)}",
              file=sys.stderr)
        return

    for (pc8, rw, size, addr, val) in memrecs[:400]:
        print(f"  MEM pc={pc8:#x} {rw}{size} addr={addr:#010x} val={val:#x}")
    print(f"mem hits: {len(memrecs)}  traced-insn words: {len(ops)}  "
          f"trace/img diffs: {pc_imgdiff}", file=sys.stderr)


if __name__ == "__main__":
    main()
