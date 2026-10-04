"""Select uncredited frozen entries within an original-image address interval."""
import argparse
import csv
from pathlib import Path
from campaign_io import write_watch

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--start', type=lambda s: int(s, 16), required=True)
    parser.add_argument('--end', type=lambda s: int(s, 16), required=True)
    parser.add_argument('--parent', type=lambda s: int(s, 16), action='append', default=[])
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    start, end = args.start | 0x80000000, args.end | 0x80000000
    if start >= end:
        raise ValueError('empty or reversed interval')
    credited = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if row['status'].startswith('ported')}
    entries = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open())
        if start <= int(row['entry'], 16) < end and int(row['entry'], 16) not in credited}
    children = len(entries)
    entries.update(parent | 0x80000000 for parent in args.parent)
    write_watch(args.out, entries, 'Frozen entries reached through original prologues; capture and replay required.')
    print(f'{children} uncredited frozen entries; {len(entries)} total watched entries')


if __name__ == '__main__':
    main()
