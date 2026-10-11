"""Geometry attribution rejects corrupted integer/FR saves and call literals."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_geometry as cg


def fixture():
    image = bytearray(0x100000)
    ops = [(cg.LOAD,0xd31f),(cg.CALL,0x430b),(cg.CALL+2,0x64e3)]
    ops += [(cg.PARENT+2*i,op) for i,op in enumerate(cg.PREFIX)]
    ops += list(cg.RESTORE)
    for pc, op in ops:
        struct.pack_into('<H',image,pc-0x8c010000,op)
    struct.pack_into('<I',image,cg.POOL-0x0c010000,cg.PARENT&0x1fffffff)
    struct.pack_into('<H',image,0x0c0ca908-0x0c010000,0x1394)
    before = list(range(63));after = list(before);after[16] = cg.RETURN
    pages = []
    for base in [0x0c0b0000,0x0c0ca000]:
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096])
        pages.append((base,data,data))
    sample = dict(entry=cg.LOAD,exitpc=cg.RETURN,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,pages=pages)
    return image,sample


class GeometryTests(unittest.TestCase):
    def test_original_literal_call_and_restores(self):
        image,sample = fixture()
        self.assertEqual(len(cg.verify_geometry_sample(sample,image)),64)

    def test_altered_call_signature_even_if_image_and_trace_match(self):
        for at in range(3):
            image,sample = fixture();pc,op = sample['ops'][at];op ^= 1
            sample['ops'][at] = (pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(at=at),self.assertRaises(AssertionError):
                cg.verify_geometry_sample(sample,image)

    def test_missing_save_or_restore(self):
        image,sample = fixture()
        for at in range(len(sample['ops'])):
            bad = copy.deepcopy(sample);del bad['ops'][at]
            with self.subTest(at=at),self.assertRaises(AssertionError):
                cg.verify_geometry_sample(bad,image)

    def test_architectural_saves_and_return(self):
        image,sample = fixture()
        for reg in list(range(8,19))+list(range(33,53)):
            if reg == 17:continue
            bad = copy.deepcopy(sample);data = bytearray(bad['after'])
            struct.pack_into('<I',data,4*reg,0xffffffff);bad['after'] = bytes(data)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):
                cg.verify_geometry_sample(bad,image)
        sample['exitpc'] += 2
        with self.assertRaises(AssertionError):cg.verify_geometry_sample(sample,image)

    def test_modified_target_or_prefix_pool_before_and_after(self):
        image,sample = fixture()
        for page,offset in [(0,0x568),(1,0x908)]:
            for side in [1,2]:
                bad = copy.deepcopy(sample);parts = list(bad['pages'][page]);data = bytearray(parts[side])
                data[offset] ^= 1;parts[side] = bytes(data);bad['pages'][page] = tuple(parts)
                with self.subTest(page=page,side=side),self.assertRaisesRegex(AssertionError,'literal'):
                    cg.verify_geometry_sample(bad,image)

    def test_changed_opcode_and_wrong_entry(self):
        image,sample = fixture();sample['ops'][3] = (cg.PARENT,0x2fd6)
        with self.assertRaisesRegex(AssertionError,'nonoriginal'):cg.verify_geometry_sample(sample,image)
        image,sample = fixture();sample['entry'] += 2
        with self.assertRaisesRegex(AssertionError,'unsupported'):cg.verify_geometry_sample(sample,image)


if __name__ == '__main__':
    unittest.main()
