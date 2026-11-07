#!/usr/bin/env python3
"""Summarize the writers of selected actor fields in a retained FA20 trace.

The report groups writes by actor-relative field and guest PC, then optionally
attributes each PC to a function range in Ghidra's baseline CSV. It is an
offline evidence tool: field names supplied by the user are labels only and do
not assign gameplay meaning.

Example (the three ranges used by the state-47 pose-builder trace):
  python tools/pose_trace_report.py \
      extract/analysis/pose_builder_fields_s47_600_v1.bin \
      --actor 0x0c20138c \
      --out extract/analysis/pose_builder_fields_s47_600_v1_report.json

Custom fields replace the defaults and use NAME:OFFSET:LENGTH, all relative
to --actor:
  python tools/pose_trace_report.py trace.bin --actor 0x0c20138c \
      --field channel_input:0x1d58:0xa8 \
      --field channel_output:0x1f50:0x54
"""

from __future__ import annotations

import argparse
import bisect
import csv
import json
import math
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_FUNCTIONS = ROOT / "extract" / "analysis" / "funcs_1ST_READ.unsc.bin.csv"
RECORD = struct.Struct("<QQQQ")
ADDRESS_MASK = 0x1FFFFFFF

DEFAULT_FIELDS = (
    ("watched_13a8", 0x13A8, 0x10),
    ("watched_1488", 0x1488, 0x0C),
    ("watched_1f14", 0x1F14, 0xC8),
)


@dataclass(frozen=True)
class FunctionRange:
    entry: int
    size: int
    name: str


@dataclass
class FieldStats:
    name: str
    offset: int
    length: int
    writes: int = 0
    first_index: int | None = None
    last_index: int | None = None
    addresses: Counter[int] = field(default_factory=Counter)
    pcs: Counter[int] = field(default_factory=Counter)
    latest_values: dict[int, tuple[int, int, int, int]] = field(default_factory=dict)


