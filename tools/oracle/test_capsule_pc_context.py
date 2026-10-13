import unittest

from capsule_pc_context import contexts


class CapsulePcContextTests(unittest.TestCase):
    def test_matches_physical_alias_and_returns_window(self):
        ops = [(0x8C010000, 0x0009), (0x0C001006, 0x085B),
               (0x8C010004, 0x000B)]
        found = contexts(ops, 0x8C001006, radius=1)
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0]["opcode"], "0x085b")
        self.assertEqual(len(found[0]["window"]), 3)

    def test_zero_radius_returns_only_matching_instruction(self):
        found = contexts([(0x1000, 1), (0x1002, 2)], 0x1002, radius=0)
        self.assertEqual(found[0]["window"], [{"pc": "0x00001002", "opcode": "0x0002"}])

    def test_rejects_negative_radius(self):
        with self.assertRaisesRegex(ValueError, "nonnegative"):
            contexts([], 0x1000, radius=-1)


if __name__ == "__main__":
    unittest.main()
