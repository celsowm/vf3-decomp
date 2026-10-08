"""Original five-instruction word store into sound RAM, plus rejected controls."""
import argparse
import json
import struct
from pathlib import Path
from text_control_probe_plan import ENTRY, TRIGGER, ROOT, fixture

ADDRESSES = dict(development=0xa0801000, acceptance=0xa0803000,
                 disabled=0xa0801000, register=0xa0702800, alias=0x80801000)


def generate(output, mode, variants=192):
    if mode not in ADDRESSES or not 64 <= variants <= 1024:
        raise ValueError('known control mode and 64..1024 variants required')
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    if struct.unpack_from('<5H', image, ENTRY - 0x8c010000) != (
            0xd344, 0x343c, 0x2452, 0x000b, 0xe001):
        raise ValueError('original word-store helper changed')
    if struct.unpack_from('<I', image, 0x8c060e28 - 0x8c010000)[0] != 0xa05f8000:
        raise ValueError('original helper base changed')
    holdout = mode == 'acceptance'
    lines = [f'entry {TRIGGER:#x} {ENTRY:#x}']
    for variant in range(variants):
        if variant:
            lines.append(f'seed {TRIGGER:#x}')
        lines += [f'target {TRIGGER:#x} {ENTRY & 0x1fffffff:#x}',
                  f'reg {TRIGGER:#x} pr {(TRIGGER+2) & 0x1fffffff:#x}']
        values = fixture(variant, (ADDRESSES[mode]-0xa05f8000) & 0xffffffff,
                         0x100000 if holdout else 0, holdout)
        lines += [f'reg {TRIGGER:#x} {name} {value:#x}' for name, value in values.items()]
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines)+'\n')
    output.with_suffix('.json').write_text(json.dumps(dict(
        advisory=True, coverage_credit=0, mode=mode, variants=variants,
        address=hex(ADDRESSES[mode]), entry=hex(ENTRY)), indent=1)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--mode', choices=ADDRESSES, required=True)
    parser.add_argument('--variants', type=int, default=192)
    args = parser.parse_args()
    generate(args.out, args.mode, args.variants)