def integer(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if value < 0 or value > 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def parse_field(text: str) -> tuple[str, int, int]:
    parts = text.split(":")
    if len(parts) != 3 or not parts[0]:
        raise argparse.ArgumentTypeError(
            "field must be NAME:OFFSET:LENGTH, e.g. channels:0x1d58:0xa8")
    try:
        offset = int(parts[1], 0)
        length = int(parts[2], 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid field range: {exc}") from exc
    if offset < 0 or offset > 0xFFFFFFFF or length <= 0 or \
            offset + length > 0x100000000:
        raise argparse.ArgumentTypeError("field range must fit in 32 bits")
    return parts[0], offset, length


def parse_pc_label(text: str) -> tuple[int, str]:
    address_text, separator, label = text.partition(":")
    if not separator or not label:
        raise argparse.ArgumentTypeError("PC label must be ADDRESS:LABEL")
    try:
        address = int(address_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid PC address: {exc}") from exc
    if not 0 <= address <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("PC address must fit in 32 bits")
    return address, label


def parse_matrix_range(text: str) -> tuple[int, int]:
    parts = text.split(":")
    if len(parts) != 2:
        raise argparse.ArgumentTypeError("matrix range must be OFFSET:COUNT")
    try:
        offset = int(parts[0], 0)
        count = int(parts[1], 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid matrix range: {exc}") from exc
    if offset < 0 or offset > 0xFFFFFFFF or not 1 <= count <= 64 or \
            offset + count * 64 > 0x100000000:
        raise argparse.ArgumentTypeError("matrix range needs 1..64 rows and a valid offset")
    return offset, count


def parse_matrix_row(text: str) -> int:
    try:
        offset = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid matrix row offset: {exc}") from exc
    if offset < 0 or offset > 0xFFFFFFC0 or offset & 3:
        raise argparse.ArgumentTypeError(
            "matrix row offset must be word-aligned and leave room for 64 bytes")
    return offset


def float_value(value: int, size: int) -> float | None:
    if size != 4:
        return None
    decoded = struct.unpack("<f", struct.pack("<I", value))[0]
    return decoded if math.isfinite(decoded) else None


def load_functions(path: Path | None) -> tuple[list[int], list[FunctionRange]]:
    if path is None:
        return [], []
    ranges: list[FunctionRange] = []
    with path.open(newline="", encoding="utf-8-sig") as handle:
        reader = csv.DictReader(handle)
        if not reader.fieldnames or not {"entry", "size"}.issubset(reader.fieldnames):
            raise ValueError(f"function CSV needs entry and size columns: {path}")
        for row in reader:
            entry = int(row["entry"], 16)
            size = int(row["size"], 0) if row["size"].lower().startswith("0x") \
                else int(row["size"])
            name = (row.get("name") or "").strip()
            ranges.append(FunctionRange(entry, size, name))
    ranges.sort(key=lambda item: item.entry)
    return [item.entry for item in ranges], ranges


def normalize_code_pc(pc: int) -> int:
    """Map the 0x0c/0x8c/0xac RAM mirrors to the 0x8c image address."""
    physical = pc & ADDRESS_MASK
    return 0x8C000000 | (physical & 0x00FFFFFF)


def containing_function(pc: int, entries: list[int],
                        ranges: list[FunctionRange]) -> FunctionRange | None:
    if not entries:
        return None
    normalized = normalize_code_pc(pc)
    index = bisect.bisect_right(entries, normalized) - 1
    if index < 0:
        return None
    item = ranges[index]
    return item if item.entry <= normalized < item.entry + max(item.size, 1) else None


def analyze(trace: Path, actor: int, fields: tuple[tuple[str, int, int], ...],
            function_csv: Path | None) -> dict[str, object]:
    trace_size = trace.stat().st_size
    if trace_size % RECORD.size:
        raise ValueError(f"trace size {trace_size} is not a multiple of {RECORD.size} bytes")
    actor_physical = actor & ADDRESS_MASK
    entries, functions = load_functions(function_csv)
    stats = [FieldStats(name, offset, length) for name, offset, length in fields]
    records = trace_size // RECORD.size
    tagged = 0

    with trace.open("rb") as handle:
        for index in range(records):
            word0, word1, address64, raw_value = RECORD.unpack(handle.read(RECORD.size))
            if (word0 & 0xFFFF) != 0xFA20:
                continue
            tagged += 1
            if not ((word1 >> 47) & 1):
                continue
            access_size = (word1 >> 48) & 0x7FFF
            if access_size == 0:
                continue
            pc = (word0 >> 16) & 0xFFFFFFFF
            address = int(address64 & 0xFFFFFFFF) & ADDRESS_MASK
            value = int(raw_value & 0xFFFFFFFF)
            relative = address - actor_physical
            access_end = relative + access_size
            for item in stats:
                if relative < item.offset + item.length and access_end > item.offset:
                    item.writes += 1
                    item.addresses[address] += 1
                    item.pcs[pc] += 1
                    item.latest_values[address] = (value, access_size, pc, index)
                    if item.first_index is None:
                        item.first_index = index
                    item.last_index = index

    reports: list[dict[str, object]] = []
    for item in stats:
        writers = []
        for pc, count in sorted(item.pcs.items(), key=lambda pair: (-pair[1], pair[0])):
            fn = containing_function(pc, entries, functions)
            writers.append({
                "pc": f"0x{pc:08x}",
                "writes": count,
                "function_entry": f"0x{fn.entry:08x}" if fn else None,
                "function_name": fn.name if fn else None,
                "explicit_source_label": None,
            })
        reports.append({
            "name": item.name,
            "actor_offset": f"0x{item.offset:x}",
            "length": item.length,
            "writes": item.writes,
            "unique_addresses": len(item.addresses),
            "first_record": item.first_index,
            "last_record": item.last_index,
            "top_writers": writers,
            "addresses": [
                {"address": f"0x{address:08x}", "actor_offset": f"+0x{address - actor_physical:x}",
                 "writes": count,
                 "last_value": f"0x{item.latest_values[address][0]:08x}",
                 "last_size": item.latest_values[address][1],
                 "last_pc": f"0x{item.latest_values[address][2]:08x}",
                 "last_record": item.latest_values[address][3],
                 "last_float": float_value(item.latest_values[address][0],
                                            item.latest_values[address][1])}
                for address, count in sorted(item.addresses.items())
            ],
        })
    return {
        "diagnostic_only": True,
        "trace": str(trace),
        "trace_bytes": trace_size,
        "record_count": records,
        "tagged_fa20_records": tagged,
        "actor": f"0x{actor:08x}",
        "function_csv": str(function_csv) if function_csv else None,
        "fields": reports,
        "limitations": [
            "The trace has no frame timestamps; record order is not frame time.",
            "Field labels are caller supplied or watch-range labels, not semantic inference.",
            "PC ownership uses baseline function ranges and does not prove call causality.",
            "Matrix exports combine the last observed store per word and are not atomic snapshots.",
        ],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("trace", type=Path, help="retained FA20 memory trace")
    parser.add_argument("--actor", type=integer, required=True,
                        help="actor base address from the capture")
    parser.add_argument("--field", type=parse_field, action="append", default=[],
                        help="custom NAME:OFFSET:LENGTH; repeatable, replaces defaults")
    parser.add_argument("--functions", type=Path, default=DEFAULT_FUNCTIONS,
                        help="Ghidra function CSV used to name writer PCs")
    parser.add_argument("--pc-label", type=parse_pc_label, action="append", default=[],
                        help="explicit PC:LABEL for readable source attribution; repeatable")
    parser.add_argument("--export-range", type=parse_matrix_range,
                        help="export last-written 4x4 matrices at actor-relative OFFSET:COUNT")
    parser.add_argument("--export-row", type=parse_matrix_row, action="append", default=[],
                        help="export one sparse 4x4 matrix row at actor-relative OFFSET; repeat in desired row order")
    parser.add_argument("--matrix-bin", type=Path,
                        help="new binary output path paired with --export-range")
    parser.add_argument("--no-functions", action="store_true",
                        help="skip function-range attribution")
    parser.add_argument("--out", type=Path,
                        help="write a new JSON report; existing paths are refused")
    parser.add_argument("--values", action="store_true",
                        help="print each watched address's last stored value")
    parser.add_argument("--top", type=int, default=12,
                        help="writer rows to print per field (default: 12)")
    args = parser.parse_args(argv)
    if args.top < 0:
        parser.error("--top cannot be negative")
    if args.export_range is not None and args.export_row:
        parser.error("use --export-range or repeated --export-row, not both")
    has_matrix_export = args.export_range is not None or bool(args.export_row)
    if has_matrix_export != (args.matrix_bin is not None):
        parser.error("--matrix-bin must be paired with --export-range or --export-row")
    if len(set(args.export_row)) != len(args.export_row):
        parser.error("--export-row offsets must be unique")
    fields = tuple(args.field) if args.field else DEFAULT_FIELDS
    if len({name for name, _offset, _length in fields}) != len(fields):
        parser.error("field names must be unique")
    function_csv = None if args.no_functions else args.functions
    pc_labels = dict(args.pc_label)

    try:
        if not args.trace.is_file():
            raise ValueError(f"trace does not exist: {args.trace}")
        if function_csv is not None and not function_csv.is_file():
            raise ValueError(f"function CSV does not exist: {function_csv}")
        if args.out and args.out.exists():
            raise ValueError(f"refusing to replace existing report: {args.out}")
        report = analyze(args.trace, args.actor, fields, function_csv)
        for field_report in report["fields"]:
            for writer in field_report["top_writers"]:
                writer["explicit_source_label"] = pc_labels.get(
                    int(writer["pc"], 0))
        if args.matrix_bin is not None:
            if args.matrix_bin.exists():
                raise ValueError(f"refusing to replace matrix output: {args.matrix_bin}")
            if args.export_range is not None:
                offset, count = args.export_range
                row_offsets = [offset + index * 64 for index in range(count)]
            else:
                row_offsets = args.export_row
            latest: dict[int, dict[str, object]] = {}
            for field_report in report["fields"]:
                for address in field_report["addresses"]:
                    latest[int(address["actor_offset"].lstrip("+"), 16)] = address
            matrix_bytes = bytearray()
            missing = []
            for row_offset in row_offsets:
                for word_index in range(16):
                    relative_offset = row_offset + word_index * 4
                    word = latest.get(relative_offset)
                    if word is None or word["last_size"] != 4:
                        missing.append(relative_offset)
                    else:
                        matrix_bytes.extend(struct.pack("<I", int(word["last_value"], 0)))
            if missing:
                preview = ", ".join(f"+0x{value:x}" for value in missing[:8])
                raise ValueError(f"matrix range has missing/non-word stores at {preview}")
            args.matrix_bin.parent.mkdir(parents=True, exist_ok=True)
            args.matrix_bin.write_bytes(matrix_bytes)
            report["matrix_export"] = {
                "actor_offset": f"0x{row_offsets[0]:x}",
                "actor_offsets": [f"0x{offset:x}" for offset in row_offsets],
                "rows": len(row_offsets),
                "path": str(args.matrix_bin),
                "bytes": len(matrix_bytes),
                "source": "last observed writes in the trace",
            }
        if args.out:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            args.out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    except (OSError, ValueError, struct.error) as exc:
        print(f"pose_trace_report: {exc}", file=sys.stderr)
        return 1

    print(f"pose_trace_report: {report['record_count']} records, "
          f"{report['tagged_fa20_records']} FA20; actor={report['actor']}")
    for item in report["fields"]:
        print(f"\n{item['name']} ({item['actor_offset']}+0x{item['length']:x}): "
              f"{item['writes']} writes, {item['unique_addresses']} addresses")
        writers = item["top_writers"]
        shown = writers if args.top == 0 else writers[:args.top]
        for writer in shown:
            label = (writer["explicit_source_label"] or
                     writer["function_name"] or "unmapped")
            entry = f" {writer['function_entry']}" if writer["function_entry"] else ""
            print(f"  {writer['pc']}: {writer['writes']:4} writes  {label}{entry}")
        if len(shown) < len(writers):
            print(f"  ... {len(writers) - len(shown)} additional writer PCs")
        if args.values:
            for address in item["addresses"]:
                value = address["last_float"]
                rendered = (f"{value:.7g}" if value is not None else
                            address["last_value"])
                print(f"    {address['actor_offset']:>8} = {rendered} "
                      f"(W{address['last_size']}, {address['last_pc']})")
    if args.out:
        print(f"report: {args.out}")
    if "matrix_export" in report:
        print(f"matrix export: {report['matrix_export']['rows']} rows -> "
              f"{report['matrix_export']['path']} (last store per word)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
