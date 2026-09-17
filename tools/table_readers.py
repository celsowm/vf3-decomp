#!/usr/bin/env python3
"""Correlate Ghidra xrefs with discovered fnptr tables.
Outputs extract/analysis/table_readers.csv and prints a ranked digest."""
import bisect
import collections
import csv
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")


def load_funcs(prog):
    rows = []
    with open(os.path.join(AN, f"funcs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    rows.sort()
    return rows


def main():
    prog = sys.argv[1] if len(sys.argv) > 1 else "1ST_READ"
    funcs = load_funcs(prog)
    ents = [f[0] for f in funcs]

    def fn_of(a):
        i = bisect.bisect_right(ents, a) - 1
        if i >= 0:
            e, s, n = funcs[i]
            if e <= a < e + max(s, 1):
                return n
        return None

    tabs = []
    with open(os.path.join(AN, f"fntables_{prog}.csv")) as f:
        for r in csv.DictReader(f):
            b = int(r["table_base"], 16)
            tabs.append((b, b + int(r["n_entries"]) * 4))

    hits = collections.Counter()
    readers = collections.defaultdict(set)
    skipped = 0
    with open(os.path.join(AN, f"xrefs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            try:
                a = int(r["to"], 16)
                fa = int(r["from"], 16)
            except ValueError:
                skipped += 1
                continue
            fn = fn_of(fa)
            for lo, hi in tabs:
                if lo <= a < hi:
                    hits[lo] += 1
                    if fn:
                        readers[lo].add(fn)
                    break

    with open(os.path.join(AN, f"table_readers_{prog}.csv"), "w",
              newline="") as f:
        w = csv.writer(f)
        w.writerow(["table_base", "n_refs", "n_reader_fns", "readers"])
        for base, c in hits.most_common():
            w.writerow([f"0x{base:08X}", c, len(readers[base]),
                        ";".join(sorted(readers[base]))])

    print(f"{len(tabs)} tables, {len(hits)} referenced; skipped unparseeable: "
          f"{skipped}")
    for base, c in hits.most_common(18):
        print(f"0x{base:08X} refs={c} readers={len(readers[base])} "
              f"{sorted(readers[base])[:4]}")


if __name__ == "__main__":
    main()
