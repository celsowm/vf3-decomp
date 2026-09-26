#!/usr/bin/env python3
"""sh4_resolve.py — resolve dynamic jsr/bsrf targets via intra-block value flow.

sh4_calls.py reports every `jsr @Rn` / `bsrf` as an opaque dyn site, which
kills closure for ~1650 functions. But most game dynamic calls are
statically computable idioms:
  mov.l @(disp,PC),Rn   ; Rn = literal (often a fixed RAM vector)
  mova @(disp,PC),Rn    ; Rn = code address (+ add/or segment-bit flips)
  mov #imm,Rn ; mov Rm,Rn ; add/or Rm,Rn

For each dyn site this tool scans BACKWARD within the straight-line run
(aborts on any branch/call/return word: no joins, single path, exact),
forward-simulates the target register, then checks no other branch in the
function targets inside (def, site] (which would admit a second path with
different values). Classes:
  STATIC <entry>  code-alias value mapping into a baseline function
                  (0x8C/0xAC high, or 0x0C-high alias of image code)
  FIXED <addr>    known non-code target (e.g. RAM routine like 0x0C09553C)
  UNKNOWN         anything else (true dispatch, joins, long flows)

Usage: python tools/sh4_resolve.py [--out extract/analysis/sh4_resolved.csv]
Reads extract/analysis/sh4_calls.csv + the image. port_plan.py consumes it.
"""
from __future__ import annotations

import argparse
import bisect
import csv
import struct
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
AN = REPO / "extract" / "analysis"
IMG = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
BASE = 0x8C010000


def s12(v: int) -> int:
    return v - 0x1000 if v & 0x800 else v


def s8(v: int) -> int:
    return v - 0x100 if v & 0x80 else v


def rd16(data: bytes, pc: int):
    off = pc - BASE
    if off < 0 or off + 2 > len(data):
        return None
    return struct.unpack_from("<H", data, off)[0]


def is_flow(w: int) -> bool:
    """Any control-transfer / return / call / trap word: block boundary."""
    if w & 0xF000 in (0xA000, 0xB000, 0x8000):
        return True
    if w & 0xF0FF in (0x400B, 0x402B):
        return True
    if (w & 0xF000) == 0x4000 and (w & 0xF) == 0x3:
        return True                          # jsr @@(d8,Rn): dynamic
    if w & 0xF00F == 0x0003:
        return True
    if w in (0x000B, 0x002B, 0xC300, 0x0023):
        return True                      # rts/rte/trapa/bsrf-range/sleep-ish
    return False


def branch_targets(data: bytes, lo: int, hi: int) -> set:
    """All static branch targets inside [lo, hi) (bra/bf/bt only)."""
    out = set()
    pc = lo
    while pc < hi:
        w = rd16(data, pc)
        if w is None:
            break
        if w & 0xF000 == 0xA000:
            out.add(pc + 4 + s12(w & 0xFFF) * 2)
        elif w & 0xF000 == 0x8000:
            out.add(pc + 4 + s8(w & 0xFF) * 2)
        pc += 2
    return out


def writes_reg(w: int):
    """(dst_reg, kind) for simulated ops, else None. Kinds: def / clobber."""
    if w & 0xF000 in (0xD000, 0x9000, 0xC000):
        return ((w >> 8) & 0xF, 'def')   # mov.l / mov.w / mova
    if w & 0xF000 == 0xE000:
        return ((w >> 8) & 0xF, 'def')   # mov #imm
    if w & 0xF000 == 0x6000 and w & 0xF == 0x3:
        return (w & 0xF, 'def')          # mov Rm,Rn
    if w & 0xF000 in (0x3000, 0x2000):
        return (w & 0xF, 'def')          # add / or Rm,Rn (need src known)
    # any other GPR write -> clobber (loads, alu, mac, shifts, stc...)
    if w & 0xF000 == 0x6000 and w & 0xF == 0x3:
        return ((w >> 8) & 0xF, 'clobber')   # (handled exactly in simulate)
    if w & 0xF000 in (0x5000, 0x6000, 0x7000, 0x4000, 0x0000, 0x1000):
        return ((w >> 8) & 0xF, 'clobber')   # over-approx: safe direction
    return None


