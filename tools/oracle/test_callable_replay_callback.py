"""Reject forged literal targets, argument setup, saves and frame returns."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_replay_callback as cp

def fixture(call=None):
    call=cp.CALLS[0] if call is None else call
    returned=call+12
    image=bytearray(0x100000)
    ops=[(call+2*i,op) for i,op in enumerate((0x60e2,0xc801,0x8902,0x53e3,0x430b,0x64e3))]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+[(0x8c0a8e24,0xd34b)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    struct.pack_into('<I',image,0x0c0a8f54-0x0c010000,0x0c0c6742)
    struct.pack_into('<I',image,0x0c0a86a8-0x0c010000,0x0c0a8e18)
    struct.pack_into('<HH',image,0x0c0a8668-0x0c010000,0xd30f,0x1d33)
    before=list(range(63));before[7]=0;before[15]=0x0c550100;before[14]=0x0c500000;before[10]=0x0c540000
    after=list(before);after[16]=returned
    pre=bytes(4096);post=bytearray(pre)
    for i,index in enumerate(cp.SAVE_INDICES):struct.pack_into('<I',post,0x100-4*(i+1),returned if index==16 else before[index])
    sample=dict(entry=call,exitpc=returned,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,
        pages=[(0x0c550000,pre,bytes(post)),(0x0c0a8000,bytes(image[0x98000:0x99000]),bytes(image[0x98000:0x99000])),
               (0x0c500000,struct.pack('<4I',1,0,0,0x0c0a8e18)+bytes(4080),struct.pack('<4I',1,0,0,0x0c0a8e18)+bytes(4080))])
    return image,sample

class ReplayCallbackTests(unittest.TestCase):
    def test_original_caller(self):
        for call in cp.CALLS:
            image,s=fixture(call);self.assertEqual(len(cp.verify_replay_callback_sample(s,image)),64)
    def test_missing_setup_prefix_or_restore(self):
        image,s=fixture()
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(bad,image)
    def test_forged_signatures(self):
        for i in range(6+len(cp.PREFIX)):
            image,s=fixture();pc,op=s['ops'][i];op^=1;s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture()
        for reg in list(range(8,17))+[18,19]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture()
        for i in range(len(cp.SAVE_INDICES)):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(bad,image)
    def test_wrong_entry_return_or_setup(self):
        image,s=fixture()
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.subTest(field=field),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(bad,image)
    def test_wrong_descriptor_flags_or_target(self):
        image,s=fixture()
        for offset in [0,12]:
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][2];pre=bytearray(pre);pre[offset]^=1;bad['pages'][2]=(base,bytes(pre),post)
            with self.subTest(offset=offset),self.assertRaises(AssertionError):cp.verify_replay_callback_sample(bad,image)
    def test_changed_or_forged_literal(self):
        image,s=fixture();base,pre,post=s['pages'][1];pre=bytearray(pre);pre[0xf54]^=1;s['pages'][1]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_replay_callback_sample(s,image)


if __name__=='__main__':unittest.main()
