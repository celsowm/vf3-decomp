"""Seal whole original development bodies for the five replay helper candidates."""
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
import sys
from capsules import convert, records
from ram_clipping_batch_audit import digest, reference
from audio_corpus import validate_batch

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_geometry import original_pools


def main():
    owners_path=ROOT/'tools/oracle/coverage_65_replay_transition_helpers_dev_v2_owners.json'
    owners=json.loads(owners_path.read_text());assert len(owners)==5
    originals=[CACHE/'coverage_65_replay_transition_helpers_dev_v2_export/batch_manifest.json',
               CACHE/'coverage_65_replay_action_special_dev_v2_export/batch_manifest.json']
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN';image=image_path.read_bytes()
    runs=[];refs=[reference(p) for p in [owners_path,image_path,*originals]];scenarios={}
    for path in originals:
        batch=json.loads(path.read_text());validate_batch(batch,True);assert len(batch['runs'])==2
        for run in batch['runs']:
            raw=Path(run['capsule']);summary_path=Path(str(raw)+'.summary.json')
            summary=json.loads(summary_path.read_text())
            assert summary['started']==summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
            assert run['emulator_sha256']==digest(CACHE/'flycast_task_return_boundary_v1.exe')
            assert digest(run['entry_patch'])==run['entry_patch_sha256']
            state=ROOT/run['state'];seen,inputs,invalid=scenarios.setdefault(digest(state),
                (defaultdict(set),defaultdict(set),Counter()))
            counted=0
            for sample in records(raw):
                counted+=1;entry=hex(sample['entry']|0x80000000);assert entry in owners
                if sample['flags']:
                    assert sample['flags'] in (1,4,5,6);invalid[(entry,sample['flags'])]+=1;continue
                assert sample['nstate']==63 and not sample['device']
                original_pools(sample,image,sample['ops'])
                for pc,op in sample['ops']:
                    offset=(pc&0x1fffffff)-0xc010000
                    assert 0<=offset<=len(image)-2 and struct.unpack_from('<H',image,offset)[0]==op
                    seen[entry].add(pc|0x80000000)
                inputs[entry].add(hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+before
                    for base,before,after in sample['pages'])).hexdigest())
            assert counted==summary['completed']
            refs.extend(reference(p) for p in (raw,summary_path,state,Path(run['log']),Path(run['entry_patch'])))
            runs.append(dict(run,name=path.parent.name+'_'+run['name']))
    assert len(scenarios)==2
    spans=body_spans();proofs=[]
    for state,(seen,inputs,invalid) in scenarios.items():
        for entry,owner in owners.items():
            required={pc for a,z in spans[int(owner,16)] for pc in range(a,z,2)}
            assert required<=seen[entry],f'incomplete {entry} body in {state}'
            assert len(inputs[entry])>=64,f'insufficient distinct {entry} inputs in {state}'
        proofs.append(dict(state_sha256=state,distinct_valid={e:len(inputs[e]) for e in owners},
            excluded=[dict(entry=e,flags=f,count=count) for (e,f),count in sorted(invalid.items())],whole_owners=5))
    out=CACHE/'coverage_65_replay_transition_helpers_combined_dev_v1_export';assert not out.exists()
    convert([Path(r['capsule']) for r in runs],out,entries={int(e,16) for e in owners})
    assert not json.loads((out/'capsule_manifest.json').read_text())['nondeterministic_entries']
    (out/'batch_manifest.json').write_text(json.dumps(dict(name='replay_transition_helpers_combined_dev_v1',
        development_only=True,coverage_credit=False,runs=runs),indent=2)+'\n')
    proof=ROOT/'extract/analysis/replay_transition_helpers_complete_original_dev_v1.json';assert not proof.exists()
    proof.write_text(json.dumps(dict(coverage_credit=False,whole_original_bodies=True,
        frozen_owner_bytes=824,scenarios=proofs,references=refs+[reference(Path(__file__))]),indent=2)+'\n')
    print('Five helper bodies PASS independently in two original states; no coverage credit')


if __name__=='__main__':main()
