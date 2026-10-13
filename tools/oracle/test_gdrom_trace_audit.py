import tempfile
import unittest
from pathlib import Path

from gdrom_trace_audit import parse_line, summarize


class GdromTraceAuditTests(unittest.TestCase):
    def test_parses_service_call_and_extension(self):
        row = parse_line(
            "gdrom fn  1 r4 0000004a r5 0c31f91c -> r0 00000001 "
            "[status 1 cmd 17 remaining 844 total 919 req 74] res 0 0 153600 0",
            1,
        )
        self.assertEqual(row["fn"], 1)
        self.assertEqual(row["r5"], 0x0C31F91C)
        self.assertEqual(row["res"], [0, 0, 153600, 0])
        self.assertEqual(row["remaining"], 844)

    def test_summarizes_calls_and_state_transitions(self):
        trace = (
            "gdrom fn  2 r4 00000000 r5 00025800 -> r0 8c001006 "
            "[status 1 cmd 17 remaining 844 total 919 req 74]\n"
            "gdrom fn  1 r4 0000004a r5 0c31f91c -> r0 00000001 "
            "[status 1 cmd 17 remaining 844 total 919 req 74] res 0 0 153600 0\n"
            "gdrom fn  1 r4 0000004a r5 0c31f91c -> r0 00000002 "
            "[status 2 cmd 17 remaining 0 total 919 req 74] res 0 0 0 0\n"
        )
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "trace.log"
            path.write_text(trace, encoding="ascii")
            observer = Path(directory) / "observer.exe"
            patch = Path(directory) / "trace.patch"
            observer.write_bytes(b"observer")
            patch.write_bytes(b"patch")
            report = summarize(path, observer, patch)
        self.assertEqual(report["records"], 3)
        self.assertEqual(report["function_counts"], {"1": 2, "2": 1})
        self.assertEqual(report["requests"]["74"]["remaining_min"], 0)
        self.assertEqual(len(report["state_transitions"]), 2)
        self.assertEqual(len(report["observer_sha256"]), 64)
        self.assertEqual(len(report["patch_sha256"]), 64)

    def test_rejects_malformed_records(self):
        with self.assertRaisesRegex(ValueError, "line 7"):
            parse_line("not a GD-ROM record", 7)

    def test_rejects_unknown_extension(self):
        with self.assertRaisesRegex(ValueError, "extension"):
            parse_line(
                "gdrom fn  1 r4 0000004a r5 0c31f91c -> r0 00000001 "
                "[status 1 cmd 17 remaining 844 total 919 req 74] other 1",
                3,
            )

    def test_parses_drive_status_extension(self):
        row = parse_line(
            "gdrom fn  4 r4 0c31fa08 r5 01000000 -> r0 00000000  "
            "[status 0 cmd 17 remaining 0 total 919 req 4294967295] drv 1 type 128",
            4,
        )
        self.assertEqual(row["drv"], [1, 128])

    def test_parses_caller_context(self):
        row = parse_line(
            "gdrom fn  2 pc 8c0965aa pr 8c0965b0 r4 00000000 "
            "r5 00025800 -> r0 8c001006  [status 1 cmd 17 "
            "remaining 844 total 919 req 74]",
            5,
        )
        self.assertEqual(row["pc"], 0x8C0965AA)
        self.assertEqual(row["pr"], 0x8C0965B0)

    def test_parses_syscall_group(self):
        row = parse_line(
            "gdrom fn  1 group 0 pc 8c001008 pr 0c0432ec r4 0000004a "
            "r5 0c31f91c -> r0 00000001  [status 1 cmd 17 "
            "remaining 844 total 919 req 74] res 0 0 153600 0",
            6,
        )
        self.assertEqual(row["group"], 0)
        self.assertEqual(row["pr"], 0x0C0432EC)


if __name__ == "__main__":
    unittest.main()
