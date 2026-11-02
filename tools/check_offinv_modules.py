#!/usr/bin/env python3
"""check_offinv_modules.py - prove the off-inventory modules are a faithful
rendering of the identity image.

The generated modules record the opcode they translated in every block
(`/* original c330, guest PC 0x0c039d90 */`).  This gate re-reads the image and
checks, for every block of every off-inventory module, that the recorded
opcode is the image's word at that PC (identity load at 0x8C010000).

The same check the gap modules get (tools/gap_fidelity.py), for the modules
the boot's off-inventory entries need.
"""
from __future__ import annotations

import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
IMAGE = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
# The image's load address in the guest's RAM (the identity load, 0x8C010000,
# is the same bytes at the mirror).  The guest PCs the modules carry are the
# RAM ones, so the offset is pc - 0x0C010000 (the same base tools/gap_fidelity.py
# uses).
BASE = 0x0C010000
MODULES = ["vf3_offinv_adapter.c", "vf3_offinv_b02_adapter.c",
           "vf3_offinv_b03_adapter.c", "vf3_offinv_b04_adapter.c"]

BLOCK = re.compile(r"^P_([0-9a-f]{8}): /\* original ([0-9a-f]{4}), guest PC 0x([0-9a-f]{8}) \*/")


def main() -> int:
    if not IMAGE.is_file():
        print(f"check_offinv_modules: {IMAGE} missing")
        return 2
    img = IMAGE.read_bytes()
    total = 0
    bad = 0
    for name in MODULES:
        path = REPO / "src" / "fight" / name
        if not path.is_file():
            print(f"{name}: missing")
            bad += 1
            continue
        blocks = 0
        for line in path.read_text().splitlines():
            m = BLOCK.match(line)
            if not m:
                continue
            blocks += 1
            op = int(m.group(2), 16)
            pc = int(m.group(3), 16)
            off = pc - BASE
            if off < 0 or off + 2 > len(img):
                print(f"  {name}: 0x{pc:08x} is outside the image")
                bad += 1
                continue
            (word,) = struct.unpack_from("<H", img, off)
            if word != op:
                print(f"  {name}: 0x{pc:08x} image says {word:04x}, the module says {op:04x}")
                bad += 1
        total += blocks
        print(f"{name}: {blocks} blocks checked")
    print(f"blocks whose opcode does not match the image: {bad}")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
