"""Typed phase, player flags, input shifts and timeout boundaries for scene nine."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c09a0a8'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        a,b,scene,mode=0x0c410000,0x0c420000,0x0c29bcc4,0x0c29b864
        m={};memory={ENTRY:m};regs={ENTRY:{}}
        def values(addr,f):m[hex(addr)]=[f(i)&0xffffffff for i in range(64)]
        # Exercise command enqueue behavior in an owned RAM ring. This grants
        # no hardware/AICA credit and does not alter the helper instructions.
        values(0x0c19e218,lambda i:0x0c450000)
        for off in range(0,64,4):m[hex(0x0c450000+off)]=0
        values(0x0c29bbac,lambda i:a);values(0x0c29bbb0,lambda i:b)
        values(a,lambda i:i+32+(64 if holdout else 0));values(b,lambda i:i+96+(64 if holdout else 0))
        values(scene+40,lambda i:(1 if i==14 else i%4)<<8)
        values(scene+8,lambda i:0x40000008|(4 if i==30 else 0) if i in [14,30] else ([0,0x10000000,0x20000000,0x30000000][i//4%4])|(4 if i//16%2 else 0)|(8 if i//8%2 else 0)|0x40000000)
        values(scene+28,lambda i:(i%2)<<8)
        values(scene+0x90,lambda i:((i//2%2)<<16)|((10+i+(9 if holdout else 0))<<24))
        values(scene+0x390,lambda i:(0 if i in [14,30] else 1 if i==10 else i//4%2)<<24)
        values(mode+12,lambda i:[-8,0,1,16,300,340,512,600][i//8%8])
        values(mode+0x13c,lambda i:0x07000700 if i==3 or i//4%2 else 0)
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_round_transition_{label}_v4_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_round_transition_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_round_transition_{label}_v4.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
