#!/usr/bin/env python3
"""Fit MT channel triples to the seven vectors emitted at actor+0x1EFC.

Input is a ``pose_vectors_timeline.jsonl`` made by
``native_pose_timeline_extract.py``.  The retail routine at 0x8C09DA72 walks
seven 12-byte channel triples from actor+0x1D04 and writes seven vec3s from
actor+0x1EFC.  This tool checks that relationship within stable mounted-motion
tracks; it reports fitted linear transforms without assigning bone names.
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import statistics
import sys


def load(path: Path) -> list[dict]:
    rows = []
    for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        if not line.strip():
            continue
        try:
            row = json.loads(line)
            row["_frame"] = int(row["frame"])
            row["_actor"] = int(row["actor"], 0)
            row["_motion"] = int(row["motion_id"], 0)
            row["_cycle"] = int(row["cycle"])
            row["_descriptor"] = int(row["descriptor_pointer"], 0)
            row["_record"] = int(row["record_pointer"], 0)
            if len(row["channels_at_0x1d04"]) < 21 or len(row["pose_vectors_at_0x1efc"]) != 21:
                raise ValueError("expected 21 source and output float values")
            if len(row["actor_offset_at_0x1488"]) != 3:
                raise ValueError("expected the three-float actor offset")
            rows.append(row)
        except (KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
            raise ValueError(f"{path}:{number}: {exc}") from exc
    return rows


def solve3(matrix: list[list[float]], rhs: list[list[float]]) -> list[list[float]] | None:
    """Solve A*B=C for a 3x3 normal matrix using pivoted Gauss-Jordan."""
    a = [matrix[i][:] + rhs[i][:] for i in range(3)]
    for col in range(3):
        pivot = max(range(col, 3), key=lambda row: abs(a[row][col]))
        if abs(a[pivot][col]) < 1e-16:
            return None
        a[col], a[pivot] = a[pivot], a[col]
        scale = a[col][col]
        a[col] = [value / scale for value in a[col]]
        for row in range(3):
            if row == col:
                continue
            factor = a[row][col]
            a[row] = [x - factor * y for x, y in zip(a[row], a[col])]
    return [row[3:] for row in a]


def track_fit(pairs: list[tuple[list[float], list[float]]]) -> tuple[int, float] | None:
    if len(pairs) < 4:
        return None
    gram = [[0.0] * 3 for _ in range(3)]
    cross = [[0.0] * 3 for _ in range(3)]
    for x, y in pairs:
        for i in range(3):
            for j in range(3):
                gram[i][j] += x[i] * x[j]
                cross[i][j] += x[i] * y[j]
    coeff = solve3(gram, cross)
    if coeff is None:
        return None
    error = 0.0
    energy = 0.0
    for x, y in pairs:
        for j in range(3):
            prediction = sum(x[i] * coeff[i][j] for i in range(3))
            error += (y[j] - prediction) ** 2
            energy += y[j] ** 2
    if energy <= 1e-18:
        return None
    return len(pairs), math.sqrt(error / energy)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("timeline", type=Path)
    parser.add_argument("--actor", type=lambda value: int(value, 0))
    parser.add_argument("--out", type=Path)
    args = parser.parse_args()
    try:
        rows = load(args.timeline)
        if args.actor is not None:
            rows = [row for row in rows if row["_actor"] == args.actor]
        tracks: dict[tuple, list[dict]] = {}
        for row in rows:
            key = (row["_actor"], row["_motion"], row["_cycle"],
                   row["_descriptor"], row["_record"])
            tracks.setdefault(key, []).append(row)

        fits: dict[tuple[int, int], list[tuple[int, float]]] = {}
        for key, samples in tracks.items():
            samples.sort(key=lambda row: row["_frame"])
            transitions = []
            for before, after in zip(samples, samples[1:]):
                if (before["_frame"] >= after["_frame"] or
                        int(before["phase_q8"]) == int(after["phase_q8"])):
                    continue
                x0 = before["channels_at_0x1d04"]
                x1 = after["channels_at_0x1d04"]
                offset0 = before["actor_offset_at_0x1488"]
                offset1 = after["actor_offset_at_0x1488"]
                y0 = [float(value) - float(offset0[index % 3])
                      for index, value in enumerate(before["pose_vectors_at_0x1efc"])]
                y1 = [float(value) - float(offset1[index % 3])
                      for index, value in enumerate(after["pose_vectors_at_0x1efc"])]
                transitions.append((x0, x1, y0, y1))
            for source in range(7):
                x_values = []
                for x0, x1, _y0, _y1 in transitions:
                    delta = [float(x1[source * 3 + k]) - float(x0[source * 3 + k])
                             for k in range(3)]
                    x_values.append(delta)
                for destination in range(7):
                    pairs = []
                    for x, (_x0, _x1, y0, y1) in zip(x_values, transitions):
                        y = [float(y1[destination * 3 + k]) - float(y0[destination * 3 + k])
                             for k in range(3)]
                        if all(math.isfinite(value) for value in x + y):
                            pairs.append((x, y))
                    result = track_fit(pairs)
                    if result:
                        fits.setdefault((source, destination), []).append(result)

        report = []
        for (source, destination), values in fits.items():
            report.append({
                "source_channel_triple": source,
                "output_vector": destination,
                "tracks": len(values),
                "pairs": sum(count for count, _error in values),
                "median_relative_fit_error": statistics.median(error for _count, error in values),
                "worst_relative_fit_error": max(error for _count, error in values),
            })
        report.sort(key=lambda row: (
            row["tracks"], -row["median_relative_fit_error"], row["pairs"]), reverse=True)
        result = {"diagnostic_only": True, "tracks": len(tracks), "fits": report}
        if args.out:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
        print(f"tracks={len(tracks)} fits={len(report)}")
        for row in report[:30]:
            print(f"channel[{row['source_channel_triple']}] -> vector[{row['output_vector']}]: "
                  f"tracks={row['tracks']} pairs={row['pairs']} "
                  f"median-relative-error={row['median_relative_fit_error']:.4g} "
                  f"worst={row['worst_relative_fit_error']:.4g}")
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"native_motion_vector_fit: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
