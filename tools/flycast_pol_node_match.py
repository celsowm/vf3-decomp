#!/usr/bin/env python3
"""Compare live display-list nodes with tagged POL meshes.

The report is an offline matching aid. Point proximity, sphere proximity, and
attribute overlap or actor-matrix transforms are candidate signals, not a part
mapping.
Review them alongside the draw path and geometry.

Example:
  python tools/flycast_pol_node_match.py tools/emu/flycast-build/data/vf3_27.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c \
      --pol extract/gamedata/MKAO_JAC.POL --top 3
"""

from __future__ import annotations

import argparse
from collections import Counter
import json
from itertools import combinations
import math
from pathlib import Path
import struct
import sys

from aica_state import load_state
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram


SELECTOR_OFFSET = 0x6C
DESCRIPTOR_TABLE = 0x0C2A1C3C
DISPLAY_LIST_HEADER_BYTES = 0x18
NODE_FIXED_BYTES = 0x50
MAX_NODE_DATA_BYTES = 0x100000


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def read_u32(ram: bytes, address_: int) -> int:
    return struct.unpack("<I", read_ram(ram, address_, 4))[0]


def read_f32(ram: bytes, address_: int) -> float:
    return struct.unpack("<f", read_ram(ram, address_, 4))[0]


def pol_u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def pol_u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def checked(offset: int, size: int, end: int, label: str) -> None:
    if offset < 0 or size < 0 or offset > end or size > end - offset:
        raise ValueError(f"{label} at 0x{offset:x} + 0x{size:x} exceeds 0x{end:x}")


def pol_mesh_bounds(data: bytes) -> list[dict[str, object]]:
    if len(data) < 0x30:
        raise ValueError("POL file is shorter than its 0x30-byte header")
    slot_count = pol_u16(data, 0x0C)
    slot_table = pol_u32(data, 0x10)
    checked(slot_table, slot_count * 4, len(data), "POL slot table")

    aliases: dict[int, list[int]] = {}
    for slot in range(slot_count):
        raw = pol_u32(data, slot_table + slot * 4)
        if raw & 1:
            start = raw & ~1
            checked(start, 0x18, len(data), f"tagged slot {slot}")
            aliases.setdefault(start, []).append(slot)
    starts = sorted(aliases)
    ends = {start: starts[i + 1] if i + 1 < len(starts) else len(data)
            for i, start in enumerate(starts)}

    source_vertices: dict[int, bytes] = {}
    meshes: list[dict[str, object]] = []
    for start in starts:
        end = ends[start]
        cursor = start + 0x18
        mesh_index = 0
        while True:
            checked(cursor, 8, end, f"slot {aliases[start][0]} model terminator")
            if pol_u32(data, cursor) == 0:
                break
            checked(cursor, 0x50, end, f"slot {aliases[start][0]} mesh header")
            data_size = pol_u32(data, cursor + 0x4C)
            checked(cursor + 0x50, data_size, end,
                    f"slot {aliases[start][0]} mesh data")
            data_cursor = cursor + 0x50
            data_end = data_cursor + data_size
            vertex_records = 0
            index_count = 0
            vertices: list[bytes] = []
            while data_cursor < data_end:
                checked(data_cursor, 8, data_end, "POL polygon header")
                kind = pol_u32(data, data_cursor)
                count = pol_u32(data, data_cursor + 4)
                data_cursor += 8
                record_count = count * 3 if kind & 8 else count
                index_count += count if kind & 8 else max(0, count - 2) * 3
                vertex_records += record_count
                for _ in range(record_count):
                    checked(data_cursor, 8, data_end, "POL vertex record")
                    second = pol_u32(data, data_cursor + 4)
                    is_reference = ((second & 0x7F800000) == 0x7F800000 and
                                    (second & 0x007FFFFF) != 0)
                    record_size = 8 if is_reference else 0x20
                    checked(data_cursor, record_size, data_end, "POL vertex")
                    if is_reference:
                        if second >= 0xFFFFFFF8:
                            raise ValueError(f"invalid POL vertex reference at 0x{data_cursor:x}")
                        target = data_cursor - (0xFFFFFFF8 - second)
                        body = source_vertices.get(target)
                        if body is None:
                            raise ValueError(f"unresolved POL vertex reference at 0x{data_cursor:x}")
                    else:
                        body_data = bytearray(data[data_cursor:data_cursor + 0x20])
                        x_bits = struct.unpack_from("<I", body_data)[0] & 0xFFFFFFFE
                        struct.pack_into("<I", body_data, 0, x_bits)
                        body = bytes(body_data)
                    source_vertices[data_cursor] = body
                    vertices.append(body)
                    data_cursor += record_size
            if data_cursor != data_end:
                raise ValueError(f"POL mesh data ended at 0x{data_cursor:x}, "
                                 f"expected 0x{data_end:x}")
            center = struct.unpack_from("<3f", data, cursor + 0x10)
            radius = struct.unpack_from("<f", data, cursor + 0x1C)[0]
            if not all(math.isfinite(value) for value in (*center, radius)):
                raise ValueError(f"non-finite bounds in POL mesh at 0x{cursor:x}")
            for slot in aliases[start]:
                meshes.append({
                    "slot": slot,
                    "model_start": start,
                    "mesh": mesh_index,
                    "mesh_header": cursor,
                    "center": center,
                    "radius": radius,
                    "data_bytes": data_size,
                    "vertex_records": vertex_records,
                    "index_count": index_count,
                    "texture": pol_u32(data, cursor + 0x20),
                    "_vertices": vertices,
                })
            cursor += 0x50 + data_size
            mesh_index += 1
    return meshes


def display_nodes(ram: bytes, descriptor: int, max_nodes: int) -> list[dict[str, object]]:
    cursor = descriptor + DISPLAY_LIST_HEADER_BYTES
    result: list[dict[str, object]] = []
    for index in range(max_nodes):
        pcw = read_u32(ram, cursor)
        if pcw == 0:
            break
        center = tuple(read_f32(ram, cursor + 0x10 + axis * 4)
                       for axis in range(3))
        radius = read_f32(ram, cursor + 0x1C)
        size = read_u32(ram, cursor + 0x4C)
        if not all(math.isfinite(value) for value in (*center, radius)):
            raise ValueError(f"non-finite live sphere at 0x{cursor + 0x10:x}")
        if size > MAX_NODE_DATA_BYTES:
            raise ValueError(f"node at 0x{cursor:x} has implausible payload size 0x{size:x}")
        strip_word = read_u32(ram, cursor + NODE_FIXED_BYTES)
        strip_count = (read_u32(ram, cursor + NODE_FIXED_BYTES + 4)
                       if size >= 8 and strip_word != 0 else None)
        first_record = (read_ram(ram, cursor + NODE_FIXED_BYTES + 8, 8).hex()
                        if size >= 16 and strip_count else None)
        vertices, decode_status, strip_trace = display_node_vertices(ram, cursor, size)
        result.append({
            "index": index,
            "pcw_address": cursor,
            "pcw": pcw,
            "isp": read_u32(ram, cursor + 4),
            "tsp": read_u32(ram, cursor + 8),
            "tex": read_u32(ram, cursor + 12),
            "center": center,
            "radius": radius,
            "payload_bytes": size,
            "first_strip_word": strip_word,
            "first_strip_count": strip_count,
            "first_record_head": first_record,
            "vertex_decode_status": decode_status,
            "vertex_count": len(vertices),
            "strip_trace": strip_trace,
            "_vertices": vertices,
        })
        cursor += NODE_FIXED_BYTES + size
    else:
        raise ValueError(f"display list at 0x{descriptor:x} exceeded --max-nodes")
    return result


