"""Reject altered scene slots, saved frames and fixed root tail sequences."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_scene_replay as cp


def fixture(index, shape=0):
    image = bytearray(0x100000)
    entry, _, prefix = cp.ROWS[index]
    restoration = cp.RESTORES[index][shape]
    target = cp.TAIL_TARGETS[restoration[0][0]]
    ops = list(cp.sequence(cp.DISPATCH, cp.DISPATCH_OPS))+list(cp.sequence(entry, prefix))
    ops += list(restoration)+[(target, 0x0009), (0x8c09803c, 0x000b), (0x8c09803e, 0x0009)]
    for pc, op in ops: struct.pack_into('<H', image, pc-0x8c010000, op)
    for pool, value in ((0x0c096934, cp.SCENE), (0x0c096938, 0x80000000), (0x0c09693c, cp.TABLE),
                        (cp.TABLE+4*index, entry&0x1fffffff)):
        struct.pack_into('<I', image, pool-0x0c010000, value)
    if restoration[-2][1]>>12 != 10:
        pc, op = next(pair for pair in reversed(restoration[:-2]) if pair[1]>>12 == 13)
        pool = ((pc+4)&~3)+4*(op&255)
        struct.pack_into('<I', image, pool-0x8c010000, target&0x1fffffff)
    before = list(range(63)); before[15], before[16], before[18] = 0x0c590100, 0x0c0432e4, 0x240001
    mode = bytearray(4096); mode[(cp.SCENE+10)&4095] = index
    pages = [(cp.SCENE&~4095, bytes(mode), bytes(mode))]
    for base in sorted({0x0c096000, 0x0c098000, 0x0c099000, cp.TABLE&~4095}):
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096]); pages.append((base, data, data))
    return image, dict(entry=cp.DISPATCH, exitpc=before[16], flags=0, nstate=63,
        before=struct.pack('<63I', *before), after=struct.pack('<63I', *before), ops=ops, pages=pages)


class SceneReplayCallerTests(unittest.TestCase):
    def test_fixed_direct_clock_and_history_tails(self):
        for index, shapes in ((53, (0,)), (56, (0, 1, 2))):
            for shape in shapes:
                image, sample = fixture(index, shape)
                self.assertEqual(len(cp.verify_scene_replay_sample(sample, image)), 64)

    def test_missing_dispatch_prefix_or_restore(self):
        for index in cp.ROWS:
            image, sample = fixture(index)
            for position in range(len(sample['ops'])-3):
                bad = copy.deepcopy(sample); del bad['ops'][position]
                with self.subTest(index=index, position=position), self.assertRaises(AssertionError):
                    cp.verify_scene_replay_sample(bad, image)

    def test_forged_fixed_instruction_even_if_image_agrees(self):
        for index in cp.ROWS:
            image, sample = fixture(index)
            for position in range(len(sample['ops'])-3):
                changed = bytearray(image); bad = copy.deepcopy(sample); pc, op = bad['ops'][position]
                bad['ops'][position] = (pc, op^1); struct.pack_into('<H', changed, pc-0x8c010000, op^1)
                with self.subTest(index=index, position=position), self.assertRaises(AssertionError):
                    cp.verify_scene_replay_sample(bad, changed)

    def test_wrong_scene_slot_or_index(self):
        for index in cp.ROWS:
            image, sample = fixture(index); slot = cp.TABLE+4*index
            image[slot-0x0c010000] ^= 1
            with self.assertRaises(AssertionError): cp.verify_scene_replay_sample(sample, image)
            image, sample = fixture(index); base, pre, post = sample['pages'][0]; pre = bytearray(pre)
            pre[(cp.SCENE+10)&4095] = 52; sample['pages'][0] = (base, bytes(pre), post)
            with self.assertRaises(AssertionError): cp.verify_scene_replay_sample(sample, image)

    def test_corrupted_architecture_or_return(self):
        for reg in range(8, 19):
            image, sample = fixture(56); after = bytearray(sample['after'])
            struct.pack_into('<I', after, reg*4, 0xffffffff); sample['after'] = bytes(after)
            with self.subTest(reg=reg), self.assertRaises(AssertionError): cp.verify_scene_replay_sample(sample, image)

    def test_wrong_tail_destination_and_repeated_restoration(self):
        image, sample = fixture(56)
        sample['ops'][-3] = (sample['ops'][-3][0]+2, sample['ops'][-3][1])
        with self.assertRaises(AssertionError): cp.verify_scene_replay_sample(sample, image)
        image, sample = fixture(56); sample['ops'][-3:-3] = list(cp.RESTORES[56][0])
        with self.assertRaises(AssertionError): cp.verify_scene_replay_sample(sample, image)


if __name__ == '__main__': unittest.main()
