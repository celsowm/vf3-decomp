"""Probe original command encoders with selector domains and a bounded RAM queue."""
import argparse
import json
import struct
from pathlib import Path
from boundary_probe_plan import ROOT

PARENTS = (0x8c040c90, 0x8c040d1c, 0x8c040e24, 0x8c040ec2,
           0x8c041d04, 0x8c041d7c, 0x8c041de0, 0x8c041e58, 0x8c041ebc)


def fixture(parent, variant, relocation=0, holdout=False):
    queue, stack = 0x0c460000 + relocation, 0x0c47f000 + relocation
    regs = {'r15': stack, 'fpscr': 0x40001}
    domain = (3, 9, 17, 63, 127, 128, 255, 256) if holdout else (0, 1, 2, 15, 64, 127, 128, 512)
    regs.update({f'r{i}': domain[(variant // (1 << (i - 4))) % 8] for i in range(4, 8)})
    if parent == 0x8c040c90:
        regs['r6'] = (0x7b0, 0xab0, 0x27b0, 0x2ab0, 0)[variant % 5]
    elif parent == 0x8c040d1c:
        regs['r5'] = (0xa5, 0xa6, 0xa7, 0x10a5, 0x10a7, 0x20a5,
                      0x30a5, 0x40a5, 0x50a5, 0)[variant % 10]
    elif parent == 0x8c040e24:
        regs['r5'] = (0xa4, 0x10a4, 0x20a4, 0x70a4, 0)[variant % 5]
    elif parent == 0x8c040ec2:
        regs['r4'] = 0xa3 if variant & 1 else 0
    elif parent >= 0x8c041d04:
        regs['r4'] = (variant // 4) % 8
    words = {queue + offset: 0 for offset in range(0, 64, 4)}
    words[queue] = (variant // 10) & 1
    words[0x0c19e218] = queue
    # Each channel's original byte table uses a 24-byte stride. The
    # encoders observe only its enabled byte; preserve all adjacent bytes.
    words.update({0x0c19e250 + channel * 24: (variant // 8) & 1
                  for channel in range(8)})
    words.update({stack + offset: (variant * (101 if holdout else 67) + offset) & 0xffffffff
                  for offset in range(0, 64, 4)})
    return regs, words


def generate(output, variants=256, relocation=0, holdout=False, parents=PARENTS):
    if not 64 <= variants <= 1024:
        raise ValueError('variants must be 64..1024')
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    for parent in parents:
        if parent not in PARENTS or struct.unpack_from('<H', image, parent - 0x8c010000)[0] != 0x2fe6:
            raise ValueError(f'original encoder prologue mismatch: {parent:#x}')
    trigger = 0x8c0432e2
    lines = [f'entry 0x{trigger:08x} 0x{parents[0]:08x}']
    first = True
    for variant in range(variants):
        for parent in parents:
            if not first:
                lines.append(f'seed 0x{trigger:08x}')
            first = False
            lines.extend((f'target 0x{trigger:08x} 0x{parent & 0x1fffffff:08x}',
                          f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}'))
            regs, words = fixture(parent, variant, relocation, holdout)
            lines.extend(f'reg 0x{trigger:08x} {name} 0x{value:08x}' for name, value in regs.items())
            lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}'
                         for address, value in sorted(words.items()))
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    output.with_suffix('.json').write_text(json.dumps(dict(advisory=True,
        parents=[hex(p) for p in parents], variants=variants,
        relocation=hex(relocation), holdout=holdout,
        contract='Original scalar selectors, enabled-channel bytes and RAM queue pointer; real command enqueue callee.'), indent=1) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=256)
    parser.add_argument('--relocation', type=lambda value: int(value, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    parser.add_argument('--parent', type=lambda value: int(value, 0), action='append', choices=PARENTS)
    args = parser.parse_args()
    generate(args.out, args.variants, args.relocation, args.holdout, args.parent or PARENTS)
