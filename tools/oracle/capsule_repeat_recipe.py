"""Prepare a diagnostic original one-shot repeat from a complete raw specimen."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from capsules import records
from inspect_capsule import REGISTER_NAMES


def prepare(capsule, invocation, output, transfer, trigger=0x8c0432e2, ordinal=1):
    output=Path(output)
    if output.exists():raise FileExistsError('refusing to replace repeat inputs')
    sample=next((r for r in records(capsule) if r['id']==invocation),None)
    if sample is None:raise ValueError('missing invocation')
    if sample['flags'] or sample['nstate']!=63 or sample['device']:
        raise ValueError('repeat requires a complete 63-word RAM-only specimen')
    if not any((pc&0x1fffffff)==(transfer&0x1fffffff) for pc,op in sample['ops']):
        raise ValueError('transfer boundary absent from original instructions')
    words=struct.unpack('<63I',sample['before'])
    # FPSCR must precede FR/XF assignments: changing FR can swap the banks.
    registers={'fpscr':words[18]}
    registers.update({name:words[index] for name,index in REGISTER_NAMES.items()
                      if name!='fpscr' and not name.startswith('rbank')})
    memory={hex(base+offset):struct.unpack_from('<I',before,offset)[0]
            for base,before,after in sample['pages'] for offset in range(0,len(before),4)}
    with Path(capsule).open('rb') as stream:digest=hashlib.file_digest(stream,'sha256').hexdigest()
    recipe=dict(advisory=True,coverage_credit=False,diagnostic_only=True,trigger=hex(trigger),
        source_capsule=str(Path(capsule).resolve()),source_capsule_sha256=digest,
        source_invocation=invocation,
        register_bank_note='Observer cannot assign rbank0..7; their equality must be checked in the resulting full 63-word input.',
        expected_inactive_gpr_bank=list(words[55:63]),
        cases=[dict(name=f'invocation_{invocation}_exact_ram',entry=hex(sample['entry']),registers=registers,
            memory=memory,trigger_ordinal=ordinal,budget=max(100000,len(sample['ops'])*2),
            expected_exit=hex(sample['exitpc']),transfer=hex(transfer),explicit_return_only=True)])
    output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(recipe,indent=2)+'\n')
    return recipe


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsule',type=Path)
    parser.add_argument('--id',type=int,required=True)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--transfer',type=lambda x:int(x,0),required=True)
    parser.add_argument('--trigger',type=lambda x:int(x,0),default=0x8c0432e2)
    parser.add_argument('--ordinal',type=int,default=1)
    args=parser.parse_args()
    prepare(args.capsule,args.id,args.out,args.transfer,args.trigger,args.ordinal)
    print('Original repeat recipe saved; diagnostic only, full input identity still requires validation')
