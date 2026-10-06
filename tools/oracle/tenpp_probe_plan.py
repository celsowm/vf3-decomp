"""Rotate typed input fixtures through a rollback-safe original interpreter probe."""
import argparse
import math
from pathlib import Path
from pointer_seeds import fixture
from inspect_capsule import REGISTER_NAMES
from comparison_inputs import boundary_palette, replace_narrow


def override_sequence(value, label):
    """Normalize scalar/list inputs or an explicit strided fixture dimension."""
    if isinstance(value, dict):
        if 'values' not in value or set(value) - {'values', 'stride', 'phase'}:
            raise ValueError(f'invalid override dimension for {label}')
        stride, phase = value.get('stride', 1), value.get('phase', 0)
        value = value['values']
    else:
        stride, phase = 1, 0
    if not isinstance(stride, int) or isinstance(stride, bool) or stride < 1:
        raise ValueError(f'override stride must be a positive integer for {label}')
    if not isinstance(phase, int) or isinstance(phase, bool) or phase < 0:
        raise ValueError(f'override phase must be a nonnegative integer for {label}')
    values = value if isinstance(value, list) else [value]
    values = [int(item, 0) if isinstance(item, str) else item for item in values]
    if not values or any(not isinstance(item, int) or not 0 <= item <= 0xffffffff for item in values):
        raise ValueError(f'override values must be nonempty uint32 integers for {label}')
    return values, stride, phase


