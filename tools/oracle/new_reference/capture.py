#!/usr/bin/env python3
"""Bounded coldboot capture. Never adopts or rewrites a historical evidence seal."""
import argparse
import json
import os
from pathlib import Path
import shutil
import shlex
import struct
import subprocess
from bootstrap import digest

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--work-dir',type=Path,required=True)
    p.add_argument('--gdi',type=Path,required=True)
    p.add_argument('--out',type=Path,required=True)
    p.add_argument('--pc',type=lambda x:int(x,0),required=True,action='append')
    p.add_argument('--snapshots',type=int,default=1)
    p.add_argument('--frames',type=int,default=1200)
    p.add_argument('--instructions',type=int,default=200000000)
    p.add_argument('--timeout',type=int,default=180)
    a=p.parse_args()
    if not 1<=a.snapshots<=16: p.error('snapshot limit must be 1..16')
    if not 1<=a.frames<=20000: p.error('frame limit must be 1..20000')
    if not 1<=a.instructions<=2000000000: p.error('instruction limit must be 1..2000000000')
    if not 1<=a.timeout<=1800: p.error('timeout must be 1..1800 seconds')
    if any(not 0<=pc<=0xffffffff for pc in a.pc): p.error('PC must be an unsigned 32-bit address')
    targets={pc&0x1fffffff for pc in a.pc}
    if len(targets)!=len(a.pc): p.error('duplicate canonical PC targets')
    if len(targets)>1 and a.snapshots!=len(targets):
        p.error('multi-target capture requires one snapshot per unique target')
    work=a.work_dir.resolve(); out=a.out.resolve(); gdi=a.gdi.resolve()
    if out.exists(): p.error('output exists; preserve prior captures and choose a new directory')
    if shutil.disk_usage(work).free<4*1024**3: p.error('4 GiB free-space reserve reached')
    build=work/'build-manifest.json'
    manifest=json.loads(build.read_text())
    for row in manifest['files']:
        if digest(row['path'])!=row['sha256']: p.error('build dependency changed: '+row['path'])
    track_paths=[]
    lines=gdi.read_text().splitlines()
    for line in lines[1:]:
        fields=shlex.split(line)
        if len(fields)!=6: p.error('invalid GDI track descriptor')
        track_paths.append(gdi.parent/fields[4])
    if len(track_paths)!=int(lines[0]): p.error('GDI track count mismatch')
    media=[dict(path=str(track.resolve()),bytes=track.stat().st_size,sha256=digest(track)) for track in track_paths]
    out.mkdir(parents=True)
    shutil.copyfile(build,out/'build-manifest.json')
    preserved=[]; references=out/'reference-inputs'; references.mkdir()
    for index,row in enumerate(manifest['files']):
        source=Path(row['path']); destination=references/(f'{index:02}_'+source.name)
        shutil.copyfile(source,destination)
        preserved.append(dict(original_path=str(source),preserved_path=str(destination.relative_to(out)),
                              sha256=digest(destination),bytes=destination.stat().st_size))
    (out/'reference-inputs.json').write_text(json.dumps(dict(schema='vf3-new-reference-input-preservation-v1',files=preserved),indent=2)+'\n')
    env={k:v for k,v in os.environ.items() if not k.startswith('VF3_')}
    env.update(VF3_NEW_OUT=str(out),VF3_NEW_PC=','.join(hex(pc) for pc in a.pc),VF3_NEW_MAX=str(a.snapshots),
               VF3_NEW_MAX_INSTRUCTIONS=str(a.instructions))
    cmd=[manifest.get('driver_path',str(work/'build/vf3-reference')),str(gdi),str(out/'private-data'),str(a.frames)]
    with (out/'run.log').open('wb') as f:
        try:
            result=subprocess.run(cmd,cwd=out,env=env,stdout=f,stderr=subprocess.STDOUT,timeout=a.timeout)
            code=result.returncode
        except subprocess.TimeoutExpired:
            code=124
    snapshots=sorted(out.glob('[0-9]*.json'))
    covered=set(); conversions=[]
    for snapshot in snapshots:
        state=json.loads(snapshot.read_text())
        if state['kind']=='entry': covered.add(state['pc']&0x1fffffff)
        if len(state['registers'])!=63: raise ValueError('unexpected register layout')
        context=snapshot.with_suffix('.context.bin')
        context.write_bytes(struct.pack('<64I',state['pc'],*state['registers']))
        conversions.append(dict(output=context.name,source=snapshot.name,source_sha256=digest(snapshot),
            format='64 little-endian uint32 words: fetched PC followed by registers[63]; no guest mutation'))
    complete=code==0 and len(snapshots)==a.snapshots and targets<=covered
    files=[p for p in out.iterdir() if p.is_file()]
    result=dict(schema='vf3-new-reference-capture-v1',historical_seal_reproduced=False,
        coverage_credit=False,build_manifest=dict(path='build-manifest.json',sha256=digest(out/'build-manifest.json')),
        gdi=dict(path=str(gdi),sha256=digest(gdi)),tracks=media,command=cmd,
        target=[hex(pc) for pc in a.pc],requested_snapshots=a.snapshots,captured_snapshots=len(snapshots),
        bounds=dict(frames=a.frames,instructions=a.instructions,timeout_seconds=a.timeout),
        covered_targets=[hex(pc) for pc in sorted(covered)],missing_targets=[hex(pc) for pc in sorted(targets-covered)],
        returncode=code,capture_complete=complete,
        last_status='requested_capture_complete' if complete else 'wall_timeout' if code==124 else 'process_error' if code else 'requested_capture_incomplete',
        context_conversions=conversions,
        raw_ram_requires_cache_interpretation=True,
        files=[dict(path=p.name,bytes=p.stat().st_size,sha256=digest(p)) for p in sorted(files)])
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:result[k] for k in ['target','returncode','captured_snapshots','capture_complete']}))
    return 0 if result['capture_complete'] else 1

if __name__=='__main__': raise SystemExit(main())
