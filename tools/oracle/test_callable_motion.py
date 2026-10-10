"""The motion attribution contract rejects altered calls and unbalanced saves."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_motion as cm


def fixture(site=cm.CALLERS[0]):
    image=bytearray(0x100000)
    opcode=0xb000 | (((cm.PARENT-site-4)//2)&0xfff)
    ops=[(site,opcode),(site+2,0x64c3)]
    ops += [(cm.PARENT+2*i,op) for i,op in enumerate(cm.PREFIX)]
    ops += list(cm.RESTORE)
    for pc,op in ops: struct.pack_into('<H',image,pc-0x8c010000,op)
    before=[0]*63;before[8:16]=list(range(8,16));after=list(before);after[16]=site+4
    sample=dict(entry=site,exitpc=site+4,flags=0,nstate=63,
                before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,pages=[])
    return image,sample


class MotionTests(unittest.TestCase):
    def test_both_original_bsr_edges(self):
        for site in cm.CALLERS:
            image,sample=fixture(site)
            self.assertEqual(len(cm.verify_motion_sample(sample,image)),64)

    def test_rejects_changed_target_and_delay_even_if_trace_matches(self):
        for at in (0,1):
            image,sample=fixture();pc,op=sample['ops'][at]
            op ^= 1;sample['ops'][at]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(at=at),self.assertRaises(AssertionError): cm.verify_motion_sample(sample,image)

    def test_rejects_removed_prefix_or_restore_instruction(self):
        image,sample=fixture()
        for at in range(len(sample['ops'])):
            bad=copy.deepcopy(sample);del bad['ops'][at]
            with self.subTest(at=at),self.assertRaises(AssertionError): cm.verify_motion_sample(bad,image)

    def test_rejects_save_stack_and_return_corruption(self):
        image,sample=fixture()
        for reg in range(8,17):
            bad=copy.deepcopy(sample);data=bytearray(bad['after']);struct.pack_into('<I',data,4*reg,0xffffffff);bad['after']=bytes(data)
            with self.subTest(reg=reg),self.assertRaises(AssertionError): cm.verify_motion_sample(bad,image)
        bad=copy.deepcopy(sample);bad['exitpc']+=2
        with self.assertRaises(AssertionError): cm.verify_motion_sample(bad,image)

    def test_rejects_nonoriginal_opcode_and_wrong_entry(self):
        image,sample=fixture();sample['ops'][2]=(cm.PARENT,0xe005)
        with self.assertRaisesRegex(AssertionError,'nonoriginal'): cm.verify_motion_sample(sample,image)
        image,sample=fixture();sample['entry']+=2
        with self.assertRaisesRegex(AssertionError,'unsupported'): cm.verify_motion_sample(sample,image)

    def test_rejects_patched_literal_before_or_after_execution(self):
        image,sample=fixture();pc=cm.PARENT+6;pool=pc+6
        sample['ops'].insert(5,(pc,0x9001))
        struct.pack_into('<H',image,pc-0x8c010000,0x9001)
        struct.pack_into('<H',image,pool-0x8c010000,0x1234)
        base=0x0c0a9000;page=bytes(image[base-0x0c010000:base-0x0c010000+4096])
        sample['pages']=[(base,page,page)]
        cm.verify_motion_sample(sample,image)
        for side in (1,2):
            bad=copy.deepcopy(sample);parts=list(bad['pages'][0]);data=bytearray(parts[side])
            struct.pack_into('<H',data,(pool&0x1fffffff)-base,0x4321)
            parts[side]=bytes(data);bad['pages'][0]=tuple(parts)
            with self.subTest(side=side),self.assertRaisesRegex(AssertionError,'literal pool'): cm.verify_motion_sample(bad,image)


if __name__=='__main__': unittest.main()
