#!/usr/bin/env python3
"""Summarize Flycast REIOS GD-ROM syscall traces without losing provenance."""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re


LINE = re.compile(
    r"^gdrom fn\s+(?P<fn>\d+)(?: group (?P<group>\d+))?"
    r"(?: pc (?P<pc>[0-9a-fA-F]{8}) pr (?P<pr>[0-9a-fA-F]{8}))?"
    r" r4 (?P<r4>[0-9a-fA-F]{8}) "
    r"r5 (?P<r5>[0-9a-fA-F]{8}) -> r0 (?P<r0>[0-9a-fA-F]{8})\s+"
    r"\[status (?P<status>-?\d+) cmd (?P<cmd>\d+) "
    r"remaining (?P<remaining>\d+) total (?P<total>\d+) req (?P<req>\d+)\]"
    r"(?: (?P<extra>.*))?$"
)
EXTRA = re.compile(r"^(?P<kind>res|params) (?P<values>(?:\d+ ?|[0-9a-fA-F]{8} ?)+)$")
DRIVE = re.compile(r"^drv (?P<status>\d+) type (?P<type>\d+)$")


def parse_line(line: str, line_number: int) -> dict:
    match = LINE.fullmatch(line.rstrip("\r\n"))
    if not match:
        raise ValueError(f"line {line_number}: malformed GD-ROM trace record")
    row = match.groupdict()
    for key in ("fn", "group", "status", "cmd", "remaining", "total", "req"):
        if row[key] is not None:
            row[key] = int(row[key], 10)
    for key in ("pc", "pr", "r4", "r5", "r0"):
        if row[key] is not None:
            row[key] = int(row[key], 16)
    extra = row.pop("extra")
    if extra:
        drive_match = DRIVE.fullmatch(extra)
        if drive_match:
            row["drv"] = [int(drive_match.group("status")), int(drive_match.group("type"))]
            return row
        extra_match = EXTRA.fullmatch(extra)
        if not extra_match:
            raise ValueError(f"line {line_number}: malformed trace extension")
        kind = extra_match.group("kind")
        values = extra_match.group("values").split()
        base = 16 if kind == "params" else 10
        row[kind] = [int(value, base) for value in values]
    return row


def file_sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def summarize(path: Path, observer: Path | None = None, patch: Path | None = None) -> dict:
    digest = hashlib.sha256()
    functions, statuses, commands, groups = Counter(), Counter(), Counter(), Counter()
    request_rows: dict[str, dict] = {}
    transitions = []
    prior_state = None
    first = last = None
    line_count = 0

    with path.open("rb") as source:
        for line_count, raw in enumerate(source, 1):
            digest.update(raw)
            try:
                decoded = raw.decode("ascii")
            except UnicodeDecodeError as error:
                raise ValueError(f"line {line_count}: non-ASCII trace data") from error
            row = parse_line(decoded, line_count)
            first = first or row
            last = row
            functions[str(row["fn"])] += 1
            statuses[str(row["status"])] += 1
            commands[str(row["cmd"])] += 1
            if row.get("group") is not None:
                groups[str(row["group"])] += 1

            request_id = (f"{row['group']}:{row['req']}" if row.get("group") is not None
                          else str(row["req"]))
            aggregate = request_rows.setdefault(request_id, {
                "calls": 0, "functions": Counter(), "statuses": Counter(),
                "commands": Counter(), "total_values": set(),
                "remaining_min": row["remaining"],
                "remaining_max": row["remaining"], "first": row,
                "last": row,
            })
            aggregate["calls"] += 1
            aggregate["functions"][str(row["fn"])] += 1
            aggregate["statuses"][str(row["status"])] += 1
            aggregate["commands"][str(row["cmd"])] += 1
            aggregate["total_values"].add(row["total"])
            aggregate["remaining_min"] = min(aggregate["remaining_min"], row["remaining"])
            aggregate["remaining_max"] = max(aggregate["remaining_max"], row["remaining"])
            aggregate["last"] = row

            state = (row.get("group"), row["req"], row["status"], row["cmd"],
                     row["remaining"], row["total"])
            if state != prior_state:
                if len(transitions) >= 10000:
                    raise ValueError("trace exceeds 10,000 distinct service-state transitions")
                transitions.append({
                    "line": line_count, "group": row.get("group"),
                    "request_id": row["req"],
                    "status": row["status"], "command": row["cmd"],
                    "remaining": row["remaining"], "total": row["total"],
                })
                prior_state = state

    def sorted_counts(counter: Counter) -> dict:
        return dict(sorted(counter.items(), key=lambda item: int(item[0])))

    requests = {}
    for request_id, row in sorted(
            request_rows.items(),
            key=lambda item: tuple(int(value) for value in item[0].split(":"))):
        requests[request_id] = {
            "calls": row["calls"],
            "functions": sorted_counts(row["functions"]),
            "statuses": sorted_counts(row["statuses"]),
            "commands": sorted_counts(row["commands"]),
            "total_values": sorted(row["total_values"]),
            "remaining_min": row["remaining_min"],
            "remaining_max": row["remaining_max"],
            "first": row["first"], "last": row["last"],
        }

    report = {
        "schema": "flycast-gdrom-trace-audit-v1",
        "input": str(path), "input_sha256": digest.hexdigest(),
        "records": line_count,
        "function_counts": sorted_counts(functions),
        "group_counts": sorted_counts(groups),
        "status_counts": sorted_counts(statuses),
        "command_counts": sorted_counts(commands),
        "requests": requests,
        "state_transitions": transitions,
        "first": first, "last": last,
    }
    if observer:
        report["observer"] = str(observer)
        report["observer_sha256"] = file_sha256(observer)
    if patch:
        report["patch"] = str(patch)
        report["patch_sha256"] = file_sha256(patch)
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("trace", type=Path)
    parser.add_argument("--observer", type=Path)
    parser.add_argument("--patch", type=Path)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    report = summarize(args.trace, args.observer, args.patch)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"{report['records']} REIOS GD-ROM calls; functions {report['function_counts']}; "
          f"commands {report['command_counts']}; report {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
