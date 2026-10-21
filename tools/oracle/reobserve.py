#!/usr/bin/env python3
"""Re-observe nested entries that existing corpora already execute.

The oracle records one specimen per *watched* entry.  A watched entry's
ops.json holds the whole call tree it executed, so a callee that ran under
it is known - but the callee only earns a corpus if it was watched too.
This tool re-runs a recorded batch with the callees added to the watch
file, so the reference captures them with its own state.

    python tools/oracle/reobserve.py --batch-dir extract/analysis/next_dev_cases \
        --children extract/analysis/u118_children.txt --out extract/analysis/u118_next

The original batch manifest carries every parameter of the recorded run
(state, play script, frame count, RAM patch, probe fixture, observer
controls and the exact emulator build), so the re-run reproduces it.
"""
from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def read_watch(path: Path) -> list[str]:
    if not path.is_file():
        return []
    return [line for line in path.read_text(encoding="utf-8").splitlines()
            if line.strip().startswith("pc ")]


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
    ap.add_argument('--children', type=Path, required=True,
                    help='file with one nested entry PC per line')
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--watch-mode', choices=('extend', 'children', 'auto'), default='auto',
                    help="'extend' keeps the original watch list (needed by probe "
                         "batches, whose target must stay watched); 'children' "
                         "watches only the nested entries and keeps the capsule small; "
                         "'auto' picks extend for probe batches and children otherwise")
    ap.add_argument('--timeout', type=int, default=900)
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()

    manifest_path = a.batch_dir / 'batch_manifest.json'
    if not manifest_path.is_file():
        raise SystemExit(f'no batch manifest in {a.batch_dir}')
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    runs = manifest.get('runs') or []
    if not runs:
        raise SystemExit(f'batch {a.batch_dir} records no run')

    children = []
    for line in a.children.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        children.append(int(line.split()[0], 16))
    if not children:
        raise SystemExit('no children given')

    original = Path(manifest.get('watch', ''))
    original_lines = read_watch(original) if original.is_file() else []
    probed = bool(runs[0].get('entry_patch'))
    mode = a.watch_mode
    if mode == 'auto':
        mode = 'extend' if probed else 'children'

    a.out.mkdir(parents=True, exist_ok=True)
    watch = a.out / 'watch.txt'
    lines = list(original_lines) if mode == 'extend' else []
    seen = {line.split()[1].lower() for line in lines}
    for child in children:
        key = f'0x{child:08x}'
        if key.lower() in seen:
            continue
        seen.add(key.lower())
        lines.append(f'pc {key}')
    watch.write_text('\n'.join(lines) + '\n', encoding='utf-8')

    name = f'reobs_{a.out.name}'
    cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
           '--watch', str(watch), '--out', str(a.out), '--capsule',
           '--max-samples', str(manifest.get('max_samples', 64))]
    for run in runs:
        # The run name may carry a colon (e.g. "fight_dev:s7"); the spec is
        # colon-separated, so keep the label flat.
        label = run['name'].replace(':', '_')
        spec = (f"{label}:{rel(run.get('state',''))}:"
                f"{rel(run.get('play',''))}:{run.get('frames',0)}")
        if run.get('ram_patch'):
            spec += f":{rel(run['ram_patch'])}"
        cmd += ['--run', spec]
    if probed:
        cmd += ['--entry-patch', run['entry_patch'], '--probe-children']
        if runs[0].get('probe_ops'):
            cmd += ['--probe-ops', str(runs[0]['probe_ops'])]
    if runs[0].get('observer_controls'):
        cmd += ['--observer-controls', str(runs[0]['observer_controls'])]
    if runs[0].get('emulator'):
        cmd += ['--emulator', str(runs[0]['emulator'])]
    cmd += ['--timeout', str(a.timeout)]

    print('reobserve:', ' '.join(cmd), flush=True)
    if a.dry_run:
        return 0
    with (a.out / 'capture.log').open('w', encoding="utf-8") as log:
        result = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=log)
    print(f'rc={result.returncode}', flush=True)

    captured = []
    for child in children:
        # The capsule names the corpus after the watched entry | 0x80000000.
        for stem in (f'f_{child:08x}', f'f_{child | 0x80000000:08x}'):
            if (a.out / f'{stem}.cases').is_file():
                captured.append(child)
                break
    print(f'captured {len(captured)}/{len(children)} nested entries', flush=True)
    (a.out / 'captured.txt').write_text(
        '\n'.join(f'0x{c:08x}' for c in captured) + '\n', encoding='utf-8')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
