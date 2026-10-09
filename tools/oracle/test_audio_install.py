import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
import install


class InstallerTests(unittest.TestCase):
    def test_upgrade_removes_duplicate_hook_and_is_idempotent(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            source = root/'hw/sh4/interpr/sh4_interpreter.cpp'
            source.parent.mkdir(parents=True)
            source.write_text('\tif (vf3AudioBefore(addr,op,ctx)) throw debugger::Stop();\n'
                '\tvf3OracleBefore(addr, op, ctx);\n'
                '\tif (vf3OracleOneShotDone()) throw debugger::Stop();\n'
                '\tvf3OracleBefore(addr, op, ctx);\n'
                '\tvf3TraceInstr(addr, op);\n')
            with patch.object(install, 'CORE', root):
                install.normalize_observer()
                fixed = source.read_bytes()
                install.normalize_observer()
                self.assertEqual(fixed, source.read_bytes())
            self.assertEqual(fixed.count(b'vf3OracleBefore('), 1)
            self.assertEqual(fixed.count(b'vf3AudioBefore('), 1)
            self.assertEqual(fixed.count(b'vf3OracleOneShotDone('), 1)


if __name__ == '__main__':
    unittest.main()
