"""Fixed original SDK clipping callers and their complete saved frames."""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes
from callable_geometry import original_pools

# Callable, literal slot, caller's MOV.L, restore start (including frame pop).
CALLERS = {
    0x8c05152c: (0x0c057288, 0x8c05725e, 0x8c051700),
    0x8c051918: (0x0c0566cc, 0x8c0566a2, 0x8c051b0c),
    0x8c051c2c: (0x0c05762c, 0x8c057602, 0x8c051e00),
    0x8c05228c: (0x0c057a10, 0x8c0579e6, 0x8c052460),
    0x8c0525c0: (0x0c056e8c, 0x8c056e62, 0x8c0527b4),
    0x8c05291c: (0x0c058148, 0x8c058120, 0x8c052af0),
    0x8c052c34: (0x0c057e08, 0x8c057de0, 0x8c052e08),
}
STRIDES = {0x8c05152c: 2, 0x8c051918: 2, 0x8c051c2c: 6,
           0x8c05228c: 2, 0x8c0525c0: 2, 0x8c05291c: 10, 0x8c052c34: 6}
SAVE_INDICES = (10, 9, 14, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
                *range(36, 20, -1), 16)
PREFIX = tuple(0x2f06+(reg<<4) for reg in SAVE_INDICES[:16])
PREFIX += tuple(0xff0b+(reg<<4) for reg in range(15, -1, -1)) + (0x4f22,)
RESTORE = (0xe101, 0x4118, 0x3f1c, 0x4f26)
RESTORE += tuple(0xf0f9+(reg<<8) for reg in range(16))
RESTORE += tuple(0x60f6+(reg<<8) for reg in (*range(12), 13, 14, 9, 10)) + (0x000b, 0x0009)


def verify_clip_triangle_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid clipping caller'
    start = canonical(sample['entry'])
    rows = [(entry, row) for entry, row in CALLERS.items() if row[1] == start]
    assert len(rows) == 1, 'unsupported original clipping caller'
    entry, (pool, load, restore) = rows[0]
    stride = STRIDES[entry]
    assert image_bytes(image, entry+0x4e, 2) == struct.pack('<H', 0x7800+stride), 'wrong clipping strip stride'
    returned = load+6
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    assert not before[18] & 0x180000, 'unsupported clipping float width or precision'
    displacement = (canonical(pool)-((load+4)&~3))//4
    assert ((load+4)&~3)+4*displacement == canonical(pool), 'invalid clipping pool alignment'
    assert 0 <= displacement <= 255, 'invalid clipping literal displacement'
    assert image_bytes(image, pool, 4) == struct.pack('<I', entry&0x1fffffff), 'wrong original clipping target'
    assert captured_bytes(sample, pool, 4) == captured_bytes(sample, pool, 4, True) == image_bytes(image, pool, 4), 'patched clipping target pool'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal clipping opcode'
    expected = [(load, 0xd200+displacement), (load+2, 0x420b), (load+4, 0x6403)]
    expected += [(entry+2*i, op) for i, op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing clipping literal load, JSR, argument or complete saves'
    restoration = [(restore+2*i, op) for i, op in enumerate(RESTORE)]
    assert ops[-len(restoration):] == restoration, 'missing clipping complete ordered restoration'
    assert sum(pair == restoration[3] for pair in ops) == 1, 'repeated clipping PR restoration'
    assert canonical(sample['exitpc']) == returned and canonical(after[16]) == returned, 'wrong clipping JSR return'
    assert after[17]&~1 == before[17]&~1, 'clipping noncondition SR bits changed'
    saved = list(before)
    saved[2], saved[4], saved[16] = entry&0x1fffffff, before[0], returned&0x1fffffff
    for reg in (*range(12), 13, 14, 15, *range(21, 53), 18, 19, 20, 54, *range(55, 63)):
        assert after[reg] == saved[reg], 'clipping saved architectural state changed'
    increment = after[12]-before[12]
    assert increment in (0, 96, 128), 'invalid clipping stream advancement'
    if increment:
        assert captured_bytes(sample, after[12]-32, 4, True) == struct.pack('<I', before[59]), 'missing clipping banked end-of-strip command'
    for i, reg in enumerate(SAVE_INDICES):
        actual = struct.unpack('<I', captured_bytes(sample, before[15]-4*(i+1), 4, True))[0]
        # The inner duplicate R10/R9 slots become the third/second strip
        # cursors; the outer copies preserve the original caller registers.
        wanted = before[8]+2*stride if i == 5 else before[8]+stride if i == 6 else saved[reg]
        assert actual == wanted, 'clipping saved frame slot changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
