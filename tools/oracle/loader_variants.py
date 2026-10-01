#!/usr/bin/env python3
"""Build RAM sentinel fixtures for the stage asset-table initializer family.

The original SH-4 code calls 0x8C0A2E2C with literal asset IDs. That helper
accepts zero and -1 as distinct empty sentinels. Fixtures vary seven IDs
actually passed by each watched initializer; the original interpreter still
executes every call. Fixtures are development inputs, never acceptance data.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

ROOT = Path(__file__).resolve().parents[2]
IMAGE_BASE = 0x8c010000
TABLE_BASE = 0x0c2a1c3c


def word(image, address):
    return struct.unpack_from('<H', image, address - IMAGE_BASE)[0]


def ids_for(image, entry, size):
    ids = []
    for pc in range(entry, entry + size - 2, 2):
        op = word(image, pc)
        if (op & 0xff00) != 0x9400:
            continue
        # Each asset ID is loaded immediately before a JSR @R14.
        if word(image, pc + 2) != 0x4e0b:
            continue
        literal = pc + 4 + (op & 255) * 2
        asset_id = word(image, literal)
        if asset_id < 0x4000 and asset_id not in ids:
            ids.append(asset_id)
    return ids


def discover():
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    survey = {int(row['entry'], 16): row for row in
              json.loads((ROOT / 'extract/analysis/fifth_all_survey.json').read_text())['rows']}
    done = {int(row['entry'], 16) for row in
            csv.DictReader((ROOT / 'docs/decomp_status.csv').open())
            if row['status'].startswith('ported')}
    rows = []
    for row in csv.DictReader((ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open()):
        entry, size = int(row['entry'], 16), int(row['size'])
        if entry in done or size < 16 or not 0x8c0b0000 <= entry < 0x8c0bf000:
            continue
        if word(image, entry) != 0x4f22:  # save PR
            continue
        ids = ids_for(image, entry, size)
        if len(ids) < 7:
            continue
        hits = survey.get(entry, {}).get('hits', {})
        rows.append((entry, size, len(ids), hits.get('s20', 0), hits.get('s21', 0)))
    reached = [row for row in rows if row[3] and row[4]]
    from select_next import union
    baseline = list(map(tuple, json.loads((ROOT / 'extract/analysis/coverage.json').read_text())['ported_spans']))
    ranges = {}
    for row in csv.DictReader((ROOT / 'extract/analysis/function_body_ranges.csv').open()):
        ranges.setdefault(int(row['entry'], 16), []).append((int(row['start'], 16), int(row['end'], 16)))
    def gain(entries):
        return union(baseline + [span for entry in entries for span in ranges[entry]]) - union(baseline)
    core = [int(line.split()[1], 16) for line in (ROOT / 'tools/watch/vf3_sixth_loader.txt').read_text().splitlines() if line.startswith('pc ')]
    expanded = [int(line.split()[1], 16) for line in (ROOT / 'tools/watch/vf3_sixth_loader_expanded.txt').read_text().splitlines() if line.startswith('pc ')]
    extra = [int(line.split()[1], 16) for line in (ROOT / 'tools/watch/vf3_sixth_loader_extra.txt').read_text().splitlines() if line.startswith('pc ')]
    workers = [0x8c074b0e, 0x8c0750be]
    owned = set()
    for path in (ROOT / 'src/fight').glob('*adapters*.c'):
        owned.update(int(match, 16) for match in re.findall(r'^P_([0-9a-f]+):',
                     path.read_text(), re.M))
    from itertools import combinations
    state_names = sorted({name for item in survey.values() for name in item['hits']})
    pairs = []
    for a, b in combinations(state_names, 2):
        members = [row for row in rows if survey.get(row[0], {}).get('hits', {}).get(a, 0)
                   and survey.get(row[0], {}).get('hits', {}).get(b, 0)]
        pairs.append((sum(row[1] for row in members), len(members), a, b))
    print(f'{len(rows)} unported 0x8C0B PR-save literal-call bodies, {sum(r[1] for r in rows)} raw bytes')
    print(f'{len(reached)} reached in both states 20 and 21, {sum(r[1] for r in reached)} raw bytes')
    print(f'Frozen union gain: workers={gain(workers)}, core={gain(core)}, expanded+extra+workers={gain(expanded+extra+workers)}')
    print('No existing C owner:', [f'0x{row[0]:08x}' for row in rows if (row[0] & 0x1fffffff) not in owned])
    print('Best state pairs:', sorted(pairs, reverse=True)[:12])
    print('Other loader scenarios:', [(f'0x{row[0]:08x}', row[1],
          sorted(survey.get(row[0], {}).get('hits', {}))) for row in rows
          if row[0] not in set(expanded + extra)])
    for entry, size, count, s20, s21 in rows:
        print(f'0x{entry:08x} {size:5} B {count:3} literal IDs, s20={s20}, s21={s21}')


def generate(watch, output, count, at_entry=False):
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    sizes = {int(row['entry'], 16): int(row['size']) for row in
             csv.DictReader((ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open())}
    roots = [int(line.split()[1], 16) for line in Path(watch).read_text().splitlines()
             if line.startswith('pc ')]
    if len(roots) != len(set(roots)):
        raise ValueError('duplicate watched root')
    assigned = set()
    selected = {}
    for root in roots:
        ids = [value for value in ids_for(image, root, sizes[root]) if value not in assigned]
        if len(ids) < 7:
            raise ValueError(f'0x{root:08x}: only {len(ids)} disjoint asset IDs')
        selected[f'0x{root:08x}'] = ids[:7]
        assigned.update(ids[:7])
    out = Path(output)
    out.mkdir(parents=True, exist_ok=True)
    patches = []
    for variant in range(count):
        path = out / f'variant_{variant:03d}.patch'
        lines = [f'# stage asset sentinel fixture {variant}']
        for root, ids in selected.items():
            for bit, asset_id in enumerate(ids):
                prefix = root + ' ' if at_entry else ''
                lines.append(f'{prefix}0x{TABLE_BASE + 4 * asset_id:08x} 0x{0xffffffff if variant & (1 << bit) else 0:08x}')
        path.write_text('\n'.join(lines) + '\n', encoding='ascii')
        patches.append({'variant': variant, 'path': str(path),
                        'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    (out / 'manifest.json').write_text(json.dumps({
        'watch': str(watch), 'image_sha256': hashlib.sha256(image).hexdigest(),
        'table_base': f'0x{TABLE_BASE:08x}', 'placement': 'entry' if at_entry else 'startup',
        'roots': selected, 'patches': patches,
    }, indent=1) + '\n')
    print(f'{len(roots)} roots, {len(assigned)} disjoint asset IDs, {count} fixtures in {out}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--watch', default='tools/watch/vf3_sixth_loader_expanded.txt')
    parser.add_argument('--out', default='extract/analysis/sixth_loader_entry_variants')
    parser.add_argument('--count', type=int, default=64)
    parser.add_argument('--discover', action='store_true')
    parser.add_argument('--entry', dest='entry', action='store_true', help='apply each root fixture at its function entry (default)')
    parser.add_argument('--startup', dest='entry', action='store_false', help='apply fixture before the first observed instruction')
    parser.set_defaults(entry=True)
    args = parser.parse_args()
    if args.discover:
        discover()
        raise SystemExit(0)
    if not 1 <= args.count <= 128:
        parser.error('count must be 1..128')
    generate(ROOT / args.watch, ROOT / args.out, args.count, args.entry)
