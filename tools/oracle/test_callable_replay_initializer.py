"""Reject forged installed targets and either initializer return shape."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_replay_initializer as cp


def fixture(mode):
    image = bytearray(0x100000)
    ops = [(cp.START+2*i, op) for i, op in enumerate((0x60e2, 0xc801, 0x8902, 0x53e3, 0x430b, 0x64e3))]
    ops += [(cp.PARENT+2*i, op) for i, op in enumerate(cp.PREFIX)]
    if mode:
        ops += list(cp.HISTORY_TAIL)+[(cp.HISTORY+2*i, op) for i, op in enumerate(cp.HISTORY_PREFIX)]
        ops += list(cp.HISTORY_RESTORE)
        indices = (14, 13, 12, 11, 10, 16)
    else:
        ops += list(cp.FAST_RESTORE)
        indices = (16, 14)
    for pc, op in [*ops, *cp.INSTALLER]: struct.pack_into('<H', image, pc-0x8c010000, op)
    struct.pack_into('<5H', image, 0x0c09690a-0x0c010000, 0x6042, 0xcb01, 0x2402, 0x000b, 0x1453)
    for pool, target in ((0x0c098ac8, cp.PARENT&0x1fffffff), (0x0c098acc, 0x0c09690a),
                         (0x0c0a8434, 0x0c0c6742), (0x0c0a843c, cp.HISTORY&0x1fffffff)):
        struct.pack_into('<I', image, pool-0x0c010000, target)
    before = list(range(63)); before[14], before[15], before[18] = 0x0c500000, 0x0c590100, 0x240001
    after = list(before); after[16] = cp.RETURN&0x1fffffff
    pre = bytearray(4096); struct.pack_into('<I', pre, 0, 1); struct.pack_into('<I', pre, 12, cp.PARENT&0x1fffffff)
    post = bytearray(pre)
    if mode: struct.pack_into('<I', post, 12, cp.HISTORY&0x1fffffff)
    stack = bytearray(4096)
    for i, reg in enumerate(indices): struct.pack_into('<I', stack, 0x100-4*(i+1), after[reg])
    modes = bytearray(4096); struct.pack_into('<I', modes, cp.MODE&4095, mode)
    pages = [(0x0c500000, bytes(pre), bytes(post)), (0x0c590000, bytes(4096), bytes(stack)),
             (cp.MODE&~4095, bytes(modes), bytes(modes))]
    for base in (0x0c096000, 0x0c098000, 0x0c0a8000):
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096]); pages.append((base, data, data))
    return image, dict(entry=cp.START, exitpc=cp.RETURN, flags=0, nstate=63,
        before=struct.pack('<63I', *before), after=struct.pack('<63I', *after), ops=ops, pages=pages), indices


class ReplayInitializerCallerTests(unittest.TestCase):
    def test_original_direct_and_history_tail(self):
        for mode in (0, 1):
            image, sample, _ = fixture(mode)
            self.assertEqual(len(cp.verify_replay_initializer_sample(sample, image)), 64)

    def test_missing_ordered_instruction(self):
        for mode in (0, 1):
            image, sample, _ = fixture(mode)
            for position in range(len(sample['ops'])):
                bad = copy.deepcopy(sample); del bad['ops'][position]
                with self.subTest(mode=mode, position=position), self.assertRaises(AssertionError):
                    cp.verify_replay_initializer_sample(bad, image)

    def test_forged_instruction_even_if_image_agrees(self):
        for mode in (0, 1):
            image, sample, _ = fixture(mode)
            for position in range(len(sample['ops'])):
                changed_image = bytearray(image); bad = copy.deepcopy(sample)
                pc, op = bad['ops'][position]; bad['ops'][position] = (pc, op^1)
                struct.pack_into('<H', changed_image, pc-0x8c010000, op^1)
                with self.subTest(mode=mode, position=position), self.assertRaises(AssertionError):
                    cp.verify_replay_initializer_sample(bad, changed_image)

    def test_wrong_installer_or_registrar(self):
        for pc in [*(pc for pc, _ in cp.INSTALLER), 0x8c09690a, 0x8c098ac8, 0x8c098acc]:
            image, sample, _ = fixture(1); image[pc-0x8c010000] ^= 1
            with self.subTest(pc=hex(pc)), self.assertRaises(AssertionError):
                cp.verify_replay_initializer_sample(sample, image)

    def test_wrong_descriptor_or_callback_transition(self):
        for mode in (0, 1):
            for after in (False, True):
                image, sample, _ = fixture(mode)
                base, pre, post = sample['pages'][0]
                data = bytearray(post if after else pre); data[12] ^= 1
                sample['pages'][0] = (base, pre, bytes(data)) if after else (base, bytes(data), post)
                with self.subTest(mode=mode, after=after), self.assertRaises(AssertionError):
                    cp.verify_replay_initializer_sample(sample, image)
        image, sample, _ = fixture(1); base, pre, post = sample['pages'][0]
        pre = bytearray(pre); pre[0] = 0; sample['pages'][0] = (base, bytes(pre), post)
        with self.assertRaises(AssertionError): cp.verify_replay_initializer_sample(sample, image)

    def test_corrupted_saved_frame(self):
        for mode in (0, 1):
            image, sample, indices = fixture(mode)
            for position in range(len(indices)):
                bad = copy.deepcopy(sample); base, pre, post = bad['pages'][1]
                post = bytearray(post); post[0x100-4*(position+1)] ^= 1; bad['pages'][1] = (base, pre, bytes(post))
                with self.subTest(mode=mode, position=position), self.assertRaises(AssertionError):
                    cp.verify_replay_initializer_sample(bad, image)

    def test_corrupted_architecture_or_return(self):
        for mode in (0, 1):
            for reg in (*range(8, 21), *range(33, 53)):
                image, sample, _ = fixture(mode); after = bytearray(sample['after'])
                struct.pack_into('<I', after, reg*4, 0xffffffff); sample['after'] = bytes(after)
                with self.subTest(mode=mode, reg=reg), self.assertRaises(AssertionError):
                    cp.verify_replay_initializer_sample(sample, image)


if __name__ == '__main__': unittest.main()
