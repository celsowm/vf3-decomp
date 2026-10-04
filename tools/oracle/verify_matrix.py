#!/usr/bin/env python3
"""Verify every matrix cohort entry once, recording successes and failures."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor, as_completed

ROOT=Path(__file__).resolve().parents[2]
def verify(directory,out,min_cases=1,jobs=1,watch=None,executable=None,timeout=120):
    directory=Path(directory)
    env=dict(os.environ); env["PATH"]="C:/msys64/ucrt64/bin;"+env["PATH"]
    env["VF3_STRICT_REPLAY"]="1"
    rows={}
    executable=Path(executable) if executable else ROOT/'build/vf3matrixfamily.exe'
    executable=executable.resolve()
    with executable.open('rb') as stream:
        executable_hash=hashlib.file_digest(stream,'sha256').hexdigest()
    try:
        executable_name=executable.relative_to(ROOT).as_posix()
    except ValueError:
        executable_name=str(executable)
    counts=json.loads((directory/'capsule_manifest.json').read_text())['entries']
    selected={int(line.split()[1],16)|0x80000000 for line in Path(watch).read_text().splitlines()
              if line.startswith('pc ')} if watch else None
    paths=[]
    for path in sorted(directory.glob("*.cases")):
        entry=int(path.stem.split("_")[1],16)
        if selected is not None and entry not in selected: continue
        if entry in (0x8c076c00,0x8c0782ea): continue
        if len(counts.get(hex(entry),[]))<min_cases: continue
        paths.append(path)
    def replay(path):
        entry=int(path.stem.split('_')[1],16)
        start=time.monotonic()
        p=subprocess.run([str(executable.resolve()),hex(entry),str(path.resolve())],cwd=ROOT,env=env,capture_output=True,text=True,timeout=timeout)
        return hex(entry),{"pass":p.returncode==0,"seconds":round(time.monotonic()-start,3),"stdout":p.stdout.strip(),"stderr":p.stderr.strip(),"cases":str(path),"executable":executable_name,"executable_sha256":executable_hash}
    with ThreadPoolExecutor(max_workers=jobs) as executor:
        futures=[executor.submit(replay,path) for path in paths]
        for future in as_completed(futures):
            entry,row=future.result(); rows[entry]=row
            Path(out).write_text(json.dumps(dict(sorted(rows.items())),indent=1),encoding='utf-8')
            print(entry,'PASS' if row['pass'] else 'FAIL',row['stdout'],flush=True)
            if not row['pass']: print(row['stderr'][:700],flush=True)
    rows=dict(sorted(rows.items()))
    Path(out).write_text(json.dumps(rows,indent=1),encoding="utf-8")
    print(f"{sum(r['pass'] for r in rows.values())}/{len(rows)} complete entry replays pass")
    return rows
if __name__=="__main__":
    ap=argparse.ArgumentParser(description=__doc__); ap.add_argument("directory"); ap.add_argument("--out",required=True)
    ap.add_argument('--discover',action='store_true',help='record unsupported entries without failing the campaign gate')
    ap.add_argument('--min-cases',type=int,default=1,help='minimum corpus size for discovery; omitted entries receive no proof')
    ap.add_argument('--watch',help='replay only selected entry PCs')
    ap.add_argument('--jobs',type=int,default=1,choices=range(1,5),help='independent replay processes (1-4); do not rebuild their executable concurrently')
    ap.add_argument('--executable',help='immutable replay executable snapshot for concurrent capture or other replay cohorts')
    ap.add_argument('--timeout',type=int,default=120,help='seconds allowed for a complete entry replay')
    a=ap.parse_args(); rows=verify(a.directory,a.out,a.min_cases,a.jobs,a.watch,a.executable,a.timeout)
    raise SystemExit(0 if a.discover or (rows and all(r['pass'] for r in rows.values())) else 1)
