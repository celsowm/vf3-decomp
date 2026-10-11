"""Reject forged literal targets, argument setup, saves and frame returns."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_aggregate_frame as cp

def fixture():
    image=bytearray(0x100000)
    ops=[(cp.LOAD,0xd323),(cp.LOAD+2,0x65a3),(cp.CALL,0x430b),(cp.CALL+2,0x64e3)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    struct.pack_into('<I',image,(cp.POOL|0x80000000)-0x8c010000,cp.PARENT&0x1fffffff)
    literal=image[0x8c0a0000-0x8c010000:0x8c0a1000-0x8c010000]
    before=list(range(63));before[15]=0x0c550100;before[14]=0x0c530000;before[10]=0x0c540000
    after=list(before);after[16]=cp.RETURN
    pre=bytes(4096);post=bytearray(pre)
    for i,index in enumerate([14,13,36,16]):struct.pack_into('<I',post,0x100-4*(i+1),cp.RETURN if index==16 else before[index])
    sample=dict(entry=cp.LOAD,exitpc=cp.RETURN,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,
        pages=[(0x0c550000,pre,bytes(post)),(0x0c0a0000,bytes(literal),bytes(literal))])
    return image,sample

class AggregateFrameTests(unittest.TestCase):
    def test_original_caller(self):
        image,s=fixture();self.assertEqual(len(cp.verify_aggregate_frame_sample(s,image)),64)
    def test_missing_setup_prefix_or_restore(self):
        image,s=fixture()
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(bad,image)
    def test_forged_signatures(self):
        for i in range(4+len(cp.PREFIX)):
            image,s=fixture();pc,op=s['ops'][i];op^=1;s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture()
        for reg in list(range(8,17))+[18]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture()
        for i in range(4):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(bad,image)
    def test_wrong_entry_return_or_setup(self):
        image,s=fixture()
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.subTest(field=field),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(bad,image)
        for register,value in [(14,4),(10,5)]:
            bad=copy.deepcopy(s);before=bytearray(bad['before']);struct.pack_into('<I',before,4*register,value);bad['before']=bytes(before)
            after=bytearray(bad['after']);struct.pack_into('<I',after,4*register,value);bad['after']=bytes(after)
            with self.subTest(register=register),self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(bad,image)
    def test_changed_or_forged_literal(self):
        image,s=fixture();base,pre,post=s['pages'][1];pre=bytearray(pre);pre[0xd88]^=1;s['pages'][1]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(s,image)
        image,s=fixture();struct.pack_into('<I',image,(cp.POOL|0x80000000)-0x8c010000,0x0c0a6dbe)
        with self.assertRaises(AssertionError):cp.verify_aggregate_frame_sample(s,image)

if __name__=='__main__':unittest.main()
