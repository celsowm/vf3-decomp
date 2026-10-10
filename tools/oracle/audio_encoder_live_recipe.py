"""Disjoint live encoder inputs; command meanings remain unattributed."""
import json
from pathlib import Path


def recipe(acceptance=False):
    cases=[]
    commands=(0x01a0,0x04a0,0x05a0,0x06a0,0x07a0,0x09a0,0x0aa0,0x10a0,0x11a0,
              0x08a0,0x001100a0,0x123401a0,0,0xffffffff)
    for i,command in enumerate(commands):
        for j in range(2):
            n=2*i+j
            parameter=(63,0xffffffff)[j] if acceptance else (0,128)[j]
            channel=0xffff8000+n*7 if acceptance else 0x12340000+n*19
            registers=dict(r4=channel,r5=command,r6=parameter,
                           r14=(0x79800000 if acceptance else 0x65400000)+n)
            if acceptance:registers['r15']=0x0c3fd000
            case=dict(name=f'{"accept" if acceptance else "dev"}_pack_{n:02d}',
                      entry='0x8c040b7c',registers=registers,event_window=True)
            if n%6==3:case['control']='queue_busy'
            cases.append(case)
    for pattern in range(4):
        memory={}
        for channel in range(1,8):
            enabled=pattern==1 or (pattern==2 and (channel+(1 if acceptance else 0))&1) or (pattern==3 and channel==(1 if acceptance else 7))
            memory[hex(0x0c19e310+12*channel)]=(0x81570000+channel if acceptance else 0) if enabled else 0xffffffff
        registers=dict(r4=0xdead8765 if acceptance else 0x12345678,
                       r5=0x001f00a0,r6=0x98765432 if acceptance else 0x12345678,
                       r14=(0x78901200 if acceptance else 0x67890100)+pattern)
        if acceptance:registers['r15']=0x0c3fd000
        case=dict(name=f'{"accept" if acceptance else "dev"}_broadcast_{pattern}',
                  entry='0x8c040b7c',registers=registers,memory=memory,event_window=True)
        if pattern==2:case['control']='queue_busy'
        cases.append(case)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=cases)


if __name__=='__main__':
    for name,acceptance in (('dev',False),('accept',True)):
        Path(__file__).with_name(f'audio_encoder_live_{name}_v1.json').write_text(
            json.dumps(recipe(acceptance),indent=2)+'\n')
    pilot=recipe();pilot['cases']=[pilot['cases'][i] for i in (0,3,5,17,22,28,29,30,31)]
    Path(__file__).with_name('audio_encoder_live_pilot_v1.json').write_text(json.dumps(pilot,indent=2)+'\n')
