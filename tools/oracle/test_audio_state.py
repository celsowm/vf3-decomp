import struct
import tempfile
import unittest
from pathlib import Path
from audio_state import ARAM_OFFSET, REG_OFFSET, CHANNEL_STATE_OFFSET, inspect
from arm_trace import records


class AudioStateReaderTests(unittest.TestCase):
    def test_hardware_register_offset_accounts_for_u32_rtc_enable(self):
        data=bytearray(2137930)
        struct.pack_into('<2I',data,0,854,0x1000000)
        struct.pack_into('<I',data,ARAM_OFFSET+0x400,0xa1)
        struct.pack_into('<4I',data,REG_OFFSET+128,0x4101,0x2468,7,31)
        struct.pack_into('<3I',data,CHANNEL_STATE_OFFSET+72,0x12468,19,1024)
        data[CHANNEL_STATE_OFFSET+72+71]=1
        result=inspect(data)
        voice=result['channels'][1]
        self.assertEqual(voice['sample_address'],'0x012468')
        self.assertEqual(voice['format'],'adpcm')
        self.assertTrue(voice['key_on_request'])
        self.assertTrue(voice['enabled'])
        self.assertEqual(voice['sample_position'],19)
        self.assertEqual((voice['loop_start'],voice['loop_end']),(7,31))

    def test_unknown_layout_rejected(self):
        with self.assertRaisesRegex(ValueError,'unsupported'):
            inspect(bytes(2137930))

    def test_arm_trace_rejects_partial_record(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'trace'
            path.write_bytes(b'VF3ARM1\0'+bytes(39))
            with self.assertRaisesRegex(ValueError,'truncated'):
                list(records(path))

    def test_arm_trace_preserves_order_and_arm_pc(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'trace'
            path.write_bytes(b'VF3ARM1\0'+struct.pack('<QQ6I',1,100,0x1020,
                             0xe5d01000,0x438,0xa1,1,0))
            row=list(records(path))[0]
            self.assertEqual((row['pc'],row['address'],row['value']),(0x1020,0x438,0xa1))
            self.assertFalse(row['store'])


if __name__=='__main__': unittest.main()
