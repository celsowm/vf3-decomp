#!/usr/bin/env python3
"""Which functions reference which strings.

Uses Ghidra xref dump (code->data refs) + function table. Focus: resource-file
name strings (*.BIN, *.POL, *.TEX...) -> reader functions = loader chain.

Outputs: extract/analysis/string_readers.csv (string_addr, preview, reader_fn)
"""
import bisect
import csv
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
AN = os.path.join(REPO, "extract", "analysis")
BASE = 0x8C010000

NAMECHARS = re.compile(rb"[ -~]{4,}")


def main():
    prog = sys.argv[1] if len(sys.argv) > 1 else "1ST_READ"
    raw = open(os.path.join(REPO, "extract", "exe",
                            prog + ".unsc.bin"), "rb").read()
    funcs = []
    with open(os.path.join(AN, f"funcs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    funcs.sort()
    ents = [r[0] for r in funcs]

    def fn_of(a):
        i = bisect.bisect_right(ents, a) - 1
        if i >= 0 and funcs[i][0] <= a < funcs[i][0] + max(funcs[i][1], 1):
            return funcs[i][2]
        return None

    # collect interesting strings: file-like names
    strings = {}   # addr -> text
    for m in NAMECHARS.finditer(raw):
        s = m.group().decode("ascii", "replace")
        if re.search(r"\.(BIN|TEX|POL|CLI|MTL|AFS|SFD)$", s, re.I) or \
                re.search(r"^[A-Z0-9_]{3,}\.[A-Z0-9]{2,3}$", s):
            strings[BASE + m.start()] = s
    print(f"name-like strings: {len(strings)}")

    readers = []   # (str_addr, text, reader_fn)
    with open(os.path.join(AN, f"xrefs_{prog}.unsc.bin.csv")) as f:
        for r in csv.DictReader(f):
            try:
                to = int(r["to"], 16)
            except ValueError:
                continue
            # nearest string start at or before 'to'
            for sa, txt in strings.items():
                if sa <= to < sa + len(txt) + 1:
                    fn = fn_of(int(r["from"], 16))
                    readers.append((sa, txt, fn,
                                    r["from"], r["type"]))
                    break

    bystr = {}
    for sa, txt, fn, fr, ty in readers:
        bystr.setdefault(sa, []).append((txt, fn, fr, ty))

    out = os.path.join(AN, f"string_readers_{prog}.csv")
    with open(out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["str_addr", "text", "reader_fn", "from", "reftype"])
        for sa in sorted(bystr):
            for txt, fn, fr, ty in bystr[sa]:
                w.writerow([f"0x{sa:08X}", txt, fn or "?", fr, ty])

    # digest: functions that read the MOST distinct file names = loader-ish
    import collections
    fnn = collections.defaultdict(set)
    for sa, txt, fn, fr, ty in readers:
        if fn:
            fnn[fn].add(txt)
    print("\ntop string-reading functions (loader candidates):")
    for fn, ss in sorted(fnn.items(), key=lambda kv: -len(kv[1]))[:15]:
        print(f"  {fn}: {len(ss)} strings  e.g. {sorted(ss)[:4]}")


if __name__ == "__main__":
    main()
