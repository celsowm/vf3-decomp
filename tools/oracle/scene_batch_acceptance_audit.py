"""Qualify both scene owners using fresh, complete original acceptance campaigns."""
from datetime import datetime
import hashlib
import json
from pathlib import Path
import struct

from capsules import convert, records
from qualify_development_batch import campaign
from ram_clipping_batch_audit import digest, reference
from task_completion_audit import freeze
from verify_matrix import verify

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def fingerprints(directory):
    batch = json.loads((Path(directory) / 'batch_manifest.json').read_text())
    result = set()
    for run in batch['runs']:
        for sample in records(Path(run['capsule'])):
            if sample['flags']:
                continue
            result.add(hashlib.sha256(sample['before'] + b''.join(
                struct.pack('<I', base) + before for base, before, _ in sample['pages'])).hexdigest())
    return result


def require_independent(development, acceptance, development_inputs, acceptance_inputs):
    dev_states = {row['state_sha256'] for row in development['scenarios']}
    held_states = {row['state_sha256'] for row in acceptance['scenarios']}
    assert len(dev_states) == len(held_states) == 2
    assert dev_states.isdisjoint(held_states), 'development state reused in acceptance'
    assert development_inputs and acceptance_inputs
    assert development_inputs.isdisjoint(acceptance_inputs), 'development input reused in acceptance'
    return held_states


def main():
    config_path = ROOT / 'tools/oracle/scene_batch_development_qualification_v1.json'
    config = json.loads(config_path.read_text())
    qualified = Path(config['out'])
    development = json.loads(qualified.read_text())
    assert development['qualified_development_only'] and development['full_regression']['passed']
    for row in development['references']:
        assert digest(row['path']) == row['sha256'], 'development dependency changed'
    archive = Path(config['source_archive'])
    native = freeze(archive, native=True)
    inputs = ROOT / 'tools/oracle/coverage_65_scene_batch_accept_input_manifest_v1.json'
    held = json.loads(inputs.read_text())
    assert held['development_freeze'] == reference(qualified)
    assert datetime.fromisoformat(held['created_at_utc']) > datetime.fromisoformat(development['frozen_at_utc'])
    assert inputs.stat().st_mtime_ns >= qualified.stat().st_mtime_ns
    for row in [*held['files'], *held['original_states']]:
        assert digest(row['path']) == row['sha256'], 'acceptance input changed'
    expected_states = {row['sha256'] for row in held['original_states']}
    assert len(held['groups']) == 4 and len(expected_states) == 2
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    proofs = []
    refs = []
    for row in config['entries']:
        groups = [group for group in held['groups'] if group['entry'] == row['entry']]
        assert len(groups) == 2 and all(group['owner'] == row['owner'] for group in groups)
        runs = []
        for group in groups:
            path = CACHE / (group['name'] + '_export/batch_manifest.json')
            batch = json.loads(path.read_text())
            assert len(batch['runs']) == 2
            group_states = set()
            for run in batch['runs']:
                assert run['returncode'] == 0 and run['frame_complete']
                assert run['ran_frames'] == run['expected_frames'] == 4000
                patch = ROOT / ('extract/analysis/' + group['name'] + '.patch')
                assert Path(run['entry_patch']).resolve() == patch.resolve()
                state = Path(run['state'])
                state = state if state.is_absolute() else ROOT / state
                group_states.add(digest(state))
                runs.append(dict(run, name=group['name'] + '_' + run['name']))
            assert group_states == expected_states
            refs.append(reference(path))
        stem = 'scene_round_decision' if row['entry'] == '0x8c098c62' else 'scene_input_transition'
        directory = CACHE / ('coverage_65_' + stem + '_combined_accept_v1_export')
        report = ROOT / ('extract/analysis/' + stem + '_integrated_combined_accept_v1_native.json')
        assert not directory.exists() and not report.exists(), 'refuse to replace acceptance evidence'
        convert([Path(run['capsule']) for run in runs], directory)
        (directory / 'batch_manifest.json').write_text(json.dumps(dict(
            coverage_credit=False, independent_acceptance=True, runs=runs), indent=2) + '\n')
        replay = verify(directory, report, min_cases=64, jobs=1, executable=native, timeout=600)
        assert replay and all(proof['pass'] for proof in replay.values()), 'strict native acceptance failed'
        accepted, files = campaign(dict(row, corpus=str(directory), native_report=str(report)), native, image)
        original = next(proof for proof in development['entries'] if proof['entry'] == row['entry'])
        states = require_independent(original, accepted, fingerprints(row['corpus']), fingerprints(directory))
        assert states == expected_states
        proofs.append(accepted)
        refs += files
    save = CACHE / 'strip_parent_original_state_save_v1_export/batch_manifest.json'
    saves = json.loads(save.read_text())
    assert len(saves['runs']) == 2
    refs.append(reference(save))
    for run, index in zip(saves['runs'], (45, 46)):
        assert run['returncode'] == 0 and run['frame_complete'] and run['ran_frames'] == 32
        cached = CACHE / f'data/vf3_{index}.state'
        local = ROOT / f'tools/emu/flycast-build/data/vf3_{index}.state'
        assert digest(cached) == digest(local) and digest(local) in expected_states
        refs.extend(reference(path) for path in (cached, local))
        for key in ('state', 'play', 'log', 'hits'):
            path = Path(run[key])
            refs.append(reference(path if path.is_absolute() else ROOT / path))
    baseline_path = ROOT / 'tools/oracle/selection_unlock_coverage_baseline_v1.json'
    baseline = json.loads(baseline_path.read_text())
    assert baseline['baseline_bytes'] == 275276 and baseline['target_bytes'] == 282527
    assert baseline['total_body_bytes'] == 434656
    for key in ('inventory', 'body_ranges', 'image'):
        assert digest(ROOT / baseline[key]) == baseline[key + '_sha256']
    from body_cover import body_spans
    accepted_bytes = {pc for start, end in baseline['baseline_spans'] for pc in range(start, end)}
    added = {pc for row in config['entries'] for start, end in body_spans()[int(row['owner'], 16)] for pc in range(start, end)}
    gain = len(added - accepted_bytes)
    assert gain == 1132
    refs += [reference(path) for path in (qualified, archive, native, inputs, baseline_path, image_path, Path(__file__))]
    output = ROOT / 'tools/oracle/scene_batch_qualification_v1.json'
    assert not output.exists()
    output.write_text(json.dumps(dict(coverage_credit=False, ready_for_promotion=True,
        marginal_bytes=gain, frozen_body_bytes=434656, development=development['entries'],
        acceptance=proofs, full_regression=development['full_regression'],
        references=list({row['path']: row for row in refs}.values())), indent=2) + '\n')
    print('Independent scene acceptance PASS; 1132 bytes ready for promotion')


if __name__ == '__main__':
    main()
