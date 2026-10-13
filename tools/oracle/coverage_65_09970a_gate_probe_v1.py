#!/usr/bin/env python3
"""Generate an original-caller probe for the first gated block of 0x8c09970a."""
from __future__ import annotations

import argparse
import copy
import json
from pathlib import Path

from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
ENTRY = "0x8c0996f4"
TRIGGER = 0x8C0432E2
NAME = "coverage_65_09970a_gate_probe_v1"
MEMORY_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_memory.json"
REGISTER_SOURCE = ROOT / "tools/oracle/percentage_inputs/coverage_65_scene_remaining_screen_v1_registers.json"
WATCH = ROOT / "tools/oracle" / f"{NAME}_watch.txt"
PATCH = ROOT / "extract/analysis" / f"{NAME}.patch"


def build(variants: int) -> Path:
    if variants < 1:
        raise ValueError("variants must be positive")
    if WATCH.exists() or PATCH.exists():
        raise FileExistsError(f"refusing to overwrite {WATCH} or {PATCH}")

    memory = json.loads(MEMORY_SOURCE.read_text(encoding="utf-8-sig"))
    registers = json.loads(REGISTER_SOURCE.read_text(encoding="utf-8-sig"))
    fields = copy.deepcopy(memory[ENTRY])
    # 0x8c09970a tests *(0x0c29bcc4 + 0x39a) == 3, the 0x40000000 and
    # 0x4 bits in *(0x0c29bcc4 + 8), and byte *(0x0c29bcc4 + 25) == 2.
    # Keep neighboring bytes of the two byte fields from the screen baseline.
    fields.update({
        "0xc29bccc": 0x40000004,
        "0xc29bcdc": 0x00000200,
        "0xc29c05c": 0x02030000,
    })

    WATCH.write_text(f"pc {ENTRY}\n", encoding="ascii")
    try:
        generate(
            WATCH, PATCH, TRIGGER, variants,
            fpscr=0x40001,
            bounded_arguments=True,
            preserve_fields=True,
            register_overrides={ENTRY: registers[ENTRY]},
            memory_overrides={ENTRY: fields},
        )
    except BaseException:
        WATCH.unlink(missing_ok=True)
        PATCH.unlink(missing_ok=True)
        raise
    return PATCH


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--variants", type=int, default=64,
                        help="distinct seeds per state; default: 64")
    args = parser.parse_args()
    print(build(args.variants))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
