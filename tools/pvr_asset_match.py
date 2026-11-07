#!/usr/bin/env python3
"""Match POL/TEX payloads against a retained PVR2 register/VRAM dump.

This is an offline evidence tool. Exact byte matches can link an extracted
texture payload to a captured VRAM allocation; a missing match does not prove
the package was unused because the capture may come from a different scene or
the upload path may have changed the bytes.

Example:
  python tools/pvr_asset_match.py extract/analysis/p3/ref_pvr_f300.bin \
      --pol extract/gamedata/MKAO_WO2.POL --tex extract/gamedata/MKAO_WO2.TEX \
      --address 0x6e0c80 --address 0x2e9000 --json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
import sys


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def pvr_vram(path: Path) -> tuple[bytes, int, int]:
    blob = path.read_bytes()
    if len(blob) < 8:
        raise ValueError("PVR2 dump is shorter than its 8-byte header")
    register_size, vram_size = struct.unpack_from("<II", blob)
    vram_start = 8 + register_size
    if vram_start > len(blob) or vram_size > len(blob) - vram_start:
        raise ValueError("PVR2 register/VRAM sizes exceed the dump")
    if vram_start + vram_size != len(blob):
        raise ValueError("PVR2 dump has trailing bytes outside its VRAM span")
    return blob[vram_start:], register_size, vram_size


def texture_descriptors(data: bytes) -> list[dict[str, int]]:
    if len(data) < 0x30:
        raise ValueError("POL file is shorter than its 0x30-byte header")
    count = struct.unpack_from("<H", data, 0x0E)[0]
    offset = struct.unpack_from("<I", data, 0x14)[0]
    if offset < 0x30 or offset > len(data) or count > (len(data) - offset) // 16:
        raise ValueError("POL texture table exceeds the package")
    result = []
    for index in range(count):
        width, height, raw_flags, data_offset, reserved = struct.unpack_from(
            "<HHIII", data, offset + index * 16)
        result.append({
            "index": index,
            "width": width,
            "height": height,
            "pixel_format": raw_flags & 0xFF,
            "data_format": (raw_flags >> 8) & 0xFF,
            "data_offset": data_offset,
            "reserved": reserved,
        })
    return result


def payload_size(desc: dict[str, int]) -> int | None:
    width, height = desc["width"], desc["height"]
    pixel_format, data_format = desc["pixel_format"], desc["data_format"]
    if (pixel_format > 2 or width == 0 or width != height or
            width & (width - 1)):
        return None
    pixels = width * height
    if data_format == 1:
        return pixels * 2
    if data_format == 3:
        return 2048 + pixels // 4
    return None


def all_offsets(haystack: bytes, needle: bytes) -> list[int]:
    if not needle:
        return []
    result = []
    offset = 0
    while True:
        found = haystack.find(needle, offset)
        if found < 0:
            return result
        result.append(found)
        offset = found + 1


def inspect_package(pvr: bytes, pol_path: Path, tex_path: Path,
                    addresses: list[int]) -> dict[str, object]:
    pol_data = pol_path.read_bytes()
    tex_data = tex_path.read_bytes()
    rows = []
    for desc in texture_descriptors(pol_data):
        size = payload_size(desc)
        start = desc["data_offset"]
        end = start + size if size is not None else start
        in_bounds = size is not None and end <= len(tex_data)
        payload = tex_data[start:end] if in_bounds else b""
        offsets = all_offsets(pvr, payload) if in_bounds else []
        rows.append({
            **desc,
            "payload_size": size,
            "payload_in_bounds": in_bounds,
            "vram_matches": [f"0x{offset:06x}" for offset in offsets[:32]],
            "vram_match_count": len(offsets),
            "live_address_hits": [f"0x{address:06x}" for address in addresses
                                   if address in offsets],
        })
    return {
        "pol": str(pol_path),
        "tex": str(tex_path),
        "texture_count": len(rows),
        "textures": rows,
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pvr_dump", type=Path,
                        help="PVR2 dump: u32 register bytes, u32 VRAM bytes, then both spans")
    parser.add_argument("--pol", type=Path, action="append", required=True,
                        help="POL package; repeat for package variants")
    parser.add_argument("--tex", type=Path, action="append", required=True,
                        help="companion TEX file, in the same order as --pol")
    parser.add_argument("--address", type=number, action="append", default=[],
                        help="live PVR texture address in bytes; repeatable")
    parser.add_argument("--json", action="store_true",
                        help="emit the complete machine-readable report")
    args = parser.parse_args(argv)
    if len(args.pol) != len(args.tex):
        parser.error("supply one --tex for each --pol, in the same order")
    if any(address >= 0x00800000 for address in args.address):
        parser.error("--address must be inside the 8 MiB PVR2 VRAM")

    try:
        vram, register_size, vram_size = pvr_vram(args.pvr_dump)
        reports = [inspect_package(vram, pol, tex, args.address)
                   for pol, tex in zip(args.pol, args.tex)]
        report = {
            "diagnostic_only": True,
            "pvr_dump": str(args.pvr_dump),
            "register_bytes": register_size,
            "vram_bytes": vram_size,
            "queried_addresses": [f"0x{address:06x}" for address in args.address],
            "packages": reports,
            "limitations": [
                "Exact matches link bytes, not a gameplay asset-selection rule.",
                "A missing match can reflect a different capture or upload path.",
                "Only raw and VQ, non-mipmapped payloads are sized here.",
            ],
        }
        if args.json:
            print(json.dumps(report, indent=2) + "\n", end="")
        else:
            print(f"{args.pvr_dump}: registers={register_size} VRAM={vram_size}")
            for package in reports:
                print(f"  {Path(str(package['pol'])).name} + "
                      f"{Path(str(package['tex'])).name}:")
                for desc in package["textures"]:
                    matches = desc["vram_matches"]
                    hits = desc["live_address_hits"]
                    print(f"    texture {desc['index']:2d} "
                          f"{desc['width']}x{desc['height']} fmt={desc['pixel_format']} "
                          f"data={desc['data_format']} bytes={desc['payload_size']} "
                          f"matches={desc['vram_match_count']} "
                          f"addresses={','.join(matches[:6]) or '-'} "
                          f"live_hits={','.join(hits) or '-'}")
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"pvr_asset_match: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
