"""Original descriptor predicate, installed callback, saved stack and return."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a8e18
OWNER=0x8c0a8e22
CALLS=(0x8c09617c,)
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0x4f22)
RESTORE=tuple((0x8c0a8f00+2*i,op) for i,op in enumerate(
    (0x7f04,0x4f26,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10']
SAVE_INDICES=[14,13,12,11,10,16]


def verify_replay_callback_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid replay-callback caller'
    call=canonical(sample['entry']);assert call in CALLS, 'unsupported replay-callback caller'
    returned=call+12
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'replay-callback integer saves/stack changed'
    assert before[33:53]==after[33:53], 'replay-callback FR saves or XF changed'
    assert before[19]==after[19], 'replay-callback MACL changed'
    assert before[18]==after[18], 'replay-callback FPSCR changed'
    assert canonical(sample['exitpc'])==returned and canonical(after[16])==returned, 'missing replay-callback JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-callback opcode'
    expected=[(call+2*i,op) for i,op in enumerate((0x60e2,0xc801,0x8902,0x53e3,0x430b,0x64e3))]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing replay-callback predicate, load, JSR, argument or save prefix'
    descriptor=before[14]
    flags=struct.unpack('<I',captured_bytes(sample,descriptor,4,False))[0]
    assert flags&1, 'inactive replay-callback descriptor'
    target=struct.unpack('<I',captured_bytes(sample,descriptor+12,4,False))[0]
    assert target==0x0c0a8e18, 'wrong replay-callback descriptor target'
    assert captured_bytes(sample,descriptor+12,4,True)==struct.pack('<I',target), 'replay-callback pointer changed'
    assert image_bytes(image,0x0c0a86a8,4)==struct.pack('<I',target), 'wrong original replay-callback installer pool'
    assert image_bytes(image,0x0c0a8668,4)==struct.pack('<HH',0xd30f,0x1d33), 'wrong original replay-callback installer'
    assert image_bytes(image,0x0c0a8f54,4)==struct.pack('<I',0x0c0c6742), 'wrong original replay mode getter'
    assert (0x8c0a8e24,0xd34b) in ops, 'missing replay mode getter load'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered replay-callback restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated replay-callback PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'replay-callback saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_replay_callback(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported replay-callback callable'
    assert min(a for a,z in spans)==OWNER, 'wrong replay-callback owner'
    assert attribution.get('call_sites')==[hex(pc+8) for pc in CALLS] and attribution.get('dispatch_start')==hex(CALLS[0]), 'wrong replay-callback caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong replay-callback save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-callback body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete replay-callback prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported replay-callback prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native replay-callback proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native replay-callback integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native replay-callback FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_replay_callback_sample)
    return PARENT,set(ops)
