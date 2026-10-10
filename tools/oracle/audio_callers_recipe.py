"""Independent request-wrapper and immutable selection-table input cases."""
import json
from pathlib import Path


def requests(acceptance=False):
    commands=(-1,0x4a0,0x5a0,0x2a0,0x3a0,0x100a0,0x300a0,0x200a0,
              0x1a0,0x8a0,0x1f00a0,0,0x123401a0,0xffffffff,0x5a0,0x300a0)
    cases=[]
    for n,command in enumerate(commands):
        registers=dict(r4=command,r5=(63 if acceptance else 128)+n,
                       r11=0x54320000+n,r12=0x65430000+n,
                       r13=0x76540000+n,r14=0x87650000+n)
        if acceptance:registers['r15']=0x0c3fd000
        memory={hex(0x0c19e310+12*c):0x81234500+c if acceptance else 0 for c in range(1,8)}
        case=dict(name=f'{"accept" if acceptance else "dev"}_request_{n:02d}',
                  entry='0x8c0c5c94',registers=registers,memory=memory,event_window=True)
        if n>=14:case['control']='queue_busy'
        cases.append(case)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=cases)


def selection(acceptance=False):
    # Owned writable selection word and controls; neither ID lookup is patched.
    pairs=((0,0),(0,0x2000),(457,8),(9,0x8000),(450,0x4000),(423,0),
           (5,0x100),(416,0x100),(100,4),(101,0x80000000),
           (102,0x200),(103,0x20000),(104,0x400),(105,0x40000000),
           (106,0x1000),(10,0xf008),(107,0x400),(108,0x400))
    cases=[]
    base=0x0c480000 if acceptance else 0x0c404000
    for n,(index,controls) in enumerate(pairs):
        if acceptance and n not in (1,2,3,4,5,6,7):index=(index+37)%458
        memory={hex(0x0c29bd7c):index<<16,hex(0x0c29b9a0):controls,
                hex(0x0c29b86c):3 if n%4==1 or n>=16 else 2,
                hex(0x0c11e504):0x80000000 if n==17 else 0,
                hex(0x0c1fd758):(0x6789 if acceptance else 0x4567)+n,
                hex(0x0c29bb94):base,hex(0x0c29bb98):base+0x100,
                hex(base+96):((n+7 if acceptance else n)%9)<<8,
                hex(base+0x100+96):((n+3 if acceptance else n+1)%9)<<8}
        for identifier in range(477):memory[hex(0x0c2cfa00+4*identifier)]=0
        registers=dict(r14=(0x789a0000 if acceptance else 0x67890000)+n)
        if acceptance:registers['r15']=0x0c3fd000
        case=dict(name=f'{"accept" if acceptance else "dev"}_input_{n:02d}',
                  entry='0x8c0c9f54',registers=registers,memory=memory,event_window=True)
        if n in (7,10):case['control']='queue_busy'
        cases.append(case)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=cases)


if __name__=='__main__':
    for name,acceptance in (('dev',False),('accept',True)):
        for target,generator in (('request',requests),('input',selection)):
            Path(__file__).with_name(f'audio_{target}_{name}_v1.json').write_text(
                json.dumps(generator(acceptance),indent=2)+'\n')
