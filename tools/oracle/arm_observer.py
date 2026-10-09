"""Check that ARM memory observation preserves aligned guest audio state.

Fresh processes use the same frozen emulator and staged state slot. No input
script, opcode replacement, audio reply replay or frame-completion claim.
"""
import argparse
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
from audio_determinism import ROOT, compare, compress_checkpoint, describe, emulator_lock, sha
from arm_trace import records


def run(args):
    out=args.out.resolve()
    out.mkdir(parents=True,exist_ok=False)
    points=[int(v) for v in args.points.split(',')]
    manifest=dict(coverage_credit=False,passed=False,runs=[],comparisons=[],
                  provenance={str(args.emulator):sha(args.emulator),
                              str(Path(__file__)):sha(__file__)})
    for name in ('vf3armtrace.cpp','vf3armtrace.h','install_arm_trace.py'):
        path=Path(__file__).parent/name
        manifest['provenance'][str(path)]=sha(path)
    for name in ('arm_mem.h','arm7_rec.h','arm7_rec.cpp','arm7_rec_x64.cpp'):
        path=ROOT/'tools/emu/flycast/core/hw/arm7'/name
        manifest['provenance'][str(path)]=sha(path)
    for path in (ROOT/'extract/gamedata/SNDDRV.BIN',ROOT/'extract/gamedata/1ST_READ.BIN'):
        manifest['provenance'][str(path)]=sha(path)
    def save():
        (out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    save()
    for state in args.state:
        manifest['provenance'][str(state)]=sha(state)
        shutil.copyfile(state,args.emulator.resolve().parent/'data/vf3.state')
        pairs=[]
        for mode in ('baseline','traced'):
            stem=out/f'{state.stem}_{mode}'
            audio=Path(str(stem)+'.audio')
            log=Path(str(stem)+'.log')
            trace=Path(str(stem)+'.arm')
            env={k:v for k,v in os.environ.items() if not k.startswith('VF3_')}
            env.update(VF3_INTERPRETER='1',VF3_STATE=str(state.resolve()),
                       VF3_TRACE_FRAMES='180',VF3_AUDIO_CHECKPOINTS=str(audio),
                       VF3_AUDIO_POINTS=args.points)
            if mode=='traced': env['VF3_ARM_TRACE']=str(trace)
            with log.open('wb') as f:
                try:
                    code=subprocess.run([str(args.emulator.resolve()),str(ROOT/'rom/vf3.gdi')],
                        cwd=args.emulator.resolve().parent,env=env,stdout=f,
                        stderr=subprocess.STDOUT,timeout=args.timeout).returncode
                except subprocess.TimeoutExpired: code='timeout'
            row=dict(state=str(state),mode=mode,returncode=code,
                     log=dict(path=str(log),sha256=sha(log)),passed=False)
            if audio.exists():
                archive,raw_sha=compress_checkpoint(audio)
                row['audio']=describe(archive)
                row['raw_sha256']=raw_sha
                row['passed']=code==0 and [r['identity'][0] for r in row['audio']['checkpoints']]==points
            if mode=='traced' and trace.exists():
                try:
                    count=sum(1 for _ in records(trace))
                except ValueError as error:
                    count=0
                    row['trace_error']=str(error)
                footer=re.search(r'\[vf3armtrace\] events=(\d+) truncated=(\d+)',log.read_text(errors='replace'))
                row['trace']=dict(path=str(trace),sha256=sha(trace),records=count)
                row['passed'] &= bool(footer and int(footer[1])==count>0 and footer[2]=='0')
            elif mode=='traced': row['passed']=False
            manifest['runs'].append(row)
            pairs.append(row)
            save()
            print(f'{state.stem} {mode}: passed={row["passed"]}',flush=True)
        result=compare(pairs[0]['audio']['path'],pairs[1]['audio']['path']) if all(r['passed'] for r in pairs) else dict(equal=False)
        manifest['comparisons'].append(dict(state=str(state),**result))
        print(result,flush=True)
        save()
    manifest['passed']=all(r['passed'] for r in manifest['runs']) and all(r['equal'] for r in manifest['comparisons'])
    save()
    return 0 if manifest['passed'] else 2


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--state',type=Path,action='append',required=True)
    ap.add_argument('--emulator',type=Path,required=True)
    ap.add_argument('--out',type=Path,required=True)
    ap.add_argument('--points',default='1,4194304')
    ap.add_argument('--timeout',type=int,default=90)
    args=ap.parse_args()
    with emulator_lock(args.emulator): return run(args)


if __name__=='__main__': raise SystemExit(main())
