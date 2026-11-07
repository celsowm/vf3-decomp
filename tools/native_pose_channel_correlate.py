#!/usr/bin/env python3
"""Rank diagnostic matches between MT pose fields and actor matrices.

Input is ``pose_timeline.jsonl`` from ``native_pose_timeline_extract.py`` or
``native_motion_timeline_probe.py --include-pose``. It compares the
frame-to-frame rotation of each captured joint, bone, or attachment matrix
with the 14 packed three-angle groups, and translation magnitudes against the
seven leading three-float groups. It reports candidate errors, but does not
assign a group to a bone or model part. Parent transforms, bind offsets, and
table semantics can prevent a correct relationship from scoring as a direct
match.

Example:
  python tools/native_pose_channel_correlate.py \
      extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1/pose_timeline_joints.jsonl \
      --actor 0x0c20138c --table joints --top 20
"""

from __future__ import annotations

import argparse
import itertools
import json
import math
from pathlib import Path
import struct
import sys


FIELD_GROUPS = 14
ANGLE_UNITS = 65536.0
DYNAMIC_ANGLE_DEG = 0.1
TABLES = {
    "joints": "joint_records_at_0x180",
    "bones": "bone_rows_at_0x7c0",
    "attachments": "attachment_rows_at_0x180",
}


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def read_samples(path: Path, selected_actor: int | None) -> dict[int, list[dict]]:
    actors: dict[int, list[dict]] = {}
    for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        if not line.strip():
            continue
        try:
            row = json.loads(line)
            actor = int(row["actor"], 0)
            frame = int(row["frame"])
            motion = int(row["motion_id"], 0)
            cycle = int(row["cycle"])
            phase_q8 = int(row.get("phase_q8", 0))
            fields = row["packed_pose_fields_at_0x1f50"]
            channels = row["channels_at_0x1d04"]
            if len(fields) != FIELD_GROUPS * 3:
                raise ValueError("packed pose field count is not 42")
            if len(channels) != 63:
                raise ValueError("MT channel count is not 63")
            row["_frame"] = frame
            row["_motion"] = motion
            row["_cycle"] = cycle
            row["_phase_q8"] = phase_q8
            row["_fields"] = [int(value) & 0xFFFF for value in fields]
            row["_channels"] = [float(value) if isinstance(value, (int, float)) and
                                 math.isfinite(value) else None for value in channels]
            for table_name, key in TABLES.items():
                values = row.get(key)
                if table_name == "joints" and values is None:
                    continue
                if not isinstance(values, list):
                    raise ValueError(f"{table_name} rows are not a list")
                if table_name == "joints":
                    decoded = []
                    offsets = []
                    for record in values:
                        raw = bytes.fromhex(record["raw"])
                        if len(raw) != 64:
                            raise ValueError("joint record prefix is not 64 bytes")
                        decoded.append(list(struct.unpack("<16f", raw)))
                        offsets.append(int(record["actor_offset"]))
                    row[key] = decoded
                    row["_joint_actor_offsets"] = offsets
            if selected_actor is None or actor == selected_actor:
                actors.setdefault(actor, []).append(row)
        except (KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
            raise ValueError(f"{path}:{line_number}: invalid pose sample: {exc}") from exc
    if not actors:
        raise ValueError("no pose samples matched the requested actor")
    for rows in actors.values():
        rows.sort(key=lambda row: row["_frame"])
    return actors


def transpose(matrix: tuple[tuple[float, ...], ...]) -> tuple[tuple[float, ...], ...]:
    return tuple(tuple(matrix[row][column] for row in range(3))
                 for column in range(3))


def multiply(left: tuple[tuple[float, ...], ...],
             right: tuple[tuple[float, ...], ...]) -> tuple[tuple[float, ...], ...]:
    return tuple(tuple(sum(left[row][k] * right[k][column] for k in range(3))
                       for column in range(3)) for row in range(3))


def matrix_rotation(values: list[object]) -> tuple[tuple[float, ...], ...] | None:
    if len(values) != 16 or any(not isinstance(value, (int, float)) or
                                not math.isfinite(value) for value in values):
        return None
    # Matrix rows are stored column-major. Remove basis scale, then use
    # Gram-Schmidt to suppress the small numerical skew from the guest.
    columns = [tuple(float(values[column * 4 + row]) for row in range(3))
               for column in range(3)]

    def norm(vector: tuple[float, float, float]) -> float:
        return math.sqrt(sum(value * value for value in vector))

    def scale(vector: tuple[float, float, float], factor: float):
        return tuple(value * factor for value in vector)

    def dot(left: tuple[float, float, float], right: tuple[float, float, float]) -> float:
        return sum(a * b for a, b in zip(left, right))

    def subtract(left: tuple[float, float, float], right: tuple[float, float, float]):
        return tuple(a - b for a, b in zip(left, right))

    first_length = norm(columns[0])
    if first_length < 1e-8:
        return None
    x_axis = scale(columns[0], 1.0 / first_length)
    y_orthogonal = subtract(columns[1], scale(x_axis, dot(columns[1], x_axis)))
    second_length = norm(y_orthogonal)
    if second_length < 1e-8:
        return None
    y_axis = scale(y_orthogonal, 1.0 / second_length)
    z_axis = (
        x_axis[1] * y_axis[2] - x_axis[2] * y_axis[1],
        x_axis[2] * y_axis[0] - x_axis[0] * y_axis[2],
        x_axis[0] * y_axis[1] - x_axis[1] * y_axis[0],
    )
    # The source row can include a stable mirror (for example, a turned
    # fighter). Relative rotation is invariant to that fixed reflection, so
    # use the right-handed frame derived from its first two axes.
    return tuple(tuple((x_axis, y_axis, z_axis)[column][row]
                       for column in range(3)) for row in range(3))


def rotation_axis(axis: str, angle: int) -> tuple[tuple[float, ...], ...]:
    radians = (angle & 0xFFFF) * (2.0 * math.pi / ANGLE_UNITS)
    sine, cosine = math.sin(radians), math.cos(radians)
    if axis == "x":
        return ((1.0, 0.0, 0.0), (0.0, cosine, -sine), (0.0, sine, cosine))
    if axis == "y":
        return ((cosine, 0.0, sine), (0.0, 1.0, 0.0), (-sine, 0.0, cosine))
    return ((cosine, -sine, 0.0), (sine, cosine, 0.0), (0.0, 0.0, 1.0))


def euler(fields: list[int], group: int, order: tuple[int, int, int]
          ) -> tuple[tuple[float, ...], ...]:
    start = group * 3
    angles = [fields[start + index] for index in range(3)]
    z = rotation_axis("z", angles[order[0]])
    y = rotation_axis("y", angles[order[1]])
    x = rotation_axis("x", angles[order[2]])
    return multiply(multiply(z, y), x)


def rotation_angle(matrix: tuple[tuple[float, ...], ...]) -> float:
    cosine = (matrix[0][0] + matrix[1][1] + matrix[2][2] - 1.0) * 0.5
    return math.acos(max(-1.0, min(1.0, cosine)))


def prepare_track(rows: list[dict], table_key: str) -> list[dict]:
    prepared = []
    for row in rows:
        converted = [matrix_rotation(values) for values in row[table_key]]
        prepared.append({
            "frame": row["_frame"],
            "motion": row["_motion"],
            "cycle": row["_cycle"],
            "phase_q8": row["_phase_q8"],
            "fields": row["_fields"],
            "channels": row["_channels"],
            "rotations": converted,
            "translations": [matrix_translation(values) for values in row[table_key]],
        })
    return prepared


def matrix_translation(values: list[object]) -> tuple[float, float, float] | None:
    if (len(values) != 16 or any(not isinstance(value, (int, float)) or
                                 not math.isfinite(value) for value in values[12:15])):
        return None
    return tuple(float(value) for value in values[12:15])


def vector_subtract(left: tuple[float, float, float],
                    right: tuple[float, float, float]) -> tuple[float, float, float]:
    return tuple(a - b for a, b in zip(left, right))


def vector_length(value: tuple[float, float, float]) -> float:
    return math.sqrt(sum(component * component for component in value))


def track_summary(rows: list[dict], table_key: str, max_gap: int) -> dict[str, int]:
    prepared = prepare_track(rows, table_key)
    row_count = min((len(row["rotations"]) for row in prepared), default=0)
    compatible_pairs = 0
    dynamic_phase_pairs = 0
    valid_rotation_rows: set[int] = set()
    dynamic_rotation_rows: set[int] = set()
    valid_translation_rows: set[int] = set()
    dynamic_translation_rows: set[int] = set()
    dynamic_channel_groups: set[int] = set()
    dynamic_pose_groups: set[int] = set()
    for previous, current in zip(prepared, prepared[1:]):
        frame_gap = current["frame"] - previous["frame"]
        if (frame_gap <= 0 or frame_gap > max_gap or
                previous["motion"] != current["motion"] or
                previous["cycle"] != current["cycle"]):
            continue
        compatible_pairs += 1
        if previous["phase_q8"] != current["phase_q8"]:
            dynamic_phase_pairs += 1
        for group in range(7):
            start = group * 3
            before = previous["channels"][start:start + 3]
            after = current["channels"][start:start + 3]
            if (all(value is not None for value in before + after) and
                    any(abs(float(a) - float(b)) > 1e-6 for a, b in zip(before, after))):
                dynamic_channel_groups.add(group)
        for group in range(FIELD_GROUPS):
            start = group * 3
            if previous["fields"][start:start + 3] != current["fields"][start:start + 3]:
                dynamic_pose_groups.add(group)
        for index in range(row_count):
            left = previous["rotations"][index]
            right = current["rotations"][index]
            if left is not None and right is not None:
                valid_rotation_rows.add(index)
                if max(rotation_angle(multiply(transpose(left), right)),
                       rotation_angle(multiply(right, transpose(left)))) >= math.radians(DYNAMIC_ANGLE_DEG):
                    dynamic_rotation_rows.add(index)
            before = previous["translations"][index]
            after = current["translations"][index]
            if before is not None and after is not None:
                valid_translation_rows.add(index)
                if vector_length(vector_subtract(after, before)) > 1e-6:
                    dynamic_translation_rows.add(index)
    return {
        "compatible_frame_pairs": compatible_pairs,
        "dynamic_phase_pairs": dynamic_phase_pairs,
        "valid_rotation_rows": len(valid_rotation_rows),
        "dynamic_rotation_rows": len(dynamic_rotation_rows),
        "valid_translation_rows": len(valid_translation_rows),
        "dynamic_translation_rows": len(dynamic_translation_rows),
        "dynamic_leading_channel_groups": len(dynamic_channel_groups),
        "dynamic_packed_pose_groups": len(dynamic_pose_groups),
    }


def score_track(rows: list[dict], table_key: str, table_label: str,
                minimum_dynamic_pairs: int, max_gap: int) -> list[dict]:
    if len(rows) < 2:
        return []
    prepared = prepare_track(rows, table_key)
    row_count = min(len(row["rotations"]) for row in prepared)
    candidates = []
    orders = list(itertools.permutations(range(3)))
    for matrix_index in range(row_count):
        pairs = []
        for previous, current in zip(prepared, prepared[1:]):
            frame_gap = current["frame"] - previous["frame"]
            if (frame_gap <= 0 or frame_gap > max_gap or
                    previous["motion"] != current["motion"] or
                    previous["cycle"] != current["cycle"]):
                continue
            left = previous["rotations"][matrix_index]
            right = current["rotations"][matrix_index]
            if left is None or right is None:
                continue
            actual_local = multiply(transpose(left), right)
            actual_world = multiply(right, transpose(left))
            pairs.append((previous, current, actual_local, actual_world,
                          rotation_angle(actual_local), rotation_angle(actual_world)))
        actual_dynamic = sum(max(local_angle, world_angle) >= math.radians(DYNAMIC_ANGLE_DEG)
                             for _a, _b, _local, _world, local_angle, world_angle in pairs)
        if actual_dynamic < minimum_dynamic_pairs:
            continue
        for group in range(FIELD_GROUPS):
            for order in orders:
                for mode in ("local", "world"):
                    angle_errors = []
                    orientation_errors = []
                    predicted_dynamic = 0
                    for previous, current, actual_local, actual_world, local_angle, world_angle in pairs:
                        prior_euler = euler(previous["fields"], group, order)
                        next_euler = euler(current["fields"], group, order)
                        if mode == "local":
                            actual_delta = actual_local
                            predicted_delta = multiply(transpose(prior_euler), next_euler)
                            actual_angle = local_angle
                        else:
                            actual_delta = actual_world
                            predicted_delta = multiply(next_euler, transpose(prior_euler))
                            actual_angle = world_angle
                        predicted_angle = rotation_angle(predicted_delta)
                        if predicted_angle >= math.radians(DYNAMIC_ANGLE_DEG):
                            predicted_dynamic += 1
                        if max(actual_angle, predicted_angle) < math.radians(DYNAMIC_ANGLE_DEG):
                            continue
                        angle_errors.append(math.degrees(abs(actual_angle - predicted_angle)))
                        mismatch = multiply(transpose(actual_delta), predicted_delta)
                        orientation_errors.append(math.degrees(rotation_angle(mismatch)))
                    if not angle_errors:
                        continue
                    rms_angle = math.sqrt(sum(value * value for value in angle_errors) /
                                           len(angle_errors))
                    rms_orientation = math.sqrt(sum(value * value for value in orientation_errors) /
                                                len(orientation_errors))
                    candidates.append({
                        "table": table_label,
                        "matrix_row": matrix_index,
                        "field_group": group,
                        "field_order": "".join("zyx"[index] for index in order),
                        "delta_space": mode,
                        "same_motion_pairs": len(pairs),
                        "actual_dynamic_pairs": actual_dynamic,
                        "predicted_dynamic_pairs": predicted_dynamic,
                        "compared_pairs": len(angle_errors),
                        "rms_angle_magnitude_error_degrees": rms_angle,
                        "rms_orientation_error_degrees": rms_orientation,
                    })
                    if table_label == "joints":
                        candidates[-1]["joint_actor_offset"] = rows[0][
                            "_joint_actor_offsets"][matrix_index]
    return candidates


def score_translation_track(rows: list[dict], table_key: str, table_label: str,
                            minimum_dynamic_pairs: int, max_gap: int) -> list[dict]:
    if len(rows) < 2:
        return []
    prepared = prepare_track(rows, table_key)
    row_count = min(len(row["translations"]) for row in prepared)
    results = []
    for matrix_index in range(row_count):
        pairs = []
        for previous, current in zip(prepared, prepared[1:]):
            frame_gap = current["frame"] - previous["frame"]
            if (frame_gap <= 0 or frame_gap > max_gap or
                    previous["motion"] != current["motion"] or
                    previous["cycle"] != current["cycle"]):
                continue
            before = previous["translations"][matrix_index]
            after = current["translations"][matrix_index]
            root_before = previous["translations"][0]
            root_after = current["translations"][0]
            if before is None or after is None or root_before is None or root_after is None:
                continue
            world_delta = vector_subtract(after, before)
            root_delta = vector_subtract(root_after, root_before)
            relative_delta = vector_subtract(world_delta, root_delta)
            pairs.append((previous, current, world_delta, relative_delta))
        for space_index, space in enumerate(("world", "root_relative")):
            actual = [pair[2 + space_index] for pair in pairs]
            dynamic_pairs = sum(vector_length(value) > 1e-6 for value in actual)
            if dynamic_pairs < minimum_dynamic_pairs:
                continue
            actual_magnitudes = [vector_length(value) for value in actual]
            actual_energy = sum(value * value for value in actual_magnitudes)
            if actual_energy <= 1e-12:
                continue
            for group in range(7):
                predicted = []
                for previous, current, _world, _relative in pairs:
                    before = previous["channels"][group * 3:group * 3 + 3]
                    after = current["channels"][group * 3:group * 3 + 3]
                    if any(value is None for value in before + after):
                        predicted.append(None)
                    else:
                        delta = tuple(float(b) - float(a) for a, b in zip(before, after))
                        predicted.append(vector_length(delta))
                valid = [(observed, candidate) for observed, candidate in
                         zip(actual_magnitudes, predicted) if candidate is not None]
                if len(valid) < minimum_dynamic_pairs:
                    continue
                denominator = sum(candidate * candidate for _observed, candidate in valid)
                if denominator <= 1e-12:
                    continue
                fitted_scale = sum(observed * candidate for observed, candidate in valid) / denominator
                squared_error = sum((observed - fitted_scale * candidate) ** 2
                                    for observed, candidate in valid)
                observed_energy = sum(observed * observed for observed, _candidate in valid)
                relative_rms = math.sqrt(squared_error / observed_energy)
                predicted_dynamic = sum(candidate > 1e-6 for _observed, candidate in valid)
                results.append({
                    "feature": "translation_magnitude",
                    "table": table_label,
                    "matrix_row": matrix_index,
                    "field_group": group,
                    "translation_space": space,
                    "same_motion_pairs": len(valid),
                    "actual_dynamic_pairs": dynamic_pairs,
                    "predicted_dynamic_pairs": predicted_dynamic,
                    "fitted_scale": fitted_scale,
                    "relative_rms_magnitude_error": relative_rms,
                })
                if table_label == "joints":
                    results[-1]["joint_actor_offset"] = rows[0][
                        "_joint_actor_offsets"][matrix_index]
    results.sort(key=lambda row: (row["relative_rms_magnitude_error"],
                                  row["matrix_row"], row["field_group"],
                                  row["translation_space"]))
    return results


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pose_timeline", type=Path,
                        help="pose_timeline.jsonl from the timeline probe")
    parser.add_argument("--actor", type=address,
                        help="analyze only this actor record address")
    parser.add_argument("--table", choices=("joints", "bones", "attachments", "both"),
                        default="both", help="matrix table to compare (default: both)")
    parser.add_argument("--feature", choices=("rotations", "translations", "both"),
                        default="both", help="channel feature to compare (default: both)")
    parser.add_argument("--top", type=int, default=20,
                        help="number of candidate rows to print per actor/table (default: 20)")
    parser.add_argument("--minimum-dynamic-pairs", type=int, default=2,
                        help="skip matrix rows with fewer changed rotations (default: 2)")
    parser.add_argument("--max-gap", type=int, default=2,
                        help="ignore wider frame gaps (default: 2)")
    parser.add_argument("--json", action="store_true",
                        help="emit the full candidate report as JSON")
    parser.add_argument("--output", type=Path,
                        help="write JSON report to a new file instead of stdout")
    args = parser.parse_args(argv)
    if args.top <= 0 or args.minimum_dynamic_pairs <= 0 or args.max_gap <= 0:
        parser.error("--top, --minimum-dynamic-pairs, and --max-gap must be positive")
    try:
        tracks = read_samples(args.pose_timeline, args.actor)
        chosen_tables = ("bones", "attachments") if args.table == "both" else (args.table,)
        chosen_features = ("rotations", "translations") if args.feature == "both" else (args.feature,)
        reports = []
        for actor, rows in sorted(tracks.items()):
            for table in chosen_tables:
                table_key = TABLES[table]
                if table == "joints" and any(table_key not in row for row in rows):
                    raise ValueError(
                        "pose timeline has no joint records; regenerate it with "
                        "native_pose_timeline_extract.py")
                for feature in chosen_features:
                    scores: list[dict] = []
                    summary = {}
                    for key, table_key in TABLES.items():
                        if key != table:
                            continue
                        summary = track_summary(rows, table_key, args.max_gap)
                        if feature == "rotations":
                            scores = score_track(rows, table_key, key,
                                                 args.minimum_dynamic_pairs,
                                                 args.max_gap)
                        else:
                            scores = score_translation_track(rows, table_key, key,
                                                             args.minimum_dynamic_pairs,
                                                             args.max_gap)
                    if feature == "rotations":
                        scores.sort(key=lambda row: (
                            row["rms_angle_magnitude_error_degrees"],
                            row["rms_orientation_error_degrees"],
                            row["matrix_row"], row["field_group"],
                            row["field_order"], row["delta_space"],
                        ))
                    reports.append({
                        "actor": f"0x{actor:08x}",
                        "table": table,
                        "feature": feature,
                        "sample_count": len(rows),
                        "matrix_activity": summary,
                        "candidate_count": len(scores),
                        "top": scores[:args.top],
                    })
    except (OSError, ValueError, TypeError, KeyError, json.JSONDecodeError) as exc:
        print(f"native_pose_channel_correlate: {exc}", file=sys.stderr)
        return 1

    payload = {
        "diagnostic_only": True,
        "source": str(args.pose_timeline),
        "method": "frame-to-frame packed pose angle groups vs normalized matrix rotation/translation",
        "angle_units": "one full turn is 65536 field units",
        "reports": reports,
        "limitations": [
            "Candidates are rankings, not bone or model-part assignments.",
            "Matrix rows can include parent transforms, bind offsets, or unrelated tables.",
            "Only adjacent samples with the same motion and cycle are compared.",
            "A stable reflection and basis scale are removed before comparison.",
            "A failed direct match does not falsify a relationship that uses an unknown rig transform.",
        ],
    }
    if args.output:
        try:
            with args.output.open("x", encoding="utf-8") as handle:
                json.dump(payload, handle, indent=2, allow_nan=False)
                handle.write("\n")
        except OSError as exc:
            print(f"native_pose_channel_correlate: cannot write report: {exc}",
                  file=sys.stderr)
            return 1
    if args.json:
        print(json.dumps(payload, indent=2, allow_nan=False))
        return 0
    for report in reports:
        print(f"actor {report['actor']} / {report['table']} / {report['feature']}: "
              f"{report['sample_count']} samples, "
              f"{report['candidate_count']} candidates; "
              f"matrix activity {report['matrix_activity']}")
        if not report["top"]:
            print("  no matrix row had enough dynamic samples")
        for rank, row in enumerate(report["top"], 1):
            if report["feature"] == "rotations":
                row_label = f"row {row['matrix_row']:02d}"
                if report["table"] == "joints":
                    row_label += f" @+{row['joint_actor_offset']:03x}"
                print(f"  {rank:2}. {row_label} <- fields "
                      f"{row['field_group']:02d} order {row['field_order']} "
                      f"{row['delta_space']}: angle RMS "
                      f"{row['rms_angle_magnitude_error_degrees']:.3f} deg, "
                      f"orientation RMS {row['rms_orientation_error_degrees']:.3f} deg; "
                      f"dynamic {row['predicted_dynamic_pairs']}/"
                      f"{row['actual_dynamic_pairs']}")
            else:
                row_label = f"row {row['matrix_row']:02d}"
                if report["table"] == "joints":
                    row_label += f" @+{row['joint_actor_offset']:03x}"
                print(f"  {rank:2}. {row_label} <- channels "
                      f"{row['field_group']:02d} {row['translation_space']}: "
                      f"relative magnitude RMS "
                      f"{row['relative_rms_magnitude_error']:.3f}, "
                      f"scale {row['fitted_scale']:.6g}; dynamic "
                      f"{row['predicted_dynamic_pairs']}/"
                      f"{row['actual_dynamic_pairs']}")
    if args.output:
        print(f"JSON: {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
