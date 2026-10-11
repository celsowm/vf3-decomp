"""Owned round-score fixtures: phase gates, normalized damage and round bonuses."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a7be2'

def prepare():
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actor,other,scene=0x0c410000,0x0c420000,0x0c29bcc4
        regs={ENTRY:dict(r4=actor,r5=other,r6=[0x02000000 if i%2 else 0 for i in range(64)],r7=[i%8 for i in range(64)])}
        m={};memory={ENTRY:m}
        def values(a,f):m[hex(a)]=[f(i)&0xffffffff for i in range(64)]
        values(scene+0x90,lambda i:(1 if i%2 else 0)<<16)
        values(0x0c29bb94,lambda i:actor+(4 if i==0 else 0))
        values(0x0c29bb98,lambda i:actor+(4 if i==0 else 0))
        gates={1:0,2:0x01000008,3:0x108,4:0x00100008,5:0x00080008}
        values(scene+8,lambda i:gates.get(i,8|(0x40000000 if i>=48 else 0)|(16 if i%2 else 0)))
        values(0x0c29b864,lambda i:0 if i==6 else 0x03000000)
        values(0x0c29b868,lambda i:0 if i==8 else (0x00200000 if i>=32 else (0x00800000 if i%4 else 0x00400000)))
        values(scene+40,lambda i:(3 if i==7 else 0)<<8 | ((i%5+1)<<24))
        values(scene+24,lambda i:(i%3)|((2 if i%7==0 else 0)<<8))
        values(scene+28,lambda i:1 if i%3==0 else (2 if i%3==1 else 4))
        values(scene+0x1c4,lambda i:actor if i%5 else other)
        values(scene+20,lambda i:128+i*13+(19 if holdout else 0))
        values(scene+60,lambda i:(1 if i%3==0 else 2 if i%3==1 else 4) if i%2 else 9)
        values(scene+0x384,lambda i:(11+i+(7 if holdout else 0))|(i%4<<16))
        values(scene+0x380,lambda i:(23+i)<<16)
        values(scene+0x394,lambda i:i+1)
        values(actor+0xff8,lambda i:([12,180,220,27][i%4]+(1 if holdout else 0))<<16)
        values(actor+68,lambda i:([12,180,220,27][i%4]+(1 if holdout else 0) if i%3==0 else [8,22,35][i%3])<<16)
        values(other+0x2304,lambda i:(0 if i%6==0 else 3+i))
        values(other+0x201c,lambda i:(i%5+1)<<8)
        def identity(i):
            p=0x0c10e4ae+i%8*4-0x0c010000
            v=int.from_bytes(image[p:p+2],'little')
            return v if i%4 else (v+1)&65535
        values(actor+60,identity)
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_round_score_{label}_v2_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_round_score_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_round_score_{label}_v2.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
