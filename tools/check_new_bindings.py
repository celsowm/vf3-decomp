#!/usr/bin/env python3
"""check_new_bindings.py — replay gate over a set of ledger rows.

Runs each binding's own test command. Bindings marked strict run with
VF3_STRICT_REPLAY=1; unmarked bindings retain their existing test semantics.
Missing evidence and invalid selections never count as successful replays.

    python tools/check_new_bindings.py --bindings tools/golden_bindings.json \
        --only-new-since HEAD
    python tools/check_new_bindings.py --pc 0x8c064246 --pc 0x8c05027a
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import shlex
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def normalize_pc(value: str) -> str:
    try:
        address = int(value, 16)
    except (TypeError, ValueError):
        raise ValueError(f"invalid PC: {value!r}") from None
    if not 0 <= address <= 0xFFFFFFFF:
        raise ValueError(f"PC outside 32-bit address range: {value!r}")
    return f"0x{address:08x}"


def binding_pc(key: str) -> str:
    """Bindings may use campaign:PC keys to retain multiple corpora per entry."""
    return normalize_pc(key.rsplit(":", 1)[-1])


def test_arguments(spec: dict) -> list[str]:
    """Parse a command without invoking a shell; lists avoid quoting entirely.

    Legacy strings allow single/double quoted arguments. Backslashes are
    literal so Windows paths survive when the manifest is read on any host.
    """
    command = spec.get("test", "build/vf3matrixfamily.exe")
    if isinstance(command, list):
        if not command or not all(isinstance(x, str) and x for x in command):
            raise ValueError("test argument list must contain nonempty strings")
        return command
    if not isinstance(command, str):
        raise ValueError("test must be a command string or argument list")
    lexer = shlex.shlex(command, posix=True)
    lexer.whitespace_split = True
    lexer.commenters = ""
    lexer.escape = ""
    args = list(lexer)
    if not args:
        raise ValueError("empty test command")
    return args


def resolve_test(command: str, repo: Path | None = None,
                 config: str | None = None) -> Path | None:
    """Find native/suffixed or CMake multi-config output, never use PATH."""
    root = REPO if repo is None else repo
    requested = root / command
    stem = requested.with_suffix("") if requested.suffix.lower() == ".exe" else requested
    native = stem.with_name(stem.name + ".exe") if os.name == "nt" else stem
    alternatives = list(dict.fromkeys((native, requested, stem, stem.with_name(stem.name + ".exe"))))
    if config:
        # Explicit configuration never falls back to a potentially stale
        # single-config binary in build/. An already qualified path is fine.
        for path in alternatives:
            candidate = path if path.parent.name == config else path.parent / config / path.name
            if candidate.is_file():
                return candidate
        return None
    for path in alternatives:
        if path.is_file():
            return path
    configs = ["Debug", "Release", "RelWithDebInfo", "MinSizeRel"]
    found = []
    for name in configs:
        for path in alternatives:
            candidate = path.parent / name / path.name
            if candidate.is_file():
                found.append(candidate)
                break
    if len(found) > 1:
        raise ValueError(f"ambiguous build for {command}; select --build-config")
    return found[0] if found else None


def ported_statuses(rows) -> dict[str, set[str]]:
    result: dict[str, set[str]] = {}
    for row in rows:
        status = row["status"]
        if status.startswith("ported"):
            result.setdefault(normalize_pc(row["entry"]), set()).add(status)
    return result


def ledger_statuses() -> dict[str, set[str]]:
    p = REPO / "docs" / "decomp_status.csv"
    with p.open(newline="") as f:
        return ported_statuses(csv.DictReader(f))


def ledger_entries() -> set[str]:
    return set(ledger_statuses())


def entries_new_since(ref: str) -> set[str]:
    p = subprocess.run(["git", "show", f"{ref}:docs/decomp_status.csv"],
                       capture_output=True, text=True, cwd=REPO)
    if p.returncode != 0:
        raise ValueError(f"cannot read ledger at Git reference {ref!r}: {p.stderr.strip()}")
    old = ported_statuses(csv.DictReader(p.stdout.splitlines()))
    return {pc for pc, statuses in ledger_statuses().items() if statuses != old.get(pc)}


def run(pc: str, spec: dict, config: str | None = None) -> tuple[str, str, str]:
    try:
        golden = REPO / spec["golden"]
        argv = test_arguments(spec)
        exe = resolve_test(argv[0], config=config)
    except (KeyError, TypeError, ValueError) as exc:
        return pc, "INVALID-BINDING", str(exc)
    if exe is None:
        return pc, "MISSING-TEST", argv[0]
    if not golden.is_file():
        return pc, "MISSING-GOLDEN", str(golden)
    if golden.stat().st_size == 0:
        return pc, "EMPTY-GOLDEN", str(golden)
    env = dict(os.environ)
    if spec.get("strict"):
        env["VF3_STRICT_REPLAY"] = "1"
    cmd = [str(exe)] + argv[1:] + [str(golden)]
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, cwd=REPO,
                           timeout=900, env=env)
    except subprocess.TimeoutExpired:
        return pc, "TIMEOUT", ""
    except OSError as exc:
        return pc, "EXEC-ERROR", str(exc)
    lines = ((p.stdout or "") + (p.stderr or "")).strip().splitlines()
    tail = lines[-1] if lines else ""
    return pc, ("PASS" if p.returncode == 0 else "FAIL"), tail


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--bindings", default="tools/golden_bindings.json")
    selection = ap.add_mutually_exclusive_group()
    selection.add_argument("--only-new-since", default="")
    selection.add_argument("--pc", action="append", default=[])
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--build-config", choices=["Debug", "Release", "RelWithDebInfo", "MinSizeRel"],
                    help="require this CMake configuration subdirectory; never fall back to build/ directly")
    a = ap.parse_args(argv)
    if a.jobs < 1:
        ap.error("--jobs must be positive")
    try:
        raw = json.loads((REPO / a.bindings).read_text(encoding="utf-8"))
        if not isinstance(raw, dict) or not raw:
            raise ValueError("bindings must be a nonempty object")
        cfg = {pc.lower(): spec for pc, spec in raw.items()}
        if len(cfg) != len(raw):
            raise ValueError("bindings contain duplicate case-insensitive keys")
        if not all(isinstance(spec, dict) for spec in cfg.values()):
            raise ValueError("each binding must be an object")
        addresses = {key: binding_pc(key) for key in cfg}
        if a.pc:
            want = {normalize_pc(p) for p in a.pc}
        elif a.only_new_since:
            want = entries_new_since(a.only_new_since)
        else:
            want = set(addresses.values())
        missing = want - set(addresses.values())
        if missing:
            raise ValueError("selected PCs have no binding: " + ", ".join(sorted(missing)))
    except (OSError, ValueError, KeyError, TypeError) as exc:
        print(f"check_new_bindings: {exc}", file=sys.stderr)
        return 2
    jobs = [(pc, spec) for pc, spec in cfg.items() if addresses[pc] in want]
    if not jobs:
        print(f"no new bindings since {a.only_new_since}; no replay executed")
        return 0
    strict = sum(bool(spec.get("strict")) for _, spec in jobs)
    print(f"check_new_bindings: {len(jobs)} bindings ({strict} marked strict, "
          f"{len(jobs) - strict} unmarked), "
          f"{a.jobs} jobs", flush=True)
    fails = []
    with ThreadPoolExecutor(max_workers=a.jobs) as pool:
        for pc, status, tail in pool.map(lambda it: run(*it, config=a.build_config), jobs):
            if status != "PASS":
                fails.append((pc, status, tail))
                print(f"  {status:>12} {pc}: {tail[:110]}", flush=True)
    print(f"\n{len(jobs) - len(fails)}/{len(jobs)} PASS, {len(fails)} not-PASS")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(main())
