"""Seal live encoder comparisons and disjoint held-out native acceptance."""
import argparse
import json
from pathlib import Path
import re
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from body_cover import body_spans,measure
from audio_corpus import validate_batch
from audio_determinism import ROOT,sha
from capsules import records


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit(root,archive):
    owner=0x8c040b7e;entry=0x8c040b7c
    spans=body_spans()[owner]
    sources=json.loads(archive.read_text())
    for row in sources:assert sha(row['path'])==row['sha256']
    result=dict(passed=True,coverage_credit=False,new_bytes=0,entry=hex(entry),
        frozen_owner=hex(owner),body_bytes=226,
        scope='Live readable C packing and channel requests; real original ARM/DSP/device execution, no voice/reset meaning or standalone playback',
        campaigns={},frozen_sources=ref(archive))
    states=[];stacks=[];inputs=[];executables=set()
    for name in ('dev','accept'):
        corpus=root/f'audio_encoder_live_{name}_v1_cases'
        batch_path=corpus/'batch_manifest.json'
        batch=json.loads(batch_path.read_text());validate_batch(batch,True)
        comparison_path=corpus/'live_audio_comparison.json'
        comparison=json.loads(comparison_path.read_text())
        assert comparison['passed'] and len(comparison['comparisons'])==64
        assert comparison['positive_aica_crossings']==64
        native_path=root/f'audio_encoder_live_{name}_v1_native_report.json'
        native=json.loads(native_path.read_text())[hex(entry)]
        cm=json.loads((corpus/'capsule_manifest.json').read_text())
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        count=len(cm['entries'][hex(entry)])
        assert count>=32 and sum(len(c['sources']) for c in cm['entries'][hex(entry)])==64
        assert native['pass'] and native['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
        executable=ROOT/native['executable']
        assert sha(executable)==native['executable_sha256'];executables.add(native['executable_sha256'])
        pcs={int(pc,16)|0x80000000 for pc in json.loads((corpus/'f_8c040b7c.ops.json').read_text())}
        assert measure(owner,spans,pcs)==(226,226,[])
        state_set={r['state'] for r in batch['runs']};assert len(state_set)==2;states.append(state_set)
        stack_set=set();input_set=set()
        for row in batch['runs']:
            sample=next(records(row['capsule']))
            before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
            assert before[14]==after[14] and before[15]==after[15]
            stack_set.add(before[15]);input_set.add((before[4],before[5],before[6],before[14],before[15]))
        stacks.append(stack_set);inputs.append(input_set)
        if name=='accept':assert stack_set=={0x0c3fd000}
        result['campaigns'][name]=dict(runs=64,distinct_native_cases=count,aica_crossings=64,
            states=sorted(state_set),stack_values=sorted(stack_set),batch=ref(batch_path),
            comparison=ref(comparison_path),native=ref(native_path),executable=ref(executable),
            native_inputs=[ref(p) for p in sorted(corpus.glob('*')) if p.is_file()])
    assert states[0].isdisjoint(states[1]) and stacks[0].isdisjoint(stacks[1])
    assert inputs[0].isdisjoint(inputs[1]) and len(executables)==1
    negative_path=root/'audio_encoder_live_v1_negative_comparison.json'
    negative=json.loads(negative_path.read_text())
    assert negative['negative_control'] and not negative['passed']
    assert any(not c['capsule_equal'] for c in negative['comparisons'])
    result['negative_control']=ref(negative_path)
    tests=root/'audio_encoder_live_v1_tool_tests.log'
    text=tests.read_text(encoding='utf-8-sig');count=re.search(r'Ran (\d+) tests',text)
    assert count and int(count[1])>=86 and text.rstrip().endswith('OK')
    result['tool_tests']=ref(tests)
    result['remaining']='Reuse in verified scene callers; attributed song/reset transitions; standalone ARM/DSP playback'
    return result


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root',type=Path,default=ROOT/'extract/analysis')
    ap.add_argument('--archive',type=Path,required=True)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();result=audit(a.root,a.archive)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print('128 strict live encoder comparisons and disjoint held-out native acceptance PASS; zero new bytes')
