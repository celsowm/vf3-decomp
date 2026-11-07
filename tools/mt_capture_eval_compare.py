#!/usr/bin/env python3
"""Inspect native MT evaluation and the captured pose-field conversion.

The selected game routine samples the 63 MT channels at ``0x8c09d670`` and
then runs ``0x8c09f432`` over that output before the watched call returns. This
tool compares the native evaluator's raw 63 values with the capture's final
``actor+0x1d04`` block. Differences are expected where the wrapper transforms
channels; the count of unchanged channels is diagnostic only, not a pass/fail
gate. ``--pose-fields`` additionally compares the 42 floats at
``actor+0x1d58`` with their low-halfword FTRC results at ``actor+0x1f50``.
It also compares the native evaluator's packed suffix with the captured
halfwords. These comparisons are diagnostic; they do not assign semantic
names to channels or map that float span back to the MT evaluator output.

The native dump accepts Q8 phases (one unit is 1/256 frame), including the
exact fractional phase retained in a capture.

Example:
  python tools/mt_capture_eval_compare.py extract/analysis/fifth_leaf_dev_v6_cases \
      --entry 0x8c09f036 --case 1 --asset MTAKIJAC.BIN \
      --vfa build/vf3_assets.vfa --dump build/vf3mtmotiondump.exe --pose-fields

If a sparse capture omits actor+0x3c or the frame fields, pass the values
independently verified for that exact specimen with --motion-id and --frame.
"""

from __future__ import annotations

import argparse
import math
from pathlib import Path
import struct
import subprocess
import sys

ADDRESS_MASK = 0x1FFFFFFF
CHANNELS = 63
Q8 = 0x100


def number(text: str) -> int:
    try:
        return int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc


def register(text: str) -> int:
    value = text.lower()
    if not value.startswith("r") or not value[1:].isdigit():
        raise argparse.ArgumentTypeError("expected a GPR name such as r4")
    index = int(value[1:])
    if not 0 <= index < 16:
        raise argparse.ArgumentTypeError("GPR index must be in 0..15")
    return index


def case_data(directory: Path, entry: int, case_number: int):
    if case_number < 1:
        raise ValueError("case number must be one-based and positive")
    lines = (directory / f"f_{entry:08x}.cases").read_text().splitlines()
    if case_number > len(lines):
        raise ValueError(f"case {case_number} is outside the {len(lines)} cases in the corpus")
    fields = lines[case_number - 1].split()
    if len(fields) < 78:
        raise ValueError(f"case {case_number} is truncated")
    before_count = int(fields[75])
    after_index = 76 + 2 * before_count
    if len(fields) < after_index + 2:
        raise ValueError("case has a truncated output-window table")
    after_count = int(fields[after_index + 1])
    if len(fields) < after_index + 2 + 2 * after_count:
        raise ValueError("case has a truncated output-window map")
    before_windows = [(int(fields[76 + 2 * i], 16), int(fields[77 + 2 * i], 16))
                      for i in range(before_count)]
    after_windows = [(int(fields[after_index + 2 + 2 * i], 16),
                      int(fields[after_index + 3 + 2 * i], 16))
                     for i in range(after_count)]
    if before_windows != after_windows:
        raise ValueError("input/output RAM window maps differ")
    before = (directory / fields[74]).read_bytes()
    after = (directory / fields[after_index]).read_bytes()
    expected_size = sum(size for base, size in before_windows)
    if len(before) != expected_size or len(after) != expected_size:
        raise ValueError("RAM shadows do not match the window map")
    return fields, before, after, before_windows


def read_ram(blob: bytes, windows: list[tuple[int, int]], address: int,
             size: int) -> bytes:
    physical = address & ADDRESS_MASK
    file_offset = 0
    for base, length in windows:
        if base <= physical and size <= base + length - physical:
            start = file_offset + physical - base
            return blob[start:start + size]
        file_offset += length
    raise ValueError(f"address {address:#010x} ({size} bytes) is outside captured RAM windows")


