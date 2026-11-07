#!/usr/bin/env python3
"""Inspect POL model and first-mesh headers for offline part mapping.

The native POL reader retains tagged model slots but does not interpret the
24-byte model header. This tool prints those raw words alongside the first
mesh's flags, center, radius, texture and vertex-data size. It is diagnostic:
the fields are not assumed to be bone IDs or transforms.

Examples:
  python tools/pol_model_headers.py extract/gamedata/MKAO_JAC.POL --slot 17 --slot 42
  python tools/pol_model_headers.py extract/gamedata/MKAO_JAC.POL --csv extract/analysis/jac_headers.csv
"""

from __future__ import annotations

import argparse
import csv
import math
from pathlib import Path
import struct
import sys

from pol_model_inventory import tagged_spans

MODEL_HEADER_SIZE = 0x18
MESH_HEADER_SIZE = 0x50


def inspect(data: bytes, selected_slots: set[int] | None = None) -> list[dict[str, object]]:
    _texture_count, ends, aliases = tagged_spans(data)
    result: list[dict[str, object]] = []
    for start in sorted(ends):
        end = ends[start]
        slots = aliases[start]
        if selected_slots is not None and not selected_slots.intersection(slots):
            continue
        if start + MODEL_HEADER_SIZE > end:
            raise ValueError(f"model at 0x{start:x} has a truncated header")
        words = struct.unpack_from("<6I", data, start)
        floats = struct.unpack_from("<6f", data, start)
        mesh = start + MODEL_HEADER_SIZE
        mesh_index = 0
        while mesh + 8 <= end:
            if struct.unpack_from("<I", data, mesh)[0] == 0:
                break
            if mesh + MESH_HEADER_SIZE > end:
                raise ValueError(f"mesh {mesh_index} at 0x{mesh:x} has a truncated header")
            vertex_bytes = struct.unpack_from("<I", data, mesh + 0x4C)[0]
            center = struct.unpack_from("<3f", data, mesh + 0x10)
            radius = struct.unpack_from("<f", data, mesh + 0x1C)[0]
            # The model header is deliberately reported as raw words too; some
            # words may encode integers rather than finite IEEE floats.
            if not all(math.isfinite(value) for value in (*center, radius)):
                raise ValueError(f"non-finite model/mesh header at 0x{mesh:x}")
            result.append({
                "slot": ",".join(str(slot) for slot in slots),
                "model_start": f"0x{start:06x}",
                "model_size": end - start,
                "model_words": " ".join(f"0x{word:08x}" for word in words),
                "model_floats": " ".join(f"{value:.8g}" for value in floats),
                "mesh": mesh_index,
                "mesh_flags": f"0x{struct.unpack_from('<I', data, mesh + 8)[0]:08x}",
                "mesh_center_x": center[0],
                "mesh_center_y": center[1],
                "mesh_center_z": center[2],
                "mesh_radius": radius,
                "texture": struct.unpack_from("<I", data, mesh + 0x20)[0],
                "vertex_data_bytes": vertex_bytes,
                "mesh_header_offset": f"0x{mesh:06x}",
            })
            mesh += MESH_HEADER_SIZE + vertex_bytes
            mesh_index += 1
        if mesh_index == 0:
            result.append({
                "slot": ",".join(str(slot) for slot in slots),
                "model_start": f"0x{start:06x}",
                "model_size": end - start,
                "model_words": " ".join(f"0x{word:08x}" for word in words),
                "model_floats": " ".join(f"{value:.8g}" for value in floats),
                "mesh": "", "mesh_flags": "", "mesh_center_x": "",
                "mesh_center_y": "", "mesh_center_z": "", "mesh_radius": "",
                "texture": "", "vertex_data_bytes": "", "mesh_header_offset": "",
            })
    return result


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", type=Path, help="extracted POL file")
    parser.add_argument("--slot", type=int, action="append",
                        help="include only this tagged slot; may be repeated")
    parser.add_argument("--csv", type=Path, help="write one row per mesh header")
    args = parser.parse_args(argv)
    if args.slot and any(slot < 0 for slot in args.slot):
        parser.error("--slot values must be nonnegative")
    try:
        rows = inspect(args.pol.read_bytes(), set(args.slot) if args.slot else None)
        if args.csv:
            args.csv.parent.mkdir(parents=True, exist_ok=True)
            fields = list(rows[0]) if rows else ["slot", "model_start", "model_words"]
            with args.csv.open("w", newline="", encoding="utf-8") as handle:
                writer = csv.DictWriter(handle, fieldnames=fields)
                writer.writeheader()
                writer.writerows(rows)
            print(f"wrote {args.csv} ({len(rows)} mesh rows)")
        else:
            print(f"{args.pol.name}: {len(rows)} model/mesh header rows")
            for row in rows:
                print(f"slot={row['slot']:>5} model={row['model_start']}"
                      f" words=[{row['model_words']}] mesh={row['mesh']}"
                      f" flags={row['mesh_flags']} center=({row['mesh_center_x']},"
                      f" {row['mesh_center_y']}, {row['mesh_center_z']})"
                      f" radius={row['mesh_radius']} tex={row['texture']}"
                      f" data={row['vertex_data_bytes']}")
    except (OSError, ValueError, struct.error) as exc:
        print(f"pol_model_headers: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
