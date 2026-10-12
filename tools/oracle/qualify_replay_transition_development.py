"""Freeze the complete replay-helper development before fresh held inputs."""
from datetime import datetime, timezone
import json
from pathlib import Path
import re
import sys
from evidence_inspect import capture
from ram_clipping_batch_audit import digest, reference, caller_files
from regression_status import summarize
from task_completion_audit import freeze

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate
from portcheck import TESTS


def main():
    output=CACHE/'replay_transition_qualified_development_freeze_v1.json'
    assert not output.exists(), 'refuse to replace development freeze'
    source=CACHE/'scene_batch_integrated_dev_v1_complete_sources/manifest.json'
    native=freeze(source,native=True)
    compiled=json.loads(source.read_text())
    assert len(compiled['files'])==408 and compiled['compiler_dependency_files']==405
    directory=CACHE/'coverage_65_replay_transition_helpers_combined_dev_v1_export'
    batch_path=directory/'batch_manifest.json'
    owners_path=ROOT/'tools/oracle/coverage_65_replay_transition_helpers_dev_v2_owners.json'
    owners=json.loads(owners_path.read_text())
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN'
    inspected=capture([batch_path],owners,image_path)
    assert len(inspected['runs'])==4 and len(inspected['scenarios'])==2
    assert not inspected['nondeterministic_entries']
    for run in inspected['runs']:
        assert run['complete_accounting'] and run['frame_complete'] and run['returncode']==0
    for state in inspected['scenarios']:
        assert set(state['entries'])==set(owners)
        for row in state['entries'].values():
            assert row['distinct_inputs']>=64 and not row['device_records']
            assert row['covered_body_bytes']==row['body_bytes'] and not row['missing_pcs']
    report_path=ROOT/'extract/analysis/replay_transition_helpers_integrated_combined_dev_v1_native.json'
    report=json.loads(report_path.read_text())
    manifest=json.loads((directory/'capsule_manifest.json').read_text())
    assert set(report)==set(owners)==set(manifest['entries'])
    for entry,row in report.items():
        count=len(manifest['entries'][entry])
        assert row['pass'] and row['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        assert row['executable_sha256']==digest(native)
    callable_path=ROOT/'tools/oracle/replay_transition_callable_v1.json'
    callables=json.loads(callable_path.read_text());assert len(callables)==3
    image=image_path.read_bytes();spans=body_spans()
    for owner,attribution in callables.items():
        validate(int(owner,16),attribution,spans[int(owner,16)],directory,image)
    bindings=ROOT/'tools/golden_bindings.json'
    full_log=ROOT/'extract/analysis/scene_round_all_bindings_accept_v1.log'
    text=full_log.read_text(encoding='utf-8-sig')
    status=summarize(text,json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings']==1415
    suites=dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b',text.split('\nbinding ',1)[0],re.M))
    assert set(suites)==set(TESTS) and all(value=='PASS' for value in suites.values())
    tests=ROOT/'extract/analysis/replay_transition_tool_tests_dev_v1.log'
    assert re.search(r'Ran 388 tests\b',tests.read_text()) and '\nOK\n' in tests.read_text()
    original_proof=ROOT/'extract/analysis/replay_transition_helpers_complete_original_dev_v1.json'
    original=json.loads(original_proof.read_text());assert original['whole_original_bodies']
    for row in original['references']:assert digest(row['path'])==row['sha256']
    refs=original['references']+caller_files(callables)
    refs += [reference(path) for path in directory.iterdir() if path.is_file()]
    refs += [reference(path) for path in (source,native,owners_path,image_path,report_path,
        callable_path,bindings,full_log,tests,original_proof,Path(__file__),
        ROOT/'tools/callable_body.py',ROOT/'tools/callable_replay_transition.py',
        ROOT/'tools/callable_dispatch.py',ROOT/'tools/callable_geometry.py',
        ROOT/'tools/oracle/replay_transition_caller_audit.py',ROOT/'tools/oracle/capsules.py')]
    refs += [reference(ROOT/'build'/f'{name}.exe') for name in TESTS]
    output.write_text(json.dumps(dict(coverage_credit=False,qualified_development_only=True,
        frozen_at_utc=datetime.now(timezone.utc).isoformat(),marginal_candidate_bytes=420,
        normal_source_archive=reference(source),native=reference(native),original=inspected,
        complete_strict_cases=sum(len(rows) for rows in manifest['entries'].values()),
        full_regression=status,native_suites=39,oracle_tests=388,
        references=list({row['path']:row for row in refs}.values())),indent=2)+'\n')
    print('Five complete helper developments qualified; 420 marginal bytes still need fresh acceptance')


if __name__=='__main__':main()
