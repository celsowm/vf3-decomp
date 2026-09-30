"""Planning costs must follow actual helper code rather than tiny seeds."""
import struct
import unittest
import tempfile
from pathlib import Path
from unittest.mock import patch
from types import SimpleNamespace
import json
from tools import portcheck
from tools.batch_plan import implementation_graph
from tools.oracle.translate_adapters import emit, adapter_pcs


class ImplementationGraphTests(unittest.TestCase):
    def image(self, words):
        return struct.pack('<'+'H'*len(words),*words)

    def test_body_extends_beyond_seed(self):
        scan=implementation_graph(self.image([9]*20+[11,9]),{})
        pcs,targets,unknown=scan(0x8c010000)
        self.assertEqual(len(pcs)*2,44)
        self.assertFalse(targets or unknown)

    def test_tail_records_dependency_without_pool_fallthrough(self):
        scan=implementation_graph(self.image([0x432b,9,0xb123,0xffff]),{0x8c010000:0x8c010020})
        pcs,targets,unknown=scan(0x8c010000)
        self.assertEqual(pcs,{0x8c010000,0x8c010002})
        self.assertEqual(targets,{0x8c010020})
        self.assertFalse(unknown)

    def test_unknown_indirect_call_remains_cost(self):
        scan=implementation_graph(self.image([0x430b,9,11,9]),{})
        pcs,targets,unknown=scan(0x8c010000)
        self.assertEqual(len(pcs),4)
        self.assertEqual(unknown,{0x8c010000})
        self.assertFalse(targets)


class AdapterOpcodeTests(unittest.TestCase):
    def test_existing_adapter_ownership_uses_only_emitted_labels(self):
        with tempfile.TemporaryDirectory() as directory:
            first=Path(directory)/'first.c'; second=Path(directory)/'second.c'
            first.write_text('/* P_0c010004: */\nP_0c010000: /* emitted */\n')
            second.write_text('P_0c010000:\nP_0c010002:\n')
            self.assertEqual(adapter_pcs([first,second]),{0x0c010000,0x0c010002})

    def test_rotate_left_updates_carry(self):
        statements=emit(0x0c010000,0x4004)
        self.assertIn('r[0]>>31',statements[0])
        self.assertEqual(statements[1],'r[0]=(r[0]<<1)|(r[0]>>31);')

    def test_cache_allocate_store_does_not_read_a_banked_register(self):
        self.assertEqual(emit(0x0c010000,0x04c3),['write(ram,r[4],r[0],4);'])
        with self.assertRaises(ValueError): emit(0x0c010000,0x04c2)


class ParallelBindingTests(unittest.TestCase):
    def test_parallel_bindings_preserve_arguments_strictness_and_order(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory); (root/'runner.exe').touch(); (root/'cases').touch()
            bindings=root/'bindings.json'
            bindings.write_text(json.dumps({
                'b':{'test':'runner.exe 0x8c010002','golden':'cases','strict':True},
                'a':{'test':'runner.exe 0x8c010000','golden':'cases','strict':True}
            }))
            with patch.object(portcheck,'REPO',root), patch.object(portcheck.subprocess,'run') as run:
                run.return_value=SimpleNamespace(returncode=0,stdout='PASS',stderr='')
                rows=portcheck.run_bindings(bindings,jobs=2)
                self.assertEqual(rows,[('a','PASS','PASS'),('b','PASS','PASS')])
                self.assertEqual(run.call_count,2)
                for call in run.call_args_list:
                    self.assertEqual(call.kwargs['env']['VF3_STRICT_REPLAY'],'1')
                    self.assertEqual(call.args[0][0],str(root/'runner.exe'))
                    self.assertEqual(call.args[0][-1],str(root/'cases'))


if __name__=='__main__':
    unittest.main()
