"""Original replay callback pilot with paired ring records and loaded actors."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a8e18'
def prepare():
    watch=ROOT/'tools/oracle/coverage_65_replay_callback_watch_v1.txt'
    watch.write_text('pc '+ENTRY+'\n')
    memory={
        '0xc29ba30':1,
        '0xc29bcc0':{'values':[0,1,0x80000,0x80001],'stride':1},
        '0xc29bccc':{'values':[0,0x800],'stride':8},
        '0xc29c0a4':{'values':[0,0x10000],'stride':16},
        '0xc400010':{'values':[0,1,318,319],'stride':4},
        '0xc400014':{'values':[0,1,2,319],'stride':8},
        '0xc29bb94':0xc1fefe4,'0xc29bb98':0xc20138c,
        '0xc29bb90':0xc470000,'0xc29bba0':0xc470100,'0xc29bbd8':0xc46e000,
        '0xc470000':3,'0xc470100':3,'0xc46e000':3,
        '0xc19e218':0xc450000,'0xc450000':0,'0xc450004':0,
    }
    for slot in [0,1,318,319]:
        for half in [0,64]:
            address=0xc22f864+slot*128+half
            for offset in range(0,64,4):memory[hex(address+offset)]=0
            memory[hex(address)]=3
            memory[hex(address+36)]={'values':[0,1,2],'stride':8}
            memory[hex(address+4)]={'values':[0,0x3f800000,0xbf800000],'stride':3}
    typed={ENTRY:memory};regs={ENTRY:{'r4':0xc400000}}
    for suffix,data in [('memory',typed),('registers',regs)]:
        (ROOT/f'tools/oracle/percentage_inputs/coverage_65_replay_callback_dev_v1_{suffix}.json').write_text(json.dumps(data,indent=2)+'\n')
    generate(watch,ROOT/'extract/analysis/coverage_65_replay_callback_dev_v1.patch',0x8c0432e2,64,
        fpscr=0x40001,bounded_arguments=True,preserve_fields=True,
        memory_overrides=typed,register_overrides=regs)
if __name__=='__main__':prepare()
