"""Fixed literal JSR and register setup for the replay-history frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a87fc
OWNER=0x8c0a8808
LOAD=0x8c099206
CALL=LOAD+4
RETURN=CALL+4
POOL=0x0c099270
PREFIX=(0x2fe6,0xe050,0x2fd6,0x2fc6,0x2fb6,0x2fa6)
RESTORE=tuple((0x8c0a88d4+2*i,op) for i,op in enumerate(
    (0x7f08,0x4f16,0x4f26,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10']
SAVE_INDICES=[14,13,12,11,10,16,19]


def verify_replay_history_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid replay-history caller'
    assert canonical(sample['entry'])==LOAD, 'unsupported replay-history caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'replay-history integer saves/stack changed'
    assert before[33:53]==after[33:53], 'replay-history FR saves or XF changed'
    assert before[19]==after[19], 'replay-history MACL changed'
    assert before[18]==after[18], 'replay-history FPSCR changed'
    assert canonical(sample['exitpc'])==RETURN and canonical(after[16])==RETURN, 'missing replay-history JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-history opcode'
    expected=[(LOAD,0xd31a),(LOAD+2,0x65f2),(CALL,0x430b),(CALL+2,0x54f1)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing replay-history literal, arguments, JSR or save prefix'
    assert ((LOAD+4)&~3)+4*0x1a==canonical(POOL), 'wrong replay-history literal slot'
    assert image_bytes(image,POOL,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong replay-history loaded target'
    assert ops.count((0x8c0a8808,0x4f22))==1 and ops.count((0x8c0a880a,0x4f12))==1, 'missing replay-history global or MACL save'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered replay-history restoration'
    assert sum(pair==RESTORE[2] for pair in ops)==1, 'repeated replay-history PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'replay-history saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_replay_history(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported replay-history callable'
    assert min(a for a,z in spans)==OWNER, 'wrong replay-history owner'
    assert attribution.get('call_sites')==[hex(CALL)] and attribution.get('literal_pool')==hex(POOL), 'wrong replay-history caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong replay-history save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-history body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete replay-history prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported replay-history prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native replay-history proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native replay-history integer saves changed'
        assert v[19]==v[56], 'native replay-history MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native replay-history FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_replay_history_sample)
    return PARENT,set(ops)
