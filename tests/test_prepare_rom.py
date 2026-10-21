"""Synthetic archive tests: no game data or external dependencies."""
from __future__ import annotations

import hashlib
import importlib.util
from pathlib import Path
import stat
import sys
import tempfile
import unittest
from unittest.mock import patch
import warnings
import zipfile

SPEC = importlib.util.spec_from_file_location(
    "prepare_rom", Path(__file__).resolve().parents[1] / "tools/prepare_rom.py")
assert SPEC and SPEC.loader
rom = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = rom
SPEC.loader.exec_module(rom)


class PrepareRomTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name).resolve()
        self.archive = self.root / "sample.zip"
        self.content = b"synthetic disc bytes\x00"
        self.expected = {"disc.bin": rom.Identity(
            len(self.content), hashlib.sha1(self.content).hexdigest())}

    def make_zip(self, entries):
        with zipfile.ZipFile(self.archive, "w", zipfile.ZIP_DEFLATED) as zf:
            for name, content in entries:
                zf.writestr(name, content)

    def test_valid_archive_verification_has_no_output_writes(self):
        self.make_zip([("disc.bin", self.content)])
        before = set(self.root.iterdir())
        result = rom.inspect_archive(self.archive, self.expected)
        self.assertEqual(result["disc.bin"]["sha256"], hashlib.sha256(self.content).hexdigest())
        self.assertEqual(before, set(self.root.iterdir()))

    def test_wrong_size_and_hash(self):
        for data, message in ((b"short", "wrong size"), (b"x" * len(self.content), "wrong SHA-1")):
            with self.subTest(message=message):
                self.make_zip([("disc.bin", data)])
                with self.assertRaisesRegex(rom.PreparationError, message):
                    rom.inspect_archive(self.archive, self.expected)

    def test_traversal_and_nested_names(self):
        for name in ("../disc.bin", "/disc.bin", "a/disc.bin", "a\\disc.bin", "C:disc.bin"):
            with self.subTest(name=name):
                self.make_zip([(name, self.content)])
                with self.assertRaisesRegex(rom.PreparationError, "unsafe or nested"):
                    rom.inspect_archive(self.archive, self.expected)

    def test_symlink_member(self):
        member = zipfile.ZipInfo("disc.bin")
        member.create_system = 3
        member.external_attr = (stat.S_IFLNK | 0o777) << 16
        self.make_zip([(member, self.content)])
        with self.assertRaisesRegex(rom.PreparationError, "not a regular file"):
            rom.inspect_archive(self.archive, self.expected)

    def test_duplicate_missing_and_unexpected_entries(self):
        cases = [([("disc.bin", self.content), ("disc.bin", self.content)], "duplicate"),
                 ([], "missing required"), ([("surprise.txt", b"a")], "unexpected")]
        for entries, message in cases:
            with self.subTest(message=message), warnings.catch_warnings():
                warnings.simplefilter("ignore", UserWarning)
                self.make_zip(entries)
                with self.assertRaisesRegex(rom.PreparationError, message):
                    rom.inspect_archive(self.archive, self.expected)

    def test_optional_cue_bounded(self):
        self.make_zip([("disc.bin", self.content), (rom.OPTIONAL_CUE, b"FILE disc.bin BINARY")])
        self.assertIn(rom.OPTIONAL_CUE, rom.inspect_archive(self.archive, self.expected))
        self.make_zip([("disc.bin", self.content), (rom.OPTIONAL_CUE, b"a" * 65537)])
        with self.assertRaisesRegex(rom.PreparationError, "exceeds 64 KiB"):
            rom.inspect_archive(self.archive, self.expected)

    def test_publish_preserves_conflicts_and_reuses_identical_file(self):
        source, target = self.root / "source", self.root / "rom/disc.bin"
        source.write_bytes(self.content)
        identity = rom.digest_file(source)
        rom.publish(source, target, identity)
        self.assertEqual(target.read_bytes(), self.content)
        rom.publish(source, target, identity)
        target.write_bytes(b"local data")
        with self.assertRaisesRegex(rom.PreparationError, "preserved unchanged"):
            rom.publish(source, target, identity)
        self.assertEqual(target.read_bytes(), b"local data")

    def test_symlink_destination_rejected(self):
        directory = self.root / "real"
        directory.mkdir()
        link = self.root / "linked"
        try:
            link.symlink_to(directory, target_is_directory=True)
        except OSError:
            self.skipTest("symlinks unavailable")
        source = self.root / "source"
        source.write_bytes(self.content)
        with self.assertRaisesRegex(rom.PreparationError, "symlink destination"):
            rom.publish(source, link / "disc.bin", rom.digest_file(source))
        self.assertFalse((directory / "disc.bin").exists())

    def fake_extract(self, stage):
        target = stage / "extract/gamedata/test.bin"
        target.parent.mkdir(parents=True)
        target.write_bytes(b"extracted synthetic data")
        return []

    def test_prepare_idempotent_and_local_only(self):
        self.make_zip([("disc.bin", self.content)])
        repo = self.root / "repo"
        repo.mkdir()
        (repo / "docs").mkdir()
        (repo / "docs/files.md").write_text("original tracked manifest")
        with patch.object(rom, "EXPECTED", self.expected), patch.object(
                rom, "extract_staged", self.fake_extract):
            first = rom.prepare(self.archive, repo)
            second = rom.prepare(self.archive, repo)
        self.assertEqual(first, second)
        self.assertEqual((repo / "docs/files.md").read_text(), "original tracked manifest")
        self.assertTrue((repo / "extract/rom_manifest.json").is_file())
        self.assertEqual(list((repo / "extract").glob(".rom-import-*")), [])

    def test_conflicting_extracted_file_prevents_track_publication(self):
        self.make_zip([("disc.bin", self.content)])
        repo = self.root / "repo"
        target = repo / "extract/gamedata/test.bin"
        target.parent.mkdir(parents=True)
        target.write_bytes(b"valuable local data")
        with patch.object(rom, "EXPECTED", self.expected), patch.object(
                rom, "extract_staged", self.fake_extract):
            with self.assertRaisesRegex(rom.PreparationError, "preserved unchanged"):
                rom.prepare(self.archive, repo)
        self.assertEqual(target.read_bytes(), b"valuable local data")
        self.assertFalse((repo / "rom/disc.bin").exists())
        self.assertEqual(list((repo / "extract").glob(".rom-import-*")), [])


if __name__ == "__main__":
    unittest.main()
