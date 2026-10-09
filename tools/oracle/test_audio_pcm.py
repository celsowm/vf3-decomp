import struct
import unittest
from audio_pcm import interval, swap_channels


class PcmExportTests(unittest.TestCase):
    def test_asymmetric_stereo_and_signed_endpoints(self):
        raw = struct.pack('<4h', -32768, 32767, -5, 12)
        swapped = swap_channels(raw)
        self.assertEqual(struct.unpack('<4h', swapped), (32767, -32768, 12, -5))
        self.assertEqual(swap_channels(swapped), raw)

    def test_interval_requires_identical_prior_samples(self):
        self.assertEqual(interval(b'1234', b'12345678'), b'5678')
        with self.assertRaisesRegex(ValueError, 'not a cumulative stream'):
            interval(b'1234', b'42345678')

    def test_partial_frame_rejected(self):
        with self.assertRaisesRegex(ValueError, 'incomplete stereo frame'):
            swap_channels(bytes(3))


if __name__ == '__main__':
    unittest.main()
