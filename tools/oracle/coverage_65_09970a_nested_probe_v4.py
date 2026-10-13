#!/usr/bin/env python3
"""Build corrected rollback-scoped parent and child gate probes for 09970a."""
from __future__ import annotations

import argparse
import copy
import json
from pathlib import Path

from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
NAME = "coverage_65_09970a_nested_probe_v4"
ROOT_ENTRY = "0x8c0996f4"
OWNER = 0x8C09970A
TRIGGER = 0x8C0432E2
MEMORY_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_memory.json"
REGISTER_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_registers.json"
GATES = ((0x0C29BCCC, 0x40000004),
         (0x0C29BCDC, 0x00000200),
         (0x0C29BCEC, 0x00000300))


def build(directory: Path, variants: int, name: str = NAME,
          watch_callback: bool = False, open_callback: bool = False,
          clear_flag_gates: bool = False,
          branch_state: str = "open-special") -> list[Path]:
    if variants < 1:
        raise ValueError("variants must be positive")
    if branch_state not in ("open-special", "alternate-event"):
        raise ValueError("branch_state must be open-special or alternate-event")
    watch = directory / f"{name}_watch.txt"
    seed_watch = directory / f"{name}_seed_watch.txt"
    entry_patch = directory / f"{name}.entry_patch"
    ram_patch = directory / f"{name}.ram_patch"
    recipe = directory / f"{name}.json"
    paths = (watch, seed_watch, entry_patch, ram_patch, recipe)
    if any(path.exists() for path in paths):
        raise FileExistsError("refusing to overwrite existing v4 probe artifacts")

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

    # The synthetic redirect targets only the parent. The owner is watched as
    # an actual child and seeded by VF3_RAM_PATCH only at its own entry.
    watched = [ROOT_ENTRY, f"0x{OWNER:08x}"]
    if watch_callback:
        watched.append("0x0c0c66b8")
    watch.write_text("".join(f"pc {entry}\n" for entry in watched), encoding="ascii")
    gate_words = GATES + (((0x0C11E514, 0x3F010001),) if open_callback else ())
    if clear_flag_gates:
        gate_words = ((0x0C29BCCC, 0),) + gate_words[1:]
    if branch_state == "alternate-event":
        # At +0x29 the owner takes the alternate event path when the byte is 1;
        # +0x1d must be nonzero to pass the first guard in that block.
        gate_words = tuple((address, 0x00000100 if address == 0x0C29BCEC else value)
                           for address, value in gate_words)
        gate_words += ((0x0C29BCE0, 0x00000100),)
    ram_patch.write_text(
        "".join(f"0x{OWNER:08x} 0x{address:08x} 0x{value:08x}\n"
                for address, value in gate_words),
        encoding="ascii")
    recipe.write_text(json.dumps({
        "schema": f"coverage-65-09970a-nested-probe-{name.rsplit('_', 1)[-1]}",
        "diagnostic_only": True,
        "coverage_credit": False,
        "root": ROOT_ENTRY,
        "owner": f"0x{OWNER:08x}",
        "trigger": f"0x{TRIGGER:08x}",
        "variants": variants,
        "watch": watch.name,
        "entry_patch": entry_patch.name,
        "entry_ram_patch": ram_patch.name,
        "callback_watched": watch_callback,
        "callback_byte_seeded": open_callback,
        "gate_values": [
            {"address": f"0x{address:08x}", "value": f"0x{value:08x}"}
            for address, value in gate_words
        ],
        "branch_contract": {
            "0x0c29bced": "equals 3; seeded by aligned word 0x0c29bcec",
            "0x0c29bccc": "must not overlap 0x40000000 or 0x4; both TST/BF gates skip when these bits are set",
            "0x0c29bcdd": "equals 2; seeded by aligned word 0x0c29bcdc",
            "callback": "0x0c0c66b8 reads byte 0x0c11e517 from the literal pointer 0x0c11e504 plus 19",
            "callback_seed": "when requested, word 0x0c11e514 is set to 0x3f010001 so byte 0x0c11e517 is nonzero",
        "flag_gate_seed": "when requested, clear bits 0x40000000 and 0x4 by setting 0x0c29bccc to zero",
        "branch_state": branch_state,
        },
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
    parser.add_argument("--name", default=NAME,
                        help="artifact basename (defaults to the checked-in v4 campaign)")
    parser.add_argument("--watch-callback", action="store_true",
                        help="also capture callback 0x0c0c66b8 register and RAM inputs")
    parser.add_argument("--open-callback", action="store_true",
                        help="seed the observed callback byte at 0x0c11e517")
    parser.add_argument("--clear-flag-gates", action="store_true",
                        help="clear the two bits whose TST/BF sequence skips the branch when set")
    parser.add_argument("--branch-state", choices=("open-special", "alternate-event"),
                        default="open-special",
                        help="owner byte+0x29 selector (alternate-event selects value 1)")
    args = parser.parse_args()
    for path in build(args.directory.resolve(), args.variants, args.name,
                      args.watch_callback, args.open_callback,
                      args.clear_flag_gates, args.branch_state):
        print(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
