"""Suggest nearby original prologues for frozen entries inside larger functions."""
import argparse
import bisect
import csv
import json
from pathlib import Path
import struct
from campaign_io import read_watch, write_watch

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x8c010000


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('watches', nargs='+', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    parser.add_argument('--distance', type=lambda s: int(s, 0), default=8192)
    parser.add_argument('--start', type=int, default=0)
    parser.add_argument('--limit', type=int)
    parser.add_argument('--children-out', type=Path,
                        help='watch selected parents and their frozen children together')
    args = parser.parse_args()
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    words = struct.unpack(f'<{len(image) // 2}H', image[:len(image) & ~1])
    # Saving PR or the callee-saved r14 is an advisory prologue signal.
    candidates = [BASE + index * 2 for index, word in enumerate(words)
                  if word in (0x2fe6, 0x4f22)]
    credited = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if row['status'].startswith('ported')}
    roots = {entry for watch in args.watches for entry in read_watch(watch)} - credited
    parents, unmapped = {}, []
    for entry in sorted(roots):
        index = bisect.bisect_right(candidates, entry) - 1
        if index < 0 or entry - candidates[index] > args.distance:
            unmapped.append(hex(entry))
            continue
        parent = candidates[index]
        # A PR save commonly follows r14/r13 setup. Prefer the nearest r14
        # save within the short prefix, without crossing another return.
        if words[(parent - BASE) // 2] == 0x4f22:
            for address in range(parent - 2, max(BASE, parent - 32) - 1, -2):
                word = words[(address - BASE) // 2]
                if word == 0x000b or (address >= BASE + 2 and words[(address - BASE) // 2 - 1] == 0x000b):
                    break
                if word == 0x2fe6:
                    parent = address
                    break
        parents.setdefault(parent, []).append(entry)
    selected = sorted(parents, key=lambda parent: (-len(parents[parent]), parent))
    selected = selected[args.start:None if args.limit is None else args.start + args.limit]
    write_watch(args.out, selected,
                'Advisory prologue candidates; inspect and capture before any coverage credit.',
                preserve_order=True)
    if args.children_out:
        write_watch(args.children_out, {entry for parent in selected
                    for entry in [parent] + parents[parent]},
                    'Selected original prologues and frozen children; advisory only.')
    args.report.write_text(json.dumps(dict(advisory=True, unmapped=unmapped,
        parents={hex(parent): [hex(entry) for entry in children]
                 for parent, children in sorted(parents.items())}), indent=1) + '\n')
    print(f'{len(roots)} uncredited roots; {len(parents)} prologue candidates; {len(unmapped)} unmapped')
    for parent in sorted(parents, key=lambda parent: (-len(parents[parent]), parent))[:20]:
        print(f'{parent:08x}: {len(parents[parent])} frozen entries')


if __name__ == '__main__':
    main()
