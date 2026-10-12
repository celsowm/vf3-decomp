"""Screen the complete seven-register prefix of the 512-byte scene reset."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]


def main():
    name='coverage_65_scene_retire_dev_v1';entry='0x8c096afc'
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    prior=json.loads((inputs/'coverage_65_replay_transition_helpers_dev_v2_memory.json').read_text())
    fields=copy.deepcopy(prior['0x8c099560'])
    fields['0xc29bcc0']=0
    fields['0xc29bccc']={'values':[0,4,0x40000000],'stride':32}
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',
           ROOT/f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths),'refuse to replace original screen inputs'
    paths[0].write_text('pc '+entry+'\n')
    paths[1].write_text(json.dumps({entry:'0x8c096b0a'},indent=2)+'\n')
    paths[2].write_text(json.dumps({entry:fields},indent=2)+'\n')
    generate(paths[0],paths[3],0x8c0432e2,128,fpscr=0x40001,bounded_arguments=True,
             preserve_fields=True,memory_overrides={entry:fields})
    print('Original scene-reset prefix screen prepared; no C credit')


if __name__=='__main__':main()
