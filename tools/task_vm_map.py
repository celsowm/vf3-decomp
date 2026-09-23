#!/usr/bin/env python3
"""tools/task_vm_map.py -- static field-usage map of the task-VM r14 struct.

The fight engine's r14 task context (trace-pinned at 0x0CBEFBE0 during a
fight frame) is only reachable through struct-field indirection — there are
no literal pointers to it in the ROM. This pass enumerates every
`mov.[blw] @(disp,r14),rN` / reverse store + `jsr @r14` site inside the
task/fight function regions (fight_f_8c0796f4, the fight ring
0x8C073C00..0x8C074900, the dispatch neighbourhood 0x8C090000.. and any fn
whose name starts with task_run_ / fight_f_ in the funcs CSV) and emits a
per-offset usage table with width+pc+context.

Writes extract/analysis/task_vm_map.csv + prints summary.

Usage: tools/.venv/Scripts/python tools/task_vm_map.py
"""
from __future__ import annotations

import csv
import re
import struct
import sys
from pathlib import Path

BASE = 0x8C010000
BIN = Path("extract/exe/1ST_READ.unsc.bin")
FUNCS = Path("extract/analysis/funcs_1ST_READ.unsc.bin.csv")
OUTD = Path("extract/analysis/task_vm_map.csv")

from capstone import CS_ARCH_SH, CS_MODE_LITTLE_ENDIAN, CS_MODE_SH4, Cs

md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)

data = BIN.read_bytes()

rows = []
with FUNCS.open(encoding="utf-8", errors="replace") as f:
    for r in csv.DictReader(f):
        try:
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
        except Exception:
            continue

r14_pat = re.compile(r"@\((\d+),\s*r14\)")
wr_pat = re.compile(r"mov\.(b|w|l)\s+(?:r|fr|dr)\d+,\s*@\((\d+),\s*r14\)")
rd_pat = re.compile(r"mov\.(b|w|l)\s+@\((\d+),\s*r14\)," +
                    r"\s*(?:r|fr|dr)\d+")

def scan_func(addr: int, size: int, name: str):
    end = addr + size
    p = addr
    while p < end:
        o = p - BASE
        if not (0 <= o < len(data) - 1):
            break
        ins = list(md.disasm(data[o:o + 2], p))
        if not ins:
            p += 2
            continue
        i = ins[0]
        t = f"{i.mnemonic} {i.op_str}"
        hit = False
        off = None
        mrid = None
        wid = None
        if "r14" in t:
            if "jsr @r14" in t or "@r14+" in t:
                hit = True
                mrid = i.mnemonic
            else:
                mr = rd_pat.search(t)
                if mr:
                    hit = True
                    off = int(mr.group(2), 16)
                    mrid = "rd"
                mw = wr_pat.search(t)
                if mw:
                    hit = True
                    off = int(mw.group(2), 16)
                    mrid = "wr"
        if hit:
            yield (p, off, mrid or i.mnemonic, f"{i.mnemonic} {i.op_str}")
        p += 2


def fn_for(addr, rows_by_entry):
    import bisect
    entries = [r[0] for r in rows_by_entry]
    j = bisect.bisect_right(entries, addr) - 1
    if j >= 0:
        e, s, n = rows_by_entry[j]
        if e <= addr < e + s:
            return (e, s, n)
    return None


rows.sort()
seen = set()
out = []

REGIONS = [
    # explicit regions we know are hot for task dispatch
    (0x8C073C00, 0x8C074900, "ring"),
    (0x8C079400, 0x8C079A00, "task_run_C"),
    (0x8C079A00, 0x8C079C80, "task_run_B"),
    (0x8C090000, 0x8C096000, "dispatch_block_low"),
    (0x8C0B1A00, 0x8C0B2700, "scene_walker"),
]
# any fn with task_ / fight_ in name gets its body scanned too
for entry, size, name in rows:
    ln = name.lower()
    if name.startswith(("task_", "fight_f_", "cand_task", "cand_scene",
                        "scene_")) or "dispatch" in ln:
        REGIONS.append((entry, entry + size, name))

for lo, hi, tag in REGIONS:
    lo2 = max(lo, BASE)
    hi2 = min(hi, BASE + len(data))
    for item in scan_func(lo2, hi2 - lo2, tag):
        pc, off, mnem, ctx = item
        key = (pc, off, mnem)
        if key in seen:
            continue
        seen.add(key)
        e = fn_for(pc, rows)
        out.append({
            "site": hex(pc), "fn": f"0x{e[0]:08X}:{e[2]}" if e else "",
            "off_in_r14": ("" if off is None else f"0x{off:02X}"),
            "mnem": mnem, "ctx": ctx, "region": tag,
        })

OUTD.write_text("")
with OUTD.open("w", newline="", encoding="utf-8") as f:
    w = csv.DictWriter(f, fieldnames=["site", "fn", "off_in_r14",
                                      "mnem", "ctx", "region"])
    w.writeheader()
    w.writerows(out)

from collections import Counter
offcount = Counter(r["off_in_r14"] for r in out if r["off_in_r14"])
print(f"total r14-field sites: {len(out)}; unique offsets: {len(offcount)}")
print("top offsets:")
for off, n in offcount.most_common(20):
    print(f"  {off}  x{n}")
print(f"-> {OUTD}")
return_code = 0
if __name__ == "__main__":
    raise SystemExit(return_code)
