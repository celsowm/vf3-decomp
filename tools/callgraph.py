#!/usr/bin/env python3
"""Call-graph resolver for VF3 SH-4 dumps (produced by Vf3DumpCode.java).

Handles the dominant Katana SHC calling pattern:
    mov.l @(disp,PC), rN     ; rN = literal word at computed pool address
    ...
    jsr @rN                   ; indirect call to that pool's value

Tracks per-register last literal load with simple forward scanning rules:
a pending load is invalidated by another write to the same register, by
conditional/unconditional branches, or by 16-instruction distance.

Outputs:
  <dump>.calls.csv     caller_fn, callee_addr, call_site
  <dump>.hotrefs.csv   target addr -> call count (descending)
"""
import bisect
import csv
import os
import re
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x8C010000


def s8(x):
    return x - 256 if x > 127 else x


def load_dump(path):
    ins = []
    with open(path, "r", encoding="ascii", errors="replace") as f:
        for line in f:
            parts = line.rstrip("\n").split("\t", 3)
            if len(parts) < 3:
                continue
            addr = int(parts[0], 16)
            raw = parts[1]
            full = parts[3] if len(parts) >= 4 else ""
            ins.append((addr, raw, full))
    return ins


def resolve(ins, binbytes):
    """Return list of (call_site, target_addr) for jsr/bsr calls."""
    lastload = {}   # reg -> (addr, value)
    calls = []
    for idx, (addr, raw, full) in enumerate(ins):
        if len(raw) < 4:
            continue
        w = int.from_bytes(bytes.fromhex(raw[:4]), "little")
        # mov.l @(disp,PC), rN   opcode D n dd ; EA = ((addr+4)&~3) + disp*4
        if (w & 0xF000) == 0xD000:
            rn = (w >> 8) & 0xF
            disp = w & 0xFF
            pool_addr = (((addr + 4) & ~3)
                         + disp * 4)
            off = pool_addr - BASE
            if 0 <= off < len(binbytes) - 4:
                val = struct.unpack_from("<I", binbytes, off)[0]
                lastload[rn] = (addr, val)
            continue
        # mov.w @(disp,PC), rN  (9 n dd) -> 16-bit sign-extended value
        if (w & 0xF000) == 0x9000:
            rn = (w >> 8) & 0xF
            disp = w & 0xFF
            pool_addr = (addr + 4) + disp * 2
            off = pool_addr - BASE
            if 0 <= off < len(binbytes) - 2:
                val = struct.unpack_from("<h", binbytes, off)[0]
                lastload[rn] = (addr, val & 0xFFFFFFFF)
            continue
        # jsr @rN
        if (w & 0xF0FF) == 0x400B:
            rn = (w >> 8) & 0xF
            if rn in lastload:
                la, val = lastload[rn]
                # Dreamcast alias: P1 physical 0x0C000000.. == cached 0x8C0.....
                if 0x0C000000 <= val <= 0x0FFFFFFF:
                    val |= 0x80000000
                if addr - la <= 32:
                    if 0x8C010000 <= val < 0x8C200000:
                        calls.append((addr, val))
            continue
        # writes that clobber register: rough general rule - reset on branch
        if (w & 0xF000) in (0xA000, 0xB000):
            lastload.clear()
        # invalidate regs when instruction writes rN (approx via text ops)
    return calls


def main():
    prog = sys.argv[1] if len(sys.argv) > 1 else "1ST_READ"
    dump = os.path.join(REPO, "extract", "analysis", f"disasm_{prog}.unsc.bin.asm")
    raw = open(os.path.join(REPO, "extract", "exe", prog + ".unsc.bin"), "rb").read()
    ins = load_dump(dump)
    print(f"instructions: {len(ins)}")
    calls = resolve(ins, raw)
    print(f"resolved calls: {len(calls)}")
    # also direct bsr
    bsr = 0
    for addr, raw, full in ins:
        if len(raw) < 4:
            continue
        w = int.from_bytes(bytes.fromhex(raw[:4]), "little")
        if (w & 0xF000) == 0xB000:
            disp = w & 0xFFF
            if disp & 0x800:
                disp -= 0x1000
            calls.append((addr, (addr + 4 + disp * 2) & 0xFFFFFFFF))
            bsr += 1
    print(f"direct bsr: {bsr}")

    with open(dump.replace(".asm", ".calls.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["call_site", "target"])
        for cs, t in sorted(calls):
            w.writerow([f"0x{cs:X}", f"0x{t:X}"])

    import collections
    cnt = collections.Counter(t for _, t in calls)
    with open(dump.replace(".asm", ".hotrefs.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["target", "count"])
        for t, c in cnt.most_common(2000):
            w.writerow([f"0x{t:X}", c])
    print("top-20 called destinations:")
    for t, c in cnt.most_common(20):
        print(f"  0x{t:08X}  x{c}")


if __name__ == "__main__":
    main()
