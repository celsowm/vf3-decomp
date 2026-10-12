"""Retain original RAM one-shots alongside their original frame campaigns.

One-shots prove their explicit original return, never completed game frames.
Every owner still needs 64 distinct inputs and its whole frozen body in each
independent state when the resulting corpus is audited. No device claim is
supported by this supplemental RAM protocol.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys
from capsules import records, convert

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from callable_geometry import original_pools


def digest(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream,'sha256').hexdigest()


def checked(ref):
    path = Path(ref['path'])
    assert digest(path) == ref['sha256'], 'changed supplemental evidence'
    return path


def reference(path):
    return dict(path=str(Path(path).resolve()),sha256=digest(path))


def validate(batch, hashes=False):
    from audio_corpus import validate_batch
    primary_path = checked(batch['original_frame_campaign'])
    primary = json.loads(primary_path.read_text())
    assert primary.get('mode') != 'original_ram_supplemented', 'nested supplemental campaign'
    validate_batch(primary, hashes)
    assert len(primary['runs']) == 2, 'need two original frame scenarios'
    original_states = {digest(ROOT/run['state']) for run in primary['runs']}
    assert len(original_states) == 2, 'duplicate original frame states'
    assert batch['runs'][:2] == primary['runs'], 'original frame campaign changed'
    supplement = json.loads(checked(batch['original_ram_supplement']).read_text())
    assert supplement['execution'] == 'original_sh4' and supplement['mode'] == 'nonrollback_one_shot' and supplement['passed'], 'supplement must be completed original execution'
    observer = primary['runs'][0]['emulator']
    provenance = {Path(path).resolve(): expected for path, expected in supplement['provenance'].items()}
    assert provenance[Path(observer).resolve()] == primary['runs'][0]['emulator_sha256'] == digest(observer), 'changed original observer'
    for path, expected in supplement['provenance'].items():
        assert digest(path) == expected, 'changed original supplemental provenance'
    recipe_path = checked(batch['supplement_inputs'])
    assert provenance[recipe_path.resolve()] == batch['supplement_inputs']['sha256'], 'wrong supplemental input recipe'
    recipe = json.loads(recipe_path.read_text())
    checked(recipe['development_freeze'])
    extra = batch['runs'][2:]
    assert len(extra) == len(supplement['runs']) and extra, 'missing supplemental runs'
    image = (ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    states = set()
    for row, original in zip(extra, supplement['runs']):
        assert original['passed'] and original['returncode'] == 0 and original['flags'] == 0 and not original['device_accesses'], 'failed or non-RAM supplement'
        for key in ('capsule','state','case','returncode','log'):
            assert row[key] == original[key], 'supplemental source changed'
        assert not row['frame_complete'] and row['one_shot_done'], 'one-shot cannot claim completed game frames'
        state_hash = digest(ROOT/row['state'])
        assert state_hash in original_states, 'supplement is from another scenario'
        states.add(state_hash)
        for path, expected in ((original['capsule'], original['capsule_sha256']),
                (original['log'], original['log_sha256']),
                (Path(original['log']).with_suffix('.patch'),original['patch_sha256']),
                (original['audio']['path'],original['audio']['sha256'])):
            assert digest(path) == expected, 'changed original supplemental artifact'
        summary = json.loads(Path(str(original['capsule'])+'.summary.json').read_text())
        assert summary == original['summary'], 'changed original supplemental accounting'
        assert summary['started'] == summary['completed'] == 1 and not summary['incomplete'] and not summary['unaccounted']
        assert summary['one_shot_done'] and summary['explicit_return_only'] and not summary['restores'], 'supplement needs explicit original completion'
        samples = list(records(original['capsule']))
        assert len(samples) == 1
        sample, = samples
        assert sample['flags'] == 0 and sample['nstate'] == 63 and not sample['device']
        assert sample['entry']&0x1fffffff == 0xc08acc0, 'unsupported supplemental root'
        before = struct.unpack('<63I',sample['before']); after = struct.unpack('<63I',sample['after'])
        assert sample['exitpc']&0x1fffffff == before[16]&0x1fffffff == after[16]&0x1fffffff == 0xc0432e4
        assert before[8:16] == after[8:16] and before[18] == after[18], 'supplemental original frame changed'
        assert [(pc&0x1fffffff,op) for pc,op in sample['ops'][-2:]] == [(0xc08af4c,0x000b),(0xc08af4e,0x6ef6)], 'missing original supplemental return'
        original_pools(sample,image,sample['ops'])
        for pc, op in sample['ops']:
            offset = (pc&0x1fffffff)-0xc010000
            assert 0 <= offset <= len(image)-2 and struct.unpack_from('<H',image,offset)[0] == op, 'nonoriginal supplemental opcode'
    assert states == original_states, 'supplement must cover both independent original states'


def evidence_references(batch):
    """Seal every retained source artifact, including audio and accounting."""
    paths = [checked(batch[key]) for key in ('original_frame_campaign','original_ram_supplement','supplement_inputs')]
    supplement = json.loads(paths[1].read_text())
    paths.extend(Path(path) for path in supplement['provenance'])
    paths.append(checked(json.loads(paths[2].read_text())['development_freeze']))
    for row in supplement['runs']:
        paths.extend([Path(row['capsule']),Path(str(row['capsule'])+'.summary.json'),
            Path(row['log']),Path(row['log']).with_suffix('.patch'),Path(row['audio']['path']),ROOT/row['state']])
    paths.append(Path(__file__).with_name('coverage_65_timed_effect_holdout_supplement.py'))
    return list({str(path.resolve()): reference(path) for path in paths}.values())


def build(primary_directory, supplement_path, output):
    primary_path = primary_directory/'batch_manifest.json'
    primary = json.loads(primary_path.read_text()); supplement = json.loads(supplement_path.read_text())
    assert not output.exists(), 'refuse to overwrite a corpus'
    rows = []
    observer = primary['runs'][0]['emulator']
    for row in supplement['runs']:
        patch = Path(row['log']).with_suffix('.patch')
        rows.append(dict(name=row['case'],case=row['case'],state=row['state'],play=None,
            capsule=row['capsule'],returncode=row['returncode'],log=row['log'],
            frame_complete=False,one_shot_done=row['summary']['one_shot_done'],
            entry_patch=str(patch),entry_patch_sha256=row['patch_sha256'],
            emulator=observer,emulator_sha256=primary['runs'][0]['emulator_sha256']))
    batch = dict(mode='original_ram_supplemented',coverage_credit=False,
        original_frame_campaign=reference(primary_path),original_ram_supplement=reference(supplement_path),
        supplement_inputs=reference(next(Path(path) for path in supplement['provenance'] if Path(path).suffix == '.json')),
        runs=primary['runs']+rows)
    validate(batch, True)
    output.mkdir(parents=True)
    (output/'batch_manifest.json').write_text(json.dumps(batch,indent=2)+'\n')
    convert([Path(row['capsule']) for row in batch['runs']],output)
    print('Supplemented original corpus retained; whole-body and strict native gates remain required')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--primary',type=Path,required=True)
    parser.add_argument('--supplement',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args();build(args.primary,args.supplement,args.out)
