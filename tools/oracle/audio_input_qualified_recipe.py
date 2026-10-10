"""Expand the proven selection branches to disjoint 64-case qualification sets."""
import copy
import json
from pathlib import Path
from audio_callers_recipe import selection


def campaign(acceptance=False):
    original=selection(acceptance)
    rows=[]
    for n in range(32):
        row=copy.deepcopy(original['cases'][n%18])
        row['name']=f'{"accept" if acceptance else "dev"}_qualified_input_{n:02d}'
        row['registers']['r13']=0x56780000+n+(256 if acceptance else 0)
        row['registers']['r14']=0x67890000+n+(256 if acceptance else 0)
        row['memory']['0xc1fd758']=(0x9a00 if acceptance else 0x8100)+n
        if n>=18:
            row['memory']['0xc29bd7c']=((n*13+(37 if acceptance else 0))%458)<<16
            base=0x0c480000 if acceptance else 0x0c404000
            row['memory'][hex(base+96)]=((n+3)%9)<<8
            row['memory'][hex(base+0x100+96)]=((n+7)%9)<<8
        rows.append(row)
    return dict(advisory=True,coverage_credit=False,trigger=original['trigger'],cases=rows)


if __name__=='__main__':
    for name,acceptance in (('dev',False),('accept',True)):
        Path(__file__).with_name(f'audio_input_qualified_{name}_v2.json').write_text(
            json.dumps(campaign(acceptance),indent=2)+'\n')
