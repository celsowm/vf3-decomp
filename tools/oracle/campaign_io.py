"""Shared capture discovery and SH-4 watch-list I/O (standard library only)."""
import json
from pathlib import Path


def attempted_entries(watches=(), progress_files=()):
    """Read prior roots consistently, including grouped progress and RAM aliases."""
    entries = {entry for watch in watches for entry in read_watch(watch)}
    for path in progress_files:
        for row in json.loads(Path(path).read_text()):
            for entry in row.get('entries', [row.get('entry')]):
                if entry is not None:
                    entries.add((int(entry, 16) if isinstance(entry, str) else entry) | 0x80000000)
    return entries


def discover(inputs, manifest='capsule_manifest.json'):
    """Find exact manifest parents, including nested isolated capture roots."""
    directories = set()
    for item in inputs:
        path = Path(item).resolve()
        if not path.exists():
            raise FileNotFoundError(path)
        found = ([path] if path.is_file() and path.name == manifest else
                 sorted(path.rglob(manifest)) if path.is_dir() else [])
        if not found:
            raise ValueError(f'{path}: no {manifest} found')
        directories.update(p.parent for p in found)
    return sorted(directories)


def read_watch(path):
    entries = set()
    for number, line in enumerate(Path(path).read_text().splitlines(), 1):
        words = line.split('#', 1)[0].split()
        if not words or words[0] != 'pc':
            continue
        if len(words) != 2:
            raise ValueError(f'{path}:{number}: expected pc <hex address>')
        entries.add(int(words[1], 16) | 0x80000000)
    return entries


def write_watch(path, entries, comment, preserve_order=False):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    ordered = list(dict.fromkeys(entries)) if preserve_order else sorted(set(entries))
    path.write_text('# ' + comment + '\n' + ''.join(
        f'pc 0x{entry:08x}\n' for entry in ordered), encoding='utf-8')


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description='Merge watch lists without duplicate roots.')
    parser.add_argument('watches', nargs='+', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--comment', default='Union of supplied watch lists; no coverage credit.')
    args = parser.parse_args()
    entries = {entry for watch in args.watches for entry in read_watch(watch)}
    write_watch(args.out, entries, args.comment)
    print(f'{len(entries)} unique roots')
