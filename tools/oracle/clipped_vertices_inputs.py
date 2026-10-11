"""Finite reciprocal-depth intersections through the original render leaf."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c058a5c'
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        old=f'coverage_65_packed_direction_{label}_v3'
        regs=json.loads((ROOT/f'tools/oracle/percentage_inputs/{old}_registers.json').read_text())['0x8c05865c']
        memory=json.loads((ROOT/f'tools/oracle/percentage_inputs/{old}_memory.json').read_text())['0x8c05865c']
        base=0x0c410000
        memory={hex(int(k,16)+48):v for k,v in memory.items()}
        # Signed packed texture coordinates for the three vertices.
        for j in [0,24,48]:memory[hex(base+j)]=[((i+j+1)&0xffff)|(((0x10000-i-j-3)&0xffff)<<16) for i in range(64)]
        for j,addr in enumerate([0x0c420000,0x0c421000,0x0c422000]):
            memory[hex(addr)]=[bits((i%8-3)*.25+j) for i in range(64)]
            memory[hex(addr+4)]=[bits((i//8-4)*.25-j) for i in range(64)]
            depth=(1.25 if holdout else 1) if j==0 else (2.5 if holdout else 2) if j==1 else (1.75 if holdout else 1.5)
            memory[hex(addr+8)]=[bits(depth*(-1 if j!=1 and i&(1<<j) else 1)) for i in range(64)]
            memory[hex(addr+12)]=bits(.125)
        memory[hex(0x0c16b880+28)]=bits(.3 if holdout else .25)
        memory[hex(0x0c16b880+96)]=0xe0000000
        regs.update(r14=base+48,r6=0x0c420000,r8=0x0c421000,r9=0x0c422000,r12=0x0c430000,r10=bits(1.75 if holdout else 1.5))
        regs.pop('r5',None)
        name=f'coverage_65_clipped_vertices_{label}_v1'
        for kind,data in [('memory',{ENTRY:memory}),('registers',{ENTRY:regs})]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_clipped_vertices_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x340001 if holdout else 0x140001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides={ENTRY:memory},register_overrides={ENTRY:regs})
if __name__=='__main__':prepare()
