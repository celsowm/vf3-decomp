"""Seal readable audio caller models without changing frozen ownership credit."""
import argparse
import json
from pathlib import Path
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from body_cover import body_spans,measure
from audio_corpus import validate_batch
from audio_determinism import ROOT,sha
from capsules import records


def ref(path):return dict(path=str(path),sha256=sha(path))


def audit(root,archive):
    for item in json.loads(archive.read_text()):assert sha(item['path'])==item['sha256']
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    result=dict(passed=True,coverage_credit=False,new_bytes=0,frozen_sources=ref(archive),families={})
    for target,entry,owner,count in (('request',0x8c0c5c94,0x8c0c5ca2,16),('input',0x8c0c9f54,0x8c0c9f62,18)):
        family={};states=[];stacks=[];executables=set()
        for name in ('dev','accept'):
            corpus=root/f'audio_{target}_{name}_v1_cases'
            batch_path=corpus/'batch_manifest.json'
            batch=json.loads(batch_path.read_text());validate_batch(batch,True)
            comparison_path=corpus/'live_audio_comparison.json'
            comparison=json.loads(comparison_path.read_text())
            assert comparison['passed'] and len(comparison['comparisons'])==count
            assert comparison['positive_aica_crossings']==count
            cm=json.loads((corpus/'capsule_manifest.json').read_text())
            assert not cm['invalid'] and not cm['nondeterministic_entries']
            assert len(cm['entries'][hex(entry)])==count
            native_path=root/f'audio_{target}_{name}_v1_native_report.json'
            native=json.loads(native_path.read_text())[hex(entry)]
            assert native['pass'] and native['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
            executable=Path(native['executable'])
            if not executable.is_absolute():executable=ROOT/executable
            assert sha(executable)==native['executable_sha256'];executables.add(native['executable_sha256'])
            ops=json.loads((corpus/f'f_{entry:08x}.ops.json').read_text())
            pcs={int(pc,16)|0x80000000 for pc in ops}
            for pc,opcode in ops.items():
                offset=(int(pc,16)|0x80000000)-0x8c010000
                assert struct.unpack_from('<H',image,offset)[0]==int(opcode,16)
            size=sum(e-s for s,e in body_spans()[owner])
            assert measure(owner,body_spans()[owner],pcs)==(size,size,[])
            state_set={r['state'] for r in batch['runs']};assert len(state_set)==1;states.append(state_set)
            stack_set=set()
            for row in batch['runs']:
                sample=next(records(row['capsule']))
                before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
                assert before[14]==after[14] and before[15]==after[15]
                if target=='request':assert before[11:14]==after[11:14]
                stack_set.add(before[15])
                if target=='input':
                    # Verify every captured part of both immutable lookups.
                    for start,length in ((0x0c101708,458*8),(0x0c11331c,9*4)):
                        for base,a,z in sample['pages']:
                            lo=max(start,base);hi=min(start+length,base+len(a))
                            if lo<hi:
                                actual=a[lo-base:hi-base]
                                assert actual==z[lo-base:hi-base]==image[lo-0x0c010000:hi-0x0c010000]
            stacks.append(stack_set)
            if name=='accept':assert stack_set=={0x0c3fd000}
            family[name]=dict(cases=count,body_bytes=size,states=sorted(state_set),
                stack_values=sorted(stack_set),comparison=ref(comparison_path),batch=ref(batch_path),
                native=ref(native_path),executable=ref(executable),
                native_inputs=[ref(p) for p in sorted(corpus.glob('*')) if p.is_file()])
        assert states[0].isdisjoint(states[1]) and stacks[0].isdisjoint(stacks[1]) and len(executables)==1
        result['families'][target]=family
    # One actual constant-target caller identifies the selection helper.
    # This is recorded separately from the existing two-caller promotion gate.
    word=lambda pc:struct.unpack_from('<H',image,pc-0x8c010000)[0]
    assert word(0x8c0c9208)==0xd218 and word(0x8c0c920a)==0x420b and word(0x8c0c920c)==9
    assert struct.unpack_from('<I',image,0x8c0c926c-0x8c010000)[0]==0x0c0c9f54
    result['input_caller']=dict(load='0x8c0c9208',call='0x8c0c920a',literal='0x8c0c926c',target='0x0c0c9f54')
    result['scope']='Request wrapper and sound-selection input behavior, real original ARM/DSP devices; no song/reset attribution'
    result['remaining']='Input frozen-owner promotion; further fight/scene callers and callback tails; attributed song/reset transitions; standalone ARM/DSP playback'
    return result


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root',type=Path,default=ROOT/'extract/analysis')
    ap.add_argument('--archive',type=Path,required=True)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();result=audit(a.root,a.archive)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print('32 request and 36 input live/native comparisons PASS; frozen credit unchanged')
