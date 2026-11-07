#!/usr/bin/env python3
"""Rank direct MT-channel/joint-record changes from a timeline capture.

Input is one or more ``joint_timeline.jsonl`` files produced by
``native_motion_timeline_probe.py --include-joints``. Capture files remain
separate when forming frame pairs and cross-track consensus. The report measures
same-motion, same-cycle frame-to-frame linear correlation between each of the
63 postprocessed actor channels and each float32 word in the 23 variable-stride
joint records. It is a lead-finding report: correlation alone does not prove a
field meaning, a hierarchy edge, a POL-part mapping, or a runtime action map.

Example:
  python tools/native_joint_channel_correlate.py \
      extract/analysis/native_motion_pose_s29_dense1800_v2/joint_timeline.jsonl \
      --actor 0x0c20138c --max-gap 30 --top 30
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import statistics
import struct
import sys


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"
CHANNEL_COUNT = 63
JOINT_COUNT = 23
FLOATS_PER_RECORD = 16


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def load_rows(paths: list[Path], actor_filter: int | None) -> dict[int, list[dict]]:
    actors: dict[int, list[dict]] = {}
    for path in paths:
        source = str(path.resolve())
        for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if not line.strip():
                continue
            try:
                row = json.loads(line)
                actor = int(row["actor"], 0)
                row["_source"] = source
                row["_frame"] = int(row["frame"])
                row["_motion"] = int(row["motion_id"], 0)
                row["_cycle"] = int(row["cycle"])
                row["_phase"] = int(row["phase_q8"])
                row["_descriptor"] = int(row["descriptor_pointer"], 0)
                row["_record"] = int(row["record_pointer"], 0)
                channels = row["channels_at_0x1d04"]
                records = row["joint_records_at_0x180"]
                if len(channels) != CHANNEL_COUNT or len(records) != JOINT_COUNT:
                    raise ValueError("channel or joint count has an unexpected size")
                decoded = []
                offsets = []
                for record in records:
                    raw = bytes.fromhex(record["raw"])
                    if len(raw) != FLOATS_PER_RECORD * 4:
                        raise ValueError("joint record prefix is not 64 bytes")
                    decoded.append(struct.unpack("<16f", raw))
                    offsets.append(int(record["actor_offset"]))
                row["_channels"] = [
                    float(value) if isinstance(value, (int, float)) and
                    math.isfinite(value) else None
                    for value in channels
                ]
                row["_records"] = decoded
                row["_record_offsets"] = offsets
                if actor_filter is None or actor == actor_filter:
                    actors.setdefault(actor, []).append(row)
            except (KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
                raise ValueError(f"{path}:{line_number}: {exc}") from exc
    for rows in actors.values():
        rows.sort(key=lambda row: (row["_source"], row["_frame"]))
    return actors


def correlation(xs: list[float], ys: list[float]
                ) -> tuple[float, float, float, float] | None:
    count = len(xs)
    if count < 2:
        return None
    mean_x = sum(xs) / count
    mean_y = sum(ys) / count
    var_x = sum((value - mean_x) ** 2 for value in xs)
    var_y = sum((value - mean_y) ** 2 for value in ys)
    if var_x <= 1e-18 or var_y <= 1e-18:
        return None
    covariance = sum((x - mean_x) * (y - mean_y)
                     for x, y in zip(xs, ys))
    slope = covariance / var_x
    intercept = mean_y - slope * mean_x
    residual = math.sqrt(sum((y - (slope * x + intercept)) ** 2
                             for x, y in zip(xs, ys)) / count)
    rms_y = math.sqrt(var_y / count)
    return covariance / math.sqrt(var_x * var_y), slope, intercept, residual / rms_y


def mapping_consensus(candidates: list[dict], min_tracks: int, limit: int) -> list[dict]:
    """Find channel/record-word leads recurring across distinct motion tracks."""
    grouped: dict[tuple[int, int, int], list[dict]] = {}
    for candidate in candidates:
        key = (candidate["channel"], candidate["joint_actor_offset"],
               candidate["word_index"])
        grouped.setdefault(key, []).append(candidate)

    consensus = []
    for (channel, offset, word), evidence in grouped.items():
        distinct: dict[tuple[str, int, int, int, int], dict] = {}
        for row in evidence:
            track = (row["capture"], int(row["motion_id"], 0), row["cycle"],
                     int(row["descriptor_pointer"], 0),
                     int(row["record_pointer"], 0))
            distinct[track] = row
        if len(distinct) < min_tracks:
            continue

        rows = list(distinct.values())
        slopes = [row["joint_delta_per_channel_delta"] for row in rows]
        positive = sum(slope > 0 for slope in slopes)
        negative = len(slopes) - positive
        sign_consistency = max(positive, negative) / len(slopes)
        consensus.append({
            "channel": channel,
            "joint_actor_offset": offset,
            "word_index": word,
            "byte_offset": word * 4,
            "tracks": len(rows),
            "distinct_motion_ids": sorted({row["motion_id"] for row in rows}),
            "pairs_total": sum(row["pairs"] for row in rows),
            "slope_sign_consistency": sign_consistency,
            "median_absolute_correlation": statistics.median(
                row["absolute_correlation"] for row in rows),
            "median_normalized_fit_rms": statistics.median(
                row["normalized_linear_fit_rms"] for row in rows),
            "median_joint_delta_per_channel_delta": statistics.median(slopes),
            "track_evidence": [{
                "capture": row["capture"],
                "motion_id": row["motion_id"],
                "cycle": row["cycle"],
                "pairs": row["pairs"],
                "correlation": row["correlation"],
                "gain": row["joint_delta_per_channel_delta"],
                "normalized_fit_rms": row["normalized_linear_fit_rms"],
            } for row in sorted(rows, key=lambda item:
                                (item["capture"], item["motion_id"]))],
        })
    consensus.sort(key=lambda row: (
        row["tracks"], row["slope_sign_consistency"],
        row["median_absolute_correlation"],
        -row["median_normalized_fit_rms"], row["pairs_total"]), reverse=True)
    return consensus[:limit]


def rank_actor(rows: list[dict], max_gap: int, min_pairs: int,
               consensus_min_tracks: int, consensus_top: int) -> dict:
    tracks: dict[tuple[str, int, int, int, int], list[tuple[dict, dict]]] = {}
    for previous, current in zip(rows, rows[1:]):
        gap = current["_frame"] - previous["_frame"]
        if (previous["_source"] != current["_source"] or
                gap <= 0 or gap > max_gap or
                previous["_motion"] != current["_motion"] or
                previous["_cycle"] != current["_cycle"] or
                previous["_descriptor"] != current["_descriptor"] or
                previous["_record"] != current["_record"] or
                previous["_phase"] == current["_phase"]):
            continue
        key = (previous["_source"], previous["_motion"], previous["_cycle"],
               previous["_descriptor"], previous["_record"])
        tracks.setdefault(key, []).append((previous, current))

    candidates = []
    dynamic_candidates = 0
    pair_count = 0
    for (capture, motion, cycle, descriptor, record_pointer), pair_rows in tracks.items():
        pair_count += len(pair_rows)
        for joint in range(JOINT_COUNT):
            for word in range(FLOATS_PER_RECORD):
                for channel in range(CHANNEL_COUNT):
                    xs: list[float] = []
                    ys: list[float] = []
                    for previous, current in pair_rows:
                        before_channel = previous["_channels"][channel]
                        after_channel = current["_channels"][channel]
                        before_joint = previous["_records"][joint][word]
                        after_joint = current["_records"][joint][word]
                        if (before_channel is None or after_channel is None or
                                not math.isfinite(before_joint) or
                                not math.isfinite(after_joint)):
                            continue
                        xs.append(after_channel - before_channel)
                        ys.append(after_joint - before_joint)
                    if len(xs) < min_pairs or not any(abs(value) > 1e-9 for value in ys):
                        continue
                    dynamic_candidates += 1
                    scored = correlation(xs, ys)
                    if scored is None:
                        continue
                    corr, slope, intercept, normalized_rms = scored
                    candidates.append({
                        "capture": capture,
                        "motion_id": f"0x{motion:04x}",
                        "cycle": cycle,
                        "descriptor_pointer": f"0x{descriptor:08x}",
                        "record_pointer": f"0x{record_pointer:08x}",
                        "channel": channel,
                        "joint_record": joint,
                        "joint_actor_offset": pair_rows[0][0]["_record_offsets"][joint],
                        "word_index": word,
                        "byte_offset": word * 4,
                        "pairs": len(xs),
                        "correlation": corr,
                        "absolute_correlation": abs(corr),
                        "joint_delta_per_channel_delta": slope,
                        "linear_intercept": intercept,
                        "normalized_linear_fit_rms": normalized_rms,
                    })
    candidates.sort(key=lambda row: (
        row["absolute_correlation"], -row["normalized_linear_fit_rms"],
        row["pairs"]), reverse=True)
    consensus = mapping_consensus(candidates, consensus_min_tracks,
                                  consensus_top)
    return {
        "sample_rows": len(rows),
        "compatible_motion_tracks": len(tracks),
        "compatible_dynamic_phase_pairs": pair_count,
        "dynamic_channel_joint_candidates": dynamic_candidates,
        "cross_track_mapping_leads": consensus,
        "ranked_candidates": candidates,
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("timeline", type=Path, nargs="+",
                        help="one or more joint_timeline.jsonl captures; runs are kept separate")
    parser.add_argument("--actor", type=address,
                        help="analyze one actor address; default analyzes every actor")
    parser.add_argument("--max-gap", type=int, default=30,
                        help="largest adjacent sample gap to compare (default: 30)")
    parser.add_argument("--min-pairs", type=int, default=5,
                        help="minimum compatible frame pairs per candidate (default: 5)")
    parser.add_argument("--top", type=int, default=30,
                        help="print this many candidates per actor (default: 30)")
    parser.add_argument("--consensus-min-tracks", type=int, default=2,
                        help="minimum distinct motion tracks for a consensus lead (default: 2)")
    parser.add_argument("--consensus-top", type=int, default=15,
                        help="print and retain this many cross-track leads per actor (default: 15)")
    parser.add_argument("--out", type=Path,
                        help="write a new JSON report inside extract/analysis")
    args = parser.parse_args(argv)
    if (args.max_gap <= 0 or args.min_pairs < 2 or args.top <= 0 or
            args.consensus_min_tracks < 2 or args.consensus_top <= 0):
        parser.error("--max-gap, --top, and --consensus-top must be positive; "
                     "--min-pairs must be at least 2 and --consensus-min-tracks at least 2")
    try:
        timelines = [path.resolve() for path in args.timeline]
        actors = load_rows(timelines, args.actor)
        if not actors:
            raise ValueError("timeline contains no rows for the selected actor")
        report = {
            "diagnostic_only": True,
            "timelines": [str(path) for path in timelines],
            "max_gap": args.max_gap,
            "min_pairs": args.min_pairs,
            "actors": {},
            "limitations": [
                "The channels are the postprocessed actor block, not raw evaluator output.",
                "Linear correlation does not prove a field meaning or a direct channel-to-joint mapping.",
                "Joint records are variable-stride prefixes; the report treats each 32-bit word as float32 only for ranking.",
                "No action label, asset row, hierarchy edge, or POL-part assignment is inferred.",
            ],
        }
        for actor, rows in sorted(actors.items()):
            result = rank_actor(rows, args.max_gap, args.min_pairs,
                                args.consensus_min_tracks, args.consensus_top)
            result["ranked_candidates"] = result["ranked_candidates"][:args.top]
            report["actors"][f"0x{actor:08x}"] = result
        if args.out:
            out_path = args.out.resolve()
            try:
                out_path.relative_to(ANALYSIS.resolve())
            except ValueError as exc:
                raise ValueError("--out must be inside extract/analysis") from exc
            out_path.parent.mkdir(parents=True, exist_ok=True)
            with out_path.open("x", encoding="utf-8") as handle:
                json.dump(report, handle, indent=2)
                handle.write("\n")
        for actor, result in report["actors"].items():
            print(f"{actor}: rows={result['sample_rows']} "
                  f"dynamic_pairs={result['compatible_dynamic_phase_pairs']} "
                  f"dynamic_channel_joint_candidates={result['dynamic_channel_joint_candidates']}")
            for candidate in result["ranked_candidates"]:
                print("  channel={channel:2d} joint={joint_record:2d} "
                      "@+{joint_actor_offset:03x} word={word_index:2d} "
                      "pairs={pairs:3d} r={correlation:+.4f} "
                      "gain={joint_delta_per_channel_delta:+.5g} "
                      "fit-rms={normalized_linear_fit_rms:.4f} "
                      "motion={motion_id}".format(**candidate))
            if result["cross_track_mapping_leads"]:
                print("  cross-track leads (diagnostic):")
                for candidate in result["cross_track_mapping_leads"]:
                    motions = ",".join(candidate["distinct_motion_ids"])
                    print("    channel={channel:2d} record=+{joint_actor_offset:03x} "
                          "word={word_index:2d} tracks={tracks:2d} "
                          "sign={slope_sign_consistency:.2f} "
                          "|r|={median_absolute_correlation:.4f} "
                          "fit-rms={median_normalized_fit_rms:.4f} "
                          "motions={motions}".format(motions=motions, **candidate))
        if args.out:
            print(f"JSON: {args.out.resolve()}")
        return 0
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        print(f"native_joint_channel_correlate: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
