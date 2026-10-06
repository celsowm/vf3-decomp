"""Plan cleanup of old original captures that produced zero valid specimens.

Never deletes files. All bound development/acceptance corpus sources are
protected. Current target captures are excluded. The JSON plan can be reviewed
and applied with native filesystem tools, preserving the audit record.
"""
import argparse
import ctypes
import json
import os
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[2]


def strings(value):
    if isinstance(value, str):
        yield value
    elif isinstance(value, dict):
        for item in value.values():
            yield from strings(item)
    elif isinstance(value, list):
        for item in value:
            yield from strings(item)


def allocated(path):
    if os.name != 'nt':
        return path.stat().st_size
    high = ctypes.c_ulong()
    function = ctypes.WinDLL('kernel32', use_last_error=True).GetCompressedFileSizeW
    function.argtypes = [ctypes.c_wchar_p, ctypes.POINTER(ctypes.c_ulong)]
    function.restype = ctypes.c_ulong
    ctypes.set_last_error(0)
    low = function(str(path), ctypes.byref(high))
    if low == 0xffffffff and ctypes.get_last_error():
        raise ctypes.WinError(ctypes.get_last_error())
    return (high.value << 32) | low


def manifests(analysis):
    # Captures use a flat batch or one isolated group directory. Do not walk
    # millions of specimen files, ROMs, reference clones or junctions.
    for entry in os.scandir(analysis):
        if not entry.is_dir(follow_symlinks=False):
            continue
        child = Path(entry.path)
        if child.is_symlink() or (hasattr(child, 'is_junction') and child.is_junction()):
            continue
        manifest = child / 'capsule_manifest.json'
        if manifest.is_file():
            yield manifest
            continue
        for group in os.scandir(child):
            if group.is_dir(follow_symlinks=False):
                group_path = Path(group.path)
                if group_path.is_symlink() or (hasattr(group_path, 'is_junction') and group_path.is_junction()):
                    continue
                manifest = group_path / 'capsule_manifest.json'
                if manifest.is_file():
                    yield manifest


def bound_sources(root):
    root = Path(root).resolve()
    analysis = (root / 'extract/analysis').resolve()
    tracked = subprocess.run(['git', 'ls-files', 'tools/oracle/*.json'],
                             cwd=root, check=True, capture_output=True,
                             text=True).stdout.splitlines()
    # A newly promoted milestone is proof evidence before its git commit too.
    metadata = sorted({root / name for name in tracked} |
                      set((root / 'tools/oracle').glob('*.json'))) + [root / 'tools/golden_bindings.json']
    bound_directories = set()
    direct_sources = set()
    for path in metadata:
        for value in strings(json.loads(path.read_text())):
            if (value.endswith('.bin') and
                    value.replace('\\', '/').rsplit('/', 1)[-1].startswith('capsule_')):
                source = Path(value)
                direct_sources.add((source if source.is_absolute() else root / source).resolve())
            if value.endswith('.cases'):
                case = Path(value)
                case = case if case.is_absolute() else root / case
                resolved = case.resolve()
                if resolved.is_relative_to(analysis):
                    bound_directories.add(resolved.parent)
    return bound_directories, direct_sources


def plan(root=ROOT, minimum_age_hours=24):
    root = Path(root).resolve()
    analysis = (root / 'extract/analysis').resolve()
    bound_directories, direct_sources = bound_sources(root)
    protected = direct_sources
    print(f'{len(bound_directories)} bound corpus directories indexed', flush=True)
    captures = list(manifests(analysis))
    print(f'{len(captures)} retained capture manifests found', flush=True)
    empty_inputs = []
    malformed = []
    for index, path in enumerate(captures):
        try:
            data = json.loads(path.read_text())
        except (ValueError, OSError) as error:
            malformed.append(dict(path=str(path), error=str(error)))
            continue
        if path.parent.resolve() in bound_directories:
            source_names = {value for value in strings(data)
                            if value.endswith('.bin') and
                            value.replace('\\', '/').rsplit('/', 1)[-1].startswith('capsule_')}
            protected.update(Path(value).resolve() for value in source_names)
        if data.get('entries') is not None and not any(data['entries'].values()):
            empty_inputs.extend((path, value) for value in data.get('inputs', []))
        if index % 250 == 249:
            print(f'{index + 1}/{len(captures)} manifests checked', flush=True)
    cutoff = time.time() - minimum_age_hours * 3600
    candidates = {}
    for manifest, value in empty_inputs:
        path = Path(value).resolve()
        if (path.parent != analysis or not path.name.startswith('capsule_')
                or path.suffix != '.bin' or path in protected
                or 'target' in path.name.lower() or not path.is_file()
                or path.stat().st_mtime > cutoff):
            continue
        candidates[str(path)] = dict(path=str(path), bytes=path.stat().st_size,
                                     allocated_bytes=allocated(path),
                                     reason='old corpus has zero valid specimens',
                                     manifest=str(manifest))
    rows = sorted(candidates.values(), key=lambda row: -row['allocated_bytes'])
    return dict(dry_run=True, analysis=str(analysis), minimum_age_hours=minimum_age_hours,
                protected_sources=len(protected), bound_directories=len(bound_directories),
                candidates=rows, allocated_bytes=sum(row['allocated_bytes'] for row in rows),
                malformed_manifests=malformed)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--minimum-age-hours', type=float, default=24)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    if args.minimum_age_hours < 0:
        parser.error('age must be nonnegative')
    report = plan(minimum_age_hours=args.minimum_age_hours)
    args.out.write_text(json.dumps(report, indent=1) + '\n')
    print(f"{len(report['candidates'])} old empty-corpus capsules; "
          f"{report['allocated_bytes'] / 2**30:.2f} GiB reclaimable; "
          f"{report['protected_sources']} bound sources protected; no files deleted")
    for row in report['candidates'][:15]:
        print(f"{row['allocated_bytes'] / 2**20:.1f} MiB {Path(row['path']).name}")


if __name__ == '__main__':
    main()
