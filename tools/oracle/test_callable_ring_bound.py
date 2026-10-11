"""Reject forged arena-bound caller, saved state and ordered return evidence."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_ring_bound as cp

def fixture():
    entry=next(iter(cp.CALLERS));image=bytearray(0x100000)
    ops=[(entry,cp.CALLERS[entry]),(entry+2,0x64e3)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    literals=bytearray(4096)
    for address,value in [(0x8c0cb558,0x138c),(0x8c0cb6ae,0x13b0)]:
        struct.pack_into('<H',image,address-0x8c010000,value)
        struct.pack_into('<H',literals,address-0x8c0cb000,value)
    before=list(range(63));before[15]=0x0c550100;before[14]=0x0c530000
    after=list(before);after[16]=entry+4
    pre=bytes(4096);post=bytearray(pre)
    for i,index in enumerate([13,12,11,10,9,36,34,16]):
        struct.pack_into('<I',post,0x100-4*(i+1),entry+4 if index==16 else before[index])
    sample=dict(entry=entry,exitpc=entry+4,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,
        pages=[(0x0c550000,pre,bytes(post)),(0x0c0cb000,bytes(literals),bytes(literals))])
    return image,sample

class RingBoundTests(unittest.TestCase):
    def test_original_caller(self):
        image,s=fixture();self.assertEqual(len(cp.verify_ring_bound_sample(s,image)),64)
    def test_missing_prefix_or_restore(self):
        image,s=fixture()
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(bad,image)
    def test_forged_caller_delay_or_prefix(self):
        for i in range(2+len(cp.PREFIX)):
            image,s=fixture();pc,op=s['ops'][i];op^=1
            s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture()
        for reg in list(range(8,17))+[18]+list(range(34,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture()
        for i in range(8):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1
            bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(bad,image)
    def test_wrong_entry_return_or_actor(self):
        image,s=fixture()
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.subTest(field=field),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(bad,image)
        for actor in [4,0x00800000]:
            bad=copy.deepcopy(s);before=bytearray(bad['before']);struct.pack_into('<I',before,4*14,actor);bad['before']=bytes(before)
            after=bytearray(bad['after']);struct.pack_into('<I',after,4*14,actor);bad['after']=bytes(after)
            with self.subTest(actor=actor),self.assertRaises(AssertionError):cp.verify_ring_bound_sample(bad,image)
    def test_changed_literal(self):
        image,s=fixture();base,pre,post=s['pages'][1];pre=bytearray(pre);pre[0x558]^=1
        s['pages'][1]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_ring_bound_sample(s,image)

if __name__=='__main__':unittest.main()
