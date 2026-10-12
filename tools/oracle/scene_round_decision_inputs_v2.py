"""Target metadata-zero, deciding-draw, perfect-win and nine-round paths."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c098c62'


def main():
    name='coverage_65_scene_round_decision_dev_v2';base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    fields=copy.deepcopy(json.loads((inputs/'coverage_65_scene_round_decision_dev_v1_memory.json').read_text())[ENTRY])
    fields['0xc11e514']=[0,0x10000]*128 # mutable option byte at +18 of metadata descriptor
    fields['0xc29bccc']=[0x20000 if i<64 else 0x88000000 if i<128 else 0 for i in range(256)]
    fields['0xc29bd00']=2
    fields['0xc29bcdc']=(1<<8)|(2<<16)|(2<<24)
    fields['0xc29bcec']=[(3<<8) if i<192 else ((1+i%2)<<8)|(9<<24) for i in range(256)]
    fields['0xc1fd758']=[0,1]*128 # loaded tie-break decision flag, read by the original code
    fields['0xc1fefe4']=3
    fields['0xc20138c']=3|0x04000000
    fields['0xc1ff028']=100<<16
    fields['0xc2013d0']=100<<16
    fields['0xc1fffdc']=100<<16
    fields['0xc202384']=100<<16
    registers={ENTRY:dict(r4=0xc400000,r5=0xc404000)}
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',
        inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text('pc '+ENTRY+'\n')
    for path,value in zip(paths[1:4],({ENTRY:'0x8c098c70'},{ENTRY:fields},registers)):
        path.write_text(json.dumps(value,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,bounded_arguments=True,
        preserve_fields=True,register_overrides=registers,memory_overrides={ENTRY:fields})


if __name__=='__main__':main()
