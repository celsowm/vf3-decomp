"""Run original/C process-owned input qualification sequentially; preserve failures."""
import argparse
from pathlib import Path
import subprocess
import sys
from audio_determinism import ROOT


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--cache',type=Path,required=True)
    ap.add_argument('--emulator',type=Path,required=True)
    ap.add_argument('--native',type=Path,required=True)
    a=ap.parse_args()
    def run(tool,*args):
        subprocess.run([sys.executable,str(ROOT/'tools/oracle'/tool),*map(str,args)],cwd=ROOT,check=True)
    for name,states in (('dev',(26,27)),('accept',(28,29))):
        manifests=[]
        for mode in ('original','c'):
            out=a.cache.resolve()/f'input_qualified_{name}_{mode}_v2'
            if out.exists():raise FileExistsError(out)
            args=['--recipe',ROOT/f'tools/oracle/audio_input_qualified_{name}_v2.json',
                  '--out',out,'--evidence-root',a.cache.resolve(),
                  '--emulator',a.emulator.resolve(),'--repetitions','1','--compress']
            for state in states:
                args+=['--state',ROOT/f'tools/emu/flycast-build/data/vf3_{state}.state']
            if mode=='c':args+=['--c-replay']
            run('audio_one_shot.py',*args)
            manifests.append(out/'manifest.json')
        corpus=ROOT/f'extract/analysis/audio_input_qualified_{name}_v2_cases'
        run('audio_corpus.py',*manifests,'--out',corpus)
        run('verify_matrix.py',corpus,'--out',ROOT/f'extract/analysis/audio_input_qualified_{name}_v2_native_report.json',
            '--executable',a.native.resolve())


if __name__=='__main__':main()
