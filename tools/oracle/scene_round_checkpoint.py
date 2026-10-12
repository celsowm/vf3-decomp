"""Seal round promotion, state lineage and the expanded full regression."""
from datetime import datetime, timezone
import json
from pathlib import Path
import re
import shutil
from ram_clipping_batch_audit import digest, reference
from regression_status import summarize
from task_completion_audit import freeze
from portcheck import TESTS

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    refs = []
    for name in ('strip_parent_historical_archive_v1.json', 'scene_round_historical_archive_v1.json'):
        path = ROOT / 'tools/oracle' / name
        data = json.loads(path.read_text())
        for row in data['references']:
            assert digest(row['path']) == row['sha256'], 'historical dependency changed'
        refs.append(reference(path))
    source = CACHE / 'scene_batch_integrated_dev_v1_complete_sources/manifest.json'
    native = freeze(source, native=True)
    compiled = json.loads(source.read_text())
    assert len(compiled['files']) == 408 and compiled['compiler_dependency_files'] == 405
    proof_path = ROOT / 'tools/oracle/scene_round_qualification_v1.json'
    proof = json.loads(proof_path.read_text())
    assert proof['ready_for_promotion'] and proof['marginal_bytes'] == 882
    state_hashes = {row['state_sha256'] for row in proof['acceptance'][0]['scenarios']}
    save_path = CACHE / 'strip_parent_original_state_save_v1_export/batch_manifest.json'
    saves = json.loads(save_path.read_text())
    assert len(saves['runs']) == 2
    for run, index in zip(saves['runs'], (45, 46)):
        assert run['returncode'] == 0 and run['frame_complete'] and run['ran_frames'] == 32
        cached = CACHE / f'data/vf3_{index}.state'
        local = ROOT / f'tools/emu/flycast-build/data/vf3_{index}.state'
        assert digest(cached) == digest(local) and digest(local) in state_hashes
        refs += [reference(cached), reference(local)]
        for key in ('state', 'play', 'log', 'hits'):
            path = Path(run[key])
            refs.append(reference(path if path.is_absolute() else ROOT / path))
    promotion_path = ROOT / 'tools/oracle/scene_round_v1_manifest.json'
    promotion = json.loads(promotion_path.read_text())
    assert set(promotion['entries']) == {'0x8c098c70'} and not promotion['excluded']
    assert promotion['measured_gain'] == 882
    coverage_path = ROOT / 'extract/analysis/coverage.json'
    coverage = json.loads(coverage_path.read_text())
    assert coverage['ported_unique_bytes'] == 276158 and coverage['bytes_total'] == 434656
    bindings = ROOT / 'tools/golden_bindings.json'
    log = ROOT / 'extract/analysis/scene_round_all_bindings_accept_v1.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text, json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings'] == 1415
    suites = dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b', text.split('\nbinding ', 1)[0], re.M))
    assert set(suites) == set(TESTS) and all(value == 'PASS' for value in suites.values())
    tests = ROOT / 'extract/analysis/scene_round_tool_tests_accept_v1.log'
    test_text = tests.read_text()
    assert re.search(r'Ran 375 tests\b', test_text) and '\nOK\n' in test_text and '\nFAILED ' not in test_text
    quarantine_path = ROOT / 'tools/oracle/scene_input_transition_observable_quarantine_v1.json'
    quarantine = json.loads(quarantine_path.read_text())
    assert not quarantine['coverage_credit'] and quarantine['quarantined_owner'] == '0x8c0993e8'
    for row in quarantine['references']:
        assert digest(row['path']) == row['sha256']
    failed_path = ROOT / 'tools/oracle/scene_input_transition_failed_acceptance_v1.json'
    failed = json.loads(failed_path.read_text())
    assert failed['acceptance_failed'] and not failed['coverage_credit']
    for row in failed['references']:
        assert digest(row['path']) == row['sha256'], 'failed campaign dependency changed'
    refs += [reference(path) for path in (source, native, proof_path, save_path, promotion_path,
             log, tests, quarantine_path, failed_path, Path(__file__))]
    refs += [reference(ROOT / 'build' / f'{name}.exe') for name in TESTS]
    archive = CACHE / 'scene_round_full_checkpoint_v1'
    output = ROOT / 'tools/oracle/scene_round_full_checkpoint_v1.json'
    assert not archive.exists() and not output.exists()
    for path in (bindings, ROOT / 'docs/decomp_status.csv', ROOT / 'docs/coverage.md', coverage_path):
        destination = archive / path.relative_to(ROOT)
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, destination)
        assert digest(destination) == digest(path)
        refs.append(dict(reference(destination), original_path=str(path)))
    output.write_text(json.dumps(dict(completed_utc=datetime.now(timezone.utc).isoformat(),
        verified_c_bytes=276158, frozen_body_bytes=434656, verified_percentage=276158/434656*100,
        target_c_bytes=282527, remaining_to_65=6369, new_owners=1, marginal_c_bytes=882,
        archived_source_inputs=408, binding_inventory=1415, native_suites=39, oracle_tool_tests=375,
        full_regression=status, scene_input_transition_credit=0, original_state_lineage=True,
        references=refs), indent=2) + '\n')
    print('Round checkpoint PASS: 276158 verified C bytes; 1415 bindings; 39 native suites; 375 tool tests')


if __name__ == '__main__':
    main()
