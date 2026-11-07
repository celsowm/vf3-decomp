#!/usr/bin/env python3
"""Compare MT channels, fighter pose storage, and actor fields in replay cases.

This is an offline diagnostic for corpora that capture an actor across a motion
update. It reports changed channel values, variable-stride joint records, the
18 selector attachment rows, bone matrices, and cached-pose records. It does
not assume that a channel corresponds to a particular joint or POL model.
Repeat --actor-range OFFSET:SIZE to inspect any aligned actor-relative dword
span; ranges are unavailable when the corpus did not capture them.

Example:
  python tools/mt_pose_capture_compare.py extract/analysis/coverage_65_replay_record_dev_v3 \
      --entry 0x8c0a9036 --case 4 --actor-register r5
  python tools/mt_pose_capture_compare.py extract/analysis/native_pose_orchestration_s29_v1 \
      --entry 0x8c09eaf2 --actor-register r4 --summary --per-case \
      --actor-range 0xcc:0x30 --actor-range 0x640:0xc0
"""

from __future__ import annotations

import argparse
from collections import Counter
import json
import math
from pathlib import Path
import struct
import sys

ADDRESS_MASK = 0x1FFFFFFF
CHANNELS = 63
BONES = 23
POSE_FIELDS = 42
ATTACHMENTS = 18
ATTACHMENT_OFFSET = 0x180
JOINT_ADVANCES = bytes.fromhex("4080004000408000400040804000400040400040004040")
JOINT_STARTS = []
_cursor = 0
for _advance in JOINT_ADVANCES:
    JOINT_STARTS.append(_cursor)
    _cursor += _advance


def number(text: str) -> int:
    try:
        return int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc


def register(text: str) -> int:
    value = text.lower()
    if not value.startswith("r") or not value[1:].isdigit():
        raise argparse.ArgumentTypeError("expected a GPR name such as r4")
    index = int(value[1:])
    if not 0 <= index < 16:
        raise argparse.ArgumentTypeError("GPR index must be in 0..15")
    return index


def parse_actor_range(text: str) -> tuple[int, int]:
    try:
        offset_text, size_text = text.split(":", 1)
        offset, size = int(offset_text, 0), int(size_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            "expected OFFSET:SIZE, for example 0x1f20:0x60") from exc
    if offset < 0 or size <= 0 or offset + size > 0x10000:
        raise argparse.ArgumentTypeError("actor range must fit within 0x10000 bytes")
    if offset & 3 or size & 3:
        raise argparse.ArgumentTypeError("actor range offset and size must be 4-byte aligned")
    return offset, size


def load_case(directory: Path, entry: int, case_number: int):
    if case_number < 1:
        raise ValueError("case number must be one-based and positive")
    lines = (directory / f"f_{entry:08x}.cases").read_text().splitlines()
    if case_number > len(lines):
        raise ValueError(f"case {case_number} is outside the {len(lines)} cases in the corpus")
    fields = lines[case_number - 1].split()
    if len(fields) < 78:
        raise ValueError(f"case {case_number} is truncated")
    try:
        before_count = int(fields[75])
    except ValueError as exc:
        raise ValueError(f"case {case_number} has an invalid input-window count") from exc
    if before_count < 0:
        raise ValueError(f"case {case_number} has a negative input-window count")
    before_end = 76 + 2 * before_count
    if len(fields) < before_end:
        raise ValueError(f"case {case_number} has a truncated input-window map")
    windows = [(int(fields[76 + 2 * i], 16), int(fields[77 + 2 * i], 16))
               for i in range(before_count)]
    after_index = before_end
    if len(fields) <= after_index + 1:
        raise ValueError(f"case {case_number} has a truncated output-window map")
    try:
        after_count = int(fields[after_index + 1])
    except ValueError as exc:
        raise ValueError(f"case {case_number} has an invalid output-window count") from exc
    if after_count < 0:
        raise ValueError(f"case {case_number} has a negative output-window count")
    after_end = after_index + 2 + 2 * after_count
    if len(fields) < after_end:
        raise ValueError(f"case {case_number} has a truncated output-window map")
    after_windows = [(int(fields[after_index + 2 + 2 * i], 16),
                      int(fields[after_index + 3 + 2 * i], 16))
                     for i in range(after_count)]
    if windows != after_windows:
        raise ValueError("input/output RAM window maps differ")
    before_path = directory / fields[74]
    after_path = directory / fields[after_index]
    before = before_path.read_bytes()
    after = after_path.read_bytes()
    if any(size < 0 for _base, size in windows):
        raise ValueError(f"case {case_number} has a negative RAM-window size")
    expected_size = sum(size for _base, size in windows)
    if len(before) != expected_size or len(after) != expected_size:
        raise ValueError("RAM shadows do not match the captured window lengths")
    registers = [int(value, 16) for value in fields[:16]]
    return fields, registers, before, after, windows


