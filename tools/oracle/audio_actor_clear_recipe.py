"""Independent actor-cleanup inputs; style lookup and resident ID map are untouched."""
import json
from pathlib import Path


def recipe(acceptance=False):
    cases=[]
    base=0x0c480000 if acceptance else 0x0c404000
    for n in range(64):
        generation=(0x6371 if acceptance else 0x4321)+n*17
        scene=3 if n%8 in (2,3) else 2
        memory={hex(0x0c29b86c):scene,hex(0x0c1fd758):generation,
                hex(0x0c11e504):((128 if acceptance else 1)<<24) if n%8==3 else 0}
        for i,field in enumerate((16,20,72,92,96,100)):
            address=base+i*0x100
            memory[hex(0x0c29bb84+field)]=address
            memory[hex(address)]=(0x83150400+n*0x100+i*6+(n&1))&0xffffffff
            if i<2:
                style=((n+5+i*7) if acceptance else (n+i*3))%16
                memory[hex(address+96)]=style<<8
        # Own the writable dedup table. Some inputs suppress repeated IDs;
        # others deliberately force publication without changing the ROM map.
        for identifier in range(477):
            memory[hex(0x0c2cfa00+4*identifier)]=generation if n%8==4 else generation-1
        registers={'r14':0x76543210+n}
        if acceptance: registers['r15']=0x0c3fd000
        case=dict(name=f'actors_{"accept" if acceptance else "dev"}_{n:02d}',
                  entry='0x8c098040',memory=memory,registers=registers,event_window=True)
        if n%8==5:case['control']='queue_busy'
        cases.append(case)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=cases)


if __name__=='__main__':
    for name,acceptance in [('dev',False),('accept',True)]:
        Path(__file__).with_name(f'audio_actor_clear_{name}_v1.json').write_text(
            json.dumps(recipe(acceptance),indent=2)+'\n')
