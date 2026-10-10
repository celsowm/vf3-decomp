"""Literal JSR attribution must prove the original load, delay slot and return."""
import copy
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_literal as cl


def fixture():
    image=bytearray(0x100000)
    ops=[(cl.LOAD,0xd218),(cl.CALL,0x420b),(cl.CALL+2,9)]
    ops += [(cl.PARENT+2*i,op) for i,op in enumerate(cl.PREFIX)]
    ops += [(0x8c0c9fea,0x4f26),(0x8c0c9fec,0x000b),(0x8c0c9fee,9)]
    ops += [(cl.RETURN,0xa006),(cl.RETURN+2,9)]
    for pc,op in ops:
        struct.pack_into('<H',image,pc-0x8c010000,op)
    struct.pack_into('<I',image,cl.POOL-0x0c010000,cl.PARENT&0x1fffffff)
    base=0x0c0c9000
    page=bytes(image[base-0x0c010000:base-0x0c010000+4096])
    extra=bytes(image[0x0c0ca000-0x0c010000:0x0c0ca000-0x0c010000+4096])
    before=[0]*63;before[13:17]=[0x1234,0x2345,0x0c3ff000,0x8c0432e4]
    after=list(before);after[16]=cl.RETURN
    sample=dict(entry=cl.LOAD,exitpc=cl.RETURN+16,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),
        ops=ops,pages=[(base,page,page),(0x0c0ca000,extra,extra)])
    return image,sample


class LiteralTests(unittest.TestCase):
    def test_original_loaded_jsr_prefix_and_return(self):
        image,sample=fixture()
        self.assertEqual(len(cl.verify_literal_sample(sample,image)),64)

    def test_rejects_wrong_caller_return_and_unbalanced_stack(self):
        image,sample=fixture()
        for field,value in (('entry',cl.CALL),('exitpc',0),('flags',1)):
            bad=copy.deepcopy(sample);bad[field]=value
            with self.subTest(field=field),self.assertRaises(AssertionError):
                cl.verify_literal_sample(bad,image)
        for reg in (13,14,15,16):
            bad=copy.deepcopy(sample);data=bytearray(bad['after'])
            struct.pack_into('<I',data,reg*4,0);bad['after']=bytes(data)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):
                cl.verify_literal_sample(bad,image)

    def test_rejects_missing_load_delay_prefix_save_restore_and_rts(self):
        image,sample=fixture()
        for at in range(len(sample['ops'])):
            bad=copy.deepcopy(sample);del bad['ops'][at]
            with self.subTest(missing=at),self.assertRaises(AssertionError):
                cl.verify_literal_sample(bad,image)

    def test_rejects_patched_target_and_opcode(self):
        image,sample=fixture()
        for side in (1,2):
            bad=copy.deepcopy(sample);page=list(bad['pages'][0]);data=bytearray(page[side])
            struct.pack_into('<I',data,cl.POOL-page[0],0x0c099060)
            page[side]=bytes(data);bad['pages'][0]=tuple(page)
            with self.subTest(side=side),self.assertRaises(AssertionError):
                cl.verify_literal_sample(bad,image)
        sample['ops'][2]=(cl.CALL+2,0xe000)
        with self.assertRaisesRegex(AssertionError,'nonoriginal'):
            cl.verify_literal_sample(sample,image)


if __name__=='__main__':unittest.main()
