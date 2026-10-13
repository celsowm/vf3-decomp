"""Emit authored caller declarations for the final 65-percent candidates."""
import argparse
import json
from pathlib import Path
import sys
from actor_table_inputs import EXTRA_OWNERS
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from callable_actor_tables import ROWS,TABLE,CALL,KIND
from callable_small_ram import ROWS as RAM_ROWS,KIND as RAM_KIND

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('batch',choices=('actor','ram'))
    p.add_argument('--out',type=Path,required=True);a=p.parse_args()
    if a.out.exists():raise FileExistsError(a.out)
    if a.batch=='actor':
        data={hex(owner):dict(kind=KIND,entry=hex(entry),index=ROWS[owner][1],
            table=hex(TABLE),call_sites=[hex(CALL)],callee_save_prefix=['r14'])
            for entry,owner in EXTRA_OWNERS.items()}
    else:
        data={hex(owner):dict(kind=RAM_KIND,entry=hex(entry),dispatch_start=hex(start),
            call_sites=[hex(call)],callee_save_prefix=[f'r{i}' if i<16 else f'fr{i-21}' for i in saves if i!=16])
            for owner,(entry,start,call,rts,returned,saves) in RAM_ROWS.items()}
    a.out.write_text(json.dumps(data,indent=2)+'\n')
