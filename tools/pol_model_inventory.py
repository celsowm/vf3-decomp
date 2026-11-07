#!/usr/bin/env python3
"""List tagged POL models and mesh bounds for offline asset investigation.

The native scene parser retains tagged slot identities, while a flat render
does not show which parts each slot contains. This read-only tool reports
per-slot/per-mesh geometry bounds, vertex-reference counts, and texture IDs.

Usage:
  python tools/pol_model_inventory.py extract/gamedata/MKAO_AKI.POL
  python tools/pol_model_inventory.py extract/gamedata/MKAO_JAC.POL --csv akira.csv
"""

from __future__ import annotations

import argparse
import csv
import math
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path


@dataclass
class Mesh:
    texture: int | None
    vertices: int = 0
    references: int = 0
    index_count: int = 0
    low: list[float] = field(default_factory=lambda: [math.inf] * 3)
    high: list[float] = field(default_factory=lambda: [-math.inf] * 3)

    def add(self, xyz: tuple[float, float, float]) -> None:
        self.vertices += 1
        for axis, value in enumerate(xyz):
            self.low[axis] = min(self.low[axis], value)
            self.high[axis] = max(self.high[axis], value)

    def bounds(self) -> str:
        if not self.vertices:
            return "empty"
        return " ".join(f"{self.low[i]:.5g}..{self.high[i]:.5g}" for i in range(3))


@dataclass
class Model:
    slot: int
    start: int
    end: int
    meshes: list[Mesh]


def u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def span_check(offset: int, size: int, end: int, what: str) -> None:
    if offset < 0 or size < 0 or offset > end or size > end - offset:
        raise ValueError(f"{what} at 0x{offset:x} with size 0x{size:x} exceeds 0x{end:x}")


def tagged_spans(data: bytes) -> tuple[int, dict[int, int], dict[int, list[int]]]:
    if len(data) < 0x30:
        raise ValueError("file is shorter than the 0x30-byte POL header")
    slot_count = u16(data, 0x0C)
    slot_off = u32(data, 0x10)
    span_check(slot_off, slot_count * 4, len(data), "slot table")
    slots = [u32(data, slot_off + i * 4) for i in range(slot_count)]
    aliases: dict[int, list[int]] = {}
    for slot, raw in enumerate(slots):
        if raw & 1:
            start = raw & ~1
            if start < 0x30 or start >= len(data):
                raise ValueError(f"tagged slot {slot} points outside the file: 0x{raw:x}")
            aliases.setdefault(start, []).append(slot)
    starts = sorted(aliases)
    if not starts:
        return u16(data, 0x0E), {}, aliases
    ends = {start: starts[i + 1] if i + 1 < len(starts) else len(data)
            for i, start in enumerate(starts)}
    return u16(data, 0x0E), ends, aliases


