"""Qualify complete independent held campaigns for the replay helpers."""
from datetime import datetime
import hashlib
import json
from pathlib import Path
import struct
from capsules import convert, records
from evidence_inspect import capture
from ram_clipping_batch_audit import digest, reference, caller_files
from task_completion_audit import freeze
from verify_matrix import verify
import sys

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate


def inputs(directory):
    batch=json.loads((directory/'batch_manifest.json').read_text());result={}
    for run in batch['runs']:
        for sample in records(Path(run['capsule'])):
            if sample['flags']:continue
            entry=hex(sample['entry']|0x80000000)
            key=hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+before
                for base,before,after in sample['pages'])).hexdigest()
            result.setdefault(entry,set()).add(key)
    return result


def main():
    qualified=CACHE/'replay_transition_qualified_development_freeze_v1.json'
    development=json.loads(qualified.read_text())
    assert development['qualified_development_only'] and development['full_regression']['passed']
    for row in development['references']:assert digest(row['path'])==row['sha256']
    source=Path(development['normal_source_archive']['path'])
    assert digest(source)==development['normal_source_archive']['sha256']
    native=freeze(source,native=True);assert reference(native)==development['native']
    held_path=ROOT/'tools/oracle/replay_transition_accept_input_manifest_v1.json'
    held=json.loads(held_path.read_text())
    assert held['development_freeze']==reference(qualified)
    assert datetime.fromisoformat(held['created_at_utc'])>datetime.fromisoformat(development['frozen_at_utc'])
    for row in [*held['files'],*held['original_states']]:assert digest(row['path'])==row['sha256']
    expected_states={row['sha256'] for row in held['original_states']};assert len(expected_states)==2
    runs=[];refs=[]
    for group in held['groups']:
        path=CACHE/(group['name']+'_export/batch_manifest.json')
        batch=json.loads(path.read_text());assert len(batch['runs'])==2
        states=set()
        for run in batch['runs']:
            assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==run['expected_frames']==4000
            assert Path(run['entry_patch']).resolve()==(ROOT/f'extract/analysis/{group["name"]}.patch').resolve()
            assert digest(run['entry_patch'])==run['entry_patch_sha256']
            assert digest(run['emulator'])==run['emulator_sha256']=='b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
            state=ROOT/run['state'];states.add(digest(state))
            raw=Path(run['capsule']);summary=Path(str(raw)+'.summary.json')
            data=json.loads(summary.read_text())
            assert data['started']==data['completed'] and not data['incomplete'] and not data['unaccounted']
            refs += [reference(p) for p in (raw,summary,state,Path(run['entry_patch']),Path(run['log']))]
            runs.append(dict(run,name=group['name']+'_'+run['name']))
        assert states==expected_states
        refs.append(reference(path))
    assert len(runs)==4
    owners_path=ROOT/'tools/oracle/coverage_65_replay_transition_helpers_dev_v2_owners.json'
    owners=json.loads(owners_path.read_text())
    directory=CACHE/'coverage_65_replay_transition_combined_accept_v1_export'
    report=ROOT/'extract/analysis/replay_transition_helpers_integrated_combined_accept_v1_native.json'
    assert not directory.exists() and not report.exists(), 'refuse to replace acceptance evidence'
    convert([Path(run['capsule']) for run in runs],directory)
    (directory/'batch_manifest.json').write_text(json.dumps(dict(coverage_credit=False,
        independent_acceptance=True,runs=runs),indent=2)+'\n')
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN'
    original=capture([directory/'batch_manifest.json'],owners,image_path)
    assert len(original['scenarios'])==2 and not original['nondeterministic_entries']
    for state in original['scenarios']:
        assert state['state_sha256'] in expected_states and set(state['entries'])==set(owners)
        for row in state['entries'].values():
            assert row['distinct_inputs']>=64 and not row['device_records']
            assert row['covered_body_bytes']==row['body_bytes'] and not row['missing_pcs']
            assert set(map(int,row['excluded_flags'])) <= {1,4,5,6}
    replay=verify(directory,report,min_cases=64,jobs=1,executable=native,timeout=600)
    assert set(replay)==set(owners) and all(row['pass'] for row in replay.values()), 'strict held replay failed'
    manifest=json.loads((directory/'capsule_manifest.json').read_text())
    for entry,row in replay.items():
        count=len(manifest['entries'][entry])
        assert row['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
    previous=CACHE/'coverage_65_replay_transition_helpers_combined_dev_v1_export'
    dev_inputs=inputs(previous);new_inputs=inputs(directory)
    old_states={state['state_sha256'] for state in development['original']['scenarios']}
    assert old_states.isdisjoint(expected_states)
    for entry in owners:assert dev_inputs[entry].isdisjoint(new_inputs[entry])
    callable_path=ROOT/'tools/oracle/replay_transition_callable_v1.json'
    callables=json.loads(callable_path.read_text());spans=body_spans();image=image_path.read_bytes()
    for owner,attribution in callables.items():validate(int(owner,16),attribution,spans[int(owner,16)],directory,image)
    save_path=CACHE/'strip_parent_original_state_save_v1_export/batch_manifest.json'
    saves=json.loads(save_path.read_text());assert len(saves['runs'])==2
    for run,index in zip(saves['runs'],(45,46)):
        assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==32
        local=ROOT/f'tools/emu/flycast-build/data/vf3_{index}.state';cached=CACHE/f'data/vf3_{index}.state'
        assert digest(local)==digest(cached) and digest(local) in expected_states
        refs += [reference(local),reference(cached)]
        refs += [reference(ROOT/Path(run[key])) for key in ('state','play','log','hits')]
    coverage_path=CACHE/'scene_round_full_checkpoint_v1/extract/analysis/coverage.json'
    checkpoint_path=ROOT/'tools/oracle/scene_round_full_checkpoint_v1.json'
    checkpoint=json.loads(checkpoint_path.read_text())
    archived=[row for row in checkpoint['references'] if Path(row['path']).resolve()==coverage_path.resolve()]
    assert len(archived)==1 and digest(coverage_path)==archived[0]['sha256']
    coverage=json.loads(coverage_path.read_text());assert coverage['ported_unique_bytes']==276158 and coverage['bytes_total']==434656
    before={pc for start,end in coverage['ported_spans'] for pc in range(start,end)}
    added={pc for owner in callables for start,end in spans[int(owner,16)] for pc in range(start,end)}
    assert len(added-before)==420
    refs += development['references']+caller_files(callables)+[reference(p) for p in directory.iterdir() if p.is_file()]
    refs += [reference(p) for p in (qualified,source,native,held_path,owners_path,report,image_path,
             callable_path,save_path,coverage_path,checkpoint_path,Path(__file__))]
    output=ROOT/'tools/oracle/replay_transition_qualification_v1.json';assert not output.exists()
    output.write_text(json.dumps(dict(coverage_credit=False,ready_for_promotion=True,
        marginal_bytes=420,development=development['original'],acceptance=original,
        strict_cases=sum(len(rows) for rows in manifest['entries'].values()),
        full_regression=development['full_regression'],references=list({row['path']:row for row in refs}.values())),indent=2)+'\n')
    print('Complete independent helper acceptance PASS; 420 bytes ready for promotion')


if __name__=='__main__':main()
