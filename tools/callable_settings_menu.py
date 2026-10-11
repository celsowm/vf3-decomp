"""Fixed scene-98 dispatcher, original table and save sequence for the settings-menu frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

from callable_dispatch import DISPATCH, DISPATCH_OPS, TABLE, SCENE
PARENT=0x8c0c95f4
OWNER=0x8c0c9610
INDEX=98
PREFIX=(0x2fe6,0xe701,0x2fd6,0xe603,0x2fc6,0xec00,0x2fb6,
        0x2fa6,0x2f96,0x905c,0xdd31,0xde32,0x05de,0x905a,0x4f22)
RESTORE=tuple((0x8c0c98d8+2*i,op) for i,op in enumerate(
    (0x7f08,0xd330,0x4f26,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0x432b,0x6ef6)))
TAIL=((0x8c09abc4,0xd512),(0x8c09ac02,0x000b),(0x8c09ac04,0x0009))
SAVES=['r14','r13','r12','r11','r10','r9']
SAVE_INDICES=[14,13,12,11,10,9,16]


def verify_settings_menu_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid settings-menu caller'
    assert canonical(sample['entry'])==DISPATCH, 'unsupported settings-menu caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'settings-menu integer saves/stack changed'
    assert before[33:53]==after[33:53], 'settings-menu FR saves or XF changed'
    assert before[19]==after[19], 'settings-menu MACL changed'
    assert before[18]==after[18], 'settings-menu FPSCR changed'
    assert canonical(sample['exitpc'])==canonical(before[16]) and canonical(after[16])==canonical(before[16]), 'missing settings-menu JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal settings-menu opcode'
    expected=[(DISPATCH+2*i,op) for i,op in enumerate(DISPATCH_OPS)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing settings-menu literal, arguments, JSR or save prefix'
    assert captured_bytes(sample,SCENE+10,1)==bytes([INDEX]), 'wrong settings-menu scene index'
    slot=TABLE+INDEX*4
    assert image_bytes(image,slot,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong settings-menu scene target'
    assert captured_bytes(sample,slot,4)==captured_bytes(sample,slot,4,True)==image_bytes(image,slot,4), 'modified settings-menu scene table'
    for pool,target in [(0x0c0c96d0,SCENE),(0x0c0c96d4,0x0c29bcc4),(0x0c0c999c,0x0c09abc4)]:
        assert image_bytes(image,pool,4)==struct.pack('<I',target), 'wrong settings-menu global or tail literal'
    original_pools(sample,image,ops)
    positions=[i for i,pair in enumerate(ops) if pair==RESTORE[0]]
    assert len(positions)==1, 'missing settings-menu restoration'
    at=positions[0]
    assert ops[at:at+len(RESTORE)]==list(RESTORE), 'missing ordered settings-menu restoration'
    assert ops[at+len(RESTORE)]==TAIL[0] and ops[-2:]==list(TAIL[-2:]), 'missing original settings-menu cursor tail and return'
    assert sum(pair==RESTORE[2] for pair in ops)==1, 'repeated settings-menu PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'settings-menu saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_settings_menu(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported settings-menu callable'
    assert min(a for a,z in spans)==OWNER, 'wrong settings-menu owner'
    assert attribution.get('call_sites')==['0x8c0968f4'] and attribution.get('table')==hex(TABLE) and attribution.get('index')==INDEX, 'wrong settings-menu caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong settings-menu save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal settings-menu body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete settings-menu prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported settings-menu prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native settings-menu proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native settings-menu integer saves changed'
        assert v[19]==v[56], 'native settings-menu MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native settings-menu FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_settings_menu_sample)
    return PARENT,set(ops)
