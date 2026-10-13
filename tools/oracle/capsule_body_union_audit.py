#!/usr/bin/env python3
"""Audit per-owner body-PC unions and distinct complete capsule inputs."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path

from capsules import records

ROOT = Path(__file__).resolve().parents[2]
BODY_RANGES = ROOT / "extract/analysis/function_body_ranges.csv"


def canonical(address: int) -> int:
    return address & 0x1FFFFFFF


def load_ranges(entry: int) -> list[tuple[int, int]]:
    result = []
    with BODY_RANGES.open(newline="", encoding="utf-8-sig") as stream:
        for row in csv.DictReader(stream):
            if canonical(int(row["entry"], 16)) == canonical(entry):
                result.append((canonical(int(row["start"], 16)),
                               canonical(int(row["end"], 16))))
    if not result:
        raise ValueError(f"no frozen body ranges for {entry:#010x}")
    return result


def body_pc(pc: int, ranges: list[tuple[int, int]]) -> bool:
    pc = canonical(pc)
    return any(start <= pc < end for start, end in ranges)


def fingerprint(record: dict) -> str:
    digest = hashlib.sha256(record["before"])
    for base, before, _after in sorted(record["pages"], key=lambda page: page[0]):
        digest.update(base.to_bytes(4, "little"))
        digest.update(before)
    return digest.hexdigest()


def audit(paths: list[Path], entry: int, ranges: list[tuple[int, int]],
          included_entries: set[int]) -> dict:
    flags: dict[str, int] = {}
    records_seen = valid = 0
    fingerprints: set[str] = set()
    pcs: set[int] = set()
    for path in paths:
        if not path.is_file():
            raise FileNotFoundError(path)
        for record in records(path):
            if canonical(record["entry"]) not in included_entries:
                continue
            records_seen += 1
            flag = int(record["flags"])
            flags[str(flag)] = flags.get(str(flag), 0) + 1
            if flag:
                continue
            valid += 1
            fingerprints.add(fingerprint(record))
            pcs.update(canonical(pc) for pc, _opcode in record["ops"]
                       if body_pc(pc, ranges))
    return {
        "capsules": [str(path) for path in paths],
        "included_entries": [f"0x{value:08x}" for value in sorted(included_entries)],
        "started_records": records_seen,
        "complete_valid_records": valid,
        "rejected_flags": flags,
        "distinct_complete_inputs": len(fingerprints),
        "unique_body_pcs": len(pcs),
        "executed_body_bytes": len(pcs) * 2,
        "body_pcs": [f"0x{pc:08x}" for pc in sorted(pcs)],
        "body_ranges": [[f"0x{a:08x}", f"0x{z:08x}"] for a, z in ranges],
        "coverage_credit": False,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--entry", required=True, type=lambda value: int(value, 0))
    parser.add_argument("--capsule", action="append", required=True, type=Path)
    parser.add_argument("--baseline-capsule", action="append", default=[], type=Path)
    parser.add_argument("--include-entry", action="append", default=[],
                        type=lambda value: int(value, 0),
                        help="also union PCs from a parent invocation that contains the owner")
    parser.add_argument("--out", type=Path)
    args = parser.parse_args()
    ranges = load_ranges(args.entry)
    included_entries = {canonical(args.entry), *(canonical(value) for value in args.include_entry)}
    current = audit(args.capsule, args.entry, ranges, included_entries)
    report = {"schema": "vf3-capsule-body-union-audit-v1",
              "entry": f"0x{canonical(args.entry):08x}",
              "diagnostic_only": True,
              "current": current}
    if args.baseline_capsule:
        baseline = audit(args.baseline_capsule, args.entry, ranges, included_entries)
        report["baseline"] = baseline
        current_pcs = set(current["body_pcs"])
        baseline_pcs = set(baseline["body_pcs"])
        report["marginal_executed_body_bytes"] = len(current_pcs - baseline_pcs) * 2
        report["new_body_pcs"] = sorted(current_pcs - baseline_pcs)
    rendered = json.dumps(report, indent=2) + "\n"
    if args.out:
        args.out.write_text(rendered, encoding="utf-8")
    print(rendered, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
