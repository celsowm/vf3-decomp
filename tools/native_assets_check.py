#!/usr/bin/env python3
"""native_assets_check.py - verify a packed native bundle against the disc.

Checks that `disc.vf3` and `boot.state` are faithful translations of the
user's own data:

  * the disc image's 2048-byte sectors are exactly the data track's user
    sectors, every stored offset is the one the index names, and every sector
    the packer skipped is all zero;
  * the boot state carries the 1ST_READ image at 0x8C010000, the copy stub's
    relocated block at 0x8C004000 and the boot entry.

    python tools/native_assets_check.py --assets build/vf3_assets
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import make_native_assets as mna  # noqa: E402
import make_boot_state as mbs      # noqa: E402

SECTOR = 2048
RAW = 2352
RAW_HDR = 16
ZERO = b"\x00" * SECTOR
UINT64_MAX = (1 << 64) - 1


def read_state(path: Path):
    data = path.read_bytes()
    entry = struct.unpack_from("<Q", data, 0)[0] >> 16
    regs = struct.unpack_from("<37Q", data, 8)
    # one windows record: count, base, len, then len words
    off = 8 * (1 + 37 + 1 + 16)
    tag = struct.unpack_from("<Q", data, off)[0]
    if tag & 0xFFFF != mbs.MARK_WINDOWS:
        raise SystemExit(f"{path}: no window record at {off:#x}")
    off += 8
    count, base, length = struct.unpack_from("<QQQ", data, off)
    off += 24
    if count != 1 or base != mbs.RAM_BASE or length != mbs.RAM_LEN:
        raise SystemExit(f"{path}: unexpected RAM window {count} {base:#x} {length:#x}")
    raw = struct.unpack_from(f"<{length // 4}Q", data, off)
    ram = b"".join(struct.pack("<I", w & 0xFFFFFFFF) for w in raw)
    return entry, regs, ram


def check_boot_state(assets: Path, image: Path) -> int:
    state_path = assets / "boot.state"
    entry, regs, ram = read_state(state_path)
    errors = 0
    if entry != 0x8C004000:
        print(f"boot.state: entry is 0x{entry:08x}, want 0x8c004000")
        errors += 1
    sp = regs[15] & 0xFFFFFFFF
    if sp != 0x8CFFFFE0:
        print(f"boot.state: sp is 0x{sp:08x}, want 0x8cffffe0")
        errors += 1
    blob = image.read_bytes()
    at = 0x10000
    if ram[at:at + len(blob)] != blob:
        print("boot.state: 1ST_READ.BIN does not match at 0x8c010000")
        errors += 1
    relocated = 0x4000
    if ram[relocated:relocated + 0x3F00] != ram[0x10100:0x14000]:
        print("boot.state: the copy stub's block is not at 0x8c004000")
        errors += 1
    # the BIOS service pointers
    for vec, target in mbs.BIOS_SERVICES.items():
        got = struct.unpack_from("<I", ram, vec & 0x00FFFFFF)[0]
        if got != target:
            print(f"boot.state: vector 0x{vec:08x} is 0x{got:08x}, want 0x{target:08x}")
            errors += 1
    print(f"boot.state: entry 0x{entry:08x}, sp 0x{sp:08x}, "
          f"{len(blob)} image bytes, {len(mbs.BIOS_SERVICES)} vectors")
    return errors


def check_disc(assets: Path, track: Path) -> int:
    path = assets / "disc.vf3"
    f = open(path, "rb")
    hdr = f.read(mna.NATIVE_HEADER if hasattr(mna, "NATIVE_HEADER") else 48)
    if hdr[:8] != mna.MAGIC:
        raise SystemExit(f"{path}: bad magic")
    version, sector_size, first_lba, nsectors = struct.unpack_from("<IIII", hdr, 8)
    index_offset, data_offset = struct.unpack_from("<QQ", hdr, 32)
    if version != mna.VERSION or sector_size != SECTOR:
        raise SystemExit(f"{path}: unsupported format {version}/{sector_size}")
    f.seek(index_offset)
    index = struct.unpack(f"<{nsectors}Q", f.read(8 * nsectors))

    t = open(track, "rb")
    track_sectors = track.stat().st_size // RAW
    if nsectors != track_sectors:
        print(f"disc.vf3: {nsectors} sectors, track has {track_sectors}")
        return 1
    f.seek(data_offset)
    stored = 0
    errors = 0
    for i in range(nsectors):
        raw = t.read(RAW)
        if len(raw) != RAW:
            print(f"track: short read at sector {i}")
            return 1
        user = raw[RAW_HDR:RAW_HDR + SECTOR]
        off = index[i]
        if user == ZERO:
            if off != UINT64_MAX:
                print(f"disc.vf3: sector {i} is zero in the track but stored")
                errors += 1
            continue
        if off == UINT64_MAX:
            print(f"disc.vf3: sector {i} is missing")
            errors += 1
            continue
        if off != f.tell() - data_offset:
            print(f"disc.vf3: sector {i} index is {off}, stream is at {f.tell() - data_offset}")
            errors += 1
        if f.read(SECTOR) != user:
            print(f"disc.vf3: sector {i} differs from the track")
            errors += 1
            if errors > 8:
                break
        stored += 1
    f.close()
    t.close()
    print(f"disc.vf3: {nsectors} sectors, {stored} stored, "
          f"{(nsectors - stored) * SECTOR / (1 << 20):.1f} MiB of zeros, "
          f"{errors} mismatch(es)")
    return errors


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n")[0])
    ap.add_argument("--assets", type=Path, default=Path("build/vf3_assets"))
    ap.add_argument("--gdi", type=Path, default=Path("rom/vf3.gdi"))
    ap.add_argument("--image", type=Path, default=Path("extract/gamedata/1ST_READ.BIN"))
    a = ap.parse_args()
    track, _lba, _size, _type = mna.parse_gdi(a.gdi)
    errors = check_boot_state(a.assets, a.image)
    errors += check_disc(a.assets, track)
    print("native bundle: OK" if errors == 0 else f"native bundle: {errors} error(s)")
    return 0 if errors == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
