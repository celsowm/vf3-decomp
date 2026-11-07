#!/usr/bin/env python3
"""Replay a fight input schedule and sample actor motion fields by frame.

The tool inserts isolated Flycast savestate checkpoints into a KEYF timeline,
replays from a retained state, then reads each actor's motion ID, Q8 phase,
cycle, and record pointers from the checkpoint RAM. It keeps the input mask active at
each checkpoint beside those fields. The report is diagnostic evidence; it
does not assign action names or prove that an input caused a transition.
Use ``--neutral-input`` with the same source schedule to produce a control
replay with every KEYF mask cleared for comparison. ``--include-pose`` also
retains the raw 63-channel block, packed pose fields, and actor matrix rows at
each checkpoint for offline channel-to-pose analysis.

Example:
  python tools/native_motion_timeline_probe.py \
      --state tools/emu/flycast-build/data/vf3_29.state \
      --play tools/vf3_play_motion_strikes.txt \
      --image extract/exe/1ST_READ.unsc.bin \
      --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 150 \
      --out extract/analysis/native_motion_timeline_s29_v1
  python tools/native_motion_timeline_probe.py \
      --state tools/emu/flycast-build/data/vf3_29.state \
      --frames 300 --pulse 30:45:0x4 \
      --image extract/exe/1ST_READ.unsc.bin \
      --actor 0x0c1fefe4 --checkpoint 30 \
      --out extract/analysis/native_motion_timeline_pulse_v1
"""

from __future__ import annotations

import argparse
import csv
import json
import math
from pathlib import Path
import struct
import subprocess
import sys

from aica_state import load_state
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"
CAPTURE = ROOT / "tools" / "flycast_capture.py"
DEFAULT_EMULATOR = ROOT / "tools" / "emu" / "flycast-build" / "flycast_v3.exe"
DEFAULT_ROM = ROOT / "rom" / "vf3.gdi"
JOINT_ADVANCE_ADDRESS = 0x0C119670
JOINT_RECORD_BASE = 0x180
JOINT_RECORD_BYTES = 64
JOINT_RECORD_COUNT = 23


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def pulse(text: str) -> tuple[int, int, int]:
    try:
        start_text, end_text, mask_text = text.split(":", 2)
        start, end, mask = int(start_text, 0), int(end_text, 0), int(mask_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            "expected START:END:MASK, for example 570:600:0x2") from exc
    if start < 1 or end <= start or not 0 <= mask <= 0xFFFF:
        raise argparse.ArgumentTypeError("pulse range or 16-bit mask is invalid")
    return start, end, mask


def frame_range(text: str) -> tuple[int, int, int]:
    try:
        start_text, end_text, step_text = text.split(":", 2)
        start, end, step = int(start_text, 0), int(end_text, 0), int(step_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            "expected START:END:STEP, for example 840:930:5") from exc
    if start < 1 or end <= start or step <= 0:
        raise argparse.ArgumentTypeError("sample range bounds or step are invalid")
    return start, end, step


def repo_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def parse_schedule(text: str) -> tuple[list[tuple[int, str, int | None]], int]:
    events: list[tuple[int, str, int | None]] = []
    exits: list[int] = []
    for line_number, source in enumerate(text.splitlines(), 1):
        line = source.split("#", 1)[0].strip()
        if not line:
            continue
        parts = line.split()
        try:
            frame = int(parts[0], 0)
        except (ValueError, IndexError) as exc:
            raise ValueError(f"line {line_number}: invalid frame-clock command") from exc
        if frame < 0 or len(parts) not in (2, 3):
            raise ValueError(f"line {line_number}: malformed frame-clock command")
        command = parts[1].upper()
        if command == "KEYF" and len(parts) == 3:
            try:
                mask = int(parts[2], 0)
            except ValueError as exc:
                raise ValueError(f"line {line_number}: invalid KEYF mask") from exc
            if not 0 <= mask <= 0xFFFF:
                raise ValueError(f"line {line_number}: KEYF mask must fit in 16 bits")
            events.append((frame, command, mask))
        elif command == "EXITF" and len(parts) == 2:
            exits.append(frame)
            events.append((frame, command, None))
        else:
            raise ValueError(f"line {line_number}: expected KEYF or EXITF")
    if len(exits) != 1:
        raise ValueError("input schedule must contain exactly one EXITF")
    exit_frame = exits[0]
    if any(frame >= exit_frame for frame, command, _mask in events
           if command != "EXITF"):
        raise ValueError("KEYF events must occur before EXITF")
    return events, exit_frame


