"""Inspect captured RAM at an address or a register-relative offset."""
import argparse
import json
from pathlib import Path
import struct
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from callable_dispatch import captured_bytes
from capsules import records
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('capsule',type=Path)
    p.add_argument('--id',type=int);p.add_argument('--address',type=lambda s:int(s,0))
    p.add_argument('--register',type=int,default=15);p.add_argument('--offset',type=lambda s:int(s,0),default=0)
    p.add_argument('--bytes',type=int,default=16);a=p.parse_args()
    for sample in records(a.capsule):
        if a.id is not None and sample['id']!=a.id:continue
        before,after=[struct.unpack('<63I',sample[k]) for k in ('before','after')]
        address=a.address if a.address is not None else before[a.register]+a.offset
        data=dict(id=sample['id'],entry=hex(sample['entry']),flags=sample['flags'],address=hex(address),
            before_registers=[hex(v) for v in before],after_registers=[hex(v) for v in after],
            before=captured_bytes(sample,address,a.bytes).hex(),after=captured_bytes(sample,address,a.bytes,True).hex())
        print(json.dumps(data,indent=2))