def read_ram(blob: bytes, windows: list[tuple[int, int]], address: int,
             size: int) -> bytes | None:
    physical = address & ADDRESS_MASK
    file_offset = 0
    for base, length in windows:
        if base <= physical and size <= base + length - physical:
            start = file_offset + physical - base
            return blob[start:start + size]
        file_offset += length
    return None


def read_u16(blob: bytes, windows: list[tuple[int, int]], address: int):
    raw = read_ram(blob, windows, address, 2)
    return None if raw is None else struct.unpack("<H", raw)[0]


def read_u32(blob: bytes, windows: list[tuple[int, int]], address: int):
    raw = read_ram(blob, windows, address, 4)
    return None if raw is None else struct.unpack("<I", raw)[0]


def json_float(raw: bytes) -> float | dict[str, str]:
    bits = struct.unpack("<I", raw)[0]
    value = struct.unpack("<f", raw)[0]
    if math.isfinite(value):
        return value
    category = "nan" if math.isnan(value) else ("+inf" if value > 0 else "-inf")
    return {"non_finite": category, "bits": f"0x{bits:08x}"}


def changed_words(before: bytes | None, after: bytes | None, limit: int = 256):
    if before is None or after is None:
        return None
    if len(before) != len(after):
        return None
    rows = []
    usable = len(before) & ~3
    for offset in range(0, usable, 4):
        old = struct.unpack_from("<I", before, offset)[0]
        new = struct.unpack_from("<I", after, offset)[0]
        if old == new:
            continue
        rows.append({
            "offset": offset,
            "before_u32": f"0x{old:08x}",
            "after_u32": f"0x{new:08x}",
            "before_f32": json_float(before[offset:offset + 4]),
            "after_f32": json_float(after[offset:offset + 4]),
        })
        if len(rows) >= limit:
            break
    return rows


def compare_pose_fields(before: bytes, after: bytes,
                        windows: list[tuple[int, int]], actor: int):
    """Compare the 42-float source span and its packed halfword destination."""
    source_before = read_ram(before, windows, actor + 0x1D58, POSE_FIELDS * 4)
    source_after = read_ram(after, windows, actor + 0x1D58, POSE_FIELDS * 4)
    stored_before = read_ram(before, windows, actor + 0x1F50, POSE_FIELDS * 2)
    stored_after = read_ram(after, windows, actor + 0x1F50, POSE_FIELDS * 2)
    if any(value is None for value in
           (source_before, source_after, stored_before, stored_after)):
        return None

    old_floats = struct.unpack(f"<{POSE_FIELDS}f", source_before)
    new_floats = struct.unpack(f"<{POSE_FIELDS}f", source_after)
    old_words = struct.unpack(f"<{POSE_FIELDS}H", stored_before)
    new_words = struct.unpack(f"<{POSE_FIELDS}H", stored_after)
    source_changes = []
    stored_changes = []
    ftrc_matches = []
    for index, (old_float, new_float, old_word, new_word) in enumerate(
            zip(old_floats, new_floats, old_words, new_words)):
        if source_before[index * 4:index * 4 + 4] != source_after[index * 4:index * 4 + 4]:
            source_changes.append({
                "field": index,
                "before": json_float(source_before[index * 4:index * 4 + 4]),
                "after": json_float(source_after[index * 4:index * 4 + 4]),
            })
        if old_word != new_word:
            stored_changes.append({
                "field": index,
                "before": f"0x{old_word:04x}",
                "after": f"0x{new_word:04x}",
            })
        valid = math.isfinite(new_float) and -2147483648.0 <= new_float < 2147483648.0
        expected = math.trunc(new_float) & 0xFFFF if valid else None
        ftrc_matches.append({
            "field": index,
            "expected": f"0x{expected:04x}" if expected is not None else None,
            "actual": f"0x{new_word:04x}",
            "matches": expected == new_word if expected is not None else None,
        })
    return {
        "source_before": [json_float(source_before[i * 4:i * 4 + 4])
                          for i in range(POSE_FIELDS)],
        "source_after": [json_float(source_after[i * 4:i * 4 + 4])
                         for i in range(POSE_FIELDS)],
        "stored_before": [f"0x{value:04x}" for value in old_words],
        "stored_after": [f"0x{value:04x}" for value in new_words],
        "source_changed": source_changes,
        "stored_changed": stored_changes,
        "ftrc_matches_after": ftrc_matches,
        "ftrc_match_count": sum(row["matches"] is True for row in ftrc_matches),
        "ftrc_checked_count": sum(row["matches"] is not None for row in ftrc_matches),
        "notes": [
            "The 42 source and destination fields are compared by index.",
            "FTRC comparison uses truncation toward zero and the low 16 bits.",
            "This does not map the 42 fields to MT channels, joints, or POL parts.",
        ],
    }


