"""Capture-integrity checks independent of game-specific port outputs."""
import importlib.util
from pathlib import Path
import struct
import tempfile
import unittest

spec=importlib.util.spec_from_file_location("capsules",Path(__file__).parents[1]/"tools/oracle/capsules.py")
capsules=importlib.util.module_from_spec(spec); spec.loader.exec_module(capsules)

def record(ident=1,flags=0,output=0,page=0x0C000000):
    state=[0]*54; state[18]=0x240001
    after=list(state); after[0]=output
    return (struct.pack("<Q6I",ident,0x0C03C4F0,0x0C000100,flags,1,1,54)
            +struct.pack("<54I",*state)+struct.pack("<54I",*after)
            +struct.pack("<I",page)+bytes(4096)*2+struct.pack("<II",0x0C03C4F0,9))

class Capsules(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory(); self.root=Path(self.tmp.name)
    def tearDown(self): self.tmp.cleanup()
    def source(self,body):
        p=self.root/"input.cap"; p.write_bytes(b"VF3CAP3\0"+body); return p
    def test_nested_identity_and_dedup(self):
        # Child exits first; IDs carry identity rather than FIFO pairing.
        p=self.source(record(2)+record(1))
        rows=list(capsules.records(p)); self.assertEqual([r["id"] for r in rows],[2,1])
        report=capsules.convert([p],self.root/"out")
        cases=report["entries"]["0x8c03c4f0"]
        self.assertEqual(len(cases),1); self.assertEqual(len(cases[0]["sources"]),2)
        self.assertEqual((self.root/"out/f_8c03c4f0.extra.bin").stat().st_size,16)
    def test_invalid_specimens_never_export(self):
        p=self.source(record(flags=1)+record(2,flags=2)+record(3,flags=4)+record(4,flags=8))
        report=capsules.convert([p],self.root/"out")
        self.assertEqual(report["entries"],{}); self.assertEqual(len(report["invalid"]),4)
    def test_truncation(self):
        with self.assertRaises(ValueError): list(capsules.records(self.source(record()[:-1])))
    def test_duplicate_identity(self):
        with self.assertRaises(ValueError): list(capsules.records(self.source(record()+record())))
    def test_conflicting_exit(self):
        with self.assertRaises(ValueError): capsules.convert([self.source(record()+record(2,output=1))],self.root/"out")
    def test_invalid_page(self):
        with self.assertRaises(ValueError): list(capsules.records(self.source(record(page=0x0C000001))))
    def test_cap4_gbr_alignment(self):
        before=[0]*55; before[54]=0x0C199900
        after=list(before); after[54]+=4
        body=struct.pack('<Q6I',1,0x0C03C4F0,0x0C000100,0,0,1,55)
        body+=struct.pack('<55I',*before)+struct.pack('<55I',*after)
        body+=struct.pack('<2I',0x0C03C4F0,9)
        path=self.root/'v4.cap'; path.write_bytes(b'VF3CAP4\0'+body)
        capsules.convert([path],self.root/'out')
        self.assertEqual(struct.unpack('<3I',(self.root/'out/f_8c03c4f0.gbr.bin').read_bytes()),
                         (before[54],after[54],1))
    def test_incomplete_invocations_are_accounted(self):
        import json
        p=self.source(record())
        summary={"started":2,"completed":1,"incomplete":[{"invocation":2,"entry":"0x0c03c4f0","flags":16}]}
        Path(str(p)+'.summary.json').write_text(json.dumps(summary))
        report=capsules.convert([p],self.root/'out')
        self.assertEqual(len(report['entries']['0x8c03c4f0']),1)
        self.assertEqual(report['runs'][0]['incomplete'][0]['flags'],16)
        summary['completed']=2
        Path(str(p)+'.summary.json').write_text(json.dumps(summary))
        with self.assertRaises(ValueError): capsules.convert([p],self.root/'bad')

if __name__=="__main__": unittest.main()
