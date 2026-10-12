"""Create disjoint scene acceptance inputs only after qualified development."""
import json
from pathlib import Path
from datetime import datetime, timezone
from ram_clipping_batch_audit import digest, reference
from tenpp_probe_plan import generate, override_sequence, override_value

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
GROUPS=[('0x8c098c62','0x8c098c70','coverage_65_scene_round_decision_dev_v1'),
        ('0x8c098c62','0x8c098c70','coverage_65_scene_round_decision_dev_v2'),
        ('0x8c0993e0','0x8c0993e8','coverage_65_scene_input_transition_branches_dev_v1'),
        ('0x8c0993e0','0x8c0993e8','coverage_65_scene_input_transition_branches_dev_v2')]


def relocated(value):
    return value+0x180000 if 0x0c400000<=value<0x0c4a0000 else value


def changed(entry,address,value):
    if entry=='0x8c098c62':
        if address==0x0c29bd00:return value+1 if value>0 else value
        if address==0x0c29bcdc:
            return (value&0xffff)|((((value>>16)&255)+1)&255)<<16|((((value>>24)&255)+1)&255)<<24
        if address in (0x0c1ff028,0x0c2013d0,0x0c1fffdc,0x0c202384):
            return (value&0xffff)|((((value>>16)+11)&65535)<<16)
    elif address==0x0c29c0a4:
        countdown=(value>>16)&65535
        return (value&65535)|(((countdown+2 if countdown else 0)&65535)<<16)
    elif address==0x0c29b870:return value+11 if 0<value<0x7ffffff0 else value
    return relocated(value)


def prepare():
    frozen=CACHE/'scene_batch_qualified_development_freeze_v1.json'
    development=json.loads(frozen.read_text());assert development['qualified_development_only']
    assert development['full_regression']['passed'] and len(development['entries'])==2
    for row in development['references']:assert digest(row['path'])==row['sha256'],'development dependency changed'
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs';paths=[];groups=[]
    for n,(entry,owner,prior) in enumerate(GROUPS,1):
        name=f'coverage_65_scene_batch_accept_v{n}'
        old=json.loads((inputs/f'{prior}_memory.json').read_text())[entry]
        old_regs=json.loads((inputs/f'{prior}_registers.json').read_text())[entry]
        memory={}
        for address,values in old.items():
            physical=int(address,16);sequence=override_sequence(values,address)
            memory[hex(relocated(physical))]=[changed(entry,physical,override_value(sequence,(i+71)%256)) for i in range(256)]
        registers={reg:[relocated(override_value(override_sequence(values,reg),(i+71)%256))
                       if not reg.startswith(('fr','xf')) else override_value(override_sequence(values,reg),(i+71)%256)
                       for i in range(256)] for reg,values in old_regs.items()}
        current=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',
                 inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
        assert not any(p.exists() for p in current),'refuse to replace acceptance inputs'
        current[0].write_text('pc '+entry+'\n')
        for path,data in zip(current[1:4],({entry:owner},{entry:memory},{entry:registers})):
            path.write_text(json.dumps(data,indent=2)+'\n')
        generate(current[0],current[4],0x8c0432e2,256,fpscr=0x40001,bounded_arguments=True,
            preserve_fields=True,register_overrides={entry:registers},memory_overrides={entry:memory})
        paths+=current;groups.append(dict(name=name,entry=entry,owner=owner))
    out=base/'coverage_65_scene_batch_accept_input_manifest_v1.json';assert not out.exists()
    out.write_text(json.dumps(dict(coverage_credit=False,created_at_utc=datetime.now(timezone.utc).isoformat(),
        development_freeze=reference(frozen),groups=groups,files=[reference(p) for p in paths],
        original_states=[reference(ROOT/f'tools/emu/flycast-build/data/vf3_{i}.state') for i in (45,46)],
        hypothesis='Disjoint initialized original states, relocated writable descriptor buffers, permuted variants and changed round thresholds/counts, paired timers and scene countdowns; code, literal pools and callback results unchanged.'),indent=2)+'\n')


if __name__=='__main__':prepare()