def read_u16(blob: bytes, windows: list[tuple[int, int]], address: int) -> int:
    return struct.unpack("<H", read_ram(blob, windows, address, 2))[0]


def compare_pose_fields(blob: bytes, windows: list[tuple[int, int]], actor: int) -> None:
    """Compare the captured FTRC input span and low-halfword output fields."""
    source = struct.unpack(
        "<42f", read_ram(blob, windows, actor + 0x1D58, 42 * 4))
    stored = struct.unpack(
        "<42H", read_ram(blob, windows, actor + 0x1F50, 42 * 2))
    checked = 0
    mismatches: list[tuple[int, float, int, int]] = []
    invalid: list[tuple[int, float]] = []
    for index, (value, actual) in enumerate(zip(source, stored)):
        if not math.isfinite(value) or value < -2147483648.0 or value >= 2147483648.0:
            invalid.append((index, value))
            continue
        expected = math.trunc(value) & 0xFFFF
        checked += 1
        if actual != expected:
            mismatches.append((index, value, expected, actual))
    print(f"pose FTRC fields: {checked - len(mismatches)}/{checked} matched; "
          f"{len(invalid)} source values outside signed-32-bit FTRC range")
    for index, value, expected, actual in mismatches:
        print(f"  field{index:02d}: source={value:.9g} "
              f"expected=0x{expected:04x} captured=0x{actual:04x}")
    for index, value in invalid:
        print(f"  field{index:02d}: source={value!r}; FTRC result not compared")


def compare_native_pose_fields(native: list[int], blob: bytes,
                               windows: list[tuple[int, int]], actor: int) -> None:
    captured = struct.unpack(
        "<42H", read_ram(blob, windows, actor + 0x1F50, 42 * 2))
    matches = [((value & 0xFFFF) == actual)
               for value, actual in zip(native, captured)]
    print(f"native packed fields vs capture: {sum(matches)}/42 matched")
    for index, (value, actual, matched) in enumerate(zip(native, captured, matches)):
        if not matched:
            print(f"  field{index:02d}: native=0x{value & 0xFFFF:04x} "
                  f"capture=0x{actual:04x}")


