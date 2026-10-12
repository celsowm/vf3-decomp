"""Prepare the original parent tail transfer and complete selection return."""
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence, override_value

ROOT=Path(__file__).resolve().parents[2]


def main():
    base=ROOT/'tools/oracle'
    inputs=base/'percentage_inputs'
    entry='0x8c0c3210';prior='coverage_65_selection_unlock_screen_v1'
    memory=json.loads((inputs/f'{prior}_memory.json').read_text())[entry]
    registers=json.loads((inputs/f'{prior}_registers.json').read_text())[entry]
    cases=[]
    for index,variant in enumerate((0,7,12,31)):
        fields={address:override_value(override_sequence(value,address),variant) for address,value in memory.items()}
        fields['0xc690100']=0xc4b1234
        regs={'fpscr':0x40001,**{reg:override_value(override_sequence(value,reg),variant) for reg,value in registers.items()},'r15':0xc690100}
        cases.append(dict(name=f'original_selection_tail_{index}',entry='0x0c0c31de',
            registers=regs,memory=fields,budget=100000,trigger_ordinal=16,
            expected_exit='0x0c0432e4',explicit_return_only=True,transfer='0x0c0c38c2'))
    out=base/'coverage_65_selection_unlock_original_tail_v1.json'
    assert not out.exists(),'refuse to overwrite original caller inputs'
    out.write_text(json.dumps(dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',
        fixture_scope='Original parent BRA at 0c0c31de and R14 pop delay slot, all seven callee saves before frozen owner 0c0c321e, actual RTS 0c0c38c2 and R14 pop delay slot; code and pools unchanged.',
        cases=cases),indent=2)+'\n')


if __name__=='__main__':main()