def compare_case(directory: Path, entry: int, case_number: int,
                 actor_register: int, verbose: bool, pose_fields: bool = False,
                 actor_ranges: list[tuple[int, int]] | None = None):
    _fields, registers, before, after, windows = load_case(directory, entry, case_number)
    actor = registers[actor_register]

    def region(offset: int, length: int):
        return (read_ram(before, windows, actor + offset, length),
                read_ram(after, windows, actor + offset, length))

    channel_before, channel_after = region(0x1D04, CHANNELS * 4)
    channels = None
    if channel_before is not None and channel_after is not None:
        channels = {
            "changed": [
                {"channel": index,
                 "before": json_float(channel_before[index * 4:index * 4 + 4]),
                 "after": json_float(channel_after[index * 4:index * 4 + 4])}
                for index in range(CHANNELS)
                if channel_before[index * 4:index * 4 + 4] !=
                   channel_after[index * 4:index * 4 + 4]
            ],
        }
        if verbose:
            channels["before"] = [
                json_float(channel_before[index * 4:index * 4 + 4])
                for index in range(CHANNELS)
            ]
            channels["after"] = [
                json_float(channel_after[index * 4:index * 4 + 4])
                for index in range(CHANNELS)
            ]

    joint_before, joint_after = region(0x180, 0x600)
    joint_rows = []
    if joint_before is not None and joint_after is not None:
        for bone, offset in enumerate(JOINT_STARTS):
            old = joint_before[offset:offset + 0x40]
            new = joint_after[offset:offset + 0x40]
            changes = changed_words(old, new)
            if changes:
                row = {"bone_index": bone, "joint_offset": offset,
                       "changed_word_count": len(changes)}
                if verbose:
                    row["changed_words"] = changes
                joint_rows.append(row)

    attachment_before, attachment_after = region(
        ATTACHMENT_OFFSET, ATTACHMENTS * 64)
    attachment_rows = []
    if attachment_before is not None and attachment_after is not None:
        for attachment in range(ATTACHMENTS):
            start = attachment * 64
            changes = changed_words(attachment_before[start:start + 64],
                                    attachment_after[start:start + 64])
            if changes:
                row = {"attachment_index": attachment,
                       "actor_offset": f"0x{ATTACHMENT_OFFSET + start:04x}",
                       "changed_word_count": len(changes)}
                if verbose:
                    row["changed_words"] = changes
                attachment_rows.append(row)

    matrices_before, matrices_after = region(0x7C0, BONES * 64)
    matrices = []
    if matrices_before is not None and matrices_after is not None:
        for bone in range(BONES):
            start = bone * 64
            changes = changed_words(matrices_before[start:start + 64],
                                    matrices_after[start:start + 64])
            if changes:
                row = {"bone_index": bone, "changed_word_count": len(changes)}
                if verbose:
                    row["changed_words"] = changes
                matrices.append(row)

    poses_before, poses_after = region(0xE00, BONES * 20)
    poses = []
    if poses_before is not None and poses_after is not None:
        for bone in range(BONES):
            start = bone * 20
            changes = changed_words(poses_before[start:start + 20],
                                    poses_after[start:start + 20])
            if changes:
                row = {"bone_index": bone, "changed_word_count": len(changes)}
                if verbose:
                    row["changed_words"] = changes
                poses.append(row)

    motion_before = read_u16(before, windows, actor + 0x3C)
    motion_after = read_u16(after, windows, actor + 0x3C)
    record_before = read_u32(before, windows, actor + 0x1D00)
    record_after = read_u32(after, windows, actor + 0x1D00)

    report = {
        "diagnostic_only": True,
        "entry": f"0x{entry:08x}",
        "case": case_number,
        "actor_register": f"r{actor_register}",
        "actor": f"0x{actor:08x}",
        "motion_id": {
            "before": f"0x{motion_before:03x}" if motion_before is not None else None,
            "after": f"0x{motion_after:03x}" if motion_after is not None else None,
        },
        "cycle": {
            "before": read_u16(before, windows, actor + 0x1A00),
            "after": read_u16(after, windows, actor + 0x1A00),
        },
        "animation_record": {
            "before": f"0x{record_before:08x}" if record_before is not None else None,
            "after": f"0x{record_after:08x}" if record_after is not None else None,
        },
        "channels_at_actor_plus_0x1d04": channels,
        "joint_rows_with_changes": joint_rows if joint_before is not None else None,
        "attachment_rows_with_changes": (
            attachment_rows if attachment_before is not None else None),
        "matrix_rows_with_changes": matrices if matrices_before is not None else None,
        "cached_pose_rows_with_changes": poses if poses_before is not None else None,
        "notes": [
            "Bone indices follow the 23-entry joint-advance table recovered for 0x8c091438.",
            "Attachment indices are the 18 rows at actor+0x180; fighter_refresh dispatches selector i with row i.",
            "No channel-to-bone or POL-part mapping is asserted by this report.",
        ],
    }
    if actor_ranges:
        range_reports = []
        for offset, length in actor_ranges:
            old = read_ram(before, windows, actor + offset, length)
            new = read_ram(after, windows, actor + offset, length)
            row = {
                "actor_offset": f"0x{offset:04x}",
                "size": length,
                "available": old is not None and new is not None,
                "changed_word_count": None,
            }
            if old is not None and new is not None:
                changes = []
                changed_count = 0
                for word_offset in range(0, length, 4):
                    old_word = old[word_offset:word_offset + 4]
                    new_word = new[word_offset:word_offset + 4]
                    if old_word == new_word:
                        continue
                    changed_count += 1
                    if verbose and len(changes) < 256:
                        change = changed_words(old_word, new_word, limit=1)[0]
                        change["offset"] = word_offset
                        change["actor_offset"] = f"0x{offset + word_offset:04x}"
                        changes.append(change)
                row["changed_word_count"] = changed_count
                if verbose:
                    row["changed_words"] = changes
                    row["changed_words_truncated"] = changed_count > len(changes)
            range_reports.append(row)
        report["actor_field_ranges"] = range_reports
    if pose_fields:
        report["pose_fields"] = compare_pose_fields(before, after, windows, actor)
    return report


