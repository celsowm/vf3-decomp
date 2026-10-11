"""Fixed literal JSR and register setup for the round-score frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a7be2
OWNER=0x8c0a7bec
LOAD=0x8c0c04ce
CALL=LOAD+4
RETURN=CALL+4
POOL=0x0c0c0504
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0x4f22)
RESTORE=tuple((0x8c0a7e28+2*i,op) for i,op in enumerate(
    (0x7f08,0x900f,0x4f16,0x05b5,0x4f26,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10']
SAVE_INDICES=[14,13,12,11,10,16,19]


def verify_round_score_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid round-score caller'
    assert canonical(sample['entry'])==LOAD, 'unsupported round-score caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'round-score integer saves/stack changed'
    assert before[33:53]==after[33:53], 'round-score FR saves or XF changed'
    assert before[19]==after[19], 'round-score MACL changed'
    assert before[18]==after[18], 'round-score FPSCR changed'
    assert canonical(sample['exitpc'])==RETURN and canonical(after[16])==RETURN, 'missing round-score JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal round-score opcode'
    expected=[(LOAD,0xd30d),(LOAD+2,0x57f5),(CALL,0x430b),(CALL+2,0x64d3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing round-score literal, arguments, JSR or save prefix'
    assert ((LOAD+4)&~3)+4*0x0d==canonical(POOL), 'wrong round-score literal slot'
    assert image_bytes(image,POOL,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong round-score loaded target'
    assert ops.count((0x8c0a7bee,0xde07))==1 and ops.count((0x8c0a7bf2,0x4f12))==1, 'missing round-score global or MACL save'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered round-score restoration'
    assert sum(pair==RESTORE[4] for pair in ops)==1, 'repeated round-score PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'round-score saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_round_score(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported round-score callable'
    assert min(a for a,z in spans)==OWNER, 'wrong round-score owner'
    assert attribution.get('call_sites')==[hex(CALL)] and attribution.get('literal_pool')==hex(POOL), 'wrong round-score caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong round-score save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal round-score body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete round-score prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported round-score prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native round-score proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native round-score integer saves changed'
        assert v[19]==v[56], 'native round-score MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native round-score FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_round_score_sample)
    return PARENT,set(ops)
