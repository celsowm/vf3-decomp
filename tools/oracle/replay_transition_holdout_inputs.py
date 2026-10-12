"""Create fresh typed helper inputs after the complete qualified development."""
from datetime import datetime, timezone
import json
from pathlib import Path
from ram_clipping_batch_audit import digest, reference
from tenpp_probe_plan import generate, override_sequence, override_value

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def relocated(value):
    return value+0x100000 if 0xc400000<=value<0xc4a0000 else value


def main():
    qualified=CACHE/'replay_transition_qualified_development_freeze_v1.json'
    development=json.loads(qualified.read_text())
    assert development['qualified_development_only'] and development['full_regression']['passed']
    for row in development['references']:assert digest(row['path'])==row['sha256']
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs';files=[];groups=[]
    owner_map=json.loads((base/'coverage_65_replay_transition_helpers_dev_v2_owners.json').read_text())
    for n,prior in enumerate(('coverage_65_replay_transition_helpers_dev_v2','coverage_65_replay_action_special_dev_v2'),1):
        name=f'coverage_65_replay_transition_accept_v{n}'
        old=json.loads((inputs/f'{prior}_memory.json').read_text())
        old_registers=json.loads((inputs/f'{prior}_registers.json').read_text())
        memory={};registers={}
        for entry,fields in old.items():
            memory[entry]={}
            for address,values in fields.items():
                sequence=override_sequence(values,address)
                changed=[]
                for i in range(128):
                    value=override_value(sequence,(i+37)%128)
                    if int(address,16)==0xc29b870 and 0<value<0x7ffffff0:value+=17
                    changed.append(relocated(value))
                memory[entry][hex(relocated(int(address,16)))]=changed
            registers[entry]={reg:[override_value(override_sequence(values,reg),(i+37)%128)
                if reg.startswith(('fr','xf')) else relocated(override_value(override_sequence(values,reg),(i+37)%128))
                for i in range(128)] for reg,values in old_registers[entry].items()}
        owners={entry:owner_map[entry] for entry in old}
        paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',
               inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
        assert not any(path.exists() for path in paths),'refuse to replace held inputs'
        paths[0].write_text(''.join('pc '+entry+'\n' for entry in owners))
        for path,data in zip(paths[1:4],(owners,memory,registers)):path.write_text(json.dumps(data,indent=2)+'\n')
        generate(paths[0],paths[4],0x8c0432e2,128,relocation=0x100000,fpscr=0x40001,
            bounded_arguments=True,preserve_fields=True,memory_overrides=memory,register_overrides=registers)
        files+=paths;groups.append(dict(name=name,owners=owners))
    output=base/'replay_transition_accept_input_manifest_v1.json'
    assert not output.exists()
    output.write_text(json.dumps(dict(coverage_credit=False,created_at_utc=datetime.now(timezone.utc).isoformat(),
        development_freeze=reference(qualified),groups=groups,files=[reference(path) for path in files],
        original_states=[reference(ROOT/f'tools/emu/flycast-build/data/vf3_{i}.state') for i in (45,46)],
        hypothesis='Changed typed counters, permuted branch profiles and relocated writable buffers, in disjoint original states; all callback results and original instructions remain computed by the original game.'),indent=2)+'\n')
    print('Fresh helper acceptance inputs created after the qualified freeze')


if __name__=='__main__':main()
