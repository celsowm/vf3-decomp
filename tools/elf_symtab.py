#!/usr/bin/env python3
"""elf_symtab.py — name SDK-matched game functions from SH-4 ELF symtabs.

Measures (and optionally emits) how many union-corpus full-body matches can
be bound to a real symbol name: for each match, locate the containing carved
region, parse the ELF program/section headers inside the region, translate
the matched file offset to a virtual address, and look up the STT_FUNC
symbol covering it.

Only whole-file ELF regions (manifest source without a "+0x" suffix) are
considered; embedded slabs lack file-header context.

Usage:
  python tools/elf_symtab.py [--matches extract/analysis/sdk_union_matches.csv]
      [--corpus extract/analysis/sdk_corpus/sdk8eu] [--out extract/analysis/sdk_union_names.csv]
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from pathlib import Path


def u16(d, o):
    return struct.unpack_from("<H", d, o)[0]


def u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def parse_elf(blob: bytes, base: int):
    """Return (segments, symbols) or None. segments = [(file_off, vaddr,
    filesz)]. symbols = [(name, value, size, bind, type)]."""
    if len(blob) - base < 52 or blob[base:base + 4] != b"\x7fELF":
        return None
    if blob[base + 4] != 1 or blob[base + 5] != 1:
        return None
    try:
        if u16(blob, base + 18) != 42:  # EM_SH
            return None
        phoff, shoff = u32(blob, base + 28), u32(blob, base + 32)
        phentsize, phnum = u16(blob, base + 42), u16(blob, base + 44)
        shentsize, shnum, shstrndx = (u16(blob, base + 46),
                                      u16(blob, base + 48),
                                      u16(blob, base + 50))
    except struct.error:
        return None
    segs = []
    for i in range(phnum):
        o = base + phoff + i * phentsize
        if o + 32 > len(blob):
            break
        p_type, p_off, p_vaddr = u32(blob, o), u32(blob, o + 4), u32(blob, o + 8)
        p_filesz = u32(blob, o + 16)
        if p_type == 1 and p_filesz:
            segs.append((p_off, p_vaddr, p_filesz))
    if shoff == 0 or shnum == 0 or shentsize < 40:
        return segs, []
    try:
        s0 = base + shoff + shstrndx * shentsize
        str_off, str_size = u32(blob, s0 + 16), u32(blob, s0 + 20)
    except struct.error:
        return segs, []
    syms = []
    for i in range(shnum):
        o = base + shoff + i * shentsize
        if o + 40 > len(blob):
            break
        sh_type = u32(blob, o + 4)
        if sh_type != 2:  # SHT_SYMTAB
            continue
        s_off, s_size = u32(blob, o + 16), u32(blob, o + 20)
        l_off = u32(blob, o + 24)
        for j in range(0, s_size, 16):
            p = base + s_off + j
            if p + 16 > len(blob):
                break
            st_name, st_value = u32(blob, p), u32(blob, p + 4)
            st_size, st_info = u32(blob, p + 8), blob[p + 12]
            if (st_info & 0xF) != 2 or st_size == 0:  # STT_FUNC
                continue
            q = base + l_off + st_name
            end = blob.find(b"\x00", q)
            if q >= len(blob) or end < 0:
                continue
            syms.append((blob[q:end].decode("ascii", "replace"),
                         st_value, st_size, st_info >> 4, st_info & 0xF))
    return segs, syms


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--matches",
                    default="extract/analysis/sdk_union_matches.csv")
    ap.add_argument("--corpus",
                    default="extract/analysis/sdk_corpus/sdk8eu")
    ap.add_argument("--out",
                    default="extract/analysis/sdk_union_names.csv")
    a = ap.parse_args()

    blob = Path(a.corpus).with_suffix(".bin").read_bytes()
    regions = []
    man = Path(a.corpus).with_suffix(".csv")
    if man.exists():
        for r in csv.DictReader(open(man)):
            regions.append((int(r["blob_off"]), int(r["size"]),
                            r["source"], r.get("kind", "")))
    regions.sort()

    rows = list(csv.DictReader(open(a.matches)))
    full = [r for r in rows if int(r["span_words"]) * 2 >= int(r["size"])]
    named, skipped, nosym = 0, 0, 0
    out = []
    cache: dict[int, object] = {}
    for r in full:
        moff = int(r["blob_off"], 16)
        reg = None
        for s, sz, src, kind in regions:
            if s <= moff < s + sz:
                reg = (s, sz, src, kind)
                break
        if reg is None or "+" in reg[2].split("/")[-1] and "+0x" in reg[2]:
            skipped += 1
            continue
        s, sz, src, kind = reg
        if s not in cache:
            cache[s] = parse_elf(blob, s)
        parsed = cache[s]
        if not parsed:
            skipped += 1
            continue
        segs, syms = parsed
        foff = moff - s
        va = None
        for p_off, p_vaddr, p_filesz in segs:
            if p_off <= foff < p_off + p_filesz:
                va = p_vaddr + (foff - p_off)
                break
        if va is None or not syms:
            nosym += 1
            continue
        hit = [nm for nm, v, z, _, _ in syms if v <= va < v + z]
        if hit:
            named += 1
            out.append({"entry": r["entry"], "size": r["size"],
                        "symbol": hit[0], "region": src, "vaddr": f"0x{va:x}"})
        else:
            nosym += 1
    with open(a.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "size", "symbol",
                                          "region", "vaddr"])
        w.writeheader()
        w.writerows(out)
    print(f"elf_symtab: full matches {len(full)}: named {named}, "
          f"region-unusable {skipped}, no-symtab/symbol {nosym} -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
