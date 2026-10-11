"""Seal selected-port C, independent complete returns, regression and byte credit."""
import json
import re
import struct
from pathlib import Path
from task_completion_audit import CACHE, ROOT, freeze, load, ref, sha
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize


def audit():
    archive = CACHE / 'controller_port_dev_v1_complete_sources/manifest.json'
    native = freeze(archive, native=True)
    assert len(load(archive)['files']) == 364
    observer = CACHE / 'task_return_boundary_v1_linked_sources/manifest.json'
    emulator = freeze(observer)
    image = ROOT / 'extract/gamedata/1ST_READ.BIN'
    rom = image.read_bytes()
    campaigns = []
    for label in ['dev', 'accept']:
        name = f'coverage_65_controller_port_{label}_v1'
        corpus = ROOT / 'extract/analysis' / name
        manifest = load(corpus / 'capsule_manifest.json')
        batch = load(corpus / 'batch_manifest.json')
        validate_batch(batch, True)
        assert not manifest['invalid'] and not manifest['nondeterministic_entries']
        assert len(manifest['entries']['0x8c09b006']) == 128
        assert all(r['started'] == r['completed'] and not r['incomplete'] and not r['unaccounted'] for r in manifest['runs'])
        paths, statuses, ports = set(), set(), set()
        count = 0
        for source in manifest['inputs']:
            for sample in records(Path(source)):
                assert not sample['flags']
                before = struct.unpack('<63I', sample['before'])
                after = struct.unpack('<63I', sample['after'])
                assert before[8:16] == after[8:16]
                assert before[16] == after[16]
                ports.add(before[4])
                for pc, opcode in sample['ops']:
                    offset = (pc & 0x1fffffff) - 0x0c010000
                    assert struct.unpack_from('<H', rom, offset)[0] == opcode
                    if (pc & 0x1fffffff) in (0x0c09b01a, 0x0c09b022):
                        paths.add(pc & 0x1fffffff)
                statuses.add(after[17] & 1)
                count += 1
        assert count == 128 and paths == {0x0c09b01a, 0x0c09b022}
        assert ports == {0, 1} and statuses == {0, 1}
        report = ROOT / f'extract/analysis/{name}_native_report.json'
        proof = load(report)['0x8c09b006']
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == 'matrix_family: 128/128 cases match (0 skipped) - PASS'
        campaigns.append(dict(batch=ref(corpus / 'batch_manifest.json'), report=ref(report),
            capsules=[ref(p) for p in manifest['inputs']],
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]))
    subset_path = CACHE / 'controller_port_v1_affected_bindings.json'
    subset = load(subset_path)
    bindings = load(ROOT / 'tools/golden_bindings.json')
    assert len(bindings) == 1370 and len(subset) == 17
    assert all(bindings[k] == v for k, v in subset.items())
    log = ROOT / 'extract/analysis/controller_port_v1_affected_portcheck.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text, subset)
    assert status['passed'] and status['reported_bindings'] == 17
    checks = re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s', text.split('replay tests:\n', 1)[1].split('golden-bound ports:\n', 1)[0], re.M)
    assert len(checks) == 39 and all(v == 'PASS' for _, v in checks)
    native_tests = []
    for name, _ in checks:
        archived = CACHE / f'native_controller_port_v1/{name}.exe'
        assert sha(archived) == sha(ROOT / f'build/{name}.exe')
        native_tests.append(ref(archived))
    tests = ROOT / 'extract/analysis/controller_port_v1_tool_tests.log'
    assert 'Ran 110 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    selection = ROOT / 'extract/analysis/controller_port_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers']
    milestone = ROOT / 'tools/oracle/percentage_controller_port_v1_milestone.json'
    promoted = load(milestone)
    assert promoted['measured_gain'] == 32 and promoted['target_gain'] == 23339 and not promoted['target_met']
    chain = ROOT / 'extract/analysis/controller_port_v1_chain_extension.json'
    extension = load(chain)
    assert extension['passed'] and extension['complete'] and extension['hashes']
    assert extension['baseline_bytes'] == 259188 and extension['final_bytes'] == 259220
    assert extension['target_bytes'] == 282527 and not extension['target_met']
    previous = ROOT / 'extract/analysis/controller_merge_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes'] == 259188
    return dict(passed=True, coverage_credit=True, new_bytes=32,
        readable_bytes=259220, total_body_bytes=434656, remaining_to_65=23307,
        frozen_sources=ref(archive), native=ref(native), original_emulator=ref(emulator),
        frozen_observer=ref(observer), image=ref(image), campaigns=campaigns,
        milestone=ref(milestone), milestone_audit=ref(ROOT / 'extract/analysis/controller_port_v1_milestone_audit.log'),
        chain_extension=ref(chain), reused_previous_complete_chain=ref(previous),
        previous_seal=ref(ROOT / 'tools/oracle/controller_merge_v1_manifest.json'),
        regression_scope='17 observed reverse-dependency/static module bindings and 39 native suites. Previous full repository gate remains historical.',
        affected_bindings=ref(subset_path), selection=ref(selection), affected_regression=ref(log),
        regression_status=status, native_tests=native_tests, tool_tests=ref(tests),
        current_bindings=ref(ROOT / 'tools/golden_bindings.json'), audit_tool=ref(Path(__file__)))


if __name__ == '__main__':
    output = ROOT / 'tools/oracle/controller_port_v1_manifest.json'
    assert not output.exists(), 'sealed proof already exists'
    output.write_text(json.dumps(audit(), indent=2)+'\n')
    print('Controller port: +32 verified bytes; 128 development/128 acceptance and affected regression PASS')