def override_value(sequence, variant):
    values, stride, phase = sequence
    return values[(variant // stride + phase) % len(values)]


def generate(watch, output, trigger, variants, relocation=0, mode='zero', scalars=(),
             float_vectors=False, fpscr=None, bounded_arguments=False,
             floating_arguments=False, alternate_fields=False, holdout_inputs=False,
             global_fields=False, scalar_fields=False, field_crosses=False,
             random_fields=False, expanded_inputs=False, preserve_fields=False,
             register_overrides=None, memory_overrides=None, comparison_boundaries=False,
             float_palette=None):
    if float_palette is not None:
        float_palette = tuple(float(value) for value in float_palette)
        if len(float_palette) != 8 or not all(math.isfinite(value) and abs(value) <= 3.4028234663852886e38
                                             for value in float_palette):
            raise ValueError('float palette must contain eight finite float32 values')
    roots = [int(line.split()[1], 16) for line in watch.read_text().splitlines()
             if line.startswith('pc ')]
    if not roots:
        raise ValueError('empty watch')
    fixtures = {entry: fixture(entry, mode, global_fields, random_fields or comparison_boundaries) for entry in roots}
    alternatives = {name: {entry: fixture(entry, name, global_fields, random_fields or comparison_boundaries) for entry in roots}
                    for name in ('one', 'open')} if alternate_fields else {}
    overrides = {}
    for entry_text, fields in (register_overrides or {}).items():
        entry = int(entry_text, 0) if isinstance(entry_text, str) else int(entry_text)
        overrides[entry] = {}
        for register_text, values in fields.items():
            name = str(register_text).lower()
            if name not in REGISTER_NAMES:
                name = f'r{int(name, 0)}'
            register = REGISTER_NAMES.get(name, -1)
            sequence = override_sequence(values, f'{entry:#x} {register_text}')
            if not (0 <= register < 15 or 21 <= register < 53):
                raise ValueError(f'invalid register override for {entry:#x}: {register_text}')
            overrides[entry][name] = sequence
    ram_overrides = {}
    for entry_text, fields in (memory_overrides or {}).items():
        entry = int(entry_text, 0) if isinstance(entry_text, str) else int(entry_text)
        ram_overrides[entry] = {}
        for address_text, values in fields.items():
            address = int(address_text, 0) if isinstance(address_text, str) else int(address_text)
            sequence = override_sequence(values, f'{entry:#x} at {address:#x}')
            if address % 4 or not 0x0c000000 <= address < 0x0d000000:
                raise ValueError(f'invalid RAM override address for {entry:#x}: {address:#x}')
            ram_overrides[entry][address] = sequence

    def relocated(value):
        return value + relocation if 0x0c400000 <= value < 0x0c480000 else value

    lines = ['# Typed original-image inputs; expected results come only from execution.',
             f'entry 0x{trigger:08x} 0x{roots[0]:08x}']
    first = True
    palette = (-3.0, -0.75, 0.25, 0.75, 1.5, 3.0, 8.0, 24.0) if holdout_inputs else (-2.0, -1.0, 0.0, 0.5, 1.0, 2.0, 10.0, 50.0)
    if float_palette is not None:
        palette = float_palette
    for variant in range(variants):
        for entry in roots:
            active_palette = palette
            if expanded_inputs and entry == 0x8c08f8de:
                active_palette = palette + (-1e-9, 1e-9, -1e-7, 1e-7)
            if expanded_inputs and entry in (0x8c084c64, 0x8c0877ac):
                active_palette = palette + (-0.2, -0.1, 0.01, 0.05, 0.1, 0.15, 0.16, 0.18, 0.19, 0.2, 0.21, 0.24, 0.3, 0.4, 0.7, 0.9)
            if expanded_inputs and entry == 0x8c0877ac:
                # Original comparisons load 0.001 and a tiny positive
                # threshold from 0878d0/0878d8, then clamp against -1.
                active_palette += (-1e-9, 0.0, 1e-9, 1e-5, 0.0001, 0.0005,
                                   0.0009, 0.001, 0.0011)
            if not first:
                lines.append(f'seed 0x{trigger:08x}')
            first = False
            lines += [f'target 0x{trigger:08x} 0x{entry & 0x1fffffff:08x}',
                      f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}']
            if fpscr is not None:
                lines.append(f'reg 0x{trigger:08x} fpscr 0x{fpscr:08x}')
            field_modes = ('zero', 'one', 'open', 'vectors') + tuple(f'scalar{n}' for n in (2,3,4,5,6,7,8,16)) if scalar_fields else ('zero', 'one', 'open', 'vectors')
            field_mode = field_modes[(variant >> 3) % len(field_modes)] if alternate_fields and not preserve_fields else mode
            template_mode = 'one' if field_mode.startswith('scalar') else field_mode
            registers, words = (alternatives[template_mode][entry] if template_mode in alternatives else fixtures[entry])[:2]
            registers = dict(registers)
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
                registers = dict(registers)
                words = dict(baseline)
                if preserve_fields:
                    # Keep the inferred memory contract while independently
                    # varying argument registers and both floating banks.
                    types = {**types, 'scalars': (), 'narrow': {}, 'floats': (),
                             'flags': {}, 'counts': (), 'nullable_args': (),
                             'nullable_fields': ()}
                protected = {addr for addr, value in words.items()
                             if 0x0c000000 <= (value & 0x1fffffff) < 0x10000000}
                integers = tuple(range(32)) if expanded_inputs else (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16)
                for addr in types['scalars']:
                    if addr in words and addr not in protected:
                        domain = (-1800, -20, -1, 0, 1, 19, 20, 21, 100, 1800, 36000, 36001, 72000) if expanded_inputs and entry == 0x8c0698fc else ((0, 1, 7, 84, 85, 100, 101, 119, 120, 121) if expanded_inputs and entry == 0x8c08d618 else integers)
                        words[addr] = rng.choice(domain) & 0xffffffff
                for addr, units in types['narrow'].items():
                    if addr in words and addr not in protected:
                        for bit in (0, 8, 16, 24):
                            if units & (1 << bit):
                                domain = (0, 1, 2, 3) if expanded_inputs and entry == 0x8c0698fc else integers
                                if expanded_inputs and entry in (0x8c080930, 0x8c07d222):
                                    byte_addr = addr + bit // 8
                                    if byte_addr == 0x0c29c0d7:
                                        domain = tuple(range(6))
                                    elif 0x0c29c0d9 <= byte_addr < 0x0c29c0e3:
                                        domain = tuple(range(26))
                                if expanded_inputs and entry == 0x8c08d618:
                                    domain = (0, 1, 7, 84, 85, 100, 101, 119, 120, 121)
                                words[addr] = (words[addr] & ~(0xff << bit)) | (rng.choice(domain) << bit)
                for addr in types['floats']:
                    if addr in words and addr not in protected:
                        words[addr] = struct.unpack('<I', struct.pack('<f', rng.choice(active_palette)))[0]
                for addr, masks in types['flags'].items():
                    if addr in words and addr not in protected:
                        words[addr] = 0
                        for mask in masks:
                            if rng.randrange(2):
                                words[addr] |= mask
                for addr in types['counts']:
                    if addr in words and addr not in protected:
                        words[addr] = rng.randrange(1, 5)
                if expanded_inputs:
                    # Only pointers tested for zero by original instructions
                    # receive null alternatives. Actual execution validates
                    # whether each alternative is a complete invocation.
                    for reg in types['nullable_args']:
                        if reg in registers and rng.randrange(2):
                            registers[reg] = 0
                    for addr in types['nullable_fields']:
                        if addr in protected and rng.randrange(2):
                            words[addr] = 0
            if comparison_boundaries and variant >= 64 and not preserve_fields:
                hints = fixtures[entry][2]
                domain = boundary_palette(hints.get('comparisons', ()), holdout_inputs)
                protected = {addr for addr, value in words.items()
                             if 0x0c000000 <= (value & 0x1fffffff) < 0x10000000}
                if hints.get('comparisons'):
                    for index, addr in enumerate(hints['scalars']):
                        if addr in words and addr not in protected:
                            words[addr] = domain[(variant // 2 + index * 7) % len(domain)]
                    for index, (addr, width) in enumerate(sorted(hints['narrow_widths'].items())):
                        aligned = addr & ~3
                        if aligned in words and aligned not in protected:
                            value = domain[(variant // (1 << (index % 4)) + index * 7) % len(domain)]
                            words[aligned] = replace_narrow(words[aligned], addr, width, value)
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
            if expanded_inputs and entry == 0x8c09bade:
                # True prologue copies selector r4 to r0 and compares with 0.
                registers = dict(registers)
                registers[0] = registers[4] = variant & 7
                lines.append(f'reg 0x{trigger:08x} sr 0x{0x60000000 | int((variant & 7) == 0):08x}')
            if expanded_inputs and global_fields and entry == 0x8c0c8334:
                # Original byte read at 0c83d4 selects the 4132 message.
                # The global object starts at 0c29bcc4, selector +0x92.
                addr = 0x0c29bd54
                words[addr] = (words.get(addr, 0) & ~0x00ff0000) | ((variant & 1) << 16)
                # At 0c8460 the current slot points to a descriptor whose
                # first word is tested for zero. Preserve the inferred
                # descriptor pointer and vary that word independently.
                descriptor = words.get(0x0c29bc40)
                if descriptor and 0x0c400000 <= descriptor < 0x0c480000:
                    words[descriptor] = 0 if variant & 2 else words.get(descriptor, 0)
            if expanded_inputs and entry == 0x8c0ade3c:
                # Three original little-endian float records, separated by a
                # one-byte selector. Supply the decoder's established r0/r3.
                import struct
                registers = dict(registers)
                record = registers[6]
                for component, offset in enumerate((1, 6, 11)):
                    bits = struct.pack('<f', palette[(variant + component * 3) & 7])
                    for byte, value in enumerate(bits):
                        addr = record + offset + byte
                        base, shift = addr & ~3, (addr & 3) * 8
                        words[base] = (words.get(base, 0) & ~(255 << shift)) | (value << shift)
                first_bits = struct.pack('<f', palette[variant & 7])
                registers[0] = first_bits[2]
                registers[3] = first_bits[3] << 24
            lines += [f'reg 0x{trigger:08x} r{reg} 0x{relocated(value):08x}'
                      for reg, value in sorted(registers.items())]
            if bounded_arguments:
                for reg in range(15):
                    if reg in registers:
                        continue
                    if expanded_inputs and random_fields and variant >= 128:
                        value = rng.randrange(32)
                        if reg in types['signed_arguments'] and rng.randrange(2):
                            value = (0xffffffff - value) & 0xffffffff
                        for mask in types['argument_flags'].get(reg, ()):
                            if rng.randrange(2):
                                value |= mask
                            else:
                                value &= ~mask
                    else:
                        value = (variant + reg * 13 + (256 if holdout_inputs else 0)) & (7 if reg < 8 else 511)
                    if comparison_boundaries and variant >= 64:
                        hints = fixtures[entry][2]
                        if hints.get('comparisons'):
                            domain = boundary_palette(hints['comparisons'], holdout_inputs)
                            value = domain[(variant // 2 + reg * 7) % len(domain)]
                    lines.append(f'reg 0x{trigger:08x} r{reg} 0x{value:08x}')
            if floating_arguments:
                import struct
                lines += [f'reg 0x{trigger:08x} {bank}{reg} 0x' +
                          f'{struct.unpack("<I", struct.pack("<f", rng.choice(active_palette) if expanded_inputs and random_fields and variant >= 128 else palette[(variant + reg) & 7]))[0]:08x}'
                          for bank in ('fr', 'xf') for reg in range(16)]
            lines += [f'reg 0x{trigger:08x} r{reg} 0x{variant & 7:08x}' for reg in scalars]
            for register, values in overrides.get(entry, {}).items():
                value = override_value(values, variant)
                if register.startswith('r'):
                    value = relocated(value)
                lines.append(f'reg 0x{trigger:08x} {register} 0x{value:08x}')
            lines += [f'ram 0x{trigger:08x} 0x{relocated(addr):08x} 0x{relocated(value):08x}'
                      for addr, value in sorted(words.items())]
            lines += [f'ram 0x{trigger:08x} 0x{relocated(address):08x} '
                      f'0x{relocated(override_value(values, variant)):08x}'
                      for address, values in sorted(ram_overrides.get(entry, {}).items())]
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
    ap.add_argument('--global-fields', action='store_true')
    ap.add_argument('--scalar-fields', action='store_true')
    ap.add_argument('--field-crosses', action='store_true')
    ap.add_argument('--random-fields', action='store_true')
    ap.add_argument('--expanded-inputs', action='store_true')
    ap.add_argument('--preserve-fields', action='store_true')
    ap.add_argument('--comparison-boundaries', action='store_true',
                    help='also sample around bounded original integer comparands')
    ap.add_argument('--holdout-inputs', action='store_true')
    ap.add_argument('--float-palette', type=float, nargs=8,
                    help='eight finite float32 inputs for original float comparison boundaries')
    a = ap.parse_args()
    generate(a.watch, a.out, a.trigger, a.variants, a.relocation, a.mode,
             a.scalar_register, a.float_vectors, a.fpscr, a.bounded_arguments,
             a.floating_arguments, a.alternate_fields,
             holdout_inputs=a.holdout_inputs, global_fields=a.global_fields,
             scalar_fields=a.scalar_fields, field_crosses=a.field_crosses,
             random_fields=a.random_fields, expanded_inputs=a.expanded_inputs,
             preserve_fields=a.preserve_fields, comparison_boundaries=a.comparison_boundaries,
             float_palette=a.float_palette)
