"""Two fixed original radial-correction BSRs and exact integer save prefix."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0cb67a
OWNER=0x8c0cb69e
CALLERS={0x8c0cb66a:(0xb006,0x0009),0x8c0cb66e:(0xb004,0x64f2)}
PREFIX=(0x2fd6,0x2fc6,0xec04,0x2fb6,0xeb06,0x2fa6,0x65b3,0x2f96,
        0x9011,0x9712,0x094e,0xc70d,0xfa08,0xc70d,0xf108,0xc70d,
        0x9d0a,0x374c,0x4f22)
RESTORE=tuple((0x8c0cb760+2*i,op) for i,op in enumerate(
    (0x4f26,0x69f6,0x6af6,0x6bf6,0x6cf6,0x000b,0x6df6)))
SAVES=['r13','r12','r11','r10','r9']

def verify_radial_bound_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid radial-bound caller'
    entry=canonical(sample['entry']);assert entry in CALLERS, 'unsupported radial-bound caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'radial-bound integer saves/stack changed'
    assert before[33:53]==after[33:53], 'radial-bound FR saves or XF changed'
    assert before[18]==after[18], 'radial-bound FPSCR changed'
    assert canonical(sample['exitpc'])==entry+4 and canonical(after[16])==entry+4, 'missing radial-bound BSR return'
    if entry==0x8c0cb66e:
        actor=struct.unpack('<I',captured_bytes(sample,before[15],4))[0]
        assert actor!=before[4], 'missing stack-delay radial actor'
    else:actor=before[4]
    assert 0x0c000000<=(actor&0x1fffffff)<0x0d000000, 'invalid radial-bound actor'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal radial-bound opcode'
    call,delay=CALLERS[entry]
    expected=[(entry,call),(entry+2,delay)]+[(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing radial-bound BSR, delay or prefix'
    d=call&4095;d=d-4096 if d&2048 else d
    assert entry+4+d*2==PARENT, 'wrong radial-bound target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered radial-bound restoration'
    assert sum(pair==RESTORE[0] for pair in ops)==1, 'repeated radial-bound PR restoration'
    for i,index in enumerate([13,12,11,10,9,16]):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'radial-bound saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_radial_bound(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported radial-bound callable'
    assert min(a for a,z in spans)==OWNER, 'wrong radial-bound frozen owner'
    assert attribution.get('call_sites')==[hex(p) for p in CALLERS], 'wrong radial-bound caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong radial-bound save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal radial-bound body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete radial-bound prefix or body'
    for i,op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i)==op, 'unsupported radial-bound prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing radial-bound native proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native radial-bound integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native radial-bound FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_radial_bound_sample)
    return PARENT,set(ops)
