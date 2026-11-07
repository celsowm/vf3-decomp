#!/usr/bin/env python3
"""Audit retained native-motion PC-watch and capsule captures.

This read-only helper separates runs that produced no watched motion-update
specimens from runs that did. It prints actor/motion/return-PC samples in
capture order, capsule accounting when available, and optional comparison to
one baseline ``.cases`` file.

The samples have no frame timestamps. A motion ID at the watched update is the
currently selected ID; it is not an action label and does not identify which
input selected it.

Examples:
  python tools/native_motion_corpus_audit.py \
      extract/analysis/native_motion_action_controls_v4 \
      extract/analysis/native_motion_action_probe_s29_v4
  python tools/native_motion_corpus_audit.py \
      extract/analysis/native_motion_context_s29_v4 \
      --baseline extract/analysis/native_motion_context_s29_v4/baseline/f_8c0ad1b8.cases
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_PC = 0x8C0AD1B8
PHYSICAL_MASK = 0x1FFFFFFF
CASE_NAME = re.compile(r"^f_([0-9a-fA-F]{8})\.cases$")


def address(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid address: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("address must fit in 32 bits")
    return value


def repository_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (ROOT / path).resolve()


def entry_from_case(path: Path) -> int | None:
    match = CASE_NAME.fullmatch(path.name)
    return int(match.group(1), 16) if match else None


def read_cases(path: Path) -> list[dict[str, int]]:
    rows: list[dict[str, int]] = []
    for line_number, line in enumerate(path.read_text(encoding="ascii").splitlines(), 1):
        fields = line.split()
        if not fields:
            continue
        if len(fields) < 74:
            raise ValueError(f"{path}:{line_number}: expected 74 register words")
        try:
            words = [int(value, 16) for value in fields[:74]]
        except ValueError as exc:
            raise ValueError(f"{path}:{line_number}: invalid register word") from exc
        rows.append({"actor": words[4], "raw_motion": words[5],
                     "motion": words[5] & 0x1FFF, "pr": words[16]})
    return rows


def load_json(path: Path) -> dict:
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        raise ValueError(f"cannot read {path}: {exc}") from exc
    if not isinstance(value, dict):
        raise ValueError(f"expected a JSON object in {path}")
    return value


def discover(paths: list[Path], target_pc: int) -> tuple[list[Path], list[Path]]:
    cases: set[Path] = set()
    manifests: set[Path] = set()
    wanted = target_pc & PHYSICAL_MASK
    for supplied in paths:
        path = repository_path(supplied)
        if path.is_file():
            if path.name == "batch_manifest.json":
                manifests.add(path)
            elif path.name == "capsule_manifest.json":
                manifests.add(path)
            elif path.suffix == ".cases":
                entry = entry_from_case(path)
                if entry is not None and (entry & PHYSICAL_MASK) == wanted:
                    cases.add(path)
            else:
                raise ValueError(f"unsupported input file: {supplied}")
            continue
        if not path.is_dir():
            raise ValueError(f"input path does not exist: {supplied}")
        for candidate in path.rglob("*.cases"):
            entry = entry_from_case(candidate)
            if entry is not None and (entry & PHYSICAL_MASK) == wanted:
                cases.add(candidate)
        for name in ("batch_manifest.json", "capsule_manifest.json"):
            manifests.update(path.rglob(name))
    return sorted(cases), sorted(manifests)


def case_rows(cases: list[Path]) -> list[dict[str, object]]:
    result = []
    for path in cases:
        result.append({"path": path, "samples": read_cases(path)})
    return result


def capsule_accounting(manifests: list[Path], target_pc: int) -> dict[Path, dict[str, object]]:
    accounting: dict[Path, dict[str, object]] = {}
    for path in manifests:
        if path.name != "capsule_manifest.json":
            continue
        data = load_json(path)
        for run in data.get("runs", []):
            if not isinstance(run, dict):
                continue
            source = run.get("source")
            if isinstance(source, str) and source:
                source_path = repository_path(Path(source))
                target_entries = any(
                    isinstance(entry, str) and entry.lower().startswith("0x") and
                    (int(entry, 16) & PHYSICAL_MASK) == (target_pc & PHYSICAL_MASK)
                    for entry in data.get("entries", {})
                )
                accounting[source_path] = {
                    "started": run.get("started"),
                    "completed": run.get("completed"),
                    "armed": run.get("armed"),
                    "unaccounted": run.get("unaccounted"),
                    "target_entries": target_entries,
                }
    return accounting


def read_run_rows(manifests: list[Path]) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for path in manifests:
        if path.name != "batch_manifest.json":
            continue
        data = load_json(path)
        for run in data.get("runs", []):
            if not isinstance(run, dict):
                continue
            rows.append({
                "manifest": path,
                "name": run.get("name", "(unnamed)"),
                "state": run.get("state", ""),
                "play": run.get("play", ""),
                "frames": run.get("ran_frames", run.get("frames", "")),
                "capsule_bytes": run.get("capsule_bytes", ""),
                "capsule": run.get("capsule", ""),
                "returncode": run.get("returncode", ""),
            })
    return rows


def sequence(samples: list[dict[str, int]]) -> list[tuple[int, int, int]]:
    return [(row["actor"], row["motion"], row["pr"]) for row in samples]


def compare_sequences(baseline: list[dict[str, int]],
                      candidate: list[dict[str, int]]) -> str:
    left, right = sequence(baseline), sequence(candidate)
    for index, (base_row, row) in enumerate(zip(left, right)):
        if base_row != row:
            return (f"differs at sample {index}: baseline {format_sample(base_row)}, "
                    f"run {format_sample(row)}")
    if len(left) != len(right):
        return f"common prefix {min(len(left), len(right))}; counts {len(left)} vs {len(right)}"
    return "matches baseline sequence"


def format_sample(row: tuple[int, int, int]) -> str:
    actor, motion, pr = row
    return f"actor=0x{actor:08x} motion=0x{motion:03x} PR=0x{pr:08x}"


def play_masks(play: str) -> str:
    if not play:
        return ""
    candidate = repository_path(Path(play))
    if not candidate.is_file():
        return ""
    masks: list[int] = []
    for line in candidate.read_text(encoding="utf-8").splitlines():
        fields = line.split()
        if len(fields) >= 3 and fields[1].upper() == "KEYF":
            try:
                mask = int(fields[2], 0)
            except ValueError:
                continue
            if mask not in masks:
                masks.append(mask)
    return ",".join(f"0x{mask:04x}" for mask in masks)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("paths", nargs="+", type=Path,
                        help="capture directories, manifest files, or .cases files")
    parser.add_argument("--pc", type=address, default=DEFAULT_PC,
                        help="motion-update entry to audit (default: 0x8c0ad1b8)")
    parser.add_argument("--baseline", type=Path,
                        help="optional .cases file for ordered-sequence comparisons")
    parser.add_argument("--json", action="store_true",
                        help="emit machine-readable JSON instead of the text report")
    args = parser.parse_args(argv)

    try:
        cases, manifests = discover(args.paths, args.pc)
        records = case_rows(cases)
        run_rows = read_run_rows(manifests)
        capsule_rows = capsule_accounting(manifests, args.pc)
        baseline_samples = read_cases(repository_path(args.baseline)) if args.baseline else None

        if args.json:
            payload = {
                "diagnostic_only": True,
                "pc": f"0x{args.pc:08x}",
                "warning": "samples have no frame timestamps or action labels",
                "runs": [{
                    "manifest": str(row["manifest"]),
                    "name": row["name"],
                    "state": row["state"],
                    "play": row["play"],
                    "frames": row["frames"],
                    "capsule_bytes": row["capsule_bytes"],
                    "returncode": row["returncode"],
                } for row in run_rows],
                "captures": [{
                    "path": str(record["path"]),
                    "samples": record["samples"],
                    "baseline_comparison": (
                        compare_sequences(baseline_samples, record["samples"])
                        if baseline_samples is not None else None),
                } for record in records],
            }
            print(json.dumps(payload, indent=2))
            return 0

        print(f"Motion-update capture audit at 0x{args.pc:08x}")
        print("Samples are in capture order; they have no frame timestamps or action labels.\n")
        if run_rows:
            print("Runs")
            for row in run_rows:
                capsule = row["capsule"]
                capsule_path = Path(capsule) if isinstance(capsule, str) and capsule else None
                account = capsule_rows.get(repository_path(capsule_path)) if capsule_path else None
                frame_text = f"{row['frames']} frames" if row["frames"] != "" else "frames unknown"
                mask_text = play_masks(str(row["play"]))
                extra = f" KEYF={mask_text}" if mask_text else ""
                if account:
                    extra += (f" probes={account['completed']}/{account['started']}"
                              f" armed={account['armed']}")
                    if account["started"] == 0 and not account["target_entries"]:
                        extra += " no watched call"
                print(f"  {row['name']}: {frame_text}; capsule={row['capsule_bytes']} B; "
                      f"exit={row['returncode']}{extra}")
        if records:
            print("\nWatched samples")
            for record in records:
                samples = record["samples"]
                print(f"  {record['path']}: {len(samples)} sample(s)")
                for index, sample in enumerate(samples):
                    print(f"    {index}: {format_sample((sample['actor'], sample['motion'], sample['pr']))}")
                if baseline_samples is not None:
                    print(f"    comparison: {compare_sequences(baseline_samples, samples)}")
        elif run_rows:
            print("\nNo matching .cases file was found for these runs.")
        else:
            print("\nNo run manifests or matching .cases files were found.")
        return 0
    except (OSError, ValueError, TypeError) as exc:
        print(f"native_motion_corpus_audit: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