def display_node_vertices(ram: bytes, node: int, payload_bytes: int
                          ) -> tuple[list[bytes], str, list[dict[str, int]]]:
    """Decode inline/indirect 32-byte vertex records in ordinary lit strips."""
    start = node + NODE_FIXED_BYTES
    end = start + payload_bytes
    strip = start
    vertices: list[bytes] = []
    trace: list[dict[str, int]] = []
    for _ in range(10000):
        if strip + 4 > end:
            return vertices, "missing-strip-terminator", trace
        strip_word = read_u32(ram, strip)
        if strip_word == 0 or strip_word & 0x80000000:
            return vertices, "ok", trace
        if strip_word & 0x0C:
            return vertices, f"unsupported-strip-0x{strip_word:08x}", trace
        if strip + 8 > end:
            return vertices, "truncated-strip-header", trace
        count = read_u32(ram, strip + 4)
        records = strip + 8
        descriptor_at = strip
        if count > (end - records) // 8:
            return vertices, "strip-count-exceeds-node-payload", trace

        while True:
            count_at = records - 4
            vertex_start = records
            for _ in range(count):
                if records + 8 > end:
                    return vertices, "truncated-vertex-record", trace
                head = read_u32(ram, records)
                if head & 1:
                    body_address = records
                    next_record = records + 0x20
                else:
                    offset = read_u32(ram, records + 4)
                    body_address = (records + 8 + offset) & 0xFFFFFFFF
                    next_record = records + 8
                if next_record > end:
                    return vertices, "vertex-record-exceeds-node-payload", trace
                body = bytearray(read_ram(ram, body_address, 0x20))
                x_bits = struct.unpack_from("<I", body)[0] & 0xFFFFFFFE
                struct.pack_into("<I", body, 0, x_bits)
                vertices.append(bytes(body))
                records = next_record

            # The non-positive word after the final strip is the next node's
            # PCW, exactly at `end`; the native walker reads it before the
            # next node is parsed.
            if records > end:
                return vertices, "missing-strip-trailer", trace
            next_strip = read_u32(ram, records)
            if next_strip == 0 or next_strip & 0x80000000:
                trace.append({"descriptor": strip_word, "descriptor_at": descriptor_at,
                              "count": count, "count_at": count_at,
                              "vertex_start": vertex_start, "records_end": records,
                              "trailer": records, "flags": next_strip,
                              "chained": 0})
                return vertices, "ok", trace
            if records + 8 > end:
                return vertices, "truncated-strip-trailer", trace
            next_count = read_u32(ram, records + 4)
            if next_strip & 0x80:
                trace.append({"descriptor": strip_word, "descriptor_at": descriptor_at,
                              "count": count, "count_at": count_at,
                              "vertex_start": vertex_start, "records_end": records,
                              "trailer": records, "flags": next_strip,
                              "chained": 1})
                records += 8
                count = next_count
                if count > (end - records) // 8:
                    return vertices, "chained-strip-count-exceeds-node-payload", trace
                continue
            trace.append({"descriptor": strip_word, "descriptor_at": descriptor_at,
                          "count": count, "count_at": count_at,
                          "vertex_start": vertex_start, "records_end": records,
                          "trailer": records, "flags": next_strip,
                          "chained": 0})
            strip = records
            break
    return vertices, "strip-limit-exceeded", trace


def rank_meshes(node: dict[str, object], meshes: list[dict[str, object]],
                node_vertices: list[bytes], top: int
                ) -> tuple[list[dict[str, object]], list[dict[str, object]],
                           list[dict[str, object]]]:
    node_center = node["center"]
    node_radius = float(node["radius"])
    node_counts = Counter(node_vertices)
    node_position_counts = Counter(vertex[:12] for vertex in node_vertices)
    node_attribute_counts = Counter(vertex[12:] for vertex in node_vertices)
    live_xyz = [struct.unpack_from("<3f", vertex) for vertex in node_vertices]
    ranked = []
    for mesh in meshes:
        mesh_center = mesh["center"]
        mesh_radius = float(mesh["radius"])
        center_delta = math.sqrt(sum((a - b) ** 2
                                     for a, b in zip(node_center, mesh_center)))
        radius_delta = abs(node_radius - mesh_radius)
        scale = max(abs(node_radius), abs(mesh_radius), 1.0e-6)
        mesh_counts = Counter(mesh["_vertices"])
        overlap = sum((node_counts & mesh_counts).values())
        union = sum((node_counts | mesh_counts).values())
        mesh_position_counts = Counter(vertex[:12] for vertex in mesh["_vertices"])
        position_overlap = sum((node_position_counts & mesh_position_counts).values())
        position_union = sum((node_position_counts | mesh_position_counts).values())
        mesh_attribute_counts = Counter(vertex[12:] for vertex in mesh["_vertices"])
        attribute_overlap = sum((node_attribute_counts & mesh_attribute_counts).values())
        attribute_union = sum((node_attribute_counts | mesh_attribute_counts).values())
        mesh_xyz = [struct.unpack_from("<3f", vertex) for vertex in mesh["_vertices"]]
        nearest_sq = [min(sum((a - b) ** 2 for a, b in zip(point, candidate))
                          for candidate in mesh_xyz)
                      for point in live_xyz] if mesh_xyz else []
        nearest_mean = (sum(math.sqrt(value) for value in nearest_sq) / len(nearest_sq)
                        if nearest_sq else math.inf)
        exact_position_count = sum(value < 1.0e-12 for value in nearest_sq)
        ranked.append({
            "package": mesh.get("_package", ""),
            "slot": mesh["slot"],
            "mesh": mesh["mesh"],
            "model_start": mesh["model_start"],
            "pol_center": mesh_center,
            "pol_radius": mesh_radius,
                        "pol_data_bytes": mesh["data_bytes"],
                        "pol_vertex_records": mesh["vertex_records"],
                        "pol_index_count": mesh["index_count"],
                        "pol_texture": mesh["texture"],
            "vertex_overlap": overlap,
            "live_vertex_count": len(node_vertices),
            "pol_vertex_count": len(mesh["_vertices"]),
            "vertex_jaccard": overlap / union if union else 0.0,
            "position_overlap": position_overlap,
            "position_jaccard": (position_overlap / position_union
                                 if position_union else 0.0),
            "attribute_overlap": attribute_overlap,
            "attribute_jaccard": (attribute_overlap / attribute_union
                                  if attribute_union else 0.0),
            "position_nearest_mean": nearest_mean,
            "position_exact_count": exact_position_count,
            "center_delta": center_delta,
            "radius_delta": radius_delta,
            "normalized_score": (center_delta + radius_delta) / scale,
        })
    geometry_ranked = sorted(ranked, key=lambda row: (
        -row["vertex_jaccard"], -row["position_jaccard"],
        row["position_nearest_mean"], row["slot"], row["mesh"]))[:top]
    sphere_ranked = sorted(ranked, key=lambda row: (
        row["normalized_score"], row["center_delta"], row["radius_delta"],
        row["slot"], row["mesh"]))[:top]
    attribute_ranked = sorted(ranked, key=lambda row: (
        -row["attribute_jaccard"], -row["attribute_overlap"],
        row["slot"], row["mesh"]))[:top]
    if not attribute_ranked or attribute_ranked[0]["attribute_overlap"] == 0:
        attribute_ranked = []
    return geometry_ranked, sphere_ranked, attribute_ranked


