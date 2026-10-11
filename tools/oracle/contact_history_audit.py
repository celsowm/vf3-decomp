"""Seal the complete contact history updater, original caller and immutable dependencies."""
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
    archive=CACHE/'contact_history_dev_v3_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==380
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    required={pc for a,z in body_spans()[0x8c0c0c04] for pc in range(a,z,2)}
    assert len(required)*2==648
    baseline=ROOT/'tools/oracle/contact_history_coverage_baseline_v1.json'
    frozen=load(baseline)
    assert frozen['baseline_bytes']==263438
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    assert 0x8c0c0c04 in {int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_contact_history_{label}_v4'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not cm['nondeterministic_entries']
        expected=len(cm['entries']['0x8c0c0bf4']);assert expected==({'dev':126,'accept':127}[label])
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
                assert before[16]==after[16] and before[18]==after[18]
                assert before[37:53]==after[37:53]
                assert not before[18]&0x100000
                assert s['entry']&0x1fffffff==0x0c0c0bf4
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert s['ops'][-2:] in ([(0x0c0c0eb6,0x000b),(0x0c0c0eb8,0x6ef6)],[(0x0c0c1080,0x000b),(0x0c0c1082,0x146f)])
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(s['before']);count+=1
        assert count==expected and flags[0]==expected and flags[1]==128-expected and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_contact_history_{label}_v4_native_report.json'
        proof=load(report)['0x8c0c0bf4']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()==f'matrix_family: {expected}/{expected} cases match (0 skipped) - PASS'
        states=set();provenance=[]
        for r in batch['runs']:
            assert r['emulator_sha256']==sha(emulator)
            assert r['entry_patch_sha256']==sha(r['entry_patch'])
            states.add(r['state'])
            provenance += [ref(ROOT/r['state']),ref(r['log']),ref(r['entry_patch']),ref(r['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=128-expected,complete_body_bytes=648,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in cm['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    from callable_dispatch import require_original_scenarios
    from callable_contact_history import verify_contact_history_sample
    callable_map=ROOT/'tools/oracle/contact_history_callable_v1.json'
    caller_refs=load(callable_map)['0x8c0c0c04']['original_caller_manifests']
    require_original_scenarios(caller_refs,rom,verify_contact_history_sample)
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
    subset_path=CACHE/'contact_history_v1_affected_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1386 and 'contact_history_qualified:0x8c0c0c04' in subset
    assert all(bindings[k]==v for k,v in subset.items())
    selection=ROOT/'extract/analysis/contact_history_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers'] and set(load(selection)['affected_bindings'])==set(subset)
    assert load(selection)['real_bsr_sites']==['0x8c0c045c','0x8c0c04bc'] and load(selection)['delay_opcode']=='64e3'
    log=ROOT/'extract/analysis/contact_history_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset);assert status['passed'] and status['reported_bindings']==len(subset)
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_contact_history_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/contact_history_v1_tool_tests.log'
    assert 'Ran 186 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/contact_init_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==263438
    chain=ROOT/'extract/analysis/contact_history_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==264086
    coverage=load(ROOT/'extract/analysis/coverage.json');assert coverage['ported_unique_bytes']==264086
    excluded=[]
    for version in [1,2,3]:
        corpus=ROOT/f'extract/analysis/coverage_65_contact_history_dev_v{version}'
        cm=load(corpus/'capsule_manifest.json')
        excluded += [ref(p) for p in sorted(corpus.iterdir()) if p.is_file()]
        excluded += [ref(p) for p in cm['inputs']]
    for name in ['coverage_65_contact_history_dev_v1_native_report.json','coverage_65_contact_history_dev_v2_native_report.json','coverage_65_contact_history_dev_v2_native_v2_report.json','coverage_65_contact_history_dev_v2_native_v3_report.json','coverage_65_contact_history_dev_v3_native_report.json']:
        excluded.append(ref(ROOT/'extract/analysis'/name))
    for version in [1,2]:excluded.append(ref(CACHE/f'vf3matrixfamily_contact_history_dev_v{version}.exe'))
    return dict(passed=True,new_bytes=648,readable_bytes=264086,total_body_bytes=434656,remaining_to_65=18441,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,excluded_development=excluded,original_caller_files=caller_files,callable_map=ref(callable_map),
        attribution_validator=ref(ROOT/'tools/callable_contact_history.py'),attribution_dispatch=ref(ROOT/'tools/callable_body.py'),bindings=ref(ROOT/'tools/golden_bindings.json'),
        affected_bindings=ref(subset_path),selection=ref(selection),regression=ref(log),regression_status=status,
        native_tests=native_tests,tool_tests=ref(tests),baseline=ref(baseline),
        milestone=ref(ROOT/'tools/oracle/percentage_contact_history_v1_milestone.json'),chain=ref(chain),
        previous_complete_chain=ref(previous),previous_percentage_seal=ref(ROOT/'tools/oracle/contact_init_v1_manifest.json'),
        gate_scope='All observed/static affected bindings and 39 native suites; previous full 60% checkpoint is pinned through contact_init.')
if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/contact_history_v1_manifest.json'
    assert not path.exists(),'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +648 verified C bytes; 264086/434656; 18441 bytes remain to 65%')
