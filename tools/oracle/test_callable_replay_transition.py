"""Helper attribution rejects changed caller edges, save prefixes and body gaps."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from callable_replay_transition import DEFINITIONS, KIND, validate_replay_transition


class ReplayTransitionAttributionTests(unittest.TestCase):
    def setUp(self):
        directory=tempfile.TemporaryDirectory(); self.addCleanup(directory.cleanup)
        self.corpus=Path(directory.name)
        self.owner=0x8c099568
        entry,words,saved,caller=DEFINITIONS[self.owner]
        self.attribution=dict(kind=KIND,entry=hex(entry),call_sites=[hex(caller)],
            callee_save_prefix=[f'r{n}' for n in saved],scene_index=57,scene_table='0xc10baa8')
        self.spans=[(self.owner,self.owner+4)]
        (self.corpus/f'f_{entry:08x}.ops.json').write_text(json.dumps(
            {f'{entry+2*n:08x}':f'{op:04x}' for n,op in enumerate(words)}))

    def verify(self):
        validate_replay_transition(self.owner,self.attribution,self.spans,self.corpus,bytes(0x110000))

    def test_changed_caller_edge_rejected(self):
        self.attribution['call_sites']=['0x8c09954e']
        with self.assertRaises(AssertionError): self.verify()

    def test_changed_save_prefix_rejected(self):
        self.attribution['callee_save_prefix']=['r13','r14','r12']
        with self.assertRaises(AssertionError): self.verify()

    def test_another_scene_slot_rejected(self):
        self.attribution['scene_index']=56
        with self.assertRaises(AssertionError): self.verify()

    def test_prefix_only_does_not_qualify_owner(self):
        with self.assertRaisesRegex(AssertionError,'incomplete helper prefix or owner body'): self.verify()


if __name__=='__main__': unittest.main()
