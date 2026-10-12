"""Prepare original index-54 scene dispatcher windows for round decisions."""
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence, override_value

ROOT=Path(__file__).resolve().parents[2]


def main():
    entry='0x8c098c62';name='coverage_65_scene_round_decision_dev_v2';inputs=ROOT/'tools/oracle/percentage_inputs'
    memory=json.loads((inputs/f'{name}_memory.json').read_text())[entry];cases=[]
    for n,variant in enumerate((0,64,128,192)):
        fields={a:override_value(override_sequence(values,a),variant) for a,values in memory.items()}
        fields['0xc29b864']=0
        fields['0xc29b86c']=(fields.get('0xc29b86c',0)&~0x00ff0000)|(54<<16)
        registers=dict(fpscr=0x40001,r15=0xc690100)
        registers.update({f'r{r}':0xc4b1000+0x100*n+0x10*r for r in range(8,15)})
        cases.append(dict(name=f'round_scene54_{variant}',entry='0x0c0968d0',registers=registers,
            memory=fields,budget=100000,expected_exit='0x0c0432e4',transfer='0x0c09803c',explicit_return_only=True))
    out=ROOT/'tools/oracle/scene_round_decision_original_dispatch_v1.json'
    assert not out.exists()
    out.write_text(json.dumps(dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',
        fixture_scope='Original scene table index 54, seven GPR saves, complete frame restoration and original audio callback tail; all instructions and pools unchanged.',cases=cases),indent=2)+'\n')


if __name__=='__main__':main()
