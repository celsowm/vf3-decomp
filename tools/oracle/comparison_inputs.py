"""Suggest integer input boundaries from original SH-4 comparisons.

These are fixture hints, never expected results or coverage evidence. Retain
original execution, complete-body capture and independent strict replay gates.
"""
import argparse
import json
from pathlib import Path


def literal_comparisons(op, registers):
    """Recover bounded literal comparands from the current advisory register map."""
    top, n, m, low = op >> 12, (op >> 8) & 15, (op >> 4) & 15, op & 15
    values = []
    if op & 0xff00 == 0x8800:
        values.append((op & 255) - (256 if op & 128 else 0))
    elif top == 3 and low in (0, 2, 3, 6, 7):
        for register in (n, m):
            expression = registers.get(register)
            if expression is not None and expression[0] == 'literal':
                value = expression[1]
                signed = value - 0x100000000 if 0x80000000 <= value <= 0xffffffff else value
                if -65535 <= signed <= 65535:
                    values.append(signed)
    elif top == 4 and op & 255 in (0x11, 0x15):
        values.append(0)
    return sorted(set(values))


def boundary_palette(comparisons, holdout=False):
    values = {0, 1}
    for comparison in comparisons:
        pivot = comparison['value'] if isinstance(comparison, dict) else comparison
        values.update((pivot + delta) & 0xffffffff for delta in (-1, 0, 1))
    ordered = sorted(values)
    return tuple(reversed(ordered)) if holdout else tuple(ordered)


def replace_narrow(word, address, width, value):
    """Replace exactly the observed byte/word field, preserving adjacent bytes."""
    shift = (address & 3) * 8
    if width not in (1, 2) or (address & 3) + width > 4:
        raise ValueError('narrow field must fit within one aligned fixture word')
    mask = (1 << (width * 8)) - 1
    return (word & ~(mask << shift)) | ((value & mask) << shift)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    from campaign_io import read_watch
    from pointer_seeds import fixture
    rows = {}
    for entry in sorted(read_watch(args.watch)):
        _, _, metadata = fixture(entry, metadata=True)
        rows[f'0x{entry:08x}'] = dict(comparisons=metadata['comparisons'],
                                    palette=boundary_palette(metadata['comparisons']))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(dict(advisory=True, entries=rows), indent=1) + '\n')
    print(f'{len(rows)} entries; comparison hints only, no coverage credit')


if __name__ == '__main__':
    main()
