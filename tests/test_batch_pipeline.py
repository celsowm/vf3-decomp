"""Planning costs must follow actual helper code rather than tiny seeds."""
import struct
import unittest
from tools.batch_plan import implementation_graph


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


if __name__=='__main__':
    unittest.main()
