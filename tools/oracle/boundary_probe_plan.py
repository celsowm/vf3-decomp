"""Generate original-prologue matrix and packed-control boundary fixtures.

Expected outputs come exclusively from original execution. The scratch matrix,
index bytes and isolated stack live in the campaign's rollback fixture pool.
"""
import argparse
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / 'extract/gamedata/1ST_READ.BIN'
PARENTS = {'matrix': 0x8c03be20, 'controls': 0x8c05d2d0}
CHILDREN = {'matrix': 0x8c03be34, 'controls': 0x8c05d2dc}


def validate_image(image):
    data = Path(image).read_bytes()
    patterns = {
        0x8c03be20: (0x2fe6, 0x2448, 0x2fd6, 0x2fc6, 0x6c53),
        0x8c03be8a: (0xf38d, 0xf434, 0x8b01, 0xa074, 0x0009),
        0x8c05d2d0: (0x2fe6, 0x2fd6, 0x2fc6, 0x2fb6, 0x2fa6, 0x2f96),
        0x8c05d306: (0x53fb, 0x2338, 0x8900, 0xec02, 0x50fc, 0x8801),
    }
    for pc, words in patterns.items():
        offset = pc - 0x8c010000
        actual = data[offset:offset + 2 * len(words)]
        if actual != struct.pack('<' + 'H' * len(words), *words):
            raise ValueError(f'original input-contract pattern changed at {pc:#x}')


def fixture(family, variant, relocation=0, holdout=False):
    if family not in PARENTS:
        raise ValueError('unknown fixture family')
    if relocation < 0 or relocation > 0x700000 or relocation % 4096:
        raise ValueError('relocation must be page aligned within RAM')
    matrix, indices, stack = (address + relocation for address in
                               (0x0c404000, 0x0c406000, 0x0c47f000))
    registers = {f'r{i}': (variant * 17 + i * 3 + (513 if holdout else 0)) & 1023
                 for i in range(15)}
    registers.update(r15=stack, fpscr=0x40001)
    palette = (-1.75, -0.25, 0.375, 1.25, 2.5, 3.75) if holdout else (-2., -1., 0., .5, 1., 2.)
    for bank in ('fr', 'xf'):
        for i in range(16):
            registers[f'{bank}{i}'] = struct.unpack('<I', struct.pack(
                '<f', palette[(variant + i) % len(palette)]))[0]
    # Clear scratch only, including space for saves and extra call arguments.
    words = {stack + offset: 0 for offset in range(-256, 32, 4)}
    if family == 'matrix':
        registers.update(r4=matrix, r5=indices)
        # Finite diagonal/permuted matrices and deliberately singular columns.
        # The zero column exercises the original fcmp/eq early return at be90.
        scales = (0.75, 1.25, 2.5, -3.5) if holdout else (0.5, 1., 2., -4.)
        permutation = variant % 4
        singular = (variant // 4) % 2 == 0
        for row in range(4):
            for column in range(4):
                value = scales[(variant // 8 + row) % 4] if column == (row + permutation) % 4 else 0.
                if singular and column == 0:
                    value = 0.
                words[matrix + 16 * row + 4 * column] = struct.unpack('<I', struct.pack('<f', value))[0]
        words.update({indices + offset: 0 for offset in range(0, 16, 4)})
    else:
        # The prologue saves six GPRs. After PR and 16-byte locals, its
        # @(44,sp)/@(48,sp) accesses address the caller's stack +0/+4.
        domain = (0, 2, 5, 9) if holdout else (0, 1, 3, 7)
        registers.update({f'r{i}': domain[(variant // (1 << (i - 4))) % 4]
                          for i in range(4, 8)})
        words[stack] = int(bool(variant & 16))
        words[stack + 4] = (variant // 32) % 3
        words.update({0x0c16caf0: (variant * (7 if holdout else 3)) & 255,
                      0x0c16cdc4: (variant // 3) % 2,
                      0x0c16cea0: 32 + (variant // 2) % 5,
                      0x0c16ca90: 32 if variant & 1 else 0,
                      0x0c16cee4: 0x2468ace0 if holdout else 0x13579bdf})
    return registers, words


def generate(output, family, variants=256, relocation=0, holdout=False,
             trigger=0x8c0432e2, image=IMAGE):
    if not 64 <= variants <= 1024:
        raise ValueError('variants must be 64..1024')
    validate_image(image)
    parent = PARENTS[family]
    lines = ['# Original inputs only; rollback protects game RAM and registers.',
             f'entry 0x{trigger:08x} 0x{parent:08x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed 0x{trigger:08x}')
        lines.extend((f'target 0x{trigger:08x} 0x{parent & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}'))
        registers, words = fixture(family, variant, relocation, holdout)
        lines.extend(f'reg 0x{trigger:08x} {name} 0x{value:08x}'
                     for name, value in registers.items())
        lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}'
                     for address, value in sorted(words.items()))
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    output.with_suffix('.json').write_text(json.dumps(dict(
        advisory=True, family=family, parent=hex(parent), child=hex(CHILDREN[family]),
        variants=variants, relocation=hex(relocation), holdout=holdout,
        contract='Finite 4x4 matrix/index buffer or integer arguments and two caller stack words; isolated rollback stack.'
    ), indent=1) + '\n')
    print(f'{family}: {variants} original-prologue input variants -> {output}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--family', choices=PARENTS, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=256)
    parser.add_argument('--relocation', type=lambda value: int(value, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    parser.add_argument('--image', type=Path, default=IMAGE)
    args = parser.parse_args()
    generate(args.out, args.family, args.variants, args.relocation, args.holdout, image=args.image)


if __name__ == '__main__':
    main()
