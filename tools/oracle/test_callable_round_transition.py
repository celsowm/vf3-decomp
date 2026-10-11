"""Reject forged literal targets, argument setup, saves and frame returns."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_round_transition as cp

def fixture():
    image=bytearray(0x100000)
    ops=[(cp.DISPATCH+2*i,op) for i,op in enumerate(cp.DISPATCH_OPS)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    for addr,v in [(0x8c096934,cp.SCENE),(0x8c096938,0x80000000),(0x8c09693c,cp.TABLE),(0x8c09a14c,0x0c29bcc4),(cp.TABLE+cp.INDEX*4,cp.PARENT&0x1fffffff)]:
        struct.pack_into('<I',image,(addr|0x80000000)-0x8c010000,v)
    before=list(range(63));before[15]=0x0c550100;before[16]=0x0c0432e4
    after=list(before);pre=bytes(4096);post=bytearray(pre)
    for i,index in enumerate(cp.SAVE_INDICES):struct.pack_into('<I',post,0x100-4*(i+1),before[index])
    scene=bytearray(4096);scene[(cp.SCENE+10)&4095]=cp.INDEX
    pages=[(0x0c550000,pre,bytes(post))]
    for base in [0x0c096000,0x0c09a000,0x0c10b000]:
        off=base-0x0c010000;data=bytes(image[off:off+4096]);pages.append((base,data,data))
    pages.append((cp.SCENE&~4095,bytes(scene),bytes(scene)))
    sample=dict(entry=cp.DISPATCH,exitpc=before[16],flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,pages=pages)
    return image,sample

class RoundTransitionTests(unittest.TestCase):
    def test_original_caller(self):
        image,s=fixture();self.assertEqual(len(cp.verify_round_transition_sample(s,image)),64)
    def test_missing_setup_prefix_or_restore(self):
        image,s=fixture()
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_round_transition_sample(bad,image)
    def test_forged_signatures(self):
        for i in range(len(cp.DISPATCH_OPS)+len(cp.PREFIX)):
            image,s=fixture();pc,op=s['ops'][i];op^=1;s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_round_transition_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture()
        for reg in list(range(8,17))+[18,19]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_round_transition_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture()
        for i in range(len(cp.SAVE_INDICES)):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_round_transition_sample(bad,image)
    def test_wrong_entry_return_or_setup(self):
        image,s=fixture()
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.subTest(field=field),self.assertRaises(AssertionError):cp.verify_round_transition_sample(bad,image)
    def test_changed_or_forged_literal(self):
        for page,off in [(1,0x934),(2,0x14c),(3,(cp.TABLE+4*cp.INDEX)&4095),(4,(cp.SCENE+10)&4095)]:
            image,s=fixture();base,pre,post=s['pages'][page];pre=bytearray(pre);pre[off]^=1;s['pages'][page]=(base,bytes(pre),post)
            with self.subTest(page=page),self.assertRaises(AssertionError):cp.verify_round_transition_sample(s,image)



if __name__=='__main__':unittest.main()
