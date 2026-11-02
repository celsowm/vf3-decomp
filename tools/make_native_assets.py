#!/usr/bin/env python3
"""make_native_assets.py - build the native asset bundle the port ships with.

The port's runtime must not need Dreamcast artefacts: no .gdi, no track files,
no BIOS ROM, no emulator savestate.  This tool turns the user's own disc dump
into one self-contained directory:

    <out>/boot.state   the cold-boot machine state, built from 1ST_READ.BIN
                       (tools/make_boot_state.py; registers + 16 MiB RAM)
    <out>/disc.vf3     the data track as a packed 2048-byte-sector image,
                       addressed by the FAD the guest uses
    <out>/manifest.json

`disc.vf3` is sparse: only sectors that carry data are stored, with a 64-bit
offset table indexed by LBA.  The retail data track is 504,150 sectors
(1.03 GB logical) but only the ~677 MB of real files are written.

    python tools/make_native_assets.py
    python tools/make_native_assets.py --gdi rom/vf3.gdi \
        --image extract/gamedata/1ST_READ.BIN --out build/vf3_assets
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import make_boot_state  # noqa: E402

MAGIC = b"VF3DISC\x00"
VERSION = 1
SECTOR = 2048
RAW = 2352
RAW_HDR = 16

UINT64_MAX = (1 << 64) - 1


def parse_gdi(gdi_path: Path):
    """The data track of a .gdi, as (path, start_lba, sector_size)."""
    lines = gdi_path.read_text(errors="replace").splitlines()
    if not lines:
        raise SystemExit(f"{gdi_path}: empty .gdi")
    tracks = []
    for line in lines[1:]:
        f = line.split()
        if len(f) < 6:
            continue
        _num, lba, _type, ssize, name, _off = f[0], int(f[1]), int(f[2]), int(f[3]), f[4], int(f[5])
        tracks.append((gdi_path.parent / name, lba, ssize, _type))
    data = [t for t in tracks if t[3] == 4]
    if not data:
        raise SystemExit(f"{gdi_path}: no data track")
    # Track 1 is the low-density boot track and is also type 4; the game's
    # data is the data track at the highest LBA.
    return max(data, key=lambda t: t[1])


def pack_disc(track_path: Path, first_lba: int, sector_size: int, out_path: Path) -> tuple[int, int]:
    """Write the sparse sector image; returns (sectors, stored sectors)."""
    if sector_size not in (RAW, SECTOR):
        raise SystemExit(f"{track_path}: unsupported sector size {sector_size}")
    nsectors = track_path.stat().st_size // sector_size
    if nsectors <= 0:
        raise SystemExit(f"{track_path}: empty track")
    hdr = 16 if sector_size == RAW else 0
    index = [UINT64_MAX] * nsectors
    stored = 0
    zero = b"\x00" * SECTOR
    t0 = time.time()
    with open(track_path, "rb") as src:
        with open(out_path, "wb") as dst:
            # header (48 bytes) + index, filled in after the payload is known
            data_base = 48 + 8 * nsectors
            dst.write(MAGIC)
            dst.write(struct.pack("<IIIIIIQQ", VERSION, SECTOR, first_lba, nsectors,
                                  0, 0, 48, data_base))
            dst.write(b"\x00" * (8 * nsectors))
            for i in range(nsectors):
                raw = src.read(sector_size)
                if len(raw) < sector_size:
                    break
                user = raw[hdr:hdr + SECTOR]
                if user == zero:
                    continue
                index[i] = dst.tell() - data_base
                dst.write(user)
                stored += 1
                if stored % 65536 == 0:
                    mb = stored * SECTOR // (1 << 20)
                    print(f"  {i + 1}/{nsectors} sectors, {mb} MiB stored", end="\r", flush=True)
            # the header and the index now that every offset is known
            dst.seek(0)
            dst.write(MAGIC)
            dst.write(struct.pack("<IIIIIIQQ", VERSION, SECTOR, first_lba, nsectors,
                                  0, 0, 48, data_base))
            for pos in range(0, nsectors, 8192):
                chunk = index[pos:pos + 8192]
                dst.write(struct.pack(f"<{len(chunk)}Q", *chunk))
    print(f"\n  packed {stored}/{nsectors} sectors "
          f"({stored * SECTOR / (1 << 20):.1f} MiB) in {time.time() - t0:.1f}s")
    return nsectors, stored


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n")[0])
    ap.add_argument("--gdi", type=Path, default=Path("rom/vf3.gdi"),
                    help="disc descriptor (the data track is what gets packed)")
    ap.add_argument("--track", type=Path, help="the data track itself (overrides --gdi)")
    ap.add_argument("--image", type=Path, default=Path("extract/gamedata/1ST_READ.BIN"),
                    help="1ST_READ.BIN (the retail ships it unscrambled)")
    ap.add_argument("--out", type=Path, default=Path("build/vf3_assets"))
    ap.add_argument("--low-ram", type=Path,
                    help="optional reference state whose first 64 KiB seed the boot")
    ap.add_argument("--entry", type=lambda s: int(s, 0), default=make_boot_state.LOAD_ADDR)
    a = ap.parse_args()

    if not a.image.exists():
        raise SystemExit(f"missing {a.image}: supply your own disc dump")
    if a.track:
        track_path, lba, ssize = a.track, 45000, RAW
    else:
        if not a.gdi.exists():
            raise SystemExit(f"missing {a.gdi}: supply your own disc dump")
        track_path, lba, ssize, _ = parse_gdi(a.gdi)
    if not track_path.exists():
        raise SystemExit(f"missing data track {track_path}")

    a.out.mkdir(parents=True, exist_ok=True)
    t0 = time.time()

    print(f"boot state: {a.image} -> {a.out / 'boot.state'}")
    low = make_boot_state.read_low_ram(a.low_ram) if a.low_ram else b""
    state = make_boot_state.build(a.image.read_bytes(), a.entry,
                                  0x8CFFFFE0, 0x700000F0, 0x00040001, low)
    (a.out / "boot.state").write_bytes(state)
    print(f"  {len(state)} bytes")

    print(f"disc image: {track_path} (LBA {lba}, {ssize} B/sector)")
    nsectors, stored = pack_disc(track_path, lba, ssize, a.out / "disc.vf3")

    manifest = {
        "format": VERSION,
        "sector_size": SECTOR,
        "first_lba": lba,
        "sectors": nsectors,
        "stored_sectors": stored,
        "boot_state": "boot.state",
        "disc": "disc.vf3",
        "entry": "0x8c004000",
        "source_image": a.image.name,
        "created": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
    }
    (a.out / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"wrote {a.out / 'manifest.json'} ({time.time() - t0:.1f}s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
