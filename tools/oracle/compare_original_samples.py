"""Compare two full original specimens without granting coverage or quarantine."""
import argparse
import json
from pathlib import Path
import struct
from capsules import records
from evidence_inspect import fingerprints, digest


def compare(left_path,left_id,right_path,right_id):
    samples=[]
    for path,ident in ((left_path,left_id),(right_path,right_id)):
        sample=next((r for r in records(path) if r['id']==ident),None)
        if sample is None:raise ValueError('missing original invocation')
        if sample['flags'] or sample['nstate']!=63 or sample['device']:
            raise ValueError('comparison requires complete 63-word RAM-only specimens')
        samples.append(sample)
    left,right=samples
    if (left['entry']&0x1fffffff)!=(right['entry']&0x1fffffff):raise ValueError('different roots')
    before=[struct.unpack('<63I',s['before']) for s in samples]
    after=[struct.unpack('<63I',s['after']) for s in samples]
    signatures=[fingerprints(s) for s in samples]
    memory=[]
    lpages={base:(a,b) for base,a,b in left['pages']};rpages={base:(a,b) for base,a,b in right['pages']}
    for base in sorted(lpages.keys()|rpages.keys()):
        if base not in lpages or base not in rpages:
            memory.append(dict(base=hex(base),present_left=base in lpages,present_right=base in rpages));continue
        if lpages[base]!=rpages[base]:
            memory.append(dict(base=hex(base),before_equal=lpages[base][0]==rpages[base][0],
                after_equal=lpages[base][1]==rpages[base][1],
                left_after_preview=lpages[base][1][:16].hex(),right_after_preview=rpages[base][1][:16].hex()))
    inputs_equal=signatures[0][0]==signatures[1][0]
    outputs_equal=signatures[0][1]==signatures[1][1]
    lops=[(pc&0x1fffffff,op) for pc,op in left['ops']]
    rops=[(pc&0x1fffffff,op) for pc,op in right['ops']]
    op_differences=[dict(index=i,left=[hex(a[0]),hex(a[1])],right=[hex(b[0]),hex(b[1])])
                    for i,(a,b) in enumerate(zip(lops,rops)) if a!=b]
    return dict(diagnostic_only=True,coverage_credit=False,
        references=[dict(path=str(Path(p).resolve()),sha256=digest(p),invocation=n)
                    for p,n in ((left_path,left_id),(right_path,right_id))],
        captured_inputs_equal=inputs_equal,captured_outputs_equal=outputs_equal,
        observable_disagreement=inputs_equal and not outputs_equal,
        input_register_differences=[i for i in range(63) if before[0][i]!=before[1][i]],
        output_register_differences=[i for i in range(63) if after[0][i]!=after[1][i]],
        memory_differences=memory,left_instructions=len(left['ops']),right_instructions=len(right['ops']),
        canonical_instruction_traces_equal=lops==rops,first_instruction_differences=op_differences[:10])


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('left',type=Path);parser.add_argument('right',type=Path)
    parser.add_argument('--left-id',type=int,required=True);parser.add_argument('--right-id',type=int,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args()
    if args.out.exists():raise FileExistsError('refusing to replace a comparison')
    result=compare(args.left,args.left_id,args.right,args.right_id)
    args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('references','memory_differences')},indent=2))
