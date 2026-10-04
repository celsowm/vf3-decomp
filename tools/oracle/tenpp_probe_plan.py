"""Rotate typed input fixtures through a rollback-safe original interpreter probe."""
import argparse
from pathlib import Path
from pointer_seeds import fixture


def generate(watch, output, trigger, variants, relocation=0, mode='zero', scalars=(),
             float_vectors=False, fpscr=None, bounded_arguments=False,
             floating_arguments=False, alternate_fields=False, holdout_inputs=False,
             global_fields=False, scalar_fields=False, field_crosses=False,
             random_fields=False):
    roots = [int(line.split()[1], 16) for line in watch.read_text().splitlines()
             if line.startswith('pc ')]
    if not roots:
        raise ValueError('empty watch')
    fixtures = {entry: fixture(entry, mode, global_fields, random_fields) for entry in roots}
    alternatives = {name: {entry: fixture(entry, name, global_fields, random_fields) for entry in roots}
                    for name in ('one', 'open')} if alternate_fields else {}

    def relocated(value):
        return value + relocation if 0x0c400000 <= value < 0x0c480000 else value

    lines = ['# Typed original-image inputs; expected results come only from execution.',
             f'entry 0x{trigger:08x} 0x{roots[0]:08x}']
    first = True
    palette = (-3.0, -0.75, 0.25, 0.75, 1.5, 3.0, 8.0, 24.0) if holdout_inputs else (-2.0, -1.0, 0.0, 0.5, 1.0, 2.0, 10.0, 50.0)
    for variant in range(variants):
        for entry in roots:
            if not first:
                lines.append(f'seed 0x{trigger:08x}')
            first = False
            lines += [f'target 0x{trigger:08x} 0x{entry & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}']
            if fpscr is not None:
                lines.append(f'reg 0x{trigger:08x} fpscr 0x{fpscr:08x}')
            field_modes = ('zero', 'one', 'open', 'vectors') + tuple(f'scalar{n}' for n in (2,3,4,5,6,7,8,16)) if scalar_fields else ('zero', 'one', 'open', 'vectors')
            field_mode = field_modes[(variant >> 3) % len(field_modes)] if alternate_fields else mode
            template_mode = 'one' if field_mode.startswith('scalar') else field_mode
            registers, words = (alternatives[template_mode][entry] if template_mode in alternatives else fixtures[entry])[:2]
            words = dict(words)
            if field_mode.startswith('scalar'):
                scalar = int(field_mode[6:])
                words = {addr: value * scalar if value and not (value & 0xfefefefe) else value
                         for addr, value in words.items()}
            if field_crosses and variant >= 128:
                # Change one scalar subfield independently while keeping its
                # neighboring selectors and inferred pointers well formed.
                zero = fixtures[entry][1]
                one = alternatives['one'][entry][1]
                fields = [(addr, bit) for addr, value in sorted(one.items())
                          if value and not (value & 0xfefefefe) and not zero.get(addr)
                          and addr % 4096 != 252
                          for bit in (0, 8, 16, 24) if value & (1 << bit)]
                if fields:
                    phase = (variant - 128) % 8
                    template_mode = 'open' if phase >= 4 else 'one'
                    registers, template = alternatives[template_mode][entry][:2]
                    words = dict(template)
                    addr, bit = fields[((variant - 128) // 8) % len(fields)]
                    mask = 0xffffffff if one[addr] == 1 else 0xff << bit
                    words[addr] = (words.get(addr, 0) & ~mask) | ((phase % 4) << bit)
            if random_fields and variant >= 128:
                import random
                import struct
                rng = random.Random((entry << 16) ^ variant ^ (0x4f1bbcdc if holdout_inputs else 0))
                registers, baseline, types = fixtures[entry]
                words = dict(baseline)
                protected = {addr for addr, value in words.items()
                             if 0x0c000000 <= (value & 0x1fffffff) < 0x10000000}
                integers = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16)
                for addr in types['scalars']:
                    if addr in words and addr not in protected:
                        words[addr] = rng.choice(integers)
                for addr, units in types['narrow'].items():
                    if addr in words and addr not in protected:
                        for bit in (0, 8, 16, 24):
                            if units & (1 << bit):
                                words[addr] = (words[addr] & ~(0xff << bit)) | (rng.choice(integers) << bit)
                for addr in types['floats']:
                    if addr in words and addr not in protected:
                        words[addr] = struct.unpack('<I', struct.pack('<f', rng.choice(palette)))[0]
                for addr, masks in types['flags'].items():
                    if addr in words and addr not in protected:
                        words[addr] = 0
                        for mask in masks:
                            if rng.randrange(2):
                                words[addr] |= mask
                for addr in types['counts']:
                    if addr in words and addr not in protected:
                        words[addr] = rng.randrange(1, 5)
            if float_vectors or field_mode == 'vectors':
                import struct
                values = palette
                pages = {value for value in (*words.values(), *registers.values())
                         if 0x0c400000 <= value < 0x0c480000 and value % 4096 == 0}
                for page in pages:
                    for component, offset in enumerate((4, 8, 12)):
                        if words.get(page + offset) == 0:
                            words[page + offset] = struct.unpack('<I', struct.pack(
                                '<f', values[(variant + component) & 7]))[0]
            lines += [f'reg 0x{trigger:08x} r{reg} 0x{relocated(value):08x}'
                      for reg, value in sorted(registers.items())]
            if bounded_arguments:
                lines += [f'reg 0x{trigger:08x} r{reg} 0x{(variant + reg * 13 + (256 if holdout_inputs else 0)) & (7 if reg < 8 else 511):08x}'
                          for reg in range(15) if reg not in registers]
            if floating_arguments:
                import struct
                lines += [f'reg 0x{trigger:08x} {bank}{reg} 0x' +
                          f'{struct.unpack("<I", struct.pack("<f", palette[(variant + reg) & 7]))[0]:08x}'
                          for bank in ('fr', 'xf') for reg in range(16)]
            lines += [f'reg 0x{trigger:08x} r{reg} 0x{variant & 7:08x}' for reg in scalars]
            lines += [f'ram 0x{trigger:08x} 0x{relocated(addr):08x} 0x{relocated(value):08x}'
                      for addr, value in sorted(words.items())]
    output.write_text('\n'.join(lines) + '\n')
    print(f'{len(roots)} roots, {variants} rounds, {len(lines)} fixture lines')


if __name__ == '__main__':
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c063d36)
    ap.add_argument('--variants', type=int, default=64)
    ap.add_argument('--relocation', type=lambda x: int(x, 16), default=0)
    ap.add_argument('--mode', choices=('zero', 'open', 'one'), default='zero')
    ap.add_argument('--scalar-register', action='append', type=int, default=[],
                    help='explicit scalar argument register varied over 0..7')
    ap.add_argument('--float-vectors', action='store_true',
                    help='finite coordinates at +4/+8/+12 of nested fixture pages')
    ap.add_argument('--fpscr', type=lambda x: int(x, 16),
                    help='explicit floating point calling mode for the probe')
    ap.add_argument('--bounded-arguments', action='store_true',
                    help='bounded argument values 0..7 and preserved-register values 0..511')
    ap.add_argument('--floating-arguments', action='store_true',
                    help='finite floating point input registers in both banks')
    ap.add_argument('--alternate-fields', action='store_true',
                    help='rotate zero, scalar-one, open-flag and finite-vector fixtures')
    a = ap.parse_args()
    generate(a.watch, a.out, a.trigger, a.variants, a.relocation, a.mode,
             a.scalar_register, a.float_vectors, a.fpscr, a.bounded_arguments,
             a.floating_arguments, a.alternate_fields)