def checkpoint_schedule(events: list[tuple[int, str, int | None]],
                        exit_frame: int, interval: int,
                        sample_frames: list[int]) -> tuple[str, list[tuple[int, int, int]]]:
    """Return a schedule with SAVEF after same-frame input updates."""
    checkpoints: list[tuple[int, int, int]] = []
    active_mask = 0
    event_frames = sorted({frame for frame, _command, _mask in events})
    keys_by_frame: dict[int, list[int]] = {}
    for frame, command, mask in events:
        if command == "KEYF":
            assert mask is not None
            keys_by_frame.setdefault(frame, []).append(mask)

    checkpoint_frames = sorted(set(range(interval, exit_frame, interval)) |
                               set(sample_frames))
    slot = 0
    for frame in checkpoint_frames:
        while event_frames and event_frames[0] <= frame:
            event_frame = event_frames.pop(0)
            if event_frame > frame:
                break
            if event_frame in keys_by_frame:
                active_mask = keys_by_frame[event_frame][-1]
        slot += 1
        checkpoints.append((slot, frame, active_mask))

    by_frame: dict[int, list[tuple[int, str, int | None]]] = {}
    for event in events:
        by_frame.setdefault(event[0], []).append(event)
    for checkpoint_slot, frame, _mask in checkpoints:
        by_frame.setdefault(frame, []).append((frame, "SAVEF", checkpoint_slot))

    rows = ["# Generated by tools/native_motion_timeline_probe.py"]
    for frame in sorted(by_frame):
        frame_events = by_frame[frame]
        frame_events.sort(key=lambda event: 1 if event[1] == "EXITF" else
                          2 if event[1] == "SAVEF" else 0)
        for _event_frame, command, value in frame_events:
            if command == "KEYF":
                rows.append(f"{frame} KEYF 0x{value:x}")
            elif command == "SAVEF":
                rows.append(f"{frame} SAVEF {value}")
            else:
                rows.append(f"{frame} EXITF")
    return "\n".join(rows) + "\n", checkpoints


def read_u16(ram: bytes, address: int) -> int:
    return struct.unpack("<H", read_ram(ram, address, 2))[0]


def read_u32(ram: bytes, address: int) -> int:
    return struct.unpack("<I", read_ram(ram, address, 4))[0]


def read_floats(ram: bytes, address: int,
                count: int) -> list[float | dict[str, str]]:
    raw = read_ram(ram, address, count * 4)
    values = struct.unpack(f"<{count}f", raw)
    bits = struct.unpack(f"<{count}I", raw)
    result: list[float | dict[str, str]] = []
    for value, word in zip(values, bits):
        if math.isfinite(value):
            result.append(value)
        else:
            category = "nan" if math.isnan(value) else ("+inf" if value > 0 else "-inf")
            result.append({"non_finite": category, "bits": f"0x{word:08x}"})
    return result


def read_u16s(ram: bytes, address: int, count: int) -> list[int]:
    raw = read_ram(ram, address, count * 2)
    return list(struct.unpack(f"<{count}H", raw))


def matrix_rows(ram: bytes, address: int,
                count: int) -> list[list[float | dict[str, str]]]:
    values = read_floats(ram, address, count * 16)
    return [values[index * 16:(index + 1) * 16] for index in range(count)]


