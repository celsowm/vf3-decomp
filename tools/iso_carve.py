#!/usr/bin/env python3
"""iso_carve.py — ISO9660 walker + ELF/SYSROF corpus carver (no deps).

The Dreamcast SDK pressings ship as raw Mode2/Form1 or plain 2048-byte
ISO images.  This tool walks the ISO9660 tree, then carves every member that
carries SH-4 code (ELF magic or SYSROF library magic) into a single
concatenated blob plus a CSV manifest, so sdk_sweep.py can match game
functions against the union of all SDK code we own.

Usage:
  python tools/iso_carve.py list  <img> [pattern]
  python tools/iso_carve.py carve <img> --out PREFIX
      [--filter SUBSTR] [--max-member BYTES] [--raw-window BYTES]

Outputs (carve): PREFIX.bin (blob), PREFIX.csv (manifest), PREFIX.log (stats).
The manifest records blob_off/size for each carved region so matches can be
required to lie fully inside one region (no cross-seam false positives).
"""
from __future__ import annotations

import argparse
import csv
import mmap
import struct
import sys
from pathlib import Path

ELF_MAGIC = b"\x7fELF\x01\x01\x01"
SYSROF_MAGIC = b"SYSROF"
SEAM = b"\x00" * 64           # separator inserted between carved regions
RAW_WINDOW = 4 * 1024 * 1024  # max bytes carved from one embedded ELF hit


