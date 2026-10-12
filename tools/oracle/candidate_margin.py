"""Measure advisory owner margins against the current verified C address union."""
import argparse
import json
from pathlib import Path
import sys
from select_next import ROOT, union
from ram_clipping_batch_audit import reference

sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans


def measure(owners,coverage,target):
    dashboard=json.loads(Path(coverage).read_text())
    baseline=list(map(tuple,dashboard['ported_spans']));accepted=union(baseline)
    if accepted!=dashboard['ported_unique_bytes']:raise ValueError('inconsistent coverage dashboard')
    spans=body_spans();rows=[];added=[]
    for owner in sorted(set(owners)):
        if owner not in spans:raise ValueError(f'owner {owner:#x} outside frozen body inventory')
        rows.append(dict(owner=hex(owner),frozen_bytes=union(spans[owner]),
                         marginal_bytes=union(baseline+spans[owner])-accepted))
        added+=spans[owner]
    gain=union(baseline+added)-accepted
    return dict(advisory=True,coverage_credit=False,accepted_bytes=accepted,target_bytes=target,
        remaining_verified_bytes=max(0,target-accepted),candidates=rows,potential_unique_bytes=gain,
        potential_shortfall=max(0,target-accepted-gain),potential_margin=max(0,accepted+gain-target),
        references=[reference(p) for p in (Path(coverage),ROOT/'docs/decomp_status.csv',
            ROOT/'extract/analysis/function_body_ranges.csv',ROOT/'extract/analysis/funcs_1ST_READ.unsc.bin.csv',
            ROOT/'extract/gamedata/1ST_READ.BIN',Path(__file__))])


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--owner',action='append',type=lambda value:int(value,0)|0x80000000,required=True)
    parser.add_argument('--coverage',type=Path,default=ROOT/'extract/analysis/coverage.json')
    parser.add_argument('--target-bytes',type=int,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args()
    if args.out.exists():raise FileExistsError('refusing to replace a candidate snapshot')
    result=measure(args.owner,args.coverage,args.target_bytes)
    args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f"Accepted {result['accepted_bytes']}; gap {result['remaining_verified_bytes']}; potential gain {result['potential_unique_bytes']}; remaining shortfall {result['potential_shortfall']}")
