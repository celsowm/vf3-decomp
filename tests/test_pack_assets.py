import hashlib
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import pack_assets  # noqa: E402


class AssetPackTests(unittest.TestCase):
    def test_deterministic_pack_and_program_exclusion(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            source = root / "source"
            source.mkdir()
            payloads = {
                "BGM_AKI.BIN": b"DTPKsample-bgm",
                "MKAO_AKI.POL": b"POLsample-model",
                "1ST_READ.BIN": b"SH4-code",
                "SNDDRV.BIN": b"ARM-code",
                "RELOAD.BIN": b"system-code",
            }
            for name, payload in payloads.items():
                (source / name).write_bytes(payload)

            archive_a = root / "a.vfa"
            archive_b = root / "b.vfa"
            manifest_a = pack_assets.pack_assets(source, archive_a)
            pack_assets.pack_assets(source, archive_b)

            self.assertEqual(archive_a.read_bytes(), archive_b.read_bytes())
            self.assertEqual(manifest_a["asset_count"], 2)
            self.assertEqual(manifest_a["excluded_program_files"],
                             ["1ST_READ.BIN", "RELOAD.BIN", "SNDDRV.BIN"])
            self.assertFalse(manifest_a["runtime_disc_required"])
            self.assertFalse(manifest_a["runtime_executable_included"])

            blob = archive_a.read_bytes()
            magic, version, count, index_offset, data_offset = struct.unpack_from(
                "<8sIIQQ", blob, 0)
            self.assertEqual((magic, version, count, index_offset),
                             (pack_assets.MAGIC, 1, 2, 32))
            self.assertGreaterEqual(data_offset, 32 + count * 112)
            entries = {}
            for i in range(count):
                name, offset, size, digest = struct.unpack_from("<64sQQ32s", blob,
                                                                index_offset + i * 112)
                key = name.split(b"\0", 1)[0].decode("ascii")
                data = blob[offset:offset + size]
                self.assertEqual(len(data), size)
                self.assertEqual(hashlib.sha256(data).digest(), digest)
                entries[key] = data
            self.assertEqual(entries, {
                "BGM_AKI.BIN": payloads["BGM_AKI.BIN"],
                "MKAO_AKI.POL": payloads["MKAO_AKI.POL"],
            })
            written_manifest = json.loads(Path(str(archive_a) + ".json").read_text())
            self.assertEqual(written_manifest["asset_count"], 2)

    def test_refuses_to_write_inside_source_tree(self):
        with tempfile.TemporaryDirectory() as tmp:
            source = Path(tmp) / "source"
            source.mkdir()
            (source / "ST01.POL").write_bytes(b"model")
            with self.assertRaises(ValueError):
                pack_assets.pack_assets(source, source / "assets.vfa")
            with self.assertRaises(ValueError):
                pack_assets.pack_assets(source, Path(tmp) / "assets.vfa",
                                        source / "manifest.json")

    def test_asset_names_are_normalized_for_case_insensitive_hosts(self):
        with tempfile.TemporaryDirectory() as tmp:
            source = Path(tmp) / "source"
            source.mkdir()
            (source / "stage.pol").write_bytes(b"model")
            assets, _ = pack_assets.collect_assets(source)
            self.assertEqual([asset.name for asset in assets], ["STAGE.POL"])


if __name__ == "__main__":
    unittest.main()
