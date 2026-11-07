#!/usr/bin/env python3
"""Inspect DTPK package headers and section ranges.

With no paths, scan ``extract/gamedata``. Explicit files and directories are
also accepted. The report goes to stdout unless ``--output`` is supplied;
this tool never writes to repository documentation implicitly.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path
from typing import Any


REPO = Path(__file__).resolve().parent.parent
MAGIC = b"DTPK"
HEADER_SIZE = 0x60
SECTION_SLOTS = 16


def analyze(path: Path) -> dict[str, Any] | None:
    """Return parsed package metadata, None for non-DTPK files.

    Raises ValueError when a DTPK signature is present but its declared size
    or section directory is malformed.
    """
    data = path.read_bytes()
    if data[:4] != MAGIC:
        return None
    if len(data) < HEADER_SIZE:
        raise ValueError(f"{path}: DTPK header is shorter than 0x60 bytes")

    serial, declared_size, reserved, tag, version, bus_size, reserved2 = (
        struct.unpack_from("<7I", data, 4)
    )
    if declared_size != len(data):
        raise ValueError(
            f"{path}: header size 0x{declared_size:x} does not match "
            f"file size 0x{len(data):x}"
        )

    directory = struct.unpack_from(f"<{SECTION_SLOTS}I", data, 0x20)
    sections: list[dict[str, int]] = []
    for slot, offset in enumerate(directory):
        if offset == 0:
            continue
        if offset < HEADER_SIZE or offset >= len(data):
            raise ValueError(f"{path}: section slot {slot} offset 0x{offset:x} is out of range")
        if sections and offset <= sections[-1]["offset"]:
            raise ValueError(f"{path}: nonzero section offsets are not strictly increasing")
        sections.append({"slot": slot, "offset": offset})

    if not sections or sections[0]["offset"] != HEADER_SIZE:
        raise ValueError(f"{path}: first section offset must be 0x60")
    for index, section in enumerate(sections):
        end = sections[index + 1]["offset"] if index + 1 < len(sections) else len(data)
        section["size"] = end - section["offset"]

    return {
        "file": str(path),
        "serial": serial,
        "size": len(data),
        "tag": tag,
        "version": version,
        "bus_size": bus_size,
        "reserved": reserved,
        "reserved2": reserved2,
        "sections": sections,
    }


def input_files(paths: list[Path]) -> list[Path]:
    roots = paths or [REPO / "extract" / "gamedata"]
    result: list[Path] = []
    seen: set[Path] = set()
    for root in roots:
        if not root.exists():
            raise FileNotFoundError(root)
        candidates = sorted(root.rglob("*") if root.is_dir() else [root])
        for candidate in candidates:
            if not candidate.is_file():
                continue
            resolved = candidate.resolve()
            if resolved not in seen:
                seen.add(resolved)
                result.append(candidate)
    return result


def render_table(rows: list[dict[str, Any]]) -> str:
    lines = [
        f"DTPK packages: {len(rows)}",
        "| file | serial | size | tag | sections (slot:offset+size) |",
        "|---|---:|---:|---:|---|",
    ]
    for row in rows:
        sections = ", ".join(
            f"{item['slot']}:0x{item['offset']:x}+0x{item['size']:x}"
            for item in row["sections"]
        )
        lines.append(
            f"| {Path(row['file']).name} | {row['serial']} | {row['size']} "
            f"| 0x{row['tag']:08x} | {sections} |"
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "paths", nargs="*", type=Path,
        help="DTPK files or directories (default: scan extract/gamedata)",
    )
    parser.add_argument("--json", action="store_true", help="emit JSON instead of a table")
    parser.add_argument(
        "--output", type=Path,
        help="write the report to this explicit path (default: stdout)",
    )
    args = parser.parse_args()

    try:
        rows = []
        for path in input_files(args.paths):
            result = analyze(path)
            if result is not None:
                rows.append(result)
    except (OSError, ValueError) as exc:
        print(exc, file=sys.stderr)
        return 2

    report = json.dumps(rows, indent=2) + "\n" if args.json else render_table(rows)
    if args.output:
        args.output.write_text(report, encoding="utf-8", newline="\n")
    else:
        sys.stdout.write(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
