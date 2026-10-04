"""Export selected complete runs from a capture batch, retaining run provenance."""
import argparse
import json
from pathlib import Path

from capsules import convert
from campaign_io import read_watch


def export(batch_path, run_names, out, watch=None):
    batch_path = Path(batch_path)
    batch = json.loads((batch_path / 'batch_manifest.json').read_text())
    available = {run['name']: run for run in batch['runs']}
    if len(set(run_names)) != len(run_names):
        raise ValueError('duplicate --run name')
    missing = sorted(set(run_names) - set(available))
    if missing:
        raise ValueError('unknown run name(s): ' + ', '.join(missing))
    runs = [available[name] for name in run_names]
    for run in runs:
        if run.get('returncode') != 0 or not run.get('frame_complete', False):
            raise ValueError(f"capture is not complete: {run['name']}")
    paths = [str(Path(run['capsule']).resolve()) for run in runs]
    if any(not Path(path).is_file() for path in paths):
        raise FileNotFoundError('selected capsule not found')
    out = Path(out)
    if out.exists():
        raise FileExistsError(f'output already exists: {out}')
    entries = read_watch(watch) if watch else None
    convert(paths, out, entries)
    (out / 'batch_manifest.json').write_text(json.dumps({
        'name': out.name,
        'watch': batch['watch'],
        'source_batch': str(batch_path.resolve()),
        'selected_runs': run_names,
        'runs': runs,
    }, indent=1) + '\n')
    print(f'{out}: exported {len(runs)} run(s) from {batch_path}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('batch', type=Path)
    parser.add_argument('--run', action='append', required=True,
                        help='exact run name from batch_manifest.json; repeatable')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--watch', type=Path,
                        help='optional root watch to export selected entries')
    args = parser.parse_args()
    export(args.batch, args.run, args.out, args.watch)


if __name__ == '__main__':
    main()
