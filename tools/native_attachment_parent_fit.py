#!/usr/bin/env python3
"""Rank attachment parent/pose-group candidates from captured timelines.

For each possible parent row, child row, and packed Euler group, test whether
the parent-relative child rotation can be represented as one constant bind
rotation followed by that group's Z-Y-X animation. This is a diagnostic fit;
it does not assign skeleton semantics.
"""

from __future__ import annotations

import argparse
import json
import math
import statistics
from pathlib import Path


def mm(a, b):
    return tuple(tuple(sum(a[r][k] * b[k][c] for k in range(3))
                       for c in range(3)) for r in range(3))


def tr(a):
    return tuple(tuple(a[c][r] for c in range(3)) for r in range(3))


def rot(values):
    cols = [tuple(float(values[c * 4 + r]) for r in range(3)) for c in range(3)]
    norm = lambda v: math.sqrt(sum(x * x for x in v))
    dot = lambda a, b: sum(x * y for x, y in zip(a, b))
    x = tuple(v / norm(cols[0]) for v in cols[0])
    y0 = tuple(cols[1][i] - dot(cols[1], x) * x[i] for i in range(3))
    y = tuple(v / norm(y0) for v in y0)
    z = (x[1]*y[2]-x[2]*y[1], x[2]*y[0]-x[0]*y[2], x[0]*y[1]-x[1]*y[0])
    return tuple(tuple((x, y, z)[c][r] for c in range(3)) for r in range(3))


def axis(axis, angle):
    q = (angle & 0xffff) * (2 * math.pi / 65536.0)
    s, c = math.sin(q), math.cos(q)
    if axis == 0: return ((1,0,0),(0,c,-s),(0,s,c))
    if axis == 1: return ((c,0,s),(0,1,0),(-s,0,c))
    return ((c,-s,0),(s,c,0),(0,0,1))


def euler(fields, group):
    i = group * 3
    return mm(mm(axis(2, fields[i]), axis(1, fields[i+1])), axis(0, fields[i+2]))


def angle(a, b):
    d = mm(tr(a), b)
    return math.degrees(math.acos(max(-1.0, min(1.0, (d[0][0]+d[1][1]+d[2][2]-1)*0.5))))


def load(path):
    tracks = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.strip(): continue
        r = json.loads(line)
        key = (r["actor"], r["motion_id"], r["cycle"], r["descriptor_pointer"], r["record_pointer"])
        matrices = r["attachment_rows_at_0x180"]
        rows = [rot(matrices[i]) for i in range(18)]
        translations = [tuple(float(v) for v in matrices[i][12:15]) for i in range(18)]
        fields = [int(v) & 0xffff for v in r["packed_pose_fields_at_0x1f50"]]
        tracks.setdefault(key, []).append((int(r["frame"]), int(r.get("phase_q8", 0)), rows, fields, translations))
    return tracks


def local_position(sample, child, parent):
    child_pos = sample[4][child]
    if parent < 0:
        return child_pos
    delta = tuple(child_pos[k] - sample[4][parent][k] for k in range(3))
    return tuple(sum(sample[2][parent][j][i] * delta[j] for j in range(3))
                 for i in range(3))


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("timelines", nargs="+", type=Path)
    p.add_argument("--top", type=int, default=40)
    p.add_argument("--max-gap", type=int, default=30)
    p.add_argument("--out", type=Path)
    a = p.parse_args()
    scores = {}
    translation_scores = {}
    for path in a.timelines:
        for key, samples in load(path).items():
            samples.sort(key=lambda x: x[0])
            pairs = [(x, y) for x, y in zip(samples, samples[1:])
                     if 0 < y[0]-x[0] <= a.max_gap and x[1] != y[1]]
            if not pairs: continue
            for child in range(18):
                for parent in range(-1, 18):
                    if parent == child: continue
                    positions = [local_position(sample, child, parent) for sample in samples]
                    spread = max(math.sqrt(sum((p[k] - positions[0][k]) ** 2 for k in range(3)))
                                 for p in positions)
                    if spread > 1e-4 and len(positions) >= 3:
                        center = tuple(statistics.mean(p[k] for p in positions) for k in range(3))
                        rms = math.sqrt(statistics.mean(sum((p[k] - center[k]) ** 2 for k in range(3))
                                                       for p in positions))
                        translation_scores.setdefault((parent, child), []).append(
                            (len(positions), rms, spread, center))
                    for group in range(14):
                        errors = []
                        bind0 = None
                        for before, after in pairs:
                            if before[3][group * 3:group * 3 + 3] == after[3][group * 3:group * 3 + 3]:
                                continue
                            p0 = ((before[2][parent] if parent >= 0 else None))
                            p1 = ((after[2][parent] if parent >= 0 else None))
                            local0 = mm(tr(p0), before[2][child]) if p0 else before[2][child]
                            local1 = mm(tr(p1), after[2][child]) if p1 else after[2][child]
                            b0 = mm(local0, tr(euler(before[3], group)))
                            b1 = mm(local1, tr(euler(after[3], group)))
                            if bind0 is None: bind0 = b0
                            errors.append(angle(bind0, b0))
                            errors.append(angle(bind0, b1))
                        if len(errors) >= 8:
                            scores.setdefault((parent, child, group), []).append((len(errors) // 2, statistics.median(errors), max(errors)))
    report = []
    for (parent, child, group), vals in scores.items():
        report.append({"parent": parent, "child": child, "group": group,
                       "tracks": len(vals), "pairs": sum(v[0] for v in vals),
                       "median_bind_drift_deg": statistics.median(v[1] for v in vals),
                       "worst_track_max_deg": max(v[2] for v in vals)})
    report.sort(key=lambda r: (r["median_bind_drift_deg"], r["worst_track_max_deg"], -r["tracks"], -r["pairs"]))
    translation_report = []
    for (parent, child), vals in translation_scores.items():
        translation_report.append({
            "parent": parent, "child": child, "tracks": len(vals),
            "samples": sum(v[0] for v in vals),
            "median_local_rms": statistics.median(v[1] for v in vals),
            "worst_track_spread": max(v[2] for v in vals),
            "median_local_offset": [statistics.median(v[3][axis] for v in vals) for axis in range(3)],
        })
    translation_report.sort(key=lambda r: (r["median_local_rms"], r["worst_track_spread"], -r["tracks"]))
    for r in report[:a.top]:
        print(f"row {r['child']:2} parent {r['parent']:2} group {r['group']:2}: "
              f"tracks={r['tracks']:2} pairs={r['pairs']:3} "
              f"median={r['median_bind_drift_deg']:.4f}deg worst={r['worst_track_max_deg']:.4f}deg")
    print("translation parent candidates (low local-offset drift):")
    for r in translation_report[:a.top]:
        print(f"row {r['child']:2} parent {r['parent']:2}: tracks={r['tracks']:2} "
              f"samples={r['samples']:3} median-rms={r['median_local_rms']:.5f} "
              f"worst-spread={r['worst_track_spread']:.5f} "
              f"offset=({r['median_local_offset'][0]:.4f},{r['median_local_offset'][1]:.4f},{r['median_local_offset'][2]:.4f})")
    if a.out:
        a.out.parent.mkdir(parents=True, exist_ok=True)
        a.out.write_text(json.dumps({"diagnostic_only": True, "fits": report,
                                     "translation_fits": translation_report}, indent=2)+"\n", encoding="utf-8")


if __name__ == "__main__": main()
