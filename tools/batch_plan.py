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
import struct
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

def implementation_graph(image,resolved):
    """Original-image bodies and transitive static calls, independent of seeds."""
    cache={}
    def body(entry):
        if entry in cache: return cache[entry]
        seen=set(); calls=set(); unknown=set(); work=[entry|0x80000000]
        def word(pc):
            off=(pc|0x80000000)-0x8c010000
            return struct.unpack_from('<H',image,off)[0] if 0<=off<len(image)-1 else None
        def signed(v,b): return v-(1<<b) if v&(1<<(b-1)) else v
        while work and len(seen)<8192:
            pc=work.pop()
            if pc in seen: continue
            w=word(pc)
            if w is None: unknown.add(pc); continue
            seen.add(pc); top=w>>12; kind=(w>>8)&15
            delayed=top in (10,11) or w in (11,43) or (w&0xf0ff) in (0x400b,0x402b,3,35) or (w&0xff00) in (0x8d00,0x8f00)
            if delayed and word(pc+2) is not None: seen.add(pc+2)
            if w in (11,43): continue
            if top==10: work.append(pc+4+signed(w&4095,12)*2)
            elif top==11:
                calls.add(pc+4+signed(w&4095,12)*2); work.append(pc+4)
            elif top==8 and kind in (9,11,13,15):
                work.extend([pc+4+signed(w&255,8)*2,pc+(4 if delayed else 2)])
            elif (w&0xf0ff) in (0x400b,0x402b,3,35):
                if pc in resolved: calls.add(resolved[pc])
                else: unknown.add(pc)
                if (w&0xf0ff) in (0x400b,3): work.append(pc+4)
            else: work.append(pc+2)
        if work: unknown.update(work)
        cache[entry]=(seen,calls,unknown)
        return cache[entry]
    return body

def union_bytes(spans):
    end=0; total=0
    for start,stop in sorted(spans):
        total+=max(0,stop-max(start,end)); end=max(end,stop)
    return total

def rank(plan,out):
    rows={int(r['entry'],16):r for r in csv.DictReader(open(plan,newline=''))}
    done={int(r['entry'],16) for r in csv.DictReader(open(ROOT/'docs/decomp_status.csv',newline='')) if r['status'].startswith('ported')}
    for path in (ROOT/'tools/oracle').glob('*_batch.json'):
        done.update(int(e,16) for e in json.loads(path.read_text()).get('helpers',[]))
    resolved={int(r['site'],16):int(r['target'],16)|0x80000000 for r in csv.DictReader(open(ROOT/'extract/analysis/sh4_resolved.csv')) if r['class']=='STATIC'}
    scan=implementation_graph((ROOT/'extract/exe/1ST_READ.unsc.bin').read_bytes(),resolved)
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
        closure=set(); code=set(); unknown_sites=set(); todo=list(dependencies)
        while todo:
            d=todo.pop()|0x80000000
            if d in closure or d in done: continue
            closure.add(d); pcs,targets,unresolved=scan(d)
            code.update(pcs); unknown_sites.update(unresolved); todo.extend(targets)
        known=2*len(code)
        unknown=len(unknown_sites)
        blockers={hex(c):rows[c]['missing_callees'] for c in callers if rows[c]['sh4_dyn']!='0' or rows[c]['sh4_fixed']!='0'}
        estimate=known+unknown*4096+64*len(callers)
        result.append(dict(dependency=hex(dep),callers=[hex(c) for c in callers],
                           potential_unique_caller_bytes=benefit,
                           missing_implementations=[hex(d) for d in dependencies],
                           unknown_dependency_bodies=unknown,unresolved_calls=blockers,
                           reachable_dependency_bytes=known,
                           static_implementation_closure=[hex(d) for d in sorted(closure)],
                           unresolved_dependency_sites=[hex(s) for s in sorted(unknown_sites)],
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
