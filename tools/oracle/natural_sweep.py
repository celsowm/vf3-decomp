"""Natural capture sweep: watch a set of entries across every emulator state.

The synthetic probe only reaches an entry with a plausible register/RAM
context; a natural capture needs none.  This driver runs the oracle over every
saved state (vf3_1 .. vf3_46) with a watch file of the entries to capture and
reports which of them the game actually reaches.
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STATES = ROOT / 'tools' / 'emu' / 'flycast-build' / 'data'


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--name', default='naturalsweep')
    ap.add_argument('--frames', type=int, default=120)
    ap.add_argument('--max-samples', type=int, default=8)
    ap.add_argument('--timeout', type=int, default=180)
    ap.add_argument('--states', default='')
    ap.add_argument('--start', type=int, default=1)
    ap.add_argument('--end', type=int, default=46)
    a = ap.parse_args()

    entries = []
    for line in a.watch.read_text().splitlines():
        if line.startswith('pc '):
            entries.append(int(line.split()[1], 16) & 0x1fffffff)
    a.out.mkdir(parents=True, exist_ok=True)
    states = a.states.split(',') if a.states else [
        str(n) for n in range(a.start, a.end + 1) if (STATES / ('vf3_%d.state' % n)).is_file()]
    print('watching %d entries over %d states' % (len(entries), len(states)), flush=True)
    got = {}
    for state in states:
        # One golden_batch call per state: a single bad state must not abort
        # the whole batch.
        cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name',
               '%s_s%s' % (a.name, state), '--watch', str(a.watch),
               '--out', str(a.out / ('s%s' % state)), '--capsule',
               '--max-samples', str(a.max_samples), '--run',
               's%s:tools/emu/flycast-build/data/vf3_%s.state::%d'
               % (state, state, a.frames)]
        result = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                                timeout=a.timeout)
        if result.returncode:
            print('  s%s rc=%d (skipped)' % (state, result.returncode), flush=True)
        for manifest in sorted((a.out / ('s%s' % state)).rglob('capsule_manifest.json')):
            try:
                data = json.loads(manifest.read_text())
            except (OSError, ValueError):
                continue
            for key, cases in data.get('entries', {}).items():
                if cases:
                    got[key] = got.get(key, 0) + len(cases)
    print('entries captured: %d / %d' % (len(got), len(entries)), flush=True)
    (a.out / 'captured.json').write_text(json.dumps(got, indent=1))
    for key, count in sorted(got.items(), key=lambda kv: -kv[1]):
        print('  %s -> %d cases' % (key, count), flush=True)
    return 0


if __name__ == '__main__':
    sys.exit(main())
