"""Prove the fixed scene-57 table transfer and the predicate's saved frame."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import (canonical, image_bytes, captured_bytes, require_original_scenarios,
                              DISPATCH, DISPATCH_OPS, TABLE, SCENE, checked_reference)
from callable_geometry import original_pools
from oracle.capsules import records

ENTRY = 0x8c0993e0
OWNER = 0x8c0993e8
INDEX = 57
PREFIX = (0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x4f22)
RESTORE = tuple((0x8c099488+2*n,op) for n,op in enumerate(
    (0x7f04,0xd211,0x4f26,0x6bf6,0x6cf6,0x6df6,0x422b,0x6ef6)))
KIND = 'vf3-scene-input-index57-v1'


def verify_scene_input_sample(sample,image):
    assert sample['flags']==0 and sample['nstate']==63 and not sample['device']
    assert canonical(sample['entry'])==DISPATCH
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16] and before[18]==after[18], 'scene caller saves changed'
    assert canonical(sample['exitpc'])==canonical(before[16]) and after[16]==before[16]
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    expected=[(DISPATCH+2*n,op) for n,op in enumerate(DISPATCH_OPS)]
    expected += [(ENTRY+2*n,op) for n,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected, 'missing scene dispatcher or save prefix'
    assert captured_bytes(sample,SCENE+10,1)==bytes([INDEX])
    slot=TABLE+4*INDEX
    assert image_bytes(image,slot,4)==struct.pack('<I',ENTRY&0x1fffffff)
    assert captured_bytes(sample,slot,4)==captured_bytes(sample,slot,4,True)==image_bytes(image,slot,4)
    for pc,op,wanted in ((DISPATCH,DISPATCH_OPS[0],SCENE),(DISPATCH+28,DISPATCH_OPS[14],TABLE)):
        pool=((pc+4)&~3)+4*(op&255)
        assert image_bytes(image,pool,4)==struct.pack('<I',wanted)
    for pc,op in ops:assert image_bytes(image,pc,2)==struct.pack('<H',op)
    original_pools(sample,image,ops)
    starts=[n for n,pair in enumerate(ops) if pair==RESTORE[0]]
    assert len(starts)==1
    at=starts[0]
    assert ops[at:at+8]==list(RESTORE) and ops[at+8][0]==0x8c097ff4
    assert ops[-2:]==[(0x8c09803c,0xb),(0x8c09803e,0x9)]
    for n,register in enumerate((14,13,12,11,16)):
        saved,=struct.unpack('<I',captured_bytes(sample,before[15]-4*(n+1),4,True))
        assert saved==before[register], 'wrong saved scene frame word'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_scene_input(owner,attribution,spans,corpus,image):
    assert owner==OWNER and attribution['kind']==KIND and int(attribution['entry'],16)==ENTRY
    assert min(a for a,z in spans)==OWNER
    assert attribution['call_sites']==['0x8c0968f4'] and attribution['table']==hex(TABLE) and attribution['index']==INDEX
    assert attribution['callee_save_prefix']==['r14','r13','r12','r11']
    ops=json.loads((Path(corpus)/f'f_{ENTRY:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    required=set(range(ENTRY,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys()
    for n,op in enumerate(PREFIX):assert ops[ENTRY+2*n]==op
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op)
    refs=attribution['original_caller_manifests']
    require_original_scenarios(refs,image,verify_scene_input_sample)
    count=0
    for ref in refs:
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            samples=list(records(checked_reference(dict(path=run['capsule'],sha256=run['capsule_sha256']))))
            assert len(samples)==1
            verify_scene_input_sample(samples[0],image);count+=1
    assert count>=8, 'need eight original scene table windows'
