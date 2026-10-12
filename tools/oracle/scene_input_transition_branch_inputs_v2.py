"""Exercise original countdown, input mixing and replay completion branches."""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def main():
    base = ROOT/'tools/oracle'
    inputs = base/'percentage_inputs'
    entry = '0x8c0993e0'
    prior = 'coverage_65_batch_screen_dev_v2'
    name = 'coverage_65_scene_input_transition_branches_dev_v2'
    fields = json.loads((inputs/f'{prior}_memory.json').read_text())[entry]
    regs = json.loads((inputs/f'{prior}_registers.json').read_text())[entry]
    fields.update({
        '0xc29bcc0': [1 if n%32==0 else 0 for n in range(256)],
        '0xc29c0a4': [(n%4)<<16 for n in range(256)],
        '0xc29bcec': [2<<8 for n in range(256)],
        '0xc29be84': [((n//8)%3)<<16|((n//4)%2)<<8|((n//16)%2)<<24 for n in range(256)],
        '0xc29b870': [16+n%7 for n in range(256)],
        '0xc29b99c': {'values':[0,0x400,0x40000], 'stride':32},
        '0xc29b9a0': {'values':[0,1,16,32], 'stride':4},
        '0xc11e514': {'values':[0,1<<24], 'stride':16},
        '0xc29bccc': {'values':[0,4,0x40000000], 'stride':64},
    })
    paths = [base/f'{name}_watch.txt',base/f'{name}_owners.json',
             inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',
             ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text('pc '+entry+'\n')
    paths[1].write_text(json.dumps({entry:'0x8c0993e8'},indent=2)+'\n')
    paths[2].write_text(json.dumps({entry:fields},indent=2)+'\n')
    paths[3].write_text(json.dumps({entry:regs},indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,
             bounded_arguments=True,preserve_fields=True,
             register_overrides={entry:regs},memory_overrides={entry:fields})


if __name__=='__main__':
    main()
