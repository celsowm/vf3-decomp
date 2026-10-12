"""Original RAM supplements cannot waive return, state or device evidence."""
import copy
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch
import ram_holdout_supplement as proof


class SupplementalEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.image = bytearray(0x7af50)
        for pc, op in ((0xc08acc0,9),(0xc08af4c,11),(0xc08af4e,0x6ef6)):
            struct.pack_into('<H',self.image,pc-0xc010000,op)
        image = self.root/'extract/gamedata/1ST_READ.BIN'; image.parent.mkdir(parents=True); image.write_bytes(self.image)
        self.observer = self.file('observer.exe',b'original')
        freeze = self.file('freeze.json',b'{}')
        self.recipe = self.json('recipe.json',{'development_freeze':proof.reference(freeze)})
        self.primary = {'runs':[]}; self.supp = dict(execution='original_sh4',mode='nonrollback_one_shot',passed=True,
            provenance={str(self.observer):proof.digest(self.observer),str(self.recipe):proof.digest(self.recipe)},runs=[])
        self.samples = {}; extras = []
        for index in range(2):
            state = self.file(f's{index}.state',bytes([index]))
            self.primary['runs'].append(dict(state=str(state),returncode=0,frame_complete=True,
                emulator=str(self.observer),emulator_sha256=proof.digest(self.observer)))
            raw = self.file(f'r{index}.bin',b'capsule'); log = self.file(f'r{index}.log',b'original log')
            patch_file = self.file(f'r{index}.patch',b'typed input'); audio = self.file(f'r{index}.audio',b'captured audio')
            summary = dict(started=1,completed=1,incomplete=[],unaccounted=0,one_shot_done=True,explicit_return_only=True,restores=0)
            self.json(f'r{index}.bin.summary.json',summary)
            row = dict(passed=True,returncode=0,flags=0,device_accesses=0,capsule=str(raw),capsule_sha256=proof.digest(raw),
                state=str(state),case=f'case{index}',log=str(log),log_sha256=proof.digest(log),patch_sha256=proof.digest(patch_file),
                audio=proof.reference(audio),summary=summary)
            self.supp['runs'].append(row)
            extras.append({**row,'frame_complete':False,'one_shot_done':True})
            registers = [0]*63; registers[16] = 0xc0432e4
            self.samples[str(raw)] = dict(flags=0,nstate=63,device=[],entry=0xc08acc0,exitpc=0xc0432e4,
                before=struct.pack('<63I',*registers),after=struct.pack('<63I',*registers),pages=[],
                ops=[(0xc08acc0,9),(0xc08af4c,11),(0xc08af4e,0x6ef6)])
        self.primary_path = self.json('primary.json',self.primary)
        self.supp_path = self.json('supp.json',self.supp)
        self.batch = dict(mode='original_ram_supplemented',original_frame_campaign=proof.reference(self.primary_path),
            original_ram_supplement=proof.reference(self.supp_path),supplement_inputs=proof.reference(self.recipe),runs=self.primary['runs']+extras)

    def file(self,name,data):
        path=self.root/name; path.write_bytes(data); return path

    def json(self,name,data):
        return self.file(name,json.dumps(data).encode())

    def validate(self):
        with patch.object(proof,'ROOT',self.root), patch.object(proof,'records',side_effect=lambda p:iter([self.samples[str(p)]])):
            proof.validate(self.batch,True)

    def reseal(self):
        self.supp_path.write_text(json.dumps(self.supp)); self.batch['original_ram_supplement']=proof.reference(self.supp_path)

    def test_original_explicit_returns_in_both_states(self): self.validate()

    def test_cannot_claim_game_frames(self):
        self.batch['runs'][2]['frame_complete']=True
        with self.assertRaises(AssertionError): self.validate()

    def test_changed_original_evidence(self):
        Path(self.supp['runs'][0]['log']).write_text('altered')
        with self.assertRaises(AssertionError): self.validate()

    def test_device_access_rejected_in_manifest_and_capsule(self):
        self.supp['runs'][0]['device_accesses']=1; self.reseal()
        with self.assertRaises(AssertionError): self.validate()
        self.supp['runs'][0]['device_accesses']=0; self.reseal()
        self.samples[self.supp['runs'][0]['capsule']]['device']=[(0x005f6900,4,0,0)]
        with self.assertRaises(AssertionError): self.validate()

    def test_missing_second_state(self):
        self.batch['runs'].pop(); self.supp['runs'].pop(); self.reseal()
        with self.assertRaises(AssertionError): self.validate()

    def test_original_return_and_callee_preservation_required(self):
        sample=self.samples[self.supp['runs'][0]['capsule']]
        original=copy.deepcopy(sample); sample['ops'].pop()
        with self.assertRaises(AssertionError): self.validate()
        sample.update(original); registers=list(struct.unpack('<63I',sample['after'])); registers[14]=1
        sample['after']=struct.pack('<63I',*registers)
        with self.assertRaises(AssertionError): self.validate()

    def test_accounting_cannot_be_repaired_by_valid_other_calls(self):
        row=self.supp['runs'][0]; row['summary']['incomplete']=[{'entry':'0xc08acc0'}]
        Path(row['capsule']+'.summary.json').write_text(json.dumps(row['summary'])); self.reseal()
        with self.assertRaises(AssertionError): self.validate()

    def test_nonoriginal_opcode_rejected(self):
        self.samples[self.supp['runs'][0]['capsule']]['ops'][0]=(0xc08acc0,0)
        with self.assertRaises(AssertionError): self.validate()


if __name__=='__main__': unittest.main()
