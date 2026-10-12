"""Require complete independent strip proof before any ledger promotion."""
import json
from pathlib import Path
from ram_clipping_batch_audit import campaign, caller_files, digest, reference
from regression_status import summarize
from task_completion_audit import freeze

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    source=CACHE/'strip_parent_integrated_dev_v1_complete_sources/manifest.json'
    native=freeze(source,native=True)
    assert len(json.loads(source.read_text())['files'])==400
    qualified=CACHE/'strip_parent_qualified_development_freeze_v1.json'
    development=json.loads(qualified.read_text())
    assert development['qualified_development_only'] and development['compiled_inputs']==400
    for ref in development['references']:assert digest(ref['path'])==ref['sha256'],'development dependency changed'
    inputs=ROOT/'tools/oracle/coverage_65_strip_parent_accept_v1_input_manifest.json'
    held=json.loads(inputs.read_text())
    assert held['development_freeze']==reference(qualified)
    assert inputs.stat().st_mtime_ns>=qualified.stat().st_mtime_ns
    for ref in held['files']:assert digest(ref['path'])==ref['sha256'],'held-out input changed'
    owners_path=ROOT/'tools/oracle/coverage_65_strip_parent_screen_v3_owners.json'
    owners=json.loads(owners_path.read_text());assert len(owners)==5
    image=ROOT/'extract/gamedata/1ST_READ.BIN'
    ds,di,dev,df=campaign(CACHE/'coverage_65_strip_parent_screen_v3_export',
        ROOT/'extract/analysis/strip_parent_integrated_dev_v2_frozen_native.json',owners,native,image.read_bytes())
    hs,hi,accept,hf=campaign(CACHE/'coverage_65_strip_parent_accept_v1_export',
        ROOT/'extract/analysis/strip_parent_integrated_accept_v1_native.json',owners,native,image.read_bytes())
    assert ds.isdisjoint(hs) and di.isdisjoint(hi),'development/acceptance overlap'
    # Original native SAVEF captures establish the independent state lineage.
    save=CACHE/'strip_parent_original_state_save_v1_export/batch_manifest.json'
    saves=json.loads(save.read_text())
    assert len(saves['runs'])==2
    provenance=[reference(save)]
    for run,index in zip(saves['runs'],(45,46)):
        assert run['returncode']==0 and run['frame_complete'] and run['ran_frames']==32
        for key in ('state','play','log','hits'):
            path=Path(run[key]);provenance.append(reference(path if path.is_absolute() else ROOT/path))
        cached=CACHE/f'data/vf3_{index}.state';local=ROOT/f'tools/emu/flycast-build/data/vf3_{index}.state'
        assert digest(cached)==digest(local) and digest(local) in hs
        provenance.extend((reference(cached),reference(local)))
    attribution_path=ROOT/'tools/oracle/strip_parent_callable_v1.json'
    attributions=json.loads(attribution_path.read_text());assert set(attributions)==set(owners.values())
    from body_cover import body_spans
    from callable_body import validate
    spans=body_spans()
    for owner,attribution in attributions.items():
        for directory in ('coverage_65_strip_parent_screen_v3_export','coverage_65_strip_parent_accept_v1_export'):
            validate(int(owner,16),attribution,spans[int(owner,16)],CACHE/directory,image.read_bytes())
    baseline_path=ROOT/'tools/oracle/strip_parent_coverage_baseline_v1.json'
    baseline=json.loads(baseline_path.read_text())
    assert baseline['baseline_bytes']==273148 and baseline['target_bytes']==282527 and baseline['total_body_bytes']==434656
    accepted={pc for a,z in baseline['baseline_spans'] for pc in range(a,z)}
    added={pc for owner in owners.values() for a,z in spans[int(owner,16)] for pc in range(a,z)}
    gain=len(added-accepted);assert gain==2128
    for key in ('inventory','body_ranges','image'):assert digest(ROOT/baseline[key])==baseline[key+'_sha256']
    log=ROOT/'extract/analysis/strip_parent_integrated_all_bindings_dev_v1.log'
    status=summarize(log.read_text(encoding='utf-8-sig'),json.loads((ROOT/'tools/golden_bindings.json').read_text()))
    assert status['passed']
    refs=df+hf+provenance+caller_files(attributions)+[reference(path) for path in
        (source,native,qualified,inputs,owners_path,attribution_path,baseline_path,image,Path(__file__))]
    out=ROOT/'tools/oracle/strip_parent_qualification_v1.json';assert not out.exists()
    out.write_text(json.dumps(dict(coverage_credit=False,ready_for_promotion=True,
        marginal_bytes=gain,frozen_body_bytes=434656,development=dev,acceptance=accept,
        full_regression=status,references=list({row['path']:row for row in refs}.values())),indent=2)+'\n')
    print('Independent strip acceptance PASS; 2128 bytes ready for promotion')


if __name__=='__main__':main()
