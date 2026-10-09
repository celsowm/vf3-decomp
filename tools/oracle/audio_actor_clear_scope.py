"""Seal the final inventory using one full replay and two strict replacements."""
import json
from pathlib import Path
import re
from audio_determinism import sha
from regression_status import summarize

ROOT=Path(__file__).resolve().parents[2]


def ref(path):
    path=Path(path)
    return dict(path=str(path),sha256=sha(path))


def main():
    root=ROOT/'extract/analysis'
    baseline_path=root/'audio_actor_clear_v1_baseline_bindings.json'
    current_path=ROOT/'tools/golden_bindings.json'
    old=json.loads(baseline_path.read_text());current=json.loads(current_path.read_text())
    addition='percentage-audio-actor-clear:0x8c098042'
    replacement='fight:0x8c0c5d86'
    assert current.keys()-old.keys()=={addition} and not old.keys()-current.keys()
    assert [k for k in old if current[k]!=old[k]]==[replacement]
    for key in ('test','strict'):assert current[replacement][key]==old[replacement][key]
    log_path=root/'audio_actor_clear_v1_regression.log'
    log=log_path.read_text(encoding='utf-8-sig');status=summarize(log,old)
    assert status['passed'] and status['reported_bindings']==1362
    native=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s+',log.split('golden-bound ports:')[0],re.M)
    assert len(native)==39 and all(row[1]=='PASS' for row in native)
    native_path=root/'audio_actor_clear_v1_native_checks.json'
    final_native=json.loads(native_path.read_text())
    assert final_native['passed'] and final_native['count']==39 and final_native['frozen_executables']
    for row in final_native['results']:
        assert row['status']=='PASS' and sha(row['executable']['path'])==row['executable']['sha256']
    reports={}
    executable=None
    for name,entry,key in [('actor_clear_dev','0x8c098040',addition),
                           ('submission_pilot','0x8c0c5d86',replacement)]:
        path=(root/'audio_actor_clear_dev_v1_native_report.json' if name=='actor_clear_dev'
              else root/'audio_submission_pilot_v1_actor_executable_report.json')
        proof=json.loads(path.read_text())[entry]
        assert proof['pass'] and '(0 skipped) - PASS' in proof['stdout']
        assert current[key]['golden']==proof['cases'].replace('\\','/')
        candidate=ROOT/proof['executable']
        assert sha(candidate)==proof['executable_sha256']
        if executable is None:executable=candidate
        else:assert candidate==executable
        reports[name]=ref(path)
    chain_path=root/'audio_actor_clear_v1_chain_audit.json'
    chain=json.loads(chain_path.read_text())
    assert chain['passed'] and chain['complete'] and chain['hashes'] and chain['final_bytes']==258502
    tests_path=root/'audio_actor_clear_all_tools_v2.log'
    tests=tests_path.read_text(encoding='utf-8-sig');count=re.search(r'Ran (\d+) tests',tests)
    assert count and int(count[1])>=86 and tests.rstrip().endswith('OK')
    archive=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence/actor_clear_v1_sources/manifest.json')
    for item in json.loads(archive.read_text()):assert sha(item['path'])==item['sha256']
    protocol_path=ROOT/'tools/oracle/audio_arm_handoff_v1_manifest.json'
    protocol=json.loads(protocol_path.read_text());assert protocol['passed'] and not protocol['coverage_credit']
    for item in protocol['artifacts']:assert sha(item['path'])==item['sha256']
    result=dict(passed=True,current_bindings=len(current),inventory=ref(current_path),
        executable=ref(executable),baseline_inventory=ref(baseline_path),
        regression=dict(baseline=ref(log_path),baseline_status=status,native_test_count=39,
                        coverage='1362 baseline bindings; upgraded submission verified in 26 cases; added cleanup verified in 128 cases',
                        native_results=native,final_native_suites=ref(native_path),strict_components=reports),
        tool_test_count=int(count[1]),tool_tests=ref(tests_path),chain_audit=ref(chain_path),
        accepted_audio=ref(ROOT/'tools/oracle/audio_actor_clear_v1_manifest.json'),
        milestone=ref(ROOT/'tools/oracle/percentage_audio_actor_clear_milestone.json'),
        submission=ref(ROOT/'tools/oracle/audio_submission_pilot_v1_manifest.json'),
        protocol=ref(protocol_path),frozen_sources=ref(archive),
        readable_bytes=258502,total_body_bytes=434656,percentage=100*258502/434656,new_credit=72,
        remaining='Two further style callers; sound-dependent scene/input callers; attributed menu/fight/second-song reset transitions; standalone ARM/DSP audio')
    (ROOT/'tools/oracle/audio_actor_clear_v1_regression_scope.json').write_text(json.dumps(result,indent=2)+'\n')
    print(f'{len(current)} bindings, 39 native suites, separate ARM protocol proof and {count[1]} tool tests PASS')


if __name__=='__main__':main()
