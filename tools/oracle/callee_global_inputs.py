"""Infer bounded scalar inputs read by real static callees, never outputs.

Root-only operand inference misses globals used inside called helpers. This
planner follows original static edges, reuses typed operand inference, and
exports only mutable global scalar words. It never installs callback stubs,
changes code, supplies expected state, or grants coverage credit.
"""
import argparse
import csv
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from batch_plan import implementation_graph
from campaign_io import read_watch
from pointer_seeds import fixture


def scalar_domain(initial, hints, address):
    masks = hints['flags'].get(address, ())
    values = [initial, 0, 1, 2, 7, 8, 15, 31]
    for mask in masks:
        values.extend((mask, mask & -mask, (~mask) & 0xffffffff))
    if masks:
        combined = 0
        for mask in masks:
            combined |= mask
        values.append(combined)
    for comparison in hints['comparisons']:
        value = comparison['value']
        if 0 <= value <= 0xffff:
            values.extend(((value - 1) & 0xffffffff, value, value + 1))
    # Byte/halfword accesses retain their actual subword positions.
    widths = [(offset, width) for offset, width in hints['narrow_widths'].items()
              if offset & ~3 == address]
    if widths:
        words = [initial]
        for value in values:
            word = initial
            for offset, width in widths:
                shift = (offset & 3) * 8
                mask = ((1 << (width * 8)) - 1) << shift
                word = (word & ~mask) | ((value << shift) & mask)
            words.append(word)
        values = words
    return list(dict.fromkeys(value & 0xffffffff for value in values))[:48]


def generate(watch, out, depth=2, maximum_callees=24, maximum_fields=48):
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    with (ROOT / 'extract/analysis/sh4_resolved.csv').open() as stream:
        resolved = {int(row['site'], 16): int(row['target'], 16) | 0x80000000
                    for row in csv.DictReader(stream) if row['class'] == 'STATIC'}
    scan = implementation_graph(image, resolved)
    cache, overrides, report = {}, {}, {}
    floor = 0x0c010000 + len(image)
    for root in sorted(read_watch(watch)):
        visited, pending, fields, sources = {root}, [(root, 0)], {}, {}
        while pending and len(visited) <= maximum_callees:
            entry, level = pending.pop(0)
            if level >= depth:
                continue
            _, targets, _ = scan(entry)
            for target in sorted(targets):
                target |= 0x80000000
                if target in visited or len(visited) > maximum_callees:
                    continue
                visited.add(target)
                pending.append((target, level + 1))
                if target not in cache:
                    cache[target] = fixture(target, 'zero', True, True)
                _, words, hints = cache[target]
                for address, value in sorted(words.items()):
                    if not floor <= address < 0x0c400000:
                        continue
                    # Pointer and callback slots are not scalar inputs, even
                    # when their original type could not be fully inferred.
                    if 0x0c000000 <= (value & 0x1fffffff) < 0x10000000:
                        continue
                    if address in hints['floats']:
                        continue
                    if address not in fields and len(fields) >= maximum_fields:
                        continue
                    domain = scalar_domain(value, hints, address)
                    fields[address] = list(dict.fromkeys(fields.get(address, []) + domain))[:48]
                    sources.setdefault(address, []).append(hex(target))
        overrides[hex(root)] = {hex(address): dict(values=values,
            stride=1 << (index % 6), phase=index // 6)
            for index, (address, values) in enumerate(sorted(fields.items()))}
        report[hex(root)] = dict(callees=sorted(map(hex, visited - {root})),
                                fields={hex(a): values for a, values in sources.items()})
        print(f'{root:#x}: {len(visited) - 1} callees, {len(fields)} scalar globals', flush=True)
    out.write_text(json.dumps(overrides, indent=1) + '\n')
    out.with_suffix('.sources.json').write_text(json.dumps(dict(advisory=True,
        input_only=True, depth=depth, maximum_callees=maximum_callees,
        maximum_fields=maximum_fields, roots=report), indent=1) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--depth', type=int, choices=range(1, 5), default=2)
    parser.add_argument('--maximum-callees', type=int, choices=range(1, 65), default=24)
    parser.add_argument('--maximum-fields', type=int, choices=range(1, 65), default=48)
    args = parser.parse_args()
    generate(args.watch, args.out, args.depth, args.maximum_callees, args.maximum_fields)
