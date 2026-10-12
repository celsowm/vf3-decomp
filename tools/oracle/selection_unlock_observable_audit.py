"""Pin two original selection input disagreements; exclude the entire owner."""
import json
from pathlib import Path
import struct
import sys
from capsules import records
from compare_original_samples import compare
from ram_clipping_batch_audit import reference, digest

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0,str(ROOT/'tools'))
from callable_geometry import original_pools


def audit():
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN';image=image_path.read_bytes()
    observer=CACHE/'flycast_task_return_boundary_v1.exe'
    assert digest(observer)=='b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
    batch_path=CACHE/'coverage_65_selection_unlock_accept_v3_export/batch_manifest.json'
    batch=json.loads(batch_path.read_text());assert len(batch['runs'])==2
    refs=[reference(p) for p in (image_path,observer,batch_path,Path(__file__))];pairs=[]
    for run,state,ident in zip(batch['runs'],(45,46),(142,199)):
        assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==2000
        assert run['emulator_sha256']==digest(observer)
        state_path=ROOT/run['state'];assert state_path.name==f'vf3_{state}.state'
        original=Path(run['capsule'])
        repeat_path=CACHE/f'selection_unlock_repeat_{ident}_original_v1/manifest.json'
        repeat=json.loads(repeat_path.read_text())
        assert repeat['execution']=='original_sh4' and repeat['mode']=='nonrollback_one_shot' and repeat['passed']
        assert len(repeat['runs'])==1
        new=repeat['runs'][0]
        assert digest(ROOT/new['state'])==digest(state_path)
        assert new['passed'] and new['returncode']==0 and new['flags']==0 and new['device_accesses']==0
        summary=new['summary']
        assert summary['explicit_return_only'] and summary['one_shot_done'] and not summary['restores']
        assert summary['started']==summary['completed']==1 and not summary['incomplete'] and not summary['unaccounted']
        repeated=Path(new['capsule'])
        for path,expected in repeat['provenance'].items():
            assert digest(path)==expected;refs.append(reference(path))
        assert repeat['provenance'][str(observer)]==digest(observer)
        result=compare(original,ident,repeated,1)
        assert result['observable_disagreement'] and not result['input_register_differences']
        specimens=[next(s for s in records(path) if s['id']==number)
                   for path,number in ((original,ident),(repeated,1))]
        assert result['canonical_instruction_traces_equal'],'instruction traces changed'
        for sample in specimens:
            assert sample['entry']&0x1fffffff==0x0c0c3210
            original_pools(sample,image,sample['ops'])
            for pc,op in sample['ops']:
                offset=(pc&0x1fffffff)-0x0c010000
                assert 0<=offset<=len(image)-2 and struct.unpack_from('<H',image,offset)[0]==op
        queue=[next(after[:16].hex() for base,before,after in sample['pages'] if base==0x0c650000)
               for sample in specimens]
        assert queue[0]!=queue[1]
        pairs.append(dict(state=state,original_invocation=ident,repeat_invocation=1,
            all_63_input_words_equal=True,captured_input_pages_equal=True,executed_instructions_equal=True,
            original_queue_preview=queue[0],repeat_queue_preview=queue[1],
            comparison=result))
        paths=[state_path,original,Path(str(original)+'.summary.json'),Path(run['log']),
            Path(run['entry_patch']),repeat_path,repeated,Path(str(repeated)+'.summary.json'),
            Path(new['log']),Path(new['log']).with_suffix('.patch'),Path(new['audio']['path'])]
        for path in paths:refs.append(reference(path))
    return dict(coverage_credit=False,quarantined_entry='0x8c0c3210',quarantined_owner='0x8c0c321e',
        excluded_owner_bytes=1574,
        reason='Two states independently reproduce identical captured RAM and 63-word inputs with differing original final RAM. This input model cannot qualify the entire owner; passing subsets remain excluded.',
        limitation='The frame campaign also has two unrelated incomplete invocations. These comparisons use complete flag-zero specimens solely to prove ambiguity, not to qualify that campaign. The hidden state responsible is not established.',
        pairs=pairs,references=list({r['path']:r for r in refs}.values()))


if __name__=='__main__':
    out=ROOT/'tools/oracle/selection_unlock_observable_quarantine_v1.json'
    assert not out.exists(),'refuse to replace original quarantine evidence'
    result=audit();out.write_text(json.dumps(result,indent=2)+'\n')
    print('Both original observable-input disagreements verified; all 1574 owner bytes remain excluded')
