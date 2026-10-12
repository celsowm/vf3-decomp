"""Compare the extended recorder with eight unchanged original caller windows."""
import json
from pathlib import Path
from audio_determinism import compare as compare_audio
from compare_original_samples import compare
from ram_clipping_batch_audit import digest, reference

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    build_path = CACHE / 'capsule_extended_observer_v1_build/manifest.json'
    build = json.loads(build_path.read_text())
    assert build['unchanged_fpu_and_simulation'] and build['maximum_recorded_instructions'] == 500000
    for row in build['references']:
        assert digest(row['path']) == row['sha256']
    assert digest(build['executable']['path']) == build['executable']['sha256']
    paths = [CACHE / 'replay_transition_original_dispatch_v2/manifest.json',
             CACHE / 'extended_observer_original_controls_v1/manifest.json']
    old, new = [json.loads(path.read_text()) for path in paths]
    assert old['passed'] and new['passed'] and old['execution'] == new['execution'] == 'original_sh4'
    assert old['mode'] == new['mode'] == 'nonrollback_one_shot'
    assert len(old['runs']) == len(new['runs']) == 8
    assert new['provenance'][build['executable']['path']] == build['executable']['sha256']
    refs = [reference(path) for path in [build_path, *paths, Path(__file__), ROOT / 'tools/oracle/capsules.py']]
    proofs = []
    for left, right in zip(old['runs'], new['runs']):
        assert left['case'] == right['case'] and left['state'] == right['state']
        for row in (left, right):
            assert row['returncode'] == 0 and row['passed'] and row['flags'] == 0 and row['device_accesses'] == 0
            summary = row['summary']
            assert summary['started'] == summary['completed'] == 1 and not summary['incomplete'] and not summary['unaccounted']
            assert summary['one_shot_done'] and summary['explicit_return_only'] and not summary['restores']
            refs += [reference(path) for path in (Path(row['capsule']), Path(str(row['capsule'])+'.summary.json'),
                Path(row['audio']['path']), Path(row['log']), Path(row['log']).with_suffix('.patch'))]
        result = compare(left['capsule'], 1, right['capsule'], 1)
        assert result['captured_inputs_equal'] and result['captured_outputs_equal']
        assert result['canonical_instruction_traces_equal']
        audio = compare_audio(left['audio']['path'], right['audio']['path'])
        assert audio['equal'], 'full original audio checkpoint differs'
        proofs.append(dict(case=left['case'], state=left['state'], architecture_ram_and_trace_equal=True,
            audio_checkpoint_equal=True, instructions=result['left_instructions']))
    for manifest in (old, new):
        for path, expected in manifest['provenance'].items():
            assert digest(path) == expected
            refs.append(reference(path))
    refs.append(reference(ROOT / 'extract/analysis/extended_capsule_tool_tests_v1.log'))
    output = ROOT / 'tools/oracle/extended_observer_controls_v1.json'
    assert not output.exists(), 'refuse to replace observer controls'
    output.write_text(json.dumps(dict(coverage_credit=False, diagnostic_controls_passed=True,
        maximum_recorded_instructions=500000, unchanged_original_simulation=True,
        observer=build['executable'], controls=proofs,
        limitation='These controls validate the recording-only extension; long candidate campaigns still need complete original paths, strict C replay, callers and independent acceptance.',
        references=list({row['path']: row for row in refs}.values())), indent=2)+'\n')
    print('Eight old/new original windows match all architecture, RAM, instructions and full audio checkpoints')


if __name__ == '__main__':
    main()
