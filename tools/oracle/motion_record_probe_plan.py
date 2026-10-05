"""Generate bounded original motion-record walker inputs, never outputs."""
import argparse
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
PARENT = 0x8c0c1bd0
CHILD = 0x8c0c1bec


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def fixture(variant, relocation=0, holdout=False):
    obj, records, stack = (address + relocation for address in
                           (0x0c420000, 0x0c430000, 0x0c47f000))
    regs = {'r4': obj, 'r15': stack, 'fpscr': 0x40001}
    words = {obj + offset: 0 for offset in range(0, 64, 4)}
    words[obj + 12] = records
    words[obj + 36] = ((variant % 8) << 16)
    # Original code advances exactly 120 records of 68 bytes. Keep all
    # inactive except one: natural all-active inputs exceed the oracle cap.
    words.update({records + offset: 0 for offset in range(0, 120 * 68, 4)})
    record = records + 68 * ((variant * (13 if holdout else 7)) % 120)
    words[record] = 1 if variant % 8 else 0
    palette = (-3., -.75, .25, 1.5, 9., 64., 512.) if holdout else (-2., -1., 0., .5, 2., 16., 256., 496.)
    for offset in (4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64):
        words[record + offset] = bits(palette[(variant // 4 + offset // 4) % len(palette)])
    words.update({0x0c2a0140: (variant % 64) + (3 if holdout else 0),
                  0x0c2a0144: obj if variant & 1 else obj + 44})
    # Saved caller words are input state too, with no invented expected state.
    words.update({stack + offset: (variant * 97 + offset) & 0xffffffff
                  for offset in range(0, 64, 4)})
    return regs, words


def generate(output, variants=128, relocation=0, holdout=False):
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    for address, expected in ((PARENT, 0x2fe6), (CHILD, 0x4f22),
                              (0x8c0c1d64, 0x7e44)):
        if struct.unpack_from('<H', image, address - 0x8c010000)[0] != expected:
            raise ValueError(f'original image contract mismatch at {address:#x}')
    if not 64 <= variants <= 1024:
        raise ValueError('variants must be 64..1024')
    trigger = 0x8c0432e2
    lines = [f'entry 0x{trigger:08x} 0x{PARENT:08x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed 0x{trigger:08x}')
        lines.extend((f'target 0x{trigger:08x} 0x{PARENT & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}'))
        regs, words = fixture(variant, relocation, holdout)
        lines.extend(f'reg 0x{trigger:08x} {name} 0x{value:08x}' for name, value in regs.items())
        lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}'
                     for address, value in sorted(words.items()))
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    output.with_suffix('.json').write_text(json.dumps(dict(advisory=True,
        parent=hex(PARENT), child=hex(CHILD), variants=variants,
        relocation=hex(relocation), holdout=holdout,
        contract='120 original 68-byte records, at most one active; real table helpers.'), indent=1) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--relocation', type=lambda value: int(value, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    args = parser.parse_args()
    generate(args.out, args.variants, args.relocation, args.holdout)
