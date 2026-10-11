"""Audit explicit callable-entry attribution without changing frozen body ranges."""
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def validate(owner, attribution, spans, corpus, image=None):
    """Require original BSR callers, a straight prefix, and complete image PCs."""
    image = image if image is not None else (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    kind = attribution.get('kind', 'bsr')
    if kind == 'vf3-controller-merge-bsr-v1':
        from callable_controller import validate_controller_merge
        return validate_controller_merge(owner, attribution, spans, corpus, image)
    if kind == 'vf3-motion-frame-bsr-v1':
        from callable_motion import validate_motion_frame
        return validate_motion_frame(owner, attribution, spans, corpus, image)
    if kind == 'vf3-fight-scene-table-v1':
        from callable_dispatch import validate_fight_scene
        return validate_fight_scene(owner, attribution, spans, corpus, image)
    if kind == 'vf3-input-literal-jsr-v1':
        from callable_literal import validate_input_literal
        return validate_input_literal(owner, attribution, spans, corpus, image)
    assert kind == 'bsr', 'unknown callable attribution contract'
    parent = int(attribution['entry'], 16)
    start = min(s for s, _ in spans)
    assert parent % 2 == 0 and 0 < start - parent <= 64, 'invalid callable prefix'
    assert any(s <= owner < e for s, e in spans), 'owner outside frozen body'

    def word(pc):
        offset = pc - 0x8c010000
        assert 0 <= offset <= len(image) - 2, 'PC outside original image'
        return struct.unpack_from('<H', image, offset)[0]

    callers = {int(site, 16) for site in attribution['call_sites']}
    assert len(callers) >= 2, 'need two distinct original callers'
    for pc in callers:
        assert pc % 2 == 0, 'unaligned caller'
        opcode = word(pc)
        displacement = opcode & 0xfff
        if displacement & 0x800:
            displacement -= 0x1000
        assert opcode >> 12 == 0xb and pc + 4 + displacement * 2 == parent, 'original BSR target mismatch'
        assert word(pc + 2) == 9, 'unsupported caller delay slot'
    ops = json.loads((Path(corpus) / f'f_{parent:08x}.ops.json').read_text())
    ops = {int(pc, 16) | 0x80000000: int(op, 16) for pc, op in ops.items()}
    for pc, opcode in ops.items():
        assert opcode == word(pc), f'captured opcode differs from original image at {pc:#x}'
    required = set(range(parent, start, 2))
    required.update(pc for s, e in spans for pc in range(s, e, 2))
    assert required <= ops.keys(), 'incomplete callable prefix or frozen body'
    # These straight-line SH-4 instructions cover loads, register moves,
    # immediate moves, FPSCR transfers and bank toggles. Fail closed for any
    # prefix requiring additional control-flow reasoning.
    for pc in range(parent, start, 2):
        opcode = word(pc)
        if opcode & 0xff0f == 0x2f06:
            register = (opcode >> 4) & 15
            assert register in (8, 9, 10, 11, 12, 13, 14), 'unsupported saved register'
            assert attribution.get('callee_save_prefix') == [f'r{register}'], 'undeclared saved prefix'
            assert start-parent == 2, 'only a single saved-register prefix is supported'
            restore = 0x60f6 | (register << 8)
            assert any(ops.get(pc) == restore for s,e in spans for pc in range(s,e,2)), 'missing register restoration'
            cases = (Path(corpus)/f'f_{parent:08x}.cases').read_text().splitlines()
            assert cases, 'missing native stack invariant evidence'
            for line in cases:
                values = [int(v,16) for v in line.split()[:74]]
                assert len(values)==74 and values[register]==values[37+register], 'saved register changed'
                assert values[15]==values[52], 'stack pointer changed'
            continue
        assert (opcode >> 12 in (0x6, 0xe) or opcode in
                (0x0009, 0x4c5a, 0x405a, 0xf3fd, 0xf20d)), 'unsupported prefix instruction'
    return parent, set(ops)
