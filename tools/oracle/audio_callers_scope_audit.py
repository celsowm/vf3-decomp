"""Seal focused audio regression while explicitly reusing accepted baseline proof."""
import json
from pathlib import Path
from audio_determinism import ROOT, sha

CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def ref(path):
    return dict(path=str(path), sha256=sha(path))


def audit():
    analysis = ROOT/'extract/analysis'
    inventory = ROOT/'tools/golden_bindings.json'
    baseline = CACHE/'audio_callers_live_v1_baseline_bindings.json'
    old = json.loads(baseline.read_text())
    current = json.loads(inventory.read_text())
    assert len(old) == 1363 and len(current) == 1364
    assert set(current)-set(old) == {'audio_input:0x8c0c9f54'}
    changed = {k for k in old if old[k] != current[k]}
    assert changed == {'motion_final:0x8c0c5ca2', 'seventh_c:0x8c040b7e'}
    for key in changed:
        assert old[key]['golden'] == current[key]['golden']
        assert old[key]['test'] == current[key]['test']
    prior = ROOT/'tools/oracle/audio_encoder_pilot_v1_manifest.json'
    accepted = json.loads(prior.read_text())
    assert accepted['passed'] and sha(baseline) == accepted['inventory']['sha256']
    archive = CACHE/'audio_callers_live_v1_sources/manifest.json'
    # Current compiled sources must be the sources used for these proofs.
    for item in json.loads(archive.read_text()):
        if item['original'].startswith('src/') or item['original'] == 'CMakeLists.txt':
            assert sha(ROOT/item['original']) == item['sha256'] == sha(item['path'])
    native_path = analysis/'audio_callers_live_v1_native_checks.json'
    native = json.loads(native_path.read_text())
    assert native['passed'] and native['count'] == len(native['results']) == 39
    assert native['frozen_executables']
    for row in native['results']:
        assert row['status'] == 'PASS'
        assert sha(row['executable']['path']) == row['executable']['sha256']
    tools = analysis/'audio_callers_live_v1_tool_tests.log'
    assert 'Ran 86 tests' in tools.read_text() and tools.read_text().rstrip().endswith('OK')
    reports = []
    for name in ('audio_callers_current_encoder_dev_native_report.json',
                 'audio_callers_current_encoder_accept_native_report.json',
                 'audio_callers_current_actor_dev_native_report.json',
                 'audio_actor_shared_encoder_v2_native_report.json',
                 'audio_submission_alias_v2_native_report.json'):
        path = analysis/name
        for row in json.loads(path.read_text()).values():
            assert row['pass'] and '(0 skipped) - PASS' in row['stdout']
            exe = Path(row['executable'])
            if not exe.is_absolute():
                exe = ROOT/exe
            assert sha(exe) == row['executable_sha256']
        reports.append(ref(path))
    default = analysis/'audio_callers_default_native_report.json'
    data = json.loads(default.read_text())
    assert data['passed'] and len(data['results']) == 5
    assert sha(ROOT/data['executable']) == data['executable_sha256']
    actor = analysis/'audio_actor_shared_encoder_v2_live_comparison.json'
    data = json.loads(actor.read_text())
    assert data['passed'] and len(data['comparisons']) == data['positive_aica_crossings'] == 8
    chain = analysis/'audio_callers_live_v1_chain_audit.json'
    data = json.loads(chain.read_text())
    assert data['passed'] and data['complete'] and data['final_bytes'] == 258502
    return dict(passed=True, coverage_credit=False, new_bytes=0,
        readable_bytes=258502, total_body_bytes=434656, current_bindings=1364,
        baseline_bindings=1363, baseline_inventory=ref(baseline),
        accepted_baseline=ref(prior), inventory=ref(inventory),
        changed_bindings=sorted(changed), uncredited_binding='audio_input:0x8c0c9f54',
        frozen_sources=ref(archive), fresh_native_checks=ref(native_path),
        tool_checks=ref(tools), focused_native=reports, default_native=ref(default),
        actor_shared_live=ref(actor), chain_audit=ref(chain),
        encoder=ref(ROOT/'tools/oracle/audio_encoder_live_v1_manifest.json'),
        callers=ref(ROOT/'tools/oracle/audio_callers_live_v1_manifest.json'),
        regression_scope='Accepted 1363-binding baseline reused; changed audio bindings and dependencies checked separately; no repeated full-inventory acceptance claimed',
        remaining='Input frozen-owner promotion; further fight/scene callers and callback tails; attributed song/reset transitions; standalone ARM/DSP playback')


if __name__ == '__main__':
    result = audit()
    out = ROOT/'tools/oracle/audio_callers_live_v1_regression_scope.json'
    out.write_text(json.dumps(result, indent=2)+'\n')
    print('1363 accepted baseline bindings + 1 uncredited pilot; focused audio, 39 native suites, 86 tools and milestone chain PASS')
