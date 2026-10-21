#!/usr/bin/env python3
"""Inventory local inputs needed to reproduce port checks; never run a check.

Exit 0: required files are present and the retail executable hash matches.
Exit 1: prerequisites missing/mismatched. Exit 2: malformed metadata/I/O error.
Presence is not validation: this tool does not certify coverage or playability.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from pathlib import Path

from check_new_bindings import binding_pc, normalize_pc, resolve_test, test_arguments

REPO = Path(__file__).resolve().parents[1]
RETAIL_SHA256 = "37f38dd9a47b785f526157c4a1674ca75322f0de1342f64bbf33c88d128e4b32"
NATIVE_STATES = (4, 5, 7, 9, 10, 11, 12, 13, 14, 15, 16, 37, 41)
BOOT_STATES = tuple(range(21, 31)) + (42, 43, 44, 45, 46)
COVERAGE_INPUTS = (
    "extract/analysis/funcs_1ST_READ.unsc.bin.csv",
    "extract/analysis/function_body_ranges.csv",
)
# Required per-row state read by the corresponding C replay runners.
# GBR, banked-register and device tapes remain optional in matrix_family.
SIDECAR_STRIDES = {
    "vf3matrixfamily": {".xfin.bin": 64, ".xfout.bin": 64, ".extra.bin": 16},
    "vf3bootmix": {".xfin.bin": 64, ".xfout.bin": 64},
    "vf3fd9ec": {".xfin.bin": 64, ".xfout.bin": 64},
    "vf3d452": {".xfin.bin": 64, ".xfout.bin": 64},
}


def present(root: Path, relative: str) -> bool:
    path = root / relative
    return path.is_file() and path.stat().st_size > 0


def inventory(root: Path, paths: list[str]) -> dict:
    unique = sorted(set(paths))
    missing = [p for p in unique if not present(root, p)]
    return {"required": len(unique), "present": len(unique) - len(missing),
            "missing": missing}


def hash_check(root: Path, relative: str) -> dict:
    result = {"path": relative, "expected_sha256": RETAIL_SHA256,
              "status": "missing", "actual_sha256": None}
    if present(root, relative):
        with (root / relative).open("rb") as f:
            digest = hashlib.file_digest(f, "sha256").hexdigest()
        result.update(actual_sha256=digest,
                      status="matches" if digest == RETAIL_SHA256 else "mismatch")
    return result


def case_dependencies(line: str) -> list[tuple[str, int]]:
    """Parse the shared C harness's v2 or fixed-two-window case layout.

    Return each named RAM blob and the minimum bytes the C reader consumes.
    Malformed/skipped rows are evidence gaps, even if a non-strict runner
    would skip them and still return success for other rows.
    """
    fields = line.split()
    if len(fields) < 78:
        raise ValueError("expected 74 register words and entry/exit RAM descriptors")
    if len(line.encode("utf-8")) >= 65536:
        raise ValueError("case row exceeds C harness line buffer")
    for token in fields[:74]:
        if not 0 <= int(token, 16) <= 0xFFFFFFFF:
            raise ValueError("register word outside uint32 range")
    cursor = 74
    dependencies = []
    for kind in ("entry", "exit"):
        if cursor + 1 >= len(fields):
            raise ValueError(f"missing {kind} RAM descriptor")
        name, token = fields[cursor:cursor + 2]
        cursor += 1
        if token.startswith(("0x", "-")):
            count = 2                 # legacy: no explicit count token
        else:
            count = int(token, 10)
            cursor += 1
        if not 0 <= count <= 128 or cursor + count * 2 > len(fields):
            raise ValueError(f"invalid {kind} RAM window count")
        size = 0
        for _ in range(count):
            base_token, length_token = fields[cursor:cursor + 2]
            base = 0 if base_token == "-" else int(base_token, 16)
            length = 0 if length_token == "-" else int(length_token, 16)
            if not 0 <= base <= 0xFFFFFFFF or not 0 <= length <= 0xFFFFFFFF:
                raise ValueError("RAM window outside uint32 range")
            if base and length:        # C harness drops padding windows
                size += length
            cursor += 2
        if name != "-":
            if not size:
                raise ValueError(f"named {kind} RAM blob has no windows")
            dependencies.append((name, size))
        elif kind == "entry":
            raise ValueError("no entry RAM shadow; C harness would skip this row")
    if cursor != len(fields):
        raise ValueError("unexpected trailing case fields")
    return dependencies


def sized_inventory(root: Path, sizes: dict[str, int]) -> dict:
    result = inventory(root, list(sizes))
    result["short"] = []
    for path, minimum in sorted(sizes.items()):
        if present(root, path) and (actual := (root / path).stat().st_size) < minimum:
            result["short"].append({"path": path, "minimum_bytes": minimum, "actual_bytes": actual})
    return result


def case_evidence(root: Path, cfg: dict) -> dict:
    cases = sorted({spec["golden"] for spec in cfg.values() if spec["golden"].lower().endswith(".cases")})
    sidecar_requirements: dict[str, dict[str, int]] = {}
    sidecar_runners = set()
    for spec in cfg.values():
        if not spec["golden"].lower().endswith(".cases"):
            continue
        runner = Path(test_arguments(spec)[0].replace("\\", "/")).name.lower().removesuffix(".exe")
        if runner in SIDECAR_STRIDES:
            sidecar_runners.add(runner)
            requirements = sidecar_requirements.setdefault(spec["golden"], {})
            for suffix, stride in SIDECAR_STRIDES[runner].items():
                requirements[suffix] = max(stride, requirements.get(suffix, 0))
    sidecar_sizes = {}
    for path, requirements in sidecar_requirements.items():
        for suffix in requirements:
            sidecar_sizes[Path(path).with_suffix(suffix).as_posix()] = 1
    ram_sizes: dict[str, int] = {}
    errors = []
    parsed_files = 0
    for relative in cases:
        if not present(root, relative):
            continue
        path = root / relative
        rows = 0
        try:
            with path.open(encoding="utf-8") as f:
                for number, line in enumerate(f, 1):
                    try:
                        dependencies = case_dependencies(line)
                    except ValueError as exc:
                        errors.append({"path": relative, "line": number, "error": str(exc)})
                        continue
                    rows += 1
                    for blob, minimum in dependencies:
                        target = path.parent / blob
                        name = target.relative_to(root).as_posix() if target.is_relative_to(root) else target.as_posix()
                        ram_sizes[name] = max(minimum, ram_sizes.get(name, 0))
            parsed_files += 1
            if not rows:
                errors.append({"path": relative, "line": None, "error": "no parseable RAM cases"})
            for suffix, stride in sidecar_requirements.get(relative, {}).items():
                sidecar_sizes[Path(relative).with_suffix(suffix).as_posix()] = max(1, rows * stride)
        except (OSError, UnicodeError) as exc:
            errors.append({"path": relative, "line": None, "error": str(exc)})
    return {"case_files": len(cases), "parsed_files": parsed_files, "parse_errors": errors,
            # Keep the schema-v1 key for existing report consumers. It now
            # includes all listed runners' mandatory XF/extra sidecars.
            "matrix_sidecars": sized_inventory(root, sidecar_sizes),
            "sidecar_runners": sorted(sidecar_runners),
            "ram_blobs": sized_inventory(root, ram_sizes)}


def inspect(root: Path, config: str | None = None,
            bindings: str | Path = "tools/golden_bindings.json") -> dict:
    root = root.resolve()
    manifest = (root / bindings).resolve()
    raw = json.loads(manifest.read_text(encoding="utf-8"))
    if not isinstance(raw, dict) or not raw:
        raise ValueError(f"bindings manifest must be a nonempty object: {manifest}")
    cfg = {pc.lower(): spec for pc, spec in raw.items()}
    if len(cfg) != len(raw):
        raise ValueError("duplicate case-insensitive binding keys")
    addresses = {binding_pc(key) for key in cfg}
    for spec in cfg.values():
        if not isinstance(spec, dict) or not isinstance(spec.get("golden"), str) or not spec["golden"]:
            raise ValueError("every binding needs a nonempty golden path")
    with (root / "docs/decomp_status.csv").open(newline="", encoding="utf-8") as f:
        rows = list(csv.DictReader(f))
    if rows and not {"entry", "status"}.issubset(rows[0]):
        raise ValueError("ledger must have entry and status columns")
    ported = [normalize_pc(row["entry"]) for row in rows if row["status"].startswith("ported")]
    golden = inventory(root, [spec["golden"] for spec in cfg.values()])
    golden["bindings_with_present_file"] = sum(present(root, s["golden"]) for s in cfg.values())
    evidence = case_evidence(root, cfg)
    commands = sorted({test_arguments(spec)[0] for spec in cfg.values()} | {"build/vf3", "build/vf3boot"})
    executables = []
    for command in commands:
        try:
            path = resolve_test(command, root, config)
            executables.append({"command": command, "status": "present" if path else "missing",
                                "resolved": path.relative_to(root).as_posix() if path and path.is_relative_to(root) else path.as_posix() if path else None})
        except ValueError as exc:
            executables.append({"command": command, "status": "ambiguous", "error": str(exc)})
    native_paths = [f"extract/analysis/{pattern.format(n=n)}" for n in NATIVE_STATES
                    for pattern in ("golden_tickx_vf3_{n}.bin", "oracle_tick_s{n}.bin", "flycast_exit_s{n}.bin")]
    boot_paths = [f"extract/analysis/golden_bootV_vf3_{n}.bin" for n in BOOT_STATES]
    boot_paths += ["extract/analysis/golden_bootI_vf3_30.bin", "extract/analysis/golden_bootS_vf3_30.bin"]
    gd_missing = []
    for n in BOOT_STATES:
        alternatives = [f"extract/analysis/gdstate_s{n}_0c0432de.txt", f"extract/analysis/gd_state/vf3_{n}.txt"]
        if not any(present(root, p) for p in alternatives):
            gd_missing.append({"state": n, "one_of": alternatives})
    coverage = inventory(root, list(COVERAGE_INPUTS))
    native = inventory(root, native_paths)
    boot = inventory(root, boot_paths)
    rom = [hash_check(root, path) for path in
           ("extract/gamedata/1ST_READ.BIN", "extract/exe/1ST_READ.unsc.bin")]
    gdi = present(root, "rom/vf3.gdi")
    ready = (all(not group["missing"] for group in (golden, coverage, native, boot))
             and not gd_missing and gdi and all(x["status"] == "matches" for x in rom)
             and not evidence["parse_errors"]
             and all(not evidence[group]["missing"] and not evidence[group]["short"]
                     for group in ("matrix_sidecars", "ram_blobs"))
             and all(x["status"] == "present" for x in executables))
    return {
        "schema_version": 1, "root": root.as_posix(), "prerequisites_present": ready,
        "bindings_manifest": manifest.relative_to(root).as_posix() if manifest.is_relative_to(root) else manifest.as_posix(),
        "checks_executed": False,
        "limits": [
            "File presence does not validate file format, provenance, replay results, or 1:1 behavior.",
            "Parsed .cases RAM blobs and mandatory runner extended-state files are inventoried, not replayed.",
            "Optional GBR/banked/device tapes, capsules and independent holdouts still need provenance and behavioral validation.",
            "Coverage needs the original frozen function inventory/ranges; a new Ghidra analysis may change its denominator.",
            "No coverage percentage is recomputed or certified by this preflight.",
            "The GDI presence check does not validate its tracks; use prepare_rom.py for disc identity.",
        ],
        "ledger": {"rows": len(rows), "ported_rows": len(ported), "unique_ported_entries": len(set(ported)),
                   "duplicate_ported_rows": len(ported) - len(set(ported)),
                   "status_counts": {status: sum(row["status"] == status for row in rows)
                                     for status in sorted({row["status"] for row in rows})}},
        "bindings": {"total": len(cfg), "marked_strict": sum(bool(s.get("strict")) for s in cfg.values()),
                     "unique_entry_addresses": len(addresses),
                     "unmarked": sum(not bool(s.get("strict")) for s in cfg.values()), "golden_files": golden,
                     "case_evidence": evidence},
        "coverage_inputs": coverage,
        "native_tick": {"states": list(NATIVE_STATES), **native},
        "boot": {"states": list(BOOT_STATES), **boot, "missing_gd_states": gd_missing},
        "rom": {"gdi_present": gdi, "executables": rom},
        "test_executables": executables,
        "capture_regeneration": {
            "emulator_tree_present": (root / "tools/emu").is_dir(),
            "recompiler_tree_present": (root / "refs/dream-recomp").is_dir(),
            "note": "Optional for replaying supplied captures; regeneration needs pinned sources, build recipes and savestates.",
        },
    }


def print_summary(report: dict) -> None:
    print("Prerequisite inventory only; no replay or coverage validation executed.")
    print("Required inputs: " + ("PRESENT" if report["prerequisites_present"] else "INCOMPLETE"))
    ledger, bindings = report["ledger"], report["bindings"]
    print(f"Ledger: {ledger['unique_ported_entries']} unique ported entries; {ledger['duplicate_ported_rows']} duplicate rows")
    print(f"Bindings: {bindings['total']}; {bindings['marked_strict']} marked strict; {bindings['unmarked']} unmarked")
    for name, data in (("Golden files", bindings["golden_files"]), ("Coverage inputs", report["coverage_inputs"]),
                       ("Native tick captures/references", report["native_tick"]), ("Boot captures", report["boot"])):
        print(f"{name}: {data['present']}/{data['required']} present")
        for path in data["missing"][:3]:
            print(f"  missing: {path}")
    print(f"Boot GD states missing: {len(report['boot']['missing_gd_states'])}")
    evidence = bindings["case_evidence"]
    for label, group in (("Required runner sidecars", "matrix_sidecars"), ("Referenced RAM blobs", "ram_blobs")):
        item = evidence[group]
        print(f"{label}: {item['present']}/{item['required']} present; {len(item['short'])} too short")
    print(f"Case parse errors: {len(evidence['parse_errors'])}; RAM dependencies cannot be inventoried for absent case files")
    print(f"GDI descriptor present: {report['rom']['gdi_present']}")
    for item in report["rom"]["executables"]:
        print(f"Retail hash: {item['status']}: {item['path']}")
    missing_tests = [item for item in report["test_executables"] if item["status"] != "present"]
    print(f"Test executables unavailable/ambiguous: {len(missing_tests)}")
    print("Use --json for all paths and scope limits. Required files present does not mean tests passed.")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=REPO)
    ap.add_argument("--bindings", type=Path, default=Path("tools/golden_bindings.json"),
                    help="binding manifest, absolute or relative to --root (default: tools/golden_bindings.json)")
    ap.add_argument("--json", action="store_true", help="print full machine-readable inventory")
    ap.add_argument("--build-config", choices=["Debug", "Release", "RelWithDebInfo", "MinSizeRel"])
    args = ap.parse_args(argv)
    try:
        report = inspect(args.root, args.build_config, bindings=args.bindings)
    except (OSError, ValueError, KeyError, TypeError) as exc:
        print(f"port_preflight: {exc}", file=sys.stderr)
        return 2
    if args.json:
        print(json.dumps(report, indent=2))
    else:
        print_summary(report)
    return 0 if report["prerequisites_present"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
