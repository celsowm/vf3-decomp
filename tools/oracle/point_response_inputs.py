"""Counted finite points and two reference triples for the adjacent caller."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a6482'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        config=0x0c410000;vectors=0x0c420000;points=0x0c430000
        regs={ENTRY:{'r4':config,'r5':vectors,'r6':points}}
        memory={ENTRY:{hex(config+k*4):0 for k in range(32)}}
        for k in range(16):memory[ENTRY][hex(config+16+k*4)]=bits(1 if k in (0,5,10,15) else 0)
        palette=[-4,-1.5,-.125,0,.5,1.25,3,5] if holdout else [-3,-1,-.25,0,.25,1,2,4]
        memory[ENTRY][hex(points)]=[i%4 for i in range(64)]
        for k in range(3):
            memory[ENTRY][hex(config+64+k*4)]=bits(k*.25+(.125 if holdout else 0))
            memory[ENTRY][hex(vectors+k*4)]=[bits((1 if i//8%2==0 else -1)*(.75 if holdout else 1) if k==0 else 0) for i in range(64)]
            memory[ENTRY][hex(vectors+12+k*4)]=bits(.125 if holdout and k==0 else 0)
            memory[ENTRY][hex(vectors+24+k*4)]=bits((1.5 if holdout else 1) if k==0 else 0)
            for j in range(3):memory[ENTRY][hex(points+4+j*12+k*4)]=[bits(palette[(i//4+j*2+k)%8]) for i in range(64)]
        name=f'coverage_65_point_response_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_point_response_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
