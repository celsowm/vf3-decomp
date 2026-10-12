"""Reject altered SDK clipping loads, delay arguments, saves and packets."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_clip_triangle as cp


def fixture(entry, increment=96):
    pool, load, restore = cp.CALLERS[entry]
    image = bytearray(0x100000)
    displacement = ((pool|0x80000000)-((load+4)&~3))//4
    ops = [(load, 0xd200+displacement), (load+2, 0x420b), (load+4, 0x6403)]
    ops += [(entry+2*i, op) for i, op in enumerate(cp.PREFIX)]
    ops += [(restore+2*i, op) for i, op in enumerate(cp.RESTORE)]
    for pc, op in ops: struct.pack_into('<H', image, pc-0x8c010000, op)
    struct.pack_into('<H', image, entry+0x4e-0x8c010000, 0x7800+cp.STRIDES[entry])
    struct.pack_into('<I', image, pool-0x0c010000, entry&0x1fffffff)
    before = list(range(63)); before[12], before[15], before[18] = 0x0c550000, 0x0c590100, 0x240001
    after = list(before)
    after[2], after[4], after[12], after[16] = entry&0x1fffffff, before[0], before[12]+increment, (load+6)&0x1fffffff
    post = bytearray(4096)
    for i, reg in enumerate(cp.SAVE_INDICES):
        wanted = before[8]+2*cp.STRIDES[entry] if i == 5 else before[8]+cp.STRIDES[entry] if i == 6 else after[reg]
        struct.pack_into('<I', post, 0x100-4*(i+1), wanted)
    output = bytearray(4096)
    if increment: struct.pack_into('<I', output, increment-32, before[59])
    pages = [(0x0c590000, bytes(4096), bytes(post)), (0x0c550000, bytes(4096), bytes(output))]
    for base in sorted({entry&0x1ffff000, pool&0x1ffff000}):
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096]); pages.append((base, data, data))
    return image, dict(entry=load, exitpc=load+6, flags=0, nstate=63,
                       before=struct.pack('<63I', *before), after=struct.pack('<63I', *after), ops=ops, pages=pages)


class ClipTriangleTests(unittest.TestCase):
    def test_all_original_callers_and_stream_sizes(self):
        for entry in cp.CALLERS:
            for increment in (0, 96, 128):
                image, sample = fixture(entry, increment)
                self.assertEqual(len(cp.verify_clip_triangle_sample(sample, image)), 64)

    def test_missing_ordered_instructions(self):
        image, sample = fixture(0x8c05152c)
        for position in range(len(sample['ops'])):
            bad = copy.deepcopy(sample); del bad['ops'][position]
            with self.subTest(position=position), self.assertRaises(AssertionError):
                cp.verify_clip_triangle_sample(bad, image)

    def test_forged_signature_even_when_image_agrees(self):
        for position in range(3+len(cp.PREFIX)):
            image, sample = fixture(0x8c05152c)
            pc, op = sample['ops'][position]; sample['ops'][position] = (pc, op^1)
            struct.pack_into('<H', image, pc-0x8c010000, op^1)
            with self.subTest(position=position), self.assertRaises(AssertionError):
                cp.verify_clip_triangle_sample(sample, image)

    def test_corrupted_architecture(self):
        for reg in (*range(12), *range(13, 19), 19, 20, *range(21, 53), *range(54, 63)):
            image, sample = fixture(0x8c05152c)
            after = bytearray(sample['after']); struct.pack_into('<I', after, 4*reg, 0xffffffff)
            sample['after'] = bytes(after)
            with self.subTest(reg=reg), self.assertRaises(AssertionError):
                cp.verify_clip_triangle_sample(sample, image)

    def test_corrupted_frame_slot(self):
        for position in range(len(cp.SAVE_INDICES)):
            image, sample = fixture(0x8c05152c)
            base, pre, post = sample['pages'][0]; post = bytearray(post); post[0x100-4*(position+1)] ^= 1
            sample['pages'][0] = (base, pre, bytes(post))
            with self.subTest(position=position), self.assertRaises(AssertionError):
                cp.verify_clip_triangle_sample(sample, image)

    def test_corrupted_final_packet_and_stream_increment(self):
        image, sample = fixture(0x8c05152c)
        base, pre, post = sample['pages'][1]; post = bytearray(post); post[64] ^= 1
        sample['pages'][1] = (base, pre, bytes(post))
        with self.assertRaises(AssertionError): cp.verify_clip_triangle_sample(sample, image)
        image, sample = fixture(0x8c05152c, 32)
        with self.assertRaises(AssertionError): cp.verify_clip_triangle_sample(sample, image)

    def test_patched_target_or_unsupported_caller(self):
        image, sample = fixture(0x8c05152c)
        pool = cp.CALLERS[0x8c05152c][0]
        struct.pack_into('<I', image, pool-0x0c010000, 0x0c05152e)
        with self.assertRaises(AssertionError): cp.verify_clip_triangle_sample(sample, image)
        image, sample = fixture(0x8c05152c); sample['entry'] += 2
        with self.assertRaises(AssertionError): cp.verify_clip_triangle_sample(sample, image)

    def test_invalid_float_mode(self):
        for mode in (0x140001, 0x80000):
            image, sample = fixture(0x8c05152c)
            before = bytearray(sample['before']); struct.pack_into('<I', before, 4*18, mode)
            sample['before'] = bytes(before)
            with self.subTest(mode=mode), self.assertRaises(AssertionError):
                cp.verify_clip_triangle_sample(sample, image)


if __name__ == '__main__': unittest.main()
