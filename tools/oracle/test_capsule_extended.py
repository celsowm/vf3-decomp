"""Extended record parsing retains legacy bounds and architectural requirements."""
from pathlib import Path
import struct
import tempfile
import unittest
from capsules import records


class ExtendedCapsuleTests(unittest.TestCase):
    def capture(self, magic, count, state=63, payload=True):
        entry = 0xc010000
        data = magic + struct.pack('<Q7I', 1, entry, entry+2, 0, 0, count, state, 0)
        if payload:
            data += bytes(state*8) + struct.pack('<II', entry, 9)*count
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        path = Path(directory.name) / 'sample.bin'
        path.write_bytes(data)
        return path

    def test_explicit_extended_format_accepts_long_trace(self):
        samples = list(records(self.capture(b'VF3CAP7\0', 100001)))
        self.assertEqual(len(samples[0]['ops']), 100001)
        self.assertEqual(samples[0]['nstate'], 63)

    def test_legacy_format_still_rejects_long_trace(self):
        with self.assertRaisesRegex(ValueError, 'invalid record sizes'):
            list(records(self.capture(b'VF3CAP6\0', 100001, payload=False)))

    def test_extended_bound_and_full_state_fail_closed(self):
        for count, state in ((500001, 63), (1, 55)):
            with self.subTest(count=count, state=state), self.assertRaisesRegex(ValueError, 'invalid record sizes'):
                list(records(self.capture(b'VF3CAP7\0', count, state, payload=False)))


if __name__ == '__main__':
    unittest.main()
