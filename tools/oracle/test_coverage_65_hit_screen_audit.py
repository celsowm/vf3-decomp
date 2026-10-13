import csv
import json
import tempfile
import unittest
from pathlib import Path

from coverage_65_hit_screen_audit import audit


class HitScreenAuditTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.watch = self.root / "watch.txt"
        self.watch.write_text("pc 0x8c001000\npc 0x8c001010\n")
        self.observer = self.root / "observer.exe"
        self.observer.write_bytes(b"pinned observer")
        self.image = self.root / "1ST_READ.BIN"
        self.image.write_bytes(b"original image")
        self.state = self.root / "state.bin"
        self.state.write_bytes(b"state")
        self.hits = self.root / "hits.csv"
        with self.hits.open("w", newline="") as stream:
            writer = csv.writer(stream)
            writer.writerow(["entry", "hits"])
            writer.writerow(["0x8c001000", 2])
            writer.writerow(["0x8c001010", 0])
        self.manifest = self.root / "batch.json"
        self.manifest.write_text(json.dumps({
            "watch": str(self.watch),
            "runs": [{"name": "s1", "state": str(self.state), "hits": str(self.hits),
                      "returncode": 0, "emulator_returncode": 0,
                      "frame_complete": True, "ran_frames": 120,
                      "expected_frames": 120}],
        }))

    def tearDown(self):
        self.temp.cleanup()

    def test_complete_run_is_reported_as_diagnostic_only(self):
        report = audit([self.manifest], self.watch, self.observer, self.image)
        self.assertFalse(report["coverage_credit"])
        self.assertEqual(report["runs"][0]["natural_hits"]["0x8c001000"], 2)

    def test_incomplete_run_is_rejected(self):
        data = json.loads(self.manifest.read_text())
        data["runs"][0]["ran_frames"] = 119
        self.manifest.write_text(json.dumps(data))
        with self.assertRaisesRegex(ValueError, "incomplete frame run"):
            audit([self.manifest], self.watch, self.observer, self.image)

    def test_hit_rows_must_match_watch_list(self):
        self.hits.write_text("entry,hits\n0x8c001000,2\n")
        with self.assertRaisesRegex(ValueError, "differ from watch list"):
            audit([self.manifest], self.watch, self.observer, self.image)


if __name__ == "__main__":
    unittest.main()
