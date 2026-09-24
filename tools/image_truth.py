#!/usr/bin/env python3
"""Verify which image the CPU actually executes from.

Streams an interp-mode trace, collects unique (pc -> opcode) pairs, and
scores three content sources at pc-BASE:
  raw   = extract/gamedata/<PROG>.BIN       (file as shipped)
  unsc  = extract/exe/<PROG>.unsc.bin       (dc_scramble descramble output)
Prints match percentages for both. A correct pipeline shows raw ~= 100%.
"""
import os
import struct
import sys

import numpy as np

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x8C010000


def collect(path, want_limit=250_000):
    data_len = os.path.getsize(path)
    n = data_len // 8
    ops = {}
    with open(path, "rb") as f:
        done = 0
        while done < n and len(ops) < want_limit:
            take = min(8_000_000, n - done)
            arr = np.frombuffer(f.read(take * 8), dtype=np.uint64)
            pc = (arr >> np.uint64(16)).astype(np.uint32)
            word = (arr & np.uint64(0xFFFF)).astype(np.uint32)
            # drop mem/probe markers
            tag = (arr & np.uint64(0xFFFF))
            instr = ~((tag == np.uint64(0xFA20)) | (tag == np.uint64(0xFA10))
                      | (tag == np.uint64(0xFA11)))
            pcs = pc[instr]
            ws = word[instr]
            pcs = (pcs | np.uint32(0x80000000))
            sel = (pcs >= np.uint32(BASE)) & (pcs < np.uint32(0x8E000000))
            for a, w in zip(pcs[sel], ws[sel]):
                ops[int(a)] = int(w)
            done += take
    return ops


def main():
    trace = sys.argv[1]
    prog = sys.argv[2] if len(sys.argv) > 2 else "1ST_READ"
    ops = collect(trace)
    print(f"unique executed (pc,op): {len(ops)}")
    raw = open(os.path.join(REPO, "extract", "gamedata", prog + ".BIN"),
               "rb").read()
    unsc = open(os.path.join(REPO, "extract", "exe", prog + ".unsc.bin"),
                "rb").read()
    mraw = munsc = mnone = 0
    for a, w in ops.items():
        off = a - BASE
        br = struct.unpack_from("<H", raw, off)[0] if off + 2 <= len(raw) else None
        bu = struct.unpack_from("<H", unsc, off)[0] if off + 2 <= len(unsc) else None
        if bu == w:
            munsc += 1
        if br == w:
            mraw += 1
        if br != w and bu != w:
            mnone += 1
    tot = len(ops)
    print(f"raw-file match : {mraw}/{tot} = {100.0*mraw/tot:.2f}%")
    print(f"unsc match     : {munsc}/{tot} = {100.0*munsc/tot:.2f}%")
    print(f"neither        : {mnone}/{tot} = {100.0*mnone/tot:.2f}%")


if __name__ == "__main__":
    main()
