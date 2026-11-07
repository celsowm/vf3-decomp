#!/usr/bin/env python3
"""Inspect MOTHEAD.BIN's leading u32 offset table and bounded records.

The table boundary is inferred from the first nonzero word outside the file;
every preceding entry is checked as an in-file record offset. Record fields
remain unnamed until independently identified.

Examples:
  python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --limit 24
  python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --record 0x5b38
  python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --limit 0 --json
  python tools/mothead_inspect.py extract/gamedata/MOTHEAD.BIN --all --json
"""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path
import struct
import sys


def parse(data: bytes) -> tuple[int, int, list[int], list[dict[str, object]], dict[str, object]]:
    if len(data) < 4:
        raise ValueError("file is shorter than one u32 word")
    first_value = struct.unpack_from("<I", data)[0]
    total_words = len(data) // 4
    candidate_count = total_words
    for index in range(1, total_words):
        value = struct.unpack_from("<I", data, index * 4)[0]
        if value != 0 and value >= len(data):
            candidate_count = index
            break
    if candidate_count < 2:
        raise ValueError("could not find a multi-entry in-file offset prefix")
    table_bytes = candidate_count * 4
    offsets = list(struct.unpack_from(f"<{candidate_count}I", data, 0))
    refs: dict[int, list[int]] = defaultdict(list)
    for index, offset in enumerate(offsets):
        if offset == 0:
            continue
        if offset < table_bytes:
            raise ValueError(
                f"candidate table row {index} points into the table: 0x{offset:x}"
            )
        refs[offset].append(index)
    starts = sorted(refs)
    rows: list[dict[str, object]] = []
    for i, start in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else len(data)
        payload = data[start:end]
        usable = len(payload) & ~1
        halfwords = list(struct.unpack_from(f"<{usable // 2}H", payload)) if usable else []
        word_count = len(payload) // 4
        words = list(struct.unpack_from(f"<{word_count}I", payload)) if word_count else []
        rows.append({
            "offset": start,
            "end": end,
            "size": end - start,
            "table_rows": refs[start],
            "prefix_hex": payload[:64].hex(),
            "u16_prefix": halfwords[:32],
            "u32_prefix": words[:16],
        })
    stats = {
        "zero_rows": sum(offset == 0 for offset in offsets),
        "first_out_of_file_row": candidate_count,
        "post_prefix_words": total_words - candidate_count,
        "post_prefix_out_of_file_words": sum(
            struct.unpack_from("<I", data, index * 4)[0] >= len(data)
            for index in range(candidate_count, total_words)
        ),
    }
    return first_value, candidate_count, offsets, rows, stats


def find_u16(data: bytes, records: list[dict[str, object]],
             values: set[int]) -> list[dict[str, object]]:
    matches = []
    for record in records:
        start = int(record["offset"])
        end = int(record["end"])
        for offset in range(start, end - 1, 2):
            value = struct.unpack_from("<H", data, offset)[0]
            if value in values:
                matches.append({
                    "value": value,
                    "file_offset": offset,
                    "record_offset": start,
                    "record_relative_offset": offset - start,
                    "table_rows": record["table_rows"],
                    "context_hex": data[max(start, offset - 8):min(end, offset + 10)].hex(),
                })
    return matches


def u16_number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFF:
        raise argparse.ArgumentTypeError("u16 search value must be in 0..0xffff")
    return value


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", type=Path, help="extracted MOTHEAD.BIN")
    parser.add_argument("--record", type=lambda value: int(value, 0), action="append",
                        help="show only this candidate record offset; may be repeated")
    parser.add_argument("--limit", type=int,
                        help="limit displayed records to the first N unique offsets (default: 24; 0 shows none)")
    parser.add_argument("--all", action="store_true",
                        help="display every candidate record (can produce large output)")
    parser.add_argument("--find-u16", type=u16_number, action="append",
                        help="find this u16 value in candidate record spans; may be repeated")
    parser.add_argument("--json", action="store_true", help="emit JSON")
    args = parser.parse_args(argv)
    if args.limit is not None and args.limit < 0:
        parser.error("--limit must be nonnegative")
    if args.all and args.limit is not None:
        parser.error("--all cannot be combined with --limit")
    if args.record is not None and any(offset < 0 for offset in args.record):
        parser.error("--record offsets must be nonnegative")

    try:
        data = args.file.read_bytes()
        first_value, candidate_count, offsets, rows, stats = parse(data)
        unique_record_count = len(rows)
        matches = find_u16(data, rows, set(args.find_u16 or []))
        selected = set(args.record or [])
        if selected:
            known = {row["offset"] for row in rows}
            missing = sorted(selected - known)
            if missing:
                raise ValueError("unknown candidate record offset(s): " +
                                 ", ".join(f"0x{offset:x}" for offset in missing))
            rows = [row for row in rows if row["offset"] in selected]
        elif not args.all:
            rows = rows[:24 if args.limit is None else args.limit]
    except (OSError, ValueError, struct.error) as exc:
        print(f"mothead_inspect: {exc}", file=sys.stderr)
        return 1

    result = {
        "diagnostic_only": True,
        "file_size": len(data),
        "first_word": first_value,
        "candidate_table_rows": len(offsets),
        "candidate_table_bytes": candidate_count * 4,
        "zero_rows": stats["zero_rows"],
        "unique_candidate_record_offsets": unique_record_count,
        "displayed_records": len(rows),
        "first_out_of_file_row": stats["first_out_of_file_row"],
        "post_prefix_words": stats["post_prefix_words"],
        "post_prefix_out_of_file_words": stats["post_prefix_out_of_file_words"],
        "records": rows,
        "u16_matches": matches,
        "notes": [
            "The in-file prefix is a heuristic for the offset-table extent, not a proven format boundary.",
            "Candidate record spans end at the next unique offset; a pointer may target an interior address.",
            "No row or payload field is assigned action, character, or motion semantics.",
        ],
    }
    if args.json:
        print(json.dumps(result, indent=2))
        return 0

    print(f"{args.file.name}: {result['file_size']} bytes")
    print(f"offset table: rows={len(offsets)}, bytes=0x{candidate_count * 4:x}, "
          f"zero={result['zero_rows']}, unique offsets="
          f"{result['unique_candidate_record_offsets']}; "
          f"row 0 points to 0x{first_value:x}")
    print(f"first out-of-file word at row {stats['first_out_of_file_row']}; "
          f"post-prefix words={stats['post_prefix_words']}, "
          f"out-of-file={stats['post_prefix_out_of_file_words']}")
    for row in rows:
        slots = ",".join(str(index) for index in row["table_rows"])
        print(f"record 0x{row['offset']:x}..0x{row['end']:x} "
              f"size=0x{row['size']:x} table_rows=[{slots}]")
        print(f"  bytes: {row['prefix_hex']}")
        print("  u16: " + " ".join(f"{value:04x}" for value in row["u16_prefix"]))
        print("  u32: " + " ".join(f"{value:08x}" for value in row["u32_prefix"]))
    for match in matches:
        print(f"match 0x{match['value']:04x} file+0x{match['file_offset']:x} "
              f"record+0x{match['record_relative_offset']:x} "
              f"record=0x{match['record_offset']:x} "
              f"table_rows={match['table_rows']} context={match['context_hex']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
