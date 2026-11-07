#!/usr/bin/env python3
"""Run a Flycast frame script in an isolated copy of its local build.

The runner copies the emulator and non-savestate device files into a new
directory under ``extract/analysis``. ``VF3_STATE`` and ``SAVEF`` therefore
operate only on that copy; retained states in ``tools/emu`` are never staged
or overwritten. The play script must end with one frame-clock ``EXITF``.

Example:
  python tools/flycast_capture.py --state tools/emu/flycast-build/data/vf3_26.state \
      --play tools/vf3_play_pose_capture.txt \
      --out extract/analysis/flycast_pose_capture_s26_v1
"""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"
DEFAULT_EMULATOR = ROOT / "tools" / "emu" / "flycast-build" / "flycast_v3.exe"
DEFAULT_ROM = ROOT / "rom" / "vf3.gdi"
EXITF_RE = re.compile(r"^\s*(\d+)\s+EXITF\s*(?:#.*)?$", re.IGNORECASE)


def repo_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def validate_play(path: Path) -> int:
    exits: list[int] = []
    for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        stripped = line.strip()
        if not stripped or stripped.startswith("#"):
            continue
        match = EXITF_RE.match(line)
        if match:
            exits.append(int(match.group(1)))
    if len(exits) != 1:
        raise ValueError("play script must contain exactly one frame-clock EXITF")
    return exits[0] + 1


def isolated_build(source_exe: Path, destination: Path) -> Path:
    destination.mkdir(parents=True)
    exe = destination / source_exe.name
    shutil.copy2(source_exe, exe)

    source_root = source_exe.parent
    config = source_root / "emu.cfg"
    if config.is_file():
        shutil.copy2(config, destination / config.name)

    source_data = source_root / "data"
    target_data = destination / "data"
    target_data.mkdir()
    if source_data.is_dir():
        for source in source_data.rglob("*"):
            if not source.is_file() or ".state" in source.name.lower():
                continue
            relative = source.relative_to(source_data)
            target = target_data / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, target)
    return exe


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--emulator", type=Path, default=DEFAULT_EMULATOR,
                        help=f"local Flycast executable (default: {DEFAULT_EMULATOR})")
    parser.add_argument("--rom", type=Path, default=DEFAULT_ROM,
                        help=f"disc image or GDI descriptor (default: {DEFAULT_ROM})")
    parser.add_argument("--state", type=Path,
                        help="optional source savestate; it is copied into the isolated data directory")
    parser.add_argument("--play", type=Path, required=True,
                        help="frame-clock input script containing exactly one EXITF")
    parser.add_argument("--out", type=Path, required=True,
                        help="new isolated output directory under extract/analysis")
    parser.add_argument("--timeout", type=int, default=900,
                        help="maximum run time in seconds (default: 900)")
    parser.add_argument("--trace-instructions", action="store_true",
                        help="record every guest PC/opcode and print a histogram")
    parser.add_argument("--trace-top", type=int, default=30,
                        help="number of histogram rows to keep (default: 30)")
    parser.add_argument("--trace-pc", type=lambda value: int(value, 0),
                        action="append", default=[], metavar="PC",
                        help="also report an exact PC count; repeatable")
    args = parser.parse_args(argv)

    emulator = repo_path(args.emulator)
    rom = repo_path(args.rom)
    play = repo_path(args.play)
    state = repo_path(args.state) if args.state else None
    out = repo_path(args.out)
    try:
        if not emulator.is_file():
            raise ValueError(f"emulator does not exist: {emulator}")
        if not rom.is_file():
            raise ValueError(f"disc image does not exist: {rom}")
        if not play.is_file():
            raise ValueError(f"play script does not exist: {play}")
        if state is not None and not state.is_file():
            raise ValueError(f"savestate does not exist: {state}")
        if args.timeout <= 0:
            raise ValueError("--timeout must be positive")
        try:
            out.relative_to(ANALYSIS.resolve())
        except ValueError as exc:
            raise ValueError("--out must be inside extract/analysis") from exc
        if out.exists():
            raise ValueError(f"refusing to replace existing output directory: {out}")
        trace_frames = validate_play(play)
        if args.trace_top <= 0:
            raise ValueError("--trace-top must be positive")
        if any(not 0 <= pc <= 0xFFFFFFFF for pc in args.trace_pc):
            raise ValueError("--trace-pc values must fit in 32 bits")
        if args.trace_pc and not args.trace_instructions:
            raise ValueError("--trace-pc requires --trace-instructions")
    except (OSError, ValueError) as exc:
        parser.error(str(exc))

    out.parent.mkdir(parents=True, exist_ok=True)
    try:
        isolated_exe = isolated_build(emulator, out)
    except OSError as exc:
        print(f"flycast_capture: cannot create isolated build: {exc}", file=sys.stderr)
        return 2

    env = {key: value for key, value in os.environ.items()
           if not key.upper().startswith("VF3_")}
    env["VF3_PLAY"] = str(play)
    if state is not None:
        env["VF3_STATE"] = str(state)
    trace_path = out / "instruction_trace.bin"
    summary_path = out / "instruction_trace_summary.txt"
    if args.trace_instructions:
        env["VF3_INTERPRETER"] = "1"
        env["VF3_FULL"] = "1"
        env["VF3_TRACE"] = str(trace_path)
        env["VF3_INSTR"] = "1"
        env["VF3_TRACE_FRAMES"] = str(trace_frames)

    log_path = out / "run.log"
    try:
        with log_path.open("w", encoding="utf-8", errors="replace") as log:
            result = subprocess.run([str(isolated_exe), str(rom)], cwd=out,
                                    env=env, stdout=log, stderr=subprocess.STDOUT,
                                    timeout=args.timeout, check=False)
    except subprocess.TimeoutExpired:
        print(f"flycast_capture: timed out after {args.timeout}s; log={log_path}",
              file=sys.stderr)
        return 2
    except OSError as exc:
        print(f"flycast_capture: could not run Flycast: {exc}; log={log_path}",
              file=sys.stderr)
        return 2

    saved_states = sorted((out / "data").glob("vf3_*.state"))
    print(f"return code: {result.returncode}")
    print(f"log: {log_path}")
    print(f"isolated data: {out / 'data'}")
    print("saved states:")
    for saved_state in saved_states:
        print(f"  {saved_state} ({saved_state.stat().st_size} bytes)")
    if not saved_states:
        print("  (none)")
    if args.trace_instructions:
        trace_tool = ROOT / "tools" / "trace_bin_sum.py"
        trace_command = [sys.executable, str(trace_tool), str(trace_path),
                         "--top", str(args.trace_top)]
        for pc in args.trace_pc:
            trace_command.extend(("--pc", hex(pc)))
        summary = subprocess.run(trace_command, cwd=ROOT, check=False,
                                 capture_output=True, text=True)
        summary_path.write_text(summary.stdout + summary.stderr,
                                encoding="utf-8")
        print(f"instruction trace: {trace_path}")
        print(f"trace summary: {summary_path}")
        if summary.returncode:
            print(f"trace_bin_sum.py exited {summary.returncode}",
                  file=sys.stderr)
            return summary.returncode
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
