"""External evidence roots preserve all proof gates and explicit path scope."""
import hashlib
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import promote_tenpp_batch as promote


class EvidencePathsTests(unittest.TestCase):
    def test_workspace_names_and_hash_format_unchanged(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);case=root/'corpus/f_00000000.cases';case.parent.mkdir();case.write_text('case')
            with patch.object(promote,'ROOT',root):
                self.assertEqual(promote.evidence_name(case),'corpus/f_00000000.cases')
                expected=hashlib.sha256(('corpus/f_00000000.cases\\0'+hashlib.sha256(case.read_bytes()).hexdigest()+'\\n').encode()).hexdigest()
                self.assertEqual(promote.artifacts(case),dict(count=1,sha256=expected))

    def test_external_cache_requires_declared_root(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);workspace=root/'workspace';cache=root/'cache';case=cache/'corpus/f_00000000.cases'
            case.parent.mkdir(parents=True);case.write_text('case')
            with patch.object(promote,'ROOT',workspace):
                with self.assertRaises(ValueError):promote.artifacts(case)
                self.assertEqual(promote.evidence_name(case,[cache]),case.resolve().as_posix())
                self.assertEqual(promote.artifacts(case,[cache])['count'],1)

    def test_sibling_prefix_cannot_escape_root(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name)
            with patch.object(promote,'ROOT',root/'workspace'),self.assertRaises(ValueError):
                promote.evidence_name(root/'cache-other/cases',[root/'cache'])


if __name__=='__main__':unittest.main()
