"""Typed IEEE-754 inputs for the original single-to-double conversion leaf."""
import argparse
import json
from pathlib import Path
from entry_patch_builder import build

PALETTE = (0, 0x80000000, 0x3f800000, 0xbf800000, 1, 0x80000001,
           0x007fffff, 0x807fffff, 0x00800000, 0x80800000,
           0x7f800000, 0xff800000, 0x7fc01234, 0xffa01234,
           0x7f7fffff, 0xff7fffff)


def prepare(output, variants):
    output.mkdir(parents=True, exist_ok=True)
    recipe, patch, watch = output/'recipe.json', output/'entry.patch', output/'watch.txt'
    if any(p.exists() for p in (recipe, patch, watch)):
        raise FileExistsError('refusing to replace float conversion inputs')
    inputs = []
    for index in range(variants):
        registers = {f'r{reg}': (index*0x101+reg*0x11111) & 0xffffffff for reg in range(4)}
        registers.update(fr0=PALETTE[index % len(PALETTE)], r15=0xc690100, fpscr=0x40001)
        inputs.append(dict(registers=registers, memory={'0xc690100': 0xc430000}))
    data = dict(trigger_pc='0x8c0432e2', target_pc='0x8c05339c', pr_offset=2, variants=inputs)
    recipe.write_text(json.dumps(data, indent=2)+'\n')
    patch.write_text(build(data))
    watch.write_text('pc 0x8c05339c\n')
    (output/'owners.json').write_text('{"0x8c05339c":"0x8c0533a4"}\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    args = parser.parse_args()
    prepare(args.out, args.variants)