class Image:
    """Memory-mapped ISO image with auto-detected sector layout."""

    LAYOUTS = ((2048, 0), (2352, 24), (2352, 16))

    def __init__(self, path: Path):
        self.path = path
        self.f = open(path, "rb")
        self.data = mmap.mmap(self.f.fileno(), 0, access=mmap.ACCESS_READ)
        self.sec, self.off = self._detect()

    def _detect(self):
        for sec, off in self.LAYOUTS:
            p = 16 * sec + off
            if self.data[p:p + 1] == b"\x01" and self.data[p + 1:p + 6] == b"CD001":
                return sec, off
        raise SystemExit(f"{self.path}: no ISO9660 PVD found")

    def _pvd(self) -> bytes:
        p = 16 * self.sec + self.off
        return self.data[p:p + 2048]

    def member(self, extent: int, size: int) -> bytes:
        """Read a member whose extents are logical 2048-byte sectors."""
        base = self.off + extent * self.sec
        return self.data[base:base + size]

    def walk(self):
        pvd = self._pvd()
        root = pvd[156:156 + 34]
        extent = struct.unpack_from("<I", root, 2)[0]
        size = struct.unpack_from("<I", root, 10)[0]
        out, seen = [], set()

        def rec(sec, length, prefix):
            if sec in seen:
                return
            seen.add(sec)
            p = self.off + sec * self.sec
            end = p + length
            while p < end and p + 33 <= len(self.data):
                rlen = self.data[p]
                if rlen == 0:
                    p = ((p - self.off) // self.sec + 1) * self.sec + self.off
                    continue
                ext = struct.unpack_from("<I", self.data, p + 2)[0]
                sz = struct.unpack_from("<I", self.data, p + 10)[0]
                flags = self.data[p + 25]
                nlen = self.data[p + 32]
                name = bytes(self.data[p + 33:p + 33 + nlen])
                if name not in (b"\x00", b"\x01"):
                    nm = name.decode("ascii", "replace").split(";")[0]
                    full = prefix + "/" + nm
                    if flags & 2:
                        out.append((full + "/", 0, ext))
                        rec(ext, sz, full)
                    else:
                        out.append((full, sz, ext))
                p += rlen

        rec(extent, size, "")
        return out

    def close(self):
        try:
            self.data.close()
        finally:
            self.f.close()


def elf_regions(data: bytes, limit: int = RAW_WINDOW):
    """Offsets of ELF headers inside a member (deduped, sorted)."""
    hits = []
    pos = 0
    while True:
        i = data.find(ELF_MAGIC, pos)
        if i < 0:
            break
        hits.append(i)
        pos = i + 1
    return hits


CODE_EXT = (".lib", ".obj", ".o", ".a")

EM_SH = 42  # e_machine for SuperH


def is_sh4_elf(d: bytes) -> bool:
    """True for a little-endian SH-4 ELF (e_machine == 42)."""
    return (len(d) >= 20 and d[:4] == b"\x7fELF" and d[4] == 1
            and struct.unpack_from("<H", d, 18)[0] == EM_SH)


def carve_member(name: str, raw: bytes, limit: int):
    """Yield (kind, subname, bytes) regions for one ISO member."""
    low = name.lower()
    if raw[:4] == b"\x7fELF":
        if is_sh4_elf(raw):
            yield ("elf", name, raw)
        return
    if raw[:6] == SYSROF_MAGIC or raw[:6] == b"LIBSYS" or raw[:1] == b"\xe0":
        yield ("lib", name, raw)
        return
    if low.endswith(CODE_EXT):
        yield ("code", name, raw)
    hits = elf_regions(raw, limit)
    libhits = []
    pos = 0
    while True:
        i = raw.find(SYSROF_MAGIC, pos)
        if i < 0:
            break
        libhits.append(i)
        pos = i + 1
    marks = sorted([(i, "elf") for i in hits] + [(i, "lib") for i in libhits])
    if not marks:
        return
    for k, (i, kind) in enumerate(marks):
        j = marks[k + 1][0] if k + 1 < len(marks) else len(raw)
        n = min(j - i, limit)
        if n >= 64:
            body = raw[i:i + n]
            if kind == "elf" and not is_sh4_elf(body):
                continue
            yield (kind, f"{name}+0x{i:x}", body)


def cmd_list(a):
    img = Image(Path(a.img))
    try:
        pat = (a.pattern or "").lower()
        for path, sz, ext in img.walk():
            if pat and pat not in path.lower():
                continue
            print(f"{sz:12d}  {path}")
    finally:
        img.close()


def cmd_carve(a):
    img = Image(Path(a.img))
    out = Path(a.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    filt = (a.filter or "").lower()
    blobs = []
    rows = []
    total = 0
    stats = {"members": 0, "elf": 0, "lib": 0, "bytes": 0}
    try:
        for path, sz, ext in img.walk():
            if sz == 0 or path.endswith("/"):
                continue
            if filt and filt not in path.lower():
                continue
            if sz > a.max_member:
                continue
            if not (path.lower().endswith((".elf", ".bin", ".abs", ".out", ".lib",
                                          ".obj", ".exe", ".prg", ".sam"))
                    or sz < 8 * 1024 * 1024):
                continue
            raw = img.member(ext, sz)
            stats["members"] += 1
            for kind, sub, body in carve_member(path, raw, a.raw_window):
                base = total
                blobs.append(body)
                rows.append({"kind": kind, "source": sub,
                             "blob_off": base, "size": len(body)})
                total += len(body) + len(SEAM)
                blobs.append(SEAM)
                stats[kind] = stats.get(kind, 0) + 1
                stats["bytes"] += len(body)
    finally:
        img.close()
    blob = b"".join(blobs)
    out.with_suffix(".bin").write_bytes(blob)
    with open(out.with_suffix(".csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["kind", "source", "blob_off", "size"])
        w.writeheader()
        w.writerows(rows)
    with open(out.with_suffix(".log"), "w") as f:
        f.write(f"image={img.path}\n")
        for k, v in stats.items():
            f.write(f"{k}={v}\n")
    print(f"carved {total} bytes in {len(rows)} regions "
          f"(elf={stats.get('elf', 0)} lib={stats.get('lib', 0)}) "
          f"-> {out.with_suffix('.bin')}")
    return 0


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list")
    p.add_argument("img")
    p.add_argument("pattern", nargs="?")
    p.set_defaults(func=cmd_list)
    p = sub.add_parser("carve")
    p.add_argument("img")
    p.add_argument("--out", required=True)
    p.add_argument("--filter", default=None)
    p.add_argument("--max-member", type=int, default=256 * 1024 * 1024)
    p.add_argument("--raw-window", type=int, default=RAW_WINDOW)
    p.set_defaults(func=cmd_carve)
    a = ap.parse_args()
    return a.func(a)


if __name__ == "__main__":
    sys.exit(main())
