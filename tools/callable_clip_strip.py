"""Verify the real command-table caller and return for RAM strip parents."""
import hashlib
import json
from pathlib import Path
import struct
from oracle.capsules import records
from callable_dispatch import canonical, checked_reference, image_bytes, captured_bytes, require_original_scenarios
from callable_geometry import original_pools

START=0x8c055788
CALL=0x8c055794
RETURN=0x8c055798
TABLE=0x0c055aa0
ROWS={
    16:(0x8c0570e0,0x8c0572aa),17:(0x8c057480,0x8c05764e),
    18:(0x8c057c60,0x8c057e2a),19:(0x8c057860,0x8c057a32),20:(0x8c057fa0,0x8c05816a)
}
PREFIX=(0x6041,0x4011,0x600c,0x8f07,0x4008,0x03ee,0x430b,0x0009)
KIND='vf3-original-strip-command-v1'


def verify_strip_sample(sample,image):
    assert sample['flags']==0 and sample['nstate']==63 and not sample['device'],'invalid strip caller specimen'
    assert canonical(sample['entry'])==START and canonical(sample['exitpc'])==RETURN
    before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
    assert before[14]==TABLE,'another command table'
    slot,=struct.unpack('<H',captured_bytes(sample,before[4],2))
    assert slot in ROWS,'unsupported strip command'
    entry,rts=ROWS[slot]
    assert canonical(struct.unpack('<I',image_bytes(image,TABLE+slot*4,4))[0])==entry
    assert captured_bytes(sample,TABLE+slot*4,4)==image_bytes(image,TABLE+slot*4,4),'patched dispatch table'
    expected=[(START+2*i,op) for i,op in enumerate(PREFIX)]+[(entry,0x2fe6),(entry+2,0x4f22)]
    assert [(canonical(pc),op) for pc,op in sample['ops'][:len(expected)]]==expected,'wrong original command dispatch'
    assert [(canonical(pc),op) for pc,op in sample['ops'][-2:]]==[(rts,0x000b),(rts+2,0x6ef6)],'missing actual strip RTS/delay slot'
    assert after[15]==before[15] and after[14]==before[14] and after[18]==before[18],'changed caller frame'
    assert canonical(after[16])==RETURN and before[58]==after[58]==0x0c16b8c8,'wrong inherited publication contract'
    assert after[3]==after[58]
    assert struct.unpack('<I',captured_bytes(sample,after[58],4,after=True))[0]==after[12],'stream publication missing'
    saved_return,saved_table=struct.unpack('<2I',captured_bytes(sample,before[15]-8,8,after=True))
    assert canonical(saved_return)==RETURN and saved_table==TABLE,'wrong original saved frame'
    # The table base is the constructor's literal +128, published at GBR+12.
    constructor={0x0c055da0:0xe380,0x0c055da4:0x633c,0x0c055da6:0xd20e,
                 0x0c055dae:0x6023,0x0c055db0:0x303c,0x0c055db2:0xc203}
    for pc,op in constructor.items():assert image_bytes(image,pc,2)==struct.pack('<H',op),'changed original constructor'
    assert struct.unpack('<I',image_bytes(image,0x0c055de0,4))[0]+128==TABLE
    original_pools(sample,image,sample['ops'])
    for pc,op in sample['ops']:assert image_bytes(image,canonical(pc),2)==struct.pack('<H',op),'nonoriginal caller opcode'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_clip_strip(owner,attribution,spans,corpus,image):
    entry=owner-2
    row=next((row for row in ROWS.values() if row[0]==entry),None)
    assert row and attribution['kind']==KIND and int(attribution['entry'],16)==entry
    assert attribution['call_sites']==[hex(CALL)] and min(a for a,z in spans)==owner
    ops=json.loads((Path(corpus)/f'f_{entry|0x80000000:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    required={entry}|{canonical(pc) for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys() and ops[entry]==0x2fe6,'incomplete parent body/save prefix'
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op)
    refs=attribution['original_caller_manifests'];require_original_scenarios(refs,image,verify_strip_sample)
    count=0;states=set();fingerprints=set()
    for ref in refs:
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            samples=list(records(checked_reference({'path':run['capsule'],'sha256':run['capsule_sha256']})))
            assert len(samples)==1
            sample=samples[0];before=struct.unpack('<63I',sample['before'])
            slot,=struct.unpack('<H',captured_bytes(sample,before[4],2))
            if ROWS[slot][0]!=entry:continue
            count+=1;fingerprints.add(verify_strip_sample(sample,image))
            path=Path(run['state'])
            if not path.is_absolute():path=Path(__file__).resolve().parents[1]/path
            with path.open('rb') as handle:states.add(hashlib.file_digest(handle,'sha256').hexdigest())
    assert count>=8 and len(states)>=2 and len(fingerprints)>=2,'need eight owner-specific original callers in two states'
