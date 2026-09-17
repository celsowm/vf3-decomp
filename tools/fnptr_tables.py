#!/usr/bin/env python3
"""Find function-pointer tables in 1ST_READ (scene/task/state tables).

A run of >=3 consecutive dwords (8-byte stride allowance) that all point into
the known function-entry set is almost certainly a dispatch table.  These are
where the game keeps its mode/scene/task switchboards.

Outputs:
  extract/analysis/fntables.csv      table_base, n_entries, first_fn
  extract/analysis/fnptr_refs.csv    table_addr, target_fn
"""
import bisect
import csv
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x8C010000


def load_funcs(prog):
    rows = []
    with open(os.path.join(REPO, "extract", "analysis",
                           f"funcs_{prog}.unsc.bin.csv")) as f:
        next(f)
        for line in f:
            t = line.strip().split(",")
            if len(t) >= 2:
                try:
                    rows.append((int(t[0], 16), int(t[1])))
                except ValueError:
                    pass
    return sorted(rows)


def main():
    prog = sys.argv[1] if len(sys.argv) > 1 else "1ST_READ"
    raw = open(os.path.join(REPO, "extract", "exe",
                            prog + ".unsc.bin"), "rb").read()
    funcs = load_funcs(prog)
    ents = [f[0] for f in funcs]
    fens = set(ents)
    fsz = {f[0]: f[1] for f in funcs}

    dws = [struct.unpack_from("<I", raw, i)[0]
           for i in range(0, len(raw) - 4, 4)]

    # pointer -> entry mapping (also allow pointers landing INSIDE small fns);
    # normalize P2 cache-through alias 0x0Cxxxxxx -> 0x8Cxxxxxx.
    def aliasnorm(v):
        if 0x0C000000 <= v <= 0x0FFFFFFF:
            return v | 0x80000000
        return v

    def is_fnptr(v):
        v = aliasnorm(v)
        if v & 3:
            return False
        if not (BASE <= v < BASE + len(raw)):
            return False
        i = bisect.bisect_right(ents, v) - 1
        if i < 0:
            return False
        e = ents[i]
        return e <= v < e + max(fsz.get(e, 4), 4)

    n = len(dws)
    tables = []   # (table_addr, entries)
    i = 0
    while i < n:
        if not is_fnptr(dws[i]):
            i += 1
            continue
        j = i
        run = []
        while j < n and is_fnptr(dws[j]):
            run.append(aliasnorm(dws[j]))
            j += 1
        if len(run) >= 3:
            tables.append((BASE + i * 4, run))
        i = j

    with open(os.path.join(REPO, "extract", "analysis",
                           f"fntables_{prog}.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["table_base", "n_entries", "first_fns"])
        for base, run in tables:
            w.writerow([f"0x{base:08X}", len(run),
                        " ".join(f"0x{v:08X}" for v in run[:6])])

    with open(os.path.join(REPO, "extract", "analysis",
                           f"fnptrs_{prog}.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["table_addr", "target"])
        for base, run in tables:
            for k, v in enumerate(run):
                w.writerow([f"0x{base + k*4:08X}", f"0x{v:08X}"])

    # stats: most-referenced function entries via tables
    import collections
    cnt = collections.Counter(v for _, run in tables for v in run)
    print(f"{prog}: {len(tables)} pointer tables "
          f"({sum(len(r) for _, r in tables)} entries)")
    with open(os.path.join(REPO, "docs", "re", f"fntables_{prog}.md"),
              "w", newline="\n") as d:
        d.write(f"# Function-pointer tables in {prog}\n\n")
        d.write("| # | base | entries | first entries |\n|---|---|---|---|\n")
        for k, (base, run) in enumerate(tables):
            first = " ".join(f"0x{v:08X}" for v in run[:4])
            d.write(f"| {k+1} | 0x{base:08X} | {len(run)} | {first} |\n")
    print("largest tables:")
    for base, run in sorted(tables, key=lambda t: -len(t[1]))[:15]:
        print(f"  0x{base:08X}  {len(run):4d} entries  "
              f"first: 0x{run[0]:08X}")


if __name__ == "__main__":
    main()
