"""Exercise round winner, draw, tie-break and rematch branches with typed inputs."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c098c62'


def main():
    name='coverage_65_scene_round_decision_dev_v1';base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    fields=copy.deepcopy(json.loads((inputs/'coverage_65_batch_screen_dev_v2_memory.json').read_text())[ENTRY])
    # Scene +8 flags select clock comparison, sudden-death and draw resolution.
    fields['0xc29bccc']={'values':[0,0x400,0x80000000,0x80000400,0x20000,0x20004,
                                  0x08000000,0x88000000],'stride':32}
    fields['0xc29bd00']=[1,2,3,4]*64 # winning round threshold (+60)
    fields['0xc29bcdc']=[((1+(i//8)%3)<<8)|(((i//2)%4)<<16)|(((i//4)%4)<<24)
                        for i in range(256)] # match mode +25 and counters +26/+27
    fields['0xc29bcec']=[((1+(i//16)%3)<<8)|(((i//32)%3)<<16) for i in range(256)] # +41/+42 modes
    fields['0xc1fefe4']=[3|(0x04000000 if i%4&1 else 0) for i in range(256)]
    fields['0xc20138c']=[3|(0x04000000 if i%4&2 else 0) for i in range(256)]
    fields['0xc1ff028']=[v<<16 for v in [0,50,100,200]*64] # actor +70 timer
    fields['0xc2013d0']=[v<<16 for v in [200,100,100,50]*64]
    fields['0xc29bd54']=[0,0x10000,0x20000,0x30000]*64 # previous winner +0x92
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
