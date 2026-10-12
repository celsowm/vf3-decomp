"""Mutation checks for both original interpolation caller shapes."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callable_replay_interpolate as replay
import callable_list_interpolation as linked


def fixture(module):
    image = bytearray(0x100000)
    if module is replay:
        ops = [(module.START+2*i, op) for i, op in enumerate((0x56f1, 0x65e3, 0xbf91, 0x64d3))]
        indices = (14, 13, 16)
        struct.pack_into('<H', image, 0x0c0a906e-0x0c010000, 0x1fb8)
        struct.pack_into('<I', image, 0x0c0a907c-0x0c010000, 0x0c09f036)
        struct.pack_into('<I', image, 0x0c0a9080-0x0c010000, 0x0c09ea66)
        pages_at = (0x0c0a8000, 0x0c0a9000)
    else:
        ops = [(module.START, 0xd214), (module.CALL, 0x420b), (module.CALL+2, 0x64d3)]
        indices = (14, 13, 12, 36, 35, 34, 16)
        struct.pack_into('<I', image, module.POOL-0x0c010000, module.PARENT&0x1fffffff)
        pages_at = (0x0c08f000, 0x0c090000)
    ops += [(module.PARENT+2*i, op) for i, op in enumerate(module.PREFIX)]
    ops += list(module.RESTORE)
    for pc, op in ops: struct.pack_into('<H', image, pc-0x8c010000, op)
    before = list(range(63)); before[13], before[15], before[18] = 0x0c504000, 0x0c590100, 0x240001
    after = list(before); after[16] = module.RETURN&0x1fffffff
    pre = bytes(4096); post = bytearray(pre)
    for i, reg in enumerate(indices): struct.pack_into('<I', post, 0x100-4*(i+1), after[reg])
    pages = [(0x0c590000, pre, bytes(post))]
    for base in pages_at:
        data = bytes(image[base-0x0c010000:base-0x0c010000+4096]); pages.append((base, data, data))
    sample = dict(entry=module.START, exitpc=module.RETURN, flags=0, nstate=63,
                  before=struct.pack('<63I', *before), after=struct.pack('<63I', *after), ops=ops, pages=pages)
    return image, sample, indices


def verify(module, sample, image):
    function = replay.verify_replay_interpolate_sample if module is replay else linked.verify_list_interpolation_sample
    return function(sample, image)


class InterpolationCallerTests(unittest.TestCase):
    def test_original_callers(self):
        for module in (replay, linked):
            image, sample, _ = fixture(module)
            self.assertEqual(len(verify(module, sample, image)), 64)

    def test_missing_setup_prefix_or_restore(self):
        for module in (replay, linked):
            image, sample, _ = fixture(module)
            for position in range(len(sample['ops'])):
                bad = copy.deepcopy(sample); del bad['ops'][position]
                with self.subTest(module=module.__name__, position=position), self.assertRaises(AssertionError):
                    verify(module, bad, image)

    def test_forged_signature_even_when_image_agrees(self):
        for module in (replay, linked):
            image, sample, _ = fixture(module)
            for position in range(len(sample['ops'])):
                changed_image = bytearray(image); bad = copy.deepcopy(sample)
                pc, op = bad['ops'][position]; bad['ops'][position] = (pc, op^1)
                struct.pack_into('<H', changed_image, pc-0x8c010000, op^1)
                with self.subTest(module=module.__name__, position=position), self.assertRaises(AssertionError):
                    verify(module, bad, changed_image)

    def test_corrupted_saved_architecture(self):
        for module in (replay, linked):
            regs = (*range(8, 19),) if module is replay else (*range(8, 19), 34, 35, 36)
            for reg in regs:
                image, sample, _ = fixture(module)
                after = bytearray(sample['after']); struct.pack_into('<I', after, 4*reg, 0xffffffff)
                sample['after'] = bytes(after)
                with self.subTest(module=module.__name__, reg=reg), self.assertRaises(AssertionError):
                    verify(module, sample, image)

    def test_corrupted_saved_stack(self):
        for module in (replay, linked):
            image, sample, indices = fixture(module)
            for position in range(len(indices)):
                bad = copy.deepcopy(sample); base, pre, post = bad['pages'][0]
                post = bytearray(post); post[0x100-4*(position+1)] ^= 1
                bad['pages'][0] = (base, pre, bytes(post))
                with self.subTest(module=module.__name__, position=position), self.assertRaises(AssertionError):
                    verify(module, bad, image)

    def test_wrong_original_pools(self):
        for module, addresses in ((replay, (0x0c0a906e, 0x0c0a907c, 0x0c0a9080)),
                                  (linked, (linked.POOL,))):
            for address in addresses:
                image, sample, _ = fixture(module); image[address-0x0c010000] ^= 1
                with self.subTest(address=hex(address)), self.assertRaises(AssertionError):
                    verify(module, sample, image)

    def test_invalid_capture_or_mode(self):
        for module in (replay, linked):
            for field, value in (('flags', 1), ('nstate', 54), ('entry', module.START+2), ('exitpc', module.RETURN+2)):
                image, sample, _ = fixture(module); sample[field] = value
                with self.subTest(module=module.__name__, field=field), self.assertRaises(AssertionError):
                    verify(module, sample, image)
            image, sample, _ = fixture(module)
            before = bytearray(sample['before']); struct.pack_into('<I', before, 4*18, 0x140001)
            sample['before'] = bytes(before)
            with self.assertRaises(AssertionError): verify(module, sample, image)


if __name__ == '__main__': unittest.main()
