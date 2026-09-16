#!/usr/bin/env python3
"""Scan extract/gamedata, fingerprint every file's magic bytes and likely
format, and write docs/formats/INVENTORY.md.

Known format magics:
  PVPA/GBIX   Dreamcast PowerVR texture / GVr header
  80 00 00 00 ADX CRI ADX header (in BGM/VO)
  PVRT        raw PVR texture
  MLD_/@(C)   Sega sound banks
Format unknowns get entropy + first-32-bytes hex for later manual work.
"""
import collections
import hashlib
import math
import os
import struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GD = os.path.join(REPO, "extract", "gamedata")
DOCS = os.path.join(REPO, "docs")

MAGICS = {
    b"PVPA": "PowerVR PVPA container",
    b"GBIX": "PowerVR GBIX/GVRT texture",
    b"PVRT": "PowerVR PVRT texture",
    b"PVPL": "PVR polygon list",
    b"NMDM": "Sega Ninja model data",
    b"NMDC": "Sega Ninja model (chunk)",
    b"NJTL": "Ninja texture list",
    b"MOCB": "motion chunk?",
    b"SMPO": "Sega Manatee/SDD bank (sequences)",
    b"MLTB": "Sega sound bank (MLTB)",
    b"MDBN": "Sega sound bank (MDBN)",
    b"OSWB": "sound bank",
    b"SFD": "CRI Sofdec container? (check @0)",
    b"ADXF": "CRI ADX fused stream",
}


def entropy(data):
    if not data:
        return 0.0
    c = collections.Counter(data[:65536])
    n = min(len(data), 65536)
    return -sum((v / n) * math.log2(v / n) for v in c.values())


def classify(name, head, size):
    for magic, desc in MAGICS.items():
        if head.startswith(magic):
            return desc
    # CRI ADX header: u16be 0x8000 then offset-to-copyright
    if len(head) >= 4 and head[0] == 0x80 and head[1] == 0x00:
        return "CRI ADX audio (0x8000 magic)"
    # PVR KMG texture files from Sega tools start with 'KMG'
    if head.startswith(b"KMG"):
        return "KMG texture (PowerVR KMG)"
    if name.upper().endswith(".SFD"):
        return "CRI Sofdec movie (opaque)"
    if head.startswith(b"SEGA") or b"SEGA" in head[:64]:
        return "contains SEGA banner (executable/driver)"
    return None


def main():
    os.makedirs(os.path.join(DOCS, "formats"), exist_ok=True)
    rows = []
    for fn in sorted(os.listdir(GD)):
        path = os.path.join(GD, fn)
        if not os.path.isfile(path):
            continue
        with open(path, "rb") as f:
            head = f.read(64)
            f.seek(0, os.SEEK_END)
            size = f.tell()
        cls = classify(fn, head, size)
        ent = round(entropy(open(path, "rb").read(65536)), 2)
        rows.append((fn, size, head[:16].hex(), cls or "", ent))

    classes = collections.Counter(r[3] or "(unidentified)" for r in rows)
    with open(os.path.join(DOCS, "formats", "INVENTORY.md"), "w", newline="\n") as d:
        d.write("# Asset format inventory (auto-generated)\n\n")
        d.write("## Summary\n\n| class | count |\n|---|---|\n")
        for c, n in classes.most_common():
            d.write(f"| {c} | {n} |\n")
        d.write("\n## Files\n\n| file | size | first16 (hex) | class | entropy |\n")
        d.write("|---|---|---|---|---|\n")
        for fn, size, hexs, cls, ent in rows:
            d.write(f"| {fn} | {size} | `{hexs}` | {cls} | {ent} |\n")
    print(f"{len(rows)} files -> docs/formats/INVENTORY.md")
    for c, n in classes.most_common():
        print(f"  {n:4d} {c}")


if __name__ == "__main__":
    main()
