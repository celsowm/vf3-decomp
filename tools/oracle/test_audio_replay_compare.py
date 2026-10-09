import json
import struct
import tempfile
import unittest
from pathlib import Path
from audio_determinism import describe, sha
from audio_replay_compare import evaluate


class LiveComparisonTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)

    def fixture(self, name, execution, changed_exit=False, marker=True):
        cap, audio, log, manifest = [self.root/f'{name}.{ext}' for ext in
                                     ['capsule', 'audio', 'log', 'json']]
        before, after = bytes(252), bytearray(252)
        if changed_exit:
            struct.pack_into('<I', after, 0, 123)
        cap.write_bytes(b'VF3CAP6\0'+struct.pack('<Q7I', 1, 0x8c040f1e,
            0x8c0432e4, 0, 0, 1, 63, 0)+before+after+
            struct.pack('<2I', 0x8c040f1e, 9))
        with audio.open('wb') as f:
            f.write(b'VF3AUD1\0')
            for ordinal in [1, 2]:
                f.write(struct.pack('<QQ4I', ordinal, 100, 0x8c040f1e, 9, 448, 1000))
                for kind, data in enumerate([bytes(252), bytes(16*1024*1024),
                    b'aica', b'cache', b'scheduler', bytes(4), bytes(24)], 1):
                    f.write(struct.pack('<2I', kind, len(data)))
                    f.write(data)
        log.write_text('[vf3audiobridge] executing C queue with live devices' if marker else '')
        data = dict(passed=True, execution=execution, provenance={'state': 'abc'},
            runs=[dict(state='state', case='queue', repetition=1, passed=True,
                returncode=0, summary=dict(one_shot=True, one_shot_done=True,
                    started=1, completed=1, incomplete=[], unaccounted=0, restores=0),
                flags=0, capsule=str(cap), capsule_sha256=sha(cap),
                audio=describe(audio), log=str(log), log_sha256=sha(log), aica_events=0)])
        manifest.write_text(json.dumps(data))
        return manifest

    def test_real_exit_mismatch_fails_even_when_audio_matches(self):
        a = self.fixture('original', 'original_sh4')
        b = self.fixture('c', 'readable_c_queue', changed_exit=True)
        result = evaluate(a, b)
        self.assertFalse(result['passed'])
        self.assertTrue(result['comparisons'][0]['audio']['equal'])
        self.assertIn('after', result['comparisons'][0]['different_fields'])

    def test_changed_artifact_hash_rejected(self):
        a = self.fixture('original', 'original_sh4')
        b = self.fixture('c', 'readable_c_queue')
        (self.root/'c.capsule').write_bytes(b'changed evidence')
        with self.assertRaisesRegex(ValueError, 'changed evidence'):
            evaluate(a, b)

    def test_c_execution_required(self):
        a = self.fixture('original', 'original_sh4')
        b = self.fixture('c', 'readable_c_queue', marker=False)
        with self.assertRaisesRegex(ValueError, 'C execution marker missing'):
            evaluate(a, b)

    def test_missing_pair_rejected(self):
        a = self.fixture('original', 'original_sh4')
        b = self.fixture('c', 'readable_c_queue')
        data = json.loads(b.read_text())
        data['runs'][0]['case'] = 'other_input'
        b.write_text(json.dumps(data))
        with self.assertRaisesRegex(ValueError, 'same corpus'):
            evaluate(a, b)

    def test_restored_process_rejected(self):
        a = self.fixture('original', 'original_sh4')
        b = self.fixture('c', 'readable_c_queue')
        data = json.loads(b.read_text())
        data['runs'][0]['summary']['restores'] = 1
        b.write_text(json.dumps(data))
        with self.assertRaisesRegex(ValueError, 'completion missing or restored'):
            evaluate(a, b)


if __name__ == '__main__':
    unittest.main()
