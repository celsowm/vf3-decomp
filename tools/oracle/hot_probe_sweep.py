"""Capture corpora for unported entries with a hot trigger and typed fixtures.

`tools/oracle/isolated_probes.py` redirects a single synthetic trigger at the
entry and lets the guest call it.  It only works when the trigger is actually
executed during the capture state: the default 0x8C063D36 has 15,179 recorded
hits and is cold in the fight states, so the emulator never reaches the entry
and rejects every specimen with flags=1 ("synthetic probe superseded").  The
trigger 0x8C0432E2 has 11,246,319 hits and is what every successful historical
capture used.

The fixture itself comes from `tenpp_probe_plan.generate()`, which rotates the
typed input fixtures of `pointer_seeds.fixture()` over `--variants` rounds and
writes the `reg` / `ram` / `seed` lines of the entry patch.
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools' / 'oracle'))

import tenpp_probe_plan  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c0432e2)
    ap.add_argument('--variants', type=int, default=64)
    ap.add_argument('--mode', choices=('zero', 'open', 'one'), default='zero')
    ap.add_argument('--states', default='21,27')
    ap.add_argument('--frames', type=int, default=60)
    ap.add_argument('--max-samples', type=int, default=8)
    ap.add_argument('--timeout', type=int, default=150)
    ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--limit', type=int, default=30)
    ap.add_argument('--alternate-fields', action='store_true')
    ap.add_argument('--global-fields', action='store_true')
    ap.add_argument('--scalar-fields', action='store_true')
    ap.add_argument('--bounded-arguments', action='store_true')
    ap.add_argument('--float-vectors', action='store_true')
    a = ap.parse_args()

    roots = [int(line.split()[1], 16) for line in
             a.watch.read_text().splitlines() if line.startswith('pc ')]
    roots = [r & 0x1fffffff for r in roots]
    if not roots:
        print('empty watch', file=sys.stderr)
        return 1
    a.out.mkdir(parents=True, exist_ok=True)
    rows = []
    progress = a.out / 'progress.json'
    for index, entry in enumerate(roots[a.start:a.start + a.limit]):
        name = '%s_%08x' % (a.out.name, entry)
        directory = a.out / name
        directory.mkdir(parents=True, exist_ok=True)
        watch = directory / 'watch.txt'
        watch.write_text('pc 0x%08x\n' % entry)
        patch = directory / 'entry.patch'
        try:
            tenpp_probe_plan.generate(
                watch, patch, a.trigger, a.variants, mode=a.mode,
                alternate_fields=a.alternate_fields, global_fields=a.global_fields,
                scalar_fields=a.scalar_fields, bounded_arguments=a.bounded_arguments,
                float_vectors=a.float_vectors)
        except Exception as exc:                       # noqa: BLE001
            print('%d: %08x fixture failed: %s' % (index, entry, exc), flush=True)
            rows.append(dict(index=index, entry=hex(entry), returncode=-1,
                             complete_cases=0, directory=str(directory)))
            progress.write_text(json.dumps(rows, indent=1) + '\n')
            continue
        cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
               '--watch', str(watch), '--out', str(directory), '--entry-patch',
               str(patch), '--capsule', '--probe-debug', '--probe-only',
               '--max-samples', str(a.max_samples)]
        for state in a.states.split(','):
            cmd += ['--run', 's%s:tools/emu/flycast-build/data/vf3_%s.state::%d'
                    % (state, state, a.frames)]
        with (directory / 'capture.log').open('w') as log:
            process = subprocess.Popen(cmd, cwd=ROOT, stdout=log, stderr=log)
            try:
                returncode = process.wait(timeout=a.timeout)
            except subprocess.TimeoutExpired:
                subprocess.run(['taskkill', '/PID', str(process.pid), '/T', '/F'],
                               stdout=log, stderr=log)
                process.wait()
                returncode = 124
        count = 0
        manifest = directory / 'capsule_manifest.json'
        if manifest.is_file():
            count = len(json.loads(manifest.read_text())['entries'].get(hex(entry), []))
        rows.append(dict(index=index, entry=hex(entry), returncode=returncode,
                         complete_cases=count, directory=str(directory)))
        progress.write_text(json.dumps(rows, indent=1) + '\n')
        print('%d: %08x rc=%d complete=%d' % (index, entry, returncode, count), flush=True)
    got = [r for r in rows if r['complete_cases']]
    print('captured %d/%d entries, %d cases' % (len(got), len(rows),
                                                sum(r['complete_cases'] for r in rows)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