def solve_linear4(matrix: list[list[float]], rhs: list[float]) -> list[float] | None:
    """Solve a 4x4 system with partial pivoting and a scale-relative guard."""
    augmented = [row[:] + [rhs[index]] for index, row in enumerate(matrix)]
    scale = max((abs(value) for row in matrix for value in row), default=0.0)
    if not math.isfinite(scale) or scale == 0.0:
        return None
    for column in range(4):
        pivot = max(range(column, 4), key=lambda row: abs(augmented[row][column]))
        if abs(augmented[pivot][column]) <= scale * 1.0e-12:
            return None
        augmented[column], augmented[pivot] = augmented[pivot], augmented[column]
        divisor = augmented[column][column]
        augmented[column] = [value / divisor for value in augmented[column]]
        for row in range(4):
            if row == column:
                continue
            factor = augmented[row][column]
            if factor:
                augmented[row] = [a - factor * b
                                  for a, b in zip(augmented[row], augmented[column])]
    result = [augmented[row][4] for row in range(4)]
    return result if all(math.isfinite(value) for value in result) else None


def affine_fit_candidates(node_vertices: list[bytes],
                          meshes: list[dict[str, object]],
                          top: int) -> list[dict[str, object]]:
    """Fit each equal-count POL mesh to the live vertices in record order.

    This tests whether a display node is a mesh transformed by one affine
    matrix. It intentionally does not reorder vertices or infer a rig.
    """
    if len(node_vertices) < 4:
        return []
    targets = [struct.unpack_from("<3f", vertex) for vertex in node_vertices]
    if any(not math.isfinite(value) for point in targets for value in point):
        return []
    ranked: list[dict[str, object]] = []
    for mesh in meshes:
        vertices = mesh["_vertices"]
        if len(vertices) != len(targets):
            continue
        features = [(*struct.unpack_from("<3f", vertex), 1.0)
                    for vertex in vertices]
        if any(not math.isfinite(value) for point in features for value in point):
            continue
        normal = [[0.0] * 4 for _ in range(4)]
        rhs = [[0.0] * 4 for _ in range(3)]
        for feature, target in zip(features, targets):
            for row in range(4):
                for column in range(4):
                    normal[row][column] += feature[row] * feature[column]
                for axis in range(3):
                    rhs[axis][row] += feature[row] * target[axis]
        coefficients = [solve_linear4(normal, rhs[axis]) for axis in range(3)]
        if any(row is None for row in coefficients):
            continue
        transform = [tuple(row) for row in coefficients if row is not None]
        squared_errors: list[float] = []
        max_error = 0.0
        for feature, target in zip(features, targets):
            predicted = tuple(sum(coefficient[i] * feature[i]
                                  for i in range(4))
                              for coefficient in transform)
            error = math.sqrt(sum((a - b) ** 2
                                  for a, b in zip(predicted, target)))
            squared_errors.append(error * error)
            max_error = max(max_error, error)
        rms_error = math.sqrt(sum(squared_errors) / len(squared_errors))
        radius = max(abs(float(mesh["radius"])), 1.0e-6)
        ranked.append({
            "slot": mesh["slot"],
            "mesh": mesh["mesh"],
            "point_count": len(targets),
            "rms_error": rms_error,
            "normalized_rms_error": rms_error / radius,
            "max_error": max_error,
            "transform": transform,
        })
    ranked.sort(key=lambda candidate: (candidate["normalized_rms_error"],
                                        candidate["rms_error"],
                                        candidate["max_error"],
                                        candidate["slot"], candidate["mesh"]))
    return ranked[:top]


def pair_distance_signature(vertices: list[bytes], bins: int = 96
                             ) -> tuple[float, ...] | None:
    """Return a scale-normalized, order-independent point-cloud signature.

    The cumulative histogram of pairwise distances is invariant to vertex
    ordering, translation, rotation, and uniform scale. It is useful for
    finding candidate source meshes when the live renderer has reordered the
    records, but it cannot identify a unique mesh or recover its transform.
    """
    if len(vertices) < 2 or bins < 2:
        return None
    points = [struct.unpack_from("<3f", vertex) for vertex in vertices]
    if any(not math.isfinite(value) for point in points for value in point):
        return None
    low = [min(point[axis] for point in points) for axis in range(3)]
    high = [max(point[axis] for point in points) for axis in range(3)]
    diagonal = math.sqrt(sum((high[axis] - low[axis]) ** 2
                             for axis in range(3)))
    if not math.isfinite(diagonal) or diagonal <= 1.0e-12:
        return None
    histogram = [0] * bins
    pair_count = 0
    for index, point in enumerate(points[:-1]):
        for other in points[index + 1:]:
            distance = math.sqrt(sum((a - b) ** 2
                                     for a, b in zip(point, other))) / diagonal
            bucket = min(bins - 1, int(distance * bins))
            histogram[bucket] += 1
            pair_count += 1
    if pair_count == 0:
        return None
    cumulative = []
    running = 0
    for count in histogram:
        running += count
        cumulative.append(running / pair_count)
    return tuple(cumulative)


