"""Original component-table index, update JSR, argument and balanced saves.

Only the two fixed component rows and the original mode-12 update path are
supported. This does not authorize arbitrary callbacks or altered tables.
"""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes
from callable_geometry import original_pools

START = 0x8c08b46e
CALL = 0x8c08b4ae
RETURN = CALL + 4
TABLE = 0x0c0f71d0
TABLE_POOL = 0x0c08b50c
ROWS = {
    2: (0x8c08acc0, 0x8c08acd8, 0x8c08af34, 0x7f14, 0xd132),
    11: (0x8c087e04, 0x8c087e1c, 0x8c08811e, 0x7f68, 0xd124),
}
DISPATCH = (
    (START, 0xda27), (START+2, 0xc727), (START+4, 0xa024),
    (START+6, 0xff08), (0x8c08b4be, 0x63ee), (0x8c08b4c0, 0x2338),
    (0x8c08b4c2, 0x8bd8), (0x8c08b476, 0x2888), (0x8c08b478, 0x8905),
    *tuple((0x8c08b486+2*i, op) for i, op in enumerate((
        0x60ee, 0x7eff, 0x6eee, 0xe31c, 0x2e3f, 0x4008, 0x09d6,
        0x52f1, 0x0e1a, 0x6eef, 0x3eac, 0x85ec, 0x6403, 0x2428,
        0x8b02, 0x60c3, 0x8810, 0x8903, 0x60c3, 0x0bee, 0x4b0b, 0x64d3))),
)
SAVE_INDICES = (14, 13, 12, 11, 10, 9, 8, 36, 35, 34, 33, 16)


def verify_component_update_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid component caller'
    assert canonical(sample['entry']) == START, 'wrong component dispatcher start'
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    index = before[14] - 1
    assert index in ROWS and before[12] == 12, 'unsupported component index or callback phase'
    assert not before[18] & 0x180000, 'unsupported component float width or precision'
    assert before[8] == 0, 'unexpected component distance-gating path'
    assert captured_bytes(sample, before[15]+4, 4) == bytes(4), 'unexpected component flag filter'
    entry, owner, restore, frame, pool_load = ROWS[index]
    record = TABLE + 28*index
    slot = record + 12
    wanted_target = struct.pack('<I', entry & 0x1fffffff)
    assert image_bytes(image, TABLE_POOL, 4) == struct.pack('<I', TABLE), 'wrong component table base pool'
    assert captured_bytes(sample, TABLE_POOL, 4) == captured_bytes(sample, TABLE_POOL, 4, True) == image_bytes(image, TABLE_POOL, 4), 'modified component table base'
    assert captured_bytes(sample, record, 28) == captured_bytes(sample, record, 28, True) == image_bytes(image, record, 28), 'modified component record'
    assert image_bytes(image, slot, 4) == wanted_target, 'wrong original component callback'
    prefix = (0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x2fa6, 0x2f96,
              0x2f86, 0xfffb, 0xffeb, 0xffdb, 0xffcb, pool_load, 0x4f22)
    assert owner == entry+24, 'wrong component owner boundary'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal component opcode'
    expected = list(DISPATCH) + [(entry+2*i, op) for i, op in enumerate(prefix)]
    assert ops[:len(expected)] == expected, 'missing component indexing, load, JSR, argument or saves'
    restoration = [(restore+2*i, op) for i, op in enumerate((
        frame, 0x4f26, 0xfcf9, 0xfdf9, 0xfef9, 0xfff9,
        0x68f6, 0x69f6, 0x6af6, 0x6bf6, 0x6cf6, 0x6df6, 0x000b, 0x6ef6))]
    assert ops[-len(restoration):] == restoration, 'missing ordered component restoration'
    assert sum(pair == restoration[1] for pair in ops) == 1, 'repeated component PR restoration'
    assert canonical(sample['exitpc']) == RETURN and canonical(after[16]) == RETURN, 'wrong component JSR return'
    assert after[17]&~1 == before[17]&~1, 'component noncondition SR bits changed'
    for reg in (8, 9, 12, 13, 15):
        assert after[reg] == before[reg], 'component caller saved register changed'
    assert after[10] == TABLE and after[11] == (entry & 0x1fffffff) and after[14] == record, 'component loader state not retained'
    assert after[33:36] == before[33:36] and after[18] == before[18], 'component FR/FPSCR saves changed'
    fr15 = struct.unpack('<I', image_bytes(image, 0x0c08b510, 4))[0]
    assert after[36] == fr15, 'component MOVA float setup not retained'
    saved = list(before)
    saved[10], saved[11], saved[14], saved[36], saved[16] = TABLE, entry & 0x1fffffff, record, fr15, RETURN & 0x1fffffff
    for i, reg in enumerate(SAVE_INDICES):
        actual = struct.unpack('<I', captured_bytes(sample, before[15]-4*(i+1), 4, True))[0]
        assert actual == saved[reg], 'component saved stack slot changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
