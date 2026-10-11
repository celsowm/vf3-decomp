"""Contact-history flags, frame keys and finite five-entry history records."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0c0bf4'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actor,other,fighter,record=0x0c410000,0x0c420000,0x0c430000,0x0c440000
        regs={ENTRY:dict(r4=actor,r5=other,r6=fighter,r7=record)};m={};memory={ENTRY:m}
        for a in [actor,record]:
            for off in range(0,128,4):m[hex(a+off)]=0
        m[hex(0x0c29b864)]=[0 if i==0 else 0x03000000 for i in range(64)]
        m[hex(0x0c29b864+4)]=[0 if i==1 else 0x00c00000 for i in range(64)]
        flags=[0x4000,0x02000000,0x08000000,0,2,4,16,22]
        m[hex(record+12)]=[flags[i%8]|(0x1000 if i//8%2 else 0) for i in range(64)]
        m[hex(record+4)]=0x0c450000;m[hex(record+44)]=0x0c460000
        m[hex(0x0c460000)]=0
        for row in range(128):
            m[hex(0x0c450000+row*32)]=[0x04030201 if i//8%2 else 0x040302ff for i in range(64)]
            m[hex(0x0c450000+row*32+4)]=[0x00000005 if i//8%2 else 0 for i in range(64)]
        m[hex(record+20)]=[(i//8)%5 for i in range(64)]
        m[hex(record+24)]=[(100 if holdout else 64)+(i//16%3-1)*8 for i in range(64)]
        m[hex(record+28)]=[255 if i//8%3==0 else 7+int(holdout) for i in range(64)]
        m[hex(record+40)]=[0x08000000 if i//8%2 else 0 for i in range(64)]
        m[hex(fighter+96)]=[i%32<<8 for i in range(64)]
        m[hex(actor+64)]=[0x20|(0x2000 if i//4%2 and i%8!=5 else 0)|0x500|0x60 for i in range(64)]
        m[hex(actor+68)]=(100 if holdout else 64)|0x12340000
        m[hex(actor+16)]=0x04030201;m[hex(actor+20)]=0x05060504
        for off in [22,24,26,28,32,34,36,38,40]:
            base=actor+(off&~3);old=m.get(hex(base),0)
            if not isinstance(old,list):m[hex(base)]=(old&~(65535<<((off&2)*8)))|((1 if off==22 else off)<<((off&2)*8))
        for k in range(5):m[hex(actor+44+k*4)]=[0 if i//16%2 else 0x00010101+k+int(holdout) for i in range(64)]
        m[hex(actor+20)]=[0x0504|((0x0408 if i==38 else 1)<<16) for i in range(64)]
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_contact_history_{label}_v4_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_contact_history_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_contact_history_{label}_v4.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
