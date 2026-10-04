"""Inspect architectural state and captured RAM for selected raw invocations."""
import argparse
from collections import Counter
import struct
from pathlib import Path
from capsules import records


REGISTER_NAMES = {**{f'r{i}': i for i in range(16)},
                  **{f'fr{i}': 21 + i for i in range(16)},
                  **{f'xf{i}': 37 + i for i in range(16)},
                  **{f'rbank{i}': 55 + i for i in range(8)},
                  'pr': 16, 'sr': 17, 'fpscr': 18, 'macl': 19, 'mach': 20,
                  'fpul': 53, 'gbr': 54}


def register_index(name):
    name = name.lower()
    if name in REGISTER_NAMES:
        return REGISTER_NAMES[name]
    try:
        number = int(name, 0)
    except ValueError:
        raise ValueError(f'unknown architectural register: {name}') from None
    if not 0 <= number < 16:
        raise ValueError('numeric register names must be GPR indices 0-15')
    return number


def format_register(value, index):
    if value is None:
        return 'unavailable'
    bits = f'{value:08x}'
    if 21 <= index < 53:
        return f'{bits}({struct.unpack("<f", struct.pack("<I", value))[0]:.9g})'
    return bits


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsules', nargs='+', type=Path)
    parser.add_argument('--entry', type=lambda s: int(s, 0), required=True)
    parser.add_argument('--invocation', type=int)
    parser.add_argument('--valid-only', action='store_true')
    parser.add_argument('--limit', type=int)
    parser.add_argument('--summary', nargs='*', metavar='REG',
                        help='summarize architectural registers (r0, fr4, xf0, fpul, gbr, rbank0)')
    parser.add_argument('--memory-summary', nargs='*', type=lambda s: int(s, 0), metavar='ADDR',
                        help='summarize initial aligned RAM words at addresses (for example 0x0c404008)')
    parser.add_argument('--ops-presence', action='append', type=lambda s: int(s, 0), default=[],
                        metavar='PC', help='include whether this PC appears in each invocation trace')
    parser.add_argument('--require-ops', action='append', type=lambda s: int(s, 0), default=[],
                        metavar='PC', help='show only invocations whose trace contains this PC')
    parser.add_argument('--word', type=lambda s: int(s, 0), action='append', default=[])
    parser.add_argument('--stack-words', type=int, default=8)
    parser.add_argument('--ops-start', type=lambda s: int(s, 0))
    parser.add_argument('--ops-end', type=lambda s: int(s, 0))
    args = parser.parse_args()
    shown = 0
    limit = args.limit if args.limit is not None else (
        None if args.summary is not None or args.memory_summary is not None else 1)
    names = [f'r{i}' for i in range(16)] if args.summary == [] else (args.summary or [])
    try:
        registers = [register_index(name) for name in names]
    except ValueError as error:
        parser.error(str(error))
    summary = Counter()
    memory_summary = Counter()
    for path in args.capsules:
        for record in records(path):
            if record['entry'] | 0x80000000 != args.entry | 0x80000000:
                continue
            if args.invocation is not None and record['id'] != args.invocation:
                continue
            if args.valid_only and record['flags']:
                continue
            if any(not any((pc & 0x1fffffff) == (wanted & 0x1fffffff)
                           for pc, _ in record['ops']) for wanted in args.require_ops):
                continue
            before = struct.unpack(f"<{record['nstate']}I", record['before'])
            after = struct.unpack(f"<{record['nstate']}I", record['after'])
            if args.summary is not None or args.memory_summary is not None:
                presence = tuple(any((pc & 0x1fffffff) == (wanted & 0x1fffffff)
                                     for pc, _ in record['ops'])
                                 for wanted in args.ops_presence)
                if args.memory_summary is not None:
                    values = []
                    for address in args.memory_summary:
                        physical = address & 0x1fffffff
                        page = next(((base, a) for base, a, _ in record['pages']
                                     if base <= physical <= base + len(a) - 4), None)
                        values.append(None if page is None else
                                      struct.unpack_from('<I', page[1], physical - page[0])[0])
                    memory_summary[(tuple(values), presence)] += 1
                if args.summary is None:
                    shown += 1
                    if limit is not None and shown >= limit:
                        break
                    continue
                summary[(tuple(before[r] if r < len(before) else None for r in registers),
                         tuple(after[r] if r < len(after) else None for r in registers), presence)] += 1
                shown += 1
                if limit is not None and shown >= limit:
                    break
                continue
            print(f"{path.name} id={record['id']} flags={record['flags']} exit={record['exitpc']:08x}")
            for reg in range(16):
                print(f'r{reg}={before[reg]:08x}->{after[reg]:08x}', end='\n' if reg % 4 == 3 else ' ')
            print(f'PR={before[16]:08x}->{after[16]:08x} FPSCR={before[18]:08x}->{after[18]:08x}')
            addresses = args.word + [before[15] + 4 * i for i in range(args.stack_words)]
            for address in addresses:
                physical = address & 0x1fffffff
                page = next(((base, a, b) for base, a, b in record['pages']
                             if base <= physical <= base + len(a) - 4), None)
                if page is None:
                    print(f'{address:08x}: uncaptured')
                    continue
                base, a, b = page
                offset = physical - base
                print(f'{address:08x}: {struct.unpack_from("<I", a, offset)[0]:08x}->'
                      f'{struct.unpack_from("<I", b, offset)[0]:08x}')
            print('last ops:', ' '.join(f'{pc:08x}:{op:04x}' for pc, op in record['ops'][-8:]))
            if args.ops_start is not None:
                start = args.ops_start & 0x1fffffff
                end = (args.ops_end & 0x1fffffff) if args.ops_end is not None else start + 0x100
                selected = [(pc, op) for pc, op in record['ops'] if start <= pc & 0x1fffffff < end]
                print('selected ops:', ' '.join(f'{pc:08x}:{op:04x}' for pc, op in selected))
            shown += 1
            if limit is not None and shown >= limit:
                return
        if (args.summary is not None or args.memory_summary is not None) and limit is not None and shown >= limit:
            break
    if args.summary is not None or args.memory_summary is not None:
        if args.summary is not None:
            labels = ','.join(names)
            print(f'{shown} records; register summary ({labels})')
            for (inputs, outputs, presence), count in sorted(summary.items(),
                    key=lambda item: (-item[1], repr(item[0]))):
                before_text = ','.join(format_register(value, reg) for value, reg in zip(inputs, registers))
                after_text = ','.join(format_register(value, reg) for value, reg in zip(outputs, registers))
                suffix = ' | ' + ','.join('yes' if value else 'no' for value in presence) if presence else ''
                print(f'{count:4d}  {before_text} -> {after_text}{suffix}')
        if args.memory_summary is not None:
            addresses = ','.join(f'{address:08x}' for address in args.memory_summary)
            pcs = ','.join(f'{pc:08x}' for pc in args.ops_presence)
            suffix = f'; op presence ({pcs})' if pcs else ''
            print(f'{shown} records; initial RAM word summary ({addresses}){suffix}')
            for (values, presence), count in sorted(memory_summary.items(),
                    key=lambda item: (-item[1], tuple(-1 if value is None else value
                                                    for value in item[0][0]), item[0][1])):
                value_text = ','.join('uncaptured' if value is None else f'{value:08x}' for value in values)
                if presence:
                    value_text += ' | ' + ','.join('yes' if value else 'no' for value in presence)
                print(f'{count:4d}  {value_text}')


if __name__ == '__main__':
    main()
