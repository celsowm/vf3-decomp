#!/usr/bin/env python3
"""Inspect the port's memory-card state in a RAM dump.

The game registers the card in the SDK's mpdrv tables (the record array at
0x0C19C6A0 and the drive table at 0x0C1B34D8); when the card is not there the
game sits on the "a memory card could not be found" screen.  This tool prints
those tables and the number of free blocks the card's FAT holds.

Usage:
    python tools/maple_card_state.py build/boot_card.ram
"""
from __future__ import annotations

import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RECORDS = 0x0C19C6A0
RECORD_STRIDE = 76
RECORDS_N = 8
DRIVES = 0x0C1B34D8
DRIVE_STRIDE = 0x148
DRIVES_N = 4


def main() -> int:
    ram = Path(sys.argv[1] if len(sys.argv) > 1 else "build/boot_card.ram").read_bytes()

    def at(addr: int, n: int) -> bytes:
        off = addr - RAM_BASE
        if off < 0 or off + n > len(ram):
            return b""
        return ram[off:off + n]

    print("record array at %08X (stride %d):" % (RECORDS, RECORD_STRIDE))
    for i in range(RECORDS_N):
        rec = at(RECORDS + i * RECORD_STRIDE, RECORD_STRIDE)
        if not rec:
            break
        words = [int.from_bytes(rec[j:j + 4], "little") for j in range(0, min(len(rec), 24), 4)]
        if any(words):
            print("  rec%d: %s" % (i, words))
    print("drive table at %08X (stride %#x):" % (DRIVES, DRIVE_STRIDE))
    for i in range(DRIVES_N):
        drv = at(DRIVES + i * DRIVE_STRIDE, DRIVE_STRIDE)
        if not drv:
            break
        words = [int.from_bytes(drv[j:j + 4], "little") for j in range(0, 32, 4)]
        if any(words):
            print("  drv%d: %s" % (i, words))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
