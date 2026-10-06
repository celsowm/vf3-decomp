"""Recover actual probed parent groups for eligible observed development roots."""
import argparse
import json
from pathlib import Path
from campaign_io import read_watch, write_watch


def select(report, roots, single_scenario=False):
    selected = {}
    for root in sorted(roots):
        rows = [row for row in report['entries']
                if int(row['entry'], 16) == root and
                (not row['reasons'] if not single_scenario else
                 row['reasons'] == ['fewer than two scenarios'])]
        if not rows:
            raise ValueError(f'no eligible original development corpus: {root:#x}')
        row = max(rows, key=lambda item: item['distinct_cases'])
        parent_watch = Path(row['directory']) / 'probe_watch.txt'
        if not parent_watch.is_file():
            raise ValueError(f'missing original probe-parent watch: {parent_watch}')
        parents = read_watch(parent_watch)
        if not parents:
            raise ValueError(f'empty original probe-parent watch: {parent_watch}')
        selected[hex(root)] = dict(parents=[hex(parent) for parent in sorted(parents)],
                                  development_directory=row['directory'])
    return selected


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report', type=Path, required=True)
    parser.add_argument('--watch', type=Path)
    parser.add_argument('--single-scenario', action='store_true',
                        help='recover complete-body roots needing a second development scenario')
    parser.add_argument('--observed-out', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    report = json.loads(args.report.read_text())
    if not args.watch and not args.single_scenario:
        parser.error('--watch is required unless --single-scenario is selected')
    roots = read_watch(args.watch) if args.watch else {
        int(row['entry'], 16) for row in report['entries']
        if row['reasons'] == ['fewer than two scenarios']}
    selected = select(report, roots, args.single_scenario)
    parents = {int(parent, 16) for row in selected.values() for parent in row['parents']}
    write_watch(args.out, parents, 'Original development probe parents for fresh acceptance; no new credit.')
    if args.observed_out:
        write_watch(args.observed_out, roots, 'Selected original observed roots; no new credit.')
    args.out.with_suffix('.json').write_text(json.dumps(dict(advisory=True,
        selected=selected), indent=1) + '\n')
    print(f'{len(selected)} eligible observed roots; {len(parents)} actual probed parents')
