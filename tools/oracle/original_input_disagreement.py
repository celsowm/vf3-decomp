"""Pin an original frame/repeat disagreement under the 63-word RAM input model."""
import argparse
import json
from pathlib import Path
import struct
import sys
from audio_corpus import validate_batch
from capsules import records
from compare_original_samples import compare
from ram_clipping_batch_audit import digest, reference

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans
from callable_geometry import original_pools


def audit(frame_path, repeat_path, frame_capsule, invocation, owner):
    frame = json.loads(frame_path.read_text())
    validate_batch(frame, True)
    repeat = json.loads(repeat_path.read_text())
    assert repeat['execution'] == 'original_sh4'
    assert repeat['mode'] == 'nonrollback_one_shot' and repeat['passed']
    assert len(repeat['runs']) == 1
    old = [run for run in frame['runs'] if Path(run['capsule']).resolve() == frame_capsule.resolve()]
    assert len(old) == 1
    old, new = old[0], repeat['runs'][0]
    assert old['returncode'] == new['returncode'] == 0 and new['passed']
    assert digest(ROOT / old['state']) == digest(ROOT / new['state'])
    observer = Path(old['emulator'])
    assert digest(observer) == old['emulator_sha256'] == 'b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
    assert repeat['provenance'][str(observer)] == digest(observer)
    paths = [frame_path, repeat_path, observer, ROOT / old['state'], Path(__file__)]
    for path, expected in repeat['provenance'].items():
        assert digest(path) == expected
        paths.append(Path(path))
    repeated = Path(new['capsule'])
    for raw in (frame_capsule, repeated):
        summary_path = Path(str(raw) + '.summary.json')
        summary = json.loads(summary_path.read_text())
        assert summary['started'] == summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
        paths.extend((raw, summary_path))
    assert new['flags'] == 0 and new['device_accesses'] == 0
    assert new['summary']['explicit_return_only'] and new['summary']['one_shot_done'] and not new['summary']['restores']
    assert new['summary']['started'] == new['summary']['completed'] == 1
    comparison = compare(frame_capsule, invocation, repeated, 1)
    assert comparison['observable_disagreement'] and comparison['canonical_instruction_traces_equal']
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    specimens = [next(sample for sample in records(path) if sample['id'] == number)
                 for path, number in ((frame_capsule, invocation), (repeated, 1))]
    entry = specimens[0]['entry'] | 0x80000000
    required = {pc for start, end in body_spans()[owner] for pc in range(start, end, 2)}
    assert required & {pc | 0x80000000 for pc, op in specimens[0]['ops']}, 'owner absent from invocation'
    for sample in specimens:
        original_pools(sample, image, sample['ops'])
        for pc, op in sample['ops']:
            offset = (pc & 0x1fffffff) - 0xc010000
            assert 0 <= offset <= len(image)-2 and struct.unpack_from('<H', image, offset)[0] == op
    paths.extend((image_path, Path(old['entry_patch']), Path(old['log']),
                  Path(new['log']), Path(new['log']).with_suffix('.patch'), Path(new['audio']['path'])))
    return dict(coverage_credit=False, quarantined_entry=hex(entry), quarantined_owner=hex(owner),
        excluded_owner_bytes=sum(end-start for start, end in body_spans()[owner]),
        reason='Identical captured RAM and all 63 architectural input words execute identical original instructions but produce differing final RAM. The entire owner remains excluded under this input model.',
        limitation='The hidden state responsible has not been established. This proves an observation limit and does not prove a C correction.',
        comparison=comparison, references=list({row['path']: row for row in map(reference, paths)}.values()))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--frame', type=Path, required=True)
    parser.add_argument('--repeat', type=Path, required=True)
    parser.add_argument('--capsule', type=Path, required=True)
    parser.add_argument('--invocation', type=int, required=True)
    parser.add_argument('--owner', type=lambda value: int(value, 0), required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    assert not args.out.exists(), 'refuse to replace disagreement evidence'
    result = audit(args.frame, args.repeat, args.capsule, args.invocation, args.owner)
    args.out.write_text(json.dumps(result, indent=2) + '\n')
    print('Original input disagreement verified; the entire owner remains uncredited')