def compute_phase(actor: int, blob: bytes, windows: list[tuple[int, int]]) -> tuple[int, int]:
    high = read_u16(blob, windows, actor + 0x3E)
    low = read_u16(blob, windows, actor + 0x40)
    cycle = read_u16(blob, windows, actor + 0x1A00)
    phase = struct.unpack("<i", struct.pack("<I", ((high << 16) | low) & 0xFFFFFFFF))[0] >> 8
    phase = max(Q8, min(phase, cycle * Q8))
    return phase, cycle


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("corpus", type=Path, help="corpus directory")
    parser.add_argument("--entry", required=True, type=number, help="entry PC")
    parser.add_argument("--case", required=True, type=int, help="one-based case number")
    parser.add_argument("--actor-register", default="r4", type=register,
                        help="GPR holding the actor pointer (default: r4)")
    parser.add_argument("--motion-id", type=number,
                        help="explicit motion ID if actor+0x3c is uncaptured")
    parser.add_argument("--frame", type=int,
                        help="explicit whole frame if actor phase fields are uncaptured")
    parser.add_argument("--phase-q8", type=number,
                        help="explicit phase in 1/256-frame units; overrides captured phase")
    parser.add_argument("--asset", required=True, help="MT*.BIN asset name in the VFA")
    parser.add_argument("--vfa", required=True, type=Path, help="VFA asset archive")
    parser.add_argument("--dump", type=Path, default=Path("build/vf3mtmotiondump.exe"),
                        help="native MT evaluator executable")
    parser.add_argument("--abs-tolerance", type=float, default=1e-4)
    parser.add_argument("--rel-tolerance", type=float, default=1e-4)
    parser.add_argument("--pose-fields", action="store_true",
                        help="also compare actor+0x1D58 FTRC inputs with actor+0x1F50 halfwords")
    args = parser.parse_args(argv)
    if args.frame is not None and args.phase_q8 is not None:
        parser.error("--frame and --phase-q8 cannot be used together")
    try:
        fields, before, after, windows = case_data(args.corpus, args.entry, args.case)
        actor = int(fields[args.actor_register], 16)
        motion_id = (args.motion_id if args.motion_id is not None else
                     read_u16(before, windows, actor + 0x3C))
        if args.phase_q8 is not None:
            if args.phase_q8 < 0 or args.phase_q8 > 0x7FFFFFFF:
                raise ValueError("phase-q8 must fit a nonnegative signed 32-bit value")
            cycle = read_u16(before, windows, actor + 0x1A00)
            phase = args.phase_q8
            phase_source = "explicit"
        elif args.frame is None:
            phase, cycle = compute_phase(actor, before, windows)
            phase_source = "captured"
        else:
            if args.frame < 0:
                raise ValueError("frame must be nonnegative")
            cycle = read_u16(before, windows, actor + 0x1A00)
            phase = args.frame * Q8
            phase_source = "explicit"
        if phase > 0x7FFFFFFF:
            raise ValueError("phase must fit a nonnegative signed 32-bit value")
        if args.motion_id is not None and args.motion_id <= 0:
            raise ValueError("motion ID must be positive")
        actual_raw = read_ram(after, windows, actor + 0x1D04, CHANNELS * 4)
        actual = struct.unpack(f"<{CHANNELS}f", actual_raw)

        command = [str(args.dump), str(args.vfa), args.asset, hex(motion_id),
                   str(cycle), str(phase // Q8), "1", "--phase-q8", str(phase)]
        if args.pose_fields:
            command.append("--pose-fields")
        result = subprocess.run(command, check=False, capture_output=True, text=True)
        if result.returncode != 0:
            raise ValueError("native MT dump failed: " + result.stderr.strip())
        lines = [line for line in result.stdout.splitlines() if line.startswith("frame=")]
        if len(lines) != 1:
            raise ValueError("native MT dump did not return exactly one frame")
        columns = lines[0].split()
        if len(columns) < CHANNELS + 2 or not columns[1].startswith("phase_q8="):
            raise ValueError("native MT dump returned an invalid phase/channel row")
        reported_phase = int(columns[1].split("=", 1)[1], 10)
        if reported_phase != phase:
            raise ValueError(f"native MT dump used phase {reported_phase}, expected {phase}")
        native = [float(value) for value in columns[2:2 + CHANNELS]]
        if len(native) != CHANNELS:
            raise ValueError(f"native MT dump returned {len(native)} channels, expected {CHANNELS}")

        matches = []
        for index, (expected, observed) in enumerate(zip(native, actual)):
            tolerance = args.abs_tolerance + args.rel_tolerance * max(abs(expected), abs(observed))
            matches.append(abs(expected - observed) <= tolerance)
        motion_source = "explicit" if args.motion_id is not None else "captured"
        print(f"entry=0x{args.entry:08x} case={args.case} actor={actor:#010x} "
              f"asset={args.asset} motion=0x{motion_id:x} motion_source={motion_source} "
              f"cycle={cycle} phase={phase:#x} phase_source={phase_source}")
        print(f"channels within tolerance: {sum(matches)}/{CHANNELS} "
              f"(abs={args.abs_tolerance:g}, rel={args.rel_tolerance:g})")
        for index, (expected, observed, equal) in enumerate(zip(native, actual, matches)):
            if not equal:
                print(f"  ch{index:02d}: native={expected:.9g} capture={observed:.9g} "
                      f"delta={observed - expected:.9g}")
        if args.pose_fields:
            marker = columns.index("pose_fields=") if "pose_fields=" in columns else -1
            if marker < 0 or len(columns) < marker + 1 + 42:
                raise ValueError("native MT dump omitted packed pose fields")
            native_fields = [int(value) & 0xFFFF
                             for value in columns[marker + 1:marker + 1 + 42]]
            compare_native_pose_fields(native_fields, after, windows, actor)
            compare_pose_fields(after, windows, actor)
        # The captured block is downstream of the game's channel postprocessor;
        # inequality is an observation, not evidence that native MT decoding failed.
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"mt_capture_eval_compare: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
