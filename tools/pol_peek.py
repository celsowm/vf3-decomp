#!/usr/bin/env python3
"""Probe VF3 POL model packages (PowerVR TA / packet format reconnaissance)."""
import struct

FILES = ["MKAO_AKI.POL", "ST01.POL", "ROB_ALP.POL", "MKAO_WOL.POL"]

for fn in FILES:
    d = open("extract/gamedata/" + fn, "rb").read()
    print(f"== {fn} size={len(d):,}")
    for r in range(0, 0x60, 4):
        v = struct.unpack_from("<I", d, r)[0]
        fv = struct.unpack_from("<f", d, r)[0]
        ff = f"  f={fv:12.4g}" if 1e-30 < abs(fv) < 1e30 else ""
        print(f"  +0x{r:02X}: 0x{v:08X}{ff}")
    print()
