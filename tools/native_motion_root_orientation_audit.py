#!/usr/bin/env python3
"""Check the recovered 0x8C09D9EA actor-root rotation against pose captures.

The retail sequence is identity, rotate Y by actor yaw (+0x1e), then rotate Z,
Y, X by the first packed triple at actor +0x1f50. This audit compares that
column-major result with attachment matrix row 0 for each timeline checkpoint.
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import statistics
import sys

from native_attachment_parent_fit import angle, axis, mm, rot


def predict(row):
    fields = row["packed_pose_fields_at_0x1f50"]
    result = axis(1, int(row["actor_yaw_at_0x1e"]))
    for ax, field in ((2, fields[0]), (1, fields[1]), (0, fields[2])):
        result = mm(result, axis(ax, int(field)))
    return result


def transpose3(matrix):
    return tuple(tuple(matrix[column][row] for column in range(3))
                 for row in range(3))


def anchor_basis(points, x_from=0, x_to=1, z_from=3, z_to=4):
    """Build a candidate root basis from two directed anchor lines."""
    def normalize(vector):
        length = math.sqrt(sum(value * value for value in vector))
        if length < 1e-8:
            return None
        return tuple(value / length for value in vector)

    def dot(a, b):
        return sum(a[index] * b[index] for index in range(3))

    def cross(a, b):
        return (a[1] * b[2] - a[2] * b[1],
                a[2] * b[0] - a[0] * b[2],
                a[0] * b[1] - a[1] * b[0])

    x = normalize(tuple(float(points[x_to * 3 + axis]) -
                        float(points[x_from * 3 + axis])
                        for axis in range(3)))
    z_source = tuple(float(points[z_to * 3 + axis]) -
                     float(points[z_from * 3 + axis])
                     for axis in range(3))
    if x is None:
        return None
    z = normalize(tuple(-z_source[axis] - dot(z_source, x) * -x[axis]
                        for axis in range(3)))
    if z is None:
        return None
    y = normalize(cross(z, x))
    if y is None:
        return None
    z = normalize(cross(x, y))
    return tuple(tuple((x, y, z)[column][row] for column in range(3))
                 for row in range(3))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("timelines", nargs="+", type=Path)
    parser.add_argument("--out", type=Path)
    parser.add_argument("--kind", type=int, action="append",
                        help="limit printed anchor fits to this actor kind; repeat to select more")
    parser.add_argument("--row-axis", type=int, choices=(0, 1, 2), action="append",
                        help="limit printed fits to this matrix axis; repeat to select more")
    parser.add_argument("--attachment-row", type=int, choices=range(18), action="append",
                        help="analyze anchor directions against this attachment row; repeat to select more (default: 0)")
    parser.add_argument("--top", type=int, default=12,
                        help="number of ranked fits per kind and attachment row (default: 12)")
    parser.add_argument("--min-samples", type=int, default=10,
                        help="minimum captures required for a fit (default: 10)")
    parser.add_argument("--motion-id", type=lambda value: int(value, 0), action="append",
                        help="limit analysis to this hexadecimal/decimal MT motion ID; repeat to select more")
    args = parser.parse_args()
    if args.top < 0 or args.min_samples < 1:
        parser.error("--top must be nonnegative and --min-samples must be positive")
    attachment_rows = args.attachment_row or [0]
    by_kind = {}
    point_basis_by_kind = {}
    basis_samples = {}
    anchor_axis_fits = {}
    try:
        lines = (line for timeline in args.timelines
                 for line in timeline.read_text(encoding="utf-8").splitlines())
        for number, line in enumerate(lines, 1):
            if not line.strip():
                continue
            row = json.loads(line)
            motion_id = int(str(row["motion_id"]), 0)
            if args.motion_id and motion_id not in args.motion_id:
                continue
            kind = int(row["byte_0x61"])
            observed_rows = row["attachment_rows_at_0x180"]
            if 0 in attachment_rows:
                observed = rot(observed_rows[0])
                if observed is not None:
                    predicted = predict(row)
                    error = angle(predicted, observed)
                    by_kind.setdefault(kind, []).append({
                        "frame": int(row["frame"]), "actor": row["actor"],
                        "motion_id": row["motion_id"], "error_deg": error,
                    })
                    candidate = anchor_basis(row["pose_vectors_at_0x1efc"])
                    if candidate is not None:
                        point_basis_by_kind.setdefault(kind, []).append(
                            angle(candidate, observed))
                    basis_samples.setdefault((kind, motion_id), []).append(
                        (row["pose_vectors_at_0x1efc"], observed))
                    basis_samples.setdefault(("all", motion_id), []).append(
                        (row["pose_vectors_at_0x1efc"], observed))
            points = row["pose_vectors_at_0x1efc"]
            for attachment_row in attachment_rows:
                observed = rot(observed_rows[attachment_row])
                if observed is None:
                    continue
                for row_axis in range(3):
                    matrix_axis = tuple(observed[row_index][row_axis] for row_index in range(3))
                    for source in range(7):
                        for destination in range(source + 1, 7):
                            vector = tuple(float(points[destination * 3 + k]) -
                                           float(points[source * 3 + k]) for k in range(3))
                            length = math.sqrt(sum(value * value for value in vector))
                            if length < 1e-6:
                                continue
                            dot = sum(matrix_axis[k] * vector[k] / length for k in range(3))
                            key = (kind, attachment_row, row_axis, source, destination)
                            anchor_axis_fits.setdefault(key, []).append(dot)
        summary = {"diagnostic_only": True, "kinds": {}}
        for kind, values in sorted(by_kind.items()):
            errors = [value["error_deg"] for value in values]
            summary["kinds"][str(kind)] = {
                "rows": len(values), "median_error_deg": statistics.median(errors),
                "p95_error_deg": sorted(errors)[int(0.95 * (len(errors) - 1))],
                "max_error_deg": max(errors),
                "anchor_basis_rows": len(point_basis_by_kind.get(kind, [])),
                "anchor_basis_median_error_deg": (
                    statistics.median(point_basis_by_kind[kind])
                    if point_basis_by_kind.get(kind) else None),
                "anchor_basis_p95_error_deg": (
                    sorted(point_basis_by_kind[kind])[int(
                        0.95 * (len(point_basis_by_kind[kind]) - 1))]
                    if point_basis_by_kind.get(kind) else None),
            }
        axis_report = []
        for (kind, attachment_row, row_axis, source, destination), dots in anchor_axis_fits.items():
            if len(dots) < args.min_samples:
                continue
            axis_report.append({
                "kind": kind, "row_axis": row_axis, "point_from": source,
                "attachment_row": attachment_row,
                "point_to": destination, "samples": len(dots),
                "median_abs_dot": statistics.median(abs(value) for value in dots),
                "median_signed_dot": statistics.median(dots),
            })
        axis_report.sort(key=lambda value: value["median_abs_dot"], reverse=True)
        summary["anchor_axis_fits"] = axis_report[:40]
        basis_report = []
        directed_pairs = [(source, destination) for source in range(7)
                          for destination in range(7) if source != destination]
        for (kind, motion_id), samples in basis_samples.items():
            for x_from, x_to in directed_pairs:
                for z_from, z_to in directed_pairs:
                    errors = []
                    candidates = []
                    bind_rotations = []
                    for points, observed in samples:
                        candidate = anchor_basis(points, x_from, x_to,
                                                 z_from, z_to)
                        if candidate is not None:
                            errors.append(angle(candidate, observed))
                            candidates.append(candidate)
                            bind_rotations.append(mm(observed, transpose3(candidate)))
                    if len(errors) != len(samples):
                        continue
                    bind = bind_rotations[0]
                    corrected_errors = [
                        angle(mm(bind, candidate), samples[index][1])
                        for index, candidate in enumerate(candidates)]
                    basis_report.append({
                        "kind": kind, "motion_id": f"0x{motion_id:x}",
                        "samples": len(errors), "x_from": x_from, "x_to": x_to,
                        "z_from": z_from, "z_to": z_to,
                        "median_error_deg": statistics.median(errors),
                        "p95_error_deg": sorted(errors)[int(0.95 * (len(errors) - 1))],
                        "bind_corrected_median_deg": statistics.median(corrected_errors),
                        "bind_corrected_p95_deg": sorted(corrected_errors)[
                            int(0.95 * (len(corrected_errors) - 1))],
                    })
        basis_report.sort(key=lambda value: (value["bind_corrected_p95_deg"],
                                             value["bind_corrected_median_deg"],
                                             value["p95_error_deg"]))
        summary["ranked_anchor_bases"] = basis_report[:100]
        if args.out:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            args.out.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
        for kind, values in summary["kinds"].items():
            print(f"kind={kind} rows={values['rows']} median={values['median_error_deg']:.6f}deg "
                  f"p95={values['p95_error_deg']:.6f}deg max={values['max_error_deg']:.6f}deg "
                  f"anchor-basis-median={values['anchor_basis_median_error_deg']} "
                  f"anchor-basis-p95={values['anchor_basis_p95_error_deg']}")
        print("best matrix axes explained by anchor-pair directions:")
        selected = [value for value in axis_report
                    if (args.kind is None or value["kind"] in args.kind)
                    and (args.row_axis is None or value["row_axis"] in args.row_axis)]
        groups = sorted({(value["kind"], value["attachment_row"]) for value in selected})
        for kind, attachment_row in groups:
            print(f"kind={kind} attachment-row={attachment_row}:")
            group = [value for value in selected
                     if value["kind"] == kind and value["attachment_row"] == attachment_row]
            for value in group[:args.top]:
                print(f"  row-axis={value['row_axis']} "
                      f"point[{value['point_from']}]->[{value['point_to']}] "
                      f"samples={value['samples']} median-|dot|={value['median_abs_dot']:.6f} "
                      f"median-dot={value['median_signed_dot']:.6f}")
        print("best root bases from directed anchor pairs:")
        basis_groups = sorted({(value["kind"], value["motion_id"])
                               for value in basis_report},
                              key=lambda group: (str(group[0]), group[1]))
        for kind, motion_id in basis_groups:
            print(f"kind={kind} motion={motion_id}:")
            group = [value for value in basis_report
                     if value["kind"] == kind and value["motion_id"] == motion_id]
            for value in group[:5]:
                print(f"  X=point[{value['x_from']}]->[{value['x_to']}] "
                      f"Z=point[{value['z_from']}]->[{value['z_to']}] "
                      f"samples={value['samples']} median={value['median_error_deg']:.4f}deg "
                      f"p95={value['p95_error_deg']:.4f}deg "
                      f"bind-corrected-p95={value['bind_corrected_p95_deg']:.4f}deg")
        return 0
    except (OSError, KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
        print(f"native_motion_root_orientation_audit: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
