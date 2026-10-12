"""Quarantine an entire owner when its captured RAM/63-word input is ambiguous.

This proves an observability limit, not a C correction or a new coverage claim.
Both original specimens and their disagreeing outputs remain immutable.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys
from capsules import records
from audio_corpus import validate_batch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from callable_geometry import original_pools


def digest(path):
    with Path(path).open('rb') as handle:
        return hashlib.file_digest(handle,'sha256').hexdigest()


def reference(path):
    return dict(path=str(Path(path).resolve()),sha256=digest(path))


def checked(ref):
    path=Path(ref['path']);assert digest(path)==ref['sha256'],'changed quarantine evidence';return path


def observable(sample, after=False):
    return sample['after' if after else 'before']+b''.join(
        struct.pack('<I',base)+values[1 if after else 0]
        for base,*values in sorted(sample['pages']))


def compare(left,right):
    for sample in (left,right):
        assert sample['flags']==0 and sample['nstate']==63 and not sample['device'],'not a complete RAM-only specimen'
        assert len(sample['before'])==len(sample['after'])==252
    assert left['entry']&0x1fffffff==right['entry']&0x1fffffff,'another root'
    assert observable(left)==observable(right),'captured original inputs differ'
    assert observable(left,True)!=observable(right,True) or left['exitpc']!=right['exitpc'],'original outputs do not disagree'


def specimen(path,ident):
    for sample in records(path):
        if sample['id']==ident:return sample
    raise AssertionError('missing original specimen')


def validate(path):
    data=json.loads(Path(path).read_text())
    assert data['coverage_credit'] is False and data['quarantined_entry']=='0x8c0a8f8c'
    refs=data['references'];paths={name:checked(ref) for name,ref in refs.items()}
    frame=json.loads(paths['frame_manifest'].read_text());validate_batch(frame,True)
    repeat=json.loads(paths['repeat_manifest'].read_text())
    assert repeat['execution']=='original_sh4' and repeat['mode']=='nonrollback_one_shot' and repeat['passed']
    old=[run for run in frame['runs'] if Path(run['capsule']).resolve()==paths['frame_capsule'].resolve()]
    new=[run for run in repeat['runs'] if Path(run['capsule']).resolve()==paths['repeat_capsule'].resolve()]
    assert len(old)==len(new)==1
    old,new=old[0],new[0]
    assert old['returncode']==new['returncode']==0 and new['passed']
    assert digest(ROOT/old['state'])==digest(ROOT/new['state']),'another original scenario'
    assert old['emulator_sha256']==digest(old['emulator'])==repeat['provenance'][old['emulator']]
    for name,expected in repeat['provenance'].items():assert digest(name)==expected,'changed repeat provenance'
    for raw in (paths['frame_capsule'],paths['repeat_capsule']):
        summary=json.loads(Path(str(raw)+'.summary.json').read_text())
        assert summary['started']==summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
    assert new['summary']['explicit_return_only'] and new['summary']['one_shot_done'] and not new['summary']['restores']
    assert new['flags']==0 and new['device_accesses']==0
    left=specimen(paths['frame_capsule'],data['frame_invocation']);right=specimen(paths['repeat_capsule'],data['repeat_invocation'])
    compare(left,right)
    assert left['entry']&0x1fffffff==0xc0a8f8c
    image=paths['image'].read_bytes()
    for sample in (left,right):
        original_pools(sample,image,sample['ops'])
        for pc,op in sample['ops']:
            offset=(pc&0x1fffffff)-0xc010000
            assert 0<=offset<=len(image)-2 and struct.unpack_from('<H',image,offset)[0]==op,'nonoriginal instruction'
    return data


def build(frame_path,repeat_path,out):
    assert not out.exists(),'refuse to overwrite quarantine proof'
    frame=json.loads(frame_path.read_text());repeat=json.loads(repeat_path.read_text())
    old=frame['runs'][1];new=repeat['runs'][0]
    paths=dict(frame_manifest=frame_path,repeat_manifest=repeat_path,
        frame_capsule=Path(old['capsule']),repeat_capsule=Path(new['capsule']),
        image=ROOT/'extract/gamedata/1ST_READ.BIN',state=ROOT/old['state'])
    paths.update({f'provenance_{i}':Path(name) for i,name in enumerate(repeat['provenance'])})
    for kind,run in (('frame',old),('repeat',new)):
        paths[kind+'_summary']=Path(str(run['capsule'])+'.summary.json');paths[kind+'_log']=Path(run['log'])
        paths[kind+'_patch']=Path(run['entry_patch']) if kind=='frame' else Path(run['log']).with_suffix('.patch')
    paths['repeat_audio']=Path(new['audio']['path'])
    data=dict(coverage_credit=False,quarantined_entry='0x8c0a8f8c',quarantined_owner='0x8c0a8f98',
        frame_invocation=2597,repeat_invocation=specimen(Path(new['capsule']),1)['id'],
        reason='Identical captured RAM and all 63 architectural values yield differing original paths and outputs; this owner cannot qualify through this observable-input model.',
        references={name:reference(path) for name,path in paths.items()})
    out.write_text(json.dumps(data,indent=2)+'\n');validate(out)
    print('Original observable-input disagreement verified; owner remains uncredited')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--frame',type=Path,required=True);parser.add_argument('--repeat',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args();build(args.frame,args.repeat,args.out)
