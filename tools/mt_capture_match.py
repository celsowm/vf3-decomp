#!/usr/bin/env python3
"""Match a captured mounted MT motion against extracted source assets.

The capture must include the actor's animation-record pointer and the RAM pages
containing its record and streams. The tool compares expanded channel opcodes,
key counts, key times, and the bounded tuple prefix against the three source
records selected by the actor's one-based motion ID. It is offline evidence;
it does not load or execute the game image.

Example:
  python tools/mt_capture_match.py extract/analysis/fifth_leaf_dev_v6_cases \
      --entry 0x8c09f036 --case 1 --assets extract/gamedata
"""

from __future__ import annotations

import argparse
from pathlib import Path
import struct
import sys

from mtmap import parse as parse_slots

ADDRESS_MASK = 0x1FFFFFFF
SLOT_COUNT = 8880
CHANNELS = 63


def parse_number(text: str) -> int:
    try:
        return int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc


def parse_register(text: str) -> int:
    text = text.lower()
    if not text.startswith("r") or not text[1:].isdigit():
        raise argparse.ArgumentTypeError("expected a GPR name such as r4")
    index = int(text[1:])
    if not 0 <= index < 16:
        raise argparse.ArgumentTypeError("GPR index must be in 0..15")
    return index


def load_case(directory: Path, entry: int, number: int) -> tuple[list[str], bytes, list[tuple[int, int]]]:
    if number < 1:
        raise ValueError("case number must be one-based and positive")
    lines = (directory / f"f_{entry:08x}.cases").read_text().splitlines()
    if number > len(lines):
        raise ValueError(f"case {number} is outside the {len(lines)} cases in the corpus")
    fields = lines[number - 1].split()
    if len(fields) < 78:
        raise ValueError(f"case {number} is truncated")
    window_count = int(fields[75])
    if len(fields) < 76 + window_count * 2:
        raise ValueError(f"case {number} has a truncated RAM-window table")
    blob = (directory / fields[74]).read_bytes()
    windows = [(int(fields[76 + 2 * index], 16),
                int(fields[77 + 2 * index], 16))
               for index in range(window_count)]
    return fields, blob, windows


def ram_read(blob: bytes, windows: list[tuple[int, int]], address: int,
             size: int) -> bytes | None:
    physical = address & ADDRESS_MASK
    file_offset = 0
    for base, length in windows:
        if base <= physical and size <= base + length - physical:
            start = file_offset + physical - base
            return blob[start:start + size]
        file_offset += length
    return None


def read_u16(blob: bytes, windows: list[tuple[int, int]], address: int,
             name: str) -> int:
    raw = ram_read(blob, windows, address, 2)
    if raw is None:
        raise ValueError(f"{name} at {address:#010x} is outside captured RAM windows")
    return struct.unpack("<H", raw)[0]


def read_u32(blob: bytes, windows: list[tuple[int, int]], address: int,
             name: str) -> int:
    raw = ram_read(blob, windows, address, 4)
    if raw is None:
        raise ValueError(f"{name} at {address:#010x} is outside captured RAM windows")
    return struct.unpack("<I", raw)[0]


def decode_ops(source: bytes, offset: int) -> bytes:
    output = bytearray()
    for packed in source[offset + 2:offset + 18]:
        output.extend((packed >> 6, (packed >> 4) & 3,
                       (packed >> 2) & 3, packed & 3))
    return bytes(output[:CHANNELS])


def stream_lengths(ops: bytes, counts: bytes) -> tuple[int, int]:
    count_cursor = 0
    time_bytes = 0
    tuple_bytes = 0
    for op in ops:
        count = 0
        if op >= 2:
            if count_cursor >= len(counts):
                raise ValueError("captured count stream is shorter than the opcode map")
            count = counts[count_cursor]
            count_cursor += 1
            time_bytes += count
        if op == 1:
            tuple_bytes += 4
        elif op == 2:
            tuple_bytes += (count + 2) * 4
        elif op >= 3:
            # Exact-key evaluation can advance eight bytes beyond the
            # interpolation path, so keep the same safe bound as mt.c.
            tuple_bytes += count * 12 + 16
    if count_cursor != len(counts):
        raise ValueError("captured count stream contains bytes beyond the opcode map")
    return time_bytes, tuple_bytes


