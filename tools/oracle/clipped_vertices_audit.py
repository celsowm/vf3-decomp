"""Seal whole-body clipped vertex proof and its immutable dependencies."""
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
    archive=CACHE/'clipped_vertices_dev_v2_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==369
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    required={pc for a,z in body_spans()[0x8c058a5c] for pc in range(a,z,2)}
    assert len(required)*2==254
    baseline=ROOT/'tools/oracle/clipped_vertices_coverage_baseline_v1.json'
    frozen=load(baseline)
    assert frozen['baseline_bytes']==259922
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    assert 0x8c058a5c in {int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_clipped_vertices_{label}_v1'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        assert len(cm['entries']['0x8c058a5c'])==128
        assert all(r['started']==r['completed']==64 and not r['incomplete'] and not r['unaccounted'] for r in cm['runs'])
        pcs=set();flags=Counter();specimens=set();count=0
        for path in cm['inputs']:
            for s in records(Path(path)):
                flags[s['flags']]+=1
                assert s['flags']==0 and s['nstate']==63
                before=struct.unpack('<63I',s['before']);after=struct.unpack('<63I',s['after'])
                assert before[3:5]==after[3:5] and before[6:12]==after[6:12] and before[13:16]==after[13:16]
                assert before[16]==after[16] and before[18]==after[18]
                assert before[37:53]==after[37:53]
                assert before[18]&0x100000
                assert s['entry']&0x1fffffff==0x0c058a5c
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert s['ops'][-2:]==[(0x0c058b56,0x000b),(0x0c058b58,0xf868)]
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(s['before']);count+=1
        assert count==128 and flags=={0:128} and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_clipped_vertices_{label}_v1_native_v2_report.json'
        proof=load(report)['0x8c058a5c']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()=='matrix_family: 128/128 cases match (0 skipped) - PASS'
        states=set();provenance=[]
        for r in batch['runs']:
            assert r['emulator_sha256']==sha(emulator)
            assert r['entry_patch_sha256']==sha(r['entry_patch'])
            states.add(r['state'])
            provenance += [ref(ROOT/r['state']),ref(r['log']),ref(r['entry_patch']),ref(r['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=0,complete_body_bytes=254,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in cm['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    helper_regressions=[]
    for label in ['dev','accept']:
        p=ROOT/f'extract/analysis/clipped_vertices_v1_packed_direction_{label}_report.json'
        proof=load(p)['0x8c05865c']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()=='matrix_family: 128/128 cases match (0 skipped) - PASS'
        helper_regressions.append(ref(p))
    subset_path=CACHE/'clipped_vertices_v1_affected_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1375 and len(subset)==1 and all(bindings[k]==v for k,v in subset.items())
    selection=ROOT/'extract/analysis/clipped_vertices_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers'] and load(selection)['rom_direct_transfer_matches']==['0x8c05849a']
    log=ROOT/'extract/analysis/clipped_vertices_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset);assert status['passed'] and status['reported_bindings']==1
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_clipped_vertices_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/clipped_vertices_v1_tool_tests.log'
    assert 'Ran 124 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/packed_direction_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==259922
    chain=ROOT/'extract/analysis/clipped_vertices_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==260176
    coverage=load(ROOT/'extract/analysis/coverage.json');assert coverage['ported_unique_bytes']==260176
    return dict(passed=True,new_bytes=254,readable_bytes=260176,total_body_bytes=434656,remaining_to_65=22351,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,helper_regressions=helper_regressions,bindings=ref(ROOT/'tools/golden_bindings.json'),
        affected_bindings=ref(subset_path),selection=ref(selection),regression=ref(log),regression_status=status,
        native_tests=native_tests,tool_tests=ref(tests),baseline=ref(baseline),
        milestone=ref(ROOT/'tools/oracle/percentage_clipped_vertices_v1_milestone.json'),chain=ref(chain),
        previous_complete_chain=ref(previous),previous_percentage_seal=ref(ROOT/'tools/oracle/packed_direction_v1_manifest.json'),
        gate_scope='One affected matrix binding plus all 39 native replay suites; the previous full inventory gate is historical. Full current inventory gate is required at 60%.')
if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/clipped_vertices_v1_manifest.json'
    assert not path.exists(),'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +254 verified C bytes; 260176/434656; 22351 bytes remain to 65%')
