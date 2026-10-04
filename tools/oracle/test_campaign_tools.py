"""Check coverage selection and architectural summaries without emulator execution."""
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import port_plan
import campaign_queue
from family_queue import rank_families
from inspect_capsule import format_register, register_index


class CampaignToolsTests(unittest.TestCase):
    def test_family_union_is_marginal_and_cycles_terminate(self):
        rows = [{'entry': '0x100', 'missing_implementations': '0x104', 'sh4_dyn': '0'},
                {'entry': '0x104', 'missing_implementations': '0x100', 'sh4_dyn': '0'}]
        families, gain = rank_families(rows, {0x100: [(100, 108)], 0x104: [(104, 112)]},
                                       [(100, 102)], set(), {0x100: 2}, 20)
        self.assertEqual(gain, 10)
        self.assertEqual(sum(row['marginal_bytes'] for row in families), gain)
        self.assertEqual(len(families), 1)

    def test_architectural_layout(self):
        self.assertEqual([register_index(r) for r in ('fr0', 'fr15', 'xf0', 'xf15', 'fpul', 'gbr', 'rbank7')],
                         [21, 36, 37, 52, 53, 54, 62])
        self.assertEqual(register_index('R14'), 14)
        self.assertEqual(register_index('0xe'), 14)

    def test_invalid_registers(self):
        for name in ('fr16', 'xf16', 'r16', 'pc', '99'):
            with self.subTest(name=name), self.assertRaises(ValueError):
                register_index(name)

    def test_float_bits_and_unavailable(self):
        self.assertEqual(format_register(0x42c80000, 21), '42c80000(100)')
        self.assertEqual(format_register(0x80000000, 37), '80000000(-0)')
        self.assertEqual(format_register(None, 54), 'unavailable')
        self.assertEqual(format_register(0x42c80000, 53), '42c80000')

    def test_helper_owner_does_not_credit_ledger(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'src').mkdir()
            (root / 'src/helper.c').write_text('/* original-image helper */')
            (root / 'docs').mkdir()
            ledger = root / 'docs/decomp_status.csv'
            ledger.write_text('entry,status\n')
            owners = root / 'owners.json'
            owners.write_text(json.dumps({'0x0c042efc': 'src/helper.c'}))
            with patch.object(port_plan, 'REPO', root):
                self.assertEqual(port_plan.implemented_helpers(owners), {0x8c042efc})
                self.assertEqual(port_plan.ported(), set())
            self.assertEqual(ledger.read_text(), 'entry,status\n')

    def test_invalid_helper_owner(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            owners = root / 'owners.json'
            for source in ('src/missing.c', '../outside.c'):
                owners.write_text(json.dumps({'0x8c042efc': source}))
                with patch.object(port_plan, 'REPO', root), self.assertRaises(ValueError):
                    port_plan.implemented_helpers(owners)

    def test_queue_rejects_attribution_excludes_attempts_and_unions_overlap(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'docs').mkdir()
            (root / 'docs/decomp_status.csv').write_text('entry,status\n')
            (root / 'ranges.csv').write_text('entry,start,end\n'
                '0x8c010100,0x8c010100,0x8c010108\n'
                '0x8c010200,0x8c010200,0x8c010208\n'
                '0x8c010204,0x8c010204,0x8c01020c\n'
                '0x8c010300,0x8c010300,0x8c010308\n')
            baseline = root / 'baseline.json'
            baseline.write_text(json.dumps({'body_ranges': 'ranges.csv', 'baseline_spans': []}))
            plan = root / 'plan.csv'
            plan.write_text('entry,size,sh4_dyn,closure_ok,implementation_closure_ok,campaign\n'
                '0x8c010100,8,0,Y,-,accounted\n'
                '0x8c010200,8,0,Y,Y,C\n'
                '0x8c010204,8,0,Y,Y,C\n'
                '0x8c010300,8,0,Y,Y,C\n')
            progress = root / 'progress.json'
            progress.write_text(json.dumps([{'entries': ['0x8c010300']}]))
            output = root / 'queue.json'
            argv = ['campaign_queue', '--plan', str(plan), '--baseline', str(baseline),
                    '--out', str(output), '--watch', str(root / 'watch.txt'),
                    '--minimum-size', '1', '--require-implementation',
                    '--exclude-progress', str(progress)]
            with patch.object(campaign_queue, 'ROOT', root), patch.object(sys, 'argv', argv), contextlib.redirect_stdout(io.StringIO()):
                campaign_queue.main()
            report = json.loads(output.read_text())
            self.assertEqual(report['potential_unique_bytes'], 12)
            self.assertEqual([r['entry'] for r in report['candidates']], ['0x8c010200', '0x8c010204'])


if __name__ == '__main__':
    unittest.main()
