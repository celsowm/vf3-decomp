"""Fixed literal JSR and register setup for the aggregation frame owner."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

PARENT=0x8c0a6dba
OWNER=0x8c0a6dc0
LOAD=0x8c0a0cf8
CALL=LOAD+4
RETURN=LOAD+8
POOL=0x0c0a0d88
PREFIX=(0x2fe6,0x2fd6,0xfffb,0x4f22)
RESTORE=((0x8c0a6fc2,0x7f38),(0x8c0a6fc4,0x4f26),
         (0x8c0a6fc6,0xfff9),(0x8c0a6fc8,0x6df6),
         (0x8c0a6fca,0x000b),(0x8c0a6fcc,0x6ef6))
SAVES=['r14','r13','fr15']

def verify_aggregate_frame_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63, 'invalid aggregation caller'
    assert canonical(sample['entry'])==LOAD, 'unsupported aggregation caller'
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16], 'aggregation integer saves/stack changed'
    assert before[33:53]==after[33:53], 'aggregation FR saves or XF changed'
    assert before[18]==after[18], 'aggregation FPSCR changed'
    assert canonical(sample['exitpc'])==RETURN and canonical(after[16])==RETURN, 'missing aggregation JSR return'
    assert before[4]!=before[14] and before[5]!=before[10], 'missing original register argument setup'
    for pointer in [before[14],before[10]]:
        assert 0x0c000000<=(pointer&0x1fffffff)<0x0d000000, 'invalid aggregation actor or rows'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal aggregation opcode'
    expected=[(LOAD,0xd323),(LOAD+2,0x65a3),(CALL,0x430b),(CALL+2,0x64e3)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing aggregation literal, arguments, JSR or save prefix'
    assert ((LOAD+4)&~3)+4*0x23==canonical(POOL), 'wrong aggregation literal slot'
    assert image_bytes(image,POOL,4)==struct.pack('<I',PARENT&0x1fffffff), 'wrong aggregation loaded target'
    original_pools(sample,image,ops)
    assert ops[-len(RESTORE):]==list(RESTORE), 'missing ordered aggregation restoration'
    assert sum(pair==RESTORE[1] for pair in ops)==1, 'repeated aggregation PR restoration'
    for i,index in enumerate([14,13,36,16]):
        wanted=after[16] if index==16 else before[index]
        actual=struct.unpack('<I',captured_bytes(sample,before[15]-4*(i+1),4,True))[0]
        assert actual==wanted, 'aggregation saved stack slot changed'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_aggregate_frame(owner,attribution,spans,corpus,image):
    assert owner==OWNER and int(attribution['entry'],16)==PARENT, 'unsupported aggregation callable'
    assert min(a for a,z in spans)==OWNER, 'wrong aggregation owner'
    assert attribution.get('call_sites')==[hex(CALL)] and attribution.get('literal_pool')==hex(POOL), 'wrong aggregation caller declaration'
    assert attribution.get('callee_save_prefix')==SAVES, 'wrong aggregation save declaration'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op), 'nonoriginal aggregation body opcode'
    required=set(range(PARENT,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(), 'incomplete aggregation prefix or body'
    for i,op in enumerate(PREFIX):assert ops.get(PARENT+2*i)==op, 'unsupported aggregation prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines();assert cases, 'missing native aggregation proof'
    for line in cases:
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53], 'native aggregation integer saves changed'
        assert v[33:37]==v[70:74] and v[18]==v[55], 'native aggregation FR/FPSCR changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_aggregate_frame_sample)
    return PARENT,set(ops)
