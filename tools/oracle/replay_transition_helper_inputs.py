"""Screen five readable replay helpers against original task/actor states."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]


def main():
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    name='coverage_65_replay_transition_helpers_dev_v1'
    owners={'0x8c099540':'0x8c099544','0x8c099560':'0x8c099568',
            '0x8c0a91da':'0x8c0a91e6','0x8c0a92c8':'0x8c0a92da','0x8c0a9444':'0x8c0a9452'}
    prior=json.loads((inputs/'coverage_65_scene_input_transition_branches_dev_v1_memory.json').read_text())['0x8c0993e0']
    memory={};registers={}
    for entry in owners:
        fields=copy.deepcopy(prior)
        fields.update({
            '0xc29bcc0':0,'0xc29bccc':{'values':[0,0x800,0x40000000],'stride':32},
            '0xc29bcdc':{'values':[0,2],'stride':64},
            '0xc29be84':{'values':[0,1<<8],'stride':64},
            '0xc29be88':{'values':[0xc1fefe4,0xc20138c],'stride':32},
            '0xc29be8c':{'values':[0xc20138c,0xc1fefe4],'stride':32},
            '0xc29c01c':{'values':[0,1<<16,2<<16],'stride':16},
            '0xc29b99c':{'values':[0,0x100,0x200,0x400,0x500,0x600,0x800,0x1d00],'stride':1},
            '0xc469014':{'values':[0,1,2,8,16],'stride':16},
            '0xc201258':{'values':[0,64<<24],'stride':16},
            '0xc203600':{'values':[0,64<<24],'stride':8},
            '0xc1ff044':{'values':[0,1<<8,3<<8,6<<8],'stride':8},
            '0xc2013ec':{'values':[0,1<<8,3<<8,6<<8],'stride':4},
            '0xc1fefe4':{'values':[0,0x800,0x8000],'stride':32},
            '0xc20138c':{'values':[0,0x800,0x8000],'stride':16},
        })
        memory[entry]=fields
        registers[entry]={'r4':{'values':[0xc1fefe4,0xc20138c],'stride':32},
                          'r5':{'values':[0xc20138c,0xc1fefe4],'stride':32}}
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',
           inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',
           ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text(''.join('pc '+entry+'\n' for entry in owners))
    for path,data in zip(paths[1:4],(owners,memory,registers)):
        path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,
             bounded_arguments=True,preserve_fields=True,
             register_overrides=registers,memory_overrides=memory)


if __name__=='__main__':main()
