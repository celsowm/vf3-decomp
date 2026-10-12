"""Pin an original frame/probe disagreement with validated recorder provenance."""
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
from golden_batch import observer_record_limit


def audit(left_path, right_path, left_raw, right_raw, left_id, right_id, owner, controls):
    batches = [json.loads(path.read_text()) for path in (left_path, right_path)]
    selected = []
    paths = [left_path, right_path, controls, Path(__file__)]
    for batch, raw in zip(batches, (left_raw, right_raw)):
        validate_batch(batch, True)
        runs = [run for run in batch['runs'] if Path(run['capsule']).resolve() == raw.resolve()]
        assert len(runs) == 1
        run = runs[0]
        assert run['returncode'] == 0 and run['frame_complete']
        assert observer_record_limit(Path(run['emulator']), controls) == 500000
        assert digest(run['emulator']) == run['emulator_sha256']
        assert Path(run['observer_controls']).resolve() == controls.resolve()
        assert run['observer_controls_sha256'] == digest(controls)
        for item in batch['runs']:
            summary_path = Path(str(item['capsule'])+'.summary.json')
            summary = json.loads(summary_path.read_text())
            assert summary['started'] == summary['completed'] and not summary['incomplete'] and not summary['unaccounted']
            assert digest(item['entry_patch']) == item['entry_patch_sha256']
            paths.extend((Path(item['capsule']), summary_path, Path(item['log']), Path(item['entry_patch']), ROOT / item['state']))
        paths.append(Path(run['emulator']))
        selected.append(run)
    assert digest(ROOT / selected[0]['state']) == digest(ROOT / selected[1]['state'])
    result = compare(left_raw, left_id, right_raw, right_id)
    assert result['observable_disagreement'] and result['canonical_instruction_traces_equal']
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    specimens = [next(sample for sample in records(path) if sample['id'] == ident)
                 for path, ident in ((left_raw, left_id), (right_raw, right_id))]
    assert specimens[0]['entry'] | 0x80000000 == specimens[1]['entry'] | 0x80000000
    required = {pc for start, end in body_spans()[owner] for pc in range(start, end, 2)}
    for sample in specimens:
        assert required & {pc | 0x80000000 for pc, op in sample['ops']}
        original_pools(sample, image, sample['ops'])
        for pc, op in sample['ops']:
            offset = (pc & 0x1fffffff) - 0xc010000
            assert 0 <= offset <= len(image)-2 and struct.unpack_from('<H', image, offset)[0] == op
    paths.append(image_path)
    return dict(coverage_credit=False, quarantined_entry=hex(specimens[0]['entry'] | 0x80000000),
        quarantined_owner=hex(owner), excluded_owner_bytes=sum(end-start for start, end in body_spans()[owner]),
        reason='Two complete original probes execute identical instructions from identical captured RAM and all 63 input words but produce differing final RAM. The entire owner is excluded under this input model.',
        limitation='The responsible hidden state has not been established. IRQ-invalid one-shot repeats are retained separately and do not support this proof.',
        comparison=result, references=list({row['path']: row for row in map(reference, paths)}.values()))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('left', 'right', 'left-raw', 'right-raw', 'observer-controls', 'out'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--left-id', type=int, required=True)
    parser.add_argument('--right-id', type=int, required=True)
    parser.add_argument('--owner', type=lambda value: int(value, 0), required=True)
    args = parser.parse_args()
    assert not args.out.exists(), 'refuse to replace original disagreement evidence'
    result = audit(args.left, args.right, args.left_raw, args.right_raw, args.left_id,
                   args.right_id, args.owner, args.observer_controls)
    args.out.write_text(json.dumps(result, indent=2)+'\n')
    print('Original probe disagreement verified; the entire owner remains uncredited')
