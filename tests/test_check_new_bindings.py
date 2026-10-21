import contextlib
from concurrent.futures import ThreadPoolExecutor
import hashlib
import io
import json
import os
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

    def make_audit_runner(self):
        runner = self.root / "replay.py"
        runner.write_text(
            "import os, pathlib, sys\n"
            "golden = pathlib.Path(sys.argv[2])\n"
            "print('fixture=' + golden.read_text())\n"
            "print('strict=' + str('VF3_STRICT_REPLAY' in os.environ))\n"
            "print('diagnostic stderr', file=sys.stderr)\n"
            "if sys.argv[1] == 'long':\n"
            f"    sys.stdout.write('x' * {gate.OUTPUT_LIMIT + 17})\n"
            f"    sys.stderr.write('y' * {gate.OUTPUT_LIMIT + 31})\n"
            "    sys.exit(0)\n"
            "sys.exit(int(sys.argv[1]))\n", encoding="utf-8")
        (self.root / "fixture.cases").write_bytes(b"synthetic fixture")
        return runner

    def test_report_real_children_hashes_environment_and_failure_exit(self):
        runner = self.make_audit_runner()
        self.bindings = {
            "0x8c000001": {"golden": "fixture.cases", "test": [sys.executable, str(runner), "0"], "strict": True},
            "holdout:0x8c000001": {"golden": "fixture.cases", "test": [sys.executable, str(runner), "7"]},
        }
        self.write_bindings()
        cache = self.root / "build/CMakeCache.txt"
        cache.parent.mkdir()
        cache.write_text("CMAKE_BUILD_TYPE:STRING=Debug\nCMAKE_C_COMPILER:FILEPATH=/test/cc\n"
                         "CMAKE_C_FLAGS:STRING=-DSECRET=not-for-report\n")
        environment = {"VF3_STRICT_REPLAY": "0", "VF3_READABLE": "private-flag-value",
                       "VF3_PRIVATE_TOKEN": "private-token-value", "PRIVATE_OTHER": "other-secret-value",
                       "VF3_IMAGE": "extract/gamedata/1ST_READ.BIN"}
        with mock.patch.dict(os.environ, environment):
            self.assertEqual(self.main(["--report", "audit/replay.json", "--jobs", "2"]), 1)
        report_text = (self.root / "audit/replay.json").read_text()
        report = json.loads(report_text)
        self.assertEqual(report["schema_version"], 1)
        self.assertEqual(report["exit_code"], 1)
        self.assertEqual(report["outcome"], "fail")
        self.assertEqual(report["totals"]["by_status"], {"PASS": 1, "FAIL": 1})
        self.assertEqual(report["totals"]["marked_strict"], {"total": 1, "pass": 1, "not_pass": 0, "executed": 1})
        self.assertEqual(report["totals"]["unmarked"], {"total": 1, "pass": 0, "not_pass": 1, "executed": 1})
        self.assertEqual(report["totals"]["effective_strict"], 2)  # getenv presence, even value "0"
        first, failed = report["results"]
        self.assertEqual((first["exit_code"], failed["exit_code"]), (0, 7))
        self.assertEqual(first["argv"], [sys.executable, str(runner), "0", str(self.root / "fixture.cases")])
        self.assertEqual(first["golden"]["sha256"], hashlib.sha256(b"synthetic fixture").hexdigest())
        self.assertEqual(first["executable"]["sha256"], hashlib.sha256(Path(sys.executable).read_bytes()).hexdigest())
        self.assertGreaterEqual(first["duration_seconds"], 0)
        self.assertIn("strict=True", first["stdout"]["text"])
        self.assertIn("diagnostic stderr", failed["stderr"]["text"])
        self.assertTrue(first["environment"]["flags_present"]["VF3_READABLE"])
        self.assertIn("VF3_PRIVATE_TOKEN", first["environment"]["other_vf3_variable_names"])
        self.assertEqual(report["metadata"]["build"]["cmake_cache"]["sha256"], hashlib.sha256(cache.read_bytes()).hexdigest())
        self.assertEqual(report["metadata"]["build"]["cmake_settings"]["CMAKE_BUILD_TYPE"], "Debug")
        for secret in ("private-token-value", "other-secret-value", "private-flag-value", "not-for-report", "PRIVATE_OTHER"):
            self.assertNotIn(secret, report_text)

    def test_report_output_is_bounded_without_losing_full_stream_digest(self):
        runner = self.make_audit_runner()
        detail = gate.run_detail("pc", {"golden": "fixture.cases", "test": [sys.executable, str(runner), "long"]}, environment={})
        self.assertEqual(detail["status"], "PASS")
        expected = {
            "stdout": "fixture=synthetic fixture\nstrict=False\n".replace("\n", os.linesep).encode() + b"x" * (gate.OUTPUT_LIMIT + 17),
            "stderr": "diagnostic stderr\n".replace("\n", os.linesep).encode() + b"y" * (gate.OUTPUT_LIMIT + 31),
        }
        # Python's child text streams use the platform newline; raw capture
        # must preserve those bytes instead of normalizing Windows CRLF.
        for channel, full in expected.items():
            with self.subTest(channel=channel):
                self.assertTrue(detail[channel]["truncated"])
                self.assertLessEqual(len(detail[channel]["text"].encode("utf-8")), gate.OUTPUT_LIMIT)
                self.assertEqual(detail[channel]["bytes"], len(full))
                self.assertEqual(detail[channel]["sha256"], hashlib.sha256(full).hexdigest())

    def test_invalid_utf8_preserves_child_status_and_replaces_old_report(self):
        runner = self.make_audit_runner()
        runner.write_text(
            "import os, sys\n"
            "os.write(1, b'out\\xff\\r\\n')\n"
            "os.write(2, b'err\\xfe\\r\\n')\n"
            "sys.exit(int(sys.argv[1]))\n", encoding="utf-8")
        passing = {"golden": "fixture.cases", "test": [sys.executable, str(runner), "0"]}
        failing = {"golden": "fixture.cases", "test": [sys.executable, str(runner), "7"]}
        self.bindings = {"0x8c000001": passing, "holdout:0x8c000001": failing}
        self.write_bindings()
        report_path = self.root / "audit.json"
        report_path.write_text(json.dumps({"outcome": "pass", "old_report": True}))

        self.assertEqual(self.main(["--report", "audit.json", "--jobs", "2"]), 1)
        report = json.loads(report_path.read_text())
        self.assertNotIn("old_report", report)
        self.assertEqual(report["outcome"], "fail")
        self.assertEqual(report["totals"]["by_status"], {"PASS": 1, "FAIL": 1})
        self.assertEqual([row["exit_code"] for row in report["results"]], [0, 7])
        for row in report["results"]:
            for channel, raw in (("stdout", b"out\xff\r\n"), ("stderr", b"err\xfe\r\n")):
                with self.subTest(binding=row["binding"], channel=channel):
                    self.assertEqual(row[channel]["bytes"], len(raw))
                    self.assertEqual(row[channel]["sha256"], hashlib.sha256(raw).hexdigest())
                    self.assertEqual(row[channel]["text"], raw.decode("utf-8", errors="replace"))
                    self.assertFalse(row[channel]["truncated"])
            self.assertEqual(row["tail"], "err\ufffd")
        self.assertEqual(gate.run("pc", failing), ("pc", "FAIL", "err\ufffd"))

    def test_report_timeout_keeps_partial_output_and_no_success_code(self):
        self.make_audit_runner()
        failure = subprocess.TimeoutExpired(["test"], 900, output=b"partial out", stderr=b"partial err")
        with mock.patch.object(gate.subprocess, "run", side_effect=failure):
            detail = gate.run_detail("pc", {"golden": "fixture.cases", "test": [sys.executable]})
        self.assertEqual(detail["status"], "TIMEOUT")
        self.assertIsNone(detail["exit_code"])
        self.assertTrue(detail["executed"])
        self.assertEqual(detail["stdout"]["text"], "partial out")
        self.assertEqual(detail["stderr"]["text"], "partial err")

    def test_output_byte_limit_handles_multibyte_boundaries(self):
        for text in ("é" * (gate.OUTPUT_LIMIT + 1), b"\xff" * (gate.OUTPUT_LIMIT + 1)):
            with self.subTest(kind=type(text).__name__):
                output = gate.captured_output(text)
                self.assertLessEqual(len(output["text"].encode("utf-8")), gate.OUTPUT_LIMIT)
                self.assertTrue(output["truncated"])

    def test_invalid_bytes_expansion_marks_presentation_truncated(self):
        raw = b"\xff" * 10000
        self.assertLess(len(raw), gate.OUTPUT_LIMIT)
        output = gate.captured_output(raw)
        self.assertTrue(output["truncated"])
        self.assertEqual(output["bytes"], len(raw))
        self.assertEqual(output["sha256"], hashlib.sha256(raw).hexdigest())
        self.assertEqual(output["text"], "\ufffd" * (gate.OUTPUT_LIMIT // 3))
        self.assertLessEqual(len(output["text"].encode("utf-8")), gate.OUTPUT_LIMIT)

    def test_report_preflight_failure_is_not_executed(self):
        spec = {"golden": "missing.cases", "test": [sys.executable], "strict": True}
        detail = gate.run_detail("pc", spec)
        self.assertEqual(detail["status"], "MISSING-GOLDEN")
        self.assertFalse(detail["executed"])
        self.assertIsNone(detail["exit_code"])
        self.assertIsNone(detail["golden"]["sha256"])
        self.assertIn("error", detail["golden"])

    def test_no_selection_report_says_no_replays_not_pass(self):
        with mock.patch.object(gate, "entries_new_since", return_value=set()):
            self.assertEqual(self.main(["--only-new-since", "HEAD", "--report", "audit.json"]), 0)
        report = json.loads((self.root / "audit.json").read_text())
        self.assertEqual(report["outcome"], "no_replays")
        self.assertEqual(report["results"], [])
        self.assertEqual(report["totals"]["executed"], 0)

    def test_selection_error_is_recorded_with_nonzero_exit(self):
        self.assertEqual(self.main(["--pc", "0x8c000002", "--report", "audit.json"]), 2)
        report = json.loads((self.root / "audit.json").read_text())
        self.assertEqual(report["exit_code"], 2)
        self.assertEqual(report["outcome"], "error")
        self.assertIn("no binding", report["error"])

    def test_report_write_failure_returns_nonzero(self):
        self.make_audit_runner()
        self.bindings = {"0x8c000001": {"golden": "fixture.cases", "test": [sys.executable, str(self.root / "replay.py"), "0"]}}
        self.write_bindings()
        with mock.patch.object(gate, "write_report", side_effect=PermissionError("denied")):
            self.assertEqual(self.main(["--report", "audit.json"]), 2)

    def test_shared_fingerprint_cache_and_file_change(self):
        fixture = self.root / "fixture.cases"
        fixture.write_bytes(b"first")
        fingerprints = gate.Fingerprints()
        original_open = Path.open
        with mock.patch.object(Path, "open", autospec=True, side_effect=original_open) as opened:
            with ThreadPoolExecutor(max_workers=4) as pool:
                values = list(pool.map(fingerprints.file, [fixture] * 16))
            self.assertEqual(opened.call_count, 1)
        self.assertTrue(all(v["sha256"] == hashlib.sha256(b"first").hexdigest() for v in values))
        old_stat = fixture.stat()
        fixture.write_bytes(b"other")
        os.utime(fixture, ns=(old_stat.st_atime_ns, old_stat.st_mtime_ns + 1_000_000_000))
        self.assertEqual(fingerprints.file(fixture)["sha256"], hashlib.sha256(b"other").hexdigest())


if __name__ == "__main__":
    unittest.main()
