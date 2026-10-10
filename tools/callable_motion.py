"""Exact original BSR/prefix contract for the motion-frame descriptor caller."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios

PARENT = 0x8c0a94d0
OWNER = 0x8c0a94d4
CALLERS = (0x8c0a9208, 0x8c0a921a)
PREFIX = (0xe004, 0x2fe6, 0x4f22)
RESTORE = ((0x8c0a9588,0x7f14), (0x8c0a958a,0x4f26),
           (0x8c0a958c,0x000b), (0x8c0a958e,0x6ef6))


def verify_motion_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid motion caller state'
    site = canonical(sample['entry'])
    assert site in CALLERS, 'unsupported motion caller'
    opcode = struct.unpack('<H',image_bytes(image,site,2))[0]
    displacement = opcode & 0xfff
    if displacement & 0x800: displacement -= 0x1000
    assert opcode >> 12 == 0xb and site+4+2*displacement == PARENT, 'wrong original BSR target'
    assert image_bytes(image,site+2,2) == struct.pack('<H',0x64c3), 'wrong original descriptor delay slot'
    before = struct.unpack('<63I',sample['before'])
    after = struct.unpack('<63I',sample['after'])
    assert before[8:16] == after[8:16], 'motion callee-save/stack invariant failed'
    assert canonical(sample['exitpc']) == site+4 and canonical(after[16]) == site+4, 'missing original BSR return'
    ops = [(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal motion opcode'
        if op >> 12 in (0x9,0xd):
            size=2 if op >> 12 == 9 else 4
            pool=pc+4+2*(op&255) if size==2 else ((pc+4)&~3)+4*(op&255)
            assert captured_bytes(sample,pool,size) == captured_bytes(sample,pool,size,True) == image_bytes(image,pool,size), 'modified motion literal pool'
    expected = [(site,opcode),(site+2,0x64c3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing original BSR, delay or prefix'
    assert ops[-4:] == list(RESTORE), 'missing ordered motion return and R14 restoration'
    assert sum(pair == RESTORE[1] for pair in ops) == 1, 'repeated motion PR restoration'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_motion_frame(owner, attribution, spans, corpus, image):
    assert owner == OWNER and int(attribution['entry'],16) == PARENT, 'unsupported motion callable'
    assert min(s for s,e in spans) == OWNER and any(s <= owner < e for s,e in spans), 'wrong frozen motion owner'
    assert attribution.get('call_sites') == [hex(pc) for pc in CALLERS], 'wrong declared motion BSR sites'
    assert attribution.get('callee_save_prefix') == ['r14'], 'wrong declared motion save'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal motion body opcode'
    required=set(range(PARENT,OWNER,2)) | {pc for s,e in spans for pc in range(s,e,2)}
    assert required <= ops.keys(), 'incomplete motion prefix or frozen body'
    for i,op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i) == op, 'unsupported motion prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing native motion save evidence'
    for line in cases:
        values=[int(v,16) for v in line.split()[:74]]
        assert len(values) == 74 and values[8:16] == values[45:53], 'native motion callee-save/stack invariant failed'
    seen=set()
    def verifier(sample,image):
        fingerprint=verify_motion_sample(sample,image)
        seen.add(canonical(sample['entry']))
        return fingerprint
    require_original_scenarios(attribution['original_caller_manifests'],image,verifier)
    assert seen == set(CALLERS), 'missing one original motion BSR site'
    return PARENT,set(ops)
