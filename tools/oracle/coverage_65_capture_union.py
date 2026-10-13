"""Combine diagnostic original-capture PC coverage without granting credit.

This measures whether separate, complete original runs cover the same frozen
body in each matching savestate. It deliberately does not qualify distinct
inputs across reports, caller provenance, C behavior, or coverage credit.
"""
import argparse
import hashlib
import json
from pathlib import Path


def load_report(path: Path) -> dict:
    report = json.loads(path.read_text(encoding="utf-8"))
    if report.get("coverage_credit") is not False:
        raise ValueError(f"{path}: expected a diagnostic-only capture report")
    if report.get("original_image_checked") is not True:
        raise ValueError(f"{path}: original image was not checked")
    for run in report.get("runs", []):
        if (run.get("complete_accounting") is not True or
                run.get("frame_complete") is not True or
                run.get("returncode") != 0 or run.get("unaccounted") != 0 or
                run.get("incomplete")):
            raise ValueError(f"{path}: incomplete or failed run {run.get('name')}")
    if not report.get("runs") or not report.get("scenarios"):
        raise ValueError(f"{path}: missing run or scenario evidence")
    return report


def combine(paths: list[Path], entry: str, owner: str) -> dict:
    reports = [(path, load_report(path)) for path in paths]
    body_sizes = set()
    by_state: dict[str, list[dict]] = {}
    for path, report in reports:
        if owner in report.get("nondeterministic_entries", []):
            raise ValueError(f"{path}: owner {owner} is quarantined as nondeterministic")
        for scenario in report["scenarios"]:
            item = scenario.get("entries", {}).get(entry)
            if item is None:
                continue
            if item.get("owner", "").lower() != owner.lower():
                raise ValueError(f"{path}: {entry} maps to unexpected owner {item.get('owner')}")
            body_sizes.add(item.get("body_bytes"))
            by_state.setdefault(scenario["state_sha256"], []).append({
                "report": str(path),
                "valid_records": item.get("valid_records"),
                "distinct_inputs_in_report": item.get("distinct_inputs"),
                "covered_body_bytes_in_report": item.get("covered_body_bytes"),
                "missing_body_bytes_in_report": item.get("missing_body_bytes"),
                "missing_pcs": set(item.get("missing_pcs", [])),
            })
    if len(body_sizes) != 1 or not by_state:
        raise ValueError("reports do not identify one consistent owner body")
    body_bytes = body_sizes.pop()
    states = []
    for state_hash, captures in sorted(by_state.items()):
        missing = set.intersection(*(capture["missing_pcs"] for capture in captures))
        # SH-4 instructions are 2 bytes. Each report's owner size and missing
        # PC accounting are checked against this relation before unioning.
        for capture in captures:
            expected = body_bytes - 2 * len(capture["missing_pcs"])
            if expected < 0 or expected != capture["covered_body_bytes_in_report"]:
                raise ValueError(f"{capture['report']}: body-byte/PC accounting mismatch")
        covered_bytes = body_bytes - 2 * len(missing)
        states.append({
            "state_sha256": state_hash,
            "capture_reports": [{k: v for k, v in capture.items() if k != "missing_pcs"}
                                 for capture in captures],
            "pc_union_covered_bytes": covered_bytes,
            "pc_union_missing_bytes": 2 * len(missing),
            "pc_union_missing_pcs": sorted(missing),
        })
    return {
        "diagnostic_only": True,
        "coverage_credit": False,
        "entry": entry,
        "owner": owner,
        "owner_bytes": body_bytes,
        "states": states,
        "limitations": [
            "PC coverage union only; no qualification or coverage credit.",
            "Distinct-input counts are reported per source and are not deduplicated across reports.",
            "Caller provenance and compiled C behavior require separate gates.",
        ],
        "sources": [
            {"path": str(path), "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
            for path, _ in reports
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--entry", required=True, help="true entry address, for example 0x8c09b36c")
    parser.add_argument("--owner", required=True, help="frozen owner address")
    parser.add_argument("--report", type=Path, action="append", required=True,
                        help="diagnostic capture report; repeat to combine campaigns")
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists():
        parser.error(f"refusing to overwrite {args.out}")
    result = combine(args.report, args.entry.lower(), args.owner.lower())
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    for state in result["states"]:
        print(f"{state['state_sha256'][:8]}: {state['pc_union_covered_bytes']}/"
              f"{result['owner_bytes']} owner bytes across {len(state['capture_reports'])} reports")
    print("Diagnostic PC union only; coverage_credit=false")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
