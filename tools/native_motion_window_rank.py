#!/usr/bin/env python3
"""Rank contiguous, same-track windows in native pose timeline captures.

This is a capture-selection aid. It reports motion phase changes beside
postprocessed channel and joint-record changes without inferring meanings or
claiming that a changing field is driven by a particular MT channel.
"""

from __future__ import annotations

import argparse
import json
import struct
from collections import defaultdict
from pathlib import Path
from typing import Any


def integer(value: Any) -> int:
    return int(value, 0) if isinstance(value, str) else int(value)


def phase_of(row: dict[str, Any]) -> int | None:
    value = row.get("phase_q8")
    if value is not None:
        return integer(value)
    value = row.get("phase_raw")
    return integer(value) if value is not None else None


def track_key(row: dict[str, Any]) -> tuple[str, int, int, int, int]:
    return (
        str(row.get("actor", "?")),
        integer(row.get("motion_id", 0)),
        integer(row.get("cycle", 0)),
        integer(row.get("descriptor_pointer", 0)),
        integer(row.get("record_pointer", 0)),
    )


def joint_words(row: dict[str, Any]) -> dict[int, tuple[int, ...]]:
    result: dict[int, tuple[int, ...]] = {}
    for record in row.get("joint_records_at_0x180", []):
        try:
            raw = bytes.fromhex(record["raw"])
            if len(raw) % 4:
                continue
            result[int(record["index"])] = struct.unpack("<" + "I" * (len(raw) // 4), raw)
        except (KeyError, TypeError, ValueError):
            continue
    return result


def pair_changes(left: dict[str, Any], right: dict[str, Any]) -> tuple[int, int, int, int]:
    left_joints, right_joints = joint_words(left), joint_words(right)
    common = left_joints.keys() & right_joints.keys()
    changed_records = 0
    changed_words = 0
    for index in common:
        a, b = left_joints[index], right_joints[index]
        if a != b:
            changed_records += 1
            changed_words += sum(x != y for x, y in zip(a, b))

    a_channels = left.get("channels_at_0x1d04")
    b_channels = right.get("channels_at_0x1d04")
    changed_channels = 0
    if isinstance(a_channels, list) and isinstance(b_channels, list):
        changed_channels = sum(a != b for a, b in zip(a_channels, b_channels))
    a_phase, b_phase = phase_of(left), phase_of(right)
    phase_changed = int(a_phase is not None and b_phase is not None and a_phase != b_phase)
    return phase_changed, changed_records, changed_words, changed_channels


def summarize_window(rows: list[dict[str, Any]], start: int, end: int) -> dict[str, Any]:
    window = rows[start:end]
    phase_pairs = record_pairs = word_changes = channel_pairs = channel_changes = 0
    for left, right in zip(window, window[1:]):
        phase, records, words, channels = pair_changes(left, right)
        phase_pairs += phase
        record_pairs += records
        word_changes += words
        channel_pairs += int(channels > 0)
        channel_changes += channels

    phases = [phase_of(row) for row in window]
    phases = [phase for phase in phases if phase is not None]
    first, last = window[0], window[-1]
    actor, motion, cycle, descriptor, record = track_key(first)
    return {
        "actor": actor,
        "motion_id": f"0x{motion:04x}",
        "cycle": cycle,
        "descriptor_pointer": f"0x{descriptor:08x}",
        "record_pointer": f"0x{record:08x}",
        "first_frame": integer(first["frame"]),
        "last_frame": integer(last["frame"]),
        "samples": len(window),
        "phase_start": phases[0] if phases else None,
        "phase_end": phases[-1] if phases else None,
        "phase_change_pairs": phase_pairs,
        "joint_change_pairs": record_pairs,
        "joint_word_changes": word_changes,
        "channel_change_pairs": channel_pairs,
        "channel_changes": channel_changes,
    }


def contiguous_segments(rows: list[dict[str, Any]], max_gap: int) -> list[list[dict[str, Any]]]:
    segments: list[list[dict[str, Any]]] = []
    for row in sorted(rows, key=lambda item: integer(item["frame"])):
        if not segments or integer(row["frame"]) - integer(segments[-1][-1]["frame"]) > max_gap:
            segments.append([row])
        else:
            segments[-1].append(row)
    return segments


def rank(timeline: Path, max_gap: int, window_samples: int,
         min_phase_pairs: int) -> dict[str, Any]:
    tracks: dict[tuple[str, int, int, int, int], list[dict[str, Any]]] = defaultdict(list)
    with timeline.open("r", encoding="utf-8") as source:
        for line_no, line in enumerate(source, 1):
            if not line.strip():
                continue
            try:
                row = json.loads(line)
                row["frame"] = integer(row["frame"])
                tracks[track_key(row)].append(row)
            except (json.JSONDecodeError, KeyError, TypeError, ValueError) as exc:
                raise ValueError(f"{timeline}:{line_no}: invalid timeline row: {exc}") from exc

    windows: list[dict[str, Any]] = []
    segment_count = 0
    for rows in tracks.values():
        for segment in contiguous_segments(rows, max_gap):
            segment_count += 1
            width = min(window_samples, len(segment))
            if width < 2:
                continue
            starts = range(0, len(segment) - width + 1)
            for start in starts:
                summary = summarize_window(segment, start, start + width)
                if summary["phase_change_pairs"] >= min_phase_pairs:
                    windows.append(summary)

    windows.sort(key=lambda row: (
        row["phase_change_pairs"], row["joint_change_pairs"],
        row["joint_word_changes"], row["channel_changes"],
        -row["first_frame"],
    ), reverse=True)
    return {
        "timeline": str(timeline),
        "max_gap_frames": max_gap,
        "window_samples": window_samples,
        "min_phase_change_pairs": min_phase_pairs,
        "track_count": len(tracks),
        "contiguous_segment_count": segment_count,
        "candidate_windows": len(windows),
        "limitations": [
            "Exact motion, cycle, descriptor, and record pointers define a track.",
            "A phase or record change is not proof of an MT channel-to-joint mapping.",
            "The report does not identify the character, action, or POL part.",
        ],
        "windows": windows,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("timeline", type=Path, help="joint_timeline.jsonl from native_motion_timeline_probe.py")
    parser.add_argument("--max-gap", type=int, default=5,
                        help="largest frame gap allowed inside a contiguous segment (default: 5)")
    parser.add_argument("--window-samples", type=int, default=12,
                        help="sample count per ranked window (default: 12)")
    parser.add_argument("--min-phase-pairs", type=int, default=3,
                        help="require this many adjacent phase changes (default: 3)")
    parser.add_argument("--limit", type=int, default=20,
                        help="number of ranked rows to print (default: 20)")
    parser.add_argument("--out", type=Path, help="write the complete JSON report here")
    args = parser.parse_args()
    if args.max_gap < 1 or args.window_samples < 2 or args.min_phase_pairs < 1 or args.limit < 1:
        parser.error("max-gap and min-phase-pairs must be positive; window-samples must be at least 2")
    try:
        report = rank(args.timeline, args.max_gap, args.window_samples, args.min_phase_pairs)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"tracks={report['track_count']} segments={report['contiguous_segment_count']} "
          f"windows={report['candidate_windows']}")
    print("frame range        actor       motion/cycle  phase pairs  joint pairs  joint words  channel changes")
    for row in report["windows"][:args.limit]:
        print(f"{row['first_frame']:5d}-{row['last_frame']:<5d}  {row['actor']:<11} "
              f"{row['motion_id']}/{row['cycle']:<5}  {row['phase_change_pairs']:>11} "
              f"{row['joint_change_pairs']:>12} {row['joint_word_changes']:>12} "
              f"{row['channel_changes']:>16}")
    if args.out:
        print(f"report: {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
