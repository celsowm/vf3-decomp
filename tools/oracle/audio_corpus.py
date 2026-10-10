"""Build native corpora from calls already verified against live C/devices.

Process-owned stop boundaries are explicit; they are never called completed
game frames. The legacy frame-completion gate remains unchanged for old batches.
"""
import argparse
import json
from pathlib import Path
from audio_determinism import sha
from audio_replay_compare import evaluate, load_runs
from capsules import convert


def validate_batch(batch, hashes=False):
    if batch.get('mode') != 'process_owned_audio':
        assert all(r['returncode']==0 and r['frame_complete'] for r in batch['runs'])
        return
    proof=batch['live_audio_proof']
    for ref in proof.values():
        assert sha(ref['path'])==ref['sha256'], 'changed live audio proof metadata'
    comparison=json.loads(Path(proof['comparison']['path']).read_text())
    assert comparison['passed'] and comparison['positive_aica_crossings']>0
    original=json.loads(Path(proof['original']['path']).read_text())
    c=json.loads(Path(proof['c']['path']).read_text())
    assert original['passed'] and c['passed'] and c['execution'] in ('readable_c_channels','readable_c_submission_family','readable_c_encoder','readable_c_callers')
    assert len(comparison['comparisons'])==len(original['runs'])==len(c['runs'])==len(batch['runs'])
    assert all(r['passed'] for r in original['runs']+c['runs'])
    for row, source in zip(batch['runs'], original['runs']):
        assert row['returncode']==0 and row['one_shot_done'] and row['restores']==0
        assert not row['frame_complete'], 'one-shot capture must not claim a completed game frame'
        for key in ('capsule','state','case','returncode'):
            assert row[key]==source[key], 'audio batch source changed'
        for key in ('one_shot_done','restores','incomplete'):
            assert row[key]==source['summary'][key], 'audio batch completion changed'
    if hashes:
        load_runs(proof['original']['path'],'original_sh4')
        load_runs(proof['c']['path'],c['execution'])


def build(original_path,c_path,out):
    result=evaluate(original_path,c_path)
    if not result['passed']: raise ValueError('live C/device comparison must pass first')
    if out.exists(): raise FileExistsError(out)
    out.mkdir(parents=True)
    comparison=out/'live_audio_comparison.json'
    comparison.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    original=json.loads(original_path.read_text())
    batch=dict(mode='process_owned_audio',runs=[],live_audio_proof={
        key:dict(path=str(path),sha256=sha(path)) for key,path in
        [('comparison',comparison),('original',original_path),('c',c_path)]})
    for r in original['runs']:
        summary=r['summary']
        batch['runs'].append(dict(capsule=r['capsule'],state=r['state'],
            play='audio_invocation',returncode=r['returncode'],frame_complete=False,
            one_shot_done=summary['one_shot_done'],restores=summary['restores'],
            case=r['case'],incomplete=summary['incomplete']))
    validate_batch(batch,True)
    convert([Path(r['capsule']) for r in batch['runs']],out)
    (out/'batch_manifest.json').write_text(json.dumps(batch,indent=2)+'\n',encoding='utf-8')


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('original',type=Path)
    ap.add_argument('c_manifest',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args()
    build(a.original,a.c_manifest,a.out)


if __name__=='__main__': main()
