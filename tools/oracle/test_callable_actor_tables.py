"""Mutation checks for the immutable resource dispatch evidence contract."""
import copy
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from callable_actor_tables import verify_actor_table_sample, START, RETURN, TABLE
from body_cover import body_spans


class ResourceCallerContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image = (ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
        owner, entry, index = 0x8c0a3246, 0x8c0a3242, 11
        record = TABLE+36*index
        descriptor = struct.unpack_from('<I', cls.image, record-0xc010000+24)[0]
        before = [0]*63
        before[13:16] = [descriptor, 0xc4b1000, 0xc690100]
        after = before.copy()
        after[16] = RETURN & 0x1fffffff
        pages = []
        for base in range(0xc010000, 0xc010000+len(cls.image), 4096):
            page = cls.image[base-0xc010000:base-0xc010000+4096].ljust(4096, b'\0')
            pages.append((base, page, page))
        stack = bytearray(4096)
        struct.pack_into('<I', stack, 0x100, record)
        post = stack.copy()
        struct.pack_into('<2I', post, 0xf8, RETURN & 0x1fffffff, before[14])
        pages.append((0xc690000, bytes(stack), bytes(post)))
        pcs = [START+2*i for i in range(4)] + [entry, entry+2]
        pcs += sorted({pc for a, z in body_spans()[owner] for pc in range(a, z, 2)
                       if not 0x8c0a2e06 <= pc < 0x8c0a2e2c})
        pcs += [0x8c0a2e28, 0x8c0a2e2a, RETURN, RETURN+2]
        ops = [(pc, struct.unpack_from('<H', cls.image, pc-0x8c010000)[0]) for pc in pcs]
        cls.sample = dict(flags=0, nstate=63, device=[], entry=START,
            exitpc=RETURN+4, before=struct.pack('<63I', *before),
            after=struct.pack('<63I', *after), pages=pages, ops=ops)

    def test_valid_declared_window(self):
        self.assertEqual(len(verify_actor_table_sample(self.sample, self.image)), 64)

    def check_rejected(self, mutate):
        sample = copy.deepcopy(self.sample)
        mutate(sample)
        with self.assertRaises(AssertionError):
            verify_actor_table_sample(sample, self.image)

    def test_missing_delay_slot(self):
        self.check_rejected(lambda s: s['ops'].pop(3))

    def test_missing_wrapper_word(self):
        self.check_rejected(lambda s: s.update(ops=[pair for pair in s['ops'] if pair[0] != 0x8c0a324a]))

    def test_wrong_return_boundary(self):
        self.check_rejected(lambda s: s.update(exitpc=RETURN))

    def test_changed_instruction(self):
        self.check_rejected(lambda s: s['ops'].__setitem__(0, (START, 9)))

    def test_changed_callback_slot(self):
        def mutate(s):
            slot = TABLE+36*11+28
            page = (slot-0xc010000)//4096
            base, pre, post = s['pages'][page]
            pre = bytearray(pre)
            struct.pack_into('<I', pre, slot-base, 0xc0a3504)
            s['pages'][page] = (base, bytes(pre), post)
        self.check_rejected(mutate)

    def test_changed_callee_saved_register(self):
        def mutate(s):
            after = list(struct.unpack('<63I', s['after']))
            after[14] += 4
            s['after'] = struct.pack('<63I', *after)
        self.check_rejected(mutate)

    def test_device_invocation(self):
        self.check_rejected(lambda s: s.update(device=[(0xa05f8000, 4, 1, 1)]))


if __name__ == '__main__':
    unittest.main()
