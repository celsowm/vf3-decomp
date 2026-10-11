#!/usr/bin/env python3
"""Build every currently bound replay and native suite without parked targets."""
import argparse
import json
from pathlib import Path
import subprocess
from portcheck import TESTS

ROOT=Path(__file__).resolve().parents[1]

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--jobs',type=int,default=4)
    parser.add_argument('--list',action='store_true',help='print targets without building')
    args=parser.parse_args()
    if args.jobs<1:parser.error('--jobs must be positive')
    targets=set(TESTS)|{'vf3matrixfamily'}
    bindings=json.loads((ROOT/'tools/golden_bindings.json').read_text())
    for row in bindings.values():
        executable=Path(row['test'].split()[0])
        if executable.parent.as_posix()!='build' or executable.suffix!='.exe':
            raise ValueError(f'Unsupported binding executable: {executable}')
        targets.add(executable.stem)
    ordered=sorted(targets)
    print(f'{len(ordered)} required executable targets',flush=True)
    if args.list:
        print('\n'.join(ordered))
        return 0
    return subprocess.run(['cmake','--build','build','--parallel',str(args.jobs),
                           '--target',*ordered],cwd=ROOT).returncode

if __name__=='__main__':raise SystemExit(main())