def capture_matrix_bytes(directory: Path, entry: int, case_number: int,
                         actor_register: int) -> tuple[int, bytes]:
    _fields, registers, _before, after, windows = load_case(
        directory, entry, case_number)
    actor = registers[actor_register]
    matrices = read_ram(after, windows, actor + 0x7C0, BONES * 64)
    if matrices is None:
        raise ValueError(
            f"case {case_number} does not capture the actor's 23 bone matrices")
    return actor, matrices


def summarize_case(report: dict[str, object]) -> dict[str, object]:
    channels = report["channels_at_actor_plus_0x1d04"]
    joints = report["joint_rows_with_changes"]
    matrices = report["matrix_rows_with_changes"]
    cached = report["cached_pose_rows_with_changes"]
    result = {
        "case": report["case"],
        "actor_register": report["actor_register"],
        "actor": report["actor"],
        "motion_id": report["motion_id"],
        "cycle": report["cycle"],
        "animation_record": report["animation_record"],
        "changed_channel_count": len(channels["changed"]) if channels is not None else None,
        "changed_joint_record_count": len(joints) if joints is not None else None,
        "changed_attachment_row_count": (
            len(report["attachment_rows_with_changes"])
            if report["attachment_rows_with_changes"] is not None else None),
        "changed_attachment_indices": (
            [row["attachment_index"]
             for row in report["attachment_rows_with_changes"]]
            if report["attachment_rows_with_changes"] is not None else None),
        "changed_matrix_count": len(matrices) if matrices is not None else None,
        "changed_cached_pose_count": len(cached) if cached is not None else None,
    }
    pose_fields = report.get("pose_fields")
    if pose_fields is not None:
        result["changed_pose_source_fields"] = len(pose_fields["source_changed"])
        result["changed_pose_stored_fields"] = len(pose_fields["stored_changed"])
        result["pose_ftrc_match_count"] = pose_fields["ftrc_match_count"]
        result["pose_ftrc_checked_count"] = pose_fields["ftrc_checked_count"]
    if "actor_field_ranges" in report:
        result["actor_field_ranges"] = [
            {key: row[key] for key in
             ("actor_offset", "size", "available", "changed_word_count")}
            for row in report["actor_field_ranges"]
        ]
    return result


