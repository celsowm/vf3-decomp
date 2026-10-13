"""Prepare original BSR, literal JSR and component-loader windows."""
import argparse
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence,override_value

def prepare(inputs,out):
    data=json.loads(inputs.read_text());cases=[]
    for entry,start,rts,returned in (
        (0x8c0885c4,0xc088794,0xc0886fa,0xc0887b6),
        (0x8c07b6f4,0xc07bbaa,0xc07b718,0xc07bbb0),
        (0x8c08c054,0xc08be1e,0xc08c0f0,0xc08be24),
        (0x8c0860c2,0xc08b46e,0xc086124,0xc08b4b2)):
        for variant in (0,5):
            fields={address:override_value(override_sequence(value,address),variant)
                    for address,value in data['memory'][hex(entry)].items()}
            regs={reg:override_value(override_sequence(value,reg),variant)
                  for reg,value in data['registers'][hex(entry)].items()}
            regs.update(r15=0xc690100,fpscr=0x40001)
            if entry==0x8c0885c4:
                # The actual parent packs position, velocity, angle, counter
                # and flags into one 36-byte motion object. Its argument
                # setup also constructs the three stack pointers.
                regs.update(r14=0xc440000)
                for off in (0,4,8):
                    fields[hex(0xc440000+off)]=fields[hex(0xc400000+off)]
                    fields[hex(0xc44000c+off)]=fields[hex(0xc404000+off)]
                fields['0xc44001c']=fields['0xc410000']
                fields['0xc440020']=fields['0xc414000']|(fields['0xc40c000']<<24)
            elif entry==0x8c07b6f4:
                regs.update(r12=regs['r5'])
            elif entry==0x8c08c054:
                regs.update(r12=regs['r4'],r13=regs['r5'])
                # Choose the normal restored-PR return; early predicate
                # returns remain covered by the separate full campaigns.
                fields['0xc404014']=0;fields['0xc404000']=4
            else:
                regs.update(r8=0,r9=0xc580000,r12=4,r13=regs['r4'],r14=11)
                fields['0xc690104']=0
            cases.append(dict(name=f'ram_{entry:08x}_{variant}',entry=hex(start),
                registers=regs,memory=fields,budget=100000,transfer=hex(rts),
                expected_exit=hex(returned),explicit_return_only=True))
    if out.exists():raise FileExistsError(out)
    out.write_text(json.dumps(dict(advisory=True,coverage_credit=False,
        trigger='0x8c0432e2',fixture_scope='Original argument preparation, call, '
        'delay slots, callee frames and return; immutable code, pools and component row 10.',
        cases=cases),indent=2)+'\n')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--inputs',type=Path,required=True);p.add_argument('--out',type=Path,required=True)
    a=p.parse_args();prepare(a.inputs,a.out)
