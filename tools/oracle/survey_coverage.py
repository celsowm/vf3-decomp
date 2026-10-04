#!/usr/bin/env python3
"""Rank unported bodies reached by VF3_HITS surveys (planning only)."""
import argparse
from collections import defaultdict
import csv
import json
from pathlib import Path
from capture_frames import expected_frames, observed_frames

ROOT=Path(__file__).resolve().parents[2]

def union(spans):
    end=0; size=0
    for start,stop in sorted(spans):
        size+=max(0,stop-max(start,end)); end=max(end,stop)
    return size

def report(batches, out, plan=None):
    baseline=list(map(tuple,json.loads((ROOT/'extract/analysis/coverage.json').read_text())['ported_spans']))
    done={int(r['entry'],16) for r in csv.DictReader((ROOT/'docs/decomp_status.csv').open()) if r['status'].startswith('ported')}
    candidates={int(r['entry'],16):r for r in csv.DictReader(Path(plan or ROOT/'extract/analysis/port_plan.csv').open())
                if int(r['entry'],16) not in done and (plan is not None or r['campaign']!='accounted')}
    spans=defaultdict(list)
    for row in csv.DictReader((ROOT/'extract/analysis/function_body_ranges.csv').open()):
        spans[int(row['entry'],16)].append((int(row['start'],16),int(row['end'],16)))
    observed=defaultdict(dict); runs=[]; rejected=[]
    for batch in batches:
        b=json.loads((Path(batch)/'batch_manifest.json').read_text())
        for r in b['runs']:
            expected=expected_frames(r['frames'],(ROOT/r['play']) if r['play'] and not Path(r['play']).is_absolute() else r['play'])
            frames=observed_frames(r['log'])
            if r['returncode'] or frames<expected or not r.get('hits'):
                rejected.append(dict(name=r['name'],frames=frames,expected=expected,returncode=r['returncode']))
                continue
            path=Path(r['hits']); rows=list(csv.DictReader(path.open()))
            if len(rows)!=sum(line.startswith('pc ') for line in Path(b['watch']).read_text().splitlines()):
                raise ValueError(f'incomplete hit file: {path}')
            for row in rows:
                entry=int(row['entry'],16)
                if entry in candidates and int(row['hits']):
                    observed[entry][r['name']]=int(row['hits'])
            runs.append(dict(name=r['name'],state=r['state'],play=r['play'],seconds=r['seconds'],frames=frames,hit_file=str(path)))
    def gain(entries):
        return union(baseline+[s for e in entries for s in spans[e]])-union(baseline)
    rows=[]
    for e,hits in observed.items():
        rows.append(dict(entry=f'0x{e:08x}',size=int(candidates[e]['size']),scenarios=len(hits),total_hits=sum(hits.values()),hits=hits))
    rows.sort(key=lambda r:(-r['size'],-r['scenarios']))
    all_entries=set(observed); repeated={e for e,h in observed.items() if len(h)>=2}
    data=dict(runs=runs,rejected_runs=rejected,observed_roots=len(all_entries),observed_unique_bytes=gain(all_entries),repeated_roots=len(repeated),repeated_unique_bytes=gain(repeated),rows=rows)
    Path(out).write_text(json.dumps(data,indent=1)+'\n')
    print(f"{len(runs)} runs: {len(all_entries)} new unported roots, {gain(all_entries)} unique candidate bytes; {len(repeated)} roots / {gain(repeated)} bytes reached in >=2 runs")
    if rejected: print('Rejected short/failed runs:',rejected)
    for row in rows[:24]: print(row['entry'],row['size'],'B',row['scenarios'],'runs',row['total_hits'],'hits')
    return data

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('batches',nargs='+')
    ap.add_argument('--out',required=True)
    ap.add_argument('--plan',help='refreshed port plan; SDK-attributed bodies remain C candidates')
    a=ap.parse_args();report(a.batches,a.out,a.plan)
