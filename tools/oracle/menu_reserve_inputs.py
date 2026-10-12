"""Screen two menu reserve owners at their original complete save prefixes."""
import argparse
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--typed-actors', action='store_true', help='vary original paired status bits and menu character metadata')
    args = parser.parse_args()
    name = 'coverage_65_menu_reserve_dev_v2' if args.typed_actors else 'coverage_65_menu_reserve_dev_v1'
    base = ROOT / 'tools/oracle'
    owners = {'0x8c07cbc8': '0x8c07cbda', '0x8c07cf3e': '0x8c07cf50'}
    memory = {entry: {
        # The first routine's live gate and exact creation-frame boundary.
        '0xc29bcf0': {'values': [0, 1, 2], 'stride': 64},
        '0xc29b870': {'values': [0, 1, 61, 62, 63], 'stride': 8},
        # Vary the packed selector byte with the other input bytes cleared.
        '0xc29b8e0': {'values': [selector << 8 for selector in range(8)], 'stride': 16},
    } for entry in owners}
    if args.typed_actors:
        for fields in memory.values():
            fields.update({
                '0xc29bbac': 0xc640000, '0xc29bbb0': 0xc641000,
                '0xc640000': {'values': [0, 2, 4], 'stride': 8},
                '0xc641000': {'values': [0, 2, 4], 'stride': 32},
                '0xc640030': {'values': [value << 16 for value in (0, 7, 8, 9, 10, 13, 20)], 'stride': 1},
                '0xc641030': {'values': [value << 16 for value in (20, 13, 10, 9, 8, 7, 0)], 'stride': 2},
                '0xc64006c': {'values': [0, 6], 'stride': 16},
                '0xc64106c': {'values': [6, 0], 'stride': 16},
                '0xc29bccc': {'values': [0, 4], 'stride': 16},
            })
    paths = [base / f'{name}_watch.txt', base / f'{name}_owners.json',
             base / f'percentage_inputs/{name}_memory.json', ROOT / f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths), 'refuse to replace reserve inputs'
    paths[0].write_text(''.join('pc ' + entry + '\n' for entry in owners))
    for path, data in zip(paths[1:3], (owners, memory)):
        path.write_text(json.dumps(data, indent=2) + '\n')
    generate(paths[0], paths[3], 0x8c0432e2, 128, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True, memory_overrides=memory)
    print('Two original menu reserve inputs prepared; advisory, no coverage credit')


if __name__ == '__main__':
    main()
