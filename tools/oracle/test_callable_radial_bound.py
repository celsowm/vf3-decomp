"""Reject forged evidence for both original radial-correction call sites."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_radial_bound as cp

def fixture(entry):
    image=bytearray(0x100000);call,delay=cp.CALLERS[entry]
    ops=[(entry,call),(entry+2,delay)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    for pc,op in ops:
        if op>>12 in (9,13) or op&0xff00==0xc700:
            size=2 if op>>12==9 else 4
            pool=pc+4+2*(op&255) if size==2 else ((pc+4)&~3)+4*(op&255)
            struct.pack_into('<H' if size==2 else '<I',image,pool-0x8c010000,0x1234)
    literals=image[0x8c0cb000-0x8c010000:0x8c0cc000-0x8c010000]
    before=list(range(63));before[15]=0x0c550100
    if entry==0x8c0cb66a:before[4]=0x0c530000
    after=list(before);after[16]=entry+4
    pre=bytearray(4096);struct.pack_into('<I',pre,0x100,0x0c530000);post=bytearray(pre)
    for i,index in enumerate([13,12,11,10,9,16]):
        struct.pack_into('<I',post,0x100-4*(i+1),entry+4 if index==16 else before[index])
    sample=dict(entry=entry,exitpc=entry+4,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,
        pages=[(0x0c550000,bytes(pre),bytes(post)),(0x0c0cb000,bytes(literals),bytes(literals))])
    return image,sample

class RadialBoundTests(unittest.TestCase):
    def test_both_original_callers(self):
        for entry in cp.CALLERS:
            image,s=fixture(entry);self.assertEqual(len(cp.verify_radial_bound_sample(s,image)),64)
    def test_missing_prefix_or_restore(self):
        for entry in cp.CALLERS:
            image,s=fixture(entry)
            for i in range(len(s['ops'])):
                bad=copy.deepcopy(s);del bad['ops'][i]
                with self.subTest(entry=entry,i=i),self.assertRaises(AssertionError):cp.verify_radial_bound_sample(bad,image)
    def test_forged_caller_delay_or_prefix(self):
        for entry in cp.CALLERS:
            for i in range(2+len(cp.PREFIX)):
                image,s=fixture(entry);pc,op=s['ops'][i];op^=1
                s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
                with self.subTest(entry=entry,i=i),self.assertRaises(AssertionError):cp.verify_radial_bound_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for reg in list(range(8,17))+[18]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_radial_bound_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for i in range(6):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1
            bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_radial_bound_sample(bad,image)
    def test_wrong_entry_return_or_actor(self):
        for entry in cp.CALLERS:
            image,s=fixture(entry)
            for field in ['entry','exitpc']:
                bad=copy.deepcopy(s);bad[field]+=2
                with self.subTest(entry=entry,field=field),self.assertRaises(AssertionError):cp.verify_radial_bound_sample(bad,image)
        image,s=fixture(0x8c0cb66e);base,pre,post=s['pages'][0];pre=bytearray(pre);struct.pack_into('<I',pre,0x100,4)
        s['pages'][0]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_radial_bound_sample(s,image)
    def test_changed_literal(self):
        image,s=fixture(next(iter(cp.CALLERS)));base,pre,post=s['pages'][1];pre=bytearray(pre);pre[0x6b0]^=1
        s['pages'][1]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_radial_bound_sample(s,image)

if __name__=='__main__':unittest.main()
