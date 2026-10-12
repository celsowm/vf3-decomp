"""Verify the original selection parent tail, complete save prefix and return."""
import hashlib
import json
from pathlib import Path
import struct
from oracle.capsules import records
from callable_dispatch import canonical, checked_reference, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

START=0x8c0c31de
ENTRY=0x8c0c3210
OWNER=0x8c0c321e
RTS=0x8c0c38c2
KIND='vf3-original-selection-tail-v1'
PREFIX=(0xa017,0x6ef6,0x2fe6,0x2fd6,0x2fc6,0x2fb6,0x2fa6,0x2f96,0x2f86,0x4f22)


def verify_selection_sample(sample,image):
    assert sample['flags']==0 and sample['nstate']==63 and not sample['device'],'invalid original selection tail'
    assert canonical(sample['entry'])==START
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    saved14,=struct.unpack('<I',captured_bytes(sample,before[15],4))
    expected=[(START,0xa017),(START+2,0x6ef6)]+[(ENTRY+2*n,op) for n,op in enumerate(PREFIX[2:])]
    assert [(canonical(pc),op) for pc,op in sample['ops'][:10]]==expected,'missing original tail or seven-register save prefix'
    assert [(canonical(pc),op) for pc,op in sample['ops'][-2:]]==[(RTS,0xb),(RTS+2,0x6ef6)],'missing actual selection RTS/delay'
    assert canonical(sample['exitpc'])==canonical(before[16]) and after[16]==before[16],'wrong tail return'
    assert after[8:14]==before[8:14] and after[14]==saved14 and after[15]==before[15]+4,'wrong original caller frame'
    assert captured_bytes(sample,before[15],4,after=True)==struct.pack('<I',saved14)
    savedpr,=struct.unpack('<I',captured_bytes(sample,before[15]-28,4,after=True))
    assert savedpr==before[16],'callee saved another return'
    original_pools(sample,image,sample['ops'])
    for pc,op in sample['ops']:assert image_bytes(image,canonical(pc),2)==struct.pack('<H',op),'nonoriginal selection instruction'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_selection_unlock(owner,attribution,spans,corpus,image):
    assert owner==OWNER and attribution['kind']==KIND and int(attribution['entry'],16)==ENTRY
    assert attribution['call_sites']==[hex(START)] and min(a for a,z in spans)==OWNER
    ops=json.loads((Path(corpus)/f'f_{ENTRY:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    required={ENTRY+2*n for n in range(7)}|{canonical(pc) for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(),'incomplete selection body/save prefix'
    for n,op in enumerate(PREFIX[2:]):assert ops[ENTRY+2*n]==op
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op)
    refs=attribution['original_caller_manifests'];require_original_scenarios(refs,image,verify_selection_sample)
    count=0;states=set();fingerprints=set()
    for ref in refs:
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            samples=list(records(checked_reference({'path':run['capsule'],'sha256':run['capsule_sha256']})))
            assert len(samples)==1
            fingerprints.add(verify_selection_sample(samples[0],image));count+=1
            path=Path(run['state'])
            if not path.is_absolute():path=Path(__file__).resolve().parents[1]/path
            with path.open('rb') as handle:states.add(hashlib.file_digest(handle,'sha256').hexdigest())
    assert count>=8 and len(states)>=2 and len(fingerprints)>=2,'need eight original tail windows in two independent states'
