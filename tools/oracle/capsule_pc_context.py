#!/usr/bin/env python3
"""Show instruction windows around a PC in raw VF3CAP invocation records."""
from __future__ import annotations

import argparse
import json
from pathlib import Path

from capsules import records


def contexts(ops: list[tuple[int, int]], target: int, radius: int = 8) -> list[dict]:
    if radius < 0:
        raise ValueError("radius must be nonnegative")
    physical = target & 0x1FFFFFFF
    matches = []
    for index, (pc, opcode) in enumerate(ops):
        if (pc & 0x1FFFFFFF) != physical:
            continue
        start, end = max(0, index - radius), min(len(ops), index + radius + 1)
        matches.append({
            "index": index, "pc": f"0x{pc:08x}",
            "opcode": f"0x{opcode:04x}",
            "window": [{"pc": f"0x{address:08x}", "opcode": f"0x{word:04x}"}
                       for address, word in ops[start:end]],
        })
    return matches


def inspect(paths: list[Path], target: int, radius: int) -> dict:
    rows = []
    for path in paths:
        for record in records(path):
            found = contexts(record["ops"], target, radius)
            rows.append({
                "source": str(path), "invocation": record["id"],
                "entry": f"0x{record['entry']:08x}",
                "exit": f"0x{record['exitpc']:08x}",
                "flags": record["flags"],
                "instruction_count": len(record["ops"]),
                "matches": found,
            })
    return {
        "schema": "vf3cap-pc-context-v1", "diagnostic_only": True,
        "coverage_credit": False, "target": f"0x{target:08x}",
        "physical_target": f"0x{target & 0x1FFFFFFF:08x}",
        "radius": radius, "invocations": len(rows),
        "matching_invocations": sum(bool(row["matches"]) for row in rows),
        "rows": rows,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capsules", nargs="+", type=Path)
    parser.add_argument("--pc", required=True, type=lambda value: int(value, 0))
    parser.add_argument("--radius", type=int, default=8)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    report = inspect(args.capsules, args.pc, args.radius)
    args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"{report['matching_invocations']}/{report['invocations']} invocations contain "
          f"{report['target']}; diagnostic only; wrote {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
