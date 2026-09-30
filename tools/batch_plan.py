#!/usr/bin/env python3
"""Rank shared dependencies by potential unique C bytes unlocked.

Consumes port_plan.csv and the frozen Ghidra ranges. SDK attribution does
not satisfy an executable dependency. Scores are planning estimates, never
coverage credit; unresolved calls remain listed in every cohort.
"""
import argparse
from collections import defaultdict
import csv
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

def union_bytes(spans):
    end=0; total=0
    for start,stop in sorted(spans):
        total+=max(0,stop-max(start,end)); end=max(end,stop)
    return total

def rank(plan,out):
    rows={int(r['entry'],16):r for r in csv.DictReader(open(plan,newline=''))}
    done={int(r['entry'],16) for r in csv.DictReader(open(ROOT/'docs/decomp_status.csv',newline='')) if r['status'].startswith('ported')}
    bodies=defaultdict(list)
    for r in csv.DictReader(open(ROOT/'extract/analysis/function_body_ranges.csv',newline='')):
        bodies[int(r['entry'],16)].append((int(r['start'],16),int(r['end'],16)))
    groups=defaultdict(list)
    for entry,row in rows.items():
        if entry in done or row['executed']!='Y': continue
        for dep in row['missing_implementations'].split(): groups[int(dep,16)].append(entry)
    result=[]
    for dep,callers in groups.items():
        if len(callers)<2: continue
        dependencies=sorted({int(d,16) for c in callers for d in rows[c]['missing_implementations'].split()})
        spans=[span for c in callers for span in bodies[c]]
        benefit=union_bytes(spans)
        known=sum(union_bytes(bodies[d]) for d in dependencies)
        unknown=sum(d not in bodies for d in dependencies)
        blockers={hex(c):rows[c]['missing_callees'] for c in callers if rows[c]['sh4_dyn']!='0' or rows[c]['sh4_fixed']!='0'}
        estimate=known+unknown*4096+64*len(callers)
        result.append(dict(dependency=hex(dep),callers=[hex(c) for c in callers],
                           potential_unique_caller_bytes=benefit,
                           missing_implementations=[hex(d) for d in dependencies],
                           unknown_dependency_bodies=unknown,unresolved_calls=blockers,
                           estimated_score=round(benefit/max(estimate,1),4)))
    result.sort(key=lambda r:(-r['estimated_score'],-r['potential_unique_caller_bytes']))
    Path(out).write_text(json.dumps(result,indent=1)+'\n',encoding='utf-8')
    for r in result[:10]:
        print(f"{r['dependency']}: {len(r['callers'])} callers, {r['potential_unique_caller_bytes']} potential bytes, score {r['estimated_score']}")
    return result

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--plan',default='extract/analysis/port_plan.csv')
    ap.add_argument('--out',default='extract/analysis/batch_plan.json')
    a=ap.parse_args(); rank(a.plan,a.out)
