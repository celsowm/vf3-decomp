"""Screen six remaining scene owners in initialized original fight states."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]
SOURCES={
    'coverage_65_batch_expand_dev_v1':{'0x8c0996f4':'0x8c09970a'},
    'coverage_65_batch_expand_dev_v2':{'0x8c097aa4':'0x8c097abc','0x8c096342':'0x8c09635a'},
    'coverage_65_batch_screen_dev_v2':{'0x8c098c62':'0x8c098c70','0x8c099d62':'0x8c099d74','0x8c08acc0':'0x8c08acd8'}}


def main():
    name='coverage_65_scene_remaining_screen_v1';base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    owners={};memory={};registers={}
    for prior,entries in SOURCES.items():
        mem=json.loads((inputs/f'{prior}_memory.json').read_text())
        regs=json.loads((inputs/f'{prior}_registers.json').read_text())
        for entry,owner in entries.items():
            fields=copy.deepcopy(mem[entry])
            fields.update({'0xc1feff4':0x3f800000,'0xc1feffc':0x3f000000,
                '0xc20139c':0x3f000000,'0xc2013a4':0x3f800000})
            owners[entry]=owner;memory[entry]=fields;registers[entry]=regs[entry]
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',
           inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths)
    paths[0].write_text(''.join('pc '+entry+'\n' for entry in owners))
    for path,data in zip(paths[1:4],(owners,memory,registers)):
        path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,128,fpscr=0x40001,bounded_arguments=True,
        preserve_fields=True,register_overrides=registers,memory_overrides=memory)


if __name__=='__main__':main()
