#!/usr/bin/env python3
"""gd_sector_check.py - prove that the bytes the port's loader received from the
GD-ROM model are the disc's own bytes.

The port's REIOS stub serves the BIOS GD-ROM vector (0x8C001006) from the
attached drive (src/fight/native_tick.c, vf3_native_gd_syscall).  The model
resolves a FAD to a track through the .gdi and copies the sector's user bytes
into the guest's buffer.  This tool re-derives the same bytes straight from the
track file and compares them with the buffer the loader was given, so the
model's address arithmetic (FAD -> LBA -> track -> file offset) is checked
against the disc rather than against itself.

    python tools/gd_sector_check.py rom/vf3.gdi build/post45.ram \
        0x0c2a6300 0x0000b06e
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

SECTOR = 2048
RAW = 2352


def read_gdi(path: Path) -> list[tuple[int, int, int, str]]:
    """[(start_lba, ctrl, size, file), ...] as the .gdi lists them."""
    rows: list[tuple[int, int, int, str]] = []
    lines = path.read_text(errors="replace").splitlines()
    for line in lines[1:]:
        parts = line.split()
        if len(parts) < 6:
            continue
        idx, start, ctrl, size = (int(parts[0]), int(parts[1]), int(parts[2]), int(parts[3]))
        name = parts[4].strip('"')
        rows.append((start, ctrl, size, name))
    return rows


def sector_bytes(gdi: Path, fad: int) -> bytes:
    rows = read_gdi(gdi)
    lba = fad - 150                      # the drive addresses FADs; the GDI lists LBAs
    best = None
    for start, _ctrl, size, name in rows:
        if start <= lba and (best is None or start > best[0]):
            best = (start, size, name)
    if best is None:
        raise SystemExit("no track holds FAD %d" % fad)
    start, size, name = best
    pos = (lba - start) * size + (16 if size == RAW else 0)
    with open(gdi.parent / name, "rb") as f:
        f.seek(pos)
        buf = f.read(SECTOR)
    if len(buf) != SECTOR:
        raise SystemExit("short read at FAD %d" % fad)
    return buf


def main() -> int:
    if len(sys.argv) < 5:
        raise SystemExit(__doc__)
    gdi = Path(sys.argv[1])
    ram = Path(sys.argv[2])
    guest = int(sys.argv[3], 16)
    fad = int(sys.argv[4], 16)
    want = sector_bytes(gdi, fad)
    with open(ram, "rb") as f:
        f.seek(guest - 0x0C000000)
        got = f.read(SECTOR)
    same = got == want
    print("FAD %08x -> guest %08x: %s" % (fad, guest, "MATCH" if same else "DIFFER"))
    print("  disc  %s" % want[:32].hex())
    print("  guest %s" % got[:32].hex())
    if not same:
        bad = [i for i in range(SECTOR) if got[i] != want[i]]
        print("  %d bytes differ, first at +%d (disc %02x guest %02x)"
              % (len(bad), bad[0], want[bad[0]], got[bad[0]]))
    return 0 if same else 1


if __name__ == "__main__":
    raise SystemExit(main())
