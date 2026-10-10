"""Narrow original scene-table attribution; no generic indirect-call exemption.

The fixed dispatcher instruction contract is replayed against original capsule
inputs. Complete ordered prefix/restore traces and native save invariants are
required separately. This does not qualify new callback or prefix shapes.
"""
import hashlib
import json
from pathlib import Path
import struct

from oracle.capsules import records

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x8c010000
DISPATCH = 0x8c0968d0
PARENT = 0x8c099060
OWNER = 0x8c099070
TABLE = 0x0c10baa8
SCENE = 0x0c29b864
DISPATCH_OPS = (0xd418, 0x7ffc, 0x5343, 0x73ff, 0x1433,
                0x844a, 0x650c, 0x6053, 0x8048, 0xd215,
                0x635b, 0x4508, 0x423d, 0x2422, 0xd013,
                0x035e, 0x6233, 0x2f32, 0x422b, 0x7f04)
PREFIX_OPS = (0x2fe6, 0x2fd6, 0xdd45, 0x9077, 0xd443,
              0x05de, 0xe029, 0x004c, 0x4f22)
RESTORE_OPS = (0x4f26, 0xd30f, 0x6df6, 0x432b, 0x6ef6)


def canonical(pc):
    return pc | 0x80000000


def image_bytes(image, address, size):
    offset = canonical(address) - BASE
    assert 0 <= offset <= len(image) - size, 'address outside original image'
    return image[offset:offset + size]


def checked_reference(ref):
    path = Path(ref['path'])
    path = path if path.is_absolute() else ROOT / path
    assert hashlib.sha256(path.read_bytes()).hexdigest() == ref['sha256'], 'changed attribution evidence'
    return path


def captured_bytes(sample, address, size, after=False):
    address &= 0x1fffffff
    result = bytearray()
    for at in range(address, address + size):
        page = next((p for p in sample['pages'] if p[0] <= at < p[0] + len(p[1])), None)
        assert page is not None, 'missing original caller RAM'
        result.append(page[2 if after else 1][at - page[0]])
    return bytes(result)


def verify_dispatch_sample(sample, image):
    """Prove the actual loaded target and balanced original save sequence."""
    assert not sample['flags'], 'invalid dispatch invocation'
    assert canonical(sample['entry']) == DISPATCH, 'wrong original caller entry'
    before = struct.unpack(f'<{sample["nstate"]}I', sample['before'])
    after = struct.unpack(f'<{sample["nstate"]}I', sample['after'])
    assert before[13:16] == after[13:16], 'dispatch save/stack invariant failed'
    assert sample['exitpc'] == before[16], 'dispatch return differs from original PR'
    ops = [(canonical(pc), op) for pc, op in sample['ops']]
    for pc, op in ops:
        assert image_bytes(image, pc, 2) == struct.pack('<H', op), 'nonoriginal dispatch opcode'
    expected = [(DISPATCH + 2*i, op) for i, op in enumerate(DISPATCH_OPS)]
    assert ops[:len(expected)] == expected, 'incomplete or reordered dispatcher'
    # MOV.L's original PC-relative pools establish the scene and table bases.
    for pc, op, wanted in ((DISPATCH, DISPATCH_OPS[0], SCENE),
                           (DISPATCH + 28, DISPATCH_OPS[14], TABLE)):
        pool = ((pc + 4) & ~3) + 4*(op & 255)
        assert image_bytes(image, pool, 4) == struct.pack('<I', wanted), 'wrong dispatcher literal'
        assert captured_bytes(sample, pool, 4) == image_bytes(image, pool, 4), 'patched dispatcher literal'
    index = captured_bytes(sample, SCENE + 10, 1)[0]
    assert index == 55, 'wrong original scene index'
    slot = TABLE + 4*index
    target = struct.unpack('<I', captured_bytes(sample, slot, 4))[0]
    assert canonical(target) == PARENT, 'loaded scene target mismatch'
    assert captured_bytes(sample, slot, 4) == captured_bytes(sample, slot, 4, True) == image_bytes(image, slot, 4), 'modified original scene slot'
    # JMP @r2 and its stack adjustment must immediately reach the loaded target.
    prefix = [(PARENT + 2*i, op) for i, op in enumerate(PREFIX_OPS)]
    assert ops[len(expected):len(expected)+len(prefix)] == prefix, 'missing original saved prefix'
    for pc,op in expected + prefix:
        if op >> 12 in (0x9,0xd):
            size = 2 if op >> 12 == 0x9 else 4
            pool = pc+4+2*(op&255) if size == 2 else ((pc+4)&~3)+4*(op&255)
            assert captured_bytes(sample,pool,size) == captured_bytes(sample,pool,size,True) == image_bytes(image,pool,size), 'modified prefix/dispatcher pool'
    restoration = [(0x8c09914e + 2*i, op) for i, op in enumerate(RESTORE_OPS)]
    positions = [i for i, pair in enumerate(ops) if pair == restoration[0]]
    assert len(positions) == 1, 'missing or repeated root restoration'
    at = positions[0]
    assert at >= len(expected)+len(prefix) and ops[at:at+5] == restoration, 'wrong save restoration order'
    assert at+5 < len(ops) and ops[at+5][0] == 0x8c097ff4, 'missing original tail transfer'
    return hashlib.sha256(sample['before'] + b''.join(struct.pack('<I', base)+a for base,a,z in sample['pages'])).hexdigest()