def joint_records(ram: bytes, actor: int,
                  advances: bytes) -> list[dict[str, object]]:
    """Read 64-byte prefixes in the builder's variable-stride joint order."""
    if len(advances) != JOINT_RECORD_COUNT:
        raise ValueError(f"expected {JOINT_RECORD_COUNT} joint advance bytes")
    records = []
    cursor = 0
    for index, advance in enumerate(advances):
        raw = read_ram(ram, actor + JOINT_RECORD_BASE + cursor,
                       JOINT_RECORD_BYTES)
        records.append({
            "index": index,
            "actor_offset": JOINT_RECORD_BASE + cursor,
            "advance": advance,
            "raw": raw.hex(),
        })
        cursor += advance
    return records


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--state", required=True, type=Path,
                        help="retained vf3_<number>.state")
    parser.add_argument("--play", type=Path,
                        help="KEYF/EXITF frame-clock input schedule")
    parser.add_argument("--frames", type=int,
                        help="generate a neutral schedule for this many frames")
    parser.add_argument("--image", required=True, type=Path,
                        help="exact game image loaded into main RAM")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help=f"image load address (default {DEFAULT_IMAGE_ADDRESS:#x})")
    parser.add_argument("--emulator", type=Path, default=DEFAULT_EMULATOR,
                        help="instrumented local Flycast build")
    parser.add_argument("--rom", type=Path, default=DEFAULT_ROM,
                        help="GDI descriptor used to launch the isolated emulator")
    parser.add_argument("--actor", type=number, action="append", required=True,
                        help="fighter actor address; repeat for each fighter")
    parser.add_argument("--checkpoint", type=int, default=150,
                        help="save a RAM sample every N frames (default 150)")
    parser.add_argument("--neutral-input", action="store_true",
                        help="replace every KEYF mask with zero for a control replay")
    parser.add_argument("--pulse", type=pulse, action="append", default=[],
                        help="apply START:END:MASK; with --play also pass --neutral-input")
    parser.add_argument("--sample-frame", type=int, action="append", default=[],
                        help="add a specific frame checkpoint; repeatable")
    parser.add_argument("--sample-range", type=frame_range, action="append", default=[],
                        metavar="START:END:STEP",
                        help="add checkpoints in a half-open frame range; repeatable")
    parser.add_argument("--include-pose", action="store_true",
                        help="also save raw MT channels, pose fields, and actor matrices")
    parser.add_argument("--include-joints", action="store_true",
                        help="also save 23 variable-stride joint-record prefixes")
    parser.add_argument("--timeout", type=int, default=900,
                        help="maximum emulator runtime in seconds")
    parser.add_argument("--out", required=True, type=Path,
                        help="new output directory under extract/analysis")
    args = parser.parse_args(argv)

    state = repo_path(args.state)
    play = repo_path(args.play) if args.play else None
    image_path = repo_path(args.image)
    emulator = repo_path(args.emulator)
    rom = repo_path(args.rom)
    out = repo_path(args.out)
    try:
        out.relative_to(ANALYSIS.resolve())
    except ValueError:
        parser.error("--out must be inside extract/analysis")
    if args.checkpoint <= 0 or args.timeout <= 0:
        parser.error("--checkpoint and --timeout must be positive")
    if (play is None) == (args.frames is None):
        parser.error("provide exactly one of --play or --frames")
    if args.frames is not None and args.frames < 2:
        parser.error("--frames must be at least 2")
    if not args.actor or len(set(args.actor)) != len(args.actor):
        parser.error("--actor values must be unique")
    for label, path in (("savestate", state), ("image", image_path),
                        ("emulator", emulator), ("GDI", rom)):
        if not path.is_file():
            parser.error(f"{label} does not exist: {path}")
    if play is not None and not play.is_file():
        parser.error(f"play schedule does not exist: {play}")
    if out.exists():
        parser.error(f"refusing to replace existing output directory: {out}")

    try:
        if play is None:
            exit_frame = args.frames - 1
            events = [(0, "KEYF", 0), (exit_frame, "EXITF", None)]
            neutral_input = True
        else:
            events, exit_frame = parse_schedule(play.read_text(encoding="utf-8"))
            neutral_input = args.neutral_input
        if args.pulse and not neutral_input:
            parser.error("--pulse requires --neutral-input")
        if any(end >= exit_frame for _start, end, _mask in args.pulse):
            parser.error("pulse end frames must precede EXITF")
        ordered_pulses = sorted(args.pulse)
        if any(current[0] < previous[1]
               for previous, current in zip(ordered_pulses, ordered_pulses[1:])):
            parser.error("input pulses must not overlap")
        if len(set(args.sample_frame)) != len(args.sample_frame) or any(
                frame < 1 or frame >= exit_frame for frame in args.sample_frame):
            parser.error("--sample-frame values must be unique and before EXITF")
        sample_frames = list(args.sample_frame)
        for start, end, step in args.sample_range:
            if end > exit_frame:
                parser.error("--sample-range frames must precede EXITF")
            sample_frames.extend(range(start, end, step))
        if neutral_input:
            events = [(frame, command, 0 if command == "KEYF" else None)
                      for frame, command, _mask in events]
        for start, end, mask in ordered_pulses:
            events.extend(((start, "KEYF", mask), (end, "KEYF", 0)))
        schedule, checkpoints = checkpoint_schedule(events, exit_frame,
                                                     args.checkpoint,
                                                     sample_frames)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    if not checkpoints:
        parser.error("checkpoint interval produced no samples before EXITF")

    out.mkdir(parents=True)
    scheduled_play = out / "input_schedule.txt"
    scheduled_play.write_text(schedule, encoding="ascii")
    capture_dir = out / "capture"
    command = [sys.executable, str(CAPTURE), "--state", str(state),
               "--play", str(scheduled_play), "--emulator", str(emulator),
               "--rom", str(rom), "--out", str(capture_dir),
               "--timeout", str(args.timeout)]
    print(f"native_motion_timeline_probe: {len(checkpoints)} checkpoints, "
          f"{len(args.actor)} actor(s), {exit_frame} frames", flush=True)
    result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True,
                            check=False)
    if result.stdout:
        print(result.stdout, end="")
    if result.stderr:
        print(result.stderr, file=sys.stderr, end="")
    if result.returncode:
        return result.returncode

    image = image_path.read_bytes()
    joint_table_offset = JOINT_ADVANCE_ADDRESS - args.image_address
    if (joint_table_offset < 0 or joint_table_offset > len(image) or
            JOINT_RECORD_COUNT > len(image) - joint_table_offset):
        print("native_motion_timeline_probe: joint-advance table lies outside the image",
              file=sys.stderr)
        return 1
    joint_advances = image[joint_table_offset:
                           joint_table_offset + JOINT_RECORD_COUNT]
    rows: list[dict[str, object]] = []
    pose_rows: list[dict[str, object]] = []
    joint_rows: list[dict[str, object]] = []
    for slot, frame, input_mask in checkpoints:
        state_path = capture_dir / "data" / f"vf3_{slot}.state"
        if not state_path.is_file():
            print(f"native_motion_timeline_probe: missing checkpoint {state_path}",
                  file=sys.stderr)
            return 1
        blob = load_state(str(state_path))
        _ram_offset, ram, anchor = locate_ram(
            blob, image, args.image_address, None)
        for actor in args.actor:
            motion_id = read_u16(ram, actor + 0x3c)
            cycle = read_u16(ram, actor + 0x1a00)
            phase_raw = read_u32(ram, actor + 0x3e)
            phase_signed = struct.unpack("<i", struct.pack("<I", phase_raw))[0]
            actor_row = {
                "frame": frame,
                "input_mask": f"0x{input_mask:04x}",
                "slot": slot,
                "state": state_path.relative_to(ROOT).as_posix(),
                "actor": f"0x{actor:08x}",
                "byte_0x60": read_ram(ram, actor + 0x60, 1)[0],
                "byte_0x61": read_ram(ram, actor + 0x61, 1)[0],
                "motion_id": f"0x{motion_id:04x}",
                "phase_raw": f"0x{phase_raw:08x}",
                "phase_q8": phase_signed,
                "phase_frame": phase_signed / 256.0,
                "cycle": cycle,
                "descriptor_pointer": f"0x{read_u32(ram, actor + 0x58):08x}",
                "record_pointer": f"0x{read_u32(ram, actor + 0x1d00):08x}",
                "ram_anchor": anchor,
            }
            rows.append(actor_row)
            if args.include_pose:
                pose_rows.append({
                    **actor_row,
                    "channels_at_0x1d04": read_floats(ram, actor + 0x1d04, 63),
                    "packed_pose_fields_at_0x1f50": read_u16s(ram, actor + 0x1f50, 42),
                    "attachment_rows_at_0x180": matrix_rows(ram, actor + 0x180, 18),
                    "bone_rows_at_0x7c0": matrix_rows(ram, actor + 0x7c0, 23),
                })
            if args.include_joints:
                joint_rows.append({
                    **actor_row,
                    "channels_at_0x1d04": read_floats(ram, actor + 0x1d04, 63),
                    "joint_records_at_0x180": joint_records(
                        ram, actor, joint_advances),
                })

    csv_path = out / "motion_timeline.csv"
    with csv_path.open("x", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    pose_path = None
    if args.include_pose:
        pose_path = out / "pose_timeline.jsonl"
        with pose_path.open("x", encoding="utf-8") as handle:
            for row in pose_rows:
                handle.write(json.dumps(row, allow_nan=False, separators=(",", ":")) + "\n")
    joint_path = None
    if args.include_joints:
        joint_path = out / "joint_timeline.jsonl"
        with joint_path.open("x", encoding="utf-8") as handle:
            for row in joint_rows:
                handle.write(json.dumps(row, separators=(",", ":")) + "\n")
    report_path = out / "motion_timeline.json"
    report_path.write_text(json.dumps({
        "diagnostic_only": True,
        "neutral_input": neutral_input,
        "pulses": [{"start": start, "end_exclusive": end,
                    "mask": f"0x{mask:04x}"}
                   for start, end, mask in ordered_pulses],
        "state": state.relative_to(ROOT).as_posix(),
        "play": play.relative_to(ROOT).as_posix() if play else None,
        "schedule": scheduled_play.relative_to(ROOT).as_posix(),
        "generated_frames": args.frames,
        "checkpoint_interval": args.checkpoint,
        "sampled_frames": [frame for _slot, frame, _mask in checkpoints],
        "actors": [f"0x{actor:08x}" for actor in args.actor],
        "pose_samples": pose_path.name if pose_path else None,
        "joint_samples": joint_path.name if joint_path else None,
        "rows": rows,
        "limitations": [
            "Input mask and actor state are sampled after each checkpoint event.",
            "Repeated runs can drift even with the same source state and inputs.",
            "A matching input mask does not establish that it caused a motion change.",
            "Motion IDs and actor bytes are reported without action labels.",
            "Pose mode preserves raw matrix rows and does not assign a channel or row to a bone or model part.",
            "Joint mode preserves variable-stride record prefixes; their fields are not semantically decoded.",
        ],
    }, indent=2) + "\n", encoding="utf-8")

    print("frame  input  actor       motion cycle descriptor      record")
    for row in rows:
        print(f"{row['frame']:5}  {row['input_mask']:>6}  {row['actor']} "
              f"{row['motion_id']:>6} {row['cycle']:5} "
              f"{row['descriptor_pointer']} {row['record_pointer']}")
    print(f"CSV: {csv_path}")
    print(f"JSON: {report_path}")
    if pose_path:
        print(f"Pose samples: {pose_path}")
    if joint_path:
        print(f"Joint samples: {joint_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
