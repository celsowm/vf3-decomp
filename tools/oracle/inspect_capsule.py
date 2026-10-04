"""Inspect architectural state and captured RAM for selected raw invocations."""
import argparse
import struct
from pathlib import Path
from capsules import records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsules', nargs='+', type=Path)
    parser.add_argument('--entry', type=lambda s: int(s, 0), required=True)
    parser.add_argument('--invocation', type=int)
    parser.add_argument('--valid-only', action='store_true')
    parser.add_argument('--limit', type=int, default=1)
    parser.add_argument('--word', type=lambda s: int(s, 0), action='append', default=[])
    parser.add_argument('--stack-words', type=int, default=8)
    args = parser.parse_args()
    shown = 0
    for path in args.capsules:
        for record in records(path):
            if record['entry'] | 0x80000000 != args.entry | 0x80000000:
                continue
            if args.invocation is not None and record['id'] != args.invocation:
                continue
            if args.valid_only and record['flags']:
                continue
            before = struct.unpack(f"<{record['nstate']}I", record['before'])
            after = struct.unpack(f"<{record['nstate']}I", record['after'])
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
            shown += 1
            if shown >= args.limit:
                return


if __name__ == '__main__':
    main()
