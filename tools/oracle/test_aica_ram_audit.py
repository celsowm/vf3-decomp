"""Negative checks for the audit that guards original AICA checkpoint evidence."""
import json
import struct
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
import audit_aica_ram as audit


class SoundRamAuditTests(unittest.TestCase):
    def proof(self, directory, mutate=None):
        directory = Path(directory)
        capsule = directory/'calls.bin'
        samples = []
        for value in range(64):
            before = [0]*63
            before[4] = 0xa0801000-0xa05f8000
            before[5] = value
            before[16] = 0x0c0432e4
            after = list(before)
            after[0], after[3], after[4] = 1, 0xa05f8000, 0xa0801000
            samples.append(dict(entry=audit.ENTRY, flags=0, nstate=63,
                before=struct.pack('<63I',*before), after=struct.pack('<63I',*after),
                device=[(0x801000,4,value,1)], pages=[], exitpc=before[16]))
        summary = dict(started=64, completed=64, armed=64, incomplete=[],
            unaccounted=0, non_ram=[], aica_timeslice_aborts=0, aica_page_restores=64)
        if mutate:
            mutate(samples,summary)
        Path(str(capsule)+'.summary.json').write_text(json.dumps(summary))
        runs = [dict(returncode=0,frame_complete=True,rollback_aica_ram=True,
            state=state,play='',capsule=str(capsule)) for state in ['s21','s27']]
        (directory/'batch_manifest.json').write_text(json.dumps(dict(runs=runs)))
        with patch.object(audit,'records',return_value=samples):
            return audit.audit_leaf(directory,'development')

    def test_valid_proof(self):
        with tempfile.TemporaryDirectory() as d:
            self.assertEqual(self.proof(d)['calls'],128)

    def test_wrong_device_value_is_rejected(self):
        with tempfile.TemporaryDirectory() as d, self.assertRaises(AssertionError):
            self.proof(d,lambda samples,summary:samples[0].update(device=[(0x801000,4,123,1)]))

    def test_missing_page_restore_is_rejected(self):
        with tempfile.TemporaryDirectory() as d, self.assertRaises(AssertionError):
            self.proof(d,lambda samples,summary:summary.update(aica_page_restores=63))

    def test_scheduler_rejections_cannot_supply_valid_cases(self):
        def reject(samples,summary):
            for sample in samples:
                sample['flags']=4
            summary['aica_timeslice_aborts']=64
        with tempfile.TemporaryDirectory() as d, self.assertRaises(AssertionError):
            self.proof(d,reject)


if __name__ == '__main__':
    unittest.main()
