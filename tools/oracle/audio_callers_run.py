"""Sequential original/live C proof for request and selection-input callers."""
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
        subprocess.run([sys.executable,str(ROOT/'tools/oracle'/tool),*[str(x) for x in args]],
                       cwd=ROOT,check=True)
    for target in ('request','input'):
        for name,state in (('dev',26),('accept',28)):
            manifests=[]
            for mode in ('original','c'):
                out=a.cache.resolve()/f'{target}_{name}_{mode}_v1'
                if out.exists():raise FileExistsError(out)
                args=['--state',ROOT/f'tools/emu/flycast-build/data/vf3_{state}.state',
                    '--recipe',ROOT/f'tools/oracle/audio_{target}_{name}_v1.json',
                    '--out',out,'--evidence-root',a.cache.resolve(),
                    '--emulator',a.emulator.resolve(),'--repetitions','1','--compress']
                if mode=='c':args+=['--c-replay']
                run('audio_one_shot.py',*args)
                manifests.append(out/'manifest.json')
            corpus=ROOT/f'extract/analysis/audio_{target}_{name}_v1_cases'
            run('audio_corpus.py',*manifests,'--out',corpus)
            run('verify_matrix.py',corpus,'--out',ROOT/f'extract/analysis/audio_{target}_{name}_v1_native_report.json',
                '--executable',a.native.resolve())
    print('Request and input caller comparisons complete',flush=True)


if __name__=='__main__':main()
