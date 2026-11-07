#!/usr/bin/env python3
"""Compare live-to-POL selector candidates across retained pose reports.

Input files are JSON reports from ``flycast_pol_asset_search.py``. This tool
keeps geometric and vertex-attribute evidence separate, then reports package,
slot, and mesh candidates that recur across every supplied capture. A stable
source-mesh candidate still says nothing about its attachment transform.

Example:
  python tools/selector_asset_audit.py \
    extract/analysis/native_aki_parts_s47_v1.json \
    extract/analysis/native_aki_parts_s48_v1.json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys
from typing import Any


CandidateKey = tuple[str, int, int]


def candidate_key(candidate: dict[str, Any]) -> CandidateKey:
    return (str(candidate["package"]).upper(), int(candidate["slot"]),
            int(candidate["mesh"]))


def load_report(path: Path) -> dict[str, Any]:
    value = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(value, dict) or not isinstance(value.get("entries"), list):
        raise ValueError(f"{path}: not a flycast POL asset-search report")
    return value


def report_nodes(report: dict[str, Any]) -> dict[tuple[int, int], dict[str, Any]]:
    result: dict[tuple[int, int], dict[str, Any]] = {}
    for entry in report["entries"]:
        if not isinstance(entry, dict) or entry.get("status") != "resolved":
            continue
        entry_index = int(entry["entry"])
        for node in entry.get("nodes", []):
            result[(entry_index, int(node["index"]))] = {
                "selector": int(entry["selector"]),
                "vertex_count": int(node.get("vertex_count", 0)),
                "position": node.get("exact_position_matches", []),
                "attributes": node.get("exact_attribute_matches", []),
            }
    return result


def evidence(node: dict[str, Any]) -> dict[CandidateKey, set[str]]:
    result: dict[CandidateKey, set[str]] = {}
    for basis, field in (("position", "position"), ("attributes", "attributes")):
        matches = node.get(field, [])
        if not isinstance(matches, list):
            continue
        for candidate in matches:
            if isinstance(candidate, dict):
                result.setdefault(candidate_key(candidate), set()).add(basis)
    return result


def format_key(key: CandidateKey) -> str:
    package, slot, mesh = key
    return f"{package} slot {slot} mesh {mesh}"


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("reports", nargs="+", type=Path,
                        help="one or more flycast_pol_asset_search JSON reports")
    parser.add_argument("--stable-only", action="store_true",
                        help="show only candidates present in every report")
    parser.add_argument("--json", action="store_true",
                        help="emit machine-readable comparison data")
    args = parser.parse_args(argv)

    try:
        reports = [(path, load_report(path)) for path in args.reports]
        actors = {int(report["actor"]) for _, report in reports}
        if len(actors) != 1:
            raise ValueError("reports refer to different actor addresses")
        node_maps = [(path, report_nodes(report)) for path, report in reports]
        all_nodes = sorted(set().union(*(set(rows) for _, rows in node_maps)))
        rows: list[dict[str, Any]] = []
        for entry, node_index in all_nodes:
            per_report = []
            for path, nodes in node_maps:
                node = nodes.get((entry, node_index))
                per_report.append({
                    "report": str(path),
                    "selector": node["selector"] if node else None,
                    "vertex_count": node["vertex_count"] if node else None,
                    "candidates": evidence(node) if node else {},
                })
            observed = [item["candidates"] for item in per_report]
            stable = set.intersection(*(set(item) for item in observed)) if observed else set()
            if args.stable_only and not stable:
                continue
            keys = sorted(set().union(*(set(item) for item in observed)),
                          key=lambda key: (key[0], key[1], key[2]))
            candidates = []
            for key in keys:
                per_capture = [sorted(item.get(key, set())) for item in observed]
                candidates.append({
                    "package": key[0], "slot": key[1], "mesh": key[2],
                    "stable_across_reports": key in stable,
                    "evidence_by_report": per_capture,
                })
            rows.append({
                "entry": entry,
                "selector": per_report[0]["selector"],
                "node": node_index,
                "live_vertices_by_report": [item["vertex_count"] for item in per_report],
                "candidates": candidates,
            })

        result = {
            "diagnostic_only": True,
            "actor": next(iter(actors)),
            "reports": [str(path) for path, _ in reports],
            "nodes": rows,
            "limitation": "Recurring source-mesh evidence does not identify attachment transforms.",
        }
    except (OSError, KeyError, TypeError, ValueError, json.JSONDecodeError) as exc:
        print(f"selector_asset_audit: {exc}", file=sys.stderr)
        return 1

    if args.json:
        print(json.dumps(result, indent=2))
        return 0

    print(f"actor=0x{result['actor']:08x}; captures={len(reports)}")
    for row in rows:
        if not row["candidates"]:
            continue
        selector = row["selector"]
        print(f"entry {row['entry']:2d} selector=0x{selector:04x} node {row['node']:2d} "
              f"vertices={row['live_vertices_by_report']}: ", end="")
        rendered = []
        for candidate in row["candidates"]:
            if args.stable_only and not candidate["stable_across_reports"]:
                continue
            capture_tags = "/".join("+".join(tags) or "-"
                                     for tags in candidate["evidence_by_report"])
            stable = "stable " if candidate["stable_across_reports"] else ""
            rendered.append(f"{stable}{format_key((candidate['package'], candidate['slot'], candidate['mesh']))} "
                            f"[{capture_tags}]")
        if rendered:
            print("; ".join(rendered))
        else:
            print("no candidate recurs across every capture")
    print(result["limitation"])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
