"""Finite configuration and two triples for the larger vector-response pilot."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a67b8'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        config=0x0c410000;position=0x0c420000;direction=0x0c430000;out=0x0c440000
        regs={ENTRY:{'r4':config,'r5':position,'r6':direction,'r7':out}}
        memory={ENTRY:{hex(config+k*4):0 for k in range(32)}}
        for k in range(4):memory[ENTRY][hex(config+k*4)]=bits(1+k*.125+(.125 if holdout else 0))
        for k in range(16):memory[ENTRY][hex(config+16+k*4)]=bits(1 if k in (0,5,10,15) else 0)
        palette=[-4,-2,-.5,0,.125,1,2.5,5] if holdout else [-3,-1,-.25,0,.25,1,2,4]
        for k in range(3):
            memory[ENTRY][hex(position+k*4)]=[bits(palette[(i+k*3)%8]) for i in range(64)]
            memory[ENTRY][hex(direction+k*4)]=[bits(palette[(i//8+k*2)%8]) for i in range(64)]
            memory[ENTRY][hex(config+80+k*4)]=bits(1 if k==1 else 0)
            memory[ENTRY][hex(config+92+k*4)]=bits((k-1)*(.25 if holdout else .125))
            memory[ENTRY][hex(config+104+k*4)]=bits(0)
        memory[ENTRY][hex(config+116)]=[bits(.25+(i//16)*.25+(.125 if holdout else 0)) for i in range(64)]
        memory[ENTRY][hex(config+120)]=[bits(.125+(i//8)*.125+(.0625 if holdout else 0)) for i in range(64)]
        name=f'coverage_65_vector_response_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_vector_response_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
