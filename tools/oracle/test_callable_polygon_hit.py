"""Polygon caller attribution fails closed for forged saves and caller edges."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_polygon_hit as cp
def fixture(entry):
    image=bytearray(0x100000)
    ops=[(entry,cp.CALLERS[entry]),(entry+2,0x54f8)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    before=list(range(63));before[15]=0x0c550100;after=list(before);after[16]=entry+4
    pre=bytearray(4096);post=bytearray(4096)
    struct.pack_into('<I',pre,0x120,0x0c530000);struct.pack_into('<I',post,0x120,0x0c530000)
    for i,index in enumerate([14,13,36,35,34,33,16]):struct.pack_into('<I',post,0x100-4*(i+1),entry+4 if index==16 else before[index])
    sample=dict(entry=entry,exitpc=entry+4,flags=0,nstate=63,before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,pages=[(0x0c550000,bytes(pre),bytes(post))])
    return image,sample
class PolygonTests(unittest.TestCase):
    def test_both_original_callers(self):
        for entry in cp.CALLERS:
            image,s=fixture(entry);self.assertEqual(len(cp.verify_polygon_sample(s,image)),64)
    def test_missing_prefix_and_restore(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_polygon_sample(bad,image)
    def test_forged_original_signatures(self):
        for index in [0,1,2,3]:
            image,s=fixture(next(iter(cp.CALLERS)));pc,op=s['ops'][index];op^=1
            s['ops'][index]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.assertRaises(AssertionError):cp.verify_polygon_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for reg in list(range(8,17))+[18]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_polygon_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for i in range(7):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.assertRaises(AssertionError):cp.verify_polygon_sample(bad,image)
    def test_wrong_entry_return_or_actor(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.assertRaises(AssertionError):cp.verify_polygon_sample(bad,image)
        base,pre,post=s['pages'][0];pre=bytearray(pre);struct.pack_into('<I',pre,0x120,4);s['pages'][0]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_polygon_sample(s,image)
if __name__=='__main__':unittest.main()
