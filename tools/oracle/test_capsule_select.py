import struct
import unittest

from capsule_select import before_register, canonical, matches, ram_word


def record():
    before = bytearray(21 * 4)
    struct.pack_into("<I", before, 10 * 4, 0x20000)
    page_before = bytearray(16)
    page_after = bytearray(16)
    struct.pack_into("<I", page_before, 4, 0x00700000)
    struct.pack_into("<I", page_after, 4, 0x00300000)
    return {
        "nstate": 21, "before": bytes(before),
        "pages": [(0x0C000000, bytes(page_before), bytes(page_after))],
        "ops": [(0x8C001000, 0x0009), (0x0C001002, 0x000B)],
    }


class CapsuleSelectTests(unittest.TestCase):
    def test_reads_entry_register_and_canonicalized_ram_word(self):
        item = record()
        self.assertEqual(before_register(item, "r10"), 0x20000)
        self.assertEqual(canonical(0x8C000004), canonical(0x0C000004))
        self.assertEqual(ram_word(item, 0x8C000004), 0x00700000)
        self.assertEqual(ram_word(item, 0x0C000004, "after"), 0x00300000)

    def test_matches_register_ram_and_physical_pc_aliases(self):
        self.assertTrue(matches(record(), registers={"r10": 0x20000},
                                words={0x8C000004: 0x00700000},
                                pcs=[0x0C001000]))
        self.assertFalse(matches(record(), registers={"r10": 0x20001}))
        self.assertFalse(matches(record(), words={0x0C000004: 0}))
        self.assertFalse(matches(record(), pcs=[0x8C001004]))

    def test_unrecorded_register_or_ram_word_does_not_match(self):
        item = record()
        item["nstate"] = 10
        self.assertIsNone(before_register(item, "r10"))
        self.assertIsNone(ram_word(item, 0x0C000020))


if __name__ == "__main__":
    unittest.main()
