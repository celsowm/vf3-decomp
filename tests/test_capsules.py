"""Capture-integrity checks independent of game-specific port outputs."""
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest

spec=importlib.util.spec_from_file_location("capsules",Path(__file__).parents[1]/"tools/oracle/capsules.py")
capsules=importlib.util.module_from_spec(spec); spec.loader.exec_module(capsules)

def record(ident=1,flags=0,output=0,page=0x0C000000,entry=0x0C03C4F0,
           input_value=0,exitpc=0x0C000100):
    state=[0]*54; state[18]=0x240001; state[0]=input_value
    after=list(state); after[0]=output
    return (struct.pack("<Q6I",ident,entry,exitpc,flags,1,1,54)
            +struct.pack("<54I",*state)+struct.pack("<54I",*after)
            +struct.pack("<I",page)+bytes(4096)*2+struct.pack("<II",entry,9))

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
    def test_filtered_export_still_checks_all_records_and_summaries(self):
        import json
        p=self.source(record()+record(2,flags=2))
        summary={'started':2,'completed':2,'incomplete':[]}
        Path(str(p)+'.summary.json').write_text(json.dumps(summary))
        report=capsules.convert([p],self.root/'out',set())
        self.assertEqual(report['entries'],{})
        self.assertEqual(len(report['invalid']),1)
        self.assertEqual(report['runs'][0]['completed'],2)
        summary['completed']=1
        Path(str(p)+'.summary.json').write_text(json.dumps(summary))
        with self.assertRaises(ValueError): capsules.convert([p],self.root/'bad',set())
        with self.assertRaises(ValueError):
            capsules.convert([self.source(record()[:-1])],self.root/'truncated',set())
    def test_truncation(self):
        with self.assertRaises(ValueError): list(capsules.records(self.source(record()[:-1])))
    def test_duplicate_identity(self):
        with self.assertRaises(ValueError): list(capsules.records(self.source(record()+record())))
    def test_conflicting_exit_quarantines_entry_without_export(self):
        # Both changed registers and a changed exit PC make a repeated input
        # nondeterministic. Quarantine must be visible in the saved manifest,
        # and no case, RAM image or sidecar may be emitted for that entry.
        for name,second in (("register",record(2,output=1)),
                            ("exitpc",record(2,exitpc=0x0C000102))):
            with self.subTest(conflict=name):
                out=self.root/name
                report=capsules.convert([self.source(record()+second)],out)
                self.assertEqual(report['entries'],{})
                self.assertEqual(report['nondeterministic_entries'],['0x8c03c4f0'])
                self.assertEqual(json.loads((out/'capsule_manifest.json').read_text()),report)
                self.assertEqual(sorted(p.name for p in out.iterdir()),['capsule_manifest.json'])

    def test_quarantine_drops_entire_entry_but_preserves_other_entries(self):
        # Distinct valid inputs before and after a conflict are also excluded;
        # otherwise a later specimen could silently resurrect a bad entry.
        body=(record(1,input_value=42)+record(2)+record(3,output=1)
              +record(4,input_value=99)+record(5,entry=0x0C03C500))
        out=self.root/'out'
        report=capsules.convert([self.source(body)],out)
        self.assertEqual(report['nondeterministic_entries'],['0x8c03c4f0'])
        self.assertEqual(set(report['entries']),{'0x8c03c500'})
        self.assertEqual(list(out.glob('f_8c03c4f0*')),[])
        self.assertTrue((out/'f_8c03c500.cases').is_file())
        self.assertEqual(len((out/'f_8c03c500.cases').read_text().splitlines()),1)
        self.assertEqual((out/'f_8c03c500_0.in.bin').read_bytes(),bytes(4096))
        self.assertEqual((out/'f_8c03c500_0.out.bin').read_bytes(),bytes(4096))

    def test_reused_output_preserves_stale_fixtures_outside_discovery(self):
        out=self.root/'out'
        original=self.source(record()+record(2,entry=0x0C03C500))
        capsules.convert([original],out)
        generated={p.name:p.read_bytes() for p in out.glob('f_8c03c4f0*')}
        self.assertEqual(len(generated),10)
        other={p.name:p.read_bytes() for p in out.glob('f_8c03c500*')}
        # Similar user-owned names and source captures are not generated output.
        untouched={'f_8c03c4f0.notes.txt':b'notes',
                   'f_8c03c4f0.cases.bak':b'backup',
                   'f_8c03c4f0_custom.in.bin':b'user fixture'}
        for name,data in untouched.items(): (out/name).write_bytes(data)
        source=out/'source.cap'
        source.write_bytes(b'VF3CAP3\0'+record()+record(2,output=1))
        source_bytes=source.read_bytes()

        report=capsules.convert([source],out)
        self.assertEqual(report['entries'],{})
        self.assertEqual(report['nondeterministic_entries'],['0x8c03c4f0'])
        self.assertEqual(len(report['quarantined_artifacts']),len(generated))
        self.assertEqual(json.loads((out/'capsule_manifest.json').read_text()),report)
        archived={}
        for row in report['quarantined_artifacts']:
            self.assertEqual(row['entry'],'0x8c03c4f0')
            self.assertFalse((out/row['original']).exists())
            saved=out/row['preserved']
            self.assertTrue(saved.name.endswith('.quarantined'))
            self.assertEqual(saved.read_bytes(),generated[row['original']])
            archived[row['preserved']]=saved.read_bytes()
        self.assertEqual([p.name for p in out.rglob('*.cases')],['f_8c03c500.cases'])
        for name,data in {**other,**untouched}.items():
            self.assertEqual((out/name).read_bytes(),data)
        self.assertEqual(source.read_bytes(),source_bytes)

        # Running the same rejection again must not create another archive or
        # resurrect a fixture. Earlier archived evidence remains intact.
        again=capsules.convert([source],out)
        self.assertEqual(again['quarantined_artifacts'],[])
        self.assertEqual(again['nondeterministic_entries'],['0x8c03c4f0'])
        self.assertEqual({str(p.relative_to(out)):p.read_bytes()
                          for p in (out/'quarantine').rglob('*.quarantined')},archived)
        for name in generated: self.assertFalse((out/name).exists())

        # A later valid export and rejection gets a new batch, never overwrites
        # the first preserved set.
        capsules.convert([original],out)
        later=capsules.convert([source],out)
        self.assertEqual(len(later['quarantined_artifacts']),len(generated))
        self.assertTrue(set(archived).isdisjoint(
            row['preserved'] for row in later['quarantined_artifacts']))
        for name,data in archived.items(): self.assertEqual((out/name).read_bytes(),data)

    def test_quarantine_rejects_directory_with_generated_file_name(self):
        out=self.root/'out'; out.mkdir()
        collision=out/'f_8c03c4f0.cases'; collision.mkdir()
        p=self.source(record()+record(2,output=1))
        with self.assertRaisesRegex(ValueError,'non-file generated artifact'):
            capsules.convert([p],out)
        self.assertTrue(collision.is_dir())
        self.assertFalse((out/'capsule_manifest.json').exists())
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
