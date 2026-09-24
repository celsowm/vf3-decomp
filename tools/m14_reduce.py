#!/usr/bin/env python3
"""Reduce an M14 mem-watch stream (m14_wide_*.bin) to human-readable hits.

Record layout per hit (4 x u64 little-endian):
  rec0 = (pc<<16) | 0xFA20
  rec1 = (size<<48) | (isWrite<<47)          # [46:0] spare
  rec2 = addr
  rec3 = value

Note: during interp execution ctx.pc = instr+2 (ReadNexOp advances before
ExecuteOpcode), so the *executing* instruction is at (pc - 2). The csv prints
both. Also annotates reads inside a resident pack window with the pack byte.
"""
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")
IMG = os.path.join(REPO, "extract", "exe", "1ST_READ.unsc.bin")
BASE = 0x8C010000

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sh4


def main():
    path = sys.argv[1]
    data = open(path, "rb").read()
    img = open(IMG, "rb").read()
    n = len(data) // 8
    out = []
    i = 0
    while i + 3 < n:
        r0, r1, r2, r3 = struct.unpack_from("<4Q", data, i * 8)
        if (r0 & 0xFFFF) != 0xFA20:
            i += 1
            continue
        pc = r0 >> 16
        size = (r1 >> 48) & 0xFFFF
        isw = (r1 >> 47) & 1
        addr, val = r2, r3
        # decode executing instruction (pc-2 per interp pre-increment)
        txt = ""
        epc = pc - 2
        off = epc - BASE
        if 0 <= off + 2 <= len(img):
            w = struct.unpack_from("<H", img, off)[0]
            dec = sh4.decode(w, epc)
            if dec:
                txt = f"{dec[0]} {dec[1]}".strip()
        out.append((pc, size, isw, addr, val, epc, txt))
        i += 4

    lim = int(sys.argv[2]) if len(sys.argv) > 2 else 60
    for t in out[:lim]:
        pc, size, isw, addr, val, epc, txt = t
        rw = "W" if isw else "R"
        print(f"pc={pc:#010x} exec@{epc:#010x} {rw}{size} "
              f"addr={addr:#010x} val={val:#010x}  {txt}")
    print(f"total hits: {len(out)}")


if __name__ == "__main__":
    main()
