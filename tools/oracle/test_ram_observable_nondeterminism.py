"""Quarantine witnesses require identical complete inputs and differing exits."""
import copy
import unittest
import ram_observable_nondeterminism as proof


class ObservableInputTests(unittest.TestCase):
    def setUp(self):
        self.left=dict(flags=0,nstate=63,device=[],entry=0x8c0a8f8c,exitpc=0xc0432e4,
            before=bytes(252),after=bytes(252),pages=[(0xc000000,b'input',b'first')])
        self.right=copy.deepcopy(self.left);self.right['pages']=[(0xc000000,b'input',b'other')]

    def test_identical_complete_inputs_disagree(self): proof.compare(self.left,self.right)

    def test_identical_outputs_are_not_a_witness(self):
        self.right=copy.deepcopy(self.left)
        with self.assertRaises(AssertionError):proof.compare(self.left,self.right)

    def test_changed_register_or_ram_input_rejected(self):
        original=copy.deepcopy(self.right);self.right['before']=b'\x01'+bytes(251)
        with self.assertRaises(AssertionError):proof.compare(self.left,self.right)
        self.right=original;self.right['pages']=[(0xc000000,b'other',b'after')]
        with self.assertRaises(AssertionError):proof.compare(self.left,self.right)

    def test_another_root_rejected(self):
        self.right['entry']=0x8c0a8370
        with self.assertRaises(AssertionError):proof.compare(self.left,self.right)

    def test_interrupted_or_device_specimens_rejected(self):
        for mutation in ({'flags':1},{'nstate':55},{'device':[(0x005f6900,4,0,0)]}):
            original=copy.deepcopy(self.right);self.right.update(mutation)
            with self.subTest(mutation=mutation),self.assertRaises(AssertionError):proof.compare(self.left,self.right)
            self.right=original

    def test_page_order_does_not_create_difference(self):
        self.left['pages'] += [(0xc001000,b'same',b'same')]
        self.right=copy.deepcopy(self.left);self.right['pages'].reverse()
        with self.assertRaises(AssertionError):proof.compare(self.left,self.right)


if __name__=='__main__':unittest.main()
