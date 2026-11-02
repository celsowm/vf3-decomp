#!/usr/bin/env python3
"""aica_voice_regs.py - decode the AICA's channel registers the ARM7 wrote.

The reference's ARM observer recorded every memory access the ARM7 made
(`extract/analysis/audio_arm_state28_v2.json`).  Its "voice_register_writes"
are the writes into the AICA's register file (the ARM7's window at
0x00800000 + offset; the register file is 8 KiB, so the offset is the
address & 0x7FFF).

This tool replays those writes into the register file and decodes the fields,
the way the hardware does (the layout is the reference's `ChannelCommonData`,
a packed struct of 16-bit fields in 32-bit slots):

    +0x00  SA_hi:7 PCMS:2 LPCTL SSCTL :3 KYONB KYONEX
    +0x04  SA_low:16
    +0x08  LSA:16          +0x0C  LEA:16
    +0x10  AR:5 :1 D1R:5 D2R:5
    +0x14  RR:5 DL:5 KRS:4 LPSLNK
    +0x18  FNS:10 :1 OCT:4
    +0x1C  ALFOS:3 ALFOWS:2 PLFOS:3 PLFOWS:2 LFOF:5 LFORE
    +0x20  ISEL:4 IMXL:4
    +0x24  DIPAN:5 :3 DISDL:4
    +0x28  Q:5 LPOFF VOFF :1 TL:8
    +0x40  FD1R:5 :3 FAR:5      +0x44  FD2R:5 :3 FRR:5

    python tools/aica_voice_regs.py
    python tools/aica_voice_regs.py --json
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
DEFAULT_TRACE = REPO / "extract" / "analysis" / "audio_arm_state28_v2.json"

REG_SIZE = 0x8000        # the register file
SLOT_STRIDE = 0x80       # one channel slot
SLOTS = REG_SIZE // SLOT_STRIDE

# the word offsets inside a slot
W = {
    "ctl": 0x00, "sa_lo": 0x04, "lsa": 0x08, "lea": 0x0C,
    "aeg": 0x10, "rel": 0x14, "pitch": 0x18, "lfo": 0x1C,
    "isel": 0x20, "dipan": 0x24, "level": 0x28,
    "feg": 0x40, "feg2": 0x44,
}


def fields(word: int, name: str) -> dict:
    """The fields of one 32-bit slot, the hardware's bit layout."""
    if name == "ctl":
        return dict(sa_hi=word & 0x7F, pcms=(word >> 7) & 3, lpctl=(word >> 9) & 1,
                    ssctl=(word >> 10) & 1, kyonb=(word >> 14) & 1, kyonex=(word >> 15) & 1)
    if name == "sa_lo":
        return dict(sa_lo=word & 0xFFFF)
    if name in ("lsa", "lea"):
        return {name: word & 0xFFFF}
    if name == "aeg":
        return dict(ar=word & 0x1F, d1r=(word >> 6) & 0x1F, d2r=(word >> 11) & 0x1F)
    if name == "rel":
        return dict(rr=word & 0x1F, dl=(word >> 5) & 0x1F, krs=(word >> 10) & 0xF,
                    lpslnk=(word >> 14) & 1)
    if name == "pitch":
        return dict(fns=word & 0x3FF, oct=(word >> 11) & 0xF)
    if name == "lfo":
        return dict(alfos=word & 7, alfows=(word >> 3) & 3, plfos=(word >> 5) & 7,
                    plfows=(word >> 8) & 3, lfof=(word >> 10) & 0x1F, lfore=(word >> 15) & 1)
    if name == "isel":
        return dict(isel=word & 0xF, imxl=(word >> 4) & 0xF)
    if name == "dipan":
        return dict(dipan=word & 0x1F, disdl=(word >> 8) & 0xF)
    if name == "level":
        return dict(q=word & 0x1F, lpoff=(word >> 5) & 1, voff=(word >> 6) & 1,
                    tl=(word >> 8) & 0xFF)
    if name == "feg":
        return dict(fd1r=word & 0x1F, far=(word >> 8) & 0x1F)
    if name == "feg2":
        return dict(fd2r=word & 0x1F, frr=(word >> 8) & 0x1F)
    raise KeyError(name)


def update_rate(fns: int, oct_: int) -> int:
    """The reference's pitch derivation (sgc_if.cpp's UpdatePitch)."""
    rate = 1024 | fns
    if oct_ & 8:
        return rate >> (16 - oct_)
    return rate << oct_


def replay(records) -> bytearray:
    """The register file after the ARM7's writes."""
    reg = bytearray(REG_SIZE)
    for r in records:
        addr = r["address"] & 0x7FFF
        size = r["size"]
        value = r["value"]
        for i in range(size):
            reg[addr + i] = (value >> (8 * i)) & 0xFF
    return reg


def channels(reg: bytearray) -> dict:
    """Every slot the ARM7 touched, with its fields decoded."""
    out = {}
    for slot in range(SLOTS):
        base = slot * SLOT_STRIDE
        words = {}
        for name, off in W.items():
            words[name] = int.from_bytes(reg[base + off:base + off + 4], "little")
        touched = any(words[n] for n in W)
        if not touched:
            continue
        flat = {}
        for name in W:
            flat.update(fields(words[name], name))
        flat["slot"] = slot
        flat["sa"] = (flat["sa_hi"] << 16) | flat["sa_lo"]
        flat["rate"] = update_rate(flat["fns"], flat["oct"])
        flat["hz"] = 44100.0 * flat["rate"] / 1024.0
        out[slot] = flat
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n")[0])
    ap.add_argument("--trace", type=Path, default=DEFAULT_TRACE)
    ap.add_argument("--json", action="store_true", help="print the table as JSON")
    args = ap.parse_args()
    if not args.trace.is_file():
        print(f"aica_voice_regs: {args.trace} missing")
        return 2
    data = json.loads(args.trace.read_text())
    recs = data["voice_register_writes"]
    chans = channels(replay(recs))
    if args.json:
        print(json.dumps(chans, indent=2))
        return 0

    print(f"{len(recs)} register writes, {len(chans)} channel slots touched\n")
    head = ("slot", "pcms", "sa", "lsa", "lea", "ar", "d1r", "d2r", "rr", "dl",
            "fns", "oct", "rate", "hz", "tl", "dipan", "disdl", "kyon")
    print("  ".join("%-6s" % h for h in head))
    for slot in sorted(chans):
        c = chans[slot]
        row = (slot, c["pcms"], "0x%06x" % c["sa"], "0x%04x" % c["lsa"], "0x%04x" % c["lea"],
               c["ar"], c["d1r"], c["d2r"], c["rr"], c["dl"], c["fns"], c["oct"],
               c["rate"], "%.0f" % c["hz"], c["tl"], c["dipan"], c["disdl"],
               c["kyonb"] | (c["kyonex"] << 1))
        print("  ".join("%-6s" % v for v in row))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
