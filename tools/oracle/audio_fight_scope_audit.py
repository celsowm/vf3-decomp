"""Seal an uncredited fight callable and its focused baseline regression."""
import json
from pathlib import Path
from audio_determinism import ROOT,sha

CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit():
    root=ROOT/'extract/analysis'
    inventory=ROOT/'tools/golden_bindings.json'
    baseline=CACHE/'audio_fight_live_v1_baseline_bindings.json'
    old=json.loads(baseline.read_text());current=json.loads(inventory.read_text())
    assert len(old)==1364 and len(current)==1365
    assert set(current)-set(old)=={'audio_fight:0x8c099060'}
    assert all(current[k]==old[k] for k in old)
    prior=ROOT/'tools/oracle/audio_callers_live_v1_regression_scope.json'
    accepted=json.loads(prior.read_text())
    assert accepted['passed'] and sha(baseline)==accepted['inventory']['sha256']
    archive=CACHE/'audio_fight_live_v1_sources/manifest.json'
    for item in json.loads(archive.read_text()):
        if item['original'].startswith('src/') or item['original']=='CMakeLists.txt':
            assert sha(ROOT/item['original'])==item['sha256']==sha(item['path'])
    checks=root/'audio_fight_live_v2_native_checks.json'
    data=json.loads(checks.read_text());assert data['passed'] and data['count']==len(data['results'])==39
    assert data['frozen_executables']
    for row in data['results']:
        assert row['status']=='PASS' and sha(row['executable']['path'])==row['executable']['sha256']
    tools=root/'audio_fight_live_v1_tool_tests.log'
    assert 'Ran 86 tests' in tools.read_text() and tools.read_text().rstrip().endswith('OK')
    dependencies=[]
    for target in ('encoder','request','input','actor','submission'):
        path=root/f'audio_fight_dependency_{target}_native_report.json'
        for row in json.loads(path.read_text()).values():
            assert row['pass'] and '(0 skipped) - PASS' in row['stdout']
            exe=Path(row['executable']);exe=exe if exe.is_absolute() else ROOT/exe
            assert sha(exe)==row['executable_sha256']
        dependencies.append(ref(path))
    default=root/'audio_fight_default_accept_native_report.json'
    data=json.loads(default.read_text());assert data['passed'] and len(data['results'])==3
    assert sha(ROOT/data['executable'])==data['executable_sha256']
    pilot=root/'audio_fight_live_pilot_v1_comparison.json'
    data=json.loads(pilot.read_text());assert data['passed'] and len(data['comparisons'])==data['positive_aica_crossings']==8
    proof=ROOT/'tools/oracle/audio_fight_live_v1_manifest.json'
    data=json.loads(proof.read_text());assert data['passed'] and not data['coverage_credit'] and data['new_bytes']==0
    chain=root/'audio_fight_live_v1_chain_audit.json'
    data=json.loads(chain.read_text());assert data['passed'] and data['complete'] and data['final_bytes']==258502
    return dict(passed=True,coverage_credit=False,new_bytes=0,readable_bytes=258502,
        total_body_bytes=434656,current_bindings=1365,baseline_bindings=1364,
        inventory=ref(inventory),baseline_inventory=ref(baseline),accepted_baseline=ref(prior),
        uncredited_binding='audio_fight:0x8c099060',proof=ref(proof),frozen_sources=ref(archive),
        fresh_native_checks=ref(checks),tool_checks=ref(tools),dependencies=dependencies,
        default_native=ref(default),live_pilot=ref(pilot),chain_audit=ref(chain),
        regression_scope='Accepted 1364-binding baseline reused; added fight caller and existing audio dependencies verified against current frozen executable. No repeated full-inventory acceptance claimed.',
        remaining='Formal table-dispatch and multi-save-prefix attribution; other callbacks; song/reset attribution; standalone ARM/DSP playback')


if __name__=='__main__':
    result=audit();(ROOT/'tools/oracle/audio_fight_live_v1_regression_scope.json').write_text(json.dumps(result,indent=2)+'\n')
    print('1364 accepted baseline bindings + 1 uncredited fight pilot; 39 native suites, 86 tool checks and milestone chain PASS')
