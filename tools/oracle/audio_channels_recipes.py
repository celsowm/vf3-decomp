"""Independent channel development/acceptance inputs; no coverage is assigned here."""
import argparse
import json
from pathlib import Path


def recipe(acceptance=False):
    cases = []
    def add(name, mono, dual, mode=0, result=0, **extra):
        registers=dict(r4=mono, r5=dual, r6=mode)
        if acceptance: registers['r15']='0x0c3fd000'
        cases.append(dict(name=name, entry='0x8c040fa4',
            registers=registers, expected_result=result,
            event_window=True, **extra))
    for dual in range(5):
        for mono in range(9-2*dual):
            inputs = dict(allocation_start=0x12000+len(cases)*32,
                          allocation_boundary=0x110000+len(cases)*64) if acceptance else {}
            add(f'layout_{mono}_{dual}',mono+(0x10000 if acceptance else 0),
                dual+(0x20000 if acceptance else 0),0x10000 if acceptance else 0,
                audio_inputs=inputs)
    for i in range(8):
        add(f'active_{i}',3 if acceptance else 2,2 if acceptance else 3,result=-3,
            memory={hex(0x0c19e250+24*i):'0x1'})
    modes = [4,6,9,-3,-4,127,-128] if acceptance else [1,2,7,-1,-2,32767,-32768]
    for mode in modes:
        add(f'mode_{mode}',3 if acceptance else 2,2 if acceptance else 3,mode,-2)
    for i in range(4):
        add(f'overflow_{i}',7+i if acceptance else 9+i,1 if acceptance else 0,result=-1)
    for i in range(8):
        add(f'small_{i}',3 if acceptance else 2,2 if acceptance else 3,
            audio_inputs=dict(allocation_boundary=(1536+i*96) if acceptance else (1024+i*64),
                              allocation_start=0x12002+i*32 if acceptance else 0x10000))
    for i in range(8):
        add(f'alignment_{i}',4 if acceptance else 2,1 if acceptance else 3,
            audio_inputs=dict(allocation_start=0x14007+i*35 if acceptance else 0x10001+i*31))
    add('negative_mono',-3 if acceptance else -1,0)
    add('negative_dual',0,-3 if acceptance else -1)
    add('busy_queue',3 if acceptance else 2,2 if acceptance else 3,control='queue_busy')
    add('wrap_queue',4 if acceptance else 2,1 if acceptance else 3,
        memory={'0x0c19e218':'0xa08004fc'})
    assert len(cases)==64
    return dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',
                corpus='acceptance' if acceptance else 'development',cases=cases)


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--development',type=Path,required=True)
    ap.add_argument('--acceptance',type=Path,required=True)
    a=ap.parse_args()
    for path,acceptance in [(a.development,False),(a.acceptance,True)]:
        if path.exists(): raise FileExistsError(path)
        path.write_text(json.dumps(recipe(acceptance),indent=2)+'\n',encoding='utf-8')


if __name__=='__main__': main()