def parse_models(data: bytes) -> list[Model]:
    texture_count, ends, aliases = tagged_spans(data)
    source_vertices: dict[int, tuple[float, float, float]] = {}
    models: list[Model] = []

    for start in sorted(ends):
        end = ends[start]
        span_check(start, 0x20, end, f"model slot {aliases[start][0]} header")
        pos = start + 0x18
        meshes: list[Mesh] = []
        while pos + 8 <= end:
            if u32(data, pos) == 0:
                pos += 8
                if any(data[pos:end]):
                    raise ValueError(f"nonzero padding after model terminator at 0x{pos - 8:x}")
                break
            span_check(pos, 0x50, end, "mesh header")
            texture_raw = u32(data, pos + 0x20)
            texture = None if texture_raw == 0xFFFFFFFF else texture_raw
            if texture is not None and texture >= texture_count:
                raise ValueError(f"mesh at 0x{pos:x} references texture {texture}, count is {texture_count}")
            data_size = u32(data, pos + 0x4C)
            data_start = pos + 0x50
            data_end = data_start + data_size
            span_check(data_start, data_size, end, "mesh polygon data")
            mesh = Mesh(texture=texture)
            cursor = data_start
            while cursor < data_end:
                span_check(cursor, 8, data_end, "polygon header")
                kind, count = struct.unpack_from("<II", data, cursor)
                cursor += 8
                record_count = count * 3 if kind & 8 else count
                mesh.index_count += count if kind & 8 else max(0, count - 2) * 3
                for _ in range(record_count):
                    remaining = data_end - cursor
                    span_check(cursor, 8, data_end, "vertex record prefix")
                    second = u32(data, cursor + 4)
                    exponent = second & 0x7F800000
                    mantissa = second & 0x007FFFFF
                    if exponent == 0x7F800000 and mantissa:
                        back = 0xFFFFFFF8 - second
                        if second >= 0xFFFFFFF8 or back == 0 or back > cursor:
                            raise ValueError(f"invalid backward vertex reference at 0x{cursor:x}")
                        target = cursor - back
                        xyz = source_vertices.get(target)
                        if xyz is None:
                            raise ValueError(f"unresolved backward vertex reference 0x{cursor:x} -> 0x{target:x}")
                        mesh.references += 1
                        source_vertices[cursor] = xyz
                        cursor += 8
                    else:
                        span_check(cursor, 0x20, data_end, "vertex")
                        values = struct.unpack_from("<8f", data, cursor)
                        if not all(math.isfinite(value) for value in values):
                            raise ValueError(f"non-finite vertex at 0x{cursor:x}")
                        xyz = values[:3]
                        source_vertices[cursor] = xyz
                        cursor += 0x20
                    mesh.add(xyz)
                if cursor > data_end:
                    raise ValueError(f"polygon data overrun at 0x{cursor:x}")
            if cursor != data_end:
                raise ValueError(f"mesh data ended at 0x{cursor:x}, expected 0x{data_end:x}")
            meshes.append(mesh)
            pos = data_end
        else:
            raise ValueError(f"model slot {aliases[start][0]} has no terminator before 0x{end:x}")

        for slot in aliases[start]:
            models.append(Model(slot, start, end, meshes))
    return models


def rows(models: list[Model]) -> list[dict[str, object]]:
    output: list[dict[str, object]] = []
    for model in models:
        for mesh_index, mesh in enumerate(model.meshes):
            output.append({
                "slot": model.slot,
                "model_start": f"0x{model.start:06x}",
                "model_size": model.end - model.start,
                "mesh": mesh_index,
                "texture": "none" if mesh.texture is None else mesh.texture,
                "vertex_records": mesh.vertices,
                "back_references": mesh.references,
                "indices": mesh.index_count,
                "x_bounds": "empty" if not mesh.vertices else f"{mesh.low[0]:.7g}..{mesh.high[0]:.7g}",
                "y_bounds": "empty" if not mesh.vertices else f"{mesh.low[1]:.7g}..{mesh.high[1]:.7g}",
                "z_bounds": "empty" if not mesh.vertices else f"{mesh.low[2]:.7g}..{mesh.high[2]:.7g}",
            })
    return output


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", type=Path, help="extracted POL file")
    parser.add_argument("--csv", type=Path, help="write one row per model mesh")
    args = parser.parse_args(argv)
    try:
        data = args.pol.read_bytes()
        models = parse_models(data)
        result = rows(models)
        if args.csv:
            with args.csv.open("w", newline="", encoding="utf-8") as handle:
                writer = csv.DictWriter(handle, fieldnames=list(result[0]) if result else ["slot"])
                writer.writeheader()
                writer.writerows(result)
            print(f"wrote {args.csv} ({len(result)} mesh rows)")
        else:
            print(f"{args.pol.name}: {len(models)} tagged model slots, {len(result)} meshes")
            print("slot  model-start size    mesh tex vertices refs indices  x bounds       y bounds       z bounds")
            for row in result:
                print(f"{row['slot']:4}  {row['model_start']:>11} {row['model_size']:6}"
                      f" {row['mesh']:4} {row['texture']:3} {row['vertex_records']:8}"
                      f" {row['back_references']:4} {row['indices']:7}  "
                      f"{row['x_bounds']:>13} {row['y_bounds']:>13} {row['z_bounds']:>13}")
    except (OSError, ValueError, struct.error) as exc:
        print(f"pol_model_inventory: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
