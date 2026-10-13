"""Fixed original callers for four RAM callbacks, with real argument frames."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical,image_bytes,captured_bytes,require_original_scenarios,checked_reference
from callable_geometry import original_pools
from callable_component_update import DISPATCH,TABLE,TABLE_POOL

KIND='vf3-small-ram-callers-v1'
# owner: (entry, caller start, call, RTS, returned, saved registers)
ROWS={
 0x8c0885d8:(0x8c0885c4,0x8c088794,0x8c0887b2,0x8c0886fa,0x8c0887b6,[14,13,12,11,10,36,35,16]),
 0x8c07b6f4:(0x8c07b6f4,0x8c07bbaa,0x8c07bbac,0x8c07b718,0x8c07bbb0,[16]),
 0x8c08c054:(0x8c08c054,0x8c08be1e,0x8c08be20,0x8c08c0f0,0x8c08be24,[16]),
 0x8c0860c6:(0x8c0860c2,0x8c08b46e,0x8c08b4ae,0x8c086124,0x8c08b4b2,[14,16])}
PREFIXES={
 0x8c0885c4:(0x2fe6,0x6e53,0x2fd6,0x2fc6,0x6c43,0x2fb6,0x6b73,0x2fa6,0xfffb,0xffeb,0x4f22),
 0x8c07b6f4:(0x4f22,),0x8c08c054:(0x4f22,),
 0x8c0860c2:(0x2fe6,0x6e43,0x4f22)}

def verify_small_ram_sample(sample,image):
    assert not sample['flags'] and sample['nstate']==63 and not sample['device'],'invalid RAM caller'
    rows=[(owner,*row) for owner,row in ROWS.items() if canonical(sample['entry'])==row[1]]
    assert len(rows)==1,'unknown RAM caller'
    owner,entry,start,call,rts,returned,saves=rows[0]
    before,after=[struct.unpack('<63I',sample[k]) for k in ('before','after')]
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal RAM caller instruction'
    original_pools(sample,image,ops)
    if owner==0x8c0860c6:
        assert before[14]==11 and before[12] in (4,8) and before[8]==0,'wrong initializer component index/phase'
        assert captured_bytes(sample,before[15]+4,4)==bytes(4),'unexpected component filter'
        record=TABLE+28*10;slot=record+before[12]
        assert captured_bytes(sample,record,28)==captured_bytes(sample,record,28,True)==image_bytes(image,record,28),'modified initializer component record'
        assert image_bytes(image,slot,4)==struct.pack('<I',entry&0x1fffffff),'wrong immutable initializer target'
        assert image_bytes(image,TABLE_POOL,4)==struct.pack('<I',TABLE),'wrong component base'
        expected=list(DISPATCH)
        assert after[14]==record and after[10]==TABLE and after[11]==entry&0x1fffffff,'lost original component loader state'
        saved=list(before);saved[14]=record
        entry_sp=before[15]
        assert after[15]==before[15],'initializer stack changed'
    else:
        expected=[(pc,struct.unpack('<H',image_bytes(image,pc,2))[0]) for pc in range(start,call+4,2)]
        saved=list(before);entry_sp=before[15]-(12 if owner==0x8c0885d8 else 0)
        assert after[8:15]==before[8:15] and after[15]==entry_sp,'RAM callee saves or argument stack changed'
        if owner==0x8c0885d8:
            assert before[18]&0x180000==0,'unsupported motion float precision'
            # Original setup pushes object+32, object+33, object+28.
            assert captured_bytes(sample,entry_sp,12,True)==struct.pack('<3I',before[14]+28,before[14]+33,before[14]+32),'wrong original motion stack arguments'
            assert after[35:53]==before[35:53],'motion floating saves changed'
        elif owner==0x8c07b6f4:
            assert image_bytes(image,0xc07bd0c,4)==struct.pack('<I',entry&0x1fffffff),'wrong literal retirement target'
    # Explicitly establish each original branch/call target and delay slot.
    call_op=struct.unpack('<H',image_bytes(image,call,2))[0]
    if call_op>>12==0xb:
        delta=call_op&4095
        if delta&2048:delta-=4096
        assert call+4+2*delta==entry,'wrong original BSR target'
    elif owner==0x8c07b6f4:assert call_op==0x420b and expected[:2]==[(start,0xd258),(call,0x420b)]
    else:assert call_op==0x4b0b
    expected += [(entry+2*i,op) for i,op in enumerate(PREFIXES[entry])]
    assert ops[:len(expected)]==expected,'missing original arguments, call, delay or saves'
    delay=0x6ef6 if owner in (0x8c0860c6,0x8c0885d8) else 9
    assert ops[-2:]==[(rts,11),(rts+2,delay)],'missing real RTS and restoration delay'
    assert canonical(sample['exitpc'])==returned and canonical(after[16])==returned,'wrong original return'
    saved[16]=returned&0x1fffffff
    for i,reg in enumerate(saves):
        actual=struct.unpack('<I',captured_bytes(sample,entry_sp-4*(i+1),4,True))[0]
        assert actual==saved[reg],'wrong original saved stack slot'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()

def validate_small_ram(owner,attribution,spans,corpus,image):
    assert owner in ROWS and attribution['kind']==KIND
    entry,start,call,rts,returned,saves=ROWS[owner]
    assert attribution['entry']==hex(entry) and attribution['call_sites']==[hex(call)]
    assert attribution['dispatch_start']==hex(start),'wrong declared caller'
    assert attribution['callee_save_prefix']==[f'r{i}' if i<16 else f'fr{i-21}' for i in saves if i!=16]
    ops={canonical(int(pc,16)):int(op,16) for pc,op in json.loads((Path(corpus)/f'f_{entry:08x}.ops.json').read_text()).items()}
    required=set(range(entry,owner,2))|{pc for a,z in spans for pc in range(a,z,2)}
    assert required<=ops.keys(),'incomplete RAM prefix or frozen body'
    for pc,op in ops.items():assert image_bytes(image,pc,2)==struct.pack('<H',op),'nonoriginal RAM body opcode'
    for i,op in enumerate(PREFIXES[entry]):assert ops.get(entry+2*i)==op,'wrong RAM callable prefix'
    for line in (Path(corpus)/f'f_{entry:08x}.cases').read_text().splitlines():
        v=[int(x,16) for x in line.split()[:74]]
        assert len(v)==74 and v[8:16]==v[45:53],'native RAM saves or stack changed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_small_ram_sample)
    from oracle.capsules import records
    states=set()
    for ref in attribution['original_caller_manifests']:
        manifest=json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            if any(canonical(s['entry'])==start for s in records(Path(run['capsule']))):states.add(run['state'])
    assert len(states)>=2,'callback lacks original callers in two states'
    return entry,set(ops)
