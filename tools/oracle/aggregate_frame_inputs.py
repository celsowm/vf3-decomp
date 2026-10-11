"""Counted vector pairs plus zero, tiny and ordinary angular-frame inputs."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from packed_direction_inputs import bits
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a6dba'

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        config=0x0c410000;rows=0x0c420000
        regs={ENTRY:{'r4':config,'r5':rows}}
        memory={ENTRY:{hex(config+k*4):0 for k in range(44)}}
        for k in range(4):memory[ENTRY][hex(config+k*4)]=bits(1+k*.125+(.125 if holdout else 0))
        for k in range(16):memory[ENTRY][hex(config+16+k*4)]=bits(1 if k in (0,5,10,15) else 0)
        memory[ENTRY][hex(rows)]=[i%4 for i in range(64)]
        for k in range(3):
            # Count-zero configurations isolate all three norm branches;
            # the other counts exercise the already-qualified vector sum.
            memory[ENTRY][hex(config+80+k*4)]=[bits(0 if i//4%3==0 else ((k+1)*(2e-6 if holdout else 1e-6) if i//4%3==1 else (k+1)*(.375 if holdout else .25))) for i in range(64)]
            for j in range(3):
                for c in range(6):memory[ENTRY][hex(rows+4+j*24+c*4)]=[bits(((i+j*3+c*2)%9-4)*(.375 if holdout else .25)) for i in range(64)]
        memory[ENTRY][hex(config+160)]=[bits(1+(i//16)*.25+(.125 if holdout else 0)) for i in range(64)]
        angles=[0,4096,-4096,16384,-16384,30000,-30000,32767]
        for word in range(3):
            values=[]
            for i in range(64):
                halves=[]
                for half in range(2):
                    field=word*2+half
                    angle=angles[(i//4+field+int(holdout))%8] if field<3 else ((i+field)%7-3)*(1536 if holdout else 1024)
                    halves.append(angle&65535)
                values.append(halves[0]|(halves[1]<<16))
            memory[ENTRY][hex(config+148+word*4)]=values
        name=f'coverage_65_aggregate_frame_{label}_v2'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_aggregate_frame_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
