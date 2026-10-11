"""History-ring classification, wraparound, and scan-limit boundaries."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c0a86ac'
def prepare():
    for held,label in [(False,'dev'),(True,'accept')]:
        previous=json.loads((ROOT/f'tools/oracle/percentage_inputs/coverage_65_replay_history_{label}_v1_memory.json').read_text())['0x8c0a87fc']
        memory={ENTRY:{a:v for a,v in previous.items() if 0x0c22f864<=int(a,16)<0x0c239864}}
        registers={ENTRY:{'r4':0,'r5':{'values':[0,1,32,40,159,160,319],'stride':1},
            'r6':[i%2 for i in range(64)],'r7':0}}
        for kind,data in [('memory',memory),('registers',registers)]:
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_history_scan_{label}_v1_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_history_scan_watch_v1.txt',
            ROOT/f'extract/analysis/coverage_65_history_scan_{label}_v1.patch',0x8c0432e2,64,
            relocation=0x100000 if held else 0,fpscr=0x240001 if held else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=held,
            memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
