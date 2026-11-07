#!/usr/bin/env python3
"""Compare per-PC instruction counts from two Flycast execution traces.

Both trace layouts supported by ``trace_bin_sum.py`` are accepted. This is a
frequency comparison, not an instruction-by-instruction alignment: use it to
screen for paths that appear or run at a different rate between captures.

Usage:
    python tools/trace_bin_diff.py baseline.bin replay.bin [--top 40]
"""

from __future__ import annotations

import argparse
from collections import Counter
from pathlib import Path

from trace_bin_sum import layout, stream


def pc_counts(path: Path) -> tuple[str, int, Counter[int]]:
    record_layout = layout(path)
    counts: Counter[int] = Counter()
    total = 0
    for pc, _opcode in stream(path):
        counts[pc] += 1
        total += 1
    return record_layout, total, counts


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("baseline", type=Path,
                        help="reference trace to compare against")
    parser.add_argument("replay", type=Path,
                        help="trace from the changed input or state")
    parser.add_argument("--top", type=int, default=40,
                        help="number of largest PC count changes to print")
    parser.add_argument("--min-delta", type=int, default=1,
                        help="hide PCs with a smaller absolute count delta")
    args = parser.parse_args(argv)
    if args.top <= 0 or args.min_delta <= 0:
        parser.error("--top and --min-delta must be positive")
    if not args.baseline.is_file():
        parser.error(f"baseline trace does not exist: {args.baseline}")
    if not args.replay.is_file():
        parser.error(f"replay trace does not exist: {args.replay}")

    try:
        base_layout, base_total, base = pc_counts(args.baseline)
        replay_layout, replay_total, replay = pc_counts(args.replay)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))

    print(f"baseline instructions: {base_total} ({base_layout})")
    print(f"replay instructions:   {replay_total} ({replay_layout})")
    print(f"distinct PCs: baseline {len(base)}, replay {len(replay)}")
    changed = [
        (abs(replay.get(pc, 0) - base.get(pc, 0)), pc,
         base.get(pc, 0), replay.get(pc, 0))
        for pc in base.keys() | replay.keys()
        if abs(replay.get(pc, 0) - base.get(pc, 0)) >= args.min_delta
    ]
    changed.sort(key=lambda row: (-row[0], row[1]))
    print(f"{'PC':>12} {'baseline':>12} {'replay':>12} {'delta':>12}")
    for _magnitude, pc, base_count, replay_count in changed[:args.top]:
        print(f"{pc:>12x} {base_count:>12d} {replay_count:>12d} "
              f"{replay_count - base_count:>+12d}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
