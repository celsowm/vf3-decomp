"""Prepare original command-table caller windows, without table/code patches."""
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence,override_value

ROOT=Path(__file__).resolve().parents[2]
ROWS={
    '0x8c0570e0':(16,'0x0c0572aa'),
    '0x8c057480':(17,'0x0c05764e'),
    '0x8c057c60':(18,'0x0c057e2a'),
    '0x8c057860':(19,'0x0c057a32'),
    '0x8c057fa0':(20,'0x0c05816a')}


def prepare():
    name='coverage_65_strip_parent_original_callers_v3'
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    memory=json.loads((inputs/'coverage_65_strip_parent_screen_v3_memory.json').read_text())
    registers=json.loads((inputs/'coverage_65_strip_parent_screen_v3_registers.json').read_text())
    cases=[]
    for entry,(slot,rts) in ROWS.items():
        for index,variant in enumerate((0,7,12,31)):
            fields={address:override_value(override_sequence(value,address),variant) for address,value in memory[entry].items()}
            fields['0xc400000']=slot
            regs={'fpscr':0x40001,**{reg:override_value(override_sequence(value,reg),variant) for reg,value in registers[entry].items()},'r14':0xc055aa0,'r15':0xc690100}
            cases.append(dict(name=f'original_strip_{int(entry,16):08x}_{index}',entry='0x0c055788',registers=regs,memory=fields,budget=100000,trigger_ordinal=16,expected_exit='0x0c055798',explicit_return_only=True,transfer=rts))
    recipe=dict(advisory=True,coverage_credit=False,trigger='0x8c0432e2',fixture_scope='Original indexed command load, signed type predicate, immutable table 0c055aa0, JSR/delay slot and actual strip-parent RTS; original constructor 0c055da6 loads 0c055a20 and adds 128 before publishing the table through GBR+12.; the RTS lies beyond each seed-fragmented frozen body, so its independently decoded instruction is used explicitly.',cases=cases)
    out=base/f'{name}.json'
    assert not out.exists(),'refuse to overwrite original caller input evidence'
    out.write_text(json.dumps(recipe,indent=2)+'\n')


if __name__=='__main__':prepare()
