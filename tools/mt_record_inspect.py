#!/usr/bin/env python3
"""Inspect selected MT*.BIN records without changing the asset or runtime.

Examples:
  python tools/mt_record_inspect.py extract/gamedata/MTJACLAU.BIN 5093 5096
  python tools/mt_record_inspect.py extract/gamedata/MTJACLAU.BIN 5093 \
      --window 0x736:16 --window 0x7a4:16
  python tools/mt_record_inspect.py extract/gamedata/MTJACLAU.BIN 5093 \
      --file-window 0x3138:12

Window offsets are relative to each selected record. The output includes the
raw bytes and little-endian float words for quick format investigation; those
interpretations are diagnostic only and do not imply field semantics.
"""

from __future__ import annotations

import argparse
import math
import struct
import sys
from pathlib import Path

SLOT_COUNT = 8_880
PAYLOAD_FLOOR = SLOT_COUNT * 4


def parse_window(value: str) -> tuple[int, int]:
    try:
        offset_text, size_text = value.split(":", 1)
        offset = int(offset_text, 0)
        size = int(size_text, 0)
    except (ValueError, TypeError) as exc:
        raise argparse.ArgumentTypeError("expected OFFSET:SIZE, e.g. 0x736:16") from exc
    if offset < 0 or size <= 0:
        raise argparse.ArgumentTypeError("window offset must be nonnegative and size positive")
    return offset, size


def record_bounds(data: bytes) -> tuple[list[int], dict[int, int]]:
    if len(data) < PAYLOAD_FLOOR:
        raise ValueError(f"file is shorter than the {SLOT_COUNT}-entry slot table")
    slots = list(struct.unpack_from(f"<{SLOT_COUNT}I", data))
    offsets = sorted(set(offset for offset in slots if offset))
    if not offsets:
        raise ValueError("slot table has no nonzero records")
    for slot, offset in enumerate(slots):
        if offset and not PAYLOAD_FLOOR <= offset < len(data):
            raise ValueError(f"slot {slot} points outside the payload: 0x{offset:x}")
    ends = {
        offset: offsets[index + 1] if index + 1 < len(offsets) else len(data)
        for index, offset in enumerate(offsets)
    }
    return slots, ends


def describe_window(record: bytes, offset: int, size: int) -> str:
    if offset >= len(record):
        return f"  +0x{offset:04x}: <outside record>"
    end = min(offset + size, len(record))
    chunk = record[offset:end]
    suffix = " (truncated at record end)" if len(chunk) < size else ""
    lines = [f"  +0x{offset:04x}..+0x{end:04x}: {chunk.hex(' ')}{suffix}"]
    float_words = len(chunk) // 4
    if float_words:
        values = struct.unpack_from(f"<{float_words}f", chunk)
        rendered = [f"{value:.7g}" if math.isfinite(value) else repr(value)
                    for value in values]
        lines.append("    f32: " + ", ".join(rendered))
    return "\n".join(lines)


def describe_file_window(data: bytes, offset: int, size: int) -> str:
    if offset >= len(data):
        return f"file+0x{offset:06x}: <outside file>"
    end = min(offset + size, len(data))
    chunk = data[offset:end]
    suffix = " (truncated at file end)" if len(chunk) < size else ""
    lines = [f"file+0x{offset:06x}..+0x{end:06x}: {chunk.hex(' ')}{suffix}"]
    word_count = len(chunk) // 4
    if word_count:
        words = struct.unpack_from(f"<{word_count}I", chunk)
        lines.append("  u32: " + ", ".join(f"0x{word:08x}" for word in words))
        values = struct.unpack_from(f"<{word_count}f", chunk)
        rendered = [f"{value:.7g}" if math.isfinite(value) else repr(value)
                    for value in values]
        lines.append("  f32: " + ", ".join(rendered))
    return "\n".join(lines)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", type=Path, help="path to an extracted MT*.BIN asset")
    parser.add_argument("slots", nargs="+", type=lambda value: int(value, 0),
                        help="slot numbers (decimal or 0x-prefixed)")
    parser.add_argument("--window", action="append", type=parse_window, default=[],
                        metavar="OFFSET:SIZE",
                        help="record-relative byte window to display; may be repeated")
    parser.add_argument("--file-window", action="append", type=parse_window, default=[],
                        metavar="OFFSET:SIZE",
                        help="absolute file byte window to display; may be repeated")
    parser.add_argument("--prefix", type=lambda value: int(value, 0), default=48,
                        metavar="SIZE", help="number of leading bytes to display (default: 48)")
    args = parser.parse_args(argv)
    if args.prefix < 0:
        parser.error("--prefix must be nonnegative")

    try:
        data = args.file.read_bytes()
        slots, ends = record_bounds(data)
        for offset, size in args.file_window:
            print(describe_file_window(data, offset, size))
        for slot in args.slots:
            if not 0 <= slot < SLOT_COUNT:
                raise ValueError(f"slot {slot} is outside 0..{SLOT_COUNT - 1}")
            offset = slots[slot]
            if not offset:
                print(f"slot {slot}: empty")
                continue
            end = ends[offset]
            record = data[offset:end]
            print(f"slot {slot}: file=0x{offset:06x} size={len(record)} (0x{len(record):x})")
            if args.prefix:
                print(describe_window(record, 0, args.prefix))
            for window_offset, window_size in args.window:
                print(describe_window(record, window_offset, window_size))
    except (OSError, ValueError, struct.error) as exc:
        print(f"mt_record_inspect: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
