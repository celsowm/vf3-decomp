"""Fixed original arena-bound BSR, register delay, saves and return contract."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT = 0x8c0cb51e
OWNER = 0x8c0cb532
CALLERS = {0x8c0cb028: 0xb279}
PREFIX = (0x2fd6,0x2fc6,0xec06,0x2fb6,0x66c3,0x2fa6,0x2f96,
          0xfffb,0xffdb,0x9012,0x4f22)
RESTORE = tuple((0x8c0cb640+2*i,op) for i,op in enumerate(
    (0x7f0c,0x4f26,0x9033,0xf437,0x2472,0xfdf9,0xfff9,
     0x69f6,0x6af6,0x6bf6,0x6cf6,0x000b,0x6df6)))
SAVES = ['r13','r12','r11','r10','r9','fr15','fr13']

def verify_ring_bound_sample(sample, image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid ring-bound caller'
    entry=canonical(sample['entry'])
    assert entry in CALLERS, 'unsupported ring-bound caller'
    before=struct.unpack('<63I',sample['before'])
    after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'ring-bound integer saves/stack changed'
    assert before[34:37]==after[34:37], 'ring-bound FR saves changed'
    assert before[37:53]==after[37:53], 'ring-bound XF changed'
    assert before[18]==after[18], 'ring-bound FPSCR changed'
    assert canonical(sample['exitpc'])==entry+4 and canonical(after[16])==entry+4, 'missing ring-bound BSR return'
    assert before[14]!=before[4] and 0x0c000000<=(before[14]&0x1fffffff)<0x0d000000, 'missing register-delay actor'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal ring-bound opcode'
    expected=[(entry,CALLERS[entry]),(entry+2,0x64e3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing ring-bound BSR, register delay or save prefix'
    d=CALLERS[entry]&4095
    d=d-4096 if d&2048 else d
    assert entry+4+d*2==PARENT, 'wrong ring-bound target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered ring-bound restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated ring-bound PR restoration'
    for i,index in enumerate([13,12,11,10,9,36,34,16]):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'ring-bound saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_ring_bound(owner, attribution, spans, corpus, image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported ring-bound callable'
    assert min(a for a,z in spans)==OWNER, 'wrong ring-bound frozen owner'
    assert attribution.get('call_sites')==[hex(p) for p in CALLERS], 'wrong ring-bound caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong ring-bound save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal ring-bound body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete ring-bound prefix or frozen body'
    for i,op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i)==op, 'unsupported ring-bound prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing native ring-bound save proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native ring-bound integer saves changed'
        assert v[34:37]==v[71:74] and v[18]==v[55], 'native ring-bound FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_ring_bound_sample)
    return PARENT,set(ops)
