"""Reject forged literal targets, argument setup, saves and frame returns."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_replay_record as cp

def fixture(call=None):
    call=cp.CALLS[0] if call is None else call
    returned=call+4
    image=bytearray(0x100000)
    ops=[(call,0xb0e7 if call==cp.CALLS[0] else 0xb0e2),(call+2,0x64d3)]
    ops += [(cp.PARENT+2*i,op) for i,op in enumerate(cp.PREFIX)]+[(0x8c0a9046,0xdb0f)]+list(cp.RESTORE)
    for pc,op in ops:struct.pack_into('<H',image,pc-0x8c010000,op)
    struct.pack_into('<I',image,0x0c0a9084-0x0c010000,0x0c29bcc4)
    before=list(range(63));before[7]=0;before[15]=0x0c550100;before[14]=0x0c530000;before[10]=0x0c540000
    after=list(before);after[16]=returned
    pre=bytes(4096);post=bytearray(pre)
    for i,index in enumerate(cp.SAVE_INDICES):struct.pack_into('<I',post,0x100-4*(i+1),returned if index==16 else before[index])
    sample=dict(entry=call,exitpc=returned,flags=0,nstate=63,
        before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),ops=ops,
        pages=[(0x0c550000,pre,bytes(post)),(0x0c0a9000,bytes(image[0x99000:0x9a000]),bytes(image[0x99000:0x9a000]))])
    return image,sample

class ReplayRecordTests(unittest.TestCase):
    def test_original_caller(self):
        for call in cp.CALLS:
            image,s=fixture(call);self.assertEqual(len(cp.verify_replay_record_sample(s,image)),64)
    def test_missing_setup_prefix_or_restore(self):
        image,s=fixture()
        for i in range(len(s['ops'])):
            bad=copy.deepcopy(s);del bad['ops'][i]
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_record_sample(bad,image)
    def test_forged_signatures(self):
        for i in range(2+len(cp.PREFIX)):
            image,s=fixture();pc,op=s['ops'][i];op^=1;s['ops'][i]=(pc,op);struct.pack_into('<H',image,pc-0x8c010000,op)
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_record_sample(s,image)
    def test_changed_saved_architecture(self):
        image,s=fixture()
        for reg in list(range(8,17))+[18,19]+list(range(33,53)):
            bad=copy.deepcopy(s);post=bytearray(bad['after']);struct.pack_into('<I',post,4*reg,0xffffffff);bad['after']=bytes(post)
            with self.subTest(reg=reg),self.assertRaises(AssertionError):cp.verify_replay_record_sample(bad,image)
    def test_corrupted_stack_save(self):
        image,s=fixture()
        for i in range(len(cp.SAVE_INDICES)):
            bad=copy.deepcopy(s);base,pre,post=bad['pages'][0];post=bytearray(post);post[0x100-4*(i+1)]^=1;bad['pages'][0]=(base,pre,bytes(post))
            with self.subTest(i=i),self.assertRaises(AssertionError):cp.verify_replay_record_sample(bad,image)
    def test_wrong_entry_return_or_setup(self):
        image,s=fixture()
        for field in ['entry','exitpc']:
            bad=copy.deepcopy(s);bad[field]+=2
            with self.subTest(field=field),self.assertRaises(AssertionError):cp.verify_replay_record_sample(bad,image)
    def test_changed_or_forged_literal(self):
        image,s=fixture();base,pre,post=s['pages'][1];pre=bytearray(pre);pre[0x84]^=1;s['pages'][1]=(base,bytes(pre),post)
        with self.assertRaises(AssertionError):cp.verify_replay_record_sample(s,image)


if __name__=='__main__':unittest.main()
