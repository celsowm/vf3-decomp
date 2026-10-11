"""Fixed two-BSR polygon entry, stack arguments and integer/FR saves."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical,image_bytes,captured_bytes,require_original_scenarios
from callable_geometry import original_pools
PARENT=0x8c06e056
OWNER=0x8c06e066
CALLERS={0x8c06dfb6:0xb04e,0x8c06e048:0xb005}
PREFIX=(0x2fe6,0xe004,0x2fd6,0x6e53,0xfffb,0xffeb,0xffdb,0xffcb,0x4f22)
RESTORE=((0x8c06e194,0x7f18),(0x8c06e196,0x4f26),(0x8c06e198,0xf33a),
         (0x8c06e19a,0xfcf9),(0x8c06e19c,0xfdf9),(0x8c06e19e,0xfef9),
         (0x8c06e1a0,0xfff9),(0x8c06e1a2,0x6df6),(0x8c06e1a4,0x000b),(0x8c06e1a6,0x6ef6))
SAVES=['r14','r13','fr15','fr14','fr13','fr12']
def verify_polygon_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63,'invalid polygon caller state'
    entry=canonical(sample['entry']);assert entry in CALLERS,'unsupported polygon caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16],'polygon integer saves/stack changed'
    assert before[33:53]==after[33:53],'polygon FR saves or XF changed'
    assert before[18]==after[18],'polygon FPSCR changed'
    assert canonical(sample['exitpc'])==entry+4 and canonical(after[16])==entry+4,'missing polygon BSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal polygon opcode'
    expected=[(entry,CALLERS[entry]),(entry+2,0x54f8)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected,'missing polygon BSR, stack-load delay or save prefix'
    d=CALLERS[entry]&4095;d=d-4096 if d&2048 else d
    assert entry+4+d*2==canonical(PARENT),'wrong polygon target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE),'missing ordered polygon restoration'
    assert sum(p==RESTORE[1] for p in ops)==1,'repeated polygon PR restoration'
    # The real delay slot loads R4 from the caller frame, with a sentinel
    # incoming R4. The original callee then saves the actual BSR return PC.
    actor=struct.unpack('<I',captured_bytes(sample,before[15]+32,4))[0]
    assert actor!=before[4] and 0x0c000000<=(actor&0x1fffffff)<0x0d000000,'missing stack-based polygon actor'
    for i,index in enumerate([14,13,36,35,34,33,16]):
        expected_value=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==expected_value,'polygon saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()
def validate_polygon_hit(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT,'unsupported polygon callable'
    assert min(a for a,z in spans)==OWNER,'wrong polygon frozen owner'
    assert attribution.get('call_sites')==[hex(p) for p in CALLERS],'wrong polygon callers'
    assert attribution.get('callee_save_prefix')==SAVES,'wrong polygon save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal polygon body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(),'incomplete polygon prefix or frozen body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op,'unsupported polygon prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases,'missing polygon native proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53],'native polygon integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55],'native polygon FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_polygon_sample)
    return PARENT,set(ops)
