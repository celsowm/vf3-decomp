"""Prove original resource-record dispatch for actor registration wrappers."""
import hashlib
import json
from pathlib import Path
import struct
from callable_dispatch import canonical, captured_bytes, image_bytes, require_original_scenarios
from callable_geometry import original_pools

KIND = 'vf3-resource-table-setters-v1'
START, CALL, RETURN = 0x8c0a2f3c, 0x8c0a2f40, 0x8c0a2f44
TABLE = 0x0c10def0
ROWS = {0x8c0a3246: (0x8c0a3242, 11), 0x8c0a3508: (0x8c0a3504, 24),
        0x8c0a38b2: (0x8c0a38ae, 13), 0x8c0a3af6: (0x8c0a3af2, 1)}
ROWS.update({
    0x8c0a4668:(0x8c0a4664,16),0x8c0a4d40:(0x8c0a4d3c,19),
    0x8c0a575c:(0x8c0a5758,15),0x8c0a5b54:(0x8c0a5b50,8),
    0x8c0a5d9c:(0x8c0a5d98,21),0x8c0a3e22:(0x8c0a3e1e,14),
    0x8c0a52f0:(0x8c0a52ec,2),0x8c0a4414:(0x8c0a4410,3),
    0x8c0a423e:(0x8c0a423a,18),0x8c0a4b62:(0x8c0a4b5e,6),
    0x8c0a61fe:(0x8c0a61fa,7),0x8c0a40b0:(0x8c0a40ac,5),
    0x8c0a4872:(0x8c0a486e,4),0x8c0a49e6:(0x8c0a49e2,17),
    0x8c0a4f00:(0x8c0a4efc,12),0x8c0a506c:(0x8c0a5068,25),
    0x8c0a5f56:(0x8c0a5f52,10),0x8c0a609e:(0x8c0a609a,23)})


def verify_actor_table_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63 and not sample['device'], 'invalid resource caller'
    assert canonical(sample['entry']) == START and canonical(sample['exitpc']) == RETURN+4
    before, after = [struct.unpack('<63I', sample[k]) for k in ('before', 'after')]
    record = struct.unpack('<I', captured_bytes(sample, before[15], 4))[0]
    selected = [(owner, entry, index) for owner, (entry, index) in ROWS.items()
                if record == TABLE+36*index]
    assert len(selected) == 1, 'unknown original resource record'
    owner, entry, index = selected[0]
    original = image_bytes(image, record, 36)
    # Only the dispatch descriptor and callback words participate in this
    # window. Row 7 crosses a page boundary, and the observer correctly
    # captures only the page containing those original words. Do not invent
    # capture evidence for the row's unused leading fields.
    assert captured_bytes(sample, record+24, 8) == captured_bytes(sample, record+24, 8, True) == original[24:32], 'modified immutable resource record'
    descriptor, callback = struct.unpack_from('<2I', original, 24)
    assert before[13] == descriptor and canonical(callback) == entry, 'wrong descriptor or callback input'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    prefix = [(START+2*n, op) for n, op in enumerate((0x62f2, 0x5327, 0x430b, 0x64d3))]
    prefix += [(entry+2*n, op) for n, op in enumerate((0x2fe6, 0x5e44, 0x4f22))]
    assert ops[:len(prefix)] == prefix, 'missing real JSR, delay slot or callable prefix'
    from body_cover import body_spans
    wrapper = {canonical(pc) for a, z in body_spans()[owner] for pc in range(a, z, 2)
               if not 0x8c0a2e06 <= pc < 0x8c0a2e2c}
    assert wrapper <= {pc for pc, _ in ops}, 'incomplete resource wrapper in caller window'
    rts = 0x8c0951ce if owner in (0x8c0a5b54,0x8c0a5d9c) else 0x8c0a2e28
    assert ops[-4:] == [(rts, 11), (rts+2, 9),
                        (RETURN, 0x60e3), (RETURN+2, 0x8808)], 'missing actual RTS and caller continuation'
    assert before[13:16] == after[13:16] and canonical(after[16]) == RETURN, 'unbalanced original caller frame'
    # The actor-profile tail pops the wrapper frame, then its two real
    # calls reuse those slots. Check the second pass's saved zero argument
    # and PR rather than
    # pretending the original R14 save survives this legitimate reuse.
    frame = (0, RETURN & 0x1fffffff) if owner in (0x8c0a5b54,0x8c0a5d9c) else (RETURN & 0x1fffffff,before[14])
    assert struct.unpack('<2I', captured_bytes(sample, before[15]-8, 8, True)) == frame, 'wrong saved frame'
    # The parent constructs the record from the low resource index, with the
    # original x36 shift/add sequence and immutable base literal.
    constructor = (0x6de3, 0x4d08, 0x4d00, 0x63e3, 0x3d3c, 0xd214,
                   0x4d08, 0x66e3, 0x6ddf, 0x3d2c, 0x4600, 0x2fd2)
    for n, op in enumerate(constructor):
        assert image_bytes(image, 0x8c0a2f14+2*n, 2) == struct.pack('<H', op)
    assert image_bytes(image, 0x8c0a2f70, 4) == struct.pack('<I', TABLE)
    assert record == TABLE+36*index
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal caller instruction'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a
                           for base, a, _ in sample['pages'])).hexdigest()


def validate_actor_table(owner, attribution, spans, corpus, image):
    assert owner in ROWS and attribution['kind'] == KIND
    entry, index = ROWS[owner]
    assert int(attribution['entry'], 16) == entry and attribution['index'] == index
    assert attribution['call_sites'] == [hex(CALL)] and int(attribution['table'], 16) == TABLE
    assert attribution['callee_save_prefix'] == ['r14']
    ops = {canonical(int(pc, 16)): int(op, 16) for pc, op in json.loads(
        (Path(corpus)/f'f_{entry:08x}.ops.json').read_text()).items()}
    required = {entry, entry+2} | {canonical(pc) for a, z in spans for pc in range(a, z, 2)}
    assert required <= ops.keys(), 'incomplete resource prefix or body'
    for pc, op in ops.items():
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal resource instruction'
    for line in (Path(corpus)/f'f_{entry:08x}.cases').read_text().splitlines():
        values = [int(value, 16) for value in line.split()[:74]]
        assert len(values) == 74 and values[14:16] == values[51:53], 'resource callee frame changed'
    # Every declaration is tied to its own callback, in two original states.
    def selected(sample, image):
        result = verify_actor_table_sample(sample, image)
        before = struct.unpack('<63I', sample['before'])
        record = struct.unpack('<I', captured_bytes(sample, before[15], 4))[0]
        return result if record == TABLE+36*index else None
    # The shared caller manifest covers all four wrappers. The general
    # provenance gate checks all samples, then require this owner's two states.
    require_original_scenarios(attribution['original_caller_manifests'], image,
                               verify_actor_table_sample)
    from oracle.capsules import records
    from callable_dispatch import checked_reference
    states = set()
    for ref in attribution['original_caller_manifests']:
        manifest = json.loads(checked_reference(ref).read_text())
        for run in manifest['runs']:
            if any(selected(sample, image) for sample in records(Path(run['capsule']))):
                states.add(run['state'])
    assert len(states) >= 2, 'owner lacks two original caller states'
    return entry, set(ops)
