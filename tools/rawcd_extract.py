#!/usr/bin/env python3
"""Extract files from 2048-byte ISO or raw 2352-byte CD images.

The Katana SDK archives include raw CD images that are not directly mountable
on Windows. This ISO-9660/Joliet reader extracts selected files without
rewriting the source image.
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

SECTOR = 2352
USER = 16
PAYLOAD = 2048
_LAYOUT: dict[int, tuple[int, int | None]] = {}


def read_block(f, lba: int) -> bytes:
    layout = _LAYOUT.get(id(f))
    if layout is None:
        f.seek(16 * PAYLOAD)
        descriptor = f.read(PAYLOAD)
        if descriptor[1:6] == b"CD001":
            layout = (PAYLOAD, 0)
        else:
            layout = (SECTOR, None)
        _LAYOUT[id(f)] = layout
    sector_size, payload_offset = layout
    f.seek(lba * sector_size)
    if payload_offset == 0:
        data = f.read(PAYLOAD)
        if len(data) != PAYLOAD:
            raise ValueError(f"short sector at LBA {lba}")
        return data
    header = f.read(24)
    # Mode 1 places the 2048-byte ISO payload at byte 16. Mode 2 Form 1
    # (used by the Japanese SDK image) places it at byte 24 after the XA
    # subheader. Other raw layouts are rejected rather than misread.
    if len(header) < 24 or header[:12] != b"\x00" + b"\xff" * 10 + b"\x00":
        raise ValueError(f"invalid raw CD sector at LBA {lba}")
    if header[15] == 1:
        offset = USER
    elif header[15] == 2 and header[18] & 0x20 == 0:
        offset = 24
    else:
        raise ValueError(f"unsupported raw CD mode at LBA {lba}")
    f.seek(lba * SECTOR + offset)
    data = f.read(PAYLOAD)
    if len(data) != PAYLOAD:
        raise ValueError(f"short sector at LBA {lba}")
    return data


def extent(f, lba: int, size: int) -> bytes:
    blocks = (size + PAYLOAD - 1) // PAYLOAD
    return b"".join(read_block(f, lba + i) for i in range(blocks))[:size]


def entries(f, lba: int, size: int, joliet: bool = False):
    data = extent(f, lba, size)
    pos = 0
    while pos < len(data):
        n = data[pos]
        if n == 0:
            pos = ((pos // PAYLOAD) + 1) * PAYLOAD
            continue
        rec = data[pos:pos + n]
        if len(rec) < 34 or len(rec) != n:
            raise ValueError(f"malformed directory record at LBA {lba}, offset {pos}")
        name_len = rec[32]
        raw_name = rec[33:33 + name_len]
        if raw_name not in (b"\x00", b"\x01"):
            if joliet:
                name = raw_name.decode("utf-16-be", "replace").split(";", 1)[0]
            else:
                name = raw_name.decode("ascii", "replace").split(";", 1)[0]
            child_lba = int.from_bytes(rec[2:6], "little")
            child_size = int.from_bytes(rec[10:14], "little")
            is_dir = bool(rec[25] & 2)
            yield name, child_lba, child_size, is_dir
        pos += n


def safe_name(s: str) -> str:
    s = re.sub(r"[^A-Za-z0-9._$-]", "_", s)
    return s or "_"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("image", type=Path)
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--ext", action="append", default=[".LIB"],
                    help="file extension to extract (repeatable; default .LIB)")
    a = ap.parse_args()
    wanted = {x.upper() if x.startswith(".") else "." + x.upper() for x in a.ext}

    with a.image.open("rb") as f:
        pvd = read_block(f, 16)
        if pvd[1:6] != b"CD001" or pvd[0] != 1:
            raise SystemExit("LBA 16 is not an ISO-9660 primary volume descriptor")
        volume = pvd
        joliet = False
        for lba in range(17, 48):
            desc = read_block(f, lba)
            if desc[1:6] != b"CD001" or desc[0] == 255:
                break
            if desc[0] == 2 and desc[88:90] == b"%/":
                volume = desc
                joliet = True
                break
        rr = volume[156:]
        root_lba = int.from_bytes(rr[2:6], "little")
        root_size = int.from_bytes(rr[10:14], "little")
        stack = [("", root_lba, root_size)]
        found = 0
        while stack:
            path, lba, size = stack.pop()
            for name, child_lba, child_size, is_dir in entries(f, lba, size, joliet):
                rel = f"{path}/{name}" if path else name
                if is_dir:
                    stack.append((rel, child_lba, child_size))
                    continue
                if Path(name).suffix.upper() not in wanted:
                    continue
                target = a.out.joinpath(*(safe_name(x) for x in rel.split("/")))
                target.parent.mkdir(parents=True, exist_ok=True)
                with target.open("wb") as out:
                    left = child_size
                    for i in range((child_size + PAYLOAD - 1) // PAYLOAD):
                        chunk = read_block(f, child_lba + i)[:min(PAYLOAD, left)]
                        out.write(chunk)
                        left -= len(chunk)
                print(f"{rel} -> {target} ({child_size} B)")
                found += 1
    print(f"extracted {found} files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
