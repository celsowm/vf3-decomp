"""Seed the original 072076 vector-grid prologue with bounded finite grid inputs."""
import argparse
from pathlib import Path
import struct


def generate(output, variants, relocation=0, holdout=False, trigger=0x8c0432e2,
             parent=0x8c072076):
    descriptor, vertices = 0x0c404000 + relocation, 0x0c420000 + relocation
    counts = (2, 3, 5, 8, 9, 10) if holdout else (1, 2, 3, 4, 8, 9)
    palette = (-1.75, -0.25, 0.375, 1.25, 2.5, 3.75) if holdout else (-2., -1., 0., .5, 1., 2.)
    lines = ['# Original 072076 inputs only; expected outputs come from execution.',
             f'entry 0x{trigger:08x} 0x{parent:08x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed 0x{trigger:08x}')
        lines.extend((f'target 0x{trigger:08x} 0x{parent & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} fpscr 0x00040001',
                      f'reg 0x{trigger:08x} r4 0x{descriptor:08x}'))
        for reg in range(15):
            if reg != 4 and (parent == 0x8c072076 or reg not in (5, 6)):
                lines.append(f'reg 0x{trigger:08x} r{reg} 0x{(variant * 17 + reg) & 511:08x}')
        for bank in ('fr', 'xf'):
            for reg in range(16):
                bits = struct.unpack('<I', struct.pack('<f', palette[(variant + reg) % len(palette)]))[0]
                lines.append(f'reg 0x{trigger:08x} {bank}{reg} 0x{bits:08x}')
        words = {descriptor + offset: 0 for offset in range(0, 0xb4, 4)}
        words.update({descriptor + 4: vertices,
                      descriptor + 0x58: counts[variant % len(counts)],
                      descriptor + 0x5c: counts[(variant // len(counts)) % len(counts)],
                      descriptor + 0xb0: (0xda, 0xe9, 0)[variant % 3]})
        if parent != 0x8c072076:
            # 071140/070008 take the descriptor in r5 and a record pointer
            # in r6, walking backward by count*24 before traversing records.
            lines.extend((f'reg 0x{trigger:08x} r5 0x{descriptor:08x}',
                          f'reg 0x{trigger:08x} r6 0x{vertices + 128 * 24:08x}'))
            words[descriptor + 0x60] = counts[variant % len(counts)]
            for offset in range(0x60, 0xb0, 4):
                if offset == 0x60:
                    continue
                value = palette[(variant + offset // 4) % len(palette)]
                words[descriptor + offset] = struct.unpack('<I', struct.pack('<f', value))[0]
        # The original prologue computes count*24 stride. Each record has
        # two three-component vectors; reserve more than the largest grid.
        for record in range(256):
            row, column = divmod(record, 16)
            values = (float(column), float(row), palette[(variant + record) % len(palette)],
                      0., 1., 0.)
            for component, value in enumerate(values):
                words[vertices + record * 24 + component * 4] = struct.unpack('<I', struct.pack('<f', value))[0]
        lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}'
                     for address, value in sorted(words.items()))
    output.write_text('\n'.join(lines) + '\n')
    print(f'{variants} bounded finite grid inputs; {len(lines)} fixture lines')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--relocation', type=lambda s: int(s, 16), default=0)
    parser.add_argument('--holdout', action='store_true')
    parser.add_argument('--parent', type=lambda s: int(s, 16), default=0x8c072076,
                        choices=(0x8c072076, 0x8c071140, 0x8c070008))
    args = parser.parse_args()
    generate(args.out, args.variants, args.relocation, args.holdout, parent=args.parent)
