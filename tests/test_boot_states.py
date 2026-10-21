"""Boot gate regressions, using synthetic logs rather than game captures."""
import importlib.util
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('boot_states', ROOT / 'tools/boot_states.py')
boot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(boot)


def summary(ok=1, failed='00000000', unowned=0, frames=12, oob=0):
    return (f'after the wait: ok {ok}, pc 0c059bee, failed {failed}, '
            f'unowned {unowned} (first {failed}), 0 BIOS calls, {frames} vblanks, oob {oob}\n')


class BootGateTest(unittest.TestCase):
    def test_clean_completion(self):
        self.assertEqual(boot.parse_result(summary(), 0, 60)['result'], 'ok')

    def test_historical_cap_does_not_hide_unowned_call(self):
        r = boot.parse_result(summary(0, '0c0597ca', 1, 700), 0, 700)
        self.assertEqual(r['result'], 'fail')
        self.assertEqual(r['cap_reached'], 1)

    def test_clean_cap_is_inconclusive(self):
        self.assertEqual(boot.parse_result(summary(frames=60), 0, 60)['result'], 'capped')

    def test_process_failure_overrides_clean_log(self):
        self.assertEqual(boot.parse_result(summary(), 2, 60)['result'], 'fail')

    def test_oob_failure_overrides_cap(self):
        self.assertEqual(boot.parse_result(summary(frames=60, oob=1), 0, 60)['result'], 'fail')

    def test_earlier_oob_is_not_hidden(self):
        text = '  hop 0: pc 0c000000 oob 3\n' + summary()
        self.assertEqual(boot.parse_result(text, 0, 60)['result'], 'fail')

    def test_missing_summary_is_not_success(self):
        self.assertEqual(boot.parse_result('GD model: status 0, 0 sectors left, cur 00000000', 0, 60)['result'], 'no result')

    def test_native_and_multiconfig_executable(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            native = root / 'build/vf3boot'
            native.parent.mkdir()
            native.touch()
            with mock.patch.object(boot, 'REPO', root):
                self.assertEqual(boot.executable(), native)
                native.unlink()
                win = root / 'build/Release/vf3boot.exe'
                win.parent.mkdir()
                win.touch()
                self.assertEqual(boot.executable(), win)

    def test_all_three_captures_required(self):
        with tempfile.TemporaryDirectory() as tmp:
            with mock.patch.object(boot, 'A', Path(tmp)):
                (Path(tmp) / 'golden_bootV_vf3_21.bin').touch()
                row = boot.run(21, 60, 1)
                self.assertEqual(row['result'], 'no capture')
                self.assertIn('golden_bootI', row['detail'])

    def test_cli_missing_capture_exits_nonzero_and_writes_report(self):
        with tempfile.TemporaryDirectory() as tmp:
            output = Path(tmp) / 'report.csv'
            p = subprocess.run([sys.executable, str(ROOT / 'tools/boot_states.py'),
                                '--states', '999999', '--csv', str(output)], capture_output=True)
            self.assertEqual(p.returncode, 1)
            self.assertIn('no capture', output.read_text())


if __name__ == '__main__':
    unittest.main()
