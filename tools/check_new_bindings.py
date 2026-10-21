#!/usr/bin/env python3
"""check_new_bindings.py — replay gate over a set of ledger rows.

Runs each binding's own test command. Bindings marked strict run with
VF3_STRICT_REPLAY=1; unmarked bindings retain their existing test semantics.
Missing evidence and invalid selections never count as successful replays.

    python tools/check_new_bindings.py --bindings tools/golden_bindings.json \
        --only-new-since HEAD
    python tools/check_new_bindings.py --pc 0x8c064246 --pc 0x8c05027a
    python tools/check_new_bindings.py --report extract/analysis/replay_audit.json

The optional report records artifact digests and child results, not additional
coverage credit. Reported stream hashes use the captured text's UTF-8 bytes
(subprocess text mode normalizes newlines); timeout byte output is hashed as-is.
"""
from __future__ import annotations

import argparse
import csv
from datetime import datetime, timezone
import hashlib
import json
import os
import platform
import shlex
import subprocess
import sys
import tempfile
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
OUTPUT_LIMIT = 20 * 1024
# These flags are consumed with getenv(), so presence (even "0" or "") is the
# behavioral setting. Do not serialize arbitrary VF3_* values or the full env.
ENV_FLAGS = (
    "VF3_STRICT_REPLAY", "VF3_READABLE", "VF3_COMPLETE_CALLS", "VF3_REPLAY_OOB",
    "VF3_SCALEMAP_DBG", "VF3_DEBUG_STUB", "VF3_DEVLOG", "VF3_TRACE_ENTRIES",
    "VF3_GD_NOCLOCK", "VF3_GDTRACE", "VF3_TMU", "VF3_ASIC_FIRST", "VF3_ASIC_VBLANK",
)
ENV_PATHS = ("VF3_IMAGE", "VF3_GD_STATE", "VF3_TRACE")


class Fingerprints:
    """Hash each unchanged input once per report, including shared executables."""
    def __init__(self):
        self.cache = {}
        self.lock = threading.Lock()

    def file(self, path: Path) -> dict:
        record = {"path": str(path.resolve()), "size_bytes": None, "sha256": None}
        try:
            before = path.stat()
            record["size_bytes"] = before.st_size
            key = (str(path.resolve()), before.st_size, before.st_mtime_ns, before.st_ctime_ns)
            # Hold the lock while hashing: otherwise many parallel bindings
            # can hash the same large test binary at once on the first batch.
            with self.lock:
                if key not in self.cache:
                    digest = hashlib.sha256()
                    with path.open("rb") as stream:
                        for block in iter(lambda: stream.read(1024 * 1024), b""):
                            digest.update(block)
                    after = path.stat()
                    if (after.st_size, after.st_mtime_ns, after.st_ctime_ns) != key[1:]:
                        raise OSError("file changed while computing its digest")
                    self.cache[key] = digest.hexdigest()
                record["sha256"] = self.cache[key]
        except OSError as exc:
            record["error"] = str(exc)
        return record


def replay_environment(env: dict) -> dict:
    """Allowlisted behavior settings only; unknown names have no logged values."""
    return {
        "flags_present": {name: name in env for name in ENV_FLAGS},
        "paths": {name: env[name] for name in ENV_PATHS if name in env},
        "other_vf3_variable_names": sorted(name for name in env
            if name.startswith("VF3_") and name not in ENV_FLAGS + ENV_PATHS),
    }


def captured_output(value: str | bytes | None) -> dict:
    # TimeoutExpired may return bytes even with text=True. Full output hashes
    # let a saved external log be matched when the inline excerpt is capped.
    data = value if isinstance(value, bytes) else (value or "").encode("utf-8", errors="replace")
    excerpt = data[:OUTPUT_LIMIT].decode("utf-8", errors="replace").encode("utf-8")
    return {"text": excerpt[:OUTPUT_LIMIT].decode("utf-8", errors="ignore"),
            "bytes": len(data), "truncated": len(data) > OUTPUT_LIMIT,
            "sha256": hashlib.sha256(data).hexdigest()}


