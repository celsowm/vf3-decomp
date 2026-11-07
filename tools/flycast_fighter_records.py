#!/usr/bin/env python3
"""Inspect live fighter attachment selectors in a Flycast savestate.

This offline evidence tool follows the two-level mode lookup and the 18
per-actor selectors used by 0x8c0b1550 / 0x8c0a7662. It reports source
addresses and raw descriptor words. It does not assign descriptors to bones,
POL slots, or motion channels.

Example:
  python tools/flycast_fighter_records.py tools/emu/flycast-build/data/vf3_27.state \
      --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c
"""

from __future__ import annotations

import argparse
from collections import Counter
import json
import math
from pathlib import Path
import struct
import sys

from aica_state import load_state
from flycast_ram import DEFAULT_IMAGE_ADDRESS, locate_ram, read_ram


MODE_TABLE = 0x0C10F6D0
DESCRIPTOR_TABLE = 0x0C2A1C3C
SELECTOR_OFFSET = 0x6C
ATTACHMENT_OFFSET = 0x180
ATTACHMENT_STRIDE = 0x40
ATTACHMENT_COUNT = 18
DEFAULT_RECORD_BYTES = 0x50
ADDRESS_MASK = 0x1FFFFFFF


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def u8(ram: bytes, address: int) -> int:
    return read_ram(ram, address, 1)[0]


def u32(ram: bytes, address: int) -> int:
    return struct.unpack("<I", read_ram(ram, address, 4))[0]


def raw_words(ram: bytes, address: int, size: int) -> list[str]:
    size -= size % 4
    data = read_ram(ram, address, size)
    return [f"0x{word:08x}" for (word,) in struct.iter_unpack("<I", data)]


def float_fields(words: list[str]) -> list[float | dict[str, str]]:
    result: list[float | dict[str, str]] = []
    for word in words:
        bits = int(word, 16)
        value = struct.unpack("<f", struct.pack("<I", bits))[0]
        if math.isfinite(value):
            result.append(value)
        else:
            kind = "nan" if math.isnan(value) else ("+inf" if value > 0 else "-inf")
            result.append({"non_finite": kind, "bits": word})
    return result


