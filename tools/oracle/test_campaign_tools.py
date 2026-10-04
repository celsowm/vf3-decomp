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
from family_queue import rank_families, marginal_bytes, merged_spans
from campaign_io import attempted_entries
import source_owners
from tenpp_probe_plan import override_sequence, override_value
from inspect_capsule import format_register, register_index


class CampaignToolsTests(unittest.TestCase):
    def test_strided_overrides_cover_independent_fields_and_keep_legacy_order(self):
        fast = override_sequence([0,1], 'fast')
        slow = override_sequence({'values':[0,1], 'stride':2}, 'slow')
        self.assertEqual([(override_value(fast,n), override_value(slow,n)) for n in range(4)],
                         [(0,0),(1,0),(0,1),(1,1)])
        self.assertEqual([override_value(override_sequence(['0x10',20], 'legacy'),n) for n in range(4)],
                         [16,20,16,20])
        self.assertEqual(override_value(override_sequence({'values':[1,2], 'phase':1}, 'phase'),0),2)
        for value in ({'values':[0], 'stride':0}, {'values':[0], 'phase':-1},
                      {'values':[]}, {'values':[0], 'extra':1}, {'values':[0x100000000]}):
            with self.subTest(value=value), self.assertRaises(ValueError):
                override_sequence(value, 'invalid')
    def test_linked_owner_priority_and_included_adapter(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'src').mkdir()
            first = root / 'src/first.c'
            first.write_text('#include "first.inc"\n')
            (root / 'src/first.inc').write_text('static const uint32_t owned_pcs[]={0x0c010100u};\n'
                'int first_contains(uint32_t pc) { return owned_pcs[0]==pc; }\n')
            second = root / 'src/second.c'
            second.write_text('static const uint32_t owned_pcs[]={0x0c010100u,0x0c010200u};\n'
                'int second_contains(uint32_t pc) { return owned_pcs[0]==pc; }\n')
            retired = root / 'src/retired.c'
            retired.write_text('int retired_contains(uint32_t pc) { switch(pc) {case 0x0c010300u: return 1;} return 0;}')
            dispatch = 'if(first_contains(entry)) return 1; if(second_contains(entry)) return 1; if(retired_contains(entry)) return 1;'
            with patch.object(source_owners, 'ROOT', root):
                owners, unresolved = source_owners.ownership([first, second], dispatch,
                    {0x8c010100, 0x8c010200, 0x8c010300})
            self.assertEqual(owners, {0x8c010100: 'src/first.c', 0x8c010200: 'src/second.c'})
            self.assertEqual(unresolved, ['retired_contains'])

    def test_fast_marginals_match_address_union(self):
        from select_next import union
        import random
        randomizer = random.Random(610)
        for _ in range(100):
            raw = [(randomizer.randrange(200), randomizer.randrange(200)) for _ in range(20)]
            spans = [(min(a,b), max(a,b)) for a,b in raw]
            candidate, covered = merged_spans(spans[:10]), merged_spans(spans[10:])
            self.assertEqual(marginal_bytes(candidate, covered, [z for _,z in covered]),
                             union(spans) - union(spans[10:]))

    def test_attempts_normalize_grouped_and_legacy_addresses(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            watch = root / 'watch.txt'
            watch.write_text('pc 0x0c010100\n')
            progress = root / 'progress.json'
            progress.write_text(json.dumps([{'entry': '0x0c010200'},
                {'entries': ['0x8c010300', 0x0c010400]}, {}]))
            self.assertEqual(attempted_entries([watch], [progress]),
                             {0x8c010100, 0x8c010200, 0x8c010300, 0x8c010400})

    def test_family_excludes_attempted_roots_but_retains_dependencies(self):
        rows = [{'entry': '0x100', 'missing_implementations': '0x104', 'sh4_dyn': '0'},
                {'entry': '0x104', 'missing_implementations': '', 'sh4_dyn': '0'}]
        families, gain = rank_families(rows, {0x100: [(100, 104)], 0x104: [(104, 108)]},
                                       [], set(), {}, 20, {0x104})
        self.assertEqual(gain, 8)
        self.assertEqual(families[0]['callers'], ['0x100'])
        self.assertEqual(families[0]['members'], ['0x100', '0x104'])

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

    def test_queue_static_dependencies_allow_explicit_unknown_indirect_sites(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'docs').mkdir()
            (root / 'docs/decomp_status.csv').write_text('entry,status\n')
            (root / 'ranges.csv').write_text('entry,start,end\n'
                '0x8c010100,0x8c010100,0x8c010108\n'
                '0x8c010200,0x8c010200,0x8c010208\n'
                '0x8c010300,0x8c010300,0x8c010308\n')
            baseline = root / 'baseline.json'
            baseline.write_text(json.dumps({'body_ranges':'ranges.csv','baseline_spans':[]}))
            plan = root / 'plan.csv'
            plan.write_text('entry,size,sh4_dyn,sh4_fixed,missing_implementations,campaign\n'
                '0x8c010100,8,2,0,,C\n'
                '0x8c010200,8,2,0,0x8c010400,C\n'
                '0x8c010300,8,2,1,,C\n')
            output = root / 'queue.json'
            argv = ['campaign_queue','--plan',str(plan),'--baseline',str(baseline),
                '--out',str(output),'--watch',str(root/'watch.txt'),'--minimum-size','1',
                '--require-static-implementation']
            with patch.object(campaign_queue,'ROOT',root), patch.object(sys,'argv',argv), contextlib.redirect_stdout(io.StringIO()):
                campaign_queue.main()
            report = json.loads(output.read_text())
            self.assertEqual([row['entry'] for row in report['candidates']], ['0x8c010100'])
            self.assertEqual(report['candidates'][0]['dynamic_calls'], 2)


if __name__ == '__main__':
    unittest.main()
