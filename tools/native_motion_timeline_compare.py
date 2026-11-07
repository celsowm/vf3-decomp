#!/usr/bin/env python3
"""Compare two native motion timeline reports at matching frames and actors.

The comparison separates input-mask differences from actor-state differences.
It is useful for checking whether a replay with neutralized controls follows
the same motion IDs and record pointers as its input-driven counterpart. It
does not infer action names or prove that a differing input caused a change.

Example:
  python tools/native_motion_timeline_compare.py \
      extract/analysis/native_motion_timeline_s29_v1/motion_timeline.json \
      extract/analysis/native_motion_timeline_s29_neutral_v1/motion_timeline.json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"
STATE_FIELDS = ("motion_id", "cycle", "descriptor_pointer", "record_pointer",
                "byte_0x60", "byte_0x61")


def read_report(path: Path) -> dict[str, object]:
    try:
        report = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        raise ValueError(f"cannot read timeline report {path}: {exc}") from exc
    if not isinstance(report, dict) or report.get("diagnostic_only") is not True:
        raise ValueError(f"{path}: not a diagnostic native motion timeline report")
    rows = report.get("rows")
    if not isinstance(rows, list) or not rows:
        raise ValueError(f"{path}: report has no rows")
    return report


def keyed_rows(report: dict[str, object], label: str) -> dict[tuple[int, str], dict[str, object]]:
    raw_rows = report["rows"]
    assert isinstance(raw_rows, list)
    result: dict[tuple[int, str], dict[str, object]] = {}
    for index, row in enumerate(raw_rows):
        if not isinstance(row, dict):
            raise ValueError(f"{label}: row {index} is not an object")
        try:
            key = (int(row["frame"]), str(row["actor"]))
            for field in (*STATE_FIELDS, "input_mask"):
                if field not in row:
                    raise KeyError(field)
        except (KeyError, TypeError, ValueError) as exc:
            raise ValueError(f"{label}: row {index} is missing a valid frame, actor, or field") from exc
        if key in result:
            raise ValueError(f"{label}: duplicate frame/actor row {key}")
        result[key] = row
    return result


def compare(base: dict[str, object], candidate: dict[str, object],
            intervention_frame: int | None = None) -> dict[str, object]:
    base_rows = keyed_rows(base, "baseline")
    candidate_rows = keyed_rows(candidate, "candidate")
    keys = sorted(set(base_rows) | set(candidate_rows))
    rows = []
    for frame, actor in keys:
        left = base_rows.get((frame, actor))
        right = candidate_rows.get((frame, actor))
        if left is None or right is None:
            rows.append({
                "frame": frame,
                "actor": actor,
                "status": "missing_candidate" if right is None else "missing_baseline",
                "changed_state_fields": [],
            })
            continue
        changed = [field for field in STATE_FIELDS if left[field] != right[field]]
        rows.append({
            "frame": frame,
            "actor": actor,
            "status": "changed" if changed else "same",
            "baseline_input_mask": left["input_mask"],
            "candidate_input_mask": right["input_mask"],
            "baseline_motion_id": left["motion_id"],
            "candidate_motion_id": right["motion_id"],
            "baseline_cycle": left["cycle"],
            "candidate_cycle": right["cycle"],
            "changed_state_fields": changed,
        })
    pre_intervention_mismatches = (
        sum(row["frame"] < intervention_frame and row["status"] != "same"
            for row in rows)
        if intervention_frame is not None else None
    )
    post_intervention_mismatches = (
        sum(row["frame"] >= intervention_frame and row["status"] != "same"
            for row in rows)
        if intervention_frame is not None else None
    )
    return {
        "diagnostic_only": True,
        "baseline": base.get("state"),
        "candidate": candidate.get("state"),
        "baseline_play": base.get("play"),
        "candidate_play": candidate.get("play"),
        "matched_rows": sum(row["status"] != "missing_candidate" and
                             row["status"] != "missing_baseline" for row in rows),
        "changed_rows": sum(row["status"] == "changed" for row in rows),
        "same_rows": sum(row["status"] == "same" for row in rows),
        "intervention_frame": intervention_frame,
        "pre_intervention_mismatches": pre_intervention_mismatches,
        "post_intervention_mismatches": post_intervention_mismatches,
        "pre_intervention_match": (pre_intervention_mismatches == 0
                                    if intervention_frame is not None else None),
        "rows": rows,
        "limitations": [
            "Matching sampled states do not prove the input was ignored between checkpoints.",
            "No pre-intervention mismatch only establishes agreement at sampled frames.",
            "A changed state does not identify the action or establish direct causality.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("baseline", type=Path, help="baseline motion_timeline.json")
    parser.add_argument("candidate", type=Path, help="candidate motion_timeline.json")
    parser.add_argument("--intervention-frame", type=int,
                        help="flag any actor-state mismatch sampled before this frame")
    parser.add_argument("--out", type=Path,
                        help="write a new JSON comparison inside extract/analysis")
    args = parser.parse_args(argv)
    baseline_path = args.baseline.resolve()
    candidate_path = args.candidate.resolve()
    try:
        baseline = read_report(baseline_path)
        candidate = read_report(candidate_path)
        if args.intervention_frame is not None and args.intervention_frame < 0:
            parser.error("--intervention-frame cannot be negative")
        report = compare(baseline, candidate, args.intervention_frame)
    except ValueError as exc:
        print(f"native_motion_timeline_compare: {exc}", file=sys.stderr)
        return 1

    if args.out:
        out = args.out.resolve() if args.out.is_absolute() else (ROOT / args.out).resolve()
        try:
            out.relative_to(ANALYSIS.resolve())
        except ValueError:
            parser.error("--out must be inside extract/analysis")
        if out.exists():
            parser.error(f"refusing to replace existing report: {out}")
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    print("frame  actor       status  baseline->candidate motion  state fields changed")
    for row in report["rows"]:
        if row["status"].startswith("missing_"):
            print(f"{row['frame']:5}  {row['actor']}  {row['status']}")
            continue
        print(f"{row['frame']:5}  {row['actor']}  {row['status']:7} "
              f"{row['baseline_motion_id']}->{row['candidate_motion_id']} "
              f"{row['changed_state_fields']}")
    print(f"native_motion_timeline_compare: {report['same_rows']} same, "
          f"{report['changed_rows']} changed, {report['matched_rows']} matched samples")
    if args.intervention_frame is not None:
        print(f"pre-intervention mismatches before frame {args.intervention_frame}: "
              f"{report['pre_intervention_mismatches']}")
        if report["pre_intervention_mismatches"]:
            print("warning: the replays already diverged before the intervention; "
                  "later differences cannot be attributed to it alone")
    if args.out:
        print(f"report: {args.out.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
