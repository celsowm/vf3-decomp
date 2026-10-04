"""Capture varied inputs in fresh states for each root, preserving all evidence."""
import argparse
import json
from pathlib import Path
import subprocess
import sys
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--limit', type=int, default=1000)
    ap.add_argument('--group-size', type=int, default=1, choices=range(1, 65),
                    help='probe this many roots per fresh state; default isolates each root')
    ap.add_argument('--variants', type=int, default=512)
    ap.add_argument('--frames', type=int, default=60)
    ap.add_argument('--states', default='21,27')
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c0432e2)
    ap.add_argument('--relocation', type=lambda x: int(x, 16), default=0)
    ap.add_argument('--holdout-inputs', action='store_true')
    ap.add_argument('--global-fields', action='store_true')
    ap.add_argument('--scalar-fields', action='store_true')
    ap.add_argument('--field-crosses', action='store_true')
    ap.add_argument('--timeout', type=int, default=25)
    ap.add_argument('--random-fields', action='store_true')
    ap.add_argument('--expanded-inputs', action='store_true',
                    help='independent bounded GPR/FR/XF values and integer fields 0..31')
    ap.add_argument('--asset-fixtures', action='store_true',
                    help='initializer descriptor and asset-table input contracts')
    ap.add_argument('--preserve-fields', action='store_true',
                    help='vary register inputs while keeping the typed memory contract')
    a = ap.parse_args()
    roots = [int(line.split()[1], 16) for line in a.watch.read_text().splitlines()
             if line.startswith('pc ')][a.start:a.start + a.limit]
    a.out.mkdir(parents=True, exist_ok=True)
    progress_path = a.out / 'progress.json'
    progress = json.loads(progress_path.read_text()) if progress_path.exists() else []
    for offset in range(0, len(roots), a.group_size):
        group = roots[offset:offset + a.group_size]
        index, entry = a.start + offset, group[0]
        suffix = f'_{group[-1]:08x}' if len(group) > 1 else ''
        name = f'{a.out.name}_{entry:08x}{suffix}'
        directory = a.out / name
        directory.mkdir(parents=True, exist_ok=True)
        if (directory / 'batch_manifest.json').exists():
            print(f'{index}: {entry:08x} already attempted', flush=True)
            continue
        watch, patch = directory / 'watch.txt', directory / 'entry.patch'
        watch.write_text(''.join(f'pc 0x{root:08x}\n' for root in group))
        if a.asset_fixtures:
            from asset_probe_plan import generate as generate_assets
            generate_assets(watch, patch, a.trigger, a.variants,
                            base=0x0c400000 + a.relocation, holdout=a.holdout_inputs)
        else:
            generate(watch, patch, a.trigger, a.variants, relocation=a.relocation,
                     fpscr=0x40001, bounded_arguments=True, floating_arguments=True,
                     alternate_fields=True, holdout_inputs=a.holdout_inputs,
                     global_fields=a.global_fields, scalar_fields=a.scalar_fields,
                     field_crosses=a.field_crosses, random_fields=a.random_fields,
                     expanded_inputs=a.expanded_inputs, preserve_fields=a.preserve_fields)
        command = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
                   '--watch', str(watch), '--out', str(directory), '--entry-patch',
                   str(patch), '--capsule', '--probe-debug', '--probe-only',
                   '--max-samples', str(a.variants), '--timeout', str(a.timeout)]
        for state in a.states.split(','):
            command += ['--run', f's{state}:tools/emu/flycast-build/data/vf3_{state}.state::{a.frames}']
        with (directory / 'capture.log').open('w') as output:
            result = subprocess.run(command, cwd=ROOT, stdout=output, stderr=output)
        manifest = directory / 'capsule_manifest.json'
        captured = json.loads(manifest.read_text())['entries'] if manifest.exists() else {}
        cases = sum(len(captured.get(hex(root), [])) for root in group)
        progress.append(dict(index=index, entry=hex(entry), returncode=result.returncode,
                             entries=[hex(root) for root in group],
                             complete_cases=cases, directory=str(directory)))
        progress_path.write_text(json.dumps(progress, indent=1) + '\n')
        print(f'{index}: {entry:08x} roots={len(group)} rc={result.returncode} complete={cases}', flush=True)
        if (a.out / 'STOP').exists():
            print('Stopped between roots; completed capture evidence retained.', flush=True)
            break


if __name__ == '__main__':
    main()
