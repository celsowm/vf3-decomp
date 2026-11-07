#!/usr/bin/env python3
"""Search POL packages for geometry used by live Flycast display-list nodes.

The report compares positions, vertex attributes, bounds and point counts. It
does not infer a bone map or certify a source asset from proximity alone.

Example:
  python tools/flycast_pol_asset_search.py \
      extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c \
      --entry 1 --pol-dir extract/gamedata --top 10
"""

from __future__ import annotations

import argparse
from collections import Counter
import json
import math
from pathlib import Path
import struct
import sys

from aica_state import load_state
from flycast_pol_node_match import (
    DESCRIPTOR_TABLE,
    SELECTOR_OFFSET,
    display_nodes,
    pol_mesh_bounds,
    rank_meshes,
    read_u32,
)
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram


ROOT = Path(__file__).resolve().parents[1]


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def repo_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def package_paths(files: list[Path] | None, directories: list[Path] | None,
                  pattern: str) -> list[Path]:
    selected = [repo_path(path) for path in (files or [])]
    for directory in directories or []:
        resolved = repo_path(directory)
        if not resolved.is_dir():
            raise ValueError(f"POL directory does not exist: {resolved}")
        selected.extend(path.resolve() for path in resolved.glob(pattern)
                        if path.is_file())
    unique = {path: None for path in selected}
    result = sorted(unique)
    if not result:
        raise ValueError("no POL packages selected")
    missing = [path for path in result if not path.is_file()]
    if missing:
        raise ValueError(f"POL package does not exist: {missing[0]}")
    return result


def texture_descriptors(data: bytes) -> list[dict[str, int]]:
    """Read the bounded 16-byte texture table from a POL package."""
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
            "raw_flags": raw_flags,
            "pixel_format": raw_flags & 0xFF,
            "data_format": (raw_flags >> 8) & 0xFF,
            "data_offset": data_offset,
            "reserved": reserved,
        })
    return result


def live_texture_header(tsp: int, tcw: int) -> dict[str, int]:
    return {
        "width": 8 << ((tsp >> 3) & 7),
        "height": 8 << (tsp & 7),
        "pixel_format": (tcw >> 27) & 7,
        "vq": (tcw >> 30) & 1,
        "mip": (tcw >> 31) & 1,
        "linear": (tcw >> 26) & 1,
        "vram_address": (tcw & 0x1FFFFF) << 3,
    }


def texture_header_match(live: dict[str, int], desc: dict[str, int]) -> bool:
    """Compare fields shared by a live TA header and a POL texture row.

    POL's format byte describes raw or VQ payload storage. The port's TEX
    decoder supports those payloads without mip chains; a match is therefore
    deliberately conservative and still does not prove the package was loaded.
    """
    expected_data_format = 3 if live["vq"] else 1
    return (not live["mip"] and
            (live["vq"] or not live["linear"]) and
            live["pixel_format"] <= 2 and
            desc["pixel_format"] <= 2 and
            desc["data_format"] in (1, 3) and
            desc["width"] == live["width"] and
            desc["height"] == live["height"] and
            desc["pixel_format"] == live["pixel_format"] and
            desc["data_format"] == expected_data_format)


def load_packages(paths: list[Path]) -> tuple[list[dict[str, object]], list[dict[str, str]]]:
    all_meshes: list[dict[str, object]] = []
    failures: list[dict[str, str]] = []
    for path in paths:
        try:
            data = path.read_bytes()
            meshes = pol_mesh_bounds(data)
            textures = texture_descriptors(data)
        except (OSError, ValueError, struct.error) as exc:
            failures.append({"package": str(path), "error": str(exc)})
            continue
        for mesh in meshes:
            mesh["_package"] = path.name
            mesh["_package_path"] = str(path)
            texture_index = int(mesh["texture"])
            mesh["_texture_descriptor"] = (
                textures[texture_index] if texture_index < len(textures) else None)
        all_meshes.extend(meshes)
    if not all_meshes:
        raise ValueError("no tagged POL meshes parsed from selected packages")
    return all_meshes, failures


