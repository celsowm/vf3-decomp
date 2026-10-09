import struct
import tempfile
import unittest
from pathlib import Path
from audio_determinism import compare, checkpoints, emulator_lock, compress_checkpoint, sha


class CheckpointTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)

    def write(self, name, *, pc=0x8c040f1e, change=None, ordinal=1):
        path = self.root/name
        with path.open('wb') as f:
            f.write(b'VF3AUD1\0')
            f.write(struct.pack('<QQ4I', ordinal, 100, pc, 9, 448, 1000))
            for kind in range(1, 8):
                data = {1: bytes(252), 2: bytes(16*1024*1024), 3: b'aica-state',
                        4: b'cache', 5: b'scheduler', 6: bytes(4), 7: bytes(24)}[kind]
                if change and change[0] == kind:
                    value = bytearray(data)
                    value[change[1]] ^= 1
                    data = bytes(value)
                f.write(struct.pack('<2I', kind, len(data)))
                f.write(data)
        return path

    def test_identical_and_changed_register(self):
        a, b = self.write('a'), self.write('b')
        self.assertTrue(compare(a, b)['equal'])
        self.write('b', change=(1, 16))
        self.assertEqual(compare(a, b)['register'], 'r4')

    def test_detects_ram_timer_pcm_and_event_mutations(self):
        a = self.write('a')
        for kind, section in [(2, 'physical_ram'), (3, 'aica'),
                              (6, 'guest_pcm'), (7, 'scheduler_events')]:
            with self.subTest(section=section):
                b = self.write('b', change=(kind, 3))
                result = compare(a, b)
                self.assertFalse(result['equal'])
                self.assertEqual(result['section'], section)
                self.assertEqual(result['offset'], 3)

    def test_misaligned_guest_boundary_rejected(self):
        result = compare(self.write('a'), self.write('b', pc=0x8c040f20))
        self.assertEqual(result['section'], 'identity')

    def test_truncated_and_empty_stream_rejected(self):
        path = self.write('a')
        with path.open('r+b') as f:
            f.truncate(path.stat().st_size-1)
        with self.assertRaises(ValueError):
            list(checkpoints(path))
        path.write_bytes(b'VF3AUD1\0')
        self.assertEqual(compare(self.write('a2'), path)['section'], 'checkpoint_count')

    def test_batch_lock_prevents_staged_state_race(self):
        with emulator_lock(self.root/'flycast.exe'):
            with self.assertRaises(OSError):
                with emulator_lock(self.root/'flycast.exe'):
                    self.fail('second batch acquired the same staging lock')

    def test_archive_preserves_complete_evidence(self):
        raw = self.write('a')
        reference = self.write('b')
        archived, digest = compress_checkpoint(raw)
        self.assertFalse(raw.exists())
        self.assertEqual(digest, sha(reference))
        self.assertTrue(compare(archived, reference)['equal'])


if __name__ == '__main__':
    unittest.main()
