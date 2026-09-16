#!/usr/bin/env python3
"""Structural probe for Sega DTPK packages (LEVEL/PLAYER/BGM/VO/ST_*/COIN/...).

Known header:
  0x00  "DTPK"
  0x04  u32        count-ish (79..)  -> hypothesis: number of entries
  0x08  u32        file size (redundant)
  0x10  u32        tag/version (0x0_0x00FFxx pattern seen)
  0x14  u32        ~0x14Dxx   (internal payload size?)
  0x18  u32        0x200000 (constant marker)
  0x1C  u32        0
  0x20  u32        0x60       (directory offset)
  0x24  u32        varies     (dir size/second offset)
"""
import os
import struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(REPO, "docs", "formats")


def analyze(path):
    d = open(path, "rb").read()
    if d[:4] != b"DTPK":
        return None
    size = len(d)
    n = struct.unpack_from("<I", d, 4)[0]
    fsize, tag, inner, flag20, z, diroff = struct.unpack_from("<6I", d, 8)
    # candidate pointer table at diroff (u32s monotonic ascending < fsize)
    ent = []
    p = diroff
    for i in range(min(n + 4, 4096)):
        v = struct.unpack_from("<I", d, p)[0]
        if v >= fsize:
            break
        ent.append(v)
        p += 4
    return {
        "file": os.path.basename(path),
        "total": size,
        "count": n,
        "filesize_field": fsize,
        "tag": tag,
        "inner": inner,
        "diroff": diroff,
        "dir_entries": len(ent),
        "first_entries": ent[:12],
    }


def main():
    rows = []
    for root, _d, files in os.walk(os.path.join(REPO, "extract", "gamedata")):
        for fn in sorted(files):
            p = os.path.join(root, fn)
            r = analyze(p)
            if r:
                rows.append(r)
    print(f"DTPK files: {len(rows)}")
    w = open(os.path.join(OUT, "DTPK.md"), "w", newline="\n")
    w.write("# DTPK container probe\n\n")
    w.write("| file | count field | dir@ | entries seen | note |\n|---|---|---|---|---|\n")
    for r in rows:
        w.write(f"| {r['file']} | {r['count']} | 0x{r['diroff']:X} | {r['dir_entries']} | tag 0x{r['tag']:08X} |\n")
    w.close()
    for r in rows[:6]:
        print(r["file"], "count:", r["count"], "first entries:",
              [hex(v) for v in r["first_entries"]])


if __name__ == "__main__":
    main()
