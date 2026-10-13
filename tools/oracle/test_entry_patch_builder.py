import unittest

from entry_patch_builder import build


class EntryPatchBuilderTests(unittest.TestCase):
    def test_round_robin_variants_preserve_only_named_inputs(self):
        text = build({
            "trigger_pc": "0x8c09635a", "target_pc": "0x8c09635a", "pr_offset": 2,
            "variants": [
                {"registers": {"r10": "0x606"},
                 "memory": {"0x0c2cf844": "0x606"}},
                {"registers": {"r10": "0x200"},
                 "memory": {"0x0c2cf844": "0x606"}},
            ],
        })
        self.assertIn("entry 0x8c09635a 0x8c09635a", text)
        self.assertIn("reg 0x8c09635a pr 0x8c09635c", text)
        self.assertIn("seed 0x8c09635a", text)
        self.assertEqual(text.count("reg 0x8c09635a r10"), 2)
        self.assertEqual(text.count("ram 0x8c09635a 0x0c2cf844"), 2)

    def test_rejects_register_collision_with_pr_offset(self):
        with self.assertRaisesRegex(ValueError, "PR is supplied"):
            build({"trigger_pc": 0x1000, "target_pc": 0x1000, "pr_offset": 2,
                   "variants": [{"registers": {"pr": 0x1002}}]})

    def test_rejects_unaligned_or_non_ram_writes(self):
        with self.assertRaisesRegex(ValueError, "invalid aligned RAM"):
            build({"trigger_pc": 0x1000, "target_pc": 0x1000,
                   "variants": [{"memory": {"0x0c000002": 1}}]})

    def test_rejects_invalid_register(self):
        with self.assertRaisesRegex(ValueError, "invalid register"):
            build({"trigger_pc": 0x1000, "target_pc": 0x1000,
                   "variants": [{"registers": {"r16": 0}}]})

    def test_fpu_banks_follow_fpscr(self):
        text = build({"trigger_pc": 0x1000, "target_pc": 0x1000,
                      "variants": [{"registers": {"fr0": 1, "xf15": 2, "fpscr": 0x240001}}]})
        self.assertLess(text.index(' fpscr '), text.index(' fr0 '))
        self.assertLess(text.index(' fpscr '), text.index(' xf15 '))


if __name__ == "__main__":
    unittest.main()
