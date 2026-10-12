"""Exact probes preserve the executed alias and seed only captured input values."""
from contextlib import redirect_stdout
import io
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
from capsule_repeat_batch import main


class CapsuleRepeatBatchTests(unittest.TestCase):
    def setUp(self):
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        self.root = Path(directory.name)
        self.raw = self.root / 'original.bin'
        self.prefix = self.root / 'repeat'
        before = [0]*63
        before[18] = 0x40001
        page = bytearray(4096)
        struct.pack_into('<I', page, 16, 0xaabbccdd)
        self.raw.write_bytes(b'VF3CAP7\0' + struct.pack('<Q7I', 1, 0x8c07cf3e,
            0xc0432e4, 0, 1, 1, 63, 0) + struct.pack('<63I', *before)
            + struct.pack('<63I', *([0x11223344]*63)) + struct.pack('<I', 0xc400000)
            + page + bytes([0x11])*4096 + struct.pack('<2I', 0xc07cf3e, 9))

    def run_generator(self):
        argv = ['capsule_repeat_batch.py', str(self.raw), '--id', '1', '--transfer',
                '0xc07cf3e', '--prefix', str(self.prefix)]
        with patch.object(sys, 'argv', argv), redirect_stdout(io.StringIO()):
            main()

    def test_actual_pc_alias_and_valid_patch_directives(self):
        self.run_generator()
        text = self.prefix.with_suffix('.patch').read_text().splitlines()
        self.assertEqual(text[:2], ['entry 0x8c0432e2 0x8c07cf3e', 'target 0x8c0432e2 0x0c07cf3e'])
        self.assertTrue(all(line.split()[0] in ('entry', 'target', 'reg', 'ram') for line in text))

    def test_full_input_page_not_expected_output_is_seeded(self):
        self.run_generator()
        text = self.prefix.with_suffix('.patch').read_text()
        self.assertIn('ram 0x8c0432e2 0x0c400010 0xaabbccdd', text)
        self.assertEqual(sum(line.startswith('ram ') for line in text.splitlines()), 1024)
        self.assertNotIn('0x11223344', text)
        self.assertNotIn('0x11111111', text)

    def test_existing_probe_evidence_is_preserved(self):
        self.prefix.with_suffix('.patch').write_text('retained original evidence')
        with self.assertRaises(AssertionError):
            self.run_generator()
        self.assertEqual(self.prefix.with_suffix('.patch').read_text(), 'retained original evidence')


if __name__ == '__main__':
    unittest.main()
