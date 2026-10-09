"""Relink and verify the native suites without overwriting a frozen matrix replay."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys
import time
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import portcheck
from audio_determinism import ROOT,sha


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--after',type=Path,help='wait for this baseline portcheck to finish before relinking')
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args()
    if a.out.exists():raise FileExistsError(a.out)
    if a.after:
        while True:
            log=a.after.read_text(encoding='utf-8-sig')
            if 'portcheck: FAIL' in log:raise ValueError('baseline regression failed')
            if 'portcheck: PASS' in log:break
            time.sleep(10)
    build_log=a.out.with_suffix('.build.log')
    env=dict(os.environ)
    if os.name=='nt':env['PATH']='C:/msys64/ucrt64/bin;'+env['PATH']
    with build_log.open('wb') as output:
        subprocess.run(['cmake','--build','build','--target',*portcheck.TESTS,'--parallel','4'],
                       cwd=ROOT,env=env,stdout=output,stderr=subprocess.STDOUT,check=True)
    results=portcheck.run_tests()
    rows=[dict(name=name,status=status,output=output,
               executable=dict(path=f'build/{name}.exe',sha256=sha(ROOT/'build'/f'{name}.exe')))
          for name,status,output in results]
    report=dict(passed=all(row['status']=='PASS' for row in rows),count=len(rows),
                results=rows,build_log=dict(path=str(build_log),sha256=sha(build_log)),
                runner=dict(path=str(Path(__file__)),sha256=sha(__file__)))
    a.out.write_text(json.dumps(report,indent=2)+'\n')
    print(f"{sum(row['status']=='PASS' for row in rows)}/{len(rows)} freshly linked native suites pass")
    return 0 if report['passed'] else 2


if __name__=='__main__':raise SystemExit(main())
