"""Seal the complete round transition routine, original caller and immutable dependencies."""
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
from callable_dispatch import captured_bytes

def audit():
    archive=CACHE/'round_transition_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==382
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    required={pc for a,z in body_spans()[0x8c09a0c0] for pc in range(a,z,2)}
    assert len(required)*2==338
    baseline=ROOT/'tools/oracle/round_transition_coverage_baseline_v1.json'
    frozen=load(baseline)
    assert frozen['baseline_bytes']==264802
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    assert 0x8c09a0c0 in {int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_round_transition_{label}_v4'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not cm['nondeterministic_entries']
        expected=len(cm['entries']['0x8c09a0a8']);assert expected==({'dev':128,'accept':127}[label])
        assert len(cm['invalid'])==128-expected
        assert all(r['started']==r['completed']==64 and not r['incomplete'] and not r['unaccounted'] for r in cm['runs'])
        pcs=set();flags=Counter();specimens=set();count=0
        for path in cm['inputs']:
            for s in records(Path(path)):
                flags[s['flags']]+=1
                if s['flags']:
                    assert s['flags']==1
                    continue
                assert s['nstate']==63
                before=struct.unpack('<63I',s['before']);after=struct.unpack('<63I',s['after'])
                assert before[8:16]==after[8:16] and before[33:37]==after[33:37]
                assert before[16]==after[16] and before[18]==after[18] and before[19]==after[19]
                assert before[37:53]==after[37:53]
                assert not before[18]&0x100000
                assert s['entry']&0x1fffffff==0x0c09a0a8
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert s['ops'][-2:]==[(0x0c09a25a,0x000b),(0x0c09a25c,0x6ef6)]
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(s['before']);count+=1
        assert count==expected and flags[0]==expected and flags[1]==128-expected and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_round_transition_{label}_v4_native_report.json'
        proof=load(report)['0x8c09a0a8']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()==f'matrix_family: {expected}/{expected} cases match (0 skipped) - PASS'
        states=set();provenance=[]
        for r in batch['runs']:
            assert r['emulator_sha256']==sha(emulator)
            assert r['entry_patch_sha256']==sha(r['entry_patch'])
            states.add(r['state'])
            provenance += [ref(ROOT/r['state']),ref(r['log']),ref(r['entry_patch']),ref(r['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=128-expected,complete_body_bytes=338,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in cm['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    from callable_dispatch import require_original_scenarios
    from callable_round_transition import verify_round_transition_sample
    callable_map=ROOT/'tools/oracle/round_transition_callable_v1.json'
    caller_refs=load(callable_map)['0x8c09a0c0']['original_caller_manifests']
    require_original_scenarios(caller_refs,rom,verify_round_transition_sample)
    caller_files=[]
    for record in caller_refs:
        path=Path(record['path']);caller=load(path)
        assert len(caller['runs'])==8 and caller['passed'] and not caller['coverage_credit']
        assert caller['provenance'][str(emulator)]==sha(emulator)
        caller_files.append(ref(path))
        for name,digest in caller['provenance'].items():assert sha(name)==digest;caller_files.append(ref(name))
        for run in caller['runs']:
            assert run['passed'] and run['flags']==0 and run['device_accesses']==0
            for field in ['capsule','log']:
                assert sha(run[field])==run[field+'_sha256'];caller_files.append(ref(run[field]))
    subset_path=CACHE/'round_transition_v1_affected_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1389 and 'round_transition_qualified:0x8c09a0c0' in subset
    assert all(bindings[k]==v for k,v in subset.items())
    selection=ROOT/'extract/analysis/round_transition_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers'] and set(load(selection)['affected_bindings'])==set(subset)
    assert load(selection)['real_dispatch_sites']==['0x8c0968f4'] and load(selection)['index']==9 and load(selection)['table']=='0x0c10baa8'
    log=ROOT/'extract/analysis/round_transition_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset);assert status['passed'] and status['reported_bindings']==len(subset)
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_round_transition_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/round_transition_v1_tool_tests.log'
    assert 'Ran 207 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/round_score_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==264802
    chain=ROOT/'extract/analysis/round_transition_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==265140
    coverage=load(ROOT/'extract/analysis/coverage.json');assert coverage['ported_unique_bytes']==265140
    excluded=[]
    for name in ['coverage_65_round_transition_dev_v1','coverage_65_round_transition_dev_v2','coverage_65_round_transition_dev_v3','coverage_65_round_transition_accept_v3']:
        corpus=ROOT/'extract/analysis'/name
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        oldops={int(pc,16)|0x80000000 for pc in load(corpus/'f_8c09a0a8.ops.json')}
        assert not required<=oldops
        if name.endswith('dev_v1'):
            assert len(cm['invalid'])==66
            assert all(s['flags']==6 for p in cm['inputs'] for s in records(Path(p)) if s['flags'])
        excluded += [ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]
        excluded += [ref(p) for p in cm['inputs']]
        excluded.append(ref(ROOT/f'extract/analysis/{name}_native_report.json'))
        for run in batch['runs']:
            assert sha(run['entry_patch'])==run['entry_patch_sha256']
            excluded += [ref(run[k]) for k in ['entry_patch','log','probe_debug']]
    return dict(passed=True,new_bytes=338,readable_bytes=265140,total_body_bytes=434656,remaining_to_65=17387,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,excluded_pilots=excluded,original_caller_files=caller_files,callable_map=ref(callable_map),
        attribution_validator=ref(ROOT/'tools/callable_round_transition.py'),attribution_dispatch=ref(ROOT/'tools/callable_body.py'),bindings=ref(ROOT/'tools/golden_bindings.json'),
        affected_bindings=ref(subset_path),selection=ref(selection),regression=ref(log),regression_status=status,
        native_tests=native_tests,tool_tests=ref(tests),baseline=ref(baseline),
        milestone=ref(ROOT/'tools/oracle/percentage_round_transition_v1_milestone.json'),chain=ref(chain),
        previous_complete_chain=ref(previous),previous_percentage_seal=ref(ROOT/'tools/oracle/round_score_v1_manifest.json'),
        gate_scope='All observed/static affected bindings and 39 native suites; previous full 60% checkpoint is pinned through round_score.')
if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/round_transition_v1_manifest.json'
    assert not path.exists(),'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +338 verified C bytes; 265140/434656; 17387 bytes remain to 65%')
