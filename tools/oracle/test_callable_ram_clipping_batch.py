"""Batch attribution rejects unsupported owners and incomplete native bodies."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_ram_clipping_batch as cp


def fixture(directory):
    owner = 0x8c08f642
    entry, prefix, _, category, calls = cp.contract(owner)
    image = bytearray(0x100000)
    ops = {entry+2*i: op for i, op in enumerate(prefix)}
    ops[owner+2] = 0x0009
    for pc, op in ops.items(): struct.pack_into('<H', image, pc-0x8c010000, op)
    Path(directory, f'f_{entry:08x}.ops.json').write_text(json.dumps({hex(pc): hex(op) for pc, op in ops.items()}))
    values = list(range(37))*2
    text = ' '.join(f'{value:x}' for value in values)+'\n'
    Path(directory, f'f_{entry:08x}.cases').write_text(text*64)
    attribution = dict(kind=cp.KIND, entry=hex(entry), contract=category,
        call_sites=[hex(pc) for pc in calls], original_caller_manifests=[{'path': 'caller', 'sha256': 'unused'}])
    return owner, attribution, [(owner, owner+4)], bytes(image)


class RamClippingBatchTests(unittest.TestCase):
    def test_fixed_owner_inventory(self):
        owners = (0x8c0a8370, 0x8c0a8f98, 0x8c087e1c, 0x8c08f642,
                  0x8c098b40, 0x8c0991a2, 0x8c08acd8,
                  0x8c05156a, 0x8c051956, 0x8c051c6a, 0x8c0522ca,
                  0x8c0525fe, 0x8c05295a, 0x8c052c72)
        self.assertEqual(len({cp.contract(owner)[0] for owner in owners}), 14)
        for owner in (0x8c051f8e, 0x8c05152c, 0x8c0991a4, 0):
            with self.subTest(owner=owner), self.assertRaises(AssertionError): cp.contract(owner)

    def test_whole_body_integration_calls_original_caller_gate(self):
        with tempfile.TemporaryDirectory() as directory:
            owner, attribution, spans, image = fixture(directory)
            with patch.object(cp, 'owner_callers') as gate:
                entry, seen = cp.validate_ram_clipping_batch(owner, attribution, spans, directory, image)
                self.assertEqual(entry, 0x8c08f632)
                self.assertIn(owner+2, seen)
                gate.assert_called_once()

    def test_altered_attribution(self):
        with tempfile.TemporaryDirectory() as directory:
            owner, attribution, spans, image = fixture(directory)
            for field, value in (('kind', 'bsr'), ('entry', '0x8c08f634'), ('contract', 'clip'), ('call_sites', ['0x8c090b7a'])):
                bad = copy.deepcopy(attribution); bad[field] = value
                with self.subTest(field=field), self.assertRaises(AssertionError):
                    cp.validate_ram_clipping_batch(owner, bad, spans, directory, image)

    def test_missing_body_or_forged_prefix(self):
        with tempfile.TemporaryDirectory() as directory:
            owner, attribution, spans, image = fixture(directory)
            path = Path(directory, 'f_8c08f632.ops.json'); original = json.loads(path.read_text())
            for pc in original:
                bad = dict(original); del bad[pc]; path.write_text(json.dumps(bad))
                with self.subTest(pc=pc), self.assertRaises(AssertionError):
                    cp.validate_ram_clipping_batch(owner, attribution, spans, directory, image)
            bad = dict(original); bad['0x8c08f632'] = '0x2fd6'; path.write_text(json.dumps(bad))
            changed = bytearray(image); struct.pack_into('<H', changed, 0x8c08f632-0x8c010000, 0x2fd6)
            with self.assertRaises(AssertionError): cp.validate_ram_clipping_batch(owner, attribution, spans, directory, changed)

    def test_insufficient_native_cases_or_saved_state(self):
        with tempfile.TemporaryDirectory() as directory:
            owner, attribution, spans, image = fixture(directory)
            path = Path(directory, 'f_8c08f632.cases'); lines = path.read_text().splitlines()
            path.write_text('\n'.join(lines[:63])+'\n')
            with self.assertRaises(AssertionError): cp.validate_ram_clipping_batch(owner, attribution, spans, directory, image)
            for offset in (45, 52, 55, 71, 73):
                bad = list(lines); words = bad[0].split(); words[offset] = 'ffffffff'; bad[0] = ' '.join(words)
                path.write_text('\n'.join(bad)+'\n')
                with self.subTest(offset=offset), self.assertRaises(AssertionError):
                    cp.validate_ram_clipping_batch(owner, attribution, spans, directory, image)

    def test_other_clip_or_component_row_cannot_prove_owner(self):
        from test_callable_clip_triangle import fixture as clip_fixture
        from test_callable_component_update import fixture as component_fixture
        _, sample = clip_fixture(0x8c05152c)
        self.assertTrue(cp.selected(sample, 0x8c05152c, 'clip'))
        self.assertFalse(cp.selected(sample, 0x8c051918, 'clip'))
        _, sample = component_fixture(11)
        self.assertTrue(cp.selected(sample, 0x8c087e04, 'component-11'))
        self.assertFalse(cp.selected(sample, 0x8c08acc0, 'component-2'))


if __name__ == '__main__': unittest.main()
