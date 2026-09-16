#!/usr/bin/env python3
"""Join resolved call targets (callgraph.py output) with Ghidra function list
and fingerprint names -> docs/re/hotspots.md (most-called functions)."""
import collections
import csv
import os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")
DOCS = os.path.join(REPO, "docs", "re")


def main():
    calls = collections.Counter()
    with open(os.path.join(AN, "disasm_1ST_READ.unsc.bin.calls.csv")) as f:
        for r in csv.DictReader(f):
            calls[int(r["target"], 16)] += 1

    gname = {}
    with open(os.path.join(AN, "funcs_1ST_READ.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            gname[int(r["entry"], 16)] = r["name"]

    with open(os.path.join(DOCS, "hotspots.md"), "w", newline="\n") as d:
        d.write("# Most-called targets in 1ST_READ (from static call-graph pass)\n\n")
        d.write("| rank | address | calls | ghidra name |\n|---|---|---|---|\n")
        for i, (addr, c) in enumerate(calls.most_common(120)):
            nm = gname.get(addr, "(not a fn start)")
            d.write(f"| {i+1} | 0x{addr:08X} | {c} | {nm} |\n")
    tot = sum(calls.values())
    print(f"hotspots written; calls={tot} targets={len(calls)}")


if __name__ == "__main__":
    main()
