"""Seal original-only/native encoder evidence without claiming live C audio."""
import argparse
import json
from pathlib import Path
import re
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from body_cover import body_spans,measure
from audio_determinism import ROOT,sha
from capsules import records


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit(capture,corpus,native,archive,capture_archive,regression,fragment,baseline_inventory,native_checks,tool_checks):
    original=json.loads(capture.read_text())
    captured_inputs=json.loads(capture_archive.read_text())
    assert {r['original']:r['sha256'] for r in captured_inputs}==original['provenance']
    for row in captured_inputs:assert sha(row['path'])==row['sha256']
    auditor=capture_archive.parent/'auditor.py'
    assert sha(auditor)==sha(__file__), 'auditor snapshot differs from executing tool'
    recipe_path=ROOT/'tools/oracle/audio_encoder_pilot_v1.json'
    recipe=json.loads(recipe_path.read_text())
    assert original['passed'] and original['execution']=='original_sh4'
    assert original['mode']=='nonrollback_one_shot'
    assert len(recipe['cases'])==64 and len(original['runs'])==128
    states={r['state'] for r in original['runs']};assert len(states)==2
    expected={(state,c['name'],1) for state in states for c in recipe['cases']}
    assert {(r['state'],r['case'],r['repetition']) for r in original['runs']}==expected
    def original_hash(path):
        matches=[digest for name,digest in original['provenance'].items()
                 if Path(name).resolve()==path.resolve()]
        assert len(matches)==1, 'ambiguous or missing capture provenance'
        return matches[0]
    assert sha(recipe_path)==original_hash(recipe_path)
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN'
    assert sha(image_path)==original_hash(image_path)
    for row in original['runs']:
        assert row['passed'] and row['returncode']==0 and row['flags']==0
        summary=row['summary']
        assert summary['one_shot_done'] and summary['one_shot']
        assert summary['started']==summary['completed']==1
        assert not summary['incomplete'] and not summary['unaccounted'] and not summary['restores']
        for path,digest in ((row['capsule'],row['capsule_sha256']),
                            (row['audio']['path'],row['audio']['sha256']),
                            (row['log'],row['log_sha256'])):
            assert sha(path)==digest, 'changed original capture'
        samples=list(records(row['capsule']));assert len(samples)==1
        sample=samples[0];assert sample['entry']==0x8c040b7c and not sample['flags']
        assert sample['nstate']==63
        before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
        assert before[14]==after[14] and before[15]==after[15]
        for pc,opcode in sample['ops']:
            offset=(pc|0x80000000)-0x8c010000
            assert 0<=offset<len(image)-1
            assert struct.unpack_from('<H',image,offset)[0]==opcode
    cm=json.loads((corpus/'capsule_manifest.json').read_text())
    assert not cm['invalid'] and not cm['nondeterministic_entries']
    native_count=len(cm['entries']['0x8c040b7c'])
    assert 64<=native_count<=128
    assert sum(len(case['sources']) for case in cm['entries']['0x8c040b7c'])==128
    assert set(cm['inputs'])=={r['capsule'] for r in original['runs']}
    proof=json.loads(native.read_text())['0x8c040b7c']
    assert proof['pass'] and proof['stdout']==f'matrix_family: {native_count}/{native_count} cases match (0 skipped) - PASS'
    executable=ROOT/proof['executable'];assert sha(executable)==proof['executable_sha256']
    old=json.loads(fragment.read_text())['0x8c040b7e']
    assert old['pass'] and old['stdout']=='matrix_family: 8/8 cases match (0 skipped) - PASS'
    assert old['executable_sha256']==proof['executable_sha256']
    frozen_sources=json.loads(archive.read_text())
    assert any(r['original'].endswith('src/fight/audio_encoder.c') for r in frozen_sources)
    for row in frozen_sources:assert sha(row['path'])==row['sha256']
    inventory=ROOT/'tools/golden_bindings.json'
    baseline=json.loads(regression.read_text())
    assert baseline['passed'] and baseline['current_bindings']==1363
    assert baseline['inventory']['sha256']==sha(baseline_inventory)
    old_inventory=json.loads(baseline_inventory.read_text())
    current=json.loads(inventory.read_text())
    assert current.keys()==old_inventory.keys()
    changed={key for key in current if current[key]!=old_inventory[key]}
    assert changed=={'seventh_c:0x8c040b7e'}
    upgraded=current['seventh_c:0x8c040b7e']
    assert upgraded['port']=='src/fight/audio_encoder.c'
    assert upgraded['test']==old_inventory['seventh_c:0x8c040b7e']['test']
    assert upgraded['golden']==old_inventory['seventh_c:0x8c040b7e']['golden']
    for item in (baseline['regression']['baseline'],baseline['regression']['final_native_suites']):
        assert sha(item['path'])==item['sha256']
    for item in baseline['regression']['strict_components'].values():
        assert sha(item['path'])==item['sha256']
    checks=json.loads(native_checks.read_text());assert checks['passed'] and checks['count']==39
    assert checks['frozen_executables']
    for row in checks['results']:
        assert row['status']=='PASS' and sha(row['executable']['path'])==row['executable']['sha256']
    test_log=tool_checks.read_text(encoding='utf-8-sig')
    count=re.search(r'Ran (\d+) tests',test_log)
    assert count and int(count[1])>=86 and test_log.rstrip().endswith('OK')
    chain_path=ROOT/'extract/analysis/audio_encoder_v2_chain_audit.json'
    chain=json.loads(chain_path.read_text())
    assert chain['passed'] and chain['complete'] and chain['hashes'] and chain['final_bytes']==258502
    ops=json.loads((corpus/'f_8c040b7c.ops.json').read_text())
    pcs={int(pc,16)|0x80000000 for pc in ops}
    covered,total,missing=measure(0x8c040b7e,body_spans()[0x8c040b7e],pcs)
    assert (covered,total)==(226,226) and not missing
    return dict(passed=True,advisory=True,coverage_credit=False,new_bytes=0,
        scope='Original SH-4 versus native readable C; device reads replayed from an observed tape. No live C/device acceptance.',
        entry='0x8c040b7c',frozen_owner='0x8c040b7e',body_bytes=226,
        original_runs=128,native_cases=native_count,legacy_fragment_cases=8,
        aica_crossings=sum(r['aica_events']>0 for r in original['runs']),
        original=ref(capture),recipe=ref(recipe_path),corpus=ref(corpus/'capsule_manifest.json'),
        auditor=ref(auditor),
        native=ref(native),fragment=ref(fragment),executable=ref(executable),
        native_inputs=[ref(p) for p in sorted(corpus.glob('*')) if p.is_file()],
        frozen_sources=ref(archive),capture_inputs=ref(capture_archive),
        baseline_regression=ref(regression),baseline_bindings=1363,
        baseline_inventory=ref(baseline_inventory),inventory=ref(inventory),
        fresh_native_checks=ref(native_checks),tool_checks=ref(tool_checks),
        chain_audit=ref(chain_path),readable_bytes=258502,total_body_bytes=434656,
        regression_scope='Reuse accepted 1363-binding baseline; changed fragment verified separately against 8 strict cases in the new executable. Broader repeated regression was stopped and supplies no new acceptance.',
        remaining='Live C scheduling and independent held-out acceptance for the callable entry; ARM/DSP playback and song/reset attribution.')


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    for name in ('capture','corpus','native','archive','capture-archive','regression','fragment',
                 'baseline-inventory','native-checks','tool-checks','out'):
        ap.add_argument('--'+name,type=Path,required=True)
    args=ap.parse_args()
    result=audit(args.capture,args.corpus,args.native,args.archive,args.capture_archive,args.regression,args.fragment,
                 args.baseline_inventory,args.native_checks,args.tool_checks)
    args.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f"128 original encoder runs, {result['native_cases']} distinct native cases, 8 legacy cases and accepted 1363-binding baseline PASS; zero new coverage credit")
