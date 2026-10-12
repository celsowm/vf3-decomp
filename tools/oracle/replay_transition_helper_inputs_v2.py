"""Screen replay helpers with initialized fight states and finite positions."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]


def main():
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    prior='coverage_65_replay_transition_helpers_dev_v1'
    name='coverage_65_replay_transition_helpers_dev_v2'
    owners=json.loads((base/f'{prior}_owners.json').read_text())
    memory=copy.deepcopy(json.loads((inputs/f'{prior}_memory.json').read_text()))
    registers=json.loads((inputs/f'{prior}_registers.json').read_text())
    for fields in memory.values():
        fields.update({'0xc1feff4':0x3f800000,'0xc1feffc':0x3f000000,
                       '0xc20139c':0x3f000000,'0xc2013a4':0x3f800000})
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',
           inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text(''.join('pc '+entry+'\n' for entry in owners))
    for path,data in zip(paths[1:4],(owners,memory,registers)):
        path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,128,fpscr=0x40001,
             bounded_arguments=True,preserve_fields=True,
             register_overrides=registers,memory_overrides=memory)


if __name__=='__main__':main()
