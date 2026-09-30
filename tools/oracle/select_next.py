#!/usr/bin/env python3
"""Rank complete capsule entries by new frozen-baseline C body coverage."""
import argparse
import csv
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def union(spans):
    end = total = 0
    for a, z in sorted(spans):
        total += max(0, z - max(a, end))
        end = max(end, z)
    return total


def select(directories, output, minimum):
    records_by_entry, source_scenario, incomplete, nondeterministic = {}, {}, set(), set()
    for directory in map(Path, directories):
        manifest = json.loads((directory / 'capsule_manifest.json').read_text())
        batch = json.loads((directory / 'batch_manifest.json').read_text())
        source_scenario.update({str(Path(r['capsule']).resolve()): (r['state'], r['play']) for r in batch['runs']})
        incomplete.update(int(r['entry'], 16) | 0x80000000 for run in manifest['runs'] for r in run.get('incomplete', []))
        nondeterministic.update(int(e, 16) for e in manifest.get('nondeterministic_entries', []))
        for entry, records in manifest['entries'].items():
            records_by_entry.setdefault(entry, []).extend(records)
    baseline = list(map(tuple, json.loads((ROOT / 'extract/analysis/coverage.json').read_text())['ported_spans']))
    old = union(baseline)
    ranges = {}
    for row in csv.DictReader((ROOT / 'extract/analysis/function_body_ranges.csv').open()):
        ranges.setdefault(int(row['entry'], 16), []).append((int(row['start'], 16), int(row['end'], 16)))
    chosen, one_scenario, short = [], [], []
    for entry, records in records_by_entry.items():
        pc = int(entry, 16)
        scenarios = {source_scenario.get(str(Path(src['source']).resolve()))
                     for record in records for src in record['sources']}
        if pc in incomplete or pc in nondeterministic or pc not in ranges:
            continue
        gain = union(baseline + ranges[pc]) - old
        if len(records) >= minimum and len(scenarios) == 1 and gain:
            one_scenario.append((gain, pc, len(records)))
        if len(records) < minimum and len(scenarios) >= 2 and gain:
            short.append((gain, pc, len(records), len(scenarios)))
        if len(records) < minimum or len(scenarios) < 2:
            continue
        if gain:
            chosen.append((pc, len(records), len(scenarios), gain))
    chosen.sort(key=lambda item: (-item[3], item[0]))
    gain = union(baseline + [span for pc, _, _, _ in chosen for span in ranges[pc]]) - old
    output = Path(output)
    output.write_text('# Complete, distinct development cases in two state/input scenarios.\n' +
                      ''.join(f'pc 0x{pc:08x}\n' for pc, _, _, _ in chosen))
    print(f'{len(chosen)} candidates; potential union +{gain} B; quarantined={[hex(e) for e in sorted(nondeterministic)]}')
    for pc, cases, scenarios, size in chosen[:60]:
        print(f'0x{pc:08x} {size:5} B {cases:4} cases {scenarios} scenarios')
    print('one scenario:', sorted(one_scenario, reverse=True)[:20])
    print('under minimum:', sorted(short, reverse=True)[:20])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directories', nargs='+')
    parser.add_argument('--out', required=True)
    parser.add_argument('--min-cases', type=int, default=64)
    args = parser.parse_args()
    select(args.directories, args.out, args.min_cases)
