"""Seal actor cleanup with separate live/native proofs and callable ownership."""
import argparse
import json
from pathlib import Path
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from body_cover import body_spans,measure
from callable_body import validate
from audio_corpus import validate_batch
from audio_determinism import sha
from capsules import records


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit(root):
    owner=0x8c098042;entry=0x8c098040
    attribution=json.loads(Path('tools/oracle/audio_actor_clear_callable_v1.json').read_text())[hex(owner)]
    spans=body_spans()[owner]
    result=dict(passed=True,entry=hex(entry),frozen_owner=hex(owner),frozen_body_bytes=72,
                scope='SH-4 actor cleanup, specialized startup and style submission; no voice/reset attribution',campaigns={})
    states=[]
    for name in ('dev','accept'):
        directory=root/f'audio_actor_clear_{name}_v1_cases'
        batch_path=directory/'batch_manifest.json'
        batch=json.loads(batch_path.read_text());validate_batch(batch,True)
        comparison_path=directory/'live_audio_comparison.json'
        comparison=json.loads(comparison_path.read_text())
        native_path=root/f'audio_actor_clear_{name}_v1_native_report.json'
        native=json.loads(native_path.read_text())[hex(entry)]
        assert native['pass'] and '(0 skipped) - PASS' in native['stdout']
        assert native['executable'].endswith('vf3matrixfamily_audio_actor_clear_v1.exe')
        executable=Path(native['executable']);assert sha(executable)==native['executable_sha256']
        cm=json.loads((directory/'capsule_manifest.json').read_text())
        assert len(cm['entries'][hex(entry)])>=64
        assert len(comparison['comparisons'])==128
        attributed,captured=validate(owner,attribution,spans,directory)
        assert attributed==entry and measure(owner,spans,captured)[:2]==(72,72)
        scenario_states={row['state'] for row in batch['runs']}
        assert len(scenario_states)==2;states.append(scenario_states)
        stack_values=set();objects=set()
        for row in batch['runs']:
            sample=next(records(row['capsule']))
            stack_values.add(struct.unpack_from('<I',sample['before'],60)[0])
            page=next(data for address,data,_ in sample['pages'] if address==0x0c29b000)
            objects.add(struct.unpack_from('<I',page,0xb94)[0])
        assert objects==({0x0c480000} if name=='accept' else {0x0c404000})
        if name=='accept':assert stack_values=={0x0c3fd000}
        result['campaigns'][name]=dict(batch=ref(batch_path),comparison=ref(comparison_path),
            native=ref(native_path),executable=ref(executable),
            distinct_cases=len(cm['entries'][hex(entry)]),runs=len(batch['runs']),
            aica_crossings=comparison['positive_aica_crossings'],
            states=sorted(scenario_states),stack_values=sorted(stack_values),owned_actors=sorted(objects))
    assert states[0].isdisjoint(states[1])
    result['callable_attribution']=ref(Path('tools/oracle/audio_actor_clear_callable_v1.json'))
    result['auditor']=ref(Path(__file__))
    return result


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root',type=Path,default=Path('extract/analysis'))
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();result=audit(a.root)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print('256 strict live comparisons and independent native full-body corpora PASS')
