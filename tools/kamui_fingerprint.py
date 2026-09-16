#!/usr/bin/env python3
"""Kamui function fingerprint scanner.

Corpus: Kamui SDK sample link maps (*.map, Hitachi LNK 'EXTERNALLY DEFINED
SYMBOLS LIST') paired with their ELF binaries (Hitachi ELF sections PSG/P).
For every ENT symbol we take the bytes from the ELF at that address up to the
next symbol (capped) as its byte fingerprint.

Target: a descrambled retail binary (1ST_READ.unsc.bin, loaded at 0x8C010000).

v1 matcher: exact byte match of the first N bytes (default 24) of each
function; reported as (target_addr, name, matched_bytes). Address-dependent
instructions (bsr/bra/mov.l @pc targets) limit exactness - good enough to
seed names for the leaf/internal Kamui routines.

Outputs: extract/analysis/kamui_matches.csv, docs/kamui_matches.md
"""
import csv
import os
import re
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
KAMUI_SDK = os.path.join(REPO, "tools", "kamui", "SDK", "KAMUI2", "SAMPLE")
KMUTIL = os.path.join(REPO, "tools", "kamui", "SOURCE", "KMUTIL")
TARGET_BASE = 0x8C010000
MIN_FUNC = 24          # don't fingerprint tiny stubs
MATCH_PREFIX = 24      # bytes compared for a hit


def parse_map(path):
    """Return (elf_name, {symbol: (addr, type)})."""
    elf_name = None
    syms = {}
    with open(path, "rb") as f:
        text = f.read().decode("ascii", "replace")
    m = re.search(r"(?im)^\s*output\s+(\S+\.elf)\s*$", text)
    if m:
        elf_name = m.group(1).replace("/", os.sep).split(os.sep)[-1]
    for mm in re.finditer(
            r"(?m)^(_?[A-Za-z_][A-Za-z0-9_]*)\s+H'([0-9A-Fa-f]{8})\s+(ENT|DAT)", text):
        name, addr, typ = mm.group(1), int(mm.group(2), 16), mm.group(3)
        syms[name] = (addr, typ)
    return elf_name, syms


def elf_sections(path):
    """Return {name: (addr, offset, size)} for SH-allocated sections + full data."""
    data = open(path, "rb").read()
    if data[:4] != b"\x7fELF" or data[4] != 1:
        return data, {}
    shoff = struct.unpack_from("<I", data, 0x20)[0]
    shentsize = struct.unpack_from("<H", data, 0x2E)[0]
    shnum = struct.unpack_from("<H", data, 0x30)[0]
    shstrndx = struct.unpack_from("<H", data, 0x32)[0]
    str_off = struct.unpack_from("<I", data, shoff + shstrndx * shentsize + 16)[0]
    out = {}
    for i in range(shnum):
        base = shoff + i * shentsize
        noff, typ, flags, addr, off, size = struct.unpack_from("<6I", data, base + 0)
        end = data.index(0, str_off + noff)
        name = data[str_off + noff:end].decode("ascii", "replace")
        if flags & 0x2 and size and typ == 1:  # SHF_ALLOC, PROGBITS
            out[name] = (addr, off, size)
    return data, out


def build_corpus():
    corpus = {}  # name -> bytes (longest found across samples)
    for root, _dirs, files in os.walk(KAMUI_SDK):
        for f in files:
            if not f.lower().endswith(".map"):
                continue
            mpath = os.path.join(root, f)
            elf_name, syms = parse_map(mpath)
            if not elf_name or not syms:
                continue
            epath = os.path.join(root, elf_name)
            if not os.path.isfile(epath):
                # some samples store the elf in ../../BINARIES
                alt = os.path.join(REPO, "tools", "kamui", "BINARIES", elf_name)
                epath = alt if os.path.isfile(alt) else None
            if not epath:
                continue
            data, secs = elf_sections(epath)
            code_secs = [(a, o, s) for n, (a, o, s) in secs.items()
                         if n in ("P", "P1", "P2") or n.startswith("P")]
            if not code_secs:
                continue

            def addr_to_off(addr):
                for a, o, s in code_secs:
                    if a <= addr < a + s:
                        return o + (addr - a)
                return None

            ents = sorted((addr, name) for name, (addr, typ) in syms.items()
                          if typ == "ENT" and addr_to_off(addr) is not None)
            for i, (addr, name) in enumerate(ents):
                off = addr_to_off(addr)
                nxt = ents[i + 1][0] if i + 1 < len(ents) and \
                    addr_to_off(ents[i + 1][0]) is not None else None
                size = (nxt - addr) if nxt and nxt > addr else 0x80
                size = min(size, 0x400)
                blob = data[off:off + size]
                if len(blob) >= MIN_FUNC and (name not in corpus or
                                              len(blob) > len(corpus[name])):
                    corpus[name] = blob
    return corpus


