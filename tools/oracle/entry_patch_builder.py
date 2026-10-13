#!/usr/bin/env python3
"""Build round-robin VF3_ENTRY_PATCH fixtures from a small typed JSON recipe."""
from __future__ import annotations

import argparse
import json
from pathlib import Path


REGISTERS = {*(f"r{index}" for index in range(16)),
             *(f"fr{index}" for index in range(16)),
             *(f"xf{index}" for index in range(16)), "pr", "gbr", "fpul",
             "fpscr", "sr", "macl", "mach"}


def number(value, label: str) -> int:
    try:
        result = int(value, 0) if isinstance(value, str) else int(value)
    except (TypeError, ValueError) as error:
        raise ValueError(f"{label} must be an integer or base-prefixed string") from error
    if not 0 <= result <= 0xFFFFFFFF:
        raise ValueError(f"{label} is outside uint32 range")
    return result


def build(recipe: dict) -> str:
    trigger = number(recipe.get("trigger_pc"), "trigger_pc")
    target = number(recipe.get("target_pc"), "target_pc")
    variants = recipe.get("variants")
    if not isinstance(variants, list) or not variants:
        raise ValueError("variants must be a nonempty list")
    pr_offset = recipe.get("pr_offset")
    if pr_offset is not None:
        pr_offset = number(pr_offset, "pr_offset")
        if trigger + pr_offset > 0xFFFFFFFF:
            raise ValueError("trigger_pc + pr_offset overflows uint32")

    lines = [f"# Generated entry probe: trigger=0x{trigger:08x} target=0x{target:08x}",
             f"entry 0x{trigger:08x} 0x{target:08x}"]
    for index, variant in enumerate(variants):
        if not isinstance(variant, dict):
            raise ValueError(f"variant {index} must be an object")
        if index:
            lines.append(f"seed 0x{trigger:08x}")
        registers = variant.get("registers", {})
        memory = variant.get("memory", {})
        if not isinstance(registers, dict) or not isinstance(memory, dict):
            raise ValueError(f"variant {index}: registers and memory must be objects")
        normalized = {}
        for name, value in registers.items():
            name = str(name).lower()
            if name not in REGISTERS:
                raise ValueError(f"variant {index}: invalid register {name!r}")
            if name == "pr" and pr_offset is not None:
                raise ValueError(f"variant {index}: PR is supplied by pr_offset")
            normalized[name] = number(value, f"variant {index} {name}")
        if pr_offset is not None:
            lines.append(f"reg 0x{trigger:08x} pr 0x{trigger + pr_offset:08x}")
        # FPSCR selects the FR/XF banks, so apply it before their named bits.
        ordered = sorted(normalized, key=lambda name: (name != 'fpscr', name))
        for name in ordered:
            value = normalized[name]
            lines.append(f"reg 0x{trigger:08x} {name} 0x{value:08x}")
        for address, value in sorted(memory.items(), key=lambda item: number(item[0], "RAM address")):
            address = number(address, f"variant {index} RAM address")
            if address & 3 or not 0x0C000000 <= address <= 0x0CFFFFFC:
                raise ValueError(f"variant {index}: invalid aligned RAM address 0x{address:08x}")
            value = number(value, f"variant {index} RAM value")
            lines.append(f"ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}")
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("recipe", type=Path)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    recipe = json.loads(args.recipe.read_text(encoding="utf-8"))
    patch = build(recipe)
    args.out.write_text(patch, encoding="ascii")
    print(f"wrote {len(recipe['variants'])} round-robin variants to {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
