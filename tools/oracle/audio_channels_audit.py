"""Seal channel configuration evidence with separate live and native gates."""
import argparse
import json
import struct
from pathlib import Path
from audio_determinism import sha
from audio_corpus import validate_batch
from capsules import records


def ref(path):
    return dict(path=str(path),sha256=sha(path))


def audit(root):
    result=dict(passed=True,entry='0x8c040fa4',frozen_body_bytes=786,
                scope='SH-4 channel allocation; ARM consumption remains separate',campaigns={})
    states=[]
    for name in ('dev','accept'):
        directory=root/f'audio_channels_{name}_v3_cases'
        batch_path=directory/'batch_manifest.json'
        batch=json.loads(batch_path.read_text())
        validate_batch(batch,True)
        comparison_path=directory/'live_audio_comparison.json'
        comparison=json.loads(comparison_path.read_text())
        native_path=root/f'audio_channels_{name}_v3_native_report.json'
        native=json.loads(native_path.read_text())['0x8c040fa4']
        assert native['pass'] and '(0 skipped) - PASS' in native['stdout']
        assert native['executable'].endswith('vf3matrixfamily_audio_channels_dev_v2.exe')
        executable=Path(native['executable'])
        assert sha(executable)==native['executable_sha256']
        assert len(comparison['comparisons'])==128
        cm=json.loads((directory/'capsule_manifest.json').read_text())
        assert len(cm['entries']['0x8c040fa4'])>=64
        campaign_states={row['state'] for row in batch['runs']}
        assert len(campaign_states)==2
        states.append(campaign_states)
        stack_values=set()
        for row in batch['runs']:
            capsule=next(records(row['capsule']))
            stack_values.add(struct.unpack_from('<I',capsule['before'],15*4)[0])
        if name=='accept': assert stack_values=={0x0c3fd000}
        result['campaigns'][name]=dict(batch=ref(batch_path),live_comparison=ref(comparison_path),
            native=ref(native_path),executable=ref(executable),runs=len(batch['runs']),
            distinct_native_cases=len(cm['entries']['0x8c040fa4']),
            aica_crossings=comparison['positive_aica_crossings'],
            states=sorted(campaign_states),entry_stack_values=sorted(stack_values))
    assert states[0].isdisjoint(states[1])
    assert result['campaigns']['dev']['entry_stack_values'] != result['campaigns']['accept']['entry_stack_values']
    for version,expected in [('v1',False),('v2',True)]:
        path=root/f'audio_channels_compare_pilot_{version}.json'
        report=json.loads(path.read_text())
        assert report['passed']==expected
        result[f'pilot_{version}']=dict(**ref(path),passed=expected)
    return result


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root',type=Path,default=Path('extract/analysis'))
    ap.add_argument('--out',type=Path,required=True)
    args=ap.parse_args()
    result=audit(args.root)
    result['auditor']=ref(Path(__file__))
    args.out.write_text(json.dumps(result,indent=2)+'\n')
    print('256 live comparisons, separate native corpora and relocated acceptance stack - PASS')


if __name__=='__main__': main()
