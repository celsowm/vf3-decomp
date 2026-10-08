"""Original-entry triangle clipping inputs; expected outputs come from execution."""
import argparse
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
ENTRY = 0x8c04a320


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def fixture(variant, relocation=0, holdout=False):
    if relocation < 0 or relocation > 0x700000 or relocation % 4096:
        raise ValueError('relocation must be page aligned within fixture RAM')
    stream, attributes, output, stack = (address + relocation for address in
        (0x0c404000, 0x0c405000, 0x0c406040, 0x0c47f000))
    registers = {f'r{i}': variant * 17 + i for i in range(15)}
    threshold = .25 if holdout else 0.
    registers.update(r4=stream, r5=attributes, r6=output,
                     r7=bits(1.25 if holdout else 1.), r12=bits(threshold),
                     r15=stack, fpscr=0x40001)
    for i in range(16):
        registers[f'fr{i}'] = bits((i + variant % 7) * .125)
        # Identity x/y/z, with homogeneous w = y, to select all eight masks.
        registers[f'xf{i}'] = bits(1. if i in (0, 5, 10, 7) else 0.)
    words = {stream + offset: 0 for offset in range(0, 0x280, 4)}
    words.update({output + offset: 0 for offset in range(-64, 1024, 4)})
    words.update({stack + offset: variant * 31 + offset & 0xffffffff
                  for offset in range(-64, 64, 4)})
    words[stream] = 1  # One triangle; followed by a zero terminator.
    mask = variant % 8
    cursor = stream + 4
    for vertex in range(3):
        if (variant // 8) & (1 << vertex):
            # Relative records occupy eight stream bytes and point forward
            # from the next record to a separate 16-byte vertex payload.
            address = stream + 0x200 + vertex * 32
            words[cursor] = 0
            words[cursor + 4] = address - (cursor + 8)
            cursor += 8
        else:
            address = cursor
            cursor += 32
        # Inline x shares its low bit with the record flag. Use a finite,
        # nonzero float with that bit set, keeping reciprocals finite.
        words[address] = bits((1.25 if holdout else 1.) + vertex * .25) | 1
        magnitude = (1.5 if holdout else 1.) + (variant // 8) * .125
        words[address + 4] = bits(magnitude if mask & (4 >> vertex) else -magnitude)
        words[address + 8] = bits((vertex + 1) * (.375 if holdout else .25))
        words[address + 12] = bits(1.)
    # A positive final word with bit 7 clear takes the original count-reload
    # path, reads the next zero count, then rewinds eight bytes before exit.
    words[cursor] = 1 if variant & 64 else 0
    words[cursor + 4] = 0
    return registers, words


def generate(output, variants=128, relocation=0, holdout=False):
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    for pc, opcode in ((ENTRY, 0x4c5a), (0x8c04a32a, 0xeb00),
                       (0x8c04a446, 0x0023), (0x8c04a432, 0x76e0)):
        if struct.unpack_from('<H', image, pc - 0x8c010000)[0] != opcode:
            raise ValueError(f'original image contract changed at {pc:#x}')
    if not 64 <= variants <= 256:
        raise ValueError('variants must be 64..256')
    trigger = 0x8c0432e2
    lines = [f'entry 0x{trigger:08x} 0x{ENTRY:08x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed 0x{trigger:08x}')
        lines.extend((f'target 0x{trigger:08x} 0x{ENTRY & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}'))
        registers, words = fixture(variant, relocation, holdout)
        lines.extend(f'reg 0x{trigger:08x} {name} 0x{value:08x}'
                     for name, value in registers.items())
        lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}'
                     for address, value in sorted(words.items()))
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    output.with_suffix('.json').write_text(json.dumps(dict(
        advisory=True, entry=hex(ENTRY), variants=variants,
        relocation=hex(relocation), holdout=holdout,
        contract='One triangle, all eight threshold masks, inline/relative records, two terminators, finite inputs, isolated stack.'
    ), indent=1) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--relocation', type=lambda value: int(value, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    args = parser.parse_args()
    generate(args.out, args.variants, args.relocation, args.holdout)
