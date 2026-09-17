#!/usr/bin/env python3
"""DTPK extractor (M3-D).

Container layout (validated across 69 packages in VF3tb):
    0x00 'DTPK'
    0x04 u32 package serial id (load-list ordinal)
    0x08 u32 total size (= file size)
    0x0C u32 0
    0x10 u32 tag (per-group classifier, low byte often = package kind)
    0x14 u32 ~0x00014D11 (near-const)
    0x18 u32 0x00200000 (const)
    0x1C u32 0
    0x20..0x5F section table: 16 x u32 offsets into THIS FILE;
              unused slots are 0.  First used value is always 0x60.
    sections: [dir[i], dir[i+1] or EOF) in ascending order.

Extraction: writes <outroot>/<PKG>/sec<NN>_<adfad>.bin for each section.
"""
import json
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(REPO, "extract", "gamedata")
DST = os.path.join(REPO, "extract", "dtpk")

# Discover DTPK files by magic rather than a hard-coded list


def split(path):
    d = open(path, "rb").read()
    if d[:4] != b"DTPK":
        return None
    serial, fsize = struct.unpack_from("<II", d, 4)
    tag = struct.unpack_from("<I", d, 0x10)[0]
    dir16 = [struct.unpack_from("<I", d, 0x20 + i * 4)[0] for i in range(16)]
    offs = sorted({x for x in dir16 if x and x < len(d)})
    sections = []
    for k, o in enumerate(offs):
        end = offs[k + 1] if k + 1 < len(offs) else len(d)
        if end > o:
            sections.append((o, end - o, k))
    return dict(serial=serial, fsize=fsize, tag=tag, dir=dir16,
                sections=sections, data=d)


def main():
    os.makedirs(DST, exist_ok=True)
    report = []
    n = 0
    for fn in sorted(os.listdir(SRC)):
        p = os.path.join(SRC, fn)
        if not os.path.isfile(p):
            continue
        info = split(p)
        if info is None:
            continue
        n += 1
        od = os.path.join(DST, os.path.splitext(fn)[0])
        os.makedirs(od, exist_ok=True)
        with open(os.path.join(od, "_dtpk.json"), "w") as j:
            json.dump({k: v for k, v in info.items() if k != "data"},
                      j, indent=1)
        for o, sz, k in info["sections"]:
            with open(os.path.join(od, f"sec{k}_{o:06X}_{sz:06X}.bin"),
                      "wb") as f:
                f.write(info["data"][o:o + sz])
        report.append((fn, info["serial"], len(info["sections"]),
                       info["sections"]))
    print(f"split {n} DTPK packages into {DST}")
    for fn, sid, ns, secs in report:
        print(f"  {fn:16s} id={sid:3d} sections={ns:2d} "
              f"sizes={' '.join(str(s) for _, s, _ in secs[:8])}")


if __name__ == "__main__":
    main()
