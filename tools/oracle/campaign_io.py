"""Shared capture discovery and SH-4 watch-list I/O (standard library only)."""
from pathlib import Path


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


def write_watch(path, entries, comment):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text('# ' + comment + '\n' + ''.join(
        f'pc 0x{entry:08x}\n' for entry in sorted(set(entries))), encoding='utf-8')


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