def descriptor(ram: bytes, table: int, selector: int, record_bytes: int) -> dict[str, object]:
    if selector == 0xFFFFFFFF:
        return {"selector": f"0x{selector:08x}", "status": "sentinel"}
    if selector >= (0x01000000 // 4):
        return {"selector": f"0x{selector:08x}", "status": "out_of_table_range"}
    cell = table + selector * 4
    try:
        pointer = u32(ram, cell)
        if pointer in (0, 0xFFFFFFFF):
            return {
                "selector": f"0x{selector:08x}",
                "table_cell": f"0x{cell:08x}",
                "pointer": f"0x{pointer:08x}",
                "status": "empty",
            }
        words = raw_words(ram, pointer, record_bytes)
        return {
            "selector": f"0x{selector:08x}",
            "table_cell": f"0x{cell:08x}",
            "pointer": f"0x{pointer:08x}",
            "status": "resolved",
            "header_words": words[:2],
            "word_offsets": [f"+0x{offset:02x}" for offset in range(0, len(words) * 4, 4)],
            "words": words,
            "float32_views": float_fields(words),
        }
    except ValueError as exc:
        return {
            "selector": f"0x{selector:08x}",
            "table_cell": f"0x{cell:08x}",
            "status": "unreadable",
            "error": str(exc),
        }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="retained Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact game image loaded at --image-address")
    parser.add_argument("--image-address", type=number, default=DEFAULT_IMAGE_ADDRESS,
                        help="SH-4 address of the image (default: 0x0c010000)")
    parser.add_argument("--actor", type=number, required=True,
                        help="actor record address from offline evidence")
    parser.add_argument("--selector-offset", type=number, default=SELECTOR_OFFSET,
                        help="actor offset of the selector array (default: 0x6c)")
    parser.add_argument("--attachment-offset", type=number, default=ATTACHMENT_OFFSET,
                        help="actor offset of 64-byte attachment records (default: 0x180)")
    parser.add_argument("--count", type=int, default=ATTACHMENT_COUNT,
                        help="number of selector/attachment entries (default: 18)")
    parser.add_argument("--entry", type=int, action="append",
                        help="report only this zero-based entry; may be repeated")
    parser.add_argument("--record-bytes", type=int, default=DEFAULT_RECORD_BYTES,
                        help="descriptor prefix to report; 4-byte aligned, up to 0x1000")
    parser.add_argument("--mode-table", type=number, default=MODE_TABLE,
                        help="mode-to-selector table address")
    parser.add_argument("--descriptor-table", type=number, default=DESCRIPTOR_TABLE,
                        help="selector-to-record-pointer table address")
    parser.add_argument("--json", action="store_true", help="emit JSON")
    args = parser.parse_args(argv)

    if not 1 <= args.count <= 64:
        parser.error("--count must be between 1 and 64")
    selected_entries = (list(range(args.count)) if args.entry is None
                        else sorted(set(args.entry)))
    if any(index < 0 or index >= args.count for index in selected_entries):
        parser.error(f"--entry values must be between 0 and {args.count - 1}")
    if not 4 <= args.record_bytes <= 0x1000 or args.record_bytes % 4:
        parser.error("--record-bytes must be 4-byte aligned and between 4 and 0x1000")

    try:
        image = args.image.read_bytes()
        blob = load_state(str(args.state))
        ram_offset, ram, anchor = locate_ram(blob, image, args.image_address, None)
        actor = args.actor
        mode = u8(ram, actor + 0x60)
        mode_cell = args.mode_table + mode * 4
        mode_selector = u32(ram, mode_cell)
        mode_descriptor = descriptor(ram, args.descriptor_table, mode_selector,
                                     args.record_bytes)

        entries: list[dict[str, object]] = []
        for index in selected_entries:
            selector_address = actor + args.selector_offset + index * 4
            selector = u32(ram, selector_address)
            attachment_address = actor + args.attachment_offset + index * ATTACHMENT_STRIDE
            entries.append({
                "entry": index,
                "selector_address": f"0x{selector_address:08x}",
                "attachment_address": f"0x{attachment_address:08x}",
                "attachment_words": raw_words(ram, attachment_address, ATTACHMENT_STRIDE),
                "descriptor": descriptor(ram, args.descriptor_table, selector,
                                          args.record_bytes),
            })

        resolved = [entry["descriptor"] for entry in entries
                    if entry["descriptor"].get("status") == "resolved"]
        header_counts = {
            f"word{word_index}": {
                value: count for value, count in sorted(Counter(
                    item["header_words"][word_index]
                    for item in resolved
                    if len(item["header_words"]) > word_index
                ).items())
            }
            for word_index in range(2)
        }

        report = {
            "diagnostic_only": True,
            "state": str(args.state),
            "ram_offset": f"0x{ram_offset:x}",
            "ram_anchor": anchor,
            "actor": f"0x{actor:08x}",
            "mode_byte_0x60": mode,
            "mode_table_cell": f"0x{mode_cell:08x}",
            "mode_selector": f"0x{mode_selector:08x}",
            "mode_descriptor": mode_descriptor,
            "selector_array": f"0x{actor + args.selector_offset:08x}",
            "attachment_array": f"0x{actor + args.attachment_offset:08x}",
            "entry_count": args.count,
            "selected_entries": selected_entries,
            "descriptor_header_counts": header_counts,
            "entries": entries,
            "notes": [
                "The 18 selector values are read as 32-bit words from actor+0x6c.",
                "Each selector indexes the pointer table at 0x0c2a1c3c.",
                "Attachment records are shown as raw 64-byte words from actor+0x180.",
                "Float32 views are alternate interpretations of raw descriptor words.",
                "--entry filters the report by zero-based attachment index.",
                "No descriptor field is assigned a bone, POL slot, or motion-channel meaning.",
            ],
        }
        if args.json:
            print(json.dumps(report, indent=2, allow_nan=False))
        else:
            print(f"{args.state}: RAM at 0x{ram_offset:x}; {anchor}")
            print(f"actor=0x{actor:08x} mode={mode} selector=0x{mode_selector:08x} "
                  f"entries={args.count}")
            print(f"mode descriptor: {mode_descriptor.get('pointer', mode_descriptor.get('status'))}")
            print(f"descriptor header counts: {header_counts}")
            for entry in entries:
                d = entry["descriptor"]
                assert isinstance(d, dict)
                print(f"  {entry['entry']:2d} selector={d['selector']} "
                      f"attachment={entry['attachment_address']} "
                      f"descriptor={d.get('pointer', d.get('status'))}")
        return 0
    except (OSError, ValueError, struct.error) as exc:
        print(f"flycast_fighter_records: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
