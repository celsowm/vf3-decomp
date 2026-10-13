"""Mutation-test sealed original caller contracts without changing evidence."""
import argparse
import copy
import json
from pathlib import Path
import struct
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from callable_dispatch import checked_reference,canonical
from callable_actor_tables import verify_actor_table_sample
from callable_small_ram import verify_small_ram_sample
from capsules import records

def controls(callables,out):
    if out.exists():raise FileExistsError(out)
    declarations=json.loads(callables.read_text());checks=[]
    manifests={ref['path']:ref for row in declarations.values() for ref in row['original_caller_manifests']}
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    for ref in manifests.values():
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            sample,=records(checked_reference(dict(path=run['capsule'],sha256=run['capsule_sha256'])))
            verify=verify_actor_table_sample if canonical(sample['entry'])==0x8c0a2f3c else verify_small_ram_sample
            verify(sample,image)
            mutations={
                'invalid_flags':lambda s:s.update(flags=1),
                'device_access':lambda s:s.update(device=[(0,0,0,0)]),
                'missing_first_instruction':lambda s:s['ops'].pop(0),
                'missing_return_delay':lambda s:s['ops'].pop(),
                'wrong_return':lambda s:s.update(exitpc=s['exitpc']+2),
                'changed_opcode':lambda s:s['ops'].__setitem__(0,(s['ops'][0][0],s['ops'][0][1]^1)),
                'changed_stack_pointer':lambda s:s.update(after=struct.pack('<63I',*(v+4 if i==15 else v for i,v in enumerate(struct.unpack('<63I',s['after']))))),
            }
            for name,mutation in mutations.items():
                altered=copy.deepcopy(sample);mutation(altered)
                try:verify(altered,image)
                except AssertionError:checks.append(dict(case=run['case'],state=run['state'],control=name,rejected=True))
                else:raise AssertionError(f'accepted {name} for {run["case"]}')
    out.write_text(json.dumps(dict(diagnostic_only=True,coverage_credit=False,passed=True,checks=checks),indent=2)+'\n')
    print(f'{len(checks)} altered caller records rejected; originals unchanged')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--callables',type=Path,required=True)
    p.add_argument('--out',type=Path,required=True);a=p.parse_args();controls(a.callables,a.out)
