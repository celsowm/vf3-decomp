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
    ap.add_argument('--observe-watch', type=Path,
                    help='also observe these nested entries without probing them directly')
    ap.add_argument('--probe-children', action='store_true',
                    help='restrict observed entries to active rollback probes')
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--limit', type=int, default=1000)
    ap.add_argument('--group-size', type=int, default=1, choices=range(1, 65),
                    help='probe this many roots per fresh state; default isolates each root')
    ap.add_argument('--variants', type=int, default=512)
    ap.add_argument('--frames', type=int, default=60)
    ap.add_argument('--states', default='21,27')
    ap.add_argument('--play', type=Path,
                    help='optional repository-relative Flycast input script for every state')
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c0432e2)
    ap.add_argument('--relocation', type=lambda x: int(x, 16), default=0)
    ap.add_argument('--holdout-inputs', action='store_true')
    ap.add_argument('--global-fields', action='store_true')
    ap.add_argument('--scalar-fields', action='store_true')
    ap.add_argument('--field-crosses', action='store_true')
    ap.add_argument('--timeout', type=int, default=25)
    ap.add_argument('--probe-ops', type=int, choices=range(1, 100001),
                    metavar='1..100000', help='original interpreter synthetic-call budget')
    ap.add_argument('--rollback-text-control', action='store_true',
                    help='opt in to the headless PVR TEXT_CONTROL checkpoint pilot')
    ap.add_argument('--random-fields', action='store_true')
    ap.add_argument('--expanded-inputs', action='store_true',
                    help='independent bounded GPR/FR/XF values and integer fields 0..31')
    ap.add_argument('--asset-fixtures', action='store_true',
                    help='initializer descriptor and asset-table input contracts')
    ap.add_argument('--preserve-fields', action='store_true',
                    help='vary register inputs while keeping the typed memory contract')
    ap.add_argument('--comparison-boundaries', action='store_true',
                    help='also sample around bounded original integer comparands')
    ap.add_argument('--register-overrides', type=Path,
                    help='JSON map of entry PCs to per-register values or variant sequences')
    ap.add_argument('--memory-overrides', type=Path,
                    help='JSON map of entry PCs to RAM word addresses and values or variant sequences')
    a = ap.parse_args()
    register_overrides = json.loads(a.register_overrides.read_text()) if a.register_overrides else None
    memory_overrides = json.loads(a.memory_overrides.read_text()) if a.memory_overrides else None
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
        probe_watch = directory / 'probe_watch.txt'
        probe_watch.write_text(watch.read_text())
        if a.observe_watch:
            from campaign_io import read_watch, write_watch
            write_watch(watch, set(group) | read_watch(a.observe_watch),
                        'Original prologue probes and observed nested entries.')
        if a.asset_fixtures:
            from asset_probe_plan import generate as generate_assets
            generate_assets(probe_watch, patch, a.trigger, a.variants,
                            base=0x0c400000 + a.relocation, holdout=a.holdout_inputs)
        else:
            generate(probe_watch, patch, a.trigger, a.variants, relocation=a.relocation,
                     fpscr=0x40001, bounded_arguments=True, floating_arguments=True,
                     alternate_fields=True, holdout_inputs=a.holdout_inputs,
                     global_fields=a.global_fields, scalar_fields=a.scalar_fields,
                     field_crosses=a.field_crosses, random_fields=a.random_fields,
                     expanded_inputs=a.expanded_inputs, preserve_fields=a.preserve_fields,
                     register_overrides=register_overrides,
                     memory_overrides=memory_overrides,
                     comparison_boundaries=a.comparison_boundaries)
        command = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
                   '--watch', str(watch), '--out', str(directory), '--entry-patch',
                   str(patch), '--capsule', '--probe-debug',
                   '--max-samples', str(a.variants), '--timeout', str(a.timeout)]
        if a.probe_children:
            command.append('--probe-children')
        elif not a.observe_watch:
            command.append('--probe-only')
        if a.probe_ops is not None:
            command += ['--probe-ops', str(a.probe_ops)]
        if a.rollback_text_control:
            command.append('--rollback-text-control')
        play = a.play.as_posix() if a.play else ''
        for state in a.states.split(','):
            command += ['--run', f's{state}:tools/emu/flycast-build/data/vf3_{state}.state:{play}:{a.frames}']
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
