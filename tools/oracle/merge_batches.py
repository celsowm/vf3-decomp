#!/usr/bin/env python3
"""Merge capture batches with input deduplication and preserved provenance."""
import argparse
import json
from pathlib import Path

from capsules import convert


def merge(directories, out, watch=None):
    runs=[]; paths=[]; seen=set(); watches=set()
    for directory in directories:
        batch=json.loads((Path(directory)/'batch_manifest.json').read_text())
        watches.add(batch['watch'])
        for run in batch['runs']:
            if run['returncode'] != 0:
                raise ValueError(f"failed capture: {run['name']}")
            path=str(Path(run['capsule']).resolve())
            if path in seen: continue
            seen.add(path); paths.append(path)
            runs.append({**run,'name':batch['name']+':'+run['name']})
    if not paths: raise ValueError('no capture inputs')
    out=Path(out)
    entries=None
    if watch:
        entries={int(line.split()[1],16)|0x80000000 for line in Path(watch).read_text().splitlines() if line.startswith('pc ')}
    convert(paths,out,entries)
    (out/'batch_manifest.json').write_text(json.dumps({
        'name':out.name,'watch':' '.join(sorted(watches)),'runs':runs
    },indent=1)+'\n')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directories',nargs='+')
    parser.add_argument('--out',required=True)
    parser.add_argument('--watch',help='export selected entries while checking every capture record and shutdown summary')
    args=parser.parse_args()
    merge(args.directories,args.out,args.watch)
