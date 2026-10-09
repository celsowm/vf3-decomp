"""Extract independent inputs and ordered-store expectations for the A0 handoff.

This gate covers protocol stores, not ARM registers, interrupts, cycle timing,
later command handling or PCM. It never earns SH-4 frozen-body coverage.
"""
import argparse
import json
from pathlib import Path
import struct
from arm_trace import records
from audio_determinism import checkpoints,sha
from audio_state import ARAM_OFFSET,ARAM_BYTES


def extract(trace,checkpoint,out):
    rows=list(records(trace))
    first=next(checkpoints(checkpoint))
    wave=first['blocks'][3][ARAM_OFFSET:ARAM_OFFSET+ARAM_BYTES]
    forward=struct.unpack_from('<I',wave,0xa210)[0]
    stores={0x680,0x688,0x698,0x6a0,0x6a8,0x6b0,0x6b8,0x245c,0x246c}
    cases=[]
    for i,row in enumerate(rows):
        if row['store'] and row['pc']==0x246c:forward=row['value']
        if row['pc']!=0x668 or row['store'] or not row['value']:continue
        end=next((j for j in range(i+1,len(rows)) if rows[j]['pc']==0x668),len(rows))
        window=rows[i:end]
        confirmed=[r for r in window if r['pc']==0x674 and not r['store']]
        if len(confirmed)!=1 or confirmed[0]['value']!=row['value']:
            raise ValueError('this corpus requires stable double reads')
        if row['value']&255!=0xa0:raise ValueError('unimplemented command class')
        effects=[r for r in window if r['store'] and r['pc'] in stores]
        if len(effects)!=9:raise ValueError('incomplete or ambiguous handoff')
        cases.append(dict(input=dict(pop=row['address']-0x400,forward=forward,word=row['value']),
                          sequence=row['sequence'],stores=effects))
    if not cases:raise ValueError('no observed A0 handoffs')
    out=Path(out)
    if out.exists():raise FileExistsError(out)
    out.mkdir(parents=True)
    lines=[]
    for case in cases:
        x=case['input'];lines.append(f"{x['pop']:x} {x['forward']:x} {x['word']:x} 9")
        lines.extend(f"{r['address']:x} {r['value']:x} {r['size']}" for r in case['stores'])
    (out/'handoff.cases').write_text('\n'.join(lines)+'\n')
    manifest=dict(coverage_credit=False,scope='A0 ordered stores only',
                  standalone_audio=False,manual_listening_completed=False,
                  source={str(p):sha(p) for p in (trace,checkpoint)},cases=cases,
                  omitted_contracts=['ARM architectural state','interrupt timing','cycles',
                                     'non-A0 classes','voice dispatch','DSP','PCM'])
    (out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(f'{len(cases)} observed independent A0 inputs')


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('trace',type=Path);ap.add_argument('checkpoint',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();extract(a.trace,a.checkpoint,a.out)
