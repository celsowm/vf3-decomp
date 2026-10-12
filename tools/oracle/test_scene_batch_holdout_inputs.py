"""Holdout mutations preserve typed branch relations while changing inputs."""
import unittest
from scene_batch_holdout_inputs import changed, relocated


class HoldoutInputsTests(unittest.TestCase):
    def test_only_owned_pointer_region_is_relocated(self):
        self.assertEqual(relocated(0x0c400000),0x0c580000)
        self.assertEqual(relocated(0x0c49fffc),0x0c61fffc)
        self.assertEqual(relocated(0x0c1fefe4),0x0c1fefe4)
        self.assertEqual(relocated(0x3f800000),0x3f800000)

    def test_round_counter_and_threshold_shift_together(self):
        packed=(1<<8)|(2<<16)|(3<<24)
        result=changed('0x8c098c62',0x0c29bcdc,packed)
        self.assertEqual(result&65535,packed&65535)
        self.assertEqual(result>>16&255,3)
        self.assertEqual(result>>24&255,4)
        self.assertEqual(changed('0x8c098c62',0x0c29bd00,2),3)

    def test_timer_and_countdown_boundaries(self):
        for address in (0x0c1ff028,0x0c2013d0,0x0c1fffdc,0x0c202384):
            self.assertEqual(changed('0x8c098c62',address,(100<<16)|7),(111<<16)|7)
        self.assertEqual(changed('0x8c0993e0',0x0c29c0a4,5),5)
        self.assertEqual(changed('0x8c0993e0',0x0c29c0a4,(1<<16)|5),(3<<16)|5)


if __name__=='__main__':unittest.main()
