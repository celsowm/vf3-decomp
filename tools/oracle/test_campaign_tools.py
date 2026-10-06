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
import tenpp_probe_plan
import prologue_roots
from expand_memory_profile import expand
from config_editor_map import decode as decode_editor
from inspect_capsule import format_register, register_index
import capture_catalog
import capture_storage
import isolate_planned
import decoded_storage
import filter_capture_closure
import portcheck
import regression_status
import state_checksum_table
import boundary_probe_plan
import allocator_probe_plan
import motion_record_probe_plan
import unattempted_parents
import command_selector_probe_plan
import text_control_probe_plan
import struct
from types import SimpleNamespace
from comparison_inputs import literal_comparisons, boundary_palette, replace_narrow


class CampaignToolsTests(unittest.TestCase):
    def test_text_control_inputs_are_distinct_and_acceptance_relocates(self):
        development = [text_control_probe_plan.fixture(i) for i in range(128)]
        acceptance = [text_control_probe_plan.fixture(i, relocation=0x100000, holdout=True)
                      for i in range(128)]
        self.assertEqual(len({r['r5'] for r in development}), 128)
        self.assertEqual(len({r['r5'] for r in acceptance}), 128)
        self.assertTrue({r['r5'] for r in development}.isdisjoint(r['r5'] for r in acceptance))
        for original, moved in zip(development, acceptance):
            self.assertEqual(original['r4'], 0xe4)
            self.assertEqual(moved['r15'], original['r15'] + 0x100000)
        self.assertEqual(text_control_probe_plan.fixture(0, offset=0xe8)['r4'], 0xe8)
        self.assertEqual(text_control_probe_plan.fixture(0, offset=0x400000e4)['r4'], 0x400000e4)

    def test_command_encoders_keep_queue_and_channel_inputs_coherent(self):
        for variant in (0, 8, 10, 16, 63, 127):
            regs, words = command_selector_probe_plan.fixture(0x8c041d04, variant)
            relocated, moved = command_selector_probe_plan.fixture(0x8c041d04, variant, 0x100000, True)
            self.assertLess(regs['r4'], 8)
            self.assertEqual(moved[0x0c19e218], words[0x0c19e218] + 0x100000)
            self.assertEqual(relocated['r15'], regs['r15'] + 0x100000)
            for channel in range(8):
                self.assertIn(words[0x0c19e250 + channel * 24], (0, 1))
            self.assertIn(words[words[0x0c19e218]], (0, 1))

    def test_parent_queue_excludes_probed_parent_but_keeps_new_prologue(self):
        with tempfile.TemporaryDirectory() as directory:
            history = Path(directory) / 'progress.json'
            history.write_text(json.dumps([{'entries': ['0x8c010000', '0x8c010100']}]))
            selected = unattempted_parents.select({'0x8c010000': ['0x8c010004'],
                '0x8c010200': ['0x8c010100']}, [history])
            self.assertEqual(selected, {0x8c010200: [0x8c010100]})
            self.assertEqual(unattempted_parents.select(
                {'0x8c010200': ['0x8c010100']}, [history], {0x8c010200}), {})

    def test_motion_walker_contract_has_120_records_and_relocates_pointers(self):
        for variant in (0, 1, 7, 8, 119):
            regs, words = motion_record_probe_plan.fixture(variant)
            relocated, moved = motion_record_probe_plan.fixture(variant, 0x100000, True)
            self.assertEqual(words[regs['r4'] + 12], 0x0c430000)
            self.assertEqual(moved[relocated['r4'] + 12], 0x0c530000)
            for base, memory in ((0x0c430000, words), (0x0c530000, moved)):
                flags = [memory[base + i * 68] & 1 for i in range(120)]
                self.assertEqual(sum(flags), int(variant % 8 != 0))
                self.assertTrue(all(base + offset in memory for offset in range(0, 8160, 4)))
            self.assertIn(words[0x0c2a0144], (regs['r4'], regs['r4'] + 44))
            self.assertNotEqual(words[0x0c2a0140], moved[0x0c2a0140])

    def test_allocator_contracts_keep_links_and_global_pool_addresses(self):
        for variant in (0, 1, 2, 4, 5, 6, 7, 32, 33):
            registers, words = allocator_probe_plan.fixture(0x8c062390, variant)
            self.assertTrue(allocator_probe_plan.POOL <= registers['r5'] < allocator_probe_plan.POOL + 24 * 4096)
            self.assertEqual((registers['r5'] - allocator_probe_plan.POOL) % 24, 0)
            header = allocator_probe_plan.HEADERS + ((variant // 8) % 2) * 20
            visited, previous = set(), 0
            current = words[header + 8]
            while current:
                self.assertNotIn(current, visited)
                visited.add(current)
                self.assertEqual(words[current + 4], previous)
                previous, current = current, words[current + 8]
            self.assertEqual(previous, words[header + 12])
            moved, shifted = allocator_probe_plan.fixture(0x8c062390, variant, 0x100000, True)
            self.assertEqual(moved['r15'] - registers['r15'], 0x100000)
            self.assertEqual(moved['r5'], registers['r5'])
            self.assertIn(allocator_probe_plan.POOL, shifted)
            self.assertIn(header + 8, shifted)
        _, words = allocator_probe_plan.fixture(0x8c061c04, 11)
        self.assertTrue(all(words[allocator_probe_plan.POOL + 24 * slot] == 1 for slot in range(1, 4096)))
        self.assertEqual(words[allocator_probe_plan.POOL], 0)

    def test_boundary_matrix_contract_and_relocation(self):
        singular, regular = 0, 0
        for variant in range(64):
            registers, words = boundary_probe_plan.fixture('matrix', variant)
            rows = [[struct.unpack('<f', struct.pack('<I', words[registers['r4'] + 16 * row + 4 * col]))[0]
                     for col in range(4)] for row in range(4)]
            if all(row[0] == 0 for row in rows):
                singular += 1
            else:
                regular += 1
                self.assertTrue(all(sum(value != 0 for value in row) == 1 for row in rows))
            relocated, shifted = boundary_probe_plan.fixture('matrix', variant, 0x100000, True)
            self.assertEqual(relocated['r15'] - registers['r15'], 0x100000)
            self.assertEqual(relocated['r4'] - registers['r4'], 0x100000)
            self.assertTrue(all(0x0c500000 <= address < 0x0c580000 for address in shifted))
            if variant == 4:
                self.assertNotEqual(words[registers['r4'] + 20], shifted[relocated['r4'] + 20])
        self.assertEqual((singular, regular), (32, 32))
        with self.assertRaises(ValueError):
            boundary_probe_plan.fixture('matrix', 0, relocation=1)

    def test_boundary_controls_cover_stack_modes_and_scene_overrides(self):
        modes, selectors, flags = set(), set(), set()
        for variant in range(256):
            registers, words = boundary_probe_plan.fixture('controls', variant)
            modes.add(words[registers['r15'] + 4])
            selectors.add(words[0x0c16cea0])
            flags.add(words[0x0c16ca90])
            moved, shifted = boundary_probe_plan.fixture('controls', variant, 0x100000, True)
            self.assertEqual(shifted[moved['r15'] + 4], words[registers['r15'] + 4])
            self.assertEqual(shifted[0x0c16cea0], words[0x0c16cea0])
        self.assertEqual(modes, {0, 1, 2})
        self.assertEqual(selectors, set(range(32, 37)))
        self.assertEqual(flags, {0, 32})

    def test_regression_status_requires_complete_binding_reports(self):
        expected = {'first': {}, 'second': {}}
        partial = 'binding first: PASS\n'
        data = regression_status.summarize(partial, expected)
        self.assertEqual(data['reported_bindings'], 1)
        self.assertFalse(data['complete'])
        self.assertFalse(data['passed'])
        self.assertFalse(regression_status.summarize(partial+'portcheck: PASS\n',expected)['passed'])
        full = partial+'binding second: PASS\ngolden-bound ports:\n  first PASS\n  second PASS\nportcheck: PASS\n'
        self.assertTrue(regression_status.summarize(full,expected)['passed'])
        self.assertEqual(regression_status.summarize(full,expected)['reported_bindings'],2)
        self.assertFalse(regression_status.summarize(full,expected,'verify_all')['complete'])
        self.assertTrue(regression_status.summarize(full+'verify_all: PASS\n',expected,'verify_all')['passed'])
        self.assertTrue(regression_status.summarize(
            'golden-bound ports:\n  first PASS\n  second PASS\nportcheck: PASS\n',expected)['passed'])
        self.assertFalse(regression_status.summarize(full+'verify_all: FAIL\n',expected)['passed'])
        self.assertFalse(regression_status.summarize(full.replace('second PASS','second FAIL'),expected)['passed'])

    def test_snapshot_override_preserves_bindings_and_other_executables(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root/'build').mkdir()
            for name in ('vf3matrixfamily.exe','other.exe','snapshot.exe','vectors.cases'):
                (root/'build'/name).touch()
            bindings = root/'bindings.json'
            bindings.write_text(json.dumps({
                'matrix':dict(test='build/vf3matrixfamily.exe 0x8c010100',golden='build/vectors.cases',strict=True),
                'other':dict(test='build/other.exe',golden='build/vectors.cases')}))
            before = bindings.read_bytes()
            with patch.object(portcheck,'REPO',root), patch.object(portcheck.subprocess,'run',
                    return_value=SimpleNamespace(returncode=0,stdout='PASS',stderr='')) as run:
                results = portcheck.run_bindings(bindings,matrix_executable=root/'build/snapshot.exe')
            self.assertTrue(all(status=='PASS' for _,status,_ in results))
            commands = {Path(call.args[0][0]).name:call for call in run.call_args_list}
            self.assertEqual(set(commands),{'snapshot.exe','other.exe'})
            self.assertEqual(commands['snapshot.exe'].kwargs['env']['VF3_STRICT_REPLAY'],'1')
            self.assertEqual(bindings.read_bytes(),before)

    def test_checksum_table_validates_original_stride_and_packed_crc(self):
        image = bytearray(0xe3868+1024)
        for address,opcode in ((0x8c076b4e,0xd006),(0x8c076b50,0x4700),
                               (0x8c076b52,0x4700),(0x8c076b54,0x027d)):
            struct.pack_into('<H',image,address-state_checksum_table.BASE,opcode)
        struct.pack_into('<I',image,0x8c076b68-state_checksum_table.BASE,0x0c0f3868)
        struct.pack_into('<256H',image,0xe3868,*state_checksum_table.crc_table())
        data = state_checksum_table.inspect(image,2)
        self.assertTrue(data['packed_table_match'])
        self.assertFalse(data['generic_crc_replacement_equivalent'])
        self.assertEqual(data['original_lookup_stride'],4)
        self.assertEqual(data['preview'][1]['packed_word'],'0x1021')
        self.assertEqual(data['preview'][1]['original_lookup_word'],'0x2042')
        image[0xe3868]=1
        self.assertFalse(state_checksum_table.inspect(image)['packed_table_match'])
        image[0x8c076b50-state_checksum_table.BASE]=0x09
        with self.assertRaises(ValueError):
            state_checksum_table.inspect(image)
        with self.assertRaises(ValueError):
            state_checksum_table.inspect(b'')

    def test_comparison_hints_use_bounded_original_literals(self):
        self.assertEqual(literal_comparisons(0x8840,{}),[64])
        self.assertEqual(literal_comparisons(0x88ff,{}),[-1])
        self.assertEqual(literal_comparisons(0x3423,
            {2:('literal',512),4:('field',None,0)}),[512])
        self.assertEqual(literal_comparisons(0x3423,
            {2:('literal',0x0c420000)}),[])
        values = boundary_palette([64,-1])
        self.assertTrue({63,64,65,0xfffffffe,0xffffffff} <= set(values))
        self.assertEqual(boundary_palette([64,-1],True),tuple(reversed(values)))
        self.assertEqual(replace_narrow(0xaabbccdd,0x0c420001,2,0x10001),0xaa0001dd)
        self.assertEqual(replace_narrow(0xaabbccdd,0x0c420001,2,-1),0xaaffffdd)
        with self.assertRaises(ValueError):
            replace_narrow(0,0x0c420003,2,64)

    def test_comparison_sampling_is_optional_and_preserves_pointer_fields(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            watch = root / 'watch.txt'
            watch.write_text('pc 0x8c010100\n')
            words = {0x0c420000:0xaabbccdd,0x0c420004:0x0c430000}
            metadata = dict(scalars=[0x0c420004],signed_arguments=[],argument_flags={},
                narrow_widths={0x0c420001:1,0x0c420004:2},
                comparisons=[dict(pc='0x8c010104',value=64)])
            with patch.object(tenpp_probe_plan,'fixture',return_value=({},words,metadata)):
                for enabled in (False,True):
                    output = root / f'{enabled}.txt'
                    with contextlib.redirect_stdout(io.StringIO()):
                        tenpp_probe_plan.generate(watch,output,0x8c010200,66,
                                                 comparison_boundaries=enabled)
            legacy = (root / 'False.txt').read_text()
            sampled = (root / 'True.txt').read_text()
            self.assertEqual(legacy.count('0x0c420000 0xaabbccdd'),66)
            self.assertIn('0x0c420000 0xaabb41dd',sampled)
            self.assertEqual(sampled.count('0x0c420004 0x0c430000'),66)

    def test_closure_filter_rejects_forbidden_aliases_and_missing_tapes(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / 'f_8c010000.ops.json').write_text('{"0c010000":"e100"}')
            (root / 'f_8c010010.ops.json').write_text('{"ac0671aa":"000b"}')
            selected, excluded = filter_capture_closure.select(
                root, {0x8c010000, 0x8c010010, 0x8c010020}, {0x8c0671aa})
            self.assertEqual(selected, {0x8c010000})
            self.assertEqual(excluded['0x8c010010'], ['0x0c0671aa'])
            self.assertIn('0x8c010020', excluded)

    def test_decoded_cleanup_keeps_bound_current_and_original_sources(self):
        import os
        import time
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            analysis = root / 'extract/analysis'
            analysis.mkdir(parents=True)
            source = analysis / 'capsule_original.bin'
            source.write_bytes(b'original')
            protected = analysis / 'bound'
            for name in ('bound', 'unbound', 'target_current'):
                directory = analysis / name
                directory.mkdir()
                (directory / 'capsule_manifest.json').write_text(json.dumps({'inputs':[str(source)]}))
                (directory / 'batch_manifest.json').write_text(json.dumps({'runs':[
                    {'returncode':0,'frame_complete':True}]}))
                for suffix in ('in', 'out'):
                    shadow = directory / f'f_8c010000_0.{suffix}.bin'
                    shadow.write_bytes(bytes(65536))
                    os.utime(shadow, (time.time()-100000, time.time()-100000))
            with patch.object(decoded_storage, 'bound_sources', return_value=({protected}, set())):
                result = decoded_storage.plan(root, reclaim_gib=1)
            self.assertEqual(len(result['candidates']), 2)
            self.assertTrue(all(Path(row['path']).parent.name == 'unbound' for row in result['candidates']))
            self.assertTrue(source.is_file())
            self.assertTrue(all(Path(row['path']).is_file() for row in result['candidates']))

    def test_capture_stops_before_writing_when_disk_reserve_is_low(self):
        from types import SimpleNamespace
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            watch = root / 'watch.txt'
            watch.write_text('pc 0x8c010000\n')
            output = io.StringIO()
            argv = ['isolate_planned', '--watch', str(watch), '--out', str(root / 'captures')]
            with patch.object(sys, 'argv', argv), \
                    patch.object(isolate_planned.shutil, 'disk_usage', return_value=SimpleNamespace(free=0)), \
                    patch.object(isolate_planned, 'generate') as generate, \
                    patch.object(isolate_planned.subprocess, 'run') as capture, \
                    contextlib.redirect_stdout(output):
                isolate_planned.main()
            generate.assert_not_called()
            capture.assert_not_called()
            self.assertIn('reserve required', output.getvalue())
            self.assertEqual(list((root / 'captures').iterdir()), [])

    def test_storage_cleanup_protects_bound_sources_and_current_captures(self):
        import os
        import time
        from types import SimpleNamespace
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            analysis = root / 'extract/analysis'
            accepted = analysis / 'accepted'
            empty = analysis / 'old_empty'
            accepted.mkdir(parents=True)
            empty.mkdir()
            (root / 'tools').mkdir()
            (accepted / 'f_8c010000.cases').write_text('specimens')
            (root / 'tools/golden_bindings.json').write_text(json.dumps({
                'binding': {'golden': 'extract/analysis/accepted/f_8c010000.cases'}}))
            sources = [analysis / name for name in
                       ('capsule_bound.bin', 'capsule_old_empty.bin', 'capsule_target_current.bin')]
            for source in sources:
                source.write_bytes(b'original')
                os.utime(source, (time.time() - 100000, time.time() - 100000))
            (accepted / 'capsule_manifest.json').write_text(json.dumps({
                'entries': {'0x8c010000': [1]}, 'inputs': [str(sources[0])]}))
            (empty / 'capsule_manifest.json').write_text(json.dumps({
                'entries': {}, 'inputs': list(map(str, sources))}))
            with patch.object(capture_storage.subprocess, 'run',
                              return_value=SimpleNamespace(stdout='')):
                result = capture_storage.plan(root)
            self.assertEqual([row['path'] for row in result['candidates']],
                             [str(sources[1].resolve())])
            self.assertEqual(result['protected_sources'], 1)
            self.assertTrue(all(source.is_file() for source in sources))

    def test_capture_catalog_is_advisory_and_excludes_holdouts(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / 'docs').mkdir()
            (root / 'docs/decomp_status.csv').write_text(
                'entry,status\n0x8c010100,ported-invocation\n')
            (root / 'ranges.csv').write_text('entry,start,end\n'
                '8c010100,8c010100,8c010110\n'
                '8c010200,8c010200,8c010210\n')
            baseline = root / 'baseline.json'
            baseline.write_text(json.dumps(dict(body_ranges='ranges.csv',
                baseline_spans=[[0x8c010100,0x8c010110]])))
            directory = root / 'development'
            directory.mkdir()
            row = dict(entry='0x8c010200', directory=str(directory), reasons=[],
                distinct_cases=128, scenarios=[['a',''],['b','']],
                covered_bytes=16, body_bytes=16, missing_pcs=[])
            development = root / 'dev_report.json'
            development.write_text(json.dumps(dict(entries=[row,row,
                dict(row,entry='0x8c010100'),dict(row,reasons=['unexecuted body PCs'])])))
            holdout = root / 'accept_report.json'
            holdout.write_text(json.dumps(dict(entries=[row])))
            with patch.object(capture_catalog,'ROOT',root):
                data = capture_catalog.catalog([development,holdout],baseline)
            self.assertTrue(data['advisory'])
            self.assertEqual(data['baseline_bytes'],16)
            self.assertEqual(data['potential_unique_bytes'],16)
            self.assertEqual(len(data['candidates']),1)
            self.assertEqual(len(data['candidates'][0]['corpora']),1)
            single = dict(row, reasons=['fewer than two scenarios'], scenarios=[['a','']])
            development.write_text(json.dumps(dict(entries=[single])))
            held = root / 'held_report.json'
            held.write_text(json.dumps(dict(entries=[single])))
            with patch.object(capture_catalog,'ROOT',root):
                self.assertEqual(capture_catalog.catalog([development],baseline)['candidates'], [])
                recovered = capture_catalog.catalog([development,held],baseline,single_scenario=True)
                self.assertEqual(len(recovered['candidates']),1)
                self.assertEqual(len(recovered['candidates'][0]['corpora']),1)
                single['distinct_cases'] = 63
                development.write_text(json.dumps(dict(entries=[single])))
                self.assertEqual(capture_catalog.catalog([development],baseline,single_scenario=True)['candidates'], [])
                partial = dict(row, reasons=['unexecuted body PCs'], covered_bytes=12,
                               missing_pcs=['0x8c01020c','0x8c01020e'])
                development.write_text(json.dumps(dict(entries=[partial])))
                self.assertEqual(capture_catalog.catalog([development],baseline)['candidates'], [])
                self.assertEqual(capture_catalog.catalog([development],baseline,maximum_gap=2)['candidates'], [])
                gaps = capture_catalog.catalog([development],baseline,maximum_gap=4)
                self.assertEqual(gaps['candidates'][0]['corpora'][0]['missing_bytes'],4)
                with self.assertRaises(ValueError):
                    capture_catalog.catalog([development],baseline,single_scenario=True,maximum_gap=4)

    def test_config_editor_parameters_and_helper_targets(self):
        import struct
        words = (0x4f22,0x7ff8,0x1f41,0xde12,0xd313,0x64e3,0x430b,0x7401,
                 0x600c,0xe305,0x2f02,0x2f36,0xe702,0x55f2,0xe601,0xd211,
                 0x420b,0x54f1,0x1f01,0x7f0c,0x4f26,0xd310,0x64e3,0x6503,
                 0x7401,0x432b,0x6ef6)
        image = bytearray(256)
        struct.pack_into('<27H',image,0,*words)
        for offset,value in ((80,0x0c11e504),(88,0x0c0c66b8),
                             (100,0x0c072ec2),(108,0x0c0c66d0)):
            struct.pack_into('<I',image,offset,value)
        row = decode_editor(image,0x8c010000)
        self.assertEqual((row['offset'],row['width'],row['minimum'],row['maximum'],row['step']),
                         (1,1,2,5,1))
        short = [op for index,op in enumerate(words) if index not in (5,24)]
        short[6] = 0x64e3
        struct.pack_into('<25H',image,0,*short)
        first = decode_editor(image,0x8c010000)
        self.assertEqual((first['offset'],first['getter_return'],first['editor_return']),
                         (0,0x0c01000e,0x0c010022))
        struct.pack_into('<I',image,100,0x0c010100)
        with self.assertRaises(ValueError): decode_editor(image,0x8c010000)

    def test_record_ranges_expand_and_preserve_variant_values(self):
        dimension = {'values': [1, 9, 0], 'stride': 8}
        rows = expand({'0x8c010000': {'ranges': [
            {'start': '0x0c420000', 'count': 3, 'stride': 68, 'value': dimension}]}}, 0x0c200000)
        self.assertEqual(list(rows['0x8c010000']),
                         ['0x0c420000', '0x0c420044', '0x0c420088'])
        self.assertEqual(rows['0x8c010000']['0x0c420088'], dimension)

    def test_record_ranges_reject_image_mutation_and_overlap(self):
        for ranges in (
            [{'start': '0x0c010000', 'count': 1, 'stride': 4, 'value': 0}],
            [{'start': '0x0c420000', 'count': 2, 'stride': 2, 'value': 0}],
            [{'start': '0x0cfffffc', 'count': 2, 'stride': 4, 'value': 0}],
            [{'start': '0x0c420000', 'count': 2, 'stride': 4, 'value': 0},
             {'start': '0x0c420004', 'count': 1, 'stride': 4, 'value': 1}],
        ):
            with self.subTest(ranges=ranges), self.assertRaises(ValueError):
                expand({'0x8c010000': {'ranges': ranges}}, 0x0c200000)

    def test_long_float_save_prefix_can_find_original_prologue(self):
        import struct
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'extract/exe').mkdir(parents=True)
            (root / 'docs').mkdir()
            (root / 'docs/decomp_status.csv').write_text('entry,status\n')
            words = [9] * 40
            words[0], words[24] = 0x2fe6, 0x4f22
            (root / 'extract/exe/1ST_READ.unsc.bin').write_bytes(struct.pack('<40H', *words))
            watch, output = root / 'watch.txt', root / 'out.txt'
            watch.write_text('pc 0x8c010030\n')
            argv = ['prologue_roots', str(watch), '--out', str(output), '--report', str(root / 'report.json')]
            with patch.object(prologue_roots, 'ROOT', root), patch.object(sys, 'argv', argv), contextlib.redirect_stdout(io.StringIO()):
                prologue_roots.main()
            self.assertIn('pc 0x8c010030', output.read_text())
            with patch.object(prologue_roots, 'ROOT', root), patch.object(sys, 'argv', argv + ['--prefix-distance', '64']), contextlib.redirect_stdout(io.StringIO()):
                prologue_roots.main()
            self.assertIn('pc 0x8c010000', output.read_text())

    def test_override_pointers_relocate_with_ram_and_float_bits_remain_exact(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            watch, output = root / 'watch.txt', root / 'probe.txt'
            watch.write_text('pc 0x8c010100\n')
            empty_fixture = ({}, {}, {'signed_arguments': [], 'argument_flags': {}})
            with patch.object(tenpp_probe_plan, 'fixture', return_value=empty_fixture):
                tenpp_probe_plan.generate(watch, output, 0x8c010200, 1,
                    relocation=0x100000,
                    register_overrides={'0x8c010100': {'r4':'0x0c404000', 'fr4':'0x0c404000'}},
                    memory_overrides={'0x8c010100': {'0x0c404000':'0x0c405000'}})
            text = output.read_text()
            self.assertIn('r4 0x0c504000', text)
            self.assertIn('fr4 0x0c404000', text)
            self.assertIn('ram 0x8c010200 0x0c504000 0x0c505000', text)

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