def unordered_shape_candidates(node_vertices: list[bytes],
                               meshes: list[dict[str, object]],
                               top: int, bins: int = 96,
                               signature_cache: dict[int, tuple[float, ...] | None] | None = None
                               ) -> list[dict[str, object]]:
    """Rank meshes by order-independent pairwise-distance distributions."""
    live_signature = pair_distance_signature(node_vertices, bins)
    if live_signature is None:
        return []
    if signature_cache is None:
        signature_cache = {}
    ranked: list[dict[str, object]] = []
    for mesh in meshes:
        key = id(mesh)
        if key not in signature_cache:
            signature_cache[key] = pair_distance_signature(mesh["_vertices"], bins)
        signature = signature_cache[key]
        if signature is None:
            continue
        score = sum(abs(live - source)
                    for live, source in zip(live_signature, signature)) / bins
        ranked.append({
            "slot": mesh["slot"],
            "mesh": mesh["mesh"],
            "point_count": len(mesh["_vertices"]),
            "live_point_count": len(node_vertices),
            "normalized_distance_cdf_error": score,
            "histogram_bins": bins,
        })
    ranked.sort(key=lambda item: (item["normalized_distance_cdf_error"],
                                  abs(item["point_count"] - item["live_point_count"]),
                                  item["slot"], item["mesh"]))
    return ranked[:top]


def composite_shape_candidates(node_vertices: list[bytes],
                               meshes: list[dict[str, object]],
                               top: int, bins: int = 96,
                               count_slack: float = 0.15
                               ) -> list[dict[str, object]]:
    """Rank two-mesh unions against a live node's point-cloud signature.

    Some live display nodes may batch more than one POL mesh. This diagnostic
    checks pairs whose combined vertex-record count is near the node count;
    source meshes are concatenated in their stored local coordinates. A low
    score is only a candidate because per-part transforms or clipping can
    change the point cloud assembled by the renderer.
    """
    live_signature = pair_distance_signature(node_vertices, bins)
    if live_signature is None:
        return []
    live_count = len(node_vertices)
    allowed_delta = max(2, int(math.ceil(live_count * count_slack)))
    candidates = [mesh for mesh in meshes
                  if 0 < len(mesh["_vertices"]) < live_count + allowed_delta]
    ranked: list[dict[str, object]] = []
    for first, second in combinations(candidates, 2):
        vertices = first["_vertices"] + second["_vertices"]
        count_delta = len(vertices) - live_count
        if abs(count_delta) > allowed_delta:
            continue
        signature = pair_distance_signature(vertices, bins)
        if signature is None:
            continue
        score = sum(abs(live - source)
                    for live, source in zip(live_signature, signature)) / bins
        ordered_affine = None
        if count_delta == 0 and live_count >= 4:
            trial = {
                "slot": first["slot"],
                "mesh": first["mesh"],
                "radius": max(float(first["radius"]), float(second["radius"]),
                              1.0e-6),
            }
            fits = []
            for order, ordered_vertices in (
                    ("first_then_second", vertices),
                    ("second_then_first", second["_vertices"] + first["_vertices"])):
                trial["_vertices"] = ordered_vertices
                fit = affine_fit_candidates(node_vertices, [trial], 1)
                if fit:
                    fits.append({
                        "order": order,
                        "rms_error": fit[0]["rms_error"],
                        "normalized_rms_error": fit[0]["normalized_rms_error"],
                        "transform": fit[0]["transform"],
                    })
            if fits:
                ordered_affine = min(fits, key=lambda item: item["rms_error"])
        ranked.append({
            "parts": [
                {"slot": first["slot"], "mesh": first["mesh"]},
                {"slot": second["slot"], "mesh": second["mesh"]},
            ],
            "point_count": len(vertices),
            "live_point_count": live_count,
            "point_count_delta": count_delta,
            "normalized_distance_cdf_error": score,
            "histogram_bins": bins,
            "ordered_affine": ordered_affine,
        })
    ranked.sort(key=lambda item: (
        item["normalized_distance_cdf_error"] +
        abs(item["point_count_delta"]) / max(live_count, 1) * 0.15,
        abs(item["point_count_delta"]),
        tuple((part["slot"], part["mesh"]) for part in item["parts"])))
    return ranked[:top]


def composite_attachment_candidates(
        node: dict[str, object], node_vertices: list[bytes],
        shape_candidates: list[dict[str, object]],
        meshes: list[dict[str, object]],
        matrices: list[tuple[float, ...]], top: int
        ) -> list[dict[str, object]]:
    """Try attachment-row pairs for the best two-mesh shape candidates."""
    root = (matrices[0][12], matrices[0][13], matrices[0][14])
    live = [struct.unpack_from("<3f", vertex) for vertex in node_vertices]
    mesh_by_key = {(mesh["slot"], mesh["mesh"]): mesh for mesh in meshes}
    transformed: dict[tuple[int, int], list[list[tuple[float, float, float]]]] = {}

    def mesh_rows(mesh: dict[str, object]) -> list[list[tuple[float, float, float]]]:
        key = (int(mesh["slot"]), int(mesh["mesh"]))
        if key not in transformed:
            rows = []
            for matrix in matrices:
                rows.append([
                    (matrix[0] * x + matrix[4] * y + matrix[8] * z + matrix[12] - root[0],
                     matrix[1] * x + matrix[5] * y + matrix[9] * z + matrix[13] - root[1],
                     matrix[2] * x + matrix[6] * y + matrix[10] * z + matrix[14] - root[2])
                    for x, y, z in (struct.unpack_from("<3f", vertex)
                                    for vertex in mesh["_vertices"])
                ])
            transformed[key] = rows
        return transformed[key]

    ranked = []
    for candidate in shape_candidates:
        first_key = (candidate["parts"][0]["slot"], candidate["parts"][0]["mesh"])
        second_key = (candidate["parts"][1]["slot"], candidate["parts"][1]["mesh"])
        first = mesh_by_key.get(first_key)
        second = mesh_by_key.get(second_key)
        if first is None or second is None:
            continue
        first_rows = mesh_rows(first)
        second_rows = mesh_rows(second)
        best = None
        for first_row, first_points in enumerate(first_rows):
            for second_row, second_points in enumerate(second_rows):
                source = first_points + second_points
                if not source or not live:
                    continue
                live_nearest = [math.inf] * len(live)
                source_nearest = [math.inf] * len(source)
                for live_index, live_point in enumerate(live):
                    for source_index, source_point in enumerate(source):
                        distance_sq = sum((a - b) ** 2
                                          for a, b in zip(live_point, source_point))
                        if distance_sq < live_nearest[live_index]:
                            live_nearest[live_index] = distance_sq
                        if distance_sq < source_nearest[source_index]:
                            source_nearest[source_index] = distance_sq
                mean_sq = (sum(live_nearest) + sum(source_nearest)) / (
                    len(live_nearest) + len(source_nearest))
                rms_error = math.sqrt(mean_sq)
                radius = max(abs(float(node["radius"])), 1.0e-6)
                result = {
                    "parts": candidate["parts"],
                    "matrix_rows": [first_row, second_row],
                    "point_count": len(source),
                    "live_point_count": len(live),
                    "rms_error": rms_error,
                    "normalized_rms_error": rms_error / radius,
                    "shape_cdf_error": candidate["normalized_distance_cdf_error"],
                }
                if best is None or result["normalized_rms_error"] < best["normalized_rms_error"]:
                    best = result
        if best is not None:
            ranked.append(best)
    ranked.sort(key=lambda item: (item["normalized_rms_error"],
                                  item["shape_cdf_error"],
                                  item["parts"][0]["slot"],
                                  item["parts"][0]["mesh"],
                                  item["parts"][1]["slot"],
                                  item["parts"][1]["mesh"]))
    return ranked[:top]


