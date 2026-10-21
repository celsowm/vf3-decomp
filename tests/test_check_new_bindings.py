import contextlib
import io
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import check_new_bindings as gate


class BindingGateTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.patch = mock.patch.object(gate, "REPO", self.root)
        self.patch.start()
        (self.root / "tools").mkdir()
        (self.root / "docs").mkdir()
        (self.root / "docs/decomp_status.csv").write_text("entry,status\n0x8c000001,ported\n")
        self.bindings = {"0x8c000001": {"golden": "fixture.cases", "test": "build/own-test.exe", "strict": True}}
        self.write_bindings()

    def tearDown(self):
        self.patch.stop()
        self.temp.cleanup()

    def write_bindings(self):
        (self.root / "tools/golden_bindings.json").write_text(json.dumps(self.bindings))

    def main(self, args):
        with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            return gate.main(args)

    def test_invalid_ref_does_not_become_empty_success(self):
        failed = subprocess.CompletedProcess([], 128, "", "unknown revision")
        with mock.patch.object(gate.subprocess, "run", return_value=failed):
            self.assertEqual(self.main(["--only-new-since", "missing-ref"]), 2)

    def test_unknown_explicit_pc_is_error(self):
        self.assertEqual(self.main(["--pc", "0x8c000002"]), 2)

    def test_pc_selection_keeps_all_campaign_corpora(self):
        self.bindings["holdout:0x8c000001"] = dict(self.bindings["0x8c000001"])
        self.write_bindings()
        with mock.patch.object(gate, "run", return_value=("pc", "PASS", "")) as run:
            self.assertEqual(self.main(["--pc", "0x8c000001"]), 0)
            self.assertEqual(run.call_count, 2)

    def test_new_ledger_pc_without_binding_is_error(self):
        old = subprocess.CompletedProcess([], 0, "entry,status\n", "")
        (self.root / "docs/decomp_status.csv").write_text("entry,status\n0x8c000002,ported\n")
        with mock.patch.object(gate.subprocess, "run", return_value=old):
            self.assertEqual(self.main(["--only-new-since", "HEAD"]), 2)

    def test_legitimate_no_new_entries_runs_nothing(self):
        old = subprocess.CompletedProcess([], 0, (self.root / "docs/decomp_status.csv").read_text(), "")
        with mock.patch.object(gate.subprocess, "run", return_value=old) as run:
            self.assertEqual(self.main(["--only-new-since", "HEAD"]), 0)
            self.assertEqual(run.call_count, 1)

    def test_existing_pc_promotion_selects_replay(self):
        for prior_status in ("parked-partial-replay", "ported-stub"):
            with self.subTest(prior_status=prior_status):
                old = subprocess.CompletedProcess([], 0, f"entry,status\n0x8c000001,{prior_status}\n", "")
                with mock.patch.object(gate.subprocess, "run", return_value=old), \
                     mock.patch.object(gate, "run", return_value=("pc", "PASS", "")) as replay:
                    self.assertEqual(self.main(["--only-new-since", "HEAD"]), 0)
                    self.assertEqual(replay.call_count, 1)

    def test_native_name_resolves_legacy_exe_manifest(self):
        executable = self.root / "build/own-test"
        executable.parent.mkdir()
        executable.touch()
        self.assertEqual(gate.resolve_test("build/own-test.exe"), executable)

    def test_multiconfig_ambiguity_needs_explicit_selection(self):
        for config in ("Debug", "Release"):
            path = self.root / "build" / config / "own-test.exe"
            path.parent.mkdir(parents=True)
            path.touch()
        with self.assertRaisesRegex(ValueError, "ambiguous"):
            gate.resolve_test("build/own-test.exe")
        self.assertEqual(gate.resolve_test("build/own-test.exe", config="Release"),
                         self.root / "build/Release/own-test.exe")

    def test_explicit_config_never_uses_stale_direct_build(self):
        direct = self.root / "build/own-test"
        direct.parent.mkdir()
        direct.touch()
        self.assertIsNone(gate.resolve_test("build/own-test.exe", config="Release"))
        selected = self.root / "build/Release/own-test.exe"
        selected.parent.mkdir()
        selected.touch()
        self.assertEqual(gate.resolve_test("build/own-test.exe", config="Release"), selected)
        self.assertEqual(gate.resolve_test("build/Release/own-test.exe", config="Release"), selected)

    def test_quotes_and_windows_backslashes_are_preserved(self):
        args = gate.test_arguments({"test": r'"C:\build dir\test.exe" "arg with spaces" 0x123'})
        self.assertEqual(args, [r"C:\build dir\test.exe", "arg with spaces", "0x123"])
        self.assertEqual(gate.test_arguments({"test": ["test", "$(not-a-shell)"]}), ["test", "$(not-a-shell)"])

    def test_each_binding_uses_own_test_and_args(self):
        executable = self.root / "build/own-test"
        executable.parent.mkdir()
        executable.touch()
        (self.root / "fixture.cases").write_bytes(b"fixture")
        spec = {"test": 'build/own-test.exe "arg with spaces" 0x8c000001', "golden": "fixture.cases", "strict": True}
        complete = subprocess.CompletedProcess([], 0, "checks passed\n", "")
        with mock.patch.object(gate.subprocess, "run", return_value=complete) as run:
            self.assertEqual(gate.run("0x8c000001", spec)[1], "PASS")
            self.assertEqual(run.call_args.args[0], [str(executable), "arg with spaces", "0x8c000001", str(self.root / "fixture.cases")])
            self.assertEqual(run.call_args.kwargs["env"]["VF3_STRICT_REPLAY"], "1")
            self.assertNotIn("shell", run.call_args.kwargs)

    def test_missing_evidence_and_spawn_error_fail(self):
        executable = self.root / "build/own-test"
        executable.parent.mkdir()
        executable.touch()
        self.assertEqual(gate.run("pc", self.bindings["0x8c000001"])[1], "MISSING-GOLDEN")
        (self.root / "fixture.cases").touch()
        self.assertEqual(gate.run("pc", self.bindings["0x8c000001"])[1], "EMPTY-GOLDEN")
        (self.root / "fixture.cases").write_bytes(b"fixture")
        with mock.patch.object(gate.subprocess, "run", side_effect=PermissionError("not executable")):
            self.assertEqual(gate.run("pc", self.bindings["0x8c000001"])[1], "EXEC-ERROR")

    def test_empty_manifest_is_not_a_pass(self):
        self.bindings = {}
        self.write_bindings()
        self.assertEqual(self.main([]), 2)


if __name__ == "__main__":
    unittest.main()
