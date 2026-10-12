"""Check route isolation, failure diagnostics and evidence identity handling."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import build_isolated as build
import evidence_inspect as inspect
import seal_callable


class ReusableEvidenceTests(unittest.TestCase):
    def test_route_guard_and_cached_alias(self):
        source=build.FUNCTION_MARKER+'\n'+build.ROUTE_MARKER+'\n    return old_route();\n}'
        result=build.route_source(source,[dict(function='candidate',entries=['0x8c099540'],entry_argument=True)])
        self.assertIn('int candidate(uint32_t,vf3_matrix_state*,const vf3_ram_map*);',result)
        self.assertLess(result.index(build.ROUTE_MARKER),result.index('return candidate(entry,s,ram)'))
        self.assertLess(result.index('return candidate(entry,s,ram)'),result.index('return old_route()'))
        self.assertIn('entry==0x0c099540u',result)

    def test_reject_duplicate_physical_routes(self):
        source=build.FUNCTION_MARKER+'\n'+build.ROUTE_MARKER
        with self.assertRaises(ValueError):
            build.route_source(source,[dict(function='candidate',entries=['0x8c099540','0x0c099540'])])

    def test_reject_invalid_addresses_and_symbols(self):
        source=build.FUNCTION_MARKER+'\n'+build.ROUTE_MARKER
        for function,entry in [('bad();',1),('ok',True),('ok',-1),('ok',0x100000000)]:
            with self.subTest(function=function,entry=entry),self.assertRaises(ValueError):
                build.route_source(source,[dict(function=function,entries=[entry])])

    def test_reject_changed_insertion_marker(self):
        with self.assertRaises(ValueError):build.route_source('different dispatcher',[])

    def test_diagnostic_preserves_failure_comparison(self):
        source='if (memcmp(m->shadow[i], m->expect[i], m->wins[i].len) != 0) {\n return 0;\n}'
        result=build.diagnostic_header(source)
        self.assertIn(source.splitlines()[0],result)
        self.assertIn('return 0;',result)
        self.assertEqual(result.count('memcmp('),1)
        self.assertIn('DIAG window',result)

    def test_input_identity_and_output_changes(self):
        sample=dict(before=b'input',after=b'output',exitpc=4,pages=[(8,b'before',b'after')],device=[])
        before,after=inspect.fingerprints(sample)
        sample['pages']=[(8,b'before',b'different')]
        other_before,other_after=inspect.fingerprints(sample)
        self.assertEqual(before,other_before)
        self.assertNotEqual(after,other_after)
        sample['device']=[(1,2,3,0)]
        self.assertNotEqual(before,inspect.fingerprints(sample)[0])

    def test_log_does_not_establish_liveness_or_full_gate(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);bindings=root/'bindings.json';log=root/'log.txt'
            bindings.write_text('{"test": {}}')
            log.write_text('binding test: PASS\nportcheck: PASS\n')
            result=inspect.status([log],bindings,'verify_all')
            self.assertFalse(result['process_liveness_checked'])
            self.assertEqual(result['logs'][0]['log_state'],'INCOMPLETE')
            log.write_text(log.read_text()+'verify_all: PASS\n')
            self.assertEqual(inspect.status([log],bindings,'verify_all')['logs'][0]['log_state'],'COMPLETE_PASS')

    def test_sample_uses_record_id_and_physical_pc(self):
        sample=dict(id=142,entry=0x0c0c3210,exitpc=4,flags=0,nstate=63,before=b'a',after=b'b',
                    pages=[],device=[],ops=[(0x0c040f4e,0xf00a)])
        with patch.object(inspect,'records',return_value=iter([sample])):
            result=inspect.sample_info('unused',142,[0x8c040f4e])
        self.assertEqual(result['invocation'],142)
        self.assertEqual(len(result['pc_hits']),1)
        self.assertEqual(result['float_store_instruction_count'],1)

    def test_case_window_offsets_and_one_based_index(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name)
            fields=['0']*74+['before.bin','2','00000010','2','00000020','3',
                                   'after.bin','2','00000010','2','00000020','3']
            (root/'f_8c000000.cases').write_text(' '.join(fields)+'\n')
            (root/'before.bin').write_bytes(b'abcde');(root/'after.bin').write_bytes(b'ABXYZ')
            (root/'capsule_manifest.json').write_text(json.dumps(dict(entries={'0x8c000000':[dict(sources=['original'])]})))
            result=inspect.replay_case(root,0x8c000000,1,1)
            self.assertEqual(result['windows'][0]['before'],b'cde'.hex())
            self.assertEqual(result['windows'][0]['after'],b'XYZ'.hex())
            with self.assertRaises(ValueError):inspect.replay_case(root,0x8c000000,0)
            with self.assertRaises(ValueError):inspect.replay_case(root,0x8c000000,1,2)

    def test_seal_refuses_existing_output(self):
        with tempfile.TemporaryDirectory() as name:
            output=Path(name)/'proof.json';output.write_text('existing')
            with self.assertRaises(FileExistsError):seal_callable.seal('unused',[],[],output,'unused')
            self.assertEqual(output.read_text(),'existing')

    def test_seal_rejects_mutating_caller(self):
        with tempfile.TemporaryDirectory() as name:
            root=Path(name);template=root/'template.json';caller=root/'caller.json';image=root/'image.bin'
            template.write_text('{"0x8c000000": {}}');caller.write_text('original');image.write_bytes(b'rom')
            def mutate(*args):caller.write_text('changed')
            with patch.object(seal_callable,'body_spans',return_value={0x8c000000:[]}),patch.object(seal_callable,'validate',side_effect=mutate):
                with self.assertRaises(ValueError):seal_callable.seal(template,[caller],[root],root/'out.json',image)
            self.assertFalse((root/'out.json').exists())


if __name__=='__main__':unittest.main()
