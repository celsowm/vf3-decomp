#!/usr/bin/env python3
"""snd_walkback.py — M56 pool-walkback: attribute mpdrv_* endpoint bodies.

Scans the true image for literal-pool dwords pointing into the libsnd
string cluster 0x8C0CD600..0x8C0CD9FF, then walks back to referencing
mov.l @(disp,PC) owners in 0x8C035Exx..0x8C0368xx.

Outputs extract/analysis/snd_walkback.csv:
  string_addr,string_name,pool_addr,owner_site,owner_fn
Verification: owner_fn must fall in sound-command block; cross-check with
VF3_WATCH pc hits across vf3_6->fight kit write.
"""
from __future__ import annotations
import csv
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMG = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
FUNCS = REPO / "extract" / "analysis" / "funcs_1ST_READ.unsc.bin.csv"
OUT = REPO / "extract" / "analysis" / "snd_walkback.csv"
BASE = 0x8C010000

STRINGS = {
    0x8C0CD540: "libsnd0.82",
    0x8C0CD874: "mpdrv_set_dreq_ns",
    0x8C0CD8A8: "mpdrv_set_dreset_ns",
    0x8C0CD900: "mpdrv_set_hreset_ns",
    0x8C0CD940: "mpdrv_set_ft4ctrl",
}

S_LO, S_HI = 0x8C0CD600, 0x8C0CDA00
O_LO, O_HI = 0x8C035E00, 0x8C036900


def load_funcs():
    rows = []
    with open(FUNCS, newline="") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r["name"]))
    rows.sort()
    return rows


def func_of(rows, addr):
    lo, hi = 0, len(rows)
    best = None
    for e, s, n in rows:
        if e <= addr < e + max(s, 1):
            best = n
    return best or ""


def main() -> int:
    raw = IMG.read_bytes()
    funcs = load_funcs()

    # 1) find pool dwords in image pointing into string cluster
    pools = []  # (pool_file_off, guest_addr, str_target)
    for off in range(0, len(raw) - 4, 2):
        v = struct.unpack_from("<I", raw, off)[0]
        if S_LO <= v < S_HI:
            pools.append((off, BASE + off, v))
    pool_by_addr = {g: t for _, g, t in pools}

    # 2) scan code for mov.l @(disp,PC) referencing those pool addrs
    out_rows = []
    for off in range(0, len(raw) - 2, 2):
        w = raw[off] | (raw[off + 1] << 8)
        if (w & 0xF000) != 0xD000:
            continue
        site = BASE + off
        if not (O_LO <= site < O_HI):
            continue
        pool = ((site + 4) & ~3) + (w & 0xFF) * 4
        if pool in pool_by_addr:
            tgt = pool_by_addr[pool]
            name = STRINGS.get(tgt, "")
            if not name:
                # nearest known string below target
                below = [(a, n) for a, n in STRINGS.items() if a <= tgt]
                name = max(below)[1] + "+off" if below else "snd_cluster"
            out_rows.append({
                "string_addr": f"0x{tgt:08x}",
                "string_name": name,
                "pool_addr": f"0x{pool:08x}",
                "owner_site": f"0x{site:08x}",
                "owner_fn": func_of(funcs, site),
            })
    out_rows.sort(key=lambda r: r["pool_addr"])
    with open(OUT, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["string_addr", "string_name",
                                          "pool_addr", "owner_site",
                                          "owner_fn"])
        w.writeheader()
        w.writerows(out_rows)
    print(f"snd_walkback: {len(pools)} pool refs, {len(out_rows)} owners "
          f"in sound block -> {OUT}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
