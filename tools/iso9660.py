#!/usr/bin/env python3
"""ISO9660 reader for the VF3tb data track (the game's own file system).

The data track (track03.bin) is a raw 2352-byte-per-sector image: 16 bytes of
sync+header in front of the 2048 bytes of user data (mode 1).  The drive
addresses FADs; the GDI lists the track by LBA, and the FAD is the LBA plus
the 150-sector pregap, so the file offset of a FAD is

    (fad - 150 - 45000) * 2352 + 16

for the data track (the GDI's start LBA 45000).

The volume is plain ISO9660: the primary volume descriptor sits at sector 16,
its root directory record points at the root directory, and the directory
records carry the extent (LBA) and the size of every file.

Usage:
    python tools/iso9660.py rom/track03.bin                 # list the volume
    python tools/iso9660.py rom/track03.bin --find CP_END   # locate a file
    python tools/iso9660.py rom/track03.bin --fad 0x85b12    # what is at a FAD
"""
import argparse
import os
import struct
import sys

SECTOR = 2352
USER = 2048
HDR = 16
DATA_TRACK_LBA = 45000
FAD_PREGAP = 150


class Track:
    """The data track, addressed by FAD the way the drive addresses it."""

    def __init__(self, path):
        self.f = open(path, "rb")

    def close(self):
        self.f.close()

    def sector_at_lba(self, lba):
        off = (lba - DATA_TRACK_LBA) * SECTOR + HDR
        if off < 0:
            return None
        self.f.seek(off)
        d = self.f.read(USER)
        return d if len(d) == USER else None

    def user_at_fad(self, fad, count=1):
        out = bytearray()
        for i in range(count):
            d = self.sector_at_lba(fad - FAD_PREGAP + i)
            if d is None:
                break
            out += d
        return bytes(out)


def _dec(b):
    """The ISO9660 names are ASCII with a trailing ';1' version suffix."""
    s = b.split(b";")[0].split(b"\x00")[0]
    return s.decode("latin1").strip()


def read_dir(track, extent, size):
    """The directory records of one directory."""
    recs = []
    data = b""
    n = (size + USER - 1) // USER
    for i in range(n):
        d = track.sector_at_lba(extent + i)
        if d is None:
            break
        data += d
    pos = 0
    while pos < len(data):
        ln = data[pos]
        if ln == 0:
            # a record never crosses a sector boundary: the rest is padding
            pos = ((pos // USER) + 1) * USER
            continue
        rec = data[pos:pos + ln]
        if len(rec) < 33:
            break
        ext_lba = struct.unpack_from("<I", rec, 2)[0]
        ext_len = struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]
        namelen = rec[32]
        name = rec[33:33 + namelen]
        recs.append(dict(name=_dec(name), raw=name, lba=ext_lba, size=ext_len,
                         dir=bool(flags & 0x02)))
        pos += ln
    return recs


def walk(track, extent, size, path="", out=None, depth=0, top=False):
    """Every file of the volume, with the directories' own names.

    The two special records of a directory are the self entry ("\x00") and the
    parent entry ("\x01"); they are skipped, and so is the root's own copy.
    """
    if out is None:
        out = []
    for r in read_dir(track, extent, size):
        if r["raw"] in (b"\x00", b"\x01"):
            continue
        full = path + "/" + r["name"]
        out.append((full, r))
        if r["dir"] and depth < 6:
            walk(track, r["lba"], r["size"], full, out, depth + 1)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("track")
    ap.add_argument("--find", help="substring of a file name to locate")
    ap.add_argument("--fad", help="hex FAD to resolve (e.g. 0x85b12)")
    ap.add_argument("--list", action="store_true", help="list every file")
    a = ap.parse_args()

    tr = Track(a.track)
    pvd = tr.user_at_fad(DATA_TRACK_LBA + FAD_PREGAP + 16)
    if pvd[:6] != b"\x01CD001":
        print("no primary volume descriptor at sector 16", file=sys.stderr)
        return 1
    root = pvd[156:190]
    root_lba = struct.unpack_from("<I", root, 2)[0]
    root_len = struct.unpack_from("<I", root, 10)[0]
    print(f"volume id : {_dec(pvd[40:72])}")
    print(f"root      : LBA {root_lba}, {root_len} bytes")

    entries = walk(tr, root_lba, root_len)

    if a.fad:
        fad = int(a.fad, 0)
        lba = fad - FAD_PREGAP
        print(f"FAD {fad:#x} -> LBA {lba}")
        for full, r in entries:
            if r["lba"] <= lba < r["lba"] + (r["size"] + USER - 1) // USER:
                print(f"  inside {full} (LBA {r['lba']}, {r['size']} bytes)")
        d = tr.user_at_fad(fad)
        print("  first 32 bytes:", d[:32].hex())
        return 0

    if a.find:
        up = a.find.upper()
        for full, r in entries:
            if up in full.upper():
                print(f"{full:40s} LBA {r['lba']:>8d}  {r['size']:>10d} bytes"
                      f"  (FAD {r['lba'] + FAD_PREGAP:#x})")
        return 0

    if a.list:
        for full, r in entries:
            print(f"{full:40s} {'dir' if r['dir'] else 'file':4s} "
                  f"LBA {r['lba']:>8d}  {r['size']:>10d}")
        return 0

    for full, r in entries[:24]:
        print(f"{full:40s} {'dir' if r['dir'] else 'file':4s} "
              f"LBA {r['lba']:>8d}  {r['size']:>10d}")
    print(f"... {len(entries)} entries")
    tr.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
