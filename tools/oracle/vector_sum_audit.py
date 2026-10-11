"""Seal whole-body vector aggregation, original caller and full 60% gate and its immutable dependencies."""
from collections import Counter
import csv
import json
import re
import struct
import sys
from pathlib import Path
from task_completion_audit import CACHE,ROOT,freeze,load,ref,sha
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize
from callable_geometry import original_pools
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans

def audit():
    archive=CACHE/'vector_sum_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==372
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    required={pc for a,z in body_spans()[0x8c0a700a] for pc in range(a,z,2)}
    assert len(required)*2==386
    baseline=ROOT/'tools/oracle/vector_sum_coverage_baseline_v1.json'
    frozen=load(baseline)
    assert frozen['baseline_bytes']==260610
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    assert 0x8c0a700a in {int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_vector_sum_{label}_v1'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        expected=128 if label=='dev' else 127
        assert len(cm['invalid'])==128-expected and not cm['nondeterministic_entries']
        assert len(cm['entries']['0x8c0a6ff8'])==expected
        assert all(r['started']==r['completed']==64 and not r['incomplete'] and not r['unaccounted'] for r in cm['runs'])
        pcs=set();flags=Counter();specimens=set();count=0
        for path in cm['inputs']:
            for s in records(Path(path)):
                flags[s['flags']]+=1
                if s['flags']:
                    assert label=='accept' and s['flags']==1
                    continue
                assert s['nstate']==63
                before=struct.unpack('<63I',s['before']);after=struct.unpack('<63I',s['after'])
                assert before[8:16]==after[8:16] and before[33:37]==after[33:37]
                assert before[16]==after[16] and before[18]==after[18]
                from callable_dispatch import captured_bytes
                rows=struct.unpack('<I',captured_bytes(s,before[5],4))[0]
                if rows:
                    configured=struct.unpack('<16I',captured_bytes(s,before[4]+16,64))
                    assert after[37:49]==configured[:12] and after[52]==configured[15]
                    assert before[49:52]==after[49:52]
                else:assert before[37:53]==after[37:53]
                assert not before[18]&0x100000
                assert s['entry']&0x1fffffff==0x0c0a6ff8
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert s['ops'][-2:]==[(0x0c0a7188,0x000b),(0x0c0a718a,0x6ef6)]
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(s['before']);count+=1
        assert count==expected and flags==({0:128} if label=='dev' else {0:127,1:1}) and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_vector_sum_{label}_v1_native_report.json'
        proof=load(report)['0x8c0a6ff8']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()==f'matrix_family: {expected}/{expected} cases match (0 skipped) - PASS'
        states=set();provenance=[]
        for r in batch['runs']:
            assert r['emulator_sha256']==sha(emulator)
            assert r['entry_patch_sha256']==sha(r['entry_patch'])
            states.add(r['state'])
            provenance += [ref(ROOT/r['state']),ref(r['log']),ref(r['entry_patch']),ref(r['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=128-expected,complete_body_bytes=386,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in cm['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    from callable_dispatch import require_original_scenarios
    from callable_vector_sum import verify_vector_sum_sample
    callable_map=ROOT/'tools/oracle/vector_sum_callable_v1.json'
    refs=load(callable_map)['0x8c0a700a']['original_caller_manifests']
    require_original_scenarios(refs,rom,verify_vector_sum_sample)
    caller_path=Path(refs[0]['path']);caller=load(caller_path)
    assert len(caller['runs'])==8 and caller['passed'] and not caller['coverage_credit']
    for path,digest in caller['provenance'].items():assert sha(path)==digest
    assert caller['provenance'][str(emulator)]==sha(emulator)
    caller_files=[ref(caller_path)]+[ref(path) for path in caller['provenance']]
    for r in caller['runs']:
        assert r['passed'] and r['flags']==0 and r['device_accesses']==0
        for field in ['capsule','log']:
            assert sha(r[field])==r[field+'_sha256'];caller_files.append(ref(r[field]))
    subset_path=CACHE/'vector_sum_v1_full_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1378 and subset==bindings
    log=ROOT/'extract/analysis/vector_sum_v1_full_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset);assert status['passed'] and status['reported_bindings']==1378
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_vector_sum_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/vector_sum_v3_tool_tests.log'
    assert 'Ran 151 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/polygon_hit_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==260610
    chain=ROOT/'extract/analysis/vector_sum_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==260996
    coverage=load(ROOT/'extract/analysis/coverage.json');assert coverage['ported_unique_bytes']==260996
    return dict(passed=True,new_bytes=386,readable_bytes=260996,total_body_bytes=434656,remaining_to_65=21531,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,original_caller_files=caller_files,callable_map=ref(callable_map),
        attribution_validator=ref(ROOT/'tools/callable_vector_sum.py'),
        attribution_dispatch=ref(ROOT/'tools/callable_body.py'),bindings=ref(ROOT/'tools/golden_bindings.json'),
        full_bindings=ref(subset_path),regression=ref(log),regression_status=status,
        native_tests=native_tests,tool_tests=ref(tests),baseline=ref(baseline),
        milestone=ref(ROOT/'tools/oracle/percentage_vector_sum_v1_milestone.json'),chain=ref(chain),
        previous_complete_chain=ref(previous),previous_percentage_seal=ref(ROOT/'tools/oracle/polygon_hit_v1_manifest.json'),
        gate_scope='Full current 1378-binding inventory and all 39 native suites. At least 60% verified readable C; the 65% goal remains incomplete.')
if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/vector_sum_v1_manifest.json'
    assert not path.exists(),'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +386 verified C bytes; 260996/434656; full 60% gate passed; 21531 bytes remain to 65%')
