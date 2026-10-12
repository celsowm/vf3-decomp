"""Qualify the complete round campaign; the separate input campaign remains failed."""
from datetime import datetime
import json
from pathlib import Path
from qualify_development_batch import campaign
from ram_clipping_batch_audit import digest, reference
from task_completion_audit import freeze
from scene_batch_acceptance_audit import fingerprints, require_independent, ROOT, CACHE


def main():
    development_path = CACHE / 'scene_batch_qualified_development_freeze_v1.json'
    development = json.loads(development_path.read_text())
    assert development['qualified_development_only'] and development['full_regression']['passed']
    for row in development['references']:
        assert digest(row['path']) == row['sha256']
    config_path = ROOT / 'tools/oracle/scene_batch_development_qualification_v1.json'
    config = json.loads(config_path.read_text())
    archive = Path(config['source_archive'])
    native = freeze(archive, native=True)
    held_path = ROOT / 'tools/oracle/coverage_65_scene_batch_accept_input_manifest_v1.json'
    held = json.loads(held_path.read_text())
    assert held['development_freeze'] == reference(development_path)
    assert datetime.fromisoformat(held['created_at_utc']) > datetime.fromisoformat(development['frozen_at_utc'])
    assert held_path.stat().st_mtime_ns >= development_path.stat().st_mtime_ns
    for row in [*held['files'], *held['original_states']]:
        assert digest(row['path']) == row['sha256']
    row = next(row for row in config['entries'] if row['entry'] == '0x8c098c62')
    groups = [group for group in held['groups'] if group['entry'] == row['entry']]
    assert len(groups) == 2
    directory = CACHE / 'coverage_65_scene_round_decision_combined_accept_v1_export'
    report = ROOT / 'extract/analysis/scene_round_decision_integrated_combined_accept_v1_native.json'
    batch = json.loads((directory / 'batch_manifest.json').read_text())
    assert len(batch['runs']) == 4 and batch['independent_acceptance']
    refs = []
    expected_runs = []
    for group in groups:
        path = CACHE / (group['name'] + '_export/batch_manifest.json')
        source = json.loads(path.read_text())
        assert len(source['runs']) == 2
        for run in source['runs']:
            assert run['returncode'] == 0 and run['frame_complete']
            assert run['ran_frames'] == run['expected_frames'] == 4000
            assert Path(run['entry_patch']).resolve() == (ROOT / ('extract/analysis/' + group['name'] + '.patch')).resolve()
            expected_runs.append(dict(run, name=group['name'] + '_' + run['name']))
        refs.append(reference(path))
    assert batch['runs'] == expected_runs, 'round campaign was filtered or changed'
    original = next(proof for proof in development['entries'] if proof['entry'] == row['entry'])
    proof, files = campaign(dict(row, corpus=str(directory), native_report=str(report)), native,
                           (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes())
    states = require_independent(original, proof, fingerprints(row['corpus']), fingerprints(directory))
    assert states == {row['sha256'] for row in held['original_states']}
    baseline_path = ROOT / 'tools/oracle/selection_unlock_coverage_baseline_v1.json'
    baseline = json.loads(baseline_path.read_text())
    from body_cover import body_spans
    before = {pc for start, end in baseline['baseline_spans'] for pc in range(start, end)}
    added = {pc for start, end in body_spans()[int(row['owner'], 16)] for pc in range(start, end)}
    assert len(added - before) == 882 and baseline['baseline_bytes'] == 275276
    refs += development['references'] + files
    refs += [reference(path) for path in (development_path, config_path, held_path, archive,
             baseline_path, Path(__file__), ROOT / 'tools/oracle/scene_batch_acceptance_audit.py')]
    output = ROOT / 'tools/oracle/scene_round_qualification_v1.json'
    assert not output.exists(), 'refuse to replace acceptance qualification'
    output.write_text(json.dumps(dict(coverage_credit=False, ready_for_promotion=True,
        marginal_bytes=882, development=[original], acceptance=[proof],
        full_regression=development['full_regression'],
        scope='All four complete round-decision runs and every valid specimen; separate failed input-transition campaign excluded in full.',
        references=list({row['path']: row for row in refs}.values())), indent=2) + '\n')
    print('Complete round campaign independently qualified; 882 bytes ready for promotion')


if __name__ == '__main__':
    main()
