"""Long captures require controls pinned to the exact recorder executable."""
import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from golden_batch import observer_record_limit


class ObserverRecordLimitTests(unittest.TestCase):
    def setUp(self):
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        self.root = Path(directory.name)
        self.executable = self.root / 'observer.exe'
        self.executable.write_bytes(b'fixed recorder')
        self.dependency = self.root / 'control.raw'
        self.dependency.write_bytes(b'fixed original controls')
        self.proof = dict(diagnostic_controls_passed=True, unchanged_original_simulation=True,
            observer=dict(path=str(self.executable), sha256=hashlib.sha256(self.executable.read_bytes()).hexdigest()),
            controls=[dict(architecture_ram_and_trace_equal=True, audio_checkpoint_equal=True)]*8,
            maximum_recorded_instructions=500000,
            references=[dict(path=str(self.dependency), sha256=hashlib.sha256(self.dependency.read_bytes()).hexdigest())])

    def check(self):
        path = self.root / 'proof.json'
        path.write_text(json.dumps(self.proof))
        return observer_record_limit(self.executable, path)

    def test_legacy_default_and_explicit_extended_controls(self):
        self.assertEqual(observer_record_limit(self.executable), 100000)
        self.assertEqual(self.check(), 500000)

    def test_another_executable_or_changed_controls_rejected(self):
        self.executable.write_bytes(b'changed recorder')
        with self.assertRaises(AssertionError): self.check()
        self.executable.write_bytes(b'fixed recorder')
        self.dependency.write_bytes(b'changed original controls')
        with self.assertRaises(AssertionError): self.check()

    def test_missing_or_failed_control_window_rejected(self):
        self.proof['controls'].pop()
        with self.assertRaises(AssertionError): self.check()
        self.proof['controls'].append(dict(architecture_ram_and_trace_equal=False, audio_checkpoint_equal=True))
        with self.assertRaises(AssertionError): self.check()


if __name__ == '__main__':
    unittest.main()
