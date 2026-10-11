"""Finite homogeneous point projection under controlled original XF matrices."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c03d9b0'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        base=0x0c410000
        regs={ENTRY:{'r4':base,'r5':base+0x1000}}
        memory={ENTRY:{}}
        for k in range(16):regs[ENTRY][f'xf{k}']=bits(1 if k in (0,5,10,15) else 0)
        regs[ENTRY]['xf15']=[bits((1.25 if holdout else 1)+(i//16)*.25) for i in range(64)]
        for k in range(3):memory[ENTRY][hex(base+k*4)]=[bits((i%16-8)*(.375 if holdout else .25)+k*.5) for i in range(64)]
        for addr,v in [(0x0c0ea534,320),(0x0c0ea538,240),(0x0c0ea540,16),(0x0c0ea53c,24)]:
            memory[ENTRY][hex(addr)]=bits(v+8 if holdout else v)
        name=f'coverage_65_project_point_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_project_point_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
