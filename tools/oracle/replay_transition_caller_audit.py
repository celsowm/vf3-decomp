"""Verify original scene-57 transfers through all three uncredited helpers."""
import json
from pathlib import Path
import struct
import sys
from capsules import records
from ram_clipping_batch_audit import digest, reference

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0, str(ROOT / 'tools'))
from callable_dispatch import DISPATCH, DISPATCH_OPS, TABLE, SCENE, canonical, captured_bytes, image_bytes
from callable_geometry import original_pools


def sequence(ops, start, words):
    expected = [(start + 2*n, word) for n, word in enumerate(words)]
    positions = [n for n, pair in enumerate(ops) if pair == expected[0]]
    assert len(positions) == 1, 'missing or repeated transfer'
    at = positions[0]
    assert ops[at:at+len(expected)] == expected, 'incomplete or reordered transfer'
    return at + len(expected)


def verify(sample, image):
    assert not sample['flags'] and sample['nstate'] == 63 and not sample['device']
    assert canonical(sample['entry']) == DISPATCH
    before, after = [struct.unpack('<63I', sample[key]) for key in ('before', 'after')]
    assert before[8:16] == after[8:16] and before[16] == after[16]
    assert canonical(sample['exitpc']) == canonical(before[16])
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    prefix = [(DISPATCH + 2*n, op) for n, op in enumerate(DISPATCH_OPS)]
    prefix += [(0x8c0993e0 + 2*n, op) for n, op in enumerate((0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x4f22))]
    assert ops[:len(prefix)] == prefix
    assert captured_bytes(sample, SCENE+10, 1) == bytes([57])
    slot = TABLE + 57*4
    assert image_bytes(image, slot, 4) == struct.pack('<I', 0xc0993e0)
    assert captured_bytes(sample, slot, 4) == captured_bytes(sample, slot, 4, True) == image_bytes(image, slot, 4)
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op)
    original_pools(sample, image, ops)
    at = sequence(ops, 0x8c099470, (0x7f04, 0x4f26, 0x6bf6, 0x6cf6, 0x6df6, 0xa061, 0x6ef6))
    assert ops[at][0] == 0x8c099540
    sequence(ops, 0x8c099540, (0x902f, 0xd41f, 0x4f22))
    at = sequence(ops, 0x8c09954c, (0xd21b, 0x420b, 0x0009))
    assert ops[at][0] == 0x8c0a91da
    sequence(ops, 0x8c0a91da, (0x2fe6, 0xe054, 0x2fd6, 0x2fc6, 0x2fb6, 0xde2e, 0x4f22))
    at = sequence(ops, 0x8c0a9232, (0x4f26, 0x65d3, 0xd31e, 0x64e3, 0x6bf6, 0x6cf6, 0x6df6, 0x432b, 0x6ef6))
    assert ops[at][0] == 0x8c0ae0ec
    assert any(pc == 0x8c099552 for pc, op in ops[at:])
    at = sequence(ops, 0x8c09955c, (0xa000, 0x4f26))
    assert ops[at][0] == 0x8c099560
    sequence(ops, 0x8c099560, (0x2fe6, 0xe054, 0x2fd6, 0x2fc6, 0x4f22))
    assert ops[-6:] == [(0x8c0996b8+2*n, op) for n, op in enumerate((0x7f18, 0x4f26, 0x6cf6, 0x6df6, 0x000b, 0x6ef6))]
    return dict(all_63_words_captured=True, original_scene_index=57,
        complete_save_restore=True, original_pair_callback_tail=True, original_outer_return=True)


def main():
    manifest_path = CACHE / 'replay_transition_original_dispatch_v2/manifest.json'
    manifest = json.loads(manifest_path.read_text())
    assert manifest['passed'] and manifest['execution'] == 'original_sh4'
    assert manifest['mode'] == 'nonrollback_one_shot' and len(manifest['runs']) == 8
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    refs = [reference(path) for path in (manifest_path, image_path, Path(__file__))]
    for path, expected in manifest['provenance'].items():
        assert digest(path) == expected
        refs.append(reference(path))
    proofs = []
    states = {}
    for run in manifest['runs']:
        assert run['passed'] and run['returncode'] == 0 and run['flags'] == 0 and run['device_accesses'] == 0
        summary = run['summary']
        assert summary['explicit_return_only'] and summary['one_shot_done'] and not summary['restores']
        assert summary['started'] == summary['completed'] == 1 and not summary['incomplete'] and not summary['unaccounted']
        raw = Path(run['capsule'])
        samples = list(records(raw))
        assert len(samples) == 1
        proof = verify(samples[0], image)
        state = ROOT / run['state']
        states[digest(state)] = states.get(digest(state), 0)+1
        proofs.append(dict(state_sha256=digest(state), case=run['case'], **proof))
        refs += [reference(path) for path in (state, raw, Path(str(raw)+'.summary.json'),
                 Path(run['log']), Path(run['log']).with_suffix('.patch'), Path(run['audio']['path']))]
    assert len(states) == 2 and set(states.values()) == {4}
    output = ROOT / 'tools/oracle/replay_transition_original_callers_v2_proof.json'
    assert not output.exists()
    output.write_text(json.dumps(dict(coverage_credit=False, original_caller_windows=8,
        owners=['0x8c099544', '0x8c099568', '0x8c0a91e6'], proofs=proofs,
        limitation='Caller evidence only; each complete owner still needs its qualified source freeze and fresh independent strict acceptance.',
        references=list({row['path']: row for row in refs}.values())), indent=2)+'\n')
    print('Eight original caller windows prove all three helper paths; no coverage credit')


if __name__ == '__main__':
    main()
