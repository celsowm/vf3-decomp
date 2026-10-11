"""Typed packed basis and finite direction inputs for the original leaf."""
import json
import struct
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c05865c'
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        base=0x0c410000
        memory={ENTRY:{hex(base):list(range(64))}}
        # Three packed float-high-word basis vectors, preceded by a header.
        words=[0x00003f80,0,0x00003f80,0,0x00003f80,0]
        for k,w in enumerate(words):memory[ENTRY][hex(base+4+k*4)]=w
        regs={ENTRY:{'r5':base}}
        for k in range(16):regs[ENTRY][f'xf{k}']=bits(1.0 if k in (0,5,10,15) else 0)
        regs[ENTRY]['xf12']=[bits((-1 if i&1 else 1)*(.375 if holdout else .25)*(1+(i//16)/8)) for i in range(64)]
        regs[ENTRY]['xf13']=[bits((-1 if i&4 else 1)*((.3 if holdout else .25)+(i%4)*.125)) for i in range(64)]
        regs[ENTRY]['xf14']=[bits((-1 if i&2 else 1)*(.1875 if i&8 else .625)) for i in range(64)]
        for k in range(16):regs[ENTRY][f'fr{k}']=bits((k+1)/32)
        name=f'coverage_65_packed_direction_{label}_v3'
        for kind,data in [('memory',memory),('registers',regs)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_packed_direction_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
                 relocation=0x100000 if holdout else 0,fpscr=0x340001 if holdout else 0x140001,
                 bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
                 memory_overrides=memory,register_overrides=regs)
if __name__=='__main__':prepare()
