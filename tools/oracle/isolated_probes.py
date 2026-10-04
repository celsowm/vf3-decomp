#!/usr/bin/env python3
"""Capture roots independently so one probe cannot starve later targets.

Every original interpreter run starts from a fresh state. Failed runs and
invalid specimens remain excluded. Generated fixtures live under analysis.
"""
import argparse
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--limit', type=int, default=30)
    ap.add_argument('--frames', type=int, default=120)
    ap.add_argument('--states', default='20,21')
    ap.add_argument('--trigger', type=lambda s: int(s, 16), default=0x8c063d36)
    ap.add_argument('--pointer-fixtures', action='store_true')
    ap.add_argument('--seed-mode', choices=('zero', 'open'), default='zero')
    a = ap.parse_args()
    roots = [int(line.split()[1], 16) for line in a.watch.read_text().splitlines()
             if line.startswith('pc ')][a.start:a.start + a.limit]
    a.out.mkdir(parents=True, exist_ok=True)
    rows = []
    for index, entry in enumerate(roots, a.start):
        name = f'{a.out.name}_{entry:08x}'
        directory = a.out / name
        directory.mkdir(parents=True, exist_ok=True)
        if (directory / 'capsule_manifest.json').exists():
            print(f'{index}: {entry:08x} already captured', flush=True)
            continue
        watch = directory / 'watch.txt'
        patch = directory / 'entry.patch'
        watch.write_text(f'pc 0x{entry:08x}\n')
        patch.write_text(f'entry 0x{a.trigger:08x} 0x{entry:08x}\n'
                         f'target 0x{a.trigger:08x} 0x{entry & 0x1fffffff:08x}\n'
                         f'reg 0x{a.trigger:08x} pr 0x{(a.trigger + 2) & 0x1fffffff:08x}\n')
        if a.pointer_fixtures:
            from pointer_seeds import fixture
            registers, words = fixture(entry, a.seed_mode)
            with patch.open('a') as output:
                for register, value in sorted(registers.items()):
                    output.write(f'reg 0x{a.trigger:08x} r{register} 0x{value:08x}\n')
                for addr, value in sorted(words.items()):
                    output.write(f'ram 0x{a.trigger:08x} 0x{addr:08x} 0x{value:08x}\n')
        cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
               '--watch', str(watch), '--out', str(directory), '--entry-patch',
               str(patch), '--capsule', '--probe-debug', '--max-samples', '8']
        for state in a.states.split(','):
            cmd += ['--run', f's{state}:tools/emu/flycast-build/data/vf3_{state}.state::{a.frames}']
        with (directory / 'capture.log').open('w') as log:
            run = subprocess.run(cmd, cwd=ROOT, stdout=log, stderr=log)
        count = 0
        if (directory / 'capsule_manifest.json').is_file():
            count = len(json.loads((directory / 'capsule_manifest.json').read_text())['entries'].get(hex(entry), []))
        rows.append(dict(index=index, entry=hex(entry), returncode=run.returncode,
                         complete_cases=count, directory=str(directory)))
        (a.out / 'progress.json').write_text(json.dumps(rows, indent=1) + '\n')
        print(f'{index}: {entry:08x} rc={run.returncode} complete={count}', flush=True)


if __name__ == '__main__':
    main()
