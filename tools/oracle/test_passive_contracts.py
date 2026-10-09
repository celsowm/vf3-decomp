"""An observed indirect edge requires the executed delay slot and destination."""
import unittest
from passive_contracts import indirect_edges, observed_word


class PassiveContractsTests(unittest.TestCase):
    def test_indirect_calls_and_tail_jumps(self):
        edges = indirect_edges([(0xc010000, 0x430b), (0xc010002, 9),
                                (0x8c020000, 0x442b), (0x8c020002, 9),
                                (0xc030000, 11)])
        self.assertEqual(dict(edges), {(0x8c010000, 0x8c020000): 1,
                                      (0x8c020000, 0x8c030000): 1})

    def test_truncated_or_unobserved_delay_slot_is_not_an_edge(self):
        self.assertFalse(indirect_edges([(0xc010000, 0x430b), (0xc020000, 9),
                                        (0xc020002, 11)]))
        self.assertFalse(indirect_edges([(0xc010000, 0x430b), (0xc010002, 9)]))
        self.assertFalse(indirect_edges([(0xc010000, 0xa001), (0xc010002, 9),
                                        (0xc020000, 11)]))

    def test_word_requires_captured_bytes_and_normalizes_ram_alias(self):
        sample = dict(pages=[(0xc100000, b'\x78\x56\x34\x12', b'\0' * 4)])
        self.assertEqual(observed_word(sample, 0x8c100000), 0x12345678)
        self.assertIsNone(observed_word(sample, 0xc100001))


if __name__ == '__main__':
    unittest.main()