def report_metadata(bindings: Path, config: str | None, fingerprints: Fingerprints) -> dict:
    def git(*args):
        try:
            result = subprocess.run(["git", *args], capture_output=True, cwd=REPO, timeout=30)
            return result.stdout if result.returncode == 0 else None
        except (OSError, subprocess.TimeoutExpired):
            return None

    head, status, diff = git("rev-parse", "HEAD"), git("status", "--porcelain", "--untracked-files=no"), git("diff", "--binary", "HEAD")
    decode = lambda value: value.decode("utf-8", errors="replace").strip() if value is not None else None
    cache = REPO / "build" / "CMakeCache.txt"
    build = {"requested_config": config, "cmake_cache": None, "cmake_settings": {}}
    if cache.is_file():
        build["cmake_cache"] = fingerprints.file(cache)
        wanted = {"CMAKE_BUILD_TYPE", "CMAKE_C_COMPILER", "CMAKE_GENERATOR",
                  "CMAKE_GENERATOR_PLATFORM", "CMAKE_GENERATOR_TOOLSET", "CMAKE_MAKE_PROGRAM"}
        try:
            for line in cache.read_text(encoding="utf-8", errors="replace").splitlines():
                key = line.split(":", 1)[0]
                if key in wanted and "=" in line:
                    build["cmake_settings"][key] = line.split("=", 1)[1]
        except OSError as exc:
            build["error"] = str(exc)
    return {
        "repository": str(REPO.resolve()),
        "git": {"head": decode(head), "tracked_dirty": bool(status) if status is not None else None,
                "tracked_status": decode(status),
                "diff_from_head_sha256": hashlib.sha256(diff).hexdigest() if diff is not None else None},
        "host": {"system": platform.system(), "machine": platform.machine(), "python": platform.python_version()},
        "bindings_manifest": fingerprints.file(bindings),
        "runner_script": fingerprints.file(Path(__file__)), "build": build,
    }


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


def _run_binding(pc: str, spec: dict, config: str | None = None, *,
                 fingerprints: Fingerprints | None = None, environment: dict | None = None) -> dict:
    env = dict(os.environ if environment is None else environment)
    marked = bool(spec.get("strict")) if isinstance(spec, dict) else False
    if marked:
        env["VF3_STRICT_REPLAY"] = "1"
    detail = {"binding": pc, "strict_marked": marked,
              "strict_effective": "VF3_STRICT_REPLAY" in env,
              "argv": None, "golden": None, "executable": None,
              "exit_code": None, "duration_seconds": 0.0, "executed": False,
              "stdout": captured_output(None), "stderr": captured_output(None)}
    if fingerprints is not None:
        detail["environment"] = replay_environment(env)

    def done(status, tail=""):
        detail.update(status=status, tail=tail)
        return detail

    try:
        golden = REPO / spec["golden"]
        argv = test_arguments(spec)
        exe = resolve_test(argv[0], config=config)
    except (KeyError, TypeError, ValueError) as exc:
        return done("INVALID-BINDING", str(exc))
    if fingerprints is not None:
        detail["golden"] = fingerprints.file(golden)
        detail["executable"] = fingerprints.file(exe) if exe else {"requested": argv[0], "path": None, "sha256": None}
    if exe is None:
        return done("MISSING-TEST", argv[0])
    cmd = [str(exe)] + argv[1:] + [str(golden)]
    detail["argv"] = cmd
    if not golden.is_file():
        return done("MISSING-GOLDEN", str(golden))
    if golden.stat().st_size == 0:
        return done("EMPTY-GOLDEN", str(golden))
    started = time.perf_counter()
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, cwd=REPO,
                           timeout=900, env=env)
    except subprocess.TimeoutExpired as exc:
        detail.update(executed=True, stdout=captured_output(exc.stdout), stderr=captured_output(exc.stderr))
        return done("TIMEOUT")
    except OSError as exc:
        return done("EXEC-ERROR", str(exc))
    finally:
        detail["duration_seconds"] = round(time.perf_counter() - started, 6)
    detail.update(executed=True, exit_code=p.returncode,
                  stdout=captured_output(p.stdout), stderr=captured_output(p.stderr))
    lines = ((p.stdout or "") + (p.stderr or "")).strip().splitlines()
    tail = lines[-1] if lines else ""
    return done("PASS" if p.returncode == 0 else "FAIL", tail)


def run(pc: str, spec: dict, config: str | None = None) -> tuple[str, str, str]:
    """Compatibility API: callers still receive (binding, status, last line)."""
    detail = _run_binding(pc, spec, config)
    return pc, detail["status"], detail["tail"]


def run_detail(pc: str, spec: dict, config: str | None = None, *,
               fingerprints: Fingerprints | None = None, environment: dict | None = None) -> dict:
    detail = _run_binding(pc, spec, config,
                          fingerprints=fingerprints if fingerprints is not None else Fingerprints(),
                          environment=environment)
    detail["tail"] = detail["tail"][-2000:]
    return detail


