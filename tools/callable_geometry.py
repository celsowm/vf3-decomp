"""Fixed original literal JSR, integer/FR saves and return for actor geometry."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios

PARENT = 0x8c0ca8c0
OWNER = 0x8c0ca8da
LOAD = 0x8c0b04ea
CALL = LOAD+2
RETURN = CALL+4
POOL = 0x0c0b0568
PREFIX = (0x2fe6,0x2fd6,0x6d43,0x2fc6,0x2fb6,0xeb02,0x2fa6,0x2f96,
          0xfffb,0xffeb,0xffdb,0xffcb,0x9016,0x4f22)
RESTORE = ((0x8c0caa82,0x7f1c),(0x8c0caa84,0x4f26),
           (0x8c0caa86,0xfcf9),(0x8c0caa88,0xfdf9),
           (0x8c0caa8a,0xfef9),(0x8c0caa8c,0xfff9),
           (0x8c0caa8e,0x69f6),(0x8c0caa90,0x6af6),
           (0x8c0caa92,0x6bf6),(0x8c0caa94,0x6cf6),
           (0x8c0caa96,0x6df6),(0x8c0caa98,0x000b),(0x8c0caa9a,0x6ef6))


def original_pools(sample, image, ops):
    for pc, op in ops:
        if op>>12 in (9,13) or op&0xff00 == 0xc700:
            size = 2 if op>>12 == 9 else 4
            pool = pc+4+2*(op&255) if size == 2 else ((pc+4)&~3)+4*(op&255)
            assert captured_bytes(sample,pool,size) == captured_bytes(sample,pool,size,True) == image_bytes(image,pool,size), 'modified geometry literal pool'


def verify_geometry_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid geometry caller state'
    assert canonical(sample['entry']) == LOAD, 'unsupported geometry caller'
    before = struct.unpack('<63I',sample['before'])
    after = struct.unpack('<63I',sample['after'])
    assert before[8:16] == after[8:16], 'geometry integer saves/stack changed'
    assert before[33:53] == after[33:53], 'geometry FR saves or XF bank changed'
    assert before[18] == after[18], 'geometry FPSCR changed'
    assert canonical(sample['exitpc']) == RETURN and canonical(after[16]) == RETURN, 'missing geometry JSR return'
    ops = [(canonical(pc),op) for pc,op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal geometry opcode'
    expected = [(LOAD,0xd31f),(CALL,0x430b),(CALL+2,0x64e3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing geometry literal JSR, delay or prefix'
    assert ((LOAD+4)&~3)+4*0x1f == canonical(POOL), 'wrong geometry literal slot'
    assert image_bytes(image,POOL,4) == struct.pack('<I',PARENT&0x1fffffff), 'wrong geometry target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):] == list(RESTORE), 'missing ordered geometry integer/FR restoration'
    assert sum(pair == RESTORE[1] for pair in ops) == 1, 'repeated geometry PR restoration'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_geometry(owner, attribution, spans, corpus, image):
    assert owner == OWNER and int(attribution['entry'],16) == PARENT, 'unsupported geometry callable'
    assert min(s for s,e in spans) == OWNER, 'wrong geometry owner'
    assert attribution.get('call_sites') == [hex(CALL)] and attribution.get('literal_pool') == hex(POOL), 'wrong geometry JSR declaration'
    assert attribution.get('callee_save_prefix') == ['r14','r13','r12','r11','r10','r9','fr15','fr14','fr13','fr12'], 'wrong geometry save declaration'
    ops = json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops = {canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc, op in ops.items():
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal geometry body opcode'
    required = set(range(PARENT,OWNER,2)) | {pc for s,e in spans for pc in range(s,e,2)}
    assert required <= ops.keys(), 'incomplete geometry prefix or body'
    for i, op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i) == op, 'unsupported geometry prefix'
    cases = (Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing native geometry save proof'
    for line in cases:
        v = [int(x,16) for x in line.split()[:74]]
        assert len(v) == 74 and v[8:16] == v[45:53], 'native geometry integer saves/stack changed'
        assert v[33:37] == v[70:74] and v[18] == v[55], 'native geometry FR/FPSCR saves changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_geometry_sample)
    return PARENT,set(ops)
