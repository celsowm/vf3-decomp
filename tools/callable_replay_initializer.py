"""Original installed initializer callback, descriptor JSR and history tail."""
import hashlib
import struct
from callable_dispatch import canonical, image_bytes, captured_bytes
from callable_geometry import original_pools
from callable_history_record import CALLER as HISTORY_TAIL, PREFIX as HISTORY_PREFIX
from callable_history_record import PARENT as HISTORY, RESTORE as HISTORY_RESTORE

START = 0x8c09617c
CALL = START+8
RETURN = CALL+4
PARENT = OWNER = 0x8c0a8370
MODE = 0x0c29ba30
INSTALLER = ((0x8c098a32, 0xd326), (0x8c098a34, 0xe050),
             (0x8c098a36, 0xd524), (0x8c098a38, 0x430b), (0x8c098a3a, 0x04de))
PREFIX = (0x4f22, 0xd330, 0x7ffc, 0x430b, 0x2f42)
FAST_RESTORE = ((0x8c0a83ba, 0x7f04), (0x8c0a83bc, 0x4f26),
                (0x8c0a83be, 0x000b), (0x8c0a83c0, 0x0009))


def verify_replay_initializer_sample(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63, 'invalid initializer caller'
    assert canonical(sample['entry']) == START, 'wrong initializer descriptor caller'
    before = struct.unpack('<63I', sample['before'])
    after = struct.unpack('<63I', sample['after'])
    assert not before[18]&0x180000, 'unsupported initializer float mode'
    descriptor = before[14]
    assert struct.unpack('<I', captured_bytes(sample, descriptor, 4))[0]&1, 'inactive initializer descriptor'
    assert captured_bytes(sample, descriptor+12, 4) == struct.pack('<I', PARENT&0x1fffffff), 'wrong installed initializer callback'
    for pc, op in INSTALLER:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'wrong original initializer installer'
    for pool, target in ((0x0c098ac8, PARENT&0x1fffffff), (0x0c098acc, 0x0c09690a),
                         (0x0c0a8434, 0x0c0c6742), (0x0c0a843c, HISTORY&0x1fffffff)):
        assert image_bytes(image, pool, 4) == struct.pack('<I', target), 'wrong original initializer pool'
    assert image_bytes(image, 0x0c09690a, 10) == struct.pack('<5H', 0x6042, 0xcb01, 0x2402, 0x000b, 0x1453), 'wrong original descriptor registrar'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal initializer opcode'
    expected = [(START+2*i, op) for i, op in enumerate((0x60e2, 0xc801, 0x8902, 0x53e3, 0x430b, 0x64e3))]
    expected += [(PARENT+2*i, op) for i, op in enumerate(PREFIX)]
    assert ops[:len(expected)] == expected, 'missing initializer predicate, callback load, JSR, argument or prefix'
    assert canonical(sample['exitpc']) == RETURN and canonical(after[16]) == RETURN, 'wrong initializer JSR return'
    assert before[8:16] == after[8:16] and before[33:53] == after[33:53], 'initializer integer/FR saves or stack changed'
    assert before[18:21] == after[18:21] and before[17]&~1 == after[17]&~1, 'initializer FPSCR/MAC or noncondition SR changed'
    mode = struct.unpack('<I', captured_bytes(sample, MODE, 4))[0]
    if mode:
        target = HISTORY&0x1fffffff
        assert captured_bytes(sample, descriptor+12, 4, True) == struct.pack('<I', target), 'initializer did not install original history callback'
        tail = list(HISTORY_TAIL)+[(HISTORY+2*i, op) for i, op in enumerate(HISTORY_PREFIX)]
        positions = [i for i, pair in enumerate(ops) if pair == tail[0]]
        assert len(positions) == 1 and ops[positions[0]:positions[0]+len(tail)] == tail, 'missing original callback installation and history tail'
        assert ops[-len(HISTORY_RESTORE):] == list(HISTORY_RESTORE), 'missing history-tail ordered restore'
        for i, reg in enumerate((14, 13, 12, 11, 10, 16)):
            wanted = RETURN&0x1fffffff if reg == 16 else before[reg]
            assert captured_bytes(sample, before[15]-4*(i+1), 4, True) == struct.pack('<I', wanted), 'initializer history-tail saved frame changed'
    else:
        assert captured_bytes(sample, descriptor+12, 4, True) == struct.pack('<I', PARENT&0x1fffffff), 'inactive-mode initializer callback changed'
        assert ops[-len(FAST_RESTORE):] == list(FAST_RESTORE), 'missing initializer direct restore'
        for offset, wanted in ((4, RETURN&0x1fffffff), (8, descriptor)):
            assert captured_bytes(sample, before[15]-offset, 4, True) == struct.pack('<I', wanted), 'initializer direct saved frame changed'
    original_pools(sample, image, ops)
    return hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+a for base, a, _ in sample['pages'])).hexdigest()
