"""Scene table attribution rejects changed slots, save frames and transfers."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_scene_input as proof


class SceneInputCallerTests(unittest.TestCase):
    def setUp(self):
        self.image=bytearray(0x110000)
        ops=[(proof.DISPATCH+2*n,op) for n,op in enumerate(proof.DISPATCH_OPS)]
        ops += [(proof.ENTRY+2*n,op) for n,op in enumerate(proof.PREFIX)]
        ops += list(proof.RESTORE)+[(0x8c097ff4,0x9),(0x8c09803c,0xb),(0x8c09803e,0x9)]
        for pc,op in ops:struct.pack_into('<H',self.image,(pc&0x1fffffff)-0xc010000,op)
        for pc,op,value in ((proof.DISPATCH,proof.DISPATCH_OPS[0],proof.SCENE),
                            (proof.DISPATCH+28,proof.DISPATCH_OPS[14],proof.TABLE)):
            pool=((pc+4)&~3)+4*(op&255)
            struct.pack_into('<I',self.image,(pool&0x1fffffff)-0xc010000,value)
        struct.pack_into('<I',self.image,proof.TABLE+4*proof.INDEX-0xc010000,proof.ENTRY&0x1fffffff)
        struct.pack_into('<I',self.image,0xc0994d0-0xc010000,0xc097ff4)
        before=[0]*63;before[15]=0xc690100;before[16]=0xc0432e4
        for register in range(11,15):before[register]=0xc500000+register*16
        pages=[]
        for base in (0xc096000,0xc098000,0xc099000,0xc10b000):
            data=bytes(self.image[base-0xc010000:base-0xc010000+4096]);pages.append((base,data,data))
        scene=bytearray(4096);scene[(proof.SCENE+10)&4095]=proof.INDEX
        pages.append((0xc29b000,bytes(scene),bytes(scene)))
        a=bytearray(4096);z=bytearray(a)
        for n,register in enumerate((14,13,12,11,16)):struct.pack_into('<I',z,0x100-4*(n+1),before[register])
        pages.append((0xc690000,bytes(a),bytes(z)))
        self.sample=dict(entry=proof.DISPATCH,exitpc=before[16],flags=0,nstate=63,device=[],ops=ops,
            before=struct.pack('<63I',*before),after=struct.pack('<63I',*before),pages=pages)

    def verify(self):proof.verify_scene_input_sample(self.sample,bytes(self.image))

    def test_original_index57_frame(self):self.verify()

    def test_missing_dispatch_delay_or_save(self):
        original=copy.deepcopy(self.sample)
        for index in (19,20,23):
            self.sample=copy.deepcopy(original);self.sample['ops'].pop(index)
            with self.subTest(index=index),self.assertRaises(AssertionError):self.verify()

    def test_changed_original_table_slot(self):
        index=next(n for n,p in enumerate(self.sample['pages']) if p[0]==0xc10b000)
        base,a,z=self.sample['pages'][index];a=bytearray(a);a[(proof.TABLE+4*proof.INDEX)&4095]^=4
        self.sample['pages'][index]=(base,bytes(a),z)
        with self.assertRaises(AssertionError):self.verify()

    def test_wrong_saved_frame_or_register(self):
        base,a,z=self.sample['pages'][-1];z=bytearray(z);z[0xec]^=1
        self.sample['pages'][-1]=(base,a,bytes(z))
        with self.assertRaises(AssertionError):self.verify()

    def test_missing_tail_return_or_device_events(self):
        original=copy.deepcopy(self.sample);self.sample['ops'][-2]=(0x8c09803a,0xb)
        with self.assertRaises(AssertionError):self.verify()
        self.sample=original;self.sample['device']=[(0x005f6900,4,0,0)]
        with self.assertRaises(AssertionError):self.verify()


if __name__=='__main__':unittest.main()
