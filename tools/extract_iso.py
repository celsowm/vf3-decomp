#!/usr/bin/env python3
"""Extract the high-density GD-ROM filesystem (track 3) of the VF3tb dump.

Reads the raw Mode1/2352 track image (file offset 0 == GD-ROM LBA 45000),
walks ISO9660 from the Primary Volume Descriptor, and extracts every file.

Outputs:
  extract/gamedata/<files>
  extract/ip/IP.BIN            (from track 3, sectors 0-15)
  docs/files.md                (manifest: name, LBA, size, sha1)
"""
import csv
import hashlib
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROM_DIR = os.path.join(REPO, "rom")
OUT_GAME = os.path.join(REPO, "extract", "gamedata")
OUT_IP = os.path.join(REPO, "extract", "ip")
DOCS = os.path.join(REPO, "docs")

SECTOR_RAW = 2352
DATA_OFF = 16          # Mode1: 12 sync + 3 addr + 1 mode, then 2048 user bytes
GD_BASE = 45000        # high-density area starts at GD-ROM LBA 45000


def find_track(pattern):
    for f in os.listdir(ROM_DIR):
        if pattern.lower() in f.lower():
            return os.path.join(ROM_DIR, f)
    raise FileNotFoundError(pattern)


def read_sector(f, lba):
    """Read 2048 user bytes of GD LBA (absolute) from the track-3 image."""
    f.seek((lba - GD_BASE) * SECTOR_RAW + DATA_OFF)
    data = f.read(2048)
    if len(data) != 2048:
        raise IOError(f"short read at LBA {lba}")
    return data


def parse_dir_record(data, p):
    if data[p] == 0:
        return None
    l = data[p]
    lba = struct.unpack_from("<I", data, p + 2)[0]
    size = struct.unpack_from("<I", data, p + 10)[0]
    flags = data[p + 25]
    nlen = data[p + 32]
    name = data[p + 33 : p + 33 + nlen].decode("ascii", "replace")
    return lba, size, flags, name, l


def walk_dir(f, lba, size, out_prefix, rows):
    remaining = size
    base = lba
    while remaining > 0:
        data = read_sector(f, base)
        p = 0
        while p < 2048 and data[p] != 0:
            rec = parse_dir_record(data, p)
            r_lba, r_size, r_flags, r_name, r_len = rec
            if r_name not in ("\x00", "\x01"):  # skip . and ..
                if r_flags & 0x02:
                    os.makedirs(os.path.join(OUT_GAME, out_prefix, r_name), exist_ok=True)
                    walk_dir(f, r_lba, r_size, os.path.join(out_prefix, r_name), rows)
                else:
                    clean = r_name.split(";")[0]
                    ns = r_size // 2048 + (1 if r_size % 2048 else 0)
                    blob = bytearray()
                    for i in range(ns):
                        blob += read_sector(f, r_lba + i)
                    blob = bytes(blob[: r_size])
                    rel = os.path.join(out_prefix, clean)
                    path = os.path.join(OUT_GAME, rel)
                    os.makedirs(os.path.dirname(path) or OUT_GAME, exist_ok=True)
                    with open(path, "wb") as w:
                        w.write(blob)
                    rows.append((rel.replace("\\", "/"), r_lba, r_size,
                                 hashlib.sha1(blob).hexdigest()))
            p += r_len
        base += 1
        remaining -= 2048


def main():
    os.makedirs(OUT_GAME, exist_ok=True)
    os.makedirs(OUT_IP, exist_ok=True)
    os.makedirs(DOCS, exist_ok=True)

    track3 = find_track("Track 3")
    rows = []
    with open(track3, "rb") as f:
        # IP.BIN: sectors 0-15 of the data area
        ip = b"".join(read_sector(f, GD_BASE + i) for i in range(16))
        with open(os.path.join(OUT_IP, "IP.BIN"), "wb") as w:
            w.write(ip)

        # PVD at LBA 45016 (file sector 16)
        pvd = read_sector(f, GD_BASE + 16)
        if pvd[0] != 1 or pvd[1:6] != b"CD001":
            raise SystemExit("PVD magic missing - wrong track?")
        root_lba, root_size, root_flags, _, _ = parse_dir_record(pvd, 156)
        walk_dir(f, root_lba, root_size, "", rows)

    rows.sort(key=lambda r: r[0].upper())
    csv_path = os.path.join(REPO, "extract", "files.csv")
    with open(csv_path, "w", newline="") as c:
        w = csv.writer(c)
        w.writerow(["name", "gd_lba", "size", "sha1"])
        w.writerows(rows)

    with open(os.path.join(DOCS, "files.md"), "w", newline="\n") as d:
        d.write("# VF3tb (USA) GD-ROM high-density area - file manifest\n\n")
        d.write(f"Total files: {len(rows)}  (source: track 3, Mode1/2352, base LBA {GD_BASE})\n\n")
        d.write("| file | GD LBA | size (bytes) | sha1 |\n|---|---|---|---|\n")
        for name, lba, size, sha in rows:
            d.write(f"| {name} | {lba} | {size} | `{sha}` |\n")

    total = sum(r[2] for r in rows)
    print(f"extracted {len(rows)} files, {total} bytes -> {OUT_GAME}")
    print(f"manifest -> docs/files.md, extract/files.csv")


if __name__ == "__main__":
    main()
