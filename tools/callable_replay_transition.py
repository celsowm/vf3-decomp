"""Attribute the three replay helpers to complete original scene-57 windows."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import checked_reference, canonical, image_bytes, require_original_scenarios
from oracle.capsules import records
from oracle.replay_transition_caller_audit import verify as verify_caller

KIND = 'vf3-scene-replay-helpers-index57-v1'
DEFINITIONS = {
    0x8c099544: (0x8c099540, (0x902f, 0xd41f, 0x4f22), (), 0x8c09947a),
    0x8c099568: (0x8c099560, (0x2fe6, 0xe054, 0x2fd6, 0x2fc6, 0x4f22), (14, 13, 12), 0x8c09955c),
    0x8c0a91e6: (0x8c0a91da, (0x2fe6, 0xe054, 0x2fd6, 0x2fc6, 0x2fb6, 0xde2e, 0x4f22), (14, 13, 12, 11), 0x8c09954e),
}


def verify_sample(sample, image):
    verify_caller(sample, image)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+before
        for base,before,after in sample['pages'])).hexdigest()


def validate_replay_transition(owner, attribution, spans, corpus, image):
    assert owner in DEFINITIONS and attribution['kind'] == KIND
    entry, words, saved, caller = DEFINITIONS[owner]
    assert int(attribution['entry'], 16) == entry
    assert attribution['call_sites'] == [hex(caller)]
    assert attribution['callee_save_prefix'] == [f'r{number}' for number in saved]
    assert attribution['scene_index'] == 57 and attribution['scene_table'] == '0xc10baa8'
    assert min(start for start, end in spans) == owner
    ops = json.loads((Path(corpus)/f'f_{entry:08x}.ops.json').read_text())
    ops = {canonical(int(pc,16)): int(op,16) for pc,op in ops.items()}
    required = set(range(entry, owner, 2)) | {pc for start,end in spans for pc in range(start,end,2)}
    assert required <= ops.keys(), 'incomplete helper prefix or owner body'
    for n, op in enumerate(words):
        assert ops[entry+2*n] == op, 'helper entry sequence changed'
    for pc, op in ops.items():
        assert image_bytes(image, pc, 2) == struct.pack('<H',op), 'nonoriginal helper opcode'
    refs = attribution['original_caller_manifests']
    require_original_scenarios(refs, image, verify_sample)
    count = 0
    for ref in refs:
        manifest = json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            raw = checked_reference(dict(path=run['capsule'], sha256=run['capsule_sha256']))
            samples = list(records(raw)); assert len(samples) == 1
            verify_caller(samples[0], image); count += 1
    assert count >= 8, 'need eight original complete helper caller windows'
    for line in (Path(corpus)/f'f_{entry:08x}.cases').read_text().splitlines():
        values = [int(value,16) for value in line.split()[:74]]
        assert len(values) == 74 and values[15] == values[52] and values[16] == values[53]
        for number in (saved or (14,13,12)):
            assert values[number] == values[number+37], 'helper save/restore invariant failed'
    return entry, set(ops)
