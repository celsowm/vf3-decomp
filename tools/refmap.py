#!/usr/bin/env python3
"""Reverse map: whose functions REFERENCE a given set of target functions.

Usage: python tools/refmap.py 1ST_READ 8c04bda2 8c08232e ...
Reads xrefs_<prog>.unsc.bin.csv (Ghidra refs from instructions) and
prints caller fn for each target addr + one-line disasm context.
"""
import bisect
import csv
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")


def load(prog):
    funcs = []
    with open(os.path.join(AN, f"funcs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    funcs.sort()
    return funcs


def fn_of(funcs, a):
    ents = [f[0] for f in funcs]
    i = bisect.bisect_right(ents, a) - 1
    if i >= 0 and funcs[i][0] <= a < funcs[i][0] + max(funcs[i][1], 1):
        return funcs[i][2]
    return None


def main():
    prog = sys.argv[1]
    wanted = [int(x, 16) for x in sys.argv[2:]]
    funcs = load(prog)
    ents = [f[0] for f in funcs]

    def fn_of(a):
        i = bisect.bisect_right(ents, a) - 1
        if i >= 0 and funcs[i][0] <= a < funcs[i][0] + max(funcs[i][1], 1):
            return funcs[i][2], funcs[i][0]
        return ("?", a)

    hits = {w: [] for w in wanted}
    with open(os.path.join(AN, f"xrefs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            try:
                to = int(r["to"], 16)
                fr = int(r["from"], 16)
            except ValueError:
                continue
            for w in wanted:
                if to == w:
                    hits[w].append((fn_of(fr), fr, r["type"]))
    for w in wanted:
        print(f"0x{w:08X}:")
        for (fn, fe), fr, ty in hits[w]:
            print(f"   <- {fn} @0x{fe:08X}  (from 0x{fr:08X}, {ty})")
        if not hits[w]:
            print("   (no refs)")


if __name__ == "__main__":
    main()
