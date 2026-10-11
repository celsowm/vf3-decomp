"""Finite scene contact records for the eighteen-slot aggregation caller."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a0aec'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actors=0x0c430000;link=0x0c450000;output=0x0c460000
        regs={ENTRY:{}}
        m={};memory={ENTRY:m}
        m[hex(0x0c29bcc0)]=[0x80001 if i%16==0 else 0 for i in range(64)]
        m[hex(0x0c29bb84+0x44)]=link
        m[hex(link+0xdc)]=actors
        for off in [0x10,0x14]:m[hex(0x0c29bb84+off)]=output
        m[hex(0x0c29bcc4+0x398)]=[0x01000000 if i%2 else 0 for i in range(64)]
        palette=[-3,-1,-.25,0,.25,1,2,4] if not holdout else [-4,-1.5,-.125,0,.5,1.25,3,5]
        angles=[-32768,-16384,-1,0,1,16383,16384,32767]
        for slot in range(18):
            actor=actors+slot*0x1d8;cfg=actor+0xc4
            for off in range(0,0x1d8,4):m[hex(actor+off)]=0
            m[hex(0x0c10dbe8+slot*12+8)]=[1 if slot==(i//4)%18 or (i%8==7 and slot==17) else 0 for i in range(64)]
            m[hex(actor)]=[i%4 for i in range(64)]
            for p in range(3):
                for k in range(3):m[hex(actor+4+p*12+k*4)]=[bits(palette[(i//4+p*2+k+slot)%8]) for i in range(64)]
            for k in range(4):m[hex(cfg+k*4)]=bits(1+k*.125+(.125 if holdout else 0))
            for k in range(16):m[hex(cfg+16+k*4)]=bits(1 if k in (0,5,10,15) else 0)
            for k in range(3):
                m[hex(cfg+64+k*4)]=bits((k+1)*.125+(.125 if holdout else 0))
                m[hex(cfg+80+k*4)]=[bits(0 if i//8%3==0 else (k+1)*(.375 if holdout else .25)) for i in range(64)]
            m[hex(cfg+160)]=bits(1.125 if holdout else 1)
            for word in [0x94,0x98,0x9c]:
                m[hex(cfg+word)]=[(angles[(i//4+word+slot+int(holdout))%8]&65535)|((angles[(i//8+word+slot+2)%8]&65535)<<16) for i in range(64)]
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_contact_frame_{label}_v2_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_contact_frame_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_contact_frame_{label}_v2.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
