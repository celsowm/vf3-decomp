"""Fixed original scene-table entries for clock and replay/history callbacks."""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes, DISPATCH, DISPATCH_OPS, TABLE, SCENE
from callable_geometry import original_pools

ROWS = {
    53: (0x8c098b3c, 0x8c098b40, (0x2fe6, 0x2fd6, 0x4f22)),
    56: (0x8c099194, 0x8c0991a2, (0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x2fa6, 0x2f96, 0x2f86, 0x4f22)),
}


def sequence(start, words):
    return tuple((start+2*i, word) for i, word in enumerate(words))


RESTORES = {
    53: (
        sequence(0x8c098c3c, (0x7f08, 0x4f26, 0x6df6, 0xa9d7, 0x6ef6)),
        sequence(0x8c098c4e, (0x52f1, 0x7f08, 0x4f26, 0x842b, 0x7001, 0x802b, 0x6df6, 0xd334, 0x432b, 0x6ef6))),
    56: (
        sequence(0x8c0992e0, (0x7f0c, 0x4f26, 0xe010, 0x80bb, 0x68f6, 0xd338, 0x69f6, 0x6af6, 0x6bf6, 0x6cf6, 0x6df6, 0x432b, 0x6ef6)),
        sequence(0x8c099304, (0x7f0c, 0x9056, 0x4f26, 0xe301, 0x0e34, 0xe00d, 0x80bb, 0x68f6, 0x69f6, 0x6af6, 0x6bf6, 0x6cf6, 0x6df6, 0xa0ec, 0x6ef6)),
        sequence(0x8c099392, (0x7f0c, 0x1b43, 0x4f26, 0xe31f, 0xe010, 0x0b34, 0x84bb, 0x7001, 0x80bb, 0x68f6, 0x69f6, 0x6af6, 0x6bf6, 0x6cf6, 0x6df6, 0xa016, 0x6ef6))),
}
TAIL_TARGETS = {0x8c098c3c: 0x8c097ff4, 0x8c098c4e: 0x8c0968d0,
                0x8c0992e0: 0x8c097ff4, 0x8c099304: 0x8c0994fa,
                0x8c099392: 0x8c0993e0}


def verify_scene_replay_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid scene replay caller'
    assert canonical(sample['entry']) == DISPATCH, 'wrong original scene dispatch start'
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    assert not before[18]&0x180000, 'unsupported scene replay float mode'
    index = captured_bytes(sample, SCENE+10, 1)[0]
    assert index in ROWS, 'unsupported scene replay index'
    entry, _, prefix = ROWS[index]
    slot = TABLE+4*index
    assert image_bytes(image, slot, 4) == struct.pack('<I', entry&0x1fffffff), 'wrong original scene replay slot'
    assert captured_bytes(sample, slot, 4) == captured_bytes(sample, slot, 4, True) == image_bytes(image, slot, 4), 'patched scene replay table slot'
    for pool, value in ((0x0c096934, SCENE), (0x0c096938, 0x80000000), (0x0c09693c, TABLE)):
        assert image_bytes(image, pool, 4) == struct.pack('<I', value), 'wrong original scene replay dispatch pool'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal scene replay opcode'
    expected = list(sequence(DISPATCH, DISPATCH_OPS))+list(sequence(entry, prefix))
    assert ops[:len(expected)] == expected, 'missing scene replay dispatch, tail jump or save prefix'
    matches = []
    for restoration in RESTORES[index]:
        for at, pair in enumerate(ops):
            if pair == restoration[0]:
                assert ops[at:at+len(restoration)] == list(restoration), 'altered scene replay restoration or tail'
                matches.append((at, restoration))
    assert len(matches) == 1, 'missing or repeated scene replay root restoration'
    at, restoration = matches[0]
    assert at+len(restoration) < len(ops), 'missing scene replay tail destination'
    # Verify the original BRA target or immutable JMP pool at this fixed tail.
    branch_pc, branch = restoration[-2]
    if branch>>12 == 10:
        displacement = branch&4095
        if displacement&2048: displacement -= 4096
        target = branch_pc+4+2*displacement
    else:
        assert branch in (0x432b,), 'unsupported scene replay root tail jump'
        load_pc, load = next(pair for pair in reversed(restoration[:-2]) if pair[1]>>12 == 13)
        pool = ((load_pc+4)&~3)+4*(load&255)
        target = canonical(struct.unpack('<I', image_bytes(image, pool, 4))[0])
    assert target == TAIL_TARGETS[restoration[0][0]], 'altered original scene replay tail target'
    assert ops[at+len(restoration)][0] == target, 'wrong original scene replay tail destination'
    assert canonical(sample['exitpc']) == canonical(before[16]) and after[16] == before[16], 'wrong scene replay outer return'
    assert before[8:16] == after[8:16], 'scene replay integer saves/stack changed'
    assert before[18] == after[18] and before[17]&~1 == after[17]&~1, 'scene replay FPSCR or noncondition SR changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
