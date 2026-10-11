"""Fixed single-BSR vector aggregation entry, stack arguments and integer/FR saves."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical,image_bytes,captured_bytes,require_original_scenarios
from callable_geometry import original_pools
PARENT=0x8c0a6ff8
OWNER=0x8c0a700a
CALLERS={0x8c0a6df2:0xb101}
PREFIX=(0x2fe6,0xe004,0x2fd6,0x6e43,0x2fc6,0xfffb,0xffeb,0xffdb,0xffcb,0x4f22)
RESTORE=((0x8c0a7176,0x7f40),(0x8c0a7178,0x4f26),(0x8c0a717a,0xf33a),
         (0x8c0a717c,0xfcf9),(0x8c0a717e,0xfdf9),(0x8c0a7180,0xfef9),
         (0x8c0a7182,0xfff9),(0x8c0a7184,0x6cf6),(0x8c0a7186,0x6df6),
         (0x8c0a7188,0x000b),(0x8c0a718a,0x6ef6))
SAVES=['r14','r13','r12','fr15','fr14','fr13','fr12']
def verify_vector_sum_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63,'invalid vector_sum caller state'
    entry=canonical(sample['entry']);assert entry in CALLERS,'unsupported vector_sum caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16],'vector_sum integer saves/stack changed'
    assert before[33:37]==after[33:37],'vector_sum FR saves changed'
    assert before[18]==after[18],'vector_sum FPSCR changed'
    assert canonical(sample['exitpc'])==entry+4 and canonical(after[16])==entry+4,'missing vector_sum BSR return'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal vector_sum opcode'
    expected=[(entry,CALLERS[entry]),(entry+2,0x54fa)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected,'missing vector_sum BSR, stack-load delay or save prefix'
    d=CALLERS[entry]&4095;d=d-4096 if d&2048 else d
    assert entry+4+d*2==canonical(PARENT),'wrong vector_sum target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE),'missing ordered vector_sum restoration'
    assert sum(p==RESTORE[1] for p in ops)==1,'repeated vector_sum PR restoration'
    # The real delay slot loads R4 from the caller frame, with a sentinel
    # incoming R4. The original callee then saves the actual BSR return PC.
    actor=struct.unpack('<I',captured_bytes(sample,before[15]+40,4))[0]
    assert actor!=before[4] and 0x0c000000<=(actor&0x1fffffff)<0x0d000000,'missing stack-based vector_sum actor'
    count=struct.unpack('<I',captured_bytes(sample,before[5],4))[0]
    if count:
        configured=struct.unpack('<16I',captured_bytes(sample,actor+16,64))
        assert after[37:49]==configured[:12] and after[52]==configured[15],'wrong installed vector_sum basis'
        assert after[49:52]==before[49:52],'vector_sum translation changed'
    else:
        assert before[37:53]==after[37:53],'empty vector_sum changed XF'
    for i,index in enumerate([14,13,12,36,35,34,33,16]):
        expected_value=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==expected_value,'vector_sum saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()
def validate_vector_sum_hit(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT,'unsupported vector_sum callable'
    assert min(a for a,z in spans)==OWNER,'wrong vector_sum frozen owner'
    assert attribution.get('call_sites')==[hex(p) for p in CALLERS],'wrong vector_sum callers'
    assert attribution.get('callee_save_prefix')==SAVES,'wrong vector_sum save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal vector_sum body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(),'incomplete vector_sum prefix or frozen body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op,'unsupported vector_sum prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases,'missing vector_sum native proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53],'native vector_sum integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55],'native vector_sum FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_vector_sum_sample)
    return PARENT,set(ops)
