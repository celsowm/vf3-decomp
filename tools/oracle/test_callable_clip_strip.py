"""Strip contracts reject invented tables, missing actual returns and frames."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import callable_clip_strip as proof


class StripCallerTests(unittest.TestCase):
    def setUp(self):
        self.image=bytearray(0x50000)
        self.slot=16;self.entry,self.rts=proof.ROWS[self.slot]
        self.ops=[(proof.START+2*i,op) for i,op in enumerate(proof.PREFIX)]
        self.ops += [(self.entry,0x2fe6),(self.entry+2,0x4f22),(self.rts,0xb),(self.rts+2,0x6ef6)]
        for pc,op in self.ops:self.opcode(pc,op)
        for pc,op in {0x0c055da0:0xe380,0x0c055da4:0x633c,0x0c055da6:0xd20e,0x0c055dae:0x6023,0x0c055db0:0x303c,0x0c055db2:0xc203}.items():self.opcode(pc,op)
        struct.pack_into('<I',self.image,0x55de0-0x10000,0xc055a20)
        struct.pack_into('<I',self.image,(proof.TABLE&0x1fffffff)-0xc010000+self.slot*4,self.entry&0x1fffffff)
        before=[0]*63;before[4]=0xc400000;before[14]=proof.TABLE;before[15]=0xc690100;before[18]=0x40001;before[58]=0xc16b8c8
        after=before.copy();after[16]=proof.RETURN&0x1fffffff;after[3]=before[58];after[12]=0xc450060
        pages={base:[bytearray(4096),bytearray(4096)] for base in (0xc400000,0xc055000,0xc690000,0xc16b000)}
        struct.pack_into('<H',pages[0xc400000][0],0,self.slot)
        struct.pack_into('<I',pages[0xc055000][0],(proof.TABLE&4095)+self.slot*4,self.entry&0x1fffffff)
        struct.pack_into('<2I',pages[0xc690000][1],0xf8,after[16],proof.TABLE)
        struct.pack_into('<I',pages[0xc16b000][1],0x8c8,after[12])
        self.sample=dict(entry=proof.START,exitpc=proof.RETURN,flags=0,nstate=63,device=[],ops=self.ops,
            before=struct.pack('<63I',*before),after=struct.pack('<63I',*after),pages=[(base,bytes(a),bytes(z)) for base,(a,z) in pages.items()])

    def opcode(self,pc,op):struct.pack_into('<H',self.image,(pc&0x1fffffff)-0xc010000,op)

    def verify(self):return proof.verify_strip_sample(self.sample,bytes(self.image))

    def test_original_dispatch_and_actual_return(self):self.verify()

    def test_frozen_body_boundary_cannot_replace_actual_rts(self):
        self.sample['ops'][-2]=(self.rts-14,0xb)
        with self.assertRaises(AssertionError):self.verify()

    def test_wrong_table_or_missing_callee_prefix(self):
        saved=copy.deepcopy(self.sample);values=list(struct.unpack('<63I',self.sample['before']));values[14]+=4
        self.sample['before']=struct.pack('<63I',*values)
        with self.assertRaises(AssertionError):self.verify()
        self.sample=saved;self.sample['ops'][8]=(self.entry+2,0x4f22)
        with self.assertRaises(AssertionError):self.verify()

    def test_stack_or_publication_mismatch(self):
        saved=copy.deepcopy(self.sample)
        for address in (0xc6900f8,0xc16b8c8):
            self.sample=copy.deepcopy(saved)
            self.sample['pages']=[(base,a,b'\xff'+z[1:]) if base==address&~4095 else (base,a,z) for base,a,z in self.sample['pages']]
            # Mutate the contract word rather than a neighboring unused byte.
            pages=[]
            for base,a,z in self.sample['pages']:
                if base==address&~4095:
                    changed=bytearray(z);changed[address-base]^=1;z=bytes(changed)
                pages.append((base,a,z))
            self.sample['pages']=pages
            with self.subTest(address=address),self.assertRaises(AssertionError):self.verify()

    def test_device_or_changed_original_instruction_rejected(self):
        self.sample['device']=[(0x005f6900,4,0,0)]
        with self.assertRaises(AssertionError):self.verify()
        self.sample['device']=[];self.sample['ops'][0]=(proof.START,0)
        with self.assertRaises(AssertionError):self.verify()


if __name__=='__main__':unittest.main()