def report_totals(results: list[dict]) -> dict:
    def group(rows):
        return {"total": len(rows), "executed": sum(row["executed"] for row in rows),
                "pass": sum(row["status"] == "PASS" for row in rows),
                "not_pass": sum(row["status"] != "PASS" for row in rows)}
    counts = {}
    for row in results:
        counts[row["status"]] = counts.get(row["status"], 0) + 1
    return {**group(results), "marked_strict": group([r for r in results if r["strict_marked"]]),
            "unmarked": group([r for r in results if not r["strict_marked"]]),
            "effective_strict": sum(row["strict_effective"] for row in results), "by_status": counts}


def write_report(path: Path, report: dict) -> None:
    """Replace the JSON atomically so an interrupted write is never a report."""
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(mode="w", encoding="utf-8", dir=path.parent,
                                         prefix=path.name + ".", suffix=".tmp", delete=False) as stream:
            temporary = Path(stream.name)
            json.dump(report, stream, indent=2, sort_keys=True, ensure_ascii=False, allow_nan=False)
            stream.write("\n")
        os.replace(temporary, path)
    finally:
        if temporary is not None:
            temporary.unlink(missing_ok=True)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--bindings", default="tools/golden_bindings.json")
    selection = ap.add_mutually_exclusive_group()
    selection.add_argument("--only-new-since", default="")
    selection.add_argument("--pc", action="append", default=[])
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--build-config", choices=["Debug", "Release", "RelWithDebInfo", "MinSizeRel"],
                    help="require this CMake configuration subdirectory; never fall back to build/ directly")
    ap.add_argument("--report", type=Path,
                    help="optional JSON audit report (relative paths are relative to the repository)")
    a = ap.parse_args(argv)
    if a.jobs < 1:
        ap.error("--jobs must be positive")
    report = None
    started = time.perf_counter()
    fingerprints = Fingerprints() if a.report else None
    environment = dict(os.environ) if a.report else None
    results = []
    if a.report:
        report = {
            "schema_version": 1, "started_at_utc": datetime.now(timezone.utc).isoformat(),
            "timeout_seconds_per_binding": 900, "output_limit_bytes_per_stream": OUTPUT_LIMIT,
            "workers": a.jobs, "selection": {"pc": a.pc, "only_new_since": a.only_new_since or None},
            "metadata": report_metadata(REPO / a.bindings, a.build_config, fingerprints),
            "inherited_environment": replay_environment(environment),
            "notes": ["PASS means the child returned zero; this report does not independently count replay cases.",
                      "Unmarked bindings retain their original semantics; inherited VF3_STRICT_REPLAY still applies.",
                      "A bounded output excerpt and the complete captured stream hash are stored for each stream."],
        }

    def finish(code: int, error: str | None = None) -> int:
        if report is not None:
            report.update(finished_at_utc=datetime.now(timezone.utc).isoformat(),
                          duration_seconds=round(time.perf_counter() - started, 6),
                          exit_code=code, results=results, totals=report_totals(results))
            report["outcome"] = "error" if error else ("no_replays" if not results else ("pass" if code == 0 else "fail"))
            if error:
                report["error"] = error
            try:
                write_report(REPO / a.report, report)
            except (OSError, ValueError) as exc:
                print(f"check_new_bindings: cannot write report: {exc}", file=sys.stderr)
                return 2
        return code

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
        return finish(2, str(exc))
    jobs = [(pc, spec) for pc, spec in cfg.items() if addresses[pc] in want]
    if not jobs:
        print(f"no new bindings since {a.only_new_since}; no replay executed")
        return finish(0)
    strict = sum(bool(spec.get("strict")) for _, spec in jobs)
    print(f"check_new_bindings: {len(jobs)} bindings ({strict} marked strict, "
          f"{len(jobs) - strict} unmarked), "
          f"{a.jobs} jobs", flush=True)
    fails = []
    with ThreadPoolExecutor(max_workers=a.jobs) as pool:
        if report is not None:
            replays = pool.map(lambda it: run_detail(*it, config=a.build_config,
                                                   fingerprints=fingerprints, environment=environment), jobs)
        else:
            replays = pool.map(lambda it: run(*it, config=a.build_config), jobs)
        for replay in replays:
            if report is not None:
                results.append(replay)
                pc, status, tail = replay["binding"], replay["status"], replay["tail"]
            else:
                pc, status, tail = replay
            if status != "PASS":
                fails.append((pc, status, tail))
                print(f"  {status:>12} {pc}: {tail[:110]}", flush=True)
    print(f"\n{len(jobs) - len(fails)}/{len(jobs)} PASS, {len(fails)} not-PASS")
    return finish(1 if fails else 0)


if __name__ == "__main__":
    sys.exit(main())
