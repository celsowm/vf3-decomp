import contextlib
import hashlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import port_preflight as preflight


class PreflightTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.write("tools/golden_bindings.json", json.dumps({
            "0x8c000001": {"golden": "extract/analysis/shared.cases", "strict": True, "test": "build/own-test.exe"},
            "0x8c000002": {"golden": "extract/analysis/shared.cases", "test": "build/own-test.exe"},
        }).encode())
        self.write("docs/decomp_status.csv", b"entry,status\n0x8c000001,ported\n0x8c000001,ported\n0x8c000002,pending\n")

    def tearDown(self):
        self.temp.cleanup()

    def write(self, relative, data=b"fixture"):
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)

    @staticmethod
    def case_line():
        return (" ".join(["00000000"] * 74) +
                " entry.bin 1 0x0c000000 0x4 exit.bin 1 0x0c000000 0x4\n").encode()

    def test_counts_distinct_files_and_duplicate_ledger_rows(self):
        report = preflight.inspect(self.root)
        self.assertEqual(report["ledger"]["unique_ported_entries"], 1)
        self.assertEqual(report["ledger"]["duplicate_ported_rows"], 1)
        self.assertEqual(report["bindings"]["total"], 2)
        self.assertEqual(report["bindings"]["marked_strict"], 1)
        self.assertEqual(report["bindings"]["golden_files"]["required"], 1)
        self.assertEqual(report["native_tick"]["required"], 39)
        self.assertEqual(report["boot"]["required"], 17)
        self.assertFalse(report["checks_executed"])
        self.assertFalse(report["prerequisites_present"])

    def test_empty_file_is_missing_and_wrong_hash_is_rejected(self):
        self.write("extract/analysis/shared.cases", b"")
        self.write("extract/gamedata/1ST_READ.BIN", b"wrong build")
        report = preflight.inspect(self.root)
        self.assertEqual(report["bindings"]["golden_files"]["present"], 0)
        self.assertEqual(report["rom"]["executables"][0]["status"], "mismatch")

    def test_all_synthetic_prerequisites_only_claim_presence(self):
        report = preflight.inspect(self.root)
        for group in (report["bindings"]["golden_files"], report["coverage_inputs"], report["native_tick"], report["boot"]):
            for relative in group["missing"]:
                self.write(relative)
        self.write("extract/analysis/shared.cases", self.case_line())
        self.write("extract/analysis/entry.bin", b"1234")
        self.write("extract/analysis/exit.bin", b"1234")
        for state in report["boot"]["missing_gd_states"]:
            self.write(state["one_of"][1])
        for executable in report["test_executables"]:
            self.write(executable["command"])
        self.write("rom/vf3.gdi")
        data = b"synthetic executable, no game code"
        self.write("extract/gamedata/1ST_READ.BIN", data)
        self.write("extract/exe/1ST_READ.unsc.bin", data)
        with mock.patch.object(preflight, "RETAIL_SHA256", hashlib.sha256(data).hexdigest()):
            result = preflight.inspect(self.root)
        self.assertTrue(result["prerequisites_present"])
        self.assertEqual(result["root"], self.root.resolve().as_posix())
        self.assertTrue(all("\\" not in item["resolved"] for item in result["test_executables"]))
        self.assertFalse(result["checks_executed"])
        self.assertEqual(result["bindings"]["golden_files"]["bindings_with_present_file"], 2)
        self.assertNotIn("coverage_percent", result)

    def test_matrix_sidecars_required_even_before_cases_arrive(self):
        manifest = {"0x8c000001": {"golden": "extract/analysis/shared.cases",
                                   "test": "build/vf3matrixfamily.exe 0x8c000001", "strict": True}}
        self.write("tools/golden_bindings.json", json.dumps(manifest).encode())
        evidence = preflight.inspect(self.root)["bindings"]["case_evidence"]
        self.assertEqual(evidence["matrix_sidecars"]["required"], 3)
        self.assertEqual(evidence["matrix_sidecars"]["present"], 0)
        self.assertEqual(evidence["matrix_sidecars"]["missing"], [
            "extract/analysis/shared.extra.bin", "extract/analysis/shared.xfin.bin",
            "extract/analysis/shared.xfout.bin",
        ])
        self.assertEqual(evidence["ram_blobs"]["required"], 0)  # absent case contents are not guessed

        self.write("extract/analysis/shared.cases", self.case_line())
        self.write("extract/analysis/shared.xfin.bin", bytes(64))
        self.write("extract/analysis/shared.xfout.bin", bytes(64))
        self.write("extract/analysis/shared.extra.bin", bytes(15))
        self.write("extract/analysis/entry.bin", b"12")
        evidence = preflight.inspect(self.root)["bindings"]["case_evidence"]
        self.assertEqual(evidence["matrix_sidecars"]["short"][0]["minimum_bytes"], 16)
        self.assertEqual(evidence["matrix_sidecars"]["short"][0]["path"], "extract/analysis/shared.extra.bin")
        self.assertEqual(evidence["ram_blobs"]["required"], 2)
        self.assertEqual(evidence["ram_blobs"]["short"][0]["minimum_bytes"], 4)
        self.assertEqual(evidence["ram_blobs"]["short"][0]["path"], "extract/analysis/entry.bin")
        self.assertEqual(evidence["ram_blobs"]["missing"], ["extract/analysis/exit.bin"])

    def test_xf_runners_require_only_xf_sidecars_with_per_row_lengths(self):
        for runner in ("vf3bootmix", "vf3fd9ec", "vf3d452"):
            with self.subTest(runner=runner):
                stem = f"extract/analysis/{runner}"
                manifest = {"0x8c000001": {"golden": stem + ".cases", "test": f"build/{runner}.exe"}}
                evidence = preflight.case_evidence(self.root, manifest)
                self.assertEqual(evidence["sidecar_runners"], [runner])
                self.assertEqual(evidence["matrix_sidecars"]["missing"], [stem + ".xfin.bin", stem + ".xfout.bin"])
                self.write(stem + ".cases", self.case_line() * 2)
                self.write(stem + ".xfin.bin", bytes(127))
                self.write(stem + ".xfout.bin", bytes(128))
                evidence = preflight.case_evidence(self.root, manifest)
                self.assertEqual(evidence["matrix_sidecars"]["required"], 2)
                self.assertEqual(evidence["matrix_sidecars"]["missing"], [])
                self.assertEqual(evidence["matrix_sidecars"]["short"], [
                    {"path": stem + ".xfin.bin", "minimum_bytes": 128, "actual_bytes": 127},
                ])

    def test_shared_cases_combine_runner_requirements_without_duplicates(self):
        manifest = {
            "0x8c000001": {"golden": "extract/analysis/shared.cases", "test": "build/vf3matrixfamily 0x8c000001"},
            "holdout:0x8c000001": {"golden": "extract/analysis/shared.cases", "test": r"build\Release\vf3fd9ec.exe"},
        }
        evidence = preflight.case_evidence(self.root, manifest)
        self.assertEqual(evidence["matrix_sidecars"]["required"], 3)
        self.assertEqual(evidence["sidecar_runners"], ["vf3fd9ec", "vf3matrixfamily"])

    def test_custom_bindings_manifest_relative_absolute_and_cli(self):
        original = (self.root / "tools/golden_bindings.json").read_bytes()
        local = "extract/analysis/remapped_bindings.json"
        manifest = {"0x8c000003": {"golden": "extract/analysis/remapped.cases", "test": "build/vf3d452"}}
        self.write(local, json.dumps(manifest).encode())
        relative_report = preflight.inspect(self.root, bindings=local)
        absolute_report = preflight.inspect(self.root, bindings=self.root / local)
        self.assertEqual(relative_report, absolute_report)
        self.assertEqual(relative_report["bindings_manifest"], local)
        self.assertEqual(relative_report["bindings"]["total"], 1)
        self.assertEqual(relative_report["bindings"]["golden_files"]["missing"], ["extract/analysis/remapped.cases"])
        self.assertEqual(preflight.inspect(self.root)["bindings"]["total"], 2)
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            self.assertEqual(preflight.main(["--root", str(self.root), "--bindings", local, "--json"]), 1)
        self.assertEqual(json.loads(output.getvalue()), relative_report)
        self.assertEqual((self.root / "tools/golden_bindings.json").read_bytes(), original)

    def test_missing_custom_bindings_is_error_without_default_fallback(self):
        with contextlib.redirect_stderr(io.StringIO()):
            self.assertEqual(preflight.main(["--root", str(self.root), "--bindings", "missing.json"]), 2)

    def test_malformed_cases_report_parse_error_and_not_ready(self):
        self.write("extract/analysis/shared.cases", b"not a case\n")
        report = preflight.inspect(self.root)
        self.assertFalse(report["prerequisites_present"])
        self.assertEqual(report["bindings"]["case_evidence"]["parse_errors"][0]["line"], 1)

    def test_legacy_case_dependencies_and_optional_exit(self):
        registers = " ".join(["00000000"] * 74)
        line = registers + " entry.bin 0x0c000000 0x4 0x0 0x0 exit.bin 0x0c000000 0x4 0x0 0x0"
        self.assertEqual(preflight.case_dependencies(line), [("entry.bin", 4), ("exit.bin", 4)])
        self.assertEqual(preflight.case_dependencies(registers + " entry.bin 1 0x0c000000 0x4 - 0"), [("entry.bin", 4)])
        with self.assertRaises(ValueError):
            preflight.case_dependencies(registers + " - 0 - 0")

    def test_cli_json_is_read_only_and_returns_missing(self):
        before = sorted(p.relative_to(self.root) for p in self.root.rglob("*"))
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            self.assertEqual(preflight.main(["--root", str(self.root), "--json"]), 1)
        after = sorted(p.relative_to(self.root) for p in self.root.rglob("*"))
        self.assertEqual(before, after)
        self.assertFalse(json.loads(output.getvalue())["checks_executed"])

    def test_invalid_manifest_is_error_not_incomplete(self):
        self.write("tools/golden_bindings.json", b"{}")
        with contextlib.redirect_stderr(io.StringIO()):
            self.assertEqual(preflight.main(["--root", str(self.root)]), 2)


if __name__ == "__main__":
    unittest.main()
