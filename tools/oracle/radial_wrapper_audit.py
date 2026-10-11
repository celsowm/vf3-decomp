"""Seal whole-body two-actor radial wrapper proof and its immutable dependencies."""
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
    archive=CACHE/'radial_wrapper_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==375
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    required={pc for a,z in body_spans()[0x8c0cb65a] for pc in range(a,z,2)}
    assert len(required)*2==32
    baseline=ROOT/'tools/oracle/radial_wrapper_coverage_baseline_v1.json'
    frozen=load(baseline)
    assert frozen['baseline_bytes']==261420
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    assert 0x8c0cb65a in {int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_radial_wrapper_{label}_v1'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not cm['nondeterministic_entries']
        expected=len(cm['entries']['0x8c0cb65a']);assert 64<=expected<=128
        assert len(cm['invalid'])==128-expected
        assert all(r['started']==r['completed']==64 and not r['incomplete'] and not r['unaccounted'] for r in cm['runs'])
        pcs=set();flags=Counter();specimens=set();count=0;branches=Counter()
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
                scene=struct.unpack('<I',captured_bytes(s,0x0c29bcc0,4))[0]
                assert captured_bytes(s,0x0c29bcc0,4)==captured_bytes(s,0x0c29bcc0,4,True)
                enabled=not(scene&0x80001);branches[enabled]+=1
                calls=[pair for pair in s['ops'] if pair[0] in (0x0c0cb66a,0x0c0cb66e)]
                assert calls==([(0x0c0cb66a,0xb006),(0x0c0cb66e,0xb004)] if enabled else [])
                assert before[4]!=before[5]
                for displacement,value in [(4,before[16]),(8,before[5])]:
                    assert struct.unpack('<I',captured_bytes(s,before[15]-displacement,4,True))[0]==value
                assert s['entry']&0x1fffffff==0x0c0cb65a
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert s['ops'][-2:]==[(0x0c0cb676,0x000b),(0x0c0cb678,0x0009)]
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(s['before']);count+=1
        assert branches[True]>0 and branches[False]>0
        assert count==expected and flags[0]==expected and flags[1]==128-expected and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_radial_wrapper_{label}_v1_native_report.json'
        proof=load(report)['0x8c0cb65a']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()==f'matrix_family: {expected}/{expected} cases match (0 skipped) - PASS'
        states=set();provenance=[]
        for r in batch['runs']:
            assert r['emulator_sha256']==sha(emulator)
            assert r['entry_patch_sha256']==sha(r['entry_patch'])
            states.add(r['state'])
            provenance += [ref(ROOT/r['state']),ref(r['log']),ref(r['entry_patch']),ref(r['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=128-expected,enabled=branches[True],bypassed=branches[False],complete_body_bytes=32,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in cm['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    subset_path=CACHE/'radial_wrapper_v1_affected_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1381 and all(bindings[k]==v for k,v in subset.items())
    selection=ROOT/'extract/analysis/radial_wrapper_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers'] and set(load(selection)['affected_bindings'])==set(subset)
    log=ROOT/'extract/analysis/radial_wrapper_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset);assert status['passed'] and status['reported_bindings']==len(subset)
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_radial_wrapper_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/radial_wrapper_v1_tool_tests.log'
    assert 'Ran 151 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/arena_bounds_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==261420
    chain=ROOT/'extract/analysis/radial_wrapper_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==261452
    coverage=load(ROOT/'extract/analysis/coverage.json');assert coverage['ported_unique_bytes']==261452
    return dict(passed=True,new_bytes=32,readable_bytes=261452,total_body_bytes=434656,remaining_to_65=21075,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,bindings=ref(ROOT/'tools/golden_bindings.json'),
        affected_bindings=ref(subset_path),selection=ref(selection),regression=ref(log),regression_status=status,
        native_tests=native_tests,tool_tests=ref(tests),baseline=ref(baseline),
        milestone=ref(ROOT/'tools/oracle/percentage_radial_wrapper_v1_milestone.json'),chain=ref(chain),
        previous_complete_chain=ref(previous),previous_percentage_seal=ref(ROOT/'tools/oracle/arena_bounds_v1_manifest.json'),
        gate_scope='All observed/static affected bindings and 39 native suites; previous full 60% checkpoint is pinned through arena_bounds.')
if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/radial_wrapper_v1_manifest.json'
    assert not path.exists(),'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +32 verified C bytes; 261452/434656; 21075 bytes remain to 65%')
