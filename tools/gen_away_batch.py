#!/usr/bin/env python3
"""
gen_away_batch.py - Generate a batch of off-inventory adapter modules.

This automates the full workflow:
1. Extract N away entries from offinv_entries.py
2. Generate adapter modules via translate_adapters.py
3. Update CMakeLists.txt with new source files
4. Update matrix_family.c with declarations and dispatch
5. Verify compilation

Usage:
    python tools/gen_away_batch.py 5          # Generate batch 5 (entries 80-99)
    python tools/gen_away_batch.py 6 --size 15 # Generate batch 6, 15 entries
    python tools/gen_away_batch.py --continue # Continue from last batch
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC_FIGHT = REPO / "src" / "fight"
BUILD = REPO / "build"
CMAKE = REPO / "CMakeLists.txt"
MATRIX_FAMILY = SRC_FIGHT / "matrix_family.py" if (SRC_FIGHT / "matrix_family.py").exists() else SRC_FIGHT / "matrix_family.c"
CAPTURE_DIR = "extract/analysis/advance_05b20e_dev_merged"
SPLIT_SIZE = 200


def run(cmd: list[str], cwd: Path = REPO, env=None, timeout=120) -> subprocess.CompletedProcess:
    """Run a command and return result."""
    print(f"+ {' '.join(cmd)}")
    return subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, env=env, timeout=timeout)


def get_away_entries() -> list[str]:
    """Get all away entries from offinv_entries.py."""
    result = run([sys.executable, "tools/offinv_entries.py"])
    if result.returncode != 0:
        raise RuntimeError(f"offinv_entries.py failed: {result.stderr}")

    away = []
    for line in result.stdout.splitlines():
        if line.strip().startswith("away   0x"):
            parts = line.strip().split()
            if len(parts) >= 2:
                away.append(parts[1])
    return away


def write_watch_file(batch_num: int, entries: list[str]) -> Path:
    """Write a watch file for the translator."""
    watch_file = BUILD / f"away_batch{batch_num}_watch.txt"
    content = "\n".join(f"pc {e}" for e in entries) + "\n"
    watch_file.write_text(content, encoding="utf-8")
    print(f"  Watch file: {watch_file} ({len(entries)} entries)")
    return watch_file


def update_cmake(batch_num: int, num_modules: int):
    """Add new source files to CMakeLists.txt."""
    content = CMAKE.read_text(encoding="utf-8")

    # Find the insertion point (before vf3_boot_adapter.c)
    marker = "src/fight/vf3_boot_adapter.c"
    idx = content.find(marker)
    if idx == -1:
        raise RuntimeError("Could not find insertion marker in CMakeLists.txt")

    # Generate new entries
    new_lines = [f"    src/fight/vf3_away_batch{batch_num}_adapter.c"]
    for i in range(num_modules):
        new_lines.append(f"    src/fight/vf3_away_batch{batch_num}_adapter_{i}.c")

    new_content = content[:idx] + "\n".join(new_lines) + "\n" + content[idx:]
    CMAKE.write_text(new_content, encoding="utf-8")
    print(f"  Updated CMakeLists.txt (+{num_modules + 1} entries)")


def run_translator(batch_num: int, watch_file: Path, split_size: int = 200) -> int:
    """Run translate_adapters.py for the batch."""
    out_file = SRC_FIGHT / f"vf3_away_batch{batch_num}_adapter.c"
    func_name = f"vf3_away_batch{batch_num}_adapter"

    result = run([
        sys.executable, "tools/oracle/translate_adapters.py",
        CAPTURE_DIR,
        "--watch", str(watch_file),
        "--out", str(out_file),
        "--function", func_name,
        "--split-size", str(split_size)
    ])

    if result.returncode != 0:
        raise RuntimeError(f"translate_adapters.py failed: {result.stderr}")

    # Count generated modules
    modules = 1
    for f in SRC_FIGHT.glob(f"vf3_away_batch{batch_num}_adapter_*.c"):
        modules += 1

    # Parse output for stats
    for line in result.stdout.splitlines():
        if "bounded source modules" in line:
            print(f"  {line.strip()}")
        if "guest statements" in line:
            print(f"  {line.strip()}")

    return modules


def update_matrix_family(batch_num: int):
    """Add declarations and dispatch to matrix_family.c."""
    content = MATRIX_FAMILY.read_text(encoding="utf-8")

    # 1. Add declarations (after previous batch's declaration)
    prev_batch = batch_num - 1
    ordinal_map = {1: "First", 2: "Second", 3: "Third", 4: "Fourth", 5: "Fifth",
                   6: "Sixth", 7: "Seventh", 8: "Eighth", 9: "Ninth", 10: "Tenth",
                   11: "Eleventh", 12: "Twelfth", 13: "Thirteenth", 14: "Fourteenth", 15: "Fifteenth"}
    prev_ordinal = ordinal_map.get(prev_batch, f"{prev_batch}th")
    decl_marker = f"/* {prev_ordinal} batch of off-inventory"
    if batch_num == 1:
        # Original file has vf3_gap_b07_adapter_contains as the last entry before boot adapters
        decl_marker = "int vf3_gap_b07_adapter_contains"

    idx = content.find(decl_marker)
    if idx == -1:
        raise RuntimeError(f"Could not find declaration marker: {decl_marker}")

    # Find the line after the previous batch's contains() declaration
    insert_idx = content.find("int vf3_boot_adapter", idx)
    if insert_idx == -1:
        raise RuntimeError("Could not find vf3_boot_adapter for declaration insertion")

    ordinal = {1: "First", 2: "Second", 3: "Third", 4: "Fourth", 5: "Fifth", 
               6: "Sixth", 7: "Seventh", 8: "Eighth", 9: "Ninth", 10: "Tenth",
               11: "Eleventh", 12: "Twelfth", 13: "Thirteenth", 14: "Fourteenth", 15: "Fifteenth"}.get(batch_num, f"{batch_num}th")
    decl_text = f"""\n/* {ordinal} batch of off-inventory entries translated from the image (no corpora). */
