#!/usr/bin/env python3
"""Capture motion-update IDs after isolated Dreamcast input pulses.

Each input mask is run from the same retained Flycast state in its own
golden_batch corpus. The guest records the current motion at 0x0C0AD1B8; the
tool prints those samples beside the exact one-pulse schedule. Results are
state- and timing-specific evidence, not action labels or a runtime clip map.
Use --base-play to capture an unmodified schedule and inject each pulse into
that same context. Context mode compares ordered actor/motion/return-PC samples;
it does not turn those samples into frame-timed action labels.

Example:
  python tools/oracle/native_motion_input_sweep.py \
      --state tools/emu/flycast-build/data/vf3_29.state \
      --emulator tools/emu/flycast-build/flycast_v3.exe \
      --out extract/analysis/native_motion_single_input_s29_v1 \
      --input 0 --input 1 --input 2 --input 4 --input 8 --input 0x10 \
      --input 0x20 --input 0x40 --input 0x80 --frames 120
"""

from __future__ import annotations

import argparse
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
MOTION_CASE_PC = 0x8C0AD1B8
WATCH_FILE = ROOT / "tools" / "oracle" / "native_motion_action_watch.txt"
REPORTER = ROOT / "tools" / "motion_probe_report.py"
GOLDEN_BATCH = ROOT / "tools" / "golden_batch.py"


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFF:
        raise argparse.ArgumentTypeError("input mask must fit in 16 bits")
    return value


def in_repo(path: Path, label: str) -> tuple[Path, str]:
    resolved = path.resolve()
    try:
        relative = resolved.relative_to(ROOT)
    except ValueError as exc:
        raise ValueError(f"{label} must be inside the repository: {path}") from exc
    return resolved, relative.as_posix()


