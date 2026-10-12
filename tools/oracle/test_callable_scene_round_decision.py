"""Round caller proofs reject changed tables, save prefixes and either tail."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_scene_round_decision as proof


class SceneRoundCallerTests(unittest.TestCase):
    def setUp(self):
        self.image=bytearray(0x110000)
        ops=[(proof.DISPATCH+2*n,op) for n,op in enumerate(proof.DISPATCH_OPS)]
        ops += [(proof.ENTRY+2*n,op) for n,op in enumerate(proof.PREFIX)]
        ops += list(proof.RESTORE)+[(0x8c099060,0x2fe6),(0x8c099062,0x2fd6)]
        ops += list(proof.AUDIO_TAIL)+[(0x8c097ff4,9),(0x8c09803c,0xb),(0x8c09803e,9)]
        for pc,op in ops:struct.pack_into('<H',self.image,(pc&0x1fffffff)-0xc010000,op)
        for pc,value in ((0x8c096934,proof.SCENE),(0x8c096938,0x80000000),(0x8c09693c,proof.TABLE),
                         (proof.TABLE+4*54,proof.ENTRY&0x1fffffff),(0x8c099190,0x0c097ff4)):
            struct.pack_into('<I',self.image,(pc&0x1fffffff)-0xc010000,value)
        pages=[]
        for base in (0xc096000,0xc097000,0xc098000,0xc099000,0xc10b000):
            data=bytes(self.image[base-0xc010000:base-0xc010000+4096]);pages.append((base,data,data))
        scene=bytearray(4096);scene[(proof.SCENE+10)&4095]=54;pages.append((0xc29b000,bytes(scene),bytes(scene)))
        before=[0]*63;before[15]=0xc690100;before[16]=0xc0432e4
        for reg in range(8,15):before[reg]=0xc400000+16*reg
        self.sample=dict(entry=proof.DISPATCH,exitpc=before[16],flags=0,nstate=63,device=[],ops=ops,
            before=struct.pack('<63I',*before),after=struct.pack('<63I',*before),pages=pages)

    def verify(self):proof.verify_scene_round_sample(self.sample,bytes(self.image))

    def test_original_round_caller(self):self.verify()

    def test_changed_scene_slot(self):
        n=next(n for n,p in enumerate(self.sample['pages']) if p[0]==0xc10b000)
        base,a,z=self.sample['pages'][n];a=bytearray(a);a[(proof.TABLE+4*54)&4095]^=4
        self.sample['pages'][n]=(base,bytes(a),z)
        with self.assertRaises(AssertionError):self.verify()

    def test_missing_save_prefix(self):
        self.sample['ops'].pop(len(proof.DISPATCH_OPS)+3)
        with self.assertRaises(AssertionError):self.verify()

    def test_changed_round_stack_restoration(self):
        at=self.sample['ops'].index(proof.RESTORE[0]);self.sample['ops'].pop(at+5)
        with self.assertRaises(AssertionError):self.verify()

    def test_changed_audio_tail_destination(self):
        at=self.sample['ops'].index(proof.AUDIO_TAIL[-1]);self.sample['ops'][at+1]=(0x8c097ff6,9)
        with self.assertRaises(AssertionError):self.verify()

    def test_changed_saved_register(self):
        after=list(struct.unpack('<63I',self.sample['after']));after[12]^=1;self.sample['after']=struct.pack('<63I',*after)
        with self.assertRaises(AssertionError):self.verify()

    def test_device_access_is_rejected(self):
        self.sample['device']=[(0x5f6900,4,0,0)]
        with self.assertRaises(AssertionError):self.verify()

    def test_interrupt_mask_change_is_rejected(self):
        after=list(struct.unpack('<63I',self.sample['after']));after[17]^=0x10
        self.sample['after']=struct.pack('<63I',*after)
        with self.assertRaises(AssertionError):self.verify()

    def test_division_status_requires_observed_division(self):
        after=list(struct.unpack('<63I',self.sample['after']));after[17]^=0x100
        self.sample['after']=struct.pack('<63I',*after)
        with self.assertRaises(AssertionError):self.verify()


if __name__=='__main__':unittest.main()
