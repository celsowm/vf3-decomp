"""Seal complete task retirement contracts; award no new body coverage."""
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

from capsules import records
from regression_status import summarize

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans
from callable_controller import validate_controller_merge
from portcheck import TESTS


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def ref(path):
    return dict(path=str(path), sha256=sha(path))


def load(path):
    return json.loads(Path(path).read_text())


def freeze(path, native=False):
    manifest = load(path)
    for row in manifest['files']:
        assert sha(path.parent / row['path']) == row['sha256']
        assert sha(ROOT / row['path']) == row['sha256'], 'compiled dependency changed'
    executable = Path(manifest['native' if native else 'executable'])
    assert sha(executable) == manifest['native_sha256' if native else 'sha256']
    return executable


def word(sample, address, after=True):
    address &= 0x1fffffff
    for base, before, post in sample['pages']:
        if base <= address <= base + 4092:
            return struct.unpack_from('<I', post if after else before, address-base)[0]
    raise AssertionError(f'missing captured RAM {address:#x}')


def audit():
    archive = CACHE / 'task_driver_dev_v9_complete_sources/manifest.json'
    native = freeze(archive, native=True)
    assert len(load(archive)['files']) == 362
    observer = CACHE / 'task_return_boundary_v1_linked_sources/manifest.json'
    emulator = freeze(observer)
    image = ROOT / 'extract/gamedata/1ST_READ.BIN'
    rom = image.read_bytes()
    seen = set()

    def specimen(sample, complete=True):
        assert sample['flags'] == 0
        for pc, opcode in sample['ops']:
            offset = (pc & 0x1fffffff) - 0x0c010000
            assert 0 <= offset <= len(rom)-2
            assert struct.unpack_from('<H', rom, offset)[0] == opcode
            if complete:
                seen.add(pc | 0x80000000)
        if complete:
            before = struct.unpack('<63I', sample['before'])
            after = struct.unpack('<63I', sample['after'])
            assert before[8:16] == after[8:16] and before[18] == after[18]
            assert sample['exitpc'] & 0x1fffffff == 0x0c0432e4
            assert sample['ops'][-2:] == [(0x0c04be26, 0x000b), (0x0c04be28, 0x6ef6)]

    def replay(corpus, report, count):
        cm = load(corpus / 'capsule_manifest.json')
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        assert sum(len(v) for v in cm['entries'].values()) == count
        proof, = load(report).values()
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        return dict(report=ref(report), files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
                    capsules=[ref(p) for p in cm['inputs']])

    def original_files(path):
        manifest = load(path)
        for name, digest in manifest['provenance'].items():
            assert sha(name) == digest
        assert manifest['provenance'][str(emulator)] == sha(emulator)
        pinned = [ref(path)]
        for run in manifest['runs']:
            for name, digest in [(run['log'], run['log_sha256']),
                                 (Path(run['log']).with_suffix('.patch'), run['patch_sha256']),
                                 (run['capsule'], run['capsule_sha256']),
                                 (run['audio']['path'], run['audio']['sha256'])]:
                assert sha(name) == digest
                pinned.append(ref(name))
        return pinned

    campaigns = []
    for name, count in [('coverage_65_task_driver_dev_v1', 128),
                        ('coverage_65_task_driver_accept_v6', 128)]:
        corpus = ROOT / 'extract/analysis' / name
        cm = load(corpus / 'capsule_manifest.json')
        for run in cm['runs']:
            assert run['started'] == run['completed'] and not run['incomplete'] and not run['unaccounted']
        for path in cm['inputs']:
            for sample in records(path):
                specimen(sample)
        report = ROOT / f'extract/analysis/task_driver_v9_{name}_report.json'
        campaigns.append(dict(name=name, cases=count, **replay(corpus, report, count)))

    completions = []
    for name, count, coherent in [('task_driver_object_resume_v2', 2, False),
                                   ('task_driver_object_wrap_v1', 2, True),
                                   ('task_driver_job_resume_accept_v2', 4, True),
                                   ('task_driver_job_wrap_accept_v2', 2, True)]:
        original = CACHE / name / 'manifest.json'
        manifest = load(original)
        assert manifest['passed'] and len(manifest['runs']) == count
        assert manifest['execution'] == 'original_sh4' and manifest['mode'] == 'nonrollback_one_shot'
        for path, digest in manifest['provenance'].items():
            assert sha(path) == digest
        assert manifest['provenance'][str(emulator)] == sha(emulator)
        for run in manifest['runs']:
            assert run['passed'] and run['flags'] == 0 and run['returncode'] == 0
            assert run['device_accesses'] == 0, 'unexpected SH-4 device contract'
            assert sha(run['log']) == run['log_sha256']
            assert sha(Path(run['log']).with_suffix('.patch')) == run['patch_sha256']
            assert sha(run['capsule']) == run['capsule_sha256']
            assert sha(run['audio']['path']) == run['audio']['sha256']
            summary = run['summary']
            assert summary['explicit_return_only'] and summary['one_shot_done']
            assert summary['started'] == summary['completed'] == 1
            assert not summary['incomplete'] and not summary['unaccounted'] and not summary['restores']
            sample, = records(run['capsule'])
            specimen(sample)
            pcs = {pc & 0x1fffffff for pc, _ in sample['ops']}
            assert {0x0c04f5d0, 0x0c04f5f4, 0x0c04bc52, 0x0c04bbc6, 0x0c04be26} <= pcs
            before = struct.unpack('<63I', sample['before'])
            context = before[4]
            assert word(sample, context+0x134) == (word(sample, context+0x134, False)+1) & 0xffffffff
            assert word(sample, context+0x14c) == 0
            if coherent:
                assert word(sample, context+0x13c, False) == 1 and word(sample, context+0x13c) == 0
        corpus = ROOT / f'extract/analysis/{name}_cases'
        report = ROOT / f'extract/analysis/{name}_native_v9_report.json'
        completions.append(dict(original=ref(original), cases=count,
                                coherent_active_count=coherent, **replay(corpus, report, count)))

    first_yields = []
    for name in ['task_driver_object_yield_v3', 'task_driver_object_yield_v6']:
        corpus = ROOT / f'extract/analysis/{name}_cases'
        for path in load(corpus / 'capsule_manifest.json')['inputs']:
            for sample in records(path):
                specimen(sample)
        first_yields.append(replay(corpus, ROOT / f'extract/analysis/{name}_native_v9_report.json', 2))

    wrapper = ROOT / 'extract/analysis/task_driver_original_wrapper_v6_cases'
    wrapper_proof = replay(wrapper, ROOT / 'extract/analysis/task_driver_original_wrapper_v6_native_v9_report.json', 8)
    wrapper_proof['original_files'] = original_files(CACHE / 'task_driver_original_wrapper_v6/manifest.json')
    for path in load(wrapper / 'capsule_manifest.json')['inputs']:
        for sample in records(path):
            specimen(sample)

    controls = []
    legacy = CACHE / 'task_return_boundary_control_v1/manifest.json'
    budget = CACHE / 'task_return_boundary_budget_v1/manifest.json'
    old = load(CACHE / 'task_driver_object_resume_v1/manifest.json')
    for run in load(legacy)['runs']:
        assert run['passed'] and run['flags'] == 0 and not run['summary']['explicit_return_only']
        sample, = records(run['capsule'])
        specimen(sample, complete=False)
        assert len(sample['ops']) == 159 and sample['exitpc'] & 0x1fffffff == 0x0c0537de
        if Path(run['state']).name == 'vf3_28.state':
            previous, = [r for r in old['runs'] if Path(r['state']).name == 'vf3_28.state' and r['case'].startswith('21_')]
            baseline, = records(previous['capsule'])
            assert all(sample[k] == baseline[k] for k in ['entry', 'exitpc', 'flags', 'before', 'after', 'pages', 'ops'])
            controls.append(dict(default_compatibility_capsule=ref(previous['capsule']), old_run=ref(CACHE / 'task_driver_object_resume_v1/manifest.json')))
    run, = load(budget)['runs']
    assert run['passed'] and run['flags'] == 4 and run['summary']['explicit_return_only']
    controls.extend(original_files(legacy) + original_files(budget))

    capability = CACHE / 'task_return_boundary_old_capability_v1/manifest.json'
    missing = load(capability)
    run, = missing['runs']
    assert not missing['passed'] and not run['passed'] and run['flags'] == 0
    assert not run['summary'].get('explicit_return_only') and run['summary']['one_shot_done']
    sample, = records(run['capsule'])
    specimen(sample, complete=False)
    assert sample['exitpc'] & 0x1fffffff == 0x0c0432e4
    old_emulator = ROOT / 'tools/emu/flycast-build/flycast_audio_fight_live_v1.exe'
    assert sha(old_emulator) == '3e9a4bf81265ea3eb26ade637cd4343ad137a6dc28e7ed0b1e80502a26b23b6c'
    for path, digest in missing['provenance'].items():
        assert sha(path) == digest
    for path, digest in [(run['capsule'], run['capsule_sha256']),
                         (run['log'], run['log_sha256']),
                         (Path(run['log']).with_suffix('.patch'), run['patch_sha256'])]:
        assert sha(path) == digest
    controls.append(dict(missing_capability=ref(capability), capsule=ref(run['capsule']),
                         old_executable=ref(old_emulator),
                         note='Run provenance includes current capture tooling. It does not describe the older executable compiled observer source.'))

    rejected = CACHE / 'task_driver_job_accept_v1/manifest.json'
    raw = load(rejected)
    assert not raw['passed'] and len(raw['runs']) == 8
    assert sum(r['flags'] == 1 and not r['passed'] for r in raw['runs']) == 2
    rejected_files = original_files(rejected)

    pilot_original = CACHE / 'task_controller_merge_pilot_v1/manifest.json'
    pilot_raw = load(pilot_original)
    assert pilot_raw['passed'] and len(pilot_raw['runs']) == 8
    pilot_corpus = ROOT / 'extract/analysis/task_controller_merge_pilot_v1_cases'
    pilot_report = ROOT / 'extract/analysis/task_controller_merge_pilot_v1_native_v9_report.json'
    pilot_proof = replay(pilot_corpus, pilot_report, 8)
    pilot_seen = set()
    for run in pilot_raw['runs']:
        sample, = records(run['capsule'])
        specimen(sample, complete=False)
        assert sample['exitpc'] & 0x1fffffff == 0x0c0432e4
        assert sample['ops'][-2:] == [(0x0c09afbc, 0x000b), (0x0c09afbe, 0x6ef6)]
        pilot_seen.update(pc | 0x80000000 for pc, _ in sample['ops'])
    pilot_body = {pc for lo, hi in body_spans()[0x8c09af72] for pc in range(lo, hi, 2)}
    assert pilot_body <= pilot_seen and len(pilot_body)*2 == 78
    pilot_proof.update(original_files=original_files(pilot_original), observed_frozen_bytes=78,
                       coverage_credit=False, limitation='Eight existing-adapter pilots only; readable C, 64-case development/acceptance and whole-caller qualification pending.')
    controller_dev = CACHE / 'task_controller_merge_dev_v1/manifest.json'
    assert load(controller_dev)['passed'] and len(load(controller_dev)['runs']) == 64
    controller_corpus = ROOT / 'extract/analysis/task_controller_merge_dev_v1_cases'
    controller_report = ROOT / 'extract/analysis/task_controller_merge_dev_v1_native_v9_report.json'
    controller_proof = replay(controller_corpus, controller_report, 64)
    controller_seen = set()
    for run in load(controller_dev)['runs']:
        assert run['device_accesses'] == 0, 'unexpected controller device access'
        sample, = records(run['capsule'])
        specimen(sample, complete=False)
        assert sample['exitpc'] & 0x1fffffff == 0x0c0432e4
        assert sample['ops'][-2:] == [(0x0c09afbc, 0x000b), (0x0c09afbe, 0x6ef6)]
        controller_seen.update(pc | 0x80000000 for pc, _ in sample['ops'])
    assert pilot_body <= controller_seen
    controller_proof.update(original_files=original_files(controller_dev), cases=64,
                            coverage_credit=False, limitation='Original development preparation matched against existing adapters. Readable C and independent acceptance/caller attribution pending.')
    candidate = CACHE / 'controller_merge_candidate_v1/manifest.json'
    candidate_manifest = load(candidate)
    assert candidate_manifest['diagnostic_only'] and not candidate_manifest['coverage_credit']
    archived_core = CACHE / 'task_driver_v9_original_core.a'
    for item in candidate_manifest['files']:
        assert sha(item['path']) == item['sha256']
        if Path(item['path']).resolve() == (ROOT / 'build/libvf3core.a').resolve():
            assert sha(archived_core) == item['sha256']
    candidate_report = ROOT / 'extract/analysis/task_controller_merge_dev_v1_isolated_candidate_report.json'
    candidate_proof, = load(candidate_report).values()
    assert candidate_proof['pass'] and candidate_proof['stdout'].strip() == 'matrix_family: 64/64 cases match (0 skipped) - PASS'
    assert candidate_proof['executable_sha256'] == sha(CACHE / 'controller_merge_candidate_v1/vf3matrixfamily_controller_candidate_v1.exe')
    controller_proof['isolated_readable_candidate'] = dict(sources=ref(candidate), report=ref(candidate_report),
        archived_original_core=ref(archived_core),
        limitation='Diagnostic cache build, outside repository C. Normal build, source freeze, caller attribution and fresh acceptance still required.')
    caller_manifest = CACHE / 'task_controller_original_callers_pilot_v1/manifest.json'
    attribution = dict(entry='0x8c09af6c', kind='vf3-controller-merge-bsr-v1',
                       call_sites=['0x8c09b92a', '0x8c09b988'],
                       callee_save_prefix=['r14', 'r13', 'r12'],
                       original_caller_manifests=[ref(caller_manifest)])
    validate_controller_merge(0x8c09af72, attribution, body_spans()[0x8c09af72], controller_corpus, rom)
    controller_proof['caller_contract'] = dict(attribution=attribution,
        original_files=original_files(caller_manifest),
        validator=ref(ROOT / 'tools/callable_controller.py'),
        routing=ref(ROOT / 'tools/callable_body.py'),
        mutation_tests=ref(ROOT / 'tools/oracle/test_callable_controller.py'),
        scope='Original BSR, callee prefix and return observations; not full parent execution.')
    frame_corpus = ROOT / 'extract/analysis/coverage_65_controller_merge_dev_v1'
    frame_manifest = load(frame_corpus / 'capsule_manifest.json')
    assert len(frame_manifest['entries']['0x8c09af6c']) == 128
    assert not frame_manifest['invalid'] and not frame_manifest['nondeterministic_entries']
    frame_batch = load(frame_corpus / 'batch_manifest.json')
    assert all(r['returncode'] == 0 and r['frame_complete'] for r in frame_batch['runs'])
    validate_controller_merge(0x8c09af72, attribution, body_spans()[0x8c09af72], frame_corpus, rom)
    frame_report = ROOT / 'extract/analysis/coverage_65_controller_merge_dev_v1_isolated_candidate_report.json'
    frame_proof, = load(frame_report).values()
    assert frame_proof['pass'] and frame_proof['stdout'].strip() == 'matrix_family: 128/128 cases match (0 skipped) - PASS'
    assert frame_proof['executable_sha256'] == candidate_proof['executable_sha256']
    controller_proof['completed_frame_development'] = dict(batch=ref(frame_corpus / 'batch_manifest.json'),
        capsules=[ref(p) for p in frame_manifest['inputs']], report=ref(frame_report),
        files=[ref(p) for p in sorted(frame_corpus.iterdir()) if p.is_file()],
        watch=ref(ROOT / 'tools/oracle/coverage_65_controller_merge_watch_v1.txt'),
        inputs=ref(ROOT / 'tools/oracle/percentage_inputs/coverage_65_controller_merge_dev_v1_memory.json'),
        coverage_credit=False)

    inventory = CACHE / 'task_driver_v9_bindings.json'
    assert sha(inventory) == sha(ROOT / 'tools/golden_bindings.json')
    bindings = load(inventory)
    log = ROOT / 'extract/analysis/task_driver_v9_portcheck.log'
    text = log.read_text(encoding='utf-8-sig', errors='replace')
    status = summarize(text, bindings)
    section = text.split('replay tests:\n', 1)[1].split('golden-bound ports:\n', 1)[0]
    checks = re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s', section, re.M)
    assert len(checks) == len(TESTS) == 39 and all(v == 'PASS' for _, v in checks)
    native_tests = []
    for name in TESTS:
        path = CACHE / f'native_task_driver_v9/{name}.exe'
        assert sha(path) == sha(ROOT / f'build/{name}.exe')
        native_tests.append(ref(path))
    bound = {}
    for executable in sorted({row['test'].split()[0] for row in bindings.values()}):
        path = native if executable == 'build/vf3matrixfamily.exe' else CACHE / 'native_task_driver_v9' / Path(executable).name
        if path != native:
            assert sha(path) == sha(ROOT / executable)
        bound[executable] = ref(path)
    tests = ROOT / 'extract/analysis/task_completion_v1_tool_tests.log'
    assert 'Ran 110 tests' in tests.read_text(encoding='utf-8-sig') and tests.read_text(encoding='utf-8-sig').rstrip().endswith('OK')
    body = {pc for lo, hi in body_spans()[0x8c04bd7a] for pc in range(lo, hi, 2)}
    missing = sorted(body-seen)
    assert missing == [0x8c04bdee, 0x8c04bdf0]
    chain = ROOT / 'extract/analysis/task_driver_v5_chain_audit.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes'] == 259110
    assert status['passed'] and status['reported_bindings'] == 1368, 'full regression pending or failed'
    return dict(passed=True, coverage_credit=False, new_bytes=0, readable_bytes=259110,
                total_body_bytes=434656, native=ref(native), frozen_sources=ref(archive),
                observer=ref(observer), emulator=ref(emulator), image=ref(image),
                frozen_body_ranges=ref(ROOT / 'extract/analysis/function_body_ranges.csv'), audit_tool=ref(Path(__file__)),
                campaigns=campaigns, completions=completions, first_yields=first_yields, wrapper=wrapper_proof,
                controls=controls, rejected_wrap_holdouts=rejected_files,
                next_controller_pilot=pilot_proof,
                next_controller_development=controller_proof,
                excluded_early_conversion=dict(reason='Converted before the mixed campaign finished; not used as acceptance proof.',
                    report=ref(ROOT / 'extract/analysis/task_driver_job_accept_v1_native_v9_report.json'),
                    corpus=ref(ROOT / 'extract/analysis/task_driver_job_accept_v1_cases/capsule_manifest.json')),
                historical_observer=ref(CACHE / 'task_return_boundary_v1_before_sources/manifest.json'),
                observed_owner_bytes=2*len(body & seen), missing_owner_pcs=[hex(p) for p in missing],
                limitation='Constructed BSR-seeded job contracts do not establish natural startup or whole-caller qualification. Default depth stops are partial driver controls. No new coverage credit.',
                bindings=ref(inventory), bound_executables=bound, full_regression=ref(log),
                native_tests=native_tests, regression_status=status, tool_tests=ref(tests), percentage_chain=ref(chain))


if __name__ == '__main__':
    output = ROOT / 'tools/oracle/task_completion_v1_manifest.json'
    assert not output.exists(), 'sealed proof already exists'
    output.write_text(json.dumps(audit(), indent=2)+'\n')
    print('Complete task retirement contracts PASS; +0 coverage bytes')
