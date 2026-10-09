"""Acceptance mutations must invalidate a proof while development stays intact."""
import hashlib
from pathlib import Path
import tempfile
import unittest
from audit_matrix_batch import check_proof_archive


class ProofArchiveAuditTests(unittest.TestCase):
    def test_independent_acceptance_mutation_and_missing_file(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            cases = [root / 'development.cases', root / 'acceptance.cases']
            archives = []
            for path in cases:
                path.write_bytes(b'original observation')
                file_hash = hashlib.sha256(b'original observation').hexdigest()
                archive_hash = hashlib.sha256((path.name+'\\0'+file_hash+'\\n').encode()).hexdigest()
                archives.append(dict(count=1, sha256=archive_hash))
                check_proof_archive(path, archives[-1], True, root)
            cases[1].write_bytes(b'changed observation')
            check_proof_archive(cases[0], archives[0], True, root)
            with self.assertRaisesRegex(AssertionError, 'proof corpus changed'):
                check_proof_archive(cases[1], archives[1], True, root)
            cases[1].unlink()
            with self.assertRaisesRegex(AssertionError, 'proof artifact count changed'):
                check_proof_archive(cases[1], archives[1], True, root)


if __name__ == '__main__':
    unittest.main()
