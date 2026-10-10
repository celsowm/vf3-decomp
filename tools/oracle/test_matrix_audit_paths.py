"""Proof runners may record absolute paths while bindings remain repo relative."""
from pathlib import Path
import tempfile
import unittest
from audit_matrix_batch import choose_bound_proof


class ProofPathTests(unittest.TestCase):
    def test_absolute_report_matches_relative_binding(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)
            proof=dict(cases=str(root/'extract/corpus/f_123.cases'))
            self.assertIs(choose_bound_proof({'dev':proof},'extract/corpus/f_123.cases',root),proof)

    def test_relative_report_selects_the_bound_independent_corpus(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)
            dev=dict(cases='extract/dev/f_123.cases')
            accept=dict(cases='extract/accept/f_123.cases')
            self.assertIs(choose_bound_proof({'dev':dev,'accept':accept},dev['cases'],root),dev)

    def test_different_corpus_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaisesRegex(AssertionError,'no strict proof'):
                choose_bound_proof({'dev':dict(cases='extract/dev/f_123.cases')},
                                   'extract/accept/f_123.cases',Path(directory))


if __name__=='__main__':unittest.main()
