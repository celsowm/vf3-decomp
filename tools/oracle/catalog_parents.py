"""Recover actual original probe groups from advisory retained-capture leads.

Keeps development corpora separate from acceptance. Outputs are leads only;
merge and recheck original records before granting any coverage credit.
"""
import argparse
import json
from pathlib import Path
from campaign_io import read_watch, write_watch


def select(catalog, excluded=()):
    selected = {}
    skipped = {}
    for candidate in catalog['candidates']:
        entry = int(candidate['entry'], 16)
        if entry in excluded:
            continue
        usable = [row for row in candidate['corpora']
                  if (Path(row['directory']) / 'probe_watch.txt').is_file()
                  and not any(word in row['directory'].lower()
                              for word in ('accept', 'holdout', 'held'))]
        if not usable:
            skipped[hex(entry)] = 'no retained original probe-parent watch'
            continue
        row = max(usable, key=lambda item: item['distinct_cases'])
        parents = read_watch(Path(row['directory']) / 'probe_watch.txt')
        if not parents:
            raise ValueError(f'empty original parent watch for {entry:#x}')
        selected[hex(entry)] = dict(directory=row['directory'],
                                   parents=[hex(parent) for parent in sorted(parents)])
    return selected, skipped


def restore(data, excluded=()):
    selected = {entry: row for entry, row in data['selected'].items()
                if int(entry, 16) not in excluded}
    for entry, row in selected.items():
        if any(word in row['directory'].lower() for word in ('accept', 'holdout', 'held')):
            raise ValueError(f'parent source is not development evidence for {entry}')
        original = read_watch(Path(row['directory']) / 'probe_watch.txt')
        if not row['parents'] or {int(parent, 16) for parent in row['parents']} != original:
            raise ValueError(f'original parent mapping changed for {entry}')
    return selected


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    inputs = parser.add_mutually_exclusive_group(required=True)
    inputs.add_argument('--catalog', type=Path)
    inputs.add_argument('--sources', type=Path,
                        help='reuse a previously selected original parent mapping')
    parser.add_argument('--watch', type=Path, help='restrict selection to these observed roots')
    parser.add_argument('--exclude-watch', type=Path, action='append', default=[])
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--parents-out', type=Path, required=True)
    parser.add_argument('--observed-out', type=Path, required=True)
    args = parser.parse_args()
    excluded = {entry for path in args.exclude_watch for entry in read_watch(path)}
    if args.catalog:
        selected, skipped = select(json.loads(args.catalog.read_text()), excluded)
    else:
        selected = restore(json.loads(args.sources.read_text()), excluded)
        skipped = {}
    if args.watch:
        wanted = read_watch(args.watch)
        selected = {entry: row for entry, row in selected.items() if int(entry, 16) in wanted}
        missing = wanted - excluded - {int(entry, 16) for entry in selected}
        if missing:
            raise ValueError('no original parent mapping for ' + ','.join(hex(entry) for entry in sorted(missing)))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(dict(advisory=True, selected=selected,
                                      skipped=skipped), indent=1) + '\n')
    write_watch(args.parents_out,
                {int(parent, 16) for row in selected.values() for parent in row['parents']},
                'Retained original probe parents; no proof or credit.')
    write_watch(args.observed_out, {int(entry, 16) for entry in selected},
                'Retained development roots needing raw revalidation; no credit.')
    print(f'{len(selected)} selected retained leads; {len(skipped)} skipped')


if __name__ == '__main__':
    main()
