"""Bounded closed polygons and finite segments, with explicit stack arguments."""
import json
import random
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c06e056'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        base=0x0c410000;points=0x0c420000;out=0x0c430000;stack=0x0c440100
        memory={ENTRY:{hex(base+0x3c4):points,hex(points):4}}
        extent=3.5 if holdout else 3
        vertices=[(-extent,-extent),(extent,-extent),(extent,extent),(-extent,extent),(-extent,-extent)]
        for k,(x,y) in enumerate(vertices):
            memory[ENTRY][hex(points+4+k*8)]=bits(x)
            memory[ENTRY][hex(points+8+k*8)]=bits(y)
        for k in range(3):memory[ENTRY][hex(stack+4+k*4)]=out+4+k*4
        rng=random.Random(817 if holdout else 613)
        palette=[-6,-3.5,-1.5,0,.5,2.5,4,6] if holdout else [-5,-3,-1,0,1,2,3,5]
        lines=[tuple(rng.choice(palette) for k in range(4)) for i in range(64)]
        # Include a segment through the polygon, outside it, and edge-coincident.
        lines[:4]=[(-6,0,6,0),(-6,6,6,6),(-extent,-6,-extent,6),(0,-6,0,6)]
        regs={ENTRY:{'r4':base,'r5':0 if holdout else 1,'r6':0x2345 if holdout else 0x1234,'r7':out}}
        for k in range(4):regs[ENTRY][f'fr{4+k}']=[bits(p[k]) for p in lines]
        name=f'coverage_65_polygon_hit_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        patch=ROOT/f'extract/analysis/{name}.patch'
        generate(ROOT/'tools/oracle/coverage_65_polygon_hit_watch_v1.txt',patch,0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
        # The prototype has three caller-stack output pointers. Give the
        # original interpreter captured writable RAM for that caller frame.
        text=patch.read_text().splitlines();result=[]
        for line in text:
            result.append(line)
            if line.startswith('target '):result.append(f'reg 0x8c0432e2 r15 {stack+(0x100000 if holdout else 0):#010x}')
        patch.write_text('\n'.join(result)+'\n')
if __name__=='__main__':prepare()
