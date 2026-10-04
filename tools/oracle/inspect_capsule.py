"""Inspect architectural state and captured RAM for selected raw invocations."""
import argparse
from collections import Counter
import struct
from pathlib import Path
from capsules import records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsules', nargs='+', type=Path)
    parser.add_argument('--entry', type=lambda s: int(s, 0), required=True)
    parser.add_argument('--invocation', type=int)
    parser.add_argument('--valid-only', action='store_true')
    parser.add_argument('--limit', type=int)
    parser.add_argument('--summary', nargs='*', metavar='REG',
                        help='summarize input/output tuples for selected GPRs (for example r0 r1)')
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
    registers = list(range(16)) if args.summary == [] else [
        int(value[1:], 0) if value.lower().startswith('r') else int(value, 0)
        for value in (args.summary or [])]
    if any(not 0 <= register < 16 for register in registers):
        parser.error('summary registers must be GPRs r0-r15')
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
                summary[(tuple(before[r] for r in registers),
                         tuple(after[r] for r in registers), presence)] += 1
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
            labels = ','.join(f'r{register}' for register in registers)
            print(f'{shown} records; GPR summary ({labels})')
            for (inputs, outputs, presence), count in sorted(summary.items(), key=lambda item: (-item[1], item[0])):
                before_text = ','.join(f'{value:08x}' for value in inputs)
                after_text = ','.join(f'{value:08x}' for value in outputs)
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
