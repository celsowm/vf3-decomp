"""Owned writable fight-caller inputs; immutable callback and sound tables stay real."""
import json
from pathlib import Path


def case(n, mode=1, flags=0x20000, countdown=0, counter=0, inputs=0x800,
         acceptance=False):
    base=0x0c480000 if acceptance else 0x0c404000
    memory={hex(0x0c29b870):countdown,
            hex(0x0c29b99c):inputs,
            hex(0x0c29bccc):flags,
            hex(0x0c29bcec):mode<<8,
            hex(0x0c29c0a4):(counter&0xffff)<<16,
            hex(0x0c1fd758):0x7900+n if acceptance else 0x5700+n,
            hex(0x0c11e504):0}
    for i,offset in enumerate(range(16,104,4)):
        obj=base+i*0x3000
        memory[hex(0x0c29bb84+offset)]=obj
        memory[hex(obj)]=0x12340001+i*2
        memory[hex(obj+0x60)]=((n+i+(3 if acceptance else 0))%9)<<8
        memory[hex(obj+0x201c)]=(n+i)&255
        memory[hex(obj+0x44)]=((n+i)&0xffff)<<16
    for identifier in range(477):memory[hex(0x0c2cfa00+4*identifier)]=0
    # Writable source float words, actor override bytes, and tail accumulators.
    memory.update({hex(0x0c29c0f4):0x3f800000+n,
                   hex(0x0c29c0fc):0xbf000000+n,
                   hex(0x0c29c0d8):((n+13)%26)<<8,
                   hex(0x0c29c0dc):((n+12)%26)<<16,
                   hex(0x0c29bcf8):10+n,hex(0x0c29bcfc):20+n})
    registers=dict(r14=0x65430000+n,r13=0x76540000+n)
    if acceptance:registers['r15']=0x0c3fd000
    return dict(name=f'{"accept" if acceptance else "dev"}_fight_{n:02d}',
                entry='0x8c099060',registers=registers,memory=memory,
                event_window=True,budget=100000)


def pilot():
    rows=[case(0,countdown=1,inputs=0),case(1),case(2,mode=3),
          case(3,mode=2,inputs=0x80000),case(4,flags=0x20004,counter=17),
          case(5,flags=0x10000000),case(6,mode=3,flags=0x50000000),
          case(7,countdown=1,flags=0x10000000)]
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=rows)


def campaign(acceptance=False):
    rows=[]
    flags=(0x20000,0,0x20004,0x10000000,0x50000000,0x10000004,
           0x20000000,0x50000004)
    counts=(-1,0,15,16,17,32767,-32768,2)
    masks=(0,0x800,0x80000,0x80800,0xffffffff)
    for n in range(32):
        mode=(1,3,2,0)[(n+(1 if acceptance else 0))%4]
        row=case(n,mode=mode,flags=flags[n%8],
                 countdown=(1 if n%7==0 else 0),counter=counts[n%8],
                 inputs=masks[(n+(2 if acceptance else 0))%5],acceptance=acceptance)
        base=0x0c480000 if acceptance else 0x0c404000
        memory=row['memory']
        source=base+0x50000
        memory[hex(0x0c29be8c)]=source
        memory[hex(source+0x430)]=0x3f400000+n+(256 if acceptance else 0)
        memory[hex(source+0x438)]=0xbf200000+n+(512 if acceptance else 0)
        for i in range(22):
            memory[hex(base+i*0x3000+0x60)]=(((n+i+(3 if acceptance else 0))%9)<<8)|((n+i)%26)
        # Bound the real style-count loop, while varying its decrement paths.
        memory[hex(0x0c29c0d4)]=(1+n%3)<<24
        for i in range(0,16,4):memory[hex(0x0c29c124+i)]=0x03020101+n%2
        if n in (9,22):row['control']='queue_busy'
        rows.append(row)
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',cases=rows)


if __name__=='__main__':
    Path(__file__).with_name('audio_fight_pilot_v1.json').write_text(
        json.dumps(pilot(),indent=2)+'\n')
    for name,accept in (('dev',False),('accept',True)):
        Path(__file__).with_name(f'audio_fight_{name}_v1.json').write_text(
            json.dumps(campaign(accept),indent=2)+'\n')
