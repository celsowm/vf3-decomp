"""Seal complete readable selection development before independent acceptance."""
from collections import Counter, defaultdict
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

from ram_clipping_batch_audit import caller_files, digest, reference
from regression_status import summarize
from task_completion_audit import freeze
from audio_corpus import validate_batch
from capsules import records

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0, str(ROOT/'tools'))
from body_cover import body_spans
from callable_geometry import original_pools
from callable_body import validate
from portcheck import TESTS

ENTRY = '0x8c0c3210'
OWNER = 0x8c0c321e


def campaign(directory, report_path, native, expected_runs):
    directory = Path(directory)
    manifest = json.loads((directory/'capsule_manifest.json').read_text())
    batch = json.loads((directory/'batch_manifest.json').read_text())
    validate_batch(batch, True)
    assert len(batch['runs']) == expected_runs and not manifest['nondeterministic_entries']
    image_path = ROOT/'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    scenarios = {}
    fingerprints = set()
    refs = []
    for run in batch['runs']:
        raw = Path(run['capsule'])
        summary_path = Path(str(raw)+'.summary.json')
        summary = json.loads(summary_path.read_text())
        assert summary['started'] == summary['completed']
        assert not summary['incomplete'] and not summary['unaccounted']
        assert run['emulator_sha256'] == digest(CACHE/'flycast_task_return_boundary_v1.exe')
        assert digest(run['entry_patch']) == run['entry_patch_sha256']
        state = ROOT/run['state']
        state_hash = digest(state)
        seen, inputs, invalid = scenarios.setdefault(state_hash, (set(), set(), Counter()))
        counted = 0
        for sample in records(raw):
            counted += 1
            assert hex(sample['entry']|0x80000000) == ENTRY
            if sample['flags']:
                assert sample['flags'] in (1, 4, 5, 6)
                invalid[sample['flags']] += 1
                continue
            assert sample['nstate'] == 63 and not sample['device']
            original_pools(sample, image, sample['ops'])
            fingerprint = hashlib.sha256(sample['before']+b''.join(
                struct.pack('<I', base)+before for base, before, _ in sample['pages'])).hexdigest()
            fingerprints.add(fingerprint)
            inputs.add(fingerprint)
            for pc, opcode in sample['ops']:
                offset = (pc&0x1fffffff)-0x0c010000
                assert 0 <= offset <= len(image)-2
                assert struct.unpack_from('<H', image, offset)[0] == opcode
                seen.add(pc|0x80000000)
        assert counted == summary['completed']
        refs.extend(reference(p) for p in (raw, summary_path, state, Path(run['log']), Path(run['entry_patch'])))
    assert len(scenarios) == 2
    required = {pc for a,z in body_spans()[OWNER] for pc in range(a,z,2)}
    proofs = []
    for state_hash, (seen, inputs, invalid) in scenarios.items():
        assert required <= seen, f'incomplete original selection body in {state_hash}'
        assert len(inputs) >= 64
        proofs.append(dict(state_sha256=state_hash, distinct_valid=len(inputs), excluded=dict(invalid), whole_body=True))
    count = len(manifest['entries'][ENTRY])
    assert count >= 64 and set(manifest['entries']) == {ENTRY}
    row = json.loads(Path(report_path).read_text())[ENTRY]
    assert row['pass'] and row['stdout'] == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
    assert row['executable_sha256'] == digest(native)
    assert Path(row['cases']).resolve() == (directory/f'f_{int(ENTRY,16):08x}.cases').resolve()
    attribution_path = ROOT/'tools/oracle/selection_unlock_callable_v1.json'
    attributions = json.loads(attribution_path.read_text())
    assert set(attributions) == {hex(OWNER)}
    validate(OWNER, attributions[hex(OWNER)], body_spans()[OWNER], directory, image)
    refs += caller_files(attributions)
    refs.extend(reference(p) for p in directory.iterdir() if p.is_file())
    refs.extend(reference(p) for p in (report_path, image_path, attribution_path))
    return set(scenarios), fingerprints, proofs, refs


def main():
    archive = CACHE/'selection_unlock_integrated_dev_v1_complete_sources/manifest.json'
    native = freeze(archive, native=True)
    source = json.loads(archive.read_text())
    assert len(source['files']) == 401 and source['compiler_dependency_files'] == 398
    states, inputs, proofs, refs = campaign(
        CACHE/'coverage_65_selection_unlock_combined_dev_v1_export',
        ROOT/'extract/analysis/selection_unlock_integrated_combined_dev_v1_native.json', native, 6)
    bindings = ROOT/'tools/golden_bindings.json'
    log = ROOT/'extract/analysis/selection_unlock_integrated_all_bindings_dev_v1.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text, json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings'] == 1414
    native_section = text.split('\nbinding ', 1)[0]
    suite_rows = dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b', native_section, re.M))
    assert set(suite_rows) == set(TESTS) and all(v == 'PASS' for v in suite_rows.values())
    tests = ROOT/'extract/analysis/selection_unlock_tool_tests_dev_v2.log'
    test_text = tests.read_text()
    assert re.search(r'Ran 335 tests', test_text) and '\nOK\n' in test_text
    refs.extend(reference(p) for p in (archive, native, bindings, log, tests, Path(__file__),
        ROOT/'tools/oracle/compiled_source_freeze.py', ROOT/'tools/oracle/selection_unlock_holdout_inputs.py'))
    refs.extend(reference(ROOT/'build'/f'{name}.exe') for name in TESTS)
    out = CACHE/'selection_unlock_qualified_development_freeze_v1.json'
    assert not out.exists()
    out.write_text(json.dumps(dict(coverage_credit=False, qualified_development_only=True,
        frozen_at_utc=datetime.now(timezone.utc).isoformat(), archived_inputs=401,
        compiler_dependency_files=398, entries=1, distinct_valid_inputs=len(inputs),
        native_suites_passed=39, oracle_tests_passed=335, full_regression=status,
        scenarios=proofs, references=list({r['path']:r for r in refs}.values())), indent=2)+'\n')
    print('Selection development freeze PASS; independent acceptance still required')


if __name__ == '__main__':
    main()
