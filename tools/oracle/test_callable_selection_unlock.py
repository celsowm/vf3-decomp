"""Selection proof rejects missing save prefixes and incorrect tail frames."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_selection_unlock as proof


class SelectionCallerTests(unittest.TestCase):
    def setUp(self):
        self.image=bytearray(0xc0000)
        self.ops=[(proof.START,0xa017),(proof.START+2,0x6ef6)]+[(proof.ENTRY+2*n,op) for n,op in enumerate(proof.PREFIX[2:])]
        self.ops += [(proof.RTS,0xb),(proof.RTS+2,0x6ef6)]
        for pc,op in self.ops:struct.pack_into('<H',self.image,(pc&0x1fffffff)-0xc010000,op)
        before=[0]*63;before[14]=0xc4a4321;before[15]=0xc690100;before[16]=0xc0432e4
        after=before.copy();after[14]=0xc4b1234;after[15]+=4
        a=bytearray(4096);z=bytearray(4096)
        struct.pack_into('<I',a,0x100,after[14]);struct.pack_into('<I',z,0x100,after[14]);struct.pack_into('<I',z,0xe4,before[16])
        self.sample=dict(entry=proof.START,exitpc=before[16],flags=0,nstate=63,device=[],ops=self.ops,
            before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),pages=[(0xc690000,bytes(a),bytes(z))])

    def verify(self):proof.verify_selection_sample(self.sample,bytes(self.image))

    def test_original_tail_and_return(self):self.verify()

    def test_missing_tail_delay_or_callee_save(self):
        original=copy.deepcopy(self.sample)
        for index in (1,2,8):
            self.sample=copy.deepcopy(original);self.sample['ops'].pop(index)
            with self.subTest(index=index),self.assertRaises(AssertionError):self.verify()

    def test_frame_restores_tail_popped_r14(self):
        values=list(struct.unpack('<63I',self.sample['after']));values[14]=0xc4a4321
        self.sample['after']=struct.pack('<63I',*values)
        with self.assertRaises(AssertionError):self.verify()

    def test_wrong_saved_return(self):
        base,a,z=self.sample['pages'][0];z=bytearray(z);z[0xe4]^=1
        self.sample['pages']=[(base,a,bytes(z))]
        with self.assertRaises(AssertionError):self.verify()

    def test_missing_actual_return_or_device_tape(self):
        original=copy.deepcopy(self.sample);self.sample['ops'][-2]=(proof.RTS-2,0xb)
        with self.assertRaises(AssertionError):self.verify()
        self.sample=original;self.sample['device']=[(0x005f6900,4,0,0)]
        with self.assertRaises(AssertionError):self.verify()


if __name__=='__main__':unittest.main()
