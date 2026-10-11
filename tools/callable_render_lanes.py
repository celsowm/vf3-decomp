"""Original BSR, R11 argument, saved registers and template for render lanes."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c05d424
OWNER=0x8c05d436
CALL=0x8c05c75c
RETURN=CALL+4
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0x6d43,0xd288,0x2fb6,0x2fa6,0x2f96,0x2f86,0x4f22)
RESTORE=tuple((0x8c05d594+2*i,op) for i,op in enumerate(
    (0x7f20,0x4f26,0x68f6,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0x000b,0x6ef6)))
SAVES=['r14','r13','r12','r11','r10','r9','r8']
SAVE_INDICES=[14,13,12,11,10,9,8,16]


def verify_render_lanes_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid render-lane caller'
    assert canonical(sample['entry'])==CALL, 'unsupported render-lane caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'render-lane integer saves/stack changed'
    assert before[33:53]==after[33:53], 'render-lane FR saves or XF changed'
    assert before[19]==after[19], 'render-lane MACL changed'
    assert before[18]==after[18], 'render-lane FPSCR changed'
    assert canonical(sample['exitpc'])==RETURN and canonical(after[16])==RETURN, 'missing render-lane JSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal render-lane opcode'
    expected=[(CALL,0xb662),(CALL+2,0x64b3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing render-lane literal, arguments, JSR or save prefix'
    assert CALL+4+0x662*2==PARENT, 'wrong render-lane BSR target'
    assert image_bytes(image,0x0c05d650,4)==struct.pack('<I',0x0c0d2c34), 'wrong render-lane template'
    assert image_bytes(image,0x0c05d654,4)==struct.pack('<I',0x0c042efc), 'wrong render-lane template copier'
    assert image_bytes(image,0x0c05d660,4)==struct.pack('<I',0x0c062e7e), 'wrong render-lane destination copier'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered render-lane restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated render-lane PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'render-lane saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_render_lanes(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported render-lane callable'
    assert min(a for a,z in spans)==OWNER, 'wrong render-lane owner'
    assert attribution.get('call_sites')==[hex(CALL)], 'wrong render-lane caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong render-lane save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal render-lane body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete render-lane prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported render-lane prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native render-lane proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native render-lane integer saves changed'
        assert v[19]==v[56], 'native render-lane MACL changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native render-lane FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_render_lanes_sample)
    return PARENT,set(ops)
