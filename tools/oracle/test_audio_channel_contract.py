import struct
import unittest
from audio_channel_contract import check, signed16


class ChannelContractTests(unittest.TestCase):
    def test_early_rejection_does_not_require_unread_channel_page(self):
        before, after = bytearray(252), bytearray(252)
        struct.pack_into('<3I', before, 16, 2, 3, 1)
        struct.pack_into('<I', after, 0, 0xfffffffe)
        sample = dict(entry=0x8c040fa4, flags=0, before=before, after=after,
                      pages=[], device=[])
        self.assertEqual(check(sample)['result'], -2)
        sample['device'] = [(0x008000a0, 4, 2, 1)]
        with self.assertRaisesRegex(ValueError, 'rejected configuration wrote'):
            check(sample)

    def test_signed_storage_width(self):
        self.assertEqual(signed16(65538), 2)
        self.assertEqual(signed16(65536), 0)
        self.assertEqual(signed16(32768), -32768)
        self.assertEqual(signed16(0xffffffff), -1)


if __name__ == '__main__':
    unittest.main()
