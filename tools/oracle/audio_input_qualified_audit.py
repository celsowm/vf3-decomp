"""Seal full input behavior and constant-JSR attribution against frozen proofs."""
import argparse
import json
from pathlib import Path
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from body_cover import body_spans,measure
from callable_body import validate
from audio_corpus import validate_batch
from audio_determinism import ROOT,sha
from capsules import records

CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit():
    owner=0x8c0c9f62;entry=0x8c0c9f54
    attribution=ROOT/'tools/oracle/audio_input_callable_v2.json'
    declaration=json.loads(attribution.read_text())[hex(owner)]
    archive=CACHE/'audio_fight_live_v1_sources/manifest.json'
    for item in json.loads(archive.read_text()):
        assert sha(item['path'])==item['sha256']
        if item['original'].startswith('src/') or item['original']=='CMakeLists.txt':
            assert sha(ROOT/item['original'])==item['sha256'], 'compiled source differs from frozen input proof'
    result=dict(passed=True,entry=hex(entry),frozen_owner=hex(owner),
        body_bytes=188,new_bytes=188,coverage_credit=True,
        frozen_sources=ref(archive),attribution=ref(attribution),campaigns={})
    states=[];actors=[];stacks=[];executables=set()
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    for name in ('dev','accept'):
        corpus=ROOT/f'extract/analysis/audio_input_qualified_{name}_v2_cases'
        batch_path=corpus/'batch_manifest.json'
        batch=json.loads(batch_path.read_text());validate_batch(batch,True)
        cm=json.loads((corpus/'capsule_manifest.json').read_text())
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        assert len(cm['entries'][hex(entry)])==64
        parent,pcs=validate(owner,declaration,body_spans()[owner],corpus)
        assert parent==entry and measure(owner,body_spans()[owner],pcs)==(188,188,[])
        comparison_path=corpus/'live_audio_comparison.json'
        comparison=json.loads(comparison_path.read_text())
        assert comparison['passed'] and len(comparison['comparisons'])==comparison['positive_aica_crossings']==64
        native_path=ROOT/f'extract/analysis/audio_input_qualified_{name}_v2_native_report.json'
        native=json.loads(native_path.read_text())[hex(entry)]
        assert native['pass'] and native['stdout']=='matrix_family: 64/64 cases match (0 skipped) - PASS'
        executable=Path(native['executable']);executable=executable if executable.is_absolute() else ROOT/executable
        assert sha(executable)==native['executable_sha256'];executables.add(sha(executable))
        state_set={r['state'] for r in batch['runs']};assert len(state_set)==2;states.append(state_set)
        actor_set=set();stack_set=set()
        for row in batch['runs']:
            sample=next(records(row['capsule']))
            before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
            assert before[13:16]==after[13:16];stack_set.add(before[15])
            for base,a,z in sample['pages']:
                address=0x0c29bb94
                if base<=address<=base+len(a)-4:actor_set.add(struct.unpack_from('<I',a,address-base)[0])
                for address,length in ((0x0c101708,458*8),(0x0c11331c,9*4),(0x0c1025f0,477*4)):
                    lo=max(base,address);hi=min(base+len(a),address+length)
                    if lo<hi:assert a[lo-base:hi-base]==z[lo-base:hi-base]==image[lo-0x0c010000:hi-0x0c010000], 'modified input ID table'
        actors.append(actor_set);stacks.append(stack_set)
        assert actor_set==({0x0c480000} if name=='accept' else {0x0c404000})
        if name=='accept':assert stack_set=={0x0c3fd000}
        result['campaigns'][name]=dict(cases=64,body_bytes=188,states=sorted(state_set),
            actors=sorted(actor_set),stacks=sorted(stack_set),batch=ref(batch_path),
            comparison=ref(comparison_path),native=ref(native_path),executable=ref(executable))
    assert states[0].isdisjoint(states[1]) and actors[0].isdisjoint(actors[1]) and stacks[0].isdisjoint(stacks[1])
    assert len(executables)==1
    negative=ROOT/'extract/analysis/audio_input_qualified_v2_negative_comparison.json'
    data=json.loads(negative.read_text())
    assert data['negative_control'] and not data['passed'] and len(data['comparisons'])==data['positive_aica_crossings']==1
    result['negative_control']=ref(negative)
    tool_log=ROOT/'extract/analysis/audio_input_qualified_v2_tool_tests.log'
    assert 'Ran 98 tests' in tool_log.read_text() and tool_log.read_text().rstrip().endswith('OK')
    result['tool_checks']=ref(tool_log)
    result['baseline_regression_reuse']=ref(ROOT/'tools/oracle/audio_fight_live_v1_regression_scope.json')
    result['coverage_bytes']=258922
    return result


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();result=audit();a.out.write_text(json.dumps(result,indent=2)+'\n')
    print('128 full-body native/live input cases, original JSR and queue negative PASS')
