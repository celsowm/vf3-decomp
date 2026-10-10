"""Fresh live regression of actor cleanup after general-encoder reuse."""
import argparse
from pathlib import Path
import subprocess
import sys
from audio_determinism import ROOT


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--cache', type=Path, required=True)
    a = ap.parse_args()
    manifests = []
    def run(tool, *args):
        subprocess.run([sys.executable, str(ROOT/'tools/oracle'/tool),
                        *map(str, args)], cwd=ROOT, check=True)
    for mode in ('original', 'c'):
        out = a.cache.resolve()/f'actor_shared_{mode}_v2'
        if out.exists():
            raise FileExistsError(out)
        args = ['--recipe', ROOT/'tools/oracle/audio_actor_clear_pilot_v1.json',
                '--out', out, '--evidence-root', a.cache.resolve(),
                '--emulator', ROOT/'tools/emu/flycast-build/flycast_audio_callers_live_v1.exe',
                '--repetitions', '1', '--compress']
        for state in (26, 28):
            args += ['--state', ROOT/f'tools/emu/flycast-build/data/vf3_{state}.state']
        if mode == 'c':
            args += ['--c-replay']
        run('audio_one_shot.py', *args)
        manifests.append(out/'manifest.json')
    run('audio_replay_compare.py', *manifests, '--out',
        ROOT/'extract/analysis/audio_actor_shared_encoder_v2_live_comparison.json')


if __name__ == '__main__':
    main()