def norm_word(w):
    """Mask address-dependent operand fields of an SH-4 instruction word."""
    hi = w & 0xF000
    if hi in (0xA000, 0xB000):                 # BRA/BSR disp12
        return hi
    if hi in (0x9000, 0xD000):                 # MOV.W/MOV.L @(disp,PC)
        return hi | (w & 0x0F00)
    if hi == 0xC000 and (w & 0x0F00) == 0x0700:  # MOVA @(disp,PC),R0
        return 0xC700
    if hi == 0x8000 and (w & 0x0F00) in (0x0100, 0x0300, 0x0900, 0x0B00):
        return w & 0xFF00                       # BT/BF/BT.S/BF.S disp8
    if (w & 0xF0FF) in (0x0023, 0x0003):       # BRAF/BSRF Rm
        return w & 0xF0FF
    return w


def normalize(blob):
    out = bytearray(len(blob))
    for i in range(0, len(blob) - 1, 2):
        w = norm_word(blob[i] | (blob[i + 1] << 8))
        out[i] = w & 0xFF
        out[i + 1] = w >> 8
    return bytes(out)


NORM_PREFIX = 48


def main():
    target_path = sys.argv[1] if len(sys.argv) > 1 else \
        os.path.join(REPO, "extract", "exe", "1ST_READ.unsc.bin")
    target = open(target_path, "rb").read()
    corpus = build_corpus()
    print(f"corpus: {len(corpus)} named functions")

    exact_idx = {}
    norm_idx = {}
    for name, blob in corpus.items():
        exact_idx.setdefault(blob[:MATCH_PREFIX], []).append((name, blob))
        if len(blob) >= NORM_PREFIX:
            norm_idx.setdefault(normalize(blob[:NORM_PREFIX]), []).append((name, blob))

    matches = []
    n = len(target)
    for pos in range(0, n - NORM_PREFIX, 2):
        key = target[pos:pos + MATCH_PREFIX]
        hits = exact_idx.get(key)
        if hits:
            name, blob = max(hits, key=lambda t: len(t[1]))
            span = len(blob)
            full = target[pos:pos + span] == blob
            matches.append((pos, name, span if full else -1))
            continue
        nkey = normalize(target[pos:pos + NORM_PREFIX])
        h = norm_idx.get(nkey)
        if h:
            name, blob = h[0]
            matches.append((pos, name + " [norm]", 0))

    matches.sort()
    outcsv = os.path.join(REPO, "extract", "analysis")
    os.makedirs(outcsv, exist_ok=True)
    with open(os.path.join(outcsv, "kamui_matches.csv"), "w", newline="") as c:
        w = csv.writer(c)
        w.writerow(["addr", "name", "span"])
        for pos, name, span in matches:
            w.writerow([f"0x{TARGET_BASE + pos:08X}", name, span])

    with open(os.path.join(REPO, "docs", "kamui_matches.md"), "w", newline="\n") as d:
        d.write("# Kamui fingerprint matches in 1ST_READ\n\n")
        d.write(f"Corpus: {len(corpus)} functions from Kamui SDK sample maps/ELFs. "
                f"Matches: {len(matches)} (target base 0x{TARGET_BASE:08X}).\n\n")
        d.write("| 1ST_READ address | name | span |\n|---|---|---|\n")
        for pos, name, span in matches:
            d.write(f"| 0x{TARGET_BASE + pos:08X} | {name} | {span if span > 0 else 'prefix-only'} |\n")

    full = sum(1 for m in matches if m[2] > 0)
    print(f"matches: {len(matches)} total, {full} full-body -> docs/kamui_matches.md")


if __name__ == "__main__":
    main()
