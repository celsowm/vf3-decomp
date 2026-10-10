"""Sequential frozen original/C pilots, development and held-out fight callers."""
import argparse
import json
from pathlib import Path
import subprocess
import sys
from audio_determinism import ROOT


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--cache',type=Path,required=True)
    ap.add_argument('--emulator',type=Path,required=True)
    ap.add_argument('--native',type=Path,required=True)
    ap.add_argument('--pilot-only',action='store_true')
    a=ap.parse_args()
    def run(tool,*args):
        subprocess.run([sys.executable,str(ROOT/'tools/oracle'/tool),*map(str,args)],cwd=ROOT,check=True)
    def capture(name,recipe,states,c=False,corrupt=False):
        out=a.cache.resolve()/name
        if out.exists():raise FileExistsError(out)
        args=['--recipe',recipe,'--out',out,'--evidence-root',a.cache.resolve(),
              '--emulator',a.emulator.resolve(),'--repetitions','1','--compress']
        for state in states:args+=['--state',ROOT/f'tools/emu/flycast-build/data/vf3_{state}.state']
        if c:args+=['--c-replay']
        if corrupt:args+=['--corrupt-command']
        run('audio_one_shot.py',*args)
        return out/'manifest.json'
    if a.pilot_only:
        recipe=ROOT/'tools/oracle/audio_fight_pilot_v1.json'
        left=capture('fight_live_pilot_original_v1',recipe,(26,))
        right=capture('fight_live_pilot_c_v1',recipe,(26,),True)
        run('audio_replay_compare.py',left,right,'--out',ROOT/'extract/analysis/audio_fight_live_pilot_v1_comparison.json')
        return
    for name,states in (('dev',(26,27)),('accept',(28,29))):
        recipe=ROOT/f'tools/oracle/audio_fight_{name}_v1.json'
        left=capture(f'fight_{name}_original_v1',recipe,states)
        right=capture(f'fight_{name}_c_v1',recipe,states,True)
        corpus=ROOT/f'extract/analysis/audio_fight_{name}_v1_cases'
        run('audio_corpus.py',left,right,'--out',corpus)
        run('verify_matrix.py',corpus,'--out',ROOT/f'extract/analysis/audio_fight_{name}_v1_native_report.json',
            '--executable',a.native.resolve())
    recipe=ROOT/'tools/oracle/audio_fight_negative_v1.json'
    left=capture('fight_negative_original_v1',recipe,(26,))
    right=capture('fight_negative_c_v1',recipe,(26,),True,True)
    run('audio_replay_compare.py',left,right,'--expect-mismatch','--out',ROOT/'extract/analysis/audio_fight_live_v1_negative_comparison.json')
    print('Fight caller development, held-out and corruption control complete',flush=True)


if __name__=='__main__':main()
