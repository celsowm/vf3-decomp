"""Combine PC roots from watch files, with optional exclusions and extra roots."""
import argparse
from campaign_io import read_watch, write_watch


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('watches', nargs='*')
    parser.add_argument('--entry', action='append', default=[], help='extra hex entry (repeatable)')
    parser.add_argument('--exclude', action='append', default=[], help='watch file to subtract (repeatable)')
    parser.add_argument('--out', required=True)
    args = parser.parse_args()
    entries = {int(entry, 16) | 0x80000000 for entry in args.entry}
    for path in args.watches:
        entries.update(read_watch(path))
    for path in args.exclude:
        entries.difference_update(read_watch(path))
    write_watch(args.out, entries, 'Combined capture roots; selection grants no coverage credit.')
    print(f'{len(entries)} roots -> {args.out}')


if __name__ == '__main__':
    main()
