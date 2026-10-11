"""Address ranges alone must not qualify hidden helpers for frozen credit."""
import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import select_next

class InventorySelection(unittest.TestCase):
    def run_selection(self,listed):
        with tempfile.TemporaryDirectory() as folder:
            root=Path(folder);analysis=root/'extract/analysis';analysis.mkdir(parents=True)
            (analysis/'coverage.json').write_text(json.dumps({'ported_spans':[]}))
            (analysis/'function_body_ranges.csv').write_text('entry,start,end\n8c010010,8c010010,8c010014\n')
            (analysis/'funcs_1ST_READ.unsc.bin.csv').write_text('entry,size,name\n'+('8c010010,4,example\n' if listed else ''))
            corpus=root/'corpus';corpus.mkdir()
            sources=[str(root/'one.cap'),str(root/'two.cap')]
            (corpus/'capsule_manifest.json').write_text(json.dumps({'runs':[], 'entries':{'0x8c010010':[{'sources':[{'source':s} for s in sources]}]}}))
            (corpus/'batch_manifest.json').write_text(json.dumps({'runs':[{'capsule':s,'state':str(i),'play':None} for i,s in enumerate(sources)]}))
            output=root/'watch.txt';log=io.StringIO()
            with patch.object(select_next,'ROOT',root),contextlib.redirect_stdout(log):
                select_next.select([corpus],output,1)
            return output.read_text(),log.getvalue()
    def test_hidden_helper_has_no_percentage_credit(self):
        watch,log=self.run_selection(False)
        self.assertNotIn('pc 0x',watch)
        self.assertIn("outside frozen inventory: ['0x8c010010']",log)
        self.assertIn('potential union +0 B',log)
    def test_frozen_function_still_selected(self):
        watch,log=self.run_selection(True)
        self.assertIn('pc 0x8c010010',watch)
        self.assertIn('potential union +4 B',log)
        self.assertIn('outside frozen inventory: []',log)

if __name__=='__main__':unittest.main()
