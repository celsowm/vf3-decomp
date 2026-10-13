"""Qualify actor-table development or disjoint acceptance without granting credit."""
import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import re
import sys
from evidence_inspect import capture, fingerprints
from capsules import records
from ram_clipping_batch_audit import digest, reference, caller_files
from task_completion_audit import freeze
from regression_status import summarize

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate
from portcheck import TESTS


def campaign(directory, report, owners, native, callables):
    batch_path = directory/'batch_manifest.json'
    inspected = capture([batch_path], owners, ROOT/'extract/gamedata/1ST_READ.BIN')
    assert len(inspected['scenarios']) == 2 and not inspected['nondeterministic_entries']
    for run in inspected['runs']:
        assert run['complete_accounting'] and run['frame_complete'] and run['returncode'] == 0
    for state in inspected['scenarios']:
        assert set(state['entries']) == set(owners)
        for row in state['entries'].values():
            assert row['distinct_inputs'] >= 64 and not row['device_records']
            assert row['covered_body_bytes'] == row['body_bytes'] and not row['missing_pcs']
            assert set(map(int, row['excluded_flags'])) <= {1, 4, 5, 6}
    replay = json.loads(report.read_text())
    manifest = json.loads((directory/'capsule_manifest.json').read_text())
    assert set(replay) == set(owners) == set(manifest['entries'])
    for entry, row in replay.items():
        count = len(manifest['entries'][entry])
        assert row['pass'] and row['stdout'] == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        assert row['executable_sha256'] == digest(native)
        assert Path(row['cases']).resolve() == (directory/f'f_{int(entry,16):08x}.cases').resolve()
    spans, image = body_spans(), (ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    for owner, attribution in callables.items():
        validate(int(owner, 16), attribution, spans[int(owner, 16)], directory, image)
    refs = [reference(p) for p in directory.iterdir() if p.is_file()]
    inputs = {entry: set() for entry in owners}
    batch = json.loads(batch_path.read_text())
    for run in batch['runs']:
        for key in ('capsule', 'log', 'entry_patch', 'emulator'):
            refs.append(reference(run[key]))
        assert digest(run['entry_patch']) == run['entry_patch_sha256']
        assert digest(run['emulator']) == run['emulator_sha256']
        refs += [reference(str(run['capsule'])+'.summary.json'), reference(ROOT/run['state'])]
        for sample in records(Path(run['capsule'])):
            if not sample['flags']:
                inputs[hex(sample['entry'] | 0x80000000)].add(fingerprints(sample)[0])
    refs.append(reference(report))
    return inspected, inputs, refs


def qualify(a):
    if a.out.exists():
        raise FileExistsError('refusing to replace qualification')
    native = freeze(a.source_freeze, native=True)
    owners = json.loads(a.owners.read_text())
    callables = json.loads(a.callables.read_text())
    assert set(owners.values()) == set(callables) and len(owners) == a.expected_owners
    dev, old_inputs, refs = campaign(a.development, a.development_report, owners, native, callables)
    bindings = json.loads(a.bindings.read_text())
    status = summarize(a.full_regression.read_text(encoding='utf-8-sig'), bindings)
    assert status['passed'], 'complete baseline regression required'
    text = a.full_regression.read_text(encoding='utf-8-sig')
    suites = dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b', text.split('\nbinding ', 1)[0], re.M))
    assert set(suites) == set(TESTS) and all(value == 'PASS' for value in suites.values())
    tests = a.tool_tests.read_text(encoding='utf-8-sig')
    count = re.search(r'Ran (\d+) tests', tests)
    assert count and '\nOK\n' in tests and '\nFAILED' not in tests
    if a.negative_controls:
        controls=json.loads(a.negative_controls.read_text())
        assert controls['passed'] and controls['checks'] and all(row['rejected'] for row in controls['checks'])
        refs += [reference(a.negative_controls),reference(ROOT/'tools/oracle/caller_negative_controls.py')]
    refs += caller_files(callables)
    refs += [reference(p) for p in (a.source_freeze, native, a.owners, a.callables,
                                   a.full_regression, a.bindings, a.tool_tests, Path(__file__))]
    refs += [reference(ROOT/'tools'/name) for name in
             ('callable_actor_tables.py', 'callable_small_ram.py', 'callable_component_update.py', 'callable_body.py', 'callable_dispatch.py',
              'callable_geometry.py', 'body_cover.py')]
    compiled = json.loads(a.source_freeze.read_text())
    refs += [reference(a.source_freeze.parent/row['path']) for row in compiled['files']]
    result = dict(coverage_credit=False, qualified_development_only=True,
        frozen_at_utc=datetime.now(timezone.utc).isoformat(),
        normal_source_archive=reference(a.source_freeze), native=reference(native),
        compiled_inputs=len(compiled['files']), development=dev, full_regression=status,
        native_suites=len(suites), oracle_tool_tests=int(count[1]))
    if a.acceptance:
        assert a.development_freeze and a.holdout_inputs and a.acceptance_report
        frozen = json.loads(a.development_freeze.read_text())
        assert frozen['qualified_development_only'] and frozen['native'] == reference(native)
        for row in frozen['references']:
            assert digest(row['path']) == row['sha256'], 'changed development dependency'
        recipe = json.loads(a.holdout_inputs.read_text())
        assert recipe['development_freeze'] == reference(a.development_freeze)
        assert a.holdout_inputs.stat().st_mtime_ns >= a.development_freeze.stat().st_mtime_ns
        held, new_inputs, held_refs = campaign(a.acceptance, a.acceptance_report, owners, native, callables)
        assert {s['state_sha256'] for s in dev['scenarios']}.isdisjoint(
            s['state_sha256'] for s in held['scenarios'])
        for entry in owners:
            assert old_inputs[entry].isdisjoint(new_inputs[entry]), 'reused development input'
        result.update(qualified_development_only=False, ready_for_promotion=True, acceptance=held)
        refs += held_refs + [reference(a.development_freeze), reference(a.holdout_inputs)]
    coverage = json.loads((ROOT/'extract/analysis/coverage.json').read_text())
    accepted = {pc for start, end in coverage['ported_spans'] for pc in range(start, end)}
    bodies = {pc for owner in owners.values() for start, end in body_spans()[int(owner,16)]
              for pc in range(start,end)}
    result['marginal_candidate_bytes'] = len(bodies-accepted)
    assert result['marginal_candidate_bytes'] == a.expected_gain
    result['references'] = list({r['path']: r for r in refs}.values())
    a.out.write_text(json.dumps(result, indent=2)+'\n')
    print(f"RAM callbacks {'acceptance' if a.acceptance else 'development freeze'} PASS; {a.expected_gain} bytes pending promotion")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('development', 'development-report', 'source-freeze', 'owners', 'callables',
                 'full-regression', 'bindings', 'tool-tests', 'out'):
        parser.add_argument('--'+name, type=Path, required=True)
    for name in ('acceptance', 'acceptance-report', 'development-freeze', 'holdout-inputs'):
        parser.add_argument('--'+name, type=Path)
    parser.add_argument('--expected-owners',type=int,default=4)
    parser.add_argument('--expected-gain',type=int,default=1236)
    parser.add_argument('--negative-controls',type=Path)
    qualify(parser.parse_args())