def attachment_matrix_candidates(node: dict[str, object],
                                 meshes: list[dict[str, object]],
                                 matrices: list[tuple[float, ...]],
                                 top: int,
                                 matrix_rows: list[int] | None = None,
                                 top_per_matrix_row: bool = False
                                 ) -> list[dict[str, object]]:
    """Rank POL mesh spheres after each captured actor attachment transform."""
    root = (matrices[0][12], matrices[0][13], matrices[0][14])
    node_center = node["center"]
    node_radius = float(node["radius"])
    ranked: list[dict[str, object]] = []
    selected_rows = (range(len(matrices)) if matrix_rows is None else matrix_rows)
    for row in selected_rows:
        matrix = matrices[row]
        for mesh in meshes:
            x, y, z = mesh["center"]
            center = (
                matrix[0] * x + matrix[4] * y + matrix[8] * z + matrix[12] - root[0],
                matrix[1] * x + matrix[5] * y + matrix[9] * z + matrix[13] - root[1],
                matrix[2] * x + matrix[6] * y + matrix[10] * z + matrix[14] - root[2],
            )
            basis_scale = max(
                math.sqrt(matrix[axis] ** 2 + matrix[axis + 1] ** 2 +
                          matrix[axis + 2] ** 2)
                for axis in (0, 4, 8)
            )
            radius = float(mesh["radius"]) * basis_scale
            center_delta = math.sqrt(sum((a - b) ** 2
                                         for a, b in zip(node_center, center)))
            radius_delta = abs(node_radius - radius)
            scale = max(abs(node_radius), abs(radius), 1.0e-6)
            ranked.append({
                "matrix_row": row,
                "slot": mesh["slot"],
                "mesh": mesh["mesh"],
                "pol_center_relative": center,
                "pol_radius_transformed": radius,
                "center_delta": center_delta,
                "radius_delta": radius_delta,
                "normalized_score": (center_delta + radius_delta) / scale,
            })
    if top_per_matrix_row:
        ranked.sort(key=lambda row: (row["matrix_row"], row["normalized_score"],
                                     row["slot"], row["mesh"]))
        row_counts: dict[int, int] = {}
        selected: list[dict[str, object]] = []
        for candidate in ranked:
            matrix_row = int(candidate["matrix_row"])
            count = row_counts.get(matrix_row, 0)
            if count < top:
                selected.append(candidate)
                row_counts[matrix_row] = count + 1
        return selected

    ranked.sort(key=lambda row: (row["normalized_score"], row["matrix_row"],
                                 row["slot"], row["mesh"]))
    return ranked[:top]


def attachment_geometry_candidates(node_vertices: list[bytes],
                                   meshes: list[dict[str, object]],
                                   matrices: list[tuple[float, ...]],
                                   top: int,
                                   matrix_rows: list[int] | None = None,
                                   top_per_matrix_row: bool = False
                                   ) -> list[dict[str, object]]:
    """Rank transformed POL vertex clouds against a live display-list node."""
    root = (matrices[0][12], matrices[0][13], matrices[0][14])
    live_xyz = [struct.unpack_from("<3f", vertex) for vertex in node_vertices]
    selected_rows = range(len(matrices)) if matrix_rows is None else matrix_rows
    ranked: list[dict[str, object]] = []
    for row in selected_rows:
        matrix = matrices[row]
        for mesh in meshes:
            transformed = []
            for vertex in mesh["_vertices"]:
                x, y, z = struct.unpack_from("<3f", vertex)
                transformed.append((
                    matrix[0] * x + matrix[4] * y + matrix[8] * z + matrix[12] - root[0],
                    matrix[1] * x + matrix[5] * y + matrix[9] * z + matrix[13] - root[1],
                    matrix[2] * x + matrix[6] * y + matrix[10] * z + matrix[14] - root[2],
                ))
            if not transformed:
                continue
            nearest_sq = [min(sum((a - b) ** 2 for a, b in zip(point, candidate))
                              for candidate in transformed)
                          for point in live_xyz]
            nearest_mean = (sum(math.sqrt(value) for value in nearest_sq) / len(nearest_sq)
                            if nearest_sq else math.inf)
            exact_count = sum(value < 1.0e-12 for value in nearest_sq)
            scale = max(abs(float(mesh["radius"])), 1.0e-6)
            ranked.append({
                "matrix_row": row,
                "slot": mesh["slot"],
                "mesh": mesh["mesh"],
                "position_nearest_mean": nearest_mean,
                "position_exact_count": exact_count,
                "live_vertex_count": len(live_xyz),
                "pol_vertex_count": len(transformed),
                "normalized_position_score": nearest_mean / scale,
            })

    if top_per_matrix_row:
        ranked.sort(key=lambda item: (item["matrix_row"],
                                     item["normalized_position_score"],
                                     -item["position_exact_count"],
                                     item["slot"], item["mesh"]))
        row_counts: dict[int, int] = {}
        selected: list[dict[str, object]] = []
        for candidate in ranked:
            matrix_row = int(candidate["matrix_row"])
            count = row_counts.get(matrix_row, 0)
            if count < top:
                selected.append(candidate)
                row_counts[matrix_row] = count + 1
        return selected

    ranked.sort(key=lambda item: (item["normalized_position_score"],
                                  -item["position_exact_count"],
                                  item["matrix_row"], item["slot"], item["mesh"]))
    return ranked[:top]