def parse_play_schedule(text: str) -> list[tuple[int, str, str]]:
    event_re = re.compile(r"^\s*(\d+)\s+(KEYF|EXITF)\b(?:\s+(\S+))?\s*$", re.I)
    events = []
    for line_number, line in enumerate(text.splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        match = event_re.match(line)
        if not match:
            raise ValueError(f"play schedule line {line_number} is not KEYF/EXITF: {line!r}")
        frame, command, value = match.groups()
        command = command.upper()
        value = value or ""
        if command == "KEYF":
            try:
                input_mask = int(value, 0)
            except ValueError as exc:
                raise ValueError(f"play schedule line {line_number} has invalid KEYF mask") from exc
            if not 0 <= input_mask <= 0xFFFF:
                raise ValueError(f"play schedule line {line_number} KEYF mask exceeds 16 bits")
            value = f"0x{input_mask:x}"
        elif value:
            raise ValueError(f"play schedule line {line_number} EXITF takes no value")
        events.append((int(frame), command, value))
    if not events or not any(command == "KEYF" for _, command, _ in events):
        raise ValueError("base play schedule must contain at least one KEYF event")
    return events


def contextual_schedule(base_events: list[tuple[int, str, str]],
                        press_frame: int, release_frame: int,
                        mask: int) -> str:
    """Insert one pulse while preserving the baseline input timeline around it."""
    key_events = [(frame, int(value, 0)) for frame, command, value in base_events
                  if command == "KEYF"]
    baseline_at_press = 0
    baseline_during_pulse = []
    for frame, value in key_events:
        if frame <= press_frame:
            baseline_at_press = value
        elif frame < release_frame:
            baseline_during_pulse.append(value)
    if all(value == mask for value in [baseline_at_press, *baseline_during_pulse]):
        raise ValueError("the injected mask matches the base input for the whole pulse")

    active_mask = 0
    for frame, value in key_events:
        if frame > release_frame:
            break
        active_mask = value

    # Lower priority values are written first at shared frame numbers. The
    # injected input therefore wins at press and reasserts over any base event
    # that falls inside the pulse; EXITF remains last on its frame.
    rows: list[tuple[int, int, str]] = []
    for frame, command, value in base_events:
        rows.append((frame, 2 if command == "EXITF" else 0,
                     f"{frame} {command}" + (f" {value}" if value else "")))
        if command == "KEYF" and press_frame < frame < release_frame:
            rows.append((frame, 1, f"{frame} KEYF 0x{mask:x}"))
    rows.append((press_frame, 1, f"{press_frame} KEYF 0x{mask:x}"))
    if not any(frame == release_frame and command == "KEYF"
               for frame, command, _ in base_events):
        rows.append((release_frame, 1, f"{release_frame} KEYF 0x{active_mask:x}"))
    rows.sort(key=lambda row: (row[0], row[1]))
    return "\n".join(row[2] for row in rows) + "\n"


def motion_rows(cases: Path) -> list[tuple[int, int, int]]:
    if not cases.is_file():
        return []
    rows = []
    for line_number, line in enumerate(cases.read_text(encoding="ascii").splitlines(), 1):
        fields = line.split()
        if not fields:
            continue
        if len(fields) < 74:
            raise ValueError(f"{cases}:{line_number}: expected 74 register words")
        words = [int(value, 16) for value in fields[:74]]
        rows.append((words[4], words[5] & 0x1FFF, words[16]))
    return rows


def format_motion_rows(rows: list[tuple[int, int, int]]) -> str:
    if not rows:
        return "(no watched calls)"
    return ", ".join(f"actor=0x{actor:08x} motion=0x{motion:03x} PR=0x{pr:08x}"
                      for actor, motion, pr in rows)


def first_sequence_difference(left: list[tuple[int, int, int]],
                              right: list[tuple[int, int, int]]) -> str:
    for index, (a, b) in enumerate(zip(left, right)):
        if a != b:
            return f"first difference at sample {index}: baseline {a!r}, replay {b!r}"
    if len(left) != len(right):
        return f"common prefix {min(len(left), len(right))}; sample counts {len(left)} vs {len(right)}"
    return "motion-update sample sequence matches baseline"


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--state", type=Path, required=True,
                        help="retained vf3_<number>.state to replay from each time")
    parser.add_argument("--emulator", type=Path, required=True,
                        help="instrumented Flycast oracle executable")
    parser.add_argument("--base-play", type=Path,
                        help="optional control script; inject each pulse into this shared context")
    parser.add_argument("--out", type=Path, required=True,
                        help="new output directory; existing paths are refused")
    parser.add_argument("--input", type=number, action="append", required=True,
                        help="16-bit KEYF input mask; repeat to sweep masks")
    parser.add_argument("--frames", type=int, default=120,
                        help="frames per replay (default 120)")
    parser.add_argument("--press-frame", type=int, default=5,
                        help="frame at which the mask is pressed (default 5)")
    parser.add_argument("--release-frame", type=int, default=8,
                        help="frame at which input returns to neutral (default 8)")
    parser.add_argument("--max-samples", type=int, default=64,
                        help="maximum motion-update specimens per replay")
    parser.add_argument("--timeout", type=int, default=900,
                        help="maximum seconds per replay")
    args = parser.parse_args(argv)

    if args.frames <= 0 or args.max_samples <= 0:
        parser.error("--frames and --max-samples must be positive")
    if not 0 <= args.press_frame < args.release_frame < args.frames:
        parser.error("require 0 <= --press-frame < --release-frame < --frames")
    if args.timeout < 0:
        parser.error("--timeout cannot be negative")
    if len(set(args.input)) != len(args.input):
        parser.error("--input masks must be unique")
    if not WATCH_FILE.is_file():
        parser.error(f"motion watch file is missing: {WATCH_FILE}")

    try:
        state, state_rel = in_repo(args.state, "state")
        emulator, emulator_rel = in_repo(args.emulator, "emulator")
        out, out_rel = in_repo(args.out, "output directory")
        base_play = None
        base_play_rel = None
        base_events = None
        if args.base_play is not None:
            base_play, base_play_rel = in_repo(args.base_play, "base play schedule")
            if not base_play.is_file():
                raise ValueError(f"base play schedule does not exist: {base_play}")
            base_events = parse_play_schedule(base_play.read_text(encoding="utf-8"))
            if any(frame >= args.frames for frame, _command, _value in base_events):
                raise ValueError("base play schedule contains an event outside --frames")
            exit_frames = [frame for frame, command, _value in base_events
                           if command == "EXITF"]
            if len(exit_frames) != 1:
                raise ValueError("base play schedule must contain exactly one EXITF")
            if args.release_frame >= exit_frames[0]:
                raise ValueError("the pulse must be released before the base EXITF")
            for mask in args.input:
                contextual_schedule(base_events, args.press_frame,
                                    args.release_frame, mask)
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
    except (OSError, ValueError) as exc:
        print(f"native_motion_input_sweep: {exc}", file=sys.stderr)
        return 1

    reports: list[str] = []
    baseline_rows: list[tuple[int, int, int]] | None = None
    run_prefix = re.sub(r"[^A-Za-z0-9_]+", "_", out.name).strip("_")
    if base_events is not None and base_play is not None:
        baseline_label = "baseline"
        baseline_path = out / f"{baseline_label}.txt"
        baseline_capture = out / baseline_label
        baseline_path.write_text(base_play.read_text(encoding="utf-8"), encoding="utf-8")
        baseline_rel = baseline_path.relative_to(ROOT).as_posix()
        capture_rel = baseline_capture.relative_to(ROOT).as_posix()
        run_name = f"s{state_number}_{run_prefix}_{baseline_label}"
        command = [
            sys.executable, str(GOLDEN_BATCH),
            "--name", run_name,
            "--watch", WATCH_FILE.relative_to(ROOT).as_posix(),
            "--out", capture_rel,
            "--capsule",
            "--max-samples", str(args.max_samples),
            "--emulator", emulator_rel,
            "--timeout", str(args.timeout),
            "--run", f"{run_name}:{state_rel}:{baseline_rel}:{args.frames}",
        ]
        print(f"native_motion_input_sweep: baseline={capture_rel}", flush=True)
        result = subprocess.run(command, cwd=ROOT, check=False)
        if result.returncode != 0:
            print(f"native_motion_input_sweep: golden_batch failed for baseline "
                  f"with exit {result.returncode}", file=sys.stderr)
            return result.returncode
        baseline_cases = baseline_capture / f"f_{MOTION_CASE_PC:08x}.cases"
        try:
            baseline_rows = motion_rows(baseline_cases)
        except (OSError, ValueError) as exc:
            print(f"native_motion_input_sweep: cannot read baseline capture: {exc}",
                  file=sys.stderr)
            return 1
        if baseline_cases.is_file():
            report = subprocess.run(
                [sys.executable, str(REPORTER), str(baseline_cases), "--show-pr"],
                cwd=ROOT, text=True, capture_output=True, check=False,
            )
            if report.returncode != 0:
                print(report.stderr.strip() or report.stdout.strip(), file=sys.stderr)
                return report.returncode
            reports.append("## baseline (unmodified context)\n" +
                           report.stdout.strip() + "\n")
        else:
            reports.append("## baseline (unmodified context)\n"
                           "No motion-update call at 0x0C0AD1B8 was observed.\n")
        print(f"baseline sequence: {format_motion_rows(baseline_rows)}", flush=True)

    for mask in args.input:
        label = f"input_{mask:04x}"
        play_path = out / f"{label}.txt"
        capture_path = out / label
        if base_events is None:
            play_text = (f"0 KEYF 0\n{args.press_frame} KEYF 0x{mask:x}\n"
                         f"{args.release_frame} KEYF 0\n{args.frames - 1} EXITF\n")
        else:
            play_text = contextual_schedule(base_events, args.press_frame,
                                            args.release_frame, mask)
        play_path.write_text(play_text, encoding="utf-8")
        play_rel = play_path.relative_to(ROOT).as_posix()
        capture_rel = capture_path.relative_to(ROOT).as_posix()
        run_name = f"s{state_number}_{run_prefix}_{label}"
        command = [
            sys.executable, str(GOLDEN_BATCH),
            "--name", run_name,
            "--watch", WATCH_FILE.relative_to(ROOT).as_posix(),
            "--out", capture_rel,
            "--capsule",
            "--max-samples", str(args.max_samples),
            "--emulator", emulator_rel,
            "--timeout", str(args.timeout),
            "--run", f"{run_name}:{state_rel}:{play_rel}:{args.frames}",
        ]
        print(f"native_motion_input_sweep: mask=0x{mask:04x}; "
              f"press {args.press_frame}..{args.release_frame - 1}; "
              f"capture={capture_rel}", flush=True)
        result = subprocess.run(command, cwd=ROOT, check=False)
        if result.returncode != 0:
            print(f"native_motion_input_sweep: golden_batch failed for {label} "
                  f"with exit {result.returncode}", file=sys.stderr)
            return result.returncode
        cases = capture_path / f"f_{MOTION_CASE_PC:08x}.cases"
        if not cases.is_file():
            message = (f"## {label} (KEYF 0x{mask:04x})\n"
                       "No motion-update call at 0x0C0AD1B8 was observed in this replay.\n")
            reports.append(message)
            print("native_motion_input_sweep: no watched motion-update call", flush=True)
            continue
        try:
            rows = motion_rows(cases)
        except (OSError, ValueError) as exc:
            print(f"native_motion_input_sweep: cannot read {label} capture: {exc}",
                  file=sys.stderr)
            return 1
        report = subprocess.run(
            [sys.executable, str(REPORTER), str(cases), "--show-pr"],
            cwd=ROOT, text=True, capture_output=True, check=False,
        )
        if report.returncode != 0:
            message = report.stderr.strip() or report.stdout.strip()
            print(f"native_motion_input_sweep: report failed for {label}: {message}",
                  file=sys.stderr)
            return report.returncode
        reports.append(f"## {label} (KEYF 0x{mask:04x})\n{report.stdout.strip()}\n")
        if baseline_rows is not None:
            comparison = first_sequence_difference(baseline_rows, rows)
            reports.append(f"Compared with baseline: {comparison}.\n")
            print(f"comparison: {comparison}", flush=True)
        print(report.stdout, end="", flush=True)

    summary = out / "motion_input_summary.md"
    summary.write_text(
        "# Motion input sweep\n\n"
        f"State: `{state_rel}`. Each input mask was pulsed at frame "
        f"{args.press_frame} and released at frame {args.release_frame}.\n\n"
        + (f"Base schedule: `{base_play_rel}`. Each pulse was inserted into that "
           "schedule, and captured actor/motion/PR sequences were compared with "
           "an unmodified baseline replay.\n\n" if base_play_rel else "")
        + "These samples retain input order within each replay but have no frame "
        "timestamps. The results do not assign action names or prove a general "
        "action-to-motion table.\n\n" + "\n".join(reports),
        encoding="utf-8",
    )
    print(f"wrote {summary.relative_to(ROOT).as_posix()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
