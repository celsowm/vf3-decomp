"""Seal a structured hidden helper without adding frozen inventory credit."""
from collections import Counter
import json
from pathlib import Path
import re
import struct
import sys
from task_completion_audit import CACHE,ROOT,freeze,load,ref,sha
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_geometry import original_pools

def audit():
    archive=CACHE/'angle_wrap_dev_v1_complete_sources/manifest.json'
    native=freeze(archive,native=True)
    assert len(load(archive)['files'])==367
    observer=CACHE/'task_return_boundary_v1_linked_sources/manifest.json'
    emulator=freeze(observer)
    image=ROOT/'extract/gamedata/1ST_READ.BIN';rom=image.read_bytes()
    spans=body_spans()[0x8c09f6fc]
    required={pc for start,end in spans for pc in range(start,end,2)}
    assert len(required)*2==254
    campaigns=[];scenarios=[];fingerprints=[]
    for label in ['dev','accept']:
        corpus=ROOT/f'extract/analysis/coverage_65_angle_wrap_{label}_v1'
        manifest=load(corpus/'capsule_manifest.json');batch=load(corpus/'batch_manifest.json')
        validate_batch(batch,True)
        assert not manifest['nondeterministic_entries']
        assert len(manifest['entries']['0x8c09f6fc'])==128
        assert all(r['started']==r['completed']==64 and not r['incomplete'] and not r['unaccounted'] for r in manifest['runs'])
        pcs=set();flags=Counter();count=0;specimens=set()
        for path in manifest['inputs']:
            for sample in records(Path(path)):
                flags[sample['flags']]+=1
                assert sample['flags']==0 and sample['nstate']==63
                before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
                assert before[8:16]==after[8:16] and before[16]==after[16]
                assert before[18]==after[18] and before[33:53]==after[33:53]
                assert sample['entry']&0x1fffffff==0x0c09f6fc
                assert sample['exitpc']&0x1fffffff==before[16]&0x1fffffff
                assert sample['ops'][-2:]==[(0x0c09f816,0x000b),(0x0c09f818,0xfdf9)]
                original_pools(sample,rom,sample['ops'])
                for pc,op in sample['ops']:
                    assert struct.unpack_from('<H',rom,(pc&0x1fffffff)-0x0c010000)[0]==op
                    pcs.add(pc|0x80000000)
                specimens.add(sample['before']);count+=1
        assert count==128 and flags=={0:128} and required<=pcs
        report=ROOT/f'extract/analysis/coverage_65_angle_wrap_{label}_v1_native_report.json'
        proof=load(report)['0x8c09f6fc']
        assert proof['pass'] and proof['executable_sha256']==sha(native)
        assert proof['stdout'].strip()=='matrix_family: 128/128 cases match (0 skipped) - PASS'
        provenance=[];states=set()
        for run in batch['runs']:
            assert run['emulator_sha256']==sha(emulator)
            assert run['entry_patch_sha256']==sha(run['entry_patch'])
            states.add(run['state'])
            provenance += [ref(ROOT/run['state']),ref(run['log']),ref(run['entry_patch']),ref(run['probe_debug'])]
        assert len(states)==2;scenarios.append(states);fingerprints.append(specimens)
        campaigns.append(dict(valid=count,excluded=0,complete_body_bytes=254,
            files=[ref(p) for p in sorted(corpus.iterdir()) if p.is_file()],
            raw_capsules=[ref(p) for p in manifest['inputs']],report=ref(report),provenance=provenance))
    assert scenarios[0].isdisjoint(scenarios[1]) and fingerprints[0].isdisjoint(fingerprints[1])
    subset_path=CACHE/'angle_wrap_v1_affected_bindings.json';subset=load(subset_path)
    bindings=load(ROOT/'tools/golden_bindings.json')
    assert len(bindings)==1373 and len(subset)==28 and all(bindings[k]==v for k,v in subset.items())
    selection=ROOT/'extract/analysis/angle_wrap_v1_affected_selection.json'
    assert not load(selection)['missing_opcode_ledgers']
    log=ROOT/'extract/analysis/angle_wrap_v1_affected_portcheck.log';text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,subset)
    assert status['passed'] and status['reported_bindings']==28
    section=text.split('replay tests:\n',1)[1].split('golden-bound ports:\n',1)[0]
    checks=re.findall(r'^  (vf3\S+)\s+(PASS|FAIL)\s',section,re.M)
    assert len(checks)==39 and all(v=='PASS' for _,v in checks)
    native_tests=[]
    for name,_ in checks:
        archived=CACHE/f'native_angle_wrap_v1/{name}.exe'
        assert sha(archived)==sha(ROOT/f'build/{name}.exe');native_tests.append(ref(archived))
    tests=ROOT/'extract/analysis/angle_wrap_v1_tool_tests.log'
    assert 'Ran 124 tests' in tests.read_text() and tests.read_text().rstrip().endswith('OK')
    coverage=load(ROOT/'extract/analysis/coverage.json')
    assert coverage['ported_unique_bytes']==259688
    baseline=ROOT/'tools/oracle/angle_wrap_coverage_baseline_v1.json'
    assert load(baseline)['baseline_bytes']==259688
    inventory=ROOT/load(baseline)['inventory']
    import csv
    assert 0x8c09f6fc not in {int(r['entry'],16) for r in csv.DictReader(inventory.open())}
    previous=ROOT/'extract/analysis/geometry_angles_v1_chain_extension.json'
    assert load(previous)['passed'] and load(previous)['complete'] and load(previous)['final_bytes']==259688
    assert not (ROOT/'tools/oracle/percentage_angle_wrap_v1_milestone.json').exists()
    return dict(passed=True,coverage_credit=False,new_bytes=0,readable_bytes=259688,
        total_body_bytes=434656,remaining_to_65=22839,complete_hidden_helper_bytes=254,
        note='The locked inventory omits this helper; its complete address ranges establish behavior but cannot earn frozen percentage credit. The historical 37-register helper and native callers remain separately tested.',
        frozen_sources=ref(archive),native=ref(native),observer_sources=ref(observer),emulator=ref(emulator),image=ref(image),
        campaigns=campaigns,bindings=ref(ROOT/'tools/golden_bindings.json'),affected_bindings=ref(subset_path),
        selection=ref(selection),regression=ref(log),regression_status=status,native_tests=native_tests,tool_tests=ref(tests),
        rejected_credit=ref(ROOT/'tools/oracle/angle_wrap_v1_rejected_credit.json'),baseline=ref(baseline),
        unchanged_previous_complete_chain=ref(previous),previous_seal=ref(ROOT/'tools/oracle/geometry_angles_v1_manifest.json'),
        inventory_guard=ref(ROOT/'tools/oracle/select_next.py'),guard_tests=ref(ROOT/'tools/oracle/test_select_inventory.py'),
        credit_selection=ref(ROOT/'extract/analysis/angle_wrap_v1_credit_selection.log'),audit_tool=ref(Path(__file__)))

if __name__=='__main__':
    output=ROOT/'tools/oracle/angle_wrap_v1_manifest.json'
    assert not output.exists(),'sealed proof already exists'
    output.write_text(json.dumps(audit(),indent=2)+'\n')
    print('Structured angle wrapping: 128 development/128 acceptance, 28 affected bindings, 39 native suites and 124 tool tests PASS; no frozen percentage credit')
