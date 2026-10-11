"""Seal both complete arena correction owners after fresh independent acceptance."""
from collections import Counter
import csv
import json
import re
import struct
import sys
from pathlib import Path
from task_completion_audit import CACHE, ROOT, freeze, load, ref, sha
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_dispatch import captured_bytes, require_original_scenarios
from callable_geometry import original_pools
from callable_ring_bound import verify_ring_bound_sample
from callable_radial_bound import verify_radial_bound_sample

OWNERS={0x8c0cb51e:(0x8c0cb532,258,0x0c0cb656,0x6df6),
        0x8c0cb67a:(0x8c0cb69e,166,0x0c0cb76a,0x6df6)}

def audit():
    archive=CACHE/'arena_bounds_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==374
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    baseline=ROOT/'tools/oracle/arena_bounds_coverage_baseline_v1.json';frozen=load(baseline)
    assert frozen['baseline_bytes']==260996 and frozen['total_body_bytes']==434656
    for key in ['inventory','body_ranges','image']:
        assert sha(ROOT/frozen[key])==frozen[key+'_sha256']
    inventory={int(r['entry'],16) for r in csv.DictReader((ROOT/frozen['inventory']).open())}
    ranges=body_spans();campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_arena_bounds_{label}_v1'
        cm=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not cm['nondeterministic_entries'] and set(cm['entries'])=={hex(e) for e in OWNERS}
        for run in cm['runs']:
            assert run['started']==run['completed']==128 and not run['incomplete'] and not run['unaccounted']
        pcs={e:set() for e in OWNERS};counts=Counter();flags=Counter();specimens=set()
        for path in cm['inputs']:
            for s in records(Path(path)):
                flags[s['flags']]+=1
                if s['flags']:
                    assert s['flags']==1, 'unsupported arena exclusion'
                    continue
                assert s['nstate']==63
                entry=s['entry']|0x80000000;assert entry in OWNERS
                before=struct.unpack('<63I',s['before']);after=struct.unpack('<63I',s['after'])
                assert before[8:16]==after[8:16] and before[16]==after[16] and before[18]==after[18]
                saved_start=34 if entry==0x8c0cb51e else 33
                assert before[saved_start:53]==after[saved_start:53]
                assert not before[18]&0x100000
                assert s['exitpc']&0x1fffffff==before[16]&0x1fffffff
                owner,size,ret,delay=OWNERS[entry]
                assert s['ops'][-2:]==[(ret,0x000b),(ret+2,delay)]
                original_pools(s,rom,s['ops'])
                for pc,op in s['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs[entry].add(pc|0x80000000)
                counts[entry]+=1;specimens.add(s['before'])
        report=ROOT/f'extract/analysis/coverage_65_arena_bounds_{label}_v1_native_report.json';proofs=load(report)
        assert set(proofs)=={hex(e) for e in OWNERS}
        for entry,(owner,size,ret,delay) in OWNERS.items():
            assert owner in inventory
            required={pc for a,z in ranges[owner] for pc in range(a,z,2)}
            assert len(required)*2==size and required<=pcs[entry]
            count=counts[entry];assert 64<=count<=128 and len(cm['entries'][hex(entry)])==count
            proof=proofs[hex(entry)]
            assert proof['pass'] and proof['executable_sha256']==sha(native)
            assert proof['stdout'].strip()==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        assert sum(counts.values())==flags[0] and flags[1]==len(cm['invalid'])
        states=set();provenance=[]
        for run in batch['runs']:
            assert run['emulator_sha256']==sha(emulator) and run['entry_patch_sha256']==sha(run['entry_patch'])
            states.add(run['state'])
            provenance += [ref(ROOT/run['state']),ref(run['log']),ref(run['entry_patch']),ref(run['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=sum(counts.values()),excluded=flags[1],complete_body_bytes=424,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],raw_capsules=[ref(p) for p in cm['inputs']],
            report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    callable_map=ROOT/'tools/oracle/arena_bounds_callable_v1.json';mapping=load(callable_map);caller_files=[]
    for owner,verifier,windows in [(0x8c0cb532,verify_ring_bound_sample,8),(0x8c0cb69e,verify_radial_bound_sample,16)]:
        refs=mapping[hex(owner)]['original_caller_manifests'];require_original_scenarios(refs,rom,verifier)
        for record in refs:
            path=Path(record['path']);caller=load(path)
            assert len(caller['runs'])==windows and caller['passed'] and not caller['coverage_credit']
            assert caller['provenance'][str(emulator)]==sha(emulator)
            caller_files.append(ref(path))
            for p,digest in caller['provenance'].items():assert sha(p)==digest;caller_files.append(ref(p))
            for run in caller['runs']:
                assert run['passed'] and run['flags']==0 and run['device_accesses']==0
                for field in ['capsule','log']:
                    assert sha(run[field])==run[field+'_sha256'];caller_files.append(ref(run[field]))
    bindings_path=CACHE/'arena_bounds_v1_affected_bindings.json';bindings=load(bindings_path)
    current=load(ROOT/'tools/golden_bindings.json');assert len(current)==1380
    assert all(current[k]==v for k,v in bindings.items())
    assert {'arena_bounds_qualified:0x8c0cb532','arena_bounds_qualified:0x8c0cb69e'}<=bindings.keys()
    log=ROOT/'extract/analysis/arena_bounds_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,bindings);assert status['passed'] and status['reported_bindings']==len(bindings)
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_arena_bounds_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/arena_bounds_v1_tool_tests.log'
    assert 'Ran 151 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    previous=ROOT/'extract/analysis/vector_sum_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==260996
    previous_seal=ROOT/'tools/oracle/vector_sum_v1_manifest.json';assert load(previous_seal)['passed']
    chain=ROOT/'extract/analysis/arena_bounds_v1_chain_extension.json'
    assert load(chain)['passed'] and load(chain)['complete'] and load(chain)['final_bytes']==261420
    assert load(ROOT/'extract/analysis/coverage.json')['ported_unique_bytes']==261420
    return dict(passed=True,new_bytes=424,readable_bytes=261420,total_body_bytes=434656,remaining_to_65=21107,
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,original_caller_files=caller_files,callable_map=ref(callable_map),
        validators=[ref(ROOT/'tools/callable_ring_bound.py'),ref(ROOT/'tools/callable_radial_bound.py')],
        attribution_dispatch=ref(ROOT/'tools/callable_body.py'),bindings=ref(ROOT/'tools/golden_bindings.json'),
        affected_bindings=ref(bindings_path),regression=ref(log),regression_status=status,native_tests=native_tests,
        tool_tests=ref(tests),baseline=ref(baseline),milestone=ref(ROOT/'tools/oracle/percentage_arena_bounds_v1_milestone.json'),
        chain=ref(chain),previous_complete_chain=ref(previous),previous_percentage_seal=ref(previous_seal),
        gate_scope='All observed/static affected bindings and 39 native suites; preceding full 60% inventory gate pinned.')

if __name__=='__main__':
    result=audit();path=ROOT/'tools/oracle/arena_bounds_v1_manifest.json'
    assert not path.exists(), 'refusing to overwrite sealed evidence'
    path.write_text(json.dumps(result,indent=2)+'\n')
    print('PASS: +424 verified C bytes; 261420/434656; 21107 bytes remain to 65%')
