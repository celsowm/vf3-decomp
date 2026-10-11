"""Owned RAM destinations for five-lane command replication boundaries."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c05d424'

def prepare():
    for held,label in [(False,'dev'),(True,'accept')]:
        shift=0x100000 if held else 0
        memory={};registers={ENTRY:{'r4':[0 if i%8==0 else 1+i%3 for i in range(64)]}}
        def values(address,fn):memory[hex(address)]=[fn(i)&0xffffffff for i in range(64)]
        values(0x0c16cee8,lambda i:i%32 if i<32 else 31)
        values(0x0c16cdc4,lambda i:0 if i<32 else 1)
        values(0x0c16cea0,lambda i:32+i%5 if i<60 else 0)
        for record in range(3):
            for lane in range(5):
                values(0x0c16ca18+record*20+lane*4,
                    lambda i,r=record,l=lane:0x0c410000+shift+r*0x1000+l*0x100)
        for lane in range(5):values(0x0c16ca74+lane*4,lambda i:100+i)
        memory={ENTRY:memory}
        for kind,data in [('memory',memory),('registers',registers)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_render_lanes_{label}_v1_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_render_lanes_watch_v1.txt',
            ROOT/f'extract/analysis/coverage_65_render_lanes_{label}_v1.patch',0x8c0432e2,64,
            relocation=shift,fpscr=0x240001 if held else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=held,
            memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
