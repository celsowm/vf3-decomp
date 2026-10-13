#!/usr/bin/env python3
"""Build a rollback-scoped parent probe with a child-local gate fixture."""
from __future__ import annotations

import argparse
import copy
import json
from pathlib import Path

from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
NAME = "coverage_65_09970a_nested_probe_v3"
ROOT_ENTRY = "0x8c0996f4"
OWNER = 0x8C09970A
TRIGGER = 0x8C0432E2
MEMORY_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_memory.json"
REGISTER_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_registers.json"
GATES = ((0x0C29BCCC, 0x40000004),
         (0x0C29BCDC, 0x00000200),
         (0x0C29C05C, 0x02030000))


def build(directory: Path, variants: int) -> list[Path]:
    if variants < 1:
        raise ValueError("variants must be positive")
    watch = directory / f"{NAME}_watch.txt"
    seed_watch = directory / f"{NAME}_seed_watch.txt"
    entry_patch = directory / f"{NAME}.entry_patch"
    ram_patch = directory / f"{NAME}.ram_patch"
    recipe = directory / f"{NAME}.json"
    paths = (watch, seed_watch, entry_patch, ram_patch, recipe)
    if any(path.exists() for path in paths):
        raise FileExistsError("refusing to overwrite existing v3 probe artifacts")

    memory = json.loads(MEMORY_SOURCE.read_text(encoding="utf-8-sig"))
    registers = json.loads(REGISTER_SOURCE.read_text(encoding="utf-8-sig"))
    root_memory = copy.deepcopy(memory[ROOT_ENTRY])
    seed_watch.write_text(f"pc {ROOT_ENTRY}\n", encoding="ascii")
    try:
        generate(seed_watch, entry_patch, TRIGGER, variants,
                 fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
                 register_overrides={ROOT_ENTRY: registers[ROOT_ENTRY]},
                 memory_overrides={ROOT_ENTRY: root_memory})
    except BaseException:
        for path in paths:
            path.unlink(missing_ok=True)
        raise
    seed_watch.unlink()

    # The entry patch redirects only to ROOT_ENTRY. The second watched entry
    # is captured naturally inside that rollback-scoped parent probe.
    watch.write_text(f"pc {ROOT_ENTRY}\npc 0x{OWNER:08x}\n", encoding="ascii")
    ram_patch.write_text(
        "".join(f"0x{OWNER:08x} 0x{address:08x} 0x{value:08x}\n"
                for address, value in GATES),
        encoding="ascii")
    recipe.write_text(json.dumps({
        "schema": "coverage-65-09970a-nested-probe-v3",
        "diagnostic_only": True,
        "coverage_credit": False,
        "root": ROOT_ENTRY,
        "owner": f"0x{OWNER:08x}",
        "trigger": f"0x{TRIGGER:08x}",
        "variants": variants,
        "watch": watch.name,
        "entry_patch": entry_patch.name,
        "entry_ram_patch": ram_patch.name,
        "gate_values": [
            {"address": f"0x{address:08x}", "value": f"0x{value:08x}"}
            for address, value in GATES
        ],
        "caller_context": "typed synthetic root probes based on captured original-caller state; root inputs are not modified with owner gate values",
        "limitations": [
            "child RAM fixture is applied at owner entry and rolled back with the synthetic parent",
            "diagnostic reachability only; no varied owner inputs or complete behavioral proof",
            "requires nested-entry-fixture observer and --probe-children",
            "no coverage credit",
        ],
    }, indent=2) + "\n", encoding="utf-8")
    return [watch, entry_patch, ram_patch, recipe]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--directory", type=Path, default=Path(__file__).resolve().parent)
    parser.add_argument("--variants", type=int, default=64)
    args = parser.parse_args()
    for path in build(args.directory.resolve(), args.variants):
        print(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
