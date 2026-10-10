"""Seal task-driver replay evidence without awarding incomplete body coverage."""
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
from portcheck import TESTS


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def ref(path):
    return dict(path=str(path), sha256=sha(path))


def audit():
    archive = CACHE / 'task_driver_dev_v7_complete_v2_sources/manifest.json'
    frozen = json.loads(archive.read_text())
    for row in frozen['files']:
        assert sha(archive.parent / row['path']) == row['sha256']
        assert sha(ROOT / row['path']) == row['sha256'], 'compiled sources changed'
    native = Path(frozen['native'])
    assert sha(native) == frozen['native_sha256']
    image = ROOT / 'extract/gamedata/1ST_READ.BIN'
    rom = image.read_bytes()
    seen = set()
    campaigns = []
    for name, count in [('coverage_65_task_driver_v1', 2),
                        ('coverage_65_task_driver_pilot_v1', 16),
                        ('coverage_65_task_driver_dev_v1', 128),
                        ('coverage_65_task_driver_accept_v5', 128),
                        ('coverage_65_active_lookup_v1', 1)]:
        corpus = ROOT / 'extract/analysis' / name
        manifest = json.loads((corpus / 'capsule_manifest.json').read_text())
        assert not manifest['invalid'] and not manifest['nondeterministic_entries']
        control = name == 'coverage_65_active_lookup_v1'
        for run in manifest['runs']:
            assert not run['unaccounted']
            if not control:
                assert run['started'] == run['completed'] and not run['incomplete']
        if control:
            # This historical passive lead has one valid sample and another
            # invocation still open when recording ends. Reuse only the valid
            # sample as a regression control, not as a complete campaign.
            assert sum(r['started'] for r in manifest['runs']) == 2
            assert sum(r['completed'] for r in manifest['runs']) == 1
            assert sum(len(r['incomplete']) for r in manifest['runs']) == 1
        samples = [s for p in manifest['inputs'] for s in records(p)]
        assert len(manifest['entries']) == 1
        assert len(next(iter(manifest['entries'].values()))) == count
        assert len(samples) >= count and all(s['flags'] == 0 for s in samples)
        for sample in samples:
            if name in ('coverage_65_task_driver_pilot_v1', 'coverage_65_task_driver_dev_v1',
                        'coverage_65_task_driver_accept_v5'):
                before = struct.unpack('<63I', sample['before'])
                after = struct.unpack('<63I', sample['after'])
                assert before[8:16] == after[8:16] and before[18] == after[18]
            for pc, opcode in sample['ops']:
                pc &= 0x1fffffff
                offset = pc - 0x0c010000
                assert 0 <= offset <= len(rom)-2
                assert struct.unpack_from('<H', rom, offset)[0] == opcode
                if name != 'coverage_65_active_lookup_v1':
                    seen.add(pc | 0x80000000)
        report = ROOT / f'extract/analysis/task_driver_v7_{name}_report.json'
        proofs = json.loads(report.read_text())
        assert len(proofs) == 1
        proof = next(iter(proofs.values()))
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        campaigns.append(dict(cases=count, regression_control_only=control,
                              raw_specimens=len(samples), capsules=[ref(p) for p in manifest['inputs']],
                              files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
                              native_report=ref(report)))
    owner = 0x8c04bd7a
    body = {pc for lo, hi in body_spans()[owner] for pc in range(lo, hi, 2)}
    missing = sorted(body - seen)
    assert missing == [0x8c04bdee, 0x8c04bdf0]
    wrappers = []
    for version in (1, 5):
        name = f'task_driver_original_wrapper_v{version}'
        wrapper = CACHE / name / 'manifest.json'
        original = json.loads(wrapper.read_text())
        assert original['passed'] and len(original['runs']) == 8
        assert original['execution'] == 'original_sh4'
        assert original['mode'] == 'nonrollback_one_shot'
        for path, digest in original['provenance'].items():
            assert sha(CACHE / 'task_driver_audio_one_shot_before_alias_fix.py' if version == 1 and Path(path).name == 'audio_one_shot.py' else path) == digest
        for row in original['runs']:
            assert row['passed'] and row['flags'] == 0
            assert sha(row['capsule']) == row['capsule_sha256']
            assert sha(row['log']) == row['log_sha256']
            assert sha(Path(row['log']).with_suffix('.patch')) == row['patch_sha256']
            summary = row['summary']
            assert summary['started'] == summary['completed'] == 1
            assert not summary['incomplete'] and not summary['unaccounted']
            assert not summary['restores'] and summary['one_shot_done']
        wrapper_corpus = ROOT / f'extract/analysis/{name}_cases'
        cm = json.loads((wrapper_corpus / 'capsule_manifest.json').read_text())
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        banks = set()
        for path in cm['inputs']:
            sample, = records(path)
            assert sample['flags'] == 0
            before = struct.unpack('<63I', sample['before'])
            after = struct.unpack('<63I', sample['after'])
            banks.add(before[18] & 0x200000)
            assert before[8:16] == after[8:16] and before[18] == after[18]
            assert (sample['exitpc'] & 0x1fffffff) == 0x0c0432e4
            assert [(pc & 0x1fffffff, op) for pc, op in sample['ops'][:4]] == [
                (0x0c053d7c, 0xd309), (0x0c053d7e, 0xd207),
                (0x0c053d80, 0x432b), (0x0c053d82, 0x6422)]
            for pc, opcode in sample['ops']:
                offset = (pc & 0x1fffffff)-0x0c010000
                assert 0 <= offset <= len(rom)-2
                assert struct.unpack_from('<H', rom, offset)[0] == opcode
        assert banks == {0, 0x200000}
        wrapper_report = ROOT / (f'extract/analysis/task_driver_v7_{name}_cases_report.json' if version == 1 else f'extract/analysis/{name}_native_v7_report.json')
        proof = json.loads(wrapper_report.read_text())['0x8c053d7c']
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == 'matrix_family: 8/8 cases match (0 skipped) - PASS'
        wrappers.append(dict(original=ref(wrapper), fpu_banks=sorted(banks), capsules=[ref(p) for p in cm['inputs']],
                             native=ref(wrapper_report),
                             files=[ref(p) for p in sorted(wrapper_corpus.iterdir()) if p.is_file()]))
    objects = []
    for version in (3, 6):
        name = f'task_driver_object_yield_v{version}'
        original_path = CACHE / name / 'manifest.json'
        original = json.loads(original_path.read_text())
        assert original['passed'] and len(original['runs']) == 2
        assert original['execution'] == 'original_sh4'
        assert original['mode'] == 'nonrollback_one_shot'
        for path, digest in original['provenance'].items():
            assert sha(path) == digest
        for row in original['runs']:
            assert row['passed'] and row['flags'] == 0
            assert sha(row['capsule']) == row['capsule_sha256']
            assert sha(row['log']) == row['log_sha256']
            patch = Path(row['log']).with_suffix('.patch')
            assert sha(patch) == row['patch_sha256']
            assert 'target 8c0432e2 0c04bd62' in patch.read_text().splitlines()
            summary = row['summary']
            assert summary['started'] == summary['completed'] == 1
            assert not summary['incomplete'] and not summary['unaccounted']
            assert not summary['restores'] and summary['one_shot_done']
            sample, = records(row['capsule'])
            before = struct.unpack('<63I', sample['before'])
            after = struct.unpack('<63I', sample['after'])
            assert before[4] == 0x0c420000  # Separate from descriptor 0x0c404000.
            assert before[8:16] == after[8:16] and before[18] == after[18]
            assert (sample['exitpc'] & 0x1fffffff) == 0x0c0432e4
            pcs = [pc & 0x1fffffff for pc, _ in sample['ops']]
            assert pcs.count(0x0c04bd94) == 2
            assert pcs.count(0x0c0544c8) == pcs.count(0x0c054454) == 2
            assert 0x0c04ff2e in pcs and 0x0c04f588 in pcs and 0x0c04be26 in pcs
            for pc, opcode in sample['ops']:
                offset = (pc & 0x1fffffff)-0x0c010000
                assert 0 <= offset <= len(rom)-2
                assert struct.unpack_from('<H', rom, offset)[0] == opcode
        corpus = ROOT / f'extract/analysis/{name}_cases'
        cm = json.loads((corpus / 'capsule_manifest.json').read_text())
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        report = ROOT / f'extract/analysis/{name}_native_v7_report.json'
        proof = json.loads(report.read_text())['0x8c04bd62']
        assert proof['pass'] and proof['executable_sha256'] == sha(native)
        assert proof['stdout'].strip() == 'matrix_family: 2/2 cases match (0 skipped) - PASS'
        objects.append(dict(original=ref(original_path), native=ref(report),
                            scope='Constructed job at actual object BSR; first cooperative yield only.',
                            capsules=[ref(p) for p in cm['inputs']],
                            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]))
    inventory = CACHE / 'task_driver_v7_bindings.json'
    assert sha(inventory) == sha(ROOT / 'tools/golden_bindings.json')
    bindings = json.loads(inventory.read_text())
    bound_native = {}
    for executable in sorted({row['test'].split()[0] for row in bindings.values()}):
        if executable == 'build/vf3matrixfamily.exe':
            bound_native[executable] = ref(native)
        else:
            archived = CACHE / 'native_task_driver_v7' / Path(executable).name
            assert sha(archived) == sha(ROOT / executable)
            bound_native[executable] = ref(archived)
    log = ROOT / 'extract/analysis/task_driver_v7_portcheck.log'
    contents = log.read_text(encoding='utf-8-sig', errors='replace')
    status = summarize(contents, bindings)
    assert status['passed'] and status['reported_bindings'] == 1368
    native_section = contents.split('replay tests:\n', 1)[1].split('golden-bound ports:\n', 1)[0]
    checks = re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s', native_section, re.M)
    assert len(checks) == len(TESTS) == 39 and all(v == 'PASS' for _, v in checks)
    for name in TESTS:
        assert sha(CACHE / f'native_task_driver_v7/{name}.exe') == sha(ROOT / f'build/{name}.exe')
    tests = ROOT / 'extract/analysis/task_driver_v7_tool_tests.log'
    text = tests.read_text(encoding='utf-8-sig')
    assert 'Ran 104 tests' in text and text.rstrip().endswith('OK')
    chain = ROOT / 'extract/analysis/task_driver_v5_chain_audit.json'
    coverage = json.loads(chain.read_text())
    assert coverage['passed'] and coverage['complete'] and coverage['final_bytes'] == 259110
    return dict(passed=True, advisory=True, coverage_credit=False, new_bytes=0,
                readable_bytes=259110, total_body_bytes=434656,
                frozen_sources=ref(archive), native=ref(native), image=ref(image),
                audit_tool=ref(Path(__file__)),
                historical_one_shot_tool=ref(CACHE / 'task_driver_audio_one_shot_before_alias_fix.py'),
                excluded_diagnostics=ref(ROOT / 'tools/oracle/task_driver_rejected_object_pilots_v1_manifest.json'),
                campaigns=campaigns, wrappers=wrappers, object_yields=objects,
                observed_owner_bytes=2*len(body & seen), frozen_owner_bytes=2*len(body),
                missing_owner_pcs=[hex(pc) for pc in missing],
                limitation='Driver resume-call return branch remains unobserved; no whole-body promotion. Object probes establish a constructed first-yield contract, not natural startup, subsequent completion, or independent whole-caller qualification. Resource workers use the uncached alias.',
                full_regression=ref(log), regression_status=status,
                bindings=ref(inventory), native_tests=[ref(CACHE / f'native_task_driver_v7/{name}.exe') for name in TESTS],
                bound_executables=bound_native,
                tool_tests=ref(tests), percentage_chain=ref(chain))


if __name__ == '__main__':
    output = ROOT / 'tools/oracle/task_driver_v1_manifest.json'
    assert not output.exists(), 'sealed proof already exists'
    result = audit()
    output.write_text(json.dumps(result, indent=2)+'\n')
    print('Task driver: replay and wrapper evidence PASS; +0 coverage bytes')
