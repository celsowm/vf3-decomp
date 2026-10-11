"""Typed replay-record probes reuse the proven observed motion fixture fields."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a9036'
def prepare(version='v3'):
    watch=ROOT/'tools/oracle/coverage_65_replay_record_watch_v1.txt'
    watch.write_text('pc '+ENTRY+'\n')
    for held,label in [(False,'dev'),(True,'accept')]:
        source='coverage_65_motion_frame_observed_accept_v1_memory.json' if held else 'coverage_65_motion_frame_observed_dev_v2_memory.json'
        fields=json.loads((ROOT/'tools/oracle/percentage_inputs'/source).read_text())['0x8c0a94d0']
        fields.update({
            '0xc19e218':0xc450000,
            '0xc450000':0,
            '0xc450004':0,
            '0xc29bccc':{'values':[0,6,0x800,0x806],'stride':4},
            '0xc29c0a4':{'values':[0,0x10000,0x60000],'stride':16},
            '0xc1ff044':{'values':[0x800 if (i//3)%5==0 else 0x100 for i in range(64)]},
        })
        memory={ENTRY:fields}
        registers={ENTRY:{'r4':0xc404000,'r5':0xc1fefe4,'r6':0xc404000}}
        for suffix,data in [('memory',memory),('registers',registers)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_replay_record_{label}_{version}_{suffix}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(watch,ROOT/f'extract/analysis/coverage_65_replay_record_{label}_{version}.patch',0x8c0432e2,64,
            relocation=0x100000 if held else 0,fpscr=0x240001 if held else 0x40001,
            preserve_fields=True,bounded_arguments=True,holdout_inputs=held,
            memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
