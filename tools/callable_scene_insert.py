"""Fixed literal JSR and register setup for the scene-insert frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c09fefe
OWNER=0x8c09ff12
LOAD=0x8c09a6b2
CALL=LOAD+2
RETURN=CALL+4
POOL=0x0c09a70c
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0xec00,0x2fb6,0x2fa6,0x2f96,0x2f86,
        0x9038,0xde24,0x4f22)
RESTORE=tuple((0x8c0a00a2+2*i,op) for i,op in enumerate(
    (0x7f10,0x4f26,0x68f6,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10','r9','r8']
SAVE_INDICES=[14,13,12,11,10,9,8,16]


def verify_scene_insert_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid scene-insert caller'
    assert canonical(sample['entry'])==LOAD, 'unsupported scene-insert caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'scene-insert integer saves/stack changed'
    assert before[33:53]==after[33:53], 'scene-insert FR saves or XF changed'
    assert before[18]==after[18], 'scene-insert FPSCR changed'
    assert canonical(sample['exitpc'])==RETURN and canonical(after[16])==RETURN, 'missing scene-insert JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal scene-insert opcode'
    expected=[(LOAD,0xd216),(CALL,0x420b),(CALL+2,0x0009)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing scene-insert literal, arguments, JSR or save prefix'
    assert ((LOAD+4)&~3)+4*0x16==canonical(POOL), 'wrong scene-insert literal slot'
    assert image_bytes(image,POOL,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong scene-insert loaded target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered scene-insert restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated scene-insert PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'scene-insert saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_scene_insert(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported scene-insert callable'
    assert min(a for a,z in spans)==OWNER, 'wrong scene-insert owner'
    assert attribution.get('call_sites')==[hex(CALL)] and attribution.get('literal_pool')==hex(POOL), 'wrong scene-insert caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong scene-insert save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal scene-insert body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete scene-insert prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported scene-insert prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native scene-insert proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native scene-insert integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native scene-insert FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_scene_insert_sample)
    return PARENT,set(ops)
