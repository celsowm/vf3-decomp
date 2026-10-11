"""Both original BSR sites, zero count, saved registers and replay scene."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a9036
OWNER=0x8c0a9040
CALLS=(0x8c0a8e64,0x8c0a8e6e)
PREFIX=(0x2fe6,0x2fd6,0x6d43,0x2fc6,0x2fb6,0x4f22)
RESTORE=tuple((0x8c0a91cc+2*i,op) for i,op in enumerate(
    (0x7f18,0x4f26,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11']
SAVE_INDICES=[14,13,12,11,16]


def verify_replay_record_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid replay-record caller'
    call=canonical(sample['entry']);assert call in CALLS, 'unsupported replay-record caller'
    returned=call+4
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'replay-record integer saves/stack changed'
    assert before[33:53]==after[33:53], 'replay-record FR saves or XF changed'
    assert before[19]==after[19], 'replay-record MACL changed'
    assert before[18]==after[18], 'replay-record FPSCR changed'
    assert canonical(sample['exitpc'])==returned and canonical(after[16])==returned, 'missing replay-record JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-record opcode'
    opcode=0xb0e7 if call==CALLS[0] else 0xb0e2
    expected=[(call,opcode),(call+2,0x64d3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing replay-record literal, arguments, JSR or save prefix'
    displacement=opcode&0xfff
    if displacement&0x800:displacement-=0x1000
    assert call+4+displacement*2==PARENT, 'wrong replay-record BSR target'
    assert image_bytes(image,0x0c0a9084,4)==struct.pack('<I',0x0c29bcc4), 'wrong original replay scene'
    assert (0x8c0a9046,0xdb0f) in ops, 'missing original scene-context load'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered replay-record restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated replay-record PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'replay-record saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_replay_record(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported replay-record callable'
    assert min(a for a,z in spans)==OWNER, 'wrong replay-record owner'
    assert attribution.get('call_sites')==[hex(pc) for pc in CALLS], 'wrong replay-record caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong replay-record save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal replay-record body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete replay-record prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported replay-record prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native replay-record proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native replay-record integer saves changed'
        assert v[19]==v[56], 'native replay-record MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native replay-record FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_replay_record_sample)
    return PARENT,set(ops)
