"""Reach character-six comparisons in initialized fight-state development."""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]


def main():
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    entry='0x8c0a92c8';name='coverage_65_replay_action_special_dev_v2'
    fields=json.loads((inputs/'coverage_65_replay_transition_helpers_dev_v2_memory.json').read_text())[entry]
    fields.update({'0xc29bcdc':0,'0xc1ff044':6<<8,'0xc2013ec':0,
        '0xc1fffdc':0,'0xc1ff028':0,'0xc202384':0,'0xc2013d0':0})
    registers={entry:dict(r4=0xc1fefe4,r5=0xc20138c)}
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',
        inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text('pc '+entry+'\n')
    for path,data in zip(paths[1:4],({entry:'0x8c0a92da'},{entry:fields},registers)):
        path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,128,fpscr=0x40001,
        bounded_arguments=True,preserve_fields=True,
        register_overrides=registers,memory_overrides={entry:fields})


if __name__=='__main__':main()
