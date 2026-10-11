"""Fixed scene-nine dispatcher, original table and save sequence for the round-transition frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

from callable_dispatch import DISPATCH, DISPATCH_OPS, TABLE, SCENE
PARENT=0x8c09a0a8
OWNER=0x8c09a0c0
INDEX=9
PREFIX=(0x2fe6,0xe029,0x2fd6,0xe701,0x2fc6,0x2fb6,0xeb00,
        0x2fa6,0xea04,0x2f96,0x2f86,0xdc23,0x4f22)
RESTORE=tuple((0x8c09a24c+2*i,op) for i,op in enumerate(
    (0x4f26,0x68f6,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10','r9','r8']
SAVE_INDICES=[14,13,12,11,10,9,8,16]


def verify_round_transition_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid round-transition caller'
    assert canonical(sample['entry'])==DISPATCH, 'unsupported round-transition caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'round-transition integer saves/stack changed'
    assert before[33:53]==after[33:53], 'round-transition FR saves or XF changed'
    assert before[19]==after[19], 'round-transition MACL changed'
    assert before[18]==after[18], 'round-transition FPSCR changed'
    assert canonical(sample['exitpc'])==canonical(before[16]) and canonical(after[16])==canonical(before[16]), 'missing round-transition JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal round-transition opcode'
    expected=[(DISPATCH+2*i,op) for i,op in enumerate(DISPATCH_OPS)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing round-transition literal, arguments, JSR or save prefix'
    assert captured_bytes(sample,SCENE+10,1)==bytes([INDEX]), 'wrong round-transition scene index'
    slot=TABLE+INDEX*4
    assert image_bytes(image,slot,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong round-transition scene target'
    assert captured_bytes(sample,slot,4)==captured_bytes(sample,slot,4,True)==image_bytes(image,slot,4), 'modified round-transition scene table'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered round-transition restoration'
    assert sum(pair==RESTORE[0] for pair in ops)==1, 'repeated round-transition PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'round-transition saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_round_transition(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported round-transition callable'
    assert min(a for a,z in spans)==OWNER, 'wrong round-transition owner'
    assert attribution.get('call_sites')==['0x8c0968f4'] and attribution.get('table')==hex(TABLE) and attribution.get('index')==INDEX, 'wrong round-transition caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong round-transition save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal round-transition body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete round-transition prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported round-transition prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native round-transition proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native round-transition integer saves changed'
        assert v[19]==v[56], 'native round-transition MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native round-transition FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_round_transition_sample)
    return PARENT,set(ops)
