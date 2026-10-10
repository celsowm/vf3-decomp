"""Seal the motion caller, frozen compiled sources and fresh regression evidence."""
import hashlib
import json
from pathlib import Path
import sys
from regression_status import summarize

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate

CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def ref(path): return dict(path=str(path),sha256=sha(path))


def audit():
    archive=CACHE/'motion_frame_dev_v1_sources/manifest.json'
    frozen=json.loads(archive.read_text())
    for item in frozen['files']:
        assert sha(archive.parent/item['path']) == item['sha256'], 'changed frozen source'
        if item['path'].startswith('src/') or item['path']=='CMakeLists.txt':
            assert sha(ROOT/item['path']) == item['sha256'], 'compiled C changed after freeze'
    assert sha(frozen['native']) == frozen['native_sha256'], 'changed native proof executable'
    mapping=ROOT/'tools/oracle/motion_frame_callable_v1.json'
    attribution=json.loads(mapping.read_text())['0x8c0a94d4']
    campaigns=[]
    for name,count,rejected in (('dev_v3',109,9),('accept_v2',118,10)):
        corpus=ROOT/f'extract/analysis/coverage_65_motion_frame_{name}'
        cm=json.loads((corpus/'capsule_manifest.json').read_text())
        assert len(cm['entries']['0x8c0a94d0']) == count
        assert len(cm['invalid']) == rejected and not cm['nondeterministic_entries']
        assert all(r['started']==r['completed'] and not r['incomplete'] and not r['unaccounted'] for r in cm['runs'])
        validate(0x8c0a94d4,attribution,body_spans()[0x8c0a94d4],corpus)
        report=ROOT/f'extract/analysis/coverage_65_motion_frame_{name}_native_report.json'
        proof=json.loads(report.read_text())['0x8c0a94d0']
        assert proof['pass'] and proof['stdout'].strip()==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        assert proof['executable_sha256']==frozen['native_sha256']==sha(proof['executable'])
        campaigns.append(dict(capsules=ref(corpus/'capsule_manifest.json'),batch=ref(corpus/'batch_manifest.json'),native=ref(report),valid_cases=count,rejected_raw_specimens=rejected))
    checks=ROOT/'extract/analysis/motion_frame_v1_native_checks.json'
    native=json.loads(checks.read_text());assert native['passed'] and native['count']==len(native['results'])==39
    for row in native['results']:
        assert row['passed'] and sha(row['executable']) == row['executable_sha256']
    native_executables=[]
    for path in sorted((CACHE/'native_motion_frame_v1').glob('*.exe')):
        assert sha(path)==sha(ROOT/'build'/path.name), 'default native executable changed during regression'
        native_executables.append(ref(path))
    tools=ROOT/'extract/analysis/motion_frame_v2_tool_tests.log'
    assert 'Ran 104 tests' in tools.read_text() and tools.read_text().rstrip().endswith('OK')
    milestone_audit=ROOT/'extract/analysis/motion_frame_v2_milestone_audit.log'
    assert milestone_audit.read_text().rstrip().endswith(' - PASS')
    chain=ROOT/'extract/analysis/motion_frame_v1_chain_audit.json'
    ch=json.loads(chain.read_text());assert ch['passed'] and ch['complete'] and ch['final_bytes']==259110
    inventory=CACHE/'motion_frame_v1_bindings.json'
    assert sha(inventory)==sha(ROOT/'tools/golden_bindings.json'), 'current binding inventory changed'
    bindings=json.loads(inventory.read_text());assert len(bindings)==1368
    log=ROOT/'extract/analysis/motion_frame_v1_verify_all.log'
    status=summarize(log.read_text(errors='replace'),bindings,'verify_all')
    assert status['passed'] and status['complete'], 'full repository regression incomplete or failed'
    return dict(passed=True,coverage_credit=True,new_bytes=188,readable_bytes=259110,total_body_bytes=434656,
                frozen_sources=ref(archive),native_executable=ref(frozen['native']),callable=ref(mapping),
                attribution_validator=ref(ROOT/'tools/callable_motion.py'),
                campaigns=campaigns,native_checks=ref(checks),tool_checks=ref(tools),
                default_native_executables=native_executables,
                milestone=ref(ROOT/'tools/oracle/percentage_motion_frame_milestone.json'),
                milestone_audit=ref(milestone_audit),
                chain=ref(chain),inventory=ref(inventory),full_regression=ref(log),regression_status=status)


if __name__=='__main__':
    out=ROOT/'tools/oracle/motion_frame_v1_manifest.json'
    assert not out.exists(), 'sealed proof already exists'
    result=audit();out.write_text(json.dumps(result,indent=2)+'\n')
    print('Motion frame: +188 verified bytes; native replay, original caller attribution and full regression PASS')
