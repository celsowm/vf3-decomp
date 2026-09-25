#!/usr/bin/env python3
"""derive_windows.py — per-PC RAM windows for the golden batch runner.

Reads register-only goldens (golden_extract .json) and derives small RAM
windows around pointer-valued entry registers, so the next capture run gets
RAM-backed .cases without dumping 16 MB per hit.

Outputs a watch file with:
    pc   0xPC             (entry/exit register snapshots)
    rampc 0xPC base len   (RAM dump at entry+exit, one line per window)

Usage:
  python tools/derive_windows.py --goldens extract/analysis/goldens_b2 \
      --out tools/watch/vf3_b2.txt [--max-win 3] [--pad 0x80] \
      [--max-len 0x4000] [--regs r3,r4,r5,r13,r14,r15]
"""
from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path

RAM_LO, RAM_HI = 0x0C000000, 0x0D000000


def canon(v: int):
    """Return canonical P2 RAM address or None."""
    if v >= 0x80000000:
        v &= 0x1FFFFFFF
    if RAM_LO <= v < RAM_HI:
        return v
    return None


def merge_ranges(ranges, gap=0x100):
    ranges = sorted(ranges)
    out = []
    for b, e in ranges:
        if out and b - out[-1][1] <= gap:
            out[-1][1] = max(out[-1][1], e)
        else:
            out.append([b, e])
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--goldens", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--csv", default="")
    ap.add_argument("--max-win", type=int, default=3)
    ap.add_argument("--pad", type=lambda s: int(s, 0), default=0x80)
    ap.add_argument("--max-len", type=lambda s: int(s, 0), default=0x4000)
    ap.add_argument("--regs", default="r3,r4,r5,r6,r7,r8,r9,r13,r14,r15")
    a = ap.parse_args()

    regs = [r.strip() for r in a.regs.split(",") if r.strip()]
    gdir = Path(a.goldens)
    rows = []
    watch_lines = []
    for jf in sorted(gdir.glob("f_*.json")):
        doc = json.loads(jf.read_text(encoding="utf-8"))
        if "pc" not in doc:
            continue
        pc = int(doc["pc"], 16)
        # counts per canonical pointer, plus originating register
        counts: dict[int, int] = {}
        regof: dict[int, str] = {}
        for s in doc.get("samples", []):
            for rn in regs:
                v = s["in"].get(rn)
                if v is None:
                    continue
                c = canon(int(v))
                if c is None:
                    continue
                counts[c] = counts.get(c, 0) + 1
                regof.setdefault(c, rn)
        # candidate ranges around every pointer (padded)
        ranges = []
        for p in counts:
            b = max(RAM_LO, (p - a.pad) & ~0x3F)
            e = min(RAM_HI, p + a.pad)
            ranges.append((b, e))
        merged = merge_ranges(ranges)
        merged = [[b, min(e, b + a.max_len)] for b, e in merged]
        # rank merged windows by how many pointers fall inside
        def score(win):
            return sum(n for p, n in counts.items() if win[0] <= p < win[1])
        merged.sort(key=score, reverse=True)
        picks = merged[:a.max_win]
        picks.sort()
        if not picks:
            watch_lines.append(f"# {doc['pc']} {doc.get('name','')}: no pointer regs")
            rows.append({"pc": doc["pc"], "name": doc.get("name", ""),
                         "base": "-", "len": "-", "pointers": 0,
                         "regs": ""})
            continue
        upc = pc | 0x80000000
        watch_lines.append(f"pc 0x{upc:08x}")
        allregs = set()
        nptr = 0
        for b, e in picks:
            ln = (e - b + 3) & ~3
            watch_lines.append(f"rampc 0x{upc:08x} 0x{b:08x} 0x{ln:x}")
            for p in counts:
                if b <= p < e:
                    nptr += 1
                    allregs.add(regof[p])
            rows.append({"pc": doc["pc"], "name": doc.get("name", ""),
                         "base": f"0x{b:08x}", "len": f"0x{ln:x}",
                         "pointers": sum(n for p, n in counts.items()
                                         if b <= p < e),
                         "regs": "".join(sorted(allregs))})
        print(f"{doc['pc']}: {len(picks)} windows, {nptr} pointers, regs={''.join(sorted(allregs))}")
    outp = Path(a.out)
    outp.parent.mkdir(parents=True, exist_ok=True)
    outp.write_text("\n".join(watch_lines) + "\n", encoding="utf-8")
    print(f"derive_windows: {len({r['pc'] for r in rows if r['base'] != '-'})} PCs, "
          f"{len([r for r in rows if r['base'] != '-'])} windows -> {outp}")
    if a.csv:
        cp = Path(a.csv)
        cp.parent.mkdir(parents=True, exist_ok=True)
        with open(cp, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=["pc", "name", "base", "len",
                                              "pointers", "regs"])
            w.writeheader()
            w.writerows(rows)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())