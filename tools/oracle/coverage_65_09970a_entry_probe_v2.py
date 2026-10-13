#!/usr/bin/env python3
"""Build an entry-local diagnostic RAM fixture for owner 0x8c09970a.

The owner is reached by original callers in the retained screen scenarios.
Unlike the v1 synthetic caller seed, these words are installed only when the
watched owner is entered, after caller setup has completed. This is diagnostic
only: the observer's entry fixture is not rolled back and earns no coverage.
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
NAME = "coverage_65_09970a_entry_probe_v2"
OWNER = 0x8C09970A
WORDS = (
    (0x0C29BCCC, 0x40000004),  # both bits tested by the owner
    (0x0C29BCDC, 0x00000200),  # byte at +1 becomes 2
    (0x0C29C05C, 0x02030000),  # byte at +2 becomes 3
)


def build(directory: Path) -> tuple[Path, Path, Path]:
    watch = directory / f"{NAME}_watch.txt"
    patch = directory / f"{NAME}.ram_patch"
    recipe = directory / f"{NAME}.json"
    if any(path.exists() for path in (watch, patch, recipe)):
        raise FileExistsError("refusing to overwrite an existing v2 probe artifact")
    watch.write_text(f"pc 0x{OWNER:08x}\n", encoding="ascii")
    patch.write_text(
        "".join(f"0x{OWNER:08x} 0x{addr:08x} 0x{value:08x}\n"
                for addr, value in WORDS),
        encoding="ascii",
    )
    recipe.write_text(json.dumps({
        "schema": "coverage-65-09970a-entry-probe-v2",
        "owner": f"0x{OWNER:08x}",
        "watch": watch.name,
        "ram_patch": patch.name,
        "patch_words": [
            {"entry": f"0x{OWNER:08x}", "address": f"0x{addr:08x}",
             "value": f"0x{value:08x}"}
            for addr, value in WORDS
        ],
        "purpose": "diagnostic branch reachability under natural owner calls",
        "limitations": [
            "the fixture mutates original RAM at owner entry and is not rolled back",
            "does not establish varied inputs, full-body replay, or held-state behavior",
            "no coverage credit",
        ],
    }, indent=2) + "\n", encoding="utf-8")
    return watch, patch, recipe


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--directory", type=Path, default=Path(__file__).resolve().parent)
    args = parser.parse_args()
    for path in build(args.directory.resolve()):
        print(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
