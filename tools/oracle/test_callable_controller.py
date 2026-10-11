"""Reject altered controller call edges, literal pools and register restores."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_controller as cc


def fixture(site=cc.CALLERS[0]):
    image = bytearray(0x100000)
    opcode = 0xb000 | (((cc.PARENT-site-4)//2)&0xfff)
    ops = [(site, opcode), (site+2, 9)]
    ops += [(cc.PARENT+2*i, op) for i, op in enumerate(cc.PREFIX)]
    ops += list(cc.RESTORE)
    for pc, op in ops:
        struct.pack_into('<H', image, pc-0x8c010000, op)
    struct.pack_into('<H', image, 0x8c09b026-0x8c010000, 0x1ec)
    before = [0]*63
    before[8:16] = list(range(8, 16))
    after = list(before)
    after[16] = site+4
    pages = []
    for base in [0x0c09a000, 0x0c09b000]:
        page = bytes(image[base-0x0c010000:base-0x0c010000+4096])
        pages.append((base, page, page))
    sample = dict(entry=site, exitpc=site+4, flags=0, nstate=63,
                  before=struct.pack('<63I', *before), after=struct.pack('<63I', *after),
                  ops=ops, pages=pages)
    return image, sample


class ControllerTests(unittest.TestCase):
    def test_both_original_call_edges(self):
        for site in cc.CALLERS:
            image, sample = fixture(site)
            self.assertEqual(len(cc.verify_controller_sample(sample, image)), 64)

    def test_changed_target_and_delay_even_when_trace_matches(self):
        for at in [0, 1]:
            image, sample = fixture()
            pc, op = sample['ops'][at]
            op ^= 1
            sample['ops'][at] = (pc, op)
            struct.pack_into('<H', image, pc-0x8c010000, op)
            with self.subTest(at=at), self.assertRaises(AssertionError):
                cc.verify_controller_sample(sample, image)

    def test_missing_prefix_or_ordered_restore(self):
        image, sample = fixture()
        for at in range(len(sample['ops'])):
            bad = copy.deepcopy(sample)
            del bad['ops'][at]
            with self.subTest(at=at), self.assertRaises(AssertionError):
                cc.verify_controller_sample(bad, image)

    def test_register_stack_and_return_corruption(self):
        image, sample = fixture()
        for reg in range(8, 17):
            bad = copy.deepcopy(sample)
            data = bytearray(bad['after'])
            struct.pack_into('<I', data, 4*reg, 0xffffffff)
            bad['after'] = bytes(data)
            with self.subTest(reg=reg), self.assertRaises(AssertionError):
                cc.verify_controller_sample(bad, image)
        sample['exitpc'] += 2
        with self.assertRaises(AssertionError):
            cc.verify_controller_sample(sample, image)

    def test_nonoriginal_opcode_and_wrong_entry(self):
        image, sample = fixture()
        sample['ops'][2] = (cc.PARENT, 0x2fd6)
        with self.assertRaisesRegex(AssertionError, 'nonoriginal'):
            cc.verify_controller_sample(sample, image)
        image, sample = fixture()
        sample['entry'] += 2
        with self.assertRaisesRegex(AssertionError, 'unsupported'):
            cc.verify_controller_sample(sample, image)

    def test_literal_modified_before_or_after(self):
        image, sample = fixture()
        for side in [1, 2]:
            bad = copy.deepcopy(sample)
            parts = list(bad['pages'][1])
            data = bytearray(parts[side])
            struct.pack_into('<H', data, 0x26, 0x1ed)
            parts[side] = bytes(data)
            bad['pages'][1] = tuple(parts)
            with self.subTest(side=side), self.assertRaisesRegex(AssertionError, 'literal'):
                cc.verify_controller_sample(bad, image)


if __name__ == '__main__':
    unittest.main()
