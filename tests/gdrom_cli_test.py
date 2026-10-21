"""ROM-free executable regression: python gdrom_cli_test.py /path/to/vf3gdrom."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest


BINARY = None
FIRST_LBA = 0x81ADB - 150


class GdromCliTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.gdi = self.root / "synthetic.gdi"
        self.gdi.write_text(f'1\n1 {FIRST_LBA} 4 2048 "track with spaces.bin" 0\n')
        self.track = self.root / "track with spaces.bin"

    def run_cli(self, *args):
        return subprocess.run([str(BINARY), *map(str, args)], cwd=self.root,
                              capture_output=True, text=True, timeout=10)

    def test_missing_descriptor_skips(self):
        result = self.run_cli(self.root / "absent.gdi")
        self.assertEqual(result.returncode, 77, result.stdout + result.stderr)
        self.assertIn("missing disc descriptor", result.stderr)

    def test_descriptor_without_track_files_skips(self):
        result = self.run_cli(self.gdi)
        self.assertEqual(result.returncode, 77, result.stdout + result.stderr)
        self.assertIn("missing track", result.stderr)
        self.assertNotIn("full cycle", result.stdout)

    def test_malformed_existing_descriptor_fails(self):
        for data in ("not a descriptor\n", "1\ninvalid track\n", "-1\n1 0 4 2048 \"x.bin\" 0\n"):
            with self.subTest(data=data):
                self.gdi.write_text(data)
                result = self.run_cli(self.gdi)
                self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                self.assertIn("invalid disc descriptor", result.stderr)

    def test_present_truncated_track_fails(self):
        self.track.write_bytes(b"corrupt")
        result = self.run_cli(self.gdi)
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("truncated track", result.stderr)

    def test_missing_track_does_not_hide_another_corrupt_track(self):
        self.gdi.write_text(f'2\n1 0 4 2048 "missing.bin" 0\n'
                            f'2 {FIRST_LBA} 4 2048 "track with spaces.bin" 0\n')
        self.track.write_bytes(b"corrupt")
        result = self.run_cli(self.gdi)
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("truncated track", result.stderr)

    def test_explicit_missing_dump_is_error_even_when_tracks_absent(self):
        result = self.run_cli(self.gdi, self.root / "missing-state.txt")
        self.assertEqual(result.returncode, 2, result.stdout + result.stderr)
        self.assertIn("cannot open requested state", result.stderr)

    def test_synthetic_disc_runs_transfer_checks(self):
        self.track.write_bytes(b"".join(bytes([i]) * 2048 for i in range(0x4B)))
        result = self.run_cli(self.gdi)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("full cycle: 15 steps, 75 sectors, 0 differ", result.stdout)
        self.assertIn("syscall cycle: 7 sectors, 0 differ", result.stdout)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit("usage: gdrom_cli_test.py /path/to/vf3gdrom")
    BINARY = Path(sys.argv[1]).resolve(strict=True)
    unittest.main(argv=[sys.argv[0]])
