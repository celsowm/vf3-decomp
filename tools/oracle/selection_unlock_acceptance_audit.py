"""Replay and qualify independent selection acceptance before any C credit."""
import json
from pathlib import Path
from capsules import convert
from selection_unlock_development_freeze import campaign
from ram_clipping_batch_audit import digest, reference
from task_completion_audit import freeze
from verify_matrix import verify

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    qualified=CACHE/'selection_unlock_qualified_development_freeze_v1.json'
    development=json.loads(qualified.read_text())
    assert development['qualified_development_only'] and development['archived_inputs']==401
    for row in development['references']:
        assert digest(row['path'])==row['sha256'], 'development dependency changed'
    archive=CACHE/'selection_unlock_integrated_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    inputs=ROOT/'tools/oracle/coverage_65_selection_unlock_accept_input_manifest_v1.json'
    held=json.loads(inputs.read_text())
    assert held['development_freeze']==reference(qualified)
    assert inputs.stat().st_mtime_ns>=qualified.stat().st_mtime_ns
    for row in [*held['files'],*held['original_states']]:assert digest(row['path'])==row['sha256']
    runs=[];refs=[]
    for version in (1,2,3):
        path=CACHE/f'coverage_65_selection_unlock_accept_v{version}_export/batch_manifest.json'
        batch=json.loads(path.read_text());assert len(batch['runs'])==2
        for run in batch['runs']:
            assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==run['expected_frames']==2000
            runs.append(dict(run,name=f'v{version}_'+run['name']))
        refs.append(reference(path))
    directory=CACHE/'coverage_65_selection_unlock_combined_accept_v1_export'
    assert not directory.exists(), 'refuse to replace independent acceptance artifacts'
    convert([Path(r['capsule']) for r in runs],directory)
    (directory/'batch_manifest.json').write_text(json.dumps(dict(
        name='selection_unlock_combined_accept_v1',coverage_credit=False,runs=runs),indent=2)+'\n')
    report=ROOT/'extract/analysis/selection_unlock_integrated_combined_accept_v1_native.json'
    assert not report.exists()
    rows=verify(directory,report,min_cases=64,jobs=1,executable=native,timeout=600)
    assert rows and all(row['pass'] for row in rows.values()), 'strict native acceptance failed; no qualification'
    ds,di,dev,df=campaign(CACHE/'coverage_65_selection_unlock_combined_dev_v1_export',
        ROOT/'extract/analysis/selection_unlock_integrated_combined_dev_v1_native.json',native,6)
    hs,hi,accept,hf=campaign(directory,report,native,6)
    assert ds.isdisjoint(hs) and di.isdisjoint(hi), 'development/acceptance overlap'
    save=CACHE/'strip_parent_original_state_save_v1_export/batch_manifest.json'
    saves=json.loads(save.read_text());assert len(saves['runs'])==2
    refs.append(reference(save))
    for run,index in zip(saves['runs'],(45,46)):
        assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==32
        cached=CACHE/f'data/vf3_{index}.state';local=ROOT/f'tools/emu/flycast-build/data/vf3_{index}.state'
        assert digest(cached)==digest(local) and digest(local) in hs
        refs.extend(reference(p) for p in (cached,local))
        for key in ('state','play','log','hits'):
            path=Path(run[key]);refs.append(reference(path if path.is_absolute() else ROOT/path))
    baseline_path=ROOT/'tools/oracle/selection_unlock_coverage_baseline_v1.json'
    baseline=json.loads(baseline_path.read_text())
    assert baseline['baseline_bytes']==275276 and baseline['target_bytes']==282527 and baseline['total_body_bytes']==434656
    from body_cover import body_spans
    accepted={pc for a,z in baseline['baseline_spans'] for pc in range(a,z)}
    added={pc for a,z in body_spans()[0x8c0c321e] for pc in range(a,z)}
    gain=len(added-accepted);assert gain==1574
    for key in ('inventory','body_ranges','image'):
        assert digest(ROOT/baseline[key])==baseline[key+'_sha256']
    refs += df+hf+[reference(p) for p in (qualified,archive,native,inputs,baseline_path,Path(__file__))]
    out=ROOT/'tools/oracle/selection_unlock_qualification_v1.json';assert not out.exists()
    out.write_text(json.dumps(dict(coverage_credit=False,ready_for_promotion=True,
        marginal_bytes=gain,development=dev,acceptance=accept,full_regression=development['full_regression'],
        references=list({r['path']:r for r in refs}.values())),indent=2)+'\n')
    print('Independent selection acceptance PASS; 1574 bytes ready for promotion')


if __name__=='__main__':main()
