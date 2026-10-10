"""Reject forged targets, reordered prefixes and broken original stack saves."""
import copy
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_dispatch as cd


def fixture():
    image = bytearray(0x300000)
    ops = [(cd.DISPATCH + 2*i, op) for i,op in enumerate(cd.DISPATCH_OPS)]
    ops += [(cd.PARENT + 2*i, op) for i,op in enumerate(cd.PREFIX_OPS)]
    ops += [(0x8c09914e + 2*i, op) for i,op in enumerate(cd.RESTORE_OPS)]
    ops += [(0x8c097ff4, 9)]
    for pc,op in ops:
        struct.pack_into('<H',image,pc-cd.BASE,op)
    pools = []
    for pc,op,wanted in ((cd.DISPATCH,cd.DISPATCH_OPS[0],cd.SCENE),
                         (cd.DISPATCH+28,cd.DISPATCH_OPS[14],cd.TABLE)):
        pool = ((pc+4)&~3)+4*(op&255)
        struct.pack_into('<I',image,pool-cd.BASE,wanted)
        pools.append(pool)
    struct.pack_into('<I',image,cd.TABLE+55*4-0x0c010000,cd.PARENT&0x1fffffff)
    bases = {(cd.TABLE+55*4)&~4095, cd.SCENE&~4095}
    bases |= {p&0x1ffff000 for p in pools}
    for pc,op in ops[:29]:
        if op >> 12 in (0x9,0xd):
            pool = pc+4+2*(op&255) if op >> 12 == 0x9 else ((pc+4)&~3)+4*(op&255)
            bases.add(pool&0x1ffff000)
    pages=[]
    for base in sorted(bases):
        data=bytearray(image[base-0x0c010000:base-0x0c010000+4096])
        if base <= cd.SCENE+10 < base+4096:
            data[cd.SCENE+10-base]=55
        pages.append((base,bytes(data),bytes(data)))
    before=[0]*63
    before[13:17]=[0x12345678,0x23456789,0x0c3ff000,0x8c0432e4]
    sample=dict(entry=cd.DISPATCH,exitpc=before[16],flags=0,nstate=63,
                before=struct.pack('<63I',*before),after=struct.pack('<63I',*before),
                ops=ops,pages=pages)
    return image,sample


class DispatchTests(unittest.TestCase):
    def test_original_loaded_edge_and_ordered_save_sequence(self):
        image,sample=fixture()
        self.assertEqual(len(cd.verify_dispatch_sample(sample,image)),64)

    def test_rejects_wrong_entry_flags_return_and_register_restoration(self):
        image,sample=fixture()
        for field,value in (('entry',cd.PARENT),('flags',1),('exitpc',0)):
            bad=copy.deepcopy(sample);bad[field]=value
            with self.subTest(field=field),self.assertRaises(AssertionError):
                cd.verify_dispatch_sample(bad,image)
        for reg in (13,14,15):
            bad=copy.deepcopy(sample);after=bytearray(bad['after'])
            struct.pack_into('<I',after,reg*4,0);bad['after']=bytes(after)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):
                cd.verify_dispatch_sample(bad,image)

    def test_rejects_missing_or_reordered_dispatch_prefix_and_restores(self):
        image,sample=fixture()
        for at in (0,19,20,21,28,29,30,31,32,33):
            bad=copy.deepcopy(sample);del bad['ops'][at]
            with self.subTest(missing=at),self.assertRaises(AssertionError):
                cd.verify_dispatch_sample(bad,image)
        for at in (0,20,29):
            bad=copy.deepcopy(sample)
            bad['ops'][at:at+2]=reversed(bad['ops'][at:at+2])
            with self.subTest(reordered=at),self.assertRaises(AssertionError):
                cd.verify_dispatch_sample(bad,image)

    def test_rejects_forged_index_target_literal_and_changed_slot(self):
        image,sample=fixture()
        for address,size,value,side in ((cd.SCENE+10,1,10,1),
                 (cd.TABLE+220,4,0x0c09a284,1),(cd.TABLE+220,4,0,2),
                 (0x0c096934,4,0,1)):
            bad=copy.deepcopy(sample)
            for i,page in enumerate(bad['pages']):
                if page[0] <= address < page[0]+4096:
                    values=list(page);data=bytearray(values[side])
                    data[address-page[0]:address-page[0]+size]=value.to_bytes(size,'little')
                    values[side]=bytes(data);bad['pages'][i]=tuple(values)
                    break
            with self.subTest(address=hex(address),side=side),self.assertRaises(AssertionError):
                cd.verify_dispatch_sample(bad,image)

    def test_rejects_capture_opcode_even_if_control_flow_looks_valid(self):
        image,sample=fixture();sample['ops'][-1]=(sample['ops'][-1][0],0xe000)
        with self.assertRaisesRegex(AssertionError,'nonoriginal'):
            cd.verify_dispatch_sample(sample,image)


if __name__ == '__main__':
    unittest.main()
