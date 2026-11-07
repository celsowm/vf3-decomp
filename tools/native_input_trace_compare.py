#!/usr/bin/env python3
"""Compare selected instruction-PC counts across retained Flycast traces.

Uses ``trace_bin_sum``'s streaming VF3_TRACE reader, so large traces are read
once without loading them into memory. Counts show where executions differed;
equal counts alone do not prove that register or RAM state was equal.

Examples:
  python tools/native_input_trace_compare.py \
      extract/analysis/fight_pc_trace_long_s3_v1/instruction_trace.bin \
      --candidate neutral=extract/analysis/fight_pc_trace_long_s3_neutral_v1/instruction_trace.bin \
      --pc 0x0c0b1ac0 --pc 0x0c09d6e0 --pc 0x0c0ad1b8
  python tools/native_input_trace_compare.py baseline.bin \
      --candidate alternate=alternate.bin --physical-aliases --changes-only
"""

from __future__ import annotations

import argparse
from collections import Counter
import json
from pathlib import Path
import sys

from trace_bin_sum import stream


ROOT = Path(__file__).resolve().parents[1]
PHYSICAL_MASK = 0x1FFFFFFF


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def candidate(text: str) -> tuple[str, Path]:
    name, separator, raw_path = text.partition("=")
    if not separator or not name or not raw_path:
        raise argparse.ArgumentTypeError("candidate must use LABEL=TRACE")
    path = Path(raw_path)
    path = path.resolve() if path.is_absolute() else (ROOT / path).resolve()
    return name, path


def trace_counts(path: Path, aliases: bool) -> tuple[Counter[int], int]:
    counts: Counter[int] = Counter()
    total = 0
    normalize = (lambda pc: pc & PHYSICAL_MASK) if aliases else int
    for pc, _opcode in stream(str(path)):
        counts[normalize(pc)] += 1
        total += 1
    return counts, total


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("baseline", type=Path, help="baseline VF3_TRACE file")
    parser.add_argument("--candidate", action="append", type=candidate, required=True,
                        metavar="LABEL=TRACE", help="candidate trace; repeatable")
    parser.add_argument("--pc", type=address, action="append", default=[],
                        help="report this exact PC; repeatable")
    parser.add_argument("--physical-aliases", action="store_true",
                        help="combine P1/P2/P3 mirror addresses by their 29-bit physical PC")
    parser.add_argument("--changes-only", action="store_true",
                        help="omit PCs whose counts match every candidate")
    parser.add_argument("--max-rows", type=int, default=100,
                        help="maximum rows when --pc is omitted (default: 100)")
    parser.add_argument("--json", action="store_true",
                        help="emit machine-readable JSON")
    args = parser.parse_args(argv)
    if args.max_rows < 1:
        parser.error("--max-rows must be positive")

    baseline_path = args.baseline.resolve() if args.baseline.is_absolute() else (ROOT / args.baseline).resolve()
    candidates = args.candidate
    if not baseline_path.is_file():
        parser.error(f"baseline trace does not exist: {baseline_path}")
    for name, path in candidates:
        if not path.is_file():
            parser.error(f"candidate trace does not exist: {name}={path}")

    try:
        baseline_counts, baseline_total = trace_counts(baseline_path,
                                                        args.physical_aliases)
        candidate_data = []
        for name, path in candidates:
            counts, total = trace_counts(path, args.physical_aliases)
            candidate_data.append({"name": name, "path": path,
                                   "counts": counts, "total": total})

        requested = args.pc
        if requested:
            keys = sorted({(pc & PHYSICAL_MASK) if args.physical_aliases else pc
                           for pc in requested})
        else:
            all_keys = set(baseline_counts)
            for item in candidate_data:
                all_keys.update(item["counts"])
            changed = [key for key in all_keys if any(
                baseline_counts.get(key, 0) != item["counts"].get(key, 0)
                for item in candidate_data)]
            keys = sorted(changed if args.changes_only else all_keys,
                          key=lambda key: max(
                              [baseline_counts.get(key, 0)] +
                              [item["counts"].get(key, 0) for item in candidate_data]),
                          reverse=True)[:args.max_rows]

        rows = []
        for key in keys:
            values = [baseline_counts.get(key, 0)] + [
                item["counts"].get(key, 0) for item in candidate_data]
            changed = len(set(values)) > 1
            if args.changes_only and not changed:
                continue
            rows.append({"pc": key, "baseline": values[0],
                         "candidates": values[1:], "delta": [
                             value - values[0] for value in values[1:]]})

        if args.json:
            print(json.dumps({
                "diagnostic_only": True,
                "warning": "PC count equality does not establish equal machine state",
                "physical_aliases": args.physical_aliases,
                "traces": [{"name": "baseline", "path": str(baseline_path),
                            "instructions": baseline_total,
                            "distinct_pcs": len(baseline_counts)}] + [
                    {"name": item["name"], "path": str(item["path"]),
                     "instructions": item["total"],
                     "distinct_pcs": len(item["counts"])}
                    for item in candidate_data],
                "rows": [{"pc": f"0x{row['pc']:08x}",
                          "baseline": row["baseline"],
                          "candidates": row["candidates"],
                          "delta": row["delta"]} for row in rows],
            }, indent=2))
            return 0

        mode = "physical aliases merged" if args.physical_aliases else "raw PCs"
        print(f"Baseline {baseline_path.name}: {baseline_total} instructions, "
              f"{len(baseline_counts)} PCs ({mode})")
        for item in candidate_data:
            print(f"Candidate {item['name']} {item['path'].name}: "
                  f"{item['total']} instructions, {len(item['counts'])} PCs")
        headings = ["PC", "baseline"] + [item["name"] for item in candidate_data]
        print("\n" + " ".join(f"{heading:>14}" for heading in headings) + "       delta")
        for row in rows:
            counts_text = [row["baseline"], *row["candidates"]]
            count_columns = " ".join(f"{value:14d}" for value in counts_text)
            deltas = ", ".join(f"{item['name']} {delta:+d}"
                                for item, delta in zip(candidate_data, row["delta"]))
            print(f"0x{row['pc']:08x} {count_columns}       {deltas}")
        if not rows:
            print("No differing PC counts in the selected scope.")
        return 0
    except (OSError, ValueError) as exc:
        print(f"native_input_trace_compare: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