def summarize_cases(reports: list[dict[str, object]],
                    include_cases: bool = False) -> dict[str, object]:
    motion_before = Counter()
    motion_after = Counter()
    channel_change_counts = Counter()
    available = {
        "channels": 0,
        "joint_records": 0,
        "attachment_rows": 0,
        "matrices": 0,
        "cached_pose": 0,
    }
    changed = {
        "channels": [],
        "joint_records": [],
        "attachment_rows": [],
        "matrices": [],
        "cached_pose": [],
    }
    range_summaries = []
    if reports and "actor_field_ranges" in reports[0]:
        range_summaries = [
            {"actor_offset": row["actor_offset"], "size": row["size"],
             "cases_available": 0, "cases_with_changes": 0,
             "changed_word_count_total": 0, "max_changed_word_count": 0}
            for row in reports[0]["actor_field_ranges"]
        ]
    for report in reports:
        motion = report["motion_id"]
        if motion["before"] is not None:
            motion_before[motion["before"]] += 1
        if motion["after"] is not None:
            motion_after[motion["after"]] += 1
        channels = report["channels_at_actor_plus_0x1d04"]
        joints = report["joint_rows_with_changes"]
        attachments = report["attachment_rows_with_changes"]
        matrices = report["matrix_rows_with_changes"]
        cached = report["cached_pose_rows_with_changes"]
        pose_fields = report.get("pose_fields")
        if pose_fields is not None:
            available.setdefault("pose_fields", 0)
            changed.setdefault("pose_source_fields", [])
            changed.setdefault("pose_stored_fields", [])
        available["channels"] += channels is not None
        available["joint_records"] += joints is not None
        available["attachment_rows"] += attachments is not None
        available["matrices"] += matrices is not None
        available["cached_pose"] += cached is not None
        if pose_fields is not None:
            available["pose_fields"] += 1
        channel_changes = len(channels["changed"]) if channels else 0
        joint_changes = len(joints) if joints is not None else 0
        attachment_changes = len(attachments) if attachments is not None else 0
        matrix_changes = len(matrices) if matrices is not None else 0
        cached_changes = len(cached) if cached is not None else 0
        if channels is not None:
            channel_change_counts[str(channel_changes)] += 1
        if channel_changes:
            changed["channels"].append(report["case"])
        if joint_changes:
            changed["joint_records"].append(report["case"])
        if attachment_changes:
            changed["attachment_rows"].append(report["case"])
        if matrix_changes:
            changed["matrices"].append(report["case"])
        if cached_changes:
            changed["cached_pose"].append(report["case"])
        if pose_fields is not None:
            if pose_fields["source_changed"]:
                changed["pose_source_fields"].append(report["case"])
            if pose_fields["stored_changed"]:
                changed["pose_stored_fields"].append(report["case"])
        for index, row in enumerate(report.get("actor_field_ranges", [])):
            aggregate = range_summaries[index]
            if not row["available"]:
                continue
            aggregate["cases_available"] += 1
            changed_count = row["changed_word_count"] or 0
            aggregate["changed_word_count_total"] += changed_count
            aggregate["max_changed_word_count"] = max(
                aggregate["max_changed_word_count"], changed_count)
            if changed_count:
                aggregate["cases_with_changes"] += 1
    summary = {
        "diagnostic_only": True,
        "entry": reports[0]["entry"] if reports else None,
        "cases_examined": len(reports),
        "cases_with_regions_available": available,
        "motion_id_before_counts": dict(sorted(motion_before.items())),
        "motion_id_after_counts": dict(sorted(motion_after.items())),
        "channel_change_count_distribution": dict(sorted(
            channel_change_counts.items(), key=lambda item: int(item[0]))),
        "cases_with_changes": changed,
        "notes": [
            "This summary does not establish action labels or channel-to-bone/POL mappings.",
            "Attachment rows are the 18 matrices at actor+0x180 with a 0x40-byte stride; fighter_refresh dispatches selector i with row i.",
            "Missing captured regions count as unavailable, not as unchanged.",
        ],
    }
    if include_cases:
        summary["case_summaries"] = [summarize_case(report) for report in reports]
    if range_summaries:
        summary["actor_field_ranges"] = range_summaries
    return summary


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("corpus", type=Path)
    parser.add_argument("--entry", required=True, type=number, help="watched entry PC")
    parser.add_argument("--case", action="append", type=int,
                        help="one-based corpus case; repeat to compare several")
    parser.add_argument("--summary", action="store_true",
                        help="summarize every case in the corpus")
    parser.add_argument("--per-case", action="store_true",
                        help="with --summary, include actor/motion and pose-change counts per case")
    parser.add_argument("--actor-register", default="r5", type=register,
                        help="GPR holding actor pointer (default: r5)")
    parser.add_argument("--verbose", action="store_true",
                        help="include every changed 32-bit word and all 63 channel values")
    parser.add_argument("--pose-fields", action="store_true",
                        help="compare actor+0x1d58 float inputs and actor+0x1f50 halfword outputs")
    parser.add_argument("--actor-range", action="append", type=parse_actor_range,
                        default=[], metavar="OFFSET:SIZE",
                        help="compare a 4-byte-aligned actor-relative range; repeatable")
    parser.add_argument("--out", type=Path,
                        help="write a new JSON report; existing files are preserved")
    parser.add_argument("--matrix-bin", type=Path,
                        help="write the selected case's 23 output matrices as 1472 raw bytes")
    args = parser.parse_args(argv)
    if args.matrix_bin and (args.summary or len(args.case or []) != 1):
        parser.error("--matrix-bin requires exactly one --case and cannot be used with --summary")
    if args.summary:
        if args.case or args.verbose:
            parser.error("--summary cannot be combined with --case or --verbose")
    elif not args.case:
        parser.error("supply --case N or use --summary")
    if args.per_case and not args.summary:
        parser.error("--per-case requires --summary")
    try:
        if args.summary:
            case_file = args.corpus / f"f_{args.entry:08x}.cases"
            case_count = len(case_file.read_text().splitlines())
            if case_count == 0:
                raise ValueError(f"no cases found in {case_file}")
            reports = [compare_case(args.corpus, args.entry, case,
                                    args.actor_register, False, args.pose_fields,
                                    args.actor_range)
                       for case in range(1, case_count + 1)]
            report = summarize_cases(reports, include_cases=args.per_case)
        else:
            reports = [compare_case(args.corpus, args.entry, case,
                                    args.actor_register, args.verbose,
                                    args.pose_fields, args.actor_range)
                       for case in args.case]
            report = reports[0] if len(reports) == 1 else reports
        matrix_dump = None
        if args.matrix_bin:
            actor, matrix_dump = capture_matrix_bytes(
                args.corpus, args.entry, args.case[0], args.actor_register)
            report["output_matrix_translations"] = [
                {"bone_index": bone,
                 "xyz": [json_float(matrix_dump[bone * 64 + (12 + axis) * 4:
                                                  bone * 64 + (13 + axis) * 4])
                         for axis in range(3)]}
                for bone in range(BONES)
            ]
    except (OSError, ValueError, struct.error) as exc:
        print(f"mt_pose_capture_compare: {exc}", file=sys.stderr)
        return 1
    output = json.dumps(report, indent=2, allow_nan=False) + "\n"
    if args.out:
        try:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            with args.out.open("x", encoding="utf-8") as target:
                target.write(output)
        except FileExistsError:
            parser.error(f"refusing to overwrite {args.out}")
        except OSError as exc:
            print(f"mt_pose_capture_compare: cannot write {args.out}: {exc}",
                  file=sys.stderr)
            return 1
    if args.matrix_bin:
        try:
            args.matrix_bin.parent.mkdir(parents=True, exist_ok=True)
            with args.matrix_bin.open("xb") as target:
                target.write(matrix_dump)
        except FileExistsError:
            parser.error(f"refusing to overwrite {args.matrix_bin}")
        except OSError as exc:
            print(f"mt_pose_capture_compare: cannot write {args.matrix_bin}: {exc}",
                  file=sys.stderr)
            return 1
        print(f"wrote 23 output matrices for actor 0x{actor:08x} to {args.matrix_bin}",
              file=sys.stderr)
    print(output, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
