"""Seal complete actor geometry, caller attribution and marginal byte credit."""
from collections import Counter
import json
from pathlib import Path
import re
import struct
import sys
from task_completion_audit import CACHE, ROOT, freeze, load, ref, sha
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate


def audit():
    archive = CACHE/'geometry_angles_dev_v3_complete_sources/manifest.json'
    native = freeze(archive,native=True)
    assert len(load(archive)['files']) == 366
    observer = CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator = freeze(observer)
    attribution_path = ROOT/'tools/oracle/geometry_angles_callable_v1.json'
    attribution = load(attribution_path)['0x8c0ca8da']
    image = ROOT/'extract/gamedata/1ST_READ.BIN'
    rom = image.read_bytes()
    campaigns = []
    for name, count, rejected in [('coverage_65_geometry_angles_pilot_v1',128,{}),
                                   ('coverage_65_geometry_angles_accept_v2',127,{1:1})]:
        corpus = ROOT/'extract/analysis'/name
        manifest = load(corpus/'capsule_manifest.json')
        batch = load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not manifest['nondeterministic_entries']
        assert len(manifest['entries']['0x8c0ca8c0']) == count
        assert all(r['started'] == r['completed'] and not r['incomplete'] and not r['unaccounted'] for r in manifest['runs'])
        validate(0x8c0ca8da,attribution,body_spans()[0x8c0ca8da],corpus)
        valid, flags, pcs = 0, Counter(), set()
        for path in manifest['inputs']:
            for sample in records(Path(path)):
                if sample['flags']:
                    flags[sample['flags']] += 1
                    continue
                valid += 1
                before = struct.unpack('<63I',sample['before'])
                after = struct.unpack('<63I',sample['after'])
                assert before[8:16] == after[8:16] and before[16] == after[16]
                assert before[33:53] == after[33:53] and before[18] == after[18]
                for pc,op in sample['ops']:
                    offset = (pc&0x1fffffff)-0x0c010000
                    assert struct.unpack_from('<H',rom,offset)[0] == op
                    pcs.add(pc|0x80000000)
        assert valid == count and flags == rejected
        assert set(range(0x8c0ca838,0x8c0ca8c0,2)) <= pcs, 'incomplete uncredited intersection helpers'
        report = ROOT/f'extract/analysis/{name}_native_v3_report.json'
        proof = load(report)['0x8c0ca8c0']
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        campaigns.append(dict(valid=count,excluded_flags=dict(flags),batch=ref(corpus/'batch_manifest.json'),
            report=ref(report),capsules=[ref(p) for p in manifest['inputs']],
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]))
    original = Path(attribution['original_caller_manifests'][0]['path'])
    caller = load(original)
    assert caller['passed'] and len(caller['runs']) == 8
    caller_files = []
    for path,digest in caller['provenance'].items():
        assert sha(path) == digest
    for run in caller['runs']:
        assert run['flags'] == 0 and run['device_accesses'] == 0
        assert run['summary']['explicit_return_only']
        for path,digest in [(run['capsule'],run['capsule_sha256']),
                            (run['log'],run['log_sha256']),
                            (Path(run['log']).with_suffix('.patch'),run['patch_sha256'])]:
            assert sha(path) == digest
            caller_files.append(ref(path))
    subset_path = CACHE/'geometry_angles_v1_affected_bindings.json'
    subset = load(subset_path)
    bindings = load(ROOT/'tools/golden_bindings.json')
    assert len(bindings) == 1372 and len(subset) == 5
    assert all(bindings[k] == v for k,v in subset.items())
    log = ROOT/'extract/analysis/geometry_angles_v1_affected_portcheck.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text,subset)
    assert status['passed'] and status['reported_bindings'] == 5
    section = text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks = re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks) == 39 and all(v == 'PASS' for _,v in checks)
    native_tests = []
    for name,_ in checks:
        archived = CACHE/f'native_geometry_angles_v1/{name}.exe'
        assert sha(archived) == sha(ROOT/f'build/{name}.exe')
        native_tests.append(ref(archived))
    tests = ROOT/'extract/analysis/geometry_angles_v1_tool_tests.log'
    assert 'Ran 122 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    selection = ROOT/'extract/analysis/geometry_angles_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers']
    milestone = ROOT/'tools/oracle/percentage_geometry_angles_v1_milestone.json'
    promoted = load(milestone)
    assert promoted['measured_gain'] == 404 and promoted['target_gain'] == 23243 and not promoted['target_met']
    chain = ROOT/'extract/analysis/geometry_angles_v1_chain_extension.json'
    extension = load(chain)
    assert extension['passed'] and extension['complete'] and extension['hashes']
    assert extension['baseline_bytes'] == 259284 and extension['final_bytes'] == 259688
    assert extension['target_bytes'] == 282527 and not extension['target_met']
    previous = ROOT/'extract/analysis/controller_secondary_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes'] == 259284
    failed_report = ROOT/'extract/analysis/coverage_65_geometry_angles_pilot_v1_candidate_report.json'
    failed = load(failed_report)['0x8c0ca8c0']
    assert not failed['pass'] and '10/128' in failed['stdout']
    assert failed['executable_sha256'] == sha(failed['executable'])
    diagnostic_source = CACHE/'geometry_angles_candidate_v1_diagnostic'
    return dict(passed=True,coverage_credit=True,new_bytes=404,readable_bytes=259688,
        total_body_bytes=434656,remaining_to_65=22839,uncredited_helper_bytes=136,
        frozen_sources=ref(archive),native=ref(native),frozen_observer=ref(observer),
        emulator=ref(emulator),image=ref(image),campaigns=campaigns,
        attribution=ref(attribution_path),original_caller=ref(original),caller_files=caller_files,
        validator=ref(ROOT/'tools/callable_geometry.py'),
        milestone=ref(milestone),milestone_audit=ref(ROOT/'extract/analysis/geometry_angles_v1_milestone_audit.log'),
        chain_extension=ref(chain),reused_previous_complete_chain=ref(previous),
        previous_seal=ref(ROOT/'tools/oracle/controller_secondary_v1_manifest.json'),
        regression_scope='5 affected bindings: new geometry, original caller owner and three controller bindings; 39 native suites. Prior full repository gate remains historical.',
        affected_bindings=ref(subset_path),selection=ref(selection),affected_regression=ref(log),
        regression_status=status,native_tests=native_tests,tool_tests=ref(tests),
        current_bindings=ref(ROOT/'tools/golden_bindings.json'),
        diagnostics=dict(coverage_credit=False,failed_native=ref(failed['executable']),
            failed_report=ref(failed_report),failed_changed_sources=[ref(diagnostic_source/p) for p in ['geometry_angles.c','matrix_family.c','CMakeLists.txt']],
            unchanged_source_baseline=ref(CACHE/'controller_secondary_dev_v1_complete_sources/manifest.json'),
            intermediate_original=ref(CACHE/'geometry_angles_quadratic_diagnostic_v1/manifest.json'),
            earlier_holdout=ref(ROOT/'extract/analysis/coverage_65_geometry_angles_accept_v1/capsule_manifest.json'),
            note='Initial C omitted the sign inversion of the second center component. Intermediate partial-call captures are diagnostic only. The final source, including its corrected clamp comment, was rebuilt and frozen as v3 before fresh acceptance v2; acceptance v1 is retained outside the credited proof.'),
        audit_tool=ref(Path(__file__)))


if __name__ == '__main__':
    output = ROOT/'tools/oracle/geometry_angles_v1_manifest.json'
    assert not output.exists(), 'sealed proof already exists'
    output.write_text(json.dumps(audit(),indent=2)+'\n')
    print('Geometry: +404 verified bytes; 128 development/127 acceptance and affected regression PASS')
