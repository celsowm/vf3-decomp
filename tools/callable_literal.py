"""Original constant-target JSR contract for the selection-input callable."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import (canonical, image_bytes, captured_bytes,
                               require_original_scenarios)

PARENT = 0x8c0c9f54
OWNER = 0x8c0c9f62
LOAD = 0x8c0c9208
CALL = LOAD + 2
RETURN = CALL + 4
POOL = 0x0c0c926c
PREFIX = (0xd734,0x9059,0xd632,0x047d,0x9057,0x9357,0x066e,0x4f22)


def verify_literal_sample(sample, image):
    assert not sample['flags'], 'invalid literal caller invocation'
    assert sample['nstate'] == 63, 'incomplete original architectural state'
    assert canonical(sample['entry']) == LOAD, 'wrong literal-load entry'
    before=struct.unpack(f'<{sample["nstate"]}I',sample['before'])
    after=struct.unpack(f'<{sample["nstate"]}I',sample['after'])
    assert before[13:16] == after[13:16], 'literal caller save/stack invariant failed'
    assert sample['exitpc'] == RETURN+16 and after[16] == RETURN, 'missing actual JSR return and continuation boundary'
    ops=[(canonical(pc),op) for pc,op in sample['ops']]
    for pc,op in ops:
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal literal caller opcode'
    expected=[(LOAD,0xd218),(CALL,0x420b),(CALL+2,9)]
    expected += [(PARENT+2*i,op) for i,op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing literal-loaded JSR or full prefix'
    assert ((LOAD+4)&~3)+4*0x18 == canonical(POOL), 'wrong PC-relative literal slot'
    assert captured_bytes(sample,POOL,4) == captured_bytes(sample,POOL,4,True) == image_bytes(image,POOL,4) == struct.pack('<I',PARENT&0x1fffffff), 'modified constant JSR target'
    for pc,op in expected[3:]:
        if op >> 12 in (0x9,0xd):
            size=2 if op >> 12 == 9 else 4
            pool=pc+4+2*(op&255) if size == 2 else ((pc+4)&~3)+4*(op&255)
            assert captured_bytes(sample,pool,size) == captured_bytes(sample,pool,size,True) == image_bytes(image,pool,size), 'modified input prefix pool'
    restores={0x8c0c9fea,0x8c0ca004,0x8c0ca006}
    positions=[i for i,(pc,op) in enumerate(ops) if pc in restores and op == 0x4f26]
    assert len(positions) == 1, 'missing or repeated input PR restoration'
    at=positions[0]
    if ops[at][0] == 0x8c0ca004:
        assert at>0 and at+1<len(ops) and ops[at-1] == (0x8c0ca002,0xa02b) and ops[at+1] == (0x8c0ca05c,0xe061), 'wrong input style-tail restoration order'
    else:
        pc=ops[at][0]
        assert ops[at+1:at+3] == [(pc+2,0x000b),(pc+4,9)], 'wrong input return restoration order'
    returns = {0x8c0c9fec:9,0x8c0ca008:9,0x8c0c5db6:9,0x8c0c5df2:0x6ef6}
    assert len(ops)>=4 and ops[-4][0] in returns and ops[-4][1] == 0x000b, 'missing original RTS'
    assert ops[-3] == (ops[-4][0]+2,returns[ops[-4][0]]), 'missing original RTS delay slot'
    assert ops[-2:] == [(RETURN,0xa006),(RETURN+2,9)], 'missing original caller continuation branch'
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_input_literal(owner, attribution, spans, corpus, image):
    assert owner == OWNER and int(attribution['entry'],16) == PARENT, 'unsupported literal callable'
    assert min(s for s,e in spans) == OWNER and any(s <= owner < e for s,e in spans), 'wrong frozen input owner'
    assert attribution.get('call_sites') == [hex(CALL)] and attribution.get('literal_pool') == hex(POOL), 'wrong declared constant JSR edge'
    assert attribution.get('callee_save_prefix',[]) == [], 'unexpected input prefix save'
    ops=json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops={canonical(int(pc,16)):int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal input opcode'
    required=set(range(PARENT,OWNER,2)) | {pc for s,e in spans for pc in range(s,e,2)}
    assert required <= ops.keys(), 'incomplete input prefix or frozen body'
    for i,op in enumerate(PREFIX):
        assert ops.get(PARENT+2*i) == op, 'unsupported input prefix'
    cases=(Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing input save invariant evidence'
    for line in cases:
        values=[int(v,16) for v in line.split()[:74]]
        assert len(values) == 74 and values[13:16] == values[50:53], 'input save/stack invariant failed'
    require_original_scenarios(attribution['original_caller_manifests'],image,verify_literal_sample)
    return PARENT,set(ops)
