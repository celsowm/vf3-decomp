"""Seal the v2 extended observer against the original control windows.

Three recorders are compared on the same eight original caller windows:

  * the pristine original oracle (cached in the evidence cache),
  * the current main oracle (the device-read policy and the 1024-page RAM
    budget applied), and
  * the v2 extended observer (the same patched source plus a 500,000
    instruction record bound and the VF3CAP7 format tag).

The first comparison shows the device-read/page patch did not move these
windows; the second shows the recorder extension did not move them either.
Both must agree on the captured inputs, the captured outputs, the canonical
instruction trace and the full audio checkpoint.
"""
import json
from pathlib import Path
from audio_determinism import compare as compare_audio
from compare_original_samples import compare
from ram_clipping_batch_audit import digest, reference

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')

ORIGINAL = CACHE / 'replay_transition_original_dispatch_v2/manifest.json'
MAIN = CACHE / 'main_observer_controls_v2/manifest.json'
EXTENDED = CACHE / 'extended_observer_v2_controls/manifest.json'
BUILD = CACHE / 'capsule_extended_observer_v2_build/manifest.json'
TOOL_TESTS = ROOT / 'extract/analysis/extended_capsule_tool_tests_v2.log'


def load(path):
    return json.loads(Path(path).read_text())


def main():
    build = load(BUILD)
    assert build['unchanged_fpu_and_simulation']
    assert build['maximum_recorded_instructions'] == 500000
    for row in build['references']:
        assert digest(row['path']) == row['sha256'], f"build input changed: {row['path']}"
    assert digest(build['executable']['path']) == build['executable']['sha256']

    original, main_obs, extended = load(ORIGINAL), load(MAIN), load(EXTENDED)
    for manifest in (original, main_obs, extended):
        assert manifest['passed'] and manifest['execution'] == 'original_sh4'
        assert manifest['mode'] == 'nonrollback_one_shot'
    assert len(original['runs']) == len(main_obs['runs']) == len(extended['runs']) == 8
    # each capture must name the recorder that produced it
    assert main_obs['provenance'][build['main_observer']['path']] == build['main_observer']['sha256']
    assert extended['provenance'][build['executable']['path']] == build['executable']['sha256']

    refs = [reference(path) for path in (BUILD, ORIGINAL, MAIN, EXTENDED, Path(__file__),
                                         ROOT / 'tools/oracle/capsules.py', TOOL_TESTS)]
    proofs = []
    for left, middle, right in zip(original['runs'], main_obs['runs'], extended['runs']):
        assert left['case'] == middle['case'] == right['case']
        assert left['state'] == middle['state'] == right['state']
        for row in (left, middle, right):
            assert row['returncode'] == 0 and row['passed']
            assert row.get('flags', 0) == 0 and row.get('device_accesses', 0) == 0
            summary = row['summary']
            assert summary['started'] == summary['completed'] == 1
            assert not summary['incomplete'] and not summary['unaccounted']
            assert summary['one_shot_done'] and summary['explicit_return_only']
            refs += [reference(path) for path in (Path(row['capsule']),
                                                 Path(str(row['capsule']) + '.summary.json'),
                                                 Path(row['audio']['path']), Path(row['log']),
                                                 Path(row['log']).with_suffix('.patch'))]
        # the patched main oracle must not have moved the window
        against_main = compare(left['capsule'], 1, middle['capsule'], 1)
        assert against_main['captured_inputs_equal'] and against_main['captured_outputs_equal'], \
            'the device-read / page-budget patch moved the control window'
        assert against_main['canonical_instruction_traces_equal']
        # the extended recorder must not have moved the window either
        result = compare(left['capsule'], 1, right['capsule'], 1)
        assert result['captured_inputs_equal'] and result['captured_outputs_equal'], \
            'the extended recorder moved the control window'
        assert result['canonical_instruction_traces_equal']
        audio = compare_audio(left['audio']['path'], right['audio']['path'])
        assert audio['equal'], 'full original audio checkpoint differs'
        proofs.append(dict(case=left['case'], state=left['state'],
                           architecture_ram_and_trace_equal=True,
                           audio_checkpoint_equal=True,
                           patched_main_oracle_equal=True,
                           instructions=result['left_instructions']))
    for manifest in (original, main_obs, extended):
        for path, expected in manifest['provenance'].items():
            assert digest(path) == expected
            refs.append(reference(path))

    output = ROOT / 'tools/oracle/extended_observer_controls_v2.json'
    assert not output.exists(), 'refuse to replace the v2 observer controls'
    output.write_text(json.dumps(dict(
        coverage_credit=False,
        diagnostic_controls_passed=True,
        maximum_recorded_instructions=500000,
        unchanged_original_simulation=True,
        observer=build['executable'],
        main_observer=build['main_observer'],
        controls=proofs,
        limitation=('These controls validate the recording-only extension against the '
                    'current patched oracle; long candidate campaigns still need complete '
                    'original paths, strict C replay, callers and independent acceptance.'),
        references=list({row['path']: row for row in refs}.values())), indent=2) + '\n')
    print('Eight windows match the pristine original, the patched main oracle and the v2 '
          'extended observer on architecture, RAM, instructions and full audio checkpoints')


if __name__ == '__main__':
    main()