def row_for_asset(path: Path, motion_id: int, captured: dict[str, bytes],
                  asset_cache: dict[Path, tuple[bytes, dict[int, tuple[int, int]]]]) -> dict[str, object]:
    try:
        if path not in asset_cache:
            data = path.read_bytes()
            rows = {slot: (offset, size) for slot, offset, size in parse_slots(path)}
            asset_cache[path] = (data, rows)
        data, offsets = asset_cache[path]
    except (OSError, ValueError) as exc:
        return {"asset": path.name, "error": str(exc)}

    first_slot = (motion_id - 1) * 3
    parts = [offsets.get(first_slot + part) for part in range(3)]
    if not all(parts):
        return {"asset": path.name, "state": "incomplete"}
    (ops_off, ops_size), (times_off, times_size), (tuples_off, tuples_size) = parts
    if ops_off + 18 > len(data):
        return {"asset": path.name, "state": "truncated"}

    ops = decode_ops(data, ops_off)
    key_count = sum(op >= 2 for op in ops)
    counts = data[ops_off + 18:ops_off + 18 + key_count]
    try:
        time_size, tuple_size = stream_lengths(ops, counts)
    except ValueError as exc:
        return {"asset": path.name, "state": "malformed", "error": str(exc)}
    asset_streams = {
        "ops": ops,
        "counts": counts,
        "times": data[times_off:times_off + time_size],
        "tuples": data[tuples_off:tuples_off + tuple_size],
    }
    comparisons = {name: asset_streams[name] == captured[name]
                   for name in asset_streams}
    return {
        "asset": path.name,
        "state": "exact" if all(comparisons.values()) else "partial",
        "comparisons": comparisons,
        "offsets": [ops_off, times_off, tuples_off],
        "record_sizes": [ops_size, times_size, tuples_size],
        "key_count": key_count,
        "time_bytes": time_size,
        "tuple_bytes": tuple_size,
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("corpus", type=Path, help="directory containing f_<entry>.cases and RAM shadows")
    parser.add_argument("--entry", required=True, type=parse_number,
                        help="corpus entry PC")
    parser.add_argument("--case", action="append", type=int, default=[],
                        help="one-based case number; may be repeated")
    parser.add_argument("--all-cases", action="store_true",
                        help="scan every case in the selected corpus")
    parser.add_argument("--verbose", action="store_true",
                        help="list every exact asset match instead of a short sample")
    parser.add_argument("--actor-register", default="r4", type=parse_register,
                        help="GPR holding the actor pointer (default: r4)")
    parser.add_argument("--motion-id", type=parse_number,
                        help="explicit motion ID when actor+0x3c is outside captured RAM; "
                             "usable with exactly one --case")
    parser.add_argument("--assets", default=Path("extract/gamedata"), type=Path,
                        help="directory containing extracted MT*.BIN files")
    args = parser.parse_args(argv)

    try:
        paths = sorted(args.assets.glob("MT*.BIN"))
        if not paths:
            raise ValueError(f"no MT*.BIN assets found in {args.assets}")
        corpus_lines = (args.corpus / f"f_{args.entry:08x}.cases").read_text().splitlines()
        if args.all_cases and args.case:
            parser.error("choose either --all-cases or one or more --case values")
        if args.motion_id is not None and len(args.case) != 1:
            parser.error("--motion-id requires exactly one --case")
        case_numbers = list(range(1, len(corpus_lines) + 1)) if args.all_cases else args.case
        if not case_numbers:
            parser.error("provide --case N or --all-cases")
        if any(number < 1 for number in case_numbers):
            parser.error("case numbers must be positive and one-based")

        asset_cache: dict[Path, tuple[bytes, dict[int, tuple[int, int]]]] = {}
        matched_cases = 0
        skipped_cases = 0
        motion_matches: dict[int, tuple[int, int, set[str]]] = {}
        for case_number in case_numbers:
            try:
                fields, blob, windows = load_case(args.corpus, args.entry, case_number)
                actor = int(fields[args.actor_register], 16)
                motion_id = (args.motion_id if args.motion_id is not None else
                             read_u16(blob, windows, actor + 0x3C, "motion ID"))
                cycle = read_u16(blob, windows, actor + 0x1A00, "cycle")
                record = read_u32(blob, windows, actor + 0x1D00, "animation record")
                stream_pointer = read_u32(blob, windows, record, "count-stream pointer")
                time_pointer = read_u32(blob, windows, record + 4, "key-time pointer")
                tuple_pointer = read_u32(blob, windows, record + 8, "tuple pointer")
                ops = ram_read(blob, windows, record + 12, CHANNELS)
                if ops is None:
                    raise ValueError("expanded opcode map is outside captured RAM windows")
                count_count = sum(op >= 2 for op in ops)
                counts = ram_read(blob, windows, stream_pointer + 1, count_count)
                if counts is None:
                    raise ValueError("count stream is outside captured RAM windows")
                time_count, tuple_count = stream_lengths(ops, counts)
                times = ram_read(blob, windows, time_pointer, time_count)
                tuples = ram_read(blob, windows, tuple_pointer, tuple_count)
                if times is None or tuples is None:
                    missing = "key-time" if times is None else "tuple"
                    raise ValueError(f"{missing} stream is outside captured RAM windows")
                captured = {"ops": ops, "counts": counts, "times": times, "tuples": tuples}
                results = [row_for_asset(path, motion_id, captured, asset_cache)
                           for path in paths]
                matches = [row for row in results if row.get("state") == "exact"]
                partial = [row for row in results if row.get("state") == "partial"]
                matched_cases += bool(matches)
                skipped_cases += 0
                prior_cases, prior_total, prior_assets = motion_matches.get(
                    motion_id, (0, 0, set()))
                motion_matches[motion_id] = (prior_cases + bool(matches),
                    prior_total + 1, prior_assets | {str(row["asset"]) for row in matches})

                motion_source = "explicit" if args.motion_id is not None else "captured"
                print(f"case={case_number} actor={actor:#010x} motion=0x{motion_id:x} "
                      f"motion_source={motion_source} cycle={cycle} "
                      f"exact={len(matches)}/{len(paths)}")
                if args.all_cases:
                    continue
                if matches:
                    shown_matches = matches if args.verbose else matches[:5]
                    for row in shown_matches:
                        print(f"  EXACT {row['asset']} offsets=" + ",".join(
                            f"0x{value:x}" for value in row["offsets"]))
                    if len(shown_matches) < len(matches):
                        print(f"  ... {len(matches) - len(shown_matches)} additional exact packs "
                              "(use --verbose to list)")
                else:
                    for row in partial:
                        checks = " ".join(f"{name}={int(value)}"
                                          for name, value in row["comparisons"].items())
                        print(f"  PARTIAL {row['asset']} {checks}")
            except (OSError, ValueError, struct.error) as exc:
                skipped_cases += 1
                print(f"case={case_number} SKIP {exc}")

        for motion_id, (matching, total, assets) in sorted(motion_matches.items()):
            sample = ",".join(sorted(assets)[:3])
            print(f"motion=0x{motion_id:x} exact_cases={matching}/{total} "
                  f"matching_packs={len(assets)} sample={sample}")
        print(f"exact cases: {matched_cases}/{len(case_numbers)}; skipped: {skipped_cases}")
        return 0 if matched_cases == len(case_numbers) and not skipped_cases else 2
    except (OSError, ValueError, struct.error) as exc:
        print(f"mt_capture_match: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
