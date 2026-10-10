"""Run fresh original/C encoder processes sequentially, then strict native replay."""
import argparse
import json
from pathlib import Path
import subprocess
import sys
from audio_determinism import ROOT


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--cache',type=Path,required=True)
    a=ap.parse_args();cache=a.cache.resolve()
    emulator=ROOT/'tools/emu/flycast-build/flycast_audio_encoder_live_v1.exe'
    native=ROOT/'build/vf3matrixfamily_audio_encoder_live_v1.exe'
    def run(tool,*args):
        subprocess.run([sys.executable,str(ROOT/'tools/oracle'/tool),*[str(x) for x in args]],
                       cwd=ROOT,check=True)
    def capture(stem,recipe,states,c=False,corrupt=False):
        out=cache/stem
        if out.exists():raise FileExistsError(out)
        args=['--recipe',ROOT/'tools/oracle'/recipe,'--out',out,'--evidence-root',cache,
              '--emulator',emulator,'--repetitions','1','--compress']
        for state in states:args+=['--state',ROOT/f'tools/emu/flycast-build/data/vf3_{state}.state']
        if c:args+=['--c-replay']
        if corrupt:args+=['--corrupt-command']
        run('audio_one_shot.py',*args)
        return out/'manifest.json'
    for name,states in (('dev',(26,27)),('accept',(28,29))):
        recipe=f'audio_encoder_live_{name}_v1.json'
        original=capture(f'encoder_live_{name}_original_v1',recipe,states)
        c=capture(f'encoder_live_{name}_c_v1',recipe,states,True)
        corpus=ROOT/f'extract/analysis/audio_encoder_live_{name}_v1_cases'
        run('audio_corpus.py',original,c,'--out',corpus)
        run('verify_matrix.py',corpus,'--out',ROOT/f'extract/analysis/audio_encoder_live_{name}_v1_native_report.json',
            '--executable',native)
    original=capture('encoder_live_negative_original_v1','audio_encoder_live_negative_v1.json',(26,))
    c=capture('encoder_live_negative_c_v1','audio_encoder_live_negative_v1.json',(26,),True,True)
    run('audio_replay_compare.py',original,c,'--expect-mismatch','--out',
        ROOT/'extract/analysis/audio_encoder_live_v1_negative_comparison.json')
    print('Encoder development, held-out and corruption-control runs complete',flush=True)


if __name__=='__main__':main()
