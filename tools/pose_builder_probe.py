#!/usr/bin/env python3
"""Capture controlled calls to the original 23-row bone-pose builder.

This offline diagnostic generates a VF3_ENTRY_PATCH at a naturally reached
trigger, routes it to 0x8C091438, and asks the oracle to roll the target call
back before continuing the original run. By default it opens the builder's
draw gate. The resulting matrices are evidence only: a saved state may lack
the initialized matrix-stack state needed for usable basis vectors.

Example:
  python tools/pose_builder_probe.py \
      --state tools/emu/flycast-build/data/vf3_26.state \
      --actor 0x0c1fefe4 --actor 0x0c20138c \
      --out extract/analysis/native_pose_builder_probe_s26_v2 \
      --emulator tools/emu/flycast-build/flycast_v3.exe --frames 120
"""

from __future__ import annotations

import argparse
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
POSE_ENTRY = 0x8C091438
DEFAULT_TRIGGER = 0x8C0434D0
FLAGS_CELL = 0x0C2A0978
DRAW_CELL = 0x0C29B864
DRAW_MASK = 0x00040000


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def in_repo(path: Path, label: str) -> tuple[Path, str]:
    resolved = path.resolve()
    try:
        relative = resolved.relative_to(ROOT)
    except ValueError as exc:
        raise ValueError(f"{label} must be inside the repository: {path}") from exc
    return resolved, relative.as_posix()


def build_patch(trigger: int, actors: list[int], force_draw: bool) -> str:
    lines = [
        "# Diagnostic pose-builder calls; the oracle rolls each target call back.",
        f"entry 0x{trigger:08x} 0x{POSE_ENTRY:08x}",
    ]
    for index, actor in enumerate(actors):
        if index:
            lines.append(f"seed 0x{trigger:08x}")
        lines.extend((
            f"target 0x{trigger:08x} 0x{POSE_ENTRY:08x}",
            f"reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0xFFFFFFFF:08x}",
            f"reg 0x{trigger:08x} r4 0x{actor:08x}",
        ))
        if force_draw:
            lines.extend((
                f"ram 0x{trigger:08x} 0x{FLAGS_CELL:08x} 0x00000000",
                f"ram 0x{trigger:08x} 0x{DRAW_CELL:08x} 0x{DRAW_MASK:08x}",
            ))
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--state", type=Path, required=True,
                        help="retained Flycast savestate inside the repository")
    parser.add_argument("--actor", type=address, action="append", required=True,
                        help="actor record address; repeat to probe several actors")
    parser.add_argument("--out", type=Path, required=True,
                        help="new output directory; existing paths are refused")
    parser.add_argument("--emulator", type=Path, required=True,
                        help="instrumented Flycast oracle executable")
    parser.add_argument("--trigger", type=address, default=DEFAULT_TRIGGER,
                        help=f"reached guest PC to substitute (default {DEFAULT_TRIGGER:#010x})")
    parser.add_argument("--frames", type=int, default=120,
                        help="frames to run from the state (default: 120)")
    parser.add_argument("--max-samples", type=int, default=8,
                        help="maximum specimens to record (default: 8)")
    parser.add_argument("--probe-ops", type=int, default=100000,
                        help="instruction budget for each synthetic call")
    parser.add_argument("--timeout", type=int, default=900,
                        help="maximum seconds for the oracle run")
    parser.add_argument("--keep-draw-gate", action="store_true",
                        help="do not seed the draw and flags cells")
    args = parser.parse_args(argv)

    if args.frames <= 0 or args.max_samples <= 0 or args.probe_ops <= 0:
        parser.error("--frames, --max-samples, and --probe-ops must be positive")
    if args.timeout < 0:
        parser.error("--timeout cannot be negative")
    if not 0x8C000000 <= args.trigger <= 0x8CFFFFFF:
        parser.error("--trigger must be in the 0x8C image mirror")
    if any(not 0x0C000000 <= actor <= 0x0CFFFFFF for actor in args.actor):
        parser.error("--actor values must be in main RAM (0x0Cxxxxxx)")
    if len(set(args.actor)) != len(args.actor):
        parser.error("--actor values must be unique")

    try:
        state, state_rel = in_repo(args.state, "state")
        emulator, emulator_rel = in_repo(args.emulator, "emulator")
        out, out_rel = in_repo(args.out, "output directory")
        if not state.is_file():
            raise ValueError(f"state does not exist: {state}")
        if not emulator.is_file():
            raise ValueError(f"emulator does not exist: {emulator}")
        if out.exists():
            raise ValueError(f"refusing to replace existing output directory: {out}")
        match = re.search(r"vf3_(\d+)\.state$", state.name, re.IGNORECASE)
        if not match:
            raise ValueError("state filename must end in vf3_<number>.state")
        state_number = match.group(1)
        out.mkdir(parents=True)
        watch = out / "watch.txt"
        patch = out / "entry.patch"
        watch.write_text(f"pc 0x{POSE_ENTRY:08x}\npc 0x{POSE_ENTRY & 0x1FFFFFFF:08x}\n",
                         encoding="utf-8")
        patch.write_text(build_patch(args.trigger, args.actor,
                                     not args.keep_draw_gate),
                         encoding="utf-8")
    except (OSError, ValueError) as exc:
        print(f"pose_builder_probe: {exc}", file=sys.stderr)
        return 1

    command = [
        sys.executable, "tools/golden_batch.py",
        "--name", out.name,
        "--watch", (out / "watch.txt").relative_to(ROOT).as_posix(),
        "--out", out_rel,
        "--entry-patch", (out / "entry.patch").relative_to(ROOT).as_posix(),
        "--capsule", "--probe-debug", "--probe-only",
        "--max-samples", str(args.max_samples),
        "--probe-ops", str(args.probe_ops),
        "--emulator", emulator_rel,
        "--timeout", str(args.timeout),
        "--run", f"s{state_number}:{state_rel}::{args.frames}",
    ]
    print("pose_builder_probe: " + " ".join(command), flush=True)
    result = subprocess.run(command, cwd=ROOT, check=False)
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
