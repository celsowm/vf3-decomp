"""Campaign gates reject incomplete, reused, partial or misreported inputs."""
import copy
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch
import ram_clipping_batch_audit as audit


class BatchCampaignTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name); self.corpus = self.root/'corpus'; self.corpus.mkdir()
        self.observer = self.root/'flycast_task_return_boundary_v1.exe'; self.observer.write_bytes(b'fixed observer')
        self.native = self.root/'native.exe'; self.native.write_bytes(b'fixed C')
        self.entry = '0x8c010100'; self.owners = {self.entry: self.entry}
        self.image = bytearray(512); struct.pack_into('<H', self.image, 256, 9)
        self.runs, self.samples = [], {}
        for scenario in range(2):
            state = self.root/f'state{scenario}.state'; state.write_bytes(bytes([scenario]))
            raw = self.root/f'raw{scenario}.bin'; raw.write_bytes(b'raw')
            log = self.root/f'run{scenario}.log'; log.write_text('completed')
            entry_patch = self.root/f'input{scenario}.patch'; entry_patch.write_text('typed input')
            summary = dict(started=64, completed=64, incomplete=[], unaccounted=0)
            Path(str(raw)+'.summary.json').write_text(json.dumps(summary))
            self.samples[raw] = [dict(entry=int(self.entry,16), flags=0, nstate=63, device=[],
                before=struct.pack('<63I', scenario*64+i, *([0]*62)), after=bytes(252),
                pages=[], ops=[(int(self.entry,16), 9)]) for i in range(64)]
            self.runs.append(dict(name=f's{scenario}', capsule=str(raw), state=state.name, log=str(log),
                entry_patch=str(entry_patch), entry_patch_sha256=audit.digest(entry_patch),
                emulator_sha256=audit.digest(self.observer), returncode=0, frame_complete=True))
        self.manifest = {'entries': {self.entry: [{}]*128}, 'nondeterministic_entries': []}
        (self.corpus/'capsule_manifest.json').write_text(json.dumps(self.manifest))
        (self.corpus/'batch_manifest.json').write_text(json.dumps({'runs': self.runs}))
        self.case = self.corpus/'f_8c010100.cases'; self.case.write_text('native vectors')
        self.report = self.root/'report.json'
        self.set_report()

    def set_report(self, **overrides):
        row = {'pass': True, 'stdout': 'matrix_family: 128/128 cases match (0 skipped) - PASS',
               'executable_sha256': audit.digest(self.native), 'cases': str(self.case)}
        row.update(overrides); self.report.write_text(json.dumps({self.entry: row}))

    def run_campaign(self, quarantined=()):
        with patch.object(audit, 'ROOT', self.root), patch.object(audit, 'CACHE', self.root), \
             patch.object(audit, 'body_spans', return_value={int(self.entry,16): [(int(self.entry,16), int(self.entry,16)+2)]}), \
             patch.object(audit, 'records', side_effect=lambda path: iter(self.samples[Path(path)])):
            return audit.campaign(self.corpus, self.report, self.owners, self.native, bytes(self.image),quarantined)

    def test_complete_independent_scenarios(self):
        states, inputs, proof, refs = self.run_campaign()
        self.assertEqual(len(states), 2); self.assertEqual(len(inputs), 128)
        self.assertEqual(len(proof), 2); self.assertTrue(refs)

    def test_incomplete_even_with_other_valid_cases(self):
        path = Path(self.runs[0]['capsule']+'.summary.json')
        data = json.loads(path.read_text()); data['incomplete'] = [{'entry': self.entry}]
        path.write_text(json.dumps(data))
        with self.assertRaises(AssertionError): self.run_campaign()

    def test_missing_distinct_inputs_or_body(self):
        raw = Path(self.runs[0]['capsule']); original = copy.deepcopy(self.samples[raw])
        self.samples[raw][1] = copy.deepcopy(self.samples[raw][0])
        with self.assertRaises(AssertionError): self.run_campaign()
        self.samples[raw] = original
        self.samples[raw] = [{**sample, 'flags': 1} for sample in original]
        with self.assertRaises(AssertionError): self.run_campaign()

    def test_wrong_case_corpus_executable_or_replay_count(self):
        for override in ({'cases': str(self.root/'another.cases')}, {'executable_sha256': '0'*64},
                         {'stdout': 'matrix_family: 127/128 cases match (1 skipped) - PASS'}, {'pass': False}):
            self.set_report(**override)
            with self.subTest(override=override), self.assertRaises(AssertionError): self.run_campaign()

    def test_nonoriginal_opcode_or_device_scope(self):
        raw = Path(self.runs[0]['capsule']); sample = self.samples[raw][0]
        sample['ops'] = [(int(self.entry,16), 0)]
        with self.assertRaises(AssertionError): self.run_campaign()
        sample['ops'] = [(int(self.entry,16), 9)]; sample['device'] = [(0x005f6900, 4, 0, 0)]
        with self.assertRaises(AssertionError): self.run_campaign()

    def test_duplicate_state_or_changed_patch(self):
        (self.root/'state1.state').write_bytes((self.root/'state0.state').read_bytes())
        with self.assertRaises(AssertionError): self.run_campaign()
        (self.root/'state1.state').write_bytes(b'different')
        Path(self.runs[0]['entry_patch']).write_text('changed')
        with self.assertRaises(AssertionError): self.run_campaign()

    def test_supplement_groups_body_only_within_its_original_state(self):
        # Protocol validation is tested separately; exercise the per-state
        # whole-body gate here, never a union across the two scenarios.
        struct.pack_into('<H',self.image,258,9)
        extras=[]
        for scenario, run in enumerate(self.runs):
            raw=self.root/f'supp{scenario}.bin'; raw.write_bytes(b'original supplement')
            Path(str(raw)+'.summary.json').write_text(json.dumps(dict(started=1,completed=1,incomplete=[],unaccounted=0)))
            self.samples[raw]=[{**copy.deepcopy(self.samples[Path(run['capsule'])][0]),'ops':[(int(self.entry,16)+2,9)]}]
            extras.append({**run,'capsule':str(raw),'frame_complete':False,'one_shot_done':True})
        (self.corpus/'batch_manifest.json').write_text(json.dumps(dict(mode='original_ram_supplemented',runs=self.runs+extras)))
        spans={int(self.entry,16):[(int(self.entry,16),int(self.entry,16)+4)]}
        with patch.object(audit,'validate_batch'), patch.object(audit,'body_spans',return_value=spans):
            # run_campaign supplies its own one-word span; call directly to
            # retain the two-word body requirement.
            with patch.object(audit,'ROOT',self.root),patch.object(audit,'CACHE',self.root),patch.object(audit,'records',side_effect=lambda p:iter(self.samples[Path(p)])):
                audit.campaign(self.corpus,self.report,self.owners,self.native,bytes(self.image))
                self.samples[Path(extras[1]['capsule'])][0]['ops']=[(int(self.entry,16),9)]
                with self.assertRaises(AssertionError):
                    audit.campaign(self.corpus,self.report,self.owners,self.native,bytes(self.image))

    def test_quarantined_owner_never_contributes_inputs_or_body(self):
        excluded='0x8c010102';struct.pack_into('<H',self.image,258,9)
        for run in self.runs:
            raw=Path(run['capsule']);sample=copy.deepcopy(self.samples[raw][0])
            sample.update(entry=int(excluded,16),ops=[(int(excluded,16),9)])
            self.samples[raw].append(sample)
            Path(str(raw)+'.summary.json').write_text(json.dumps(dict(started=65,completed=65,incomplete=[],unaccounted=0)))
        self.manifest['nondeterministic_entries']=[excluded]
        path=self.corpus/'capsule_manifest.json';path.write_text(json.dumps(self.manifest))
        states,inputs,proof,refs=self.run_campaign({excluded})
        self.assertEqual(len(inputs),128)
        self.assertTrue(all(row['complete_owners']==1 and set(row['distinct_valid'])=={self.entry} for row in proof))
        self.manifest['nondeterministic_entries'].append(self.entry);path.write_text(json.dumps(self.manifest))
        with self.assertRaises(AssertionError):self.run_campaign({excluded})


if __name__ == '__main__': unittest.main()
