#!/usr/bin/env python3
"""Find compact slot/bone index tables in untagged POL payloads.

This diagnostic scans untagged POL spans for aligned u8/u16/u32 runs whose
values fit a caller-selected index range (plus common sentinels). It reports
candidate runs only; a low-valued sequence is not proof that it maps model
slots to pose matrices.

Examples:
  python tools/pol_index_map_scan.py extract/gamedata/MKAO_AKI.POL extract/gamedata/MKAO_JAC.POL
  python tools/pol_index_map_scan.py extract/gamedata/MKAO_JAC.POL --max-index 22 --length 23 --length 31 --json-out extract/analysis/jac_pol_index_candidates.json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
import sys

from pol_model_inventory import tagged_spans
from pol_slot_inspect import inspect as inspect_slots


WIDTHS = (1, 2, 4)
DEFAULT_SENTINELS = (0xFF, 0xFFFF, 0xFFFFFFFF)


def integer(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if value < 0 or value > 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in an unsigned 32-bit word")
    return value


def scan_run(data: bytes, start: int, end: int, width: int,
             max_index: int, sentinels: set[int], min_run: int,
             min_unique: int) -> list[dict[str, object]]:
    """Return aligned maximal low-index runs in one untagged span."""
    fmt = {1: "<B", 2: "<H", 4: "<I"}[width]
    candidates: list[dict[str, object]] = []
    for alignment in range(width):
        cursor = start + alignment
        run_start: int | None = None
        values: list[int] = []
        unique: set[int] = set()

        def finish() -> None:
            nonlocal run_start, values, unique
            if (run_start is not None and len(values) >= min_run and
                    len(unique) >= min_unique):
                candidates.append({
                    "offset": run_start,
                    "width": width,
                    "alignment": alignment,
                    "scalar_count": len(values),
                    "unique_indices": len(unique),
                    "minimum_lengths_met": [],
                    "values": values[:128],
                    "values_truncated": len(values) > 128,
                })
            run_start = None
            values = []
            unique = set()

        while cursor + width <= end:
            value = struct.unpack_from(fmt, data, cursor)[0]
            if value <= max_index or value in sentinels:
                if run_start is None:
                    run_start = cursor
                values.append(value)
                if value <= max_index:
                    unique.add(value)
            else:
                finish()
            cursor += width
        finish()
    return candidates


def inspect_pol(path: Path, max_index: int, min_unique: int,
                requested_lengths: list[int], sentinels: set[int]
                ) -> dict[str, object]:
    data = path.read_bytes()
    _texture_count, tagged_ends, tagged_aliases = tagged_spans(data)
    tagged_count = sum(len(slots) for slots in tagged_aliases.values())
    slot_count = struct.unpack_from("<H", data, 0x0C)[0]
    lengths = sorted(set(requested_lengths or [23, tagged_count, slot_count]))
    lengths = [length for length in lengths if length > 0]
    if not lengths:
        raise ValueError("no positive candidate table lengths are available")

    spans = inspect_slots(data, tagged=False, word_count=0)
    candidates: list[dict[str, object]] = []
    for span in spans:
        start = int(span["start"])
        end = int(span["end"])
        aliases = [int(slot) for slot in span["untagged_slots"]]
        for width in WIDTHS:
            for run in scan_run(data, start, end, width, max_index,
                                sentinels, min(lengths), min_unique):
                run["minimum_lengths_met"] = [length for length in lengths
                                               if length <= int(run["scalar_count"])]
                if not run["minimum_lengths_met"]:
                    continue
                run["span_start"] = start
                run["span_end"] = end
                run["slot_aliases"] = aliases
                candidates.append(run)

    candidates.sort(key=lambda row: (
        -len(row["minimum_lengths_met"]),
        -int(row["unique_indices"]),
        -int(row["scalar_count"]),
        int(row["offset"]),
        int(row["width"]),
    ))
    return {
        "file": str(path),
        "file_size": len(data),
        "slot_count": slot_count,
        "tagged_model_slots": tagged_count,
        "tagged_model_spans": len(tagged_ends),
        "candidate_lengths": lengths,
        "max_index": max_index,
        "min_unique_indices": min_unique,
        "diagnostic_only": True,
        "candidates": candidates,
        "limitations": [
            "Only aligned little-endian u8/u16/u32 runs are scanned.",
            "An in-range integer run may be unrelated metadata or geometry.",
            "A candidate does not establish a model-slot-to-matrix mapping.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", nargs="+", type=Path,
                        help="one or more extracted POL packages")
    parser.add_argument("--max-index", type=integer, default=22,
                        help="largest valid index (default: 22 for 23 pose rows)")
    parser.add_argument("--length", type=int, action="append", default=[],
                        help="candidate map length; repeatable (default: 23, tagged count, slot count)")
    parser.add_argument("--sentinel", type=integer, action="append",
                        help="additional allowed sentinel value; repeatable")
    parser.add_argument("--min-unique", type=int, default=8,
                        help="minimum distinct in-range values (default: 8)")
    parser.add_argument("--json", action="store_true",
                        help="print full JSON candidate data")
    parser.add_argument("--json-out", type=Path,
                        help="write full JSON to a new file; refuses overwrite")
    args = parser.parse_args(argv)

    if args.max_index > 0xFFFF:
        parser.error("--max-index must be at most 65535")
    if args.min_unique < 1:
        parser.error("--min-unique must be positive")
    if args.length and any(length <= 0 for length in args.length):
        parser.error("--length values must be positive")
    if args.json and args.json_out:
        parser.error("choose --json or --json-out")

    sentinels = set(DEFAULT_SENTINELS)
    if args.sentinel:
        sentinels.update(args.sentinel)

    try:
        reports = [inspect_pol(path, args.max_index, args.min_unique,
                               args.length, sentinels)
                   for path in args.pol]
        output = {"diagnostic_only": True, "reports": reports}
        if args.json:
            print(json.dumps(output, indent=2))
        elif args.json_out:
            if args.json_out.exists():
                raise FileExistsError(f"refusing to replace {args.json_out}")
            args.json_out.parent.mkdir(parents=True, exist_ok=True)
            with args.json_out.open("x", encoding="utf-8") as handle:
                json.dump(output, handle, indent=2)
                handle.write("\n")
            print(f"wrote {args.json_out}")
        else:
            for report in reports:
                print(f"{Path(str(report['file'])).name}: "
                      f"{report['slot_count']} slots, "
                      f"{report['tagged_model_slots']} tagged model slots, "
                      f"candidate lengths={report['candidate_lengths']}")
                if not report["candidates"]:
                    print("  no qualifying compact index runs in untagged spans")
                    continue
                for row in report["candidates"]:
                    values = row["values"]
                    rendered = ",".join(f"{value:x}" for value in values[:32])
                    if row["values_truncated"]:
                        rendered += ",..."
                    print(f"  file+0x{row['offset']:x} u{row['width'] * 8} "
                          f"count={row['scalar_count']} unique={row['unique_indices']} "
                          f"minimum_lengths_met={row['minimum_lengths_met']} "
                          f"slots={row['slot_aliases']} values=[{rendered}]")
                print("  candidates are unassigned integer runs, not rig evidence")
    except (OSError, ValueError, struct.error) as exc:
        print(f"pol_index_map_scan: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
