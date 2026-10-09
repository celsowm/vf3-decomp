"""Original-only command encoder pilot; no live C or percentage acceptance."""
import json
from pathlib import Path


def recipe():
    cases=[]
    commands=(0x01a0,0x04a0,0x05a0,0x06a0,0x07a0,0x09a0,0x0aa0,0x10a0,0x11a0,
              0x08a0,0x001100a0,0x123401a0,0,0xffffffff)
    for i,command in enumerate(commands):
        for j,parameter in enumerate((0,63,128,0xffffffff)):
            case=dict(name=f'pack_{i:02d}_{j}',entry='0x8c040b7c',
                registers=dict(r4=(0x12340000+i*19+j),r5=command,r6=parameter,
                               r14=0x76890000+i*4+j),event_window=True)
            if j==3:case['control']='queue_busy'
            cases.append(case)
    for pattern in range(4):
        for busy in range(2):
            memory={}
            for channel in range(1,8):
                enabled=pattern==1 or (pattern==2 and channel&1) or (pattern==3 and channel==7)
                memory[hex(0x0c19e310+channel*12)]=0 if enabled else 0xffffffff
            case=dict(name=f'broadcast_{pattern}_{busy}',entry='0x8c040b7c',
                registers=dict(r4=0xffff,r5=0x001f00a0,r6=0x89abcdef,r14=0x55667788),
                memory=memory,event_window=True)
            if busy:case['control']='queue_busy'
            cases.append(case)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=cases)


if __name__=='__main__':
    Path(__file__).with_name('audio_encoder_pilot_v1.json').write_text(
        json.dumps(recipe(),indent=2)+'\n')
