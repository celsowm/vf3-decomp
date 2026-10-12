"""Seal a normal-build development batch before creating independent inputs."""
import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
from audio_corpus import validate_batch
from capsules import records
from ram_clipping_batch_audit import caller_files, digest, reference
from regression_status import summarize
from task_completion_audit import freeze

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate
from callable_geometry import original_pools
from portcheck import TESTS


def campaign(row,native,image):
    directory=Path(row['corpus']);report_path=Path(row['native_report'])
    entry=int(row['entry'],16);owner=int(row['owner'],16);spans=body_spans()[owner]
    manifest=json.loads((directory/'capsule_manifest.json').read_text())
    batch=json.loads((directory/'batch_manifest.json').read_text());validate_batch(batch,True)
    assert len(batch['runs'])==row['expected_runs'] and not manifest['nondeterministic_entries']
    assert set(manifest['entries'])=={hex(entry)}
    states={};fingerprints=set();refs=[]
    for run in batch['runs']:
        raw=Path(run['capsule']);summary_path=Path(str(raw)+'.summary.json');summary=json.loads(summary_path.read_text())
        assert summary['started']==summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
        assert digest(run['entry_patch'])==run['entry_patch_sha256']
        assert digest(run['emulator'])==run['emulator_sha256']=='b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
        state=Path(run['state']);state=state if state.is_absolute() else ROOT/state
        seen,inputs,excluded=states.setdefault(digest(state),(set(),set(),Counter()));count=0
        for sample in records(raw):
            count+=1;assert sample['entry']|0x80000000==entry and sample['nstate']==63
            if sample['flags']:
                assert sample['flags'] in (1,4,5,6);excluded[sample['flags']]+=1;continue
            assert not sample['device'];original_pools(sample,image,sample['ops'])
            key=hashlib.sha256(sample['before']+b''.join(struct.pack('<I',base)+before for base,before,after in sample['pages'])).hexdigest()
            inputs.add(key);fingerprints.add(key)
            for pc,op in sample['ops']:
                offset=(pc&0x1fffffff)-0x0c010000
                assert 0<=offset<=len(image)-2 and struct.unpack_from('<H',image,offset)[0]==op
                seen.add(pc|0x80000000)
        assert count==summary['completed']
        refs.extend(reference(p) for p in (raw,summary_path,state,Path(run['log']),Path(run['entry_patch']),Path(run['emulator'])))
    assert len(states)==2
    required={pc for a,z in spans for pc in range(a,z,2)};scenarios=[]
    for state,(seen,inputs,excluded) in states.items():
        assert required<=seen and len(inputs)>=64
        scenarios.append(dict(state_sha256=state,distinct_valid=len(inputs),whole_body=True,excluded_flags=dict(excluded)))
    count=len(manifest['entries'][hex(entry)]);native_row=json.loads(report_path.read_text())[hex(entry)]
    assert native_row['pass'] and native_row['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
    assert Path(native_row['cases']).resolve()==(directory/f'f_{entry:08x}.cases').resolve()
    assert native_row['executable_sha256']==digest(native)
    attribution_path=Path(row['callable']);attributions=json.loads(attribution_path.read_text())
    assert set(attributions)=={hex(owner)};validate(owner,attributions[hex(owner)],spans,directory,image)
    refs+=caller_files(attributions)
    refs.extend(reference(p) for p in directory.iterdir() if p.is_file())
    refs.extend(reference(p) for p in (report_path,attribution_path))
    return dict(entry=hex(entry),owner=hex(owner),distinct_valid=count,scenarios=scenarios),refs


def qualify(config_path):
    config=json.loads(Path(config_path).read_text());output=Path(config['out'])
    assert not output.exists(),'refuse to replace a development freeze'
    archive=Path(config['source_archive']);native=freeze(archive,native=True);source=json.loads(archive.read_text())
    assert len(source['files'])==config['archived_inputs'] and source['compiler_dependency_files']==config['compiler_dependency_files']
    image_path=ROOT/'extract/gamedata/1ST_READ.BIN';image=image_path.read_bytes();entries=[];refs=[]
    for row in config['entries']:
        proof,files=campaign(row,native,image);entries.append(proof);refs+=files
    bindings=ROOT/'tools/golden_bindings.json';log=Path(config['full_log']);text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings']==config['expected_bindings']
    native_section=text.split('\nbinding ',1)[0]
    suites=dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b',native_section,re.M))
    assert set(suites)==set(TESTS) and all(value=='PASS' for value in suites.values())
    tests=Path(config['test_log']);test_text=tests.read_text()
    assert re.search(rf'Ran {config["expected_tests"]} tests\b',test_text) and '\nOK\n' in test_text and '\nFAILED ' not in test_text
    for path in config.get('additional_native_reports',[]):
        rows=json.loads(Path(path).read_text());assert rows
        for row in rows.values():
            assert row['pass'] and row['executable_sha256']==digest(native)
            assert re.fullmatch(r'matrix_family: (\d+)/\1 cases match \(0 skipped\) - PASS',row['stdout'])
        refs.append(reference(path))
    refs.extend(reference(ROOT/'build'/f'{name}.exe') for name in TESTS)
    refs.extend(reference(p) for p in (archive,native,image_path,bindings,log,tests,config_path,Path(__file__),
        ROOT/'tools/callable_body.py',ROOT/'tools/callable_scene_round_decision.py',ROOT/'tools/callable_scene_input.py',
        ROOT/'tools/oracle/compiled_source_freeze.py'))
    result=dict(coverage_credit=False,qualified_development_only=True,frozen_at_utc=datetime.now(timezone.utc).isoformat(),
        archived_inputs=config['archived_inputs'],compiler_dependency_files=config['compiler_dependency_files'],
        entries=entries,native_suites_passed=len(TESTS),oracle_tests_passed=config['expected_tests'],full_regression=status,
        references=list({row['path']:row for row in refs}.values()))
    output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(result,indent=2)+'\n')
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--config',type=Path,required=True)
    args=parser.parse_args();result=qualify(args.config)
    print(f'{len(result["entries"])} development entries qualified; independent acceptance still required')