def simulate(data: bytes, words: list, reg: int):
    """Forward-simulate `words` (list of (pc, w)); return value or None."""
    UNK = object()
    vals = [UNK] * 16

    def val(r):
        return vals[r]

    for pc, w in words:
        if w & 0xF000 == 0xD000:          # mov.l @(disp,PC),Rn (u32 literal)
            n = (w >> 8) & 0xF
            a = ((pc + 4) & ~3) + (w & 0xFF) * 4
            off = a - BASE
            if off < 0 or off + 4 > len(data):
                return None
            vals[n] = struct.unpack_from("<I", data, off)[0]
        elif w & 0xF000 == 0x9000:        # mov.w @(disp,PC),Rn (SIGNED 16)
            n = (w >> 8) & 0xF
            a = pc + 4 + (w & 0xFF) * 2
            off = a - BASE
            if off < 0 or off + 2 > len(data):
                return None
            v = struct.unpack_from("<H", data, off)[0]
            vals[n] = v - 0x10000 if v & 0x8000 else v
        elif w & 0xF000 == 0xC000:        # mova @(disp,PC),R0 (always R0!)
            vals[0] = ((pc + 4) & ~3) + (w & 0xFF) * 4
        elif w & 0xF000 == 0xE000:        # mov #imm,Rn (signed 8)
            n = (w >> 8) & 0xF
            v = w & 0xFF
            vals[n] = v - 0x100 if v & 0x80 else v
        elif w & 0xF00F == 0x6003:            # mov Rm,Rn (exact)
            m, n = (w >> 4) & 0xF, (w >> 8) & 0xF
            vals[n] = vals[m]
        elif w & 0xF0FF == 0x300C:            # add Rm,Rn (exact; n is hi)
            m, n = (w >> 4) & 0xF, (w >> 8) & 0xF
            if vals[m] is UNK or vals[n] is UNK:
                return None
            vals[n] = (vals[n] + vals[m]) & 0xFFFFFFFF
        elif w & 0xF0FF == 0x200B:            # or Rm,Rn (exact; n is hi)
            m, n = (w >> 4) & 0xF, (w >> 8) & 0xF
            if vals[m] is UNK or vals[n] is UNK:
                return None
            vals[n] = vals[n] | vals[m]
        else:
            wr = writes_reg(w)
            if wr is not None:
                vals[wr[0]] = UNK
    v = vals[reg]
    return None if v is UNK else (v & 0xFFFFFFFF)


def resolve(data, funcs, starts, entry, size, site, word):
    reg = (word >> 8) & 0xF
    # backward straight-run collection (cap 64 words)
    run = []
    pc = site - 2
    for _ in range(64):
        if pc < entry:
            break
        w = rd16(data, pc)
        if w is None or is_flow(w):
            break
        run.append((pc, w))
        pc -= 2
    run.reverse()
    if not run:
        return ('UNKNOWN', None, 'empty-run')
    # interference: any static branch in the function targeting (def, site]
    lo, hi = entry, entry + size + 256
    tgts = branch_targets(data, lo, hi)
    first = run[0][0]
    if any(first < t <= site for t in tgts):
        return ('UNKNOWN', None, 'join-in-run')
    v = simulate(data, run, reg)
    if v is None:
        return ('UNKNOWN', None, 'untracked')
    # classify. KEY alias result (2026-09-26, proven by RAM-dump/image
    # cross-check at 0x0C09553C): the game addresses image bytes through
    # the 0x0C P0 alias, so ANY 0x8C/0xAC/0x0C-high value whose canonical
    # P1 address lies in the image byte range is a STATIC image edge —
    # even with no Ghidra function containing it (gap code).
    hib = v >> 24
    img_lo, img_hi = BASE, BASE + len(data)
    if hib in (0x8C, 0xAC, 0x0C):
        canon = 0x8C000000 | (v & 0xFFFFFF)
        if img_lo <= canon < img_hi:
            i = bisect.bisect_right(starts, canon) - 1
            if i >= 0:
                e, s = funcs[i]
                if canon < e + s:
                    return ('STATIC', e, '0x%08X' % v)
            return ('STATIC', canon, '0x%08X' % v)
        return ('FIXED', v, '0x%08X' % v)
    if v >= 0x0C000000:
        return ('FIXED', v, '0x%08X' % v)
    return ('UNKNOWN', None, 'small-0x%08X' % v)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="extract/analysis/sh4_resolved.csv")
    a = ap.parse_args()
    data = IMG.read_bytes()
    funcs = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"])))
    funcs.sort()
    starts = [e for e, _ in funcs]
    sizes = dict(funcs)
    rows = []
    n_static = n_fixed = n_unk = 0
    with open(AN / "sh4_calls.csv", newline="") as f:
        for r in csv.DictReader(f):
            ent = int(r["entry"], 16)
            for d in r["dyn_sites"].split():
                site = int(d, 16)
                w = rd16(data, site)
                if w is None:
                    rows.append({"caller": r["entry"], "site": d,
                                 "class": "UNKNOWN", "target": "",
                                 "note": "oob"})
                    n_unk += 1
                    continue
                cls, tgt, note = resolve(data, funcs, starts, ent,
                                         sizes[ent], site, w)
                if cls == 'STATIC':
                    n_static += 1
                elif cls == 'FIXED':
                    n_fixed += 1
                else:
                    n_unk += 1
                rows.append({"caller": r["entry"], "site": d, "class": cls,
                             "target": ("0x%08X" % tgt) if tgt is not None else "",
                             "note": note})
    outp = Path(a.out)
    with open(outp, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["caller", "site", "class",
                                          "target", "note"])
        w.writeheader()
        w.writerows(rows)
    print(f"sh4_resolve: {outp} ({len(rows)} sites: {n_static} STATIC, "
          f"{n_fixed} FIXED, {n_unk} UNKNOWN)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
