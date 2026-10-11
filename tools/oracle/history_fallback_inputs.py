"""Owned fallback tables covering sentinels, lengths, ties and seed fallback."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0c0f60'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actor,record,table,header=0x0c410000,0x0c440000,0x0c450000,0x0c460000
        regs={ENTRY:dict(r4=actor,r5=record)};m={};memory={ENTRY:m}
        m[hex(record+4)]=table;m[hex(record+44)]=header
        m[hex(header)]=[0 if i%8==0 or i==63 else 2 for i in range(64)]
        m[hex(0x0c29bcc4+0xb0)]=[(0x76543210 if holdout else 0x12345678)+i*7919 for i in range(64)]
        m[hex(0x0c29bcc4+0xb4)]=0x41c64e6d;m[hex(0x0c29bcc4+0xb8)]=0x3039
        def row_bytes(i,row):
            kind=i%8
            chars=[1,2,3,4,5];weights=[255]*5
            if kind==1:chars[0]=255
            elif kind==2:chars[1]=255
            elif kind==3:weights[0]=0
            elif kind==4:chars[2 if row%2==0 else 3]=255;weights=[1+row%3]*5
            elif kind==5:weights=[3+row%5]*5
            elif kind==6:chars[3 if row%2==0 else 2]=255;weights=[255]*5
            return bytes(chars+weights+[0]*22)
        for row in range(128):
            for off in [0,4,8]:m[hex(table+row*32+off)]=[int.from_bytes(row_bytes(i,row)[off:off+4],'little') for i in range(64)]
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_history_fallback_{label}_v2_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_history_fallback_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_history_fallback_{label}_v2.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
