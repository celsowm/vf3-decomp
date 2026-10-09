import copy
import json
import tempfile
import unittest
from pathlib import Path
from audio_corpus import validate_batch
from audio_determinism import sha


class AudioBatchGateTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        root = Path(self.tmp.name)
        source = dict(capsule='capture.capsule', state='state26', case='layout',
                      returncode=0, passed=True,
                      summary=dict(one_shot_done=True, restores=0, incomplete=[]))
        values = dict(comparison=dict(passed=True, positive_aica_crossings=1,
                                     comparisons=[{}]),
                      original=dict(passed=True, runs=[source]),
                      c=dict(passed=True, execution='readable_c_channels', runs=[source]))
        refs = {}
        for key, value in values.items():
            path = root/f'{key}.json'
            path.write_text(json.dumps(value))
            refs[key] = dict(path=str(path), sha256=sha(path))
        self.batch = dict(mode='process_owned_audio', live_audio_proof=refs,
            runs=[dict(capsule=source['capsule'], state=source['state'], case=source['case'],
                       returncode=0, frame_complete=False, **source['summary'])])

    def test_verified_one_shot_does_not_need_frame_completion(self):
        validate_batch(self.batch)

    def test_legacy_batch_still_requires_complete_frame(self):
        with self.assertRaises(AssertionError):
            validate_batch(dict(runs=[dict(returncode=0, frame_complete=False)]))

    def test_false_frame_claim_rejected(self):
        self.batch['runs'][0]['frame_complete'] = True
        with self.assertRaisesRegex(AssertionError, 'completed game frame'):
            validate_batch(self.batch)

    def test_changed_source_rejected(self):
        self.batch['runs'][0]['capsule'] = 'unverified.capsule'
        with self.assertRaisesRegex(AssertionError, 'source changed'):
            validate_batch(self.batch)

    def test_changed_live_proof_rejected(self):
        Path(self.batch['live_audio_proof']['comparison']['path']).write_text('{}')
        with self.assertRaisesRegex(AssertionError, 'changed live audio proof'):
            validate_batch(self.batch)

    def test_rollback_rejected(self):
        self.batch['runs'][0]['restores'] = 1
        with self.assertRaises(AssertionError):
            validate_batch(self.batch)


if __name__ == '__main__':
    unittest.main()
