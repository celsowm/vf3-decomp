"""Typed original fight-history ring boundaries and owned actor arguments."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a87fc'
def prepare():
    for held,label in [(False,'dev'),(True,'accept')]:
        shift=0x100000 if held else 0
        m={};registers={ENTRY:{'r4':0x0c410000+shift,'r5':0x0c420000+shift}}
        def values(a,fn):m[hex(a)]=[fn(i)&0xffffffff for i in range(64)]
        values(0x0c29bbd4,lambda i:0x0c430000+shift)
        values(0x0c430010+shift,lambda i:[0,1,2,319,320][i%5])
        values(0x0c29bb94,lambda i:0x0c410000+shift)
        values(0x0c29be8c,lambda i:0x0c410000+shift if i%2 else 0x0c420000+shift)
        values(0x0c29bcec,lambda i:((1+i%3)<<24)|(i%2<<8))
        values(0x0c29c068,lambda i:[0,127,128,200,255][i%5])
        values(0x0c410060+shift,lambda i:20+i)
        values(0x0c420060+shift,lambda i:70+i+(1 if held else 0))
        for slot in range(320):
            values(0x0c22f864+slot*128+56,
                lambda i,k=slot:(0 if i%8==0 or (i%8 in [4,5] and k%4==0) else 1)<<24)
            values(0x0c22f864+slot*128+16,lambda i:0x21000 if i%8==2 else 0)
            values(0x0c22f864+slot*128+80,lambda i:0x08882000 if i%8 in [5,6] else 0)
        memory={ENTRY:m}
        for kind,data in [('memory',memory),('registers',registers)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_replay_history_{label}_v1_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_replay_history_watch_v1.txt',
            ROOT/f'extract/analysis/coverage_65_replay_history_{label}_v1.patch',0x8c0432e2,64,
            relocation=shift,fpscr=0x240001 if held else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=held,
            memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
