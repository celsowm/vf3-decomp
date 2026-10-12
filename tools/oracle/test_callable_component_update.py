"""Mutation checks for the original component index and update callback path."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_component_update as cp


def fixture(index):
    entry, _, restore, frame, pool_load = cp.ROWS[index]
    image = bytearray(0x100000)
    prefix = (0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x2fa6, 0x2f96,
              0x2f86, 0xfffb, 0xffeb, 0xffdb, 0xffcb, pool_load, 0x4f22)
    ops = list(cp.DISPATCH) + [(entry+2*i, op) for i, op in enumerate(prefix)]
    ops += [(restore+2*i, op) for i, op in enumerate((
        frame, 0x4f26, 0xfcf9, 0xfdf9, 0xfef9, 0xfff9,
        0x68f6, 0x69f6, 0x6af6, 0x6bf6, 0x6cf6, 0x6df6, 0x000b, 0x6ef6))]
    for pc, op in ops:
        struct.pack_into('<H', image, pc-0x8c010000, op)
    struct.pack_into('<I', image, cp.TABLE_POOL-0x0c010000, cp.TABLE)
    struct.pack_into('<I', image, 0x0c08b510-0x0c010000, 0x46629000)
    record = cp.TABLE + 28*index
    struct.pack_into('<I', image, record+12-0x0c010000, entry & 0x1fffffff)
    before = list(range(63))
    before[8], before[12], before[14], before[15], before[18] = 0, 12, index+1, 0x0c590100, 0x240001
    after = list(before)
    after[10], after[11], after[14], after[16], after[36] = cp.TABLE, entry & 0x1fffffff, record, cp.RETURN & 0x1fffffff, 0x46629000
    pre = bytes(4096)
    post = bytearray(pre)
    for i, reg in enumerate(cp.SAVE_INDICES):
        struct.pack_into('<I', post, 0x100-4*(i+1), after[reg])
    pages = [(0x0c590000, pre, bytes(post))]
    for base in (0x0c087000, 0x0c088000, 0x0c08a000, 0x0c08b000, 0x0c0f7000):
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096])
        pages.append((base, data, data))
    sample = dict(entry=cp.START, exitpc=cp.RETURN, flags=0, nstate=63,
                  before=struct.pack('<63I', *before), after=struct.pack('<63I', *after),
                  ops=ops, pages=pages)
    return image, sample


class ComponentUpdateTests(unittest.TestCase):
    def test_original_component_rows(self):
        for index in cp.ROWS:
            image, sample = fixture(index)
            self.assertEqual(len(cp.verify_component_update_sample(sample, image)), 64)

    def test_missing_or_changed_ordered_instructions(self):
        for index in cp.ROWS:
            image, sample = fixture(index)
            for position in range(len(sample['ops'])):
                bad = copy.deepcopy(sample)
                del bad['ops'][position]
                with self.subTest(index=index, position=position), self.assertRaises(AssertionError):
                    cp.verify_component_update_sample(bad, image)

    def test_forged_signature_even_when_image_agrees(self):
        for position in range(len(cp.DISPATCH)):
            image, sample = fixture(11)
            pc, op = sample['ops'][position]
            sample['ops'][position] = (pc, op ^ 1)
            struct.pack_into('<H', image, pc-0x8c010000, op ^ 1)
            with self.subTest(position=position), self.assertRaises(AssertionError):
                cp.verify_component_update_sample(sample, image)

    def test_invalid_index_phase_filter_or_float_mode(self):
        for reg, value in ((8, 1), (12, 16), (14, 4), (18, 0x140001), (18, 0x80000)):
            image, sample = fixture(11)
            data = bytearray(sample['before'])
            struct.pack_into('<I', data, 4*reg, value)
            sample['before'] = bytes(data)
            with self.subTest(reg=reg), self.assertRaises(AssertionError):
                cp.verify_component_update_sample(sample, image)
        image, sample = fixture(11)
        base, pre, post = sample['pages'][0]
        pre = bytearray(pre); struct.pack_into('<I', pre, 0x104, 1)
        sample['pages'][0] = (base, bytes(pre), post)
        with self.assertRaises(AssertionError): cp.verify_component_update_sample(sample, image)

    def test_corrupted_saved_architecture_or_return(self):
        for reg in (8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 33, 34, 35, 36):
            image, sample = fixture(11)
            data = bytearray(sample['after']); struct.pack_into('<I', data, 4*reg, 0xffffffff)
            sample['after'] = bytes(data)
            with self.subTest(reg=reg), self.assertRaises(AssertionError):
                cp.verify_component_update_sample(sample, image)

    def test_corrupted_saved_stack_slots(self):
        for position in range(len(cp.SAVE_INDICES)):
            image, sample = fixture(11)
            base, pre, post = sample['pages'][0]
            post = bytearray(post); post[0x100-4*(position+1)] ^= 1
            sample['pages'][0] = (base, pre, bytes(post))
            with self.subTest(position=position), self.assertRaises(AssertionError):
                cp.verify_component_update_sample(sample, image)

    def test_modified_or_forged_original_callback_table(self):
        for after in (False, True):
            image, sample = fixture(11)
            base, pre, post = sample['pages'][-1]
            changed = bytearray(post if after else pre)
            changed[cp.TABLE+28*11+12-base] ^= 1
            sample['pages'][-1] = (base, pre, bytes(changed)) if after else (base, bytes(changed), post)
            with self.subTest(after=after), self.assertRaises(AssertionError):
                cp.verify_component_update_sample(sample, image)
        image, sample = fixture(11)
        struct.pack_into('<I', image, cp.TABLE+28*11+12-0x0c010000, 0x0c087e06)
        with self.assertRaises(AssertionError): cp.verify_component_update_sample(sample, image)


if __name__ == '__main__': unittest.main()
