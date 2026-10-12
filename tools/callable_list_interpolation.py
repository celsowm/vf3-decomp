"""Original list interpolation literal-JSR, object argument and saved frame."""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes
from callable_geometry import original_pools

START = 0x8c090b76
CALL = START+2
RETURN = CALL+4
POOL = 0x0c090bc8
PARENT = 0x8c08f632
OWNER = 0x8c08f642
PREFIX = (0x2fe6, 0x6e43, 0x2fd6, 0x2fc6, 0xfffb, 0xffeb, 0xffdb, 0x902b, 0x4f22)
RESTORE = tuple((0x8c08f8a2+2*i, op) for i, op in enumerate((
    0x7f04, 0x9076, 0x4f26, 0xffd0, 0xfe07, 0x9073, 0xfef7,
    0xfdf9, 0xfef9, 0xfff9, 0x6cf6, 0x6df6, 0x000b, 0x6ef6)))


def verify_list_interpolation_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid list interpolation caller'
    assert canonical(sample['entry']) == START, 'wrong list interpolation caller start'
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    assert not before[18]&0x180000, 'unsupported list interpolation float mode'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal list interpolation opcode'
    expected = [(START, 0xd214), (CALL, 0x420b), (CALL+2, 0x64d3)]
    expected += [(PARENT+2*i, op) for i, op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing list literal, JSR, object argument or saves'
    assert ((START+4)&~3)+4*0x14 == canonical(POOL), 'wrong list interpolation literal displacement'
    assert image_bytes(image, POOL, 4) == struct.pack('<I', PARENT&0x1fffffff), 'wrong original list interpolation target'
    assert ops[-len(RESTORE):] == list(RESTORE), 'missing ordered list interpolation restoration'
    assert sum(pair == RESTORE[2] for pair in ops) == 1, 'repeated list interpolation PR restore'
    assert canonical(sample['exitpc']) == RETURN and canonical(after[16]) == RETURN, 'wrong list interpolation JSR return'
    assert before[8:16] == after[8:16] and before[34:37] == after[34:37], 'list interpolation saves/stack changed'
    assert before[18] == after[18] and before[17]&~1 == after[17]&~1, 'list interpolation FPSCR or noncondition SR changed'
    for i, index in enumerate((14, 13, 12, 36, 35, 34, 16)):
        wanted = RETURN&0x1fffffff if index == 16 else before[index]
        assert captured_bytes(sample, before[15]-4*(i+1), 4, True) == struct.pack('<I', wanted), 'list interpolation saved stack slot changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
