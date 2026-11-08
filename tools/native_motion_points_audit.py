#!/usr/bin/env python3
"""Audit the native seven-point transform against captured actor timelines.

The input is produced by ``native_pose_timeline_extract.py``. The calculation
mirrors 0x8C09DA72: optional origin subtraction, actor-kind Y drop gated by the
actor +0x48 flags, yaw rotation, and actor translation. The output vectors are
compared with the seven triples recorded at actor +0x1EFC. This audit does not
assign points to skeleton rows.
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import statistics
import sys


MODE_DROPS = {6: 0.0300, 8: 0.0600, 11: 0.0550, 12: 0.0200}
ANCHOR_ATTACHMENT_ROWS = {0: 0, 1: 1, 3: 5, 4: 9, 5: 14, 6: 17}


def point_outputs(row: dict) -> list[tuple[float, float, float]]:
    channels = [float(v) for v in row["channels_at_0x1d04"][:21]]
    source = [float(v) for v in row["pose_vectors_at_0x1efc"]]
    position = [float(v) for v in row["actor_position_at_0x10"]]
    yaw = int(row["actor_yaw_at_0x1e"]) & 0xFFFF
    actor_flags = int(row["actor_flags_word0"])
    pose_flags = int(row["actor_pose_flags_at_0x48"])
    global_flags = int(row["actor_global_pose_flags_at_0x0c29bccc"])
    kind = int(row["byte_0x61"])
    if not (pose_flags & 0x00029000):
        position[1] -= MODE_DROPS.get(kind, 0.0)
    angle = yaw * (2.0 * math.pi / 65536.0)
    sine, cosine = math.sin(angle), math.cos(angle)
    result = []
    for point in range(7):
        local = channels[point * 3:point * 3 + 3]
        if actor_flags & 0x20000000:
            local = [local[axis] - channels[axis] for axis in range(3)]
        # 0x0C09DB70..0x0C09DB92: bt/s (global & 0x800), bf (actor &
        # 0x8000 must be CLEAR - bf branches when T is clear, and tst
        # leaves T clear exactly when the bit is set), bt (actor &
        # 0x40000), bt (pose & 0x21000). See motion_vectors.h.
        if (global_flags & 0x0800 and not actor_flags & 0x00008000 and
                actor_flags & 0x00040000 and pose_flags & 0x00021000):
            local[1] = 0.0
        x, y, z = local
        result.append((
            position[0] + cosine * x + sine * z,
            position[1] + y,
            position[2] - sine * x + cosine * z,
        ))
    if len(source) != 21:
        raise ValueError("captured output must have 21 floats")
    return result


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("timeline", type=Path)
    parser.add_argument("--out", type=Path)
    parser.add_argument("--max-errors", type=int, default=12)
    parser.add_argument("--motion-id", type=lambda value: int(value, 0), action="append",
                        help="limit analysis to this hexadecimal/decimal MT motion ID; repeat to select more")
    args = parser.parse_args()
    errors = []
    actors = {}
    kinds = {}
    anchor_attachment_errors: dict[tuple[str, int, str, int, int], list[float]] = {}
    anchor_attachment_offsets: dict[tuple[str, int, str, int, int], list[list[float]]] = {}
    try:
        for line_number, line in enumerate(args.timeline.read_text(encoding="utf-8").splitlines(), 1):
            if not line.strip():
                continue
            row = json.loads(line)
            motion_id = int(str(row["motion_id"]), 0)
            if args.motion_id and motion_id not in args.motion_id:
                continue
            predicted = point_outputs(row)
            reference = row["pose_vectors_at_0x1efc"]
            attachment_rows = row["attachment_rows_at_0x180"]
            point_errors = []
            for point, predicted_point in enumerate(predicted):
                expected = reference[point * 3:point * 3 + 3]
                point_errors.append(math.sqrt(sum((predicted_point[k] - float(expected[k])) ** 2
                                                  for k in range(3))))
            actor = row["actor"]
            row_error = max(point_errors)
            actors.setdefault(actor, []).append(row_error)
            kind = int(row["byte_0x61"])
            kinds.setdefault((actor, kind), []).append(row_error)
            for point, attachment in ANCHOR_ATTACHMENT_ROWS.items():
                expected = [float(value) for value in predicted[point]]
                observed = [float(value) for value in attachment_rows[attachment][12:15]]
                offset = [observed[axis] - expected[axis] for axis in range(3)]
                distance = math.sqrt(sum((expected[axis] - observed[axis]) ** 2
                                         for axis in range(3)))
                track = (actor, kind, f"0x{motion_id:x}", int(row["cycle"]),
                         int(row["record_pointer"], 0) if isinstance(row["record_pointer"], str)
                         else int(row["record_pointer"]))
                fit_key = (*track, attachment)
                anchor_attachment_errors.setdefault(fit_key, []).append(distance)
                anchor_attachment_offsets.setdefault(fit_key, []).append(offset)
            if max(point_errors) > 1e-4:
                errors.append({"line": line_number, "actor": actor,
                               "kind": kind, "frame": row["frame"], "max_point_error": row_error,
                               "point_errors": point_errors})
        summary = {
            "diagnostic_only": True,
            "rows": sum(len(v) for v in actors.values()),
            "actors": {
                actor: {"rows": len(values), "max_error": max(values),
                        "median_max_point_error": statistics.median(values)}
                for actor, values in actors.items()
            },
            "actor_kinds": {
                f"{actor}/kind-{kind}": {"rows": len(values), "max_error": max(values),
                                          "median_max_point_error": statistics.median(values)}
                for (actor, kind), values in kinds.items()
            },
            "anchor_attachment_translation_fits": {
                f"{actor}/kind-{kind}/motion-{motion}/cycle-{cycle}/record-{record:#x}/row-{attachment}": {
                    "point": next(point for point, row_index in ANCHOR_ATTACHMENT_ROWS.items()
                                  if row_index == attachment),
                    "samples": len(values), "median_error": statistics.median(values),
                    "p95_error": sorted(values)[int(0.95 * (len(values) - 1))],
                    "max_error": max(values),
                    "median_offset": [statistics.median(offset[axis] for offset in
                                                         anchor_attachment_offsets[(actor, kind, motion, cycle,
                                                                                     record, attachment)])
                                      for axis in range(3)],
                    "offset_corrected_median_error": statistics.median(
                        math.sqrt(sum((offset[axis] - statistics.median(
                            sample[axis] for sample in anchor_attachment_offsets[
                                (actor, kind, motion, cycle, record, attachment)])) ** 2
                                       for axis in range(3)))
                        for offset in anchor_attachment_offsets[
                            (actor, kind, motion, cycle, record, attachment)]),
                }
                for (actor, kind, motion, cycle, record, attachment), values
                in anchor_attachment_errors.items()
            },
            "mismatch_count_gt_1e-4": len(errors),
            "largest_mismatches": sorted(errors, key=lambda item: item["max_point_error"],
                                         reverse=True)[:args.max_errors],
        }
        if args.out:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            args.out.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
        print(f"rows={summary['rows']} mismatches={len(errors)}")
        for actor, values in summary["actors"].items():
            print(f"actor={actor} rows={values['rows']} max={values['max_error']:.8g} "
                  f"median-row-max={values['median_max_point_error']:.8g}")
        for key, values in summary["anchor_attachment_translation_fits"].items():
            print(f"anchor-fit={key} point={values['point']} rows={values['samples']} "
                  f"median={values['median_error']:.8g} p95={values['p95_error']:.8g} "
                  f"max={values['max_error']:.8g} offset={values['median_offset']} "
                  f"corrected-median={values['offset_corrected_median_error']:.8g}")
        for item in summary["largest_mismatches"]:
            print(f"frame={item['frame']} actor={item['actor']} "
                  f"max-point-error={item['max_point_error']:.8g}")
        return 0
    except (OSError, KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
        print(f"native_motion_points_audit: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
