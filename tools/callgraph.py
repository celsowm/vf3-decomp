#!/usr/bin/env python3
"""Call-graph v2 for VF3 SH-4 dumps (Ghidra Vf3DumpCode output).

SHC on SH-4 mostly calls via literal-pool + jsr @rN (BSR only reaches ±4KB).
This pass tracks register loads (mov.l/mov.w @(disp,PC)) with a 48-byte window,
ignores conditional branches (delayable odds) and normalizes Dreamcast P1
aliases (0x0Cxxxxxx -> 0x8Cxxxxxx).

Outputs:
  <dump>.calls.csv       caller_fn, callee_addr, call_site, mode(jsr/bsr)
  docs/re/hotspots.md    most-called targets with Ghidra names
"""
import bisect
import collections
import csv
import os
import re
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x8C010000
TEXT_LO, TEXT_HI = 0x8C010000, 0x8C200000


def load_dump(path):
    ins = []
    with open(path, "r", encoding="ascii", errors="replace") as f:
        for line in f:
            parts = line.split("\t", 3)
            if len(parts) < 3:
                continue
            addr = int(parts[0], 16)
            ins.append((addr, parts[1], parts[3] if len(parts) >= 4 else parts[2]))
    return ins


def load_funcs(path):
    rows = []
    with open(path) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    rows.sort()
    return rows


def func_of(func_rows, ents, addr):
    i = bisect.bisect_right(ents, addr) - 1
    if i >= 0 and func_rows[i][0] <= addr < func_rows[i][0] + max(func_rows[i][1], 1):
        return func_rows[i]
    return None


WRITE_RE = re.compile(r"(?:mov|mov\.[bwl]|movs|swap|extu|exts|add|sub|lds|lds\.l|fmov|fneg|fabs|fsub|fadd|xor|or|and|not|neg|shll|shlr|rotl|rotr|mova)\b.*?[,\s]r(\d+)\s*$", re.I)


def jsr_calls(ins, raw, func_rows, ents):
    lastload = {}   # reg -> (from_addr, loaded_value)
    edges = []
    unresolved = 0
    for addr, hexraw, txt in ins:
        if len(hexraw) < 4:
            continue
        w = int.from_bytes(bytes.fromhex(hexraw[:4]), "little")
        hi = w & 0xF000

        if hi == 0xD000:                       # mov.l @(disp,PC), rN
            rn = (w >> 8) & 0xF
            pool = ((addr + 4) & ~3) + (w & 0xFF) * 4
            off = pool - BASE
            if 0 <= off <= len(raw) - 4:
                val = struct.unpack_from("<I", raw, off)[0]
                lastload[rn] = (addr, val)
        elif hi == 0x9000:                     # mov.w @(disp,PC), rN
            rn = (w >> 8) & 0xF
            pool = (addr + 4) + (w & 0xFF) * 2
            off = pool - BASE
            if 0 <= off <= len(raw) - 2:
                v = struct.unpack_from("<h", raw, off)[0] & 0xFFFFFFFF
                lastload[rn] = (addr, v)
        elif (w & 0xF0FF) == 0x400B:           # jsr @Rn
            rn = (w >> 8) & 0xF
            rec = lastload.get(rn)
            if rec is not None:
                v = rec[1]
                if 0x0C000000 <= v <= 0x0FFFFFFF:
                    v |= 0x80000000
                if TEXT_LO <= v < TEXT_HI:
                    edges.append((addr, v, "jsr"))
                else:
                    unresolved += 1
            else:
                unresolved += 1
            # calls clobber caller-saved regs r0-r7
            for r in range(8):
                lastload.pop(r, None)
        elif hi == 0xB000:                     # bsr (direct +/-4KB)
            disp = w & 0xFFF
            if disp & 0x800:
                disp -= 0x1000
            edges.append((addr, addr + 4 + disp * 2, "bsr"))
            for r in range(8):
                lastload.pop(r, None)
        elif hi == 0xA000 or (w & 0xF0FF) in (0x402B, 0x0009):  # bra/rts
            lastload.clear()
        elif txt.strip().startswith("_"):      # delay-slot shadow (Ghidra)
            pass
        else:
            m = WRITE_RE.match(txt.strip())
            if m:
                lastload.pop(int(m.group(1)), None)
    return edges, unresolved


def main():
    prog = sys.argv[1] if len(sys.argv) > 1 else "1ST_READ"
    dump = os.path.join(REPO, "extract", "analysis", f"disasm_{prog}.unsc.bin.asm")
    raw = open(os.path.join(REPO, "extract", "exe", prog + ".unsc.bin"), "rb").read()
    funcs = load_funcs(os.path.join(REPO, "extract", "analysis", f"funcs_{prog}.unsc.bin.csv"))
    ents = [f[0] for f in funcs]

    ins = load_dump(dump)
    print(f"instructions: {len(ins)}")
    edges, unresolved = jsr_calls(ins, raw, funcs, ents)
    print(f"call edges: {len(edges)}    unresolved jsr sites: {unresolved}")

    # distinct (fn,target) pairs for names
    cnt = collections.Counter()
    for site, tgt, mode in edges:
        cf = func_of(funcs, ents, site)
        cnt[(cf[2] if cf else f"?{site:08X}", tgt)] += 1

    with open(dump.replace(".asm", ".calls.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["caller_fn", "call_site", "target", "mode"])
        for site, tgt, mode in sorted(edges):
            cf = func_of(funcs, ents, site)
            w.writerow([cf[2] if cf else "", f"0x{site:X}", f"0x{tgt:X}", mode])

    with open(dump.replace(".asm", ".hotrefs.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["target", "count"])
        for tgt, c in collections.Counter(t for _, t, _ in edges).most_common(2000):
            w.writerow([f"0x{tgt:X}", c])

    tgtName = {f[0]: f[2] for f in funcs}
    docs = os.path.join(REPO, "docs", "re")
    os.makedirs(docs, exist_ok=True)
    hot = collections.Counter(t for _, t, _ in edges)
    with open(os.path.join(docs, f"hotspots_{prog}.md"), "w", newline="\n") as d:
        d.write(f"# Most-called targets in {prog}\n\n")
        d.write("| rank | address | calls | fn name |\n|---|---|---|---|\n")
        for i, (t, c) in enumerate(hot.most_common(80)):
            d.write(f"| {i+1} | 0x{t:08X} | {c} | {tgtName.get(t, '(not a fn start)')} |\n")

    print("\ntop-20 callee targets:")
    for t, c in hot.most_common(20):
        print(f"  0x{t:08X}  x{c}  {tgtName.get(t,'?')}")


if __name__ == "__main__":
    main()
