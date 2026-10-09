import unittest
from pathlib import Path
from audio_bank_map import residents


class ResidentBankTests(unittest.TestCase):
    def test_complete_file_equality_required(self):
        asset=b'DTPK'+bytes(range(64))
        wave=bytes(32)+asset+bytes(17)
        result=residents(wave,[(Path('BGM.BIN'),asset)])
        self.assertEqual((result[0]['aica_offset'],result[0]['bytes']),(32,len(asset)))
        changed=bytearray(wave)
        changed[50]^=1
        self.assertEqual(residents(changed,[(Path('BGM.BIN'),asset)]),[])

    def test_duplicate_residency_retained_without_guessing_slot(self):
        asset=b'DTPK'+bytes(range(32))
        result=residents(asset+bytes(7)+asset,[(Path('BGM.BIN'),asset)])
        self.assertEqual([r['aica_offset'] for r in result],[0,len(asset)+7])


if __name__=='__main__': unittest.main()
