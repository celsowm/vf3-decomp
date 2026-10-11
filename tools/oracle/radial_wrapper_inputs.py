"""Two-actor radial wrapper with both enabled and scene-mask bypass paths."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0cb65a'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        source=json.loads((ROOT/f'tools/oracle/percentage_inputs/coverage_65_radial_bound_{label}_v1_memory.json').read_text())['0x8c0cb67a']
        memory={}
        for displacement in [0,0x40000]:
            for address,values in source.items():
                if int(address,16)==0x0c41138c:values+=displacement
                memory[hex(int(address,16)+displacement)]=values
        memory['0xc29bcc0']=[0 if i%4==0 else [1,0x80000,0x80001][(i+int(holdout))%3] for i in range(64)]
        regs={ENTRY:{'r4':0x0c410000,'r5':0x0c450000}};mem={ENTRY:memory}
        name=f'coverage_65_radial_wrapper_{label}_v1'
        for kind,data in [('memory',mem),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_radial_wrapper_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=mem,register_overrides=regs)
if __name__=='__main__':prepare()
