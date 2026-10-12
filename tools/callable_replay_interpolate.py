"""Original replay interpolation argument setup, BSR, saves and return."""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes
from callable_geometry import original_pools

START = 0x8c0a9062
CALL = 0x8c0a9066
RETURN = CALL+4
PARENT = 0x8c0a8f8c
OWNER = 0x8c0a8f98
PREFIX = (0x2fe6, 0x6e53, 0x2fd6, 0x6d43, 0x906b, 0xe700, 0x4f22)
RESTORE = tuple((0x8c0a902c+2*i, op) for i, op in enumerate(
    (0x7f10, 0x4f26, 0x6df6, 0x000b, 0x6ef6)))


def verify_replay_interpolate_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid interpolation caller'
    assert canonical(sample['entry']) == START, 'wrong interpolation caller start'
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    assert not before[18]&0x180000, 'unsupported interpolation float mode'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal interpolation opcode'
    expected = [(START+2*i, op) for i, op in enumerate((0x56f1, 0x65e3, 0xbf91, 0x64d3))]
    expected += [(PARENT+2*i, op) for i, op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing interpolation stack argument, actor, BSR or saves'
    assert CALL+4+2*(0xf91-0x1000) == PARENT, 'wrong interpolation BSR destination'
    assert ops[-len(RESTORE):] == list(RESTORE), 'missing ordered interpolation restoration'
    assert sum(pair == RESTORE[1] for pair in ops) == 1, 'repeated interpolation PR restore'
    assert canonical(sample['exitpc']) == RETURN and canonical(after[16]) == RETURN, 'wrong interpolation BSR return'
    assert before[8:16] == after[8:16], 'interpolation integer saves/stack changed'
    assert before[18] == after[18] and before[17]&~1 == after[17]&~1, 'interpolation FPSCR or noncondition SR changed'
    assert image_bytes(image, 0x0c0a906e, 2) == struct.pack('<H', 0x1fb8), 'wrong original actor replay field'
    assert image_bytes(image, 0x0c0a907c, 4) == struct.pack('<I', 0x0c09f036), 'wrong interpolation actor update helper'
    assert image_bytes(image, 0x0c0a9080, 4) == struct.pack('<I', 0x0c09ea66), 'wrong interpolation actor finalize helper'
    for i, index in enumerate((14, 13, 16)):
        wanted = RETURN&0x1fffffff if index == 16 else before[index]
        assert captured_bytes(sample, before[15]-4*(i+1), 4, True) == struct.pack('<I', wanted), 'interpolation saved stack slot changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
