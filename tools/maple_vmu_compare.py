#!/usr/bin/env python3
"""Compare the reference's default VMU image with the port's synthetic card.

The port builds its card in `src/sys/maple_hle.c` (`vmu_format`); the reference
initialises an empty card from the zlib blob in `maple_devs.cpp`.  Both have to
look the same to the game, so this tool prints the fields that differ.

Usage:
    python tools/maple_vmu_compare.py build/vmu_default.bin
"""
from __future__ import annotations

import sys
from pathlib import Path

BLOCK = 512
BLOCKS = 256


def words16(buf: bytes, off: int, count: int) -> list[int]:
    return [int.from_bytes(buf[off + 2 * i:off + 2 * i + 2], "little") for i in range(count)]


def main() -> int:
    image = Path(sys.argv[1] if len(sys.argv) > 1 else "build/vmu_default.bin").read_bytes()
    root = image[255 * BLOCK:256 * BLOCK]
    fat = image[254 * BLOCK:255 * BLOCK]

    print("root block 255 (first 0x60 bytes)")
    for off in range(0, 0x60, 16):
        print("  %04x  %s" % (off, root[off:off + 16].hex(" ")))

    print("media info words (root + 0x40): %s" % words16(root, 0x40, 12))

    print("FAT block 254, distinct entries:")
    seen = {}
    for b in range(BLOCKS):
        v = int.from_bytes(fat[2 * b:2 * b + 2], "little")
        seen.setdefault(v, []).append(b)
    for v, blocks in sorted(seen.items()):
        if len(blocks) > 6:
            print("  %04x -> %d blocks (%d..%d)" % (v, len(blocks), blocks[0], blocks[-1]))
        else:
            print("  %04x -> %s" % (v, blocks))

    print("blocks 236..255 (the directory chain):")
    for b in range(236, 256):
        v = int.from_bytes(fat[2 * b:2 * b + 2], "little")
        print("  %3d -> %04x" % (b, v))

    print("directory block 253 head: %s" % image[253 * BLOCK:253 * BLOCK + 64].hex(" "))
    print("block 0 head:              %s" % image[0:64].hex(" "))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
