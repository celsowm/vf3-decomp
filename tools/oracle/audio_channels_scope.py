"""Seal the complete current inventory from unchanged baseline and new binding.

Both replay components use the same immutable native executable. Existing
bindings are compared structurally before accepting the one-binding extension.
"""
import json
from pathlib import Path
import re
from audio_determinism import sha
from regression_status import summarize

ROOT=Path(__file__).resolve().parents[2]


def ref(path):
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path))


def main():
    root=ROOT/'extract/analysis'
    current_path=ROOT/'tools/golden_bindings.json'
    current=json.loads(current_path.read_text())
    baseline_path=root/'audio_channels_v2_baseline_bindings.json'
    baseline=json.loads(baseline_path.read_text())
    key='percentage-audio-channels:0x8c040fa4'
    assert current.keys()-baseline.keys()=={key}
    assert all(current[k]==v for k,v in baseline.items())
    log_path=root/'audio_channels_v2_regression.log'
    log=log_path.read_text(encoding='utf-8-sig')
    status=summarize(log,baseline)
    assert status['passed']
    proof_path=root/'audio_channels_dev_v3_native_report.json'
    proof=json.loads(proof_path.read_text())['0x8c040fa4']
    assert proof['pass'] and proof['stdout']=='matrix_family: 128/128 cases match (0 skipped) - PASS'
    assert current[key]['golden']==proof['cases'].replace('\\','/')
    assert current[key]['test']=='build/vf3matrixfamily.exe 0x8c040fa4' and current[key]['strict']
    executable=ROOT/proof['executable']
    assert sha(executable)==proof['executable_sha256']
    native=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s+',log.split('golden-bound ports:')[0],re.M)
    assert len(native)==39 and all(row[1]=='PASS' for row in native)
    chain_path=root/'audio_channels_v3_chain_audit.json'
    chain=json.loads(chain_path.read_text())
    assert chain['passed'] and chain['complete'] and chain['hashes'] and chain['final_bytes']==258430
    tests_path=root/'audio_channels_tools_final.log'
    tests=tests_path.read_text(encoding='utf-8-sig')
    count=re.search(r'Ran (\d+) tests',tests)
    assert count and int(count[1])>=77 and tests.rstrip().endswith('OK')
    sources_path=root/'audio_channels_v2_frozen_sources/manifest.json'
    for source in json.loads(sources_path.read_text()): assert sha(source['path'])==source['sha256']
    result=dict(passed=True,current_bindings=len(current),inventory=ref(current_path),
        executable=ref(executable),baseline_inventory=ref(baseline_path),
        regression=dict(coverage='1361 unchanged bindings plus one independently replayed binding',
                        baseline=ref(log_path),baseline_status=status,addition=ref(proof_path),
                        native_test_count=len(native),native_results=native),
        tool_test_count=int(count[1]),tool_tests=ref(tests_path),chain_audit=ref(chain_path),
        accepted_audio=ref(ROOT/'tools/oracle/audio_channels_v3_manifest.json'),
        milestone=ref(ROOT/'tools/oracle/percentage_audio_channels_milestone.json'),
        frozen_sources=ref(sources_path),readable_bytes=258430,total_body_bytes=434656,
        percentage=100*258430/434656,new_credit=786,
        remaining='Sound-dependent callers, attributed bank/reset transitions and portable playback; original ARM/DSP remain research dependencies')
    (ROOT/'tools/oracle/audio_channels_v3_regression_scope.json').write_text(json.dumps(result,indent=2)+'\n')
    print(f'{len(current)} bindings, 39 native checks, {count[1]} tool checks and full hash audit - PASS')


if __name__=='__main__': main()
