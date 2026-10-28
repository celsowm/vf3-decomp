#!/usr/bin/env python3
"""Extract the reference's default VMU image (core/hw/maple/maple_devs.cpp).

The reference initialises an empty VMU from a zlib blob (`vmu_default`), so the
card the game sees in the reference is exactly that image.  This tool writes it
out as a raw 128 KiB image, and prints the root block's fields the game reads.

Usage:
    python tools/maple_vmu_default.py tools/emu/flycast/core/hw/maple/maple_devs.cpp build/vmu_default.bin
"""
from __future__ import annotations

import re
import sys
import zlib
from pathlib import Path

BLOCK = 512
BLOCKS = 256


def extract(source: Path) -> bytes:
    text = source.read_text(encoding="utf-8", errors="replace")
    start = text.find("u8 vmu_default[] = {")
    if start < 0:
        raise SystemExit("vmu_default not found in " + str(source))
    end = text.find("};", start)
    body = text[start:end]
    values = [int(v, 16) for v in re.findall(r"0x([0-9a-fA-F]{1,2})", body)]
    return bytes(values)


def main() -> int:
    source = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("tools/emu/flycast/core/hw/maple/maple_devs.cpp")
    out = Path(sys.argv[2]) if len(sys.argv) > 2 else Path("build/vmu_default.bin")
    blob = extract(source)
    image = zlib.decompress(blob)
    if len(image) != BLOCKS * BLOCK:
        raise SystemExit("the image is %d bytes, expected %d" % (len(image), BLOCKS * BLOCK))
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(image)

    root = image[255 * BLOCK:256 * BLOCK]
    print("wrote %s (%d bytes)" % (out, len(image)))
    print("root block 255:")
    print("  magic        %r" % root[0:4])
    print("  reserved 4   %s" % root[4:0x10].hex())
    print("  date/time    %s" % root[0x30:0x38].hex())
    print("  icon shape   %02x" % root[0x10])
    print("  media info   %s" % root[0x40:0x58].hex())
    words = [int.from_bytes(root[0x40 + 2 * i:0x42 + 2 * i], "little") for i in range(12)]
    print("  media words  %s" % words)
    fat = image[254 * BLOCK:255 * BLOCK]
    used = sum(1 for b in range(BLOCKS) if int.from_bytes(fat[2 * b:2 * b + 2], "little") != 0xFFFC)
    print("  FAT block 254: %d of %d entries are free" % (BLOCKS - used, BLOCKS))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
