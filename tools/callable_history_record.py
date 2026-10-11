"""Original callback installation, initializer tail and nested save frame."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a83c2
OWNER=0x8c0a83ce
LOAD=0x8c0a83ae
TAIL=0x8c0a83b6
POOL=0x0c0a843c
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0xd11d,0x4f22)
CALLER=((LOAD,0xd223),(LOAD+2,0x1723),(LOAD+4,0x64f2),(LOAD+6,0x7f04),(TAIL,0xa004),(TAIL+2,0x4f26))
RESTORE=tuple((0x8c0a8420+2*i,op) for i,op in enumerate(
    (0x4f26,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10']
SAVE_INDICES=[14,13,12,11,10,16]


def verify_history_record_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid history-record caller'
    assert canonical(sample['entry'])==LOAD, 'unsupported history-record caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:15]==after[8:15] and after[15]==before[15]+8, 'history-record integer saves/stack changed'
    assert before[33:53]==after[33:53], 'history-record FR saves or XF changed'
    assert before[19]==after[19], 'history-record MACL changed'
    assert before[18]==after[18], 'history-record FPSCR changed'
    saved_return=struct.unpack('<I',captured_bytes(sample,before[15]+4,4,False))[0]
    assert canonical(sample['exitpc'])==canonical(saved_return) and after[16]==saved_return, 'missing history-record restored caller return'
    descriptor=struct.unpack('<I',captured_bytes(sample,before[15],4,False))[0]
    assert before[7]==descriptor, 'callback descriptor/argument mismatch'
    installed=struct.unpack('<I',captured_bytes(sample,descriptor+12,4,True))[0]
    assert installed==(PARENT&0x1fffffff), 'callback installation changed'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal history-record opcode'
    expected=list(CALLER)+[(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing ordered callback installation, tail or save prefix'
    assert TAIL+4+4*2==PARENT, 'wrong original initializer tail'
    assert image_bytes(image,POOL,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong installed callback target'
    assert image_bytes(image,0x0c0a8444,4)==struct.pack('<I',0x0c29bcc0), 'wrong callback global'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered history-record restoration'
    assert sum(pair==RESTORE[0] for pair in ops)==1, 'repeated history-record PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]+8-4*(i+1),4,True))[0]
        assert actual==wanted, 'history-record saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_history_record(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported history-record callable'
    assert min(a for a,z in spans)==OWNER, 'wrong history-record owner'
    assert attribution.get('call_sites')==[hex(TAIL)] and attribution.get('callback_pool')==hex(POOL), 'wrong history-record caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong history-record save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal history-record body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete history-record prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported history-record prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native history-record proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native history-record integer saves changed'
        assert v[19]==v[56], 'native history-record MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native history-record FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_history_record_sample)
    return PARENT,set(ops)
