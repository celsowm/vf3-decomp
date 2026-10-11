"""Fixed original scene contact BSR, register delay, saves and return contract."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT = 0x8c0a07e4
OWNER = 0x8c0a07fa
CALLERS = {0x8c0a1156: 0xbb45}
PREFIX = (0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0x2f96,0x2f86,
          0xfffb,0xffeb,0xffdb,0xffcb,0x4f22)
RESTORE = tuple((0x8c0a0acc+2*i,op) for i,op in enumerate(
    (0x7f18,0xd31e,0x4f26,0xe401,0xfcf9,0xfdf9,0xfef9,0xfff9,
     0x68f6,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0x432b,0x6ef6)))
SAVES = ['r14','r13','r12','r11','r10','r9','r8','fr15','fr14','fr13','fr12']
SAVE_INDICES = [14,13,12,11,10,9,8,36,35,34,33,16]


def verify_contact_init_sample(sample, image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid contact-init caller'
    entry=canonical(sample['entry'])
    assert entry in CALLERS, 'unsupported contact-init caller'
    before=struct.unpack('<63I',sample['before'])
    after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'contact-init integer saves/stack changed'
    assert before[33:37]==after[33:37], 'contact-init FR saves changed'
    assert before[18]==after[18], 'contact-init FPSCR changed'
    assert canonical(sample['exitpc'])==entry+4 and canonical(after[16])==entry+4, 'missing contact-init BSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal contact-init opcode'
    expected=[(entry,CALLERS[entry]),(entry+2,0x64e3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing contact-init BSR, register delay or save prefix'
    d=CALLERS[entry]&4095
    d=d-4096 if d&2048 else d
    assert entry+4+d*2==PARENT, 'wrong contact-init target'
    original_pools(sample,image,ops)
    assert any(ops[i:i+len(RESTORE)]==list(RESTORE) for i in range(len(ops))), 'missing ordered contact-init restoration'
    assert ops[-2:]==[(0x8c03c4dc,0x000b),(0x8c03c4de,0xf3fd)], 'missing matrix-pop return'
    index=ops.index(RESTORE[-1]);assert ops[index+1]==(0x8c03c4a0,0xd30f), 'wrong tail target'
    assert sum(pair==RESTORE[2] for pair in ops)==1, 'repeated contact-init PR restoration'
    for i,index in enumerate(SAVE_INDICES):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'contact-init saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_contact_init(owner, attribution, spans, corpus, image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported contact-init callable'
    assert min(a for a,z in spans)==OWNER, 'wrong contact-init frozen owner'
    assert attribution.get('call_sites')==[hex(p) for p in CALLERS], 'wrong contact-init caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong contact-init save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal contact-init body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete contact-init prefix or frozen body'
    for i,op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i)==op, 'unsupported contact-init prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing native contact-init save proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native contact-init integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native contact-init FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_contact_init_sample)
    return PARENT,set(ops)
