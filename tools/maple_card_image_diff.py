#!/usr/bin/env python3
"""maple_card_image_diff.py - the port's card image against the reference's.

The port builds the VMU image in C (src/sys/maple_hle.c, vmu_format) and the
reference carries one as a file (tools/emu/flycast-ref-build/data/
vf3.gdi_vmu_save_A1.bin, which is the zlib blob of maple_devs.cpp unpacked).
This tool rebuilds the port's image the way vmu_format does and diffs it
block by block, so a difference in the card's *contents* - and not in the
guest's logic - can be seen.

Usage:
    python tools/maple_card_image_diff.py [reference.bin]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

BLOCK = 512
BLOCKS = 256

# src/sys/maple_hle.c: vmu_root[] - the root block's first 0x57 bytes.
VMU_ROOT = bytes([
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x01, 0xFF, 0xFF, 0xFF, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x19, 0x98, 0x11, 0x27, 0x00, 0x00, 0x59, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFE, 0x00, 0x01, 0x00, 0xFD, 0x00, 0x0D, 0x00, 0x05, 0x00,
    0xC8, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x80,
])

BLOCK0 = b"\xc4\x00\xa4\x00\x00\x4f\x97"

BLOCK11 = bytes([
    0x04, 0x00, 0x00, 0x00, 0x1D, 0x8C, 0x06, 0x00, 0x90, 0x00, 0xA4, 0x00, 0x90, 0x00, 0xA4, 0x00,
    0x38, 0x00, 0x93, 0x00, 0x38, 0x00, 0x93, 0x00, 0x00, 0x60, 0x98, 0x00, 0x00, 0xA0, 0x0A,
])


def put16(buf: bytearray, off: int, v: int) -> None:
    buf[off] = v & 0xFF
    buf[off + 1] = (v >> 8) & 0xFF


def port_image() -> bytearray:
    """The image src/sys/maple_hle.c:vmu_format builds."""
    vmu = bytearray(BLOCKS * BLOCK)
    vmu[255 * BLOCK:255 * BLOCK + len(VMU_ROOT)] = VMU_ROOT
    vmu[0:len(BLOCK0)] = BLOCK0
    vmu[11 * BLOCK + 0x188:11 * BLOCK + 0x188 + len(BLOCK11)] = BLOCK11
    fat = 255 * BLOCK          # the FAT is built inside the root block's slot
    fat = 254 * BLOCK
    for b in range(BLOCKS):
        put16(vmu, fat + 2 * b, 0xFFFC)          # free
    put16(vmu, fat + 2 * 255, 0xFFFA)
    put16(vmu, fat + 2 * 254, 0xFFFA)
    for b in range(241, 254):
        put16(vmu, fat + 2 * b, 0xFFFA if b == 241 else b - 1)   # the directory chain
    return vmu


def main() -> int:
    ref_path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(
        "tools/emu/flycast-ref-build/data/vf3.gdi_vmu_save_A1.bin")
    ref = ref_path.read_bytes()
    port = port_image()

    print("reference: %s (%d bytes)" % (ref_path, len(ref)))
    print("port:      src/sys/maple_hle.c vmu_format (%d bytes)" % len(port))
    print()

    total = 0
    for b in range(BLOCKS):
        r = ref[b * BLOCK:(b + 1) * BLOCK]
        p = port[b * BLOCK:(b + 1) * BLOCK]
        if r == p:
            continue
        diffs = [(i, r[i], p[i]) for i in range(BLOCK) if r[i] != p[i]]
        total += len(diffs)
        print("block %3d: %d bytes differ" % (b, len(diffs)))
        for i, rv, pv in diffs[:8]:
            print("    +0x%03x: reference %02x, port %02x" % (i, rv, pv))
        if len(diffs) > 8:
            print("    ... %d more" % (len(diffs) - 8))
    if total == 0:
        print("the two images are byte identical")
    else:
        print("%d bytes differ in total" % total)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
