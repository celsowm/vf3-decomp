#!/usr/bin/env python3
"""Classify saved front-end states by guest fight/control code execution.

For each retained Flycast state, replay a short frame-clock input schedule with
the instruction tracer enabled, then report counts for the fight workers,
controller readers, merge routine, and action update in both the 0x0c and 0x8c
RAM mirrors. Actor data can be stale; these PC counts provide a direct
execution check.

Example:
  python tools/front_to_fight_state_scan.py \
      --state-dir extract/analysis/front_to_fight_probe_v3/data \
      --out extract/analysis/front_to_fight_state_scan_v3 \
      --pulse 15:30:0x8 --pulse 45:60:0x4
"""

from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path
import re
import subprocess
import sys

from native_motion_input_probe import play_text, pulse


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "extract" / "analysis"
CAPTURE = ROOT / "tools" / "flycast_capture.py"
DEFAULT_EMULATOR = ROOT / "tools" / "emu" / "flycast-build" / "flycast_v3.exe"
DEFAULT_ROM = ROOT / "rom" / "vf3.gdi"
TRACE_BASES = (
    (0x0C073C2A, "fight worker"),
    (0x0C068F86, "fight worker"),
    (0x0C069078, "fight worker"),
    (0x0C09D6E0, "MT evaluator"),
    (0x0C09AF6C, "controller merge"),
    (0x0C09B006, "selected controller port"),
    (0x0C0AD1B8, "action update"),
)
PC_LABELS = {
    address: label
    for base, label in TRACE_BASES
    for address in (base, base | 0x80000000)
}
TRACE_PCS = tuple(PC_LABELS)
PC_COUNT_RE = re.compile(r"^PC (0x[0-9a-fA-F]+): (\d+)\s*$", re.MULTILINE)


def repo_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def state_sort_key(path: Path) -> tuple[int, str]:
    match = re.search(r"(\d+)$", path.stem)
    return (int(match.group(1)) if match else 0x7FFFFFFF,
            path.name.casefold())


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--state-dir", required=True, type=Path,
                        help="directory of retained savestates")
    parser.add_argument("--pattern", default="vf3_*.state",
                        help="state filename glob (default: vf3_*.state)")
    parser.add_argument("--out", required=True, type=Path,
                        help="new report directory under extract/analysis")
    parser.add_argument("--emulator", type=Path, default=DEFAULT_EMULATOR)
    parser.add_argument("--rom", type=Path, default=DEFAULT_ROM)
    parser.add_argument("--frames", type=int, default=90,
                        help="frames replayed per state (default: 90)")
    parser.add_argument("--pulse", type=pulse, action="append", default=[],
                        help="input pulse START:END:MASK; repeatable")
    parser.add_argument("--timeout", type=int, default=900,
                        help="per-state timeout in seconds (default: 900)")
    args = parser.parse_args(argv)

    state_dir = repo_path(args.state_dir)
    emulator = repo_path(args.emulator)
    rom = repo_path(args.rom)
    out = repo_path(args.out)
    try:
        out.relative_to(ANALYSIS.resolve())
    except ValueError:
        parser.error("--out must be inside extract/analysis")
    if args.frames < 2 or args.timeout <= 0:
        parser.error("--frames must be at least 2 and --timeout must be positive")
    if not state_dir.is_dir():
        parser.error(f"savestate directory does not exist: {state_dir}")
    if not emulator.is_file():
        parser.error(f"emulator does not exist: {emulator}")
    if not rom.is_file():
        parser.error(f"disc image does not exist: {rom}")
    if not CAPTURE.is_file():
        parser.error(f"capture runner is missing: {CAPTURE}")
    if out.exists():
        parser.error(f"refusing to replace existing output directory: {out}")
    if not args.pulse:
        args.pulse = [(15, 30, 0x8), (45, 60, 0x4)]
    try:
        schedule = play_text(args.frames, args.pulse)
    except ValueError as exc:
        parser.error(str(exc))

    states = sorted((p.resolve() for p in state_dir.glob(args.pattern) if p.is_file()),
                    key=state_sort_key)
    if not states:
        parser.error(f"no states matched {args.pattern!r} in {state_dir}")

    out.mkdir(parents=True)
    play_path = out / "input_schedule.txt"
    play_path.write_text(schedule, encoding="ascii")
    rows: list[dict[str, object]] = []
    for index, state in enumerate(states, 1):
        probe_out = out / state.stem
        command = [sys.executable, str(CAPTURE), "--state", str(state),
                   "--emulator", str(emulator), "--rom", str(rom),
                   "--play", str(play_path), "--out", str(probe_out),
                   "--timeout", str(args.timeout), "--trace-instructions"]
        for pc in TRACE_PCS:
            command.extend(("--trace-pc", hex(pc)))
        print(f"[{index}/{len(states)}] {state.name}", flush=True)
        result = subprocess.run(command, cwd=ROOT, check=False)
        summary = probe_out / "instruction_trace_summary.txt"
        row: dict[str, object] = {
            "state": state.name,
            "return_code": result.returncode,
            "summary": str(summary),
            "counts": {f"0x{pc:08x}": 0 for pc in TRACE_PCS},
        }
        if result.returncode == 0 and summary.is_file():
            values = {int(address, 16): int(count)
                      for address, count in PC_COUNT_RE.findall(
                          summary.read_text(encoding="utf-8", errors="replace"))}
            row["counts"] = {f"0x{pc:08x}": values.get(pc, 0)
                             for pc in TRACE_PCS}
        else:
            row["error"] = "capture failed or instruction summary is missing"
        rows.append(row)

    report = {
        "diagnostic_only": True,
        "state_dir": str(state_dir),
        "frames": args.frames,
        "pulses": [
            {"start": start, "end_exclusive": end, "mask": f"0x{mask:04x}"}
            for start, end, mask in sorted(args.pulse)
        ],
        "pc_labels": {f"0x{pc:08x}": label
                       for pc, label in PC_LABELS.items()},
        "records": rows,
        "limitations": [
            "A PC hit establishes execution, not that an input caused it.",
            "A missing hit within this replay window does not prove the path is unreachable.",
        ],
    }
    report_path = out / "state_scan.json"
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    csv_path = out / "state_scan.csv"
    fields = ["state", *[f"pc_{pc:08x}" for pc in TRACE_PCS], "return_code"]
    with csv_path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        for row in rows:
            counts = row["counts"]
            writer.writerow({
                "state": row["state"],
                **{f"pc_{pc:08x}": counts[f"0x{pc:08x}"] for pc in TRACE_PCS},
                "return_code": row["return_code"],
            })
    print(f"report: {report_path}")
    print(f"CSV: {csv_path}")
    return 0 if all(row["return_code"] == 0 for row in rows) else 1


if __name__ == "__main__":
    raise SystemExit(main())
