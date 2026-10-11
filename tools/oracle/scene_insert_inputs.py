"""Ordered eighteen-entry frame/key tables and boundary insertion positions."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c09fefe'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actor=0x0c410000;step=13 if holdout else 10;start=1234 if holdout else 800
        regs={ENTRY:{}};m={};memory={ENTRY:m}
        for k in range(18):
            m[hex(0x0c11e418+k*4)]=[0x12340000+k+i for i in range(64)]
            m[hex(0x0c11e418+72+k*4)]=start+k*step
            m[hex(0x0c11e418+144+k*4)]=k*7+int(holdout)
        for k in range(5):m[hex(0x0c11e418+216+k*4)]=0x03020100+k*0x04040404
        m[hex(0x0c29bcc4+48)]=[start+(i%20)*step+(step//2 if i//20==1 else 0) for i in range(64)]
        m[hex(0x0c29bcc4+132)]=[(i%20)*7+[-1,0,1][i//20%3]+int(holdout) for i in range(64)]
        # The candidate key uses unsigned RAM storage and signed comparisons.
        m[hex(0x0c29bcc4+132)]=[v&0xffffffff for v in m[hex(0x0c29bcc4+132)]]
        m[hex(0x0c29bcc4+40)]=[0x100 if i%2 else 0 for i in range(64)]
        for off in [16,20]:m[hex(0x0c29bb84+off)]=actor
        m[hex(actor+96)]=[0x5500+(i%18)*256+int(holdout) for i in range(64)]
        name=f'coverage_65_scene_insert_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_scene_insert_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
