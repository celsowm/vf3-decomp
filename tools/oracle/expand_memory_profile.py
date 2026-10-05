"""Expand typed record/table RAM ranges into standard probe word overrides.

Input maps entry PCs to {words: {...}, ranges: [{start, count, stride, value}]}.
Values use tenpp_probe_plan's scalar/list/strided-variant syntax. This tool
creates inputs only; original execution and independent replay remain required.
"""
import argparse
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence

ROOT = Path(__file__).resolve().parents[2]


def expand(profile, data_floor):
    result = {}
    for entry, specification in profile.items():
        if set(specification) - {'words', 'ranges'}:
            raise ValueError(f'unknown profile fields for {entry}')
        words = {}

        def add(address, value):
            address = int(address, 0) if isinstance(address, str) else address
            if address % 4 or not data_floor <= address <= 0x0cfffffc:
                raise ValueError(f'override outside mutable aligned RAM: {address:#x}')
            override_sequence(value, f'{entry} {address:#x}')
            key = f'0x{address:08x}'
            if key in words:
                raise ValueError(f'overlapping override at {key}')
            words[key] = value

        for address, value in specification.get('words', {}).items():
            add(address, value)
        for row in specification.get('ranges', []):
            if set(row) != {'start', 'count', 'stride', 'value'}:
                raise ValueError(f'invalid RAM range for {entry}')
            start = int(row['start'], 0) if isinstance(row['start'], str) else row['start']
            count, stride = row['count'], row['stride']
            if (type(count) is not int or not 1 <= count <= 65536 or
                    type(stride) is not int or stride < 4 or stride % 4):
                raise ValueError(f'invalid range dimensions for {entry}')
            for index in range(count):
                add(start + index * stride, row['value'])
        result[entry] = words
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('profile', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--image', type=Path, default=ROOT / 'extract/exe/1ST_READ.unsc.bin')
    args = parser.parse_args()
    words = expand(json.loads(args.profile.read_text()), 0x0c010000 + args.image.stat().st_size)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(words, indent=1) + '\n')
    print(f'{len(words)} entries; {sum(map(len, words.values()))} mutable RAM words')


if __name__ == '__main__':
    main()
