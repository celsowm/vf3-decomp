#!/usr/bin/env python3
"""Inspect raw POL slot payloads without assigning model or rig semantics.

The POL scene parser covers tagged geometry. This read-only inspector keeps
untagged and tagged slot identities, bounds each payload at the next distinct
slot target, and displays its leading little-endian words with in-file target
candidates. It is intended for offline format research, not runtime loading.

Examples:
  python tools/pol_slot_inspect.py extract/gamedata/MKAO_AKI.POL
  python tools/pol_slot_inspect.py extract/gamedata/MKAO_JAC.POL --slot 0 --slot 2 --words 16
  python tools/pol_slot_inspect.py extract/gamedata/MKAO_AKI.POL --all
"""

from __future__ import annotations

import argparse
from collections import defaultdict
from pathlib import Path
import struct
import sys


def file_range(text: str) -> tuple[int, int]:
    try:
        offset_text, size_text = text.split(":", 1)
        offset = int(offset_text, 0)
        size = int(size_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            "expected OFFSET:SIZE, e.g. 0x1d4:0x40") from exc
    if offset < 0 or size <= 0 or offset > 0xFFFFFFFF or size > 0x100000:
        raise argparse.ArgumentTypeError(
            "range must use a 32-bit offset and size 1..1 MiB")
    return offset, size


