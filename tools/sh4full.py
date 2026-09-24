#!/usr/bin/env python3
"""SH-4 full linear-sweep dump (complete decoder, FP included).

Drop-in companion to sh4dump.py that actually understands the SH-4 FPU
space. Usage:

    python tools/sh4full.py <addr_hex> [n_instructions]
    python tools/sh4full.py f <func_hex> <count>    (same thing; f kept for
                                                     sh4dump CLI parity)
Literal-pool values annotated inline; delay-slot lines prefixed '_'.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sh4

BASE = 0x8C010000
IMG = os.path.join(sh4.REPO, "extract", "exe", "1ST_READ.unsc.bin")


def main():
    args = sys.argv[1:]
    if args and args[0] == "f":
        args = args[1:]
    addr = int(args[0], 16)
    n = int(args[1]) if len(args) > 1 else 60
    with open(IMG, "rb") as f:
        data = f.read()
    for r in sh4.disasm(data, BASE, addr, n):
        tag = "_" if r["delay"] else ""
        note = ""
        if "lit_val" in r:
            note = (f"  # lit={r['lit_val']:08x}"
                    if r["word"] >> 12 == 0xD else
                    f"  # lit.w={r['lit_val']:04x}")
            note += f" @{r['lit_addr']:08x}"
        print(f"{r['addr']:08x}  {r['word']:04x}   {tag}{r['text']}{note}")


if __name__ == "__main__":
    main()
