"""Finite counted vector pairs and affine configuration for original execution."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a6ff8'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        config=0x0c410000;rows=0x0c420000;out=0x0c430000;stack=0x0c440100
        regs={ENTRY:{'r4':config,'r5':rows,'r6':out,'r7':out+4}}
        memory={ENTRY:{hex(rows):[i%4 for i in range(64)]}}
        for k in range(4):memory[ENTRY][hex(config+k*4)]=bits((1.25 if holdout else 1)+k*.125)
        for k in range(16):memory[ENTRY][hex(config+16+k*4)]=bits(1 if k in (0,5,10,15) else 0)
        for k in range(3):memory[ENTRY][hex(config+104+k*4)]=[bits((i//4-8)*.125+k+(.25 if holdout else 0)) for i in range(64)]
        for j in range(3):
            for k in range(6):memory[ENTRY][hex(rows+4+j*24+k*4)]=[bits(((i+k*3+j*5)%13-6)*(.375 if holdout else .25)) for i in range(64)]
        for k in range(4):memory[ENTRY][hex(stack+k*4)]=out+8+k*4
        name=f'coverage_65_vector_sum_{label}_v1'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        patch=ROOT/f'extract/analysis/{name}.patch'
        generate(ROOT/'tools/oracle/coverage_65_vector_sum_watch_v1.txt',patch,0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
        result=[]
        for line in patch.read_text().splitlines():
            result.append(line)
            if line.startswith('target '):result.append(f'reg 0x8c0432e2 r15 {stack+(0x100000 if holdout else 0):#010x}')
        patch.write_text('\n'.join(result)+'\n')
if __name__=='__main__':prepare()
