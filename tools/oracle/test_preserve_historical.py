"""Historical preservation rejects mutation and keeps source closures distinct."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import preserve_historical as archive
from ram_clipping_batch_audit import reference


class PreserveTests(unittest.TestCase):
    def test_mutable_workspace_dependency_is_copied(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name)/'workspace';source=root/'tools/proof_input.json';source.parent.mkdir(parents=True);source.write_text('input')
            proof=root/'proof.json';proof.write_text(json.dumps(dict(references=[reference(source)])))
            out=Path(name)/'archive';manifest=Path(name)/'manifest.json'
            with patch.object(archive,'ROOT',root):result=archive.preserve([proof],[],out,manifest)
            source.write_text('later')
            self.assertEqual((out/'tools/proof_input.json').read_text(),'input')
            self.assertTrue(result['historical_only'])
            self.assertFalse(result['coverage_credit'])

    def test_changed_dependency_rejected_before_output(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);source=root/'input';source.write_text('input')
            proof=root/'proof.json';proof.write_text(json.dumps(dict(references=[reference(source)])))
            source.write_text('changed');out=root/'archive'
            with self.assertRaises(ValueError):archive.preserve([proof],[],out,root/'manifest.json')
            self.assertFalse(out.exists())

    def test_existing_archive_is_not_replaced(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);out=root/'archive';out.mkdir()
            with self.assertRaises(FileExistsError):archive.preserve([],[],out,root/'manifest.json')


if __name__=='__main__':unittest.main()
