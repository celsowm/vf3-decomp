"""Finite scales, actor selections, angles and enable masks for contact setup."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a07e4'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        first,second,actors,link,output=0x0c410000,0x0c420000,0x0c430000,0x0c450000,0x0c460000
        regs={ENTRY:{'r4':output}};m={};memory={ENTRY:m}
        m[hex(0x0c29bb84+16)]=first;m[hex(0x0c29bb84+20)]=second
        m[hex(0x0c29bb84+68)]=link;m[hex(link+0xdc)]=actors
        m[hex(0x0c29bcc4)]=bits(.375 if holdout else .25)
        m[hex(0x0c29bcc4+0x398)]=[0x01000000 if i%2 else 0 for i in range(64)]
        m[hex(0x0c0ea4e0)]=[(0x31415927 if holdout else 0x12345678)+i*7919 for i in range(64)]
        angles=[0,1,16384,32767,32768,49152,65535,12345]
        for a in [first,second]:
            m[hex(a+72)]=[0x1000 if i//2%2 else 0 for i in range(64)]
            m[hex(a+28)]=[(angles[(i//4+int(holdout))%8]<<16)|0x2345 for i in range(64)]
            m[hex(a+0x1a28)]=[angles[(i//8+3+int(holdout))%8] for i in range(64)]
        for slot in range(18):
            actor=actors+slot*0x1d8
            for off in range(0,0x1d8,4):m[hex(actor+off)]=0
            m[hex(0x0c10dbe8+slot*12+4)]=[bits([.5,.75,1,1.25,1.5,2,3,4][(slot+i//8+int(holdout))%8]) for i in range(64)]
            m[hex(0x0c10dbe8+slot*12+8)]=[1 if i%16==15 or slot==(i//4)%18 or (i%8==7 and slot==17) else 0 for i in range(64)]
            for k in range(3):m[hex(0x0c10dcc0+slot*12+k*4)]=[bits((slot+k+1)*(.1875 if holdout else .125)*(-1 if i//8%2 else 1)) for i in range(64)]
            for k in range(16):m[hex(output+0x180+slot*64+k*4)]=bits(1 if k in (0,5,10,15) else 0)
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_contact_init_{label}_v1_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_contact_init_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_contact_init_{label}_v1.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
