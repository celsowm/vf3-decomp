"""Finite six-joint extents for the original arena-bound correction leaf."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0cb51e'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        actor=0x0c410000;points=0x0c420000
        regs={ENTRY:{'r4':actor}}
        memory={ENTRY:{hex(actor):0,hex(actor+0x138c):points}}
        palette=[-40,-28.5,-27.5,-1,.25,27.5,28.5,40] if holdout else [-36,-28,-27,0,1,27,28,36]
        # The immutable joint selector bytes are 8,28,48,52,76,104; the
        # original signed division helper receives divisor 4.
        for k,joint in enumerate([2,7,12,13,19,26]):
            memory[ENTRY][hex(actor+0x12ac+joint*4)]=[bits((.75 if holdout else .5)+(i//16)*.25) for i in range(64)]
            memory[ENTRY][hex(points+joint*12)]=[bits(palette[(i+k)%8]) for i in range(64)]
            memory[ENTRY][hex(points+joint*12+4)]=0
            memory[ENTRY][hex(points+joint*12+8)]=[bits(palette[((i//8)+k*3)%8]) for i in range(64)]
        name=f'coverage_65_ring_bound_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_ring_bound_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
