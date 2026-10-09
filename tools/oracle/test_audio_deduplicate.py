import os
from pathlib import Path
import tempfile
import unittest
from audio_deduplicate import retain_hard_link
from audio_determinism import sha


class EvidenceCacheTests(unittest.TestCase):
    def test_external_cache_requires_explicit_root(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp)
            first,second=root/'first',root/'second'
            first.write_bytes(b'complete captured bytes')
            second.write_bytes(first.read_bytes())
            with self.assertRaisesRegex(ValueError,'local and regular'):
                retain_hard_link(first,second,sha(first))
            self.assertTrue(retain_hard_link(first,second,sha(first),[root]))
            self.assertEqual(os.stat(first).st_ino,os.stat(second).st_ino)

    def test_changed_bytes_are_preserved_and_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp)
            first,second=root/'first',root/'second'
            first.write_bytes(b'actual output')
            second.write_bytes(b'different output')
            with self.assertRaisesRegex(ValueError,'changed during deduplication'):
                retain_hard_link(first,second,sha(first),[root])
            self.assertEqual(first.read_bytes(),b'actual output')
            self.assertEqual(second.read_bytes(),b'different output')


if __name__=='__main__': unittest.main()
