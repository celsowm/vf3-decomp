#!/usr/bin/env python3
"""Diff VF3 builds via function mnemonic skeletons exported by Vf3Export.java.

Classification for M2: functions with identical normalized mnemonic streams in
retail & E3 are library/stable-core code; functions without a counterpart are
game-code that changed between builds.
"""
import csv
import collections
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")


def load(path):
    funcs = []
    with open(path) as f:
        addr = size = ops = None
        buf = []
        for line in f:
            if line.startswith("FN "):
                if addr is not None:
                    funcs.append((addr, size, "\n".join(buf), buf))
                _, a, s, n, h = line.split()
                addr, size = int(a, 16), int(s)
                buf = []
            else:
                buf.append(line.strip())
        if addr is not None:
            funcs.append((addr, size, "\n".join(buf), buf))
    return funcs


def main():
    a = load(os.path.join(AN, "export_1ST_READ.unsc.bin.txt"))
    b = load(os.path.join(AN, "export_VF3TBE3.unsc.bin.txt"))
    byops_b = collections.defaultdict(list)
    for addr, size, ops, lst in b:
        byops_b[ops].append((addr, size))

    exact = 0
    mapped = []
    unmatched = []
    for addr, size, ops, lst in a:
        cands = byops_b.get(ops)
        if cands:
            exact += 1
            mapped.append((addr, cands[0][0], size, len(lst)))
        else:
            unmatched.append((addr, size))

    print(f"1ST_READ funcs: {len(a)}  VF3TBE3 funcs: {len(b)}")
    print(f"exact mnemonic-stream matches: {exact}")
    with open(os.path.join(AN, "build_diff_map.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["retail_addr", "e3_addr", "retail_size", "ninstr"])
        for r, e, s, n in mapped:
            w.writerow([f"0x{r:X}", f"0x{e:X}", s, n])

    unmatched.sort(key=lambda t: -t[1])
    with open(os.path.join(AN, "unmatched_retail.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["retail_addr", "size"])
        for a_, s_ in unmatched:
            w.writerow([f"0x{a_:X}", s_])

    print(f"unmatched (game-code candidates): {len(unmatched)}")
    print("largest unmatched retail functions:")
    for a_, s_ in unmatched[:25]:
        print(f"  0x{a_:08X}  {s_:6d} bytes")


if __name__ == "__main__":
    main()
