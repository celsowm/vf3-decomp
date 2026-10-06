"""Exclude development roots whose observed closure uses forbidden fixture PCs.

This exports a conservative watch, never changes specimens or grants credit.
Forbidden addresses are normalized across SH-4 cached/uncached aliases.
"""
import argparse
import json
from pathlib import Path
from campaign_io import read_watch, write_watch


def select(directory, roots, forbidden):
    forbidden = {pc & 0x1fffffff for pc in forbidden}
    selected, excluded = set(), {}
    for entry in sorted(roots):
        path = Path(directory) / f'f_{entry:08x}.ops.json'
        if not path.is_file():
            excluded[hex(entry)] = 'no captured operation closure'
            continue
        operations = {int(pc, 16) & 0x1fffffff for pc in json.loads(path.read_text())}
        hits = operations & forbidden
        if hits:
            excluded[hex(entry)] = [f'0x{pc:08x}' for pc in sorted(hits)]
        else:
            selected.add(entry)
    return selected, excluded


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--directory', type=Path, required=True)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--forbidden-pc', type=lambda value: int(value, 0), action='append', required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    selected, excluded = select(args.directory, read_watch(args.watch), args.forbidden_pc)
    write_watch(args.out, selected, 'Observed closure excludes specified fixture PCs; no new credit.')
    args.report.write_text(json.dumps(dict(advisory=True, excluded=excluded,
        selected=[hex(entry) for entry in sorted(selected)]), indent=1) + '\n')
    print(f'{len(selected)} roots retained; {len(excluded)} excluded')


if __name__ == '__main__':
    main()
