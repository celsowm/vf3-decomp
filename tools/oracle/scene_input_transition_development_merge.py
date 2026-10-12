"""Merge selected original scene development, retaining all raw provenance."""
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import sys
from capsules import convert, records
from ram_clipping_batch_audit import digest, reference
from audio_corpus import validate_batch

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_geometry import original_pools


def main():
    originals = [CACHE/f'coverage_65_scene_input_transition_branches_dev_v{v}_export/batch_manifest.json'
                 for v in (1,2)]
    runs = []
    refs = [reference(p) for p in originals]
    image_path = ROOT/'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    scenarios = {}
    for original in originals:
        batch = json.loads(original.read_text())
        validate_batch(batch,True)
        assert len(batch['runs']) == 2
        for run in batch['runs']:
            assert run['emulator_sha256'] == digest(CACHE/'flycast_task_return_boundary_v1.exe')
            assert digest(run['entry_patch']) == run['entry_patch_sha256']
            raw = Path(run['capsule'])
            summary_path = Path(str(raw)+'.summary.json')
            summary = json.loads(summary_path.read_text())
            assert summary['started'] == summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
            state = ROOT/run['state']
            seen,inputs,excluded = scenarios.setdefault(digest(state),(set(),set(),Counter()))
            counted = 0
            for sample in records(raw):
                counted += 1
                if sample['entry']|0x80000000 != 0x8c0993e0:
                    continue
                if sample['flags']:
                    assert sample['flags'] in (1,4,5,6)
                    excluded[sample['flags']] += 1
                    continue
                assert sample['nstate'] == 63 and not sample['device']
                original_pools(sample,image,sample['ops'])
                for pc,op in sample['ops']:
                    offset = (pc&0x1fffffff)-0x0c010000
                    assert 0 <= offset <= len(image)-2 and struct.unpack_from('<H',image,offset)[0] == op
                    seen.add(pc|0x80000000)
                inputs.add(hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+before
                    for base,before,after in sample['pages'])).hexdigest())
            assert counted == summary['completed']
            refs.extend(reference(p) for p in (raw,summary_path,state,Path(run['log']),Path(run['entry_patch'])))
            runs.append(dict(run,name=original.parent.name+'_'+run['name']))
    required = {pc for a,z in body_spans()[0x8c0993e8] for pc in range(a,z,2)}
    assert len(required)*2 == 250 and len(scenarios) == 2
    proofs = []
    for state,(seen,inputs,excluded) in scenarios.items():
        assert required <= seen and len(inputs) >= 64
        proofs.append(dict(state_sha256=state,distinct_valid=len(inputs),whole_body_bytes=250,excluded=dict(excluded)))
    out = CACHE/'coverage_65_scene_input_transition_combined_dev_v1_export'
    assert not out.exists()
    convert([Path(run['capsule']) for run in runs],out,entries={0x8c0993e0})
    manifest = json.loads((out/'capsule_manifest.json').read_text())
    assert not manifest['nondeterministic_entries']
    (out/'batch_manifest.json').write_text(json.dumps(dict(name='scene_input_transition_combined_dev_v1',
        development_only=True,coverage_credit=False,selected_entries=['0x8c0993e0'],runs=runs),indent=2)+'\n')
    proof = ROOT/'extract/analysis/scene_input_transition_complete_original_dev_v1.json'
    assert not proof.exists()
    proof.write_text(json.dumps(dict(coverage_credit=False,whole_original_body=True,
        scenarios=proofs,references=refs+[reference(image_path),reference(Path(__file__))]),indent=2)+'\n')
    print('Whole scene input body PASS independently in both original development states')


if __name__=='__main__':
    main()
