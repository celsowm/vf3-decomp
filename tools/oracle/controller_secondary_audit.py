"""Seal the controller merge's C, whole-body/caller proof and marginal union."""
import json
import re
import sys
from pathlib import Path
from task_completion_audit import CACHE, ROOT, freeze, load, ref, sha
from regression_status import summarize
from capsules import records
from audio_corpus import validate_batch

sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans
from callable_body import validate
from portcheck import TESTS


def audit():
    archive = CACHE / 'controller_secondary_dev_v1_complete_sources/manifest.json'
    native = freeze(archive, native=True)
    assert len(load(archive)['files']) == 365
    attribution_path = ROOT / 'tools/oracle/controller_secondary_callable_v1.json'
    attribution = load(attribution_path)['0x8c09afc6']
    campaigns = []
    for label in ['dev', 'accept']:
        name = f'coverage_65_controller_secondary_{label}_v1'
        corpus = ROOT / 'extract/analysis' / name
        manifest = load(corpus / 'capsule_manifest.json')
        batch = load(corpus / 'batch_manifest.json')
        validate_batch(batch, True)
        assert not manifest['invalid'] and not manifest['nondeterministic_entries']
        assert len(manifest['entries']['0x8c09afc0']) == 128
        assert all(r['started'] == r['completed'] and not r['incomplete'] and not r['unaccounted'] for r in manifest['runs'])
        validate(0x8c09afc6, attribution, body_spans()[0x8c09afc6], corpus)
        report = ROOT / f'extract/analysis/{name}_native_report.json'
        proof = load(report)['0x8c09afc0']
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == 'matrix_family: 128/128 cases match (0 skipped) - PASS'
        campaigns.append(dict(batch=ref(corpus / 'batch_manifest.json'), report=ref(report),
            capsules=[ref(p) for p in manifest['inputs']],
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]))
    original = Path(attribution['original_caller_manifests'][0]['path'])
    caller = load(original)
    assert caller['passed'] and len(caller['runs']) == 16
    caller_files = []
    for path, digest in caller['provenance'].items():
        assert sha(path) == digest
    for run in caller['runs']:
        assert run['flags'] == 0 and run['device_accesses'] == run['aica_events'] == 0
        assert run['summary']['explicit_return_only']
        for path, digest in [(run['capsule'], run['capsule_sha256']),
                             (run['log'], run['log_sha256']),
                             (Path(run['log']).with_suffix('.patch'), run['patch_sha256'])]:
            assert sha(path) == digest
            caller_files.append(ref(path))
    affected = CACHE / 'controller_secondary_v1_affected_bindings.json'
    subset = load(affected)
    assert len(subset) == 18
    bindings = load(ROOT / 'tools/golden_bindings.json')
    assert len(bindings) == 1371 and all(bindings[k] == v for k, v in subset.items())
    log = ROOT / 'extract/analysis/controller_secondary_v1_affected_portcheck.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text, subset)
    assert status['passed'] and status['reported_bindings'] == 18
    section = text.split('replay tests:\n', 1)[1].split('golden-bound ports:\n', 1)[0]
    checks = re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s', section, re.M)
    assert len(checks) == len(TESTS) == 39 and all(v == 'PASS' for _, v in checks)
    native_tests = []
    for name in TESTS:
        archived = CACHE / f'native_controller_secondary_v1/{name}.exe'
        assert sha(archived) == sha(ROOT / f'build/{name}.exe')
        native_tests.append(ref(archived))
    tests = ROOT / 'extract/analysis/controller_secondary_v1_tool_tests.log'
    assert 'Ran 116 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    milestone = ROOT / 'tools/oracle/percentage_controller_secondary_v1_milestone.json'
    promoted = load(milestone)
    assert promoted['measured_gain'] == 64 and promoted['target_gain'] == 23307 and not promoted['target_met']
    chain = ROOT / 'extract/analysis/controller_secondary_v1_chain_extension.json'
    extension = load(chain)
    assert extension['passed'] and extension['complete'] and extension['hashes']
    assert extension['baseline_bytes'] == 259220 and extension['final_bytes'] == 259284
    assert extension['target_bytes'] == 282527 and not extension['target_met']
    previous = ROOT / 'extract/analysis/controller_port_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes'] == 259220
    selection = ROOT / 'extract/analysis/controller_secondary_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers']
    return dict(passed=True, coverage_credit=True, new_bytes=64,
                readable_bytes=259284, total_body_bytes=434656, remaining_to_65=23243,
                frozen_sources=ref(archive), native=ref(native), campaigns=campaigns,
                attribution=ref(attribution_path), original_callers=ref(original), caller_files=caller_files,
                validator=ref(ROOT / 'tools/callable_controller_secondary.py'),
                milestone=ref(milestone), milestone_audit=ref(ROOT / 'extract/analysis/controller_secondary_v1_milestone_audit.log'),
                chain_extension=ref(chain), reused_previous_complete_chain=ref(previous),
                previous_seal=ref(ROOT / 'tools/oracle/controller_port_v1_manifest.json'),
                historical_full_repository_gate=ref(ROOT / 'tools/oracle/task_completion_v1_manifest.json'),
                regression_scope='Current controller change: observed reverse dependencies and static target/small-tail module bindings (18), plus 39 native suites. The earlier 1368-binding full gate validates the preceding task-completion checkpoint.',
                affected_bindings=ref(affected), selection=ref(selection), affected_regression=ref(log),
                regression_status=status, native_tests=native_tests, tool_tests=ref(tests),
                current_bindings=ref(ROOT / 'tools/golden_bindings.json'),
                audit_tool=ref(Path(__file__)))


if __name__ == '__main__':
    output = ROOT / 'tools/oracle/controller_secondary_v1_manifest.json'
    assert not output.exists(), 'sealed proof already exists'
    output.write_text(json.dumps(audit(), indent=2)+'\n')
    print('Controller secondary merge: +64 verified bytes; 128 development/128 acceptance and affected regression PASS')
