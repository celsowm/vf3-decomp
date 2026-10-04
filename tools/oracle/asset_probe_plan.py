#!/usr/bin/env python3
"""Rotate original-image asset initializers through a rollback-safe trigger.

Descriptor lists and asset table sentinels are explicit fixtures. Their live
RAM pages are restored by the oracle; no page is assumed to be unused.
The initializer and its lookup helper execute in the original interpreter.
"""
import argparse
import csv
import struct
from pathlib import Path

from loader_variants import ROOT, TABLE_BASE


def asset_ids(image, entry, size):
    """Include calls whose delay-slot load needs an intervening offset setup."""
    def word(pc):
        return struct.unpack_from('<H', image, pc - 0x8c010000)[0]
    ids = set()
    for pc in range(entry, entry + size - 8, 2):
        op = word(pc)
        if op & 0xff00 == 0x9400 and any(
                word(pc + delta) == 0x4e0b for delta in (2, 4, 6)):
            ids.add(word(pc + 4 + (op & 255) * 2))
    if any(asset >= 0x4000 for asset in ids):
        raise ValueError(f'{entry:08x}: invalid asset ID')
    return sorted(ids)


def generate(watch, output, trigger, variants, base=0x0c400000, holdout=False):
    roots = [int(line.split()[1], 16) for line in watch.read_text().splitlines()
             if line.startswith('pc ')]
    sizes = {int(row['entry'], 16): int(row['size']) for row in csv.DictReader(
        (ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open())}
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    lines = ['# Original-image initializer probes; rollback replays the trigger.',
             f'entry 0x{trigger:08x} 0x{roots[0]:08x}']
    first = True
    for variant in range(variants):
        for root in roots:
            ids = asset_ids(image, root, sizes[root])
            if len(ids) < 7:
                raise ValueError(f'{root:08x}: not an asset initializer')
            if not first:
                lines.append(f'seed 0x{trigger:08x}')
            first = False
            lines.extend([f'target 0x{trigger:08x} 0x{root:08x}',
                          f'reg 0x{trigger:08x} pr 0x{trigger + 2:08x}',
                          f'reg 0x{trigger:08x} r4 0x{base + 0x2000:08x}'])
            # The native sibling descriptor has two list pointers at +16/+20.
            # The unconditional installer requires a resource pointer even
            # when the destination table is empty. Its +4 flag chooses whether
            # the table receives the resource itself or its first pointer.
            fixture = {base + 0x2000 + off: 0 for off in range(0, 32, 4)}
            fixture.update({base + 0x2010: base,
                            base + 0x2014: base + 0x1000})
            for list_base in (base, base + 0x1000):
                fixture.update({list_base + 4 * index:
                    base + 0x3000 + (32 if holdout and index % 2 else 0)
                    for index in range(256)})
            fixture.update({base + 0x3000 + off: 0 for off in range(0, 64, 4)})
            fixture.update({base + 0x3000: base + 0x3100,
                            base + 0x3004: variant & 1,
                            base + 0x3020: base + 0x3180,
                            base + 0x3024: (variant >> 1) & 1})
            for addr, value in fixture.items():
                lines.append(f'ram 0x{trigger:08x} 0x{addr:08x} 0x{value:08x}')
            for index, asset in enumerate(ids):
                value = 0xffffffff if (variant >> (index % 7)) & 1 else 0
                if holdout and index % 3 == 2:
                    value = base + 0x3100
                lines.append(f'ram 0x{trigger:08x} '
                             f'0x{TABLE_BASE + 4 * asset:08x} 0x{value:08x}')
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    print(f'{len(roots)} targets, {variants} sentinel variants each: {output}')


if __name__ == '__main__':
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', required=True, type=Path)
    ap.add_argument('--out', required=True, type=Path)
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c048284)
    ap.add_argument('--variants', type=int, default=64)
    ap.add_argument('--fixture-base', type=lambda x: int(x, 16), default=0x0c400000)
    ap.add_argument('--holdout', action='store_true')
    a = ap.parse_args()
    if not 1 <= a.variants <= 128:
        ap.error('--variants must be 1..128')
    if a.fixture_base % 4096 or not 0x0c000000 <= a.fixture_base <= 0x0cffc000:
        ap.error('--fixture-base must leave four aligned pages inside main RAM')
    generate(a.watch, a.out, a.trigger, a.variants, a.fixture_base, a.holdout)
