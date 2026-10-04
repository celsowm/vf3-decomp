"""Rotate typed input fixtures through a rollback-safe original interpreter probe."""
import argparse
from pathlib import Path
from pointer_seeds import fixture


def generate(watch, output, trigger, variants, relocation=0, mode='zero', scalars=(),
             float_vectors=False, fpscr=None, bounded_arguments=False,
             floating_arguments=False, alternate_fields=False):
    roots = [int(line.split()[1], 16) for line in watch.read_text().splitlines()
             if line.startswith('pc ')]
    if not roots:
        raise ValueError('empty watch')
    fixtures = {entry: fixture(entry, mode) for entry in roots}
    alternatives = {name: {entry: fixture(entry, name) for entry in roots}
                    for name in ('one', 'open')} if alternate_fields else {}

    def relocated(value):
        return value + relocation if 0x0c400000 <= value < 0x0c480000 else value

    lines = ['# Typed original-image inputs; expected results come only from execution.',
             f'entry 0x{trigger:08x} 0x{roots[0]:08x}']
    first = True
    for variant in range(variants):
        for entry in roots:
            if not first:
                lines.append(f'seed 0x{trigger:08x}')
            first = False
            lines += [f'target 0x{trigger:08x} 0x{entry & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}']
            if fpscr is not None:
                lines.append(f'reg 0x{trigger:08x} fpscr 0x{fpscr:08x}')
            field_mode = ('zero', 'one', 'open', 'vectors')[(variant >> 3) % 4] if alternate_fields else mode
            registers, words = alternatives[field_mode][entry] if field_mode in alternatives else fixtures[entry]
            words = dict(words)
            if float_vectors or field_mode == 'vectors':
                import struct
                values = (-2.0, -1.0, 0.0, 0.5, 1.0, 2.0, 10.0, 50.0)
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
                lines += [f'reg 0x{trigger:08x} r{reg} 0x{(variant + reg * 13) & (7 if reg < 8 else 511):08x}'
                          for reg in range(15) if reg not in registers]
            if floating_arguments:
                import struct
                palette = (-2.0, -1.0, 0.0, 0.5, 1.0, 2.0, 10.0, 50.0)
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
