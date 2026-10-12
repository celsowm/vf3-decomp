"""Prove scene index 54, round-frame restoration and the original audio tail."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, require_original_scenarios, checked_reference, DISPATCH, DISPATCH_OPS, TABLE, SCENE
from callable_geometry import original_pools
from oracle.capsules import records

ENTRY=0x8c098c62
OWNER=0x8c098c70
KIND='vf3-scene-round-index54-v1'
PREFIX=(0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0x2f96,0x2f86,0x4f22)
RESTORE=tuple((0x8c09901a+2*n,op) for n,op in enumerate(
    (0x7f1c,0x84cb,0x4f26,0x7001,0x80cb,0x68f6,0x69f6,0x6af6,0x6bf6,0x6cf6,0x6df6,0xa016,0x6ef6)))
AUDIO_TAIL=tuple((0x8c09914e+2*n,op) for n,op in enumerate((0x4f26,0xd30f,0x6df6,0x432b,0x6ef6)))


def verify_scene_round_sample(sample,image):
    assert sample['flags']==0 and sample['nstate']==63 and not sample['device']
    assert canonical(sample['entry'])==DISPATCH
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[8:16]==after[8:16] and before[16]==after[16]
    assert before[18]==after[18]
    # The record callback performs SH-4 integer division. Q/M/T are scratch
    # status bits; privilege, bank, interrupt mask and the remaining SR bits
    # must retain their original values. Native replay compares all SR bits.
    changed_sr=before[17]^after[17]
    assert not changed_sr&~0x301
    assert canonical(sample['exitpc'])==canonical(before[16])
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    if changed_sr&0x300:
        assert any(op==0x0019 or op&0xf00f in (0x2007,0x3004) for pc,op in ops),'division status changed without a division instruction'
    expected=[(DISPATCH+2*n,op) for n,op in enumerate(DISPATCH_OPS)]+[(ENTRY+2*n,op) for n,op in enumerate(PREFIX)]
    assert ops[:len(expected)]==expected,'missing dispatcher or seven-register save prefix'
    assert captured_bytes(sample,SCENE+10,1)==bytes([54])
    slot=TABLE+4*54;wanted=struct.pack('<I',ENTRY&0x1fffffff)
    assert image_bytes(image,slot,4)==captured_bytes(sample,slot,4)==captured_bytes(sample,slot,4,True)==wanted
    for pool,value in ((0x8c096934,SCENE),(0x8c096938,0x80000000),(0x8c09693c,TABLE)):
        assert image_bytes(image,pool,4)==struct.pack('<I',value)
    for pc,op in ops:assert image_bytes(image,pc,2)==struct.pack('<H',op)
    original_pools(sample,image,ops)
    positions=[n for n,pair in enumerate(ops) if pair==RESTORE[0]];assert len(positions)==1
    at=positions[0];assert ops[at:at+len(RESTORE)]==list(RESTORE)
    assert ops[at+len(RESTORE):at+len(RESTORE)+2]==[(0x8c099060,0x2fe6),(0x8c099062,0x2fd6)]
    positions=[n for n,pair in enumerate(ops) if pair==AUDIO_TAIL[0]];assert len(positions)==1
    at=positions[0];assert ops[at:at+len(AUDIO_TAIL)]==list(AUDIO_TAIL)
    assert ops[at+len(AUDIO_TAIL)][0]==0x8c097ff4
    assert image_bytes(image,0x8c099190,4)==captured_bytes(sample,0x8c099190,4)==struct.pack('<I',0x0c097ff4)
    assert ops[-2:]==[(0x8c09803c,0xb),(0x8c09803e,9)]
    # The audio tail legitimately reuses the restored caller stack; final
    # stack contents are not the round frame's original saved-word array.
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_scene_round(owner,attribution,spans,corpus,image):
    assert owner==OWNER and attribution['kind']==KIND and int(attribution['entry'],16)==ENTRY
    assert min(a for a,z in spans)==OWNER
    assert attribution['call_sites']==['0x8c0968f4'] and attribution['table']==hex(TABLE) and attribution['index']==54
    assert attribution['callee_save_prefix']==['r14','r13','r12','r11','r10','r9','r8']
    ops=json.loads((Path(corpus)/f'f_{ENTRY:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    required=set(range(ENTRY,OWNER,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys()
    for n,op in enumerate(PREFIX):assert ops[ENTRY+2*n]==op
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op)
    refs=attribution['original_caller_manifests'];require_original_scenarios(refs,image,verify_scene_round_sample)
    count=0
    for ref in refs:
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            samples=list(records(checked_reference(dict(path=run['capsule'],sha256=run['capsule_sha256']))))
            assert len(samples)==1;verify_scene_round_sample(samples[0],image);count+=1
    assert count>=8