def shortlist_meshes(node: dict[str, object], node_vertices: list[bytes],
                     meshes: list[dict[str, object]], top: int
                     ) -> tuple[list[dict[str, object]], list[dict[str, object]],
                                list[dict[str, object]]]:
    """Keep exact overlap candidates and a bounded set of plausible meshes.

    The full nearest-vertex ranker is useful for a handful of meshes, but its
    point-to-point work is too expensive over every package in the disc.
    Multiset overlap and mesh bounds cheaply retain exact matches and a broad
    fallback set for that detailed ranker.
    """
    node_positions = Counter(vertex[:12] for vertex in node_vertices)
    node_attributes = Counter(vertex[12:] for vertex in node_vertices)
    node_center = node["center"]
    node_radius = float(node["radius"])
    scored: list[tuple[tuple[float, ...], dict[str, object], bool]] = []
    exact_position: list[dict[str, object]] = []
    exact_attributes: list[dict[str, object]] = []
    for mesh in meshes:
        vertices = mesh["_vertices"]
        positions = Counter(vertex[:12] for vertex in vertices)
        attributes = Counter(vertex[12:] for vertex in vertices)
        position_overlap = sum((node_positions & positions).values())
        position_union = sum((node_positions | positions).values())
        attribute_overlap = sum((node_attributes & attributes).values())
        attribute_union = sum((node_attributes | attributes).values())
        pos_jaccard = position_overlap / position_union if position_union else 0.0
        attr_jaccard = attribute_overlap / attribute_union if attribute_union else 0.0
        is_exact = bool(node_vertices) and position_overlap == len(node_vertices)
        if is_exact:
            exact_position.append(mesh)
        if bool(node_vertices) and attribute_overlap == len(node_vertices):
            exact_attributes.append(mesh)
        center_delta = math.sqrt(sum((a - b) ** 2 for a, b in
                                     zip(node_center, mesh["center"])))
        radius_delta = abs(node_radius - float(mesh["radius"]))
        scale = max(abs(node_radius), abs(float(mesh["radius"])), 1.0e-6)
        scored.append(((-float(is_exact), -pos_jaccard, -attr_jaccard,
                        (center_delta + radius_delta) / scale,
                        center_delta, float(mesh["slot"]), float(mesh["mesh"])),
                       mesh, is_exact))

    # Include the strongest attribute candidates as well as geometry and
    # bounds candidates; this preserves evidence when the live stream has a
    # coordinate transform but still shares its source vertex attributes.
    feature_ranked = sorted(scored, key=lambda row: row[0])
    attribute_ranked = sorted(scored, key=lambda row: (
        row[0][2], row[0][3], row[0][4], row[0][5], row[0][6]))
    candidate_limit = max(64, top * 8)
    selected: dict[int, dict[str, object]] = {id(mesh): mesh for mesh in exact_position}
    for row in feature_ranked[:candidate_limit]:
        selected[id(row[1])] = row[1]
    for row in attribute_ranked[:candidate_limit]:
        selected[id(row[1])] = row[1]
    return list(selected.values()), exact_position, exact_attributes


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact 1ST_READ image loaded in the state")
    parser.add_argument("--image-address", type=address,
                        default=DEFAULT_IMAGE_ADDRESS)
    parser.add_argument("--actor", type=address, required=True,
                        help="fighter record address in guest RAM")
    entry_group = parser.add_mutually_exclusive_group()
    entry_group.add_argument("--entry", type=int, action="append",
                             help="zero-based attachment index; default: entry 1")
    entry_group.add_argument("--all-entries", action="store_true",
                             help="scan every selector entry")
    parser.add_argument("--count", type=int, default=18,
                        help="selector count (default: 18)")
    parser.add_argument("--selector-offset", type=address, default=SELECTOR_OFFSET)
    parser.add_argument("--descriptor-table", type=address, default=DESCRIPTOR_TABLE)
    parser.add_argument("--max-nodes", type=int, default=128)
    parser.add_argument("--pol", type=Path, action="append",
                        help="POL package to include; repeatable")
    parser.add_argument("--pol-dir", type=Path, action="append",
                        help="directory of POL packages; repeatable")
    parser.add_argument("--glob", default="*.POL",
                        help="package filename pattern for each --pol-dir")
    parser.add_argument("--top", type=int, default=10,
                        help="number of candidates to retain per ranking")
    parser.add_argument("--exact-only", action="store_true",
                        help="print only nodes with exact position or attribute matches")
    parser.add_argument("--json", action="store_true",
                        help="emit the complete machine-readable report")
    parser.add_argument("--out", type=Path,
                        help="write JSON to a new report file instead of stdout")
    args = parser.parse_args(argv)

    if not 1 <= args.count <= 64:
        parser.error("--count must be between 1 and 64")
    if not 1 <= args.max_nodes <= 4096:
        parser.error("--max-nodes must be between 1 and 4096")
    if not 1 <= args.top <= 100:
        parser.error("--top must be between 1 and 100")
    if args.all_entries:
        entries = list(range(args.count))
    else:
        entries = sorted(set(args.entry if args.entry is not None else [1]))
    if any(entry < 0 or entry >= args.count for entry in entries):
        parser.error(f"--entry values must be between 0 and {args.count - 1}")

    try:
        default_directories = ([Path("extract/gamedata")]
                               if not args.pol and not args.pol_dir else [])
        paths = package_paths(args.pol, args.pol_dir or default_directories,
                              args.glob)
        meshes, failures = load_packages(paths)
        meshes_by_key = {
            (mesh["_package"], mesh["slot"], mesh["mesh"]): mesh
            for mesh in meshes
        }
        image = repo_path(args.image).read_bytes()
        state = repo_path(args.state)
        blob = load_state(str(state))
        ram_offset, ram, anchor = locate_ram(blob, image, args.image_address, None)
        records: list[dict[str, object]] = []
        for entry in entries:
            selector_address = args.actor + args.selector_offset + entry * 4
            selector = read_u32(ram, selector_address)
            record: dict[str, object] = {
                "entry": entry,
                "selector": selector,
                "selector_address": selector_address,
            }
            if selector == 0xFFFFFFFF:
                record["status"] = "sentinel"
                records.append(record)
                continue
            if selector >= 0x01000000 // 4:
                record["status"] = "out_of_table_range"
                records.append(record)
                continue
            table_cell = args.descriptor_table + selector * 4
            descriptor = read_u32(ram, table_cell)
            record["table_cell"] = table_cell
            record["descriptor"] = descriptor
            if descriptor in (0, 0xFFFFFFFF):
                record["status"] = "empty"
                records.append(record)
                continue

            nodes = display_nodes(ram, descriptor, args.max_nodes)
            for node in nodes:
                node_vertices = node.pop("_vertices")
                live_header = live_texture_header(int(node["tsp"]), int(node["tex"]))
                node["texture_header"] = live_header
                candidates, exact_positions, exact_attrs = shortlist_meshes(
                    node, node_vertices, meshes, args.top)
                if args.exact_only:
                    exact_candidates = {id(mesh): mesh for mesh in
                                        exact_positions + exact_attrs}
                    if exact_candidates:
                        geometry, spheres, attributes = rank_meshes(
                            node, list(exact_candidates.values()), node_vertices,
                            len(exact_candidates))
                    else:
                        geometry, spheres, attributes = [], [], []
                else:
                    geometry, spheres, attributes = rank_meshes(
                        node, candidates, node_vertices,
                        max(args.top, len(candidates)))
                node["candidate_mesh_count"] = len(candidates)
                for ranking in (geometry, spheres, attributes):
                    for candidate in ranking:
                        mesh = meshes_by_key.get((candidate["package"],
                                                  candidate["slot"],
                                                  candidate["mesh"]))
                        descriptor = mesh.get("_texture_descriptor") if mesh else None
                        candidate["pol_texture_descriptor"] = descriptor
                        candidate["texture_header_match"] = bool(
                            descriptor and texture_header_match(live_header, descriptor))
                node["nearest_meshes"] = geometry[:args.top]
                node["sphere_nearest_meshes"] = spheres[:args.top]
                node["attribute_nearest_meshes"] = attributes[:args.top]
                live_count = len(node_vertices)
                node["exact_position_matches"] = [
                    candidate for candidate in geometry
                    if live_count and candidate["position_exact_count"] == live_count
                ]
                node["exact_attribute_matches"] = [
                    candidate for candidate in attributes
                    if live_count and candidate["attribute_overlap"] == live_count
                ]
            record["status"] = "resolved"
            record["nodes"] = nodes
            records.append(record)

        report = {
            "diagnostic_only": True,
            "state": str(state),
            "ram_offset": ram_offset,
            "ram_anchor": anchor,
            "actor": args.actor,
            "packages_scanned": len(paths),
            "mesh_count": len(meshes),
            "package_failures": failures,
            "entries": records,
            "limitations": [
                "Only tagged POL model records are compared.",
                "Candidate proximity does not prove a display-list source.",
                "A source-mesh match does not identify its transform or bone.",
            ],
        }
        if args.out:
            out = repo_path(args.out)
            if out.exists():
                parser.error(f"refusing to replace existing report: {out}")
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_text(json.dumps(report, indent=2, allow_nan=False) + "\n",
                           encoding="utf-8")
            print(f"report: {out}")
        elif args.json:
            print(json.dumps(report, indent=2, allow_nan=False))
        else:
            print(f"{state}: packages={len(paths)} meshes={len(meshes)} "
                  f"anchor={anchor}")
            for item in failures:
                print(f"  skipped {Path(item['package']).name}: {item['error']}")
            for record in records:
                if args.exact_only and record.get("status") == "resolved":
                    exact_nodes = [node for node in record["nodes"]
                                   if node["exact_position_matches"] or
                                   node["exact_attribute_matches"]]
                    if not exact_nodes:
                        continue
                    print(f"entry {record['entry']}: selector=0x{record['selector']:08x} "
                          f"exact_nodes={len(exact_nodes)}")
                    shown_nodes = exact_nodes
                else:
                    print(f"entry {record['entry']}: selector=0x{record['selector']:08x} "
                          f"status={record['status']}")
                    shown_nodes = record.get("nodes", [])
                if record.get("status") != "resolved":
                    continue
                for node in shown_nodes:
                    live_count = node["vertex_count"]
                    exact = node["exact_position_matches"]
                    exact_attrs = node["exact_attribute_matches"]
                    print(f"  node {node['index']} live={live_count} "
                          f"isp=0x{node['isp']:08x} tsp=0x{node['tsp']:08x} "
                          f"tex=0x{node['tex']:08x} "
                          f"texture={live_header['width']}x{live_header['height']} "
                          f"fmt={live_header['pixel_format']} vq={live_header['vq']} "
                          f"mip={live_header['mip']} lin={live_header['linear']}:")
                    if exact:
                        for candidate in exact:
                            descriptor = candidate["pol_texture_descriptor"]
                            texture_note = (f"texture_header_match={candidate['texture_header_match']} "
                                            f"texture={descriptor}" if descriptor else
                                            "texture_descriptor=missing")
                            print(f"    exact positions: {candidate['package']} "
                                  f"slot {candidate['slot']} mesh {candidate['mesh']} "
                                  f"pol_texture={candidate['pol_texture']} "
                                  f"{texture_note} "
                                  f"center_delta={candidate['center_delta']:.6g} "
                                  f"radius_delta={candidate['radius_delta']:.6g}")
                    else:
                        for candidate in node["nearest_meshes"][:3]:
                            print(f"    near: {candidate['package']} slot "
                                  f"{candidate['slot']} mesh {candidate['mesh']} "
                                  f"J={candidate['position_jaccard']:.4f} "
                                  f"mean={candidate['position_nearest_mean']:.6g}")
                    if exact_attrs:
                        for candidate in exact_attrs:
                            print(f"    exact attributes: {candidate['package']} "
                                  f"slot {candidate['slot']} mesh {candidate['mesh']} "
                                  f"pol_texture={candidate['pol_texture']} "
                                  f"center_delta={candidate['center_delta']:.6g} "
                                  f"radius_delta={candidate['radius_delta']:.6g}")
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"flycast_pol_asset_search: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