int vf3_away_batch{batch_num}_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_away_batch{batch_num}_adapter_contains(uint32_t);
"""
    content = content[:insert_idx] + decl_text + content[insert_idx:]

    # 2. Add dispatch (after previous batch's dispatch)
    dispatch_marker = f"if(vf3_away_batch{prev_batch}_adapter_contains(entry))"
    if batch_num == 1:
        dispatch_marker = "if(vf3_gap_b07_adapter_contains(entry))"

    print(f"  Dispatch: {dispatch_marker!r}")
    print(f"  Content length = {len(content)}")
    idx = content.find(dispatch_marker)
    print(f"  Found at idx = {idx}")
    if idx == -1:
        raise RuntimeError(f"Could not find dispatch marker: {dispatch_marker}")

    # Find the line after this dispatch
    insert_idx = content.find("\n", idx)
    insert_idx = content.find("\n", insert_idx + 1)  # Next line

    dispatch_text = f"        if(vf3_away_batch{batch_num}_adapter_contains(entry)) return vf3_away_batch{batch_num}_adapter(entry,s,ram);\n"
    content = content[:insert_idx] + dispatch_text + content[insert_idx:]

    MATRIX_FAMILY.write_text(content, encoding="utf-8")
    print(f"  Updated matrix_family.c (declaration + dispatch)")


def test_compile(batch_num: int, num_modules: int) -> bool:
    """Test compile a few modules."""
    env = __import__("os").environ.copy()
    env["PATH"] = r"C:\msys64\ucrt64\bin;C:\msys64\ucrt64\lib\gcc\x86_64-w64-mingw32\16.2.0;" + env["PATH"]

    test_indices = [0, 1, min(10, num_modules - 1), min(num_modules - 1, 25)]
    test_indices = [i for i in test_indices if i < num_modules]

    for i in test_indices:
        target = f"CMakeFiles/vf3core.dir/src/fight/vf3_away_batch{batch_num}_adapter_{i}.c.obj" if i > 0 else f"CMakeFiles/vf3core.dir/src/fight/vf3_away_batch{batch_num}_adapter.c.obj"
        result = run(["ninja", target], cwd=BUILD, env=env, timeout=60)
        if result.returncode != 0:
            print(f"  FAIL: {target}")
            print(f"  {result.stderr}")
            return False
        print(f"  OK: {target}")

    return True


def regenerate_cmake():
    """Re-run cmake to pick up new sources."""
    result = run(["cmake", ".."], cwd=BUILD)
    if result.returncode != 0:
        print(f"  Warning: cmake returned {result.returncode}")
    else:
        print("  CMake regenerated")


def main():
    ap = argparse.ArgumentParser(description="Generate off-inventory adapter batch")
    ap.add_argument("batch_num", type=int, nargs="?", help="Batch number (1-based)")
    ap.add_argument("--size", type=int, default=20, help="Entries per batch")
    ap.add_argument("--start", type=int, default=0, help="Start index (0-based)")
    ap.add_argument("--continue", dest="continue_batch", action="store_true", help="Auto-detect next batch")
    ap.add_argument("--no-cmake", action="store_true", help="Skip cmake regeneration")
    ap.add_argument("--no-test", action="store_true", help="Skip compilation test")
    ap.add_argument("--split-size", type=int, default=200, help="Split size for translator")
    args = ap.parse_args()

    # Determine batch number and start index
    if args.continue_batch:
        # Find highest existing batch
        existing = sorted(SRC_FIGHT.glob("vf3_away_batch*_adapter.c"))
        if existing:
            last = max(int(re.search(r"batch(\d+)", f.name).group(1)) for f in existing)
            batch_num = last + 1
            start_idx = batch_num * 20  # assuming 20 per batch
        else:
            batch_num = 1
            start_idx = 0
    elif args.batch_num:
        batch_num = args.batch_num
        start_idx = args.start or (batch_num - 1) * args.size
    else:
        ap.error("Specify batch number or --continue")

    print(f"\n=== Generating Batch {batch_num} (entries {start_idx}-{start_idx + args.size - 1}) ===")

    # Get away entries
    away = get_away_entries()
    print(f"Total away entries: {len(away)}")

    batch_entries = away[start_idx:start_idx + args.size]
    if not batch_entries:
        print("No entries for this batch")
        return 1

    # Write watch file
    watch_file = write_watch_file(batch_num, batch_entries)

    # Run translator
    num_modules = run_translator(batch_num, watch_file, args.split_size)

    # Update build system
    update_cmake(batch_num, num_modules)
    update_matrix_family(batch_num)

    # Regenerate cmake
    if not args.no_cmake:
        regenerate_cmake()

    # Test compile
    if not args.no_test:
        print("\nTesting compilation...")
        if not test_compile(batch_num, num_modules):
            print("Compilation test FAILED")
            return 1

    # Show gap reduction
    result = run([sys.executable, "tools/gap_holes.py"])
    for line in result.stdout.splitlines()[:5]:
        print(f"  {line}")

    print(f"\n[OK] Batch {batch_num} complete ({len(batch_entries)} entries, {num_modules} modules)")
    return 0


if __name__ == "__main__":
    sys.exit(main())