def read_attachment_matrices(ram: bytes, actor: int, offset: int,
                             count: int) -> list[tuple[float, ...]]:
    data = read_ram(ram, actor + offset, count * 64)
    values = struct.unpack(f"<{count * 16}f", data)
    if not all(math.isfinite(value) for value in values):
        raise ValueError("attachment matrix table contains a non-finite value")
    return [values[index * 16:(index + 1) * 16]
            for index in range(count)]


def premultiply_attachment_matrices(
        scene: tuple[float, ...],
        matrices: list[tuple[float, ...]]) -> list[tuple[float, ...]]:
    """Apply the shared draw matrix before each actor attachment row."""
    composed = []
    for attachment in matrices:
        values = [0.0] * 16
        for column in range(4):
            for row in range(4):
                values[column * 4 + row] = sum(
                    scene[k * 4 + row] * attachment[column * 4 + k]
                    for k in range(4))
        composed.append(tuple(values))
    return composed


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact 1ST_READ image loaded in the state")
    parser.add_argument("--image-address", type=address, default=DEFAULT_IMAGE_ADDRESS,
                        help="guest address of the image (default: 0x0c010000)")
    parser.add_argument("--actor", type=address, required=True,
                        help="fighter record address in guest RAM")
    parser.add_argument("--pol", type=Path, required=True,
                        help="matching fighter POL package")
    parser.add_argument("--entry", type=int, action="append",
                        help="zero-based attachment index; repeat to select entries")
    parser.add_argument("--count", type=int, default=18,
                        help="attachment selector count (default: 18)")
    parser.add_argument("--selector-offset", type=address, default=SELECTOR_OFFSET,
                        help="actor selector-array offset (default: 0x6c)")
    parser.add_argument("--descriptor-table", type=address, default=DESCRIPTOR_TABLE,
                        help="selector-to-display-list pointer table")
    parser.add_argument("--max-nodes", type=int, default=128,
                        help="maximum display-list nodes per attachment")
    parser.add_argument("--top", type=int, default=5,
                        help="nearest POL mesh spheres to show per live node")
    parser.add_argument("--attachment-matches", action="store_true",
                        help="also rank mesh spheres transformed by actor attachment matrices")
    parser.add_argument("--attachment-offset", type=address, default=0x180,
                        help="actor offset of 64-byte attachment matrices (default: 0x180)")
    parser.add_argument("--attachment-count", type=int, default=18,
                        help="number of attachment matrices (default: 18)")
    parser.add_argument("--scene-matrix-address", type=address,
                        help="pre-multiply attachment rows by the shared 4x4 draw matrix at this guest address")
    parser.add_argument("--matrix-row", type=int, action="append",
                        help="restrict transformed candidates to this matrix row; repeatable")
    parser.add_argument("--top-per-matrix-row", action="store_true",
                        help="show --top candidates for each selected matrix row")
    parser.add_argument("--attachment-geometry-matches", action="store_true",
                        help="rank transformed POL vertex positions against live node vertices")
    parser.add_argument("--affine-fit", action="store_true",
                        help="fit equal-count POL/live vertex records in their existing order")
    parser.add_argument("--unordered-shape", action="store_true",
                        help="rank meshes by a scale-normalized pairwise-distance signature")
    parser.add_argument("--composite-shape", action="store_true",
                        help="rank two-mesh unions by pairwise-distance signature")
    parser.add_argument("--composite-attachment-fit", action="store_true",
                        help="try attachment matrix-row pairs for top two-mesh candidates")
    parser.add_argument("--trace-strips", action="store_true",
                        help="print strip offsets/counts for each decoded node")
    parser.add_argument("--json", action="store_true", help="emit JSON")
    parser.add_argument("--summary", action="store_true",
                        help="print exact mesh matches per live descriptor node")
    args = parser.parse_args(argv)
    if not 1 <= args.count <= 64:
        parser.error("--count must be between 1 and 64")
    entries = (list(range(args.count)) if args.entry is None
               else sorted(set(args.entry)))
    if any(index < 0 or index >= args.count for index in entries):
        parser.error(f"--entry values must be between 0 and {args.count - 1}")
    if not 1 <= args.max_nodes <= 4096:
        parser.error("--max-nodes must be between 1 and 4096")
    if not 1 <= args.top <= 100:
        parser.error("--top must be between 1 and 100")
    if not 1 <= args.attachment_count <= 64:
        parser.error("--attachment-count must be between 1 and 64")
    if args.matrix_row is not None:
        if not args.attachment_matches:
            parser.error("--matrix-row requires --attachment-matches")
        if any(row < 0 or row >= args.attachment_count for row in args.matrix_row):
            parser.error(f"--matrix-row values must be between 0 and {args.attachment_count - 1}")
    if args.top_per_matrix_row and not args.attachment_matches:
        parser.error("--top-per-matrix-row requires --attachment-matches")
    if args.attachment_geometry_matches and not args.attachment_matches:
        parser.error("--attachment-geometry-matches requires --attachment-matches")
    if args.composite_attachment_fit and not args.attachment_matches:
        parser.error("--composite-attachment-fit requires --attachment-matches")
    if args.composite_attachment_fit and not args.composite_shape:
        parser.error("--composite-attachment-fit requires --composite-shape")
    if args.scene_matrix_address is not None and not args.attachment_matches:
        parser.error("--scene-matrix-address requires --attachment-matches")

    try:
        image = args.image.read_bytes()
        pol = args.pol.read_bytes()
        meshes = pol_mesh_bounds(pol)
        blob = load_state(str(args.state))
        ram_offset, ram, anchor = locate_ram(blob, image, args.image_address, None)
        matrices = (read_attachment_matrices(ram, args.actor, args.attachment_offset,
                                             args.attachment_count)
                    if args.attachment_matches else None)
        if matrices is not None and args.scene_matrix_address is not None:
            scene_values = struct.unpack(
                "<16f", read_ram(ram, args.scene_matrix_address, 64))
            if not all(math.isfinite(value) for value in scene_values):
                raise ValueError("scene matrix contains a non-finite value")
            matrices = premultiply_attachment_matrices(scene_values, matrices)
        shape_signature_cache: dict[int, tuple[float, ...] | None] = {}
        records = []
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
                geometry_ranked, sphere_ranked, attribute_ranked = rank_meshes(
                    node, meshes, node_vertices, args.top)
                node["nearest_pol_meshes"] = geometry_ranked
                node["sphere_nearest_pol_meshes"] = sphere_ranked
                node["attribute_nearest_pol_meshes"] = attribute_ranked
                if args.affine_fit:
                    node["affine_fit_candidates"] = affine_fit_candidates(
                        node_vertices, meshes, args.top)
                if args.unordered_shape:
                    node["unordered_shape_candidates"] = unordered_shape_candidates(
                        node_vertices, meshes, args.top,
                        signature_cache=shape_signature_cache)
                if args.composite_shape:
                    node["composite_shape_candidates"] = composite_shape_candidates(
                        node_vertices, meshes, args.top)
                if args.composite_attachment_fit and matrices is not None:
                    node["composite_attachment_candidates"] = composite_attachment_candidates(
                        node, node_vertices, node["composite_shape_candidates"],
                        meshes, matrices, args.top)
                if matrices is not None:
                    node["attachment_matrix_candidates"] = attachment_matrix_candidates(
                        node, meshes, matrices, args.top, args.matrix_row,
                        args.top_per_matrix_row)
                    if args.attachment_geometry_matches:
                        node["attachment_geometry_candidates"] = attachment_geometry_candidates(
                            node_vertices, meshes, matrices, args.top, args.matrix_row,
                            args.top_per_matrix_row)
            record["status"] = "resolved"
            record["nodes"] = nodes
            records.append(record)
        report = {
            "diagnostic_only": True,
            "state": str(args.state),
            "ram_offset": ram_offset,
            "ram_anchor": anchor,
            "actor": args.actor,
            "pol": str(args.pol),
            "pol_mesh_count": len(meshes),
            "attachment_matrix_count": len(matrices) if matrices is not None else 0,
            "scene_matrix_address": args.scene_matrix_address,
            "entries": records,
            "matching_note": (
                "Full vertex-record, position-only, vertex-attribute-only, and "
                "bounding-sphere signals are reported separately. "
                + ("The shared scene matrix is pre-multiplied into each attachment row. "
                   if args.scene_matrix_address is not None else "")
                + "Attachment matrix candidates transform POL mesh bounds relative "
                "to matrix row 0; they are also diagnostic only. "
                "Attachment geometry candidates transform POL vertex positions "
                "the same way and rank them against live node vertices. "
                "Affine-fit candidates solve a 3x4 least-squares transform for "
                "equal-count vertex streams in their existing order. "
                "Unordered shape candidates compare scale-normalized pairwise "
                "distance distributions, which ignore vertex order, translation "
                "and rotation; these rankings do not recover a transform. "
                "Composite shape candidates compare concatenated two-mesh POL "
                "point clouds near the live node's record count; they are also "
                "diagnostic and assume no separate per-mesh transform. "
                "Composite attachment candidates separately apply selected "
                "actor attachment rows to each part, then rank symmetric point "
                "cloud distance; these do not prove a part or row assignment. "
                "A match does not prove that a POL mesh is the rendered "
                "display-list part. Unsupported strip variants are reported."
            ),
        }
        if args.summary:
            print(f"{args.state}: actor=0x{args.actor:08x} "
                  f"POL meshes={len(meshes)}")
            if args.scene_matrix_address is not None:
                print(f"scene matrix 0x{args.scene_matrix_address:08x} "
                      "pre-multiplied into attachment rows")
            for record in records:
                print(f"entry {record['entry']:2}: selector=0x{record['selector']:08x} "
                      f"status={record['status']}")
                if record.get("status") != "resolved":
                    continue
                for node in record["nodes"]:
                    live_count = int(node["vertex_count"])
                    exact = [candidate for candidate in node["nearest_pol_meshes"]
                             if live_count and
                             candidate["position_exact_count"] == live_count]
                    if exact:
                        matches = "; ".join(
                            f"slot {candidate['slot']} mesh {candidate['mesh']} "
                            f"records {candidate['vertex_overlap']}/{live_count}"
                            for candidate in exact)
                        print(f"  node {node['index']:2} live={live_count}: "
                              f"exact POL positions: {matches}")
                    else:
                        nearest = node["nearest_pol_meshes"][0]
                        print(f"  node {node['index']:2} live={live_count}: "
                              f"no exact position mesh; nearest slot {nearest['slot']} "
                              f"mesh {nearest['mesh']} mean={nearest['position_nearest_mean']:.6g}")
                    attributes = node.get("attribute_nearest_pol_meshes", [])
                    exact_attributes = [candidate for candidate in attributes
                                        if live_count and
                                        candidate["attribute_overlap"] == live_count]
                    if exact_attributes:
                        matches = "; ".join(
                            f"slot {candidate['slot']} mesh {candidate['mesh']} "
                            f"records {candidate['attribute_overlap']}/{live_count}"
                            for candidate in exact_attributes)
                        print(f"    exact non-position attributes: {matches}")
                    elif attributes:
                        best_attributes = attributes[0]
                        print(f"    best non-position attributes: slot "
                              f"{best_attributes['slot']} mesh {best_attributes['mesh']} "
                              f"records {best_attributes['attribute_overlap']}/{live_count}")
                    else:
                        print("    no exact non-position vertex attributes")
                    affine = node.get("affine_fit_candidates", [])
                    if affine:
                        best_fit = affine[0]
                        print(f"    best ordered affine candidate: slot {best_fit['slot']} "
                              f"mesh {best_fit['mesh']} "
                              f"rms={best_fit['rms_error']:.6g} "
                              f"normalized={best_fit['normalized_rms_error']:.6g} "
                              f"max={best_fit['max_error']:.6g} "
                              f"points={best_fit['point_count']}")
                    shape = node.get("unordered_shape_candidates", [])
                    if shape:
                        best_shape = shape[0]
                        print(f"    best unordered shape candidate: slot {best_shape['slot']} "
                              f"mesh {best_shape['mesh']} "
                              f"cdf-error={best_shape['normalized_distance_cdf_error']:.6g} "
                              f"points={best_shape['point_count']}/"
                              f"{best_shape['live_point_count']}")
                    composite = node.get("composite_shape_candidates", [])
                    if composite:
                        best_composite = composite[0]
                        parts = " + ".join(
                            f"slot {part['slot']} mesh {part['mesh']}"
                            for part in best_composite["parts"])
                        print(f"    best two-mesh shape candidate: {parts} "
                              f"cdf-error={best_composite['normalized_distance_cdf_error']:.6g} "
                              f"points={best_composite['point_count']}/"
                              f"{best_composite['live_point_count']}")
                        affine = best_composite.get("ordered_affine")
                        if affine:
                            print(f"      ordered affine: {affine['order']} "
                                  f"rms={affine['rms_error']:.6g} "
                                  f"normalized={affine['normalized_rms_error']:.6g}")
                    attachment = node.get("composite_attachment_candidates", [])
                    if attachment:
                        best_attachment = attachment[0]
                        parts = " + ".join(
                            f"slot {part['slot']} mesh {part['mesh']}"
                            for part in best_attachment["parts"])
                        rows = best_attachment["matrix_rows"]
                        print(f"    best two-mesh attachment fit: {parts} "
                              f"rows {rows[0]}/{rows[1]} "
                              f"normalized-rms={best_attachment['normalized_rms_error']:.6g} "
                              f"points={best_attachment['point_count']}/"
                              f"{best_attachment['live_point_count']}")
                    sphere_rows = node.get("attachment_matrix_candidates", [])
                    if sphere_rows:
                        exact_meshes = [candidate for candidate in node["nearest_pol_meshes"]
                                        if live_count and
                                        candidate["position_exact_count"] == live_count]
                        exact_slot3 = [candidate for candidate in exact_meshes
                                       if candidate["slot"] == 3]
                        if exact_slot3:
                            rows = []
                            for mesh in exact_slot3:
                                matching = [candidate for candidate in sphere_rows
                                            if candidate["slot"] == mesh["slot"] and
                                            candidate["mesh"] == mesh["mesh"]]
                                if matching:
                                    best = min(matching,
                                               key=lambda candidate: candidate["normalized_score"])
                                    rows.append(
                                        f"slot {mesh['slot']} mesh {mesh['mesh']} -> "
                                        f"row {best['matrix_row']} "
                                        f"score={best['normalized_score']:.6g}")
                            if rows:
                                print("    best sphere rows for exact meshes: " + "; ".join(rows))
                        else:
                            best = min(sphere_rows,
                                       key=lambda candidate: candidate["normalized_score"])
                            print(f"    best sphere candidate: row {best['matrix_row']} "
                                  f"slot {best['slot']} mesh {best['mesh']} "
                                  f"score={best['normalized_score']:.6g}")
                    transformed = node.get("attachment_geometry_candidates", [])
                    if transformed:
                        exact_rows = [candidate for candidate in transformed
                                      if live_count and
                                      candidate["position_exact_count"] == live_count]
                        if exact_rows:
                            matches = "; ".join(
                                f"row {candidate['matrix_row']} slot {candidate['slot']} "
                                f"mesh {candidate['mesh']}"
                                for candidate in exact_rows)
                            print(f"    transformed exact: {matches}")
                        else:
                            best = min(transformed,
                                       key=lambda candidate: candidate["normalized_position_score"])
                            print(f"    no transformed exact; best row {best['matrix_row']} "
                                  f"slot {best['slot']} mesh {best['mesh']} "
                                  f"mean={best['position_nearest_mean']:.6g}")
        elif args.json:
            print(json.dumps(report, indent=2, allow_nan=False))
        else:
            print(f"{args.state}: RAM at 0x{ram_offset:x}; {anchor}")
            print(f"actor=0x{args.actor:08x} POL meshes={len(meshes)}")
            for record in records:
                print(f"entry {record['entry']:2}: selector=0x{record['selector']:08x} "
                      f"status={record['status']}")
                if record.get("status") != "resolved":
                    continue
                for node in record["nodes"]:
                    center = node["center"]
                    print(f"  node {node['index']:2} pcw=0x{node['pcw']:08x} "
                          f"center=({center[0]:.6g},{center[1]:.6g},{center[2]:.6g}) "
                          f"r={node['radius']:.6g} bytes=0x{node['payload_bytes']:x} "
                          f"strip=0x{node['first_strip_word']:08x} "
                          f"count={node['first_strip_count']} "
                          f"rec={node['first_record_head']} "
                          f"vertex-decode={node['vertex_decode_status']} "
                          f"live-v={node['vertex_count']}")
                    for candidate in node["nearest_pol_meshes"]:
                        print(f"    slot={candidate['slot']:2} mesh={candidate['mesh']:2} "
                              f"v={candidate['pol_vertex_count']} i={candidate['pol_index_count']} "
                              f"data=0x{candidate['pol_data_bytes']:x} "
                              f"v-overlap={candidate['vertex_overlap']} "
                              f"v-jaccard={candidate['vertex_jaccard']:.4f} "
                              f"p-overlap={candidate['position_overlap']} "
                              f"p-jaccard={candidate['position_jaccard']:.4f} "
                              f"p-nearest={candidate['position_nearest_mean']:.6g} "
                              f"p-exact={candidate['position_exact_count']} "
                              f"center_delta={candidate['center_delta']:.6g} "
                              f"radius_delta={candidate['radius_delta']:.6g} "
                              f"score={candidate['normalized_score']:.6g}")
                    print("    closest POL bounding spheres:")
                    for candidate in node["sphere_nearest_pol_meshes"]:
                        print(f"      slot={candidate['slot']:2} mesh={candidate['mesh']:2} "
                              f"center_delta={candidate['center_delta']:.6g} "
                              f"radius_delta={candidate['radius_delta']:.6g} "
                              f"score={candidate['normalized_score']:.6g}")
                    if node["attribute_nearest_pol_meshes"]:
                        print("    POL meshes with exact vertex-attribute overlap:")
                        for candidate in node["attribute_nearest_pol_meshes"]:
                            print(f"      slot={candidate['slot']:2} mesh={candidate['mesh']:2} "
                                  f"overlap={candidate['attribute_overlap']} "
                                  f"jaccard={candidate['attribute_jaccard']:.4f}")
                    else:
                        print("    no exact POL vertex-attribute overlap")
                    for candidate in node.get("attachment_matrix_candidates", []):
                        print(f"    matrix={candidate['matrix_row']:2} "
                              f"slot={candidate['slot']:2} mesh={candidate['mesh']:2} "
                              f"center_delta={candidate['center_delta']:.6g} "
                              f"radius_delta={candidate['radius_delta']:.6g} "
                              f"score={candidate['normalized_score']:.6g}")
                    for candidate in node.get("attachment_geometry_candidates", []):
                        print(f"    matrix={candidate['matrix_row']:2} "
                              f"geometry slot={candidate['slot']:2} "
                              f"mesh={candidate['mesh']:2} "
                              f"nearest={candidate['position_nearest_mean']:.6g} "
                              f"exact={candidate['position_exact_count']}/"
                              f"{candidate['live_vertex_count']} "
                              f"score={candidate['normalized_position_score']:.6g}")
                    if args.trace_strips:
                        for strip in node["strip_trace"]:
                            print(f"    strip@0x{strip['descriptor_at']:08x} "
                                  f"flags=0x{strip['descriptor']:08x} "
                                  f"count={strip['count']} records="
                                  f"0x{strip['vertex_start']:08x}.."
                                  f"0x{strip['records_end']:08x} "
                                  f"trailer=0x{strip['trailer']:08x} "
                                  f"next=0x{strip['flags']:08x} "
                                  f"chained={strip['chained']}")
            print(report["matching_note"])
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"flycast_pol_node_match: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
