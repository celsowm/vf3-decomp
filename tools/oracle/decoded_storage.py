"""Plan pruning old, unbound RAM shadow caches while keeping original captures.

Leaves opcode maps, case headers, manifests and original capsules in place.
Bound proofs, current target corpora and explicitly retained leads are excluded.
Decoded shadows can be rebuilt from the original capsules with merge_batches.
"""
import argparse
import json
import os
from pathlib import Path
import re
import time
from capture_storage import ROOT, allocated, bound_sources, manifests

SHADOW = re.compile(r'f_[0-9a-f]{8}_[0-9]+\.(?:in|out)\.bin$')


def plan(root=ROOT, minimum_age_hours=24, reclaim_gib=40, maximum_files=200000,
         preserve_sources=()):
    root = Path(root).resolve()
    analysis = (root / 'extract/analysis').resolve()
    protected, _ = bound_sources(root)
    for source_file in preserve_sources:
        data = json.loads(Path(source_file).read_text())
        for row in data['selected'].values():
            directory = row.get('directory', row.get('development_directory'))
            if directory:
                protected.add(Path(directory).resolve())
    cutoff = time.time() - minimum_age_hours * 3600
    candidates, corpora = [], {}
    total = 0
    for manifest in manifests(analysis):
        directory = manifest.parent.resolve()
        if directory in protected or 'target' in str(directory).lower():
            continue
        batch_path = directory / 'batch_manifest.json'
        if not batch_path.is_file():
            continue
        # Only inspect a corpus with substantial old decoded shadows.
        files = [Path(entry.path) for entry in os.scandir(directory)
                 if entry.is_file(follow_symlinks=False) and SHADOW.fullmatch(entry.name)
                 and entry.stat().st_mtime <= cutoff and entry.stat().st_size >= 65536]
        if not files:
            continue
        try:
            batch = json.loads(batch_path.read_text())
            data = json.loads(manifest.read_text())
        except ValueError:
            continue
        if not batch.get('runs') or not all(run.get('returncode') == 0 and
                                           run.get('frame_complete') for run in batch['runs']):
            continue
        sources = [Path(value).resolve() for value in data.get('inputs', [])]
        if not sources or not all(path.is_file() for path in sources):
            continue
        corpus_key = str(directory)
        corpora[corpus_key] = dict(manifest=str(manifest), sources=[
            dict(path=str(path), bytes=path.stat().st_size) for path in sources])
        for path in sorted(files):
            size = allocated(path)
            candidates.append(dict(path=str(path.resolve()), bytes=path.stat().st_size,
                                   allocated_bytes=size, corpus=corpus_key))
            total += size
            if total >= reclaim_gib * 2**30 or len(candidates) >= maximum_files:
                break
        print(f'{len(candidates)} shadow files; {total / 2**30:.2f} GiB reclaimable', flush=True)
        if total >= reclaim_gib * 2**30 or len(candidates) >= maximum_files:
            break
    return dict(dry_run=True, mode='decoded_cache', analysis=str(analysis),
                minimum_age_hours=minimum_age_hours, protected_directories=sorted(map(str, protected)),
                corpora=corpora, candidates=candidates, allocated_bytes=total)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--minimum-age-hours', type=float, default=24)
    parser.add_argument('--reclaim-gib', type=float, default=40)
    parser.add_argument('--maximum-files', type=int, default=200000)
    parser.add_argument('--preserve-sources', type=Path, action='append', default=[])
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    if args.minimum_age_hours < 0 or args.reclaim_gib <= 0 or args.maximum_files < 1:
        parser.error('invalid age or pruning budget')
    result = plan(minimum_age_hours=args.minimum_age_hours, reclaim_gib=args.reclaim_gib,
                  maximum_files=args.maximum_files, preserve_sources=args.preserve_sources)
    args.out.write_text(json.dumps(result, indent=1) + '\n')
    print(f"{len(result['candidates'])} old unbound shadows; "
          f"{result['allocated_bytes'] / 2**30:.2f} GiB; original capsules retained; no deletion")


if __name__ == '__main__':
    main()
