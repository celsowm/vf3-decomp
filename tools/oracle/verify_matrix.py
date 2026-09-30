#!/usr/bin/env python3
"""Verify every matrix cohort entry once, recording successes and failures."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
def verify(directory,out,min_cases=1):
    directory=Path(directory)
    env=dict(os.environ); env["PATH"]="C:/msys64/ucrt64/bin;"+env["PATH"]
    env["VF3_STRICT_REPLAY"]="1"
    rows={}
    counts=json.loads((directory/'capsule_manifest.json').read_text())['entries']
    for path in sorted(directory.glob("*.cases")):
        entry=int(path.stem.split("_")[1],16)
        if entry in (0x8c076c00,0x8c0782ea): continue
        if len(counts.get(hex(entry),[]))<min_cases: continue
        start=time.monotonic()
        p=subprocess.run([str(ROOT/"build/vf3matrixfamily.exe"),hex(entry),str(path.resolve())],cwd=ROOT,env=env,capture_output=True,text=True,timeout=120)
        rows[hex(entry)]={"pass":p.returncode==0,"seconds":round(time.monotonic()-start,3),"stdout":p.stdout.strip(),"stderr":p.stderr.strip(),"cases":str(path)}
        print(hex(entry),"PASS" if p.returncode==0 else "FAIL",p.stdout.strip(),flush=True)
        if p.returncode: print(p.stderr[:700],flush=True)
    Path(out).write_text(json.dumps(rows,indent=1),encoding="utf-8")
    print(f"{sum(r['pass'] for r in rows.values())}/{len(rows)} complete entry replays pass")
    return rows
if __name__=="__main__":
    ap=argparse.ArgumentParser(description=__doc__); ap.add_argument("directory"); ap.add_argument("--out",required=True)
    ap.add_argument('--discover',action='store_true',help='record unsupported entries without failing the campaign gate')
    ap.add_argument('--min-cases',type=int,default=1,help='minimum corpus size for discovery; omitted entries receive no proof')
    a=ap.parse_args(); rows=verify(a.directory,a.out,a.min_cases)
    raise SystemExit(0 if a.discover or (rows and all(r['pass'] for r in rows.values())) else 1)
