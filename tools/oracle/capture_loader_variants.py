#!/usr/bin/env python3
"""Capture one half of the original interpreter's loader sentinel fixtures."""
import argparse
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('half', choices=('a', 'b'))
    parser.add_argument('--frames', type=int, default=300)
    parser.add_argument('--name')
    parser.add_argument('--watch', default='tools/watch/vf3_sixth_loader_expanded.txt')
    parser.add_argument('--variant-dir', default='extract/analysis/sixth_loader_entry_variants')
    parser.add_argument('--start', type=int)
    parser.add_argument('--stop', type=int)
    parser.add_argument('--state', type=int)
    parser.add_argument('--play', default='tools/vf3_play_motion_strikes.txt')
    args = parser.parse_args()
    default_start, default_stop, default_state = (0, 32, 20) if args.half == 'a' else (32, 64, 21)
    start = default_start if args.start is None else args.start
    stop = default_stop if args.stop is None else args.stop
    state = default_state if args.state is None else args.state
    name = args.name or f'sixth_loader_{args.half}'
    cmd = [sys.executable, str(ROOT / 'tools/golden_batch.py'),
           '--name', name, '--watch', args.watch,
           '--out', f'extract/analysis/{name}_cases', '--capsule',
           '--max-samples', '8']
    for variant in range(start, stop):
        patch = f'{args.variant_dir}/variant_{variant:03d}.patch'
        if not (ROOT / patch).is_file():
            parser.error(f'missing {patch}; run loader_variants.py first')
        cmd.extend(['--run',
                    f'v{variant:03d}_s{state}:tools/emu/flycast-build/data/vf3_{state}.state:'
                    f'{args.play}:{args.frames}:{patch}'])
    raise SystemExit(subprocess.run(cmd, cwd=ROOT).returncode)


if __name__ == '__main__':
    main()
