"""Vector caller attribution fails closed for forged saves and caller edges."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_vector_sum as cp
def fixture(entry):
    image=bytearray(0x100000)
    ops=[(entry,cp.CALLERS[entry]),(entry+2,0x54fa)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    before=list(range(63));before[15]=0x0c550100;before[5]=0x0c540000;after=list(before);after[16]=entry+4
    pre=bytearray(4096);post=bytearray(4096)
    struct.pack_into('<I',pre,0x128,0x0c530000);struct.pack_into('<I',post,0x128,0x0c530000)
    for i,index in enumerate([14,13,12,36,35,34,33,16]):struct.pack_into('<I',post,0x100-4*(i+1),entry+4 if index==16 else before[index])
    sample=dict(entry=entry,exitpc=entry+4,flags=0,nstate=63,before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,pages=[(0x0c550000,bytes(pre),bytes(post)),(0x0c540000,bytes(4096),bytes(4096))])
    return image,sample
class VectorSumTests(unittest.TestCase):
    def test_nonempty_installs_basis_preserving_translation(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        count=struct.pack('<I',1)+bytes(4092);s['pages'][1]=(0x0c540000,count,count)
        config=bytearray(4096)
        basis=[0x3f800000 if i in (0,5,10,15) else 0 for i in range(16)]
        struct.pack_into('<16I',config,16,*basis);s['pages'].append((0x0c530000,bytes(config),bytes(config)))
        after=list(struct.unpack('<63I',s['after']));after[37:49]=basis[:12];after[52]=basis[15];s['after']=struct.pack('<63I',*after)
        self.assertEqual(len(cp.verify_vector_sum_sample(s,image)),64)
        for reg in list(range(37,53)):
            bad=copy.deepcopy(s);a=bytearray(bad['after']);struct.pack_into('<I',a,4*reg,0xffffffff);bad['after']=bytes(a)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_vector_sum_sample(bad,image)
    def test_original_caller(self):
        for entry in cp.CALLERS:
            image,s=fixture(entry);self.assertEqual(len(cp.verify_vector_sum_sample(s,image)),64)
    def test_missing_prefix_and_restore(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_vector_sum_sample(bad,image)
    def test_forged_original_signatures(self):
        for index in [0,1,2,3]:
            image,s=fixture(next(iter(cp.CALLERS)));pc,op=s['ops'][index];op^=1
            s['ops'][index]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.assertRaises(AssertionError):cp.verify_vector_sum_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for reg in list(range(8,17))+[18]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_vector_sum_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for i in range(8):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.assertRaises(AssertionError):cp.verify_vector_sum_sample(bad,image)
    def test_wrong_entry_return_or_actor(self):
        image,s=fixture(next(iter(cp.CALLERS)))
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.assertRaises(AssertionError):cp.verify_vector_sum_sample(bad,image)
        base,pre,post=s['pages'][0];pre=bytearray(pre);struct.pack_into('<I',pre,0x128,4);s['pages'][0]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_vector_sum_sample(s,image)
if __name__=='__main__':unittest.main()