def inspect(data: bytes, selected_slots: set[int] | None = None,
            tagged: bool | None = False, word_count: int = 8,
            show_floats: bool = False,
            find_slot_references: bool = False,
            context_before: int = 0) -> list[dict[str, object]]:
    if len(data) < 0x30:
        raise ValueError("file is shorter than the 0x30-byte POL header")
    slot_count = struct.unpack_from("<H", data, 0x0C)[0]
    slot_offset = struct.unpack_from("<I", data, 0x10)[0]
    if slot_offset > len(data) or slot_count * 4 > len(data) - slot_offset:
        raise ValueError("slot table exceeds the file")

    slots = [struct.unpack_from("<I", data, slot_offset + index * 4)[0]
             for index in range(slot_count)]
    aliases: dict[int, list[int]] = defaultdict(list)
    for index, raw in enumerate(slots):
        if raw:
            target = raw & ~1
            if target < 0x30 or target >= len(data):
                raise ValueError(f"slot {index} target 0x{target:x} is outside the file")
            aliases[target].append(index)
    tagged_targets = {
        target: [slot for slot in slot_ids if slots[slot] & 1]
        for target, slot_ids in aliases.items()
    }
    tagged_targets = {target: ids for target, ids in tagged_targets.items() if ids}

    targets = sorted(aliases)
    ends = {target: targets[i + 1] if i + 1 < len(targets) else len(data)
            for i, target in enumerate(targets)}
    output: list[dict[str, object]] = []
    for target in targets:
        end = ends[target]
        slot_ids = aliases[target]
        tagged_slots = [slot for slot in slot_ids if slots[slot] & 1]
        untagged_slots = [slot for slot in slot_ids if not slots[slot] & 1]
        if tagged is True and not tagged_slots:
            continue
        if tagged is False and not untagged_slots:
            continue
        if selected_slots is not None and not selected_slots.intersection(slot_ids):
            continue
        words = [struct.unpack_from("<I", data, offset)[0]
                 for offset in range(target, min(end, target + word_count * 4), 4)
                 if offset + 4 <= end]
        candidates = []
        for word_index, value in enumerate(words):
            target_slots = aliases.get(value, [])
            if value < len(data):
                candidates.append({
                    "word": word_index,
                    "value": value,
                    "target_slots": target_slots,
                })
        slot_references = []
        if find_slot_references:
            for offset in range(target, end - 3, 4):
                value = struct.unpack_from("<I", data, offset)[0]
                referenced_slots = tagged_targets.get(value)
                low_bit_tag = False
                if referenced_slots is None and value & 1:
                    referenced_slots = tagged_targets.get(value & ~1)
                    low_bit_tag = referenced_slots is not None
                if referenced_slots:
                    slot_references.append({
                        "offset": offset,
                        "value": value,
                        "target_slots": referenced_slots,
                        "low_bit_tag": low_bit_tag,
                    })
        output.append({
            "slots": slot_ids,
            "tagged_slots": tagged_slots,
            "untagged_slots": untagged_slots,
            "raw": slots[slot_ids[0]],
            "start": target,
            "end": end,
            "context_before": data[max(0, target - context_before):target],
            "context_start": max(0, target - context_before),
            "words": words,
            "floats": [struct.unpack("<f", struct.pack("<I", word))[0]
                       for word in words] if show_floats else None,
            "candidates": candidates,
            "slot_references": slot_references,
        })
    return output


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pol", type=Path, help="extracted POL file")
    parser.add_argument("--slot", type=int, action="append",
                        help="inspect only this slot; may be repeated")
    parser.add_argument("--all", action="store_true",
                        help="include tagged geometry slots (default: untagged slots)")
    parser.add_argument("--words", type=int, default=8,
                        help="leading 32-bit words per payload (default: 8)")
    parser.add_argument("--floats", action="store_true",
                        help="also interpret the preview words as IEEE-754 floats")
    parser.add_argument("--find-slot-references", action="store_true",
                        help="scan the full payload for exact pointers to tagged slot starts")
    parser.add_argument("--before-bytes", type=lambda value: int(value, 0), default=0,
                        metavar="N",
                        help="also show N bytes immediately before each slot target (base prefixes allowed)")
    parser.add_argument("--file-range", action="append", type=file_range,
                        metavar="OFFSET:SIZE",
                        help="show raw bytes and little-endian words at an exact file range; repeatable")
    args = parser.parse_args(argv)
    if args.words < 0 or args.words > 256:
        parser.error("--words must be between 0 and 256")
    if args.before_bytes < 0 or args.before_bytes > 0x1000:
        parser.error("--before-bytes must be between 0 and 4096")
    if args.file_range and (args.slot is not None or args.all or
                            args.find_slot_references or args.before_bytes or
                            args.floats):
        parser.error("--file-range cannot be combined with slot filtering, slot scans, or context options")
    if args.slot is not None and any(slot < 0 for slot in args.slot):
        parser.error("--slot values must be nonnegative")

    try:
        data = args.pol.read_bytes()
        if args.file_range:
            for offset, size in args.file_range:
                if offset > len(data) or size > len(data) - offset:
                    raise ValueError(
                        f"file range 0x{offset:x}..0x{offset + size:x} exceeds {len(data)} bytes")
                raw = data[offset:offset + size]
                print(f"range=0x{offset:x}..0x{offset + size:x} size=0x{size:x}")
                for at in range(0, len(raw), 4):
                    chunk = raw[at:at + 4]
                    word = int.from_bytes(chunk, "little")
                    print(f"  0x{offset + at:06x}: {chunk.hex(' '):<11} 0x{word:08x}")
            return 0
        rows = inspect(data,
                       None if args.slot is None else set(args.slot),
                       None if args.all else False, args.words, args.floats,
                       args.find_slot_references, args.before_bytes)
    except (OSError, ValueError, struct.error) as exc:
        print(f"pol_slot_inspect: {exc}", file=sys.stderr)
        return 1

    if not rows:
        print(f"{args.pol.name}: no matching nonzero slots")
        return 0
    for row in rows:
        word_text = " ".join(f"{word:08x}" for word in row["words"])
        aliases = ",".join(str(slot) for slot in row["slots"])
        if row["tagged_slots"] and row["untagged_slots"]:
            tag_kind = "mixed"
        elif row["tagged_slots"]:
            tag_kind = "yes"
        else:
            tag_kind = "no"
        print(f"slots={aliases} tagged={tag_kind} raw=0x{row['raw']:08x} "
              f"span=0x{row['start']:x}..0x{row['end']:x} "
              f"size=0x{row['end'] - row['start']:x}")
        context = row["context_before"]
        if context:
            print(f"  preceding bytes @0x{row['context_start']:x}: "
                  f"{context.hex(' ')}")
        if word_text:
            print(f"  words: {word_text}")
        if row["floats"] is not None:
            float_text = " ".join(f"{value:.7g}" for value in row["floats"])
            print(f"  floats: {float_text}")
        for candidate in row["candidates"]:
            slot_targets = ",".join(str(slot) for slot in candidate["target_slots"])
            slots_text = f" slots={slot_targets}" if slot_targets else ""
            print(f"  word[{candidate['word']}] -> file+0x{candidate['value']:x}{slots_text}")
        for reference in row["slot_references"]:
            slot_targets = ",".join(str(slot) for slot in reference["target_slots"])
            encoding = " (low-bit tag)" if reference["low_bit_tag"] else ""
            print(f"  ref file+0x{reference['offset']:x} -> "
                  f"tagged slots={slot_targets} value=0x{reference['value']:x}{encoding}")
        if args.find_slot_references and not row["slot_references"]:
            print("  tagged-slot references: none")
    print(f"{args.pol.name}: {len(rows)} payload spans")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
