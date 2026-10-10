"""Audit complete fight caller evidence without relaxing callable promotion rules."""
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


def audit(archive):
    for item in json.loads(archive.read_text()):assert sha(item['path'])==item['sha256']
    image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    result=dict(passed=True,coverage_credit=False,new_bytes=0,
                entry='0x8c099060',frozen_owner='0x8c099070',body_bytes=232,
                frozen_sources=ref(archive),campaigns={})
    states=[];stacks=[];executables=set()
    for name in ('dev','accept'):
        corpus=ROOT/f'extract/analysis/audio_fight_{name}_v1_cases'
        batch_path=corpus/'batch_manifest.json'
        batch=json.loads(batch_path.read_text());validate_batch(batch,True)
        comparison_path=corpus/'live_audio_comparison.json'
        comparison=json.loads(comparison_path.read_text())
        assert comparison['passed'] and len(comparison['comparisons'])==64
        assert comparison['positive_aica_crossings']==64
        cm=json.loads((corpus/'capsule_manifest.json').read_text())
        assert not cm['invalid'] and not cm['nondeterministic_entries']
        assert len(cm['entries']['0x8c099060'])==64
        native_path=ROOT/f'extract/analysis/audio_fight_{name}_v1_native_report.json'
        native=json.loads(native_path.read_text())['0x8c099060']
        assert native['pass'] and native['stdout']=='matrix_family: 64/64 cases match (0 skipped) - PASS'
        exe=Path(native['executable'])
        if not exe.is_absolute():exe=ROOT/exe
        assert sha(exe)==native['executable_sha256'];executables.add(sha(exe))
        ops=json.loads((corpus/'f_8c099060.ops.json').read_text())
        pcs={int(pc,16)|0x80000000 for pc in ops}
        for pc,opcode in ops.items():
            assert struct.unpack_from('<H',image,(int(pc,16)|0x80000000)-0x8c010000)[0]==int(opcode,16)
        assert measure(0x8c099070,body_spans()[0x8c099070],pcs)==(232,232,[])
        assert set(range(0x8c099060,0x8c099070,2))<=pcs
        state_set={r['state'] for r in batch['runs']};assert len(state_set)==2;states.append(state_set)
        stack_set=set();callback_count=0;mmio_count=0;actors=set()
        for row in batch['runs']:
            sample=next(records(row['capsule']))
            before=struct.unpack('<63I',sample['before']);after=struct.unpack('<63I',sample['after'])
            assert before[13:16]==after[13:16]
            stack_set.add(before[15]);case_pcs={pc&0x1fffffff for pc,op in sample['ops']}
            if 0x0c09a284 in case_pcs:
                callback_count+=1
                assert {0x0c038fe0,0x0c0645f4,0x0c0a7a0c,0x0c059508}<=case_pcs
                for base,a,z in sample['pages']:
                    for address,length in ((0x0c10baa8,64*4),(0x0c11331c,9*4)):
                        lo=max(base,address);hi=min(base+len(a),address+length)
                        if lo<hi:assert a[lo-base:hi-base]==z[lo-base:hi-base]==image[lo-0x0c010000:hi-0x0c010000]
            if any((d[0]&0x1fffffff)==0x005f80b0 and d[3] for d in sample['device']):mmio_count+=1
            for base,a,z in sample['pages']:
                address=0x0c29bb94
                if base<=address<=base+len(a)-4:actors.add(struct.unpack_from('<I',a,address-base)[0])
        assert callback_count==mmio_count and callback_count>0
        stacks.append(stack_set)
        if name=='accept':assert stack_set=={0x0c3fd000}
        result['campaigns'][name]=dict(cases=64,body_bytes=232,callback_cases=callback_count,
            pvr_write_cases=mmio_count,states=sorted(state_set),stack_values=sorted(stack_set),
            actor_addresses=sorted(actors),batch=ref(batch_path),comparison=ref(comparison_path),
            native=ref(native_path),executable=ref(exe),
            inputs=[ref(p) for p in sorted(corpus.glob('*')) if p.is_file()])
    assert states[0].isdisjoint(states[1]) and stacks[0].isdisjoint(stacks[1]) and len(executables)==1
    assert set(result['campaigns']['dev']['actor_addresses']).isdisjoint(result['campaigns']['accept']['actor_addresses'])
    assert struct.unpack_from('<I',image,0x10bb84-0x10000)[0]==0x0c099060
    assert struct.unpack_from('<I',image,0x10bad0-0x10000)[0]==0x0c09a284
    callers=[]
    for offset in range(0,len(image)-1,2):
        op=struct.unpack_from('<H',image,offset)[0]
        if op>>12==0xb:
            disp=op&4095;disp=disp if disp<2048 else disp-4096
            if 0x8c010000+offset+4+2*disp==0x8c099060:callers.append(hex(0x8c010000+offset))
    assert not callers
    result['attribution']=dict(table_slot='0x0c10bb84',index=55,callback_slot='0x0c10bad0',
        callback_index=10,callback='0x0c09a284',direct_bsr_callers=callers,
        promotion_pending='Existing validator requires two original BSR callers and supports only a single saved-register prefix; this callable has a table entry and a 16-byte prefix saving r14/r13. Rules unchanged.')
    negative=ROOT/'extract/analysis/audio_fight_live_v1_negative_comparison.json'
    data=json.loads(negative.read_text())
    assert data['negative_control'] and not data['passed'] and len(data['comparisons'])==data['positive_aica_crossings']==1
    result['negative_control']=ref(negative)
    result['scope']='Full callable, real callback 10, observed rendering helpers, original ARM/DSP and devices; overlay helper limited to this callback zero arguments'
    result['remaining']='Formal table-dispatch and multi-save-prefix promotion support; other callbacks; song/reset attribution; standalone ARM/DSP playback'
    return result


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--archive',type=Path,required=True)
    ap.add_argument('--out',type=Path,required=True);a=ap.parse_args()
    result=audit(a.archive);a.out.write_text(json.dumps(result,indent=2)+'\n')
    print('128 complete live/native fight comparisons including real callback PASS; promotion remains uncredited')
