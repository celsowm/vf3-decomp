#!/usr/bin/env python3
"""tools/bin_names.py -- enumerate embedded '*.BIN' name records in 1ST_READ.

Layout (docs/formats/RESOURCE_NAMES.md):
  name[<=12] '\x00' pad? then optional 4-byte `_xx` / plain tag (e.g. '_hi',
  '_ak', '_du'), trailing padding.

The string table region the game loader walks isn't fixed-stride: we find
'.BIN' anchors and walk back to the previous (alpha) run start. Emitting:

  extract/analysis/bin_names.csv (addr, name, tag, stride_next)

Usage: python tools/bin_names.py
"""
from __future__ import annotations

import csv
import re
from pathlib import Path

BIN = Path("extract/exe/1ST_READ.unsc.bin")
OUT = Path("extract/analysis/bin_names.csv")
BASE = 0x8C010000


def main():
    d = BIN.read_bytes()
    out = []
    for m in re.finditer(rb"\.BIN\x00?", d):
        e = m.start()
        s = e
        while s > 0:
            c = d[s - 1]
            if 65 <= c <= 90 or 48 <= c <= 57 or c in (0x5F, 0x20):
                s -= 1
            else:
                break
        name = d[s:e].decode("ascii", "ignore")
        if not (2 <= len(name) <= 12):
            continue
        tail_raw = d[m.end():m.end() + 12].split(b"\x00")[0]
        tail = "".join(chr(c) if 32 <= c < 127 else "" for c in tail_raw)
        out.append((s + BASE, name + ".BIN", tail))

    # dedupe (consecutive scans hitting same name end get filtered)
    seen = set()
    final = []
    for o, n, t in out:
        if n in seen:
            continue
        seen.add(n)
        final.append((o, n, t))

    with OUT.open("w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["addr", "name", "tag", "stride_next"])
        for i, (o, n, t) in enumerate(final):
            stride = (final[i + 1][0] - o) if i + 1 < len(final) else 0
            w.writerow([hex(o), n, t, stride])
    print(f"-> {OUT}  ({len(final)} .BIN rows)")


if __name__ == "__main__":
    main()