def validate_fight_scene(owner, attribution, spans, corpus, image):
    assert owner == OWNER and int(attribution['entry'], 16) == PARENT, 'unsupported scene callable'
    assert min(s for s,e in spans) == OWNER and any(s <= owner < e for s,e in spans), 'wrong frozen scene owner'
    assert attribution.get('callee_save_prefix') == ['r14', 'r13'], 'wrong declared save order'
    assert attribution.get('call_sites') == ['0x8c0968f4'], 'wrong declared dispatcher edge'
    assert attribution.get('table') == hex(TABLE) and attribution.get('index') == 55, 'wrong declared scene slot'
    ops = json.loads((Path(corpus)/f'f_{PARENT:08x}.ops.json').read_text())
    ops = {canonical(int(pc,16)): int(op,16) for pc,op in ops.items()}
    for pc,op in ops.items():
        assert image_bytes(image,pc,2) == struct.pack('<H',op), 'nonoriginal callable opcode'
    required = set(range(PARENT, OWNER, 2)) | {pc for s,e in spans for pc in range(s,e,2)}
    assert required <= ops.keys(), 'incomplete callable prefix or frozen body'
    for i,op in enumerate(PREFIX_OPS):
        assert ops.get(PARENT+2*i) == op, 'unsupported scene prefix'
    for i,op in enumerate(RESTORE_OPS):
        assert ops.get(0x8c09914e+2*i) == op, 'unsupported scene restoration'
    cases = (Path(corpus)/f'f_{PARENT:08x}.cases').read_text().splitlines()
    assert cases, 'missing native save invariant evidence'
    for line in cases:
        values = [int(v,16) for v in line.split()[:74]]
        assert len(values) == 74 and values[13:16] == values[50:53], 'callable save/stack invariant failed'
    require_original_scenarios(attribution['original_dispatch_manifests'], image, verify_dispatch_sample)
    return PARENT, set(ops)


def require_original_scenarios(references, image, verifier):
    """Validate pinned process inputs and original-only caller records."""
    states, fingerprints = set(), set()
    for ref in references:
        manifest = json.loads(checked_reference(ref).read_text())
        assert manifest['passed'] and manifest['execution'] == 'original_sh4', 'not original dispatcher evidence'
        assert manifest['mode'] == 'nonrollback_one_shot', 'wrong dispatcher capture mode'
        assert any(path.endswith('.exe') for path in manifest['provenance']), 'missing original executable provenance'
        images = [digest for path,digest in manifest['provenance'].items() if path.endswith('1ST_READ.BIN')]
        assert images == [hashlib.sha256(image).hexdigest()], 'wrong original image provenance'
        for path,digest in manifest['provenance'].items():
            # Historical source hashes remain valid provenance; source archives
            # seal those versions. These execution inputs must still exist unchanged.
            if path.endswith(('.exe', '.state', '.json', '1ST_READ.BIN')):
                checked_reference(dict(path=path,sha256=digest))
        for run in manifest['runs']:
            assert run['passed'] and run['returncode'] == 0, 'incomplete original dispatch run'
            capsule = checked_reference(dict(path=run['capsule'],sha256=run['capsule_sha256']))
            samples = list(records(capsule))
            assert len(samples) == 1, 'ambiguous dispatch invocation'
            fingerprints.add(verifier(samples[0], image))
            state = Path(run['state']); state = state if state.is_absolute() else ROOT/state
            digest = hashlib.sha256(state.read_bytes()).hexdigest()
            assert manifest['provenance'].get(run['state']) == digest, 'missing/changed original state provenance'
            states.add(digest)
    assert len(states) >= 2 and len(fingerprints) >= 2, 'need two distinct original dispatch scenarios and inputs'
