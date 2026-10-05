"""Exercise the original PVR word-store helper; no expected outputs or code patches."""
import argparse
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ENTRY = 0x8c060d14
TRIGGER = 0x8c0432e2


def fixture(variant, offset=0xe4, relocation=0, holdout=False):
    # A permutation of uint32 values makes every original helper invocation
    # distinct. Acceptance uses a different permutation and a relocated stack.
    value = (variant * (0x9e3779b1 if holdout else 0x45d9f3b) +
             (0x87654321 if holdout else 0x12345678)) & 0xffffffff
    return {'r4': offset, 'r5': value, 'r15': 0x0c47f000 + relocation,
            'fpscr': 0x40001}


def generate(output, variants=128, offset=0xe4, relocation=0, holdout=False):
    if not 64 <= variants <= 1024:
        raise ValueError('variants must be 64..1024')
    if offset not in (0xe4, 0xe8, 0x400000e4):
        raise ValueError('only TEXT_CONTROL, adjacent and store-queue alias controls are supported')
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    actual = struct.unpack_from('<5H', image, ENTRY - 0x8c010000)
    if actual != (0xd344, 0x343c, 0x2452, 0x000b, 0xe001):
        raise ValueError('original PVR word-store helper mismatch')
    if struct.unpack_from('<I', image, 0x8c060e28 - 0x8c010000)[0] != 0xa05f8000:
        raise ValueError('original PVR base literal mismatch')
    lines = [f'entry 0x{TRIGGER:08x} 0x{ENTRY:08x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed 0x{TRIGGER:08x}')
        lines.extend((f'target 0x{TRIGGER:08x} 0x{ENTRY & 0x1fffffff:08x}',
                      f'reg 0x{TRIGGER:08x} pr 0x{(TRIGGER + 2) & 0x1fffffff:08x}'))
        lines.extend(f'reg 0x{TRIGGER:08x} {reg} 0x{value:08x}'
                     for reg, value in fixture(variant, offset, relocation, holdout).items())
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    output.with_suffix('.json').write_text(json.dumps(dict(advisory=True,
        entry=hex(ENTRY), variants=variants, offset=hex(offset),
        relocation=hex(relocation), holdout=holdout,
        contract='Original five-instruction PVR word store; real device handler.'), indent=1) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--offset', type=lambda v: int(v, 0), default=0xe4)
    parser.add_argument('--relocation', type=lambda v: int(v, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    args = parser.parse_args()
    generate(args.out, args.variants, args.offset, args.relocation, args.holdout)
