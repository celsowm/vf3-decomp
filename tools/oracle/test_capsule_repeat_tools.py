"""Keep diagnostic original repeats separate from valid equality evidence."""
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch
import capsule_repeat_recipe as recipe
import compare_original_samples as comparison


def specimen():
    return dict(id=1,entry=0x0c0c3210,exitpc=0x0c0432e4,nstate=63,flags=0,device=[],
        before=struct.pack('<63I',*range(63)),after=struct.pack('<63I',*range(63)),
        pages=[(0x0c650000,b'\0'*4,b'\1'*4)],ops=[(0x0c0c38c2,0x000b)])


class RepeatTests(unittest.TestCase):
    def test_recipe_sets_fpscr_before_float_banks(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);raw=root/'raw.bin';raw.write_bytes(b'identity')
            with patch.object(recipe,'records',return_value=iter([specimen()])):
                result=recipe.prepare(raw,1,root/'recipe.json',0x0c0c38c2)
            regs=result['cases'][0]['registers']
            self.assertEqual(next(iter(regs)),'fpscr')
            self.assertEqual(len(regs),55)
            self.assertEqual(result['expected_inactive_gpr_bank'],list(range(55,63)))
            self.assertEqual(result['cases'][0]['memory'],{'0xc650000':0})
            self.assertFalse(result['coverage_credit'])

    def test_recipe_rejects_invalid_sample_and_missing_transfer(self):
        with tempfile.TemporaryDirectory() as name:
            for flags,transfer in ((16,0x0c0c38c2),(0,0x0c012345)):
                sample=specimen();sample['flags']=flags
                with patch.object(recipe,'records',return_value=iter([sample])),self.assertRaises(ValueError):
                    recipe.prepare('unused',1,Path(name)/'out.json',transfer)

    def run_comparison(self,left,right):
        with tempfile.TemporaryDirectory() as name:
            raw=Path(name)/'raw.bin';raw.write_bytes(b'identity')
            with patch.object(comparison,'records',side_effect=[iter([left]),iter([right])]):
                return comparison.compare(raw,1,raw,1)

    def test_identical_inputs_different_memory_outputs(self):
        left=specimen();right=specimen();right['pages']=[(0x0c650000,b'\0'*4,b'\2'*4)]
        result=self.run_comparison(left,right)
        self.assertTrue(result['observable_disagreement'])
        self.assertEqual(result['input_register_differences'],[])

    def test_changed_inactive_bank_is_not_ambiguity_proof(self):
        left=specimen();right=specimen()
        words=list(range(63));words[55]=0x1234;right['before']=struct.pack('<63I',*words)
        result=self.run_comparison(left,right)
        self.assertFalse(result['captured_inputs_equal'])
        self.assertFalse(result['observable_disagreement'])
        self.assertEqual(result['input_register_differences'],[55])

    def test_equal_outputs_are_not_ambiguity_proof(self):
        result=self.run_comparison(specimen(),specimen())
        self.assertTrue(result['captured_inputs_equal'])
        self.assertTrue(result['captured_outputs_equal'])
        self.assertFalse(result['observable_disagreement'])


if __name__=='__main__':unittest.main()
