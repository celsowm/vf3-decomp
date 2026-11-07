#!/usr/bin/env python3
"""Decode a retained Flycast guest-memory access trace without running Flycast.

Trace records are four little-endian u64 values:
``(pc << 16) | 0xFA20, (size << 48) | (isWrite << 47), address, value``.
They preserve access order but contain no frame timestamp.

Examples:
  python tools/mem_trace_decode.py extract/analysis/native_mt_fields_both_s29_v1.bin
  python tools/mem_trace_decode.py trace.bin --watch-range 0x0c1ff020:2 --writes
  python tools/mem_trace_decode.py trace.bin --pc 0x0c03b568 --pc 0x0c03b56c \
      --watch-range 0x0c201b4c:0x1000
"""
from __future__ import annotations

import argparse
from collections import Counter
import struct
import sys
from pathlib import Path


def parse_range(text: str) -> tuple[int, int]:
    try:
        addr_text, size_text = text.split(':', 1)
        addr, length = int(addr_text, 0), int(size_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            'range must be ADDRESS:LENGTH, e.g. 0x0C1FF020:2') from exc
    if addr < 0 or addr > 0xFFFFFFFF or length <= 0 or \
            addr + length > 0x100000000:
        raise argparse.ArgumentTypeError(
            'range must fit in the 32-bit address space')
    return addr, length


def parse_pc(text: str) -> int:
    try:
        pc = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f'invalid PC address: {text}') from exc
    if not 0 <= pc <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError('PC address must fit in 32 bits')
    return pc


def decode_trace(trace: Path, ranges: list[tuple[int, int]] | None = None,
                 writes: bool = False, changes_only: bool = False,
                 limit: int = 60, pcs: set[int] | None = None) -> int:
    """Print matching FA20 accesses and return a process-style status code."""
    try:
        data = trace.read_bytes()
    except OSError as exc:
        print(f'mem_trace_decode: cannot read trace {trace}: {exc}',
              file=sys.stderr)
        return 1
    if len(data) % 32:
        print(f'mem_trace_decode: trace size {len(data)} is not a multiple of 32 bytes',
              file=sys.stderr)
        return 1
    if limit < 0:
        print('mem_trace_decode: --limit cannot be negative', file=sys.stderr)
        return 2

    shown = 0
    previous: dict[int, int] = {}
    records = len(data) // 32
    for index in range(records):
        word0, word1, address, value = struct.unpack_from('<QQQQ', data, index * 32)
        if (word0 & 0xFFFF) != 0xFA20:
            continue
        pc = word0 >> 16
        if pcs and pc not in pcs:
            continue
        if ranges:
            physical = address & 0x1FFFFFFF
            if not any((base & 0x1FFFFFFF) <= physical <
                       (base & 0x1FFFFFFF) + length
                       for base, length in ranges):
                continue
        is_write = (word1 >> 47) & 1
        if writes and not is_write:
            continue
        value &= 0xFFFFFFFF
        if changes_only and address in previous and previous[address] == value:
            continue
        previous[address] = value
        print(f'{index:6d} pc {pc:08x} '
              f'{"W" if is_write else "R"}{word1 >> 48} '
              f'[{address:08x}] = {value:08x}')
        shown += 1
        if limit and shown >= limit:
            break
    print(f'{shown} hits shown ({records} records, trace {trace})',
          file=sys.stderr)
    return 0


def summarize_trace(trace: Path, ranges: list[tuple[int, int]] | None = None,
                    writes: bool = False, limit: int = 20,
                    pcs: set[int] | None = None) -> int:
    """Count matching memory-access records by PC, address, and access kind."""
    try:
        data = trace.read_bytes()
    except OSError as exc:
        print(f'mem_trace_decode: cannot read trace {trace}: {exc}',
              file=sys.stderr)
        return 1
    if len(data) % 32:
        print(f'mem_trace_decode: trace size {len(data)} is not a multiple of 32 bytes',
              file=sys.stderr)
        return 1
    if limit < 0:
        print('mem_trace_decode: --limit cannot be negative', file=sys.stderr)
        return 2

    pc_counts: Counter[int] = Counter()
    address_counts: Counter[int] = Counter()
    access_counts: Counter[tuple[int, int, int]] = Counter()
    tagged = matched = 0
    records = len(data) // 32
    for index in range(records):
        word0, word1, address, _value = struct.unpack_from('<QQQQ', data,
                                                            index * 32)
        if (word0 & 0xFFFF) != 0xFA20:
            continue
        tagged += 1
        pc = word0 >> 16
        if pcs and pc not in pcs:
            continue
        if ranges:
            physical = address & 0x1FFFFFFF
            if not any((base & 0x1FFFFFFF) <= physical <
                       (base & 0x1FFFFFFF) + length
                       for base, length in ranges):
                continue
        is_write = (word1 >> 47) & 1
        if writes and not is_write:
            continue
        matched += 1
        pc_counts[pc] += 1
        address_counts[address] += 1
        access_counts[(address, is_write, word1 >> 48)] += 1

    print(f'{matched} matching accesses ({tagged} tagged, {records} total records)')
    sections = (
        ('PC counts', sorted(pc_counts.items(), key=lambda item: (-item[1], item[0]))),
        ('Address counts', sorted(address_counts.items(), key=lambda item: (-item[1], item[0]))),
    )
    for title, rows in sections:
        print(f'\n{title}:')
        shown = rows if limit == 0 else rows[:limit]
        for value, count in shown:
            print(f'  {value:08x}: {count}')
        if not rows:
            print('  (none)')
        elif len(shown) < len(rows):
            print(f'  ... {len(rows) - len(shown)} more')

    print('\nAccess kinds:')
    kinds = sorted(access_counts.items(),
                   key=lambda item: (-item[1], item[0][0], item[0][1], item[0][2]))
    shown = kinds if limit == 0 else kinds[:limit]
    for (address, is_write, size), count in shown:
        print(f'  {address:08x} {"W" if is_write else "R"}{size}: {count}')
    if not kinds:
        print('  (none)')
    elif len(shown) < len(kinds):
        print(f'  ... {len(kinds) - len(shown)} more')
    return 0


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('trace', type=Path, help='retained .bin memory trace')
    parser.add_argument('--watch-range', action='append', type=parse_range,
                        help='filter ADDRESS:LENGTH; repeat for multiple ranges')
    parser.add_argument('--pc', action='append', type=parse_pc,
                        help='filter guest PC; repeat for multiple PCs')
    parser.add_argument('--writes', action='store_true',
                        help='show only write accesses')
    parser.add_argument('--changes-only', action='store_true',
                        help='show only the first value and changes per address')
    parser.add_argument('--summary', action='store_true',
                        help='count matching memory-access records by PC/address instead of listing them')
    parser.add_argument('--limit', type=int, default=60,
                        help='maximum rows per section; 0 prints all (default: 60)')
    args = parser.parse_args(argv)
    pcs = set(args.pc) if args.pc else None
    if args.summary:
        if args.changes_only:
            parser.error('--summary cannot be combined with --changes-only')
        return summarize_trace(args.trace, args.watch_range, args.writes,
                               args.limit, pcs)
    return decode_trace(args.trace, args.watch_range, args.writes,
                        args.changes_only, args.limit, pcs)


if __name__ == '__main__':
    raise SystemExit(main())
