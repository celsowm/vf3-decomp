"""Controller/menu-state boundaries, including signed selectors with original ROM tables."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0c95f4'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        mode,scene=0x0c29b864,0x0c29bcc4
        m={};memory={ENTRY:m};regs={ENTRY:{}}
        def values(a,f):m[hex(a)]=[f(i)&0xffffffff for i in range(64)]
        def control(i):
            if i<16:return [0,0x80000104,0x40001008,0x2000][i%4]
            if i<40:return 0x40001008 if i%2 else 0x2000
            if i<48:return 0x40001008 if i==40 else 0x80004104
            return 0x10 if i==55 else [0x80004104,0x00008400,0x80000004,0][i%4]
        def selector(i):
            if i<16:return i//4
            if i<40:return (i-16)//4
            if i<48:return [-128,-2,-1,1,2,3,4,5][i-40]
            return [0,1,5,-1][i%4]
        def phase(i):return 0 if i<16 else 1 if i<56 else [2,3,4,5][i%4]
        values(mode+0x13c,control)
        values(mode+0x138,lambda i:0x40000008 if i in [49,50,54] else 0)
        values(mode+8,lambda i:((31+i%22)<<24))
        values(scene+0x204,lambda i:phase(i)|((selector(i)&255)<<16)|(i%3<<24))
        values(scene+0x240,lambda i:(127 if i==17 else [0,1,2,3][i%4])|(2<<8)|((i%5)<<16)|((i%3)<<24))
        values(scene+0x244,lambda i:(i%3)|((i%2)<<8))
        values(mode+12,lambda i:64+i+(16 if holdout else 0))
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_settings_menu_{label}_v3_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_settings_menu_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_settings_menu_{label}_v3.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
