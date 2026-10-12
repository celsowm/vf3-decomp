"""Whole-owner integration for the fixed RAM/clipping batch caller shapes.

The original caller verifiers remain independent and unchanged. Joint clip
manifests must pass every original window, then provide eight owner-specific
windows across two distinct original states; another row cannot prove an owner.
"""
import hashlib
import json
from pathlib import Path
import struct
from oracle.capsules import records
from callable_dispatch import canonical, checked_reference, image_bytes, captured_bytes, require_original_scenarios
import callable_clip_triangle as clip
import callable_component_update as component
import callable_list_interpolation as linked
import callable_replay_initializer as initializer
import callable_replay_interpolate as interpolate
import callable_scene_replay as scene

KIND = 'vf3-ram-clipping-batch-v1'


def contract(owner):
    for entry in clip.CALLERS:
        if owner == entry+62:
            return entry, clip.PREFIX, clip.verify_clip_triangle_sample, 'clip', [clip.CALLERS[entry][1]+2]
    fixed = {
        initializer.OWNER: (initializer.PARENT, initializer.PREFIX[:1], initializer.verify_replay_initializer_sample, 'initializer', [initializer.CALL]),
        interpolate.OWNER: (interpolate.PARENT, interpolate.PREFIX, interpolate.verify_replay_interpolate_sample, 'interpolate', [interpolate.CALL]),
        linked.OWNER: (linked.PARENT, linked.PREFIX, linked.verify_list_interpolation_sample, 'list', [linked.CALL]),
    }
    for index, (entry, owned, _, _, load) in component.ROWS.items():
        prefix = (0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x2fa6, 0x2f96, 0x2f86,
                  0xfffb, 0xffeb, 0xffdb, 0xffcb, load, 0x4f22)
        fixed[owned] = (entry, prefix, component.verify_component_update_sample, f'component-{index}', [component.CALL])
    for index, (entry, owned, prefix) in scene.ROWS.items():
        fixed[owned] = (entry, prefix, scene.verify_scene_replay_sample, f'scene-{index}', [scene.DISPATCH+36])
    assert owner in fixed, 'unsupported RAM/clipping batch owner'
    return fixed[owner]


def selected(sample, entry, category):
    if category == 'clip':
        return canonical(sample['entry']) == clip.CALLERS[entry][1]
    if category.startswith('component-'):
        before = struct.unpack('<63I', sample['before'])
        return before[14]-1 == int(category.split('-')[1])
    if category.startswith('scene-'):
        return captured_bytes(sample, scene.SCENE+10, 1)[0] == int(category.split('-')[1])
    return canonical(sample['entry']) == {'initializer': initializer.START,
        'interpolate': interpolate.START, 'list': linked.START}[category]


def owner_callers(references, image, entry, category, verifier):
    assert references, 'missing original caller manifests'
    require_original_scenarios(references, image, verifier)
    states, fingerprints, count = set(), set(), 0
    for reference in references:
        manifest = json.loads(checked_reference(reference).read_text())
        for run in manifest['runs']:
            samples = list(records(checked_reference({'path': run['capsule'], 'sha256': run['capsule_sha256']})))
            assert len(samples) == 1, 'ambiguous original caller specimen'
            sample = samples[0]
            if not selected(sample, entry, category):
                continue
            fingerprints.add(verifier(sample, image)); count += 1
            state = Path(run['state'])
            if not state.is_absolute(): state = Path(__file__).resolve().parents[1]/state
            states.add(hashlib.file_digest(state.open('rb'), 'sha256').hexdigest())
    assert count >= 8 and len(states) >= 2 and len(fingerprints) >= 2, 'need eight owner-specific original callers across two states'


def validate_ram_clipping_batch(owner, attribution, spans, corpus, image):
    entry, prefix, verifier, category, calls = contract(owner)
    assert attribution.get('kind') == KIND and int(attribution['entry'], 16) == entry, 'wrong batch callable declaration'
    assert attribution.get('contract') == category and attribution.get('call_sites') == [hex(pc) for pc in calls], 'wrong batch caller declaration'
    assert spans and min(start for start, _ in spans) == owner, 'wrong frozen batch owner'
    ops = json.loads((Path(corpus)/f'f_{entry:08x}.ops.json').read_text())
    ops = {canonical(int(pc, 16)): int(op, 16) for pc, op in ops.items()}
    for pc, op in ops.items():
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal batch body opcode'
    required = set(range(entry, owner, 2))|{pc for start, end in spans for pc in range(start, end, 2)}
    assert required <= ops.keys(), 'incomplete batch callable prefix or frozen body'
    for offset, op in enumerate(prefix):
        assert ops.get(entry+2*offset) == op, 'wrong batch original save prefix'
    lines = (Path(corpus)/f'f_{entry:08x}.cases').read_text().splitlines()
    assert len(lines) >= 64, 'need 64 distinct native batch cases'
    for line in lines:
        values = [int(word, 16) for word in line.split()[:74]]
        assert len(values) == 74 and values[18] == values[55], 'batch native FPSCR changed'
        if category == 'clip':
            assert values[:12] == values[37:49] and values[13:16] == values[50:53], 'batch native clipping integer frame changed'
            assert values[21:37] == values[58:74] and values[49]-values[12] in (0, 96, 128), 'batch native clipping FR frame or stream advancement changed'
        else:
            assert values[8:16] == values[45:53], 'batch native integer frame changed'
        if category.startswith('component-'):
            assert values[33:37] == values[70:74], 'batch native component FR saves changed'
        if category == 'list':
            assert values[34:37] == values[71:74], 'batch native list FR saves changed'
    owner_callers(attribution.get('original_caller_manifests', []), image, entry, category, verifier)
    return entry, set(ops)
