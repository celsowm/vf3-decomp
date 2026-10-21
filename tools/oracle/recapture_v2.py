#!/usr/bin/env python3
"""recapture_v2.py - re-run a recorded batch with the 1024-page observer.

Some corpora were recorded before the oracle's RAM page budget was raised
(docs/re/oracle_device_reads.patch).  The recorder refused a specimen once
its 512 KiB page cache was full, so the corpus kept only its register rows
and lost the RAM shadow: the replay harness then has nothing to compare the
port's memory against, and the entry cannot be promoted.

This tool re-runs such a batch with the v2 observer - the same oracle source
with the page budget raised to 1024 pages - so the specimen is recorded whole.
The batch manifest carries every parameter of the original run, so the re-run
reproduces it.

    python tools/oracle/recapture_v2.py --batch-dir extract/analysis/tenpp_medium_global_dev/tenpp_medium_global_dev_8c058348 \
        --out extract/analysis/u141_8c058348
"""
from __future__ import annotations

import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
V2_EXECUTABLE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence/flycast_capsule_extended_v2.exe')
V2_CONTROLS = ROOT / 'tools/oracle/extended_observer_controls_v2.json'


def rel(value: str) -> str:
    """Repository-relative path: the run spec is colon-separated."""
    if not value:
        return ''
    path = Path(value)
    try:
        return path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return value


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--batch-dir', type=Path, required=True,
                    help='corpus directory holding batch_manifest.json')
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--timeout', type=int, default=1800)
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()

    manifest_path = a.batch_dir / 'batch_manifest.json'
    if not manifest_path.is_file():
        raise SystemExit(f'no batch manifest in {a.batch_dir}')
    manifest = json.loads(manifest_path.read_text(encoding='utf-8'))
    runs = manifest.get('runs') or []
    if not runs:
        raise SystemExit(f'batch {a.batch_dir} records no run')
    if not V2_EXECUTABLE.is_file():
        raise SystemExit(f'missing the v2 observer: {V2_EXECUTABLE}')
    if not V2_CONTROLS.is_file():
        raise SystemExit(f'missing the v2 observer controls: {V2_CONTROLS}')

    a.out.mkdir(parents=True, exist_ok=True)
    watch = Path(manifest['watch'])
    if not watch.is_file():
        raise SystemExit(f'missing watch file: {watch}')

    name = f'v2_{a.out.name}'
    cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
           '--watch', str(watch), '--out', str(a.out), '--capsule',
           '--max-samples', str(manifest.get('max_samples', 64)),
           '--emulator', str(V2_EXECUTABLE),
           '--observer-controls', str(V2_CONTROLS)]
    for run in runs:
        label = run['name'].replace(':', '_')
        spec = (f"{label}:{rel(run.get('state', ''))}:"
                f"{rel(run.get('play', ''))}:{run.get('frames', 0)}")
        if run.get('ram_patch'):
            spec += f":{rel(run['ram_patch'])}"
        cmd += ['--run', spec]
    if runs[0].get('entry_patch'):
        cmd += ['--entry-patch', runs[0]['entry_patch']]
        if runs[0].get('probe_ops'):
            cmd += ['--probe-ops', str(runs[0]['probe_ops'])]
    cmd += ['--timeout', str(a.timeout)]

    print('recapture_v2:', ' '.join(cmd), flush=True)
    if a.dry_run:
        return 0
    with (a.out / 'capture.log').open('w', encoding='utf-8') as log:
        result = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=log)
    print(f'rc={result.returncode}', flush=True)
    return result.returncode


if __name__ == '__main__':
    raise SystemExit(main())
